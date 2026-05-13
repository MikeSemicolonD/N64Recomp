#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void bcmp_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029F60: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // 0x80029F64: bne         $at, $zero, L_8002A044
    if (ctx->r1 != 0) {
        // 0x80029F68: xor         $v0, $a0, $a1
        ctx->r2 = ctx->r4 ^ ctx->r5;
            goto L_8002A044;
    }
    // 0x80029F68: xor         $v0, $a0, $a1
    ctx->r2 = ctx->r4 ^ ctx->r5;
    // 0x80029F6C: andi        $v0, $v0, 0x3
    ctx->r2 = ctx->r2 & 0X3;
    // 0x80029F70: bne         $v0, $zero, L_80029FD8
    if (ctx->r2 != 0) {
        // 0x80029F74: negu        $t8, $a0
        ctx->r24 = SUB32(0, ctx->r4);
            goto L_80029FD8;
    }
    // 0x80029F74: negu        $t8, $a0
    ctx->r24 = SUB32(0, ctx->r4);
    // 0x80029F78: andi        $t8, $t8, 0x3
    ctx->r24 = ctx->r24 & 0X3;
    // 0x80029F7C: beq         $t8, $zero, L_80029F9C
    if (ctx->r24 == 0) {
        // 0x80029F80: subu        $a2, $a2, $t8
        ctx->r6 = SUB32(ctx->r6, ctx->r24);
            goto L_80029F9C;
    }
    // 0x80029F80: subu        $a2, $a2, $t8
    ctx->r6 = SUB32(ctx->r6, ctx->r24);
    // 0x80029F84: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80029F88: lwl         $v0, 0x0($a0)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
    // 0x80029F8C: lwl         $v1, 0x0($a1)
    ctx->r3 = do_lwl(rdram, ctx->r3, ctx->r5, 0X0);
    // 0x80029F90: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x80029F94: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x80029F98: bne         $v0, $v1, L_8002A074
    if (ctx->r2 != ctx->r3) {
        // 0x80029F9C: addiu       $at, $zero, -0x4
        ctx->r1 = ADD32(0, -0X4);
            goto L_8002A074;
    }
L_80029F9C:
    // 0x80029F9C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80029FA0: and         $a3, $a2, $at
    ctx->r7 = ctx->r6 & ctx->r1;
    // 0x80029FA4: beq         $a3, $zero, L_8002A044
    if (ctx->r7 == 0) {
        // 0x80029FA8: subu        $a2, $a2, $a3
        ctx->r6 = SUB32(ctx->r6, ctx->r7);
            goto L_8002A044;
    }
    // 0x80029FA8: subu        $a2, $a2, $a3
    ctx->r6 = SUB32(ctx->r6, ctx->r7);
    // 0x80029FAC: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
    // 0x80029FB0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_80029FB4:
    // 0x80029FB4: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80029FB8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80029FBC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80029FC0: bne         $v0, $v1, L_8002A074
    if (ctx->r2 != ctx->r3) {
        // 0x80029FC4: nop
    
            goto L_8002A074;
    }
    // 0x80029FC4: nop

    // 0x80029FC8: bnel        $a0, $a3, L_80029FB4
    if (ctx->r4 != ctx->r7) {
        // 0x80029FCC: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_80029FB4;
    }
    goto skip_0;
    // 0x80029FCC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x80029FD0: b           L_8002A044
    // 0x80029FD4: nop

        goto L_8002A044;
    // 0x80029FD4: nop

L_80029FD8:
    // 0x80029FD8: negu        $a3, $a1
    ctx->r7 = SUB32(0, ctx->r5);
    // 0x80029FDC: andi        $a3, $a3, 0x3
    ctx->r7 = ctx->r7 & 0X3;
    // 0x80029FE0: beq         $a3, $zero, L_8002A00C
    if (ctx->r7 == 0) {
        // 0x80029FE4: subu        $a2, $a2, $a3
        ctx->r6 = SUB32(ctx->r6, ctx->r7);
            goto L_8002A00C;
    }
    // 0x80029FE4: subu        $a2, $a2, $a3
    ctx->r6 = SUB32(ctx->r6, ctx->r7);
    // 0x80029FE8: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
    // 0x80029FEC: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
L_80029FF0:
    // 0x80029FF0: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x80029FF4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80029FF8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80029FFC: bne         $v0, $v1, L_8002A074
    if (ctx->r2 != ctx->r3) {
        // 0x8002A000: nop
    
            goto L_8002A074;
    }
    // 0x8002A000: nop

    // 0x8002A004: bnel        $a0, $a3, L_80029FF0
    if (ctx->r4 != ctx->r7) {
        // 0x8002A008: lbu         $v0, 0x0($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X0);
            goto L_80029FF0;
    }
    goto skip_1;
    // 0x8002A008: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    skip_1:
L_8002A00C:
    // 0x8002A00C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8002A010: and         $a3, $a2, $at
    ctx->r7 = ctx->r6 & ctx->r1;
    // 0x8002A014: beq         $a3, $zero, L_8002A044
    if (ctx->r7 == 0) {
        // 0x8002A018: subu        $a2, $a2, $a3
        ctx->r6 = SUB32(ctx->r6, ctx->r7);
            goto L_8002A044;
    }
    // 0x8002A018: subu        $a2, $a2, $a3
    ctx->r6 = SUB32(ctx->r6, ctx->r7);
    // 0x8002A01C: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
    // 0x8002A020: lwl         $v0, 0x0($a0)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
L_8002A024:
    // 0x8002A024: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8002A028: lwr         $v0, 0x3($a0)
    ctx->r2 = do_lwr(rdram, ctx->r2, ctx->r4, 0X3);
    // 0x8002A02C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8002A030: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8002A034: bne         $v0, $v1, L_8002A074
    if (ctx->r2 != ctx->r3) {
        // 0x8002A038: nop
    
            goto L_8002A074;
    }
    // 0x8002A038: nop

    // 0x8002A03C: bnel        $a0, $a3, L_8002A024
    if (ctx->r4 != ctx->r7) {
        // 0x8002A040: lwl         $v0, 0x0($a0)
        ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
            goto L_8002A024;
    }
    goto skip_2;
    // 0x8002A040: lwl         $v0, 0x0($a0)
    ctx->r2 = do_lwl(rdram, ctx->r2, ctx->r4, 0X0);
    skip_2:
L_8002A044:
    // 0x8002A044: blez        $a2, L_8002A06C
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8002A048: addu        $a3, $a2, $a0
        ctx->r7 = ADD32(ctx->r6, ctx->r4);
            goto L_8002A06C;
    }
    // 0x8002A048: addu        $a3, $a2, $a0
    ctx->r7 = ADD32(ctx->r6, ctx->r4);
    // 0x8002A04C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
L_8002A050:
    // 0x8002A050: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x8002A054: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002A058: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8002A05C: bne         $v0, $v1, L_8002A074
    if (ctx->r2 != ctx->r3) {
        // 0x8002A060: nop
    
            goto L_8002A074;
    }
    // 0x8002A060: nop

    // 0x8002A064: bnel        $a0, $a3, L_8002A050
    if (ctx->r4 != ctx->r7) {
        // 0x8002A068: lbu         $v0, 0x0($a0)
        ctx->r2 = MEM_BU(ctx->r4, 0X0);
            goto L_8002A050;
    }
    goto skip_3;
    // 0x8002A068: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    skip_3:
L_8002A06C:
    // 0x8002A06C: jr          $ra
    // 0x8002A070: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8002A070: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002A074:
    // 0x8002A074: jr          $ra
    // 0x8002A078: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8002A078: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void bzero_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A080: slti        $at, $a1, 0xC
    ctx->r1 = SIGNED(ctx->r5) < 0XC ? 1 : 0;
    // 0x8002A084: bne         $at, $zero, L_8002A0FC
    if (ctx->r1 != 0) {
        // 0x8002A088: negu        $v1, $a0
        ctx->r3 = SUB32(0, ctx->r4);
            goto L_8002A0FC;
    }
    // 0x8002A088: negu        $v1, $a0
    ctx->r3 = SUB32(0, ctx->r4);
    // 0x8002A08C: andi        $v1, $v1, 0x3
    ctx->r3 = ctx->r3 & 0X3;
    // 0x8002A090: beq         $v1, $zero, L_8002A0A0
    if (ctx->r3 == 0) {
        // 0x8002A094: subu        $a1, $a1, $v1
        ctx->r5 = SUB32(ctx->r5, ctx->r3);
            goto L_8002A0A0;
    }
    // 0x8002A094: subu        $a1, $a1, $v1
    ctx->r5 = SUB32(ctx->r5, ctx->r3);
    // 0x8002A098: swl         $zero, 0x0($a0)
    do_swl(rdram, 0X0, ctx->r4, 0);
    // 0x8002A09C: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
L_8002A0A0:
    // 0x8002A0A0: addiu       $at, $zero, -0x20
    ctx->r1 = ADD32(0, -0X20);
    // 0x8002A0A4: and         $a3, $a1, $at
    ctx->r7 = ctx->r5 & ctx->r1;
    // 0x8002A0A8: beq         $a3, $zero, L_8002A0DC
    if (ctx->r7 == 0) {
        // 0x8002A0AC: subu        $a1, $a1, $a3
        ctx->r5 = SUB32(ctx->r5, ctx->r7);
            goto L_8002A0DC;
    }
    // 0x8002A0AC: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x8002A0B0: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_8002A0B4:
    // 0x8002A0B4: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x8002A0B8: sw          $zero, -0x20($a0)
    MEM_W(-0X20, ctx->r4) = 0;
    // 0x8002A0BC: sw          $zero, -0x1C($a0)
    MEM_W(-0X1C, ctx->r4) = 0;
    // 0x8002A0C0: sw          $zero, -0x18($a0)
    MEM_W(-0X18, ctx->r4) = 0;
    // 0x8002A0C4: sw          $zero, -0x14($a0)
    MEM_W(-0X14, ctx->r4) = 0;
    // 0x8002A0C8: sw          $zero, -0x10($a0)
    MEM_W(-0X10, ctx->r4) = 0;
    // 0x8002A0CC: sw          $zero, -0xC($a0)
    MEM_W(-0XC, ctx->r4) = 0;
    // 0x8002A0D0: sw          $zero, -0x8($a0)
    MEM_W(-0X8, ctx->r4) = 0;
    // 0x8002A0D4: bne         $a0, $a3, L_8002A0B4
    if (ctx->r4 != ctx->r7) {
        // 0x8002A0D8: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_8002A0B4;
    }
    // 0x8002A0D8: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
L_8002A0DC:
    // 0x8002A0DC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8002A0E0: and         $a3, $a1, $at
    ctx->r7 = ctx->r5 & ctx->r1;
    // 0x8002A0E4: beq         $a3, $zero, L_8002A0FC
    if (ctx->r7 == 0) {
        // 0x8002A0E8: subu        $a1, $a1, $a3
        ctx->r5 = SUB32(ctx->r5, ctx->r7);
            goto L_8002A0FC;
    }
    // 0x8002A0E8: subu        $a1, $a1, $a3
    ctx->r5 = SUB32(ctx->r5, ctx->r7);
    // 0x8002A0EC: addu        $a3, $a3, $a0
    ctx->r7 = ADD32(ctx->r7, ctx->r4);
L_8002A0F0:
    // 0x8002A0F0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8002A0F4: bne         $a0, $a3, L_8002A0F0
    if (ctx->r4 != ctx->r7) {
        // 0x8002A0F8: sw          $zero, -0x4($a0)
        MEM_W(-0X4, ctx->r4) = 0;
            goto L_8002A0F0;
    }
    // 0x8002A0F8: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
L_8002A0FC:
    // 0x8002A0FC: blez        $a1, L_8002A114
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8002A100: nop
    
            goto L_8002A114;
    }
    // 0x8002A100: nop

    // 0x8002A104: addu        $a1, $a1, $a0
    ctx->r5 = ADD32(ctx->r5, ctx->r4);
L_8002A108:
    // 0x8002A108: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002A10C: bne         $a0, $a1, L_8002A108
    if (ctx->r4 != ctx->r5) {
        // 0x8002A110: sb          $zero, -0x1($a0)
        MEM_B(-0X1, ctx->r4) = 0;
            goto L_8002A108;
    }
    // 0x8002A110: sb          $zero, -0x1($a0)
    MEM_B(-0X1, ctx->r4) = 0;
L_8002A114:
    // 0x8002A114: jr          $ra
    // 0x8002A118: nop

    return;
    // 0x8002A118: nop

;}
RECOMP_FUNC void cosf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002B190: swc1        $f12, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f12.u32l;
    // 0x8002B194: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x8002B198: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8002B19C: lwc1        $f10, 0x0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8002B1A0: sra         $t6, $v0, 22
    ctx->r14 = S32(SIGNED(ctx->r2) >> 22);
    // 0x8002B1A4: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x8002B1A8: slti        $at, $t7, 0x136
    ctx->r1 = SIGNED(ctx->r15) < 0X136 ? 1 : 0;
    // 0x8002B1AC: beql        $at, $zero, L_8002B2D4
    if (ctx->r1 == 0) {
        // 0x8002B1B0: c.eq.s      $f10, $f10
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f10.fl == ctx->f10.fl;
            goto L_8002B2D4;
    }
    goto skip_0;
    // 0x8002B1B0: c.eq.s      $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f10.fl == ctx->f10.fl;
    skip_0:
    // 0x8002B1B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002B1B8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8002B1BC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8002B1C0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8002B1C4: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8002B1C8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8002B1CC: bc1fl       L_8002B1E0
    if (!c1cs) {
        // 0x8002B1D0: neg.s       $f0, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
            goto L_8002B1E0;
    }
    goto skip_1;
    // 0x8002B1D0: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    skip_1:
    // 0x8002B1D4: b           L_8002B1E0
    // 0x8002B1D8: mov.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = ctx->f6.fl;
        goto L_8002B1E0;
    // 0x8002B1D8: mov.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = ctx->f6.fl;
    // 0x8002B1DC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_8002B1E0:
    // 0x8002B1E0: ldc1        $f8, -0x5F08($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X5F08);
    // 0x8002B1E4: cvt.d.s     $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.d = CVT_D_S(ctx->f0.fl);
    // 0x8002B1E8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8002B1EC: mul.d       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f12.d, ctx->f8.d);
    // 0x8002B1F0: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x8002B1F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8002B1F8: add.d       $f14, $f10, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f14.d = ctx->f10.d + ctx->f18.d;
    // 0x8002B1FC: c.le.d      $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f4.d <= ctx->f14.d;
    // 0x8002B200: nop

    // 0x8002B204: bc1fl       L_8002B224
    if (!c1cs) {
        // 0x8002B208: sub.d       $f10, $f14, $f18
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f14.d - ctx->f18.d;
            goto L_8002B224;
    }
    goto skip_2;
    // 0x8002B208: sub.d       $f10, $f14, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f14.d - ctx->f18.d;
    skip_2:
    // 0x8002B20C: add.d       $f6, $f14, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f14.d + ctx->f18.d;
    // 0x8002B210: trunc.w.d   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x8002B214: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8002B218: b           L_8002B234
    // 0x8002B21C: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
        goto L_8002B234;
    // 0x8002B21C: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8002B220: sub.d       $f10, $f14, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.d); NAN_CHECK(ctx->f18.d); 
    ctx->f10.d = ctx->f14.d - ctx->f18.d;
L_8002B224:
    // 0x8002B224: trunc.w.d   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x8002B228: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8002B22C: nop

    // 0x8002B230: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
L_8002B234:
    // 0x8002B234: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8002B238: ldc1        $f10, -0x5F00($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X5F00);
    // 0x8002B23C: cvt.d.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.d = CVT_D_W(ctx->f6.u32l);
    // 0x8002B240: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8002B244: ldc1        $f6, -0x5EF8($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X5EF8);
    // 0x8002B248: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8002B24C: addiu       $v1, $v1, -0x5F30
    ctx->r3 = ADD32(ctx->r3, -0X5F30);
    // 0x8002B250: sub.d       $f0, $f8, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f18.d); 
    ctx->f0.d = ctx->f8.d - ctx->f18.d;
    // 0x8002B254: andi        $t0, $v0, 0x1
    ctx->r8 = ctx->r2 & 0X1;
    // 0x8002B258: mul.d       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f10.d);
    // 0x8002B25C: ldc1        $f10, 0x20($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X20);
    // 0x8002B260: mul.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x8002B264: ldc1        $f6, 0x18($v1)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r3, 0X18);
    // 0x8002B268: sub.d       $f2, $f12, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f12.d - ctx->f4.d;
    // 0x8002B26C: sub.d       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f2.d = ctx->f2.d - ctx->f8.d;
    // 0x8002B270: mul.d       $f14, $f2, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f14.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x8002B274: nop

    // 0x8002B278: mul.d       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f14.d);
    // 0x8002B27C: add.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d + ctx->f6.d;
    // 0x8002B280: ldc1        $f4, 0x10($v1)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r3, 0X10);
    // 0x8002B284: mul.d       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f14.d);
    // 0x8002B288: add.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d + ctx->f4.d;
    // 0x8002B28C: ldc1        $f10, 0x8($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X8);
    // 0x8002B290: mul.d       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f14.d);
    // 0x8002B294: bne         $t0, $zero, L_8002B2B4
    if (ctx->r8 != 0) {
        // 0x8002B298: add.d       $f16, $f10, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d + ctx->f8.d;
            goto L_8002B2B4;
    }
    // 0x8002B298: add.d       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f16.d = ctx->f10.d + ctx->f8.d;
    // 0x8002B29C: mul.d       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f14.d);
    // 0x8002B2A0: nop

    // 0x8002B2A4: mul.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x8002B2A8: add.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f6.d + ctx->f2.d;
    // 0x8002B2AC: jr          $ra
    // 0x8002B2B0: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    return;
    // 0x8002B2B0: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_8002B2B4:
    // 0x8002B2B4: mul.d       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f14.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f14.d);
    // 0x8002B2B8: nop

    // 0x8002B2BC: mul.d       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f16.d);
    // 0x8002B2C0: add.d       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = ctx->f4.d + ctx->f2.d;
    // 0x8002B2C4: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
    // 0x8002B2C8: jr          $ra
    // 0x8002B2CC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    return;
    // 0x8002B2CC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8002B2D0: c.eq.s      $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f10.fl == ctx->f10.fl;
L_8002B2D4:
    // 0x8002B2D4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8002B2D8: bc1t        L_8002B2EC
    if (c1cs) {
        // 0x8002B2DC: nop
    
            goto L_8002B2EC;
    }
    // 0x8002B2DC: nop

    // 0x8002B2E0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8002B2E4: jr          $ra
    // 0x8002B2E8: lwc1        $f0, -0x5E90($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5E90);
    return;
    // 0x8002B2E8: lwc1        $f0, -0x5E90($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5E90);
L_8002B2EC:
    // 0x8002B2EC: lwc1        $f0, -0x5EF0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5EF0);
    // 0x8002B2F0: jr          $ra
    // 0x8002B2F4: nop

    return;
    // 0x8002B2F4: nop

;}
RECOMP_FUNC void func_8002BB34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void guMtxXFML(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E3B0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8002E3B4: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x8002E3B8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8002E3BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8002E3C0: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x8002E3C4: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x8002E3C8: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x8002E3CC: jal         0x8002E838
    // 0x8002E3D0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    guMtxL2F(rdram, ctx);
        goto after_0;
    // 0x8002E3D0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x8002E3D4: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x8002E3D8: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x8002E3DC: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    // 0x8002E3E0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8002E3E4: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x8002E3E8: lw          $a2, 0x70($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X70);
    // 0x8002E3EC: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
    // 0x8002E3F0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8002E3F4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8002E3F8: jal         0x8002E470
    // 0x8002E3FC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    guMtxXFMF(rdram, ctx);
        goto after_1;
    // 0x8002E3FC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_1:
    // 0x8002E400: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8002E404: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8002E408: jr          $ra
    // 0x8002E40C: nop

    return;
    // 0x8002E40C: nop

;}
RECOMP_FUNC void guMtxCatL(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E410: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x8002E414: sw          $a1, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r5;
    // 0x8002E418: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8002E41C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002E420: sw          $a0, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r4;
    // 0x8002E424: sw          $a2, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r6;
    // 0x8002E428: jal         0x8002E838
    // 0x8002E42C: addiu       $a0, $sp, 0x98
    ctx->r4 = ADD32(ctx->r29, 0X98);
    guMtxL2F(rdram, ctx);
        goto after_0;
    // 0x8002E42C: addiu       $a0, $sp, 0x98
    ctx->r4 = ADD32(ctx->r29, 0X98);
    after_0:
    // 0x8002E430: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x8002E434: jal         0x8002E838
    // 0x8002E438: lw          $a1, 0xDC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XDC);
    guMtxL2F(rdram, ctx);
        goto after_1;
    // 0x8002E438: lw          $a1, 0xDC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XDC);
    after_1:
    // 0x8002E43C: addiu       $a0, $sp, 0x98
    ctx->r4 = ADD32(ctx->r29, 0X98);
    // 0x8002E440: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    // 0x8002E444: jal         0x8002E510
    // 0x8002E448: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    guMtxCatF(rdram, ctx);
        goto after_2;
    // 0x8002E448: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_2:
    // 0x8002E44C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8002E450: jal         0x8002E680
    // 0x8002E454: lw          $a1, 0xE0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE0);
    guMtxF2L(rdram, ctx);
        goto after_3;
    // 0x8002E454: lw          $a1, 0xE0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE0);
    after_3:
    // 0x8002E458: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002E45C: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    // 0x8002E460: jr          $ra
    // 0x8002E464: nop

    return;
    // 0x8002E464: nop

;}
RECOMP_FUNC void guMtxXFMF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E470: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8002E474: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8002E478: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8002E47C: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8002E480: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8002E484: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x8002E488: lwc1        $f4, 0x20($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X20);
    // 0x8002E48C: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x8002E490: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x8002E494: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8002E498: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8002E49C: lwc1        $f10, 0x30($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X30);
    // 0x8002E4A0: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8002E4A4: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8002E4A8: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
    // 0x8002E4AC: lwc1        $f18, 0x4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8002E4B0: lwc1        $f10, 0x14($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8002E4B4: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x8002E4B8: mul.s       $f8, $f18, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8002E4BC: lwc1        $f18, 0x24($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8002E4C0: mul.s       $f6, $f10, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8002E4C4: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8002E4C8: mul.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x8002E4CC: lwc1        $f6, 0x34($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X34);
    // 0x8002E4D0: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8002E4D4: add.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8002E4D8: swc1        $f18, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f18.u32l;
    // 0x8002E4DC: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8002E4E0: lwc1        $f6, 0x18($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X18);
    // 0x8002E4E4: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8002E4E8: mul.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8002E4EC: lwc1        $f4, 0x28($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X28);
    // 0x8002E4F0: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8002E4F4: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8002E4F8: mul.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8002E4FC: lwc1        $f8, 0x38($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8002E500: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8002E504: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8002E508: jr          $ra
    // 0x8002E50C: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    return;
    // 0x8002E50C: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
;}
RECOMP_FUNC void guMtxCatF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E510: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8002E514: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8002E518: addiu       $v1, $sp, 0x1C
    ctx->r3 = ADD32(ctx->r29, 0X1C);
    // 0x8002E51C: addiu       $t3, $sp, 0x5C
    ctx->r11 = ADD32(ctx->r29, 0X5C);
    // 0x8002E520: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8002E524: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x8002E528: addiu       $t2, $zero, 0x10
    ctx->r10 = ADD32(0, 0X10);
L_8002E52C:
    // 0x8002E52C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002E530: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x8002E534: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
    // 0x8002E538: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x8002E53C: lwc1        $f12, 0x0($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8002E540: lwc1        $f14, 0x0($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8002E544: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8002E548: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8002E54C: mul.s       $f18, $f14, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8002E550: beql        $a0, $t2, L_8002E5D4
    if (ctx->r4 == ctx->r10) {
        // 0x8002E554: add.s       $f14, $f16, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
            goto L_8002E5D4;
    }
    goto skip_0;
    // 0x8002E554: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    skip_0:
    // 0x8002E558: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
L_8002E55C:
    // 0x8002E55C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8002E560: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8002E564: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x8002E568: swc1        $f14, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f14.u32l;
    // 0x8002E56C: lwc1        $f14, 0x4($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8002E570: lwc1        $f12, 0xC($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0XC);
    // 0x8002E574: lwc1        $f10, -0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, -0X4);
    // 0x8002E578: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8002E57C: add.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x8002E580: swc1        $f12, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f12.u32l;
    // 0x8002E584: lwc1        $f12, 0x8($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8002E588: lwc1        $f10, 0x1C($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x8002E58C: lwc1        $f14, -0x4($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, -0X4);
    // 0x8002E590: mul.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x8002E594: add.s       $f10, $f14, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x8002E598: swc1        $f10, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f10.u32l;
    // 0x8002E59C: lwc1        $f10, 0xC($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8002E5A0: lwc1        $f14, 0x2C($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0X2C);
    // 0x8002E5A4: lwc1        $f12, -0x4($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, -0X4);
    // 0x8002E5A8: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x8002E5AC: mul.s       $f14, $f10, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8002E5B0: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8002E5B4: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x8002E5B8: swc1        $f14, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f14.u32l;
    // 0x8002E5BC: lwc1        $f14, 0x0($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8002E5C0: lwc1        $f12, 0x0($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8002E5C4: mul.s       $f18, $f14, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8002E5C8: bnel        $a0, $t2, L_8002E55C
    if (ctx->r4 != ctx->r10) {
        // 0x8002E5CC: add.s       $f14, $f16, $f18
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
            goto L_8002E55C;
    }
    goto skip_1;
    // 0x8002E5CC: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
    skip_1:
    // 0x8002E5D0: add.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f18.fl;
L_8002E5D4:
    // 0x8002E5D4: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8002E5D8: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x8002E5DC: swc1        $f14, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f14.u32l;
    // 0x8002E5E0: lwc1        $f12, 0xC($t1)
    ctx->f12.u32l = MEM_W(ctx->r9, 0XC);
    // 0x8002E5E4: lwc1        $f14, 0x4($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8002E5E8: lwc1        $f10, -0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, -0X4);
    // 0x8002E5EC: mul.s       $f12, $f14, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f14.fl, ctx->f12.fl);
    // 0x8002E5F0: add.s       $f12, $f10, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f12.fl;
    // 0x8002E5F4: swc1        $f12, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f12.u32l;
    // 0x8002E5F8: lwc1        $f10, 0x1C($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x8002E5FC: lwc1        $f12, 0x8($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8002E600: lwc1        $f14, -0x4($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, -0X4);
    // 0x8002E604: mul.s       $f10, $f12, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x8002E608: add.s       $f10, $f14, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x8002E60C: swc1        $f10, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f10.u32l;
    // 0x8002E610: lwc1        $f14, 0x2C($t1)
    ctx->f14.u32l = MEM_W(ctx->r9, 0X2C);
    // 0x8002E614: lwc1        $f10, 0xC($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8002E618: lwc1        $f12, -0x4($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, -0X4);
    // 0x8002E61C: mul.s       $f14, $f10, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8002E620: add.s       $f14, $f12, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x8002E624: swc1        $f14, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->f14.u32l;
    // 0x8002E628: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8002E62C: sltu        $at, $v1, $t3
    ctx->r1 = ctx->r3 < ctx->r11 ? 1 : 0;
    // 0x8002E630: bne         $at, $zero, L_8002E52C
    if (ctx->r1 != 0) {
        // 0x8002E634: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_8002E52C;
    }
    // 0x8002E634: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8002E638: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x8002E63C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x8002E640: addiu       $v0, $sp, 0x5C
    ctx->r2 = ADD32(ctx->r29, 0X5C);
L_8002E644:
    // 0x8002E644: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8002E648: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8002E64C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8002E650: swc1        $f6, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->f6.u32l;
    // 0x8002E654: lwc1        $f8, -0xC($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, -0XC);
    // 0x8002E658: swc1        $f8, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f8.u32l;
    // 0x8002E65C: lwc1        $f16, -0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, -0X8);
    // 0x8002E660: swc1        $f16, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f16.u32l;
    // 0x8002E664: lwc1        $f10, -0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, -0X4);
    // 0x8002E668: bne         $a0, $v0, L_8002E644
    if (ctx->r4 != ctx->r2) {
        // 0x8002E66C: swc1        $f10, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
            goto L_8002E644;
    }
    // 0x8002E66C: swc1        $f10, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
    // 0x8002E670: jr          $ra
    // 0x8002E674: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8002E674: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void guMtxF2L(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E680: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x8002E684: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002E688: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8002E68C: addiu       $v1, $a1, 0x20
    ctx->r3 = ADD32(ctx->r5, 0X20);
    // 0x8002E690: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8002E694: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8002E698: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8002E69C: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8002E6A0: lui         $t2, 0xFFFF
    ctx->r10 = S32(0XFFFF << 16);
L_8002E6A4:
    // 0x8002E6A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002E6A8: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x8002E6AC: lwc1        $f14, 0x4($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8002E6B0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002E6B4: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8002E6B8: mul.s       $f16, $f14, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8002E6BC: beq         $a0, $t3, L_8002E724
    if (ctx->r4 == ctx->r11) {
        // 0x8002E6C0: nop
    
            goto L_8002E724;
    }
    // 0x8002E6C0: nop

L_8002E6C4:
    // 0x8002E6C4: mul.s       $f14, $f18, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8002E6C8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002E6CC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8002E6D0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8002E6D4: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x8002E6D8: trunc.w.s   $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8002E6DC: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x8002E6E0: mfc1        $t1, $f12
    ctx->r9 = (int32_t)ctx->f12.u32l;
    // 0x8002E6E4: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x8002E6E8: sra         $t9, $t1, 16
    ctx->r25 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8002E6EC: andi        $t5, $t9, 0xFFFF
    ctx->r13 = ctx->r25 & 0XFFFF;
    // 0x8002E6F0: and         $t8, $a1, $t2
    ctx->r24 = ctx->r5 & ctx->r10;
    // 0x8002E6F4: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x8002E6F8: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x8002E6FC: and         $t9, $t7, $t2
    ctx->r25 = ctx->r15 & ctx->r10;
    // 0x8002E700: sw          $t6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r14;
    // 0x8002E704: andi        $t8, $t1, 0xFFFF
    ctx->r24 = ctx->r9 & 0XFFFF;
    // 0x8002E708: or          $t5, $t9, $t8
    ctx->r13 = ctx->r25 | ctx->r24;
    // 0x8002E70C: sw          $t5, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r13;
    // 0x8002E710: lwc1        $f14, 0x4($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X4);
    // 0x8002E714: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8002E718: mul.s       $f16, $f14, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8002E71C: bne         $a0, $t3, L_8002E6C4
    if (ctx->r4 != ctx->r11) {
        // 0x8002E720: nop
    
            goto L_8002E6C4;
    }
    // 0x8002E720: nop

L_8002E724:
    // 0x8002E724: mul.s       $f14, $f18, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8002E728: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x8002E72C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8002E730: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8002E734: trunc.w.s   $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8002E738: trunc.w.s   $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    ctx->f14.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x8002E73C: mfc1        $t1, $f12
    ctx->r9 = (int32_t)ctx->f12.u32l;
    // 0x8002E740: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x8002E744: sra         $t9, $t1, 16
    ctx->r25 = S32(SIGNED(ctx->r9) >> 16);
    // 0x8002E748: andi        $t5, $t9, 0xFFFF
    ctx->r13 = ctx->r25 & 0XFFFF;
    // 0x8002E74C: and         $t8, $a1, $t2
    ctx->r24 = ctx->r5 & ctx->r10;
    // 0x8002E750: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x8002E754: sll         $t7, $a1, 16
    ctx->r15 = S32(ctx->r5 << 16);
    // 0x8002E758: and         $t9, $t7, $t2
    ctx->r25 = ctx->r15 & ctx->r10;
    // 0x8002E75C: andi        $t8, $t1, 0xFFFF
    ctx->r24 = ctx->r9 & 0XFFFF;
    // 0x8002E760: sw          $t6, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r14;
    // 0x8002E764: or          $t5, $t9, $t8
    ctx->r13 = ctx->r25 | ctx->r24;
    // 0x8002E768: sw          $t5, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r13;
    // 0x8002E76C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8002E770: bne         $a2, $t4, L_8002E6A4
    if (ctx->r6 != ctx->r12) {
        // 0x8002E774: addiu       $a3, $a3, 0x10
        ctx->r7 = ADD32(ctx->r7, 0X10);
            goto L_8002E6A4;
    }
    // 0x8002E774: addiu       $a3, $a3, 0x10
    ctx->r7 = ADD32(ctx->r7, 0X10);
    // 0x8002E778: jr          $ra
    // 0x8002E77C: nop

    return;
    // 0x8002E77C: nop

;}
RECOMP_FUNC void guMtxIdentF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E780: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002E784: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8002E788: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002E78C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8002E790: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8002E794: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002E798: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x8002E79C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8002E7A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
L_8002E7A4:
    // 0x8002E7A4: bnel        $v0, $zero, L_8002E7B8
    if (ctx->r2 != 0) {
        // 0x8002E7A8: swc1        $f2, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
            goto L_8002E7B8;
    }
    goto skip_0;
    // 0x8002E7A8: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
    skip_0:
    // 0x8002E7AC: b           L_8002E7B8
    // 0x8002E7B0: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
        goto L_8002E7B8;
    // 0x8002E7B0: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x8002E7B4: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
L_8002E7B8:
    // 0x8002E7B8: bnel        $v0, $a0, L_8002E7CC
    if (ctx->r2 != ctx->r4) {
        // 0x8002E7BC: swc1        $f2, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
            goto L_8002E7CC;
    }
    goto skip_1;
    // 0x8002E7BC: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
    skip_1:
    // 0x8002E7C0: b           L_8002E7CC
    // 0x8002E7C4: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
        goto L_8002E7CC;
    // 0x8002E7C4: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x8002E7C8: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
L_8002E7CC:
    // 0x8002E7CC: bnel        $v0, $a1, L_8002E7E0
    if (ctx->r2 != ctx->r5) {
        // 0x8002E7D0: swc1        $f2, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
            goto L_8002E7E0;
    }
    goto skip_2;
    // 0x8002E7D0: swc1        $f2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
    skip_2:
    // 0x8002E7D4: b           L_8002E7E0
    // 0x8002E7D8: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
        goto L_8002E7E0;
    // 0x8002E7D8: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x8002E7DC: swc1        $f2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
L_8002E7E0:
    // 0x8002E7E0: bnel        $v0, $a2, L_8002E7F4
    if (ctx->r2 != ctx->r6) {
        // 0x8002E7E4: swc1        $f2, 0xC($v1)
        MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
            goto L_8002E7F4;
    }
    goto skip_3;
    // 0x8002E7E4: swc1        $f2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
    skip_3:
    // 0x8002E7E8: b           L_8002E7F4
    // 0x8002E7EC: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
        goto L_8002E7F4;
    // 0x8002E7EC: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
    // 0x8002E7F0: swc1        $f2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
L_8002E7F4:
    // 0x8002E7F4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8002E7F8: bne         $v0, $a3, L_8002E7A4
    if (ctx->r2 != ctx->r7) {
        // 0x8002E7FC: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_8002E7A4;
    }
    // 0x8002E7FC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8002E800: jr          $ra
    // 0x8002E804: nop

    return;
    // 0x8002E804: nop

;}
RECOMP_FUNC void guMtxIdent(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E808: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8002E80C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002E810: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8002E814: jal         0x8002E780
    // 0x8002E818: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    guMtxIdentF(rdram, ctx);
        goto after_0;
    // 0x8002E818: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x8002E81C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8002E820: jal         0x8002E680
    // 0x8002E824: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    guMtxF2L(rdram, ctx);
        goto after_1;
    // 0x8002E824: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_1:
    // 0x8002E828: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002E82C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8002E830: jr          $ra
    // 0x8002E834: nop

    return;
    // 0x8002E834: nop

;}
RECOMP_FUNC void guMtxL2F(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E838: lui         $at, 0x3780
    ctx->r1 = S32(0X3780 << 16);
    // 0x8002E83C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8002E840: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8002E844: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8002E848: addiu       $v1, $a1, 0x20
    ctx->r3 = ADD32(ctx->r5, 0X20);
    // 0x8002E84C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8002E850: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x8002E854: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8002E858: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8002E85C: lui         $t2, 0xFFFF
    ctx->r10 = S32(0XFFFF << 16);
L_8002E860:
    // 0x8002E860: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002E864: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
L_8002E868:
    // 0x8002E868: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8002E86C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8002E870: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002E874: srl         $t7, $t6, 16
    ctx->r15 = S32(U32(ctx->r14) >> 16);
    // 0x8002E878: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8002E87C: and         $t5, $t9, $t2
    ctx->r13 = ctx->r25 & ctx->r10;
    // 0x8002E880: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x8002E884: sw          $t6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r14;
    // 0x8002E888: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8002E88C: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8002E890: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8002E894: sll         $t5, $t8, 16
    ctx->r13 = S32(ctx->r24 << 16);
    // 0x8002E898: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8002E89C: and         $t6, $t5, $t2
    ctx->r14 = ctx->r13 & ctx->r10;
    // 0x8002E8A0: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x8002E8A4: or          $a3, $t9, $t6
    ctx->r7 = ctx->r25 | ctx->r14;
    // 0x8002E8A8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8002E8AC: mtc1        $a3, $f10
    ctx->f10.u32l = ctx->r7;
    // 0x8002E8B0: sw          $a3, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r7;
    // 0x8002E8B4: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x8002E8B8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8002E8BC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8002E8C0: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8002E8C4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8002E8C8: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8002E8CC: swc1        $f8, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->f8.u32l;
    // 0x8002E8D0: bne         $a0, $t3, L_8002E868
    if (ctx->r4 != ctx->r11) {
        // 0x8002E8D4: swc1        $f18, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->f18.u32l;
            goto L_8002E868;
    }
    // 0x8002E8D4: swc1        $f18, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->f18.u32l;
    // 0x8002E8D8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8002E8DC: bne         $a2, $t4, L_8002E860
    if (ctx->r6 != ctx->r12) {
        // 0x8002E8E0: addiu       $t0, $t0, 0x10
        ctx->r8 = ADD32(ctx->r8, 0X10);
            goto L_8002E860;
    }
    // 0x8002E8E0: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x8002E8E4: jr          $ra
    // 0x8002E8E8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8002E8E8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void guPerspectiveF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002E950: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002E954: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8002E958: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002E95C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8002E960: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8002E964: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8002E968: jal         0x8002E780
    // 0x8002E96C: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    guMtxIdentF(rdram, ctx);
        goto after_0;
    // 0x8002E96C: swc1        $f14, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x8002E970: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8002E974: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8002E978: ldc1        $f6, -0x5E80($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X5E80);
    // 0x8002E97C: cvt.d.s     $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.d = CVT_D_S(ctx->f14.fl);
    // 0x8002E980: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002E984: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8002E988: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002E98C: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x8002E990: div.s       $f12, $f14, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f14.fl, ctx->f10.fl);
    // 0x8002E994: jal         0x8002B190
    // 0x8002E998: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x8002E998: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x8002E99C: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8002E9A0: jal         0x80033960
    // 0x8002E9A4: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x8002E9A4: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x8002E9A8: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8002E9AC: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8002E9B0: lwc1        $f14, 0x40($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8002E9B4: div.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8002E9B8: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8002E9BC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8002E9C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002E9C4: add.s       $f18, $f14, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x8002E9C8: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8002E9CC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002E9D0: sub.s       $f12, $f14, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f14.fl - ctx->f16.fl;
    // 0x8002E9D4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8002E9D8: swc1        $f4, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f4.u32l;
    // 0x8002E9DC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002E9E0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8002E9E4: div.s       $f10, $f18, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8002E9E8: swc1        $f2, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f2.u32l;
    // 0x8002E9EC: div.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8002E9F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8002E9F4: swc1        $f10, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f10.u32l;
    // 0x8002E9F8: swc1        $f8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f8.u32l;
    // 0x8002E9FC: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x8002EA00: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002EA04: nop

    // 0x8002EA08: swc1        $f6, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->f6.u32l;
    // 0x8002EA0C: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8002EA10: div.s       $f4, $f10, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8002EA14: swc1        $f4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f4.u32l;
    // 0x8002EA18: lwc1        $f0, 0x48($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8002EA1C: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002EA20: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002EA24: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8002EA28: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8002EA2C: lwc1        $f12, 0x8($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8002EA30: beq         $v1, $a0, L_8002EA74
    if (ctx->r3 == ctx->r4) {
        // 0x8002EA34: lwc1        $f14, 0xC($v0)
        ctx->f14.u32l = MEM_W(ctx->r2, 0XC);
            goto L_8002EA74;
    }
    // 0x8002EA34: lwc1        $f14, 0xC($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0XC);
L_8002EA38:
    // 0x8002EA38: mul.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8002EA3C: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8002EA40: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8002EA44: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8002EA48: lwc1        $f12, 0x18($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8002EA4C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002EA50: mul.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8002EA54: lwc1        $f14, 0x1C($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8002EA58: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x8002EA5C: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8002EA60: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x8002EA64: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x8002EA68: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8002EA6C: bne         $v1, $a0, L_8002EA38
    if (ctx->r3 != ctx->r4) {
        // 0x8002EA70: swc1        $f2, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
            goto L_8002EA38;
    }
    // 0x8002EA70: swc1        $f2, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
L_8002EA74:
    // 0x8002EA74: mul.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8002EA78: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8002EA7C: swc1        $f10, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->f10.u32l;
    // 0x8002EA80: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8002EA84: nop

    // 0x8002EA88: mul.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8002EA8C: swc1        $f8, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->f8.u32l;
    // 0x8002EA90: swc1        $f4, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->f4.u32l;
    // 0x8002EA94: swc1        $f2, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f2.u32l;
    // 0x8002EA98: beq         $a1, $zero, L_8002EB70
    if (ctx->r5 == 0) {
        // 0x8002EA9C: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_8002EB70;
    }
    // 0x8002EA9C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8002EAA0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8002EAA4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8002EAA8: cvt.d.s     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.d = CVT_D_S(ctx->f18.fl);
    // 0x8002EAAC: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x8002EAB0: c.le.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d <= ctx->f8.d;
    // 0x8002EAB4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8002EAB8: bc1fl       L_8002EACC
    if (!c1cs) {
        // 0x8002EABC: mtc1        $at, $f11
        ctx->f_odd[(11 - 1) * 2] = ctx->r1;
            goto L_8002EACC;
    }
    goto skip_0;
    // 0x8002EABC: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    skip_0:
    // 0x8002EAC0: b           L_8002EB70
    // 0x8002EAC4: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
        goto L_8002EB70;
    // 0x8002EAC4: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x8002EAC8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
L_8002EACC:
    // 0x8002EACC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002EAD0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8002EAD4: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8002EAD8: div.d       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = DIV_D(ctx->f10.d, ctx->f0.d);
    // 0x8002EADC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8002EAE0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8002EAE4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8002EAE8: nop

    // 0x8002EAEC: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x8002EAF0: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8002EAF4: nop

    // 0x8002EAF8: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8002EAFC: beql        $t8, $zero, L_8002EB50
    if (ctx->r24 == 0) {
        // 0x8002EB00: mfc1        $t8, $f6
        ctx->r24 = (int32_t)ctx->f6.u32l;
            goto L_8002EB50;
    }
    goto skip_1;
    // 0x8002EB00: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    skip_1:
    // 0x8002EB04: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8002EB08: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8002EB0C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8002EB10: sub.d       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f6.d = ctx->f4.d - ctx->f6.d;
    // 0x8002EB14: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8002EB18: nop

    // 0x8002EB1C: cvt.w.d     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_D(ctx->f6.d);
    // 0x8002EB20: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8002EB24: nop

    // 0x8002EB28: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8002EB2C: bne         $t8, $zero, L_8002EB44
    if (ctx->r24 != 0) {
        // 0x8002EB30: nop
    
            goto L_8002EB44;
    }
    // 0x8002EB30: nop

    // 0x8002EB34: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x8002EB38: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8002EB3C: b           L_8002EB5C
    // 0x8002EB40: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_8002EB5C;
    // 0x8002EB40: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_8002EB44:
    // 0x8002EB44: b           L_8002EB5C
    // 0x8002EB48: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_8002EB5C;
    // 0x8002EB48: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8002EB4C: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
L_8002EB50:
    // 0x8002EB50: nop

    // 0x8002EB54: bltz        $t8, L_8002EB44
    if (SIGNED(ctx->r24) < 0) {
        // 0x8002EB58: nop
    
            goto L_8002EB44;
    }
    // 0x8002EB58: nop

L_8002EB5C:
    // 0x8002EB5C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8002EB60: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x8002EB64: bgtz        $t9, L_8002EB70
    if (SIGNED(ctx->r25) > 0) {
        // 0x8002EB68: sh          $t8, 0x0($a1)
        MEM_H(0X0, ctx->r5) = ctx->r24;
            goto L_8002EB70;
    }
    // 0x8002EB68: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x8002EB6C: sh          $t0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r8;
L_8002EB70:
    // 0x8002EB70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002EB74: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8002EB78: jr          $ra
    // 0x8002EB7C: nop

    return;
    // 0x8002EB7C: nop

;}
RECOMP_FUNC void guPerspective(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002EB80: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8002EB84: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8002EB88: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x8002EB8C: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8002EB90: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8002EB94: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8002EB98: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8002EB9C: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x8002EBA0: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x8002EBA4: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x8002EBA8: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8002EBAC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8002EBB0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x8002EBB4: jal         0x8002E950
    // 0x8002EBB8: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    guPerspectiveF(rdram, ctx);
        goto after_0;
    // 0x8002EBB8: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8002EBBC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8002EBC0: jal         0x8002E680
    // 0x8002EBC4: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    guMtxF2L(rdram, ctx);
        goto after_1;
    // 0x8002EBC4: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    after_1:
    // 0x8002EBC8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8002EBCC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8002EBD0: jr          $ra
    // 0x8002EBD4: nop

    return;
    // 0x8002EBD4: nop

;}
RECOMP_FUNC void __osPfsDeclarePage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F064: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8002F068: lbu         $t6, 0x63($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X63);
    // 0x8002F06C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002F070: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8002F074: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8002F078: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x8002F07C: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x8002F080: blez        $t6, L_8002F094
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8002F084: sw          $zero, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = 0;
            goto L_8002F094;
    }
    // 0x8002F084: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8002F088: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8002F08C: b           L_8002F0A0
    // 0x8002F090: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
        goto L_8002F0A0;
    // 0x8002F090: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
L_8002F094:
    // 0x8002F094: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8002F098: lw          $t9, 0x60($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X60);
    // 0x8002F09C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
L_8002F0A0:
    // 0x8002F0A0: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8002F0A4: slti        $at, $t0, 0x80
    ctx->r1 = SIGNED(ctx->r8) < 0X80 ? 1 : 0;
    // 0x8002F0A8: beq         $at, $zero, L_8002F0E4
    if (ctx->r1 == 0) {
        // 0x8002F0AC: sw          $t0, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r8;
            goto L_8002F0E4;
    }
    // 0x8002F0AC: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
L_8002F0B0:
    // 0x8002F0B0: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x8002F0B4: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x8002F0B8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8002F0BC: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8002F0C0: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8002F0C4: lhu         $t5, 0x0($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X0);
    // 0x8002F0C8: beq         $t5, $at, L_8002F0E4
    if (ctx->r13 == ctx->r1) {
        // 0x8002F0CC: nop
    
            goto L_8002F0E4;
    }
    // 0x8002F0CC: nop

    // 0x8002F0D0: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x8002F0D4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8002F0D8: slti        $at, $t7, 0x80
    ctx->r1 = SIGNED(ctx->r15) < 0X80 ? 1 : 0;
    // 0x8002F0DC: bne         $at, $zero, L_8002F0B0
    if (ctx->r1 != 0) {
        // 0x8002F0E0: sw          $t7, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r15;
            goto L_8002F0B0;
    }
    // 0x8002F0E0: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
L_8002F0E4:
    // 0x8002F0E4: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x8002F0E8: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x8002F0EC: bne         $t8, $at, L_8002F108
    if (ctx->r24 != ctx->r1) {
        // 0x8002F0F0: nop
    
            goto L_8002F108;
    }
    // 0x8002F0F0: nop

    // 0x8002F0F4: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x8002F0F8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8002F0FC: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8002F100: b           L_8002F2B8
    // 0x8002F104: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
        goto L_8002F2B8;
    // 0x8002F104: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_8002F108:
    // 0x8002F108: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_8002F10C:
    // 0x8002F10C: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8002F110: addu        $t1, $sp, $t2
    ctx->r9 = ADD32(ctx->r29, ctx->r10);
    // 0x8002F114: sb          $zero, 0x24($t1)
    MEM_B(0X24, ctx->r9) = 0;
    // 0x8002F118: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8002F11C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8002F120: slti        $at, $t4, 0x20
    ctx->r1 = SIGNED(ctx->r12) < 0X20 ? 1 : 0;
    // 0x8002F124: bne         $at, $zero, L_8002F10C
    if (ctx->r1 != 0) {
        // 0x8002F128: sw          $t4, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r12;
            goto L_8002F10C;
    }
    // 0x8002F128: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x8002F12C: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x8002F130: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x8002F134: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8002F138: sw          $t5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r13;
    // 0x8002F13C: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8002F140: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x8002F144: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x8002F148: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x8002F14C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8002F150: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    // 0x8002F154: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x8002F158: lw          $t1, 0x0($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X0);
    // 0x8002F15C: slt         $at, $t1, $t0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8002F160: beq         $at, $zero, L_8002F234
    if (ctx->r1 == 0) {
        // 0x8002F164: slti        $at, $t9, 0x80
        ctx->r1 = SIGNED(ctx->r25) < 0X80 ? 1 : 0;
            goto L_8002F234;
    }
    // 0x8002F164: slti        $at, $t9, 0x80
    ctx->r1 = SIGNED(ctx->r25) < 0X80 ? 1 : 0;
    // 0x8002F168: beq         $at, $zero, L_8002F234
    if (ctx->r1 == 0) {
        // 0x8002F16C: nop
    
            goto L_8002F234;
    }
    // 0x8002F16C: nop

L_8002F170:
    // 0x8002F170: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x8002F174: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x8002F178: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8002F17C: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8002F180: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8002F184: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x8002F188: bne         $t7, $at, L_8002F200
    if (ctx->r15 != ctx->r1) {
        // 0x8002F18C: nop
    
            goto L_8002F200;
    }
    // 0x8002F18C: nop

    // 0x8002F190: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8002F194: lbu         $t8, 0x63($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X63);
    // 0x8002F198: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x8002F19C: sll         $t0, $t2, 1
    ctx->r8 = S32(ctx->r10 << 1);
    // 0x8002F1A0: addu        $t1, $t3, $t0
    ctx->r9 = ADD32(ctx->r11, ctx->r8);
    // 0x8002F1A4: sb          $t8, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r24;
    // 0x8002F1A8: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x8002F1AC: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x8002F1B0: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x8002F1B4: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x8002F1B8: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x8002F1BC: sb          $t9, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r25;
    // 0x8002F1C0: lbu         $a3, 0x63($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X63);
    // 0x8002F1C4: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8002F1C8: jal         0x8002F2C8
    // 0x8002F1CC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    __osClearPage(rdram, ctx);
        goto after_0;
    // 0x8002F1CC: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_0:
    // 0x8002F1D0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8002F1D4: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x8002F1D8: beq         $t2, $zero, L_8002F1E8
    if (ctx->r10 == 0) {
        // 0x8002F1DC: nop
    
            goto L_8002F1E8;
    }
    // 0x8002F1DC: nop

    // 0x8002F1E0: b           L_8002F2B8
    // 0x8002F1E4: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
        goto L_8002F2B8;
    // 0x8002F1E4: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_8002F1E8:
    // 0x8002F1E8: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x8002F1EC: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x8002F1F0: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x8002F1F4: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x8002F1F8: addiu       $t1, $t8, 0x1
    ctx->r9 = ADD32(ctx->r24, 0X1);
    // 0x8002F1FC: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
L_8002F200:
    // 0x8002F200: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x8002F204: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x8002F208: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x8002F20C: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x8002F210: sw          $t4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r12;
    // 0x8002F214: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x8002F218: slt         $at, $t7, $t6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8002F21C: beq         $at, $zero, L_8002F234
    if (ctx->r1 == 0) {
        // 0x8002F220: nop
    
            goto L_8002F234;
    }
    // 0x8002F220: nop

    // 0x8002F224: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x8002F228: slti        $at, $t2, 0x80
    ctx->r1 = SIGNED(ctx->r10) < 0X80 ? 1 : 0;
    // 0x8002F22C: bne         $at, $zero, L_8002F170
    if (ctx->r1 != 0) {
        // 0x8002F230: nop
    
            goto L_8002F170;
    }
    // 0x8002F230: nop

L_8002F234:
    // 0x8002F234: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x8002F238: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x8002F23C: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x8002F240: sw          $t3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r11;
    // 0x8002F244: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x8002F248: bne         $t1, $at, L_8002F27C
    if (ctx->r9 != ctx->r1) {
        // 0x8002F24C: nop
    
            goto L_8002F27C;
    }
    // 0x8002F24C: nop

    // 0x8002F250: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x8002F254: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x8002F258: lw          $t4, 0x0($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X0);
    // 0x8002F25C: slt         $at, $t4, $t0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8002F260: beq         $at, $zero, L_8002F27C
    if (ctx->r1 == 0) {
        // 0x8002F264: nop
    
            goto L_8002F27C;
    }
    // 0x8002F264: nop

    // 0x8002F268: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8002F26C: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x8002F270: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8002F274: b           L_8002F2B8
    // 0x8002F278: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
        goto L_8002F2B8;
    // 0x8002F278: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_8002F27C:
    // 0x8002F27C: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8002F280: lw          $t2, 0x54($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X54);
    // 0x8002F284: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8002F288: sll         $t8, $t3, 1
    ctx->r24 = S32(ctx->r11 << 1);
    // 0x8002F28C: addu        $t1, $t2, $t8
    ctx->r9 = ADD32(ctx->r10, ctx->r24);
    // 0x8002F290: sh          $t7, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r15;
    // 0x8002F294: lbu         $a3, 0x63($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X63);
    // 0x8002F298: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x8002F29C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x8002F2A0: jal         0x8002F2C8
    // 0x8002F2A4: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    __osClearPage(rdram, ctx);
        goto after_1;
    // 0x8002F2A4: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x8002F2A8: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x8002F2AC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8002F2B0: sw          $zero, 0x0($t5)
    MEM_W(0X0, ctx->r13) = 0;
    // 0x8002F2B4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_8002F2B8:
    // 0x8002F2B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002F2BC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8002F2C0: jr          $ra
    // 0x8002F2C4: nop

    return;
    // 0x8002F2C4: nop

;}
RECOMP_FUNC void __osClearPage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F2C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002F2CC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8002F2D0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8002F2D4: lbu         $t6, 0x37($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X37);
    // 0x8002F2D8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8002F2DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002F2E0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8002F2E4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8002F2E8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8002F2EC: sb          $t6, 0x65($t7)
    MEM_B(0X65, ctx->r15) = ctx->r14;
    // 0x8002F2F0: jal         0x8003007C
    // 0x8002F2F4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    __osPfsSelectBank_recomp(rdram, ctx);
        goto after_0;
    // 0x8002F2F4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_0:
    // 0x8002F2F8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8002F2FC: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8002F300: beq         $t8, $zero, L_8002F310
    if (ctx->r24 == 0) {
        // 0x8002F304: nop
    
            goto L_8002F310;
    }
    // 0x8002F304: nop

    // 0x8002F308: b           L_8002F378
    // 0x8002F30C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_8002F378;
    // 0x8002F30C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_8002F310:
    // 0x8002F310: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_8002F314:
    // 0x8002F314: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8002F318: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8002F31C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8002F320: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    // 0x8002F324: lw          $a1, 0x8($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X8);
    // 0x8002F328: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x8002F32C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8002F330: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8002F334: jal         0x8002DED0
    // 0x8002F338: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    __osContRamWrite_recomp(rdram, ctx);
        goto after_1;
    // 0x8002F338: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    after_1:
    // 0x8002F33C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8002F340: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x8002F344: bne         $t3, $zero, L_8002F360
    if (ctx->r11 != 0) {
        // 0x8002F348: nop
    
            goto L_8002F360;
    }
    // 0x8002F348: nop

    // 0x8002F34C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8002F350: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8002F354: slti        $at, $t5, 0x8
    ctx->r1 = SIGNED(ctx->r13) < 0X8 ? 1 : 0;
    // 0x8002F358: bne         $at, $zero, L_8002F314
    if (ctx->r1 != 0) {
        // 0x8002F35C: sw          $t5, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r13;
            goto L_8002F314;
    }
    // 0x8002F35C: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
L_8002F360:
    // 0x8002F360: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8002F364: sb          $zero, 0x65($t6)
    MEM_B(0X65, ctx->r14) = 0;
    // 0x8002F368: jal         0x8003007C
    // 0x8002F36C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    __osPfsSelectBank_recomp(rdram, ctx);
        goto after_2;
    // 0x8002F36C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8002F370: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8002F374: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
L_8002F378:
    // 0x8002F378: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8002F37C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002F380: jr          $ra
    // 0x8002F384: nop

    return;
    // 0x8002F384: nop

;}
RECOMP_FUNC void __osSumcalc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F390: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8002F394: sw          $zero, 0x8($sp)
    MEM_W(0X8, ctx->r29) = 0;
    // 0x8002F398: sw          $a0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r4;
    // 0x8002F39C: blez        $a1, L_8002F3E0
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8002F3A0: sw          $zero, 0xC($sp)
        MEM_W(0XC, ctx->r29) = 0;
            goto L_8002F3E0;
    }
    // 0x8002F3A0: sw          $zero, 0xC($sp)
    MEM_W(0XC, ctx->r29) = 0;
L_8002F3A4:
    // 0x8002F3A4: lw          $t7, 0x4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4);
    // 0x8002F3A8: lw          $t6, 0x8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8);
    // 0x8002F3AC: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x8002F3B0: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x8002F3B4: addiu       $t0, $t7, 0x1
    ctx->r8 = ADD32(ctx->r15, 0X1);
    // 0x8002F3B8: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x8002F3BC: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8002F3C0: sw          $t9, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r25;
    // 0x8002F3C4: lw          $t1, 0x8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8);
    // 0x8002F3C8: slt         $at, $t4, $a1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8002F3CC: sw          $t4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r12;
    // 0x8002F3D0: andi        $t2, $t1, 0xFFFF
    ctx->r10 = ctx->r9 & 0XFFFF;
    // 0x8002F3D4: sw          $t0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r8;
    // 0x8002F3D8: bne         $at, $zero, L_8002F3A4
    if (ctx->r1 != 0) {
        // 0x8002F3DC: sw          $t2, 0x8($sp)
        MEM_W(0X8, ctx->r29) = ctx->r10;
            goto L_8002F3A4;
    }
    // 0x8002F3DC: sw          $t2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r10;
L_8002F3E0:
    // 0x8002F3E0: lhu         $v0, 0xA($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0XA);
    // 0x8002F3E4: jr          $ra
    // 0x8002F3E8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8002F3E8: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void __osIdCheckSum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F3EC: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8002F3F0: sh          $zero, 0x6($sp)
    MEM_H(0X6, ctx->r29) = 0;
    // 0x8002F3F4: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
    // 0x8002F3F8: lhu         $t6, 0x0($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X0);
    // 0x8002F3FC: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x8002F400: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_8002F404:
    // 0x8002F404: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x8002F408: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x8002F40C: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x8002F410: sh          $t9, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r25;
    // 0x8002F414: lhu         $t0, 0x0($a1)
    ctx->r8 = MEM_HU(ctx->r5, 0X0);
    // 0x8002F418: addu        $t1, $t0, $t9
    ctx->r9 = ADD32(ctx->r8, ctx->r25);
    // 0x8002F41C: sh          $t1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r9;
    // 0x8002F420: lhu         $t3, 0x6($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X6);
    // 0x8002F424: lhu         $t2, 0x0($a2)
    ctx->r10 = MEM_HU(ctx->r6, 0X0);
    // 0x8002F428: nor         $t4, $t3, $zero
    ctx->r12 = ~(ctx->r11 | 0);
    // 0x8002F42C: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8002F430: sh          $t5, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r13;
    // 0x8002F434: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x8002F438: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x8002F43C: sltiu       $at, $t7, 0x1C
    ctx->r1 = ctx->r15 < 0X1C ? 1 : 0;
    // 0x8002F440: bne         $at, $zero, L_8002F404
    if (ctx->r1 != 0) {
        // 0x8002F444: sw          $t7, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r15;
            goto L_8002F404;
    }
    // 0x8002F444: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x8002F448: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002F44C: jr          $ra
    // 0x8002F450: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8002F450: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void __osPfsReleasePages(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800303D0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800303D4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800303D8: lbu         $t8, 0x33($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X33);
    // 0x800303DC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800303E0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800303E4: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800303E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800303EC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800303F0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800303F4: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800303F8: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x800303FC: lhu         $at, 0x0($t0)
    ctx->r1 = MEM_HU(ctx->r8, 0X0);
    // 0x80030400: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
    // 0x80030404: sh          $at, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r1;
    // 0x80030408: lhu         $t4, 0x24($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X24);
    // 0x8003040C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80030410: beq         $t4, $at, L_80030440
    if (ctx->r12 == ctx->r1) {
        // 0x80030414: nop
    
            goto L_80030440;
    }
    // 0x80030414: nop

    // 0x80030418: lbu         $t5, 0x24($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X24);
    // 0x8003041C: blez        $t5, L_80030430
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80030420: nop
    
            goto L_80030430;
    }
    // 0x80030420: nop

    // 0x80030424: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80030428: b           L_80030464
    // 0x8003042C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
        goto L_80030464;
    // 0x8003042C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
L_80030430:
    // 0x80030430: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80030434: lw          $t9, 0x60($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X60);
    // 0x80030438: b           L_80030464
    // 0x8003043C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
        goto L_80030464;
    // 0x8003043C: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
L_80030440:
    // 0x80030440: lbu         $t2, 0x3B($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X3B);
    // 0x80030444: blez        $t2, L_80030458
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80030448: nop
    
            goto L_80030458;
    }
    // 0x80030448: nop

    // 0x8003044C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80030450: b           L_80030464
    // 0x80030454: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
        goto L_80030464;
    // 0x80030454: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
L_80030458:
    // 0x80030458: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8003045C: lw          $t0, 0x60($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X60);
    // 0x80030460: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
L_80030464:
    // 0x80030464: lbu         $t3, 0x25($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X25);
    // 0x80030468: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x8003046C: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80030470: beq         $at, $zero, L_80030490
    if (ctx->r1 == 0) {
        // 0x80030474: nop
    
            goto L_80030490;
    }
    // 0x80030474: nop

    // 0x80030478: lhu         $t5, 0x24($sp)
    ctx->r13 = MEM_HU(ctx->r29, 0X24);
    // 0x8003047C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80030480: beq         $t5, $at, L_80030490
    if (ctx->r13 == ctx->r1) {
        // 0x80030484: nop
    
            goto L_80030490;
    }
    // 0x80030484: nop

    // 0x80030488: b           L_80030608
    // 0x8003048C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80030608;
    // 0x8003048C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80030490:
    // 0x80030490: addiu       $t7, $sp, 0x24
    ctx->r15 = ADD32(ctx->r29, 0X24);
    // 0x80030494: lhu         $at, 0x0($t7)
    ctx->r1 = MEM_HU(ctx->r15, 0X0);
    // 0x80030498: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x8003049C: sh          $at, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r1;
    // 0x800304A0: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800304A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800304A8: bne         $t1, $at, L_800304C8
    if (ctx->r9 != ctx->r1) {
        // 0x800304AC: nop
    
            goto L_800304C8;
    }
    // 0x800304AC: nop

    // 0x800304B0: lbu         $t3, 0x33($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X33);
    // 0x800304B4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800304B8: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800304BC: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x800304C0: addu        $t5, $t0, $t4
    ctx->r13 = ADD32(ctx->r8, ctx->r12);
    // 0x800304C4: sh          $t6, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r14;
L_800304C8:
    // 0x800304C8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800304CC: lbu         $a1, 0x33($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X33);
    // 0x800304D0: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800304D4: jal         0x80030618
    // 0x800304D8: lbu         $a3, 0x3B($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X3B);
    __osBlockSum(rdram, ctx);
        goto after_0;
    // 0x800304D8: lbu         $a3, 0x3B($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X3B);
    after_0:
    // 0x800304DC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800304E0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800304E4: beq         $t9, $zero, L_800304F4
    if (ctx->r25 == 0) {
        // 0x800304E8: nop
    
            goto L_800304F4;
    }
    // 0x800304E8: nop

    // 0x800304EC: b           L_80030608
    // 0x800304F0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_80030608;
    // 0x800304F0: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800304F4:
    // 0x800304F4: lhu         $t8, 0x24($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X24);
    // 0x800304F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800304FC: bne         $t8, $at, L_8003050C
    if (ctx->r24 != ctx->r1) {
        // 0x80030500: nop
    
            goto L_8003050C;
    }
    // 0x80030500: nop

    // 0x80030504: b           L_80030608
    // 0x80030508: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80030608;
    // 0x80030508: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8003050C:
    // 0x8003050C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80030510: lhu         $t7, 0x24($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X24);
    // 0x80030514: lw          $t1, 0x60($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X60);
    // 0x80030518: slt         $at, $t7, $t1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8003051C: bne         $at, $zero, L_800305B4
    if (ctx->r1 != 0) {
        // 0x80030520: nop
    
            goto L_800305B4;
    }
    // 0x80030520: nop

L_80030524:
    // 0x80030524: lbu         $t6, 0x25($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X25);
    // 0x80030528: lhu         $t3, 0x24($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X24);
    // 0x8003052C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x80030530: sll         $t5, $t6, 1
    ctx->r13 = S32(ctx->r14 << 1);
    // 0x80030534: sh          $t3, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r11;
    // 0x80030538: addu        $t9, $t4, $t5
    ctx->r25 = ADD32(ctx->r12, ctx->r13);
    // 0x8003053C: lhu         $at, 0x0($t9)
    ctx->r1 = MEM_HU(ctx->r25, 0X0);
    // 0x80030540: addiu       $t0, $sp, 0x24
    ctx->r8 = ADD32(ctx->r29, 0X24);
    // 0x80030544: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80030548: sh          $at, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r1;
    // 0x8003054C: lbu         $t3, 0x21($sp)
    ctx->r11 = MEM_BU(ctx->r29, 0X21);
    // 0x80030550: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80030554: sll         $t6, $t3, 1
    ctx->r14 = S32(ctx->r11 << 1);
    // 0x80030558: addu        $t4, $t1, $t6
    ctx->r12 = ADD32(ctx->r9, ctx->r14);
    // 0x8003055C: sh          $t7, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r15;
    // 0x80030560: lbu         $a3, 0x3B($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X3B);
    // 0x80030564: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80030568: lbu         $a1, 0x21($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X21);
    // 0x8003056C: jal         0x80030618
    // 0x80030570: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    __osBlockSum(rdram, ctx);
        goto after_1;
    // 0x80030570: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80030574: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80030578: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x8003057C: beq         $t5, $zero, L_8003058C
    if (ctx->r13 == 0) {
        // 0x80030580: nop
    
            goto L_8003058C;
    }
    // 0x80030580: nop

    // 0x80030584: b           L_80030608
    // 0x80030588: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
        goto L_80030608;
    // 0x80030588: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_8003058C:
    // 0x8003058C: lbu         $t8, 0x24($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X24);
    // 0x80030590: lbu         $t0, 0x3B($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X3B);
    // 0x80030594: bne         $t8, $t0, L_800305B4
    if (ctx->r24 != ctx->r8) {
        // 0x80030598: nop
    
            goto L_800305B4;
    }
    // 0x80030598: nop

    // 0x8003059C: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800305A0: lhu         $t9, 0x24($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X24);
    // 0x800305A4: lw          $t3, 0x60($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X60);
    // 0x800305A8: slt         $at, $t9, $t3
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800305AC: beq         $at, $zero, L_80030524
    if (ctx->r1 == 0) {
        // 0x800305B0: nop
    
            goto L_80030524;
    }
    // 0x800305B0: nop

L_800305B4:
    // 0x800305B4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800305B8: lhu         $t1, 0x24($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X24);
    // 0x800305BC: lw          $t7, 0x60($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X60);
    // 0x800305C0: slt         $at, $t1, $t7
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800305C4: bne         $at, $zero, L_800305F4
    if (ctx->r1 != 0) {
        // 0x800305C8: nop
    
            goto L_800305F4;
    }
    // 0x800305C8: nop

    // 0x800305CC: lbu         $t4, 0x24($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X24);
    // 0x800305D0: lbu         $t5, 0x3B($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X3B);
    // 0x800305D4: bne         $t4, $t5, L_800305F4
    if (ctx->r12 != ctx->r13) {
        // 0x800305D8: nop
    
            goto L_800305F4;
    }
    // 0x800305D8: nop

    // 0x800305DC: lbu         $t2, 0x25($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X25);
    // 0x800305E0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x800305E4: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x800305E8: sll         $t9, $t2, 1
    ctx->r25 = S32(ctx->r10 << 1);
    // 0x800305EC: addu        $t3, $t0, $t9
    ctx->r11 = ADD32(ctx->r8, ctx->r25);
    // 0x800305F0: sh          $t8, 0x0($t3)
    MEM_H(0X0, ctx->r11) = ctx->r24;
L_800305F4:
    // 0x800305F4: addiu       $t1, $sp, 0x24
    ctx->r9 = ADD32(ctx->r29, 0X24);
    // 0x800305F8: lhu         $at, 0x0($t1)
    ctx->r1 = MEM_HU(ctx->r9, 0X0);
    // 0x800305FC: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80030600: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80030604: sh          $at, 0x0($t6)
    MEM_H(0X0, ctx->r14) = ctx->r1;
L_80030608:
    // 0x80030608: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003060C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80030610: jr          $ra
    // 0x80030614: nop

    return;
    // 0x80030614: nop

;}
RECOMP_FUNC void __osBlockSum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030618: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8003061C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80030620: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80030624: lbu         $t6, 0x4F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X4F);
    // 0x80030628: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x8003062C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80030630: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80030634: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80030638: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x8003063C: sb          $t6, 0x65($t7)
    MEM_B(0X65, ctx->r15) = ctx->r14;
    // 0x80030640: jal         0x8003007C
    // 0x80030644: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    __osPfsSelectBank_recomp(rdram, ctx);
        goto after_0;
    // 0x80030644: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_0:
    // 0x80030648: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x8003064C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80030650: beq         $t8, $zero, L_80030660
    if (ctx->r24 == 0) {
        // 0x80030654: nop
    
            goto L_80030660;
    }
    // 0x80030654: nop

    // 0x80030658: b           L_800306F8
    // 0x8003065C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_800306F8;
    // 0x8003065C: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80030660:
    // 0x80030660: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
L_80030664:
    // 0x80030664: lbu         $t0, 0x47($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X47);
    // 0x80030668: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x8003066C: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x80030670: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x80030674: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x80030678: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    // 0x8003067C: lw          $a1, 0x8($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X8);
    // 0x80030680: jal         0x8002DB70
    // 0x80030684: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    __osContRamRead_recomp(rdram, ctx);
        goto after_1;
    // 0x80030684: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    after_1:
    // 0x80030688: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x8003068C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80030690: beq         $t3, $zero, L_800306B0
    if (ctx->r11 == 0) {
        // 0x80030694: nop
    
            goto L_800306B0;
    }
    // 0x80030694: nop

    // 0x80030698: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8003069C: sb          $zero, 0x65($t4)
    MEM_B(0X65, ctx->r12) = 0;
    // 0x800306A0: jal         0x8003007C
    // 0x800306A4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    __osPfsSelectBank_recomp(rdram, ctx);
        goto after_2;
    // 0x800306A4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_2:
    // 0x800306A8: b           L_800306F8
    // 0x800306AC: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
        goto L_800306F8;
    // 0x800306AC: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
L_800306B0:
    // 0x800306B0: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800306B4: jal         0x8002F390
    // 0x800306B8: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    __osSumcalc(rdram, ctx);
        goto after_3;
    // 0x800306B8: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_3:
    // 0x800306BC: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x800306C0: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x800306C4: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800306C8: sh          $t7, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r15;
    // 0x800306CC: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800306D0: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800306D4: slti        $at, $t9, 0x8
    ctx->r1 = SIGNED(ctx->r25) < 0X8 ? 1 : 0;
    // 0x800306D8: bne         $at, $zero, L_80030664
    if (ctx->r1 != 0) {
        // 0x800306DC: sw          $t9, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r25;
            goto L_80030664;
    }
    // 0x800306DC: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x800306E0: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800306E4: sb          $zero, 0x65($t0)
    MEM_B(0X65, ctx->r8) = 0;
    // 0x800306E8: jal         0x8003007C
    // 0x800306EC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    __osPfsSelectBank_recomp(rdram, ctx);
        goto after_4;
    // 0x800306EC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_4:
    // 0x800306F0: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800306F4: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
L_800306F8:
    // 0x800306F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800306FC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80030700: jr          $ra
    // 0x80030704: nop

    return;
    // 0x80030704: nop

;}
RECOMP_FUNC void guScaleF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033370: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80033374: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80033378: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003337C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80033380: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80033384: jal         0x8002E780
    // 0x80033388: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    guMtxIdentF(rdram, ctx);
        goto after_0;
    // 0x80033388: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003338C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80033390: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80033394: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80033398: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003339C: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x800333A0: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800333A4: swc1        $f6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f6.u32l;
    // 0x800333A8: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800333AC: swc1        $f10, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f10.u32l;
    // 0x800333B0: swc1        $f8, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f8.u32l;
    // 0x800333B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800333B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800333BC: jr          $ra
    // 0x800333C0: nop

    return;
    // 0x800333C0: nop

;}
RECOMP_FUNC void guScale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800333C4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800333C8: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800333CC: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x800333D0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800333D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800333D8: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x800333DC: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x800333E0: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x800333E4: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x800333E8: jal         0x80033370
    // 0x800333EC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    guScaleF(rdram, ctx);
        goto after_0;
    // 0x800333EC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x800333F0: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800333F4: jal         0x8002E680
    // 0x800333F8: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    guMtxF2L(rdram, ctx);
        goto after_1;
    // 0x800333F8: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_1:
    // 0x800333FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80033400: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80033404: jr          $ra
    // 0x80033408: nop

    return;
    // 0x80033408: nop

;}
RECOMP_FUNC void sinf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033960: swc1        $f12, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->f12.u32l;
    // 0x80033964: lw          $v0, 0x0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X0);
    // 0x80033968: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x8003396C: sra         $v1, $v0, 22
    ctx->r3 = S32(SIGNED(ctx->r2) >> 22);
    // 0x80033970: andi        $t6, $v1, 0x1FF
    ctx->r14 = ctx->r3 & 0X1FF;
    // 0x80033974: slti        $at, $t6, 0xFF
    ctx->r1 = SIGNED(ctx->r14) < 0XFF ? 1 : 0;
    // 0x80033978: beq         $at, $zero, L_800339E0
    if (ctx->r1 == 0) {
        // 0x8003397C: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_800339E0;
    }
    // 0x8003397C: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x80033980: slti        $at, $t6, 0xE6
    ctx->r1 = SIGNED(ctx->r14) < 0XE6 ? 1 : 0;
    // 0x80033984: bne         $at, $zero, L_800339D8
    if (ctx->r1 != 0) {
        // 0x80033988: cvt.d.s     $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
            goto L_800339D8;
    }
    // 0x80033988: cvt.d.s     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.d = CVT_D_S(ctx->f4.fl);
    // 0x8003398C: mul.d       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f12.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x80033990: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80033994: addiu       $v1, $v1, -0x5DD0
    ctx->r3 = ADD32(ctx->r3, -0X5DD0);
    // 0x80033998: ldc1        $f6, 0x20($v1)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r3, 0X20);
    // 0x8003399C: ldc1        $f10, 0x18($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X18);
    // 0x800339A0: ldc1        $f4, 0x10($v1)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r3, 0X10);
    // 0x800339A4: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x800339A8: add.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f8.d + ctx->f10.d;
    // 0x800339AC: ldc1        $f10, 0x8($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X8);
    // 0x800339B0: mul.d       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f12.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f12.d);
    // 0x800339B4: add.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d + ctx->f4.d;
    // 0x800339B8: mul.d       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f12.d);
    // 0x800339BC: add.d       $f14, $f10, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f14.d = ctx->f10.d + ctx->f8.d;
    // 0x800339C0: mul.d       $f16, $f2, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x800339C4: nop

    // 0x800339C8: mul.d       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f14.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f14.d);
    // 0x800339CC: add.d       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = ctx->f18.d + ctx->f2.d;
    // 0x800339D0: jr          $ra
    // 0x800339D4: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
    return;
    // 0x800339D4: cvt.s.d     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f0.fl = CVT_S_D(ctx->f4.d);
L_800339D8:
    // 0x800339D8: jr          $ra
    // 0x800339DC: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
    return;
    // 0x800339DC: lwc1        $f0, 0x0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X0);
L_800339E0:
    // 0x800339E0: slti        $at, $v1, 0x136
    ctx->r1 = SIGNED(ctx->r3) < 0X136 ? 1 : 0;
    // 0x800339E4: beq         $at, $zero, L_80033AF8
    if (ctx->r1 == 0) {
        // 0x800339E8: lwc1        $f4, 0x0($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
            goto L_80033AF8;
    }
    // 0x800339E8: lwc1        $f4, 0x0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800339EC: lwc1        $f6, 0x0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X0);
    // 0x800339F0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800339F4: ldc1        $f10, -0x5DA8($at)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r1, -0X5DA8);
    // 0x800339F8: cvt.d.s     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f2.d = CVT_D_S(ctx->f6.fl);
    // 0x800339FC: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x80033A00: mul.d       $f0, $f2, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f0.d = MUL_D(ctx->f2.d, ctx->f10.d);
    // 0x80033A04: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80033A08: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80033A0C: c.le.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d <= ctx->f0.d;
    // 0x80033A10: nop

    // 0x80033A14: bc1fl       L_80033A44
    if (!c1cs) {
        // 0x80033A18: mtc1        $at, $f7
        ctx->f_odd[(7 - 1) * 2] = ctx->r1;
            goto L_80033A44;
    }
    goto skip_0;
    // 0x80033A18: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    skip_0:
    // 0x80033A1C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80033A20: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80033A24: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80033A28: nop

    // 0x80033A2C: add.d       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f0.d + ctx->f16.d;
    // 0x80033A30: trunc.w.d   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_D(ctx->f18.d);
    // 0x80033A34: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80033A38: b           L_80033A60
    // 0x80033A3C: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
        goto L_80033A60;
    // 0x80033A3C: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x80033A40: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
L_80033A44:
    // 0x80033A44: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80033A48: nop

    // 0x80033A4C: sub.d       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f0.d - ctx->f6.d;
    // 0x80033A50: trunc.w.d   $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x80033A54: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80033A58: nop

    // 0x80033A5C: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
L_80033A60:
    // 0x80033A60: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80033A64: ldc1        $f18, -0x5DA0($at)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r1, -0X5DA0);
    // 0x80033A68: cvt.d.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.d = CVT_D_W(ctx->f16.u32l);
    // 0x80033A6C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80033A70: ldc1        $f6, -0x5D98($at)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r1, -0X5D98);
    // 0x80033A74: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80033A78: addiu       $v1, $v1, -0x5DD0
    ctx->r3 = ADD32(ctx->r3, -0X5DD0);
    // 0x80033A7C: mul.d       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f0.d, ctx->f18.d);
    // 0x80033A80: ldc1        $f8, 0x20($v1)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r3, 0X20);
    // 0x80033A84: ldc1        $f18, 0x18($v1)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r3, 0X18);
    // 0x80033A88: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x80033A8C: mul.d       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x80033A90: sub.d       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f2.d = ctx->f2.d - ctx->f4.d;
    // 0x80033A94: sub.d       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f10.d); 
    ctx->f2.d = ctx->f2.d - ctx->f10.d;
    // 0x80033A98: ldc1        $f10, 0x10($v1)
    CHECK_FR(ctx, 10);
    ctx->f10.u64 = LD(ctx->r3, 0X10);
    // 0x80033A9C: mul.d       $f12, $f2, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f12.d = MUL_D(ctx->f2.d, ctx->f2.d);
    // 0x80033AA0: nop

    // 0x80033AA4: mul.d       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f12.d);
    // 0x80033AA8: add.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f16.d + ctx->f18.d;
    // 0x80033AAC: ldc1        $f18, 0x8($v1)
    CHECK_FR(ctx, 18);
    ctx->f18.u64 = LD(ctx->r3, 0X8);
    // 0x80033AB0: mul.d       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f12.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f12.d);
    // 0x80033AB4: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x80033AB8: mul.d       $f16, $f8, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f12.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f12.d);
    // 0x80033ABC: bne         $t9, $zero, L_80033ADC
    if (ctx->r25 != 0) {
        // 0x80033AC0: add.d       $f14, $f18, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f14.d = ctx->f18.d + ctx->f16.d;
            goto L_80033ADC;
    }
    // 0x80033AC0: add.d       $f14, $f18, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f14.d = ctx->f18.d + ctx->f16.d;
    // 0x80033AC4: mul.d       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x80033AC8: nop

    // 0x80033ACC: mul.d       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f14.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f14.d);
    // 0x80033AD0: add.d       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = ctx->f6.d + ctx->f2.d;
    // 0x80033AD4: jr          $ra
    // 0x80033AD8: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    return;
    // 0x80033AD8: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_80033ADC:
    // 0x80033ADC: mul.d       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f12.d); 
    ctx->f8.d = MUL_D(ctx->f2.d, ctx->f12.d);
    // 0x80033AE0: nop

    // 0x80033AE4: mul.d       $f18, $f8, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f14.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f14.d);
    // 0x80033AE8: add.d       $f16, $f18, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f16.d = ctx->f18.d + ctx->f2.d;
    // 0x80033AEC: cvt.s.d     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f0.fl = CVT_S_D(ctx->f16.d);
    // 0x80033AF0: jr          $ra
    // 0x80033AF4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    return;
    // 0x80033AF4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_80033AF8:
    // 0x80033AF8: c.eq.s      $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f4.fl == ctx->f4.fl;
    // 0x80033AFC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80033B00: bc1t        L_80033B14
    if (c1cs) {
        // 0x80033B04: nop
    
            goto L_80033B14;
    }
    // 0x80033B04: nop

    // 0x80033B08: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80033B0C: jr          $ra
    // 0x80033B10: lwc1        $f0, -0x5E90($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5E90);
    return;
    // 0x80033B10: lwc1        $f0, -0x5E90($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5E90);
L_80033B14:
    // 0x80033B14: lwc1        $f0, -0x5D90($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5D90);
    // 0x80033B18: jr          $ra
    // 0x80033B1C: nop

    return;
    // 0x80033B1C: nop

;}
RECOMP_FUNC void proutSprintf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033CA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80033CA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80033CA8: jal         0x800346F0
    // 0x80033CAC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    memcpy_recomp(rdram, ctx);
        goto after_0;
    // 0x80033CAC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80033CB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80033CB4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80033CB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80033CBC: jr          $ra
    // 0x80033CC0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    return;
    // 0x80033CC0: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
;}
RECOMP_FUNC void sprintf_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033CC4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80033CC8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80033CCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80033CD0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80033CD4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80033CD8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80033CDC: lui         $a0, 0x8003
    ctx->r4 = S32(0X8003 << 16);
    // 0x80033CE0: addiu       $a0, $a0, 0x3CA0
    ctx->r4 = ADD32(ctx->r4, 0X3CA0);
    // 0x80033CE4: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // 0x80033CE8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80033CEC: jal         0x80035FD0
    // 0x80033CF0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    _Printf(rdram, ctx);
        goto after_0;
    // 0x80033CF0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_0:
    // 0x80033CF4: bltz        $v0, L_80033D08
    if (SIGNED(ctx->r2) < 0) {
        // 0x80033CF8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80033D08;
    }
    // 0x80033CF8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80033CFC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80033D00: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80033D04: sb          $zero, 0x0($t7)
    MEM_B(0X0, ctx->r15) = 0;
L_80033D08:
    // 0x80033D08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80033D0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80033D10: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80033D14: jr          $ra
    // 0x80033D18: nop

    return;
    // 0x80033D18: nop

;}
RECOMP_FUNC void _VirtualToPhysicalTask(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033D20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80033D24: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80033D28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80033D2C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80033D30: addiu       $t6, $t6, -0x790
    ctx->r14 = ADD32(ctx->r14, -0X790);
    // 0x80033D34: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80033D38: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80033D3C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80033D40: jal         0x80034010
    // 0x80033D44: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    bcopy_recomp(rdram, ctx);
        goto after_0;
    // 0x80033D44: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_0:
    // 0x80033D48: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80033D4C: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x80033D50: beq         $t8, $zero, L_80033D68
    if (ctx->r24 == 0) {
        // 0x80033D54: nop
    
            goto L_80033D68;
    }
    // 0x80033D54: nop

    // 0x80033D58: jal         0x80035120
    // 0x80033D5C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_1;
    // 0x80033D5C: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_1:
    // 0x80033D60: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80033D64: sw          $v0, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->r2;
L_80033D68:
    // 0x80033D68: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80033D6C: lw          $t1, 0x18($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X18);
    // 0x80033D70: beq         $t1, $zero, L_80033D88
    if (ctx->r9 == 0) {
        // 0x80033D74: nop
    
            goto L_80033D88;
    }
    // 0x80033D74: nop

    // 0x80033D78: jal         0x80035120
    // 0x80033D7C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x80033D7C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_2:
    // 0x80033D80: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80033D84: sw          $v0, 0x18($t2)
    MEM_W(0X18, ctx->r10) = ctx->r2;
L_80033D88:
    // 0x80033D88: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80033D8C: lw          $t4, 0x20($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X20);
    // 0x80033D90: beq         $t4, $zero, L_80033DA8
    if (ctx->r12 == 0) {
        // 0x80033D94: nop
    
            goto L_80033DA8;
    }
    // 0x80033D94: nop

    // 0x80033D98: jal         0x80035120
    // 0x80033D9C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_3;
    // 0x80033D9C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    after_3:
    // 0x80033DA0: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80033DA4: sw          $v0, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->r2;
L_80033DA8:
    // 0x80033DA8: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80033DAC: lw          $t7, 0x28($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X28);
    // 0x80033DB0: beq         $t7, $zero, L_80033DC8
    if (ctx->r15 == 0) {
        // 0x80033DB4: nop
    
            goto L_80033DC8;
    }
    // 0x80033DB4: nop

    // 0x80033DB8: jal         0x80035120
    // 0x80033DBC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_4;
    // 0x80033DBC: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_4:
    // 0x80033DC0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80033DC4: sw          $v0, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r2;
L_80033DC8:
    // 0x80033DC8: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80033DCC: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x80033DD0: beq         $t0, $zero, L_80033DE8
    if (ctx->r8 == 0) {
        // 0x80033DD4: nop
    
            goto L_80033DE8;
    }
    // 0x80033DD4: nop

    // 0x80033DD8: jal         0x80035120
    // 0x80033DDC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_5;
    // 0x80033DDC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    after_5:
    // 0x80033DE0: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80033DE4: sw          $v0, 0x2C($t1)
    MEM_W(0X2C, ctx->r9) = ctx->r2;
L_80033DE8:
    // 0x80033DE8: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80033DEC: lw          $t3, 0x30($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X30);
    // 0x80033DF0: beq         $t3, $zero, L_80033E08
    if (ctx->r11 == 0) {
        // 0x80033DF4: nop
    
            goto L_80033E08;
    }
    // 0x80033DF4: nop

    // 0x80033DF8: jal         0x80035120
    // 0x80033DFC: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_6;
    // 0x80033DFC: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_6:
    // 0x80033E00: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80033E04: sw          $v0, 0x30($t4)
    MEM_W(0X30, ctx->r12) = ctx->r2;
L_80033E08:
    // 0x80033E08: lw          $t5, 0x1C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X1C);
    // 0x80033E0C: lw          $t6, 0x38($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X38);
    // 0x80033E10: beq         $t6, $zero, L_80033E28
    if (ctx->r14 == 0) {
        // 0x80033E14: nop
    
            goto L_80033E28;
    }
    // 0x80033E14: nop

    // 0x80033E18: jal         0x80035120
    // 0x80033E1C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_7;
    // 0x80033E1C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_7:
    // 0x80033E20: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80033E24: sw          $v0, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->r2;
L_80033E28:
    // 0x80033E28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80033E2C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80033E30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80033E34: jr          $ra
    // 0x80033E38: nop

    return;
    // 0x80033E38: nop

;}
RECOMP_FUNC void bcopy_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034010: beq         $a2, $zero, L_8003407C
    if (ctx->r6 == 0) {
        // 0x80034014: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_8003407C;
    }
    // 0x80034014: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80034018: beq         $a0, $a1, L_8003407C
    if (ctx->r4 == ctx->r5) {
        // 0x8003401C: slt         $at, $a1, $a0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8003407C;
    }
    // 0x8003401C: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80034020: bnel        $at, $zero, L_80034044
    if (ctx->r1 != 0) {
        // 0x80034024: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_80034044;
    }
    goto skip_0;
    // 0x80034024: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_0:
    // 0x80034028: add         $v0, $a0, $a2
    ctx->r2 = ADD32(ctx->r4, ctx->r6);
    // 0x8003402C: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80034030: beql        $at, $zero, L_80034044
    if (ctx->r1 == 0) {
        // 0x80034034: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_80034044;
    }
    goto skip_1;
    // 0x80034034: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_1:
    // 0x80034038: b           L_800341A8
    // 0x8003403C: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
        goto L_800341A8;
    // 0x8003403C: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    // 0x80034040: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_80034044:
    // 0x80034044: bne         $at, $zero, L_8003405C
    if (ctx->r1 != 0) {
        // 0x80034048: nop
    
            goto L_8003405C;
    }
    // 0x80034048: nop

    // 0x8003404C: andi        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 & 0X3;
    // 0x80034050: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x80034054: beq         $v0, $v1, L_80034084
    if (ctx->r2 == ctx->r3) {
        // 0x80034058: nop
    
            goto L_80034084;
    }
    // 0x80034058: nop

L_8003405C:
    // 0x8003405C: beq         $a2, $zero, L_8003407C
    if (ctx->r6 == 0) {
        // 0x80034060: nop
    
            goto L_8003407C;
    }
    // 0x80034060: nop

    // 0x80034064: addu        $v1, $a0, $a2
    ctx->r3 = ADD32(ctx->r4, ctx->r6);
L_80034068:
    // 0x80034068: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x8003406C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80034070: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80034074: bne         $a0, $v1, L_80034068
    if (ctx->r4 != ctx->r3) {
        // 0x80034078: sb          $v0, -0x1($a1)
        MEM_B(-0X1, ctx->r5) = ctx->r2;
            goto L_80034068;
    }
    // 0x80034078: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
L_8003407C:
    // 0x8003407C: jr          $ra
    // 0x80034080: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x80034080: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_80034084:
    // 0x80034084: beq         $v0, $zero, L_800340E8
    if (ctx->r2 == 0) {
        // 0x80034088: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800340E8;
    }
    // 0x80034088: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003408C: beq         $v0, $at, L_800340CC
    if (ctx->r2 == ctx->r1) {
        // 0x80034090: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800340CC;
    }
    // 0x80034090: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80034094: beql        $v0, $at, L_800340B8
    if (ctx->r2 == ctx->r1) {
        // 0x80034098: lh          $v0, 0x0($a0)
        ctx->r2 = MEM_H(ctx->r4, 0X0);
            goto L_800340B8;
    }
    goto skip_2;
    // 0x80034098: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    skip_2:
    // 0x8003409C: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x800340A0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800340A4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800340A8: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800340AC: b           L_800340E8
    // 0x800340B0: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
        goto L_800340E8;
    // 0x800340B0: sb          $v0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r2;
    // 0x800340B4: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
L_800340B8:
    // 0x800340B8: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800340BC: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x800340C0: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x800340C4: b           L_800340E8
    // 0x800340C8: sh          $v0, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r2;
        goto L_800340E8;
    // 0x800340C8: sh          $v0, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r2;
L_800340CC:
    // 0x800340CC: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x800340D0: lh          $v1, 0x1($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X1);
    // 0x800340D4: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x800340D8: addiu       $a1, $a1, 0x3
    ctx->r5 = ADD32(ctx->r5, 0X3);
    // 0x800340DC: addiu       $a2, $a2, -0x3
    ctx->r6 = ADD32(ctx->r6, -0X3);
    // 0x800340E0: sb          $v0, -0x3($a1)
    MEM_B(-0X3, ctx->r5) = ctx->r2;
    // 0x800340E4: sh          $v1, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r3;
L_800340E8:
    // 0x800340E8: slti        $at, $a2, 0x20
    ctx->r1 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
    // 0x800340EC: bnel        $at, $zero, L_80034148
    if (ctx->r1 != 0) {
        // 0x800340F0: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_80034148;
    }
    goto skip_3;
    // 0x800340F0: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_3:
    // 0x800340F4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800340F8: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x800340FC: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x80034100: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x80034104: lw          $t2, 0x10($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X10);
    // 0x80034108: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x8003410C: lw          $t4, 0x18($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X18);
    // 0x80034110: lw          $t5, 0x1C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X1C);
    // 0x80034114: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x80034118: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // 0x8003411C: addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
    // 0x80034120: sw          $v0, -0x20($a1)
    MEM_W(-0X20, ctx->r5) = ctx->r2;
    // 0x80034124: sw          $v1, -0x1C($a1)
    MEM_W(-0X1C, ctx->r5) = ctx->r3;
    // 0x80034128: sw          $t0, -0x18($a1)
    MEM_W(-0X18, ctx->r5) = ctx->r8;
    // 0x8003412C: sw          $t1, -0x14($a1)
    MEM_W(-0X14, ctx->r5) = ctx->r9;
    // 0x80034130: sw          $t2, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->r10;
    // 0x80034134: sw          $t3, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->r11;
    // 0x80034138: sw          $t4, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->r12;
    // 0x8003413C: b           L_800340E8
    // 0x80034140: sw          $t5, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r13;
        goto L_800340E8;
    // 0x80034140: sw          $t5, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r13;
L_80034144:
    // 0x80034144: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_80034148:
    // 0x80034148: bnel        $at, $zero, L_80034184
    if (ctx->r1 != 0) {
        // 0x8003414C: slti        $at, $a2, 0x4
        ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
            goto L_80034184;
    }
    goto skip_4;
    // 0x8003414C: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    skip_4:
    // 0x80034150: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80034154: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x80034158: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x8003415C: lw          $t1, 0xC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XC);
    // 0x80034160: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80034164: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80034168: addiu       $a2, $a2, -0x10
    ctx->r6 = ADD32(ctx->r6, -0X10);
    // 0x8003416C: sw          $v0, -0x10($a1)
    MEM_W(-0X10, ctx->r5) = ctx->r2;
    // 0x80034170: sw          $v1, -0xC($a1)
    MEM_W(-0XC, ctx->r5) = ctx->r3;
    // 0x80034174: sw          $t0, -0x8($a1)
    MEM_W(-0X8, ctx->r5) = ctx->r8;
    // 0x80034178: b           L_80034144
    // 0x8003417C: sw          $t1, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r9;
        goto L_80034144;
    // 0x8003417C: sw          $t1, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r9;
L_80034180:
    // 0x80034180: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
L_80034184:
    // 0x80034184: bne         $at, $zero, L_8003405C
    if (ctx->r1 != 0) {
        // 0x80034188: nop
    
            goto L_8003405C;
    }
    // 0x80034188: nop

    // 0x8003418C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80034190: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80034194: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80034198: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x8003419C: b           L_80034180
    // 0x800341A0: sw          $v0, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r2;
        goto L_80034180;
    // 0x800341A0: sw          $v0, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = ctx->r2;
    // 0x800341A4: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_800341A8:
    // 0x800341A8: add         $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x800341AC: bne         $at, $zero, L_800341C4
    if (ctx->r1 != 0) {
        // 0x800341B0: add         $a1, $a1, $a2
        ctx->r5 = ADD32(ctx->r5, ctx->r6);
            goto L_800341C4;
    }
    // 0x800341B0: add         $a1, $a1, $a2
    ctx->r5 = ADD32(ctx->r5, ctx->r6);
    // 0x800341B4: andi        $v0, $a0, 0x3
    ctx->r2 = ctx->r4 & 0X3;
    // 0x800341B8: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x800341BC: beq         $v0, $v1, L_800341F4
    if (ctx->r2 == ctx->r3) {
        // 0x800341C0: nop
    
            goto L_800341F4;
    }
    // 0x800341C0: nop

L_800341C4:
    // 0x800341C4: beq         $a2, $zero, L_8003407C
    if (ctx->r6 == 0) {
        // 0x800341C8: nop
    
            goto L_8003407C;
    }
    // 0x800341C8: nop

    // 0x800341CC: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800341D0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800341D4: subu        $v1, $a0, $a2
    ctx->r3 = SUB32(ctx->r4, ctx->r6);
L_800341D8:
    // 0x800341D8: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x800341DC: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800341E0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800341E4: bne         $a0, $v1, L_800341D8
    if (ctx->r4 != ctx->r3) {
        // 0x800341E8: sb          $v0, 0x1($a1)
        MEM_B(0X1, ctx->r5) = ctx->r2;
            goto L_800341D8;
    }
    // 0x800341E8: sb          $v0, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r2;
    // 0x800341EC: jr          $ra
    // 0x800341F0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x800341F0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800341F4:
    // 0x800341F4: beq         $v0, $zero, L_80034258
    if (ctx->r2 == 0) {
        // 0x800341F8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80034258;
    }
    // 0x800341F8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800341FC: beq         $v0, $at, L_8003423C
    if (ctx->r2 == ctx->r1) {
        // 0x80034200: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8003423C;
    }
    // 0x80034200: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80034204: beql        $v0, $at, L_80034228
    if (ctx->r2 == ctx->r1) {
        // 0x80034208: lh          $v0, -0x2($a0)
        ctx->r2 = MEM_H(ctx->r4, -0X2);
            goto L_80034228;
    }
    goto skip_5;
    // 0x80034208: lh          $v0, -0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, -0X2);
    skip_5:
    // 0x8003420C: lb          $v0, -0x1($a0)
    ctx->r2 = MEM_B(ctx->r4, -0X1);
    // 0x80034210: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80034214: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80034218: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8003421C: b           L_80034258
    // 0x80034220: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
        goto L_80034258;
    // 0x80034220: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x80034224: lh          $v0, -0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, -0X2);
L_80034228:
    // 0x80034228: addiu       $a0, $a0, -0x2
    ctx->r4 = ADD32(ctx->r4, -0X2);
    // 0x8003422C: addiu       $a1, $a1, -0x2
    ctx->r5 = ADD32(ctx->r5, -0X2);
    // 0x80034230: addiu       $a2, $a2, -0x2
    ctx->r6 = ADD32(ctx->r6, -0X2);
    // 0x80034234: b           L_80034258
    // 0x80034238: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
        goto L_80034258;
    // 0x80034238: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
L_8003423C:
    // 0x8003423C: lb          $v0, -0x1($a0)
    ctx->r2 = MEM_B(ctx->r4, -0X1);
    // 0x80034240: lh          $v1, -0x3($a0)
    ctx->r3 = MEM_H(ctx->r4, -0X3);
    // 0x80034244: addiu       $a0, $a0, -0x3
    ctx->r4 = ADD32(ctx->r4, -0X3);
    // 0x80034248: addiu       $a1, $a1, -0x3
    ctx->r5 = ADD32(ctx->r5, -0X3);
    // 0x8003424C: addiu       $a2, $a2, -0x3
    ctx->r6 = ADD32(ctx->r6, -0X3);
    // 0x80034250: sb          $v0, 0x2($a1)
    MEM_B(0X2, ctx->r5) = ctx->r2;
    // 0x80034254: sh          $v1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r3;
L_80034258:
    // 0x80034258: slti        $at, $a2, 0x20
    ctx->r1 = SIGNED(ctx->r6) < 0X20 ? 1 : 0;
    // 0x8003425C: bnel        $at, $zero, L_800342B8
    if (ctx->r1 != 0) {
        // 0x80034260: slti        $at, $a2, 0x10
        ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
            goto L_800342B8;
    }
    goto skip_6;
    // 0x80034260: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
    skip_6:
    // 0x80034264: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x80034268: lw          $v1, -0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X8);
    // 0x8003426C: lw          $t0, -0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, -0XC);
    // 0x80034270: lw          $t1, -0x10($a0)
    ctx->r9 = MEM_W(ctx->r4, -0X10);
    // 0x80034274: lw          $t2, -0x14($a0)
    ctx->r10 = MEM_W(ctx->r4, -0X14);
    // 0x80034278: lw          $t3, -0x18($a0)
    ctx->r11 = MEM_W(ctx->r4, -0X18);
    // 0x8003427C: lw          $t4, -0x1C($a0)
    ctx->r12 = MEM_W(ctx->r4, -0X1C);
    // 0x80034280: lw          $t5, -0x20($a0)
    ctx->r13 = MEM_W(ctx->r4, -0X20);
    // 0x80034284: addiu       $a0, $a0, -0x20
    ctx->r4 = ADD32(ctx->r4, -0X20);
    // 0x80034288: addiu       $a1, $a1, -0x20
    ctx->r5 = ADD32(ctx->r5, -0X20);
    // 0x8003428C: addiu       $a2, $a2, -0x20
    ctx->r6 = ADD32(ctx->r6, -0X20);
    // 0x80034290: sw          $v0, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r2;
    // 0x80034294: sw          $v1, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r3;
    // 0x80034298: sw          $t0, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r8;
    // 0x8003429C: sw          $t1, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r9;
    // 0x800342A0: sw          $t2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r10;
    // 0x800342A4: sw          $t3, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r11;
    // 0x800342A8: sw          $t4, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r12;
    // 0x800342AC: b           L_80034258
    // 0x800342B0: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
        goto L_80034258;
    // 0x800342B0: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
L_800342B4:
    // 0x800342B4: slti        $at, $a2, 0x10
    ctx->r1 = SIGNED(ctx->r6) < 0X10 ? 1 : 0;
L_800342B8:
    // 0x800342B8: bnel        $at, $zero, L_800342F4
    if (ctx->r1 != 0) {
        // 0x800342BC: slti        $at, $a2, 0x4
        ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
            goto L_800342F4;
    }
    goto skip_7;
    // 0x800342BC: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    skip_7:
    // 0x800342C0: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x800342C4: lw          $v1, -0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X8);
    // 0x800342C8: lw          $t0, -0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, -0XC);
    // 0x800342CC: lw          $t1, -0x10($a0)
    ctx->r9 = MEM_W(ctx->r4, -0X10);
    // 0x800342D0: addiu       $a0, $a0, -0x10
    ctx->r4 = ADD32(ctx->r4, -0X10);
    // 0x800342D4: addiu       $a1, $a1, -0x10
    ctx->r5 = ADD32(ctx->r5, -0X10);
    // 0x800342D8: addiu       $a2, $a2, -0x10
    ctx->r6 = ADD32(ctx->r6, -0X10);
    // 0x800342DC: sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    // 0x800342E0: sw          $v1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r3;
    // 0x800342E4: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
    // 0x800342E8: b           L_800342B4
    // 0x800342EC: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
        goto L_800342B4;
    // 0x800342EC: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
L_800342F0:
    // 0x800342F0: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
L_800342F4:
    // 0x800342F4: bne         $at, $zero, L_800341C4
    if (ctx->r1 != 0) {
        // 0x800342F8: nop
    
            goto L_800341C4;
    }
    // 0x800342F8: nop

    // 0x800342FC: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x80034300: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x80034304: addiu       $a1, $a1, -0x4
    ctx->r5 = ADD32(ctx->r5, -0X4);
    // 0x80034308: addiu       $a2, $a2, -0x4
    ctx->r6 = ADD32(ctx->r6, -0X4);
    // 0x8003430C: b           L_800342F0
    // 0x80034310: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
        goto L_800342F0;
    // 0x80034310: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
;}
RECOMP_FUNC void memcpy_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800346F0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800346F4: beq         $a2, $zero, L_80034714
    if (ctx->r6 == 0) {
        // 0x800346F8: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_80034714;
    }
    // 0x800346F8: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_800346FC:
    // 0x800346FC: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x80034700: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x80034704: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80034708: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8003470C: bne         $a2, $zero, L_800346FC
    if (ctx->r6 != 0) {
        // 0x80034710: sb          $t6, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = ctx->r14;
            goto L_800346FC;
    }
    // 0x80034710: sb          $t6, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = ctx->r14;
L_80034714:
    // 0x80034714: jr          $ra
    // 0x80034718: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80034718: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void strlen_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003471C: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x80034720: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80034724: beq         $t6, $zero, L_8003473C
    if (ctx->r14 == 0) {
        // 0x80034728: nop
    
            goto L_8003473C;
    }
    // 0x80034728: nop

    // 0x8003472C: lbu         $t7, 0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1);
L_80034730:
    // 0x80034730: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80034734: bnel        $t7, $zero, L_80034730
    if (ctx->r15 != 0) {
        // 0x80034738: lbu         $t7, 0x1($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0X1);
            goto L_80034730;
    }
    goto skip_0;
    // 0x80034738: lbu         $t7, 0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1);
    skip_0:
L_8003473C:
    // 0x8003473C: jr          $ra
    // 0x80034740: subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
    return;
    // 0x80034740: subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
;}
RECOMP_FUNC void strchr_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034744: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x80034748: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8003474C: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x80034750: beql        $t6, $v1, L_8003477C
    if (ctx->r14 == ctx->r3) {
        // 0x80034754: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8003477C;
    }
    goto skip_0;
    // 0x80034754: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    skip_0:
L_80034758:
    // 0x80034758: bnel        $v1, $zero, L_8003476C
    if (ctx->r3 != 0) {
        // 0x8003475C: lbu         $v1, 0x1($a0)
        ctx->r3 = MEM_BU(ctx->r4, 0X1);
            goto L_8003476C;
    }
    goto skip_1;
    // 0x8003475C: lbu         $v1, 0x1($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X1);
    skip_1:
    // 0x80034760: jr          $ra
    // 0x80034764: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80034764: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80034768: lbu         $v1, 0x1($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X1);
L_8003476C:
    // 0x8003476C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80034770: bne         $v0, $v1, L_80034758
    if (ctx->r2 != ctx->r3) {
        // 0x80034774: nop
    
            goto L_80034758;
    }
    // 0x80034774: nop

    // 0x80034778: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8003477C:
    // 0x8003477C: jr          $ra
    // 0x80034780: nop

    return;
    // 0x80034780: nop

;}
RECOMP_FUNC void _Putfld(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035960: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80035964: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80035968: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003596C: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80035970: slti        $at, $t6, 0x26
    ctx->r1 = SIGNED(ctx->r14) < 0X26 ? 1 : 0;
    // 0x80035974: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80035978: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x8003597C: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x80035980: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x80035984: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x80035988: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x8003598C: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x80035990: bne         $at, $zero, L_800359BC
    if (ctx->r1 != 0) {
        // 0x80035994: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_800359BC;
    }
    // 0x80035994: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x80035998: addiu       $t7, $t6, -0x45
    ctx->r15 = ADD32(ctx->r14, -0X45);
    // 0x8003599C: sltiu       $at, $t7, 0x34
    ctx->r1 = ctx->r15 < 0X34 ? 1 : 0;
    // 0x800359A0: beq         $at, $zero, L_80035FA8
    if (ctx->r1 == 0) {
        // 0x800359A4: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80035FA8;
    }
    // 0x800359A4: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800359A8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800359AC: addu        $at, $at, $t7
    gpr jr_addend_800359B4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800359B0: lw          $t7, -0x5D5C($at)
    ctx->r15 = ADD32(ctx->r1, -0X5D5C);
    // 0x800359B4: jr          $t7
    // 0x800359B8: nop

    switch (jr_addend_800359B4 >> 2) {
        case 0: goto L_80035CC8; break;
        case 1: goto L_80035FA8; break;
        case 2: goto L_80035CC8; break;
        case 3: goto L_80035FA8; break;
        case 4: goto L_80035FA8; break;
        case 5: goto L_80035FA8; break;
        case 6: goto L_80035FA8; break;
        case 7: goto L_80035FA8; break;
        case 8: goto L_80035FA8; break;
        case 9: goto L_80035FA8; break;
        case 10: goto L_80035FA8; break;
        case 11: goto L_80035FA8; break;
        case 12: goto L_80035FA8; break;
        case 13: goto L_80035FA8; break;
        case 14: goto L_80035FA8; break;
        case 15: goto L_80035FA8; break;
        case 16: goto L_80035FA8; break;
        case 17: goto L_80035FA8; break;
        case 18: goto L_80035FA8; break;
        case 19: goto L_80035B78; break;
        case 20: goto L_80035FA8; break;
        case 21: goto L_80035FA8; break;
        case 22: goto L_80035FA8; break;
        case 23: goto L_80035FA8; break;
        case 24: goto L_80035FA8; break;
        case 25: goto L_80035FA8; break;
        case 26: goto L_80035FA8; break;
        case 27: goto L_80035FA8; break;
        case 28: goto L_80035FA8; break;
        case 29: goto L_80035FA8; break;
        case 30: goto L_800359D0; break;
        case 31: goto L_80035A08; break;
        case 32: goto L_80035CC8; break;
        case 33: goto L_80035CC8; break;
        case 34: goto L_80035CC8; break;
        case 35: goto L_80035FA8; break;
        case 36: goto L_80035A08; break;
        case 37: goto L_80035FA8; break;
        case 38: goto L_80035FA8; break;
        case 39: goto L_80035FA8; break;
        case 40: goto L_80035FA8; break;
        case 41: goto L_80035E2C; break;
        case 42: goto L_80035B78; break;
        case 43: goto L_80035EFC; break;
        case 44: goto L_80035FA8; break;
        case 45: goto L_80035FA8; break;
        case 46: goto L_80035F44; break;
        case 47: goto L_80035FA8; break;
        case 48: goto L_80035B78; break;
        case 49: goto L_80035FA8; break;
        case 50: goto L_80035FA8; break;
        case 51: goto L_80035B78; break;
        default: switch_error(__func__, 0x800359B4, 0x8003A2A4);
    }
    // 0x800359B8: nop

L_800359BC:
    // 0x800359BC: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x800359C0: beql        $v1, $at, L_80035F8C
    if (ctx->r3 == ctx->r1) {
        // 0x800359C4: lw          $t8, 0xC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XC);
            goto L_80035F8C;
    }
    goto skip_0;
    // 0x800359C4: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    skip_0:
    // 0x800359C8: b           L_80035FAC
    // 0x800359CC: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
        goto L_80035FAC;
    // 0x800359CC: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
L_800359D0:
    // 0x800359D0: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800359D4: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800359D8: addiu       $t9, $t8, 0x3
    ctx->r25 = ADD32(ctx->r24, 0X3);
    // 0x800359DC: and         $t6, $t9, $at
    ctx->r14 = ctx->r25 & ctx->r1;
    // 0x800359E0: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x800359E4: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800359E8: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800359EC: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x800359F0: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x800359F4: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
    // 0x800359F8: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x800359FC: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x80035A00: b           L_80035FC0
    // 0x80035A04: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
        goto L_80035FC0;
    // 0x80035A04: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
L_80035A08:
    // 0x80035A08: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x80035A0C: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x80035A10: bnel        $v0, $at, L_80035A48
    if (ctx->r2 != ctx->r1) {
        // 0x80035A14: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_80035A48;
    }
    goto skip_1;
    // 0x80035A14: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    skip_1:
    // 0x80035A18: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80035A1C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80035A20: addiu       $t7, $t9, 0x3
    ctx->r15 = ADD32(ctx->r25, 0X3);
    // 0x80035A24: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80035A28: addiu       $t6, $t8, 0x4
    ctx->r14 = ADD32(ctx->r24, 0X4);
    // 0x80035A2C: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80035A30: lw          $t7, -0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X4);
    // 0x80035A34: sra         $t8, $t7, 31
    ctx->r24 = S32(SIGNED(ctx->r15) >> 31);
    // 0x80035A38: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80035A3C: b           L_80035AA4
    // 0x80035A40: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
        goto L_80035AA4;
    // 0x80035A40: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x80035A44: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
L_80035A48:
    // 0x80035A48: bnel        $v0, $at, L_80035A80
    if (ctx->r2 != ctx->r1) {
        // 0x80035A4C: lw          $t7, 0x0($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X0);
            goto L_80035A80;
    }
    goto skip_2;
    // 0x80035A4C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    skip_2:
    // 0x80035A50: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80035A54: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x80035A58: addiu       $t7, $t6, 0x7
    ctx->r15 = ADD32(ctx->r14, 0X7);
    // 0x80035A5C: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80035A60: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80035A64: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80035A68: lw          $t8, -0x8($t9)
    ctx->r24 = MEM_W(ctx->r25, -0X8);
    // 0x80035A6C: lw          $t9, -0x4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4);
    // 0x80035A70: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80035A74: b           L_80035AA4
    // 0x80035A78: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
        goto L_80035AA4;
    // 0x80035A78: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x80035A7C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
L_80035A80:
    // 0x80035A80: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80035A84: addiu       $t6, $t7, 0x3
    ctx->r14 = ADD32(ctx->r15, 0X3);
    // 0x80035A88: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x80035A8C: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x80035A90: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80035A94: lw          $t6, -0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, -0X4);
    // 0x80035A98: sra         $t8, $t6, 31
    ctx->r24 = S32(SIGNED(ctx->r14) >> 31);
    // 0x80035A9C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80035AA0: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
L_80035AA4:
    // 0x80035AA4: lbu         $t7, 0x34($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X34);
    // 0x80035AA8: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x80035AAC: bnel        $t7, $at, L_80035AD0
    if (ctx->r15 != ctx->r1) {
        // 0x80035AB0: lw          $t6, 0x0($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X0);
            goto L_80035AD0;
    }
    goto skip_3;
    // 0x80035AB0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    skip_3:
    // 0x80035AB4: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x80035AB8: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x80035ABC: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80035AC0: sra         $t8, $t6, 31
    ctx->r24 = S32(SIGNED(ctx->r14) >> 31);
    // 0x80035AC4: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80035AC8: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x80035ACC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
L_80035AD0:
    // 0x80035AD0: bgtzl       $t6, L_80035B0C
    if (SIGNED(ctx->r14) > 0) {
        // 0x80035AD4: lw          $v0, 0x30($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X30);
            goto L_80035B0C;
    }
    goto skip_4;
    // 0x80035AD4: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    skip_4:
    // 0x80035AD8: bltzl       $t6, L_80035AEC
    if (SIGNED(ctx->r14) < 0) {
        // 0x80035ADC: lw          $t9, 0xC($s0)
        ctx->r25 = MEM_W(ctx->r16, 0XC);
            goto L_80035AEC;
    }
    goto skip_5;
    // 0x80035ADC: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    skip_5:
    // 0x80035AE0: b           L_80035B0C
    // 0x80035AE4: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
        goto L_80035B0C;
    // 0x80035AE4: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    // 0x80035AE8: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
L_80035AEC:
    // 0x80035AEC: addiu       $t8, $zero, 0x2D
    ctx->r24 = ADD32(0, 0X2D);
    // 0x80035AF0: addu        $t6, $a3, $t9
    ctx->r14 = ADD32(ctx->r7, ctx->r25);
    // 0x80035AF4: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
    // 0x80035AF8: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x80035AFC: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x80035B00: b           L_80035B5C
    // 0x80035B04: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
        goto L_80035B5C;
    // 0x80035B04: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
    // 0x80035B08: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
L_80035B0C:
    // 0x80035B0C: andi        $t8, $v0, 0x2
    ctx->r24 = ctx->r2 & 0X2;
    // 0x80035B10: beq         $t8, $zero, L_80035B38
    if (ctx->r24 == 0) {
        // 0x80035B14: andi        $t6, $v0, 0x1
        ctx->r14 = ctx->r2 & 0X1;
            goto L_80035B38;
    }
    // 0x80035B14: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x80035B18: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x80035B1C: addiu       $t6, $zero, 0x2B
    ctx->r14 = ADD32(0, 0X2B);
    // 0x80035B20: addu        $t9, $a3, $t7
    ctx->r25 = ADD32(ctx->r7, ctx->r15);
    // 0x80035B24: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x80035B28: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x80035B2C: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x80035B30: b           L_80035B5C
    // 0x80035B34: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
        goto L_80035B5C;
    // 0x80035B34: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
L_80035B38:
    // 0x80035B38: beql        $t6, $zero, L_80035B60
    if (ctx->r14 == 0) {
        // 0x80035B3C: lw          $t9, 0xC($s0)
        ctx->r25 = MEM_W(ctx->r16, 0XC);
            goto L_80035B60;
    }
    goto skip_6;
    // 0x80035B3C: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    skip_6:
    // 0x80035B40: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x80035B44: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x80035B48: addu        $t7, $a3, $t8
    ctx->r15 = ADD32(ctx->r7, ctx->r24);
    // 0x80035B4C: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
    // 0x80035B50: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x80035B54: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x80035B58: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
L_80035B5C:
    // 0x80035B5C: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
L_80035B60:
    // 0x80035B60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80035B64: addu        $t7, $t9, $a3
    ctx->r15 = ADD32(ctx->r25, ctx->r7);
    // 0x80035B68: jal         0x80037270
    // 0x80035B6C: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    _Litob(rdram, ctx);
        goto after_0;
    // 0x80035B6C: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    after_0:
    // 0x80035B70: b           L_80035FC4
    // 0x80035B74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80035FC4;
    // 0x80035B74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80035B78:
    // 0x80035B78: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x80035B7C: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x80035B80: bnel        $v0, $at, L_80035BB8
    if (ctx->r2 != ctx->r1) {
        // 0x80035B84: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_80035BB8;
    }
    goto skip_7;
    // 0x80035B84: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    skip_7:
    // 0x80035B88: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80035B8C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80035B90: addiu       $t8, $t6, 0x3
    ctx->r24 = ADD32(ctx->r14, 0X3);
    // 0x80035B94: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x80035B98: addiu       $t7, $t9, 0x4
    ctx->r15 = ADD32(ctx->r25, 0X4);
    // 0x80035B9C: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80035BA0: lw          $t8, -0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X4);
    // 0x80035BA4: sra         $t6, $t8, 31
    ctx->r14 = S32(SIGNED(ctx->r24) >> 31);
    // 0x80035BA8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80035BAC: b           L_80035C14
    // 0x80035BB0: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
        goto L_80035C14;
    // 0x80035BB0: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x80035BB4: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
L_80035BB8:
    // 0x80035BB8: bnel        $v0, $at, L_80035BF0
    if (ctx->r2 != ctx->r1) {
        // 0x80035BBC: lw          $t6, 0x0($a2)
        ctx->r14 = MEM_W(ctx->r6, 0X0);
            goto L_80035BF0;
    }
    goto skip_8;
    // 0x80035BBC: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    skip_8:
    // 0x80035BC0: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80035BC4: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x80035BC8: addiu       $t8, $t9, 0x7
    ctx->r24 = ADD32(ctx->r25, 0X7);
    // 0x80035BCC: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x80035BD0: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80035BD4: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80035BD8: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80035BDC: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80035BE0: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x80035BE4: b           L_80035C14
    // 0x80035BE8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
        goto L_80035C14;
    // 0x80035BE8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80035BEC: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
L_80035BF0:
    // 0x80035BF0: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80035BF4: addiu       $t7, $t6, 0x3
    ctx->r15 = ADD32(ctx->r14, 0X3);
    // 0x80035BF8: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80035BFC: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x80035C00: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80035C04: lw          $t7, -0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, -0X4);
    // 0x80035C08: sra         $t8, $t7, 31
    ctx->r24 = S32(SIGNED(ctx->r15) >> 31);
    // 0x80035C0C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80035C10: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
L_80035C14:
    // 0x80035C14: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x80035C18: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x80035C1C: bne         $v0, $at, L_80035C3C
    if (ctx->r2 != ctx->r1) {
        // 0x80035C20: nop
    
            goto L_80035C3C;
    }
    // 0x80035C20: nop

    // 0x80035C24: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x80035C28: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x80035C2C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80035C30: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x80035C34: b           L_80035C54
    // 0x80035C38: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
        goto L_80035C54;
    // 0x80035C38: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
L_80035C3C:
    // 0x80035C3C: bnel        $v0, $zero, L_80035C58
    if (ctx->r2 != 0) {
        // 0x80035C40: lw          $t7, 0x30($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X30);
            goto L_80035C58;
    }
    goto skip_9;
    // 0x80035C40: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
    skip_9:
    // 0x80035C44: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x80035C48: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80035C4C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80035C50: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
L_80035C54:
    // 0x80035C54: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
L_80035C58:
    // 0x80035C58: andi        $t6, $t7, 0x8
    ctx->r14 = ctx->r15 & 0X8;
    // 0x80035C5C: beql        $t6, $zero, L_80035CB0
    if (ctx->r14 == 0) {
        // 0x80035C60: lw          $t8, 0xC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XC);
            goto L_80035CB0;
    }
    goto skip_10;
    // 0x80035C60: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    skip_10:
    // 0x80035C64: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x80035C68: addiu       $t8, $zero, 0x30
    ctx->r24 = ADD32(0, 0X30);
    // 0x80035C6C: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x80035C70: addu        $t7, $a3, $t9
    ctx->r15 = ADD32(ctx->r7, ctx->r25);
    // 0x80035C74: sb          $t8, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r24;
    // 0x80035C78: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x80035C7C: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x80035C80: beq         $v1, $at, L_80035C94
    if (ctx->r3 == ctx->r1) {
        // 0x80035C84: sw          $t9, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->r25;
            goto L_80035C94;
    }
    // 0x80035C84: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
    // 0x80035C88: addiu       $at, $zero, 0x58
    ctx->r1 = ADD32(0, 0X58);
    // 0x80035C8C: bnel        $v1, $at, L_80035CB0
    if (ctx->r3 != ctx->r1) {
        // 0x80035C90: lw          $t8, 0xC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XC);
            goto L_80035CB0;
    }
    goto skip_11;
    // 0x80035C90: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    skip_11:
L_80035C94:
    // 0x80035C94: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x80035C98: addu        $t7, $a3, $t8
    ctx->r15 = ADD32(ctx->r7, ctx->r24);
    // 0x80035C9C: sb          $a1, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r5;
    // 0x80035CA0: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x80035CA4: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x80035CA8: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
    // 0x80035CAC: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
L_80035CB0:
    // 0x80035CB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80035CB4: addu        $t7, $t8, $a3
    ctx->r15 = ADD32(ctx->r24, ctx->r7);
    // 0x80035CB8: jal         0x80037270
    // 0x80035CBC: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    _Litob(rdram, ctx);
        goto after_1;
    // 0x80035CBC: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    after_1:
    // 0x80035CC0: b           L_80035FC4
    // 0x80035CC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80035FC4;
    // 0x80035CC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80035CC8:
    // 0x80035CC8: lbu         $t6, 0x34($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X34);
    // 0x80035CCC: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    // 0x80035CD0: bnel        $t6, $at, L_80035D38
    if (ctx->r14 != ctx->r1) {
        // 0x80035CD4: lw          $v0, 0x0($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X0);
            goto L_80035D38;
    }
    goto skip_12;
    // 0x80035CD4: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    skip_12:
    // 0x80035CD8: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80035CDC: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x80035CE0: beq         $t9, $zero, L_80035CF8
    if (ctx->r25 == 0) {
        // 0x80035CE4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80035CF8;
    }
    // 0x80035CE4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80035CE8: addiu       $t8, $v1, 0x7
    ctx->r24 = ADD32(ctx->r3, 0X7);
    // 0x80035CEC: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80035CF0: b           L_80035D28
    // 0x80035CF4: addiu       $v0, $t8, -0x16
    ctx->r2 = ADD32(ctx->r24, -0X16);
        goto L_80035D28;
    // 0x80035CF4: addiu       $v0, $t8, -0x16
    ctx->r2 = ADD32(ctx->r24, -0X16);
L_80035CF8:
    // 0x80035CF8: andi        $t7, $v1, 0x2
    ctx->r15 = ctx->r3 & 0X2;
    // 0x80035CFC: beq         $t7, $zero, L_80035D14
    if (ctx->r15 == 0) {
        // 0x80035D00: addiu       $t9, $v0, 0x7
        ctx->r25 = ADD32(ctx->r2, 0X7);
            goto L_80035D14;
    }
    // 0x80035D00: addiu       $t9, $v0, 0x7
    ctx->r25 = ADD32(ctx->r2, 0X7);
    // 0x80035D04: addiu       $t6, $v1, 0xA
    ctx->r14 = ADD32(ctx->r3, 0XA);
    // 0x80035D08: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80035D0C: b           L_80035D24
    // 0x80035D10: addiu       $a0, $t6, -0x28
    ctx->r4 = ADD32(ctx->r14, -0X28);
        goto L_80035D24;
    // 0x80035D10: addiu       $a0, $t6, -0x28
    ctx->r4 = ADD32(ctx->r14, -0X28);
L_80035D14:
    // 0x80035D14: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x80035D18: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x80035D1C: addiu       $a0, $t8, 0x8
    ctx->r4 = ADD32(ctx->r24, 0X8);
    // 0x80035D20: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
L_80035D24:
    // 0x80035D24: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80035D28:
    // 0x80035D28: ldc1        $f4, -0x8($v0)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r2, -0X8);
    // 0x80035D2C: b           L_80035D8C
    // 0x80035D30: sdc1        $f4, 0x0($s0)
    CHECK_FR(ctx, 4);
    SD(ctx->f4.u64, 0X0, ctx->r16);
        goto L_80035D8C;
    // 0x80035D30: sdc1        $f4, 0x0($s0)
    CHECK_FR(ctx, 4);
    SD(ctx->f4.u64, 0X0, ctx->r16);
    // 0x80035D34: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
L_80035D38:
    // 0x80035D38: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x80035D3C: beq         $t6, $zero, L_80035D54
    if (ctx->r14 == 0) {
        // 0x80035D40: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80035D54;
    }
    // 0x80035D40: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80035D44: addiu       $t9, $v1, 0x7
    ctx->r25 = ADD32(ctx->r3, 0X7);
    // 0x80035D48: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80035D4C: b           L_80035D84
    // 0x80035D50: addiu       $v0, $t9, -0x16
    ctx->r2 = ADD32(ctx->r25, -0X16);
        goto L_80035D84;
    // 0x80035D50: addiu       $v0, $t9, -0x16
    ctx->r2 = ADD32(ctx->r25, -0X16);
L_80035D54:
    // 0x80035D54: andi        $t8, $v1, 0x2
    ctx->r24 = ctx->r3 & 0X2;
    // 0x80035D58: beq         $t8, $zero, L_80035D70
    if (ctx->r24 == 0) {
        // 0x80035D5C: addiu       $t6, $v0, 0x7
        ctx->r14 = ADD32(ctx->r2, 0X7);
            goto L_80035D70;
    }
    // 0x80035D5C: addiu       $t6, $v0, 0x7
    ctx->r14 = ADD32(ctx->r2, 0X7);
    // 0x80035D60: addiu       $t7, $v1, 0xA
    ctx->r15 = ADD32(ctx->r3, 0XA);
    // 0x80035D64: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80035D68: b           L_80035D80
    // 0x80035D6C: addiu       $a0, $t7, -0x28
    ctx->r4 = ADD32(ctx->r15, -0X28);
        goto L_80035D80;
    // 0x80035D6C: addiu       $a0, $t7, -0x28
    ctx->r4 = ADD32(ctx->r15, -0X28);
L_80035D70:
    // 0x80035D70: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x80035D74: and         $t9, $t6, $at
    ctx->r25 = ctx->r14 & ctx->r1;
    // 0x80035D78: addiu       $a0, $t9, 0x8
    ctx->r4 = ADD32(ctx->r25, 0X8);
    // 0x80035D7C: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
L_80035D80:
    // 0x80035D80: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80035D84:
    // 0x80035D84: ldc1        $f6, -0x8($v0)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r2, -0X8);
    // 0x80035D88: sdc1        $f6, 0x0($s0)
    CHECK_FR(ctx, 6);
    SD(ctx->f6.u64, 0X0, ctx->r16);
L_80035D8C:
    // 0x80035D8C: lhu         $t7, 0x0($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X0);
    // 0x80035D90: andi        $t6, $t7, 0x8000
    ctx->r14 = ctx->r15 & 0X8000;
    // 0x80035D94: beql        $t6, $zero, L_80035DC0
    if (ctx->r14 == 0) {
        // 0x80035D98: lw          $v0, 0x30($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X30);
            goto L_80035DC0;
    }
    goto skip_13;
    // 0x80035D98: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    skip_13:
    // 0x80035D9C: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x80035DA0: addiu       $t9, $zero, 0x2D
    ctx->r25 = ADD32(0, 0X2D);
    // 0x80035DA4: addu        $t7, $a3, $t8
    ctx->r15 = ADD32(ctx->r7, ctx->r24);
    // 0x80035DA8: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
    // 0x80035DAC: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x80035DB0: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x80035DB4: b           L_80035E10
    // 0x80035DB8: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
        goto L_80035E10;
    // 0x80035DB8: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
    // 0x80035DBC: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
L_80035DC0:
    // 0x80035DC0: andi        $t9, $v0, 0x2
    ctx->r25 = ctx->r2 & 0X2;
    // 0x80035DC4: beq         $t9, $zero, L_80035DEC
    if (ctx->r25 == 0) {
        // 0x80035DC8: andi        $t7, $v0, 0x1
        ctx->r15 = ctx->r2 & 0X1;
            goto L_80035DEC;
    }
    // 0x80035DC8: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x80035DCC: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x80035DD0: addiu       $t7, $zero, 0x2B
    ctx->r15 = ADD32(0, 0X2B);
    // 0x80035DD4: addu        $t8, $a3, $t6
    ctx->r24 = ADD32(ctx->r7, ctx->r14);
    // 0x80035DD8: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x80035DDC: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x80035DE0: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x80035DE4: b           L_80035E10
    // 0x80035DE8: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
        goto L_80035E10;
    // 0x80035DE8: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
L_80035DEC:
    // 0x80035DEC: beql        $t7, $zero, L_80035E14
    if (ctx->r15 == 0) {
        // 0x80035DF0: lw          $t8, 0xC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XC);
            goto L_80035E14;
    }
    goto skip_14;
    // 0x80035DF0: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    skip_14:
    // 0x80035DF4: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x80035DF8: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x80035DFC: addu        $t6, $a3, $t9
    ctx->r14 = ADD32(ctx->r7, ctx->r25);
    // 0x80035E00: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
    // 0x80035E04: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x80035E08: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x80035E0C: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
L_80035E10:
    // 0x80035E10: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
L_80035E14:
    // 0x80035E14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80035E18: addu        $t6, $t8, $a3
    ctx->r14 = ADD32(ctx->r24, ctx->r7);
    // 0x80035E1C: jal         0x80036B90
    // 0x80035E20: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    _Ldtob(rdram, ctx);
        goto after_2;
    // 0x80035E20: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    after_2:
    // 0x80035E24: b           L_80035FC4
    // 0x80035E28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80035FC4;
    // 0x80035E28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80035E2C:
    // 0x80035E2C: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x80035E30: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x80035E34: bnel        $v0, $at, L_80035E68
    if (ctx->r2 != ctx->r1) {
        // 0x80035E38: addiu       $at, $zero, 0x6C
        ctx->r1 = ADD32(0, 0X6C);
            goto L_80035E68;
    }
    goto skip_15;
    // 0x80035E38: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    skip_15:
    // 0x80035E3C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80035E40: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80035E44: addiu       $t9, $t7, 0x3
    ctx->r25 = ADD32(ctx->r15, 0X3);
    // 0x80035E48: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x80035E4C: addiu       $t6, $t8, 0x4
    ctx->r14 = ADD32(ctx->r24, 0X4);
    // 0x80035E50: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80035E54: lw          $t9, -0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, -0X4);
    // 0x80035E58: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x80035E5C: b           L_80035FC0
    // 0x80035E60: sh          $t7, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r15;
        goto L_80035FC0;
    // 0x80035E60: sh          $t7, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r15;
    // 0x80035E64: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
L_80035E68:
    // 0x80035E68: bnel        $v0, $at, L_80035E9C
    if (ctx->r2 != ctx->r1) {
        // 0x80035E6C: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_80035E9C;
    }
    goto skip_16;
    // 0x80035E6C: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    skip_16:
    // 0x80035E70: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80035E74: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80035E78: addiu       $t6, $t8, 0x3
    ctx->r14 = ADD32(ctx->r24, 0X3);
    // 0x80035E7C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x80035E80: addiu       $t9, $t7, 0x4
    ctx->r25 = ADD32(ctx->r15, 0X4);
    // 0x80035E84: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80035E88: lw          $t6, -0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, -0X4);
    // 0x80035E8C: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
    // 0x80035E90: b           L_80035FC0
    // 0x80035E94: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
        goto L_80035FC0;
    // 0x80035E94: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x80035E98: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
L_80035E9C:
    // 0x80035E9C: bnel        $v0, $at, L_80035ED8
    if (ctx->r2 != ctx->r1) {
        // 0x80035EA0: lw          $t7, 0x0($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X0);
            goto L_80035ED8;
    }
    goto skip_17;
    // 0x80035EA0: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    skip_17:
    // 0x80035EA4: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80035EA8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80035EAC: addiu       $t9, $t7, 0x3
    ctx->r25 = ADD32(ctx->r15, 0X3);
    // 0x80035EB0: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x80035EB4: addiu       $t6, $t8, 0x4
    ctx->r14 = ADD32(ctx->r24, 0X4);
    // 0x80035EB8: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80035EBC: lw          $t6, -0x4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4);
    // 0x80035EC0: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x80035EC4: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80035EC8: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x80035ECC: b           L_80035FC0
    // 0x80035ED0: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
        goto L_80035FC0;
    // 0x80035ED0: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x80035ED4: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
L_80035ED8:
    // 0x80035ED8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80035EDC: addiu       $t8, $t7, 0x3
    ctx->r24 = ADD32(ctx->r15, 0X3);
    // 0x80035EE0: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x80035EE4: addiu       $t6, $t9, 0x4
    ctx->r14 = ADD32(ctx->r25, 0X4);
    // 0x80035EE8: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80035EEC: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80035EF0: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x80035EF4: b           L_80035FC0
    // 0x80035EF8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
        goto L_80035FC0;
    // 0x80035EF8: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
L_80035EFC:
    // 0x80035EFC: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80035F00: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80035F04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80035F08: addiu       $t6, $t9, 0x3
    ctx->r14 = ADD32(ctx->r25, 0X3);
    // 0x80035F0C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x80035F10: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x80035F14: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80035F18: lw          $t6, -0x4($t8)
    ctx->r14 = MEM_W(ctx->r24, -0X4);
    // 0x80035F1C: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x80035F20: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x80035F24: sra         $t8, $t6, 31
    ctx->r24 = S32(SIGNED(ctx->r14) >> 31);
    // 0x80035F28: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x80035F2C: addu        $t6, $t7, $a3
    ctx->r14 = ADD32(ctx->r15, ctx->r7);
    // 0x80035F30: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80035F34: jal         0x80037270
    // 0x80035F38: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    _Litob(rdram, ctx);
        goto after_3;
    // 0x80035F38: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    after_3:
    // 0x80035F3C: b           L_80035FC4
    // 0x80035F40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80035FC4;
    // 0x80035F40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80035F44:
    // 0x80035F44: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80035F48: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80035F4C: addiu       $t9, $t8, 0x3
    ctx->r25 = ADD32(ctx->r24, 0X3);
    // 0x80035F50: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x80035F54: addiu       $t6, $t7, 0x4
    ctx->r14 = ADD32(ctx->r15, 0X4);
    // 0x80035F58: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80035F5C: lw          $a0, -0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, -0X4);
    // 0x80035F60: jal         0x8003471C
    // 0x80035F64: sw          $a0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r4;
    strlen_recomp(rdram, ctx);
        goto after_4;
    // 0x80035F64: sw          $a0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r4;
    after_4:
    // 0x80035F68: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    // 0x80035F6C: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x80035F70: bltz        $v1, L_80035FC0
    if (SIGNED(ctx->r3) < 0) {
        // 0x80035F74: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80035FC0;
    }
    // 0x80035F74: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80035F78: beql        $at, $zero, L_80035FC4
    if (ctx->r1 == 0) {
        // 0x80035F7C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80035FC4;
    }
    goto skip_18;
    // 0x80035F7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_18:
    // 0x80035F80: b           L_80035FC0
    // 0x80035F84: sw          $v1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r3;
        goto L_80035FC0;
    // 0x80035F84: sw          $v1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r3;
    // 0x80035F88: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
L_80035F8C:
    // 0x80035F8C: addiu       $t6, $zero, 0x25
    ctx->r14 = ADD32(0, 0X25);
    // 0x80035F90: addu        $t9, $a3, $t8
    ctx->r25 = ADD32(ctx->r7, ctx->r24);
    // 0x80035F94: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x80035F98: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x80035F9C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80035FA0: b           L_80035FC0
    // 0x80035FA4: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
        goto L_80035FC0;
    // 0x80035FA4: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
L_80035FA8:
    // 0x80035FA8: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
L_80035FAC:
    // 0x80035FAC: addu        $t9, $a3, $t6
    ctx->r25 = ADD32(ctx->r7, ctx->r14);
    // 0x80035FB0: sb          $a1, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r5;
    // 0x80035FB4: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x80035FB8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80035FBC: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
L_80035FC0:
    // 0x80035FC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80035FC4:
    // 0x80035FC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80035FC8: jr          $ra
    // 0x80035FCC: nop

    return;
    // 0x80035FCC: nop

;}
RECOMP_FUNC void _Printf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035FD0: addiu       $sp, $sp, -0xD8
    ctx->r29 = ADD32(ctx->r29, -0XD8);
    // 0x80035FD4: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80035FD8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80035FDC: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80035FE0: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80035FE4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80035FE8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80035FEC: sw          $a3, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r7;
    // 0x80035FF0: lui         $s5, 0x8004
    ctx->r21 = S32(0X8004 << 16);
    // 0x80035FF4: lui         $s6, 0x8004
    ctx->r22 = S32(0X8004 << 16);
    // 0x80035FF8: lui         $s7, 0x8004
    ctx->r23 = S32(0X8004 << 16);
    // 0x80035FFC: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80036000: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80036004: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80036008: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8003600C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80036010: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80036014: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80036018: sw          $a2, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r6;
    // 0x8003601C: sw          $zero, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = 0;
    // 0x80036020: addiu       $s7, $s7, -0x5FB0
    ctx->r23 = ADD32(ctx->r23, -0X5FB0);
    // 0x80036024: addiu       $s6, $s6, -0x5D7C
    ctx->r22 = ADD32(ctx->r22, -0X5D7C);
    // 0x80036028: addiu       $s5, $s5, -0x5F8C
    ctx->r21 = ADD32(ctx->r21, -0X5F8C);
    // 0x8003602C: addiu       $fp, $zero, 0xA
    ctx->r30 = ADD32(0, 0XA);
L_80036030:
    // 0x80036030: lbu         $v0, 0x0($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X0);
    // 0x80036034: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x80036038: addiu       $v1, $zero, 0x25
    ctx->r3 = ADD32(0, 0X25);
    // 0x8003603C: beq         $v0, $zero, L_80036064
    if (ctx->r2 == 0) {
        // 0x80036040: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80036064;
    }
    // 0x80036040: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80036044: beql        $v1, $v0, L_80036068
    if (ctx->r3 == ctx->r2) {
        // 0x80036048: subu        $v0, $s2, $a3
        ctx->r2 = SUB32(ctx->r18, ctx->r7);
            goto L_80036068;
    }
    goto skip_0;
    // 0x80036048: subu        $v0, $s2, $a3
    ctx->r2 = SUB32(ctx->r18, ctx->r7);
    skip_0:
    // 0x8003604C: lbu         $v0, 0x1($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X1);
L_80036050:
    // 0x80036050: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80036054: beq         $v0, $zero, L_80036064
    if (ctx->r2 == 0) {
        // 0x80036058: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80036064;
    }
    // 0x80036058: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8003605C: bnel        $v1, $v0, L_80036050
    if (ctx->r3 != ctx->r2) {
        // 0x80036060: lbu         $v0, 0x1($s2)
        ctx->r2 = MEM_BU(ctx->r18, 0X1);
            goto L_80036050;
    }
    goto skip_1;
    // 0x80036060: lbu         $v0, 0x1($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X1);
    skip_1:
L_80036064:
    // 0x80036064: subu        $v0, $s2, $a3
    ctx->r2 = SUB32(ctx->r18, ctx->r7);
L_80036068:
    // 0x80036068: blez        $v0, L_800360A0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003606C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800360A0;
    }
    // 0x8003606C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80036070: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80036074: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80036078: jalr        $s4
    // 0x8003607C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_0;
    // 0x8003607C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_0:
    // 0x80036080: beq         $v0, $zero, L_80036098
    if (ctx->r2 == 0) {
        // 0x80036084: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80036098;
    }
    // 0x80036084: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80036088: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x8003608C: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x80036090: b           L_800360A0
    // 0x80036094: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
        goto L_800360A0;
    // 0x80036094: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
L_80036098:
    // 0x80036098: b           L_800365E8
    // 0x8003609C: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_800365E8;
    // 0x8003609C: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_800360A0:
    // 0x800360A0: bne         $s0, $zero, L_800360B0
    if (ctx->r16 != 0) {
        // 0x800360A4: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800360B0;
    }
    // 0x800360A4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800360A8: b           L_800365E8
    // 0x800360AC: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_800365E8;
    // 0x800360AC: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_800360B0:
    // 0x800360B0: sw          $zero, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = 0;
    // 0x800360B4: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    // 0x800360B8: jal         0x80034744
    // 0x800360BC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    strchr_recomp(rdram, ctx);
        goto after_1;
    // 0x800360BC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_1:
    // 0x800360C0: beq         $v0, $zero, L_80036100
    if (ctx->r2 == 0) {
        // 0x800360C4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80036100;
    }
    // 0x800360C4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800360C8:
    // 0x800360C8: subu        $t9, $s0, $s6
    ctx->r25 = SUB32(ctx->r16, ctx->r22);
    // 0x800360CC: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800360D0: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x800360D4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800360D8: lw          $t7, -0x5D74($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5D74);
    // 0x800360DC: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    // 0x800360E0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800360E4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800360E8: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x800360EC: sw          $t9, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r25;
    // 0x800360F0: jal         0x80034744
    // 0x800360F4: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    strchr_recomp(rdram, ctx);
        goto after_2;
    // 0x800360F4: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    after_2:
    // 0x800360F8: bne         $v0, $zero, L_800360C8
    if (ctx->r2 != 0) {
        // 0x800360FC: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800360C8;
    }
    // 0x800360FC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80036100:
    // 0x80036100: lbu         $t6, 0x0($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X0);
    // 0x80036104: addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
    // 0x80036108: lw          $t8, 0xE4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XE4);
    // 0x8003610C: bne         $v0, $t6, L_80036154
    if (ctx->r2 != ctx->r14) {
        // 0x80036110: lui         $a0, 0x8004
        ctx->r4 = S32(0X8004 << 16);
            goto L_80036154;
    }
    // 0x80036110: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80036114: addiu       $t7, $t8, 0x3
    ctx->r15 = ADD32(ctx->r24, 0X3);
    // 0x80036118: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x8003611C: and         $t9, $t7, $at
    ctx->r25 = ctx->r15 & ctx->r1;
    // 0x80036120: addiu       $t6, $t9, 0x4
    ctx->r14 = ADD32(ctx->r25, 0X4);
    // 0x80036124: sw          $t6, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r14;
    // 0x80036128: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x8003612C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80036130: bgez        $t8, L_8003614C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80036134: sw          $t8, 0xC8($sp)
        MEM_W(0XC8, ctx->r29) = ctx->r24;
            goto L_8003614C;
    }
    // 0x80036134: sw          $t8, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r24;
    // 0x80036138: lw          $t6, 0xD0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD0);
    // 0x8003613C: negu        $t7, $t8
    ctx->r15 = SUB32(0, ctx->r24);
    // 0x80036140: sw          $t7, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r15;
    // 0x80036144: ori         $t9, $t6, 0x4
    ctx->r25 = ctx->r14 | 0X4;
    // 0x80036148: sw          $t9, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r25;
L_8003614C:
    // 0x8003614C: b           L_800361B0
    // 0x80036150: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
        goto L_800361B0;
    // 0x80036150: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
L_80036154:
    // 0x80036154: sw          $zero, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = 0;
    // 0x80036158: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    // 0x8003615C: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x80036160: bne         $at, $zero, L_800361B0
    if (ctx->r1 != 0) {
        // 0x80036164: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_800361B0;
    }
    // 0x80036164: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x80036168: beql        $at, $zero, L_800361B4
    if (ctx->r1 == 0) {
        // 0x8003616C: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_800361B4;
    }
    goto skip_2;
    // 0x8003616C: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    skip_2:
    // 0x80036170: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
L_80036174:
    // 0x80036174: slti        $at, $t8, 0x3E7
    ctx->r1 = SIGNED(ctx->r24) < 0X3E7 ? 1 : 0;
    // 0x80036178: beql        $at, $zero, L_80036198
    if (ctx->r1 == 0) {
        // 0x8003617C: lbu         $a1, 0x1($s2)
        ctx->r5 = MEM_BU(ctx->r18, 0X1);
            goto L_80036198;
    }
    goto skip_3;
    // 0x8003617C: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
    skip_3:
    // 0x80036180: multu       $t8, $fp
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80036184: mflo        $t7
    ctx->r15 = lo;
    // 0x80036188: addu        $t6, $a1, $t7
    ctx->r14 = ADD32(ctx->r5, ctx->r15);
    // 0x8003618C: addiu       $t9, $t6, -0x30
    ctx->r25 = ADD32(ctx->r14, -0X30);
    // 0x80036190: sw          $t9, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r25;
    // 0x80036194: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
L_80036198:
    // 0x80036198: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8003619C: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x800361A0: bne         $at, $zero, L_800361B0
    if (ctx->r1 != 0) {
        // 0x800361A4: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_800361B0;
    }
    // 0x800361A4: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x800361A8: bnel        $at, $zero, L_80036174
    if (ctx->r1 != 0) {
        // 0x800361AC: lw          $t8, 0xC8($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XC8);
            goto L_80036174;
    }
    goto skip_4;
    // 0x800361AC: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    skip_4:
L_800361B0:
    // 0x800361B0: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
L_800361B4:
    // 0x800361B4: beq         $a1, $at, L_800361C8
    if (ctx->r5 == ctx->r1) {
        // 0x800361B8: addiu       $t8, $zero, -0x1
        ctx->r24 = ADD32(0, -0X1);
            goto L_800361C8;
    }
    // 0x800361B8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800361BC: sw          $t8, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r24;
    // 0x800361C0: b           L_8003625C
    // 0x800361C4: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
        goto L_8003625C;
    // 0x800361C4: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
L_800361C8:
    // 0x800361C8: lbu         $t7, 0x1($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X1);
    // 0x800361CC: lw          $t6, 0xE4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE4);
    // 0x800361D0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800361D4: bne         $v0, $t7, L_80036200
    if (ctx->r2 != ctx->r15) {
        // 0x800361D8: addiu       $t9, $t6, 0x3
        ctx->r25 = ADD32(ctx->r14, 0X3);
            goto L_80036200;
    }
    // 0x800361D8: addiu       $t9, $t6, 0x3
    ctx->r25 = ADD32(ctx->r14, 0X3);
    // 0x800361DC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800361E0: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x800361E4: addiu       $t7, $t8, 0x4
    ctx->r15 = ADD32(ctx->r24, 0X4);
    // 0x800361E8: sw          $t7, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r15;
    // 0x800361EC: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x800361F0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800361F4: sw          $t6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r14;
    // 0x800361F8: b           L_8003625C
    // 0x800361FC: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
        goto L_8003625C;
    // 0x800361FC: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
L_80036200:
    // 0x80036200: sw          $zero, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = 0;
    // 0x80036204: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    // 0x80036208: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x8003620C: bne         $at, $zero, L_8003625C
    if (ctx->r1 != 0) {
        // 0x80036210: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_8003625C;
    }
    // 0x80036210: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x80036214: beq         $at, $zero, L_8003625C
    if (ctx->r1 == 0) {
        // 0x80036218: nop
    
            goto L_8003625C;
    }
    // 0x80036218: nop

    // 0x8003621C: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
L_80036220:
    // 0x80036220: slti        $at, $t9, 0x3E7
    ctx->r1 = SIGNED(ctx->r25) < 0X3E7 ? 1 : 0;
    // 0x80036224: beql        $at, $zero, L_80036244
    if (ctx->r1 == 0) {
        // 0x80036228: lbu         $a1, 0x1($s2)
        ctx->r5 = MEM_BU(ctx->r18, 0X1);
            goto L_80036244;
    }
    goto skip_5;
    // 0x80036228: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
    skip_5:
    // 0x8003622C: multu       $t9, $fp
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80036230: mflo        $t7
    ctx->r15 = lo;
    // 0x80036234: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x80036238: addiu       $t6, $t8, -0x30
    ctx->r14 = ADD32(ctx->r24, -0X30);
    // 0x8003623C: sw          $t6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r14;
    // 0x80036240: lbu         $a1, 0x1($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X1);
L_80036244:
    // 0x80036244: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80036248: slti        $at, $a1, 0x30
    ctx->r1 = SIGNED(ctx->r5) < 0X30 ? 1 : 0;
    // 0x8003624C: bne         $at, $zero, L_8003625C
    if (ctx->r1 != 0) {
        // 0x80036250: slti        $at, $a1, 0x3A
        ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
            goto L_8003625C;
    }
    // 0x80036250: slti        $at, $a1, 0x3A
    ctx->r1 = SIGNED(ctx->r5) < 0X3A ? 1 : 0;
    // 0x80036254: bnel        $at, $zero, L_80036220
    if (ctx->r1 != 0) {
        // 0x80036258: lw          $t9, 0xC4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XC4);
            goto L_80036220;
    }
    goto skip_6;
    // 0x80036258: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
    skip_6:
L_8003625C:
    // 0x8003625C: jal         0x80034744
    // 0x80036260: addiu       $a0, $a0, -0x5D80
    ctx->r4 = ADD32(ctx->r4, -0X5D80);
    strchr_recomp(rdram, ctx);
        goto after_3;
    // 0x80036260: addiu       $a0, $a0, -0x5D80
    ctx->r4 = ADD32(ctx->r4, -0X5D80);
    after_3:
    // 0x80036264: beq         $v0, $zero, L_8003627C
    if (ctx->r2 == 0) {
        // 0x80036268: addiu       $s0, $sp, 0xA0
        ctx->r16 = ADD32(ctx->r29, 0XA0);
            goto L_8003627C;
    }
    // 0x80036268: addiu       $s0, $sp, 0xA0
    ctx->r16 = ADD32(ctx->r29, 0XA0);
    // 0x8003626C: lbu         $t9, 0x0($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X0);
    // 0x80036270: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80036274: b           L_80036280
    // 0x80036278: sb          $t9, 0xD4($sp)
    MEM_B(0XD4, ctx->r29) = ctx->r25;
        goto L_80036280;
    // 0x80036278: sb          $t9, 0xD4($sp)
    MEM_B(0XD4, ctx->r29) = ctx->r25;
L_8003627C:
    // 0x8003627C: sb          $zero, 0xD4($sp)
    MEM_B(0XD4, ctx->r29) = 0;
L_80036280:
    // 0x80036280: lbu         $t7, 0xD4($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XD4);
    // 0x80036284: addiu       $v0, $zero, 0x6C
    ctx->r2 = ADD32(0, 0X6C);
    // 0x80036288: addiu       $a2, $sp, 0xE4
    ctx->r6 = ADD32(ctx->r29, 0XE4);
    // 0x8003628C: bne         $v0, $t7, L_800362AC
    if (ctx->r2 != ctx->r15) {
        // 0x80036290: addiu       $a3, $sp, 0x74
        ctx->r7 = ADD32(ctx->r29, 0X74);
            goto L_800362AC;
    }
    // 0x80036290: addiu       $a3, $sp, 0x74
    ctx->r7 = ADD32(ctx->r29, 0X74);
    // 0x80036294: lbu         $t8, 0x0($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X0);
    // 0x80036298: addiu       $t6, $zero, 0x4C
    ctx->r14 = ADD32(0, 0X4C);
    // 0x8003629C: bne         $v0, $t8, L_800362AC
    if (ctx->r2 != ctx->r24) {
        // 0x800362A0: nop
    
            goto L_800362AC;
    }
    // 0x800362A0: nop

    // 0x800362A4: sb          $t6, 0xD4($sp)
    MEM_B(0XD4, ctx->r29) = ctx->r14;
    // 0x800362A8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800362AC:
    // 0x800362AC: jal         0x80035960
    // 0x800362B0: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    _Putfld(rdram, ctx);
        goto after_4;
    // 0x800362B0: lbu         $a1, 0x0($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X0);
    after_4:
    // 0x800362B4: lw          $t9, 0xC8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC8);
    // 0x800362B8: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x800362BC: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x800362C0: subu        $t8, $t9, $t7
    ctx->r24 = SUB32(ctx->r25, ctx->r15);
    // 0x800362C4: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x800362C8: subu        $t9, $t8, $t6
    ctx->r25 = SUB32(ctx->r24, ctx->r14);
    // 0x800362CC: lw          $t6, 0xB8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB8);
    // 0x800362D0: subu        $t8, $t9, $t7
    ctx->r24 = SUB32(ctx->r25, ctx->r15);
    // 0x800362D4: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x800362D8: subu        $t9, $t8, $t6
    ctx->r25 = SUB32(ctx->r24, ctx->r14);
    // 0x800362DC: lw          $t6, 0xC0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC0);
    // 0x800362E0: subu        $t8, $t9, $t7
    ctx->r24 = SUB32(ctx->r25, ctx->r15);
    // 0x800362E4: lw          $t7, 0xD0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD0);
    // 0x800362E8: subu        $t9, $t8, $t6
    ctx->r25 = SUB32(ctx->r24, ctx->r14);
    // 0x800362EC: sw          $t9, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r25;
    // 0x800362F0: andi        $t8, $t7, 0x4
    ctx->r24 = ctx->r15 & 0X4;
    // 0x800362F4: bne         $t8, $zero, L_80036360
    if (ctx->r24 != 0) {
        // 0x800362F8: slt         $t6, $zero, $t9
        ctx->r14 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
            goto L_80036360;
    }
    // 0x800362F8: slt         $t6, $zero, $t9
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800362FC: beql        $t6, $zero, L_80036364
    if (ctx->r14 == 0) {
        // 0x80036300: lw          $t9, 0xAC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XAC);
            goto L_80036364;
    }
    goto skip_7;
    // 0x80036300: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    skip_7:
    // 0x80036304: beq         $t6, $zero, L_80036360
    if (ctx->r14 == 0) {
        // 0x80036308: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_80036360;
    }
    // 0x80036308: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x8003630C: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_80036310:
    // 0x80036310: bne         $at, $zero, L_80036320
    if (ctx->r1 != 0) {
        // 0x80036314: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80036320;
    }
    // 0x80036314: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80036318: b           L_80036320
    // 0x8003631C: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_80036320;
    // 0x8003631C: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_80036320:
    // 0x80036320: blez        $s0, L_80036354
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80036324: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80036354;
    }
    // 0x80036324: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80036328: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x8003632C: jalr        $s4
    // 0x80036330: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_5;
    // 0x80036330: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_5:
    // 0x80036334: beq         $v0, $zero, L_8003634C
    if (ctx->r2 == 0) {
        // 0x80036338: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8003634C;
    }
    // 0x80036338: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8003633C: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x80036340: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x80036344: b           L_80036354
    // 0x80036348: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
        goto L_80036354;
    // 0x80036348: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
L_8003634C:
    // 0x8003634C: b           L_800365E8
    // 0x80036350: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_800365E8;
    // 0x80036350: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_80036354:
    // 0x80036354: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x80036358: bgtzl       $s1, L_80036310
    if (SIGNED(ctx->r17) > 0) {
        // 0x8003635C: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_80036310;
    }
    goto skip_8;
    // 0x8003635C: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_8:
L_80036360:
    // 0x80036360: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
L_80036364:
    // 0x80036364: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80036368: addiu       $a1, $sp, 0x74
    ctx->r5 = ADD32(ctx->r29, 0X74);
    // 0x8003636C: blezl       $t9, L_800363A4
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80036370: lw          $t9, 0xB0($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XB0);
            goto L_800363A4;
    }
    goto skip_9;
    // 0x80036370: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    skip_9:
    // 0x80036374: jalr        $s4
    // 0x80036378: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_6;
    // 0x80036378: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_6:
    // 0x8003637C: beq         $v0, $zero, L_80036398
    if (ctx->r2 == 0) {
        // 0x80036380: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80036398;
    }
    // 0x80036380: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80036384: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x80036388: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x8003638C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80036390: b           L_800363A0
    // 0x80036394: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
        goto L_800363A0;
    // 0x80036394: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
L_80036398:
    // 0x80036398: b           L_800365E8
    // 0x8003639C: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_800365E8;
    // 0x8003639C: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_800363A0:
    // 0x800363A0: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
L_800363A4:
    // 0x800363A4: slt         $t6, $zero, $t9
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800363A8: beql        $t6, $zero, L_80036410
    if (ctx->r14 == 0) {
        // 0x800363AC: lw          $t9, 0xB4($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XB4);
            goto L_80036410;
    }
    goto skip_10;
    // 0x800363AC: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
    skip_10:
    // 0x800363B0: beq         $t6, $zero, L_8003640C
    if (ctx->r14 == 0) {
        // 0x800363B4: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_8003640C;
    }
    // 0x800363B4: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x800363B8: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_800363BC:
    // 0x800363BC: bne         $at, $zero, L_800363CC
    if (ctx->r1 != 0) {
        // 0x800363C0: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800363CC;
    }
    // 0x800363C0: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800363C4: b           L_800363CC
    // 0x800363C8: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_800363CC;
    // 0x800363C8: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_800363CC:
    // 0x800363CC: blez        $s0, L_80036400
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800363D0: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80036400;
    }
    // 0x800363D0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800363D4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800363D8: jalr        $s4
    // 0x800363DC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_7;
    // 0x800363DC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_7:
    // 0x800363E0: beq         $v0, $zero, L_800363F8
    if (ctx->r2 == 0) {
        // 0x800363E4: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800363F8;
    }
    // 0x800363E4: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800363E8: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x800363EC: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x800363F0: b           L_80036400
    // 0x800363F4: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
        goto L_80036400;
    // 0x800363F4: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
L_800363F8:
    // 0x800363F8: b           L_800365E8
    // 0x800363FC: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_800365E8;
    // 0x800363FC: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_80036400:
    // 0x80036400: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x80036404: bgtzl       $s1, L_800363BC
    if (SIGNED(ctx->r17) > 0) {
        // 0x80036408: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_800363BC;
    }
    goto skip_11;
    // 0x80036408: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_11:
L_8003640C:
    // 0x8003640C: lw          $t9, 0xB4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB4);
L_80036410:
    // 0x80036410: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80036414: lw          $a1, 0xA8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA8);
    // 0x80036418: blezl       $t9, L_80036450
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8003641C: lw          $t9, 0xB8($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XB8);
            goto L_80036450;
    }
    goto skip_12;
    // 0x8003641C: lw          $t9, 0xB8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB8);
    skip_12:
    // 0x80036420: jalr        $s4
    // 0x80036424: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_8;
    // 0x80036424: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_8:
    // 0x80036428: beq         $v0, $zero, L_80036444
    if (ctx->r2 == 0) {
        // 0x8003642C: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80036444;
    }
    // 0x8003642C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80036430: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x80036434: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x80036438: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8003643C: b           L_8003644C
    // 0x80036440: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
        goto L_8003644C;
    // 0x80036440: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
L_80036444:
    // 0x80036444: b           L_800365E8
    // 0x80036448: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_800365E8;
    // 0x80036448: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_8003644C:
    // 0x8003644C: lw          $t9, 0xB8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB8);
L_80036450:
    // 0x80036450: slt         $t6, $zero, $t9
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80036454: beql        $t6, $zero, L_800364BC
    if (ctx->r14 == 0) {
        // 0x80036458: lw          $t9, 0xBC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XBC);
            goto L_800364BC;
    }
    goto skip_13;
    // 0x80036458: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
    skip_13:
    // 0x8003645C: beq         $t6, $zero, L_800364B8
    if (ctx->r14 == 0) {
        // 0x80036460: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_800364B8;
    }
    // 0x80036460: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x80036464: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_80036468:
    // 0x80036468: bne         $at, $zero, L_80036478
    if (ctx->r1 != 0) {
        // 0x8003646C: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80036478;
    }
    // 0x8003646C: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80036470: b           L_80036478
    // 0x80036474: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_80036478;
    // 0x80036474: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_80036478:
    // 0x80036478: blez        $s0, L_800364AC
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8003647C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800364AC;
    }
    // 0x8003647C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80036480: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80036484: jalr        $s4
    // 0x80036488: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_9;
    // 0x80036488: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_9:
    // 0x8003648C: beq         $v0, $zero, L_800364A4
    if (ctx->r2 == 0) {
        // 0x80036490: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800364A4;
    }
    // 0x80036490: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80036494: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x80036498: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x8003649C: b           L_800364AC
    // 0x800364A0: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
        goto L_800364AC;
    // 0x800364A0: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
L_800364A4:
    // 0x800364A4: b           L_800365E8
    // 0x800364A8: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_800365E8;
    // 0x800364A8: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_800364AC:
    // 0x800364AC: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x800364B0: bgtzl       $s1, L_80036468
    if (SIGNED(ctx->r17) > 0) {
        // 0x800364B4: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_80036468;
    }
    goto skip_14;
    // 0x800364B4: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_14:
L_800364B8:
    // 0x800364B8: lw          $t9, 0xBC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XBC);
L_800364BC:
    // 0x800364BC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800364C0: lw          $t6, 0xA8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA8);
    // 0x800364C4: blez        $t9, L_800364FC
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800364C8: lw          $t7, 0xB4($sp)
        ctx->r15 = MEM_W(ctx->r29, 0XB4);
            goto L_800364FC;
    }
    // 0x800364C8: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x800364CC: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x800364D0: jalr        $s4
    // 0x800364D4: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_10;
    // 0x800364D4: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    after_10:
    // 0x800364D8: beq         $v0, $zero, L_800364F4
    if (ctx->r2 == 0) {
        // 0x800364DC: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800364F4;
    }
    // 0x800364DC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800364E0: lw          $t8, 0xCC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XCC);
    // 0x800364E4: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x800364E8: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x800364EC: b           L_800364FC
    // 0x800364F0: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
        goto L_800364FC;
    // 0x800364F0: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
L_800364F4:
    // 0x800364F4: b           L_800365E8
    // 0x800364F8: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_800365E8;
    // 0x800364F8: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_800364FC:
    // 0x800364FC: lw          $t9, 0xC0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC0);
    // 0x80036500: slt         $t8, $zero, $t9
    ctx->r24 = SIGNED(0) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80036504: beql        $t8, $zero, L_8003656C
    if (ctx->r24 == 0) {
        // 0x80036508: lw          $t9, 0xD0($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XD0);
            goto L_8003656C;
    }
    goto skip_15;
    // 0x80036508: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    skip_15:
    // 0x8003650C: beq         $t8, $zero, L_80036568
    if (ctx->r24 == 0) {
        // 0x80036510: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_80036568;
    }
    // 0x80036510: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x80036514: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_80036518:
    // 0x80036518: bne         $at, $zero, L_80036528
    if (ctx->r1 != 0) {
        // 0x8003651C: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80036528;
    }
    // 0x8003651C: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80036520: b           L_80036528
    // 0x80036524: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_80036528;
    // 0x80036524: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_80036528:
    // 0x80036528: blez        $s0, L_8003655C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8003652C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8003655C;
    }
    // 0x8003652C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80036530: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80036534: jalr        $s4
    // 0x80036538: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_11;
    // 0x80036538: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_11:
    // 0x8003653C: beq         $v0, $zero, L_80036554
    if (ctx->r2 == 0) {
        // 0x80036540: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80036554;
    }
    // 0x80036540: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80036544: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x80036548: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x8003654C: b           L_8003655C
    // 0x80036550: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
        goto L_8003655C;
    // 0x80036550: sw          $t7, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r15;
L_80036554:
    // 0x80036554: b           L_800365E8
    // 0x80036558: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_800365E8;
    // 0x80036558: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_8003655C:
    // 0x8003655C: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x80036560: bgtzl       $s1, L_80036518
    if (SIGNED(ctx->r17) > 0) {
        // 0x80036564: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_80036518;
    }
    goto skip_16;
    // 0x80036564: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_16:
L_80036568:
    // 0x80036568: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
L_8003656C:
    // 0x8003656C: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x80036570: andi        $t8, $t9, 0x4
    ctx->r24 = ctx->r25 & 0X4;
    // 0x80036574: beq         $t8, $zero, L_800365E0
    if (ctx->r24 == 0) {
        // 0x80036578: slt         $t7, $zero, $t6
        ctx->r15 = SIGNED(0) < SIGNED(ctx->r14) ? 1 : 0;
            goto L_800365E0;
    }
    // 0x80036578: slt         $t7, $zero, $t6
    ctx->r15 = SIGNED(0) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8003657C: beq         $t7, $zero, L_800365E0
    if (ctx->r15 == 0) {
        // 0x80036580: nop
    
            goto L_800365E0;
    }
    // 0x80036580: nop

    // 0x80036584: beq         $t7, $zero, L_800365E0
    if (ctx->r15 == 0) {
        // 0x80036588: or          $s1, $t6, $zero
        ctx->r17 = ctx->r14 | 0;
            goto L_800365E0;
    }
    // 0x80036588: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x8003658C: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
L_80036590:
    // 0x80036590: bne         $at, $zero, L_800365A0
    if (ctx->r1 != 0) {
        // 0x80036594: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800365A0;
    }
    // 0x80036594: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80036598: b           L_800365A0
    // 0x8003659C: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
        goto L_800365A0;
    // 0x8003659C: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_800365A0:
    // 0x800365A0: blez        $s0, L_800365D4
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800365A4: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800365D4;
    }
    // 0x800365A4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800365A8: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800365AC: jalr        $s4
    // 0x800365B0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_12;
    // 0x800365B0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_12:
    // 0x800365B4: beq         $v0, $zero, L_800365CC
    if (ctx->r2 == 0) {
        // 0x800365B8: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800365CC;
    }
    // 0x800365B8: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800365BC: lw          $t9, 0xCC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XCC);
    // 0x800365C0: addu        $t8, $t9, $s0
    ctx->r24 = ADD32(ctx->r25, ctx->r16);
    // 0x800365C4: b           L_800365D4
    // 0x800365C8: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
        goto L_800365D4;
    // 0x800365C8: sw          $t8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r24;
L_800365CC:
    // 0x800365CC: b           L_800365E8
    // 0x800365D0: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
        goto L_800365E8;
    // 0x800365D0: lw          $v0, 0xCC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XCC);
L_800365D4:
    // 0x800365D4: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x800365D8: bgtzl       $s1, L_80036590
    if (SIGNED(ctx->r17) > 0) {
        // 0x800365DC: sltiu       $at, $s1, 0x21
        ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
            goto L_80036590;
    }
    goto skip_17;
    // 0x800365DC: sltiu       $at, $s1, 0x21
    ctx->r1 = ctx->r17 < 0X21 ? 1 : 0;
    skip_17:
L_800365E0:
    // 0x800365E0: b           L_80036030
    // 0x800365E4: addiu       $a3, $s2, 0x1
    ctx->r7 = ADD32(ctx->r18, 0X1);
        goto L_80036030;
    // 0x800365E4: addiu       $a3, $s2, 0x1
    ctx->r7 = ADD32(ctx->r18, 0X1);
L_800365E8:
    // 0x800365E8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800365EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800365F0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800365F4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800365F8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800365FC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80036600: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80036604: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80036608: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8003660C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80036610: jr          $ra
    // 0x80036614: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
    return;
    // 0x80036614: addiu       $sp, $sp, 0xD8
    ctx->r29 = ADD32(ctx->r29, 0XD8);
;}
RECOMP_FUNC void _Genld(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036620: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80036624: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80036628: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x8003662C: sra         $s2, $t6, 16
    ctx->r18 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80036630: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80036634: sll         $t8, $s3, 16
    ctx->r24 = S32(ctx->r19 << 16);
    // 0x80036638: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8003663C: andi        $t6, $s4, 0xFF
    ctx->r14 = ctx->r20 & 0XFF;
    // 0x80036640: sw          $s4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r20;
    // 0x80036644: or          $s4, $t6, $zero
    ctx->r20 = ctx->r14 | 0;
    // 0x80036648: bgtz        $s3, L_8003665C
    if (SIGNED(ctx->r19) > 0) {
        // 0x8003664C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8003665C;
    }
    // 0x8003664C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80036650: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80036654: addiu       $s1, $s1, -0x5C30
    ctx->r17 = ADD32(ctx->r17, -0X5C30);
    // 0x80036658: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_8003665C:
    // 0x8003665C: addiu       $v0, $zero, 0x66
    ctx->r2 = ADD32(0, 0X66);
    // 0x80036660: beq         $v0, $s4, L_80036694
    if (ctx->r2 == ctx->r20) {
        // 0x80036664: or          $v1, $s4, $zero
        ctx->r3 = ctx->r20 | 0;
            goto L_80036694;
    }
    // 0x80036664: or          $v1, $s4, $zero
    ctx->r3 = ctx->r20 | 0;
    // 0x80036668: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    // 0x8003666C: beq         $a0, $v1, L_80036678
    if (ctx->r4 == ctx->r3) {
        // 0x80036670: addiu       $at, $zero, 0x47
        ctx->r1 = ADD32(0, 0X47);
            goto L_80036678;
    }
    // 0x80036670: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x80036674: bne         $v1, $at, L_800368D0
    if (ctx->r3 != ctx->r1) {
        // 0x80036678: slti        $at, $s2, -0x4
        ctx->r1 = SIGNED(ctx->r18) < -0X4 ? 1 : 0;
            goto L_800368D0;
    }
L_80036678:
    // 0x80036678: slti        $at, $s2, -0x4
    ctx->r1 = SIGNED(ctx->r18) < -0X4 ? 1 : 0;
    // 0x8003667C: bne         $at, $zero, L_800368D0
    if (ctx->r1 != 0) {
        // 0x80036680: nop
    
            goto L_800368D0;
    }
    // 0x80036680: nop

    // 0x80036684: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x80036688: slt         $at, $s2, $t7
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8003668C: beq         $at, $zero, L_800368D0
    if (ctx->r1 == 0) {
        // 0x80036690: nop
    
            goto L_800368D0;
    }
    // 0x80036690: nop

L_80036694:
    // 0x80036694: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80036698: sll         $t8, $s2, 16
    ctx->r24 = S32(ctx->r18 << 16);
    // 0x8003669C: beq         $v0, $v1, L_800366D8
    if (ctx->r2 == ctx->r3) {
        // 0x800366A0: sra         $s2, $t8, 16
        ctx->r18 = S32(SIGNED(ctx->r24) >> 16);
            goto L_800366D8;
    }
    // 0x800366A0: sra         $s2, $t8, 16
    ctx->r18 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800366A4: lw          $t6, 0x30($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X30);
    // 0x800366A8: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800366AC: andi        $t7, $t6, 0x8
    ctx->r15 = ctx->r14 & 0X8;
    // 0x800366B0: bne         $t7, $zero, L_800366C8
    if (ctx->r15 != 0) {
        // 0x800366B4: slt         $at, $s3, $v0
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_800366C8;
    }
    // 0x800366B4: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800366B8: beql        $at, $zero, L_800366CC
    if (ctx->r1 == 0) {
        // 0x800366BC: subu        $t8, $v0, $s2
        ctx->r24 = SUB32(ctx->r2, ctx->r18);
            goto L_800366CC;
    }
    goto skip_0;
    // 0x800366BC: subu        $t8, $v0, $s2
    ctx->r24 = SUB32(ctx->r2, ctx->r18);
    skip_0:
    // 0x800366C0: sw          $s3, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r19;
    // 0x800366C4: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
L_800366C8:
    // 0x800366C8: subu        $t8, $v0, $s2
    ctx->r24 = SUB32(ctx->r2, ctx->r18);
L_800366CC:
    // 0x800366CC: bgez        $t8, L_800366D8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800366D0: sw          $t8, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r24;
            goto L_800366D8;
    }
    // 0x800366D0: sw          $t8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r24;
    // 0x800366D4: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
L_800366D8:
    // 0x800366D8: bgtz        $s2, L_800367A8
    if (SIGNED(ctx->r18) > 0) {
        // 0x800366DC: slt         $at, $s3, $s2
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r18) ? 1 : 0;
            goto L_800367A8;
    }
    // 0x800366DC: slt         $at, $s3, $s2
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x800366E0: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x800366E4: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800366E8: addiu       $t6, $zero, 0x30
    ctx->r14 = ADD32(0, 0X30);
    // 0x800366EC: negu        $v1, $s2
    ctx->r3 = SUB32(0, ctx->r18);
    // 0x800366F0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800366F4: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x800366F8: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800366FC: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80036700: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80036704: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80036708: bgtz        $v0, L_80036720
    if (SIGNED(ctx->r2) > 0) {
        // 0x8003670C: sw          $t8, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->r24;
            goto L_80036720;
    }
    // 0x8003670C: sw          $t8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r24;
    // 0x80036710: lw          $t6, 0x30($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X30);
    // 0x80036714: andi        $t9, $t6, 0x8
    ctx->r25 = ctx->r14 & 0X8;
    // 0x80036718: beql        $t9, $zero, L_80036748
    if (ctx->r25 == 0) {
        // 0x8003671C: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80036748;
    }
    goto skip_1;
    // 0x8003671C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    skip_1:
L_80036720:
    // 0x80036720: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x80036724: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x80036728: addiu       $t7, $zero, 0x2E
    ctx->r15 = ADD32(0, 0X2E);
    // 0x8003672C: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x80036730: sb          $t7, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r15;
    // 0x80036734: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80036738: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8003673C: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x80036740: sw          $t6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r14;
    // 0x80036744: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_80036748:
    // 0x80036748: beql        $at, $zero, L_80036764
    if (ctx->r1 == 0) {
        // 0x8003674C: addu        $t8, $v0, $s2
        ctx->r24 = ADD32(ctx->r2, ctx->r18);
            goto L_80036764;
    }
    goto skip_2;
    // 0x8003674C: addu        $t8, $v0, $s2
    ctx->r24 = ADD32(ctx->r2, ctx->r18);
    skip_2:
    // 0x80036750: negu        $s2, $v0
    ctx->r18 = SUB32(0, ctx->r2);
    // 0x80036754: sll         $t7, $s2, 16
    ctx->r15 = S32(ctx->r18 << 16);
    // 0x80036758: sra         $s2, $t7, 16
    ctx->r18 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8003675C: negu        $v1, $s2
    ctx->r3 = SUB32(0, ctx->r18);
    // 0x80036760: addu        $t8, $v0, $s2
    ctx->r24 = ADD32(ctx->r2, ctx->r18);
L_80036764:
    // 0x80036764: slt         $at, $t8, $s3
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80036768: sw          $v1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r3;
    // 0x8003676C: beq         $at, $zero, L_80036780
    if (ctx->r1 == 0) {
        // 0x80036770: sw          $t8, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r24;
            goto L_80036780;
    }
    // 0x80036770: sw          $t8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r24;
    // 0x80036774: sll         $s3, $t8, 16
    ctx->r19 = S32(ctx->r24 << 16);
    // 0x80036778: sra         $t6, $s3, 16
    ctx->r14 = S32(SIGNED(ctx->r19) >> 16);
    // 0x8003677C: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
L_80036780:
    // 0x80036780: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80036784: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x80036788: sw          $s3, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r19;
    // 0x8003678C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80036790: jal         0x800346F0
    // 0x80036794: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    memcpy_recomp(rdram, ctx);
        goto after_0;
    // 0x80036794: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    after_0:
    // 0x80036798: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x8003679C: subu        $t6, $t8, $s3
    ctx->r14 = SUB32(ctx->r24, ctx->r19);
    // 0x800367A0: b           L_80036B2C
    // 0x800367A4: sw          $t6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r14;
        goto L_80036B2C;
    // 0x800367A4: sw          $t6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r14;
L_800367A8:
    // 0x800367A8: beq         $at, $zero, L_80036820
    if (ctx->r1 == 0) {
        // 0x800367AC: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_80036820;
    }
    // 0x800367AC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800367B0: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x800367B4: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x800367B8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800367BC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800367C0: jal         0x800346F0
    // 0x800367C4: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    memcpy_recomp(rdram, ctx);
        goto after_1;
    // 0x800367C4: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    after_1:
    // 0x800367C8: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800367CC: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800367D0: subu        $t7, $s2, $s3
    ctx->r15 = SUB32(ctx->r18, ctx->r19);
    // 0x800367D4: addu        $t6, $t8, $s3
    ctx->r14 = ADD32(ctx->r24, ctx->r19);
    // 0x800367D8: sw          $t6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r14;
    // 0x800367DC: bgtz        $v0, L_800367F4
    if (SIGNED(ctx->r2) > 0) {
        // 0x800367E0: sw          $t7, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->r15;
            goto L_800367F4;
    }
    // 0x800367E0: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
    // 0x800367E4: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x800367E8: andi        $t8, $t9, 0x8
    ctx->r24 = ctx->r25 & 0X8;
    // 0x800367EC: beq         $t8, $zero, L_80036818
    if (ctx->r24 == 0) {
        // 0x800367F0: nop
    
            goto L_80036818;
    }
    // 0x800367F0: nop

L_800367F4:
    // 0x800367F4: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x800367F8: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x800367FC: addiu       $t6, $zero, 0x2E
    ctx->r14 = ADD32(0, 0X2E);
    // 0x80036800: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x80036804: sb          $t6, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r14;
    // 0x80036808: lw          $t7, 0x1C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1C);
    // 0x8003680C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80036810: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x80036814: sw          $t9, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r25;
L_80036818:
    // 0x80036818: b           L_80036B2C
    // 0x8003681C: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
        goto L_80036B2C;
    // 0x8003681C: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
L_80036820:
    // 0x80036820: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x80036824: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80036828: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8003682C: jal         0x800346F0
    // 0x80036830: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    memcpy_recomp(rdram, ctx);
        goto after_2;
    // 0x80036830: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    after_2:
    // 0x80036834: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x80036838: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8003683C: subu        $s3, $s3, $s2
    ctx->r19 = SUB32(ctx->r19, ctx->r18);
    // 0x80036840: sll         $t6, $s3, 16
    ctx->r14 = S32(ctx->r19 << 16);
    // 0x80036844: addu        $t9, $t7, $s2
    ctx->r25 = ADD32(ctx->r15, ctx->r18);
    // 0x80036848: sw          $t9, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r25;
    // 0x8003684C: bgtz        $v0, L_80036864
    if (SIGNED(ctx->r2) > 0) {
        // 0x80036850: sra         $s3, $t6, 16
        ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
            goto L_80036864;
    }
    // 0x80036850: sra         $s3, $t6, 16
    ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80036854: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
    // 0x80036858: andi        $t9, $t7, 0x8
    ctx->r25 = ctx->r15 & 0X8;
    // 0x8003685C: beql        $t9, $zero, L_8003688C
    if (ctx->r25 == 0) {
        // 0x80036860: slt         $at, $v0, $s3
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
            goto L_8003688C;
    }
    goto skip_3;
    // 0x80036860: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    skip_3:
L_80036864:
    // 0x80036864: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x80036868: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x8003686C: addiu       $t6, $zero, 0x2E
    ctx->r14 = ADD32(0, 0X2E);
    // 0x80036870: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x80036874: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x80036878: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x8003687C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80036880: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x80036884: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x80036888: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
L_8003688C:
    // 0x8003688C: beq         $at, $zero, L_800368A0
    if (ctx->r1 == 0) {
        // 0x80036890: addu        $a1, $s2, $s1
        ctx->r5 = ADD32(ctx->r18, ctx->r17);
            goto L_800368A0;
    }
    // 0x80036890: addu        $a1, $s2, $s1
    ctx->r5 = ADD32(ctx->r18, ctx->r17);
    // 0x80036894: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x80036898: sra         $t6, $s3, 16
    ctx->r14 = S32(SIGNED(ctx->r19) >> 16);
    // 0x8003689C: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
L_800368A0:
    // 0x800368A0: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x800368A4: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800368A8: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800368AC: jal         0x800346F0
    // 0x800368B0: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    memcpy_recomp(rdram, ctx);
        goto after_3;
    // 0x800368B0: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    after_3:
    // 0x800368B4: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800368B8: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x800368BC: addu        $t6, $t7, $s3
    ctx->r14 = ADD32(ctx->r15, ctx->r19);
    // 0x800368C0: subu        $t8, $t9, $s3
    ctx->r24 = SUB32(ctx->r25, ctx->r19);
    // 0x800368C4: sw          $t6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r14;
    // 0x800368C8: b           L_80036B2C
    // 0x800368CC: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
        goto L_80036B2C;
    // 0x800368CC: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
L_800368D0:
    // 0x800368D0: beq         $a0, $v1, L_800368E0
    if (ctx->r4 == ctx->r3) {
        // 0x800368D4: addiu       $at, $zero, 0x47
        ctx->r1 = ADD32(0, 0X47);
            goto L_800368E0;
    }
    // 0x800368D4: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x800368D8: bnel        $v1, $at, L_80036920
    if (ctx->r3 != ctx->r1) {
        // 0x800368DC: lw          $t8, 0x8($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X8);
            goto L_80036920;
    }
    goto skip_4;
    // 0x800368DC: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    skip_4:
L_800368E0:
    // 0x800368E0: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800368E4: addiu       $s4, $zero, 0x45
    ctx->r20 = ADD32(0, 0X45);
    // 0x800368E8: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800368EC: beql        $at, $zero, L_80036900
    if (ctx->r1 == 0) {
        // 0x800368F0: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_80036900;
    }
    goto skip_5;
    // 0x800368F0: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    skip_5:
    // 0x800368F4: sw          $s3, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r19;
    // 0x800368F8: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x800368FC: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
L_80036900:
    // 0x80036900: bgez        $t7, L_8003690C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80036904: sw          $t7, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r15;
            goto L_8003690C;
    }
    // 0x80036904: sw          $t7, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r15;
    // 0x80036908: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
L_8003690C:
    // 0x8003690C: bne         $a0, $v1, L_8003691C
    if (ctx->r4 != ctx->r3) {
        // 0x80036910: nop
    
            goto L_8003691C;
    }
    // 0x80036910: nop

    // 0x80036914: b           L_8003691C
    // 0x80036918: addiu       $s4, $zero, 0x65
    ctx->r20 = ADD32(0, 0X65);
        goto L_8003691C;
    // 0x80036918: addiu       $s4, $zero, 0x65
    ctx->r20 = ADD32(0, 0X65);
L_8003691C:
    // 0x8003691C: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
L_80036920:
    // 0x80036920: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x80036924: lbu         $t9, 0x0($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X0);
    // 0x80036928: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8003692C: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x80036930: sb          $t9, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r25;
    // 0x80036934: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80036938: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8003693C: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x80036940: bgtz        $v0, L_80036958
    if (SIGNED(ctx->r2) > 0) {
        // 0x80036944: sw          $t7, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->r15;
            goto L_80036958;
    }
    // 0x80036944: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x80036948: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x8003694C: andi        $t6, $t9, 0x8
    ctx->r14 = ctx->r25 & 0X8;
    // 0x80036950: beq         $t6, $zero, L_8003697C
    if (ctx->r14 == 0) {
        // 0x80036954: nop
    
            goto L_8003697C;
    }
    // 0x80036954: nop

L_80036958:
    // 0x80036958: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x8003695C: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x80036960: addiu       $t8, $zero, 0x2E
    ctx->r24 = ADD32(0, 0X2E);
    // 0x80036964: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x80036968: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
    // 0x8003696C: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x80036970: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80036974: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x80036978: sw          $t9, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r25;
L_8003697C:
    // 0x8003697C: blezl       $v0, L_800369D8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80036980: lw          $t6, 0x8($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X8);
            goto L_800369D8;
    }
    goto skip_6;
    // 0x80036980: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    skip_6:
    // 0x80036984: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x80036988: sll         $t8, $s3, 16
    ctx->r24 = S32(ctx->r19 << 16);
    // 0x8003698C: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80036990: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80036994: beq         $at, $zero, L_800369A8
    if (ctx->r1 == 0) {
        // 0x80036998: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_800369A8;
    }
    // 0x80036998: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8003699C: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x800369A0: sra         $t7, $s3, 16
    ctx->r15 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800369A4: or          $s3, $t7, $zero
    ctx->r19 = ctx->r15 | 0;
L_800369A8:
    // 0x800369A8: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x800369AC: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x800369B0: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800369B4: jal         0x800346F0
    // 0x800369B8: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    memcpy_recomp(rdram, ctx);
        goto after_4;
    // 0x800369B8: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    after_4:
    // 0x800369BC: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x800369C0: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x800369C4: addu        $t7, $t6, $s3
    ctx->r15 = ADD32(ctx->r14, ctx->r19);
    // 0x800369C8: subu        $t8, $t9, $s3
    ctx->r24 = SUB32(ctx->r25, ctx->r19);
    // 0x800369CC: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x800369D0: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
    // 0x800369D4: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
L_800369D8:
    // 0x800369D8: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800369DC: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
    // 0x800369E0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800369E4: bltz        $s2, L_800369FC
    if (SIGNED(ctx->r18) < 0) {
        // 0x800369E8: sb          $s4, -0x1($s1)
        MEM_B(-0X1, ctx->r17) = ctx->r20;
            goto L_800369FC;
    }
    // 0x800369E8: sb          $s4, -0x1($s1)
    MEM_B(-0X1, ctx->r17) = ctx->r20;
    // 0x800369EC: addiu       $t9, $zero, 0x2B
    ctx->r25 = ADD32(0, 0X2B);
    // 0x800369F0: sb          $t9, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r25;
    // 0x800369F4: b           L_80036A18
    // 0x800369F8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_80036A18;
    // 0x800369F8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800369FC:
    // 0x800369FC: negu        $s2, $s2
    ctx->r18 = SUB32(0, ctx->r18);
    // 0x80036A00: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x80036A04: addiu       $t8, $zero, 0x2D
    ctx->r24 = ADD32(0, 0X2D);
    // 0x80036A08: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80036A0C: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x80036A10: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80036A14: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
L_80036A18:
    // 0x80036A18: slti        $at, $s2, 0x64
    ctx->r1 = SIGNED(ctx->r18) < 0X64 ? 1 : 0;
    // 0x80036A1C: bnel        $at, $zero, L_80036AC8
    if (ctx->r1 != 0) {
        // 0x80036A20: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_80036AC8;
    }
    goto skip_7;
    // 0x80036A20: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    skip_7:
    // 0x80036A24: slti        $at, $s2, 0x3E8
    ctx->r1 = SIGNED(ctx->r18) < 0X3E8 ? 1 : 0;
    // 0x80036A28: bne         $at, $zero, L_80036A78
    if (ctx->r1 != 0) {
        // 0x80036A2C: addiu       $v0, $zero, 0x3E8
        ctx->r2 = ADD32(0, 0X3E8);
            goto L_80036A78;
    }
    // 0x80036A2C: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
    // 0x80036A30: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x80036A34: bne         $v0, $zero, L_80036A40
    if (ctx->r2 != 0) {
        // 0x80036A38: nop
    
            goto L_80036A40;
    }
    // 0x80036A38: nop

    // 0x80036A3C: break       7
    do_break(2147707452);
L_80036A40:
    // 0x80036A40: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80036A44: bne         $v0, $at, L_80036A58
    if (ctx->r2 != ctx->r1) {
        // 0x80036A48: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80036A58;
    }
    // 0x80036A48: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80036A4C: bne         $s2, $at, L_80036A58
    if (ctx->r18 != ctx->r1) {
        // 0x80036A50: nop
    
            goto L_80036A58;
    }
    // 0x80036A50: nop

    // 0x80036A54: break       6
    do_break(2147707476);
L_80036A58:
    // 0x80036A58: mfhi        $s2
    ctx->r18 = hi;
    // 0x80036A5C: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x80036A60: mflo        $t9
    ctx->r25 = lo;
    // 0x80036A64: addiu       $t8, $t9, 0x30
    ctx->r24 = ADD32(ctx->r25, 0X30);
    // 0x80036A68: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80036A6C: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x80036A70: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x80036A74: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80036A78:
    // 0x80036A78: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // 0x80036A7C: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x80036A80: bne         $v0, $zero, L_80036A8C
    if (ctx->r2 != 0) {
        // 0x80036A84: nop
    
            goto L_80036A8C;
    }
    // 0x80036A84: nop

    // 0x80036A88: break       7
    do_break(2147707528);
L_80036A8C:
    // 0x80036A8C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80036A90: bne         $v0, $at, L_80036AA4
    if (ctx->r2 != ctx->r1) {
        // 0x80036A94: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80036AA4;
    }
    // 0x80036A94: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80036A98: bne         $s2, $at, L_80036AA4
    if (ctx->r18 != ctx->r1) {
        // 0x80036A9C: nop
    
            goto L_80036AA4;
    }
    // 0x80036A9C: nop

    // 0x80036AA0: break       6
    do_break(2147707552);
L_80036AA4:
    // 0x80036AA4: mfhi        $s2
    ctx->r18 = hi;
    // 0x80036AA8: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x80036AAC: mflo        $t9
    ctx->r25 = lo;
    // 0x80036AB0: addiu       $t8, $t9, 0x30
    ctx->r24 = ADD32(ctx->r25, 0X30);
    // 0x80036AB4: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80036AB8: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x80036ABC: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x80036AC0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80036AC4: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_80036AC8:
    // 0x80036AC8: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x80036ACC: bne         $v0, $zero, L_80036AD8
    if (ctx->r2 != 0) {
        // 0x80036AD0: nop
    
            goto L_80036AD8;
    }
    // 0x80036AD0: nop

    // 0x80036AD4: break       7
    do_break(2147707604);
L_80036AD8:
    // 0x80036AD8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80036ADC: bne         $v0, $at, L_80036AF0
    if (ctx->r2 != ctx->r1) {
        // 0x80036AE0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80036AF0;
    }
    // 0x80036AE0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80036AE4: bne         $s2, $at, L_80036AF0
    if (ctx->r18 != ctx->r1) {
        // 0x80036AE8: nop
    
            goto L_80036AF0;
    }
    // 0x80036AE8: nop

    // 0x80036AEC: break       6
    do_break(2147707628);
L_80036AF0:
    // 0x80036AF0: mfhi        $s2
    ctx->r18 = hi;
    // 0x80036AF4: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x80036AF8: mflo        $t9
    ctx->r25 = lo;
    // 0x80036AFC: addiu       $t8, $t9, 0x30
    ctx->r24 = ADD32(ctx->r25, 0X30);
    // 0x80036B00: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80036B04: addiu       $t9, $t7, 0x30
    ctx->r25 = ADD32(ctx->r15, 0X30);
    // 0x80036B08: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x80036B0C: sb          $t9, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r25;
    // 0x80036B10: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x80036B14: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x80036B18: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x80036B1C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x80036B20: subu        $t6, $s1, $t8
    ctx->r14 = SUB32(ctx->r17, ctx->r24);
    // 0x80036B24: subu        $t9, $t6, $t7
    ctx->r25 = SUB32(ctx->r14, ctx->r15);
    // 0x80036B28: sw          $t9, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r25;
L_80036B2C:
    // 0x80036B2C: lw          $t8, 0x30($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X30);
    // 0x80036B30: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80036B34: andi        $t6, $t8, 0x14
    ctx->r14 = ctx->r24 & 0X14;
    // 0x80036B38: bnel        $t6, $at, L_80036B7C
    if (ctx->r14 != ctx->r1) {
        // 0x80036B3C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80036B7C;
    }
    goto skip_8;
    // 0x80036B3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_8:
    // 0x80036B40: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x80036B44: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x80036B48: lw          $t6, 0x18($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18);
    // 0x80036B4C: lw          $v1, 0x28($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X28);
    // 0x80036B50: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x80036B54: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    // 0x80036B58: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x80036B5C: lw          $t6, 0x20($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X20);
    // 0x80036B60: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x80036B64: addu        $v0, $t8, $t6
    ctx->r2 = ADD32(ctx->r24, ctx->r14);
    // 0x80036B68: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80036B6C: beq         $at, $zero, L_80036B78
    if (ctx->r1 == 0) {
        // 0x80036B70: subu        $t7, $v1, $v0
        ctx->r15 = SUB32(ctx->r3, ctx->r2);
            goto L_80036B78;
    }
    // 0x80036B70: subu        $t7, $v1, $v0
    ctx->r15 = SUB32(ctx->r3, ctx->r2);
    // 0x80036B74: sw          $t7, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r15;
L_80036B78:
    // 0x80036B78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80036B7C:
    // 0x80036B7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80036B80: jr          $ra
    // 0x80036B84: nop

    return;
    // 0x80036B84: nop

;}
RECOMP_FUNC void noopHandler_80036B88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036B88: jr          $ra
    // 0x80036B8C: nop

    return;
    // 0x80036B8C: nop

;}
RECOMP_FUNC void _Ldtob(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036B90: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x80036B94: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80036B98: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x80036B9C: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x80036BA0: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80036BA4: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80036BA8: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80036BAC: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80036BB0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80036BB4: sw          $a0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r4;
    // 0x80036BB8: sw          $a1, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r5;
    // 0x80036BBC: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x80036BC0: addiu       $s5, $sp, 0xB0
    ctx->r21 = ADD32(ctx->r29, 0XB0);
    // 0x80036BC4: ldc1        $f20, 0x0($a0)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r4, 0X0);
    // 0x80036BC8: bgez        $v0, L_80036BD8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80036BCC: addiu       $t7, $zero, 0x6
        ctx->r15 = ADD32(0, 0X6);
            goto L_80036BD8;
    }
    // 0x80036BCC: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x80036BD0: b           L_80036C04
    // 0x80036BD4: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
        goto L_80036C04;
    // 0x80036BD4: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
L_80036BD8:
    // 0x80036BD8: bne         $v0, $zero, L_80036C04
    if (ctx->r2 != 0) {
        // 0x80036BDC: lbu         $t8, 0xD7($sp)
        ctx->r24 = MEM_BU(ctx->r29, 0XD7);
            goto L_80036C04;
    }
    // 0x80036BDC: lbu         $t8, 0xD7($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XD7);
    // 0x80036BE0: addiu       $at, $zero, 0x67
    ctx->r1 = ADD32(0, 0X67);
    // 0x80036BE4: beq         $t8, $at, L_80036BF8
    if (ctx->r24 == ctx->r1) {
        // 0x80036BE8: sw          $t8, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r24;
            goto L_80036BF8;
    }
    // 0x80036BE8: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x80036BEC: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x80036BF0: bnel        $t8, $at, L_80036C08
    if (ctx->r24 != ctx->r1) {
        // 0x80036BF4: lw          $t6, 0xD0($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XD0);
            goto L_80036C08;
    }
    goto skip_0;
    // 0x80036BF4: lw          $t6, 0xD0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD0);
    skip_0:
L_80036BF8:
    // 0x80036BF8: lw          $t7, 0xD0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD0);
    // 0x80036BFC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80036C00: sw          $t9, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->r25;
L_80036C04:
    // 0x80036C04: lw          $t6, 0xD0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD0);
L_80036C08:
    // 0x80036C08: addiu       $at, $zero, 0x7FF
    ctx->r1 = ADD32(0, 0X7FF);
    // 0x80036C0C: lhu         $a0, 0x0($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X0);
    // 0x80036C10: andi        $v1, $a0, 0x7FF0
    ctx->r3 = ctx->r4 & 0X7FF0;
    // 0x80036C14: sra         $t8, $v1, 4
    ctx->r24 = S32(SIGNED(ctx->r3) >> 4);
    // 0x80036C18: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80036C1C: sra         $v1, $t9, 16
    ctx->r3 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80036C20: bne         $v1, $at, L_80036C84
    if (ctx->r3 != ctx->r1) {
        // 0x80036C24: nop
    
            goto L_80036C84;
    }
    // 0x80036C24: nop

    // 0x80036C28: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
    // 0x80036C2C: lhu         $t8, 0x0($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X0);
    // 0x80036C30: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80036C34: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x80036C38: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x80036C3C: bnel        $t9, $zero, L_80036C68
    if (ctx->r25 != 0) {
        // 0x80036C40: sra         $t7, $v0, 16
        ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
            goto L_80036C68;
    }
    goto skip_1;
    // 0x80036C40: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    skip_1:
    // 0x80036C44: lhu         $t7, 0x2($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X2);
    // 0x80036C48: bnel        $t7, $zero, L_80036C68
    if (ctx->r15 != 0) {
        // 0x80036C4C: sra         $t7, $v0, 16
        ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
            goto L_80036C68;
    }
    goto skip_2;
    // 0x80036C4C: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    skip_2:
    // 0x80036C50: lhu         $t8, 0x4($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X4);
    // 0x80036C54: bnel        $t8, $zero, L_80036C68
    if (ctx->r24 != 0) {
        // 0x80036C58: sra         $t7, $v0, 16
        ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
            goto L_80036C68;
    }
    goto skip_3;
    // 0x80036C58: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    skip_3:
    // 0x80036C5C: lhu         $t9, 0x6($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X6);
    // 0x80036C60: beq         $t9, $zero, L_80036C70
    if (ctx->r25 == 0) {
        // 0x80036C64: sra         $t7, $v0, 16
        ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
            goto L_80036C70;
    }
    // 0x80036C64: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
L_80036C68:
    // 0x80036C68: b           L_80036CBC
    // 0x80036C6C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_80036CBC;
    // 0x80036C6C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80036C70:
    // 0x80036C70: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80036C74: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x80036C78: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80036C7C: b           L_80036CBC
    // 0x80036C80: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_80036CBC;
    // 0x80036C80: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80036C84:
    // 0x80036C84: blez        $v1, L_80036CA8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80036C88: andi        $t8, $a0, 0x800F
        ctx->r24 = ctx->r4 & 0X800F;
            goto L_80036CA8;
    }
    // 0x80036C88: andi        $t8, $a0, 0x800F
    ctx->r24 = ctx->r4 & 0X800F;
    // 0x80036C8C: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    // 0x80036C90: ori         $t6, $t8, 0x3FF0
    ctx->r14 = ctx->r24 | 0X3FF0;
    // 0x80036C94: addiu       $t7, $v1, -0x3FE
    ctx->r15 = ADD32(ctx->r3, -0X3FE);
    // 0x80036C98: sh          $t6, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r14;
    // 0x80036C9C: sh          $t7, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r15;
    // 0x80036CA0: b           L_80036CBC
    // 0x80036CA4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80036CBC;
    // 0x80036CA4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80036CA8:
    // 0x80036CA8: bgez        $v1, L_80036CB8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80036CAC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80036CB8;
    }
    // 0x80036CAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80036CB0: b           L_80036CBC
    // 0x80036CB4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80036CBC;
    // 0x80036CB4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80036CB8:
    // 0x80036CB8: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
L_80036CBC:
    // 0x80036CBC: blez        $v0, L_80036D08
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80036CC0: sll         $t8, $v0, 16
        ctx->r24 = S32(ctx->r2 << 16);
            goto L_80036D08;
    }
    // 0x80036CC0: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x80036CC4: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x80036CC8: sra         $t6, $t8, 16
    ctx->r14 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80036CCC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80036CD0: bne         $t6, $at, L_80036CE4
    if (ctx->r14 != ctx->r1) {
        // 0x80036CD4: lw          $t9, 0xD0($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XD0);
            goto L_80036CE4;
    }
    // 0x80036CD4: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    // 0x80036CD8: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80036CDC: b           L_80036CEC
    // 0x80036CE0: addiu       $a1, $a1, -0x5C38
    ctx->r5 = ADD32(ctx->r5, -0X5C38);
        goto L_80036CEC;
    // 0x80036CE0: addiu       $a1, $a1, -0x5C38
    ctx->r5 = ADD32(ctx->r5, -0X5C38);
L_80036CE4:
    // 0x80036CE4: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80036CE8: addiu       $a1, $a1, -0x5C34
    ctx->r5 = ADD32(ctx->r5, -0X5C34);
L_80036CEC:
    // 0x80036CEC: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80036CF0: sw          $t7, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->r15;
    // 0x80036CF4: lw          $a0, 0x8($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X8);
    // 0x80036CF8: jal         0x800346F0
    // 0x80036CFC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    memcpy_recomp(rdram, ctx);
        goto after_0;
    // 0x80036CFC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x80036D00: b           L_800370B8
    // 0x80036D04: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800370B8;
    // 0x80036D04: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80036D08:
    // 0x80036D08: sra         $t6, $t8, 16
    ctx->r14 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80036D0C: bne         $t6, $zero, L_80036D1C
    if (ctx->r14 != 0) {
        // 0x80036D10: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_80036D1C;
    }
    // 0x80036D10: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80036D14: b           L_800370A0
    // 0x80036D18: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
        goto L_800370A0;
    // 0x80036D18: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
L_80036D1C:
    // 0x80036D1C: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    // 0x80036D20: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80036D24: lbu         $t7, 0xD7($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XD7);
    // 0x80036D28: lh          $t9, 0x9A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X9A);
    // 0x80036D2C: c.lt.d      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.d < ctx->f2.d;
    // 0x80036D30: addiu       $at, $zero, 0x7597
    ctx->r1 = ADD32(0, 0X7597);
    // 0x80036D34: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80036D38: addiu       $s5, $sp, 0xB1
    ctx->r21 = ADD32(ctx->r29, 0XB1);
    // 0x80036D3C: bc1f        L_80036D48
    if (!c1cs) {
        // 0x80036D40: sw          $t7, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r15;
            goto L_80036D48;
    }
    // 0x80036D40: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x80036D44: neg.d       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.d); 
    ctx->f20.d = -ctx->f20.d;
L_80036D48:
    // 0x80036D48: multu       $t9, $at
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r1)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80036D4C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80036D50: ori         $at, $at, 0x86A0
    ctx->r1 = ctx->r1 | 0X86A0;
    // 0x80036D54: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80036D58: mflo        $t8
    ctx->r24 = lo;
    // 0x80036D5C: nop

    // 0x80036D60: nop

    // 0x80036D64: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x80036D68: mflo        $t6
    ctx->r14 = lo;
    // 0x80036D6C: addiu       $t7, $t6, -0x4
    ctx->r15 = ADD32(ctx->r14, -0X4);
    // 0x80036D70: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x80036D74: sra         $t8, $t9, 16
    ctx->r24 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80036D78: bgez        $t8, L_80036DE0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80036D7C: sh          $t7, 0x9A($sp)
        MEM_H(0X9A, ctx->r29) = ctx->r15;
            goto L_80036DE0;
    }
    // 0x80036D7C: sh          $t7, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r15;
    // 0x80036D80: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x80036D84: sra         $t8, $t9, 16
    ctx->r24 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80036D88: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80036D8C: subu        $a0, $t6, $t8
    ctx->r4 = SUB32(ctx->r14, ctx->r24);
    // 0x80036D90: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80036D94: and         $v0, $a0, $at
    ctx->r2 = ctx->r4 & ctx->r1;
    // 0x80036D98: negu        $t9, $v0
    ctx->r25 = SUB32(0, ctx->r2);
    // 0x80036D9C: blez        $v0, L_80036E50
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80036DA0: sh          $t9, 0x9A($sp)
        MEM_H(0X9A, ctx->r29) = ctx->r25;
            goto L_80036E50;
    }
    // 0x80036DA0: sh          $t9, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r25;
    // 0x80036DA4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80036DA8: addiu       $a0, $a0, -0x5C80
    ctx->r4 = ADD32(ctx->r4, -0X5C80);
L_80036DAC:
    // 0x80036DAC: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x80036DB0: beq         $t6, $zero, L_80036DCC
    if (ctx->r14 == 0) {
        // 0x80036DB4: sra         $t9, $v0, 1
        ctx->r25 = S32(SIGNED(ctx->r2) >> 1);
            goto L_80036DCC;
    }
    // 0x80036DB4: sra         $t9, $v0, 1
    ctx->r25 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80036DB8: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x80036DBC: addu        $t7, $a0, $t8
    ctx->r15 = ADD32(ctx->r4, ctx->r24);
    // 0x80036DC0: ldc1        $f4, 0x0($t7)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r15, 0X0);
    // 0x80036DC4: mul.d       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f4.d); 
    ctx->f20.d = MUL_D(ctx->f20.d, ctx->f4.d);
    // 0x80036DC8: nop

L_80036DCC:
    // 0x80036DCC: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x80036DD0: bgtz        $t9, L_80036DAC
    if (SIGNED(ctx->r25) > 0) {
        // 0x80036DD4: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80036DAC;
    }
    // 0x80036DD4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80036DD8: b           L_80036E54
    // 0x80036DDC: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
        goto L_80036E54;
    // 0x80036DDC: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
L_80036DE0:
    // 0x80036DE0: lh          $t6, 0x9A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X9A);
    // 0x80036DE4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80036DE8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80036DEC: blez        $t6, L_80036E50
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80036DF0: andi        $t8, $t6, 0xFFFC
        ctx->r24 = ctx->r14 & 0XFFFC;
            goto L_80036E50;
    }
    // 0x80036DF0: andi        $t8, $t6, 0xFFFC
    ctx->r24 = ctx->r14 & 0XFFFC;
    // 0x80036DF4: sll         $v0, $t8, 16
    ctx->r2 = S32(ctx->r24 << 16);
    // 0x80036DF8: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80036DFC: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80036E00: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80036E04: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80036E08: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80036E0C: sh          $t8, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r24;
    // 0x80036E10: blez        $t6, L_80036E4C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80036E14: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_80036E4C;
    }
    // 0x80036E14: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80036E18: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80036E1C: addiu       $a0, $a0, -0x5C80
    ctx->r4 = ADD32(ctx->r4, -0X5C80);
L_80036E20:
    // 0x80036E20: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x80036E24: beq         $t7, $zero, L_80036E40
    if (ctx->r15 == 0) {
        // 0x80036E28: sra         $t6, $v0, 1
        ctx->r14 = S32(SIGNED(ctx->r2) >> 1);
            goto L_80036E40;
    }
    // 0x80036E28: sra         $t6, $v0, 1
    ctx->r14 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80036E2C: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x80036E30: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x80036E34: ldc1        $f6, 0x0($t9)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r25, 0X0);
    // 0x80036E38: mul.d       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x80036E3C: nop

L_80036E40:
    // 0x80036E40: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80036E44: bgtz        $t6, L_80036E20
    if (SIGNED(ctx->r14) > 0) {
        // 0x80036E48: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80036E20;
    }
    // 0x80036E48: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80036E4C:
    // 0x80036E4C: div.d       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f0.d); 
    ctx->f20.d = DIV_D(ctx->f20.d, ctx->f0.d);
L_80036E50:
    // 0x80036E50: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
L_80036E54:
    // 0x80036E54: addiu       $at, $zero, 0x66
    ctx->r1 = ADD32(0, 0X66);
    // 0x80036E58: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    // 0x80036E5C: bne         $t7, $at, L_80036E70
    if (ctx->r15 != ctx->r1) {
        // 0x80036E60: addiu       $t6, $zero, 0x30
        ctx->r14 = ADD32(0, 0X30);
            goto L_80036E70;
    }
    // 0x80036E60: addiu       $t6, $zero, 0x30
    ctx->r14 = ADD32(0, 0X30);
    // 0x80036E64: lh          $a1, 0x9A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X9A);
    // 0x80036E68: b           L_80036E70
    // 0x80036E6C: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
        goto L_80036E70;
    // 0x80036E6C: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
L_80036E70:
    // 0x80036E70: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x80036E74: addu        $s4, $a1, $t9
    ctx->r20 = ADD32(ctx->r5, ctx->r25);
    // 0x80036E78: slti        $at, $s4, 0x14
    ctx->r1 = SIGNED(ctx->r20) < 0X14 ? 1 : 0;
    // 0x80036E7C: bne         $at, $zero, L_80036E88
    if (ctx->r1 != 0) {
        // 0x80036E80: nop
    
            goto L_80036E88;
    }
    // 0x80036E80: nop

    // 0x80036E84: addiu       $s4, $zero, 0x13
    ctx->r20 = ADD32(0, 0X13);
L_80036E88:
    // 0x80036E88: blez        $s4, L_80036F58
    if (SIGNED(ctx->r20) <= 0) {
        // 0x80036E8C: sb          $t6, 0xB0($sp)
        MEM_B(0XB0, ctx->r29) = ctx->r14;
            goto L_80036F58;
    }
    // 0x80036E8C: sb          $t6, 0xB0($sp)
    MEM_B(0XB0, ctx->r29) = ctx->r14;
    // 0x80036E90: c.lt.d      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.d < ctx->f20.d;
    // 0x80036E94: addiu       $s3, $zero, 0x30
    ctx->r19 = ADD32(0, 0X30);
    // 0x80036E98: addiu       $s2, $sp, 0x74
    ctx->r18 = ADD32(ctx->r29, 0X74);
    // 0x80036E9C: bc1fl       L_80036F5C
    if (!c1cs) {
        // 0x80036EA0: lh          $t8, 0x9A($sp)
        ctx->r24 = MEM_H(ctx->r29, 0X9A);
            goto L_80036F5C;
    }
    goto skip_4;
    // 0x80036EA0: lh          $t8, 0x9A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X9A);
    skip_4:
    // 0x80036EA4: trunc.w.d   $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.u32l = TRUNC_W_D(ctx->f20.d);
L_80036EA8:
    // 0x80036EA8: addiu       $s4, $s4, -0x8
    ctx->r20 = ADD32(ctx->r20, -0X8);
    // 0x80036EAC: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x80036EB0: mfc1        $s1, $f8
    ctx->r17 = (int32_t)ctx->f8.u32l;
    // 0x80036EB4: blez        $s4, L_80036ED8
    if (SIGNED(ctx->r20) <= 0) {
        // 0x80036EB8: nop
    
            goto L_80036ED8;
    }
    // 0x80036EB8: nop

    // 0x80036EBC: mtc1        $s1, $f10
    ctx->f10.u32l = ctx->r17;
    // 0x80036EC0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80036EC4: ldc1        $f8, -0x5C28($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X5C28);
    // 0x80036EC8: cvt.d.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.d = CVT_D_W(ctx->f10.u32l);
    // 0x80036ECC: sub.d       $f6, $f20, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f20.d - ctx->f4.d;
    // 0x80036ED0: mul.d       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f20.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80036ED4: nop

L_80036ED8:
    // 0x80036ED8: blez        $s1, L_80036F20
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80036EDC: addiu       $s0, $zero, 0x8
        ctx->r16 = ADD32(0, 0X8);
            goto L_80036F20;
    }
    // 0x80036EDC: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
    // 0x80036EE0: addiu       $s0, $zero, 0x7
    ctx->r16 = ADD32(0, 0X7);
    // 0x80036EE4: bltz        $s0, L_80036F20
    if (SIGNED(ctx->r16) < 0) {
        // 0x80036EE8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80036F20;
    }
    // 0x80036EE8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80036EEC:
    // 0x80036EEC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80036EF0: jal         0x800371E0
    // 0x80036EF4: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    ldiv_recomp(rdram, ctx);
        goto after_1;
    // 0x80036EF4: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_1:
    // 0x80036EF8: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x80036EFC: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // 0x80036F00: addiu       $t9, $t8, 0x30
    ctx->r25 = ADD32(ctx->r24, 0X30);
    // 0x80036F04: sb          $t9, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r25;
    // 0x80036F08: lw          $s1, 0x74($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X74);
    // 0x80036F0C: blezl       $s1, L_80036F24
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80036F10: mtc1        $zero, $f3
        ctx->f_odd[(3 - 1) * 2] = 0;
            goto L_80036F24;
    }
    goto skip_5;
    // 0x80036F10: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    skip_5:
    // 0x80036F14: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80036F18: bgezl       $s0, L_80036EEC
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80036F1C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80036EEC;
    }
    goto skip_6;
    // 0x80036F1C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_6:
L_80036F20:
    // 0x80036F20: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
L_80036F24:
    // 0x80036F24: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80036F28: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80036F2C: bltz        $s0, L_80036F40
    if (SIGNED(ctx->r16) < 0) {
        // 0x80036F30: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_80036F40;
    }
L_80036F30:
    // 0x80036F30: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80036F34: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // 0x80036F38: bgez        $s0, L_80036F30
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80036F3C: sb          $s3, 0x0($s5)
        MEM_B(0X0, ctx->r21) = ctx->r19;
            goto L_80036F30;
    }
    // 0x80036F3C: sb          $s3, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r19;
L_80036F40:
    // 0x80036F40: blez        $s4, L_80036F58
    if (SIGNED(ctx->r20) <= 0) {
        // 0x80036F44: addiu       $s5, $s5, 0x8
        ctx->r21 = ADD32(ctx->r21, 0X8);
            goto L_80036F58;
    }
    // 0x80036F44: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x80036F48: c.lt.d      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.d < ctx->f20.d;
    // 0x80036F4C: nop

    // 0x80036F50: bc1tl       L_80036EA8
    if (c1cs) {
        // 0x80036F54: trunc.w.d   $f8, $f20
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.u32l = TRUNC_W_D(ctx->f20.d);
            goto L_80036EA8;
    }
    goto skip_7;
    // 0x80036F54: trunc.w.d   $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.u32l = TRUNC_W_D(ctx->f20.d);
    skip_7:
L_80036F58:
    // 0x80036F58: lh          $t8, 0x9A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X9A);
L_80036F5C:
    // 0x80036F5C: lbu         $t6, 0xB1($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XB1);
    // 0x80036F60: addiu       $t7, $sp, 0xB0
    ctx->r15 = ADD32(ctx->r29, 0XB0);
    // 0x80036F64: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x80036F68: subu        $s4, $s5, $t7
    ctx->r20 = SUB32(ctx->r21, ctx->r15);
    // 0x80036F6C: addiu       $t9, $t8, 0x7
    ctx->r25 = ADD32(ctx->r24, 0X7);
    // 0x80036F70: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x80036F74: sh          $t9, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r25;
    // 0x80036F78: bne         $v0, $t6, L_80036FA0
    if (ctx->r2 != ctx->r14) {
        // 0x80036F7C: addiu       $s5, $sp, 0xB1
        ctx->r21 = ADD32(ctx->r29, 0XB1);
            goto L_80036FA0;
    }
    // 0x80036F7C: addiu       $s5, $sp, 0xB1
    ctx->r21 = ADD32(ctx->r29, 0XB1);
    // 0x80036F80: lh          $t7, 0x9A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X9A);
L_80036F84:
    // 0x80036F84: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80036F88: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x80036F8C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80036F90: sh          $t8, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r24;
    // 0x80036F94: lbu         $t9, 0x0($s5)
    ctx->r25 = MEM_BU(ctx->r21, 0X0);
    // 0x80036F98: beql        $v0, $t9, L_80036F84
    if (ctx->r2 == ctx->r25) {
        // 0x80036F9C: lh          $t7, 0x9A($sp)
        ctx->r15 = MEM_H(ctx->r29, 0X9A);
            goto L_80036F84;
    }
    goto skip_8;
    // 0x80036F9C: lh          $t7, 0x9A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X9A);
    skip_8:
L_80036FA0:
    // 0x80036FA0: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80036FA4: addiu       $at, $zero, 0x66
    ctx->r1 = ADD32(0, 0X66);
    // 0x80036FA8: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    // 0x80036FAC: bne         $t6, $at, L_80036FC0
    if (ctx->r14 != ctx->r1) {
        // 0x80036FB0: lw          $t7, 0x48($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X48);
            goto L_80036FC0;
    }
    // 0x80036FB0: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80036FB4: lh          $a1, 0x9A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X9A);
    // 0x80036FB8: b           L_80036FE0
    // 0x80036FBC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_80036FE0;
    // 0x80036FBC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80036FC0:
    // 0x80036FC0: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x80036FC4: beq         $t7, $at, L_80036FD4
    if (ctx->r15 == ctx->r1) {
        // 0x80036FC8: addiu       $at, $zero, 0x45
        ctx->r1 = ADD32(0, 0X45);
            goto L_80036FD4;
    }
    // 0x80036FC8: addiu       $at, $zero, 0x45
    ctx->r1 = ADD32(0, 0X45);
    // 0x80036FCC: bne         $t7, $at, L_80036FDC
    if (ctx->r15 != ctx->r1) {
        // 0x80036FD0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80036FDC;
    }
    // 0x80036FD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80036FD4:
    // 0x80036FD4: b           L_80036FDC
    // 0x80036FD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80036FDC;
    // 0x80036FD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80036FDC:
    // 0x80036FDC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80036FE0:
    // 0x80036FE0: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x80036FE4: addu        $s3, $a1, $t9
    ctx->r19 = ADD32(ctx->r5, ctx->r25);
    // 0x80036FE8: sll         $t6, $s3, 16
    ctx->r14 = S32(ctx->r19 << 16);
    // 0x80036FEC: sra         $s3, $t6, 16
    ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80036FF0: slt         $at, $s4, $s3
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80036FF4: beq         $at, $zero, L_80037008
    if (ctx->r1 == 0) {
        // 0x80036FF8: nop
    
            goto L_80037008;
    }
    // 0x80036FF8: nop

    // 0x80036FFC: sll         $s3, $s4, 16
    ctx->r19 = S32(ctx->r20 << 16);
    // 0x80037000: sra         $t8, $s3, 16
    ctx->r24 = S32(SIGNED(ctx->r19) >> 16);
    // 0x80037004: or          $s3, $t8, $zero
    ctx->r19 = ctx->r24 | 0;
L_80037008:
    // 0x80037008: blez        $s3, L_800370A0
    if (SIGNED(ctx->r19) <= 0) {
        // 0x8003700C: slt         $at, $s3, $s4
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
            goto L_800370A0;
    }
    // 0x8003700C: slt         $at, $s3, $s4
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80037010: beq         $at, $zero, L_80037030
    if (ctx->r1 == 0) {
        // 0x80037014: addu        $v0, $s3, $s5
        ctx->r2 = ADD32(ctx->r19, ctx->r21);
            goto L_80037030;
    }
    // 0x80037014: addu        $v0, $s3, $s5
    ctx->r2 = ADD32(ctx->r19, ctx->r21);
    // 0x80037018: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x8003701C: slti        $at, $t9, 0x35
    ctx->r1 = SIGNED(ctx->r25) < 0X35 ? 1 : 0;
    // 0x80037020: bnel        $at, $zero, L_80037034
    if (ctx->r1 != 0) {
        // 0x80037024: addiu       $a1, $zero, 0x30
        ctx->r5 = ADD32(0, 0X30);
            goto L_80037034;
    }
    goto skip_9;
    // 0x80037024: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    skip_9:
    // 0x80037028: b           L_80037038
    // 0x8003702C: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
        goto L_80037038;
    // 0x8003702C: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
L_80037030:
    // 0x80037030: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
L_80037034:
    // 0x80037034: addu        $v0, $s3, $s5
    ctx->r2 = ADD32(ctx->r19, ctx->r21);
L_80037038:
    // 0x80037038: lbu         $t6, -0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, -0X1);
    // 0x8003703C: addiu       $v1, $s3, -0x1
    ctx->r3 = ADD32(ctx->r19, -0X1);
    // 0x80037040: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80037044: bne         $a1, $t6, L_8003706C
    if (ctx->r5 != ctx->r14) {
        // 0x80037048: addiu       $at, $zero, 0x39
        ctx->r1 = ADD32(0, 0X39);
            goto L_8003706C;
    }
    // 0x80037048: addiu       $at, $zero, 0x39
    ctx->r1 = ADD32(0, 0X39);
    // 0x8003704C: addu        $v0, $v1, $s5
    ctx->r2 = ADD32(ctx->r3, ctx->r21);
L_80037050:
    // 0x80037050: lbu         $t9, -0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X1);
    // 0x80037054: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x80037058: sll         $t7, $s3, 16
    ctx->r15 = S32(ctx->r19 << 16);
    // 0x8003705C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80037060: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80037064: beq         $a0, $t9, L_80037050
    if (ctx->r4 == ctx->r25) {
        // 0x80037068: sra         $s3, $t7, 16
        ctx->r19 = S32(SIGNED(ctx->r15) >> 16);
            goto L_80037050;
    }
    // 0x80037068: sra         $s3, $t7, 16
    ctx->r19 = S32(SIGNED(ctx->r15) >> 16);
L_8003706C:
    // 0x8003706C: bne         $a0, $at, L_80037080
    if (ctx->r4 != ctx->r1) {
        // 0x80037070: addu        $v0, $s5, $v1
        ctx->r2 = ADD32(ctx->r21, ctx->r3);
            goto L_80037080;
    }
    // 0x80037070: addu        $v0, $s5, $v1
    ctx->r2 = ADD32(ctx->r21, ctx->r3);
    // 0x80037074: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80037078: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8003707C: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
L_80037080:
    // 0x80037080: bgez        $v1, L_800370A0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80037084: lh          $t6, 0x9A($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X9A);
            goto L_800370A0;
    }
    // 0x80037084: lh          $t6, 0x9A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X9A);
    // 0x80037088: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8003708C: sll         $t8, $s3, 16
    ctx->r24 = S32(ctx->r19 << 16);
    // 0x80037090: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80037094: sh          $t7, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r15;
    // 0x80037098: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8003709C: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
L_800370A0:
    // 0x800370A0: lw          $s0, 0xD0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XD0);
    // 0x800370A4: lbu         $s4, 0xD7($sp)
    ctx->r20 = MEM_BU(ctx->r29, 0XD7);
    // 0x800370A8: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
    // 0x800370AC: jal         0x80036620
    // 0x800370B0: lh          $s2, 0x9A($sp)
    ctx->r18 = MEM_H(ctx->r29, 0X9A);
    _Genld(rdram, ctx);
        goto after_2;
    // 0x800370B0: lh          $s2, 0x9A($sp)
    ctx->r18 = MEM_H(ctx->r29, 0X9A);
    after_2:
    // 0x800370B4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800370B8:
    // 0x800370B8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800370BC: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x800370C0: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800370C4: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x800370C8: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x800370CC: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x800370D0: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x800370D4: jr          $ra
    // 0x800370D8: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x800370D8: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void lldiv_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800370E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800370E4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800370E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800370EC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800370F0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800370F4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800370F8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800370FC: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x80037100: jal         0x8002D1BC
    // 0x80037104: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    __ll_div_recomp(rdram, ctx);
        goto after_0;
    // 0x80037104: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    after_0:
    // 0x80037108: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8003710C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80037110: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80037114: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80037118: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8003711C: jal         0x8002D218
    // 0x80037120: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    __ll_mul_recomp(rdram, ctx);
        goto after_1;
    // 0x80037120: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    after_1:
    // 0x80037124: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80037128: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8003712C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80037130: subu        $t8, $t6, $v0
    ctx->r24 = SUB32(ctx->r14, ctx->r2);
    // 0x80037134: sltu        $at, $t7, $v1
    ctx->r1 = ctx->r15 < ctx->r3 ? 1 : 0;
    // 0x80037138: subu        $t8, $t8, $at
    ctx->r24 = SUB32(ctx->r24, ctx->r1);
    // 0x8003713C: subu        $t9, $t7, $v1
    ctx->r25 = SUB32(ctx->r15, ctx->r3);
    // 0x80037140: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x80037144: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x80037148: bgtz        $t0, L_800371A8
    if (SIGNED(ctx->r8) > 0) {
        // 0x8003714C: lw          $t1, 0x24($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X24);
            goto L_800371A8;
    }
    // 0x8003714C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80037150: bltz        $t0, L_80037160
    if (SIGNED(ctx->r8) < 0) {
        // 0x80037154: nop
    
            goto L_80037160;
    }
    // 0x80037154: nop

    // 0x80037158: b           L_800371AC
    // 0x8003715C: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
        goto L_800371AC;
    // 0x8003715C: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
L_80037160:
    // 0x80037160: bltzl       $t8, L_800371AC
    if (SIGNED(ctx->r24) < 0) {
        // 0x80037164: addiu       $t0, $sp, 0x20
        ctx->r8 = ADD32(ctx->r29, 0X20);
            goto L_800371AC;
    }
    goto skip_0;
    // 0x80037164: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
    skip_0:
    // 0x80037168: bgtz        $t8, L_80037178
    if (SIGNED(ctx->r24) > 0) {
        // 0x8003716C: addiu       $t3, $t1, 0x1
        ctx->r11 = ADD32(ctx->r9, 0X1);
            goto L_80037178;
    }
    // 0x8003716C: addiu       $t3, $t1, 0x1
    ctx->r11 = ADD32(ctx->r9, 0X1);
    // 0x80037170: beql        $t9, $zero, L_800371AC
    if (ctx->r25 == 0) {
        // 0x80037174: addiu       $t0, $sp, 0x20
        ctx->r8 = ADD32(ctx->r29, 0X20);
            goto L_800371AC;
    }
    goto skip_1;
    // 0x80037174: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
    skip_1:
L_80037178:
    // 0x80037178: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8003717C: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x80037180: sltiu       $at, $t3, 0x1
    ctx->r1 = ctx->r11 < 0X1 ? 1 : 0;
    // 0x80037184: addu        $t2, $t0, $at
    ctx->r10 = ADD32(ctx->r8, ctx->r1);
    // 0x80037188: subu        $t6, $t8, $t4
    ctx->r14 = SUB32(ctx->r24, ctx->r12);
    // 0x8003718C: sltu        $at, $t9, $t5
    ctx->r1 = ctx->r25 < ctx->r13 ? 1 : 0;
    // 0x80037190: subu        $t6, $t6, $at
    ctx->r14 = SUB32(ctx->r14, ctx->r1);
    // 0x80037194: subu        $t7, $t9, $t5
    ctx->r15 = SUB32(ctx->r25, ctx->r13);
    // 0x80037198: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x8003719C: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x800371A0: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x800371A4: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
L_800371A8:
    // 0x800371A8: addiu       $t0, $sp, 0x20
    ctx->r8 = ADD32(ctx->r29, 0X20);
L_800371AC:
    // 0x800371AC: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x800371B0: lw          $at, 0x0($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X0);
    // 0x800371B4: sw          $at, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r1;
    // 0x800371B8: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x800371BC: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800371C0: lw          $at, 0x8($t0)
    ctx->r1 = MEM_W(ctx->r8, 0X8);
    // 0x800371C4: sw          $at, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r1;
    // 0x800371C8: lw          $t3, 0xC($t0)
    ctx->r11 = MEM_W(ctx->r8, 0XC);
    // 0x800371CC: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
    // 0x800371D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800371D4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800371D8: jr          $ra
    // 0x800371DC: nop

    return;
    // 0x800371DC: nop

;}
RECOMP_FUNC void ldiv_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800371E0: div         $zero, $a1, $a2
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r6)));
    // 0x800371E4: mflo        $v0
    ctx->r2 = lo;
    // 0x800371E8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800371EC: bne         $a2, $zero, L_800371F8
    if (ctx->r6 != 0) {
        // 0x800371F0: nop
    
            goto L_800371F8;
    }
    // 0x800371F0: nop

    // 0x800371F4: break       7
    do_break(2147709428);
L_800371F8:
    // 0x800371F8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800371FC: bne         $a2, $at, L_80037210
    if (ctx->r6 != ctx->r1) {
        // 0x80037200: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80037210;
    }
    // 0x80037200: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80037204: bne         $a1, $at, L_80037210
    if (ctx->r5 != ctx->r1) {
        // 0x80037208: nop
    
            goto L_80037210;
    }
    // 0x80037208: nop

    // 0x8003720C: break       6
    do_break(2147709452);
L_80037210:
    // 0x80037210: multu       $a2, $v0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80037214: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
    // 0x80037218: addiu       $t7, $sp, 0x0
    ctx->r15 = ADD32(ctx->r29, 0X0);
    // 0x8003721C: mflo        $t6
    ctx->r14 = lo;
    // 0x80037220: subu        $v1, $a1, $t6
    ctx->r3 = SUB32(ctx->r5, ctx->r14);
    // 0x80037224: bgez        $v0, L_80037248
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80037228: sw          $v1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r3;
            goto L_80037248;
    }
    // 0x80037228: sw          $v1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r3;
    // 0x8003722C: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
    // 0x80037230: blez        $v1, L_80037248
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80037234: sw          $v1, 0x4($sp)
        MEM_W(0X4, ctx->r29) = ctx->r3;
            goto L_80037248;
    }
    // 0x80037234: sw          $v1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r3;
    // 0x80037238: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8003723C: subu        $v1, $v1, $a2
    ctx->r3 = SUB32(ctx->r3, ctx->r6);
    // 0x80037240: sw          $v1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r3;
    // 0x80037244: sw          $v0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r2;
L_80037248:
    // 0x80037248: lw          $at, 0x0($t7)
    ctx->r1 = MEM_W(ctx->r15, 0X0);
    // 0x8003724C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80037250: sw          $at, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r1;
    // 0x80037254: lw          $t0, 0x4($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X4);
    // 0x80037258: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x8003725C: jr          $ra
    // 0x80037260: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    return;
    // 0x80037260: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
;}
RECOMP_FUNC void _Litob(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037270: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80037274: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80037278: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x8003727C: addiu       $v1, $zero, 0x58
    ctx->r3 = ADD32(0, 0X58);
    // 0x80037280: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80037284: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80037288: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8003728C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80037290: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80037294: bne         $v1, $v0, L_800372A8
    if (ctx->r3 != ctx->r2) {
        // 0x80037298: sw          $a1, 0x94($sp)
        MEM_W(0X94, ctx->r29) = ctx->r5;
            goto L_800372A8;
    }
    // 0x80037298: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x8003729C: lui         $s3, 0x8004
    ctx->r19 = S32(0X8004 << 16);
    // 0x800372A0: b           L_800372B0
    // 0x800372A4: addiu       $s3, $s3, -0x5F4C
    ctx->r19 = ADD32(ctx->r19, -0X5F4C);
        goto L_800372B0;
    // 0x800372A4: addiu       $s3, $s3, -0x5F4C
    ctx->r19 = ADD32(ctx->r19, -0X5F4C);
L_800372A8:
    // 0x800372A8: lui         $s3, 0x8004
    ctx->r19 = S32(0X8004 << 16);
    // 0x800372AC: addiu       $s3, $s3, -0x5F60
    ctx->r19 = ADD32(ctx->r19, -0X5F60);
L_800372B0:
    // 0x800372B0: addiu       $at, $zero, 0x6F
    ctx->r1 = ADD32(0, 0X6F);
    // 0x800372B4: bne         $v0, $at, L_800372C4
    if (ctx->r2 != ctx->r1) {
        // 0x800372B8: addiu       $s0, $zero, 0x18
        ctx->r16 = ADD32(0, 0X18);
            goto L_800372C4;
    }
    // 0x800372B8: addiu       $s0, $zero, 0x18
    ctx->r16 = ADD32(0, 0X18);
    // 0x800372BC: b           L_800372E4
    // 0x800372C0: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
        goto L_800372E4;
    // 0x800372C0: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
L_800372C4:
    // 0x800372C4: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x800372C8: beq         $v0, $at, L_800372E0
    if (ctx->r2 == ctx->r1) {
        // 0x800372CC: addiu       $t0, $zero, 0x10
        ctx->r8 = ADD32(0, 0X10);
            goto L_800372E0;
    }
    // 0x800372CC: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x800372D0: beq         $v1, $v0, L_800372E0
    if (ctx->r3 == ctx->r2) {
        // 0x800372D4: nop
    
            goto L_800372E0;
    }
    // 0x800372D4: nop

    // 0x800372D8: b           L_800372E0
    // 0x800372DC: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
        goto L_800372E0;
    // 0x800372DC: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
L_800372E0:
    // 0x800372E0: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
L_800372E4:
    // 0x800372E4: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800372E8: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x800372EC: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x800372F0: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x800372F4: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x800372F8: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x800372FC: beq         $v0, $at, L_80037310
    if (ctx->r2 == ctx->r1) {
        // 0x80037300: sw          $t9, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r25;
            goto L_80037310;
    }
    // 0x80037300: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    // 0x80037304: addiu       $at, $zero, 0x69
    ctx->r1 = ADD32(0, 0X69);
    // 0x80037308: bnel        $v0, $at, L_8003734C
    if (ctx->r2 != ctx->r1) {
        // 0x8003730C: lw          $t2, 0x60($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X60);
            goto L_8003734C;
    }
    goto skip_0;
    // 0x8003730C: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    skip_0:
L_80037310:
    // 0x80037310: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80037314: bgtzl       $t4, L_8003734C
    if (SIGNED(ctx->r12) > 0) {
        // 0x80037318: lw          $t2, 0x60($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X60);
            goto L_8003734C;
    }
    goto skip_1;
    // 0x80037318: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    skip_1:
    // 0x8003731C: bltz        $t4, L_8003732C
    if (SIGNED(ctx->r12) < 0) {
        // 0x80037320: lw          $t6, 0x60($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X60);
            goto L_8003732C;
    }
    // 0x80037320: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x80037324: b           L_8003734C
    // 0x80037328: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
        goto L_8003734C;
    // 0x80037328: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
L_8003732C:
    // 0x8003732C: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x80037330: nor         $t8, $t6, $zero
    ctx->r24 = ~(ctx->r14 | 0);
    // 0x80037334: sltiu       $at, $t7, 0x1
    ctx->r1 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80037338: addu        $t8, $t8, $at
    ctx->r24 = ADD32(ctx->r24, ctx->r1);
    // 0x8003733C: negu        $t9, $t7
    ctx->r25 = SUB32(0, ctx->r15);
    // 0x80037340: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    // 0x80037344: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x80037348: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
L_8003734C:
    // 0x8003734C: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x80037350: addiu       $t0, $zero, 0x17
    ctx->r8 = ADD32(0, 0X17);
    // 0x80037354: bne         $t2, $zero, L_80037370
    if (ctx->r10 != 0) {
        // 0x80037358: lw          $a0, 0x60($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X60);
            goto L_80037370;
    }
    // 0x80037358: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8003735C: bnel        $t3, $zero, L_80037374
    if (ctx->r11 != 0) {
        // 0x80037360: addiu       $s0, $zero, 0x17
        ctx->r16 = ADD32(0, 0X17);
            goto L_80037374;
    }
    goto skip_2;
    // 0x80037360: addiu       $s0, $zero, 0x17
    ctx->r16 = ADD32(0, 0X17);
    skip_2:
    // 0x80037364: lw          $t4, 0x24($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X24);
    // 0x80037368: beql        $t4, $zero, L_800373AC
    if (ctx->r12 == 0) {
        // 0x8003736C: addiu       $s2, $sp, 0x78
        ctx->r18 = ADD32(ctx->r29, 0X78);
            goto L_800373AC;
    }
    goto skip_3;
    // 0x8003736C: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
    skip_3:
L_80037370:
    // 0x80037370: addiu       $s0, $zero, 0x17
    ctx->r16 = ADD32(0, 0X17);
L_80037374:
    // 0x80037374: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80037378: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x8003737C: sra         $a2, $t1, 31
    ctx->r6 = S32(SIGNED(ctx->r9) >> 31);
    // 0x80037380: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x80037384: jal         0x8002D0DC
    // 0x80037388: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    __ull_rem_recomp(rdram, ctx);
        goto after_0;
    // 0x80037388: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    after_0:
    // 0x8003738C: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x80037390: addu        $t6, $v1, $s3
    ctx->r14 = ADD32(ctx->r3, ctx->r19);
    // 0x80037394: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80037398: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
    // 0x8003739C: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x800373A0: addu        $t8, $s2, $t0
    ctx->r24 = ADD32(ctx->r18, ctx->r8);
    // 0x800373A4: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x800373A8: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
L_800373AC:
    // 0x800373AC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x800373B0: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x800373B4: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x800373B8: sra         $a2, $t1, 31
    ctx->r6 = S32(SIGNED(ctx->r9) >> 31);
    // 0x800373BC: jal         0x8002D118
    // 0x800373C0: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    __ull_div_recomp(rdram, ctx);
        goto after_1;
    // 0x800373C0: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    after_1:
    // 0x800373C4: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x800373C8: sw          $v1, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r3;
    // 0x800373CC: bltz        $v0, L_8003747C
    if (SIGNED(ctx->r2) < 0) {
        // 0x800373D0: sw          $v0, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r2;
            goto L_8003747C;
    }
    // 0x800373D0: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x800373D4: bgtz        $v0, L_800373E4
    if (SIGNED(ctx->r2) > 0) {
        // 0x800373D8: nop
    
            goto L_800373E4;
    }
    // 0x800373D8: nop

    // 0x800373DC: beql        $v1, $zero, L_80037480
    if (ctx->r3 == 0) {
        // 0x800373E0: addiu       $t4, $zero, 0x18
        ctx->r12 = ADD32(0, 0X18);
            goto L_80037480;
    }
    goto skip_4;
    // 0x800373E0: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
    skip_4:
L_800373E4:
    // 0x800373E4: blez        $s0, L_8003747C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800373E8: sra         $t4, $t1, 31
        ctx->r12 = S32(SIGNED(ctx->r9) >> 31);
            goto L_8003747C;
    }
    // 0x800373E8: sra         $t4, $t1, 31
    ctx->r12 = S32(SIGNED(ctx->r9) >> 31);
    // 0x800373EC: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x800373F0: lw          $t3, 0x4($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X4);
    // 0x800373F4: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x800373F8: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x800373FC: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x80037400: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x80037404: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
L_80037408:
    // 0x80037408: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x8003740C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80037410: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80037414: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x80037418: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8003741C: jal         0x800370E0
    // 0x80037420: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    lldiv_recomp(rdram, ctx);
        goto after_2;
    // 0x80037420: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_2:
    // 0x80037424: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80037428: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x8003742C: addiu       $a0, $s0, -0x1
    ctx->r4 = ADD32(ctx->r16, -0X1);
    // 0x80037430: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80037434: sw          $t9, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r25;
    // 0x80037438: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x8003743C: addu        $t7, $s2, $a0
    ctx->r15 = ADD32(ctx->r18, ctx->r4);
    // 0x80037440: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80037444: addu        $t5, $t3, $s3
    ctx->r13 = ADD32(ctx->r11, ctx->r19);
    // 0x80037448: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x8003744C: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x80037450: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80037454: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x80037458: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x8003745C: bltz        $t8, L_8003747C
    if (SIGNED(ctx->r24) < 0) {
        // 0x80037460: sw          $t9, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r25;
            goto L_8003747C;
    }
    // 0x80037460: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x80037464: bgtz        $t8, L_80037474
    if (SIGNED(ctx->r24) > 0) {
        // 0x80037468: nop
    
            goto L_80037474;
    }
    // 0x80037468: nop

    // 0x8003746C: beql        $t9, $zero, L_80037480
    if (ctx->r25 == 0) {
        // 0x80037470: addiu       $t4, $zero, 0x18
        ctx->r12 = ADD32(0, 0X18);
            goto L_80037480;
    }
    goto skip_5;
    // 0x80037470: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
    skip_5:
L_80037474:
    // 0x80037474: bgtzl       $s0, L_80037408
    if (SIGNED(ctx->r16) > 0) {
        // 0x80037478: lw          $t6, 0x38($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X38);
            goto L_80037408;
    }
    goto skip_6;
    // 0x80037478: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    skip_6:
L_8003747C:
    // 0x8003747C: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
L_80037480:
    // 0x80037480: subu        $a2, $t4, $s0
    ctx->r6 = SUB32(ctx->r12, ctx->r16);
    // 0x80037484: sw          $a2, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r6;
    // 0x80037488: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    // 0x8003748C: jal         0x800346F0
    // 0x80037490: addu        $a1, $s2, $s0
    ctx->r5 = ADD32(ctx->r18, ctx->r16);
    memcpy_recomp(rdram, ctx);
        goto after_3;
    // 0x80037490: addu        $a1, $s2, $s0
    ctx->r5 = ADD32(ctx->r18, ctx->r16);
    after_3:
    // 0x80037494: lw          $a1, 0x14($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X14);
    // 0x80037498: lw          $a0, 0x24($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X24);
    // 0x8003749C: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800374A0: beq         $at, $zero, L_800374AC
    if (ctx->r1 == 0) {
        // 0x800374A4: subu        $t5, $a0, $a1
        ctx->r13 = SUB32(ctx->r4, ctx->r5);
            goto L_800374AC;
    }
    // 0x800374A4: subu        $t5, $a0, $a1
    ctx->r13 = SUB32(ctx->r4, ctx->r5);
    // 0x800374A8: sw          $t5, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r13;
L_800374AC:
    // 0x800374AC: bgezl       $a0, L_800374F0
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800374B0: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800374F0;
    }
    goto skip_7;
    // 0x800374B0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_7:
    // 0x800374B4: lw          $t6, 0x30($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X30);
    // 0x800374B8: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800374BC: andi        $t7, $t6, 0x14
    ctx->r15 = ctx->r14 & 0X14;
    // 0x800374C0: bnel        $t7, $at, L_800374F0
    if (ctx->r15 != ctx->r1) {
        // 0x800374C4: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800374F0;
    }
    goto skip_8;
    // 0x800374C4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_8:
    // 0x800374C8: lw          $t8, 0x28($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X28);
    // 0x800374CC: lw          $t9, 0xC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XC);
    // 0x800374D0: lw          $v0, 0x10($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X10);
    // 0x800374D4: subu        $t2, $t8, $t9
    ctx->r10 = SUB32(ctx->r24, ctx->r25);
    // 0x800374D8: subu        $t3, $t2, $v0
    ctx->r11 = SUB32(ctx->r10, ctx->r2);
    // 0x800374DC: subu        $s0, $t3, $a1
    ctx->r16 = SUB32(ctx->r11, ctx->r5);
    // 0x800374E0: blez        $s0, L_800374EC
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800374E4: addu        $t4, $v0, $s0
        ctx->r12 = ADD32(ctx->r2, ctx->r16);
            goto L_800374EC;
    }
    // 0x800374E4: addu        $t4, $v0, $s0
    ctx->r12 = ADD32(ctx->r2, ctx->r16);
    // 0x800374E8: sw          $t4, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r12;
L_800374EC:
    // 0x800374EC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800374F0:
    // 0x800374F0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800374F4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800374F8: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800374FC: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80037500: jr          $ra
    // 0x80037504: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80037504: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void __OSGlobalIntMask(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void clearSceneBssRegion(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DF20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003DF24: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8003DF28: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8003DF2C: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8003DF30: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8003DF34: bne         $a0, $v0, L_8003DF48
    if (ctx->r4 != ctx->r2) {
        // 0x8003DF38: addu        $a1, $v1, $zero
        ctx->r5 = ADD32(ctx->r3, 0);
            goto L_8003DF48;
    }
    // 0x8003DF38: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x8003DF3C: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x8003DF40: j           L_8003DF58
    // 0x8003DF44: addiu       $v1, $v0, 0x1EF0
    ctx->r3 = ADD32(ctx->r2, 0X1EF0);
        goto L_8003DF58;
    // 0x8003DF44: addiu       $v1, $v0, 0x1EF0
    ctx->r3 = ADD32(ctx->r2, 0X1EF0);
L_8003DF48:
    // 0x8003DF48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003DF4C: bne         $a0, $v0, L_8003DF64
    if (ctx->r4 != ctx->r2) {
        // 0x8003DF50: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_8003DF64;
    }
    // 0x8003DF50: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x8003DF54: addiu       $v1, $v0, 0x3E0
    ctx->r3 = ADD32(ctx->r2, 0X3E0);
L_8003DF58:
    // 0x8003DF58: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8003DF5C: addiu       $v0, $v0, -0x2E00
    ctx->r2 = ADD32(ctx->r2, -0X2E00);
    // 0x8003DF60: subu        $a1, $v0, $v1
    ctx->r5 = SUB32(ctx->r2, ctx->r3);
L_8003DF64:
    // 0x8003DF64: jal         0x80001820
    // 0x8003DF68: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    queueDeferredClearRequest(rdram, ctx);
        goto after_0;
    // 0x8003DF68: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    after_0:
    // 0x8003DF6C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8003DF70: jr          $ra
    // 0x8003DF74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8003DF74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void clearDeferredClearRequest(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DF78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003DF7C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8003DF80: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8003DF84: jal         0x80001820
    // 0x8003DF88: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    queueDeferredClearRequest(rdram, ctx);
        goto after_0;
    // 0x8003DF88: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    after_0:
    // 0x8003DF8C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8003DF90: jr          $ra
    // 0x8003DF94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8003DF94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void fake_func_8003DF98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void mainGameLoop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    {
    static int s_log = -1;
    if (s_log < 0) {
        const char* e = getenv("ROGUESQ_LOG_HOOKS");
        s_log = (e && *e && *e != '0') ? 1 : 0;
    }
    if (s_log) {
        static int s_count = 0;
        ++s_count;
        if (s_count <= 4 || (s_count & 63) == 0) {
            extern void rs64_dbg_log4(const char* tag, unsigned a, unsigned b, unsigned c, unsigned d);
            uint32_t b04 = (uint32_t)MEM_BU(0xB44, (gpr)0xFFFFFFFF80130000ULL);
            uint32_t b21 = (uint32_t)MEM_BU(0xB61, (gpr)0xFFFFFFFF80130000ULL);
            uint32_t b50 = (uint32_t)MEM_W(0xB50, (gpr)0xFFFFFFFF80130000ULL);
            uint32_t b58 = (uint32_t)MEM_W(0xB58, (gpr)0xFFFFFFFF80130000ULL);
            rs64_dbg_log4("8003DFA0 b40+04 b40+21 B50 B58", b04, b21, b50, b58);
        }
    }
}
    // 0x8003DFA0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8003DFA4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8003DFA8: sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // 0x8003DFAC: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x8003DFB0: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x8003DFB4: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x8003DFB8: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8003DFBC: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8003DFC0: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8003DFC4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8003DFC8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003DFCC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8003DFD0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8003DFD4: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x8003DFD8: addiu       $s4, $fp, 0xB10
    ctx->r20 = ADD32(ctx->r30, 0XB10);
    // 0x8003DFDC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8003DFE0: jal         0x80023D30
    // 0x8003DFE4: sw          $v1, -0x76E0($v0)
    MEM_W(-0X76E0, ctx->r2) = ctx->r3;
    setGlobalByte_80038CE0(rdram, ctx);
        goto after_0;
    // 0x8003DFE4: sw          $v1, -0x76E0($v0)
    MEM_W(-0X76E0, ctx->r2) = ctx->r3;
    after_0:
    // 0x8003DFE8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8003DFEC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8003DFF0: jal         0x80003104
    // 0x8003DFF4: addiu       $a1, $a1, 0xB88
    ctx->r5 = ADD32(ctx->r5, 0XB88);
    func_80003104(rdram, ctx);
        goto after_1;
    // 0x8003DFF4: addiu       $a1, $a1, 0xB88
    ctx->r5 = ADD32(ctx->r5, 0XB88);
    after_1:
    // 0x8003DFF8: jal         0x80063B58
    // 0x8003DFFC: nop

    initAllPlayerSlots(rdram, ctx);
        goto after_2;
    // 0x8003DFFC: nop

    after_2:
    // 0x8003E000: jal         0x80003460
    // 0x8003E004: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    setRngSeed(rdram, ctx);
        goto after_3;
    // 0x8003E004: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x8003E008: jal         0x80000B20
    // 0x8003E00C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    loadOverlay(rdram, ctx);
        goto after_4;
    // 0x8003E00C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x8003E010: jal         0x8006D900
    // 0x8003E014: nop

    runIdleFramesAndLoadSaveData(rdram, ctx);
        goto after_5;
    // 0x8003E014: nop

    after_5:
    // 0x8003E018: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003E01C: addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
    // 0x8003E020: addiu       $v0, $s5, 0xB40
    ctx->r2 = ADD32(ctx->r21, 0XB40);
    // 0x8003E024: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8003E028: lui         $v0, 0x8003
    ctx->r2 = S32(0X8003 << 16);
    // 0x8003E02C: addiu       $s7, $v0, 0x7570
    ctx->r23 = ADD32(ctx->r2, 0X7570);
    // 0x8003E030: lw          $v0, 0x10($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X10);
    // 0x8003E034: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8003E038: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8003E03C: sh          $v0, 0x7D00($v1)
    MEM_H(0X7D00, ctx->r3) = ctx->r2;
    // 0x8003E040: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8003E044: sh          $v0, -0x7FA4($v1)
    MEM_H(-0X7FA4, ctx->r3) = ctx->r2;
L_8003E048:
    // 0x8003E048: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8003E04C:
    // 0x8003E04C: addiu       $a3, $zero, -0x21
    ctx->r7 = ADD32(0, -0X21);
    // 0x8003E050: addiu       $v1, $zero, -0x201
    ctx->r3 = ADD32(0, -0X201);
    // 0x8003E054: lw          $v0, 0x10($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X10);
    // 0x8003E058: addiu       $a1, $zero, -0x401
    ctx->r5 = ADD32(0, -0X401);
    // 0x8003E05C: and         $v0, $v0, $a3
    ctx->r2 = ctx->r2 & ctx->r7;
    // 0x8003E060: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8003E064: lw          $v1, 0x18($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X18);
    // 0x8003E068: and         $v0, $v0, $a1
    ctx->r2 = ctx->r2 & ctx->r5;
    // 0x8003E06C: sw          $v0, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->r2;
    // 0x8003E070: and         $v1, $v1, $a3
    ctx->r3 = ctx->r3 & ctx->r7;
    // 0x8003E074: jal         0x80000B20
    // 0x8003E078: sw          $v1, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r3;
    loadOverlay(rdram, ctx);
        goto after_6;
    // 0x8003E078: sw          $v1, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r3;
    after_6:
    // 0x8003E07C: lbu         $v0, 0x20($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X20);
    // 0x8003E080: beq         $v0, $zero, L_8003E0DC
    if (ctx->r2 == 0) {
        // 0x8003E084: addiu       $a1, $zero, 0x9
        ctx->r5 = ADD32(0, 0X9);
            goto L_8003E0DC;
    }
    // 0x8003E084: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x8003E088: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8003E08C: jal         0x800C58A0
    // 0x8003E090: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    menuOverlayInit(rdram, ctx);
        goto after_7;
    // 0x8003E090: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_7:
    // 0x8003E094: jal         0x8006F01C
    // 0x8003E098: nop

    isViModeTypePal(rdram, ctx);
        goto after_8;
    // 0x8003E098: nop

    after_8:
    // 0x8003E09C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8003E0A0: beq         $v0, $zero, L_8003E0DC
    if (ctx->r2 == 0) {
        // 0x8003E0A4: nop
    
            goto L_8003E0DC;
    }
    // 0x8003E0A4: nop

    // 0x8003E0A8: jal         0x8006ED90
    // 0x8003E0AC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    isUnlockBitSet(rdram, ctx);
        goto after_9;
    // 0x8003E0AC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_9:
    // 0x8003E0B0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8003E0B4: bne         $v0, $zero, L_8003E0DC
    if (ctx->r2 != 0) {
        // 0x8003E0B8: nop
    
            goto L_8003E0DC;
    }
    // 0x8003E0B8: nop

    // 0x8003E0BC: jal         0x80000B20
    // 0x8003E0C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    loadOverlay(rdram, ctx);
        goto after_10;
    // 0x8003E0C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_10:
    // 0x8003E0C4: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8003E0C8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8003E0CC: jal         0x800C58A0
    // 0x8003E0D0: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    menuOverlayInit(rdram, ctx);
        goto after_11;
    // 0x8003E0D0: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_11:
    // 0x8003E0D4: jal         0x8006E360
    // 0x8003E0D8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    setUnlockBitAndPersist(rdram, ctx);
        goto after_12;
    // 0x8003E0D8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_12:
L_8003E0DC:
    // 0x8003E0DC: lbu         $v0, 0x21($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X21);
    // 0x8003E0E0: bne         $v0, $zero, L_8003E114
    if (ctx->r2 != 0) {
        // 0x8003E0E4: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_8003E114;
    }
    // 0x8003E0E4: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x8003E0E8: lbu         $v1, 0x4($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X4);
    // 0x8003E0EC: beq         $v1, $v0, L_8003E114
    if (ctx->r3 == ctx->r2) {
        // 0x8003E0F0: addiu       $a3, $zero, 0x3
        ctx->r7 = ADD32(0, 0X3);
            goto L_8003E114;
    }
    // 0x8003E0F0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x8003E0F4: beq         $v1, $a3, L_8003E114
    if (ctx->r3 == ctx->r7) {
        // 0x8003E0F8: nop
    
            goto L_8003E114;
    }
    // 0x8003E0F8: nop

    // 0x8003E0FC: jal         0x80000B20
    // 0x8003E100: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    loadOverlay(rdram, ctx);
        goto after_13;
    // 0x8003E100: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_13:
    // 0x8003E104: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    // 0x8003E108: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8003E10C: jal         0x800A5D80
    // 0x8003E110: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    cinematicLoopBody(rdram, ctx);
        goto after_14;
    // 0x8003E110: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_14:
L_8003E114:
    // 0x8003E114: lbu         $v0, 0x22($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X22);
    // 0x8003E118: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8003E11C: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x8003E120: jal         0x80000B20
    // 0x8003E124: sll         $s0, $v0, 2
    ctx->r16 = S32(ctx->r2 << 2);
    loadOverlay(rdram, ctx);
        goto after_15;
    // 0x8003E124: sll         $s0, $v0, 2
    ctx->r16 = S32(ctx->r2 << 2);
    after_15:
    // 0x8003E128: lbu         $v0, 0x21($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X21);
    // 0x8003E12C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003E130: bnel        $v0, $a1, L_8003E138
    if (ctx->r2 != ctx->r5) {
        // 0x8003E134: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_8003E138;
    }
    goto skip_0;
    // 0x8003E134: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    skip_0:
L_8003E138:
    // 0x8003E138: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8003E13C: jal         0x800C58A0
    // 0x8003E140: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    menuOverlayInit(rdram, ctx);
        goto after_16;
    // 0x8003E140: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_16:
    // 0x8003E144: lw          $a0, 0x10($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X10);
    // 0x8003E148: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003E14C: andi        $v1, $a0, 0x1
    ctx->r3 = ctx->r4 & 0X1;
    // 0x8003E150: sh          $v1, 0x7D00($v0)
    MEM_H(0X7D00, ctx->r2) = ctx->r3;
    // 0x8003E154: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8003E158: sh          $v1, -0x7FA4($v0)
    MEM_H(-0X7FA4, ctx->r2) = ctx->r3;
    // 0x8003E15C: andi        $v0, $a0, 0x400
    ctx->r2 = ctx->r4 & 0X400;
    // 0x8003E160: beq         $v0, $zero, L_8003E250
    if (ctx->r2 == 0) {
        // 0x8003E164: addiu       $v0, $zero, -0x801
        ctx->r2 = ADD32(0, -0X801);
            goto L_8003E250;
    }
    // 0x8003E164: addiu       $v0, $zero, -0x801
    ctx->r2 = ADD32(0, -0X801);
    // 0x8003E168: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x8003E16C: sw          $v0, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->r2;
    // 0x8003E170: jal         0x80000B20
    // 0x8003E174: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    loadOverlay(rdram, ctx);
        goto after_17;
    // 0x8003E174: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_17:
    // 0x8003E178: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x8003E17C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8003E180: addiu       $s6, $v0, -0x13B0
    ctx->r22 = ADD32(ctx->r2, -0X13B0);
    // 0x8003E184: andi        $s0, $s2, 0xFF
    ctx->r16 = ctx->r18 & 0XFF;
L_8003E188:
    // 0x8003E188: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8003E18C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8003E190: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
    // 0x8003E194: addu        $s1, $v0, $s6
    ctx->r17 = ADD32(ctx->r2, ctx->r22);
    // 0x8003E198: lbu         $v0, 0x3($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X3);
    // 0x8003E19C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x8003E1A0: jal         0x800A5D80
    // 0x8003E1A4: sb          $v0, 0x1($s3)
    MEM_B(0X1, ctx->r19) = ctx->r2;
    cinematicLoopBody(rdram, ctx);
        goto after_18;
    // 0x8003E1A4: sb          $v0, 0x1($s3)
    MEM_B(0X1, ctx->r19) = ctx->r2;
    after_18:
    // 0x8003E1A8: lw          $v0, 0x10($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X10);
    // 0x8003E1AC: andi        $v0, $v0, 0x800
    ctx->r2 = ctx->r2 & 0X800;
    // 0x8003E1B0: bne         $v0, $zero, L_8003E1EC
    if (ctx->r2 != 0) {
        // 0x8003E1B4: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_8003E1EC;
    }
    // 0x8003E1B4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8003E1B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003E1BC: lbu         $v0, 0x3($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X3);
    // 0x8003E1C0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8003E1C4: jal         0x800A5D80
    // 0x8003E1C8: sb          $v0, 0x1($s3)
    MEM_B(0X1, ctx->r19) = ctx->r2;
    cinematicLoopBody(rdram, ctx);
        goto after_19;
    // 0x8003E1C8: sb          $v0, 0x1($s3)
    MEM_B(0X1, ctx->r19) = ctx->r2;
    after_19:
    // 0x8003E1CC: lw          $v0, 0x10($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X10);
    // 0x8003E1D0: andi        $v0, $v0, 0x800
    ctx->r2 = ctx->r2 & 0X800;
    // 0x8003E1D4: bne         $v0, $zero, L_8003E1EC
    if (ctx->r2 != 0) {
        // 0x8003E1D8: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8003E1EC;
    }
    // 0x8003E1D8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8003E1DC: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x8003E1E0: sltiu       $v0, $v0, 0x10
    ctx->r2 = ctx->r2 < 0X10 ? 1 : 0;
    // 0x8003E1E4: bne         $v0, $zero, L_8003E188
    if (ctx->r2 != 0) {
        // 0x8003E1E8: andi        $s0, $s2, 0xFF
        ctx->r16 = ctx->r18 & 0XFF;
            goto L_8003E188;
    }
    // 0x8003E1E8: andi        $s0, $s2, 0xFF
    ctx->r16 = ctx->r18 & 0XFF;
L_8003E1EC:
    // 0x8003E1EC: sb          $zero, 0xB40($s5)
    MEM_B(0XB40, ctx->r21) = 0;
    // 0x8003E1F0: sb          $zero, 0x21($s4)
    MEM_B(0X21, ctx->r20) = 0;
    // 0x8003E1F4: lw          $v0, 0x10($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X10);
    // 0x8003E1F8: addiu       $v1, $zero, -0x801
    ctx->r3 = ADD32(0, -0X801);
    // 0x8003E1FC: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8003E200: addiu       $v1, $zero, -0x401
    ctx->r3 = ADD32(0, -0X401);
    // 0x8003E204: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8003E208: j           L_8003E114
    // 0x8003E20C: sw          $v0, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->r2;
        goto L_8003E114;
    // 0x8003E20C: sw          $v0, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->r2;
L_8003E210:
    // 0x8003E210: jal         0x80000B20
    // 0x8003E214: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    loadOverlay(rdram, ctx);
        goto after_20;
    // 0x8003E214: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_20:
    // 0x8003E218: addiu       $a0, $s5, 0xB40
    ctx->r4 = ADD32(ctx->r21, 0XB40);
    // 0x8003E21C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8003E220: jal         0x800C58A0
    // 0x8003E224: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    menuOverlayInit(rdram, ctx);
        goto after_21;
    // 0x8003E224: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_21:
    // 0x8003E228: j           L_8003E04C
    // 0x8003E22C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_8003E04C;
    // 0x8003E22C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8003E230:
    // 0x8003E230: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x8003E234: addiu       $a3, $zero, -0x21
    ctx->r7 = ADD32(0, -0X21);
    // 0x8003E238: and         $v0, $v0, $a3
    ctx->r2 = ctx->r2 & ctx->r7;
    // 0x8003E23C: sw          $v0, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->r2;
    // 0x8003E240: jal         0x8006F044
    // 0x8003E244: sb          $zero, 0x21($s4)
    MEM_B(0X21, ctx->r20) = 0;
    cycleIdleDemoId(rdram, ctx);
        goto after_22;
    // 0x8003E244: sb          $zero, 0x21($s4)
    MEM_B(0X21, ctx->r20) = 0;
    after_22:
    // 0x8003E248: j           L_8003E114
    // 0x8003E24C: nop

        goto L_8003E114;
    // 0x8003E24C: nop

L_8003E250:
    // 0x8003E250: lw          $v1, 0x18($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X18);
    // 0x8003E254: lui         $v0, 0x200
    ctx->r2 = S32(0X200 << 16);
    // 0x8003E258: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x8003E25C: beq         $v0, $zero, L_8003E2E8
    if (ctx->r2 == 0) {
        // 0x8003E260: lui         $v0, 0xFDFF
        ctx->r2 = S32(0XFDFF << 16);
            goto L_8003E2E8;
    }
    // 0x8003E260: lui         $v0, 0xFDFF
    ctx->r2 = S32(0XFDFF << 16);
    // 0x8003E264: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x8003E268: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8003E26C: and         $v0, $v1, $v0
    ctx->r2 = ctx->r3 & ctx->r2;
    // 0x8003E270: jal         0x80000B20
    // 0x8003E274: sw          $v0, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r2;
    loadOverlay(rdram, ctx);
        goto after_23;
    // 0x8003E274: sw          $v0, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r2;
    after_23:
    // 0x8003E278: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x8003E27C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8003E280: sb          $zero, 0x1($s3)
    MEM_B(0X1, ctx->r19) = 0;
    // 0x8003E284: sb          $v0, 0xB40($s5)
    MEM_B(0XB40, ctx->r21) = ctx->r2;
    // 0x8003E288: sb          $zero, 0x2($s3)
    MEM_B(0X2, ctx->r19) = 0;
    // 0x8003E28C: jal         0x8006B000
    // 0x8003E290: sb          $a3, 0xB10($fp)
    MEM_B(0XB10, ctx->r30) = ctx->r7;
    applyLevelScreenAndCameraSettings(rdram, ctx);
        goto after_24;
    // 0x8003E290: sb          $a3, 0xB10($fp)
    MEM_B(0XB10, ctx->r30) = ctx->r7;
    after_24:
    // 0x8003E294: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // 0x8003E298: addiu       $a1, $s7, 0x1C
    ctx->r5 = ADD32(ctx->r23, 0X1C);
    // 0x8003E29C: jal         0x80001354
    // 0x8003E2A0: addiu       $a2, $s7, 0xC
    ctx->r6 = ADD32(ctx->r23, 0XC);
    runVideoFrameTick(rdram, ctx);
        goto after_25;
    // 0x8003E2A0: addiu       $a2, $s7, 0xC
    ctx->r6 = ADD32(ctx->r23, 0XC);
    after_25:
    // 0x8003E2A4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8003E2A8: jal         0x800047F4
    // 0x8003E2AC: addiu       $a0, $a0, -0x5C20
    ctx->r4 = ADD32(ctx->r4, -0X5C20);
    findManifestEntryByName(rdram, ctx);
        goto after_26;
    // 0x8003E2AC: addiu       $a0, $a0, -0x5C20
    ctx->r4 = ADD32(ctx->r4, -0X5C20);
    after_26:
    // 0x8003E2B0: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x8003E2B4: jal         0x800FA250
    // 0x8003E2B8: sw          $v0, 0x7CFC($a3)
    MEM_W(0X7CFC, ctx->r7) = ctx->r2;
    initMission(rdram, ctx);
        goto after_27;
    // 0x8003E2B8: sw          $v0, 0x7CFC($a3)
    MEM_W(0X7CFC, ctx->r7) = ctx->r2;
    after_27:
    // 0x8003E2BC: jal         0x800FA6A4
    // 0x8003E2C0: nop

    runInMissionFrame(rdram, ctx);
        goto after_28;
    // 0x8003E2C0: nop

    after_28:
    // 0x8003E2C4: jal         0x800FB9E4
    // 0x8003E2C8: nop

    endMissionCleanup(rdram, ctx);
        goto after_29;
    // 0x8003E2C8: nop

    after_29:
    // 0x8003E2CC: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x8003E2D0: lw          $a0, 0x7CFC($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X7CFC);
    // 0x8003E2D4: jal         0x80004994
    // 0x8003E2D8: nop

    freeManifestSegmentAssets(rdram, ctx);
        goto after_30;
    // 0x8003E2D8: nop

    after_30:
    // 0x8003E2DC: sb          $zero, 0x21($s4)
    MEM_B(0X21, ctx->r20) = 0;
    // 0x8003E2E0: j           L_8003E114
    // 0x8003E2E4: sb          $zero, 0xB40($s5)
    MEM_B(0XB40, ctx->r21) = 0;
        goto L_8003E114;
    // 0x8003E2E4: sb          $zero, 0xB40($s5)
    MEM_B(0XB40, ctx->r21) = 0;
L_8003E2E8:
    // 0x8003E2E8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003E2EC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8003E2F0: sb          $a3, 0x7CE0($v0)
    MEM_B(0X7CE0, ctx->r2) = ctx->r7;
    // 0x8003E2F4: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8003E2F8: addiu       $s0, $v0, -0x5C18
    ctx->r16 = ADD32(ctx->r2, -0X5C18);
    // 0x8003E2FC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003E300: addiu       $s1, $v0, 0xB1C
    ctx->r17 = ADD32(ctx->r2, 0XB1C);
L_8003E304:
    // 0x8003E304: lw          $v0, 0x10($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X10);
    // 0x8003E308: andi        $v0, $v0, 0x100
    ctx->r2 = ctx->r2 & 0X100;
    // 0x8003E30C: bne         $v0, $zero, L_8003E340
    if (ctx->r2 != 0) {
        // 0x8003E310: nop
    
            goto L_8003E340;
    }
    // 0x8003E310: nop

    // 0x8003E314: jal         0x80000B20
    // 0x8003E318: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    loadOverlay(rdram, ctx);
        goto after_31;
    // 0x8003E318: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_31:
    // 0x8003E31C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8003E320: lbu         $a0, 0xB40($s5)
    ctx->r4 = MEM_BU(ctx->r21, 0XB40);
    // 0x8003E324: jal         0x800A5D80
    // 0x8003E328: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    cinematicLoopBody(rdram, ctx);
        goto after_32;
    // 0x8003E328: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_32:
    // 0x8003E32C: lw          $a0, 0x10($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X10);
    // 0x8003E330: addiu       $v0, $zero, 0x820
    ctx->r2 = ADD32(0, 0X820);
    // 0x8003E334: andi        $v1, $a0, 0x820
    ctx->r3 = ctx->r4 & 0X820;
    // 0x8003E338: beq         $v1, $v0, L_8003E230
    if (ctx->r3 == ctx->r2) {
        // 0x8003E33C: addiu       $v0, $zero, -0x801
        ctx->r2 = ADD32(0, -0X801);
            goto L_8003E230;
    }
    // 0x8003E33C: addiu       $v0, $zero, -0x801
    ctx->r2 = ADD32(0, -0X801);
L_8003E340:
    // 0x8003E340: jal         0x80000B20
    // 0x8003E344: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    loadOverlay(rdram, ctx);
        goto after_33;
    // 0x8003E344: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_33:
    // 0x8003E348: jal         0x800BF358
    // 0x8003E34C: nop

    applyResModeFromSettings(rdram, ctx);
        goto after_34;
    // 0x8003E34C: nop

    after_34:
    // 0x8003E350: jal         0x8006B000
    // 0x8003E354: nop

    applyLevelScreenAndCameraSettings(rdram, ctx);
        goto after_35;
    // 0x8003E354: nop

    after_35:
    // 0x8003E358: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // 0x8003E35C: addiu       $a1, $s7, 0x1C
    ctx->r5 = ADD32(ctx->r23, 0X1C);
    // 0x8003E360: jal         0x80001354
    // 0x8003E364: addiu       $a2, $s7, 0xC
    ctx->r6 = ADD32(ctx->r23, 0XC);
    runVideoFrameTick(rdram, ctx);
        goto after_36;
    // 0x8003E364: addiu       $a2, $s7, 0xC
    ctx->r6 = ADD32(ctx->r23, 0XC);
    after_36:
    // 0x8003E368: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8003E36C: jal         0x800047F4
    // 0x8003E370: addiu       $a0, $a0, -0x5C20
    ctx->r4 = ADD32(ctx->r4, -0X5C20);
    findManifestEntryByName(rdram, ctx);
        goto after_37;
    // 0x8003E370: addiu       $a0, $a0, -0x5C20
    ctx->r4 = ADD32(ctx->r4, -0X5C20);
    after_37:
    // 0x8003E374: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x8003E378: jal         0x800FA250
    // 0x8003E37C: sw          $v0, 0x7CFC($a3)
    MEM_W(0X7CFC, ctx->r7) = ctx->r2;
    initMission(rdram, ctx);
        goto after_38;
    // 0x8003E37C: sw          $v0, 0x7CFC($a3)
    MEM_W(0X7CFC, ctx->r7) = ctx->r2;
    after_38:
    // 0x8003E380: jal         0x800FA6A4
    // 0x8003E384: nop

    runInMissionFrame(rdram, ctx);
        goto after_39;
    // 0x8003E384: nop

    after_39:
    // 0x8003E388: jal         0x800FB9E4
    // 0x8003E38C: nop

    endMissionCleanup(rdram, ctx);
        goto after_40;
    // 0x8003E38C: nop

    after_40:
    // 0x8003E390: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x8003E394: lw          $a0, 0x7CFC($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X7CFC);
    // 0x8003E398: jal         0x80004994
    // 0x8003E39C: nop

    freeManifestSegmentAssets(rdram, ctx);
        goto after_41;
    // 0x8003E39C: nop

    after_41:
    // 0x8003E3A0: lbu         $v1, 0x4($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X4);
    // 0x8003E3A4: addiu       $v0, $v1, -0x4
    ctx->r2 = ADD32(ctx->r3, -0X4);
    // 0x8003E3A8: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x8003E3AC: bne         $v0, $zero, L_8003E3C4
    if (ctx->r2 != 0) {
        // 0x8003E3B0: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_8003E3C4;
    }
    // 0x8003E3B0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8003E3B4: beq         $v1, $a3, L_8003E3C4
    if (ctx->r3 == ctx->r7) {
        // 0x8003E3B8: nop
    
            goto L_8003E3C4;
    }
    // 0x8003E3B8: nop

    // 0x8003E3BC: jal         0x8006EDD8
    // 0x8003E3C0: nop

    syncMissionUnlockBitsToSettings(rdram, ctx);
        goto after_42;
    // 0x8003E3C0: nop

    after_42:
L_8003E3C4:
    // 0x8003E3C4: lbu         $v1, 0x4($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X4);
    // 0x8003E3C8: sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // 0x8003E3CC: beq         $v0, $zero, L_8003E304
    if (ctx->r2 == 0) {
        // 0x8003E3D0: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8003E304;
    }
    // 0x8003E3D0: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8003E3D4: addu        $v0, $v0, $s0
    gpr jr_addend_8003E3DC = ctx->r2;
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8003E3D8: lw          $v0, 0x0($v0)
    ctx->r2 = ADD32(ctx->r2, 0X0);
    // 0x8003E3DC: jr          $v0
    // 0x8003E3E0: nop

    switch (jr_addend_8003E3DC >> 2) {
        case 0: goto L_8003E4FC; break;
        case 1: goto L_8003E3E4; break;
        case 2: goto L_8003E4BC; break;
        case 3: goto L_8003E514; break;
        case 4: goto L_8003E544; break;
        case 5: goto L_8003E544; break;
        default: switch_error(__func__, 0x8003E3DC, 0x8003A3E8);
    }
    // 0x8003E3E0: nop

L_8003E3E4:
    // 0x8003E3E4: jal         0x80000B20
    // 0x8003E3E8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    loadOverlay(rdram, ctx);
        goto after_43;
    // 0x8003E3E8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_43:
    // 0x8003E3EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003E3F0: lbu         $a0, 0xB40($s5)
    ctx->r4 = MEM_BU(ctx->r21, 0XB40);
    // 0x8003E3F4: jal         0x800A5D80
    // 0x8003E3F8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    cinematicLoopBody(rdram, ctx);
        goto after_44;
    // 0x8003E3F8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_44:
    // 0x8003E3FC: lbu         $s0, 0x1F($s4)
    ctx->r16 = MEM_BU(ctx->r20, 0X1F);
    // 0x8003E400: jal         0x8006EA78
    // 0x8003E404: nop

    initializeNumLives(rdram, ctx);
        goto after_45;
    // 0x8003E404: nop

    after_45:
    // 0x8003E408: lbu         $v0, 0xB40($s5)
    ctx->r2 = MEM_BU(ctx->r21, 0XB40);
    // 0x8003E40C: lbu         $a1, 0x1F($s4)
    ctx->r5 = MEM_BU(ctx->r20, 0X1F);
    // 0x8003E410: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x8003E414: slt         $v0, $a1, $v1
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003E418: bnel        $v0, $zero, L_8003E420
    if (ctx->r2 != 0) {
        // 0x8003E41C: addu        $a1, $v1, $zero
        ctx->r5 = ADD32(ctx->r3, 0);
            goto L_8003E420;
    }
    goto skip_1;
    // 0x8003E41C: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    skip_1:
L_8003E420:
    // 0x8003E420: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8003E424: jal         0x80000B20
    // 0x8003E428: sb          $a1, 0x1F($s4)
    MEM_B(0X1F, ctx->r20) = ctx->r5;
    loadOverlay(rdram, ctx);
        goto after_46;
    // 0x8003E428: sb          $a1, 0x1F($s4)
    MEM_B(0X1F, ctx->r20) = ctx->r5;
    after_46:
    // 0x8003E42C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8003E430: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8003E434: jal         0x800C58A0
    // 0x8003E438: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    menuOverlayInit(rdram, ctx);
        goto after_47;
    // 0x8003E438: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_47:
    // 0x8003E43C: lbu         $a0, 0xB40($s5)
    ctx->r4 = MEM_BU(ctx->r21, 0XB40);
    // 0x8003E440: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x8003E444: sltiu       $v0, $v1, 0x10
    ctx->r2 = ctx->r3 < 0X10 ? 1 : 0;
    // 0x8003E448: beq         $v0, $zero, L_8003E048
    if (ctx->r2 == 0) {
        // 0x8003E44C: addiu       $v0, $zero, 0xF
        ctx->r2 = ADD32(0, 0XF);
            goto L_8003E048;
    }
    // 0x8003E44C: addiu       $v0, $zero, 0xF
    ctx->r2 = ADD32(0, 0XF);
    // 0x8003E450: bne         $v1, $v0, L_8003E464
    if (ctx->r3 != ctx->r2) {
        // 0x8003E454: andi        $v0, $s0, 0xFF
        ctx->r2 = ctx->r16 & 0XFF;
            goto L_8003E464;
    }
    // 0x8003E454: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x8003E458: sltiu       $v0, $v0, 0x10
    ctx->r2 = ctx->r2 < 0X10 ? 1 : 0;
    // 0x8003E45C: bne         $v0, $zero, L_8003E470
    if (ctx->r2 != 0) {
        // 0x8003E460: nop
    
            goto L_8003E470;
    }
    // 0x8003E460: nop

L_8003E464:
    // 0x8003E464: lbu         $v0, 0x25($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X25);
    // 0x8003E468: beq         $v0, $zero, L_8003E4B4
    if (ctx->r2 == 0) {
        // 0x8003E46C: addiu       $v0, $a0, 0x1
        ctx->r2 = ADD32(ctx->r4, 0X1);
            goto L_8003E4B4;
    }
    // 0x8003E46C: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
L_8003E470:
    // 0x8003E470: jal         0x80000B20
    // 0x8003E474: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    loadOverlay(rdram, ctx);
        goto after_48;
    // 0x8003E474: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_48:
    // 0x8003E478: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8003E47C: jal         0x800AE878
    // 0x8003E480: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    dispatchCinematicFromMainLoop(rdram, ctx);
        goto after_49;
    // 0x8003E480: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_49:
    // 0x8003E484: jal         0x80000B20
    // 0x8003E488: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    loadOverlay(rdram, ctx);
        goto after_50;
    // 0x8003E488: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_50:
    // 0x8003E48C: addiu       $a0, $s5, 0xB40
    ctx->r4 = ADD32(ctx->r21, 0XB40);
    // 0x8003E490: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8003E494: jal         0x800C58A0
    // 0x8003E498: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    menuOverlayInit(rdram, ctx);
        goto after_51;
    // 0x8003E498: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_51:
    // 0x8003E49C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8003E4A0: sb          $a3, 0x22($s4)
    MEM_B(0X22, ctx->r20) = ctx->r7;
    // 0x8003E4A4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x8003E4A8: sb          $zero, 0x21($s4)
    MEM_B(0X21, ctx->r20) = 0;
    // 0x8003E4AC: j           L_8003E048
    // 0x8003E4B0: sb          $a3, 0x4($s4)
    MEM_B(0X4, ctx->r20) = ctx->r7;
        goto L_8003E048;
    // 0x8003E4B0: sb          $a3, 0x4($s4)
    MEM_B(0X4, ctx->r20) = ctx->r7;
L_8003E4B4:
    // 0x8003E4B4: j           L_8003E048
    // 0x8003E4B8: sb          $v0, 0xB40($s5)
    MEM_B(0XB40, ctx->r21) = ctx->r2;
        goto L_8003E048;
    // 0x8003E4B8: sb          $v0, 0xB40($s5)
    MEM_B(0XB40, ctx->r21) = ctx->r2;
L_8003E4BC:
    // 0x8003E4BC: lbu         $v0, 0xB10($fp)
    ctx->r2 = MEM_BU(ctx->r30, 0XB10);
    // 0x8003E4C0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8003E4C4: sb          $zero, 0x7CE0($v1)
    MEM_B(0X7CE0, ctx->r3) = 0;
    // 0x8003E4C8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8003E4CC: sb          $v0, 0xB10($fp)
    MEM_B(0XB10, ctx->r30) = ctx->r2;
    // 0x8003E4D0: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8003E4D4: blez        $v0, L_8003E518
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003E4D8: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8003E518;
    }
    // 0x8003E4D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8003E4DC: jal         0x80000B20
    // 0x8003E4E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    loadOverlay(rdram, ctx);
        goto after_52;
    // 0x8003E4E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_52:
    // 0x8003E4E4: addiu       $a0, $s5, 0xB40
    ctx->r4 = ADD32(ctx->r21, 0XB40);
    // 0x8003E4E8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8003E4EC: jal         0x800C58A0
    // 0x8003E4F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    menuOverlayInit(rdram, ctx);
        goto after_53;
    // 0x8003E4F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_53:
    // 0x8003E4F4: j           L_8003E304
    // 0x8003E4F8: nop

        goto L_8003E304;
    // 0x8003E4F8: nop

L_8003E4FC:
    // 0x8003E4FC: lbu         $v0, 0xB10($fp)
    ctx->r2 = MEM_BU(ctx->r30, 0XB10);
    // 0x8003E500: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8003E504: sb          $v0, 0xB10($fp)
    MEM_B(0XB10, ctx->r30) = ctx->r2;
    // 0x8003E508: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8003E50C: bgtz        $v0, L_8003E210
    if (SIGNED(ctx->r2) > 0) {
        // 0x8003E510: nop
    
            goto L_8003E210;
    }
    // 0x8003E510: nop

L_8003E514:
    // 0x8003E514: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8003E518:
    // 0x8003E518: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x8003E51C: sb          $zero, 0x21($s4)
    MEM_B(0X21, ctx->r20) = 0;
    // 0x8003E520: jal         0x80000B20
    // 0x8003E524: sb          $a3, 0x4($s4)
    MEM_B(0X4, ctx->r20) = ctx->r7;
    loadOverlay(rdram, ctx);
        goto after_54;
    // 0x8003E524: sb          $a3, 0x4($s4)
    MEM_B(0X4, ctx->r20) = ctx->r7;
    after_54:
    // 0x8003E528: addiu       $a0, $s5, 0xB40
    ctx->r4 = ADD32(ctx->r21, 0XB40);
    // 0x8003E52C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8003E530: jal         0x800C58A0
    // 0x8003E534: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    menuOverlayInit(rdram, ctx);
        goto after_55;
    // 0x8003E534: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_55:
    // 0x8003E538: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8003E53C: j           L_8003E048
    // 0x8003E540: sb          $a3, 0x22($s4)
    MEM_B(0X22, ctx->r20) = ctx->r7;
        goto L_8003E048;
    // 0x8003E540: sb          $a3, 0x22($s4)
    MEM_B(0X22, ctx->r20) = ctx->r7;
L_8003E544:
    // 0x8003E544: jal         0x800BF3A4
    // 0x8003E548: nop

    restoreGameSettingsAfterDemo(rdram, ctx);
        goto after_56;
    // 0x8003E548: nop

    after_56:
    // 0x8003E54C: jal         0x8006F044
    // 0x8003E550: sb          $zero, 0x21($s4)
    MEM_B(0X21, ctx->r20) = 0;
    cycleIdleDemoId(rdram, ctx);
        goto after_57;
    // 0x8003E550: sb          $zero, 0x21($s4)
    MEM_B(0X21, ctx->r20) = 0;
    after_57:
    // 0x8003E554: j           L_8003E04C
    // 0x8003E558: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_8003E04C;
    // 0x8003E558: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
;}
RECOMP_FUNC void fake_func_8003E55C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void initNpcSlotList(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E560: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003E564: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003E568: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8003E56C: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    // 0x8003E570: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003E574: jal         0x80001ACC
    // 0x8003E578: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x8003E578: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x8003E57C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8003E580: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x8003E584: sw          $v0, 0xBB0($s0)
    MEM_W(0XBB0, ctx->r16) = ctx->r2;
L_8003E588:
    // 0x8003E588: sll         $v1, $a1, 3
    ctx->r3 = S32(ctx->r5 << 3);
    // 0x8003E58C: addiu       $a0, $a1, -0x1
    ctx->r4 = ADD32(ctx->r5, -0X1);
    // 0x8003E590: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x8003E594: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x8003E598: addu        $v1, $v1, $a2
    ctx->r3 = ADD32(ctx->r3, ctx->r6);
    // 0x8003E59C: slti        $v0, $a1, 0x800
    ctx->r2 = SIGNED(ctx->r5) < 0X800 ? 1 : 0;
    // 0x8003E5A0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8003E5A4: sh          $a0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r4;
    // 0x8003E5A8: bne         $v0, $zero, L_8003E588
    if (ctx->r2 != 0) {
        // 0x8003E5AC: sh          $a1, 0x4($v1)
        MEM_H(0X4, ctx->r3) = ctx->r5;
            goto L_8003E588;
    }
    // 0x8003E5AC: sh          $a1, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r5;
    // 0x8003E5B0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8003E5B4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8003E5B8: sh          $v0, 0xBB4($v1)
    MEM_H(0XBB4, ctx->r3) = ctx->r2;
    // 0x8003E5BC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003E5C0: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    // 0x8003E5C4: lw          $v0, 0xBB0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XBB0);
    // 0x8003E5C8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8003E5CC: sh          $a0, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r4;
    // 0x8003E5D0: sh          $v1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r3;
    // 0x8003E5D4: sh          $zero, 0xE($v0)
    MEM_H(0XE, ctx->r2) = 0;
    // 0x8003E5D8: sh          $a0, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r4;
    // 0x8003E5DC: sh          $a0, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r4;
    // 0x8003E5E0: sh          $a0, 0x16($v0)
    MEM_H(0X16, ctx->r2) = ctx->r4;
    // 0x8003E5E4: sh          $a0, 0x3FFC($v0)
    MEM_H(0X3FFC, ctx->r2) = ctx->r4;
    // 0x8003E5E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003E5EC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003E5F0: jr          $ra
    // 0x8003E5F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8003E5F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void allocateNpcSlot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E5F8: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8003E5FC: lhu         $t2, 0xBB4($a2)
    ctx->r10 = MEM_HU(ctx->r6, 0XBB4);
    // 0x8003E600: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // 0x8003E604: andi        $a3, $t2, 0xFFFF
    ctx->r7 = ctx->r10 & 0XFFFF;
    // 0x8003E608: bne         $a3, $v1, L_8003E618
    if (ctx->r7 != ctx->r3) {
        // 0x8003E60C: lui         $t1, 0x8013
        ctx->r9 = S32(0X8013 << 16);
            goto L_8003E618;
    }
    // 0x8003E60C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8003E610: jr          $ra
    // 0x8003E614: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    return;
    // 0x8003E614: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
L_8003E618:
    // 0x8003E618: lw          $a1, 0xBB0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0XBB0);
    // 0x8003E61C: sll         $t0, $a3, 3
    ctx->r8 = S32(ctx->r7 << 3);
    // 0x8003E620: addu        $v0, $t0, $a1
    ctx->r2 = ADD32(ctx->r8, ctx->r5);
    // 0x8003E624: lhu         $v0, 0x4($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4);
    // 0x8003E628: sh          $v0, 0xBB4($a2)
    MEM_H(0XBB4, ctx->r6) = ctx->r2;
    // 0x8003E62C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8003E630: beq         $v0, $v1, L_8003E648
    if (ctx->r2 == ctx->r3) {
        // 0x8003E634: nop
    
            goto L_8003E648;
    }
    // 0x8003E634: nop

    // 0x8003E638: lhu         $v0, 0xBB4($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0XBB4);
    // 0x8003E63C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8003E640: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8003E644: sh          $v1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r3;
L_8003E648:
    // 0x8003E648: lw          $v0, 0xBB0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0XBB0);
    // 0x8003E64C: addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // 0x8003E650: sh          $v1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r3;
    // 0x8003E654: sh          $v1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r3;
    // 0x8003E658: beq         $a0, $zero, L_8003E67C
    if (ctx->r4 == 0) {
        // 0x8003E65C: sw          $zero, 0x0($v0)
        MEM_W(0X0, ctx->r2) = 0;
            goto L_8003E67C;
    }
    // 0x8003E65C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8003E660: lbu         $v0, 0x1B($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1B);
    // 0x8003E664: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x8003E668: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8003E66C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8003E670: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x8003E674: sb          $v1, 0x1B($a0)
    MEM_B(0X1B, ctx->r4) = ctx->r3;
    // 0x8003E678: sh          $t2, 0x1C($v0)
    MEM_H(0X1C, ctx->r2) = ctx->r10;
L_8003E67C:
    // 0x8003E67C: jr          $ra
    // 0x8003E680: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
    return;
    // 0x8003E680: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
;}
RECOMP_FUNC void popNpcSlotFromTail(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E684: beq         $a1, $zero, L_8003E6B0
    if (ctx->r5 == 0) {
        // 0x8003E688: addu        $t2, $zero, $zero
        ctx->r10 = ADD32(0, 0);
            goto L_8003E6B0;
    }
    // 0x8003E688: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x8003E68C: lbu         $v0, 0x1B($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1B);
    // 0x8003E690: sltiu       $v0, $v0, 0x10
    ctx->r2 = ctx->r2 < 0X10 ? 1 : 0;
    // 0x8003E694: bne         $v0, $zero, L_8003E6A4
    if (ctx->r2 != 0) {
        // 0x8003E698: nop
    
            goto L_8003E6A4;
    }
    // 0x8003E698: nop

L_8003E69C:
    // 0x8003E69C: jr          $ra
    // 0x8003E6A0: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    return;
    // 0x8003E6A0: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_8003E6A4:
    // 0x8003E6A4: beq         $a1, $zero, L_8003E6B0
    if (ctx->r5 == 0) {
        // 0x8003E6A8: addu        $t2, $zero, $zero
        ctx->r10 = ADD32(0, 0);
            goto L_8003E6B0;
    }
    // 0x8003E6A8: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x8003E6AC: lbu         $t2, 0x19($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X19);
L_8003E6B0:
    // 0x8003E6B0: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8003E6B4: lhu         $t1, 0xBB4($a2)
    ctx->r9 = MEM_HU(ctx->r6, 0XBB4);
    // 0x8003E6B8: ori         $a3, $zero, 0xFFFF
    ctx->r7 = 0 | 0XFFFF;
    // 0x8003E6BC: andi        $v0, $t1, 0xFFFF
    ctx->r2 = ctx->r9 & 0XFFFF;
    // 0x8003E6C0: beq         $v0, $a3, L_8003E69C
    if (ctx->r2 == ctx->r7) {
        // 0x8003E6C4: lui         $t0, 0x8013
        ctx->r8 = S32(0X8013 << 16);
            goto L_8003E69C;
    }
    // 0x8003E6C4: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8003E6C8: lw          $v1, 0xBB0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0XBB0);
    // 0x8003E6CC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8003E6D0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8003E6D4: lhu         $v0, 0x4($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4);
    // 0x8003E6D8: sh          $v0, 0xBB4($a2)
    MEM_H(0XBB4, ctx->r6) = ctx->r2;
    // 0x8003E6DC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8003E6E0: beq         $v0, $a3, L_8003E6FC
    if (ctx->r2 == ctx->r7) {
        // 0x8003E6E4: andi        $v0, $a0, 0xFFFF
        ctx->r2 = ctx->r4 & 0XFFFF;
            goto L_8003E6FC;
    }
    // 0x8003E6E4: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x8003E6E8: lhu         $v0, 0xBB4($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0XBB4);
    // 0x8003E6EC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8003E6F0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8003E6F4: sh          $a3, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r7;
    // 0x8003E6F8: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
L_8003E6FC:
    // 0x8003E6FC: beq         $v0, $a3, L_8003E748
    if (ctx->r2 == ctx->r7) {
        // 0x8003E700: addu        $v1, $a0, $zero
        ctx->r3 = ADD32(ctx->r4, 0);
            goto L_8003E748;
    }
    // 0x8003E700: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x8003E704: lw          $t0, 0xBB0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XBB0);
    // 0x8003E708: andi        $a3, $t2, 0xFF
    ctx->r7 = ctx->r10 & 0XFF;
    // 0x8003E70C: ori         $t2, $zero, 0xFFFF
    ctx->r10 = 0 | 0XFFFF;
    // 0x8003E710: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
L_8003E714:
    // 0x8003E714: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8003E718: addu        $a2, $v0, $t0
    ctx->r6 = ADD32(ctx->r2, ctx->r8);
    // 0x8003E71C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8003E720: beq         $v0, $zero, L_8003E73C
    if (ctx->r2 == 0) {
        // 0x8003E724: nop
    
            goto L_8003E73C;
    }
    // 0x8003E724: nop

    // 0x8003E728: lbu         $v0, 0x19($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X19);
    // 0x8003E72C: sltu        $v0, $a3, $v0
    ctx->r2 = ctx->r7 < ctx->r2 ? 1 : 0;
    // 0x8003E730: beq         $v0, $zero, L_8003E74C
    if (ctx->r2 == 0) {
        // 0x8003E734: andi        $t3, $t1, 0xFFFF
        ctx->r11 = ctx->r9 & 0XFFFF;
            goto L_8003E74C;
    }
    // 0x8003E734: andi        $t3, $t1, 0xFFFF
    ctx->r11 = ctx->r9 & 0XFFFF;
    // 0x8003E738: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
L_8003E73C:
    // 0x8003E73C: lhu         $v1, 0x4($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X4);
    // 0x8003E740: bne         $v1, $t2, L_8003E714
    if (ctx->r3 != ctx->r10) {
        // 0x8003E744: andi        $v0, $v1, 0xFFFF
        ctx->r2 = ctx->r3 & 0XFFFF;
            goto L_8003E714;
    }
    // 0x8003E744: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
L_8003E748:
    // 0x8003E748: andi        $t3, $t1, 0xFFFF
    ctx->r11 = ctx->r9 & 0XFFFF;
L_8003E74C:
    // 0x8003E74C: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x8003E750: sll         $t2, $t3, 3
    ctx->r10 = S32(ctx->r11 << 3);
    // 0x8003E754: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x8003E758: sll         $t0, $v0, 3
    ctx->r8 = S32(ctx->r2 << 3);
    // 0x8003E75C: lw          $a2, 0xBB0($t4)
    ctx->r6 = MEM_W(ctx->r12, 0XBB0);
    // 0x8003E760: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // 0x8003E764: addu        $v0, $t0, $a2
    ctx->r2 = ADD32(ctx->r8, ctx->r6);
    // 0x8003E768: lhu         $v0, 0x4($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X4);
    // 0x8003E76C: addu        $a3, $t2, $a2
    ctx->r7 = ADD32(ctx->r10, ctx->r6);
    // 0x8003E770: sh          $v0, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r2;
    // 0x8003E774: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8003E778: beq         $v0, $v1, L_8003E790
    if (ctx->r2 == ctx->r3) {
        // 0x8003E77C: nop
    
            goto L_8003E790;
    }
    // 0x8003E77C: nop

    // 0x8003E780: lhu         $v0, 0x4($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X4);
    // 0x8003E784: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8003E788: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8003E78C: sh          $t1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r9;
L_8003E790:
    // 0x8003E790: lw          $v0, 0xBB0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0XBB0);
    // 0x8003E794: addu        $v1, $t2, $v0
    ctx->r3 = ADD32(ctx->r10, ctx->r2);
    // 0x8003E798: addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // 0x8003E79C: sh          $a0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r4;
    // 0x8003E7A0: sh          $t1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r9;
    // 0x8003E7A4: beq         $a1, $zero, L_8003E7C8
    if (ctx->r5 == 0) {
        // 0x8003E7A8: sw          $a1, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r5;
            goto L_8003E7C8;
    }
    // 0x8003E7A8: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x8003E7AC: lbu         $v0, 0x1B($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1B);
    // 0x8003E7B0: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x8003E7B4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8003E7B8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8003E7BC: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x8003E7C0: sb          $v1, 0x1B($a1)
    MEM_B(0X1B, ctx->r5) = ctx->r3;
    // 0x8003E7C4: sh          $t1, 0x1C($v0)
    MEM_H(0X1C, ctx->r2) = ctx->r9;
L_8003E7C8:
    // 0x8003E7C8: jr          $ra
    // 0x8003E7CC: addu        $v0, $t3, $zero
    ctx->r2 = ADD32(ctx->r11, 0);
    return;
    // 0x8003E7CC: addu        $v0, $t3, $zero
    ctx->r2 = ADD32(ctx->r11, 0);
;}
RECOMP_FUNC void unregisterAndFreeNpcSlot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E7D0: lbu         $v0, 0x1B($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1B);
    // 0x8003E7D4: addu        $t1, $a0, $zero
    ctx->r9 = ADD32(ctx->r4, 0);
    // 0x8003E7D8: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    // 0x8003E7DC: bltz        $a0, L_8003E8D4
    if (SIGNED(ctx->r4) < 0) {
        // 0x8003E7E0: lui         $a3, 0x8013
        ctx->r7 = S32(0X8013 << 16);
            goto L_8003E8D4;
    }
    // 0x8003E7E0: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x8003E7E4: andi        $v1, $t1, 0xFFFF
    ctx->r3 = ctx->r9 & 0XFFFF;
    // 0x8003E7E8: sll         $a2, $v1, 3
    ctx->r6 = S32(ctx->r3 << 3);
    // 0x8003E7EC: ori         $t0, $zero, 0xFFFF
    ctx->r8 = 0 | 0XFFFF;
    // 0x8003E7F0: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x8003E7F4: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
L_8003E7F8:
    // 0x8003E7F8: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x8003E7FC: lhu         $v0, 0x1C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X1C);
    // 0x8003E800: bnel        $v0, $v1, L_8003E8CC
    if (ctx->r2 != ctx->r3) {
        // 0x8003E804: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_8003E8CC;
    }
    goto skip_0;
    // 0x8003E804: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    skip_0:
    // 0x8003E808: lbu         $v0, 0x1B($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1B);
    // 0x8003E80C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8003E810: sb          $v0, 0x1B($a1)
    MEM_B(0X1B, ctx->r5) = ctx->r2;
    // 0x8003E814: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8003E818: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003E81C: beq         $v0, $zero, L_8003E84C
    if (ctx->r2 == 0) {
        // 0x8003E820: sll         $v1, $a0, 1
        ctx->r3 = S32(ctx->r4 << 1);
            goto L_8003E84C;
    }
    // 0x8003E820: sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4 << 1);
L_8003E824:
    // 0x8003E824: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8003E828: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8003E82C: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x8003E830: lhu         $v0, 0x1C($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X1C);
    // 0x8003E834: addu        $v1, $a1, $v1
    ctx->r3 = ADD32(ctx->r5, ctx->r3);
    // 0x8003E838: sh          $v0, 0x1C($v1)
    MEM_H(0X1C, ctx->r3) = ctx->r2;
    // 0x8003E83C: lbu         $v0, 0x1B($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1B);
    // 0x8003E840: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003E844: bne         $v0, $zero, L_8003E824
    if (ctx->r2 != 0) {
        // 0x8003E848: sll         $v1, $a0, 1
        ctx->r3 = S32(ctx->r4 << 1);
            goto L_8003E824;
    }
    // 0x8003E848: sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4 << 1);
L_8003E84C:
    // 0x8003E84C: lw          $a0, 0xBB0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0XBB0);
    // 0x8003E850: addu        $v1, $a2, $a0
    ctx->r3 = ADD32(ctx->r6, ctx->r4);
    // 0x8003E854: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
    // 0x8003E858: beq         $v0, $t0, L_8003E874
    if (ctx->r2 == ctx->r8) {
        // 0x8003E85C: sll         $v0, $v0, 3
        ctx->r2 = S32(ctx->r2 << 3);
            goto L_8003E874;
    }
    // 0x8003E85C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8003E860: lhu         $v1, 0x6($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X6);
    // 0x8003E864: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8003E868: sh          $v1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r3;
    // 0x8003E86C: lw          $a0, 0xBB0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0XBB0);
    // 0x8003E870: addu        $v1, $a2, $a0
    ctx->r3 = ADD32(ctx->r6, ctx->r4);
L_8003E874:
    // 0x8003E874: lhu         $v0, 0x6($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X6);
    // 0x8003E878: beq         $v0, $t0, L_8003E88C
    if (ctx->r2 == ctx->r8) {
        // 0x8003E87C: sll         $v0, $v0, 3
        ctx->r2 = S32(ctx->r2 << 3);
            goto L_8003E88C;
    }
    // 0x8003E87C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8003E880: lhu         $v1, 0x4($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X4);
    // 0x8003E884: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8003E888: sh          $v1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r3;
L_8003E88C:
    // 0x8003E88C: lw          $a0, 0xBB0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0XBB0);
    // 0x8003E890: lhu         $v1, 0xBB4($t2)
    ctx->r3 = MEM_HU(ctx->r10, 0XBB4);
    // 0x8003E894: addu        $v0, $a2, $a0
    ctx->r2 = ADD32(ctx->r6, ctx->r4);
    // 0x8003E898: sh          $v1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r3;
    // 0x8003E89C: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x8003E8A0: beq         $v1, $t0, L_8003E8B8
    if (ctx->r3 == ctx->r8) {
        // 0x8003E8A4: nop
    
            goto L_8003E8B8;
    }
    // 0x8003E8A4: nop

    // 0x8003E8A8: lhu         $v0, 0xBB4($t2)
    ctx->r2 = MEM_HU(ctx->r10, 0XBB4);
    // 0x8003E8AC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8003E8B0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8003E8B4: sh          $t1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r9;
L_8003E8B8:
    // 0x8003E8B8: lw          $v0, 0xBB0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XBB0);
    // 0x8003E8BC: sh          $t1, 0xBB4($t2)
    MEM_H(0XBB4, ctx->r10) = ctx->r9;
    // 0x8003E8C0: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x8003E8C4: jr          $ra
    // 0x8003E8C8: sh          $t0, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r8;
    return;
    // 0x8003E8C8: sh          $t0, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r8;
L_8003E8CC:
    // 0x8003E8CC: bgez        $a0, L_8003E7F8
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8003E8D0: sll         $v0, $a0, 1
        ctx->r2 = S32(ctx->r4 << 1);
            goto L_8003E7F8;
    }
    // 0x8003E8D0: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
L_8003E8D4:
    // 0x8003E8D4: jr          $ra
    // 0x8003E8D8: nop

    return;
    // 0x8003E8D8: nop

;}
RECOMP_FUNC void slotDispatcherIter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E8DC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8003E8E0: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x8003E8E4: addu        $s7, $a1, $zero
    ctx->r23 = ADD32(ctx->r5, 0);
    // 0x8003E8E8: sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // 0x8003E8EC: addu        $fp, $a2, $zero
    ctx->r30 = ADD32(ctx->r6, 0);
    // 0x8003E8F0: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8003E8F4: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x8003E8F8: andi        $v1, $s4, 0xFFFF
    ctx->r3 = ctx->r20 & 0XFFFF;
    // 0x8003E8FC: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8003E900: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8003E904: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x8003E908: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x8003E90C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8003E910: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8003E914: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8003E918: beq         $v1, $v0, L_8003EA18
    if (ctx->r3 == ctx->r2) {
        // 0x8003E91C: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_8003EA18;
    }
    // 0x8003E91C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003E920: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x8003E924: addu        $s6, $v0, $zero
    ctx->r22 = ADD32(ctx->r2, 0);
    // 0x8003E928: andi        $v0, $s4, 0xFFFF
    ctx->r2 = ctx->r20 & 0XFFFF;
L_8003E92C:
    // 0x8003E92C: lw          $v1, 0xBB0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0XBB0);
    // 0x8003E930: sll         $s2, $v0, 3
    ctx->r18 = S32(ctx->r2 << 3);
    // 0x8003E934: addu        $v0, $s2, $v1
    ctx->r2 = ADD32(ctx->r18, ctx->r3);
    // 0x8003E938: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8003E93C: beq         $a0, $zero, L_8003EA08
    if (ctx->r4 == 0) {
        // 0x8003E940: addu        $s1, $a0, $zero
        ctx->r17 = ADD32(ctx->r4, 0);
            goto L_8003EA08;
    }
    // 0x8003E940: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8003E944: lbu         $v0, 0x1A($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1A);
    // 0x8003E948: lhu         $v1, 0x14($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X14);
    // 0x8003E94C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8003E950: andi        $v1, $v1, 0x8
    ctx->r3 = ctx->r3 & 0X8;
    // 0x8003E954: bne         $v1, $zero, L_8003E9C4
    if (ctx->r3 != 0) {
        // 0x8003E958: sb          $v0, 0x1A($s1)
        MEM_B(0X1A, ctx->r17) = ctx->r2;
            goto L_8003E9C4;
    }
    // 0x8003E958: sb          $v0, 0x1A($s1)
    MEM_B(0X1A, ctx->r17) = ctx->r2;
    // 0x8003E95C: andi        $a1, $s7, 0xFFFF
    ctx->r5 = ctx->r23 & 0XFFFF;
    // 0x8003E960: lw          $v1, 0xBB0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0XBB0);
    // 0x8003E964: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8003E968: addu        $v1, $s2, $v1
    ctx->r3 = ADD32(ctx->r18, ctx->r3);
    // 0x8003E96C: lhu         $s0, 0x4($v1)
    ctx->r16 = MEM_HU(ctx->r3, 0X4);
    // 0x8003E970: lhu         $s3, 0x6($v1)
    ctx->r19 = MEM_HU(ctx->r3, 0X6);
    // 0x8003E974: jalr        $v0
    // 0x8003E978: addu        $a2, $fp, $zero
    ctx->r6 = ADD32(ctx->r30, 0);
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x8003E978: addu        $a2, $fp, $zero
    ctx->r6 = ADD32(ctx->r30, 0);
    after_0:
    // 0x8003E97C: beq         $v0, $zero, L_8003E9BC
    if (ctx->r2 == 0) {
        // 0x8003E980: andi        $a0, $s3, 0xFFFF
        ctx->r4 = ctx->r19 & 0XFFFF;
            goto L_8003E9BC;
    }
    // 0x8003E980: andi        $a0, $s3, 0xFFFF
    ctx->r4 = ctx->r19 & 0XFFFF;
    // 0x8003E984: lw          $a1, 0xBB0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0XBB0);
    // 0x8003E988: addu        $v1, $s2, $a1
    ctx->r3 = ADD32(ctx->r18, ctx->r5);
    // 0x8003E98C: lhu         $v0, 0x6($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X6);
    // 0x8003E990: bne         $v0, $a0, L_8003E9A4
    if (ctx->r2 != ctx->r4) {
        // 0x8003E994: andi        $v0, $s0, 0xFFFF
        ctx->r2 = ctx->r16 & 0XFFFF;
            goto L_8003E9A4;
    }
    // 0x8003E994: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x8003E998: lhu         $s0, 0x4($v1)
    ctx->r16 = MEM_HU(ctx->r3, 0X4);
    // 0x8003E99C: j           L_8003E9D0
    // 0x8003E9A0: nop

        goto L_8003E9D0;
    // 0x8003E9A0: nop

L_8003E9A4:
    // 0x8003E9A4: beq         $v0, $s6, L_8003E9D0
    if (ctx->r2 == ctx->r22) {
        // 0x8003E9A8: sll         $v0, $v0, 3
        ctx->r2 = S32(ctx->r2 << 3);
            goto L_8003E9D0;
    }
    // 0x8003E9A8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8003E9AC: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8003E9B0: lhu         $v0, 0x6($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6);
    // 0x8003E9B4: beq         $v0, $a0, L_8003E9D0
    if (ctx->r2 == ctx->r4) {
        // 0x8003E9B8: nop
    
            goto L_8003E9D0;
    }
    // 0x8003E9B8: nop

L_8003E9BC:
    // 0x8003E9BC: j           L_8003E9D0
    // 0x8003E9C0: ori         $s0, $zero, 0xFFFF
    ctx->r16 = 0 | 0XFFFF;
        goto L_8003E9D0;
    // 0x8003E9C0: ori         $s0, $zero, 0xFFFF
    ctx->r16 = 0 | 0XFFFF;
L_8003E9C4:
    // 0x8003E9C4: lw          $v0, 0xBB0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0XBB0);
    // 0x8003E9C8: addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // 0x8003E9CC: lhu         $s0, 0x4($v0)
    ctx->r16 = MEM_HU(ctx->r2, 0X4);
L_8003E9D0:
    // 0x8003E9D0: lbu         $v0, 0x1A($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X1A);
    // 0x8003E9D4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    { if (((uint64_t)ctx->r17 & 0xFFFFFFFFE0000000ULL) != 0xFFFFFFFF80000000ULL) { ctx->r17 = 0; goto L_8003EA08; } }
    // 0x8003E9D8: sb          $v0, 0x1A($s1)
    MEM_B(0X1A, ctx->r17) = ctx->r2;
    // 0x8003E9DC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8003E9E0: bnel        $v0, $zero, L_8003EA10
    if (ctx->r2 != 0) {
        // 0x8003E9E4: addu        $s4, $s0, $zero
        ctx->r20 = ADD32(ctx->r16, 0);
            goto L_8003EA10;
    }
    goto skip_0;
    // 0x8003E9E4: addu        $s4, $s0, $zero
    ctx->r20 = ADD32(ctx->r16, 0);
    skip_0:
    // 0x8003E9E8: lhu         $v0, 0x14($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X14);
    // 0x8003E9EC: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x8003E9F0: beql        $v0, $zero, L_8003EA10
    if (ctx->r2 == 0) {
        // 0x8003E9F4: addu        $s4, $s0, $zero
        ctx->r20 = ADD32(ctx->r16, 0);
            goto L_8003EA10;
    }
    goto skip_1;
    // 0x8003E9F4: addu        $s4, $s0, $zero
    ctx->r20 = ADD32(ctx->r16, 0);
    skip_1:
    // 0x8003E9F8: jal         0x8003ED74
    // 0x8003E9FC: andi        $a0, $s4, 0xFFFF
    ctx->r4 = ctx->r20 & 0XFFFF;
    destroyNpcSlotByIndex(rdram, ctx);
        goto after_1;
    // 0x8003E9FC: andi        $a0, $s4, 0xFFFF
    ctx->r4 = ctx->r20 & 0XFFFF;
    after_1:
    // 0x8003EA00: j           L_8003EA10
    // 0x8003EA04: addu        $s4, $s0, $zero
    ctx->r20 = ADD32(ctx->r16, 0);
        goto L_8003EA10;
    // 0x8003EA04: addu        $s4, $s0, $zero
    ctx->r20 = ADD32(ctx->r16, 0);
L_8003EA08:
    // 0x8003EA08: lhu         $s0, 0x4($v0)
    ctx->r16 = MEM_HU(ctx->r2, 0X4);
    // 0x8003EA0C: addu        $s4, $s0, $zero
    ctx->r20 = ADD32(ctx->r16, 0);
L_8003EA10:
    // 0x8003EA10: bne         $s4, $s6, L_8003E92C
    if (ctx->r20 != ctx->r22) {
        // 0x8003EA14: andi        $v0, $s4, 0xFFFF
        ctx->r2 = ctx->r20 & 0XFFFF;
            goto L_8003E92C;
    }
    // 0x8003EA14: andi        $v0, $s4, 0xFFFF
    ctx->r2 = ctx->r20 & 0XFFFF;
L_8003EA18:
    // 0x8003EA18: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8003EA1C: lw          $fp, 0x30($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X30);
    // 0x8003EA20: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x8003EA24: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x8003EA28: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x8003EA2C: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8003EA30: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8003EA34: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8003EA38: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8003EA3C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003EA40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8003EA44: jr          $ra
    // 0x8003EA48: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8003EA48: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void slotDispatcherInner(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003EA4C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003EA50: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8003EA54: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8003EA58: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8003EA5C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8003EA60: lhu         $v1, 0x14($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X14);
    // 0x8003EA64: andi        $v0, $v1, 0x4
    ctx->r2 = ctx->r3 & 0X4;
    // 0x8003EA68: bne         $v0, $zero, L_8003EBFC
    if (ctx->r2 != 0) {
        // 0x8003EA6C: andi        $v0, $v1, 0x1
        ctx->r2 = ctx->r3 & 0X1;
            goto L_8003EBFC;
    }
    // 0x8003EA6C: andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // 0x8003EA70: beq         $v0, $zero, L_8003EA80
    if (ctx->r2 == 0) {
        // 0x8003EA74: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8003EA80;
    }
    // 0x8003EA74: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003EA78: j           L_8003EA88
    // 0x8003EA7C: addiu       $s0, $v0, 0xBC0
    ctx->r16 = ADD32(ctx->r2, 0XBC0);
        goto L_8003EA88;
    // 0x8003EA7C: addiu       $s0, $v0, 0xBC0
    ctx->r16 = ADD32(ctx->r2, 0XBC0);
L_8003EA80:
    // 0x8003EA80: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8003EA84: addiu       $s0, $v0, 0xBC4
    ctx->r16 = ADD32(ctx->r2, 0XBC4);
L_8003EA88:
    // 0x8003EA88: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8003EA8C: bne         $a0, $zero, L_8003EAE0
    if (ctx->r4 != 0) {
        // 0x8003EA90: nop
    
            goto L_8003EAE0;
    }
    // 0x8003EA90: nop

    // 0x8003EA94: addiu       $a0, $zero, 0x204C
    ctx->r4 = ADD32(0, 0X204C);
    // 0x8003EA98: jal         0x80001ACC
    // 0x8003EA9C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x8003EA9C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x8003EAA0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8003EAA4: addiu       $v0, $zero, 0x3F
    ctx->r2 = ADD32(0, 0X3F);
    // 0x8003EAA8: addu        $v1, $a0, $v0
    ctx->r3 = ADD32(ctx->r4, ctx->r2);
    // 0x8003EAAC: sw          $zero, 0x44($a0)
    MEM_W(0X44, ctx->r4) = 0;
    // 0x8003EAB0: sw          $zero, 0x48($a0)
    MEM_W(0X48, ctx->r4) = 0;
L_8003EAB4:
    // 0x8003EAB4: sb          $v0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r2;
    // 0x8003EAB8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8003EABC: bgez        $v0, L_8003EAB4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8003EAC0: addiu       $v1, $v1, -0x1
        ctx->r3 = ADD32(ctx->r3, -0X1);
            goto L_8003EAB4;
    }
    // 0x8003EAC0: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8003EAC4: lhu         $v0, 0x14($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X14);
    // 0x8003EAC8: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8003EACC: beq         $v0, $zero, L_8003EAD8
    if (ctx->r2 == 0) {
        // 0x8003EAD0: addiu       $v1, $zero, 0x1F
        ctx->r3 = ADD32(0, 0X1F);
            goto L_8003EAD8;
    }
    // 0x8003EAD0: addiu       $v1, $zero, 0x1F
    ctx->r3 = ADD32(0, 0X1F);
    // 0x8003EAD4: addiu       $v1, $zero, 0x3F
    ctx->r3 = ADD32(0, 0X3F);
L_8003EAD8:
    // 0x8003EAD8: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // 0x8003EADC: sw          $a0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r4;
L_8003EAE0:
    // 0x8003EAE0: lb          $v0, 0x0($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X0);
    // 0x8003EAE4: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x8003EAE8: lbu         $v1, 0x1($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X1);
    // 0x8003EAEC: lhu         $v0, 0x14($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X14);
    // 0x8003EAF0: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8003EAF4: beq         $v0, $zero, L_8003EB20
    if (ctx->r2 == 0) {
        // 0x8003EAF8: sb          $v1, 0x18($s1)
        MEM_B(0X18, ctx->r17) = ctx->r3;
            goto L_8003EB20;
    }
    // 0x8003EAF8: sb          $v1, 0x18($s1)
    MEM_B(0X18, ctx->r17) = ctx->r3;
    // 0x8003EAFC: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8003EB00: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x8003EB04: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8003EB08: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8003EB0C: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x8003EB10: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // 0x8003EB14: lb          $v0, 0x1($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X1);
    // 0x8003EB18: j           L_8003EB40
    // 0x8003EB1C: sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2 << 7);
        goto L_8003EB40;
    // 0x8003EB1C: sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2 << 7);
L_8003EB20:
    // 0x8003EB20: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8003EB24: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x8003EB28: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8003EB2C: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8003EB30: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x8003EB34: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // 0x8003EB38: lb          $v0, 0x1($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X1);
    // 0x8003EB3C: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
L_8003EB40:
    // 0x8003EB40: addiu       $v0, $v0, 0x4C
    ctx->r2 = ADD32(ctx->r2, 0X4C);
    // 0x8003EB44: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x8003EB48: sw          $v0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r2;
    // 0x8003EB4C: lb          $a1, 0x0($a0)
    ctx->r5 = MEM_B(ctx->r4, 0X0);
    // 0x8003EB50: bgez        $a1, L_8003EB98
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8003EB54: nop
    
            goto L_8003EB98;
    }
    // 0x8003EB54: nop

    // 0x8003EB58: lw          $v1, 0x44($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X44);
    // 0x8003EB5C: beq         $v1, $zero, L_8003EB70
    if (ctx->r3 == 0) {
        // 0x8003EB60: nop
    
            goto L_8003EB70;
    }
    // 0x8003EB60: nop

    // 0x8003EB64: lw          $v0, 0x48($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X48);
    // 0x8003EB68: j           L_8003EB78
    // 0x8003EB6C: sw          $v0, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r2;
        goto L_8003EB78;
    // 0x8003EB6C: sw          $v0, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r2;
L_8003EB70:
    // 0x8003EB70: lw          $v0, 0x48($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X48);
    // 0x8003EB74: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
L_8003EB78:
    // 0x8003EB78: lw          $v1, 0x48($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X48);
    // 0x8003EB7C: beql        $v1, $zero, L_8003EB90
    if (ctx->r3 == 0) {
        // 0x8003EB80: sw          $zero, 0x44($a0)
        MEM_W(0X44, ctx->r4) = 0;
            goto L_8003EB90;
    }
    goto skip_0;
    // 0x8003EB80: sw          $zero, 0x44($a0)
    MEM_W(0X44, ctx->r4) = 0;
    skip_0:
    // 0x8003EB84: lw          $v0, 0x44($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X44);
    // 0x8003EB88: sw          $v0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r2;
    // 0x8003EB8C: sw          $zero, 0x44($a0)
    MEM_W(0X44, ctx->r4) = 0;
L_8003EB90:
    // 0x8003EB90: j           L_8003EBFC
    // 0x8003EB94: sw          $zero, 0x48($a0)
    MEM_W(0X48, ctx->r4) = 0;
        goto L_8003EBFC;
    // 0x8003EB94: sw          $zero, 0x48($a0)
    MEM_W(0X48, ctx->r4) = 0;
L_8003EB98:
    // 0x8003EB98: lw          $v1, 0x44($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X44);
    // 0x8003EB9C: beq         $v1, $zero, L_8003EBFC
    if (ctx->r3 == 0) {
        // 0x8003EBA0: nop
    
            goto L_8003EBFC;
    }
    // 0x8003EBA0: nop

    { if (((uint64_t)ctx->r2 & 0xFFFFFFFFE0000000ULL) != 0xFFFFFFFF80000000ULL) goto L_8003EBFC; }
    // 0x8003EBA4: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8003EBA8: slt         $v0, $a1, $v0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003EBAC: beq         $v0, $zero, L_8003EBFC
    if (ctx->r2 == 0) {
        // 0x8003EBB0: nop
    
            goto L_8003EBFC;
    }
    // 0x8003EBB0: nop

    // 0x8003EBB4: lw          $v0, 0x48($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X48);
    // 0x8003EBB8: bnel        $v0, $zero, L_8003EBC0
    if (ctx->r2 != 0) {
        // 0x8003EBBC: sw          $v1, 0x44($v0)
        MEM_W(0X44, ctx->r2) = ctx->r3;
            goto L_8003EBC0;
    }
    goto skip_1;
    // 0x8003EBBC: sw          $v1, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r3;
    skip_1:
L_8003EBC0:
    // 0x8003EBC0: lw          $v1, 0x44($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X44);
    // 0x8003EBC4: lw          $v0, 0x48($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X48);
    // 0x8003EBC8: sw          $v0, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r2;
    // 0x8003EBCC: lw          $v0, 0x44($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X44);
    // 0x8003EBD0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8003EBD4: sw          $v0, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->r2;
    // 0x8003EBD8: lw          $v0, 0x44($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X44);
    // 0x8003EBDC: beql        $v0, $zero, L_8003EBE8
    if (ctx->r2 == 0) {
        // 0x8003EBE0: sw          $a0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r4;
            goto L_8003EBE8;
    }
    goto skip_2;
    // 0x8003EBE0: sw          $a0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r4;
    skip_2:
    // 0x8003EBE4: sw          $a0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r4;
L_8003EBE8:
    // 0x8003EBE8: lw          $v0, 0x44($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X44);
    // 0x8003EBEC: lw          $v1, 0x48($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X48);
    // 0x8003EBF0: lw          $v0, 0x44($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X44);
    // 0x8003EBF4: sw          $v0, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->r2;
    // 0x8003EBF8: sw          $a0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->r4;
L_8003EBFC:
    // 0x8003EBFC: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8003EC00: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8003EC04: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8003EC08: jr          $ra
    // 0x8003EC0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8003EC0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
