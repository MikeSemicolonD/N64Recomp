#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80054C54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054C54: addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
    // 0x80054C58: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80054C5C: addiu       $v0, $v0, 0x7C90
    ctx->r2 = ADD32(ctx->r2, 0X7C90);
    // 0x80054C60: addiu       $v0, $v0, 0x46
    ctx->r2 = ADD32(ctx->r2, 0X46);
L_80054C64:
    // 0x80054C64: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x80054C68: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80054C6C: bgez        $v1, L_80054C64
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80054C70: addiu       $v0, $v0, -0xA
        ctx->r2 = ADD32(ctx->r2, -0XA);
            goto L_80054C64;
    }
    // 0x80054C70: addiu       $v0, $v0, -0xA
    ctx->r2 = ADD32(ctx->r2, -0XA);
    // 0x80054C74: jr          $ra
    // 0x80054C78: nop

    return;
    // 0x80054C78: nop

;}
RECOMP_FUNC void func_80054C7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054C7C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80054C80: sdc1        $f24, 0x48($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X48, ctx->r29);
    // 0x80054C84: mtc1        $a3, $f24
    ctx->f24.u32l = ctx->r7;
    // 0x80054C88: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x80054C8C: lhu         $s6, 0x62($sp)
    ctx->r22 = MEM_HU(ctx->r29, 0X62);
    // 0x80054C90: sdc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X40, ctx->r29);
    // 0x80054C94: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80054C98: lwc1        $f22, -0x52F4($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X52F4);
    // 0x80054C9C: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x80054CA0: addu        $s7, $a0, $zero
    ctx->r23 = ADD32(ctx->r4, 0);
    // 0x80054CA4: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80054CA8: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x80054CAC: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x80054CB0: addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // 0x80054CB4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80054CB8: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80054CBC: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x80054CC0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80054CC4: lwc1        $f20, -0x52F0($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X52F0);
    // 0x80054CC8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80054CCC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80054CD0: addiu       $s1, $v0, 0x7C90
    ctx->r17 = ADD32(ctx->r2, 0X7C90);
    // 0x80054CD4: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80054CD8: ori         $s3, $zero, 0xFFFF
    ctx->r19 = 0 | 0XFFFF;
    // 0x80054CDC: sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // 0x80054CE0: lui         $fp, 0x8000
    ctx->r30 = S32(0X8000 << 16);
    // 0x80054CE4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80054CE8: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    // 0x80054CEC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
L_80054CF0:
    // 0x80054CF0: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x80054CF4: bnel        $v0, $zero, L_80054D78
    if (ctx->r2 != 0) {
        // 0x80054CF8: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80054D78;
    }
    goto skip_0;
    // 0x80054CF8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x80054CFC: jal         0x80022D68
    // 0x80054D00: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    func_80022D68(rdram, ctx);
        goto after_0;
    // 0x80054D00: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    after_0:
    // 0x80054D04: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x80054D08: beql        $a0, $s3, L_80054D78
    if (ctx->r4 == ctx->r19) {
        // 0x80054D0C: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80054D78;
    }
    goto skip_1;
    // 0x80054D0C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_1:
    // 0x80054D10: jal         0x80023364
    // 0x80054D14: nop

    func_80023364(rdram, ctx);
        goto after_1;
    // 0x80054D14: nop

    after_1:
    // 0x80054D18: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80054D1C: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    // 0x80054D20: beql        $v0, $s3, L_80054D78
    if (ctx->r2 == ctx->r19) {
        // 0x80054D24: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80054D78;
    }
    goto skip_2;
    // 0x80054D24: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_2:
    // 0x80054D28: mul.s       $f0, $f24, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f24.fl, ctx->f22.fl);
    // 0x80054D2C: sh          $v1, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r3;
    // 0x80054D30: sb          $s4, -0x2($s0)
    MEM_B(-0X2, ctx->r16) = ctx->r20;
    // 0x80054D34: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
    // 0x80054D38: nop

    // 0x80054D3C: bc1t        L_80054D54
    if (c1cs) {
        // 0x80054D40: sb          $s5, -0x1($s0)
        MEM_B(-0X1, ctx->r16) = ctx->r21;
            goto L_80054D54;
    }
    // 0x80054D40: sb          $s5, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r21;
    // 0x80054D44: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80054D48: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80054D4C: j           L_80054D68
    // 0x80054D50: andi        $v0, $s2, 0xFFFF
    ctx->r2 = ctx->r18 & 0XFFFF;
        goto L_80054D68;
    // 0x80054D50: andi        $v0, $s2, 0xFFFF
    ctx->r2 = ctx->r18 & 0XFFFF;
L_80054D54:
    // 0x80054D54: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x80054D58: trunc.w.s   $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80054D5C: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80054D60: or          $a3, $a3, $fp
    ctx->r7 = ctx->r7 | ctx->r30;
    // 0x80054D64: andi        $v0, $s2, 0xFFFF
    ctx->r2 = ctx->r18 & 0XFFFF;
L_80054D68:
    // 0x80054D68: sh          $a3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r7;
    // 0x80054D6C: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x80054D70: j           L_80054D8C
    // 0x80054D74: sh          $s6, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r22;
        goto L_80054D8C;
    // 0x80054D74: sh          $s6, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r22;
L_80054D78:
    // 0x80054D78: addiu       $s0, $s0, 0xA
    ctx->r16 = ADD32(ctx->r16, 0XA);
    // 0x80054D7C: slti        $v0, $s2, 0x8
    ctx->r2 = SIGNED(ctx->r18) < 0X8 ? 1 : 0;
    // 0x80054D80: bne         $v0, $zero, L_80054CF0
    if (ctx->r2 != 0) {
        // 0x80054D84: addiu       $s1, $s1, 0xA
        ctx->r17 = ADD32(ctx->r17, 0XA);
            goto L_80054CF0;
    }
    // 0x80054D84: addiu       $s1, $s1, 0xA
    ctx->r17 = ADD32(ctx->r17, 0XA);
    // 0x80054D88: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_80054D8C:
    // 0x80054D8C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80054D90: lw          $fp, 0x30($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X30);
    // 0x80054D94: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x80054D98: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x80054D9C: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x80054DA0: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80054DA4: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80054DA8: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80054DAC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80054DB0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80054DB4: ldc1        $f24, 0x48($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X48);
    // 0x80054DB8: ldc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X40);
    // 0x80054DBC: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x80054DC0: jr          $ra
    // 0x80054DC4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80054DC4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80054DC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054DC8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80054DCC: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x80054DD0: mov.s       $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    ctx->f22.fl = ctx->f12.fl;
    // 0x80054DD4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80054DD8: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80054DDC: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80054DE0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80054DE4: lwc1        $f20, -0x52EC($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X52EC);
    // 0x80054DE8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80054DEC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80054DF0: addiu       $s1, $v0, 0x7C90
    ctx->r17 = ADD32(ctx->r2, 0X7C90);
    // 0x80054DF4: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80054DF8: lui         $s3, 0x8000
    ctx->r19 = S32(0X8000 << 16);
    // 0x80054DFC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80054E00: addiu       $s0, $s1, 0x8
    ctx->r16 = ADD32(ctx->r17, 0X8);
    // 0x80054E04: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
L_80054E08:
    // 0x80054E08: lhu         $v0, -0x4($s0)
    ctx->r2 = MEM_HU(ctx->r16, -0X4);
    // 0x80054E0C: beql        $v0, $zero, L_80054EB8
    if (ctx->r2 == 0) {
        // 0x80054E10: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80054EB8;
    }
    goto skip_0;
    // 0x80054E10: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x80054E14: lhu         $v0, -0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, -0X2);
    // 0x80054E18: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x80054E1C: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80054E20: mul.s       $f2, $f22, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x80054E24: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x80054E28: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80054E2C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80054E30: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80054E34: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
    // 0x80054E38: nop

    // 0x80054E3C: bc1tl       L_80054E54
    if (c1cs) {
        // 0x80054E40: sub.s       $f0, $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
            goto L_80054E54;
    }
    goto skip_1;
    // 0x80054E40: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    skip_1:
    // 0x80054E44: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80054E48: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80054E4C: j           L_80054E64
    // 0x80054E50: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
        goto L_80054E64;
    // 0x80054E50: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
L_80054E54:
    // 0x80054E54: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80054E58: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80054E5C: or          $v0, $v0, $s3
    ctx->r2 = ctx->r2 | ctx->r19;
    // 0x80054E60: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
L_80054E64:
    // 0x80054E64: andi        $v0, $v0, 0xFF00
    ctx->r2 = ctx->r2 & 0XFF00;
    // 0x80054E68: beql        $v0, $zero, L_80054EB8
    if (ctx->r2 == 0) {
        // 0x80054E6C: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80054EB8;
    }
    goto skip_2;
    // 0x80054E6C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_2:
L_80054E70:
    // 0x80054E70: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x80054E74: lhu         $v1, -0x4($s0)
    ctx->r3 = MEM_HU(ctx->r16, -0X4);
    // 0x80054E78: lbu         $a1, -0x6($s0)
    ctx->r5 = MEM_BU(ctx->r16, -0X6);
    // 0x80054E7C: lbu         $a2, -0x5($s0)
    ctx->r6 = MEM_BU(ctx->r16, -0X5);
    // 0x80054E80: addiu       $v0, $v0, -0x100
    ctx->r2 = ADD32(ctx->r2, -0X100);
    // 0x80054E84: andi        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 & 0X1;
    // 0x80054E88: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x80054E8C: lhu         $a0, 0x0($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X0);
    // 0x80054E90: beq         $v1, $zero, L_80054E9C
    if (ctx->r3 == 0) {
        // 0x80054E94: addiu       $a3, $zero, -0x1
        ctx->r7 = ADD32(0, -0X1);
            goto L_80054E9C;
    }
    // 0x80054E94: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x80054E98: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_80054E9C:
    // 0x80054E9C: jal         0x8002384C
    // 0x80054EA0: nop

    func_8002384C(rdram, ctx);
        goto after_0;
    // 0x80054EA0: nop

    after_0:
    // 0x80054EA4: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x80054EA8: andi        $v0, $v0, 0xFF00
    ctx->r2 = ctx->r2 & 0XFF00;
    // 0x80054EAC: bne         $v0, $zero, L_80054E70
    if (ctx->r2 != 0) {
        // 0x80054EB0: nop
    
            goto L_80054E70;
    }
    // 0x80054EB0: nop

    // 0x80054EB4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80054EB8:
    // 0x80054EB8: addiu       $s0, $s0, 0xA
    ctx->r16 = ADD32(ctx->r16, 0XA);
    // 0x80054EBC: slti        $v0, $s2, 0x8
    ctx->r2 = SIGNED(ctx->r18) < 0X8 ? 1 : 0;
    // 0x80054EC0: bne         $v0, $zero, L_80054E08
    if (ctx->r2 != 0) {
        // 0x80054EC4: addiu       $s1, $s1, 0xA
        ctx->r17 = ADD32(ctx->r17, 0XA);
            goto L_80054E08;
    }
    // 0x80054EC4: addiu       $s1, $s1, 0xA
    ctx->r17 = ADD32(ctx->r17, 0XA);
    // 0x80054EC8: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80054ECC: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80054ED0: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80054ED4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80054ED8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80054EDC: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x80054EE0: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x80054EE4: jr          $ra
    // 0x80054EE8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80054EE8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80054EF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80054EF0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80054EF4: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x80054EF8: addu        $s7, $a0, $zero
    ctx->r23 = ADD32(ctx->r4, 0);
    // 0x80054EFC: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x80054F00: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80054F04: lw          $a0, 0x7CFC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X7CFC);
    // 0x80054F08: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x80054F0C: lw          $fp, 0x78($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X78);
    // 0x80054F10: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80054F14: addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    // 0x80054F18: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80054F1C: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x80054F20: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x80054F24: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80054F28: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x80054F2C: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80054F30: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80054F34: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x80054F38: jal         0x80004D5C
    // 0x80054F3C: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    get_asset_size_extra(rdram, ctx);
        goto after_0;
    // 0x80054F3C: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    after_0:
    // 0x80054F40: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    // 0x80054F44: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x80054F48: jal         0x80001ACC
    // 0x80054F4C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    rs_malloc(rdram, ctx);
        goto after_1;
    // 0x80054F4C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_1:
    // 0x80054F50: addu        $s6, $v0, $zero
    ctx->r22 = ADD32(ctx->r2, 0);
    // 0x80054F54: bnel        $s6, $zero, L_80054F70
    if (ctx->r22 != 0) {
        // 0x80054F58: addu        $a1, $s7, $zero
        ctx->r5 = ADD32(ctx->r23, 0);
            goto L_80054F70;
    }
    goto skip_0;
    // 0x80054F58: addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    skip_0:
    // 0x80054F5C: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x80054F60: jal         0x80001ACC
    // 0x80054F64: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_2;
    // 0x80054F64: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_2:
    // 0x80054F68: addu        $s6, $v0, $zero
    ctx->r22 = ADD32(ctx->r2, 0);
    // 0x80054F6C: addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
L_80054F70:
    // 0x80054F70: addu        $s2, $s6, $zero
    ctx->r18 = ADD32(ctx->r22, 0);
    // 0x80054F74: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x80054F78: lw          $a0, 0x7CFC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X7CFC);
    // 0x80054F7C: jal         0x80005134
    // 0x80054F80: addu        $s5, $s3, $zero
    ctx->r21 = ADD32(ctx->r19, 0);
    get_asset_size_simple(rdram, ctx);
        goto after_3;
    // 0x80054F80: addu        $s5, $s3, $zero
    ctx->r21 = ADD32(ctx->r19, 0);
    after_3:
    // 0x80054F84: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    // 0x80054F88: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x80054F8C: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80054F90: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x80054F94: lw          $a2, 0x7CFC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X7CFC);
    // 0x80054F98: addu        $a3, $s7, $zero
    ctx->r7 = ADD32(ctx->r23, 0);
    // 0x80054F9C: jal         0x80004AAC
    // 0x80054FA0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80004AAC(rdram, ctx);
        goto after_4;
    // 0x80054FA0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x80054FA4: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x80054FA8: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80054FAC: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x80054FB0: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x80054FB4: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // 0x80054FB8: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x80054FBC: jal         0x80004E70
    // 0x80054FC0: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    func_80004E70(rdram, ctx);
        goto after_5;
    // 0x80054FC0: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    after_5:
    // 0x80054FC4: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x80054FC8: jal         0x80004C70
    // 0x80054FCC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_80004C70(rdram, ctx);
        goto after_6;
    // 0x80054FCC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_6:
    // 0x80054FD0: addiu       $a0, $s4, -0x10
    ctx->r4 = ADD32(ctx->r20, -0X10);
    // 0x80054FD4: beq         $a0, $zero, L_80055000
    if (ctx->r4 == 0) {
        // 0x80054FD8: nop
    
            goto L_80055000;
    }
    // 0x80054FD8: nop

    // 0x80054FDC: addiu       $v1, $zero, -0x4
    ctx->r3 = ADD32(0, -0X4);
L_80054FE0:
    // 0x80054FE0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80054FE4: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80054FE8: addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
    // 0x80054FEC: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80054FF0: addu        $s3, $s3, $v0
    ctx->r19 = ADD32(ctx->r19, ctx->r2);
    // 0x80054FF4: sltu        $v0, $s3, $a0
    ctx->r2 = ctx->r19 < ctx->r4 ? 1 : 0;
    // 0x80054FF8: bne         $v0, $zero, L_80054FE0
    if (ctx->r2 != 0) {
        // 0x80054FFC: addu        $s2, $s6, $s3
        ctx->r18 = ADD32(ctx->r22, ctx->r19);
            goto L_80054FE0;
    }
    // 0x80054FFC: addu        $s2, $s6, $s3
    ctx->r18 = ADD32(ctx->r22, ctx->r19);
L_80055000:
    // 0x80055000: lw          $s4, 0x70($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X70);
    // 0x80055004: bne         $s4, $zero, L_80055024
    if (ctx->r20 != 0) {
        // 0x80055008: addu        $s2, $s6, $zero
        ctx->r18 = ADD32(ctx->r22, 0);
            goto L_80055024;
    }
    // 0x80055008: addu        $s2, $s6, $zero
    ctx->r18 = ADD32(ctx->r22, 0);
    // 0x8005500C: addiu       $a0, $s5, 0x1
    ctx->r4 = ADD32(ctx->r21, 0X1);
    // 0x80055010: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    // 0x80055014: jal         0x80001ACC
    // 0x80055018: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_7;
    // 0x80055018: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_7:
    // 0x8005501C: addu        $s4, $v0, $zero
    ctx->r20 = ADD32(ctx->r2, 0);
    // 0x80055020: addu        $s2, $s6, $zero
    ctx->r18 = ADD32(ctx->r22, 0);
L_80055024:
    // 0x80055024: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x80055028: addu        $s0, $s3, $zero
    ctx->r16 = ADD32(ctx->r19, 0);
    // 0x8005502C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80055030: lwc1        $f0, -0x52D8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X52D8);
    // 0x80055034: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80055038: lwc1        $f2, -0x52D4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X52D4);
    // 0x8005503C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80055040: sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // 0x80055044: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80055048: sb          $v0, 0x28($sp)
    MEM_B(0X28, ctx->r29) = ctx->r2;
    // 0x8005504C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80055050: blez        $s5, L_80055184
    if (SIGNED(ctx->r21) <= 0) {
        // 0x80055054: swc1        $f2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
            goto L_80055184;
    }
    // 0x80055054: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    // 0x80055058: addiu       $s7, $sp, 0x2C
    ctx->r23 = ADD32(ctx->r29, 0X2C);
    // 0x8005505C: addu        $s1, $s4, $zero
    ctx->r17 = ADD32(ctx->r20, 0);
L_80055060:
    // 0x80055060: addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    // 0x80055064: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80055068: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8005506C: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
L_80055070:
    // 0x80055070: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80055074: beq         $v0, $zero, L_80055084
    if (ctx->r2 == 0) {
        // 0x80055078: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80055084;
    }
    // 0x80055078: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8005507C: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80055080: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80055084:
    // 0x80055084: slti        $v0, $a0, 0x8
    ctx->r2 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x80055088: bne         $v0, $zero, L_80055070
    if (ctx->r2 != 0) {
        // 0x8005508C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80055070;
    }
    // 0x8005508C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80055090: lw          $v0, 0x20($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X20);
    // 0x80055094: beq         $v0, $zero, L_800550A0
    if (ctx->r2 == 0) {
        // 0x80055098: addu        $v0, $v0, $a2
        ctx->r2 = ADD32(ctx->r2, ctx->r6);
            goto L_800550A0;
    }
    // 0x80055098: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8005509C: sw          $v0, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r2;
L_800550A0:
    // 0x800550A0: lw          $v0, 0x24($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X24);
    // 0x800550A4: beq         $v0, $zero, L_800550B0
    if (ctx->r2 == 0) {
        // 0x800550A8: addu        $v0, $v0, $a2
        ctx->r2 = ADD32(ctx->r2, ctx->r6);
            goto L_800550B0;
    }
    // 0x800550A8: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800550AC: sw          $v0, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r2;
L_800550B0:
    // 0x800550B0: beq         $fp, $zero, L_800550EC
    if (ctx->r30 == 0) {
        // 0x800550B4: nop
    
            goto L_800550EC;
    }
    // 0x800550B4: nop

    // 0x800550B8: div         $zero, $s0, $fp
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r30))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r30)));
    // 0x800550BC: bne         $fp, $zero, L_800550C8
    if (ctx->r30 != 0) {
        // 0x800550C0: nop
    
            goto L_800550C8;
    }
    // 0x800550C0: nop

    // 0x800550C4: break       7
    do_break(2147832004);
L_800550C8:
    // 0x800550C8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800550CC: bne         $fp, $at, L_800550E0
    if (ctx->r30 != ctx->r1) {
        // 0x800550D0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800550E0;
    }
    // 0x800550D0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800550D4: bne         $s0, $at, L_800550E0
    if (ctx->r16 != ctx->r1) {
        // 0x800550D8: nop
    
            goto L_800550E0;
    }
    // 0x800550D8: nop

    // 0x800550DC: break       6
    do_break(2147832028);
L_800550E0:
    // 0x800550E0: mfhi        $v1
    ctx->r3 = hi;
    // 0x800550E4: bne         $v1, $zero, L_8005514C
    if (ctx->r3 != 0) {
        // 0x800550E8: subu        $v0, $s0, $v1
        ctx->r2 = SUB32(ctx->r16, ctx->r3);
            goto L_8005514C;
    }
    // 0x800550E8: subu        $v0, $s0, $v1
    ctx->r2 = SUB32(ctx->r16, ctx->r3);
L_800550EC:
    // 0x800550EC: lhu         $v0, 0x32($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X32);
    // 0x800550F0: lw          $t0, 0x74($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X74);
    // 0x800550F4: or          $v0, $v0, $t0
    ctx->r2 = ctx->r2 | ctx->r8;
    // 0x800550F8: sh          $v0, 0x32($s2)
    MEM_H(0X32, ctx->r18) = ctx->r2;
    // 0x800550FC: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x80055100: beq         $t0, $zero, L_80055124
    if (ctx->r8 == 0) {
        // 0x80055104: addu        $a0, $s7, $zero
        ctx->r4 = ADD32(ctx->r23, 0);
            goto L_80055124;
    }
    // 0x80055104: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // 0x80055108: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8005510C: addiu       $a1, $a1, -0x52E0
    ctx->r5 = ADD32(ctx->r5, -0X52E0);
    // 0x80055110: addu        $a2, $t0, $zero
    ctx->r6 = ADD32(ctx->r8, 0);
    // 0x80055114: jal         0x80033CC4
    // 0x80055118: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    sprintf_recomp(rdram, ctx);
        goto after_8;
    // 0x80055118: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_8:
    // 0x8005511C: j           L_80055134
    // 0x80055120: sw          $s7, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r23;
        goto L_80055134;
    // 0x80055120: sw          $s7, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r23;
L_80055124:
    // 0x80055124: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80055128: lw          $a1, 0x28($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X28);
    // 0x8005512C: jal         0x80007640
    // 0x80055130: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    rs_strncpy(rdram, ctx);
        goto after_9;
    // 0x80055130: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_9:
L_80055134:
    // 0x80055134: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80055138: addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    // 0x8005513C: jal         0x80022B90
    // 0x80055140: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_80022B90(rdram, ctx);
        goto after_10;
    // 0x80055140: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_10:
    // 0x80055144: j           L_8005515C
    // 0x80055148: sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
        goto L_8005515C;
    // 0x80055148: sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
L_8005514C:
    // 0x8005514C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80055150: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x80055154: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80055158: sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
L_8005515C:
    // 0x8005515C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x80055160: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80055164: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80055168: addiu       $v1, $zero, -0x4
    ctx->r3 = ADD32(0, -0X4);
    // 0x8005516C: addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
    // 0x80055170: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80055174: addu        $s3, $s3, $v0
    ctx->r19 = ADD32(ctx->r19, ctx->r2);
    // 0x80055178: slt         $v0, $s0, $s5
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x8005517C: bne         $v0, $zero, L_80055060
    if (ctx->r2 != 0) {
        // 0x80055180: addu        $s2, $s6, $s3
        ctx->r18 = ADD32(ctx->r22, ctx->r19);
            goto L_80055060;
    }
    // 0x80055180: addu        $s2, $s6, $s3
    ctx->r18 = ADD32(ctx->r22, ctx->r19);
L_80055184:
    // 0x80055184: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x80055188: bne         $t0, $zero, L_8005519C
    if (ctx->r8 != 0) {
        // 0x8005518C: sll         $v0, $s0, 1
        ctx->r2 = S32(ctx->r16 << 1);
            goto L_8005519C;
    }
    // 0x8005518C: sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16 << 1);
    // 0x80055190: addu        $v0, $v0, $s4
    ctx->r2 = ADD32(ctx->r2, ctx->r20);
    // 0x80055194: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // 0x80055198: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
L_8005519C:
    // 0x8005519C: jal         0x80001C98
    // 0x800551A0: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    rs_free(rdram, ctx);
        goto after_11;
    // 0x800551A0: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    after_11:
    // 0x800551A4: addu        $v0, $s4, $zero
    ctx->r2 = ADD32(ctx->r20, 0);
    // 0x800551A8: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x800551AC: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x800551B0: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x800551B4: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x800551B8: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x800551BC: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x800551C0: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800551C4: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x800551C8: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x800551CC: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x800551D0: jr          $ra
    // 0x800551D4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800551D4: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_800551D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800551D8: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800551DC: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x800551E0: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x800551E4: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x800551E8: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800551EC: lw          $a0, 0x7CFC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X7CFC);
    // 0x800551F0: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x800551F4: addu        $fp, $a1, $zero
    ctx->r30 = ADD32(ctx->r5, 0);
    // 0x800551F8: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x800551FC: addu        $s5, $a3, $zero
    ctx->r21 = ADD32(ctx->r7, 0);
    // 0x80055200: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x80055204: lw          $s7, 0x78($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X78);
    // 0x80055208: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8005520C: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x80055210: addu        $s6, $a2, $zero
    ctx->r22 = ADD32(ctx->r6, 0);
    // 0x80055214: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80055218: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x8005521C: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x80055220: jal         0x80004D5C
    // 0x80055224: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    get_asset_size_extra(rdram, ctx);
        goto after_0;
    // 0x80055224: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    after_0:
    // 0x80055228: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8005522C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80055230: jal         0x80001ACC
    // 0x80055234: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_1;
    // 0x80055234: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // 0x80055238: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005523C: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80055240: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // 0x80055244: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x80055248: lw          $a2, 0x7CFC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X7CFC);
    // 0x8005524C: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x80055250: jal         0x80004AAC
    // 0x80055254: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80004AAC(rdram, ctx);
        goto after_2;
    // 0x80055254: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x80055258: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005525C: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80055260: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x80055264: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x80055268: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x8005526C: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80055270: jal         0x80004E70
    // 0x80055274: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    func_80004E70(rdram, ctx);
        goto after_3;
    // 0x80055274: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    after_3:
    // 0x80055278: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x8005527C: jal         0x80004C70
    // 0x80055280: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_80004C70(rdram, ctx);
        goto after_4;
    // 0x80055280: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_4:
    // 0x80055284: addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    // 0x80055288: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x8005528C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80055290: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
L_80055294:
    // 0x80055294: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80055298: beq         $v0, $zero, L_800552A8
    if (ctx->r2 == 0) {
        // 0x8005529C: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800552A8;
    }
    // 0x8005529C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800552A0: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800552A4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_800552A8:
    // 0x800552A8: slti        $v0, $a0, 0x8
    ctx->r2 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800552AC: bne         $v0, $zero, L_80055294
    if (ctx->r2 != 0) {
        // 0x800552B0: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80055294;
    }
    // 0x800552B0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800552B4: lw          $v0, 0x20($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X20);
    // 0x800552B8: beq         $v0, $zero, L_800552C4
    if (ctx->r2 == 0) {
        // 0x800552BC: addu        $v0, $v0, $a2
        ctx->r2 = ADD32(ctx->r2, ctx->r6);
            goto L_800552C4;
    }
    // 0x800552BC: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800552C0: sw          $v0, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r2;
L_800552C4:
    // 0x800552C4: lw          $v0, 0x24($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X24);
    // 0x800552C8: beq         $v0, $zero, L_800552D4
    if (ctx->r2 == 0) {
        // 0x800552CC: addu        $v0, $v0, $a2
        ctx->r2 = ADD32(ctx->r2, ctx->r6);
            goto L_800552D4;
    }
    // 0x800552CC: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800552D0: sw          $v0, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r2;
L_800552D4:
    // 0x800552D4: lh          $v1, 0x2E($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X2E);
    // 0x800552D8: andi        $v0, $s6, 0xFFFF
    ctx->r2 = ctx->r22 & 0XFFFF;
    // 0x800552DC: div         $zero, $v1, $v0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r2)));
    // 0x800552E0: bne         $v0, $zero, L_800552EC
    if (ctx->r2 != 0) {
        // 0x800552E4: nop
    
            goto L_800552EC;
    }
    // 0x800552E4: nop

    // 0x800552E8: break       7
    do_break(2147832552);
L_800552EC:
    // 0x800552EC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800552F0: bne         $v0, $at, L_80055304
    if (ctx->r2 != ctx->r1) {
        // 0x800552F4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80055304;
    }
    // 0x800552F4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800552F8: bne         $v1, $at, L_80055304
    if (ctx->r3 != ctx->r1) {
        // 0x800552FC: nop
    
            goto L_80055304;
    }
    // 0x800552FC: nop

    // 0x80055300: break       6
    do_break(2147832576);
L_80055304:
    // 0x80055304: mflo        $s4
    ctx->r20 = lo;
    // 0x80055308: slt         $v0, $s7, $s4
    ctx->r2 = SIGNED(ctx->r23) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8005530C: bnel        $v0, $zero, L_80055314
    if (ctx->r2 != 0) {
        // 0x80055310: addu        $s4, $s7, $zero
        ctx->r20 = ADD32(ctx->r23, 0);
            goto L_80055314;
    }
    goto skip_0;
    // 0x80055310: addu        $s4, $s7, $zero
    ctx->r20 = ADD32(ctx->r23, 0);
    skip_0:
L_80055314:
    // 0x80055314: lhu         $v0, 0x32($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X32);
    // 0x80055318: andi        $v1, $v0, 0xF
    ctx->r3 = ctx->r2 & 0XF;
    // 0x8005531C: sltiu       $v0, $v1, 0x6
    ctx->r2 = ctx->r3 < 0X6 ? 1 : 0;
    // 0x80055320: beq         $v0, $zero, L_800553A8
    if (ctx->r2 == 0) {
        // 0x80055324: sh          $s6, 0x2E($s2)
        MEM_H(0X2E, ctx->r18) = ctx->r22;
            goto L_800553A8;
    }
    // 0x80055324: sh          $s6, 0x2E($s2)
    MEM_H(0X2E, ctx->r18) = ctx->r22;
    // 0x80055328: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8005532C: addiu       $v0, $v0, -0x52C8
    ctx->r2 = ADD32(ctx->r2, -0X52C8);
    // 0x80055330: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80055334: addu        $v1, $v1, $v0
    gpr jr_addend_8005533C = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80055338: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x8005533C: jr          $v0
    // 0x80055340: nop

    switch (jr_addend_8005533C >> 2) {
        case 0: goto L_80055398; break;
        case 1: goto L_8005538C; break;
        case 2: goto L_80055344; break;
        case 3: goto L_80055350; break;
        case 4: goto L_8005537C; break;
        case 5: goto L_8005538C; break;
        default: switch_error(__func__, 0x8005533C, 0x8003AD38);
    }
    // 0x80055340: nop

L_80055344:
    // 0x80055344: lh          $v0, 0x2C($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X2C);
    // 0x80055348: j           L_800553AC
    // 0x8005534C: sll         $s1, $v0, 1
    ctx->r17 = S32(ctx->r2 << 1);
        goto L_800553AC;
    // 0x8005534C: sll         $s1, $v0, 1
    ctx->r17 = S32(ctx->r2 << 1);
L_80055350:
    // 0x80055350: lhu         $v0, 0x32($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X32);
    // 0x80055354: andi        $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 & 0X8000;
    // 0x80055358: beq         $v0, $zero, L_8005536C
    if (ctx->r2 == 0) {
        // 0x8005535C: nop
    
            goto L_8005536C;
    }
    // 0x8005535C: nop

    // 0x80055360: lh          $v0, 0x2C($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X2C);
    // 0x80055364: j           L_800553AC
    // 0x80055368: sll         $s1, $v0, 2
    ctx->r17 = S32(ctx->r2 << 2);
        goto L_800553AC;
    // 0x80055368: sll         $s1, $v0, 2
    ctx->r17 = S32(ctx->r2 << 2);
L_8005536C:
    // 0x8005536C: lh          $v1, 0x2C($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X2C);
    // 0x80055370: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80055374: j           L_800553AC
    // 0x80055378: addu        $s1, $v0, $v1
    ctx->r17 = ADD32(ctx->r2, ctx->r3);
        goto L_800553AC;
    // 0x80055378: addu        $s1, $v0, $v1
    ctx->r17 = ADD32(ctx->r2, ctx->r3);
L_8005537C:
    // 0x8005537C: lhu         $v0, 0x32($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X32);
    // 0x80055380: andi        $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 & 0X8000;
    // 0x80055384: beq         $v0, $zero, L_80055398
    if (ctx->r2 == 0) {
        // 0x80055388: nop
    
            goto L_80055398;
    }
    // 0x80055388: nop

L_8005538C:
    // 0x8005538C: lh          $s1, 0x2C($s2)
    ctx->r17 = MEM_H(ctx->r18, 0X2C);
    // 0x80055390: j           L_800553B0
    // 0x80055394: andi        $v1, $s6, 0xFFFF
    ctx->r3 = ctx->r22 & 0XFFFF;
        goto L_800553B0;
    // 0x80055394: andi        $v1, $s6, 0xFFFF
    ctx->r3 = ctx->r22 & 0XFFFF;
L_80055398:
    // 0x80055398: lh          $v0, 0x2C($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X2C);
    // 0x8005539C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800553A0: j           L_800553AC
    // 0x800553A4: sra         $s1, $v0, 1
    ctx->r17 = S32(SIGNED(ctx->r2) >> 1);
        goto L_800553AC;
    // 0x800553A4: sra         $s1, $v0, 1
    ctx->r17 = S32(SIGNED(ctx->r2) >> 1);
L_800553A8:
    // 0x800553A8: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_800553AC:
    // 0x800553AC: andi        $v1, $s6, 0xFFFF
    ctx->r3 = ctx->r22 & 0XFFFF;
L_800553B0:
    // 0x800553B0: mult        $s1, $v1
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800553B4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800553B8: lwc1        $f0, -0x52B0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X52B0);
    // 0x800553BC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800553C0: lwc1        $f2, -0x52AC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X52AC);
    // 0x800553C4: lw          $v1, 0x7C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X7C);
    // 0x800553C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800553CC: sh          $v0, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r2;
    // 0x800553D0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800553D4: sb          $v0, 0x28($sp)
    MEM_B(0X28, ctx->r29) = ctx->r2;
    // 0x800553D8: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800553DC: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    // 0x800553E0: lhu         $v0, 0x32($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X32);
    // 0x800553E4: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800553E8: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800553EC: mflo        $s1
    ctx->r17 = lo;
    // 0x800553F0: blez        $s4, L_80055450
    if (SIGNED(ctx->r20) <= 0) {
        // 0x800553F4: sh          $v0, 0x32($s2)
        MEM_H(0X32, ctx->r18) = ctx->r2;
            goto L_80055450;
    }
    // 0x800553F4: sh          $v0, 0x32($s2)
    MEM_H(0X32, ctx->r18) = ctx->r2;
    // 0x800553F8: addiu       $s3, $sp, 0x2C
    ctx->r19 = ADD32(ctx->r29, 0X2C);
    // 0x800553FC: lui         $s6, 0x8004
    ctx->r22 = S32(0X8004 << 16);
L_80055400:
    // 0x80055400: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80055404: addiu       $a1, $s6, -0x52D0
    ctx->r5 = ADD32(ctx->r22, -0X52D0);
    // 0x80055408: addu        $a2, $fp, $zero
    ctx->r6 = ADD32(ctx->r30, 0);
    // 0x8005540C: jal         0x80033CC4
    // 0x80055410: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    sprintf_recomp(rdram, ctx);
        goto after_5;
    // 0x80055410: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_5:
    // 0x80055414: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x80055418: lw          $a0, 0x28($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X28);
    // 0x8005541C: jal         0x8000761C
    // 0x80055420: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    rs_strcpy(rdram, ctx);
        goto after_6;
    // 0x80055420: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    after_6:
    // 0x80055424: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80055428: addiu       $a1, $s2, 0x4
    ctx->r5 = ADD32(ctx->r18, 0X4);
    // 0x8005542C: jal         0x80022B90
    // 0x80055430: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_80022B90(rdram, ctx);
        goto after_7;
    // 0x80055430: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_7:
    // 0x80055434: sh          $v0, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r2;
    // 0x80055438: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x8005543C: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x80055440: sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
    // 0x80055444: slt         $v0, $s0, $s4
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80055448: bne         $v0, $zero, L_80055400
    if (ctx->r2 != 0) {
        // 0x8005544C: addiu       $s5, $s5, 0x2
        ctx->r21 = ADD32(ctx->r21, 0X2);
            goto L_80055400;
    }
    // 0x8005544C: addiu       $s5, $s5, 0x2
    ctx->r21 = ADD32(ctx->r21, 0X2);
L_80055450:
    // 0x80055450: jal         0x80001C98
    // 0x80055454: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    rs_free(rdram, ctx);
        goto after_8;
    // 0x80055454: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_8:
    // 0x80055458: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x8005545C: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x80055460: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x80055464: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x80055468: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x8005546C: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x80055470: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x80055474: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x80055478: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x8005547C: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80055480: jr          $ra
    // 0x80055484: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80055484: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void full_header_image_offset_convert(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055488: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8005548C: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_80055490:
    // 0x80055490: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80055494: beq         $v0, $zero, L_800554A4
    if (ctx->r2 == 0) {
        // 0x80055498: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_800554A4;
    }
    // 0x80055498: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8005549C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800554A0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_800554A4:
    // 0x800554A4: slti        $v0, $a2, 0x8
    ctx->r2 = SIGNED(ctx->r6) < 0X8 ? 1 : 0;
    // 0x800554A8: bne         $v0, $zero, L_80055490
    if (ctx->r2 != 0) {
        // 0x800554AC: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80055490;
    }
    // 0x800554AC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800554B0: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
    // 0x800554B4: beq         $v0, $zero, L_800554C0
    if (ctx->r2 == 0) {
        // 0x800554B8: addu        $v0, $v0, $a1
        ctx->r2 = ADD32(ctx->r2, ctx->r5);
            goto L_800554C0;
    }
    // 0x800554B8: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800554BC: sw          $v0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r2;
L_800554C0:
    // 0x800554C0: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x800554C4: beq         $v0, $zero, L_800554D0
    if (ctx->r2 == 0) {
        // 0x800554C8: addu        $v0, $v0, $a1
        ctx->r2 = ADD32(ctx->r2, ctx->r5);
            goto L_800554D0;
    }
    // 0x800554C8: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800554CC: sw          $v0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r2;
L_800554D0:
    // 0x800554D0: jr          $ra
    // 0x800554D4: nop

    return;
    // 0x800554D4: nop

;}
RECOMP_FUNC void func_800554D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800554D8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800554DC: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x800554E0: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x800554E4: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x800554E8: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x800554EC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800554F0: jal         0x8006488C
    // 0x800554F4: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    load_asset(rdram, ctx);
        goto after_0;
    // 0x800554F4: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    after_0:
    // 0x800554F8: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x800554FC: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x80055500: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80055504: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80055508: addu        $v1, $a1, $zero
    ctx->r3 = ADD32(ctx->r5, 0);
L_8005550C:
    // 0x8005550C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80055510: beq         $v0, $zero, L_80055520
    if (ctx->r2 == 0) {
        // 0x80055514: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80055520;
    }
    // 0x80055514: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80055518: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8005551C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_80055520:
    // 0x80055520: slti        $v0, $a0, 0x8
    ctx->r2 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x80055524: bne         $v0, $zero, L_8005550C
    if (ctx->r2 != 0) {
        // 0x80055528: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8005550C;
    }
    // 0x80055528: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8005552C: lw          $v0, 0x20($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X20);
    // 0x80055530: beq         $v0, $zero, L_8005553C
    if (ctx->r2 == 0) {
        // 0x80055534: addu        $v0, $v0, $a2
        ctx->r2 = ADD32(ctx->r2, ctx->r6);
            goto L_8005553C;
    }
    // 0x80055534: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80055538: sw          $v0, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r2;
L_8005553C:
    // 0x8005553C: lw          $v0, 0x24($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X24);
    // 0x80055540: beq         $v0, $zero, L_8005554C
    if (ctx->r2 == 0) {
        // 0x80055544: addu        $v0, $v0, $a2
        ctx->r2 = ADD32(ctx->r2, ctx->r6);
            goto L_8005554C;
    }
    // 0x80055544: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80055548: sw          $v0, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r2;
L_8005554C:
    // 0x8005554C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80055550: lwc1        $f0, -0x52A8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X52A8);
    // 0x80055554: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80055558: lwc1        $f2, -0x52A4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X52A4);
    // 0x8005555C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80055560: sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // 0x80055564: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80055568: sb          $v0, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r2;
    // 0x8005556C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80055570: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x80055574: lhu         $v0, 0x32($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X32);
    // 0x80055578: or          $v0, $v0, $s0
    ctx->r2 = ctx->r2 | ctx->r16;
    // 0x8005557C: beq         $s2, $zero, L_800555A0
    if (ctx->r18 == 0) {
        // 0x80055580: sh          $v0, 0x32($s1)
        MEM_H(0X32, ctx->r17) = ctx->r2;
            goto L_800555A0;
    }
    // 0x80055580: sh          $v0, 0x32($s1)
    MEM_H(0X32, ctx->r17) = ctx->r2;
    // 0x80055584: addiu       $s0, $sp, 0x24
    ctx->r16 = ADD32(ctx->r29, 0X24);
    // 0x80055588: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8005558C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80055590: jal         0x80007640
    // 0x80055594: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    rs_strncpy(rdram, ctx);
        goto after_1;
    // 0x80055594: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_1:
    // 0x80055598: j           L_800555B0
    // 0x8005559C: sw          $s0, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r16;
        goto L_800555B0;
    // 0x8005559C: sw          $s0, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r16;
L_800555A0:
    // 0x800555A0: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x800555A4: lw          $a1, 0x28($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X28);
    // 0x800555A8: jal         0x80007640
    // 0x800555AC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    rs_strncpy(rdram, ctx);
        goto after_2;
    // 0x800555AC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_2:
L_800555B0:
    // 0x800555B0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800555B4: addiu       $a1, $s1, 0x4
    ctx->r5 = ADD32(ctx->r17, 0X4);
    // 0x800555B8: jal         0x80022B90
    // 0x800555BC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_80022B90(rdram, ctx);
        goto after_3;
    // 0x800555BC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_3:
    // 0x800555C0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800555C4: jal         0x80001C98
    // 0x800555C8: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    rs_free(rdram, ctx);
        goto after_4;
    // 0x800555C8: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_4:
    // 0x800555CC: andi        $v0, $s0, 0xFFFF
    ctx->r2 = ctx->r16 & 0XFFFF;
    // 0x800555D0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800555D4: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x800555D8: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x800555DC: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800555E0: jr          $ra
    // 0x800555E4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800555E4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void fake_func_800555E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_800555F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800555F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800555F4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800555F8: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800555FC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80055600: addiu       $v0, $v0, -0x7FF4
    ctx->r2 = ADD32(ctx->r2, -0X7FF4);
    // 0x80055604: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80055608: addiu       $s0, $v0, -0x254
    ctx->r16 = ADD32(ctx->r2, -0X254);
    // 0x8005560C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80055610: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80055614: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
L_80055618:
    // 0x80055618: jal         0x8001CA50
    // 0x8005561C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA50(rdram, ctx);
        goto after_0;
    // 0x8005561C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_0:
    // 0x80055620: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x80055624: sw          $zero, 0x298($s0)
    MEM_W(0X298, ctx->r16) = 0;
    // 0x80055628: sw          $zero, 0x29C($s0)
    MEM_W(0X29C, ctx->r16) = 0;
    // 0x8005562C: addiu       $s0, $s0, 0x2A0
    ctx->r16 = ADD32(ctx->r16, 0X2A0);
    // 0x80055630: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80055634: blez        $s2, L_80055618
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80055638: addiu       $s1, $s1, 0x2A0
        ctx->r17 = ADD32(ctx->r17, 0X2A0);
            goto L_80055618;
    }
    // 0x80055638: addiu       $s1, $s1, 0x2A0
    ctx->r17 = ADD32(ctx->r17, 0X2A0);
    // 0x8005563C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80055640: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80055644: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80055648: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8005564C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80055650: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80055654: sb          $v0, 0x7DB8($v1)
    MEM_B(0X7DB8, ctx->r3) = ctx->r2;
    // 0x80055658: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8005565C: sb          $zero, 0x7CF4($v0)
    MEM_B(0X7CF4, ctx->r2) = 0;
    // 0x80055660: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80055664: sb          $zero, -0x7770($v0)
    MEM_B(-0X7770, ctx->r2) = 0;
    // 0x80055668: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005566C: sb          $zero, -0x76DB($v0)
    MEM_B(-0X76DB, ctx->r2) = 0;
    // 0x80055670: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80055674: sb          $zero, -0x77C8($v0)
    MEM_B(-0X77C8, ctx->r2) = 0;
    // 0x80055678: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005567C: sb          $zero, -0x77C7($v0)
    MEM_B(-0X77C7, ctx->r2) = 0;
    // 0x80055680: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80055684: sb          $zero, -0x76D9($v0)
    MEM_B(-0X76D9, ctx->r2) = 0;
    // 0x80055688: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005568C: sb          $zero, -0x76DC($v0)
    MEM_B(-0X76DC, ctx->r2) = 0;
    // 0x80055690: jr          $ra
    // 0x80055694: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80055694: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void fake_func_80055698(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void loadTxtFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800556A0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800556A4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800556A8: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x800556AC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800556B0: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x800556B4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800556B8: lui         $s5, 0x8014
    ctx->r21 = S32(0X8014 << 16);
    // 0x800556BC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800556C0: lw          $a0, -0x76E0($s5)
    ctx->r4 = MEM_W(ctx->r21, -0X76E0);
    // 0x800556C4: lw          $a2, 0x7CFC($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X7CFC);
    // 0x800556C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800556CC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800556D0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800556D4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800556D8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800556DC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800556E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800556E4: jal         0x80004AAC
    // 0x800556E8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_80004AAC(rdram, ctx);
        goto after_0;
    // 0x800556E8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_0:
    // 0x800556EC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800556F0: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x800556F4: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x800556F8: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x800556FC: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
    // 0x80055700: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80055704: lw          $a0, -0x76E0($s5)
    ctx->r4 = MEM_W(ctx->r21, -0X76E0);
    // 0x80055708: addiu       $s2, $s0, -0x71A0
    ctx->r18 = ADD32(ctx->r16, -0X71A0);
    // 0x8005570C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80055710: jal         0x80004E70
    // 0x80055714: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    func_80004E70(rdram, ctx);
        goto after_1;
    // 0x80055714: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    after_1:
    // 0x80055718: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8005571C: addiu       $s4, $v0, 0xB40
    ctx->r20 = ADD32(ctx->r2, 0XB40);
    // 0x80055720: lui         $s6, 0x8014
    ctx->r22 = S32(0X8014 << 16);
    // 0x80055724: lbu         $v0, 0x6($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X6);
    // 0x80055728: lhu         $v1, -0x71A0($s0)
    ctx->r3 = MEM_HU(ctx->r16, -0X71A0);
    // 0x8005572C: lhu         $a0, 0x2($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X2);
    // 0x80055730: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80055734: bne         $v0, $zero, L_80055740
    if (ctx->r2 != 0) {
        // 0x80055738: sh          $a0, -0x7184($s6)
        MEM_H(-0X7184, ctx->r22) = ctx->r4;
            goto L_80055740;
    }
    // 0x80055738: sh          $a0, -0x7184($s6)
    MEM_H(-0X7184, ctx->r22) = ctx->r4;
    // 0x8005573C: sb          $zero, 0x6($s4)
    MEM_B(0X6, ctx->r20) = 0;
L_80055740:
    // 0x80055740: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // 0x80055744: bne         $v0, $zero, L_800557F4
    if (ctx->r2 != 0) {
        // 0x80055748: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_800557F4;
    }
    // 0x80055748: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005574C: lbu         $v1, 0x6($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X6);
    // 0x80055750: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80055754: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80055758: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8005575C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80055760: addu        $v1, $v1, $s2
    ctx->r3 = ADD32(ctx->r3, ctx->r18);
    // 0x80055764: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x80055768: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8005576C: subu        $s1, $a0, $v0
    ctx->r17 = SUB32(ctx->r4, ctx->r2);
    // 0x80055770: jal         0x80001ACC
    // 0x80055774: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    rs_malloc(rdram, ctx);
        goto after_2;
    // 0x80055774: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_2:
    // 0x80055778: lw          $a0, -0x76E0($s5)
    ctx->r4 = MEM_W(ctx->r21, -0X76E0);
    // 0x8005577C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80055780: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x80055784: lbu         $v1, 0x6($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X6);
    // 0x80055788: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x8005578C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80055790: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80055794: addu        $v1, $v1, $s2
    ctx->r3 = ADD32(ctx->r3, ctx->r18);
    // 0x80055798: lw          $a3, 0x4($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X4);
    // 0x8005579C: lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // 0x800557A0: jal         0x80004E70
    // 0x800557A4: sw          $v0, -0x1360($s0)
    MEM_W(-0X1360, ctx->r16) = ctx->r2;
    func_80004E70(rdram, ctx);
        goto after_3;
    // 0x800557A4: sw          $v0, -0x1360($s0)
    MEM_W(-0X1360, ctx->r16) = ctx->r2;
    after_3:
    // 0x800557A8: lw          $a0, -0x76E0($s5)
    ctx->r4 = MEM_W(ctx->r21, -0X76E0);
    // 0x800557AC: jal         0x80004C70
    // 0x800557B0: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_80004C70(rdram, ctx);
        goto after_4;
    // 0x800557B0: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_4:
    // 0x800557B4: addiu       $a0, $zero, 0xF5
    ctx->r4 = ADD32(0, 0XF5);
    // 0x800557B8: lhu         $v0, -0x7184($s6)
    ctx->r2 = MEM_HU(ctx->r22, -0X7184);
    // 0x800557BC: lw          $v1, -0x1360($s0)
    ctx->r3 = MEM_W(ctx->r16, -0X1360);
    // 0x800557C0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800557C4: subu        $s1, $s1, $v0
    ctx->r17 = SUB32(ctx->r17, ctx->r2);
    // 0x800557C8: beq         $s1, $zero, L_80055854
    if (ctx->r17 == 0) {
        // 0x800557CC: addu        $v1, $v1, $v0
        ctx->r3 = ADD32(ctx->r3, ctx->r2);
            goto L_80055854;
    }
    // 0x800557CC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
L_800557D0:
    // 0x800557D0: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800557D4: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x800557D8: xor         $v0, $v0, $a0
    ctx->r2 = ctx->r2 ^ ctx->r4;
    // 0x800557DC: xor         $a0, $a0, $v0
    ctx->r4 = ctx->r4 ^ ctx->r2;
    // 0x800557E0: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x800557E4: bne         $s1, $zero, L_800557D0
    if (ctx->r17 != 0) {
        // 0x800557E8: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800557D0;
    }
    // 0x800557E8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800557EC: j           L_80055854
    // 0x800557F0: nop

        goto L_80055854;
    // 0x800557F0: nop

L_800557F4:
    // 0x800557F4: lhu         $v1, 0x2($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X2);
    // 0x800557F8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800557FC: sw          $s3, -0x135C($v0)
    MEM_W(-0X135C, ctx->r2) = ctx->r19;
    // 0x80055800: sll         $s1, $v1, 1
    ctx->r17 = S32(ctx->r3 << 1);
    // 0x80055804: jal         0x80001ACC
    // 0x80055808: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    rs_malloc(rdram, ctx);
        goto after_5;
    // 0x80055808: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_5:
    // 0x8005580C: lw          $a0, -0x76E0($s5)
    ctx->r4 = MEM_W(ctx->r21, -0X76E0);
    // 0x80055810: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80055814: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x80055818: lbu         $v1, 0x6($s4)
    ctx->r3 = MEM_BU(ctx->r20, 0X6);
    // 0x8005581C: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x80055820: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80055824: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80055828: addu        $v1, $v1, $s2
    ctx->r3 = ADD32(ctx->r3, ctx->r18);
    // 0x8005582C: lw          $a3, 0x4($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X4);
    // 0x80055830: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80055834: jal         0x80004E70
    // 0x80055838: sw          $v0, -0x1358($v1)
    MEM_W(-0X1358, ctx->r3) = ctx->r2;
    func_80004E70(rdram, ctx);
        goto after_6;
    // 0x80055838: sw          $v0, -0x1358($v1)
    MEM_W(-0X1358, ctx->r3) = ctx->r2;
    after_6:
    // 0x8005583C: lbu         $v0, 0x6($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X6);
    // 0x80055840: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80055844: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80055848: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x8005584C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80055850: sw          $v1, -0x7180($v0)
    MEM_W(-0X7180, ctx->r2) = ctx->r3;
L_80055854:
    // 0x80055854: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80055858: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8005585C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80055860: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80055864: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80055868: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8005586C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80055870: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80055874: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80055878: jr          $ra
    // 0x8005587C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8005587C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void loadGameOrFrontTxtFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055880: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80055884: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80055888: jal         0x800556A0
    // 0x8005588C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    loadTxtFile(rdram, ctx);
        goto after_0;
    // 0x8005588C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x80055890: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80055894: jr          $ra
    // 0x80055898: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80055898: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void getGameOrFrontText(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005589C: bltz        $a0, L_800558CC
    if (SIGNED(ctx->r4) < 0) {
        // 0x800558A0: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800558CC;
    }
    // 0x800558A0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800558A4: lhu         $v0, -0x7184($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X7184);
    // 0x800558A8: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800558AC: beq         $v0, $zero, L_800558CC
    if (ctx->r2 == 0) {
        // 0x800558B0: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_800558CC;
    }
    // 0x800558B0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800558B4: lw          $v1, -0x1360($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X1360);
    // 0x800558B8: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x800558BC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800558C0: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x800558C4: jr          $ra
    // 0x800558C8: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    return;
    // 0x800558C8: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
L_800558CC:
    // 0x800558CC: jr          $ra
    // 0x800558D0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x800558D0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void freeTxtFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800558D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800558D8: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800558DC: lui         $s3, 0x800A
    ctx->r19 = S32(0X800A << 16);
    // 0x800558E0: lw          $a0, -0x1360($s3)
    ctx->r4 = MEM_W(ctx->r19, -0X1360);
    // 0x800558E4: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800558E8: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800558EC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800558F0: beq         $a0, $zero, L_80055900
    if (ctx->r4 == 0) {
        // 0x800558F4: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_80055900;
    }
    // 0x800558F4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800558F8: jal         0x80001C98
    // 0x800558FC: nop

    rs_free(rdram, ctx);
        goto after_0;
    // 0x800558FC: nop

    after_0:
L_80055900:
    // 0x80055900: lui         $s2, 0x800A
    ctx->r18 = S32(0X800A << 16);
    // 0x80055904: lw          $a0, -0x1358($s2)
    ctx->r4 = MEM_W(ctx->r18, -0X1358);
    // 0x80055908: beq         $a0, $zero, L_80055918
    if (ctx->r4 == 0) {
        // 0x8005590C: lui         $s1, 0x800A
        ctx->r17 = S32(0X800A << 16);
            goto L_80055918;
    }
    // 0x8005590C: lui         $s1, 0x800A
    ctx->r17 = S32(0X800A << 16);
    // 0x80055910: jal         0x80001C98
    // 0x80055914: nop

    rs_free(rdram, ctx);
        goto after_1;
    // 0x80055914: nop

    after_1:
L_80055918:
    // 0x80055918: lw          $a1, -0x135C($s1)
    ctx->r5 = MEM_W(ctx->r17, -0X135C);
    // 0x8005591C: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x80055920: beq         $a1, $s0, L_80055938
    if (ctx->r5 == ctx->r16) {
        // 0x80055924: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_80055938;
    }
    // 0x80055924: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80055928: lw          $a0, -0x76E0($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X76E0);
    // 0x8005592C: jal         0x80004C70
    // 0x80055930: nop

    func_80004C70(rdram, ctx);
        goto after_2;
    // 0x80055930: nop

    after_2:
    // 0x80055934: sw          $s0, -0x135C($s1)
    MEM_W(-0X135C, ctx->r17) = ctx->r16;
L_80055938:
    // 0x80055938: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8005593C: sw          $zero, -0x1360($s3)
    MEM_W(-0X1360, ctx->r19) = 0;
    // 0x80055940: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80055944: sw          $zero, -0x1358($s2)
    MEM_W(-0X1358, ctx->r18) = 0;
    // 0x80055948: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8005594C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80055950: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80055954: jr          $ra
    // 0x80055958: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80055958: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void loadVoiceTxtFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005595C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80055960: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80055964: jal         0x800556A0
    // 0x80055968: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    loadTxtFile(rdram, ctx);
        goto after_0;
    // 0x80055968: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8005596C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80055970: jr          $ra
    // 0x80055974: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80055974: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void getVoiceText(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055978: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005597C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80055980: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    // 0x80055984: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80055988: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x8005598C: addiu       $s0, $s0, -0x7170
    ctx->r16 = ADD32(ctx->r16, -0X7170);
    // 0x80055990: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x80055994: lw          $v0, -0x1358($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1358);
    // 0x80055998: lw          $a2, -0x135C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X135C);
    // 0x8005599C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800559A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800559A4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800559A8: lhu         $v0, 0x2($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X2);
    // 0x800559AC: lhu         $t0, 0x0($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X0);
    // 0x800559B0: lw          $a0, -0x76E0($v1)
    ctx->r4 = MEM_W(ctx->r3, -0X76E0);
    // 0x800559B4: subu        $v0, $v0, $t0
    ctx->r2 = SUB32(ctx->r2, ctx->r8);
    // 0x800559B8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800559BC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800559C0: lw          $a3, -0x7180($v0)
    ctx->r7 = MEM_W(ctx->r2, -0X7180);
    // 0x800559C4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800559C8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800559CC: jal         0x80004E70
    // 0x800559D0: addu        $a3, $a3, $t0
    ctx->r7 = ADD32(ctx->r7, ctx->r8);
    func_80004E70(rdram, ctx);
        goto after_0;
    // 0x800559D0: addu        $a3, $a3, $t0
    ctx->r7 = ADD32(ctx->r7, ctx->r8);
    after_0:
    // 0x800559D4: addiu       $a1, $zero, 0xF5
    ctx->r5 = ADD32(0, 0XF5);
L_800559D8:
    // 0x800559D8: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800559DC: xor         $v1, $v0, $a1
    ctx->r3 = ctx->r2 ^ ctx->r5;
    // 0x800559E0: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x800559E4: addiu       $v0, $v1, -0x61
    ctx->r2 = ADD32(ctx->r3, -0X61);
    // 0x800559E8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800559EC: sltiu       $v0, $v0, 0x1A
    ctx->r2 = ctx->r2 < 0X1A ? 1 : 0;
    // 0x800559F0: beq         $v0, $zero, L_800559FC
    if (ctx->r2 == 0) {
        // 0x800559F4: xor         $a1, $a1, $v1
        ctx->r5 = ctx->r5 ^ ctx->r3;
            goto L_800559FC;
    }
    // 0x800559F4: xor         $a1, $a1, $v1
    ctx->r5 = ctx->r5 ^ ctx->r3;
    // 0x800559F8: addiu       $a0, $v1, -0x20
    ctx->r4 = ADD32(ctx->r3, -0X20);
L_800559FC:
    // 0x800559FC: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x80055A00: beq         $v0, $zero, L_80055A10
    if (ctx->r2 == 0) {
        // 0x80055A04: sb          $a0, 0x0($s0)
        MEM_B(0X0, ctx->r16) = ctx->r4;
            goto L_80055A10;
    }
    // 0x80055A04: sb          $a0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r4;
    // 0x80055A08: j           L_800559D8
    // 0x80055A0C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800559D8;
    // 0x80055A0C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80055A10:
    // 0x80055A10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80055A14: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80055A18: jr          $ra
    // 0x80055A1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80055A1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80055A20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055A20: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80055A24: jr          $ra
    // 0x80055A28: addiu       $v0, $v0, -0x7170
    ctx->r2 = ADD32(ctx->r2, -0X7170);
    return;
    // 0x80055A28: addiu       $v0, $v0, -0x7170
    ctx->r2 = ADD32(ctx->r2, -0X7170);
;}
RECOMP_FUNC void fake_func_80055A2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80055A30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055A30: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80055A34: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80055A38: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80055A3C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80055A40: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80055A44: addiu       $t3, $v0, -0x52A0
    ctx->r11 = ADD32(ctx->r2, -0X52A0);
    // 0x80055A48: lwl         $t0, 0x0($t3)
    ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r11, 0X0);
    // 0x80055A4C: lwr         $t0, 0x3($t3)
    ctx->r8 = do_lwr(rdram, ctx->r8, ctx->r11, 0X3);
    // 0x80055A50: swl         $t0, 0x18($sp)
    do_swl(rdram, 0X18, ctx->r29, ctx->r8);
    // 0x80055A54: swr         $t0, 0x1B($sp)
    do_swr(rdram, 0X1B, ctx->r29, ctx->r8);
    // 0x80055A58: jal         0x8005595C
    // 0x80055A5C: addiu       $a0, $a0, -0x529C
    ctx->r4 = ADD32(ctx->r4, -0X529C);
    loadVoiceTxtFile(rdram, ctx);
        goto after_0;
    // 0x80055A5C: addiu       $a0, $a0, -0x529C
    ctx->r4 = ADD32(ctx->r4, -0X529C);
    after_0:
    // 0x80055A60: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x80055A64: jal         0x80001ACC
    // 0x80055A68: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_1;
    // 0x80055A68: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // 0x80055A6C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80055A70: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x80055A74: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80055A78: sw          $v0, -0x6FF0($v1)
    MEM_W(-0X6FF0, ctx->r3) = ctx->r2;
    // 0x80055A7C: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // 0x80055A80: jal         0x800561AC
    // 0x80055A84: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    func_800561AC(rdram, ctx);
        goto after_2;
    // 0x80055A84: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    after_2:
    // 0x80055A88: jal         0x8006B3E0
    // 0x80055A8C: nop

    func_8006B3E0(rdram, ctx);
        goto after_3;
    // 0x80055A8C: nop

    after_3:
    // 0x80055A90: jal         0x8006B3D0
    // 0x80055A94: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    func_8006B3D0(rdram, ctx);
        goto after_4;
    // 0x80055A94: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_4:
    // 0x80055A98: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x80055A9C: mtc1        $s0, $f0
    ctx->f0.u32l = ctx->r16;
    // 0x80055AA0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80055AA4: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80055AA8: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x80055AAC: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80055AB0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80055AB4: lwc1        $f4, -0x528C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X528C);
    // 0x80055AB8: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80055ABC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80055AC0: nop

    // 0x80055AC4: bc1f        L_80055AD8
    if (!c1cs) {
        // 0x80055AC8: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_80055AD8;
    }
    // 0x80055AC8: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80055ACC: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x80055AD0: j           L_80055AF8
    // 0x80055AD4: sh          $v0, -0x6FEC($v1)
    MEM_H(-0X6FEC, ctx->r3) = ctx->r2;
        goto L_80055AF8;
    // 0x80055AD4: sh          $v0, -0x6FEC($v1)
    MEM_H(-0X6FEC, ctx->r3) = ctx->r2;
L_80055AD8:
    // 0x80055AD8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80055ADC: lw          $v0, 0xB50($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XB50);
    // 0x80055AE0: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80055AE4: beq         $v0, $zero, L_80055AF0
    if (ctx->r2 == 0) {
        // 0x80055AE8: addiu       $v1, $zero, 0x4
        ctx->r3 = ADD32(0, 0X4);
            goto L_80055AF0;
    }
    // 0x80055AE8: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x80055AEC: addiu       $v1, $zero, 0xB
    ctx->r3 = ADD32(0, 0XB);
L_80055AF0:
    // 0x80055AF0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80055AF4: sh          $v1, -0x6FEC($v0)
    MEM_H(-0X6FEC, ctx->r2) = ctx->r3;
L_80055AF8:
    // 0x80055AF8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80055AFC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80055B00: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80055B04: lhu         $a1, -0x6FEC($s0)
    ctx->r5 = MEM_HU(ctx->r16, -0X6FEC);
    // 0x80055B08: jal         0x800613C0
    // 0x80055B0C: addiu       $a3, $zero, 0x12C
    ctx->r7 = ADD32(0, 0X12C);
    func_800613C0(rdram, ctx);
        goto after_5;
    // 0x80055B0C: addiu       $a3, $zero, 0x12C
    ctx->r7 = ADD32(0, 0X12C);
    after_5:
    // 0x80055B10: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80055B14: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80055B18: jal         0x80063E2C
    // 0x80055B1C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    func_80063E2C(rdram, ctx);
        goto after_6;
    // 0x80055B1C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_6:
    // 0x80055B20: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80055B24: lhu         $a0, -0x6FEC($s0)
    ctx->r4 = MEM_HU(ctx->r16, -0X6FEC);
    // 0x80055B28: jal         0x80063E54
    // 0x80055B2C: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    func_80063E54(rdram, ctx);
        goto after_7;
    // 0x80055B2C: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_7:
    // 0x80055B30: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80055B34: addiu       $a1, $a1, -0x5290
    ctx->r5 = ADD32(ctx->r5, -0X5290);
    // 0x80055B38: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80055B3C: addiu       $a3, $zero, -0x64
    ctx->r7 = ADD32(0, -0X64);
    // 0x80055B40: lhu         $a0, -0x6FEC($s0)
    ctx->r4 = MEM_HU(ctx->r16, -0X6FEC);
    // 0x80055B44: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x80055B48: jal         0x80063CFC
    // 0x80055B4C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_80063CFC(rdram, ctx);
        goto after_8;
    // 0x80055B4C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_8:
    // 0x80055B50: lhu         $a0, -0x6FEC($s0)
    ctx->r4 = MEM_HU(ctx->r16, -0X6FEC);
    // 0x80055B54: jal         0x80063C3C
    // 0x80055B58: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_80063C3C(rdram, ctx);
        goto after_9;
    // 0x80055B58: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_9:
    // 0x80055B5C: lw          $v1, 0x14($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X14);
    // 0x80055B60: ori         $v1, $v1, 0x20
    ctx->r3 = ctx->r3 | 0X20;
    // 0x80055B64: sw          $v1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r3;
    // 0x80055B68: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80055B6C: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x80055B70: lw          $v1, -0x6FF0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6FF0);
    // 0x80055B74: lbu         $v0, 0x7($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7);
    // 0x80055B78: sb          $v0, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r2;
    // 0x80055B7C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80055B80: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80055B84: jr          $ra
    // 0x80055B88: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80055B88: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80055B8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055B8C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80055B90: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80055B94: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80055B98: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80055B9C: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80055BA0: lw          $a0, -0x6FF0($s1)
    ctx->r4 = MEM_W(ctx->r17, -0X6FF0);
    // 0x80055BA4: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80055BA8: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x80055BAC: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80055BB0: beq         $v1, $v0, L_80055C9C
    if (ctx->r3 == ctx->r2) {
        // 0x80055BB4: nop
    
            goto L_80055C9C;
    }
    // 0x80055BB4: nop

    // 0x80055BB8: lbu         $v0, 0x3($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X3);
    // 0x80055BBC: beq         $v0, $zero, L_80055C9C
    if (ctx->r2 == 0) {
        // 0x80055BC0: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_80055C9C;
    }
    // 0x80055BC0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80055BC4: lhu         $a0, -0x6FEC($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6FEC);
    // 0x80055BC8: jal         0x80063C3C
    // 0x80055BCC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_80063C3C(rdram, ctx);
        goto after_0;
    // 0x80055BCC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x80055BD0: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x80055BD4: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x80055BD8: beq         $v1, $zero, L_80055BE4
    if (ctx->r3 == 0) {
        // 0x80055BDC: sw          $v1, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r3;
            goto L_80055BE4;
    }
    // 0x80055BDC: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // 0x80055BE0: sw          $a2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r6;
L_80055BE4:
    // 0x80055BE4: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x80055BE8: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x80055BEC: lw          $a1, -0x6FF0($s1)
    ctx->r5 = MEM_W(ctx->r17, -0X6FF0);
    // 0x80055BF0: sw          $a2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r6;
    // 0x80055BF4: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x80055BF8: srl         $v1, $v0, 31
    ctx->r3 = S32(U32(ctx->r2) >> 31);
    // 0x80055BFC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80055C00: lh          $v1, 0x12($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X12);
    // 0x80055C04: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80055C08: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80055C0C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80055C10: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80055C14: swc1        $f0, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f0.u32l;
    // 0x80055C18: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x80055C1C: lh          $a0, 0xC($a1)
    ctx->r4 = MEM_H(ctx->r5, 0XC);
    // 0x80055C20: srl         $v1, $v0, 31
    ctx->r3 = S32(U32(ctx->r2) >> 31);
    // 0x80055C24: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80055C28: lh          $v1, 0x14($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X14);
    // 0x80055C2C: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80055C30: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80055C34: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80055C38: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80055C3C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80055C40: swc1        $f0, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->f0.u32l;
    // 0x80055C44: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x80055C48: addiu       $v0, $v0, -0x222
    ctx->r2 = ADD32(ctx->r2, -0X222);
    // 0x80055C4C: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80055C50: beq         $v0, $zero, L_80055C9C
    if (ctx->r2 == 0) {
        // 0x80055C54: nop
    
            goto L_80055C9C;
    }
    // 0x80055C54: nop

    // 0x80055C58: lw          $v1, 0x10($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X10);
    // 0x80055C5C: lw          $a0, 0x10($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X10);
    // 0x80055C60: srl         $v0, $v1, 31
    ctx->r2 = S32(U32(ctx->r3) >> 31);
    // 0x80055C64: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80055C68: lhu         $v0, 0x8($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X8);
    // 0x80055C6C: sra         $v1, $v1, 1
    ctx->r3 = S32(SIGNED(ctx->r3) >> 1);
    // 0x80055C70: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80055C74: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80055C78: lh          $v0, -0x4($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X4);
    // 0x80055C7C: lh          $a0, 0x4($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X4);
    // 0x80055C80: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80055C84: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80055C88: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80055C8C: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80055C90: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x80055C94: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80055C98: swc1        $f0, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->f0.u32l;
L_80055C9C:
    // 0x80055C9C: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80055CA0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80055CA4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80055CA8: jr          $ra
    // 0x80055CAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80055CAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80055CB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055CB0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80055CB4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80055CB8: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80055CBC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80055CC0: lw          $v1, -0x6FF0($s0)
    ctx->r3 = MEM_W(ctx->r16, -0X6FF0);
    // 0x80055CC4: addiu       $a0, $v0, 0xB40
    ctx->r4 = ADD32(ctx->r2, 0XB40);
    // 0x80055CC8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80055CCC: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80055CD0: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80055CD4: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80055CD8: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80055CDC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80055CE0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80055CE4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80055CE8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80055CEC: sdc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X48, ctx->r29);
    // 0x80055CF0: lbu         $v0, 0x16($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X16);
    // 0x80055CF4: lh          $t2, 0x16($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X16);
    // 0x80055CF8: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x80055CFC: beq         $v0, $zero, L_80055D10
    if (ctx->r2 == 0) {
        // 0x80055D00: sw          $t2, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r10;
            goto L_80055D10;
    }
    // 0x80055D00: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x80055D04: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80055D08: j           L_80055D24
    // 0x80055D0C: addiu       $a1, $zero, 0x222
    ctx->r5 = ADD32(0, 0X222);
        goto L_80055D24;
    // 0x80055D0C: addiu       $a1, $zero, 0x222
    ctx->r5 = ADD32(0, 0X222);
L_80055D10:
    // 0x80055D10: lw          $v0, 0x10($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X10);
    // 0x80055D14: andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // 0x80055D18: beq         $v0, $zero, L_80055D4C
    if (ctx->r2 == 0) {
        // 0x80055D1C: addiu       $a1, $zero, 0x223
        ctx->r5 = ADD32(0, 0X223);
            goto L_80055D4C;
    }
    // 0x80055D1C: addiu       $a1, $zero, 0x223
    ctx->r5 = ADD32(0, 0X223);
    // 0x80055D20: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
L_80055D24:
    // 0x80055D24: beq         $v0, $a1, L_80055D4C
    if (ctx->r2 == ctx->r5) {
        // 0x80055D28: addu        $a0, $a1, $zero
        ctx->r4 = ADD32(ctx->r5, 0);
            goto L_80055D4C;
    }
    // 0x80055D28: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // 0x80055D2C: jal         0x80055978
    // 0x80055D30: sh          $a1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r5;
    getVoiceText(rdram, ctx);
        goto after_0;
    // 0x80055D30: sh          $a1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r5;
    after_0:
    // 0x80055D34: lw          $v0, -0x6FF0($s0)
    ctx->r2 = MEM_W(ctx->r16, -0X6FF0);
    // 0x80055D38: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
    // 0x80055D3C: lw          $a0, -0x6FF0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X6FF0);
    // 0x80055D40: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80055D44: sw          $v1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r3;
    // 0x80055D48: sb          $zero, 0x2($a0)
    MEM_B(0X2, ctx->r4) = 0;
L_80055D4C:
    // 0x80055D4C: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80055D50: lw          $v1, -0x6FF0($s1)
    ctx->r3 = MEM_W(ctx->r17, -0X6FF0);
    // 0x80055D54: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80055D58: ori         $s0, $zero, 0xFFFF
    ctx->r16 = 0 | 0XFFFF;
    // 0x80055D5C: beq         $v0, $s0, L_80056178
    if (ctx->r2 == ctx->r16) {
        // 0x80055D60: nop
    
            goto L_80056178;
    }
    // 0x80055D60: nop

    // 0x80055D64: jal         0x80055A20
    // 0x80055D68: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_80055A20(rdram, ctx);
        goto after_1;
    // 0x80055D68: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_1:
    // 0x80055D6C: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x80055D70: beq         $s2, $zero, L_80056178
    if (ctx->r18 == 0) {
        // 0x80055D74: nop
    
            goto L_80056178;
    }
    // 0x80055D74: nop

    // 0x80055D78: lw          $v0, -0x6FF0($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X6FF0);
    // 0x80055D7C: lbu         $v0, 0x2($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2);
    // 0x80055D80: bnel        $v0, $zero, L_80055F68
    if (ctx->r2 != 0) {
        // 0x80055D84: lui         $s0, 0x8014
        ctx->r16 = S32(0X8014 << 16);
            goto L_80055F68;
    }
    goto skip_0;
    // 0x80055D84: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    skip_0:
    // 0x80055D88: jal         0x8006B3D0
    // 0x80055D8C: lui         $s3, 0x8014
    ctx->r19 = S32(0X8014 << 16);
    func_8006B3D0(rdram, ctx);
        goto after_2;
    // 0x80055D8C: lui         $s3, 0x8014
    ctx->r19 = S32(0X8014 << 16);
    after_2:
    // 0x80055D90: lui         $a0, 0x6666
    ctx->r4 = S32(0X6666 << 16);
    // 0x80055D94: ori         $a0, $a0, 0x6667
    ctx->r4 = ctx->r4 | 0X6667;
    // 0x80055D98: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80055D9C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80055DA0: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x80055DA4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80055DA8: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x80055DAC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80055DB0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80055DB4: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x80055DB8: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x80055DBC: mult        $v1, $a0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80055DC0: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x80055DC4: lhu         $a0, -0x6FEC($s3)
    ctx->r4 = MEM_HU(ctx->r19, -0X6FEC);
    // 0x80055DC8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80055DCC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80055DD0: mfhi        $t2
    ctx->r10 = hi;
    // 0x80055DD4: sra         $a3, $t2, 7
    ctx->r7 = S32(SIGNED(ctx->r10) >> 7);
    // 0x80055DD8: subu        $a3, $a3, $v1
    ctx->r7 = SUB32(ctx->r7, ctx->r3);
    // 0x80055DDC: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x80055DE0: jal         0x80063CFC
    // 0x80055DE4: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    func_80063CFC(rdram, ctx);
        goto after_3;
    // 0x80055DE4: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    after_3:
    // 0x80055DE8: lhu         $a0, -0x6FEC($s3)
    ctx->r4 = MEM_HU(ctx->r19, -0X6FEC);
    // 0x80055DEC: jal         0x80063C3C
    // 0x80055DF0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_80063C3C(rdram, ctx);
        goto after_4;
    // 0x80055DF0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_4:
    // 0x80055DF4: addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
    // 0x80055DF8: lhu         $v0, 0x8($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X8);
    // 0x80055DFC: bne         $v0, $zero, L_80055E10
    if (ctx->r2 != 0) {
        // 0x80055E00: addu        $s7, $zero, $zero
        ctx->r23 = ADD32(0, 0);
            goto L_80055E10;
    }
    // 0x80055E00: addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
    // 0x80055E04: lw          $v0, -0x6FF0($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X6FF0);
    // 0x80055E08: j           L_80056178
    // 0x80055E0C: sh          $s0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r16;
        goto L_80056178;
    // 0x80055E0C: sh          $s0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r16;
L_80055E10:
    // 0x80055E10: addu        $s0, $s7, $zero
    ctx->r16 = ADD32(ctx->r23, 0);
    // 0x80055E14: addu        $s4, $s7, $zero
    ctx->r20 = ADD32(ctx->r23, 0);
    // 0x80055E18: lw          $v1, -0x6FF0($s1)
    ctx->r3 = MEM_W(ctx->r17, -0X6FF0);
    // 0x80055E1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80055E20: sb          $v0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r2;
    // 0x80055E24: lw          $v0, -0x6FF0($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X6FF0);
    // 0x80055E28: sh          $zero, 0xE($v0)
    MEM_H(0XE, ctx->r2) = 0;
    // 0x80055E2C: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x80055E30: lw          $s6, 0x10($s5)
    ctx->r22 = MEM_W(ctx->r21, 0X10);
    // 0x80055E34: beq         $v0, $zero, L_80055F14
    if (ctx->r2 == 0) {
        // 0x80055E38: addu        $s1, $s7, $zero
        ctx->r17 = ADD32(ctx->r23, 0);
            goto L_80055F14;
    }
    // 0x80055E38: addu        $s1, $s7, $zero
    ctx->r17 = ADD32(ctx->r23, 0);
    // 0x80055E3C: addiu       $fp, $s3, -0x6FEC
    ctx->r30 = ADD32(ctx->r19, -0X6FEC);
    // 0x80055E40: addu        $s3, $s2, $zero
    ctx->r19 = ADD32(ctx->r18, 0);
    // 0x80055E44: addu        $s2, $s6, $zero
    ctx->r18 = ADD32(ctx->r22, 0);
L_80055E48:
    // 0x80055E48: lbu         $v1, 0x0($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X0);
    // 0x80055E4C: addiu       $v0, $zero, 0x20
    ctx->r2 = ADD32(0, 0X20);
    // 0x80055E50: beql        $v1, $v0, L_80055E58
    if (ctx->r3 == ctx->r2) {
        // 0x80055E54: addu        $s4, $s1, $zero
        ctx->r20 = ADD32(ctx->r17, 0);
            goto L_80055E58;
    }
    goto skip_1;
    // 0x80055E54: addu        $s4, $s1, $zero
    ctx->r20 = ADD32(ctx->r17, 0);
    skip_1:
L_80055E58:
    // 0x80055E58: lbu         $a0, 0x1($fp)
    ctx->r4 = MEM_BU(ctx->r30, 0X1);
    // 0x80055E5C: jal         0x80063C18
    // 0x80055E60: nop

    func_80063C18(rdram, ctx);
        goto after_5;
    // 0x80055E60: nop

    after_5:
    // 0x80055E64: lbu         $v1, 0x0($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X0);
    // 0x80055E68: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80055E6C: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x80055E70: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80055E74: beql        $v1, $v0, L_80055F08
    if (ctx->r3 == ctx->r2) {
        // 0x80055E78: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_80055F08;
    }
    goto skip_2;
    // 0x80055E78: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_2:
    // 0x80055E7C: lhu         $v0, 0x0($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X0);
    // 0x80055E80: subu        $v0, $v0, $s7
    ctx->r2 = SUB32(ctx->r2, ctx->r23);
    // 0x80055E84: sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
    // 0x80055E88: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80055E8C: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80055E90: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80055E94: slt         $v0, $t2, $v0
    ctx->r2 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80055E98: beq         $v0, $zero, L_80055EF8
    if (ctx->r2 == 0) {
        // 0x80055E9C: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_80055EF8;
    }
    // 0x80055E9C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80055EA0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x80055EA4: sll         $v0, $s4, 2
    ctx->r2 = S32(ctx->r20 << 2);
    // 0x80055EA8: addu        $a0, $v0, $s6
    ctx->r4 = ADD32(ctx->r2, ctx->r22);
    // 0x80055EAC: lw          $v0, -0x6FF0($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X6FF0);
    // 0x80055EB0: lh          $v1, 0x0($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X0);
    // 0x80055EB4: lbu         $v0, 0x5($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5);
    // 0x80055EB8: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x80055EBC: slt         $v0, $s1, $s4
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80055EC0: bne         $v0, $zero, L_80055EF8
    if (ctx->r2 != 0) {
        // 0x80055EC4: addu        $s7, $s7, $v1
        ctx->r23 = ADD32(ctx->r23, ctx->r3);
            goto L_80055EF8;
    }
    // 0x80055EC4: addu        $s7, $s7, $v1
    ctx->r23 = ADD32(ctx->r23, ctx->r3);
    // 0x80055EC8: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x80055ECC: sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17 << 2);
    // 0x80055ED0: addu        $a0, $v0, $s6
    ctx->r4 = ADD32(ctx->r2, ctx->r22);
L_80055ED4:
    // 0x80055ED4: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80055ED8: lhu         $v1, 0x0($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X0);
    // 0x80055EDC: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x80055EE0: sh          $s0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r16;
    // 0x80055EE4: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80055EE8: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x80055EEC: slt         $v0, $a1, $s4
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x80055EF0: beq         $v0, $zero, L_80055ED4
    if (ctx->r2 == 0) {
        // 0x80055EF4: addiu       $a0, $a0, -0x4
        ctx->r4 = ADD32(ctx->r4, -0X4);
            goto L_80055ED4;
    }
    // 0x80055EF4: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
L_80055EF8:
    // 0x80055EF8: sh          $s0, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r16;
    // 0x80055EFC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80055F00: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80055F04: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80055F08:
    // 0x80055F08: lbu         $v0, 0x0($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X0);
    // 0x80055F0C: bne         $v0, $zero, L_80055E48
    if (ctx->r2 != 0) {
        // 0x80055F10: nop
    
            goto L_80055E48;
    }
    // 0x80055F10: nop

L_80055F14:
    // 0x80055F14: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80055F18: lw          $v1, -0x6FF0($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X6FF0);
    // 0x80055F1C: lbu         $v0, 0x5($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X5);
    // 0x80055F20: div         $zero, $s0, $v0
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r2)));
    // 0x80055F24: bne         $v0, $zero, L_80055F30
    if (ctx->r2 != 0) {
        // 0x80055F28: nop
    
            goto L_80055F30;
    }
    // 0x80055F28: nop

    // 0x80055F2C: break       7
    do_break(2147835692);
L_80055F30:
    // 0x80055F30: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80055F34: bne         $v0, $at, L_80055F48
    if (ctx->r2 != ctx->r1) {
        // 0x80055F38: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80055F48;
    }
    // 0x80055F38: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80055F3C: bne         $s0, $at, L_80055F48
    if (ctx->r16 != ctx->r1) {
        // 0x80055F40: nop
    
            goto L_80055F48;
    }
    // 0x80055F40: nop

    // 0x80055F44: break       6
    do_break(2147835716);
L_80055F48:
    // 0x80055F48: mflo        $v0
    ctx->r2 = lo;
    // 0x80055F4C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80055F50: sb          $v0, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r2;
    // 0x80055F54: lw          $v1, -0x6FF0($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X6FF0);
    // 0x80055F58: lhu         $v0, 0x8($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X8);
    // 0x80055F5C: sh          $v0, 0x10($v1)
    MEM_H(0X10, ctx->r3) = ctx->r2;
    // 0x80055F60: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x80055F64: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
L_80055F68:
    // 0x80055F68: lw          $v1, -0x6FF0($s0)
    ctx->r3 = MEM_W(ctx->r16, -0X6FF0);
    // 0x80055F6C: lbu         $v0, 0x3($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X3);
    // 0x80055F70: bnel        $v0, $zero, L_80055FEC
    if (ctx->r2 != 0) {
        // 0x80055F74: lui         $s1, 0x8014
        ctx->r17 = S32(0X8014 << 16);
            goto L_80055FEC;
    }
    goto skip_3;
    // 0x80055F74: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    skip_3:
    // 0x80055F78: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x80055F7C: addiu       $v0, $v0, -0x222
    ctx->r2 = ADD32(ctx->r2, -0X222);
    // 0x80055F80: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80055F84: beq         $v0, $zero, L_80055FA4
    if (ctx->r2 == 0) {
        // 0x80055F88: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80055FA4;
    }
    // 0x80055F88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80055F8C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80055F90: lwc1        $f0, -0x5288($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5288);
    // 0x80055F94: sw          $zero, 0x18($v1)
    MEM_W(0X18, ctx->r3) = 0;
    // 0x80055F98: sb          $v0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r2;
    // 0x80055F9C: j           L_80055FD8
    // 0x80055FA0: swc1        $f0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f0.u32l;
        goto L_80055FD8;
    // 0x80055FA0: swc1        $f0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f0.u32l;
L_80055FA4:
    // 0x80055FA4: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
    // 0x80055FA8: jal         0x8009B8A8
    // 0x80055FAC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    func_8009B8A8(rdram, ctx);
        goto after_6;
    // 0x80055FAC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_6:
    // 0x80055FB0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80055FB4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80055FB8: nop

    // 0x80055FBC: bc1f        L_80055FD8
    if (!c1cs) {
        // 0x80055FC0: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80055FD8;
    }
    // 0x80055FC0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80055FC4: lw          $v0, -0x6FF0($s0)
    ctx->r2 = MEM_W(ctx->r16, -0X6FF0);
    // 0x80055FC8: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80055FCC: swc1        $f2, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f2.u32l;
    // 0x80055FD0: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x80055FD4: sb          $v1, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r3;
L_80055FD8:
    // 0x80055FD8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80055FDC: lw          $v0, -0x6FF0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6FF0);
    // 0x80055FE0: lbu         $v0, 0x3($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X3);
    // 0x80055FE4: beq         $v0, $zero, L_80056178
    if (ctx->r2 == 0) {
        // 0x80055FE8: lui         $s1, 0x8014
        ctx->r17 = S32(0X8014 << 16);
            goto L_80056178;
    }
    // 0x80055FE8: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
L_80055FEC:
    // 0x80055FEC: lw          $v0, -0x6FF0($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X6FF0);
    // 0x80055FF0: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80055FF4: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x80055FF8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80055FFC: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80056000: nop

    // 0x80056004: bc1f        L_80056178
    if (!c1cs) {
        // 0x80056008: swc1        $f0, 0x18($v0)
        MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
            goto L_80056178;
    }
    // 0x80056008: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x8005600C: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80056010: lhu         $a0, -0x6FEC($s0)
    ctx->r4 = MEM_HU(ctx->r16, -0X6FEC);
    // 0x80056014: jal         0x80063C3C
    // 0x80056018: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_80063C3C(rdram, ctx);
        goto after_7;
    // 0x80056018: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_7:
    // 0x8005601C: lw          $a2, -0x6FF0($s1)
    ctx->r6 = MEM_W(ctx->r17, -0X6FF0);
    // 0x80056020: lhu         $v1, 0xE($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0XE);
    // 0x80056024: lhu         $a0, 0x10($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X10);
    // 0x80056028: sltu        $v1, $v1, $a0
    ctx->r3 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x8005602C: bne         $v1, $zero, L_80056050
    if (ctx->r3 != 0) {
        // 0x80056030: addu        $s5, $v0, $zero
        ctx->r21 = ADD32(ctx->r2, 0);
            goto L_80056050;
    }
    // 0x80056030: addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
    // 0x80056034: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80056038: lhu         $a0, -0x6FEC($s0)
    ctx->r4 = MEM_HU(ctx->r16, -0X6FEC);
    // 0x8005603C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80056040: jal         0x80063C3C
    // 0x80056044: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    func_80063C3C(rdram, ctx);
        goto after_8;
    // 0x80056044: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    after_8:
    // 0x80056048: j           L_80056178
    // 0x8005604C: nop

        goto L_80056178;
    // 0x8005604C: nop

L_80056050:
    // 0x80056050: lbu         $v0, 0x3($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X3);
    // 0x80056054: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x80056058: bne         $v0, $zero, L_80056088
    if (ctx->r2 != 0) {
        // 0x8005605C: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_80056088;
    }
    // 0x8005605C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80056060: lhu         $v0, 0x8($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X8);
    // 0x80056064: lw          $v1, 0xC($s5)
    ctx->r3 = MEM_W(ctx->r21, 0XC);
    // 0x80056068: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8005606C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80056070: lhu         $v0, 0x8($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X8);
    // 0x80056074: sw          $v1, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r3;
    // 0x80056078: lw          $v1, 0x10($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X10);
    // 0x8005607C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80056080: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80056084: sw          $v1, 0x10($s5)
    MEM_W(0X10, ctx->r21) = ctx->r3;
L_80056088:
    // 0x80056088: lw          $a1, 0x10($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X10);
    // 0x8005608C: lw          $v0, -0x6FF0($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X6FF0);
    // 0x80056090: lh          $s0, 0x2($a1)
    ctx->r16 = MEM_H(ctx->r5, 0X2);
    // 0x80056094: lhu         $v1, 0xE($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XE);
    // 0x80056098: lhu         $a0, 0x10($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X10);
    // 0x8005609C: addu        $v0, $v1, $a2
    ctx->r2 = ADD32(ctx->r3, ctx->r6);
    // 0x800560A0: slt         $v0, $v0, $a0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800560A4: beq         $v0, $zero, L_800560F0
    if (ctx->r2 == 0) {
        // 0x800560A8: addu        $a3, $a2, $zero
        ctx->r7 = ADD32(ctx->r6, 0);
            goto L_800560F0;
    }
    // 0x800560A8: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // 0x800560AC: addu        $t1, $v1, $zero
    ctx->r9 = ADD32(ctx->r3, 0);
    // 0x800560B0: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x800560B4: addiu       $a0, $a1, 0x4
    ctx->r4 = ADD32(ctx->r5, 0X4);
L_800560B8:
    // 0x800560B8: lh          $v1, 0x2($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X2);
    // 0x800560BC: slt         $v0, $s0, $v1
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800560C0: beql        $v0, $zero, L_800560E0
    if (ctx->r2 == 0) {
        // 0x800560C4: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_800560E0;
    }
    goto skip_4;
    // 0x800560C4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_4:
    // 0x800560C8: slti        $v0, $a3, 0x3
    ctx->r2 = SIGNED(ctx->r7) < 0X3 ? 1 : 0;
    // 0x800560CC: beq         $v0, $zero, L_800560F4
    if (ctx->r2 == 0) {
        // 0x800560D0: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800560F4;
    }
    // 0x800560D0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800560D4: addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
    // 0x800560D8: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800560DC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_800560E0:
    // 0x800560E0: addu        $v0, $a2, $t1
    ctx->r2 = ADD32(ctx->r6, ctx->r9);
    // 0x800560E4: slt         $v0, $v0, $t0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800560E8: bne         $v0, $zero, L_800560B8
    if (ctx->r2 != 0) {
        // 0x800560EC: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800560B8;
    }
    // 0x800560EC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_800560F0:
    // 0x800560F0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
L_800560F4:
    // 0x800560F4: lw          $a1, -0x6FF0($v0)
    ctx->r5 = MEM_W(ctx->r2, -0X6FF0);
    // 0x800560F8: lhu         $v0, 0xE($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XE);
    // 0x800560FC: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80056100: sh          $v0, 0xE($a1)
    MEM_H(0XE, ctx->r5) = ctx->r2;
    // 0x80056104: sh          $a2, 0x8($s5)
    MEM_H(0X8, ctx->r21) = ctx->r6;
    // 0x80056108: lbu         $v0, 0x5($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X5);
    // 0x8005610C: lhu         $v1, 0xE($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0XE);
    // 0x80056110: lhu         $a0, 0x10($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X10);
    // 0x80056114: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x80056118: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x8005611C: sltu        $v1, $v1, $a0
    ctx->r3 = ctx->r3 < ctx->r4 ? 1 : 0;
    // 0x80056120: bne         $v1, $zero, L_80056140
    if (ctx->r3 != 0) {
        // 0x80056124: sh          $v0, 0xC($a1)
        MEM_H(0XC, ctx->r5) = ctx->r2;
            goto L_80056140;
    }
    // 0x80056124: sh          $v0, 0xC($a1)
    MEM_H(0XC, ctx->r5) = ctx->r2;
    // 0x80056128: lwc1        $f0, 0x18($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X18);
    // 0x8005612C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80056130: lwc1        $f2, -0x5284($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5284);
    // 0x80056134: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80056138: j           L_8005614C
    // 0x8005613C: swc1        $f0, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->f0.u32l;
        goto L_8005614C;
    // 0x8005613C: swc1        $f0, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->f0.u32l;
L_80056140:
    // 0x80056140: lbu         $v0, 0x3($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X3);
    // 0x80056144: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80056148: sb          $v0, 0x3($a1)
    MEM_B(0X3, ctx->r5) = ctx->r2;
L_8005614C:
    // 0x8005614C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80056150: lw          $v1, -0x6FF0($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X6FF0);
    // 0x80056154: lwc1        $f0, 0x1C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x80056158: mtc1        $a3, $f2
    ctx->f2.u32l = ctx->r7;
    // 0x8005615C: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80056160: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80056164: lbu         $v0, 0x4($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X4);
    // 0x80056168: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x8005616C: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80056170: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80056174: swc1        $f0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f0.u32l;
L_80056178:
    // 0x80056178: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8005617C: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80056180: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80056184: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80056188: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8005618C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80056190: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80056194: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80056198: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8005619C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800561A0: ldc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X48);
    // 0x800561A4: jr          $ra
    // 0x800561A8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800561A8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_800561AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800561AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800561B0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800561B4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800561B8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800561BC: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x800561C0: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800561C4: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800561C8: jal         0x8006B3D0
    // 0x800561CC: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    func_8006B3D0(rdram, ctx);
        goto after_0;
    // 0x800561CC: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    after_0:
    // 0x800561D0: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x800561D4: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800561D8: addiu       $s0, $s0, 0x18
    ctx->r16 = ADD32(ctx->r16, 0X18);
    // 0x800561DC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800561E0: mult        $s0, $v0
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800561E4: mflo        $s0
    ctx->r16 = lo;
    // 0x800561E8: lui         $s3, 0x6666
    ctx->r19 = S32(0X6666 << 16);
    // 0x800561EC: ori         $s3, $s3, 0x6667
    ctx->r19 = ctx->r19 | 0X6667;
    // 0x800561F0: mult        $s0, $s3
    result = S64(S32(ctx->r16)) * S64(S32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800561F4: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x800561F8: sra         $s0, $s0, 31
    ctx->r16 = S32(SIGNED(ctx->r16) >> 31);
    // 0x800561FC: mfhi        $v1
    ctx->r3 = hi;
    // 0x80056200: sra         $v0, $v1, 7
    ctx->r2 = S32(SIGNED(ctx->r3) >> 7);
    // 0x80056204: lw          $v1, -0x6FF0($s2)
    ctx->r3 = MEM_W(ctx->r18, -0X6FF0);
    // 0x80056208: subu        $v0, $v0, $s0
    ctx->r2 = SUB32(ctx->r2, ctx->r16);
    // 0x8005620C: jal         0x8006B3E0
    // 0x80056210: sh          $v0, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r2;
    func_8006B3E0(rdram, ctx);
        goto after_1;
    // 0x80056210: sh          $v0, 0x12($v1)
    MEM_H(0X12, ctx->r3) = ctx->r2;
    after_1:
    // 0x80056214: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x80056218: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x8005621C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80056220: mult        $s1, $v0
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80056224: mflo        $s1
    ctx->r17 = lo;
    // 0x80056228: lui         $v0, 0x9249
    ctx->r2 = S32(0X9249 << 16);
    // 0x8005622C: ori         $v0, $v0, 0x2493
    ctx->r2 = ctx->r2 | 0X2493;
    // 0x80056230: mult        $s1, $v0
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80056234: mfhi        $v1
    ctx->r3 = hi;
    // 0x80056238: addu        $v0, $v1, $s1
    ctx->r2 = ADD32(ctx->r3, ctx->r17);
    // 0x8005623C: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x80056240: sra         $s1, $s1, 31
    ctx->r17 = S32(SIGNED(ctx->r17) >> 31);
    // 0x80056244: lw          $v1, -0x6FF0($s2)
    ctx->r3 = MEM_W(ctx->r18, -0X6FF0);
    // 0x80056248: subu        $v0, $v0, $s1
    ctx->r2 = SUB32(ctx->r2, ctx->r17);
    // 0x8005624C: jal         0x8006B3D0
    // 0x80056250: sh          $v0, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r2;
    func_8006B3D0(rdram, ctx);
        goto after_2;
    // 0x80056250: sh          $v0, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r2;
    after_2:
    // 0x80056254: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80056258: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x8005625C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80056260: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80056264: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80056268: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8005626C: mult        $v1, $s3
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80056270: lw          $a1, -0x6FF0($s2)
    ctx->r5 = MEM_W(ctx->r18, -0X6FF0);
    // 0x80056274: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x80056278: lhu         $a0, 0x12($a1)
    ctx->r4 = MEM_HU(ctx->r5, 0X12);
    // 0x8005627C: mfhi        $a3
    ctx->r7 = hi;
    // 0x80056280: sra         $v0, $a3, 7
    ctx->r2 = S32(SIGNED(ctx->r7) >> 7);
    // 0x80056284: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80056288: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x8005628C: sh          $v0, 0x16($a1)
    MEM_H(0X16, ctx->r5) = ctx->r2;
    // 0x80056290: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80056294: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80056298: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8005629C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800562A0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800562A4: jr          $ra
    // 0x800562A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800562A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800562AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800562AC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800562B0: lhu         $a0, -0x6FEC($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6FEC);
    // 0x800562B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800562B8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800562BC: jal         0x80063BEC
    // 0x800562C0: nop

    func_80063BEC(rdram, ctx);
        goto after_0;
    // 0x800562C0: nop

    after_0:
    // 0x800562C4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800562C8: lw          $a0, -0x6FF0($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X6FF0);
    // 0x800562CC: jal         0x80001C98
    // 0x800562D0: nop

    rs_free(rdram, ctx);
        goto after_1;
    // 0x800562D0: nop

    after_1:
    // 0x800562D4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800562D8: jr          $ra
    // 0x800562DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800562DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800562E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800562E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800562E4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800562E8: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x800562EC: lw          $v0, -0x6FF0($s0)
    ctx->r2 = MEM_W(ctx->r16, -0X6FF0);
    // 0x800562F0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800562F4: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x800562F8: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800562FC: sh          $a0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r4;
    // 0x80056300: jal         0x80055978
    // 0x80056304: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    getVoiceText(rdram, ctx);
        goto after_0;
    // 0x80056304: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    after_0:
    // 0x80056308: lw          $v0, -0x6FF0($s0)
    ctx->r2 = MEM_W(ctx->r16, -0X6FF0);
    // 0x8005630C: sb          $zero, 0x3($v0)
    MEM_B(0X3, ctx->r2) = 0;
    // 0x80056310: lw          $v1, -0x6FF0($s0)
    ctx->r3 = MEM_W(ctx->r16, -0X6FF0);
    // 0x80056314: sw          $s1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r17;
    // 0x80056318: sb          $zero, 0x2($v1)
    MEM_B(0X2, ctx->r3) = 0;
    // 0x8005631C: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80056320: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80056324: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80056328: jr          $ra
    // 0x8005632C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8005632C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80056330(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056330: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80056334: lw          $v1, -0x6FF0($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X6FF0);
    // 0x80056338: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8005633C: jr          $ra
    // 0x80056340: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    return;
    // 0x80056340: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void fake_func_80056344(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80056350(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056350: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80056354: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80056358: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8005635C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80056360: addiu       $a1, $v0, -0x6FE0
    ctx->r5 = ADD32(ctx->r2, -0X6FE0);
    // 0x80056364: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
L_80056368:
    // 0x80056368: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8005636C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80056370: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x80056374: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    // 0x80056378: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    // 0x8005637C: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x80056380: slti        $v0, $a0, 0x60
    ctx->r2 = SIGNED(ctx->r4) < 0X60 ? 1 : 0;
    // 0x80056384: bnel        $v0, $zero, L_80056368
    if (ctx->r2 != 0) {
        // 0x80056388: sll         $v0, $a0, 1
        ctx->r2 = S32(ctx->r4 << 1);
            goto L_80056368;
    }
    goto skip_0;
    // 0x80056388: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    skip_0:
    // 0x8005638C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80056390: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80056394: sh          $v0, -0x6B6C($v1)
    MEM_H(-0X6B6C, ctx->r3) = ctx->r2;
    // 0x80056398: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8005639C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x800563A0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800563A4: addiu       $v0, $v0, -0x6B50
    ctx->r2 = ADD32(ctx->r2, -0X6B50);
    // 0x800563A8: addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
L_800563AC:
    // 0x800563AC: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
    // 0x800563B0: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800563B4: bgez        $a0, L_800563AC
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800563B8: addiu       $v0, $v0, -0x2
        ctx->r2 = ADD32(ctx->r2, -0X2);
            goto L_800563AC;
    }
    // 0x800563B8: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x800563BC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800563C0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800563C4: addiu       $a1, $v0, -0x5B68
    ctx->r5 = ADD32(ctx->r2, -0X5B68);
    // 0x800563C8: addu        $v1, $a0, $a1
    ctx->r3 = ADD32(ctx->r4, ctx->r5);
L_800563CC:
    // 0x800563CC: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x800563D0: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x800563D4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800563D8: slti        $v0, $a0, 0x80
    ctx->r2 = SIGNED(ctx->r4) < 0X80 ? 1 : 0;
    // 0x800563DC: bne         $v0, $zero, L_800563CC
    if (ctx->r2 != 0) {
        // 0x800563E0: addu        $v1, $a0, $a1
        ctx->r3 = ADD32(ctx->r4, ctx->r5);
            goto L_800563CC;
    }
    // 0x800563E0: addu        $v1, $a0, $a1
    ctx->r3 = ADD32(ctx->r4, ctx->r5);
    // 0x800563E4: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800563E8: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x800563EC: sh          $v0, -0x5B70($v1)
    MEM_H(-0X5B70, ctx->r3) = ctx->r2;
    // 0x800563F0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800563F4: sh          $zero, -0x6B60($v0)
    MEM_H(-0X6B60, ctx->r2) = 0;
    // 0x800563F8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800563FC: sh          $zero, -0x6B1C($v0)
    MEM_H(-0X6B1C, ctx->r2) = 0;
    // 0x80056400: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80056404: addiu       $a0, $zero, 0x4380
    ctx->r4 = ADD32(0, 0X4380);
    // 0x80056408: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005640C: jal         0x80001ACC
    // 0x80056410: sh          $zero, -0x6B1E($v0)
    MEM_H(-0X6B1E, ctx->r2) = 0;
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x80056410: sh          $zero, -0x6B1E($v0)
    MEM_H(-0X6B1E, ctx->r2) = 0;
    after_0:
    // 0x80056414: addiu       $a0, $zero, 0x5F
    ctx->r4 = ADD32(0, 0X5F);
    // 0x80056418: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8005641C: addiu       $v1, $v1, -0x6B10
    ctx->r3 = ADD32(ctx->r3, -0X6B10);
    // 0x80056420: addu        $a1, $v1, $a0
    ctx->r5 = ADD32(ctx->r3, ctx->r4);
    // 0x80056424: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80056428: sw          $v0, -0x6B18($v1)
    MEM_W(-0X6B18, ctx->r3) = ctx->r2;
L_8005642C:
    // 0x8005642C: sb          $a0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r4;
    // 0x80056430: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80056434: bgez        $a0, L_8005642C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80056438: addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
            goto L_8005642C;
    }
    // 0x80056438: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x8005643C: addiu       $a0, $zero, 0x60
    ctx->r4 = ADD32(0, 0X60);
    // 0x80056440: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80056444: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80056448: sb          $a0, -0x6AB0($v0)
    MEM_B(-0X6AB0, ctx->r2) = ctx->r4;
    // 0x8005644C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80056450: sw          $zero, -0x6AAC($v0)
    MEM_W(-0X6AAC, ctx->r2) = 0;
    // 0x80056454: jr          $ra
    // 0x80056458: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80056458: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void load_hmt_and_hob(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005645C: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x80056460: sw          $s6, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r22;
    // 0x80056464: addu        $s6, $zero, $zero
    ctx->r22 = ADD32(0, 0);
    // 0x80056468: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005646C: sw          $s4, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r20;
    // 0x80056470: addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // 0x80056474: andi        $t0, $s4, 0x1
    ctx->r8 = ctx->r20 & 0X1;
    // 0x80056478: sw          $a0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r4;
    // 0x8005647C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80056480: sw          $a1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r5;
    // 0x80056484: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80056488: lh          $v0, -0x7FA4($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X7FA4);
    // 0x8005648C: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x80056490: addiu       $a1, $a1, -0x5280
    ctx->r5 = ADD32(ctx->r5, -0X5280);
    // 0x80056494: sw          $ra, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r31;
    // 0x80056498: sw          $fp, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r30;
    // 0x8005649C: sw          $s7, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r23;
    // 0x800564A0: sw          $s5, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r21;
    // 0x800564A4: sw          $s3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r19;
    // 0x800564A8: sw          $s2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r18;
    // 0x800564AC: sw          $s1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r17;
    // 0x800564B0: sw          $s0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r16;
    // 0x800564B4: sb          $t0, 0x8F($sp)
    MEM_B(0X8F, ctx->r29) = ctx->r8;
    // 0x800564B8: sw          $a3, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r7;
    // 0x800564BC: jal         0x80033CC4
    // 0x800564C0: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    sprintf_recomp(rdram, ctx);
        goto after_0;
    // 0x800564C0: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    after_0:
    // 0x800564C4: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x800564C8: blez        $t0, L_80056568
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800564CC: addiu       $t0, $sp, 0x18
        ctx->r8 = ADD32(ctx->r29, 0X18);
            goto L_80056568;
    }
    // 0x800564CC: addiu       $t0, $sp, 0x18
    ctx->r8 = ADD32(ctx->r29, 0X18);
    // 0x800564D0: lbu         $v0, 0x18($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X18);
    // 0x800564D4: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x800564D8: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
    // 0x800564DC: beq         $v0, $zero, L_80056528
    if (ctx->r2 == 0) {
        // 0x800564E0: sw          $t0, 0x70($sp)
        MEM_W(0X70, ctx->r29) = ctx->r8;
            goto L_80056528;
    }
    // 0x800564E0: sw          $t0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r8;
    // 0x800564E4: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
L_800564E8:
    // 0x800564E8: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x800564EC: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x800564F0: addu        $v0, $v1, $t0
    ctx->r2 = ADD32(ctx->r3, ctx->r8);
    // 0x800564F4: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800564F8: bnel        $v0, $a1, L_80056514
    if (ctx->r2 != ctx->r5) {
        // 0x800564FC: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_80056514;
    }
    goto skip_0;
    // 0x800564FC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    skip_0:
    // 0x80056500: addiu       $v0, $t0, 0x1
    ctx->r2 = ADD32(ctx->r8, 0X1);
    // 0x80056504: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80056508: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x8005650C: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x80056510: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_80056514:
    // 0x80056514: addu        $v0, $v1, $t0
    ctx->r2 = ADD32(ctx->r3, ctx->r8);
    // 0x80056518: sw          $t0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r8;
    // 0x8005651C: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80056520: bne         $v0, $zero, L_800564E8
    if (ctx->r2 != 0) {
        // 0x80056524: nop
    
            goto L_800564E8;
    }
    // 0x80056524: nop

L_80056528:
    // 0x80056528: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x8005652C: addiu       $v0, $t0, 0x30
    ctx->r2 = ADD32(ctx->r8, 0X30);
    // 0x80056530: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x80056534: sb          $v0, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r2;
    // 0x80056538: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8005653C: lw          $a0, 0x7CFC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X7CFC);
    // 0x80056540: jal         0x80005080
    // 0x80056544: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    get_manifest_entry_type(rdram, ctx);
        goto after_1;
    // 0x80056544: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x80056548: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8005654C: beq         $v0, $v1, L_80056568
    if (ctx->r2 == ctx->r3) {
        // 0x80056550: addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
            goto L_80056568;
    }
    // 0x80056550: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x80056554: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80056558: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x8005655C: jal         0x80033CC4
    // 0x80056560: addiu       $a1, $a1, -0x5280
    ctx->r5 = ADD32(ctx->r5, -0X5280);
    sprintf_recomp(rdram, ctx);
        goto after_2;
    // 0x80056560: addiu       $a1, $a1, -0x5280
    ctx->r5 = ADD32(ctx->r5, -0X5280);
    after_2:
    // 0x80056564: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
L_80056568:
    // 0x80056568: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8005656C: lw          $a0, 0x7CFC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X7CFC);
    // 0x80056570: jal         0x80004D5C
    // 0x80056574: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    get_asset_size_extra(rdram, ctx);
        goto after_3;
    // 0x80056574: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_3:
    // 0x80056578: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x8005657C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80056580: jal         0x80001ACC
    // 0x80056584: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    rs_malloc(rdram, ctx);
        goto after_4;
    // 0x80056584: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_4:
    // 0x80056588: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8005658C: bnel        $s3, $zero, L_800565A8
    if (ctx->r19 != 0) {
        // 0x80056590: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_800565A8;
    }
    goto skip_1;
    // 0x80056590: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    skip_1:
    // 0x80056594: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80056598: jal         0x80001ACC
    // 0x8005659C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_5;
    // 0x8005659C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_5:
    // 0x800565A0: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x800565A4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_800565A8:
    // 0x800565A8: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x800565AC: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x800565B0: lw          $a2, 0x7CFC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X7CFC);
    // 0x800565B4: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x800565B8: jal         0x80004AAC
    // 0x800565BC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_80004AAC(rdram, ctx);
        goto after_6;
    // 0x800565BC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_6:
    // 0x800565C0: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x800565C4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800565C8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x800565CC: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x800565D0: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x800565D4: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x800565D8: jal         0x80004E70
    // 0x800565DC: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    func_80004E70(rdram, ctx);
        goto after_7;
    // 0x800565DC: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    after_7:
    // 0x800565E0: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x800565E4: jal         0x80004C70
    // 0x800565E8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_80004C70(rdram, ctx);
        goto after_8;
    // 0x800565E8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_8:
    // 0x800565EC: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x800565F0: lw          $a0, 0xC0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XC0);
    // 0x800565F4: jal         0x800076F8
    // 0x800565F8: addiu       $a1, $a1, -0x5278
    ctx->r5 = ADD32(ctx->r5, -0X5278);
    rs_strcmp(rdram, ctx);
        goto after_9;
    // 0x800565F8: addiu       $a1, $a1, -0x5278
    ctx->r5 = ADD32(ctx->r5, -0X5278);
    after_9:
    // 0x800565FC: bne         $v0, $zero, L_80056618
    if (ctx->r2 != 0) {
        // 0x80056600: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_80056618;
    }
    // 0x80056600: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80056604: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80056608: lw          $a2, 0xB68($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XB68);
    // 0x8005660C: jal         0x8006AFC0
    // 0x80056610: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    decrypt_ns_hmt(rdram, ctx);
        goto after_10;
    // 0x80056610: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_10:
    // 0x80056614: sw          $zero, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = 0;
L_80056618:
    // 0x80056618: lw          $v0, 0x4($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X4);
    // 0x8005661C: beq         $v0, $zero, L_800566E0
    if (ctx->r2 == 0) {
        // 0x80056620: nop
    
            goto L_800566E0;
    }
    // 0x80056620: nop

    // 0x80056624: addu        $s6, $s3, $v0
    ctx->r22 = ADD32(ctx->r19, ctx->r2);
    // 0x80056628: sw          $s6, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r22;
    // 0x8005662C: lhu         $v0, 0x0($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X0);
    // 0x80056630: beq         $v0, $zero, L_800566E0
    if (ctx->r2 == 0) {
        // 0x80056634: sw          $zero, 0x78($sp)
        MEM_W(0X78, ctx->r29) = 0;
            goto L_800566E0;
    }
    // 0x80056634: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
    // 0x80056638: andi        $fp, $s4, 0x2
    ctx->r30 = ctx->r20 & 0X2;
    // 0x8005663C: andi        $s7, $s4, 0x4
    ctx->r23 = ctx->r20 & 0X4;
    // 0x80056640: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
    // 0x80056644: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80056648: addu        $s1, $s6, $zero
    ctx->r17 = ADD32(ctx->r22, 0);
L_8005664C:
    // 0x8005664C: lw          $v0, 0x24($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X24);
    // 0x80056650: beq         $v0, $zero, L_8005665C
    if (ctx->r2 == 0) {
        // 0x80056654: addu        $v0, $v0, $s3
        ctx->r2 = ADD32(ctx->r2, ctx->r19);
            goto L_8005665C;
    }
    // 0x80056654: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80056658: sw          $v0, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r2;
L_8005665C:
    // 0x8005665C: lw          $v0, 0x28($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X28);
    // 0x80056660: beq         $v0, $zero, L_8005666C
    if (ctx->r2 == 0) {
        // 0x80056664: addu        $v0, $v0, $s3
        ctx->r2 = ADD32(ctx->r2, ctx->r19);
            goto L_8005666C;
    }
    // 0x80056664: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80056668: sw          $v0, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r2;
L_8005666C:
    // 0x8005666C: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x80056670: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_80056674:
    // 0x80056674: addu        $v1, $s6, $a0
    ctx->r3 = ADD32(ctx->r22, ctx->r4);
    // 0x80056678: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8005667C: beq         $v0, $zero, L_8005668C
    if (ctx->r2 == 0) {
        // 0x80056680: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_8005668C;
    }
    // 0x80056680: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80056684: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80056688: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_8005668C:
    // 0x8005668C: slti        $v0, $s4, 0x8
    ctx->r2 = SIGNED(ctx->r20) < 0X8 ? 1 : 0;
    // 0x80056690: bne         $v0, $zero, L_80056674
    if (ctx->r2 != 0) {
        // 0x80056694: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80056674;
    }
    // 0x80056694: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80056698: beql        $fp, $zero, L_800566C0
    if (ctx->r30 == 0) {
        // 0x8005669C: addiu       $s5, $s5, 0x34
        ctx->r21 = ADD32(ctx->r21, 0X34);
            goto L_800566C0;
    }
    goto skip_2;
    // 0x8005669C: addiu       $s5, $s5, 0x34
    ctx->r21 = ADD32(ctx->r21, 0X34);
    skip_2:
    // 0x800566A0: addu        $s0, $s6, $s5
    ctx->r16 = ADD32(ctx->r22, ctx->r21);
    // 0x800566A4: jal         0x8007A260
    // 0x800566A8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8007A260(rdram, ctx);
        goto after_11;
    // 0x800566A8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_11:
    // 0x800566AC: beql        $s7, $zero, L_800566C0
    if (ctx->r23 == 0) {
        // 0x800566B0: addiu       $s5, $s5, 0x34
        ctx->r21 = ADD32(ctx->r21, 0X34);
            goto L_800566C0;
    }
    goto skip_3;
    // 0x800566B0: addiu       $s5, $s5, 0x34
    ctx->r21 = ADD32(ctx->r21, 0X34);
    skip_3:
    // 0x800566B4: jal         0x8007A260
    // 0x800566B8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8007A260(rdram, ctx);
        goto after_12;
    // 0x800566B8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_12:
    // 0x800566BC: addiu       $s5, $s5, 0x34
    ctx->r21 = ADD32(ctx->r21, 0X34);
L_800566C0:
    // 0x800566C0: addiu       $s2, $s2, 0x34
    ctx->r18 = ADD32(ctx->r18, 0X34);
    // 0x800566C4: addiu       $s1, $s1, 0x34
    ctx->r17 = ADD32(ctx->r17, 0X34);
    // 0x800566C8: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x800566CC: lhu         $v0, 0x0($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X0);
    // 0x800566D0: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800566D4: slt         $v0, $t0, $v0
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800566D8: bne         $v0, $zero, L_8005664C
    if (ctx->r2 != 0) {
        // 0x800566DC: sw          $t0, 0x78($sp)
        MEM_W(0X78, ctx->r29) = ctx->r8;
            goto L_8005664C;
    }
    // 0x800566DC: sw          $t0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r8;
L_800566E0:
    // 0x800566E0: lhu         $v0, 0x0($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X0);
    // 0x800566E4: beq         $v0, $zero, L_80056D74
    if (ctx->r2 == 0) {
        // 0x800566E8: addu        $a0, $v0, $zero
        ctx->r4 = ADD32(ctx->r2, 0);
            goto L_80056D74;
    }
    // 0x800566E8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800566EC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800566F0: jal         0x80001ACC
    // 0x800566F4: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    rs_malloc(rdram, ctx);
        goto after_13;
    // 0x800566F4: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    after_13:
    // 0x800566F8: bne         $v0, $zero, L_80056714
    if (ctx->r2 != 0) {
        // 0x800566FC: sw          $v0, 0x74($sp)
        MEM_W(0X74, ctx->r29) = ctx->r2;
            goto L_80056714;
    }
    // 0x800566FC: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x80056700: lhu         $a0, 0x0($s3)
    ctx->r4 = MEM_HU(ctx->r19, 0X0);
    // 0x80056704: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80056708: jal         0x80001ACC
    // 0x8005670C: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    rs_malloc(rdram, ctx);
        goto after_14;
    // 0x8005670C: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    after_14:
    // 0x80056710: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
L_80056714:
    // 0x80056714: lhu         $v0, 0x0($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X0);
    // 0x80056718: beq         $v0, $zero, L_80056798
    if (ctx->r2 == 0) {
        // 0x8005671C: sw          $zero, 0x78($sp)
        MEM_W(0X78, ctx->r29) = 0;
            goto L_80056798;
    }
    // 0x8005671C: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
    // 0x80056720: lw          $s2, 0x74($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X74);
    // 0x80056724: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
    // 0x80056728: addu        $s0, $s3, $zero
    ctx->r16 = ADD32(ctx->r19, 0);
L_8005672C:
    // 0x8005672C: lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X8);
    // 0x80056730: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80056734: beq         $v0, $zero, L_80056764
    if (ctx->r2 == 0) {
        // 0x80056738: addu        $a0, $s3, $s1
        ctx->r4 = ADD32(ctx->r19, ctx->r17);
            goto L_80056764;
    }
    // 0x80056738: addu        $a0, $s3, $s1
    ctx->r4 = ADD32(ctx->r19, ctx->r17);
    // 0x8005673C: lhu         $v0, 0xA($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XA);
    // 0x80056740: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80056744: sll         $a1, $v0, 1
    ctx->r5 = S32(ctx->r2 << 1);
    // 0x80056748: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8005674C: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x80056750: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x80056754: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x80056758: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8005675C: j           L_8005676C
    // 0x80056760: addu        $a1, $s6, $a1
    ctx->r5 = ADD32(ctx->r22, ctx->r5);
        goto L_8005676C;
    // 0x80056760: addu        $a1, $s6, $a1
    ctx->r5 = ADD32(ctx->r22, ctx->r5);
L_80056764:
    // 0x80056764: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80056768: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
L_8005676C:
    // 0x8005676C: jal         0x80022B90
    // 0x80056770: addiu       $s1, $s1, 0x24
    ctx->r17 = ADD32(ctx->r17, 0X24);
    func_80022B90(rdram, ctx);
        goto after_15;
    // 0x80056770: addiu       $s1, $s1, 0x24
    ctx->r17 = ADD32(ctx->r17, 0X24);
    after_15:
    // 0x80056774: sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
    // 0x80056778: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x8005677C: addiu       $s0, $s0, 0x24
    ctx->r16 = ADD32(ctx->r16, 0X24);
    // 0x80056780: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x80056784: lhu         $v0, 0x0($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X0);
    // 0x80056788: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8005678C: slt         $v0, $t0, $v0
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80056790: bne         $v0, $zero, L_8005672C
    if (ctx->r2 != 0) {
        // 0x80056794: sw          $t0, 0x78($sp)
        MEM_W(0X78, ctx->r29) = ctx->r8;
            goto L_8005672C;
    }
    // 0x80056794: sw          $t0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r8;
L_80056798:
    // 0x80056798: jal         0x80001C98
    // 0x8005679C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    rs_free(rdram, ctx);
        goto after_16;
    // 0x8005679C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_16:
    // 0x800567A0: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800567A4: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x800567A8: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x800567AC: jal         0x80033CC4
    // 0x800567B0: addiu       $a1, $a1, -0x5264
    ctx->r5 = ADD32(ctx->r5, -0X5264);
    sprintf_recomp(rdram, ctx);
        goto after_17;
    // 0x800567B0: addiu       $a1, $a1, -0x5264
    ctx->r5 = ADD32(ctx->r5, -0X5264);
    after_17:
    // 0x800567B4: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x800567B8: blez        $t0, L_800567C8
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800567BC: addiu       $v0, $t0, 0x30
        ctx->r2 = ADD32(ctx->r8, 0X30);
            goto L_800567C8;
    }
    // 0x800567BC: addiu       $v0, $t0, 0x30
    ctx->r2 = ADD32(ctx->r8, 0X30);
    // 0x800567C0: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x800567C4: sb          $v0, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r2;
L_800567C8:
    // 0x800567C8: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800567CC: lw          $a0, 0x7CFC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X7CFC);
    // 0x800567D0: jal         0x80004D5C
    // 0x800567D4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    get_asset_size_extra(rdram, ctx);
        goto after_18;
    // 0x800567D4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_18:
    // 0x800567D8: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x800567DC: lbu         $s3, 0x8F($sp)
    ctx->r19 = MEM_BU(ctx->r29, 0X8F);
    // 0x800567E0: beq         $s3, $zero, L_800567EC
    if (ctx->r19 == 0) {
        // 0x800567E4: addiu       $a1, $zero, 0x10
        ctx->r5 = ADD32(0, 0X10);
            goto L_800567EC;
    }
    // 0x800567E4: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x800567E8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
L_800567EC:
    // 0x800567EC: jal         0x80001ACC
    // 0x800567F0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    rs_malloc(rdram, ctx);
        goto after_19;
    // 0x800567F0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_19:
    // 0x800567F4: bne         $v0, $zero, L_8005680C
    if (ctx->r2 != 0) {
        // 0x800567F8: sw          $v0, 0x68($sp)
        MEM_W(0X68, ctx->r29) = ctx->r2;
            goto L_8005680C;
    }
    // 0x800567F8: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x800567FC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80056800: jal         0x80001ACC
    // 0x80056804: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    rs_malloc(rdram, ctx);
        goto after_20;
    // 0x80056804: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_20:
    // 0x80056808: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
L_8005680C:
    // 0x8005680C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80056810: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80056814: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x80056818: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x8005681C: lw          $a2, 0x7CFC($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X7CFC);
    // 0x80056820: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x80056824: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80056828: sw          $t0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r8;
    // 0x8005682C: jal         0x80004AAC
    // 0x80056830: sw          $t0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r8;
    func_80004AAC(rdram, ctx);
        goto after_21;
    // 0x80056830: sw          $t0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r8;
    after_21:
    // 0x80056834: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80056838: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005683C: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x80056840: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x80056844: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x80056848: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x8005684C: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x80056850: jal         0x80004E70
    // 0x80056854: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    func_80004E70(rdram, ctx);
        goto after_22;
    // 0x80056854: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_22:
    // 0x80056858: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x8005685C: jal         0x80004C70
    // 0x80056860: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_80004C70(rdram, ctx);
        goto after_23;
    // 0x80056860: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_23:
    // 0x80056864: beq         $s3, $zero, L_800568A4
    if (ctx->r19 == 0) {
        // 0x80056868: addiu       $a1, $zero, 0x10
        ctx->r5 = ADD32(0, 0X10);
            goto L_800568A4;
    }
    // 0x80056868: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8005686C: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x80056870: sw          $t0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r8;
    // 0x80056874: lw          $a0, 0x4($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X4);
    // 0x80056878: sw          $t0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r8;
    // 0x8005687C: jal         0x80001ACC
    // 0x80056880: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    rs_malloc(rdram, ctx);
        goto after_24;
    // 0x80056880: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    after_24:
    // 0x80056884: lw          $a1, 0x6C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X6C);
    // 0x80056888: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x8005688C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80056890: lw          $a2, 0x4($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X4);
    // 0x80056894: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x80056898: sw          $t0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r8;
    // 0x8005689C: jal         0x80018EF4
    // 0x800568A0: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    zmemcpy(rdram, ctx);
        goto after_25;
    // 0x800568A0: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    after_25:
L_800568A4:
    // 0x800568A4: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x800568A8: lhu         $v0, 0x0($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X0);
    // 0x800568AC: beq         $v0, $zero, L_80056D50
    if (ctx->r2 == 0) {
        // 0x800568B0: sw          $zero, 0x78($sp)
        MEM_W(0X78, ctx->r29) = 0;
            goto L_80056D50;
    }
    // 0x800568B0: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
    // 0x800568B4: sw          $zero, 0x90($sp)
    MEM_W(0X90, ctx->r29) = 0;
    // 0x800568B8: addu        $s6, $t0, $zero
    ctx->r22 = ADD32(ctx->r8, 0);
L_800568BC:
    // 0x800568BC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800568C0: lw          $v1, -0x7764($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X7764);
    // 0x800568C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800568C8: sh          $v0, 0x40($s6)
    MEM_H(0X40, ctx->r22) = ctx->r2;
    // 0x800568CC: lw          $v0, 0x30($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X30);
    // 0x800568D0: sh          $zero, 0x42($s6)
    MEM_H(0X42, ctx->r22) = 0;
    // 0x800568D4: sw          $v1, 0x44($s6)
    MEM_W(0X44, ctx->r22) = ctx->r3;
    // 0x800568D8: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x800568DC: lw          $v1, 0x34($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X34);
    // 0x800568E0: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x800568E4: addu        $s7, $v1, $t0
    ctx->r23 = ADD32(ctx->r3, ctx->r8);
    // 0x800568E8: sw          $v0, 0x30($s6)
    MEM_W(0X30, ctx->r22) = ctx->r2;
    // 0x800568EC: sw          $s7, 0x34($s6)
    MEM_W(0X34, ctx->r22) = ctx->r23;
    // 0x800568F0: lw          $v0, 0x0($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X0);
    // 0x800568F4: beq         $v0, $zero, L_8005691C
    if (ctx->r2 == 0) {
        // 0x800568F8: addu        $v1, $s7, $zero
        ctx->r3 = ADD32(ctx->r23, 0);
            goto L_8005691C;
    }
    // 0x800568F8: addu        $v1, $s7, $zero
    ctx->r3 = ADD32(ctx->r23, 0);
L_800568FC:
    // 0x800568FC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80056900: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x80056904: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x80056908: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8005690C: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x80056910: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80056914: bne         $v0, $zero, L_800568FC
    if (ctx->r2 != 0) {
        // 0x80056918: nop
    
            goto L_800568FC;
    }
    // 0x80056918: nop

L_8005691C:
    // 0x8005691C: lw          $v0, 0x38($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X38);
    // 0x80056920: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x80056924: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x80056928: sw          $v0, 0x38($s6)
    MEM_W(0X38, ctx->r22) = ctx->r2;
    // 0x8005692C: lw          $v0, 0x60($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X60);
    // 0x80056930: lw          $v1, 0x18($s6)
    ctx->r3 = MEM_W(ctx->r22, 0X18);
    // 0x80056934: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x80056938: beq         $v1, $zero, L_80056948
    if (ctx->r3 == 0) {
        // 0x8005693C: sw          $v0, 0x60($s6)
        MEM_W(0X60, ctx->r22) = ctx->r2;
            goto L_80056948;
    }
    // 0x8005693C: sw          $v0, 0x60($s6)
    MEM_W(0X60, ctx->r22) = ctx->r2;
    // 0x80056940: addu        $v0, $v1, $t0
    ctx->r2 = ADD32(ctx->r3, ctx->r8);
    // 0x80056944: sw          $v0, 0x18($s6)
    MEM_W(0X18, ctx->r22) = ctx->r2;
L_80056948:
    // 0x80056948: lw          $v0, 0x1C($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X1C);
    // 0x8005694C: beq         $v0, $zero, L_800569B4
    if (ctx->r2 == 0) {
        // 0x80056950: addu        $s5, $zero, $zero
        ctx->r21 = ADD32(0, 0);
            goto L_800569B4;
    }
    // 0x80056950: addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
    // 0x80056954: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x80056958: addu        $a0, $v0, $t0
    ctx->r4 = ADD32(ctx->r2, ctx->r8);
    // 0x8005695C: sw          $a0, 0x1C($s6)
    MEM_W(0X1C, ctx->r22) = ctx->r4;
    // 0x80056960: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80056964: beq         $v0, $zero, L_80056994
    if (ctx->r2 == 0) {
        // 0x80056968: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_80056994;
    }
    // 0x80056968: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8005696C: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
L_80056970:
    // 0x80056970: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x80056974: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x80056978: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8005697C: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x80056980: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x80056984: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x80056988: slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8005698C: bne         $v0, $zero, L_80056970
    if (ctx->r2 != 0) {
        // 0x80056990: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_80056970;
    }
    // 0x80056990: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_80056994:
    // 0x80056994: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x80056998: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8005699C: ori         $v1, $v1, 0x1
    ctx->r3 = ctx->r3 | 0X1;
    // 0x800569A0: beq         $v0, $v1, L_800569B4
    if (ctx->r2 == ctx->r3) {
        // 0x800569A4: addu        $s5, $zero, $zero
        ctx->r21 = ADD32(0, 0);
            goto L_800569B4;
    }
    // 0x800569A4: addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
    // 0x800569A8: lhu         $v0, 0x40($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X40);
    // 0x800569AC: andi        $v0, $v0, 0xFFFE
    ctx->r2 = ctx->r2 & 0XFFFE;
    // 0x800569B0: sh          $v0, 0x40($s6)
    MEM_H(0X40, ctx->r22) = ctx->r2;
L_800569B4:
    // 0x800569B4: lw          $fp, 0x90($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X90);
L_800569B8:
    // 0x800569B8: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x800569BC: addu        $v1, $t0, $fp
    ctx->r3 = ADD32(ctx->r8, ctx->r30);
    // 0x800569C0: lw          $v0, 0x20($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X20);
    // 0x800569C4: beql        $v0, $zero, L_80056A90
    if (ctx->r2 == 0) {
        // 0x800569C8: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_80056A90;
    }
    goto skip_4;
    // 0x800569C8: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    skip_4:
    // 0x800569CC: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x800569D0: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x800569D4: addu        $s3, $v0, $t0
    ctx->r19 = ADD32(ctx->r2, ctx->r8);
    // 0x800569D8: sw          $s3, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r19;
    // 0x800569DC: lhu         $v0, 0x0($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X0);
    // 0x800569E0: beq         $v0, $zero, L_80056A8C
    if (ctx->r2 == 0) {
        // 0x800569E4: addu        $s1, $s4, $zero
        ctx->r17 = ADD32(ctx->r20, 0);
            goto L_80056A8C;
    }
    // 0x800569E4: addu        $s1, $s4, $zero
    ctx->r17 = ADD32(ctx->r20, 0);
    // 0x800569E8: addu        $s2, $s3, $zero
    ctx->r18 = ADD32(ctx->r19, 0);
L_800569EC:
    // 0x800569EC: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x800569F0: beq         $v0, $zero, L_80056A74
    if (ctx->r2 == 0) {
        // 0x800569F4: sll         $v0, $s1, 2
        ctx->r2 = S32(ctx->r17 << 2);
            goto L_80056A74;
    }
    // 0x800569F4: sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17 << 2);
    // 0x800569F8: addu        $s0, $v0, $s3
    ctx->r16 = ADD32(ctx->r2, ctx->r19);
    // 0x800569FC: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
L_80056A00:
    // 0x80056A00: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x80056A04: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x80056A08: blez        $s5, L_80056A60
    if (SIGNED(ctx->r21) <= 0) {
        // 0x80056A0C: sw          $v0, 0x4($s0)
        MEM_W(0X4, ctx->r16) = ctx->r2;
            goto L_80056A60;
    }
    // 0x80056A0C: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x80056A10: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    // 0x80056A14: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    // 0x80056A18: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80056A1C: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    // 0x80056A20: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x80056A24: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
    // 0x80056A28: jal         0x800587F0
    // 0x80056A2C: nop

    meshdef1_offset_convert(rdram, ctx);
        goto after_26;
    // 0x80056A2C: nop

    after_26:
    // 0x80056A30: lw          $t0, 0xC4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC4);
    // 0x80056A34: beq         $t0, $zero, L_80056A48
    if (ctx->r8 == 0) {
        // 0x80056A38: nop
    
            goto L_80056A48;
    }
    // 0x80056A38: nop

    // 0x80056A3C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x80056A40: jal         0x80058B40
    // 0x80056A44: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    func_80058B40(rdram, ctx);
        goto after_27;
    // 0x80056A44: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    after_27:
L_80056A48:
    // 0x80056A48: lw          $t0, 0xCC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XCC);
    // 0x80056A4C: beq         $t0, $zero, L_80056A60
    if (ctx->r8 == 0) {
        // 0x80056A50: addu        $a1, $t0, $zero
        ctx->r5 = ADD32(ctx->r8, 0);
            goto L_80056A60;
    }
    // 0x80056A50: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // 0x80056A54: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x80056A58: jal         0x800599C0
    // 0x80056A5C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_800599C0(rdram, ctx);
        goto after_28;
    // 0x80056A5C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_28:
L_80056A60:
    // 0x80056A60: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80056A64: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80056A68: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80056A6C: bne         $v0, $zero, L_80056A00
    if (ctx->r2 != 0) {
        // 0x80056A70: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80056A00;
    }
    // 0x80056A70: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80056A74:
    // 0x80056A74: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80056A78: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80056A7C: lhu         $v0, 0x0($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X0);
    // 0x80056A80: slt         $v0, $s4, $v0
    ctx->r2 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80056A84: bne         $v0, $zero, L_800569EC
    if (ctx->r2 != 0) {
        // 0x80056A88: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800569EC;
    }
    // 0x80056A88: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80056A8C:
    // 0x80056A8C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
L_80056A90:
    // 0x80056A90: slti        $v0, $s5, 0x4
    ctx->r2 = SIGNED(ctx->r21) < 0X4 ? 1 : 0;
    // 0x80056A94: bne         $v0, $zero, L_800569B8
    if (ctx->r2 != 0) {
        // 0x80056A98: addiu       $fp, $fp, 0x4
        ctx->r30 = ADD32(ctx->r30, 0X4);
            goto L_800569B8;
    }
    // 0x80056A98: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x80056A9C: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    // 0x80056AA0: lw          $a2, 0x84($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X84);
    // 0x80056AA4: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
    // 0x80056AA8: lw          $a0, 0x18($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X18);
    // 0x80056AAC: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
    // 0x80056AB0: jal         0x80058948
    // 0x80056AB4: nop

    meshdef0_offset_convert(rdram, ctx);
        goto after_29;
    // 0x80056AB4: nop

    after_29:
    // 0x80056AB8: lw          $t0, 0xCC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XCC);
    // 0x80056ABC: beq         $t0, $zero, L_80056AD0
    if (ctx->r8 == 0) {
        // 0x80056AC0: addu        $a1, $t0, $zero
        ctx->r5 = ADD32(ctx->r8, 0);
            goto L_80056AD0;
    }
    // 0x80056AC0: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    // 0x80056AC4: lw          $a0, 0x18($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X18);
    // 0x80056AC8: jal         0x800599EC
    // 0x80056ACC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_800599EC(rdram, ctx);
        goto after_30;
    // 0x80056ACC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_30:
L_80056AD0:
    // 0x80056AD0: lw          $t0, 0xC4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC4);
    // 0x80056AD4: beq         $t0, $zero, L_80056AE8
    if (ctx->r8 == 0) {
        // 0x80056AD8: nop
    
            goto L_80056AE8;
    }
    // 0x80056AD8: nop

    // 0x80056ADC: lw          $a0, 0x18($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X18);
    // 0x80056AE0: jal         0x800596C4
    // 0x80056AE4: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    func_800596C4(rdram, ctx);
        goto after_31;
    // 0x80056AE4: addu        $a1, $t0, $zero
    ctx->r5 = ADD32(ctx->r8, 0);
    after_31:
L_80056AE8:
    // 0x80056AE8: lw          $v0, 0x24($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X24);
    // 0x80056AEC: beq         $v0, $zero, L_80056B00
    if (ctx->r2 == 0) {
        // 0x80056AF0: lui         $a1, 0x1
        ctx->r5 = S32(0X1 << 16);
            goto L_80056B00;
    }
    // 0x80056AF0: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x80056AF4: lw          $a0, 0x18($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X18);
    // 0x80056AF8: jal         0x800599EC
    // 0x80056AFC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_800599EC(rdram, ctx);
        goto after_32;
    // 0x80056AFC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_32:
L_80056B00:
    // 0x80056B00: lbu         $v0, 0x8F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X8F);
    // 0x80056B04: beql        $v0, $zero, L_80056C58
    if (ctx->r2 == 0) {
        // 0x80056B08: addu        $s4, $zero, $zero
        ctx->r20 = ADD32(0, 0);
            goto L_80056C58;
    }
    goto skip_5;
    // 0x80056B08: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    skip_5:
    // 0x80056B0C: lw          $s1, 0x18($s6)
    ctx->r17 = MEM_W(ctx->r22, 0X18);
    // 0x80056B10: beq         $s1, $zero, L_80056BAC
    if (ctx->r17 == 0) {
        // 0x80056B14: nop
    
            goto L_80056BAC;
    }
    // 0x80056B14: nop

L_80056B18:
    // 0x80056B18: lw          $a0, 0x10($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X10);
    // 0x80056B1C: beq         $a0, $zero, L_80056B8C
    if (ctx->r4 == 0) {
        // 0x80056B20: nop
    
            goto L_80056B8C;
    }
    // 0x80056B20: nop

    // 0x80056B24: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
L_80056B28:
    // 0x80056B28: lw          $v0, 0x0($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X0);
    // 0x80056B2C: beq         $v0, $zero, L_80056B70
    if (ctx->r2 == 0) {
        // 0x80056B30: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80056B70;
    }
    // 0x80056B30: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80056B34: addu        $v1, $s7, $zero
    ctx->r3 = ADD32(ctx->r23, 0);
    // 0x80056B38: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
L_80056B3C:
    // 0x80056B3C: beq         $s0, $v0, L_80056B58
    if (ctx->r16 == ctx->r2) {
        // 0x80056B40: sll         $v0, $a0, 1
        ctx->r2 = S32(ctx->r4 << 1);
            goto L_80056B58;
    }
    // 0x80056B40: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x80056B44: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x80056B48: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80056B4C: bne         $v0, $zero, L_80056B3C
    if (ctx->r2 != 0) {
        // 0x80056B50: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80056B3C;
    }
    // 0x80056B50: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80056B54: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
L_80056B58:
    // 0x80056B58: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80056B5C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80056B60: addu        $v0, $v0, $s7
    ctx->r2 = ADD32(ctx->r2, ctx->r23);
    // 0x80056B64: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80056B68: bne         $v0, $zero, L_80056B80
    if (ctx->r2 != 0) {
        // 0x80056B6C: nop
    
            goto L_80056B80;
    }
    // 0x80056B6C: nop

L_80056B70:
    // 0x80056B70: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80056B74: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80056B78: jal         0x80014DE0
    // 0x80056B7C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    func_80014DE0(rdram, ctx);
        goto after_33;
    // 0x80056B7C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_33:
L_80056B80:
    // 0x80056B80: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x80056B84: bne         $s0, $zero, L_80056B28
    if (ctx->r16 != 0) {
        // 0x80056B88: nop
    
            goto L_80056B28;
    }
    // 0x80056B88: nop

L_80056B8C:
    // 0x80056B8C: lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC);
    // 0x80056B90: beq         $a0, $zero, L_80056BA0
    if (ctx->r4 == 0) {
        // 0x80056B94: nop
    
            goto L_80056BA0;
    }
    // 0x80056B94: nop

    // 0x80056B98: jal         0x80059A80
    // 0x80056B9C: addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    func_80059A80(rdram, ctx);
        goto after_34;
    // 0x80056B9C: addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    after_34:
L_80056BA0:
    // 0x80056BA0: lw          $s1, 0x0($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X0);
    // 0x80056BA4: bne         $s1, $zero, L_80056B18
    if (ctx->r17 != 0) {
        // 0x80056BA8: nop
    
            goto L_80056B18;
    }
    // 0x80056BA8: nop

L_80056BAC:
    // 0x80056BAC: lw          $t0, 0x90($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X90);
    // 0x80056BB0: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x80056BB4: addiu       $s7, $t0, 0x4
    ctx->r23 = ADD32(ctx->r8, 0X4);
L_80056BB8:
    // 0x80056BB8: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x80056BBC: addu        $v0, $t0, $s7
    ctx->r2 = ADD32(ctx->r8, ctx->r23);
    // 0x80056BC0: lw          $v0, 0x20($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X20);
    // 0x80056BC4: beql        $v0, $zero, L_80056C34
    if (ctx->r2 == 0) {
        // 0x80056BC8: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_80056C34;
    }
    goto skip_6;
    // 0x80056BC8: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    skip_6:
    // 0x80056BCC: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x80056BD0: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x80056BD4: lhu         $v0, 0x0($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X0);
    // 0x80056BD8: beq         $v0, $zero, L_80056C30
    if (ctx->r2 == 0) {
        // 0x80056BDC: addu        $s1, $s4, $zero
        ctx->r17 = ADD32(ctx->r20, 0);
            goto L_80056C30;
    }
    // 0x80056BDC: addu        $s1, $s4, $zero
    ctx->r17 = ADD32(ctx->r20, 0);
    // 0x80056BE0: addu        $s2, $s3, $zero
    ctx->r18 = ADD32(ctx->r19, 0);
L_80056BE4:
    // 0x80056BE4: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x80056BE8: beq         $v0, $zero, L_80056C18
    if (ctx->r2 == 0) {
        // 0x80056BEC: sll         $v0, $s1, 2
        ctx->r2 = S32(ctx->r17 << 2);
            goto L_80056C18;
    }
    // 0x80056BEC: sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17 << 2);
    // 0x80056BF0: addu        $s0, $v0, $s3
    ctx->r16 = ADD32(ctx->r2, ctx->r19);
L_80056BF4:
    // 0x80056BF4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80056BF8: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80056BFC: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x80056C00: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80056C04: jal         0x80014DE0
    // 0x80056C08: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    func_80014DE0(rdram, ctx);
        goto after_35;
    // 0x80056C08: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    after_35:
    // 0x80056C0C: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80056C10: bne         $v0, $zero, L_80056BF4
    if (ctx->r2 != 0) {
        // 0x80056C14: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80056BF4;
    }
    // 0x80056C14: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80056C18:
    // 0x80056C18: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80056C1C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80056C20: lhu         $v0, 0x0($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X0);
    // 0x80056C24: slt         $v0, $s4, $v0
    ctx->r2 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80056C28: bne         $v0, $zero, L_80056BE4
    if (ctx->r2 != 0) {
        // 0x80056C2C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80056BE4;
    }
    // 0x80056C2C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80056C30:
    // 0x80056C30: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
L_80056C34:
    // 0x80056C34: slti        $v0, $s5, 0x4
    ctx->r2 = SIGNED(ctx->r21) < 0X4 ? 1 : 0;
    // 0x80056C38: bne         $v0, $zero, L_80056BB8
    if (ctx->r2 != 0) {
        // 0x80056C3C: addiu       $s7, $s7, 0x4
        ctx->r23 = ADD32(ctx->r23, 0X4);
            goto L_80056BB8;
    }
    // 0x80056C3C: addiu       $s7, $s7, 0x4
    ctx->r23 = ADD32(ctx->r23, 0X4);
    // 0x80056C40: lhu         $v1, 0x40($s6)
    ctx->r3 = MEM_HU(ctx->r22, 0X40);
    // 0x80056C44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80056C48: sh          $v0, 0x42($s6)
    MEM_H(0X42, ctx->r22) = ctx->r2;
    // 0x80056C4C: ori         $v1, $v1, 0x2
    ctx->r3 = ctx->r3 | 0X2;
    // 0x80056C50: sh          $v1, 0x40($s6)
    MEM_H(0X40, ctx->r22) = ctx->r3;
    // 0x80056C54: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
L_80056C58:
    // 0x80056C58: addu        $s1, $s4, $zero
    ctx->r17 = ADD32(ctx->r20, 0);
    // 0x80056C5C: lw          $a2, 0x90($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X90);
    // 0x80056C60: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x80056C64: addu        $v0, $s1, $a2
    ctx->r2 = ADD32(ctx->r17, ctx->r6);
L_80056C68:
    // 0x80056C68: addu        $v1, $t0, $v0
    ctx->r3 = ADD32(ctx->r8, ctx->r2);
    // 0x80056C6C: lbu         $v0, 0x8($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X8);
    // 0x80056C70: beq         $v0, $zero, L_80056C88
    if (ctx->r2 == 0) {
        // 0x80056C74: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80056C88;
    }
    // 0x80056C74: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80056C78: addu        $s4, $s4, $v0
    ctx->r20 = ADD32(ctx->r20, ctx->r2);
    // 0x80056C7C: slti        $v0, $s1, 0x10
    ctx->r2 = SIGNED(ctx->r17) < 0X10 ? 1 : 0;
    // 0x80056C80: bne         $v0, $zero, L_80056C68
    if (ctx->r2 != 0) {
        // 0x80056C84: addu        $v0, $s1, $a2
        ctx->r2 = ADD32(ctx->r17, ctx->r6);
            goto L_80056C68;
    }
    // 0x80056C84: addu        $v0, $s1, $a2
    ctx->r2 = ADD32(ctx->r17, ctx->r6);
L_80056C88:
    // 0x80056C88: lui         $v0, 0x51EB
    ctx->r2 = S32(0X51EB << 16);
    // 0x80056C8C: ori         $v0, $v0, 0x851F
    ctx->r2 = ctx->r2 | 0X851F;
    // 0x80056C90: mult        $s4, $v0
    result = S64(S32(ctx->r20)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80056C94: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80056C98: sra         $v0, $s4, 31
    ctx->r2 = S32(SIGNED(ctx->r20) >> 31);
    // 0x80056C9C: lhu         $s1, -0x6B60($t0)
    ctx->r17 = MEM_HU(ctx->r8, -0X6B60);
    // 0x80056CA0: mfhi        $t0
    ctx->r8 = hi;
    // 0x80056CA4: sra         $v1, $t0, 3
    ctx->r3 = S32(SIGNED(ctx->r8) >> 3);
    // 0x80056CA8: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80056CAC: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80056CB0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80056CB4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80056CB8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80056CBC: subu        $s4, $s4, $v0
    ctx->r20 = SUB32(ctx->r20, ctx->r2);
    // 0x80056CC0: sll         $v0, $s1, 1
    ctx->r2 = S32(ctx->r17 << 1);
    // 0x80056CC4: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x80056CC8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80056CCC: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80056CD0: addiu       $t0, $t0, -0x6FE0
    ctx->r8 = ADD32(ctx->r8, -0X6FE0);
    // 0x80056CD4: addu        $a1, $v0, $t0
    ctx->r5 = ADD32(ctx->r2, ctx->r8);
    // 0x80056CD8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80056CDC: addiu       $v0, $v0, -0x6B50
    ctx->r2 = ADD32(ctx->r2, -0X6B50);
    // 0x80056CE0: sll         $v1, $s4, 1
    ctx->r3 = S32(ctx->r20 << 1);
    // 0x80056CE4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80056CE8: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x80056CEC: lhu         $a0, 0x0($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X0);
    // 0x80056CF0: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80056CF4: sh          $v0, -0x6B60($t0)
    MEM_H(-0X6B60, ctx->r8) = ctx->r2;
    // 0x80056CF8: sh          $a0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r4;
    // 0x80056CFC: sh          $s1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r17;
    // 0x80056D00: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x80056D04: addiu       $v0, $a2, 0x8
    ctx->r2 = ADD32(ctx->r6, 0X8);
    // 0x80056D08: addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // 0x80056D0C: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    // 0x80056D10: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x80056D14: bnel        $t0, $zero, L_80056D24
    if (ctx->r8 != 0) {
        // 0x80056D18: sw          $zero, 0x8($a1)
        MEM_W(0X8, ctx->r5) = 0;
            goto L_80056D24;
    }
    goto skip_7;
    // 0x80056D18: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
    skip_7:
    // 0x80056D1C: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x80056D20: sw          $t0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r8;
L_80056D24:
    // 0x80056D24: lw          $t0, 0x90($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X90);
    // 0x80056D28: addiu       $t0, $t0, 0x74
    ctx->r8 = ADD32(ctx->r8, 0X74);
    // 0x80056D2C: sw          $t0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r8;
    // 0x80056D30: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x80056D34: lhu         $v0, 0x0($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X0);
    // 0x80056D38: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x80056D3C: addiu       $s6, $s6, 0x74
    ctx->r22 = ADD32(ctx->r22, 0X74);
    // 0x80056D40: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80056D44: slt         $v0, $t0, $v0
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80056D48: bne         $v0, $zero, L_800568BC
    if (ctx->r2 != 0) {
        // 0x80056D4C: sw          $t0, 0x78($sp)
        MEM_W(0X78, ctx->r29) = ctx->r8;
            goto L_800568BC;
    }
    // 0x80056D4C: sw          $t0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r8;
L_80056D50:
    // 0x80056D50: lbu         $v0, 0x8F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X8F);
    // 0x80056D54: beq         $v0, $zero, L_80056D68
    if (ctx->r2 == 0) {
        // 0x80056D58: nop
    
            goto L_80056D68;
    }
    // 0x80056D58: nop

    // 0x80056D5C: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x80056D60: jal         0x80001C98
    // 0x80056D64: nop

    rs_free(rdram, ctx);
        goto after_36;
    // 0x80056D64: nop

    after_36:
L_80056D68:
    // 0x80056D68: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x80056D6C: jal         0x80001C98
    // 0x80056D70: nop

    rs_free(rdram, ctx);
        goto after_37;
    // 0x80056D70: nop

    after_37:
L_80056D74:
    // 0x80056D74: lw          $ra, 0xBC($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XBC);
    // 0x80056D78: lw          $fp, 0xB8($sp)
    ctx->r30 = MEM_W(ctx->r29, 0XB8);
    // 0x80056D7C: lw          $s7, 0xB4($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XB4);
    // 0x80056D80: lw          $s6, 0xB0($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XB0);
    // 0x80056D84: lw          $s5, 0xAC($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XAC);
    // 0x80056D88: lw          $s4, 0xA8($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XA8);
    // 0x80056D8C: lw          $s3, 0xA4($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XA4);
    // 0x80056D90: lw          $s2, 0xA0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XA0);
    // 0x80056D94: lw          $s1, 0x9C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X9C);
    // 0x80056D98: lw          $s0, 0x98($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X98);
    // 0x80056D9C: jr          $ra
    // 0x80056DA0: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x80056DA0: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void isHobObjectLoaded(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056DA4: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x80056DA8: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    // 0x80056DAC: beq         $v0, $zero, L_80056DC8
    if (ctx->r2 == 0) {
        // 0x80056DB0: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_80056DC8;
    }
    // 0x80056DB0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80056DB4:
    // 0x80056DB4: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x80056DB8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80056DBC: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80056DC0: bne         $v0, $zero, L_80056DB4
    if (ctx->r2 != 0) {
        // 0x80056DC4: addu        $a1, $a1, $v1
        ctx->r5 = ADD32(ctx->r5, ctx->r3);
            goto L_80056DB4;
    }
    // 0x80056DC4: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
L_80056DC8:
    // 0x80056DC8: lui         $v0, 0x51EB
    ctx->r2 = S32(0X51EB << 16);
    // 0x80056DCC: ori         $v0, $v0, 0x851F
    ctx->r2 = ctx->r2 | 0X851F;
    // 0x80056DD0: mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80056DD4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80056DD8: addiu       $a0, $a0, -0x6B50
    ctx->r4 = ADD32(ctx->r4, -0X6B50);
    // 0x80056DDC: sra         $v0, $a1, 31
    ctx->r2 = S32(SIGNED(ctx->r5) >> 31);
    // 0x80056DE0: mfhi        $t4
    ctx->r12 = hi;
    // 0x80056DE4: sra         $v1, $t4, 3
    ctx->r3 = S32(SIGNED(ctx->r12) >> 3);
    // 0x80056DE8: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80056DEC: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80056DF0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80056DF4: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80056DF8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80056DFC: subu        $v0, $a1, $v0
    ctx->r2 = SUB32(ctx->r5, ctx->r2);
    // 0x80056E00: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80056E04: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80056E08: lhu         $a2, 0x0($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X0);
    // 0x80056E0C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80056E10: beq         $a2, $v0, L_80056EA4
    if (ctx->r6 == ctx->r2) {
        // 0x80056E14: ori         $t3, $zero, 0xFFFF
        ctx->r11 = 0 | 0XFFFF;
            goto L_80056EA4;
    }
    // 0x80056E14: ori         $t3, $zero, 0xFFFF
    ctx->r11 = 0 | 0XFFFF;
    // 0x80056E18: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80056E1C: addiu       $t1, $v0, -0x6FE0
    ctx->r9 = ADD32(ctx->r2, -0X6FE0);
    // 0x80056E20: lbu         $t2, 0x0($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X0);
    // 0x80056E24: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
L_80056E28:
    // 0x80056E28: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80056E2C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80056E30: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x80056E34: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x80056E38: beq         $t2, $zero, L_80056E70
    if (ctx->r10 == 0) {
        // 0x80056E3C: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_80056E70;
    }
    // 0x80056E3C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80056E40: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x80056E44: addu        $v0, $a3, $a1
    ctx->r2 = ADD32(ctx->r7, ctx->r5);
L_80056E48:
    // 0x80056E48: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x80056E4C: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80056E50: bne         $v1, $v0, L_80056E88
    if (ctx->r3 != ctx->r2) {
        // 0x80056E54: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80056E88;
    }
    // 0x80056E54: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80056E58: slti        $v0, $a1, 0x10
    ctx->r2 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x80056E5C: beq         $v0, $zero, L_80056E70
    if (ctx->r2 == 0) {
        // 0x80056E60: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80056E70;
    }
    // 0x80056E60: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80056E64: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80056E68: bne         $v0, $zero, L_80056E48
    if (ctx->r2 != 0) {
        // 0x80056E6C: addu        $v0, $a3, $a1
        ctx->r2 = ADD32(ctx->r7, ctx->r5);
            goto L_80056E48;
    }
    // 0x80056E6C: addu        $v0, $a3, $a1
    ctx->r2 = ADD32(ctx->r7, ctx->r5);
L_80056E70:
    // 0x80056E70: addu        $v0, $t0, $a1
    ctx->r2 = ADD32(ctx->r8, ctx->r5);
    // 0x80056E74: addu        $v1, $a3, $a1
    ctx->r3 = ADD32(ctx->r7, ctx->r5);
    // 0x80056E78: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x80056E7C: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80056E80: beq         $a0, $v0, L_80056EA8
    if (ctx->r4 == ctx->r2) {
        // 0x80056E84: xori        $v0, $a2, 0xFFFF
        ctx->r2 = ctx->r6 ^ 0XFFFF;
            goto L_80056EA8;
    }
    // 0x80056E84: xori        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 ^ 0XFFFF;
L_80056E88:
    // 0x80056E88: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x80056E8C: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80056E90: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80056E94: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x80056E98: lhu         $a2, 0x0($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X0);
    // 0x80056E9C: bnel        $a2, $t3, L_80056E28
    if (ctx->r6 != ctx->r11) {
        // 0x80056EA0: sll         $v0, $a2, 1
        ctx->r2 = S32(ctx->r6 << 1);
            goto L_80056E28;
    }
    goto skip_0;
    // 0x80056EA0: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    skip_0:
L_80056EA4:
    // 0x80056EA4: xori        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 ^ 0XFFFF;
L_80056EA8:
    // 0x80056EA8: jr          $ra
    // 0x80056EAC: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    return;
    // 0x80056EAC: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
;}
RECOMP_FUNC void func_80056EB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80056EB0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80056EB4: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x80056EB8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80056EBC: sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // 0x80056EC0: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x80056EC4: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x80056EC8: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x80056ECC: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x80056ED0: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80056ED4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80056ED8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80056EDC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80056EE0: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
    // 0x80056EE4: beq         $v0, $zero, L_80056F00
    if (ctx->r2 == 0) {
        // 0x80056EE8: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_80056F00;
    }
    // 0x80056EE8: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_80056EEC:
    // 0x80056EEC: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x80056EF0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80056EF4: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80056EF8: bne         $v0, $zero, L_80056EEC
    if (ctx->r2 != 0) {
        // 0x80056EFC: addu        $s1, $s1, $v1
        ctx->r17 = ADD32(ctx->r17, ctx->r3);
            goto L_80056EEC;
    }
    // 0x80056EFC: addu        $s1, $s1, $v1
    ctx->r17 = ADD32(ctx->r17, ctx->r3);
L_80056F00:
    // 0x80056F00: lui         $v0, 0x51EB
    ctx->r2 = S32(0X51EB << 16);
    // 0x80056F04: ori         $v0, $v0, 0x851F
    ctx->r2 = ctx->r2 | 0X851F;
    // 0x80056F08: mult        $s1, $v0
    result = S64(S32(ctx->r17)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80056F0C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80056F10: addiu       $a0, $a0, -0x6B50
    ctx->r4 = ADD32(ctx->r4, -0X6B50);
    // 0x80056F14: sra         $v0, $s1, 31
    ctx->r2 = S32(SIGNED(ctx->r17) >> 31);
    // 0x80056F18: mfhi        $t2
    ctx->r10 = hi;
    // 0x80056F1C: sra         $v1, $t2, 3
    ctx->r3 = S32(SIGNED(ctx->r10) >> 3);
    // 0x80056F20: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80056F24: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80056F28: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80056F2C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80056F30: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80056F34: subu        $v0, $s1, $v0
    ctx->r2 = SUB32(ctx->r17, ctx->r2);
    // 0x80056F38: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80056F3C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80056F40: lhu         $s2, 0x0($v0)
    ctx->r18 = MEM_HU(ctx->r2, 0X0);
    // 0x80056F44: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80056F48: beq         $s2, $v0, L_80057304
    if (ctx->r18 == ctx->r2) {
        // 0x80056F4C: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_80057304;
    }
    // 0x80056F4C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80056F50: addiu       $a3, $v0, -0x6FE0
    ctx->r7 = ADD32(ctx->r2, -0X6FE0);
    // 0x80056F54: lbu         $t0, 0x0($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X0);
    // 0x80056F58: ori         $t1, $zero, 0xFFFF
    ctx->r9 = 0 | 0XFFFF;
    // 0x80056F5C: sll         $v0, $s2, 1
    ctx->r2 = S32(ctx->r18 << 1);
L_80056F60:
    // 0x80056F60: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80056F64: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80056F68: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80056F6C: lw          $a1, 0x4($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X4);
    // 0x80056F70: beq         $t0, $zero, L_80056FA8
    if (ctx->r8 == 0) {
        // 0x80056F74: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_80056FA8;
    }
    // 0x80056F74: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80056F78: addu        $a0, $a2, $zero
    ctx->r4 = ADD32(ctx->r6, 0);
    // 0x80056F7C: addu        $v0, $a1, $s1
    ctx->r2 = ADD32(ctx->r5, ctx->r17);
L_80056F80:
    // 0x80056F80: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x80056F84: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80056F88: bne         $v1, $v0, L_80056FC0
    if (ctx->r3 != ctx->r2) {
        // 0x80056F8C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80056FC0;
    }
    // 0x80056F8C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80056F90: slti        $v0, $s1, 0x10
    ctx->r2 = SIGNED(ctx->r17) < 0X10 ? 1 : 0;
    // 0x80056F94: beq         $v0, $zero, L_80056FA8
    if (ctx->r2 == 0) {
        // 0x80056F98: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80056FA8;
    }
    // 0x80056F98: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80056F9C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80056FA0: bne         $v0, $zero, L_80056F80
    if (ctx->r2 != 0) {
        // 0x80056FA4: addu        $v0, $a1, $s1
        ctx->r2 = ADD32(ctx->r5, ctx->r17);
            goto L_80056F80;
    }
    // 0x80056FA4: addu        $v0, $a1, $s1
    ctx->r2 = ADD32(ctx->r5, ctx->r17);
L_80056FA8:
    // 0x80056FA8: addu        $v0, $a2, $s1
    ctx->r2 = ADD32(ctx->r6, ctx->r17);
    // 0x80056FAC: addu        $v1, $a1, $s1
    ctx->r3 = ADD32(ctx->r5, ctx->r17);
    // 0x80056FB0: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x80056FB4: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80056FB8: beq         $a0, $v0, L_80056FE0
    if (ctx->r4 == ctx->r2) {
        // 0x80056FBC: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_80056FE0;
    }
    // 0x80056FBC: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_80056FC0:
    // 0x80056FC0: sll         $v0, $s2, 1
    ctx->r2 = S32(ctx->r18 << 1);
    // 0x80056FC4: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80056FC8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80056FCC: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x80056FD0: lhu         $s2, 0x0($v0)
    ctx->r18 = MEM_HU(ctx->r2, 0X0);
    // 0x80056FD4: bne         $s2, $t1, L_80056F60
    if (ctx->r18 != ctx->r9) {
        // 0x80056FD8: sll         $v0, $s2, 1
        ctx->r2 = S32(ctx->r18 << 1);
            goto L_80056F60;
    }
    // 0x80056FD8: sll         $v0, $s2, 1
    ctx->r2 = S32(ctx->r18 << 1);
    // 0x80056FDC: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_80056FE0:
    // 0x80056FE0: beq         $s2, $v0, L_80057304
    if (ctx->r18 == ctx->r2) {
        // 0x80056FE4: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_80057304;
    }
    // 0x80056FE4: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80056FE8: addiu       $v1, $v1, -0x6FE0
    ctx->r3 = ADD32(ctx->r3, -0X6FE0);
    // 0x80056FEC: sll         $v0, $s2, 1
    ctx->r2 = S32(ctx->r18 << 1);
    // 0x80056FF0: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x80056FF4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80056FF8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80056FFC: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x80057000: lw          $a0, 0x18($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X18);
    // 0x80057004: lhu         $v0, 0x38($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X38);
    // 0x80057008: lw          $fp, 0x14($v1)
    ctx->r30 = MEM_W(ctx->r3, 0X14);
    // 0x8005700C: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80057010: beq         $v0, $zero, L_8005707C
    if (ctx->r2 == 0) {
        // 0x80057014: addiu       $s4, $a0, 0x4
        ctx->r20 = ADD32(ctx->r4, 0X4);
            goto L_8005707C;
    }
    // 0x80057014: addiu       $s4, $a0, 0x4
    ctx->r20 = ADD32(ctx->r4, 0X4);
    // 0x80057018: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8005701C: lbu         $v1, -0x6AB0($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X6AB0);
    // 0x80057020: beq         $v1, $zero, L_8005707C
    if (ctx->r3 == 0) {
        // 0x80057024: addiu       $v1, $v1, -0x1
        ctx->r3 = ADD32(ctx->r3, -0X1);
            goto L_8005707C;
    }
    // 0x80057024: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80057028: sb          $v1, -0x6AB0($v0)
    MEM_B(-0X6AB0, ctx->r2) = ctx->r3;
    // 0x8005702C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80057030: addiu       $v0, $v0, -0x6B10
    ctx->r2 = ADD32(ctx->r2, -0X6B10);
    // 0x80057034: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x80057038: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8005703C: lbu         $v1, 0x0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X0);
    // 0x80057040: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80057044: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80057048: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005704C: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80057050: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80057054: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80057058: lw          $v0, -0x6B18($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X6B18);
    // 0x8005705C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80057060: addu        $s7, $v0, $v1
    ctx->r23 = ADD32(ctx->r2, ctx->r3);
    // 0x80057064: lw          $v0, -0x6AAC($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X6AAC);
    // 0x80057068: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x8005706C: sh          $v1, 0x8($s7)
    MEM_H(0X8, ctx->r23) = ctx->r3;
    // 0x80057070: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80057074: j           L_800570C4
    // 0x80057078: sw          $v0, -0x6AAC($a0)
    MEM_W(-0X6AAC, ctx->r4) = ctx->r2;
        goto L_800570C4;
    // 0x80057078: sw          $v0, -0x6AAC($a0)
    MEM_W(-0X6AAC, ctx->r4) = ctx->r2;
L_8005707C:
    // 0x8005707C: lhu         $v1, 0x0($fp)
    ctx->r3 = MEM_HU(ctx->r30, 0X0);
    // 0x80057080: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80057084: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80057088: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005708C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80057090: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80057094: lhu         $v1, 0x2($fp)
    ctx->r3 = MEM_HU(ctx->r30, 0X2);
    // 0x80057098: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005709C: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
    // 0x800570A0: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x800570A4: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x800570A8: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x800570AC: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800570B0: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    // 0x800570B4: jal         0x80001ACC
    // 0x800570B8: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x800570B8: addu        $a0, $v0, $a0
    ctx->r4 = ADD32(ctx->r2, ctx->r4);
    after_0:
    // 0x800570BC: addu        $s7, $v0, $zero
    ctx->r23 = ADD32(ctx->r2, 0);
    // 0x800570C0: sh          $zero, 0x8($s7)
    MEM_H(0X8, ctx->r23) = 0;
L_800570C4:
    // 0x800570C4: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800570C8: addiu       $v1, $v1, -0x6FE0
    ctx->r3 = ADD32(ctx->r3, -0X6FE0);
    // 0x800570CC: sll         $v0, $s2, 1
    ctx->r2 = S32(ctx->r18 << 1);
    // 0x800570D0: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x800570D4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800570D8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800570DC: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x800570E0: lhu         $v1, 0x3A($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X3A);
    // 0x800570E4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800570E8: sh          $v1, 0x3A($a0)
    MEM_H(0X3A, ctx->r4) = ctx->r3;
    // 0x800570EC: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x800570F0: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800570F4: sw          $zero, 0x4($s7)
    MEM_W(0X4, ctx->r23) = 0;
    // 0x800570F8: sb          $zero, 0xA($s7)
    MEM_B(0XA, ctx->r23) = 0;
    // 0x800570FC: sb          $zero, 0xB($s7)
    MEM_B(0XB, ctx->r23) = 0;
    // 0x80057100: sw          $v0, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r2;
    // 0x80057104: lhu         $v1, 0x0($fp)
    ctx->r3 = MEM_HU(ctx->r30, 0X0);
    // 0x80057108: addiu       $s6, $s7, 0xC
    ctx->r22 = ADD32(ctx->r23, 0XC);
    // 0x8005710C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80057110: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80057114: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80057118: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8005711C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80057120: lhu         $v1, 0x2($fp)
    ctx->r3 = MEM_HU(ctx->r30, 0X2);
    // 0x80057124: beq         $v1, $zero, L_80057154
    if (ctx->r3 == 0) {
        // 0x80057128: addu        $s3, $s6, $v0
        ctx->r19 = ADD32(ctx->r22, ctx->r2);
            goto L_80057154;
    }
    // 0x80057128: addu        $s3, $s6, $v0
    ctx->r19 = ADD32(ctx->r22, ctx->r2);
    // 0x8005712C: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x80057130: addu        $s0, $s3, $zero
    ctx->r16 = ADD32(ctx->r19, 0);
L_80057134:
    // 0x80057134: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80057138: jal         0x8000A85C
    // 0x8005713C: sw          $s1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r17;
    func_8000A85C(rdram, ctx);
        goto after_1;
    // 0x8005713C: sw          $s1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r17;
    after_1:
    // 0x80057140: lhu         $v0, 0x2($fp)
    ctx->r2 = MEM_HU(ctx->r30, 0X2);
    // 0x80057144: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80057148: slt         $v0, $s2, $v0
    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8005714C: bne         $v0, $zero, L_80057134
    if (ctx->r2 != 0) {
        // 0x80057150: addiu       $s0, $s0, 0x5C
        ctx->r16 = ADD32(ctx->r16, 0X5C);
            goto L_80057134;
    }
    // 0x80057150: addiu       $s0, $s0, 0x5C
    ctx->r16 = ADD32(ctx->r16, 0X5C);
L_80057154:
    // 0x80057154: lhu         $v0, 0x0($fp)
    ctx->r2 = MEM_HU(ctx->r30, 0X0);
    // 0x80057158: beq         $v0, $zero, L_800572FC
    if (ctx->r2 == 0) {
        // 0x8005715C: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_800572FC;
    }
    // 0x8005715C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80057160: addu        $s0, $s6, $zero
    ctx->r16 = ADD32(ctx->r22, 0);
    // 0x80057164: addu        $s5, $fp, $zero
    ctx->r21 = ADD32(ctx->r30, 0);
    // 0x80057168: addiu       $s2, $s3, 0xC
    ctx->r18 = ADD32(ctx->r19, 0XC);
L_8005716C:
    // 0x8005716C: lw          $a0, 0x4($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X4);
    // 0x80057170: lui         $v0, 0x3F00
    ctx->r2 = S32(0X3F00 << 16);
    // 0x80057174: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x80057178: beq         $v0, $zero, L_800571A8
    if (ctx->r2 == 0) {
        // 0x8005717C: srl         $v1, $a0, 24
        ctx->r3 = S32(U32(ctx->r4) >> 24);
            goto L_800571A8;
    }
    // 0x8005717C: srl         $v1, $a0, 24
    ctx->r3 = S32(U32(ctx->r4) >> 24);
    // 0x80057180: andi        $v1, $v1, 0x3F
    ctx->r3 = ctx->r3 & 0X3F;
    // 0x80057184: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80057188: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005718C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80057190: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80057194: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80057198: addiu       $v0, $v0, -0x4C
    ctx->r2 = ADD32(ctx->r2, -0X4C);
    // 0x8005719C: addu        $v0, $s6, $v0
    ctx->r2 = ADD32(ctx->r22, ctx->r2);
    // 0x800571A0: j           L_800571AC
    // 0x800571A4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
        goto L_800571AC;
    // 0x800571A4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
L_800571A8:
    // 0x800571A8: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
L_800571AC:
    // 0x800571AC: lui         $v0, 0xFC
    ctx->r2 = S32(0XFC << 16);
    // 0x800571B0: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x800571B4: beq         $v0, $zero, L_800571E4
    if (ctx->r2 == 0) {
        // 0x800571B8: srl         $v1, $a0, 18
        ctx->r3 = S32(U32(ctx->r4) >> 18);
            goto L_800571E4;
    }
    // 0x800571B8: srl         $v1, $a0, 18
    ctx->r3 = S32(U32(ctx->r4) >> 18);
    // 0x800571BC: andi        $v1, $v1, 0x3F
    ctx->r3 = ctx->r3 & 0X3F;
    // 0x800571C0: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800571C4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800571C8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800571CC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800571D0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800571D4: addiu       $v0, $v0, -0x4C
    ctx->r2 = ADD32(ctx->r2, -0X4C);
    // 0x800571D8: addu        $v0, $s6, $v0
    ctx->r2 = ADD32(ctx->r22, ctx->r2);
    // 0x800571DC: j           L_800571E8
    // 0x800571E0: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
        goto L_800571E8;
    // 0x800571E0: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
L_800571E4:
    // 0x800571E4: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
L_800571E8:
    // 0x800571E8: lui         $v0, 0x3
    ctx->r2 = S32(0X3 << 16);
    // 0x800571EC: ori         $v0, $v0, 0xF000
    ctx->r2 = ctx->r2 | 0XF000;
    // 0x800571F0: and         $v0, $a0, $v0
    ctx->r2 = ctx->r4 & ctx->r2;
    // 0x800571F4: beq         $v0, $zero, L_80057224
    if (ctx->r2 == 0) {
        // 0x800571F8: srl         $v1, $a0, 12
        ctx->r3 = S32(U32(ctx->r4) >> 12);
            goto L_80057224;
    }
    // 0x800571F8: srl         $v1, $a0, 12
    ctx->r3 = S32(U32(ctx->r4) >> 12);
    // 0x800571FC: andi        $v1, $v1, 0x3F
    ctx->r3 = ctx->r3 & 0X3F;
    // 0x80057200: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80057204: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80057208: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005720C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80057210: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80057214: addiu       $v0, $v0, -0x4C
    ctx->r2 = ADD32(ctx->r2, -0X4C);
    // 0x80057218: addu        $v0, $s6, $v0
    ctx->r2 = ADD32(ctx->r22, ctx->r2);
    // 0x8005721C: j           L_80057228
    // 0x80057220: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
        goto L_80057228;
    // 0x80057220: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
L_80057224:
    // 0x80057224: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
L_80057228:
    // 0x80057228: andi        $v0, $a0, 0xFC0
    ctx->r2 = ctx->r4 & 0XFC0;
    // 0x8005722C: beq         $v0, $zero, L_8005725C
    if (ctx->r2 == 0) {
        // 0x80057230: srl         $v1, $a0, 6
        ctx->r3 = S32(U32(ctx->r4) >> 6);
            goto L_8005725C;
    }
    // 0x80057230: srl         $v1, $a0, 6
    ctx->r3 = S32(U32(ctx->r4) >> 6);
    // 0x80057234: andi        $v1, $v1, 0x3F
    ctx->r3 = ctx->r3 & 0X3F;
    // 0x80057238: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8005723C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80057240: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80057244: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80057248: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005724C: addiu       $v0, $v0, -0x4C
    ctx->r2 = ADD32(ctx->r2, -0X4C);
    // 0x80057250: addu        $v0, $s6, $v0
    ctx->r2 = ADD32(ctx->r22, ctx->r2);
    // 0x80057254: j           L_80057260
    // 0x80057258: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
        goto L_80057260;
    // 0x80057258: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
L_8005725C:
    // 0x8005725C: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
L_80057260:
    // 0x80057260: lw          $a1, 0x8($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X8);
    // 0x80057264: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x80057268: lw          $v0, 0x14($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X14);
    // 0x8005726C: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x80057270: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x80057274: lw          $v0, 0x18($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X18);
    // 0x80057278: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    // 0x8005727C: jal         0x80018EF4
    // 0x80057280: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    zmemcpy(rdram, ctx);
        goto after_2;
    // 0x80057280: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    after_2:
    // 0x80057284: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x80057288: beq         $v0, $zero, L_800572DC
    if (ctx->r2 == 0) {
        // 0x8005728C: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800572DC;
    }
    // 0x8005728C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80057290: sw          $s3, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r19;
L_80057294:
    // 0x80057294: lw          $v0, 0x4($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X4);
    // 0x80057298: beq         $v0, $zero, L_800572A4
    if (ctx->r2 == 0) {
        // 0x8005729C: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_800572A4;
    }
    // 0x8005729C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800572A0: addiu       $v1, $s3, 0x5C
    ctx->r3 = ADD32(ctx->r19, 0X5C);
L_800572A4:
    // 0x800572A4: sw          $v1, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r3;
    // 0x800572A8: sw          $a0, -0x8($s2)
    MEM_W(-0X8, ctx->r18) = ctx->r4;
    // 0x800572AC: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x800572B0: addiu       $s3, $s3, 0x5C
    ctx->r19 = ADD32(ctx->r19, 0X5C);
    // 0x800572B4: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800572B8: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x800572BC: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x800572C0: sw          $t2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r10;
    // 0x800572C4: sw          $v0, -0x4($s2)
    MEM_W(-0X4, ctx->r18) = ctx->r2;
    // 0x800572C8: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x800572CC: bne         $v0, $zero, L_80057294
    if (ctx->r2 != 0) {
        // 0x800572D0: addiu       $s2, $s2, 0x5C
        ctx->r18 = ADD32(ctx->r18, 0X5C);
            goto L_80057294;
    }
    // 0x800572D0: addiu       $s2, $s2, 0x5C
    ctx->r18 = ADD32(ctx->r18, 0X5C);
    // 0x800572D4: j           L_800572E4
    // 0x800572D8: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
        goto L_800572E4;
    // 0x800572D8: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
L_800572DC:
    // 0x800572DC: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x800572E0: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
L_800572E4:
    // 0x800572E4: addiu       $s0, $s0, 0x4C
    ctx->r16 = ADD32(ctx->r16, 0X4C);
    // 0x800572E8: lhu         $v0, 0x0($fp)
    ctx->r2 = MEM_HU(ctx->r30, 0X0);
    // 0x800572EC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800572F0: slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800572F4: bne         $v0, $zero, L_8005716C
    if (ctx->r2 != 0) {
        // 0x800572F8: addiu       $s5, $s5, 0x8
        ctx->r21 = ADD32(ctx->r21, 0X8);
            goto L_8005716C;
    }
    // 0x800572F8: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
L_800572FC:
    // 0x800572FC: j           L_80057308
    // 0x80057300: addu        $v0, $s7, $zero
    ctx->r2 = ADD32(ctx->r23, 0);
        goto L_80057308;
    // 0x80057300: addu        $v0, $s7, $zero
    ctx->r2 = ADD32(ctx->r23, 0);
L_80057304:
    // 0x80057304: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80057308:
    // 0x80057308: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8005730C: lw          $fp, 0x30($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X30);
    // 0x80057310: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x80057314: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x80057318: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x8005731C: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80057320: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80057324: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80057328: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8005732C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80057330: jr          $ra
    // 0x80057334: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80057334: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80057338(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057338: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005733C: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x80057340: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80057344: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80057348: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8005734C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80057350: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80057354: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    // 0x80057358: beq         $v0, $zero, L_80057374
    if (ctx->r2 == 0) {
        // 0x8005735C: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_80057374;
    }
    // 0x8005735C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80057360:
    // 0x80057360: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x80057364: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80057368: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8005736C: bne         $v0, $zero, L_80057360
    if (ctx->r2 != 0) {
        // 0x80057370: addu        $a1, $a1, $v1
        ctx->r5 = ADD32(ctx->r5, ctx->r3);
            goto L_80057360;
    }
    // 0x80057370: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
L_80057374:
    // 0x80057374: lui         $v0, 0x51EB
    ctx->r2 = S32(0X51EB << 16);
    // 0x80057378: ori         $v0, $v0, 0x851F
    ctx->r2 = ctx->r2 | 0X851F;
    // 0x8005737C: mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80057380: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80057384: addiu       $a0, $a0, -0x6B50
    ctx->r4 = ADD32(ctx->r4, -0X6B50);
    // 0x80057388: sra         $v0, $a1, 31
    ctx->r2 = S32(SIGNED(ctx->r5) >> 31);
    // 0x8005738C: mfhi        $t4
    ctx->r12 = hi;
    // 0x80057390: sra         $v1, $t4, 3
    ctx->r3 = S32(SIGNED(ctx->r12) >> 3);
    // 0x80057394: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80057398: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8005739C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800573A0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800573A4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800573A8: subu        $v0, $a1, $v0
    ctx->r2 = SUB32(ctx->r5, ctx->r2);
    // 0x800573AC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800573B0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800573B4: lhu         $a2, 0x0($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X0);
    // 0x800573B8: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800573BC: beq         $a2, $v0, L_8005745C
    if (ctx->r6 == ctx->r2) {
        // 0x800573C0: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_8005745C;
    }
    // 0x800573C0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800573C4: addiu       $t1, $v0, -0x6FE0
    ctx->r9 = ADD32(ctx->r2, -0X6FE0);
    // 0x800573C8: lbu         $t2, 0x0($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X0);
    // 0x800573CC: ori         $t3, $zero, 0xFFFF
    ctx->r11 = 0 | 0XFFFF;
    // 0x800573D0: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
L_800573D4:
    // 0x800573D4: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800573D8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800573DC: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x800573E0: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x800573E4: beq         $t2, $zero, L_8005741C
    if (ctx->r10 == 0) {
        // 0x800573E8: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8005741C;
    }
    // 0x800573E8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800573EC: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x800573F0: addu        $v0, $a3, $a1
    ctx->r2 = ADD32(ctx->r7, ctx->r5);
L_800573F4:
    // 0x800573F4: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x800573F8: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800573FC: bne         $v1, $v0, L_80057434
    if (ctx->r3 != ctx->r2) {
        // 0x80057400: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80057434;
    }
    // 0x80057400: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80057404: slti        $v0, $a1, 0x10
    ctx->r2 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x80057408: beq         $v0, $zero, L_8005741C
    if (ctx->r2 == 0) {
        // 0x8005740C: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8005741C;
    }
    // 0x8005740C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80057410: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80057414: bne         $v0, $zero, L_800573F4
    if (ctx->r2 != 0) {
        // 0x80057418: addu        $v0, $a3, $a1
        ctx->r2 = ADD32(ctx->r7, ctx->r5);
            goto L_800573F4;
    }
    // 0x80057418: addu        $v0, $a3, $a1
    ctx->r2 = ADD32(ctx->r7, ctx->r5);
L_8005741C:
    // 0x8005741C: addu        $v0, $t0, $a1
    ctx->r2 = ADD32(ctx->r8, ctx->r5);
    // 0x80057420: addu        $v1, $a3, $a1
    ctx->r3 = ADD32(ctx->r7, ctx->r5);
    // 0x80057424: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x80057428: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8005742C: beq         $a0, $v0, L_80057454
    if (ctx->r4 == ctx->r2) {
        // 0x80057430: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_80057454;
    }
    // 0x80057430: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_80057434:
    // 0x80057434: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x80057438: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8005743C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80057440: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x80057444: lhu         $a2, 0x0($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X0);
    // 0x80057448: bne         $a2, $t3, L_800573D4
    if (ctx->r6 != ctx->r11) {
        // 0x8005744C: sll         $v0, $a2, 1
        ctx->r2 = S32(ctx->r6 << 1);
            goto L_800573D4;
    }
    // 0x8005744C: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x80057450: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_80057454:
    // 0x80057454: bne         $a2, $v0, L_80057464
    if (ctx->r6 != ctx->r2) {
        // 0x80057458: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_80057464;
    }
    // 0x80057458: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
L_8005745C:
    // 0x8005745C: j           L_8005752C
    // 0x80057460: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_8005752C;
    // 0x80057460: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80057464:
    // 0x80057464: addiu       $v0, $v0, -0x6FE0
    ctx->r2 = ADD32(ctx->r2, -0X6FE0);
    // 0x80057468: sll         $s1, $a2, 1
    ctx->r17 = S32(ctx->r6 << 1);
    // 0x8005746C: addu        $s1, $s1, $a2
    ctx->r17 = ADD32(ctx->r17, ctx->r6);
    // 0x80057470: sll         $s1, $s1, 2
    ctx->r17 = S32(ctx->r17 << 2);
    // 0x80057474: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // 0x80057478: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x8005747C: lw          $v0, 0x18($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X18);
    // 0x80057480: lw          $s2, 0x4($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X4);
    // 0x80057484: lw          $a0, -0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, -0X4);
    // 0x80057488: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8005748C: jal         0x80001ACC
    // 0x80057490: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x80057490: addiu       $a0, $a0, 0x58
    ctx->r4 = ADD32(ctx->r4, 0X58);
    after_0:
    // 0x80057494: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80057498: addiu       $s3, $s0, 0x58
    ctx->r19 = ADD32(ctx->r16, 0X58);
    // 0x8005749C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x800574A0: lw          $a2, -0x4($s2)
    ctx->r6 = MEM_W(ctx->r18, -0X4);
    // 0x800574A4: jal         0x80018EF4
    // 0x800574A8: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    zmemcpy(rdram, ctx);
        goto after_1;
    // 0x800574A8: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_1:
    // 0x800574AC: lw          $v1, 0x4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X4);
    // 0x800574B0: addiu       $v0, $zero, 0x1001
    ctx->r2 = ADD32(0, 0X1001);
    // 0x800574B4: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // 0x800574B8: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x800574BC: addiu       $a0, $zero, -0x9
    ctx->r4 = ADD32(0, -0X9);
    // 0x800574C0: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800574C4: sb          $zero, 0xA($s0)
    MEM_B(0XA, ctx->r16) = 0;
    // 0x800574C8: sb          $zero, 0xB($s0)
    MEM_B(0XB, ctx->r16) = 0;
    // 0x800574CC: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x800574D0: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x800574D4: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x800574D8: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x800574DC: sw          $s3, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r19;
    // 0x800574E0: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x800574E4: sw          $zero, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = 0;
    // 0x800574E8: sw          $zero, 0x58($s0)
    MEM_W(0X58, ctx->r16) = 0;
    // 0x800574EC: sw          $v1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r3;
    // 0x800574F0: lw          $v1, 0x78($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X78);
    // 0x800574F4: and         $v0, $v0, $a0
    ctx->r2 = ctx->r2 & ctx->r4;
    // 0x800574F8: sw          $v0, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r2;
    // 0x800574FC: subu        $v1, $v1, $s2
    ctx->r3 = SUB32(ctx->r3, ctx->r18);
    // 0x80057500: addiu       $v1, $v1, 0x58
    ctx->r3 = ADD32(ctx->r3, 0X58);
    // 0x80057504: addu        $v1, $s0, $v1
    ctx->r3 = ADD32(ctx->r16, ctx->r3);
    // 0x80057508: sw          $v1, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r3;
    // 0x8005750C: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x80057510: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80057514: subu        $v0, $v0, $s2
    ctx->r2 = SUB32(ctx->r2, ctx->r18);
    // 0x80057518: addiu       $v0, $v0, 0x58
    ctx->r2 = ADD32(ctx->r2, 0X58);
    // 0x8005751C: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x80057520: jal         0x8000A85C
    // 0x80057524: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    func_8000A85C(rdram, ctx);
        goto after_2;
    // 0x80057524: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    after_2:
    // 0x80057528: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
L_8005752C:
    // 0x8005752C: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80057530: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80057534: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80057538: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8005753C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80057540: jr          $ra
    // 0x80057544: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80057544: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80057548(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057548: lui         $a3, 0x8080
    ctx->r7 = S32(0X8080 << 16);
    // 0x8005754C: ori         $a3, $a3, 0x8081
    ctx->r7 = ctx->r7 | 0X8081;
    // 0x80057550: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x80057554: lw          $v0, 0x1C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X1C);
    // 0x80057558: sll         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3 << 8);
    // 0x8005755C: lw          $v0, 0x20($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X20);
    // 0x80057560: mult        $v1, $a3
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80057564: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x80057568: lw          $t4, 0xC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XC);
    // 0x8005756C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80057570: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x80057574: lbu         $a2, 0x1($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0X1);
    // 0x80057578: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x8005757C: mfhi        $a0
    ctx->r4 = hi;
    // 0x80057580: sll         $a2, $a2, 8
    ctx->r6 = S32(ctx->r6 << 8);
    // 0x80057584: lw          $v0, 0x20($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X20);
    // 0x80057588: mult        $a2, $a3
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005758C: lw          $t5, 0x8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X8);
    // 0x80057590: addu        $v0, $a0, $v1
    ctx->r2 = ADD32(ctx->r4, ctx->r3);
    // 0x80057594: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x80057598: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x8005759C: subu        $t3, $v0, $v1
    ctx->r11 = SUB32(ctx->r2, ctx->r3);
    // 0x800575A0: lbu         $a0, 0x2($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X2);
    // 0x800575A4: mfhi        $t1
    ctx->r9 = hi;
    // 0x800575A8: lbu         $v1, 0x3($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X3);
    // 0x800575AC: sll         $a0, $a0, 8
    ctx->r4 = S32(ctx->r4 << 8);
    // 0x800575B0: mult        $a0, $a3
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800575B4: sll         $v1, $v1, 8
    ctx->r3 = S32(ctx->r3 << 8);
    // 0x800575B8: addu        $v0, $t1, $a2
    ctx->r2 = ADD32(ctx->r9, ctx->r6);
    // 0x800575BC: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x800575C0: mfhi        $t1
    ctx->r9 = hi;
    // 0x800575C4: sra         $a2, $a2, 31
    ctx->r6 = S32(SIGNED(ctx->r6) >> 31);
    // 0x800575C8: subu        $t2, $v0, $a2
    ctx->r10 = SUB32(ctx->r2, ctx->r6);
    // 0x800575CC: mult        $v1, $a3
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800575D0: addu        $v0, $t1, $a0
    ctx->r2 = ADD32(ctx->r9, ctx->r4);
    // 0x800575D4: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x800575D8: sra         $a0, $a0, 31
    ctx->r4 = S32(SIGNED(ctx->r4) >> 31);
    // 0x800575DC: subu        $a2, $v0, $a0
    ctx->r6 = SUB32(ctx->r2, ctx->r4);
    // 0x800575E0: mfhi        $a3
    ctx->r7 = hi;
    // 0x800575E4: addu        $v0, $a3, $v1
    ctx->r2 = ADD32(ctx->r7, ctx->r3);
    // 0x800575E8: sra         $v0, $v0, 7
    ctx->r2 = S32(SIGNED(ctx->r2) >> 7);
    // 0x800575EC: sra         $v1, $v1, 31
    ctx->r3 = S32(SIGNED(ctx->r3) >> 31);
    // 0x800575F0: blez        $t4, L_80057794
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800575F4: subu        $a1, $v0, $v1
        ctx->r5 = SUB32(ctx->r2, ctx->r3);
            goto L_80057794;
    }
    // 0x800575F4: subu        $a1, $v0, $v1
    ctx->r5 = SUB32(ctx->r2, ctx->r3);
    // 0x800575F8: lui         $a3, 0x3
    ctx->r7 = S32(0X3 << 16);
    // 0x800575FC: ori         $a3, $a3, 0xF000
    ctx->r7 = ctx->r7 | 0XF000;
    // 0x80057600: lui         $t1, 0x3F00
    ctx->r9 = S32(0X3F00 << 16);
L_80057604:
    // 0x80057604: lw          $v0, 0x4($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X4);
    // 0x80057608: and         $v0, $v0, $a3
    ctx->r2 = ctx->r2 & ctx->r7;
    // 0x8005760C: srl         $v1, $v0, 10
    ctx->r3 = S32(U32(ctx->r2) >> 10);
    // 0x80057610: addu        $a0, $t5, $v1
    ctx->r4 = ADD32(ctx->r13, ctx->r3);
    // 0x80057614: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80057618: mult        $v0, $t3
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005761C: addu        $v1, $t0, $v1
    ctx->r3 = ADD32(ctx->r8, ctx->r3);
    // 0x80057620: mflo        $t6
    ctx->r14 = lo;
    // 0x80057624: sra         $v0, $t6, 8
    ctx->r2 = S32(SIGNED(ctx->r14) >> 8);
    // 0x80057628: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x8005762C: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    // 0x80057630: mult        $v0, $t2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80057634: mflo        $t6
    ctx->r14 = lo;
    // 0x80057638: sra         $v0, $t6, 8
    ctx->r2 = S32(SIGNED(ctx->r14) >> 8);
    // 0x8005763C: sb          $v0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r2;
    // 0x80057640: lbu         $v0, 0x2($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2);
    // 0x80057644: mult        $v0, $a2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80057648: mflo        $t6
    ctx->r14 = lo;
    // 0x8005764C: sra         $v0, $t6, 8
    ctx->r2 = S32(SIGNED(ctx->r14) >> 8);
    // 0x80057650: sb          $v0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r2;
    // 0x80057654: lbu         $v0, 0x3($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X3);
    // 0x80057658: mult        $v0, $a1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005765C: mflo        $t6
    ctx->r14 = lo;
    // 0x80057660: sra         $v0, $t6, 8
    ctx->r2 = S32(SIGNED(ctx->r14) >> 8);
    // 0x80057664: sb          $v0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r2;
    // 0x80057668: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8005766C: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80057670: beq         $v0, $zero, L_80057778
    if (ctx->r2 == 0) {
        // 0x80057674: nop
    
            goto L_80057778;
    }
    // 0x80057674: nop

    // 0x80057678: lbu         $v0, 0x4($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X4);
    // 0x8005767C: mult        $v0, $t3
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80057680: mflo        $t6
    ctx->r14 = lo;
    // 0x80057684: sra         $v0, $t6, 8
    ctx->r2 = S32(SIGNED(ctx->r14) >> 8);
    // 0x80057688: sb          $v0, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r2;
    // 0x8005768C: lbu         $v0, 0x5($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X5);
    // 0x80057690: mult        $v0, $t2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80057694: mflo        $t6
    ctx->r14 = lo;
    // 0x80057698: sra         $v0, $t6, 8
    ctx->r2 = S32(SIGNED(ctx->r14) >> 8);
    // 0x8005769C: sb          $v0, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r2;
    // 0x800576A0: lbu         $v0, 0x6($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X6);
    // 0x800576A4: mult        $v0, $a2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800576A8: mflo        $t6
    ctx->r14 = lo;
    // 0x800576AC: sra         $v0, $t6, 8
    ctx->r2 = S32(SIGNED(ctx->r14) >> 8);
    // 0x800576B0: sb          $v0, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r2;
    // 0x800576B4: lbu         $v0, 0x7($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X7);
    // 0x800576B8: mult        $v0, $a1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800576BC: mflo        $t6
    ctx->r14 = lo;
    // 0x800576C0: sra         $v0, $t6, 8
    ctx->r2 = S32(SIGNED(ctx->r14) >> 8);
    // 0x800576C4: sb          $v0, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r2;
    // 0x800576C8: lbu         $v0, 0x8($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X8);
    // 0x800576CC: mult        $v0, $t3
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800576D0: mflo        $t6
    ctx->r14 = lo;
    // 0x800576D4: sra         $v0, $t6, 8
    ctx->r2 = S32(SIGNED(ctx->r14) >> 8);
    // 0x800576D8: sb          $v0, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r2;
    // 0x800576DC: lbu         $v0, 0x9($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X9);
    // 0x800576E0: mult        $v0, $t2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800576E4: mflo        $t6
    ctx->r14 = lo;
    // 0x800576E8: sra         $v0, $t6, 8
    ctx->r2 = S32(SIGNED(ctx->r14) >> 8);
    // 0x800576EC: sb          $v0, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r2;
    // 0x800576F0: lbu         $v0, 0xA($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XA);
    // 0x800576F4: mult        $v0, $a2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800576F8: mflo        $t6
    ctx->r14 = lo;
    // 0x800576FC: sra         $v0, $t6, 8
    ctx->r2 = S32(SIGNED(ctx->r14) >> 8);
    // 0x80057700: sb          $v0, 0xA($v1)
    MEM_B(0XA, ctx->r3) = ctx->r2;
    // 0x80057704: lbu         $v0, 0xB($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XB);
    // 0x80057708: mult        $v0, $a1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005770C: mflo        $t6
    ctx->r14 = lo;
    // 0x80057710: sra         $v0, $t6, 8
    ctx->r2 = S32(SIGNED(ctx->r14) >> 8);
    // 0x80057714: sb          $v0, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r2;
    // 0x80057718: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8005771C: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x80057720: beq         $v0, $zero, L_80057778
    if (ctx->r2 == 0) {
        // 0x80057724: nop
    
            goto L_80057778;
    }
    // 0x80057724: nop

    // 0x80057728: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8005772C: mult        $v0, $t3
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80057730: mflo        $t6
    ctx->r14 = lo;
    // 0x80057734: sra         $v0, $t6, 8
    ctx->r2 = S32(SIGNED(ctx->r14) >> 8);
    // 0x80057738: sb          $v0, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r2;
    // 0x8005773C: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    // 0x80057740: mult        $v0, $t2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80057744: mflo        $t6
    ctx->r14 = lo;
    // 0x80057748: sra         $v0, $t6, 8
    ctx->r2 = S32(SIGNED(ctx->r14) >> 8);
    // 0x8005774C: sb          $v0, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r2;
    // 0x80057750: lbu         $v0, 0x2($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2);
    // 0x80057754: mult        $v0, $a2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80057758: mflo        $t6
    ctx->r14 = lo;
    // 0x8005775C: sra         $v0, $t6, 8
    ctx->r2 = S32(SIGNED(ctx->r14) >> 8);
    // 0x80057760: sb          $v0, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r2;
    // 0x80057764: lbu         $v0, 0x3($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X3);
    // 0x80057768: mult        $v0, $a1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8005776C: mflo        $t6
    ctx->r14 = lo;
    // 0x80057770: sra         $v0, $t6, 8
    ctx->r2 = S32(SIGNED(ctx->r14) >> 8);
    // 0x80057774: sb          $v0, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r2;
L_80057778:
    // 0x80057778: lw          $v0, 0x4($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X4);
    // 0x8005777C: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x80057780: and         $v0, $v0, $t1
    ctx->r2 = ctx->r2 & ctx->r9;
    // 0x80057784: srl         $v1, $v0, 22
    ctx->r3 = S32(U32(ctx->r2) >> 22);
    // 0x80057788: addu        $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
    // 0x8005778C: bgtz        $t4, L_80057604
    if (SIGNED(ctx->r12) > 0) {
        // 0x80057790: addu        $t5, $t5, $v1
        ctx->r13 = ADD32(ctx->r13, ctx->r3);
            goto L_80057604;
    }
    // 0x80057790: addu        $t5, $t5, $v1
    ctx->r13 = ADD32(ctx->r13, ctx->r3);
L_80057794:
    // 0x80057794: jr          $ra
    // 0x80057798: nop

    return;
    // 0x80057798: nop

;}
RECOMP_FUNC void func_8005779C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005779C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800577A0: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x800577A4: addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // 0x800577A8: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x800577AC: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x800577B0: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800577B4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800577B8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800577BC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800577C0: lhu         $v0, 0x8($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X8);
    // 0x800577C4: lw          $v1, 0x0($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X0);
    // 0x800577C8: andi        $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 & 0X1000;
    // 0x800577CC: bne         $v0, $zero, L_80057864
    if (ctx->r2 != 0) {
        // 0x800577D0: nop
    
            goto L_80057864;
    }
    // 0x800577D0: nop

    // 0x800577D4: lhu         $v0, 0x3A($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X3A);
    // 0x800577D8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800577DC: sh          $v0, 0x3A($v1)
    MEM_H(0X3A, ctx->r3) = ctx->r2;
    // 0x800577E0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800577E4: bne         $v0, $zero, L_80057864
    if (ctx->r2 != 0) {
        // 0x800577E8: nop
    
            goto L_80057864;
    }
    // 0x800577E8: nop

    // 0x800577EC: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x800577F0: addu        $s3, $v1, $zero
    ctx->r19 = ADD32(ctx->r3, 0);
L_800577F4:
    // 0x800577F4: lw          $v0, 0x18($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X18);
    // 0x800577F8: beq         $v0, $zero, L_80057864
    if (ctx->r2 == 0) {
        // 0x800577FC: nop
    
            goto L_80057864;
    }
    // 0x800577FC: nop

    // 0x80057800: lhu         $s2, 0x0($v0)
    ctx->r18 = MEM_HU(ctx->r2, 0X0);
    // 0x80057804: blez        $s2, L_80057854
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80057808: addiu       $s1, $v0, 0x4
        ctx->r17 = ADD32(ctx->r2, 0X4);
            goto L_80057854;
    }
    // 0x80057808: addiu       $s1, $v0, 0x4
    ctx->r17 = ADD32(ctx->r2, 0X4);
    // 0x8005780C: j           L_8005783C
    // 0x80057810: nop

        goto L_8005783C;
    // 0x80057810: nop

L_80057814:
    // 0x80057814: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x80057818: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x8005781C: beql        $v0, $zero, L_8005783C
    if (ctx->r2 == 0) {
        // 0x80057820: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8005783C;
    }
    goto skip_0;
    // 0x80057820: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    skip_0:
    // 0x80057824: jal         0x80008350
    // 0x80057828: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80008350(rdram, ctx);
        goto after_0;
    // 0x80057828: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8005782C: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x80057830: ori         $v0, $v0, 0x8
    ctx->r2 = ctx->r2 | 0X8;
    // 0x80057834: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // 0x80057838: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8005783C:
    // 0x8005783C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80057840: bne         $s0, $zero, L_80057814
    if (ctx->r16 != 0) {
        // 0x80057844: nop
    
            goto L_80057814;
    }
    // 0x80057844: nop

    // 0x80057848: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x8005784C: bgtz        $s2, L_8005783C
    if (SIGNED(ctx->r18) > 0) {
        // 0x80057850: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8005783C;
    }
    // 0x80057850: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80057854:
    // 0x80057854: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80057858: slti        $v0, $s4, 0x4
    ctx->r2 = SIGNED(ctx->r20) < 0X4 ? 1 : 0;
    // 0x8005785C: bne         $v0, $zero, L_800577F4
    if (ctx->r2 != 0) {
        // 0x80057860: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_800577F4;
    }
    // 0x80057860: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
L_80057864:
    // 0x80057864: lbu         $v0, 0xB($s5)
    ctx->r2 = MEM_BU(ctx->r21, 0XB);
    // 0x80057868: beq         $v0, $zero, L_80057894
    if (ctx->r2 == 0) {
        // 0x8005786C: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_80057894;
    }
    // 0x8005786C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80057870: lhu         $v0, -0x5B70($v1)
    ctx->r2 = MEM_HU(ctx->r3, -0X5B70);
    // 0x80057874: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80057878: sh          $v0, -0x5B70($v1)
    MEM_H(-0X5B70, ctx->r3) = ctx->r2;
    // 0x8005787C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80057880: addiu       $v1, $v1, -0x5B68
    ctx->r3 = ADD32(ctx->r3, -0X5B68);
    // 0x80057884: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80057888: lbu         $a0, 0xB($s5)
    ctx->r4 = MEM_BU(ctx->r21, 0XB);
    // 0x8005788C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80057890: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
L_80057894:
    // 0x80057894: lhu         $v0, 0x8($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X8);
    // 0x80057898: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x8005789C: beq         $v0, $zero, L_800578B0
    if (ctx->r2 == 0) {
        // 0x800578A0: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_800578B0;
    }
    // 0x800578A0: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800578A4: lhu         $v0, -0x6B1E($v1)
    ctx->r2 = MEM_HU(ctx->r3, -0X6B1E);
    // 0x800578A8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800578AC: sh          $v0, -0x6B1E($v1)
    MEM_H(-0X6B1E, ctx->r3) = ctx->r2;
L_800578B0:
    // 0x800578B0: lhu         $v0, 0x8($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X8);
    // 0x800578B4: andi        $v0, $v0, 0x100
    ctx->r2 = ctx->r2 & 0X100;
    // 0x800578B8: beq         $v0, $zero, L_800578CC
    if (ctx->r2 == 0) {
        // 0x800578BC: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_800578CC;
    }
    // 0x800578BC: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800578C0: lhu         $v0, -0x6B1C($v1)
    ctx->r2 = MEM_HU(ctx->r3, -0X6B1C);
    // 0x800578C4: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800578C8: sh          $v0, -0x6B1C($v1)
    MEM_H(-0X6B1C, ctx->r3) = ctx->r2;
L_800578CC:
    // 0x800578CC: lhu         $v0, 0x8($s5)
    ctx->r2 = MEM_HU(ctx->r21, 0X8);
    // 0x800578D0: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x800578D4: beq         $v0, $zero, L_80057934
    if (ctx->r2 == 0) {
        // 0x800578D8: lui         $a2, 0x16C1
        ctx->r6 = S32(0X16C1 << 16);
            goto L_80057934;
    }
    // 0x800578D8: lui         $a2, 0x16C1
    ctx->r6 = S32(0X16C1 << 16);
    // 0x800578DC: ori         $a2, $a2, 0x6C17
    ctx->r6 = ctx->r6 | 0X6C17;
    // 0x800578E0: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x800578E4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800578E8: lbu         $a0, -0x6AB0($a1)
    ctx->r4 = MEM_BU(ctx->r5, -0X6AB0);
    // 0x800578EC: lw          $v0, -0x6B18($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6B18);
    // 0x800578F0: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    // 0x800578F4: subu        $v0, $s5, $v0
    ctx->r2 = SUB32(ctx->r21, ctx->r2);
    // 0x800578F8: srl         $v0, $v0, 2
    ctx->r2 = S32(U32(ctx->r2) >> 2);
    // 0x800578FC: multu       $v0, $a2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80057900: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80057904: addiu       $v0, $v0, -0x6B10
    ctx->r2 = ADD32(ctx->r2, -0X6B10);
    // 0x80057908: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8005790C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80057910: sb          $v1, -0x6AB0($a1)
    MEM_B(-0X6AB0, ctx->r5) = ctx->r3;
    // 0x80057914: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80057918: mfhi        $a3
    ctx->r7 = hi;
    // 0x8005791C: srl         $v0, $a3, 2
    ctx->r2 = S32(U32(ctx->r7) >> 2);
    // 0x80057920: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x80057924: lw          $v0, -0x6AAC($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X6AAC);
    // 0x80057928: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8005792C: j           L_80057954
    // 0x80057930: sw          $v0, -0x6AAC($v1)
    MEM_W(-0X6AAC, ctx->r3) = ctx->r2;
        goto L_80057954;
    // 0x80057930: sw          $v0, -0x6AAC($v1)
    MEM_W(-0X6AAC, ctx->r3) = ctx->r2;
L_80057934:
    // 0x80057934: lw          $v0, 0x8($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X8);
    // 0x80057938: lui         $v1, 0x1001
    ctx->r3 = S32(0X1001 << 16);
    // 0x8005793C: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x80057940: lui         $v1, 0x1
    ctx->r3 = S32(0X1 << 16);
    // 0x80057944: beq         $v0, $v1, L_80057954
    if (ctx->r2 == ctx->r3) {
        // 0x80057948: nop
    
            goto L_80057954;
    }
    // 0x80057948: nop

    // 0x8005794C: jal         0x80001C98
    // 0x80057950: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    rs_free(rdram, ctx);
        goto after_1;
    // 0x80057950: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    after_1:
L_80057954:
    // 0x80057954: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x80057958: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x8005795C: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x80057960: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80057964: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80057968: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8005796C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80057970: jr          $ra
    // 0x80057974: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80057974: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80057978(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057978: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8005797C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80057980: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80057984: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80057988: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8005798C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80057990: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80057994: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80057998: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8005799C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800579A0: bne         $a0, $zero, L_80057AA4
    if (ctx->r4 != 0) {
        // 0x800579A4: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_80057AA4;
    }
    // 0x800579A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800579A8: addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
    // 0x800579AC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800579B0: addiu       $fp, $v0, -0x6FE0
    ctx->r30 = ADD32(ctx->r2, -0X6FE0);
    // 0x800579B4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800579B8: addiu       $s6, $v0, -0x6B50
    ctx->r22 = ADD32(ctx->r2, -0X6B50);
L_800579BC:
    // 0x800579BC: lhu         $s3, 0x0($s6)
    ctx->r19 = MEM_HU(ctx->r22, 0X0);
    // 0x800579C0: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800579C4: beql        $s3, $v0, L_80057A90
    if (ctx->r19 == ctx->r2) {
        // 0x800579C8: addiu       $s7, $s7, 0x1
        ctx->r23 = ADD32(ctx->r23, 0X1);
            goto L_80057A90;
    }
    goto skip_0;
    // 0x800579C8: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    skip_0:
    // 0x800579CC: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800579D0: sll         $v0, $s3, 1
    ctx->r2 = S32(ctx->r19 << 1);
L_800579D4:
    // 0x800579D4: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x800579D8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800579DC: addu        $v0, $v0, $fp
    ctx->r2 = ADD32(ctx->r2, ctx->r30);
    // 0x800579E0: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x800579E4: lhu         $v0, 0x38($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X38);
    // 0x800579E8: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x800579EC: bne         $v0, $zero, L_80057A74
    if (ctx->r2 != 0) {
        // 0x800579F0: sll         $v0, $s3, 1
        ctx->r2 = S32(ctx->r19 << 1);
            goto L_80057A74;
    }
    // 0x800579F0: sll         $v0, $s3, 1
    ctx->r2 = S32(ctx->r19 << 1);
    // 0x800579F4: addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
    // 0x800579F8: addu        $s4, $v1, $zero
    ctx->r20 = ADD32(ctx->r3, 0);
L_800579FC:
    // 0x800579FC: lw          $v0, 0x18($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X18);
    // 0x80057A00: beql        $v0, $zero, L_80057A74
    if (ctx->r2 == 0) {
        // 0x80057A04: sll         $v0, $s3, 1
        ctx->r2 = S32(ctx->r19 << 1);
            goto L_80057A74;
    }
    goto skip_1;
    // 0x80057A04: sll         $v0, $s3, 1
    ctx->r2 = S32(ctx->r19 << 1);
    skip_1:
    // 0x80057A08: lhu         $s2, 0x0($v0)
    ctx->r18 = MEM_HU(ctx->r2, 0X0);
    // 0x80057A0C: blez        $s2, L_80057A60
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80057A10: addiu       $s1, $v0, 0x4
        ctx->r17 = ADD32(ctx->r2, 0X4);
            goto L_80057A60;
    }
    // 0x80057A10: addiu       $s1, $v0, 0x4
    ctx->r17 = ADD32(ctx->r2, 0X4);
    // 0x80057A14: j           L_80057A48
    // 0x80057A18: nop

        goto L_80057A48;
    // 0x80057A18: nop

L_80057A1C:
    // 0x80057A1C: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x80057A20: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80057A24: beq         $v0, $zero, L_80057A44
    if (ctx->r2 == 0) {
        // 0x80057A28: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_80057A44;
    }
    // 0x80057A28: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80057A2C: jal         0x80008350
    // 0x80057A30: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    func_80008350(rdram, ctx);
        goto after_0;
    // 0x80057A30: sw          $a1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r5;
    after_0:
    // 0x80057A34: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x80057A38: ori         $v0, $v0, 0x8
    ctx->r2 = ctx->r2 | 0X8;
    // 0x80057A3C: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // 0x80057A40: lw          $a1, 0x10($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X10);
L_80057A44:
    // 0x80057A44: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80057A48:
    // 0x80057A48: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80057A4C: bne         $s0, $zero, L_80057A1C
    if (ctx->r16 != 0) {
        // 0x80057A50: nop
    
            goto L_80057A1C;
    }
    // 0x80057A50: nop

    // 0x80057A54: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80057A58: bgtz        $s2, L_80057A48
    if (SIGNED(ctx->r18) > 0) {
        // 0x80057A5C: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80057A48;
    }
    // 0x80057A5C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80057A60:
    // 0x80057A60: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80057A64: slti        $v0, $s5, 0x4
    ctx->r2 = SIGNED(ctx->r21) < 0X4 ? 1 : 0;
    // 0x80057A68: bne         $v0, $zero, L_800579FC
    if (ctx->r2 != 0) {
        // 0x80057A6C: addiu       $s4, $s4, 0x4
        ctx->r20 = ADD32(ctx->r20, 0X4);
            goto L_800579FC;
    }
    // 0x80057A6C: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80057A70: sll         $v0, $s3, 1
    ctx->r2 = S32(ctx->r19 << 1);
L_80057A74:
    // 0x80057A74: addu        $v0, $v0, $s3
    ctx->r2 = ADD32(ctx->r2, ctx->r19);
    // 0x80057A78: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80057A7C: addu        $v0, $v0, $fp
    ctx->r2 = ADD32(ctx->r2, ctx->r30);
    // 0x80057A80: lhu         $s3, 0x0($v0)
    ctx->r19 = MEM_HU(ctx->r2, 0X0);
    // 0x80057A84: bne         $s3, $a1, L_800579D4
    if (ctx->r19 != ctx->r5) {
        // 0x80057A88: sll         $v0, $s3, 1
        ctx->r2 = S32(ctx->r19 << 1);
            goto L_800579D4;
    }
    // 0x80057A88: sll         $v0, $s3, 1
    ctx->r2 = S32(ctx->r19 << 1);
    // 0x80057A8C: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
L_80057A90:
    // 0x80057A90: slti        $v0, $s7, 0x19
    ctx->r2 = SIGNED(ctx->r23) < 0X19 ? 1 : 0;
    // 0x80057A94: bne         $v0, $zero, L_800579BC
    if (ctx->r2 != 0) {
        // 0x80057A98: addiu       $s6, $s6, 0x2
        ctx->r22 = ADD32(ctx->r22, 0X2);
            goto L_800579BC;
    }
    // 0x80057A98: addiu       $s6, $s6, 0x2
    ctx->r22 = ADD32(ctx->r22, 0X2);
    // 0x80057A9C: j           L_80057B1C
    // 0x80057AA0: nop

        goto L_80057B1C;
    // 0x80057AA0: nop

L_80057AA4:
    // 0x80057AA4: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x80057AA8: lw          $s3, 0x0($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X0);
L_80057AAC:
    // 0x80057AAC: lw          $v0, 0x18($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X18);
    // 0x80057AB0: beq         $v0, $zero, L_80057B1C
    if (ctx->r2 == 0) {
        // 0x80057AB4: nop
    
            goto L_80057B1C;
    }
    // 0x80057AB4: nop

    // 0x80057AB8: lhu         $s2, 0x0($v0)
    ctx->r18 = MEM_HU(ctx->r2, 0X0);
    // 0x80057ABC: blez        $s2, L_80057B0C
    if (SIGNED(ctx->r18) <= 0) {
        // 0x80057AC0: addiu       $s1, $v0, 0x4
        ctx->r17 = ADD32(ctx->r2, 0X4);
            goto L_80057B0C;
    }
    // 0x80057AC0: addiu       $s1, $v0, 0x4
    ctx->r17 = ADD32(ctx->r2, 0X4);
    // 0x80057AC4: j           L_80057AF4
    // 0x80057AC8: nop

        goto L_80057AF4;
    // 0x80057AC8: nop

L_80057ACC:
    // 0x80057ACC: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x80057AD0: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80057AD4: beql        $v0, $zero, L_80057AF4
    if (ctx->r2 == 0) {
        // 0x80057AD8: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80057AF4;
    }
    goto skip_2;
    // 0x80057AD8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    skip_2:
    // 0x80057ADC: jal         0x80008350
    // 0x80057AE0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80008350(rdram, ctx);
        goto after_1;
    // 0x80057AE0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80057AE4: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x80057AE8: ori         $v0, $v0, 0x8
    ctx->r2 = ctx->r2 | 0X8;
    // 0x80057AEC: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // 0x80057AF0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80057AF4:
    // 0x80057AF4: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80057AF8: bne         $s0, $zero, L_80057ACC
    if (ctx->r16 != 0) {
        // 0x80057AFC: nop
    
            goto L_80057ACC;
    }
    // 0x80057AFC: nop

    // 0x80057B00: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80057B04: bgtz        $s2, L_80057AF4
    if (SIGNED(ctx->r18) > 0) {
        // 0x80057B08: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80057AF4;
    }
    // 0x80057B08: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_80057B0C:
    // 0x80057B0C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80057B10: slti        $v0, $s4, 0x4
    ctx->r2 = SIGNED(ctx->r20) < 0X4 ? 1 : 0;
    // 0x80057B14: bne         $v0, $zero, L_80057AAC
    if (ctx->r2 != 0) {
        // 0x80057B18: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_80057AAC;
    }
    // 0x80057B18: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
L_80057B1C:
    // 0x80057B1C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80057B20: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80057B24: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80057B28: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80057B2C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80057B30: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80057B34: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80057B38: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80057B3C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80057B40: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80057B44: jr          $ra
    // 0x80057B48: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80057B48: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void getHobObjectByName(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057B4C: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x80057B50: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    // 0x80057B54: beq         $v0, $zero, L_80057B70
    if (ctx->r2 == 0) {
        // 0x80057B58: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_80057B70;
    }
    // 0x80057B58: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80057B5C:
    // 0x80057B5C: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x80057B60: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80057B64: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80057B68: bne         $v0, $zero, L_80057B5C
    if (ctx->r2 != 0) {
        // 0x80057B6C: addu        $a1, $a1, $v1
        ctx->r5 = ADD32(ctx->r5, ctx->r3);
            goto L_80057B5C;
    }
    // 0x80057B6C: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
L_80057B70:
    // 0x80057B70: lui         $v0, 0x51EB
    ctx->r2 = S32(0X51EB << 16);
    // 0x80057B74: ori         $v0, $v0, 0x851F
    ctx->r2 = ctx->r2 | 0X851F;
    // 0x80057B78: mult        $a1, $v0
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80057B7C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80057B80: addiu       $a0, $a0, -0x6B50
    ctx->r4 = ADD32(ctx->r4, -0X6B50);
    // 0x80057B84: sra         $v0, $a1, 31
    ctx->r2 = S32(SIGNED(ctx->r5) >> 31);
    // 0x80057B88: mfhi        $t4
    ctx->r12 = hi;
    // 0x80057B8C: sra         $v1, $t4, 3
    ctx->r3 = S32(SIGNED(ctx->r12) >> 3);
    // 0x80057B90: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80057B94: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80057B98: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80057B9C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80057BA0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80057BA4: subu        $v0, $a1, $v0
    ctx->r2 = SUB32(ctx->r5, ctx->r2);
    // 0x80057BA8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80057BAC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80057BB0: lhu         $a2, 0x0($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X0);
    // 0x80057BB4: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80057BB8: beq         $a2, $v0, L_80057C80
    if (ctx->r6 == ctx->r2) {
        // 0x80057BBC: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_80057C80;
    }
    // 0x80057BBC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80057BC0: addiu       $t1, $v0, -0x6FE0
    ctx->r9 = ADD32(ctx->r2, -0X6FE0);
    // 0x80057BC4: lbu         $t2, 0x0($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X0);
    // 0x80057BC8: ori         $t3, $zero, 0xFFFF
    ctx->r11 = 0 | 0XFFFF;
    // 0x80057BCC: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
L_80057BD0:
    // 0x80057BD0: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80057BD4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80057BD8: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x80057BDC: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x80057BE0: beq         $t2, $zero, L_80057C18
    if (ctx->r10 == 0) {
        // 0x80057BE4: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_80057C18;
    }
    // 0x80057BE4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80057BE8: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x80057BEC: addu        $v0, $a3, $a1
    ctx->r2 = ADD32(ctx->r7, ctx->r5);
L_80057BF0:
    // 0x80057BF0: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x80057BF4: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x80057BF8: bne         $v1, $v0, L_80057C30
    if (ctx->r3 != ctx->r2) {
        // 0x80057BFC: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80057C30;
    }
    // 0x80057BFC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80057C00: slti        $v0, $a1, 0x10
    ctx->r2 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x80057C04: beq         $v0, $zero, L_80057C18
    if (ctx->r2 == 0) {
        // 0x80057C08: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80057C18;
    }
    // 0x80057C08: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80057C0C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80057C10: bne         $v0, $zero, L_80057BF0
    if (ctx->r2 != 0) {
        // 0x80057C14: addu        $v0, $a3, $a1
        ctx->r2 = ADD32(ctx->r7, ctx->r5);
            goto L_80057BF0;
    }
    // 0x80057C14: addu        $v0, $a3, $a1
    ctx->r2 = ADD32(ctx->r7, ctx->r5);
L_80057C18:
    // 0x80057C18: addu        $v0, $t0, $a1
    ctx->r2 = ADD32(ctx->r8, ctx->r5);
    // 0x80057C1C: addu        $v1, $a3, $a1
    ctx->r3 = ADD32(ctx->r7, ctx->r5);
    // 0x80057C20: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x80057C24: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80057C28: beq         $a0, $v0, L_80057C50
    if (ctx->r4 == ctx->r2) {
        // 0x80057C2C: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_80057C50;
    }
    // 0x80057C2C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_80057C30:
    // 0x80057C30: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x80057C34: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80057C38: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80057C3C: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x80057C40: lhu         $a2, 0x0($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X0);
    // 0x80057C44: bne         $a2, $t3, L_80057BD0
    if (ctx->r6 != ctx->r11) {
        // 0x80057C48: sll         $v0, $a2, 1
        ctx->r2 = S32(ctx->r6 << 1);
            goto L_80057BD0;
    }
    // 0x80057C48: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x80057C4C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
L_80057C50:
    // 0x80057C50: beq         $a2, $v0, L_80057C80
    if (ctx->r6 == ctx->r2) {
        // 0x80057C54: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_80057C80;
    }
    // 0x80057C54: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80057C58: addiu       $v1, $v1, -0x6FE0
    ctx->r3 = ADD32(ctx->r3, -0X6FE0);
    // 0x80057C5C: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x80057C60: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80057C64: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80057C68: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80057C6C: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x80057C70: lhu         $v1, 0x38($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X38);
    // 0x80057C74: andi        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 & 0X1;
    // 0x80057C78: bne         $v1, $zero, L_80057C84
    if (ctx->r3 != 0) {
        // 0x80057C7C: nop
    
            goto L_80057C84;
    }
    // 0x80057C7C: nop

L_80057C80:
    // 0x80057C80: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80057C84:
    // 0x80057C84: jr          $ra
    // 0x80057C88: nop

    return;
    // 0x80057C88: nop

;}
RECOMP_FUNC void func_80057C8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057C8C: mtc1        $a3, $f0
    ctx->f0.u32l = ctx->r7;
    // 0x80057C90: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80057C94: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80057C98: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x80057C9C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80057CA0: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x80057CA4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80057CA8: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x80057CAC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80057CB0: lbu         $v0, 0xB($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XB);
    // 0x80057CB4: lw          $s2, 0x0($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X0);
    // 0x80057CB8: beq         $v0, $zero, L_80057CFC
    if (ctx->r2 == 0) {
        // 0x80057CBC: addiu       $s1, $zero, -0x1
        ctx->r17 = ADD32(0, -0X1);
            goto L_80057CFC;
    }
    // 0x80057CBC: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x80057CC0: lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X8);
    // 0x80057CC4: andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // 0x80057CC8: bne         $v0, $zero, L_80057D00
    if (ctx->r2 != 0) {
        // 0x80057CCC: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80057D00;
    }
    // 0x80057CCC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80057CD0: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80057CD4: lhu         $v0, -0x5B70($v1)
    ctx->r2 = MEM_HU(ctx->r3, -0X5B70);
    // 0x80057CD8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80057CDC: sh          $v0, -0x5B70($v1)
    MEM_H(-0X5B70, ctx->r3) = ctx->r2;
    // 0x80057CE0: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80057CE4: addiu       $v1, $v1, -0x5B68
    ctx->r3 = ADD32(ctx->r3, -0X5B68);
    // 0x80057CE8: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80057CEC: lbu         $a0, 0xB($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XB);
    // 0x80057CF0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80057CF4: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    // 0x80057CF8: sb          $zero, 0xB($s0)
    MEM_B(0XB, ctx->r16) = 0;
L_80057CFC:
    // 0x80057CFC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_80057D00:
    // 0x80057D00: lbu         $v0, 0xB39($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB39);
    // 0x80057D04: bne         $v0, $zero, L_80057E3C
    if (ctx->r2 != 0) {
        // 0x80057D08: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_80057E3C;
    }
    // 0x80057D08: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80057D0C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80057D10: lw          $v0, -0x7764($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7764);
    // 0x80057D14: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80057D18: beq         $v0, $zero, L_80057DA4
    if (ctx->r2 == 0) {
        // 0x80057D1C: nop
    
            goto L_80057DA4;
    }
    // 0x80057D1C: nop

    // 0x80057D20: lhu         $v1, 0x8($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X8);
    // 0x80057D24: andi        $v0, $v1, 0x80
    ctx->r2 = ctx->r3 & 0X80;
    // 0x80057D28: bne         $v0, $zero, L_80057E74
    if (ctx->r2 != 0) {
        // 0x80057D2C: andi        $v0, $v1, 0x180
        ctx->r2 = ctx->r3 & 0X180;
            goto L_80057E74;
    }
    // 0x80057D2C: andi        $v0, $v1, 0x180
    ctx->r2 = ctx->r3 & 0X180;
    // 0x80057D30: bne         $v0, $zero, L_80057D7C
    if (ctx->r2 != 0) {
        // 0x80057D34: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_80057D7C;
    }
    // 0x80057D34: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80057D38: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80057D3C: lui         $a3, 0x8014
    ctx->r7 = S32(0X8014 << 16);
    // 0x80057D40: lhu         $a1, -0x6B1E($t0)
    ctx->r5 = MEM_HU(ctx->r8, -0X6B1E);
    // 0x80057D44: lhu         $a0, -0x6B1C($a3)
    ctx->r4 = MEM_HU(ctx->r7, -0X6B1C);
    // 0x80057D48: sltu        $v0, $a1, $a0
    ctx->r2 = ctx->r5 < ctx->r4 ? 1 : 0;
    // 0x80057D4C: beq         $v0, $zero, L_80057D64
    if (ctx->r2 == 0) {
        // 0x80057D50: ori         $v0, $v1, 0x80
        ctx->r2 = ctx->r3 | 0X80;
            goto L_80057D64;
    }
    // 0x80057D50: ori         $v0, $v1, 0x80
    ctx->r2 = ctx->r3 | 0X80;
    // 0x80057D54: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // 0x80057D58: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x80057D5C: j           L_80057D74
    // 0x80057D60: sh          $v0, -0x6B1E($t0)
    MEM_H(-0X6B1E, ctx->r8) = ctx->r2;
        goto L_80057D74;
    // 0x80057D60: sh          $v0, -0x6B1E($t0)
    MEM_H(-0X6B1E, ctx->r8) = ctx->r2;
L_80057D64:
    // 0x80057D64: ori         $v0, $v1, 0x100
    ctx->r2 = ctx->r3 | 0X100;
    // 0x80057D68: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // 0x80057D6C: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80057D70: sh          $v0, -0x6B1C($a3)
    MEM_H(-0X6B1C, ctx->r7) = ctx->r2;
L_80057D74:
    // 0x80057D74: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80057D78: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80057D7C:
    // 0x80057D7C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80057D80: addiu       $v0, $sp, 0x18
    ctx->r2 = ADD32(ctx->r29, 0X18);
    // 0x80057D84: jal         0x8001DC34
    // 0x80057D88: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_8001DC34(rdram, ctx);
        goto after_0;
    // 0x80057D88: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_0:
    // 0x80057D8C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80057D90: beq         $v0, $zero, L_80057E1C
    if (ctx->r2 == 0) {
        // 0x80057D94: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_80057E1C;
    }
    // 0x80057D94: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80057D98: lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X8);
    // 0x80057D9C: j           L_80057E70
    // 0x80057DA0: ori         $v0, $v0, 0x200
    ctx->r2 = ctx->r2 | 0X200;
        goto L_80057E70;
    // 0x80057DA0: ori         $v0, $v0, 0x200
    ctx->r2 = ctx->r2 | 0X200;
L_80057DA4:
    // 0x80057DA4: lhu         $v1, 0x8($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X8);
    // 0x80057DA8: andi        $v0, $v1, 0x100
    ctx->r2 = ctx->r3 & 0X100;
    // 0x80057DAC: bne         $v0, $zero, L_80057E74
    if (ctx->r2 != 0) {
        // 0x80057DB0: andi        $v0, $v1, 0x180
        ctx->r2 = ctx->r3 & 0X180;
            goto L_80057E74;
    }
    // 0x80057DB0: andi        $v0, $v1, 0x180
    ctx->r2 = ctx->r3 & 0X180;
    // 0x80057DB4: bne         $v0, $zero, L_80057DFC
    if (ctx->r2 != 0) {
        // 0x80057DB8: addu        $a0, $s3, $zero
        ctx->r4 = ADD32(ctx->r19, 0);
            goto L_80057DFC;
    }
    // 0x80057DB8: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x80057DBC: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80057DC0: lui         $a3, 0x8014
    ctx->r7 = S32(0X8014 << 16);
    // 0x80057DC4: lhu         $a1, -0x6B1E($t0)
    ctx->r5 = MEM_HU(ctx->r8, -0X6B1E);
    // 0x80057DC8: lhu         $a0, -0x6B1C($a3)
    ctx->r4 = MEM_HU(ctx->r7, -0X6B1C);
    // 0x80057DCC: sltu        $v0, $a1, $a0
    ctx->r2 = ctx->r5 < ctx->r4 ? 1 : 0;
    // 0x80057DD0: beq         $v0, $zero, L_80057DE8
    if (ctx->r2 == 0) {
        // 0x80057DD4: ori         $v0, $v1, 0x80
        ctx->r2 = ctx->r3 | 0X80;
            goto L_80057DE8;
    }
    // 0x80057DD4: ori         $v0, $v1, 0x80
    ctx->r2 = ctx->r3 | 0X80;
    // 0x80057DD8: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // 0x80057DDC: addiu       $v0, $a1, 0x1
    ctx->r2 = ADD32(ctx->r5, 0X1);
    // 0x80057DE0: j           L_80057DF8
    // 0x80057DE4: sh          $v0, -0x6B1E($t0)
    MEM_H(-0X6B1E, ctx->r8) = ctx->r2;
        goto L_80057DF8;
    // 0x80057DE4: sh          $v0, -0x6B1E($t0)
    MEM_H(-0X6B1E, ctx->r8) = ctx->r2;
L_80057DE8:
    // 0x80057DE8: ori         $v0, $v1, 0x100
    ctx->r2 = ctx->r3 | 0X100;
    // 0x80057DEC: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // 0x80057DF0: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80057DF4: sh          $v0, -0x6B1C($a3)
    MEM_H(-0X6B1C, ctx->r7) = ctx->r2;
L_80057DF8:
    // 0x80057DF8: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
L_80057DFC:
    // 0x80057DFC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80057E00: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80057E04: addiu       $v0, $sp, 0x18
    ctx->r2 = ADD32(ctx->r29, 0X18);
    // 0x80057E08: jal         0x8001DC34
    // 0x80057E0C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_8001DC34(rdram, ctx);
        goto after_1;
    // 0x80057E0C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_1:
    // 0x80057E10: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80057E14: bne         $v0, $zero, L_80057E30
    if (ctx->r2 != 0) {
        // 0x80057E18: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_80057E30;
    }
    // 0x80057E18: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_80057E1C:
    // 0x80057E1C: lhu         $v1, 0x8($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X8);
    // 0x80057E20: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80057E24: andi        $v1, $v1, 0xFDFF
    ctx->r3 = ctx->r3 & 0XFDFF;
    // 0x80057E28: j           L_8005804C
    // 0x80057E2C: sh          $v1, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r3;
        goto L_8005804C;
    // 0x80057E2C: sh          $v1, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r3;
L_80057E30:
    // 0x80057E30: lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X8);
    // 0x80057E34: j           L_80057E70
    // 0x80057E38: ori         $v0, $v0, 0x200
    ctx->r2 = ctx->r2 | 0X200;
        goto L_80057E70;
    // 0x80057E38: ori         $v0, $v0, 0x200
    ctx->r2 = ctx->r2 | 0X200;
L_80057E3C:
    // 0x80057E3C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80057E40: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80057E44: addiu       $v0, $sp, 0x18
    ctx->r2 = ADD32(ctx->r29, 0X18);
    // 0x80057E48: jal         0x8001DC34
    // 0x80057E4C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_8001DC34(rdram, ctx);
        goto after_2;
    // 0x80057E4C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_2:
    // 0x80057E50: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80057E54: beq         $v0, $zero, L_80057E68
    if (ctx->r2 == 0) {
        // 0x80057E58: nop
    
            goto L_80057E68;
    }
    // 0x80057E58: nop

    // 0x80057E5C: lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X8);
    // 0x80057E60: j           L_80057E70
    // 0x80057E64: ori         $v0, $v0, 0x200
    ctx->r2 = ctx->r2 | 0X200;
        goto L_80057E70;
    // 0x80057E64: ori         $v0, $v0, 0x200
    ctx->r2 = ctx->r2 | 0X200;
L_80057E68:
    // 0x80057E68: lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X8);
    // 0x80057E6C: andi        $v0, $v0, 0xFDFF
    ctx->r2 = ctx->r2 & 0XFDFF;
L_80057E70:
    // 0x80057E70: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
L_80057E74:
    // 0x80057E74: lhu         $v0, 0x8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X8);
    // 0x80057E78: andi        $v0, $v0, 0x200
    ctx->r2 = ctx->r2 & 0X200;
    // 0x80057E7C: beq         $v0, $zero, L_8005804C
    if (ctx->r2 == 0) {
        // 0x80057E80: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8005804C;
    }
    // 0x80057E80: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80057E84: lw          $v0, 0x1C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X1C);
    // 0x80057E88: beq         $v0, $zero, L_80057FC4
    if (ctx->r2 == 0) {
        // 0x80057E8C: lui         $v0, 0x8
        ctx->r2 = S32(0X8 << 16);
            goto L_80057FC4;
    }
    // 0x80057E8C: lui         $v0, 0x8
    ctx->r2 = S32(0X8 << 16);
    // 0x80057E90: bne         $s1, $zero, L_80057FC4
    if (ctx->r17 != 0) {
        // 0x80057E94: nop
    
            goto L_80057FC4;
    }
    // 0x80057E94: nop

    // 0x80057E98: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x80057E9C: bne         $a0, $zero, L_80057EA8
    if (ctx->r4 != 0) {
        // 0x80057EA0: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_80057EA8;
    }
    // 0x80057EA0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80057EA4: addiu       $a0, $v0, -0x1350
    ctx->r4 = ADD32(ctx->r2, -0X1350);
L_80057EA8:
    // 0x80057EA8: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80057EAC: addiu       $v1, $s1, 0x1
    ctx->r3 = ADD32(ctx->r17, 0X1);
L_80057EB0:
    // 0x80057EB0: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80057EB4: addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // 0x80057EB8: lw          $v0, 0x18($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X18);
    // 0x80057EBC: beq         $v0, $zero, L_80057EE8
    if (ctx->r2 == 0) {
        // 0x80057EC0: sll         $v0, $s1, 2
        ctx->r2 = S32(ctx->r17 << 2);
            goto L_80057EE8;
    }
    // 0x80057EC0: sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17 << 2);
    // 0x80057EC4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80057EC8: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80057ECC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80057ED0: nop

    // 0x80057ED4: bc1t        L_80057EE8
    if (c1cs) {
        // 0x80057ED8: slti        $v0, $v1, 0x4
        ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
            goto L_80057EE8;
    }
    // 0x80057ED8: slti        $v0, $v1, 0x4
    ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x80057EDC: addu        $s1, $v1, $zero
    ctx->r17 = ADD32(ctx->r3, 0);
    // 0x80057EE0: bne         $v0, $zero, L_80057EB0
    if (ctx->r2 != 0) {
        // 0x80057EE4: addiu       $v1, $s1, 0x1
        ctx->r3 = ADD32(ctx->r17, 0X1);
            goto L_80057EB0;
    }
    // 0x80057EE4: addiu       $v1, $s1, 0x1
    ctx->r3 = ADD32(ctx->r17, 0X1);
L_80057EE8:
    // 0x80057EE8: lbu         $v0, 0xA($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XA);
    // 0x80057EEC: beq         $s1, $v0, L_80057FC0
    if (ctx->r17 == ctx->r2) {
        // 0x80057EF0: sll         $v0, $s1, 2
        ctx->r2 = S32(ctx->r17 << 2);
            goto L_80057FC0;
    }
    // 0x80057EF0: sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17 << 2);
    // 0x80057EF4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80057EF8: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80057EFC: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    // 0x80057F00: beq         $a0, $zero, L_80057FC4
    if (ctx->r4 == 0) {
        // 0x80057F04: lui         $v0, 0x8
        ctx->r2 = S32(0X8 << 16);
            goto L_80057FC4;
    }
    // 0x80057F04: lui         $v0, 0x8
    ctx->r2 = S32(0X8 << 16);
    // 0x80057F08: lw          $a1, 0x14($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X14);
    // 0x80057F0C: lhu         $v1, 0x2($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X2);
    // 0x80057F10: lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X2);
    // 0x80057F14: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80057F18: bne         $v0, $zero, L_80057FC4
    if (ctx->r2 != 0) {
        // 0x80057F1C: lui         $v0, 0x8
        ctx->r2 = S32(0X8 << 16);
            goto L_80057FC4;
    }
    // 0x80057F1C: lui         $v0, 0x8
    ctx->r2 = S32(0X8 << 16);
    // 0x80057F20: addiu       $a2, $a0, 0x4
    ctx->r6 = ADD32(ctx->r4, 0X4);
    // 0x80057F24: lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X0);
    // 0x80057F28: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x80057F2C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80057F30: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80057F34: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80057F38: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80057F3C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80057F40: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x80057F44: beq         $v1, $zero, L_80057FBC
    if (ctx->r3 == 0) {
        // 0x80057F48: addu        $a1, $s0, $v0
        ctx->r5 = ADD32(ctx->r16, ctx->r2);
            goto L_80057FBC;
    }
    // 0x80057F48: addu        $a1, $s0, $v0
    ctx->r5 = ADD32(ctx->r16, ctx->r2);
    // 0x80057F4C: addiu       $t1, $s0, 0x1C
    ctx->r9 = ADD32(ctx->r16, 0X1C);
    // 0x80057F50: addiu       $t0, $a1, 0x8
    ctx->r8 = ADD32(ctx->r5, 0X8);
L_80057F54:
    // 0x80057F54: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80057F58: beq         $v0, $zero, L_80057FA4
    if (ctx->r2 == 0) {
        // 0x80057F5C: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_80057FA4;
    }
    // 0x80057F5C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80057F60: sw          $a1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r5;
L_80057F64:
    // 0x80057F64: lw          $v0, 0x4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X4);
    // 0x80057F68: beq         $v0, $zero, L_80057F74
    if (ctx->r2 == 0) {
        // 0x80057F6C: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80057F74;
    }
    // 0x80057F6C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80057F70: addiu       $a0, $a1, 0x5C
    ctx->r4 = ADD32(ctx->r5, 0X5C);
L_80057F74:
    // 0x80057F74: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    // 0x80057F78: sw          $a3, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r7;
    // 0x80057F7C: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x80057F80: addiu       $a1, $a1, 0x5C
    ctx->r5 = ADD32(ctx->r5, 0X5C);
    // 0x80057F84: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80057F88: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80057F8C: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x80057F90: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80057F94: bne         $v0, $zero, L_80057F64
    if (ctx->r2 != 0) {
        // 0x80057F98: addiu       $t0, $t0, 0x5C
        ctx->r8 = ADD32(ctx->r8, 0X5C);
            goto L_80057F64;
    }
    // 0x80057F98: addiu       $t0, $t0, 0x5C
    ctx->r8 = ADD32(ctx->r8, 0X5C);
    // 0x80057F9C: j           L_80057FAC
    // 0x80057FA0: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
        goto L_80057FAC;
    // 0x80057FA0: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
L_80057FA4:
    // 0x80057FA4: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x80057FA8: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
L_80057FAC:
    // 0x80057FAC: addiu       $t1, $t1, 0x4C
    ctx->r9 = ADD32(ctx->r9, 0X4C);
    // 0x80057FB0: slt         $v0, $t2, $v1
    ctx->r2 = SIGNED(ctx->r10) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80057FB4: bne         $v0, $zero, L_80057F54
    if (ctx->r2 != 0) {
        // 0x80057FB8: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_80057F54;
    }
    // 0x80057FB8: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_80057FBC:
    // 0x80057FBC: sb          $s1, 0xA($s0)
    MEM_B(0XA, ctx->r16) = ctx->r17;
L_80057FC0:
    // 0x80057FC0: lui         $v0, 0x8
    ctx->r2 = S32(0X8 << 16);
L_80057FC4:
    // 0x80057FC4: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x80057FC8: ori         $v0, $v0, 0xFF00
    ctx->r2 = ctx->r2 | 0XFF00;
    // 0x80057FCC: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80057FD0: lui         $v0, 0x8
    ctx->r2 = S32(0X8 << 16);
    // 0x80057FD4: bne         $v1, $v0, L_80058028
    if (ctx->r3 != ctx->r2) {
        // 0x80057FD8: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_80058028;
    }
    // 0x80057FD8: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80057FDC: lw          $v0, 0x3C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X3C);
    // 0x80057FE0: lw          $v1, -0x7764($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7764);
    // 0x80057FE4: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x80057FE8: bne         $v0, $zero, L_80058028
    if (ctx->r2 != 0) {
        // 0x80057FEC: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80058028;
    }
    // 0x80057FEC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80057FF0: lhu         $v0, 0x38($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X38);
    // 0x80057FF4: sw          $v1, 0x3C($s2)
    MEM_W(0X3C, ctx->r18) = ctx->r3;
    // 0x80057FF8: xori        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 ^ 0X10;
    // 0x80057FFC: sh          $v0, 0x38($s2)
    MEM_H(0X38, ctx->r18) = ctx->r2;
    // 0x80058000: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80058004: beq         $v0, $zero, L_80058018
    if (ctx->r2 == 0) {
        // 0x80058008: addiu       $a1, $zero, 0x120
        ctx->r5 = ADD32(0, 0X120);
            goto L_80058018;
    }
    // 0x80058008: addiu       $a1, $zero, 0x120
    ctx->r5 = ADD32(0, 0X120);
    // 0x8005800C: lw          $a0, 0x10($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X10);
    // 0x80058010: j           L_80058020
    // 0x80058014: nop

        goto L_80058020;
    // 0x80058014: nop

L_80058018:
    // 0x80058018: lw          $a0, 0x10($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X10);
    // 0x8005801C: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
L_80058020:
    // 0x80058020: jal         0x800599EC
    // 0x80058024: lui         $a2, 0x10
    ctx->r6 = S32(0X10 << 16);
    func_800599EC(rdram, ctx);
        goto after_3;
    // 0x80058024: lui         $a2, 0x10
    ctx->r6 = S32(0X10 << 16);
    after_3:
L_80058028:
    // 0x80058028: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x8005802C: beq         $v1, $zero, L_8005803C
    if (ctx->r3 == 0) {
        // 0x80058030: sw          $v1, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->r3;
            goto L_8005803C;
    }
    // 0x80058030: sw          $v1, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r3;
    // 0x80058034: addiu       $v0, $s0, 0xC
    ctx->r2 = ADD32(ctx->r16, 0XC);
    // 0x80058038: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_8005803C:
    // 0x8005803C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80058040: addiu       $v1, $s0, 0xC
    ctx->r3 = ADD32(ctx->r16, 0XC);
    // 0x80058044: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x80058048: sw          $v1, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r3;
L_8005804C:
    // 0x8005804C: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x80058050: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80058054: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80058058: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8005805C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80058060: jr          $ra
    // 0x80058064: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80058064: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80058068(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058068: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8005806C: sdc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X40, ctx->r29);
    // 0x80058070: mtc1        $a3, $f22
    ctx->f22.u32l = ctx->r7;
    // 0x80058074: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x80058078: lwc1        $f20, 0x58($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8005807C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80058080: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x80058084: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80058088: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x8005808C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80058090: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x80058094: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80058098: lbu         $v0, 0xB($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XB);
    // 0x8005809C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800580A0: beq         $v0, $zero, L_800580E4
    if (ctx->r2 == 0) {
        // 0x800580A4: addu        $s3, $a2, $zero
        ctx->r19 = ADD32(ctx->r6, 0);
            goto L_800580E4;
    }
    // 0x800580A4: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x800580A8: lhu         $v0, 0x8($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X8);
    // 0x800580AC: andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // 0x800580B0: bnel        $v0, $zero, L_800580E8
    if (ctx->r2 != 0) {
        // 0x800580B4: add.s       $f2, $f22, $f20
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f22.fl + ctx->f20.fl;
            goto L_800580E8;
    }
    goto skip_0;
    // 0x800580B4: add.s       $f2, $f22, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f22.fl + ctx->f20.fl;
    skip_0:
    // 0x800580B8: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800580BC: lhu         $v0, -0x5B70($v1)
    ctx->r2 = MEM_HU(ctx->r3, -0X5B70);
    // 0x800580C0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800580C4: sh          $v0, -0x5B70($v1)
    MEM_H(-0X5B70, ctx->r3) = ctx->r2;
    // 0x800580C8: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800580CC: addiu       $v1, $v1, -0x5B68
    ctx->r3 = ADD32(ctx->r3, -0X5B68);
    // 0x800580D0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800580D4: lbu         $a0, 0xB($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0XB);
    // 0x800580D8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800580DC: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    // 0x800580E0: sb          $zero, 0xB($s1)
    MEM_B(0XB, ctx->r17) = 0;
L_800580E4:
    // 0x800580E4: add.s       $f2, $f22, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f22.fl + ctx->f20.fl;
L_800580E8:
    // 0x800580E8: lwc1        $f0, 0x44($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X44);
    // 0x800580EC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800580F0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800580F4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800580F8: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x800580FC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80058100: addiu       $v0, $sp, 0x18
    ctx->r2 = ADD32(ctx->r29, 0X18);
    // 0x80058104: jal         0x8001DC34
    // 0x80058108: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_8001DC34(rdram, ctx);
        goto after_0;
    // 0x80058108: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_0:
    // 0x8005810C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80058110: beq         $v0, $zero, L_8005832C
    if (ctx->r2 == 0) {
        // 0x80058114: addiu       $a0, $s1, 0x28
        ctx->r4 = ADD32(ctx->r17, 0X28);
            goto L_8005832C;
    }
    // 0x80058114: addiu       $a0, $s1, 0x28
    ctx->r4 = ADD32(ctx->r17, 0X28);
    // 0x80058118: lw          $v0, 0x1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X1C);
    // 0x8005811C: beq         $v0, $zero, L_80058254
    if (ctx->r2 == 0) {
        // 0x80058120: lui         $v0, 0x8
        ctx->r2 = S32(0X8 << 16);
            goto L_80058254;
    }
    // 0x80058120: lui         $v0, 0x8
    ctx->r2 = S32(0X8 << 16);
    // 0x80058124: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    // 0x80058128: bne         $a0, $zero, L_80058138
    if (ctx->r4 != 0) {
        // 0x8005812C: addu        $t3, $zero, $zero
        ctx->r11 = ADD32(0, 0);
            goto L_80058138;
    }
    // 0x8005812C: addu        $t3, $zero, $zero
    ctx->r11 = ADD32(0, 0);
    // 0x80058130: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80058134: addiu       $a0, $v0, -0x1350
    ctx->r4 = ADD32(ctx->r2, -0X1350);
L_80058138:
    // 0x80058138: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8005813C: addiu       $v1, $t3, 0x1
    ctx->r3 = ADD32(ctx->r11, 0X1);
L_80058140:
    // 0x80058140: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80058144: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x80058148: lw          $v0, 0x18($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X18);
    // 0x8005814C: beq         $v0, $zero, L_80058178
    if (ctx->r2 == 0) {
        // 0x80058150: sll         $v0, $t3, 2
        ctx->r2 = S32(ctx->r11 << 2);
            goto L_80058178;
    }
    // 0x80058150: sll         $v0, $t3, 2
    ctx->r2 = S32(ctx->r11 << 2);
    // 0x80058154: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80058158: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8005815C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80058160: nop

    // 0x80058164: bc1t        L_80058178
    if (c1cs) {
        // 0x80058168: slti        $v0, $v1, 0x4
        ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
            goto L_80058178;
    }
    // 0x80058168: slti        $v0, $v1, 0x4
    ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x8005816C: addu        $t3, $v1, $zero
    ctx->r11 = ADD32(ctx->r3, 0);
    // 0x80058170: bne         $v0, $zero, L_80058140
    if (ctx->r2 != 0) {
        // 0x80058174: addiu       $v1, $t3, 0x1
        ctx->r3 = ADD32(ctx->r11, 0X1);
            goto L_80058140;
    }
    // 0x80058174: addiu       $v1, $t3, 0x1
    ctx->r3 = ADD32(ctx->r11, 0X1);
L_80058178:
    // 0x80058178: lbu         $v0, 0xA($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XA);
    // 0x8005817C: beq         $t3, $v0, L_80058250
    if (ctx->r11 == ctx->r2) {
        // 0x80058180: sll         $v0, $t3, 2
        ctx->r2 = S32(ctx->r11 << 2);
            goto L_80058250;
    }
    // 0x80058180: sll         $v0, $t3, 2
    ctx->r2 = S32(ctx->r11 << 2);
    // 0x80058184: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x80058188: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x8005818C: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    // 0x80058190: beq         $a0, $zero, L_80058254
    if (ctx->r4 == 0) {
        // 0x80058194: lui         $v0, 0x8
        ctx->r2 = S32(0X8 << 16);
            goto L_80058254;
    }
    // 0x80058194: lui         $v0, 0x8
    ctx->r2 = S32(0X8 << 16);
    // 0x80058198: lw          $a1, 0x14($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X14);
    // 0x8005819C: lhu         $v1, 0x2($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X2);
    // 0x800581A0: lhu         $v0, 0x2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X2);
    // 0x800581A4: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800581A8: bne         $v0, $zero, L_80058254
    if (ctx->r2 != 0) {
        // 0x800581AC: lui         $v0, 0x8
        ctx->r2 = S32(0X8 << 16);
            goto L_80058254;
    }
    // 0x800581AC: lui         $v0, 0x8
    ctx->r2 = S32(0X8 << 16);
    // 0x800581B0: addiu       $a2, $a0, 0x4
    ctx->r6 = ADD32(ctx->r4, 0X4);
    // 0x800581B4: lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X0);
    // 0x800581B8: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x800581BC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800581C0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800581C4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800581C8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800581CC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800581D0: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800581D4: beq         $v1, $zero, L_8005824C
    if (ctx->r3 == 0) {
        // 0x800581D8: addu        $a1, $s1, $v0
        ctx->r5 = ADD32(ctx->r17, ctx->r2);
            goto L_8005824C;
    }
    // 0x800581D8: addu        $a1, $s1, $v0
    ctx->r5 = ADD32(ctx->r17, ctx->r2);
    // 0x800581DC: addiu       $t1, $s1, 0x1C
    ctx->r9 = ADD32(ctx->r17, 0X1C);
    // 0x800581E0: addiu       $t0, $a1, 0x8
    ctx->r8 = ADD32(ctx->r5, 0X8);
L_800581E4:
    // 0x800581E4: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800581E8: beq         $v0, $zero, L_80058234
    if (ctx->r2 == 0) {
        // 0x800581EC: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_80058234;
    }
    // 0x800581EC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x800581F0: sw          $a1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r5;
L_800581F4:
    // 0x800581F4: lw          $v0, 0x4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X4);
    // 0x800581F8: beq         $v0, $zero, L_80058204
    if (ctx->r2 == 0) {
        // 0x800581FC: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80058204;
    }
    // 0x800581FC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80058200: addiu       $a0, $a1, 0x5C
    ctx->r4 = ADD32(ctx->r5, 0X5C);
L_80058204:
    // 0x80058204: sw          $a0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r4;
    // 0x80058208: sw          $a3, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r7;
    // 0x8005820C: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x80058210: addiu       $a1, $a1, 0x5C
    ctx->r5 = ADD32(ctx->r5, 0X5C);
    // 0x80058214: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80058218: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8005821C: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x80058220: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80058224: bne         $v0, $zero, L_800581F4
    if (ctx->r2 != 0) {
        // 0x80058228: addiu       $t0, $t0, 0x5C
        ctx->r8 = ADD32(ctx->r8, 0X5C);
            goto L_800581F4;
    }
    // 0x80058228: addiu       $t0, $t0, 0x5C
    ctx->r8 = ADD32(ctx->r8, 0X5C);
    // 0x8005822C: j           L_8005823C
    // 0x80058230: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
        goto L_8005823C;
    // 0x80058230: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
L_80058234:
    // 0x80058234: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x80058238: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
L_8005823C:
    // 0x8005823C: addiu       $t1, $t1, 0x4C
    ctx->r9 = ADD32(ctx->r9, 0X4C);
    // 0x80058240: slt         $v0, $t2, $v1
    ctx->r2 = SIGNED(ctx->r10) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80058244: bne         $v0, $zero, L_800581E4
    if (ctx->r2 != 0) {
        // 0x80058248: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_800581E4;
    }
    // 0x80058248: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_8005824C:
    // 0x8005824C: sb          $t3, 0xA($s1)
    MEM_B(0XA, ctx->r17) = ctx->r11;
L_80058250:
    // 0x80058250: lui         $v0, 0x8
    ctx->r2 = S32(0X8 << 16);
L_80058254:
    // 0x80058254: lw          $v1, 0x8($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X8);
    // 0x80058258: ori         $v0, $v0, 0xFF00
    ctx->r2 = ctx->r2 | 0XFF00;
    // 0x8005825C: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x80058260: lui         $v0, 0x8
    ctx->r2 = S32(0X8 << 16);
    // 0x80058264: bne         $v1, $v0, L_800582B8
    if (ctx->r3 != ctx->r2) {
        // 0x80058268: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_800582B8;
    }
    // 0x80058268: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8005826C: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
    // 0x80058270: lw          $v1, -0x7764($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X7764);
    // 0x80058274: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x80058278: bne         $v0, $zero, L_800582B8
    if (ctx->r2 != 0) {
        // 0x8005827C: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800582B8;
    }
    // 0x8005827C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80058280: lhu         $v0, 0x38($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X38);
    // 0x80058284: sw          $v1, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r3;
    // 0x80058288: xori        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 ^ 0X10;
    // 0x8005828C: sh          $v0, 0x38($s0)
    MEM_H(0X38, ctx->r16) = ctx->r2;
    // 0x80058290: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    // 0x80058294: beq         $v0, $zero, L_800582A8
    if (ctx->r2 == 0) {
        // 0x80058298: addiu       $a1, $zero, 0x120
        ctx->r5 = ADD32(0, 0X120);
            goto L_800582A8;
    }
    // 0x80058298: addiu       $a1, $zero, 0x120
    ctx->r5 = ADD32(0, 0X120);
    // 0x8005829C: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    // 0x800582A0: j           L_800582B0
    // 0x800582A4: nop

        goto L_800582B0;
    // 0x800582A4: nop

L_800582A8:
    // 0x800582A8: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    // 0x800582AC: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
L_800582B0:
    // 0x800582B0: jal         0x800599EC
    // 0x800582B4: lui         $a2, 0x10
    ctx->r6 = S32(0X10 << 16);
    func_800599EC(rdram, ctx);
        goto after_1;
    // 0x800582B4: lui         $a2, 0x10
    ctx->r6 = S32(0X10 << 16);
    after_1:
L_800582B8:
    // 0x800582B8: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800582BC: lwc1        $f2, 0x28($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X28);
    // 0x800582C0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800582C4: lwc1        $f4, -0x525C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X525C);
    // 0x800582C8: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800582CC: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800582D0: nop

    // 0x800582D4: bc1f        L_800582E4
    if (!c1cs) {
        // 0x800582D8: swc1        $f0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
            goto L_800582E4;
    }
    // 0x800582D8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800582DC: j           L_800582EC
    // 0x800582E0: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
        goto L_800582EC;
    // 0x800582E0: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
L_800582E4:
    // 0x800582E4: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800582E8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
L_800582EC:
    // 0x800582EC: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800582F0: add.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f0.fl;
    // 0x800582F4: addiu       $a0, $s1, 0x28
    ctx->r4 = ADD32(ctx->r17, 0X28);
    // 0x800582F8: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x800582FC: jal         0x80059B50
    // 0x80058300: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_80059B50(rdram, ctx);
        goto after_2;
    // 0x80058300: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_2:
    // 0x80058304: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x80058308: beq         $v1, $zero, L_80058318
    if (ctx->r3 == 0) {
        // 0x8005830C: sw          $v1, 0xC($s1)
        MEM_W(0XC, ctx->r17) = ctx->r3;
            goto L_80058318;
    }
    // 0x8005830C: sw          $v1, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r3;
    // 0x80058310: addiu       $v0, $s1, 0xC
    ctx->r2 = ADD32(ctx->r17, 0XC);
    // 0x80058314: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_80058318:
    // 0x80058318: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005831C: addiu       $v1, $s1, 0xC
    ctx->r3 = ADD32(ctx->r17, 0XC);
    // 0x80058320: sw          $zero, 0x10($s1)
    MEM_W(0X10, ctx->r17) = 0;
    // 0x80058324: j           L_8005833C
    // 0x80058328: sw          $v1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r3;
        goto L_8005833C;
    // 0x80058328: sw          $v1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r3;
L_8005832C:
    // 0x8005832C: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80058330: jal         0x80059B50
    // 0x80058334: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_80059B50(rdram, ctx);
        goto after_3;
    // 0x80058334: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_3:
    // 0x80058338: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8005833C:
    // 0x8005833C: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x80058340: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80058344: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80058348: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8005834C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80058350: ldc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X40);
    // 0x80058354: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x80058358: jr          $ra
    // 0x8005835C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8005835C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_80058360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058360: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80058364: sw          $ra, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r31;
    // 0x80058368: sw          $fp, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r30;
    // 0x8005836C: sw          $s7, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r23;
    // 0x80058370: sw          $s6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r22;
    // 0x80058374: sw          $s5, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r21;
    // 0x80058378: sw          $s4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r20;
    // 0x8005837C: sw          $s3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r19;
    // 0x80058380: sw          $s2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r18;
    // 0x80058384: sw          $s1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r17;
    // 0x80058388: sw          $s0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r16;
    // 0x8005838C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80058390: lw          $t0, 0x30($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X30);
    // 0x80058394: lw          $s4, 0xA8($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XA8);
    // 0x80058398: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    // 0x8005839C: lw          $t2, 0xAC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XAC);
    // 0x800583A0: beq         $v0, $zero, L_80058548
    if (ctx->r2 == 0) {
        // 0x800583A4: addu        $fp, $a3, $zero
        ctx->r30 = ADD32(ctx->r7, 0);
            goto L_80058548;
    }
    // 0x800583A4: addu        $fp, $a3, $zero
    ctx->r30 = ADD32(ctx->r7, 0);
    // 0x800583A8: sll         $v0, $a2, 3
    ctx->r2 = S32(ctx->r6 << 3);
    // 0x800583AC: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800583B0: sll         $t1, $v0, 2
    ctx->r9 = S32(ctx->r2 << 2);
    // 0x800583B4: addiu       $s5, $sp, 0x10
    ctx->r21 = ADD32(ctx->r29, 0X10);
    // 0x800583B8: addiu       $s6, $fp, 0xC
    ctx->r22 = ADD32(ctx->r30, 0XC);
    // 0x800583BC: addiu       $s7, $fp, 0x18
    ctx->r23 = ADD32(ctx->r30, 0X18);
L_800583C0:
    // 0x800583C0: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800583C4: addu        $v0, $t0, $s2
    ctx->r2 = ADD32(ctx->r8, ctx->r18);
L_800583C8:
    // 0x800583C8: addu        $v1, $a1, $s2
    ctx->r3 = ADD32(ctx->r5, ctx->r18);
    // 0x800583CC: lbu         $a3, 0x0($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X0);
    // 0x800583D0: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800583D4: bne         $a3, $v0, L_80058528
    if (ctx->r7 != ctx->r2) {
        // 0x800583D8: nop
    
            goto L_80058528;
    }
    // 0x800583D8: nop

    // 0x800583DC: beq         $a3, $zero, L_800583F8
    if (ctx->r7 == 0) {
        // 0x800583E0: addu        $v0, $t0, $s2
        ctx->r2 = ADD32(ctx->r8, ctx->r18);
            goto L_800583F8;
    }
    // 0x800583E0: addu        $v0, $t0, $s2
    ctx->r2 = ADD32(ctx->r8, ctx->r18);
    // 0x800583E4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800583E8: slti        $v0, $s2, 0x6
    ctx->r2 = SIGNED(ctx->r18) < 0X6 ? 1 : 0;
    // 0x800583EC: bne         $v0, $zero, L_800583C8
    if (ctx->r2 != 0) {
        // 0x800583F0: addu        $v0, $t0, $s2
        ctx->r2 = ADD32(ctx->r8, ctx->r18);
            goto L_800583C8;
    }
    // 0x800583F0: addu        $v0, $t0, $s2
    ctx->r2 = ADD32(ctx->r8, ctx->r18);
    // 0x800583F4: addu        $v1, $a1, $s2
    ctx->r3 = ADD32(ctx->r5, ctx->r18);
L_800583F8:
    // 0x800583F8: lbu         $a3, 0x0($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X0);
    // 0x800583FC: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80058400: bne         $a3, $v0, L_80058528
    if (ctx->r7 != ctx->r2) {
        // 0x80058404: nop
    
            goto L_80058528;
    }
    // 0x80058404: nop

    // 0x80058408: bne         $a3, $zero, L_80058528
    if (ctx->r7 != 0) {
        // 0x8005840C: nop
    
            goto L_80058528;
    }
    // 0x8005840C: nop

    // 0x80058410: lbu         $v1, 0x7($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0X7);
    // 0x80058414: slt         $v0, $a2, $v1
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80058418: bne         $v0, $zero, L_80058434
    if (ctx->r2 != 0) {
        // 0x8005841C: addu        $v0, $t0, $t1
        ctx->r2 = ADD32(ctx->r8, ctx->r9);
            goto L_80058434;
    }
    // 0x8005841C: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x80058420: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80058424: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x80058428: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005842C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80058430: addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
L_80058434:
    // 0x80058434: beq         $s4, $zero, L_80058444
    if (ctx->r20 == 0) {
        // 0x80058438: addiu       $s3, $v0, 0x8
        ctx->r19 = ADD32(ctx->r2, 0X8);
            goto L_80058444;
    }
    // 0x80058438: addiu       $s3, $v0, 0x8
    ctx->r19 = ADD32(ctx->r2, 0X8);
    // 0x8005843C: bne         $t2, $zero, L_800584E0
    if (ctx->r10 != 0) {
        // 0x80058440: addu        $s1, $s4, $zero
        ctx->r17 = ADD32(ctx->r20, 0);
            goto L_800584E0;
    }
    // 0x80058440: addu        $s1, $s4, $zero
    ctx->r17 = ADD32(ctx->r20, 0);
L_80058444:
    // 0x80058444: lbu         $v1, 0x6($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0X6);
    // 0x80058448: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8005844C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80058450: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80058454: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80058458: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005845C: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x80058460: addu        $s0, $a0, $v0
    ctx->r16 = ADD32(ctx->r4, ctx->r2);
    // 0x80058464: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80058468: bne         $v0, $zero, L_80058498
    if (ctx->r2 != 0) {
        // 0x8005846C: addiu       $a1, $s0, 0x1C
        ctx->r5 = ADD32(ctx->r16, 0X1C);
            goto L_80058498;
    }
    // 0x8005846C: addiu       $a1, $s0, 0x1C
    ctx->r5 = ADD32(ctx->r16, 0X1C);
    // 0x80058470: beq         $s4, $zero, L_80058490
    if (ctx->r20 == 0) {
        // 0x80058474: addu        $s1, $s4, $zero
        ctx->r17 = ADD32(ctx->r20, 0);
            goto L_80058490;
    }
    // 0x80058474: addu        $s1, $s4, $zero
    ctx->r17 = ADD32(ctx->r20, 0);
    // 0x80058478: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8005847C: addiu       $a1, $s0, 0x1C
    ctx->r5 = ADD32(ctx->r16, 0X1C);
    // 0x80058480: jal         0x80018EF4
    // 0x80058484: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    zmemcpy(rdram, ctx);
        goto after_0;
    // 0x80058484: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_0:
    // 0x80058488: j           L_800584E4
    // 0x8005848C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
        goto L_800584E4;
    // 0x8005848C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_80058490:
    // 0x80058490: j           L_800584E0
    // 0x80058494: addiu       $s1, $s0, 0x1C
    ctx->r17 = ADD32(ctx->r16, 0X1C);
        goto L_800584E0;
    // 0x80058494: addiu       $s1, $s0, 0x1C
    ctx->r17 = ADD32(ctx->r16, 0X1C);
L_80058498:
    // 0x80058498: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_8005849C:
    // 0x8005849C: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x800584A0: bnel        $v0, $zero, L_800584B4
    if (ctx->r2 != 0) {
        // 0x800584A4: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800584B4;
    }
    goto skip_0;
    // 0x800584A4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x800584A8: bne         $s4, $zero, L_800584C8
    if (ctx->r20 != 0) {
        // 0x800584AC: addu        $s1, $s4, $zero
        ctx->r17 = ADD32(ctx->r20, 0);
            goto L_800584C8;
    }
    // 0x800584AC: addu        $s1, $s4, $zero
    ctx->r17 = ADD32(ctx->r20, 0);
    // 0x800584B0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_800584B4:
    // 0x800584B4: andi        $v1, $s2, 0x1
    ctx->r3 = ctx->r18 & 0X1;
    // 0x800584B8: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800584BC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800584C0: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x800584C4: addu        $s1, $s5, $v0
    ctx->r17 = ADD32(ctx->r21, ctx->r2);
L_800584C8:
    // 0x800584C8: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x800584CC: jal         0x800191C4
    // 0x800584D0: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_800191C4(rdram, ctx);
        goto after_1;
    // 0x800584D0: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_1:
    // 0x800584D4: lw          $s0, 0x8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X8);
    // 0x800584D8: bne         $s0, $zero, L_8005849C
    if (ctx->r16 != 0) {
        // 0x800584DC: addu        $a1, $s1, $zero
        ctx->r5 = ADD32(ctx->r17, 0);
            goto L_8005849C;
    }
    // 0x800584DC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
L_800584E0:
    // 0x800584E0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_800584E4:
    // 0x800584E4: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x800584E8: jal         0x800193E8
    // 0x800584EC: addu        $a2, $fp, $zero
    ctx->r6 = ADD32(ctx->r30, 0);
    func_800193E8(rdram, ctx);
        goto after_2;
    // 0x800584EC: addu        $a2, $fp, $zero
    ctx->r6 = ADD32(ctx->r30, 0);
    after_2:
    // 0x800584F0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800584F4: addiu       $a1, $s3, 0xC
    ctx->r5 = ADD32(ctx->r19, 0XC);
    // 0x800584F8: jal         0x800194A4
    // 0x800584FC: addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    func_800194A4(rdram, ctx);
        goto after_3;
    // 0x800584FC: addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    after_3:
    // 0x80058500: jal         0x8001CF58
    // 0x80058504: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    normalize_vector(rdram, ctx);
        goto after_4;
    // 0x80058504: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    after_4:
    // 0x80058508: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8005850C: addiu       $a1, $s3, 0x18
    ctx->r5 = ADD32(ctx->r19, 0X18);
    // 0x80058510: jal         0x800194A4
    // 0x80058514: addu        $a2, $s7, $zero
    ctx->r6 = ADD32(ctx->r23, 0);
    func_800194A4(rdram, ctx);
        goto after_5;
    // 0x80058514: addu        $a2, $s7, $zero
    ctx->r6 = ADD32(ctx->r23, 0);
    after_5:
    // 0x80058518: jal         0x8001CF58
    // 0x8005851C: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    normalize_vector(rdram, ctx);
        goto after_6;
    // 0x8005851C: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    after_6:
    // 0x80058520: j           L_8005854C
    // 0x80058524: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8005854C;
    // 0x80058524: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80058528:
    // 0x80058528: lbu         $v0, 0x7($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X7);
    // 0x8005852C: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x80058530: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80058534: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80058538: addu        $v1, $t0, $v1
    ctx->r3 = ADD32(ctx->r8, ctx->r3);
    // 0x8005853C: lbu         $v0, 0x8($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X8);
    // 0x80058540: bne         $v0, $zero, L_800583C0
    if (ctx->r2 != 0) {
        // 0x80058544: addiu       $t0, $v1, 0x8
        ctx->r8 = ADD32(ctx->r3, 0X8);
            goto L_800583C0;
    }
    // 0x80058544: addiu       $t0, $v1, 0x8
    ctx->r8 = ADD32(ctx->r3, 0X8);
L_80058548:
    // 0x80058548: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8005854C:
    // 0x8005854C: lw          $ra, 0x94($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X94);
    // 0x80058550: lw          $fp, 0x90($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X90);
    // 0x80058554: lw          $s7, 0x8C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X8C);
    // 0x80058558: lw          $s6, 0x88($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X88);
    // 0x8005855C: lw          $s5, 0x84($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X84);
    // 0x80058560: lw          $s4, 0x80($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X80);
    // 0x80058564: lw          $s3, 0x7C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X7C);
    // 0x80058568: lw          $s2, 0x78($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X78);
    // 0x8005856C: lw          $s1, 0x74($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X74);
    // 0x80058570: lw          $s0, 0x70($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X70);
    // 0x80058574: jr          $ra
    // 0x80058578: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x80058578: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_8005857C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005857C: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80058580: sw          $s7, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r23;
    // 0x80058584: addu        $s7, $a1, $zero
    ctx->r23 = ADD32(ctx->r5, 0);
    // 0x80058588: sw          $s5, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r21;
    // 0x8005858C: sw          $ra, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r31;
    // 0x80058590: sw          $fp, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r30;
    // 0x80058594: sw          $s6, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r22;
    // 0x80058598: sw          $s4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r20;
    // 0x8005859C: sw          $s3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r19;
    // 0x800585A0: sw          $s2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r18;
    // 0x800585A4: sw          $s1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r17;
    // 0x800585A8: sw          $s0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r16;
    // 0x800585AC: sw          $a3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r7;
    // 0x800585B0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800585B4: lw          $fp, 0xA8($sp)
    ctx->r30 = MEM_W(ctx->r29, 0XA8);
    // 0x800585B8: lw          $s6, 0xAC($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XAC);
    // 0x800585BC: lw          $t0, 0xB0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB0);
    // 0x800585C0: lw          $a3, 0x30($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X30);
    // 0x800585C4: bne         $s7, $zero, L_80058604
    if (ctx->r23 != 0) {
        // 0x800585C8: addu        $s5, $zero, $zero
        ctx->r21 = ADD32(0, 0);
            goto L_80058604;
    }
    // 0x800585C8: addu        $s5, $zero, $zero
    ctx->r21 = ADD32(0, 0);
    // 0x800585CC: lw          $t1, 0xA4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA4);
    // 0x800585D0: lw          $s5, 0x0($t1)
    ctx->r21 = MEM_W(ctx->r9, 0X0);
    // 0x800585D4: blez        $s5, L_80058660
    if (SIGNED(ctx->r21) <= 0) {
        // 0x800585D8: nop
    
            goto L_80058660;
    }
    // 0x800585D8: nop

L_800585DC:
    // 0x800585DC: lbu         $v1, 0x7($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X7);
    // 0x800585E0: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // 0x800585E4: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x800585E8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800585EC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800585F0: addu        $v0, $a3, $v0
    ctx->r2 = ADD32(ctx->r7, ctx->r2);
    // 0x800585F4: bgtz        $s5, L_800585DC
    if (SIGNED(ctx->r21) > 0) {
        // 0x800585F8: addiu       $a3, $v0, 0x8
        ctx->r7 = ADD32(ctx->r2, 0X8);
            goto L_800585DC;
    }
    // 0x800585F8: addiu       $a3, $v0, 0x8
    ctx->r7 = ADD32(ctx->r2, 0X8);
    // 0x800585FC: j           L_80058660
    // 0x80058600: nop

        goto L_80058660;
    // 0x80058600: nop

L_80058604:
    // 0x80058604: lbu         $v0, 0x0($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X0);
    // 0x80058608: beq         $v0, $zero, L_800587C0
    if (ctx->r2 == 0) {
        // 0x8005860C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800587C0;
    }
    // 0x8005860C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80058610:
    // 0x80058610: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80058614: addu        $v0, $a3, $s2
    ctx->r2 = ADD32(ctx->r7, ctx->r18);
L_80058618:
    // 0x80058618: addu        $v1, $s7, $s2
    ctx->r3 = ADD32(ctx->r23, ctx->r18);
    // 0x8005861C: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
    // 0x80058620: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80058624: bne         $a1, $v0, L_80058798
    if (ctx->r5 != ctx->r2) {
        // 0x80058628: nop
    
            goto L_80058798;
    }
    // 0x80058628: nop

    // 0x8005862C: beq         $a1, $zero, L_80058648
    if (ctx->r5 == 0) {
        // 0x80058630: addu        $v0, $a3, $s2
        ctx->r2 = ADD32(ctx->r7, ctx->r18);
            goto L_80058648;
    }
    // 0x80058630: addu        $v0, $a3, $s2
    ctx->r2 = ADD32(ctx->r7, ctx->r18);
    // 0x80058634: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80058638: slti        $v0, $s2, 0x6
    ctx->r2 = SIGNED(ctx->r18) < 0X6 ? 1 : 0;
    // 0x8005863C: bne         $v0, $zero, L_80058618
    if (ctx->r2 != 0) {
        // 0x80058640: addu        $v0, $a3, $s2
        ctx->r2 = ADD32(ctx->r7, ctx->r18);
            goto L_80058618;
    }
    // 0x80058640: addu        $v0, $a3, $s2
    ctx->r2 = ADD32(ctx->r7, ctx->r18);
    // 0x80058644: addu        $v1, $s7, $s2
    ctx->r3 = ADD32(ctx->r23, ctx->r18);
L_80058648:
    // 0x80058648: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
    // 0x8005864C: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80058650: bne         $a1, $v0, L_80058798
    if (ctx->r5 != ctx->r2) {
        // 0x80058654: nop
    
            goto L_80058798;
    }
    // 0x80058654: nop

    // 0x80058658: bne         $a1, $zero, L_80058798
    if (ctx->r5 != 0) {
        // 0x8005865C: nop
    
            goto L_80058798;
    }
    // 0x8005865C: nop

L_80058660:
    // 0x80058660: lbu         $v1, 0x7($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X7);
    // 0x80058664: slt         $v0, $a2, $v1
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80058668: beq         $v0, $zero, L_80058678
    if (ctx->r2 == 0) {
        // 0x8005866C: sll         $v0, $a2, 3
        ctx->r2 = S32(ctx->r6 << 3);
            goto L_80058678;
    }
    // 0x8005866C: sll         $v0, $a2, 3
    ctx->r2 = S32(ctx->r6 << 3);
    // 0x80058670: j           L_80058684
    // 0x80058674: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
        goto L_80058684;
    // 0x80058674: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
L_80058678:
    // 0x80058678: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8005867C: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x80058680: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
L_80058684:
    // 0x80058684: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80058688: addu        $v0, $a3, $v0
    ctx->r2 = ADD32(ctx->r7, ctx->r2);
    // 0x8005868C: beq         $s6, $zero, L_8005869C
    if (ctx->r22 == 0) {
        // 0x80058690: addiu       $s4, $v0, 0x8
        ctx->r20 = ADD32(ctx->r2, 0X8);
            goto L_8005869C;
    }
    // 0x80058690: addiu       $s4, $v0, 0x8
    ctx->r20 = ADD32(ctx->r2, 0X8);
    // 0x80058694: bne         $t0, $zero, L_8005873C
    if (ctx->r8 != 0) {
        // 0x80058698: addu        $s1, $s6, $zero
        ctx->r17 = ADD32(ctx->r22, 0);
            goto L_8005873C;
    }
    // 0x80058698: addu        $s1, $s6, $zero
    ctx->r17 = ADD32(ctx->r22, 0);
L_8005869C:
    // 0x8005869C: lbu         $v1, 0x6($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X6);
    // 0x800586A0: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800586A4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800586A8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800586AC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800586B0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800586B4: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800586B8: addu        $s0, $a0, $v0
    ctx->r16 = ADD32(ctx->r4, ctx->r2);
    // 0x800586BC: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x800586C0: bne         $v0, $zero, L_800586F0
    if (ctx->r2 != 0) {
        // 0x800586C4: addiu       $a1, $s0, 0x1C
        ctx->r5 = ADD32(ctx->r16, 0X1C);
            goto L_800586F0;
    }
    // 0x800586C4: addiu       $a1, $s0, 0x1C
    ctx->r5 = ADD32(ctx->r16, 0X1C);
    // 0x800586C8: beq         $s6, $zero, L_800586E8
    if (ctx->r22 == 0) {
        // 0x800586CC: addu        $s1, $s6, $zero
        ctx->r17 = ADD32(ctx->r22, 0);
            goto L_800586E8;
    }
    // 0x800586CC: addu        $s1, $s6, $zero
    ctx->r17 = ADD32(ctx->r22, 0);
    // 0x800586D0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800586D4: addiu       $a1, $s0, 0x1C
    ctx->r5 = ADD32(ctx->r16, 0X1C);
    // 0x800586D8: jal         0x80018EF4
    // 0x800586DC: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    zmemcpy(rdram, ctx);
        goto after_0;
    // 0x800586DC: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_0:
    // 0x800586E0: j           L_80058740
    // 0x800586E4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
        goto L_80058740;
    // 0x800586E4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_800586E8:
    // 0x800586E8: j           L_8005873C
    // 0x800586EC: addiu       $s1, $s0, 0x1C
    ctx->r17 = ADD32(ctx->r16, 0X1C);
        goto L_8005873C;
    // 0x800586EC: addiu       $s1, $s0, 0x1C
    ctx->r17 = ADD32(ctx->r16, 0X1C);
L_800586F0:
    // 0x800586F0: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800586F4: addiu       $s3, $sp, 0x10
    ctx->r19 = ADD32(ctx->r29, 0X10);
L_800586F8:
    // 0x800586F8: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x800586FC: bnel        $v0, $zero, L_80058710
    if (ctx->r2 != 0) {
        // 0x80058700: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_80058710;
    }
    goto skip_0;
    // 0x80058700: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_0:
    // 0x80058704: bne         $s6, $zero, L_80058724
    if (ctx->r22 != 0) {
        // 0x80058708: addu        $s1, $s6, $zero
        ctx->r17 = ADD32(ctx->r22, 0);
            goto L_80058724;
    }
    // 0x80058708: addu        $s1, $s6, $zero
    ctx->r17 = ADD32(ctx->r22, 0);
    // 0x8005870C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80058710:
    // 0x80058710: andi        $v1, $s2, 0x1
    ctx->r3 = ctx->r18 & 0X1;
    // 0x80058714: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80058718: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8005871C: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80058720: addu        $s1, $s3, $v0
    ctx->r17 = ADD32(ctx->r19, ctx->r2);
L_80058724:
    // 0x80058724: addiu       $a0, $s0, 0x1C
    ctx->r4 = ADD32(ctx->r16, 0X1C);
    // 0x80058728: jal         0x800191C4
    // 0x8005872C: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_800191C4(rdram, ctx);
        goto after_1;
    // 0x8005872C: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_1:
    // 0x80058730: lw          $s0, 0x8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X8);
    // 0x80058734: bne         $s0, $zero, L_800586F8
    if (ctx->r16 != 0) {
        // 0x80058738: addu        $a1, $s1, $zero
        ctx->r5 = ADD32(ctx->r17, 0);
            goto L_800586F8;
    }
    // 0x80058738: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
L_8005873C:
    // 0x8005873C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_80058740:
    // 0x80058740: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x80058744: jal         0x800193E8
    // 0x80058748: addu        $a2, $fp, $zero
    ctx->r6 = ADD32(ctx->r30, 0);
    func_800193E8(rdram, ctx);
        goto after_2;
    // 0x80058748: addu        $a2, $fp, $zero
    ctx->r6 = ADD32(ctx->r30, 0);
    after_2:
    // 0x8005874C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80058750: addiu       $a1, $s4, 0xC
    ctx->r5 = ADD32(ctx->r20, 0XC);
    // 0x80058754: addiu       $s0, $fp, 0xC
    ctx->r16 = ADD32(ctx->r30, 0XC);
    // 0x80058758: jal         0x800194A4
    // 0x8005875C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_800194A4(rdram, ctx);
        goto after_3;
    // 0x8005875C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_3:
    // 0x80058760: jal         0x8001CF58
    // 0x80058764: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    normalize_vector(rdram, ctx);
        goto after_4;
    // 0x80058764: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_4:
    // 0x80058768: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8005876C: addiu       $a1, $s4, 0x18
    ctx->r5 = ADD32(ctx->r20, 0X18);
    // 0x80058770: addiu       $s0, $fp, 0x18
    ctx->r16 = ADD32(ctx->r30, 0X18);
    // 0x80058774: jal         0x800194A4
    // 0x80058778: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_800194A4(rdram, ctx);
        goto after_5;
    // 0x80058778: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_5:
    // 0x8005877C: jal         0x8001CF58
    // 0x80058780: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    normalize_vector(rdram, ctx);
        goto after_6;
    // 0x80058780: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_6:
    // 0x80058784: beq         $s7, $zero, L_800587C0
    if (ctx->r23 == 0) {
        // 0x80058788: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800587C0;
    }
    // 0x80058788: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8005878C: lw          $t1, 0xA4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA4);
    // 0x80058790: j           L_800587C0
    // 0x80058794: sw          $s5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r21;
        goto L_800587C0;
    // 0x80058794: sw          $s5, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r21;
L_80058798:
    // 0x80058798: lbu         $v0, 0x7($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X7);
    // 0x8005879C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800587A0: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x800587A4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800587A8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800587AC: addu        $v1, $a3, $v1
    ctx->r3 = ADD32(ctx->r7, ctx->r3);
    // 0x800587B0: lbu         $v0, 0x8($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X8);
    // 0x800587B4: bne         $v0, $zero, L_80058610
    if (ctx->r2 != 0) {
        // 0x800587B8: addiu       $a3, $v1, 0x8
        ctx->r7 = ADD32(ctx->r3, 0X8);
            goto L_80058610;
    }
    // 0x800587B8: addiu       $a3, $v1, 0x8
    ctx->r7 = ADD32(ctx->r3, 0X8);
    // 0x800587BC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800587C0:
    // 0x800587C0: lw          $ra, 0x94($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X94);
    // 0x800587C4: lw          $fp, 0x90($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X90);
    // 0x800587C8: lw          $s7, 0x8C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X8C);
    // 0x800587CC: lw          $s6, 0x88($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X88);
    // 0x800587D0: lw          $s5, 0x84($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X84);
    // 0x800587D4: lw          $s4, 0x80($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X80);
    // 0x800587D8: lw          $s3, 0x7C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X7C);
    // 0x800587DC: lw          $s2, 0x78($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X78);
    // 0x800587E0: lw          $s1, 0x74($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X74);
    // 0x800587E4: lw          $s0, 0x70($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X70);
    // 0x800587E8: jr          $ra
    // 0x800587EC: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x800587EC: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void meshdef1_offset_convert(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800587F0: lw          $t5, 0x10($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X10);
    // 0x800587F4: beq         $a0, $zero, L_80058940
    if (ctx->r4 == 0) {
        // 0x800587F8: lui         $t6, 0x10
        ctx->r14 = S32(0X10 << 16);
            goto L_80058940;
    }
    // 0x800587F8: lui         $t6, 0x10
    ctx->r14 = S32(0X10 << 16);
    // 0x800587FC: ori         $t6, $t6, 0x8
    ctx->r14 = ctx->r14 | 0X8;
    // 0x80058800: lui         $t4, 0x3F00
    ctx->r12 = S32(0X3F00 << 16);
L_80058804:
    // 0x80058804: lw          $v0, 0x0($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X0);
    // 0x80058808: beq         $v0, $zero, L_80058834
    if (ctx->r2 == 0) {
        // 0x8005880C: addu        $t3, $a2, $zero
        ctx->r11 = ADD32(ctx->r6, 0);
            goto L_80058834;
    }
    // 0x8005880C: addu        $t3, $a2, $zero
    ctx->r11 = ADD32(ctx->r6, 0);
    // 0x80058810: addu        $v1, $t5, $zero
    ctx->r3 = ADD32(ctx->r13, 0);
L_80058814:
    // 0x80058814: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80058818: bne         $a0, $v0, L_80058828
    if (ctx->r4 != ctx->r2) {
        // 0x8005881C: addiu       $v1, $v1, 0xC
        ctx->r3 = ADD32(ctx->r3, 0XC);
            goto L_80058828;
    }
    // 0x8005881C: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x80058820: j           L_80058834
    // 0x80058824: addu        $t3, $a1, $zero
    ctx->r11 = ADD32(ctx->r5, 0);
        goto L_80058834;
    // 0x80058824: addu        $t3, $a1, $zero
    ctx->r11 = ADD32(ctx->r5, 0);
L_80058828:
    // 0x80058828: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8005882C: bne         $v0, $zero, L_80058814
    if (ctx->r2 != 0) {
        // 0x80058830: nop
    
            goto L_80058814;
    }
    // 0x80058830: nop

L_80058834:
    // 0x80058834: lw          $v0, -0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X4);
    // 0x80058838: subu        $v1, $a0, $a1
    ctx->r3 = SUB32(ctx->r4, ctx->r5);
    // 0x8005883C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80058840: sw          $v0, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = ctx->r2;
    // 0x80058844: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x80058848: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8005884C: or          $v0, $v0, $t6
    ctx->r2 = ctx->r2 | ctx->r14;
    // 0x80058850: beq         $v1, $zero, L_80058860
    if (ctx->r3 == 0) {
        // 0x80058854: sw          $v0, 0xC($a0)
        MEM_W(0XC, ctx->r4) = ctx->r2;
            goto L_80058860;
    }
    // 0x80058854: sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
    // 0x80058858: addu        $v0, $v1, $a1
    ctx->r2 = ADD32(ctx->r3, ctx->r5);
    // 0x8005885C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
L_80058860:
    // 0x80058860: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80058864: beq         $v0, $zero, L_80058870
    if (ctx->r2 == 0) {
        // 0x80058868: addu        $v0, $v0, $a1
        ctx->r2 = ADD32(ctx->r2, ctx->r5);
            goto L_80058870;
    }
    // 0x80058868: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8005886C: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_80058870:
    // 0x80058870: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
    // 0x80058874: beq         $v0, $zero, L_80058914
    if (ctx->r2 == 0) {
        // 0x80058878: addu        $v0, $v0, $t3
        ctx->r2 = ADD32(ctx->r2, ctx->r11);
            goto L_80058914;
    }
    // 0x80058878: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x8005887C: addu        $t1, $v0, $zero
    ctx->r9 = ADD32(ctx->r2, 0);
    // 0x80058880: beq         $t1, $zero, L_80058914
    if (ctx->r9 == 0) {
        // 0x80058884: sw          $v0, 0x20($a0)
        MEM_W(0X20, ctx->r4) = ctx->r2;
            goto L_80058914;
    }
    // 0x80058884: sw          $v0, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r2;
L_80058888:
    // 0x80058888: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x8005888C: beq         $v0, $zero, L_80058898
    if (ctx->r2 == 0) {
        // 0x80058890: addu        $v0, $v0, $t3
        ctx->r2 = ADD32(ctx->r2, ctx->r11);
            goto L_80058898;
    }
    // 0x80058890: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x80058894: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
L_80058898:
    // 0x80058898: lw          $v0, 0x4($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X4);
    // 0x8005889C: beq         $v0, $zero, L_800588A8
    if (ctx->r2 == 0) {
        // 0x800588A0: addu        $v0, $v0, $t3
        ctx->r2 = ADD32(ctx->r2, ctx->r11);
            goto L_800588A8;
    }
    // 0x800588A0: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x800588A4: sw          $v0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r2;
L_800588A8:
    // 0x800588A8: lw          $v0, 0x8($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X8);
    // 0x800588AC: beq         $v0, $zero, L_80058908
    if (ctx->r2 == 0) {
        // 0x800588B0: nop
    
            goto L_80058908;
    }
    // 0x800588B0: nop

    // 0x800588B4: beq         $a3, $zero, L_80058908
    if (ctx->r7 == 0) {
        // 0x800588B8: addu        $v0, $v0, $t3
        ctx->r2 = ADD32(ctx->r2, ctx->r11);
            goto L_80058908;
    }
    // 0x800588B8: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x800588BC: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x800588C0: lw          $v0, 0xC($t1)
    ctx->r2 = MEM_W(ctx->r9, 0XC);
    // 0x800588C4: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x800588C8: beq         $v0, $zero, L_80058908
    if (ctx->r2 == 0) {
        // 0x800588CC: sw          $t0, 0x8($t1)
        MEM_W(0X8, ctx->r9) = ctx->r8;
            goto L_80058908;
    }
    // 0x800588CC: sw          $t0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r8;
L_800588D0:
    // 0x800588D0: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800588D4: lhu         $v0, 0x8($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X8);
    // 0x800588D8: lw          $v1, 0x4($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X4);
    // 0x800588DC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800588E0: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x800588E4: and         $v1, $v1, $t4
    ctx->r3 = ctx->r3 & ctx->r12;
    // 0x800588E8: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x800588EC: srl         $v1, $v1, 22
    ctx->r3 = S32(U32(ctx->r3) >> 22);
    // 0x800588F0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800588F4: sw          $v0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r2;
    // 0x800588F8: lw          $v0, 0xC($t1)
    ctx->r2 = MEM_W(ctx->r9, 0XC);
    // 0x800588FC: sltu        $v0, $t2, $v0
    ctx->r2 = ctx->r10 < ctx->r2 ? 1 : 0;
    // 0x80058900: bne         $v0, $zero, L_800588D0
    if (ctx->r2 != 0) {
        // 0x80058904: addu        $t0, $t0, $v1
        ctx->r8 = ADD32(ctx->r8, ctx->r3);
            goto L_800588D0;
    }
    // 0x80058904: addu        $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
L_80058908:
    // 0x80058908: lw          $t1, 0x0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X0);
    // 0x8005890C: bne         $t1, $zero, L_80058888
    if (ctx->r9 != 0) {
        // 0x80058910: nop
    
            goto L_80058888;
    }
    // 0x80058910: nop

L_80058914:
    // 0x80058914: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x80058918: beq         $v0, $zero, L_80058924
    if (ctx->r2 == 0) {
        // 0x8005891C: addu        $v0, $v0, $t3
        ctx->r2 = ADD32(ctx->r2, ctx->r11);
            goto L_80058924;
    }
    // 0x8005891C: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x80058920: sw          $v0, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r2;
L_80058924:
    // 0x80058924: lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28);
    // 0x80058928: beq         $v0, $zero, L_80058934
    if (ctx->r2 == 0) {
        // 0x8005892C: addu        $v0, $v0, $t3
        ctx->r2 = ADD32(ctx->r2, ctx->r11);
            goto L_80058934;
    }
    // 0x8005892C: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x80058930: sw          $v0, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r2;
L_80058934:
    // 0x80058934: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80058938: bne         $a0, $zero, L_80058804
    if (ctx->r4 != 0) {
        // 0x8005893C: nop
    
            goto L_80058804;
    }
    // 0x8005893C: nop

L_80058940:
    // 0x80058940: jr          $ra
    // 0x80058944: nop

    return;
    // 0x80058944: nop

;}
RECOMP_FUNC void meshdef0_offset_convert(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058948: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8005894C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80058950: lw          $s5, 0x48($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X48);
    // 0x80058954: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80058958: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8005895C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80058960: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x80058964: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80058968: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x8005896C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80058970: addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // 0x80058974: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x80058978: beq         $s0, $zero, L_80058B1C
    if (ctx->r16 == 0) {
        // 0x8005897C: sw          $s1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r17;
            goto L_80058B1C;
    }
    // 0x8005897C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
L_80058980:
    // 0x80058980: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80058984: beq         $v0, $zero, L_80058990
    if (ctx->r2 == 0) {
        // 0x80058988: addu        $v0, $v0, $s2
        ctx->r2 = ADD32(ctx->r2, ctx->r18);
            goto L_80058990;
    }
    // 0x80058988: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8005898C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
L_80058990:
    // 0x80058990: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x80058994: beq         $v0, $zero, L_800589A0
    if (ctx->r2 == 0) {
        // 0x80058998: addu        $v0, $v0, $s2
        ctx->r2 = ADD32(ctx->r2, ctx->r18);
            goto L_800589A0;
    }
    // 0x80058998: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x8005899C: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
L_800589A0:
    // 0x800589A0: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x800589A4: beq         $v0, $zero, L_800589B0
    if (ctx->r2 == 0) {
        // 0x800589A8: addu        $v0, $v0, $s2
        ctx->r2 = ADD32(ctx->r2, ctx->r18);
            goto L_800589B0;
    }
    // 0x800589A8: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x800589AC: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
L_800589B0:
    // 0x800589B0: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x800589B4: beq         $v0, $zero, L_800589C0
    if (ctx->r2 == 0) {
        // 0x800589B8: addu        $v0, $v0, $s2
        ctx->r2 = ADD32(ctx->r2, ctx->r18);
            goto L_800589C0;
    }
    // 0x800589B8: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x800589BC: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
L_800589C0:
    // 0x800589C0: lw          $v0, 0x10($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X10);
    // 0x800589C4: beq         $v0, $zero, L_800589E8
    if (ctx->r2 == 0) {
        // 0x800589C8: addu        $a1, $s2, $zero
        ctx->r5 = ADD32(ctx->r18, 0);
            goto L_800589E8;
    }
    // 0x800589C8: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800589CC: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x800589D0: addu        $v0, $v0, $s2
    ctx->r2 = ADD32(ctx->r2, ctx->r18);
    // 0x800589D4: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x800589D8: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x800589DC: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    // 0x800589E0: jal         0x800587F0
    // 0x800589E4: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    meshdef1_offset_convert(rdram, ctx);
        goto after_0;
    // 0x800589E4: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    after_0:
L_800589E8:
    // 0x800589E8: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x800589EC: beq         $v0, $zero, L_80058A08
    if (ctx->r2 == 0) {
        // 0x800589F0: addu        $a1, $s2, $zero
        ctx->r5 = ADD32(ctx->r18, 0);
            goto L_80058A08;
    }
    // 0x800589F0: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800589F4: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x800589F8: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x800589FC: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    // 0x80058A00: jal         0x80058948
    // 0x80058A04: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    meshdef0_offset_convert(rdram, ctx);
        goto after_1;
    // 0x80058A04: addu        $a3, $s4, $zero
    ctx->r7 = ADD32(ctx->r20, 0);
    after_1:
L_80058A08:
    // 0x80058A08: addiu       $s1, $s0, 0x1C
    ctx->r17 = ADD32(ctx->r16, 0X1C);
    // 0x80058A0C: jal         0x8001CA50
    // 0x80058A10: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA50(rdram, ctx);
        goto after_2;
    // 0x80058A10: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_2:
    // 0x80058A14: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x80058A18: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80058A1C: beq         $v0, $zero, L_80058A50
    if (ctx->r2 == 0) {
        // 0x80058A20: nop
    
            goto L_80058A50;
    }
    // 0x80058A20: nop

    // 0x80058A24: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80058A28: lwc1        $f2, 0x58($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80058A2C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80058A30: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x80058A34: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80058A38: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80058A3C: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80058A40: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80058A44: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80058A48: jal         0x8001CA90
    // 0x80058A4C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA90(rdram, ctx);
        goto after_3;
    // 0x80058A4C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_3:
L_80058A50:
    // 0x80058A50: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x80058A54: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x80058A58: beq         $v0, $zero, L_80058A74
    if (ctx->r2 == 0) {
        // 0x80058A5C: nop
    
            goto L_80058A74;
    }
    // 0x80058A5C: nop

    // 0x80058A60: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    // 0x80058A64: lw          $a2, 0x60($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X60);
    // 0x80058A68: lw          $a3, 0x64($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X64);
    // 0x80058A6C: jal         0x8001CB04
    // 0x80058A70: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CB04(rdram, ctx);
        goto after_4;
    // 0x80058A70: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_4:
L_80058A74:
    // 0x80058A74: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x80058A78: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x80058A7C: beq         $v0, $zero, L_80058A8C
    if (ctx->r2 == 0) {
        // 0x80058A80: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80058A8C;
    }
    // 0x80058A80: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80058A84: jal         0x8001DAEC
    // 0x80058A88: addiu       $a1, $s0, 0x68
    ctx->r5 = ADD32(ctx->r16, 0X68);
    func_8001DAEC(rdram, ctx);
        goto after_5;
    // 0x80058A88: addiu       $a1, $s0, 0x68
    ctx->r5 = ADD32(ctx->r16, 0X68);
    after_5:
L_80058A8C:
    // 0x80058A8C: lw          $a0, 0x4C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4C);
    // 0x80058A90: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x80058A94: andi        $v1, $a0, 0x9
    ctx->r3 = ctx->r4 & 0X9;
    // 0x80058A98: bne         $v1, $v0, L_80058AD8
    if (ctx->r3 != ctx->r2) {
        // 0x80058A9C: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_80058AD8;
    }
    // 0x80058A9C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80058AA0: lwc1        $f2, 0x78($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80058AA4: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80058AA8: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80058AAC: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80058AB0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80058AB4: lwc1        $f2, 0x7C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80058AB8: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80058ABC: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80058AC0: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80058AC4: lwc1        $f2, 0x80($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X80);
    // 0x80058AC8: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80058ACC: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80058AD0: j           L_80058B08
    // 0x80058AD4: nop

        goto L_80058B08;
    // 0x80058AD4: nop

L_80058AD8:
    // 0x80058AD8: bne         $v1, $v0, L_80058AF4
    if (ctx->r3 != ctx->r2) {
        // 0x80058ADC: andi        $v0, $a0, 0x1
        ctx->r2 = ctx->r4 & 0X1;
            goto L_80058AF4;
    }
    // 0x80058ADC: andi        $v0, $a0, 0x1
    ctx->r2 = ctx->r4 & 0X1;
    // 0x80058AE0: lw          $a1, 0x78($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X78);
    // 0x80058AE4: lw          $a2, 0x7C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X7C);
    // 0x80058AE8: lw          $a3, 0x80($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X80);
    // 0x80058AEC: j           L_80058B08
    // 0x80058AF0: nop

        goto L_80058B08;
    // 0x80058AF0: nop

L_80058AF4:
    // 0x80058AF4: beq         $v0, $zero, L_80058B10
    if (ctx->r2 == 0) {
        // 0x80058AF8: nop
    
            goto L_80058B10;
    }
    // 0x80058AF8: nop

    // 0x80058AFC: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    // 0x80058B00: lw          $a2, 0x54($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X54);
    // 0x80058B04: lw          $a3, 0x58($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X58);
L_80058B08:
    // 0x80058B08: jal         0x8001CA90
    // 0x80058B0C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA90(rdram, ctx);
        goto after_6;
    // 0x80058B0C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_6:
L_80058B10:
    // 0x80058B10: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x80058B14: bne         $s0, $zero, L_80058980
    if (ctx->r16 != 0) {
        // 0x80058B18: nop
    
            goto L_80058980;
    }
    // 0x80058B18: nop

L_80058B1C:
    // 0x80058B1C: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x80058B20: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80058B24: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80058B28: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80058B2C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80058B30: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80058B34: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80058B38: jr          $ra
    // 0x80058B3C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80058B3C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80058B40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80058B40: beq         $a0, $zero, L_800591CC
    if (ctx->r4 == 0) {
        // 0x80058B44: lui         $a3, 0x8000
        ctx->r7 = S32(0X8000 << 16);
            goto L_800591CC;
    }
    // 0x80058B44: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80058B48: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80058B4C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80058B50: lwc1        $f6, -0x5258($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5258);
    // 0x80058B54: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80058B58: lwc1        $f4, -0x5254($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5254);
L_80058B5C:
    // 0x80058B5C: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
    // 0x80058B60: beq         $v0, $zero, L_800591C0
    if (ctx->r2 == 0) {
        // 0x80058B64: nop
    
            goto L_800591C0;
    }
    // 0x80058B64: nop

    // 0x80058B68: addu        $t1, $v0, $zero
    ctx->r9 = ADD32(ctx->r2, 0);
L_80058B6C:
    // 0x80058B6C: lw          $v0, 0x8($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X8);
    // 0x80058B70: beq         $v0, $zero, L_800591B4
    if (ctx->r2 == 0) {
        // 0x80058B74: nop
    
            goto L_800591B4;
    }
    // 0x80058B74: nop

    // 0x80058B78: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x80058B7C: lw          $v0, 0xC($t1)
    ctx->r2 = MEM_W(ctx->r9, 0XC);
    // 0x80058B80: beq         $v0, $zero, L_800591B4
    if (ctx->r2 == 0) {
        // 0x80058B84: addu        $t2, $zero, $zero
        ctx->r10 = ADD32(0, 0);
            goto L_800591B4;
    }
    // 0x80058B84: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
L_80058B88:
    // 0x80058B88: lw          $v0, 0x4($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X4);
    // 0x80058B8C: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80058B90: srl         $v0, $v0, 10
    ctx->r2 = S32(U32(ctx->r2) >> 10);
    // 0x80058B94: andi        $v0, $v0, 0xFC
    ctx->r2 = ctx->r2 & 0XFC;
    // 0x80058B98: andi        $v1, $v1, 0x10
    ctx->r3 = ctx->r3 & 0X10;
    // 0x80058B9C: beq         $v1, $zero, L_80059068
    if (ctx->r3 == 0) {
        // 0x80058BA0: addu        $a2, $t0, $v0
        ctx->r6 = ADD32(ctx->r8, ctx->r2);
            goto L_80059068;
    }
    // 0x80058BA0: addu        $a2, $t0, $v0
    ctx->r6 = ADD32(ctx->r8, ctx->r2);
    // 0x80058BA4: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
    // 0x80058BA8: lwc1        $f2, 0x0($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80058BAC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80058BB0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80058BB4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80058BB8: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80058BBC: nop

    // 0x80058BC0: bc1t        L_80058C04
    if (c1cs) {
        // 0x80058BC4: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80058C04;
    }
    // 0x80058BC4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80058BC8: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x80058BCC: nop

    // 0x80058BD0: bc1t        L_80058C04
    if (c1cs) {
        // 0x80058BD4: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_80058C04;
    }
    // 0x80058BD4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80058BD8: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80058BDC: nop

    // 0x80058BE0: bc1tl       L_80058BF8
    if (c1cs) {
        // 0x80058BE4: sub.s       $f0, $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
            goto L_80058BF8;
    }
    goto skip_0;
    // 0x80058BE4: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    skip_0:
    // 0x80058BE8: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80058BEC: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80058BF0: j           L_80058C08
    // 0x80058BF4: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
        goto L_80058C08;
    // 0x80058BF4: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
L_80058BF8:
    // 0x80058BF8: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80058BFC: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80058C00: or          $v0, $v0, $a3
    ctx->r2 = ctx->r2 | ctx->r7;
L_80058C04:
    // 0x80058C04: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
L_80058C08:
    // 0x80058C08: lbu         $v0, 0x1($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X1);
    // 0x80058C0C: lwc1        $f2, 0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80058C10: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80058C14: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80058C18: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80058C1C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80058C20: nop

    // 0x80058C24: bc1t        L_80058C68
    if (c1cs) {
        // 0x80058C28: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80058C68;
    }
    // 0x80058C28: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80058C2C: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x80058C30: nop

    // 0x80058C34: bc1t        L_80058C68
    if (c1cs) {
        // 0x80058C38: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_80058C68;
    }
    // 0x80058C38: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80058C3C: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80058C40: nop

    // 0x80058C44: bc1tl       L_80058C5C
    if (c1cs) {
        // 0x80058C48: sub.s       $f0, $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
            goto L_80058C5C;
    }
    goto skip_1;
    // 0x80058C48: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    skip_1:
    // 0x80058C4C: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80058C50: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80058C54: j           L_80058C6C
    // 0x80058C58: sb          $v0, 0x1($a2)
    MEM_B(0X1, ctx->r6) = ctx->r2;
        goto L_80058C6C;
    // 0x80058C58: sb          $v0, 0x1($a2)
    MEM_B(0X1, ctx->r6) = ctx->r2;
L_80058C5C:
    // 0x80058C5C: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80058C60: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80058C64: or          $v0, $v0, $a3
    ctx->r2 = ctx->r2 | ctx->r7;
L_80058C68:
    // 0x80058C68: sb          $v0, 0x1($a2)
    MEM_B(0X1, ctx->r6) = ctx->r2;
L_80058C6C:
    // 0x80058C6C: lbu         $v0, 0x2($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X2);
    // 0x80058C70: lwc1        $f2, 0x8($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80058C74: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80058C78: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80058C7C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80058C80: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80058C84: nop

    // 0x80058C88: bc1t        L_80058CCC
    if (c1cs) {
        // 0x80058C8C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80058CCC;
    }
    // 0x80058C8C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80058C90: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x80058C94: nop

    // 0x80058C98: bc1t        L_80058CCC
    if (c1cs) {
        // 0x80058C9C: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_80058CCC;
    }
    // 0x80058C9C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80058CA0: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80058CA4: nop

    // 0x80058CA8: bc1tl       L_80058CC0
    if (c1cs) {
        // 0x80058CAC: sub.s       $f0, $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
            goto L_80058CC0;
    }
    goto skip_2;
    // 0x80058CAC: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    skip_2:
    // 0x80058CB0: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80058CB4: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80058CB8: j           L_80058CD0
    // 0x80058CBC: sb          $v0, 0x2($a2)
    MEM_B(0X2, ctx->r6) = ctx->r2;
        goto L_80058CD0;
    // 0x80058CBC: sb          $v0, 0x2($a2)
    MEM_B(0X2, ctx->r6) = ctx->r2;
L_80058CC0:
    // 0x80058CC0: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80058CC4: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80058CC8: or          $v0, $v0, $a3
    ctx->r2 = ctx->r2 | ctx->r7;
L_80058CCC:
    // 0x80058CCC: sb          $v0, 0x2($a2)
    MEM_B(0X2, ctx->r6) = ctx->r2;
L_80058CD0:
    // 0x80058CD0: lbu         $v0, 0x4($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X4);
    // 0x80058CD4: lwc1        $f2, 0x0($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80058CD8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80058CDC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80058CE0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80058CE4: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80058CE8: nop

    // 0x80058CEC: bc1t        L_80058D30
    if (c1cs) {
        // 0x80058CF0: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80058D30;
    }
    // 0x80058CF0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80058CF4: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x80058CF8: nop

    // 0x80058CFC: bc1t        L_80058D30
    if (c1cs) {
        // 0x80058D00: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_80058D30;
    }
    // 0x80058D00: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80058D04: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80058D08: nop

    // 0x80058D0C: bc1tl       L_80058D24
    if (c1cs) {
        // 0x80058D10: sub.s       $f0, $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
            goto L_80058D24;
    }
    goto skip_3;
    // 0x80058D10: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    skip_3:
    // 0x80058D14: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80058D18: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80058D1C: j           L_80058D34
    // 0x80058D20: sb          $v0, 0x4($a2)
    MEM_B(0X4, ctx->r6) = ctx->r2;
        goto L_80058D34;
    // 0x80058D20: sb          $v0, 0x4($a2)
    MEM_B(0X4, ctx->r6) = ctx->r2;
L_80058D24:
    // 0x80058D24: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80058D28: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80058D2C: or          $v0, $v0, $a3
    ctx->r2 = ctx->r2 | ctx->r7;
L_80058D30:
    // 0x80058D30: sb          $v0, 0x4($a2)
    MEM_B(0X4, ctx->r6) = ctx->r2;
L_80058D34:
    // 0x80058D34: lbu         $v0, 0x5($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X5);
    // 0x80058D38: lwc1        $f2, 0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80058D3C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80058D40: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80058D44: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80058D48: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80058D4C: nop

    // 0x80058D50: bc1t        L_80058D94
    if (c1cs) {
        // 0x80058D54: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80058D94;
    }
    // 0x80058D54: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80058D58: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x80058D5C: nop

    // 0x80058D60: bc1t        L_80058D94
    if (c1cs) {
        // 0x80058D64: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_80058D94;
    }
    // 0x80058D64: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80058D68: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80058D6C: nop

    // 0x80058D70: bc1tl       L_80058D88
    if (c1cs) {
        // 0x80058D74: sub.s       $f0, $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
            goto L_80058D88;
    }
    goto skip_4;
    // 0x80058D74: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    skip_4:
    // 0x80058D78: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80058D7C: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80058D80: j           L_80058D98
    // 0x80058D84: sb          $v0, 0x5($a2)
    MEM_B(0X5, ctx->r6) = ctx->r2;
        goto L_80058D98;
    // 0x80058D84: sb          $v0, 0x5($a2)
    MEM_B(0X5, ctx->r6) = ctx->r2;
L_80058D88:
    // 0x80058D88: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80058D8C: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80058D90: or          $v0, $v0, $a3
    ctx->r2 = ctx->r2 | ctx->r7;
L_80058D94:
    // 0x80058D94: sb          $v0, 0x5($a2)
    MEM_B(0X5, ctx->r6) = ctx->r2;
L_80058D98:
    // 0x80058D98: lbu         $v0, 0x6($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X6);
    // 0x80058D9C: lwc1        $f2, 0x8($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80058DA0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80058DA4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80058DA8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80058DAC: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80058DB0: nop

    // 0x80058DB4: bc1t        L_80058DF8
    if (c1cs) {
        // 0x80058DB8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80058DF8;
    }
    // 0x80058DB8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80058DBC: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x80058DC0: nop

    // 0x80058DC4: bc1t        L_80058DF8
    if (c1cs) {
        // 0x80058DC8: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_80058DF8;
    }
    // 0x80058DC8: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80058DCC: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80058DD0: nop

    // 0x80058DD4: bc1tl       L_80058DEC
    if (c1cs) {
        // 0x80058DD8: sub.s       $f0, $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
            goto L_80058DEC;
    }
    goto skip_5;
    // 0x80058DD8: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    skip_5:
    // 0x80058DDC: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80058DE0: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80058DE4: j           L_80058DFC
    // 0x80058DE8: sb          $v0, 0x6($a2)
    MEM_B(0X6, ctx->r6) = ctx->r2;
        goto L_80058DFC;
    // 0x80058DE8: sb          $v0, 0x6($a2)
    MEM_B(0X6, ctx->r6) = ctx->r2;
L_80058DEC:
    // 0x80058DEC: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80058DF0: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80058DF4: or          $v0, $v0, $a3
    ctx->r2 = ctx->r2 | ctx->r7;
L_80058DF8:
    // 0x80058DF8: sb          $v0, 0x6($a2)
    MEM_B(0X6, ctx->r6) = ctx->r2;
L_80058DFC:
    // 0x80058DFC: lbu         $v0, 0x8($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X8);
    // 0x80058E00: lwc1        $f2, 0x0($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80058E04: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80058E08: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80058E0C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80058E10: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80058E14: nop

    // 0x80058E18: bc1t        L_80058E5C
    if (c1cs) {
        // 0x80058E1C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80058E5C;
    }
    // 0x80058E1C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80058E20: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x80058E24: nop

    // 0x80058E28: bc1t        L_80058E5C
    if (c1cs) {
        // 0x80058E2C: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_80058E5C;
    }
    // 0x80058E2C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80058E30: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80058E34: nop

    // 0x80058E38: bc1tl       L_80058E50
    if (c1cs) {
        // 0x80058E3C: sub.s       $f0, $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
            goto L_80058E50;
    }
    goto skip_6;
    // 0x80058E3C: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    skip_6:
    // 0x80058E40: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80058E44: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80058E48: j           L_80058E60
    // 0x80058E4C: sb          $v0, 0x8($a2)
    MEM_B(0X8, ctx->r6) = ctx->r2;
        goto L_80058E60;
    // 0x80058E4C: sb          $v0, 0x8($a2)
    MEM_B(0X8, ctx->r6) = ctx->r2;
L_80058E50:
    // 0x80058E50: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80058E54: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80058E58: or          $v0, $v0, $a3
    ctx->r2 = ctx->r2 | ctx->r7;
L_80058E5C:
    // 0x80058E5C: sb          $v0, 0x8($a2)
    MEM_B(0X8, ctx->r6) = ctx->r2;
L_80058E60:
    // 0x80058E60: lbu         $v0, 0x9($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X9);
    // 0x80058E64: lwc1        $f2, 0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80058E68: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80058E6C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80058E70: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80058E74: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80058E78: nop

    // 0x80058E7C: bc1t        L_80058EC0
    if (c1cs) {
        // 0x80058E80: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80058EC0;
    }
    // 0x80058E80: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80058E84: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x80058E88: nop

    // 0x80058E8C: bc1t        L_80058EC0
    if (c1cs) {
        // 0x80058E90: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_80058EC0;
    }
    // 0x80058E90: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80058E94: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80058E98: nop

    // 0x80058E9C: bc1tl       L_80058EB4
    if (c1cs) {
        // 0x80058EA0: sub.s       $f0, $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
            goto L_80058EB4;
    }
    goto skip_7;
    // 0x80058EA0: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    skip_7:
    // 0x80058EA4: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80058EA8: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80058EAC: j           L_80058EC4
    // 0x80058EB0: sb          $v0, 0x9($a2)
    MEM_B(0X9, ctx->r6) = ctx->r2;
        goto L_80058EC4;
    // 0x80058EB0: sb          $v0, 0x9($a2)
    MEM_B(0X9, ctx->r6) = ctx->r2;
L_80058EB4:
    // 0x80058EB4: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80058EB8: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80058EBC: or          $v0, $v0, $a3
    ctx->r2 = ctx->r2 | ctx->r7;
L_80058EC0:
    // 0x80058EC0: sb          $v0, 0x9($a2)
    MEM_B(0X9, ctx->r6) = ctx->r2;
L_80058EC4:
    // 0x80058EC4: lbu         $v0, 0xA($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0XA);
    // 0x80058EC8: lwc1        $f2, 0x8($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80058ECC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80058ED0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80058ED4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80058ED8: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80058EDC: nop

    // 0x80058EE0: bc1t        L_80058F24
    if (c1cs) {
        // 0x80058EE4: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80058F24;
    }
    // 0x80058EE4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80058EE8: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x80058EEC: nop

    // 0x80058EF0: bc1t        L_80058F24
    if (c1cs) {
        // 0x80058EF4: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_80058F24;
    }
    // 0x80058EF4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80058EF8: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80058EFC: nop

    // 0x80058F00: bc1tl       L_80058F18
    if (c1cs) {
        // 0x80058F04: sub.s       $f0, $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
            goto L_80058F18;
    }
    goto skip_8;
    // 0x80058F04: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    skip_8:
    // 0x80058F08: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80058F0C: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80058F10: j           L_80058F28
    // 0x80058F14: sb          $v0, 0xA($a2)
    MEM_B(0XA, ctx->r6) = ctx->r2;
        goto L_80058F28;
    // 0x80058F14: sb          $v0, 0xA($a2)
    MEM_B(0XA, ctx->r6) = ctx->r2;
L_80058F18:
    // 0x80058F18: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80058F1C: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80058F20: or          $v0, $v0, $a3
    ctx->r2 = ctx->r2 | ctx->r7;
L_80058F24:
    // 0x80058F24: sb          $v0, 0xA($a2)
    MEM_B(0XA, ctx->r6) = ctx->r2;
L_80058F28:
    // 0x80058F28: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80058F2C: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    // 0x80058F30: beql        $v0, $zero, L_80059198
    if (ctx->r2 == 0) {
        // 0x80058F34: addiu       $t2, $t2, 0x1
        ctx->r10 = ADD32(ctx->r10, 0X1);
            goto L_80059198;
    }
    goto skip_9;
    // 0x80058F34: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    skip_9:
    // 0x80058F38: lbu         $v0, 0xC($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0XC);
    // 0x80058F3C: lwc1        $f2, 0x0($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80058F40: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80058F44: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80058F48: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80058F4C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80058F50: nop

    // 0x80058F54: bc1t        L_80058F98
    if (c1cs) {
        // 0x80058F58: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80058F98;
    }
    // 0x80058F58: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80058F5C: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x80058F60: nop

    // 0x80058F64: bc1t        L_80058F98
    if (c1cs) {
        // 0x80058F68: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_80058F98;
    }
    // 0x80058F68: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80058F6C: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80058F70: nop

    // 0x80058F74: bc1tl       L_80058F8C
    if (c1cs) {
        // 0x80058F78: sub.s       $f0, $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
            goto L_80058F8C;
    }
    goto skip_10;
    // 0x80058F78: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    skip_10:
    // 0x80058F7C: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80058F80: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80058F84: j           L_80058F9C
    // 0x80058F88: sb          $v0, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r2;
        goto L_80058F9C;
    // 0x80058F88: sb          $v0, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r2;
L_80058F8C:
    // 0x80058F8C: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80058F90: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80058F94: or          $v0, $v0, $a3
    ctx->r2 = ctx->r2 | ctx->r7;
L_80058F98:
    // 0x80058F98: sb          $v0, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r2;
L_80058F9C:
    // 0x80058F9C: lbu         $v0, 0xD($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0XD);
    // 0x80058FA0: lwc1        $f2, 0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80058FA4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80058FA8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80058FAC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80058FB0: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80058FB4: nop

    // 0x80058FB8: bc1t        L_80058FFC
    if (c1cs) {
        // 0x80058FBC: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80058FFC;
    }
    // 0x80058FBC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80058FC0: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x80058FC4: nop

    // 0x80058FC8: bc1t        L_80058FFC
    if (c1cs) {
        // 0x80058FCC: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_80058FFC;
    }
    // 0x80058FCC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80058FD0: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80058FD4: nop

    // 0x80058FD8: bc1tl       L_80058FF0
    if (c1cs) {
        // 0x80058FDC: sub.s       $f0, $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
            goto L_80058FF0;
    }
    goto skip_11;
    // 0x80058FDC: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    skip_11:
    // 0x80058FE0: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80058FE4: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80058FE8: j           L_80059000
    // 0x80058FEC: sb          $v0, 0xD($a2)
    MEM_B(0XD, ctx->r6) = ctx->r2;
        goto L_80059000;
    // 0x80058FEC: sb          $v0, 0xD($a2)
    MEM_B(0XD, ctx->r6) = ctx->r2;
L_80058FF0:
    // 0x80058FF0: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80058FF4: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80058FF8: or          $v0, $v0, $a3
    ctx->r2 = ctx->r2 | ctx->r7;
L_80058FFC:
    // 0x80058FFC: sb          $v0, 0xD($a2)
    MEM_B(0XD, ctx->r6) = ctx->r2;
L_80059000:
    // 0x80059000: lbu         $v0, 0xE($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0XE);
    // 0x80059004: lwc1        $f2, 0x8($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80059008: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8005900C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80059010: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80059014: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80059018: nop

    // 0x8005901C: bc1t        L_80059060
    if (c1cs) {
        // 0x80059020: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80059060;
    }
    // 0x80059020: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80059024: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x80059028: nop

    // 0x8005902C: bc1t        L_80059060
    if (c1cs) {
        // 0x80059030: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_80059060;
    }
    // 0x80059030: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80059034: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80059038: nop

    // 0x8005903C: bc1tl       L_80059054
    if (c1cs) {
        // 0x80059040: sub.s       $f0, $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
            goto L_80059054;
    }
    goto skip_12;
    // 0x80059040: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    skip_12:
    // 0x80059044: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80059048: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x8005904C: j           L_80059194
    // 0x80059050: sb          $v0, 0xE($a2)
    MEM_B(0XE, ctx->r6) = ctx->r2;
        goto L_80059194;
    // 0x80059050: sb          $v0, 0xE($a2)
    MEM_B(0XE, ctx->r6) = ctx->r2;
L_80059054:
    // 0x80059054: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80059058: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x8005905C: or          $v0, $v0, $a3
    ctx->r2 = ctx->r2 | ctx->r7;
L_80059060:
    // 0x80059060: j           L_80059194
    // 0x80059064: sb          $v0, 0xE($a2)
    MEM_B(0XE, ctx->r6) = ctx->r2;
        goto L_80059194;
    // 0x80059064: sb          $v0, 0xE($a2)
    MEM_B(0XE, ctx->r6) = ctx->r2;
L_80059068:
    // 0x80059068: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
    // 0x8005906C: lwc1        $f2, 0x0($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80059070: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80059074: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80059078: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8005907C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80059080: nop

    // 0x80059084: bc1t        L_800590C8
    if (c1cs) {
        // 0x80059088: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800590C8;
    }
    // 0x80059088: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8005908C: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x80059090: nop

    // 0x80059094: bc1t        L_800590C8
    if (c1cs) {
        // 0x80059098: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_800590C8;
    }
    // 0x80059098: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8005909C: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x800590A0: nop

    // 0x800590A4: bc1tl       L_800590BC
    if (c1cs) {
        // 0x800590A8: sub.s       $f0, $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
            goto L_800590BC;
    }
    goto skip_13;
    // 0x800590A8: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    skip_13:
    // 0x800590AC: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800590B0: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x800590B4: j           L_800590CC
    // 0x800590B8: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
        goto L_800590CC;
    // 0x800590B8: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
L_800590BC:
    // 0x800590BC: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800590C0: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x800590C4: or          $v0, $v0, $a3
    ctx->r2 = ctx->r2 | ctx->r7;
L_800590C8:
    // 0x800590C8: sb          $v0, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r2;
L_800590CC:
    // 0x800590CC: lbu         $v0, 0x1($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X1);
    // 0x800590D0: lwc1        $f2, 0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800590D4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800590D8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800590DC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800590E0: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x800590E4: nop

    // 0x800590E8: bc1t        L_8005912C
    if (c1cs) {
        // 0x800590EC: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8005912C;
    }
    // 0x800590EC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800590F0: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x800590F4: nop

    // 0x800590F8: bc1t        L_8005912C
    if (c1cs) {
        // 0x800590FC: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_8005912C;
    }
    // 0x800590FC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80059100: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80059104: nop

    // 0x80059108: bc1tl       L_80059120
    if (c1cs) {
        // 0x8005910C: sub.s       $f0, $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
            goto L_80059120;
    }
    goto skip_14;
    // 0x8005910C: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    skip_14:
    // 0x80059110: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80059114: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80059118: j           L_80059130
    // 0x8005911C: sb          $v0, 0x1($a2)
    MEM_B(0X1, ctx->r6) = ctx->r2;
        goto L_80059130;
    // 0x8005911C: sb          $v0, 0x1($a2)
    MEM_B(0X1, ctx->r6) = ctx->r2;
L_80059120:
    // 0x80059120: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80059124: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80059128: or          $v0, $v0, $a3
    ctx->r2 = ctx->r2 | ctx->r7;
L_8005912C:
    // 0x8005912C: sb          $v0, 0x1($a2)
    MEM_B(0X1, ctx->r6) = ctx->r2;
L_80059130:
    // 0x80059130: lbu         $v0, 0x2($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X2);
    // 0x80059134: lwc1        $f2, 0x8($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80059138: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8005913C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80059140: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80059144: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80059148: nop

    // 0x8005914C: bc1t        L_80059190
    if (c1cs) {
        // 0x80059150: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80059190;
    }
    // 0x80059150: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80059154: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x80059158: nop

    // 0x8005915C: bc1t        L_80059190
    if (c1cs) {
        // 0x80059160: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_80059190;
    }
    // 0x80059160: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80059164: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80059168: nop

    // 0x8005916C: bc1tl       L_80059184
    if (c1cs) {
        // 0x80059170: sub.s       $f0, $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
            goto L_80059184;
    }
    goto skip_15;
    // 0x80059170: sub.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f4.fl;
    skip_15:
    // 0x80059174: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80059178: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x8005917C: j           L_80059194
    // 0x80059180: sb          $v0, 0x2($a2)
    MEM_B(0X2, ctx->r6) = ctx->r2;
        goto L_80059194;
    // 0x80059180: sb          $v0, 0x2($a2)
    MEM_B(0X2, ctx->r6) = ctx->r2;
L_80059184:
    // 0x80059184: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80059188: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x8005918C: or          $v0, $v0, $a3
    ctx->r2 = ctx->r2 | ctx->r7;
L_80059190:
    // 0x80059190: sb          $v0, 0x2($a2)
    MEM_B(0X2, ctx->r6) = ctx->r2;
L_80059194:
    // 0x80059194: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
L_80059198:
    // 0x80059198: lw          $v1, 0x4($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X4);
    // 0x8005919C: lw          $v0, 0xC($t1)
    ctx->r2 = MEM_W(ctx->r9, 0XC);
    // 0x800591A0: srl         $v1, $v1, 22
    ctx->r3 = S32(U32(ctx->r3) >> 22);
    // 0x800591A4: andi        $v1, $v1, 0xFC
    ctx->r3 = ctx->r3 & 0XFC;
    // 0x800591A8: sltu        $v0, $t2, $v0
    ctx->r2 = ctx->r10 < ctx->r2 ? 1 : 0;
    // 0x800591AC: bne         $v0, $zero, L_80058B88
    if (ctx->r2 != 0) {
        // 0x800591B0: addu        $t0, $t0, $v1
        ctx->r8 = ADD32(ctx->r8, ctx->r3);
            goto L_80058B88;
    }
    // 0x800591B0: addu        $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
L_800591B4:
    // 0x800591B4: lw          $t1, 0x0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X0);
    // 0x800591B8: bne         $t1, $zero, L_80058B6C
    if (ctx->r9 != 0) {
        // 0x800591BC: nop
    
            goto L_80058B6C;
    }
    // 0x800591BC: nop

L_800591C0:
    // 0x800591C0: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x800591C4: bne         $a0, $zero, L_80058B5C
    if (ctx->r4 != 0) {
        // 0x800591C8: nop
    
            goto L_80058B5C;
    }
    // 0x800591C8: nop

L_800591CC:
    // 0x800591CC: jr          $ra
    // 0x800591D0: nop

    return;
    // 0x800591D0: nop

;}
RECOMP_FUNC void freeAllHobFiles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800591D4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800591D8: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x800591DC: ori         $s6, $zero, 0xFFFF
    ctx->r22 = 0 | 0XFFFF;
    // 0x800591E0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800591E4: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x800591E8: addiu       $s4, $v0, -0x6FE0
    ctx->r20 = ADD32(ctx->r2, -0X6FE0);
    // 0x800591EC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800591F0: addiu       $v0, $v0, -0x6B50
    ctx->r2 = ADD32(ctx->r2, -0X6B50);
    // 0x800591F4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800591F8: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x800591FC: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x80059200: addiu       $s5, $s2, 0x32
    ctx->r21 = ADD32(ctx->r18, 0X32);
    // 0x80059204: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80059208: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8005920C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80059210: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
L_80059214:
    // 0x80059214: lhu         $v1, 0x0($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X0);
    // 0x80059218: beql        $v1, $s6, L_80059260
    if (ctx->r3 == ctx->r22) {
        // 0x8005921C: addiu       $s2, $s2, 0x2
        ctx->r18 = ADD32(ctx->r18, 0X2);
            goto L_80059260;
    }
    goto skip_0;
    // 0x8005921C: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    skip_0:
    // 0x80059220: addu        $s1, $s2, $zero
    ctx->r17 = ADD32(ctx->r18, 0);
    // 0x80059224: ori         $s3, $zero, 0xFFFF
    ctx->r19 = 0 | 0XFFFF;
L_80059228:
    // 0x80059228: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8005922C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80059230: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80059234: addu        $s0, $v0, $s4
    ctx->r16 = ADD32(ctx->r2, ctx->r20);
    // 0x80059238: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x8005923C: beq         $a0, $zero, L_8005924C
    if (ctx->r4 == 0) {
        // 0x80059240: nop
    
            goto L_8005924C;
    }
    // 0x80059240: nop

    // 0x80059244: jal         0x80001C98
    // 0x80059248: nop

    rs_free(rdram, ctx);
        goto after_0;
    // 0x80059248: nop

    after_0:
L_8005924C:
    // 0x8005924C: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x80059250: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80059254: bne         $v1, $s3, L_80059228
    if (ctx->r3 != ctx->r19) {
        // 0x80059258: sh          $v0, 0x0($s1)
        MEM_H(0X0, ctx->r17) = ctx->r2;
            goto L_80059228;
    }
    // 0x80059258: sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // 0x8005925C: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
L_80059260:
    // 0x80059260: slt         $v0, $s2, $s5
    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r21) ? 1 : 0;
    // 0x80059264: bne         $v0, $zero, L_80059214
    if (ctx->r2 != 0) {
        // 0x80059268: nop
    
            goto L_80059214;
    }
    // 0x80059268: nop

    // 0x8005926C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80059270: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x80059274: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x80059278: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8005927C: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80059280: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80059284: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80059288: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8005928C: jr          $ra
    // 0x80059290: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80059290: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80059294(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059294: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80059298: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8005929C: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800592A0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800592A4: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x800592A8: bne         $s0, $zero, L_800592C0
    if (ctx->r16 != 0) {
        // 0x800592AC: sw          $ra, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r31;
            goto L_800592C0;
    }
    // 0x800592AC: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800592B0: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    // 0x800592B4: jal         0x80001ACC
    // 0x800592B8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x800592B8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x800592BC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_800592C0:
    // 0x800592C0: sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
    // 0x800592C4: lhu         $v0, 0x3A($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X3A);
    // 0x800592C8: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x800592CC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800592D0: sh          $v0, 0x3A($s1)
    MEM_H(0X3A, ctx->r17) = ctx->r2;
    // 0x800592D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800592D8: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800592DC: sh          $v0, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r2;
    // 0x800592E0: sb          $zero, 0xA($s0)
    MEM_B(0XA, ctx->r16) = 0;
    // 0x800592E4: sb          $zero, 0xB($s0)
    MEM_B(0XB, ctx->r16) = 0;
    // 0x800592E8: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x800592EC: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x800592F0: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x800592F4: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x800592F8: sw          $a0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r4;
    // 0x800592FC: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x80059300: sw          $zero, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = 0;
    // 0x80059304: sw          $zero, 0x58($s0)
    MEM_W(0X58, ctx->r16) = 0;
    // 0x80059308: lw          $v0, 0x18($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X18);
    // 0x8005930C: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x80059310: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80059314: sw          $v0, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r2;
    // 0x80059318: jal         0x8000A85C
    // 0x8005931C: sw          $v1, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r3;
    func_8000A85C(rdram, ctx);
        goto after_1;
    // 0x8005931C: sw          $v1, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r3;
    after_1:
    // 0x80059320: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x80059324: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80059328: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8005932C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80059330: jr          $ra
    // 0x80059334: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80059334: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80059338(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059338: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8005933C: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x80059340: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80059344: lw          $a2, 0x18($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X18);
    // 0x80059348: beq         $a2, $zero, L_80059404
    if (ctx->r6 == 0) {
        // 0x8005934C: nop
    
            goto L_80059404;
    }
    // 0x8005934C: nop

    // 0x80059350: lw          $a3, 0x14($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X14);
    // 0x80059354: lhu         $v1, 0x2($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X2);
    // 0x80059358: lhu         $v0, 0x2($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X2);
    // 0x8005935C: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80059360: bne         $v0, $zero, L_80059404
    if (ctx->r2 != 0) {
        // 0x80059364: addiu       $t0, $a2, 0x4
        ctx->r8 = ADD32(ctx->r6, 0X4);
            goto L_80059404;
    }
    // 0x80059364: addiu       $t0, $a2, 0x4
    ctx->r8 = ADD32(ctx->r6, 0X4);
    // 0x80059368: lhu         $v1, 0x0($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X0);
    // 0x8005936C: addu        $t4, $zero, $zero
    ctx->r12 = ADD32(0, 0);
    // 0x80059370: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80059374: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80059378: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8005937C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80059380: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80059384: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x80059388: beq         $v1, $zero, L_80059400
    if (ctx->r3 == 0) {
        // 0x8005938C: addu        $a3, $a0, $v0
        ctx->r7 = ADD32(ctx->r4, ctx->r2);
            goto L_80059400;
    }
    // 0x8005938C: addu        $a3, $a0, $v0
    ctx->r7 = ADD32(ctx->r4, ctx->r2);
    // 0x80059390: addiu       $t3, $a0, 0x1C
    ctx->r11 = ADD32(ctx->r4, 0X1C);
    // 0x80059394: addiu       $t2, $a3, 0x8
    ctx->r10 = ADD32(ctx->r7, 0X8);
L_80059398:
    // 0x80059398: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8005939C: beq         $v0, $zero, L_800593E8
    if (ctx->r2 == 0) {
        // 0x800593A0: addu        $t1, $zero, $zero
        ctx->r9 = ADD32(0, 0);
            goto L_800593E8;
    }
    // 0x800593A0: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x800593A4: sw          $a3, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r7;
L_800593A8:
    // 0x800593A8: lw          $v0, 0x4($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X4);
    // 0x800593AC: beq         $v0, $zero, L_800593B8
    if (ctx->r2 == 0) {
        // 0x800593B0: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_800593B8;
    }
    // 0x800593B0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800593B4: addiu       $a2, $a3, 0x5C
    ctx->r6 = ADD32(ctx->r7, 0X5C);
L_800593B8:
    // 0x800593B8: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
    // 0x800593BC: sw          $t1, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->r9;
    // 0x800593C0: addu        $t1, $a3, $zero
    ctx->r9 = ADD32(ctx->r7, 0);
    // 0x800593C4: addiu       $a3, $a3, 0x5C
    ctx->r7 = ADD32(ctx->r7, 0X5C);
    // 0x800593C8: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800593CC: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x800593D0: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
    // 0x800593D4: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800593D8: bne         $v0, $zero, L_800593A8
    if (ctx->r2 != 0) {
        // 0x800593DC: addiu       $t2, $t2, 0x5C
        ctx->r10 = ADD32(ctx->r10, 0X5C);
            goto L_800593A8;
    }
    // 0x800593DC: addiu       $t2, $t2, 0x5C
    ctx->r10 = ADD32(ctx->r10, 0X5C);
    // 0x800593E0: j           L_800593F0
    // 0x800593E4: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
        goto L_800593F0;
    // 0x800593E4: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
L_800593E8:
    // 0x800593E8: sw          $zero, 0x0($t3)
    MEM_W(0X0, ctx->r11) = 0;
    // 0x800593EC: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
L_800593F0:
    // 0x800593F0: addiu       $t3, $t3, 0x4C
    ctx->r11 = ADD32(ctx->r11, 0X4C);
    // 0x800593F4: slt         $v0, $t4, $v1
    ctx->r2 = SIGNED(ctx->r12) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800593F8: bne         $v0, $zero, L_80059398
    if (ctx->r2 != 0) {
        // 0x800593FC: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_80059398;
    }
    // 0x800593FC: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
L_80059400:
    // 0x80059400: sb          $a1, 0xA($a0)
    MEM_B(0XA, ctx->r4) = ctx->r5;
L_80059404:
    // 0x80059404: jr          $ra
    // 0x80059408: nop

    return;
    // 0x80059408: nop

;}
RECOMP_FUNC void func_8005940C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005940C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80059410: addiu       $v0, $sp, 0x18
    ctx->r2 = ADD32(ctx->r29, 0X18);
    // 0x80059414: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80059418: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x8005941C: jal         0x8001DC34
    // 0x80059420: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_8001DC34(rdram, ctx);
        goto after_0;
    // 0x80059420: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_0:
    // 0x80059424: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80059428: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8005942C: jr          $ra
    // 0x80059430: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80059430: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80059434(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059434: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80059438: lw          $t1, 0x28($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X28);
    // 0x8005943C: beq         $t1, $zero, L_800594E0
    if (ctx->r9 == 0) {
        // 0x80059440: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800594E0;
    }
    // 0x80059440: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80059444: lbu         $v0, 0x0($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X0);
    // 0x80059448: beq         $v0, $zero, L_800594D8
    if (ctx->r2 == 0) {
        // 0x8005944C: addiu       $t2, $t1, 0x9
        ctx->r10 = ADD32(ctx->r9, 0X9);
            goto L_800594D8;
    }
    // 0x8005944C: addiu       $t2, $t1, 0x9
    ctx->r10 = ADD32(ctx->r9, 0X9);
L_80059450:
    // 0x80059450: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80059454: addu        $v0, $t1, $a3
    ctx->r2 = ADD32(ctx->r9, ctx->r7);
L_80059458:
    // 0x80059458: addu        $v1, $a1, $a3
    ctx->r3 = ADD32(ctx->r5, ctx->r7);
    // 0x8005945C: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x80059460: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80059464: bnel        $t0, $v0, L_800594CC
    if (ctx->r8 != ctx->r2) {
        // 0x80059468: addiu       $t1, $t1, 0xA
        ctx->r9 = ADD32(ctx->r9, 0XA);
            goto L_800594CC;
    }
    goto skip_0;
    // 0x80059468: addiu       $t1, $t1, 0xA
    ctx->r9 = ADD32(ctx->r9, 0XA);
    skip_0:
    // 0x8005946C: bnel        $t0, $zero, L_800594BC
    if (ctx->r8 != 0) {
        // 0x80059470: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_800594BC;
    }
    goto skip_1;
    // 0x80059470: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    skip_1:
    // 0x80059474: beq         $a2, $zero, L_80059498
    if (ctx->r6 == 0) {
        // 0x80059478: nop
    
            goto L_80059498;
    }
    // 0x80059478: nop

    // 0x8005947C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80059480: lbu         $v0, 0x0($t2)
    ctx->r2 = MEM_BU(ctx->r10, 0X0);
    // 0x80059484: lw          $v1, 0x14($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X14);
    // 0x80059488: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8005948C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80059490: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x80059494: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_80059498:
    // 0x80059498: lbu         $v1, 0x0($t2)
    ctx->r3 = MEM_BU(ctx->r10, 0X0);
    // 0x8005949C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800594A0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800594A4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800594A8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800594AC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800594B0: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800594B4: jr          $ra
    // 0x800594B8: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    return;
    // 0x800594B8: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
L_800594BC:
    // 0x800594BC: slti        $v0, $a3, 0x9
    ctx->r2 = SIGNED(ctx->r7) < 0X9 ? 1 : 0;
    // 0x800594C0: bne         $v0, $zero, L_80059458
    if (ctx->r2 != 0) {
        // 0x800594C4: addu        $v0, $t1, $a3
        ctx->r2 = ADD32(ctx->r9, ctx->r7);
            goto L_80059458;
    }
    // 0x800594C4: addu        $v0, $t1, $a3
    ctx->r2 = ADD32(ctx->r9, ctx->r7);
    // 0x800594C8: addiu       $t1, $t1, 0xA
    ctx->r9 = ADD32(ctx->r9, 0XA);
L_800594CC:
    // 0x800594CC: lbu         $v0, 0x0($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X0);
    // 0x800594D0: bne         $v0, $zero, L_80059450
    if (ctx->r2 != 0) {
        // 0x800594D4: addiu       $t2, $t2, 0xA
        ctx->r10 = ADD32(ctx->r10, 0XA);
            goto L_80059450;
    }
    // 0x800594D4: addiu       $t2, $t2, 0xA
    ctx->r10 = ADD32(ctx->r10, 0XA);
L_800594D8:
    // 0x800594D8: jr          $ra
    // 0x800594DC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x800594DC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800594E0:
    // 0x800594E0: jr          $ra
    // 0x800594E4: nop

    return;
    // 0x800594E4: nop

;}
RECOMP_FUNC void func_800594E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800594E8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800594EC: lwc1        $f0, 0x34($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X34);
    // 0x800594F0: jr          $ra
    // 0x800594F4: nop

    return;
    // 0x800594F4: nop

;}
RECOMP_FUNC void func_800594F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800594F8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800594FC: lw          $a3, 0x2C($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X2C);
    // 0x80059500: bne         $a3, $zero, L_80059548
    if (ctx->r7 != 0) {
        // 0x80059504: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80059548;
    }
    // 0x80059504: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80059508: jr          $ra
    // 0x8005950C: nop

    return;
    // 0x8005950C: nop

L_80059510:
    // 0x80059510: jr          $ra
    // 0x80059514: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
    return;
    // 0x80059514: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
L_80059518:
    // 0x80059518: addu        $v0, $a3, $a0
    ctx->r2 = ADD32(ctx->r7, ctx->r4);
L_8005951C:
    // 0x8005951C: addu        $v1, $a1, $a0
    ctx->r3 = ADD32(ctx->r5, ctx->r4);
    // 0x80059520: lbu         $a2, 0x4($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X4);
    // 0x80059524: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80059528: bnel        $a2, $v0, L_80059548
    if (ctx->r6 != ctx->r2) {
        // 0x8005952C: addiu       $a3, $a3, 0xC
        ctx->r7 = ADD32(ctx->r7, 0XC);
            goto L_80059548;
    }
    goto skip_0;
    // 0x8005952C: addiu       $a3, $a3, 0xC
    ctx->r7 = ADD32(ctx->r7, 0XC);
    skip_0:
    // 0x80059530: beq         $a2, $zero, L_80059510
    if (ctx->r6 == 0) {
        // 0x80059534: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80059510;
    }
    // 0x80059534: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80059538: sltiu       $v0, $a0, 0x7
    ctx->r2 = ctx->r4 < 0X7 ? 1 : 0;
    // 0x8005953C: bne         $v0, $zero, L_8005951C
    if (ctx->r2 != 0) {
        // 0x80059540: addu        $v0, $a3, $a0
        ctx->r2 = ADD32(ctx->r7, ctx->r4);
            goto L_8005951C;
    }
    // 0x80059540: addu        $v0, $a3, $a0
    ctx->r2 = ADD32(ctx->r7, ctx->r4);
    // 0x80059544: addiu       $a3, $a3, 0xC
    ctx->r7 = ADD32(ctx->r7, 0XC);
L_80059548:
    // 0x80059548: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8005954C: bne         $v0, $zero, L_80059518
    if (ctx->r2 != 0) {
        // 0x80059550: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80059518;
    }
    // 0x80059550: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80059554: jr          $ra
    // 0x80059558: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80059558: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_8005955C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005955C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80059560: beq         $a0, $zero, L_80059584
    if (ctx->r4 == 0) {
        // 0x80059564: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_80059584;
    }
    // 0x80059564: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80059568: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8005956C: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    // 0x80059570: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    // 0x80059574: jal         0x800599EC
    // 0x80059578: addu        $a2, $a3, $zero
    ctx->r6 = ADD32(ctx->r7, 0);
    func_800599EC(rdram, ctx);
        goto after_0;
    // 0x80059578: addu        $a2, $a3, $zero
    ctx->r6 = ADD32(ctx->r7, 0);
    after_0:
    // 0x8005957C: j           L_80059594
    // 0x80059580: nop

        goto L_80059594;
    // 0x80059580: nop

L_80059584:
    // 0x80059584: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // 0x80059588: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    // 0x8005958C: jal         0x800599C0
    // 0x80059590: addu        $a2, $a3, $zero
    ctx->r6 = ADD32(ctx->r7, 0);
    func_800599C0(rdram, ctx);
        goto after_1;
    // 0x80059590: addu        $a2, $a3, $zero
    ctx->r6 = ADD32(ctx->r7, 0);
    after_1:
L_80059594:
    // 0x80059594: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80059598: jr          $ra
    // 0x8005959C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8005959C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
