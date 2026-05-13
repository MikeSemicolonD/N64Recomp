#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_80077AC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077AC0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80077AC4: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // 0x80077AC8: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x80077ACC: mtc1        $a2, $f0
    ctx->f0.u32l = ctx->r6;
    // 0x80077AD0: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x80077AD4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80077AD8: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80077ADC: jal         0x80075BB0
    // 0x80077AE0: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    func_80075BB0(rdram, ctx);
        goto after_0;
    // 0x80077AE0: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    after_0:
    // 0x80077AE4: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80077AE8: jr          $ra
    // 0x80077AEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80077AEC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80077AF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80077AF0: addiu       $sp, $sp, -0x118
    ctx->r29 = ADD32(ctx->r29, -0X118);
    // 0x80077AF4: sw          $s6, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r22;
    // 0x80077AF8: addu        $s6, $a0, $zero
    ctx->r22 = ADD32(ctx->r4, 0);
    // 0x80077AFC: sw          $s5, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r21;
    // 0x80077B00: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80077B04: addiu       $v1, $a1, -0x1
    ctx->r3 = ADD32(ctx->r5, -0X1);
    // 0x80077B08: sltiu       $v0, $v1, 0xF
    ctx->r2 = ctx->r3 < 0XF ? 1 : 0;
    // 0x80077B0C: sw          $ra, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r31;
    // 0x80077B10: sw          $fp, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r30;
    // 0x80077B14: sw          $s7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r23;
    // 0x80077B18: sw          $s4, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r20;
    // 0x80077B1C: sw          $s3, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r19;
    // 0x80077B20: sw          $s2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r18;
    // 0x80077B24: sw          $s1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r17;
    // 0x80077B28: sw          $s0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r16;
    // 0x80077B2C: sdc1        $f30, 0x110($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X110, ctx->r29);
    // 0x80077B30: sdc1        $f28, 0x108($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X108, ctx->r29);
    // 0x80077B34: sdc1        $f26, 0x100($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X100, ctx->r29);
    // 0x80077B38: sdc1        $f24, 0xF8($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0XF8, ctx->r29);
    // 0x80077B3C: sdc1        $f22, 0xF0($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0XF0, ctx->r29);
    // 0x80077B40: sdc1        $f20, 0xE8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XE8, ctx->r29);
    // 0x80077B44: lw          $s2, 0x4($s6)
    ctx->r18 = MEM_W(ctx->r22, 0X4);
    // 0x80077B48: beq         $v0, $zero, L_80078DF0
    if (ctx->r2 == 0) {
        // 0x80077B4C: addu        $s5, $a2, $zero
        ctx->r21 = ADD32(ctx->r6, 0);
            goto L_80078DF0;
    }
    // 0x80077B4C: addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // 0x80077B50: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80077B54: addiu       $v0, $v0, -0x2C78
    ctx->r2 = ADD32(ctx->r2, -0X2C78);
    // 0x80077B58: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80077B5C: addu        $v1, $v1, $v0
    gpr jr_addend_80077B64 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80077B60: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x80077B64: jr          $v0
    // 0x80077B68: nop

    switch (jr_addend_80077B64 >> 2) {
        case 0: goto L_80077B6C; break;
        case 1: goto L_80078044; break;
        case 2: goto L_800780BC; break;
        case 3: goto L_800782BC; break;
        case 4: goto L_800788D0; break;
        case 5: goto L_80078DF0; break;
        case 6: goto L_80078DD4; break;
        case 7: goto L_80078DF0; break;
        case 8: goto L_80078DF0; break;
        case 9: goto L_80078DF0; break;
        case 10: goto L_80078DF0; break;
        case 11: goto L_80078DF0; break;
        case 12: goto L_80078DF0; break;
        case 13: goto L_80078DF0; break;
        case 14: goto L_80078D60; break;
        default: switch_error(__func__, 0x80077B64, 0x8003D388);
    }
    // 0x80077B68: nop

L_80077B6C:
    // 0x80077B6C: addiu       $a0, $zero, 0x214
    ctx->r4 = ADD32(0, 0X214);
    // 0x80077B70: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80077B74: jal         0x80001ACC
    // 0x80077B78: addu        $s1, $s5, $zero
    ctx->r17 = ADD32(ctx->r21, 0);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x80077B78: addu        $s1, $s5, $zero
    ctx->r17 = ADD32(ctx->r21, 0);
    after_0:
    // 0x80077B7C: lhu         $v1, 0x14($s6)
    ctx->r3 = MEM_HU(ctx->r22, 0X14);
    // 0x80077B80: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x80077B84: sw          $s2, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->r18;
    // 0x80077B88: ori         $v1, $v1, 0x100
    ctx->r3 = ctx->r3 | 0X100;
    // 0x80077B8C: sh          $v1, 0x14($s6)
    MEM_H(0X14, ctx->r22) = ctx->r3;
    // 0x80077B90: sw          $s1, 0x68($s2)
    MEM_W(0X68, ctx->r18) = ctx->r17;
    // 0x80077B94: lw          $a0, 0x5C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X5C);
    // 0x80077B98: jal         0x80056EB0
    // 0x80077B9C: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    walkMeshdef0List(rdram, ctx);
        goto after_1;
    // 0x80077B9C: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    after_1:
    // 0x80077BA0: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80077BA4: addiu       $a0, $a0, -0x2CC0
    ctx->r4 = ADD32(ctx->r4, -0X2CC0);
    // 0x80077BA8: jal         0x80056EB0
    // 0x80077BAC: sw          $v0, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->r2;
    walkMeshdef0List(rdram, ctx);
        goto after_2;
    // 0x80077BAC: sw          $v0, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->r2;
    after_2:
    // 0x80077BB0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80077BB4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80077BB8: lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
    // 0x80077BBC: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x80077BC0: jal         0x8005955C
    // 0x80077BC4: sw          $a0, 0x64($s2)
    MEM_W(0X64, ctx->r18) = ctx->r4;
    func_8005955C(rdram, ctx);
        goto after_3;
    // 0x80077BC4: sw          $a0, 0x64($s2)
    MEM_W(0X64, ctx->r18) = ctx->r4;
    after_3:
    // 0x80077BC8: lwc1        $f0, 0x10($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X10);
    // 0x80077BCC: swc1        $f0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f0.u32l;
    // 0x80077BD0: lwc1        $f0, 0x14($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80077BD4: swc1        $f0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f0.u32l;
    // 0x80077BD8: lwc1        $f0, 0x18($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X18);
    // 0x80077BDC: swc1        $f0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f0.u32l;
    // 0x80077BE0: lw          $a1, 0x1C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1C);
    // 0x80077BE4: lw          $a2, 0x20($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X20);
    // 0x80077BE8: lw          $a3, 0x24($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X24);
    // 0x80077BEC: jal         0x80059D78
    // 0x80077BF0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_80059D78(rdram, ctx);
        goto after_4;
    // 0x80077BF0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_4:
    // 0x80077BF4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80077BF8: lw          $v0, 0x30($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X30);
    // 0x80077BFC: swc1        $f0, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f0.u32l;
    // 0x80077C00: swc1        $f0, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f0.u32l;
    // 0x80077C04: swc1        $f0, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f0.u32l;
    // 0x80077C08: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80077C0C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80077C10: lwc1        $f2, -0x2C3C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2C3C);
    // 0x80077C14: lwc1        $f4, 0x34($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80077C18: lwc1        $f0, 0x28($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X28);
    // 0x80077C1C: div.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80077C20: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80077C24: swc1        $f0, 0x12C($s2)
    MEM_W(0X12C, ctx->r18) = ctx->f0.u32l;
    // 0x80077C28: lwc1        $f0, 0x28($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X28);
    // 0x80077C2C: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80077C30: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80077C34: lwc1        $f0, 0x2C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x80077C38: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80077C3C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80077C40: lwc1        $f0, 0x30($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X30);
    // 0x80077C44: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80077C48: addu        $s4, $s2, $zero
    ctx->r20 = ADD32(ctx->r18, 0);
    // 0x80077C4C: addiu       $s0, $zero, 0xA8
    ctx->r16 = ADD32(0, 0XA8);
    // 0x80077C50: lw          $a0, 0x30($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X30);
    // 0x80077C54: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80077C58: jal         0x8001CB64
    // 0x80077C5C: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_8001CB64(rdram, ctx);
        goto after_5;
    // 0x80077C5C: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_5:
    // 0x80077C60: lw          $a0, 0x30($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X30);
    // 0x80077C64: lw          $a1, 0x1C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1C);
    // 0x80077C68: jal         0x8001CB9C
    // 0x80077C6C: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_8001CB9C(rdram, ctx);
        goto after_6;
    // 0x80077C6C: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_6:
    // 0x80077C70: lw          $a0, 0x30($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X30);
    // 0x80077C74: lw          $a1, 0x20($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X20);
    // 0x80077C78: jal         0x8001CCCC
    // 0x80077C7C: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_8001CCCC(rdram, ctx);
        goto after_7;
    // 0x80077C7C: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_7:
    // 0x80077C80: lw          $a0, 0x30($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X30);
    // 0x80077C84: lw          $a1, 0x24($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X24);
    // 0x80077C88: jal         0x8001CDFC
    // 0x80077C8C: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_8001CDFC(rdram, ctx);
        goto after_8;
    // 0x80077C8C: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_8:
    // 0x80077C90: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x80077C94: lw          $a2, 0x4($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X4);
    // 0x80077C98: lw          $a0, 0x30($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X30);
    // 0x80077C9C: lw          $a3, 0x8($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X8);
    // 0x80077CA0: jal         0x8001CA90
    // 0x80077CA4: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_8001CA90(rdram, ctx);
        goto after_9;
    // 0x80077CA4: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_9:
    // 0x80077CA8: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80077CAC: sw          $s2, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->r18;
    // 0x80077CB0: lw          $v0, 0x30($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X30);
    // 0x80077CB4: addiu       $a1, $a1, -0x2CB4
    ctx->r5 = ADD32(ctx->r5, -0X2CB4);
    // 0x80077CB8: sw          $v0, 0xC($s6)
    MEM_W(0XC, ctx->r22) = ctx->r2;
    // 0x80077CBC: lw          $a0, 0x30($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X30);
    // 0x80077CC0: jal         0x80059434
    // 0x80077CC4: addiu       $a2, $s2, 0x9C
    ctx->r6 = ADD32(ctx->r18, 0X9C);
    func_80059434(rdram, ctx);
        goto after_10;
    // 0x80077CC4: addiu       $a2, $s2, 0x9C
    ctx->r6 = ADD32(ctx->r18, 0X9C);
    after_10:
    // 0x80077CC8: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80077CCC: addiu       $a1, $a1, -0x2CAC
    ctx->r5 = ADD32(ctx->r5, -0X2CAC);
    // 0x80077CD0: lw          $a0, 0x30($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X30);
    // 0x80077CD4: addiu       $a2, $s2, 0xA0
    ctx->r6 = ADD32(ctx->r18, 0XA0);
    // 0x80077CD8: jal         0x80059434
    // 0x80077CDC: sw          $v0, 0x70($s2)
    MEM_W(0X70, ctx->r18) = ctx->r2;
    func_80059434(rdram, ctx);
        goto after_11;
    // 0x80077CDC: sw          $v0, 0x70($s2)
    MEM_W(0X70, ctx->r18) = ctx->r2;
    after_11:
    // 0x80077CE0: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80077CE4: addiu       $a1, $a1, -0x2CA0
    ctx->r5 = ADD32(ctx->r5, -0X2CA0);
    // 0x80077CE8: lw          $a0, 0x30($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X30);
    // 0x80077CEC: addiu       $a2, $s2, 0xA4
    ctx->r6 = ADD32(ctx->r18, 0XA4);
    // 0x80077CF0: jal         0x80059434
    // 0x80077CF4: sw          $v0, 0x74($s2)
    MEM_W(0X74, ctx->r18) = ctx->r2;
    func_80059434(rdram, ctx);
        goto after_12;
    // 0x80077CF4: sw          $v0, 0x74($s2)
    MEM_W(0X74, ctx->r18) = ctx->r2;
    after_12:
    // 0x80077CF8: sw          $v0, 0x78($s2)
    MEM_W(0X78, ctx->r18) = ctx->r2;
    // 0x80077CFC: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80077D00: addiu       $t5, $v0, -0x2C98
    ctx->r13 = ADD32(ctx->r2, -0X2C98);
    // 0x80077D04: lw          $t2, 0x0($t5)
    ctx->r10 = MEM_W(ctx->r13, 0X0);
    // 0x80077D08: lw          $t3, 0x4($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X4);
    // 0x80077D0C: lb          $t4, 0x8($t5)
    ctx->r12 = MEM_B(ctx->r13, 0X8);
    // 0x80077D10: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x80077D14: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x80077D18: sb          $t4, 0x30($sp)
    MEM_B(0X30, ctx->r29) = ctx->r12;
L_80077D1C:
    // 0x80077D1C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80077D20: addu        $a2, $s2, $s0
    ctx->r6 = ADD32(ctx->r18, ctx->r16);
    // 0x80077D24: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80077D28: lw          $a0, 0x30($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X30);
    // 0x80077D2C: jal         0x80059434
    // 0x80077D30: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    func_80059434(rdram, ctx);
        goto after_13;
    // 0x80077D30: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    after_13:
    // 0x80077D34: sw          $v0, 0x7C($s4)
    MEM_W(0X7C, ctx->r20) = ctx->r2;
    // 0x80077D38: lbu         $v0, 0x2F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X2F);
    // 0x80077D3C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80077D40: sb          $v0, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r2;
    // 0x80077D44: slti        $v0, $s3, 0x8
    ctx->r2 = SIGNED(ctx->r19) < 0X8 ? 1 : 0;
    // 0x80077D48: bne         $v0, $zero, L_80077D1C
    if (ctx->r2 != 0) {
        // 0x80077D4C: addiu       $s4, $s4, 0x4
        ctx->r20 = ADD32(ctx->r20, 0X4);
            goto L_80077D1C;
    }
    // 0x80077D4C: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80077D50: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x80077D54: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80077D58: lw          $v0, -0x2C8C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2C8C);
    // 0x80077D5C: addu        $s0, $s2, $zero
    ctx->r16 = ADD32(ctx->r18, 0);
    // 0x80077D60: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_80077D64:
    // 0x80077D64: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80077D68: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80077D6C: lhu         $a0, 0x16($s6)
    ctx->r4 = MEM_HU(ctx->r22, 0X16);
    // 0x80077D70: jal         0x8003FA14
    // 0x80077D74: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    func_8003FA14(rdram, ctx);
        goto after_14;
    // 0x80077D74: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    after_14:
    // 0x80077D78: sh          $v0, 0xF4($s0)
    MEM_H(0XF4, ctx->r16) = ctx->r2;
    // 0x80077D7C: lbu         $v0, 0x2A($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X2A);
    // 0x80077D80: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80077D84: sb          $v0, 0x2A($sp)
    MEM_B(0X2A, ctx->r29) = ctx->r2;
    // 0x80077D88: slti        $v0, $s3, 0x8
    ctx->r2 = SIGNED(ctx->r19) < 0X8 ? 1 : 0;
    // 0x80077D8C: bne         $v0, $zero, L_80077D64
    if (ctx->r2 != 0) {
        // 0x80077D90: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_80077D64;
    }
    // 0x80077D90: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80077D94: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80077D98: addiu       $a1, $a1, -0x2C88
    ctx->r5 = ADD32(ctx->r5, -0X2C88);
    // 0x80077D9C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80077DA0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80077DA4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80077DA8: lw          $a0, 0x30($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X30);
    // 0x80077DAC: jal         0x80058360
    // 0x80077DB0: addiu       $a3, $s2, 0x34
    ctx->r7 = ADD32(ctx->r18, 0X34);
    func_80058360(rdram, ctx);
        goto after_15;
    // 0x80077DB0: addiu       $a3, $s2, 0x34
    ctx->r7 = ADD32(ctx->r18, 0X34);
    after_15:
    // 0x80077DB4: lwc1        $f6, 0x12C($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X12C);
    // 0x80077DB8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80077DBC: lwc1        $f0, -0x2C38($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2C38);
    // 0x80077DC0: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80077DC4: lwc1        $f4, 0x12C($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X12C);
    // 0x80077DC8: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80077DCC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80077DD0: lwc1        $f2, 0x50($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X50);
    // 0x80077DD4: lwc1        $f0, 0x4C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X4C);
    // 0x80077DD8: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x80077DDC: swc1        $f2, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f2.u32l;
    // 0x80077DE0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80077DE4: lwc1        $f2, -0x2C34($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2C34);
    // 0x80077DE8: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80077DEC: swc1        $f0, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->f0.u32l;
    // 0x80077DF0: lwc1        $f0, 0x54($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X54);
    // 0x80077DF4: addiu       $s3, $v0, -0x6AA0
    ctx->r19 = ADD32(ctx->r2, -0X6AA0);
    // 0x80077DF8: swc1        $f2, 0xCC($s2)
    MEM_W(0XCC, ctx->r18) = ctx->f2.u32l;
    // 0x80077DFC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80077E00: swc1        $f0, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f0.u32l;
    // 0x80077E04: swc1        $f6, 0xC8($s2)
    MEM_W(0XC8, ctx->r18) = ctx->f6.u32l;
    // 0x80077E08: swc1        $f4, 0xD0($s2)
    MEM_W(0XD0, ctx->r18) = ctx->f4.u32l;
    // 0x80077E0C: lw          $v0, 0x8C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8C);
    // 0x80077E10: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80077E14: bne         $v0, $s0, L_80077E20
    if (ctx->r2 != ctx->r16) {
        // 0x80077E18: addiu       $v1, $zero, 0x12
        ctx->r3 = ADD32(0, 0X12);
            goto L_80077E20;
    }
    // 0x80077E18: addiu       $v1, $zero, 0x12
    ctx->r3 = ADD32(0, 0X12);
    // 0x80077E1C: addiu       $v1, $zero, 0xE
    ctx->r3 = ADD32(0, 0XE);
L_80077E20:
    // 0x80077E20: addu        $v0, $v1, $s3
    ctx->r2 = ADD32(ctx->r3, ctx->r19);
    // 0x80077E24: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x80077E28: jal         0x8003E684
    // 0x80077E2C: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    func_8003E684(rdram, ctx);
        goto after_16;
    // 0x80077E2C: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    after_16:
    // 0x80077E30: sh          $v0, 0x148($s2)
    MEM_H(0X148, ctx->r18) = ctx->r2;
    // 0x80077E34: lw          $v0, 0x90($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X90);
    // 0x80077E38: beq         $v0, $zero, L_80077E68
    if (ctx->r2 == 0) {
        // 0x80077E3C: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_80077E68;
    }
    // 0x80077E3C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80077E40: lw          $v0, 0x8C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8C);
    // 0x80077E44: bne         $v0, $s0, L_80077E50
    if (ctx->r2 != ctx->r16) {
        // 0x80077E48: addiu       $v1, $zero, 0x18
        ctx->r3 = ADD32(0, 0X18);
            goto L_80077E50;
    }
    // 0x80077E48: addiu       $v1, $zero, 0x18
    ctx->r3 = ADD32(0, 0X18);
    // 0x80077E4C: addiu       $v1, $zero, 0x1A
    ctx->r3 = ADD32(0, 0X1A);
L_80077E50:
    // 0x80077E50: addu        $v0, $v1, $s3
    ctx->r2 = ADD32(ctx->r3, ctx->r19);
    // 0x80077E54: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x80077E58: jal         0x8003E684
    // 0x80077E5C: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    func_8003E684(rdram, ctx);
        goto after_17;
    // 0x80077E5C: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    after_17:
    // 0x80077E60: j           L_80077E6C
    // 0x80077E64: sh          $v0, 0x14A($s2)
    MEM_H(0X14A, ctx->r18) = ctx->r2;
        goto L_80077E6C;
    // 0x80077E64: sh          $v0, 0x14A($s2)
    MEM_H(0X14A, ctx->r18) = ctx->r2;
L_80077E68:
    // 0x80077E68: sh          $v0, 0x14A($s2)
    MEM_H(0X14A, ctx->r18) = ctx->r2;
L_80077E6C:
    // 0x80077E6C: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80077E70: addiu       $s0, $s0, -0x6AA0
    ctx->r16 = ADD32(ctx->r16, -0X6AA0);
    // 0x80077E74: lhu         $a0, 0x1C($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X1C);
    // 0x80077E78: jal         0x8003E684
    // 0x80077E7C: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    func_8003E684(rdram, ctx);
        goto after_18;
    // 0x80077E7C: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    after_18:
    // 0x80077E80: sh          $v0, 0x144($s2)
    MEM_H(0X144, ctx->r18) = ctx->r2;
    // 0x80077E84: lw          $a1, 0x8C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X8C);
    // 0x80077E88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80077E8C: beq         $a1, $v0, L_80077EA0
    if (ctx->r5 == ctx->r2) {
        // 0x80077E90: addiu       $v0, $zero, 0x26
        ctx->r2 = ADD32(0, 0X26);
            goto L_80077EA0;
    }
    // 0x80077E90: addiu       $v0, $zero, 0x26
    ctx->r2 = ADD32(0, 0X26);
    // 0x80077E94: bne         $a1, $zero, L_80077EA0
    if (ctx->r5 != 0) {
        // 0x80077E98: addiu       $v0, $zero, 0x2A
        ctx->r2 = ADD32(0, 0X2A);
            goto L_80077EA0;
    }
    // 0x80077E98: addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
    // 0x80077E9C: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
L_80077EA0:
    // 0x80077EA0: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x80077EA4: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x80077EA8: jal         0x8003E684
    // 0x80077EAC: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    func_8003E684(rdram, ctx);
        goto after_19;
    // 0x80077EAC: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    after_19:
    // 0x80077EB0: addiu       $a0, $s2, 0x150
    ctx->r4 = ADD32(ctx->r18, 0X150);
    // 0x80077EB4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80077EB8: lw          $v1, 0x30($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X30);
    // 0x80077EBC: lui         $a3, 0x4160
    ctx->r7 = S32(0X4160 << 16);
    // 0x80077EC0: addiu       $a2, $s2, 0x24
    ctx->r6 = ADD32(ctx->r18, 0X24);
    // 0x80077EC4: sh          $v0, 0x146($s2)
    MEM_H(0X146, ctx->r18) = ctx->r2;
    // 0x80077EC8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80077ECC: lwc1        $f0, 0x12C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X12C);
    // 0x80077ED0: lwc1        $f2, 0x44($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X44);
    // 0x80077ED4: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80077ED8: sh          $v0, 0x106($s2)
    MEM_H(0X106, ctx->r18) = ctx->r2;
    // 0x80077EDC: sh          $v0, 0x104($s2)
    MEM_H(0X104, ctx->r18) = ctx->r2;
    // 0x80077EE0: sh          $v0, 0x10A($s2)
    MEM_H(0X10A, ctx->r18) = ctx->r2;
    // 0x80077EE4: sh          $v0, 0x108($s2)
    MEM_H(0X108, ctx->r18) = ctx->r2;
    // 0x80077EE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80077EEC: sb          $v0, 0x1D8($s2)
    MEM_B(0X1D8, ctx->r18) = ctx->r2;
    // 0x80077EF0: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80077EF4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80077EF8: lwc1        $f0, -0x2C30($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2C30);
    // 0x80077EFC: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80077F00: sw          $zero, 0x130($s2)
    MEM_W(0X130, ctx->r18) = 0;
    // 0x80077F04: sw          $zero, 0x134($s2)
    MEM_W(0X134, ctx->r18) = 0;
    // 0x80077F08: sw          $zero, 0x138($s2)
    MEM_W(0X138, ctx->r18) = 0;
    // 0x80077F0C: sw          $zero, 0x13C($s2)
    MEM_W(0X13C, ctx->r18) = 0;
    // 0x80077F10: sw          $zero, 0x140($s2)
    MEM_W(0X140, ctx->r18) = 0;
    // 0x80077F14: sb          $zero, 0x124($s2)
    MEM_B(0X124, ctx->r18) = 0;
    // 0x80077F18: sh          $zero, 0x126($s2)
    MEM_H(0X126, ctx->r18) = 0;
    // 0x80077F1C: sw          $zero, 0x14C($s2)
    MEM_W(0X14C, ctx->r18) = 0;
    // 0x80077F20: swc1        $f2, 0x128($s2)
    MEM_W(0X128, ctx->r18) = ctx->f2.u32l;
    // 0x80077F24: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80077F28: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x80077F2C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80077F30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80077F34: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80077F38: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x80077F3C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80077F40: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x80077F44: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80077F48: jal         0x80098BDC
    // 0x80077F4C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_80098BDC(rdram, ctx);
        goto after_20;
    // 0x80077F4C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_20:
    // 0x80077F50: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80077F54: lbu         $v0, 0xB39($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB39);
    // 0x80077F58: bne         $v0, $zero, L_80077F84
    if (ctx->r2 != 0) {
        // 0x80077F5C: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80077F84;
    }
    // 0x80077F5C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80077F60: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80077F64: addiu       $a0, $s2, 0x6C
    ctx->r4 = ADD32(ctx->r18, 0X6C);
    // 0x80077F68: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80077F6C: addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    // 0x80077F70: lui         $a3, 0x8008
    ctx->r7 = S32(0X8008 << 16);
    // 0x80077F74: jal         0x800EC588
    // 0x80077F78: addiu       $a3, $a3, -0x6E04
    ctx->r7 = ADD32(ctx->r7, -0X6E04);
    func_800EC588(rdram, ctx);
        goto after_21;
    // 0x80077F78: addiu       $a3, $a3, -0x6E04
    ctx->r7 = ADD32(ctx->r7, -0X6E04);
    after_21:
    // 0x80077F7C: j           L_80078030
    // 0x80077F80: nop

        goto L_80078030;
    // 0x80077F80: nop

L_80077F84:
    // 0x80077F84: sb          $zero, 0x125($s2)
    MEM_B(0X125, ctx->r18) = 0;
    // 0x80077F88: lbu         $v0, 0xBA0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XBA0);
    // 0x80077F8C: beq         $v0, $zero, L_80078030
    if (ctx->r2 == 0) {
        // 0x80077F90: addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
            goto L_80078030;
    }
    // 0x80077F90: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x80077F94: addiu       $s5, $sp, 0x38
    ctx->r21 = ADD32(ctx->r29, 0X38);
    // 0x80077F98: addiu       $s4, $sp, 0x70
    ctx->r20 = ADD32(ctx->r29, 0X70);
    // 0x80077F9C: lui         $fp, 0x8004
    ctx->r30 = S32(0X8004 << 16);
    // 0x80077FA0: ori         $s7, $zero, 0xFFFF
    ctx->r23 = 0 | 0XFFFF;
L_80077FA4:
    // 0x80077FA4: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x80077FA8: sll         $v0, $s3, 2
    ctx->r2 = S32(ctx->r19 << 2);
    // 0x80077FAC: addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // 0x80077FB0: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80077FB4: addiu       $t3, $zero, 0x63
    ctx->r11 = ADD32(0, 0X63);
    // 0x80077FB8: addiu       $t4, $zero, 0x62
    ctx->r12 = ADD32(0, 0X62);
    // 0x80077FBC: sw          $t2, 0xD4($v0)
    MEM_W(0XD4, ctx->r2) = ctx->r10;
    // 0x80077FC0: addiu       $v0, $s3, 0x31
    ctx->r2 = ADD32(ctx->r19, 0X31);
    // 0x80077FC4: sb          $t3, 0x68($sp)
    MEM_B(0X68, ctx->r29) = ctx->r11;
    // 0x80077FC8: sb          $t4, 0x69($sp)
    MEM_B(0X69, ctx->r29) = ctx->r12;
    // 0x80077FCC: sb          $v0, 0x6A($sp)
    MEM_B(0X6A, ctx->r29) = ctx->r2;
    // 0x80077FD0: jal         0x80079A94
    // 0x80077FD4: sb          $zero, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = 0;
    func_80079A94(rdram, ctx);
        goto after_22;
    // 0x80077FD4: sb          $zero, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = 0;
    after_22:
    // 0x80077FD8: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x80077FDC: addiu       $a1, $fp, -0x2C84
    ctx->r5 = ADD32(ctx->r30, -0X2C84);
    // 0x80077FE0: addiu       $s1, $s3, 0x1
    ctx->r17 = ADD32(ctx->r19, 0X1);
    // 0x80077FE4: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x80077FE8: jal         0x80033CC4
    // 0x80077FEC: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    sprintf_recomp(rdram, ctx);
        goto after_23;
    // 0x80077FEC: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    after_23:
    // 0x80077FF0: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x80077FF4: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // 0x80077FF8: jal         0x80079BC8
    // 0x80077FFC: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    func_80079BC8(rdram, ctx);
        goto after_24;
    // 0x80077FFC: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    after_24:
    // 0x80078000: sll         $s0, $s3, 1
    ctx->r16 = S32(ctx->r19 << 1);
    // 0x80078004: addu        $s0, $s2, $s0
    ctx->r16 = ADD32(ctx->r18, ctx->r16);
    // 0x80078008: lhu         $a0, 0xF4($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0XF4);
    // 0x8007800C: jal         0x8003ED74
    // 0x80078010: addu        $s3, $s1, $zero
    ctx->r19 = ADD32(ctx->r17, 0);
    func_8003ED74(rdram, ctx);
        goto after_25;
    // 0x80078010: addu        $s3, $s1, $zero
    ctx->r19 = ADD32(ctx->r17, 0);
    after_25:
    // 0x80078014: slti        $v0, $s3, 0x7
    ctx->r2 = SIGNED(ctx->r19) < 0X7 ? 1 : 0;
    // 0x80078018: bne         $v0, $zero, L_80077FA4
    if (ctx->r2 != 0) {
        // 0x8007801C: sh          $s7, 0xF4($s0)
        MEM_H(0XF4, ctx->r16) = ctx->r23;
            goto L_80077FA4;
    }
    // 0x8007801C: sh          $s7, 0xF4($s0)
    MEM_H(0XF4, ctx->r16) = ctx->r23;
    // 0x80078020: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80078024: sw          $v0, 0xF0($s2)
    MEM_W(0XF0, ctx->r18) = ctx->r2;
    // 0x80078028: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x8007802C: sh          $v0, 0x126($s2)
    MEM_H(0X126, ctx->r18) = ctx->r2;
L_80078030:
    // 0x80078030: lw          $a1, 0x30($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X30);
    // 0x80078034: jal         0x80071308
    // 0x80078038: addiu       $a0, $s2, 0x1DC
    ctx->r4 = ADD32(ctx->r18, 0X1DC);
    func_80071308(rdram, ctx);
        goto after_26;
    // 0x80078038: addiu       $a0, $s2, 0x1DC
    ctx->r4 = ADD32(ctx->r18, 0X1DC);
    after_26:
    // 0x8007803C: j           L_80078DF4
    // 0x80078040: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80078DF4;
    // 0x80078040: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80078044:
    // 0x80078044: lbu         $v1, 0x1D8($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X1D8);
    // 0x80078048: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007804C: bne         $v1, $v0, L_80078064
    if (ctx->r3 != ctx->r2) {
        // 0x80078050: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80078064;
    }
    // 0x80078050: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80078054: sb          $zero, 0x1D8($s2)
    MEM_B(0X1D8, ctx->r18) = 0;
    // 0x80078058: jal         0x80098DE0
    // 0x8007805C: addiu       $a0, $s2, 0x150
    ctx->r4 = ADD32(ctx->r18, 0X150);
    func_80098DE0(rdram, ctx);
        goto after_27;
    // 0x8007805C: addiu       $a0, $s2, 0x150
    ctx->r4 = ADD32(ctx->r18, 0X150);
    after_27:
    // 0x80078060: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_80078064:
    // 0x80078064: lbu         $v0, 0xB39($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB39);
    // 0x80078068: bne         $v0, $zero, L_8007809C
    if (ctx->r2 != 0) {
        // 0x8007806C: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_8007809C;
    }
    // 0x8007806C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80078070: lw          $v0, 0x68($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X68);
    // 0x80078074: lbu         $a1, 0x125($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X125);
    // 0x80078078: addiu       $v0, $v0, 0x70
    ctx->r2 = ADD32(ctx->r2, 0X70);
    // 0x8007807C: xori        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 ^ 0X1;
    // 0x80078080: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80078084: lw          $a0, 0x6C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X6C);
    // 0x80078088: lw          $a2, 0x68($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X68);
    // 0x8007808C: jal         0x800F1E7C
    // 0x80078090: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    func_800F1E7C(rdram, ctx);
        goto after_28;
    // 0x80078090: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    after_28:
    // 0x80078094: jal         0x800EC684
    // 0x80078098: addiu       $a0, $s2, 0x6C
    ctx->r4 = ADD32(ctx->r18, 0X6C);
    func_800EC684(rdram, ctx);
        goto after_29;
    // 0x80078098: addiu       $a0, $s2, 0x6C
    ctx->r4 = ADD32(ctx->r18, 0X6C);
    after_29:
L_8007809C:
    // 0x8007809C: lw          $a1, 0x30($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X30);
    // 0x800780A0: jal         0x80072AF8
    // 0x800780A4: addiu       $a0, $s2, 0x1DC
    ctx->r4 = ADD32(ctx->r18, 0X1DC);
    func_80072AF8(rdram, ctx);
        goto after_30;
    // 0x800780A4: addiu       $a0, $s2, 0x1DC
    ctx->r4 = ADD32(ctx->r18, 0X1DC);
    after_30:
    // 0x800780A8: lw          $a0, 0x30($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X30);
    // 0x800780AC: jal         0x8005779C
    // 0x800780B0: nop

    func_8005779C(rdram, ctx);
        goto after_31;
    // 0x800780B0: nop

    after_31:
    // 0x800780B4: j           L_80078DF4
    // 0x800780B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80078DF4;
    // 0x800780B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800780BC:
    // 0x800780BC: lwc1        $f20, 0x0($s5)
    ctx->f20.u32l = MEM_W(ctx->r21, 0X0);
    // 0x800780C0: jal         0x8007636C
    // 0x800780C4: nop

    func_8007636C(rdram, ctx);
        goto after_32;
    // 0x800780C4: nop

    after_32:
    // 0x800780C8: lbu         $v1, 0x125($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X125);
    // 0x800780CC: beq         $v1, $zero, L_800780E4
    if (ctx->r3 == 0) {
        // 0x800780D0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800780E4;
    }
    // 0x800780D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800780D4: beq         $v1, $v0, L_80078148
    if (ctx->r3 == ctx->r2) {
        // 0x800780D8: nop
    
            goto L_80078148;
    }
    // 0x800780D8: nop

    // 0x800780DC: j           L_80078238
    // 0x800780E0: nop

        goto L_80078238;
    // 0x800780E0: nop

L_800780E4:
    // 0x800780E4: lw          $v0, 0x68($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X68);
    // 0x800780E8: lwc1        $f0, 0x94($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X94);
    // 0x800780EC: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800780F0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800780F4: lwc1        $f2, -0x2C2C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2C2C);
    // 0x800780F8: mul.s       $f22, $f0, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800780FC: lwc1        $f12, 0x134($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X134);
    // 0x80078100: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80078104: lwc1        $f20, -0x2C28($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X2C28);
    // 0x80078108: add.s       $f12, $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f22.fl;
    // 0x8007810C: jal         0x8001E20C
    // 0x80078110: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    floatModulo(rdram, ctx);
        goto after_33;
    // 0x80078110: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_33:
    // 0x80078114: lwc1        $f12, 0x130($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X130);
    // 0x80078118: sub.s       $f12, $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f22.fl;
    // 0x8007811C: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x80078120: jal         0x8001E20C
    // 0x80078124: swc1        $f0, 0x134($s2)
    MEM_W(0X134, ctx->r18) = ctx->f0.u32l;
    floatModulo(rdram, ctx);
        goto after_34;
    // 0x80078124: swc1        $f0, 0x134($s2)
    MEM_W(0X134, ctx->r18) = ctx->f0.u32l;
    after_34:
    // 0x80078128: add.s       $f2, $f22, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = ctx->f22.fl + ctx->f22.fl;
    // 0x8007812C: lwc1        $f12, 0x138($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X138);
    // 0x80078130: add.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x80078134: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x80078138: jal         0x8001E20C
    // 0x8007813C: swc1        $f0, 0x130($s2)
    MEM_W(0X130, ctx->r18) = ctx->f0.u32l;
    floatModulo(rdram, ctx);
        goto after_35;
    // 0x8007813C: swc1        $f0, 0x130($s2)
    MEM_W(0X130, ctx->r18) = ctx->f0.u32l;
    after_35:
    // 0x80078140: j           L_80078238
    // 0x80078144: swc1        $f0, 0x138($s2)
    MEM_W(0X138, ctx->r18) = ctx->f0.u32l;
        goto L_80078238;
    // 0x80078144: swc1        $f0, 0x138($s2)
    MEM_W(0X138, ctx->r18) = ctx->f0.u32l;
L_80078148:
    // 0x80078148: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007814C: lwc1        $f0, -0x2C24($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2C24);
    // 0x80078150: lwc1        $f2, 0x13C($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X13C);
    // 0x80078154: div.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80078158: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8007815C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80078160: lwc1        $f22, -0x2C20($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X2C20);
    // 0x80078164: c.lt.s      $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f22.fl < ctx->f2.fl;
    // 0x80078168: nop

    // 0x8007816C: bc1f        L_80078178
    if (!c1cs) {
        // 0x80078170: swc1        $f2, 0x13C($s2)
        MEM_W(0X13C, ctx->r18) = ctx->f2.u32l;
            goto L_80078178;
    }
    // 0x80078170: swc1        $f2, 0x13C($s2)
    MEM_W(0X13C, ctx->r18) = ctx->f2.u32l;
    // 0x80078174: swc1        $f22, 0x13C($s2)
    MEM_W(0X13C, ctx->r18) = ctx->f22.u32l;
L_80078178:
    // 0x80078178: lwc1        $f12, 0x13C($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X13C);
    // 0x8007817C: jal         0x800662E0
    // 0x80078180: ori         $s0, $zero, 0xFFFF
    ctx->r16 = 0 | 0XFFFF;
    func_800662E0(rdram, ctx);
        goto after_36;
    // 0x80078180: ori         $s0, $zero, 0xFFFF
    ctx->r16 = 0 | 0XFFFF;
    after_36:
    // 0x80078184: lw          $v0, 0x68($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X68);
    // 0x80078188: swc1        $f0, 0x140($s2)
    MEM_W(0X140, ctx->r18) = ctx->f0.u32l;
    // 0x8007818C: lwc1        $f2, 0x94($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X94);
    // 0x80078190: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x80078194: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80078198: lwc1        $f4, -0x2C1C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2C1C);
    // 0x8007819C: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800781A0: sub.s       $f0, $f22, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f22.fl - ctx->f0.fl;
    // 0x800781A4: mul.s       $f22, $f2, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800781A8: lwc1        $f12, 0x134($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X134);
    // 0x800781AC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800781B0: lwc1        $f20, -0x2C18($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X2C18);
    // 0x800781B4: add.s       $f12, $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f22.fl;
    // 0x800781B8: jal         0x8001E20C
    // 0x800781BC: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    floatModulo(rdram, ctx);
        goto after_37;
    // 0x800781BC: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    after_37:
    // 0x800781C0: lwc1        $f12, 0x130($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X130);
    // 0x800781C4: sub.s       $f12, $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f22.fl;
    // 0x800781C8: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x800781CC: jal         0x8001E20C
    // 0x800781D0: swc1        $f0, 0x134($s2)
    MEM_W(0X134, ctx->r18) = ctx->f0.u32l;
    floatModulo(rdram, ctx);
        goto after_38;
    // 0x800781D0: swc1        $f0, 0x134($s2)
    MEM_W(0X134, ctx->r18) = ctx->f0.u32l;
    after_38:
    // 0x800781D4: lhu         $v0, 0x108($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X108);
    // 0x800781D8: beq         $v0, $s0, L_80078200
    if (ctx->r2 == ctx->r16) {
        // 0x800781DC: swc1        $f0, 0x130($s2)
        MEM_W(0X130, ctx->r18) = ctx->f0.u32l;
            goto L_80078200;
    }
    // 0x800781DC: swc1        $f0, 0x130($s2)
    MEM_W(0X130, ctx->r18) = ctx->f0.u32l;
    // 0x800781E0: lwc1        $f2, 0x110($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X110);
    // 0x800781E4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800781E8: lwc1        $f0, -0x2C14($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2C14);
    // 0x800781EC: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800781F0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800781F4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800781F8: jal         0x80078E3C
    // 0x800781FC: swc1        $f2, 0x110($s2)
    MEM_W(0X110, ctx->r18) = ctx->f2.u32l;
    func_80078E3C(rdram, ctx);
        goto after_39;
    // 0x800781FC: swc1        $f2, 0x110($s2)
    MEM_W(0X110, ctx->r18) = ctx->f2.u32l;
    after_39:
L_80078200:
    // 0x80078200: lhu         $v0, 0x10A($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X10A);
    // 0x80078204: beq         $v0, $s0, L_80078214
    if (ctx->r2 == ctx->r16) {
        // 0x80078208: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_80078214;
    }
    // 0x80078208: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8007820C: jal         0x80078E3C
    // 0x80078210: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_80078E3C(rdram, ctx);
        goto after_40;
    // 0x80078210: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_40:
L_80078214:
    // 0x80078214: lbu         $v1, 0x124($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X124);
    // 0x80078218: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8007821C: bne         $v1, $v0, L_80078238
    if (ctx->r3 != ctx->r2) {
        // 0x80078220: nop
    
            goto L_80078238;
    }
    // 0x80078220: nop

L_80078224:
    // 0x80078224: lhu         $a0, 0x16($s6)
    ctx->r4 = MEM_HU(ctx->r22, 0X16);
    // 0x80078228: jal         0x8003ED74
    // 0x8007822C: nop

    func_8003ED74(rdram, ctx);
        goto after_41;
    // 0x8007822C: nop

    after_41:
    // 0x80078230: j           L_80078DF4
    // 0x80078234: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80078DF4;
    // 0x80078234: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80078238:
    // 0x80078238: lw          $v0, 0x68($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X68);
    // 0x8007823C: lw          $v0, 0x88($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X88);
    // 0x80078240: beql        $v0, $zero, L_80078278
    if (ctx->r2 == 0) {
        // 0x80078244: sw          $zero, 0x14C($s2)
        MEM_W(0X14C, ctx->r18) = 0;
            goto L_80078278;
    }
    goto skip_0;
    // 0x80078244: sw          $zero, 0x14C($s2)
    MEM_W(0X14C, ctx->r18) = 0;
    skip_0:
    // 0x80078248: jal         0x80047D40
    // 0x8007824C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_80047D40(rdram, ctx);
        goto after_42;
    // 0x8007824C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_42:
    // 0x80078250: beq         $v0, $zero, L_80078260
    if (ctx->r2 == 0) {
        // 0x80078254: nop
    
            goto L_80078260;
    }
    // 0x80078254: nop

    // 0x80078258: j           L_80078278
    // 0x8007825C: sw          $zero, 0x14C($s2)
    MEM_W(0X14C, ctx->r18) = 0;
        goto L_80078278;
    // 0x8007825C: sw          $zero, 0x14C($s2)
    MEM_W(0X14C, ctx->r18) = 0;
L_80078260:
    // 0x80078260: lw          $v0, 0x14C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X14C);
    // 0x80078264: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80078268: sw          $v0, 0x14C($s2)
    MEM_W(0X14C, ctx->r18) = ctx->r2;
    // 0x8007826C: slti        $v0, $v0, 0x15
    ctx->r2 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x80078270: beq         $v0, $zero, L_80078224
    if (ctx->r2 == 0) {
        // 0x80078274: nop
    
            goto L_80078224;
    }
    // 0x80078274: nop

L_80078278:
    // 0x80078278: lbu         $v1, 0x1DC($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X1DC);
    // 0x8007827C: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80078280: beq         $v1, $v0, L_8007829C
    if (ctx->r3 == ctx->r2) {
        // 0x80078284: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8007829C;
    }
    // 0x80078284: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80078288: lw          $a1, 0x30($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X30);
    // 0x8007828C: lw          $a2, 0x0($s5)
    ctx->r6 = MEM_W(ctx->r21, 0X0);
    // 0x80078290: jal         0x80072BE0
    // 0x80078294: addiu       $a0, $s2, 0x1DC
    ctx->r4 = ADD32(ctx->r18, 0X1DC);
    func_80072BE0(rdram, ctx);
        goto after_43;
    // 0x80078294: addiu       $a0, $s2, 0x1DC
    ctx->r4 = ADD32(ctx->r18, 0X1DC);
    after_43:
    // 0x80078298: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_8007829C:
    // 0x8007829C: lbu         $v0, 0xB39($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB39);
    // 0x800782A0: bne         $v0, $zero, L_80078DF4
    if (ctx->r2 != 0) {
        // 0x800782A4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80078DF4;
    }
    // 0x800782A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800782A8: lw          $a0, 0x6C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X6C);
    // 0x800782AC: jal         0x800EC6C0
    // 0x800782B0: nop

    func_800EC6C0(rdram, ctx);
        goto after_44;
    // 0x800782B0: nop

    after_44:
    // 0x800782B4: j           L_80078DF4
    // 0x800782B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80078DF4;
    // 0x800782B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800782BC:
    // 0x800782BC: addu        $s6, $s5, $zero
    ctx->r22 = ADD32(ctx->r21, 0);
    // 0x800782C0: lw          $v0, 0x70($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X70);
    // 0x800782C4: lw          $s0, 0x9C($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X9C);
    // 0x800782C8: addiu       $s1, $v0, 0x1C
    ctx->r17 = ADD32(ctx->r2, 0X1C);
    // 0x800782CC: jal         0x8001CA50
    // 0x800782D0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA50(rdram, ctx);
        goto after_45;
    // 0x800782D0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_45:
    // 0x800782D4: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x800782D8: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800782DC: beq         $v0, $zero, L_80078310
    if (ctx->r2 == 0) {
        // 0x800782E0: nop
    
            goto L_80078310;
    }
    // 0x800782E0: nop

    // 0x800782E4: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800782E8: lwc1        $f2, 0x58($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800782EC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800782F0: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x800782F4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800782F8: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800782FC: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80078300: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80078304: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80078308: jal         0x8001CA90
    // 0x8007830C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA90(rdram, ctx);
        goto after_46;
    // 0x8007830C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_46:
L_80078310:
    // 0x80078310: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x80078314: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x80078318: beq         $v0, $zero, L_80078334
    if (ctx->r2 == 0) {
        // 0x8007831C: nop
    
            goto L_80078334;
    }
    // 0x8007831C: nop

    // 0x80078320: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    // 0x80078324: lw          $a2, 0x60($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X60);
    // 0x80078328: lw          $a3, 0x64($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X64);
    // 0x8007832C: jal         0x8001CB04
    // 0x80078330: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CB04(rdram, ctx);
        goto after_47;
    // 0x80078330: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_47:
L_80078334:
    // 0x80078334: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x80078338: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x8007833C: beq         $v0, $zero, L_8007834C
    if (ctx->r2 == 0) {
        // 0x80078340: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_8007834C;
    }
    // 0x80078340: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80078344: jal         0x8001DAEC
    // 0x80078348: addiu       $a1, $s0, 0x68
    ctx->r5 = ADD32(ctx->r16, 0X68);
    func_8001DAEC(rdram, ctx);
        goto after_48;
    // 0x80078348: addiu       $a1, $s0, 0x68
    ctx->r5 = ADD32(ctx->r16, 0X68);
    after_48:
L_8007834C:
    // 0x8007834C: lw          $a1, 0x134($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X134);
    // 0x80078350: jal         0x8001CCCC
    // 0x80078354: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CCCC(rdram, ctx);
        goto after_49;
    // 0x80078354: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_49:
    // 0x80078358: lw          $a0, 0x4C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4C);
    // 0x8007835C: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x80078360: andi        $v1, $a0, 0x9
    ctx->r3 = ctx->r4 & 0X9;
    // 0x80078364: bne         $v1, $v0, L_800783A4
    if (ctx->r3 != ctx->r2) {
        // 0x80078368: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_800783A4;
    }
    // 0x80078368: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x8007836C: lwc1        $f2, 0x78($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80078370: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80078374: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80078378: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x8007837C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80078380: lwc1        $f2, 0x7C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80078384: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80078388: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x8007838C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80078390: lwc1        $f2, 0x80($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X80);
    // 0x80078394: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80078398: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8007839C: j           L_800783D4
    // 0x800783A0: nop

        goto L_800783D4;
    // 0x800783A0: nop

L_800783A4:
    // 0x800783A4: bne         $v1, $v0, L_800783C0
    if (ctx->r3 != ctx->r2) {
        // 0x800783A8: andi        $v0, $a0, 0x1
        ctx->r2 = ctx->r4 & 0X1;
            goto L_800783C0;
    }
    // 0x800783A8: andi        $v0, $a0, 0x1
    ctx->r2 = ctx->r4 & 0X1;
    // 0x800783AC: lw          $a1, 0x78($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X78);
    // 0x800783B0: lw          $a2, 0x7C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X7C);
    // 0x800783B4: lw          $a3, 0x80($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X80);
    // 0x800783B8: j           L_800783D4
    // 0x800783BC: nop

        goto L_800783D4;
    // 0x800783BC: nop

L_800783C0:
    // 0x800783C0: beq         $v0, $zero, L_800783DC
    if (ctx->r2 == 0) {
        // 0x800783C4: nop
    
            goto L_800783DC;
    }
    // 0x800783C4: nop

    // 0x800783C8: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    // 0x800783CC: lw          $a2, 0x54($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X54);
    // 0x800783D0: lw          $a3, 0x58($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X58);
L_800783D4:
    // 0x800783D4: jal         0x8001CA90
    // 0x800783D8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA90(rdram, ctx);
        goto after_50;
    // 0x800783D8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_50:
L_800783DC:
    // 0x800783DC: lw          $v0, 0x74($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X74);
    // 0x800783E0: lw          $s0, 0xA0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0XA0);
    // 0x800783E4: addiu       $s1, $v0, 0x1C
    ctx->r17 = ADD32(ctx->r2, 0X1C);
    // 0x800783E8: jal         0x8001CA50
    // 0x800783EC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA50(rdram, ctx);
        goto after_51;
    // 0x800783EC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_51:
    // 0x800783F0: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x800783F4: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800783F8: beq         $v0, $zero, L_8007842C
    if (ctx->r2 == 0) {
        // 0x800783FC: nop
    
            goto L_8007842C;
    }
    // 0x800783FC: nop

    // 0x80078400: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80078404: lwc1        $f2, 0x58($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80078408: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8007840C: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x80078410: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80078414: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80078418: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8007841C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80078420: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80078424: jal         0x8001CA90
    // 0x80078428: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA90(rdram, ctx);
        goto after_52;
    // 0x80078428: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_52:
L_8007842C:
    // 0x8007842C: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x80078430: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x80078434: beq         $v0, $zero, L_80078450
    if (ctx->r2 == 0) {
        // 0x80078438: nop
    
            goto L_80078450;
    }
    // 0x80078438: nop

    // 0x8007843C: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    // 0x80078440: lw          $a2, 0x60($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X60);
    // 0x80078444: lw          $a3, 0x64($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X64);
    // 0x80078448: jal         0x8001CB04
    // 0x8007844C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CB04(rdram, ctx);
        goto after_53;
    // 0x8007844C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_53:
L_80078450:
    // 0x80078450: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x80078454: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x80078458: beq         $v0, $zero, L_80078468
    if (ctx->r2 == 0) {
        // 0x8007845C: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80078468;
    }
    // 0x8007845C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80078460: jal         0x8001DAEC
    // 0x80078464: addiu       $a1, $s0, 0x68
    ctx->r5 = ADD32(ctx->r16, 0X68);
    func_8001DAEC(rdram, ctx);
        goto after_54;
    // 0x80078464: addiu       $a1, $s0, 0x68
    ctx->r5 = ADD32(ctx->r16, 0X68);
    after_54:
L_80078468:
    // 0x80078468: lw          $a1, 0x130($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X130);
    // 0x8007846C: jal         0x8001CCCC
    // 0x80078470: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CCCC(rdram, ctx);
        goto after_55;
    // 0x80078470: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_55:
    // 0x80078474: lw          $a0, 0x4C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4C);
    // 0x80078478: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x8007847C: andi        $v1, $a0, 0x9
    ctx->r3 = ctx->r4 & 0X9;
    // 0x80078480: bne         $v1, $v0, L_800784C0
    if (ctx->r3 != ctx->r2) {
        // 0x80078484: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_800784C0;
    }
    // 0x80078484: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80078488: lwc1        $f2, 0x78($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8007848C: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80078490: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80078494: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80078498: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8007849C: lwc1        $f2, 0x7C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x800784A0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800784A4: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800784A8: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800784AC: lwc1        $f2, 0x80($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X80);
    // 0x800784B0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800784B4: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800784B8: j           L_800784F0
    // 0x800784BC: nop

        goto L_800784F0;
    // 0x800784BC: nop

L_800784C0:
    // 0x800784C0: bne         $v1, $v0, L_800784DC
    if (ctx->r3 != ctx->r2) {
        // 0x800784C4: andi        $v0, $a0, 0x1
        ctx->r2 = ctx->r4 & 0X1;
            goto L_800784DC;
    }
    // 0x800784C4: andi        $v0, $a0, 0x1
    ctx->r2 = ctx->r4 & 0X1;
    // 0x800784C8: lw          $a1, 0x78($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X78);
    // 0x800784CC: lw          $a2, 0x7C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X7C);
    // 0x800784D0: lw          $a3, 0x80($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X80);
    // 0x800784D4: j           L_800784F0
    // 0x800784D8: nop

        goto L_800784F0;
    // 0x800784D8: nop

L_800784DC:
    // 0x800784DC: beq         $v0, $zero, L_800784F8
    if (ctx->r2 == 0) {
        // 0x800784E0: nop
    
            goto L_800784F8;
    }
    // 0x800784E0: nop

    // 0x800784E4: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    // 0x800784E8: lw          $a2, 0x54($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X54);
    // 0x800784EC: lw          $a3, 0x58($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X58);
L_800784F0:
    // 0x800784F0: jal         0x8001CA90
    // 0x800784F4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA90(rdram, ctx);
        goto after_56;
    // 0x800784F4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_56:
L_800784F8:
    // 0x800784F8: lw          $v0, 0x78($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X78);
    // 0x800784FC: lw          $s0, 0xA4($s2)
    ctx->r16 = MEM_W(ctx->r18, 0XA4);
    // 0x80078500: addiu       $s1, $v0, 0x1C
    ctx->r17 = ADD32(ctx->r2, 0X1C);
    // 0x80078504: jal         0x8001CA50
    // 0x80078508: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA50(rdram, ctx);
        goto after_57;
    // 0x80078508: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_57:
    // 0x8007850C: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x80078510: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80078514: beq         $v0, $zero, L_80078548
    if (ctx->r2 == 0) {
        // 0x80078518: nop
    
            goto L_80078548;
    }
    // 0x80078518: nop

    // 0x8007851C: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80078520: lwc1        $f2, 0x58($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80078524: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80078528: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x8007852C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80078530: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80078534: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80078538: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8007853C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80078540: jal         0x8001CA90
    // 0x80078544: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA90(rdram, ctx);
        goto after_58;
    // 0x80078544: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_58:
L_80078548:
    // 0x80078548: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x8007854C: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x80078550: beq         $v0, $zero, L_8007856C
    if (ctx->r2 == 0) {
        // 0x80078554: nop
    
            goto L_8007856C;
    }
    // 0x80078554: nop

    // 0x80078558: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    // 0x8007855C: lw          $a2, 0x60($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X60);
    // 0x80078560: lw          $a3, 0x64($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X64);
    // 0x80078564: jal         0x8001CB04
    // 0x80078568: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CB04(rdram, ctx);
        goto after_59;
    // 0x80078568: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_59:
L_8007856C:
    // 0x8007856C: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x80078570: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x80078574: beq         $v0, $zero, L_80078584
    if (ctx->r2 == 0) {
        // 0x80078578: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80078584;
    }
    // 0x80078578: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8007857C: jal         0x8001DAEC
    // 0x80078580: addiu       $a1, $s0, 0x68
    ctx->r5 = ADD32(ctx->r16, 0X68);
    func_8001DAEC(rdram, ctx);
        goto after_60;
    // 0x80078580: addiu       $a1, $s0, 0x68
    ctx->r5 = ADD32(ctx->r16, 0X68);
    after_60:
L_80078584:
    // 0x80078584: lwc1        $f0, 0x140($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X140);
    // 0x80078588: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8007858C: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80078590: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80078594: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80078598: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8007859C: jal         0x8001CA90
    // 0x800785A0: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    func_8001CA90(rdram, ctx);
        goto after_61;
    // 0x800785A0: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_61:
    // 0x800785A4: lw          $a0, 0x4C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4C);
    // 0x800785A8: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x800785AC: andi        $v1, $a0, 0x9
    ctx->r3 = ctx->r4 & 0X9;
    // 0x800785B0: bne         $v1, $v0, L_800785F0
    if (ctx->r3 != ctx->r2) {
        // 0x800785B4: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_800785F0;
    }
    // 0x800785B4: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800785B8: lwc1        $f2, 0x78($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800785BC: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800785C0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800785C4: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800785C8: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800785CC: lwc1        $f2, 0x7C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x800785D0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800785D4: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800785D8: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800785DC: lwc1        $f2, 0x80($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X80);
    // 0x800785E0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800785E4: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800785E8: j           L_80078620
    // 0x800785EC: nop

        goto L_80078620;
    // 0x800785EC: nop

L_800785F0:
    // 0x800785F0: bne         $v1, $v0, L_8007860C
    if (ctx->r3 != ctx->r2) {
        // 0x800785F4: andi        $v0, $a0, 0x1
        ctx->r2 = ctx->r4 & 0X1;
            goto L_8007860C;
    }
    // 0x800785F4: andi        $v0, $a0, 0x1
    ctx->r2 = ctx->r4 & 0X1;
    // 0x800785F8: lw          $a1, 0x78($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X78);
    // 0x800785FC: lw          $a2, 0x7C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X7C);
    // 0x80078600: lw          $a3, 0x80($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X80);
    // 0x80078604: j           L_80078620
    // 0x80078608: nop

        goto L_80078620;
    // 0x80078608: nop

L_8007860C:
    // 0x8007860C: beq         $v0, $zero, L_8007862C
    if (ctx->r2 == 0) {
        // 0x80078610: addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
            goto L_8007862C;
    }
    // 0x80078610: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x80078614: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    // 0x80078618: lw          $a2, 0x54($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X54);
    // 0x8007861C: lw          $a3, 0x58($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X58);
L_80078620:
    // 0x80078620: jal         0x8001CA90
    // 0x80078624: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA90(rdram, ctx);
        goto after_62;
    // 0x80078624: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_62:
    // 0x80078628: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
L_8007862C:
    // 0x8007862C: addu        $s4, $s2, $zero
    ctx->r20 = ADD32(ctx->r18, 0);
L_80078630:
    // 0x80078630: lw          $v0, 0xD4($s4)
    ctx->r2 = MEM_W(ctx->r20, 0XD4);
    // 0x80078634: blezl       $v0, L_8007875C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80078638: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_8007875C;
    }
    goto skip_1;
    // 0x80078638: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_1:
    // 0x8007863C: lw          $v0, 0x7C($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X7C);
    // 0x80078640: lw          $s0, 0xA8($s4)
    ctx->r16 = MEM_W(ctx->r20, 0XA8);
    // 0x80078644: addiu       $s1, $v0, 0x1C
    ctx->r17 = ADD32(ctx->r2, 0X1C);
    // 0x80078648: jal         0x8001CA50
    // 0x8007864C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA50(rdram, ctx);
        goto after_63;
    // 0x8007864C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_63:
    // 0x80078650: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x80078654: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x80078658: beq         $v0, $zero, L_8007868C
    if (ctx->r2 == 0) {
        // 0x8007865C: nop
    
            goto L_8007868C;
    }
    // 0x8007865C: nop

    // 0x80078660: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x80078664: lwc1        $f2, 0x58($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80078668: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8007866C: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x80078670: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80078674: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80078678: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8007867C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80078680: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80078684: jal         0x8001CA90
    // 0x80078688: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA90(rdram, ctx);
        goto after_64;
    // 0x80078688: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_64:
L_8007868C:
    // 0x8007868C: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x80078690: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x80078694: beq         $v0, $zero, L_800786B0
    if (ctx->r2 == 0) {
        // 0x80078698: nop
    
            goto L_800786B0;
    }
    // 0x80078698: nop

    // 0x8007869C: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    // 0x800786A0: lw          $a2, 0x60($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X60);
    // 0x800786A4: lw          $a3, 0x64($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X64);
    // 0x800786A8: jal         0x8001CB04
    // 0x800786AC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CB04(rdram, ctx);
        goto after_65;
    // 0x800786AC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_65:
L_800786B0:
    // 0x800786B0: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x800786B4: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x800786B8: beq         $v0, $zero, L_800786C8
    if (ctx->r2 == 0) {
        // 0x800786BC: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_800786C8;
    }
    // 0x800786BC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800786C0: jal         0x8001DAEC
    // 0x800786C4: addiu       $a1, $s0, 0x68
    ctx->r5 = ADD32(ctx->r16, 0X68);
    func_8001DAEC(rdram, ctx);
        goto after_66;
    // 0x800786C4: addiu       $a1, $s0, 0x68
    ctx->r5 = ADD32(ctx->r16, 0X68);
    after_66:
L_800786C8:
    // 0x800786C8: lw          $a1, 0x138($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X138);
    // 0x800786CC: jal         0x8001CCCC
    // 0x800786D0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CCCC(rdram, ctx);
        goto after_67;
    // 0x800786D0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_67:
    // 0x800786D4: lw          $a0, 0x4C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4C);
    // 0x800786D8: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x800786DC: andi        $v1, $a0, 0x9
    ctx->r3 = ctx->r4 & 0X9;
    // 0x800786E0: bne         $v1, $v0, L_80078720
    if (ctx->r3 != ctx->r2) {
        // 0x800786E4: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_80078720;
    }
    // 0x800786E4: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800786E8: lwc1        $f2, 0x78($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800786EC: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800786F0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800786F4: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800786F8: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800786FC: lwc1        $f2, 0x7C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x80078700: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80078704: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80078708: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8007870C: lwc1        $f2, 0x80($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X80);
    // 0x80078710: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80078714: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x80078718: j           L_80078750
    // 0x8007871C: nop

        goto L_80078750;
    // 0x8007871C: nop

L_80078720:
    // 0x80078720: bne         $v1, $v0, L_8007873C
    if (ctx->r3 != ctx->r2) {
        // 0x80078724: andi        $v0, $a0, 0x1
        ctx->r2 = ctx->r4 & 0X1;
            goto L_8007873C;
    }
    // 0x80078724: andi        $v0, $a0, 0x1
    ctx->r2 = ctx->r4 & 0X1;
    // 0x80078728: lw          $a1, 0x78($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X78);
    // 0x8007872C: lw          $a2, 0x7C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X7C);
    // 0x80078730: lw          $a3, 0x80($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X80);
    // 0x80078734: j           L_80078750
    // 0x80078738: nop

        goto L_80078750;
    // 0x80078738: nop

L_8007873C:
    // 0x8007873C: beql        $v0, $zero, L_8007875C
    if (ctx->r2 == 0) {
        // 0x80078740: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_8007875C;
    }
    goto skip_2;
    // 0x80078740: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_2:
    // 0x80078744: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    // 0x80078748: lw          $a2, 0x54($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X54);
    // 0x8007874C: lw          $a3, 0x58($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X58);
L_80078750:
    // 0x80078750: jal         0x8001CA90
    // 0x80078754: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8001CA90(rdram, ctx);
        goto after_68;
    // 0x80078754: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_68:
    // 0x80078758: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_8007875C:
    // 0x8007875C: slti        $v0, $s3, 0x8
    ctx->r2 = SIGNED(ctx->r19) < 0X8 ? 1 : 0;
    // 0x80078760: bne         $v0, $zero, L_80078630
    if (ctx->r2 != 0) {
        // 0x80078764: addiu       $s4, $s4, 0x4
        ctx->r20 = ADD32(ctx->r20, 0X4);
            goto L_80078630;
    }
    // 0x80078764: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x80078768: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8007876C: lw          $a0, 0x30($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X30);
    // 0x80078770: lw          $a2, 0x12C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X12C);
    // 0x80078774: jal         0x80059B50
    // 0x80078778: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_80059B50(rdram, ctx);
        goto after_69;
    // 0x80078778: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_69:
    // 0x8007877C: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    // 0x80078780: lw          $a1, 0x30($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X30);
    // 0x80078784: lw          $a3, 0x128($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X128);
    // 0x80078788: jal         0x80057C8C
    // 0x8007878C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_80057C8C(rdram, ctx);
        goto after_70;
    // 0x8007878C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_70:
    // 0x80078790: beq         $v0, $zero, L_800787B0
    if (ctx->r2 == 0) {
        // 0x80078794: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_800787B0;
    }
    // 0x80078794: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80078798: lbu         $v1, 0x1DC($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X1DC);
    // 0x8007879C: beq         $v1, $v0, L_800787B0
    if (ctx->r3 == ctx->r2) {
        // 0x800787A0: addiu       $a0, $s2, 0x1DC
        ctx->r4 = ADD32(ctx->r18, 0X1DC);
            goto L_800787B0;
    }
    // 0x800787A0: addiu       $a0, $s2, 0x1DC
    ctx->r4 = ADD32(ctx->r18, 0X1DC);
    // 0x800787A4: lw          $a1, 0x30($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X30);
    // 0x800787A8: jal         0x80071928
    // 0x800787AC: addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    func_80071928(rdram, ctx);
        goto after_71;
    // 0x800787AC: addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    after_71:
L_800787B0:
    // 0x800787B0: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x800787B4: addiu       $a1, $a1, -0x2C88
    ctx->r5 = ADD32(ctx->r5, -0X2C88);
    // 0x800787B8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800787BC: addiu       $s0, $s2, 0x34
    ctx->r16 = ADD32(ctx->r18, 0X34);
    // 0x800787C0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800787C4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800787C8: lw          $a0, 0x30($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X30);
    // 0x800787CC: jal         0x80058360
    // 0x800787D0: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    func_80058360(rdram, ctx);
        goto after_72;
    // 0x800787D0: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_72:
    // 0x800787D4: lwc1        $f0, 0x140($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X140);
    // 0x800787D8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800787DC: lwc1        $f6, -0x2C10($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2C10);
    // 0x800787E0: sub.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800787E4: lwc1        $f4, 0xC8($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0XC8);
    // 0x800787E8: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800787EC: lwc1        $f0, 0x4C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X4C);
    // 0x800787F0: lwc1        $f2, 0x54($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X54);
    // 0x800787F4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800787F8: swc1        $f0, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->f0.u32l;
    // 0x800787FC: lwc1        $f0, 0x50($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X50);
    // 0x80078800: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x80078804: swc1        $f2, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f2.u32l;
    // 0x80078808: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8007880C: swc1        $f0, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f0.u32l;
    // 0x80078810: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x80078814: lwc1        $f0, 0x140($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X140);
    // 0x80078818: sub.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8007881C: lwc1        $f4, 0xCC($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0XCC);
    // 0x80078820: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80078824: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x80078828: lwc1        $f0, 0x140($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X140);
    // 0x8007882C: sub.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80078830: lwc1        $f0, 0xD0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XD0);
    // 0x80078834: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80078838: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8007883C: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x80078840: nop

    // 0x80078844: bc1f        L_80078874
    if (!c1cs) {
        // 0x80078848: swc1        $f0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
            goto L_80078874;
    }
    // 0x80078848: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x8007884C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80078850: lw          $a0, 0x64($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X64);
    // 0x80078854: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x80078858: jal         0x80059C24
    // 0x8007885C: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_80059C24(rdram, ctx);
        goto after_73;
    // 0x8007885C: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_73:
    // 0x80078860: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    // 0x80078864: lw          $a1, 0x64($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X64);
    // 0x80078868: lw          $a3, 0x128($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X128);
    // 0x8007886C: jal         0x80057C8C
    // 0x80078870: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_80057C8C(rdram, ctx);
        goto after_74;
    // 0x80078870: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_74:
L_80078874:
    // 0x80078874: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x80078878: ori         $s1, $zero, 0xFFFF
    ctx->r17 = 0 | 0XFFFF;
    // 0x8007887C: addu        $s0, $s2, $zero
    ctx->r16 = ADD32(ctx->r18, 0);
L_80078880:
    // 0x80078880: lhu         $v0, 0x104($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X104);
    // 0x80078884: beql        $v0, $s1, L_800788A0
    if (ctx->r2 == ctx->r17) {
        // 0x80078888: addiu       $s3, $s3, 0x1
        ctx->r19 = ADD32(ctx->r19, 0X1);
            goto L_800788A0;
    }
    goto skip_3;
    // 0x80078888: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    skip_3:
    // 0x8007888C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80078890: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x80078894: jal         0x8003E8DC
    // 0x80078898: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    slotDispatcherIter(rdram, ctx);
        goto after_75;
    // 0x80078898: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    after_75:
    // 0x8007889C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_800788A0:
    // 0x800788A0: slti        $v0, $s3, 0x2
    ctx->r2 = SIGNED(ctx->r19) < 0X2 ? 1 : 0;
    // 0x800788A4: bne         $v0, $zero, L_80078880
    if (ctx->r2 != 0) {
        // 0x800788A8: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_80078880;
    }
    // 0x800788A8: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800788AC: lbu         $v0, 0x1D8($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X1D8);
    // 0x800788B0: beq         $v0, $zero, L_80078DF0
    if (ctx->r2 == 0) {
        // 0x800788B4: addiu       $a0, $s2, 0x150
        ctx->r4 = ADD32(ctx->r18, 0X150);
            goto L_80078DF0;
    }
    // 0x800788B4: addiu       $a0, $s2, 0x150
    ctx->r4 = ADD32(ctx->r18, 0X150);
    // 0x800788B8: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800788BC: addiu       $a2, $a1, 0x24
    ctx->r6 = ADD32(ctx->r5, 0X24);
    // 0x800788C0: jal         0x800988E8
    // 0x800788C4: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
    func_800988E8(rdram, ctx);
        goto after_76;
    // 0x800788C4: addiu       $a3, $zero, 0x7F
    ctx->r7 = ADD32(0, 0X7F);
    after_76:
    // 0x800788C8: j           L_80078DF4
    // 0x800788CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80078DF4;
    // 0x800788CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800788D0:
    // 0x800788D0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800788D4: lbu         $v0, 0xB39($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB39);
    // 0x800788D8: bne         $v0, $zero, L_800788F4
    if (ctx->r2 != 0) {
        // 0x800788DC: addu        $s7, $s5, $zero
        ctx->r23 = ADD32(ctx->r21, 0);
            goto L_800788F4;
    }
    // 0x800788DC: addu        $s7, $s5, $zero
    ctx->r23 = ADD32(ctx->r21, 0);
    // 0x800788E0: lw          $a0, 0x6C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X6C);
    // 0x800788E4: jal         0x800F20EC
    // 0x800788E8: nop

    getNpcCurrentHealth(rdram, ctx);
        goto after_77;
    // 0x800788E8: nop

    after_77:
    // 0x800788EC: j           L_800788F8
    // 0x800788F0: slt         $v0, $zero, $v0
    ctx->r2 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
        goto L_800788F8;
    // 0x800788F0: slt         $v0, $zero, $v0
    ctx->r2 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
L_800788F4:
    // 0x800788F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800788F8:
    // 0x800788F8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800788FC: sw          $v0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r2;
    // 0x80078900: lw          $t5, 0xBC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XBC);
    // 0x80078904: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80078908: bne         $t5, $v0, L_80078D40
    if (ctx->r13 != ctx->r2) {
        // 0x8007890C: nop
    
            goto L_80078D40;
    }
    // 0x8007890C: nop

    // 0x80078910: jal         0x80076250
    // 0x80078914: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    func_80076250(rdram, ctx);
        goto after_78;
    // 0x80078914: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    after_78:
    // 0x80078918: lw          $a2, 0x8($s7)
    ctx->r6 = MEM_W(ctx->r23, 0X8);
    // 0x8007891C: beql        $a2, $zero, L_80078D08
    if (ctx->r6 == 0) {
        // 0x80078920: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80078D08;
    }
    goto skip_4;
    // 0x80078920: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    skip_4:
    // 0x80078924: lw          $s3, 0x24($a2)
    ctx->r19 = MEM_W(ctx->r6, 0X24);
    // 0x80078928: beq         $s3, $zero, L_80078D04
    if (ctx->r19 == 0) {
        // 0x8007892C: addiu       $v0, $zero, 0x63
        ctx->r2 = ADD32(0, 0X63);
            goto L_80078D04;
    }
    // 0x8007892C: addiu       $v0, $zero, 0x63
    ctx->r2 = ADD32(0, 0X63);
    // 0x80078930: lbu         $s5, 0x0($s3)
    ctx->r21 = MEM_BU(ctx->r19, 0X0);
    // 0x80078934: bnel        $s5, $v0, L_80078D08
    if (ctx->r21 != ctx->r2) {
        // 0x80078938: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80078D08;
    }
    goto skip_5;
    // 0x80078938: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    skip_5:
    // 0x8007893C: lbu         $s4, 0x1($s3)
    ctx->r20 = MEM_BU(ctx->r19, 0X1);
    // 0x80078940: addiu       $v0, $zero, 0x62
    ctx->r2 = ADD32(0, 0X62);
    // 0x80078944: bne         $s4, $v0, L_80078D08
    if (ctx->r20 != ctx->r2) {
        // 0x80078948: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80078D08;
    }
    // 0x80078948: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8007894C: lbu         $v1, 0x2($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X2);
    // 0x80078950: addiu       $v0, $zero, 0x5F
    ctx->r2 = ADD32(0, 0X5F);
    // 0x80078954: bne         $v1, $v0, L_80078D08
    if (ctx->r3 != ctx->r2) {
        // 0x80078958: nop
    
            goto L_80078D08;
    }
    // 0x80078958: nop

    // 0x8007895C: lbu         $s1, 0x7($s3)
    ctx->r17 = MEM_BU(ctx->r19, 0X7);
    // 0x80078960: addiu       $t2, $s1, -0x31
    ctx->r10 = ADD32(ctx->r17, -0X31);
    // 0x80078964: sll         $v0, $t2, 2
    ctx->r2 = S32(ctx->r10 << 2);
    // 0x80078968: addu        $s0, $s2, $v0
    ctx->r16 = ADD32(ctx->r18, ctx->r2);
    // 0x8007896C: sw          $t2, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r10;
    // 0x80078970: lw          $v0, 0xD4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD4);
    // 0x80078974: blez        $v0, L_80078D40
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80078978: addu        $a1, $s2, $zero
        ctx->r5 = ADD32(ctx->r18, 0);
            goto L_80078D40;
    }
    // 0x80078978: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8007897C: addiu       $fp, $s2, 0x24
    ctx->r30 = ADD32(ctx->r18, 0X24);
    // 0x80078980: addu        $a2, $fp, $zero
    ctx->r6 = ADD32(ctx->r30, 0);
    // 0x80078984: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80078988: lwc1        $f26, -0x2C0C($at)
    ctx->f26.u32l = MEM_W(ctx->r1, -0X2C0C);
    // 0x8007898C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80078990: lwc1        $f0, -0x2C08($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2C08);
    // 0x80078994: addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
    // 0x80078998: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8007899C: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x800789A0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800789A4: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x800789A8: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x800789AC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800789B0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800789B4: jal         0x800989D8
    // 0x800789B8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800989D8(rdram, ctx);
        goto after_79;
    // 0x800789B8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_79:
    // 0x800789BC: lhu         $v1, 0x6($s7)
    ctx->r3 = MEM_HU(ctx->r23, 0X6);
    // 0x800789C0: lw          $v0, 0xD4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XD4);
    // 0x800789C4: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800789C8: bgtz        $v0, L_80078D40
    if (SIGNED(ctx->r2) > 0) {
        // 0x800789CC: sw          $v0, 0xD4($s0)
        MEM_W(0XD4, ctx->r16) = ctx->r2;
            goto L_80078D40;
    }
    // 0x800789CC: sw          $v0, 0xD4($s0)
    MEM_W(0XD4, ctx->r16) = ctx->r2;
    // 0x800789D0: addiu       $a1, $sp, 0xB0
    ctx->r5 = ADD32(ctx->r29, 0XB0);
    // 0x800789D4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800789D8: addiu       $s0, $sp, 0x80
    ctx->r16 = ADD32(ctx->r29, 0X80);
    // 0x800789DC: sb          $s5, 0xB0($sp)
    MEM_B(0XB0, ctx->r29) = ctx->r21;
    // 0x800789E0: sb          $s4, 0xB1($sp)
    MEM_B(0XB1, ctx->r29) = ctx->r20;
    // 0x800789E4: sb          $s1, 0xB2($sp)
    MEM_B(0XB2, ctx->r29) = ctx->r17;
    // 0x800789E8: sb          $zero, 0xB3($sp)
    MEM_B(0XB3, ctx->r29) = 0;
    // 0x800789EC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800789F0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800789F4: lw          $a0, 0x30($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X30);
    // 0x800789F8: jal         0x80058360
    // 0x800789FC: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    func_80058360(rdram, ctx);
        goto after_80;
    // 0x800789FC: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_80:
    // 0x80078A00: lwc1        $f0, 0x12C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X12C);
    // 0x80078A04: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80078A08: lwc1        $f30, -0x2C04($at)
    ctx->f30.u32l = MEM_W(ctx->r1, -0X2C04);
    // 0x80078A0C: mul.s       $f0, $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f30.fl);
    // 0x80078A10: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80078A14: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80078A18: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80078A1C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80078A20: lwc1        $f2, 0x12C($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X12C);
    // 0x80078A24: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80078A28: lwc1        $f0, -0x2C00($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2C00);
    // 0x80078A2C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80078A30: lwc1        $f20, -0x2BFC($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X2BFC);
    // 0x80078A34: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80078A38: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80078A3C: lwc1        $f22, -0x2BF8($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X2BF8);
    // 0x80078A40: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // 0x80078A44: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80078A48: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x80078A4C: jal         0x80072684
    // 0x80078A50: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    func_80072684(rdram, ctx);
        goto after_81;
    // 0x80078A50: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    after_81:
    // 0x80078A54: lwc1        $f2, 0x12C($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X12C);
    // 0x80078A58: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80078A5C: lwc1        $f0, -0x2BF4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2BF4);
    // 0x80078A60: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80078A64: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80078A68: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80078A6C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80078A70: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // 0x80078A74: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x80078A78: lwc1        $f0, 0x12C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X12C);
    // 0x80078A7C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80078A80: lwc1        $f24, -0x2BF0($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X2BF0);
    // 0x80078A84: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80078A88: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80078A8C: swc1        $f24, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f24.u32l;
    // 0x80078A90: jal         0x80072684
    // 0x80078A94: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_80072684(rdram, ctx);
        goto after_82;
    // 0x80078A94: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_82:
    // 0x80078A98: lwc1        $f0, 0x12C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X12C);
    // 0x80078A9C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80078AA0: lwc1        $f28, -0x2BEC($at)
    ctx->f28.u32l = MEM_W(ctx->r1, -0X2BEC);
    // 0x80078AA4: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x80078AA8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80078AAC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80078AB0: lwc1        $f2, -0x2BE8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2BE8);
    // 0x80078AB4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80078AB8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80078ABC: lwc1        $f0, 0x12C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X12C);
    // 0x80078AC0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80078AC4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80078AC8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80078ACC: lwc1        $f2, -0x2BE4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2BE4);
    // 0x80078AD0: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // 0x80078AD4: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x80078AD8: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x80078ADC: jal         0x80072684
    // 0x80078AE0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_80072684(rdram, ctx);
        goto after_83;
    // 0x80078AE0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_83:
    // 0x80078AE4: lwc1        $f2, 0x12C($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X12C);
    // 0x80078AE8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80078AEC: lwc1        $f0, -0x2BE0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2BE0);
    // 0x80078AF0: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80078AF4: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80078AF8: jal         0x800612A4
    // 0x80078AFC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800612A4(rdram, ctx);
        goto after_84;
    // 0x80078AFC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_84:
    // 0x80078B00: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80078B04: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80078B08: addu        $a2, $fp, $zero
    ctx->r6 = ADD32(ctx->r30, 0);
    // 0x80078B0C: mfc1        $a3, $f26
    ctx->r7 = (int32_t)ctx->f26.u32l;
    // 0x80078B10: addiu       $v0, $zero, 0x23
    ctx->r2 = ADD32(0, 0X23);
    // 0x80078B14: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80078B18: addiu       $v0, $zero, 0x7D
    ctx->r2 = ADD32(0, 0X7D);
    // 0x80078B1C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80078B20: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    // 0x80078B24: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    // 0x80078B28: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80078B2C: jal         0x800989D8
    // 0x80078B30: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    func_800989D8(rdram, ctx);
        goto after_85;
    // 0x80078B30: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_85:
    // 0x80078B34: lw          $t3, 0xB8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB8);
    // 0x80078B38: sll         $v0, $t3, 1
    ctx->r2 = S32(ctx->r11 << 1);
    // 0x80078B3C: addu        $s0, $s2, $v0
    ctx->r16 = ADD32(ctx->r18, ctx->r2);
    // 0x80078B40: lhu         $v0, 0xF4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0XF4);
    // 0x80078B44: ori         $s4, $zero, 0xFFFF
    ctx->r20 = 0 | 0XFFFF;
    // 0x80078B48: beq         $v0, $s4, L_80078B5C
    if (ctx->r2 == ctx->r20) {
        // 0x80078B4C: addiu       $s1, $sp, 0x48
        ctx->r17 = ADD32(ctx->r29, 0X48);
            goto L_80078B5C;
    }
    // 0x80078B4C: addiu       $s1, $sp, 0x48
    ctx->r17 = ADD32(ctx->r29, 0X48);
    // 0x80078B50: jal         0x8003ED74
    // 0x80078B54: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_8003ED74(rdram, ctx);
        goto after_86;
    // 0x80078B54: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_86:
    // 0x80078B58: addiu       $s1, $sp, 0x48
    ctx->r17 = ADD32(ctx->r29, 0X48);
L_80078B5C:
    // 0x80078B5C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80078B60: jal         0x80079A94
    // 0x80078B64: sh          $s4, 0xF4($s0)
    MEM_H(0XF4, ctx->r16) = ctx->r20;
    func_80079A94(rdram, ctx);
        goto after_87;
    // 0x80078B64: sh          $s4, 0xF4($s0)
    MEM_H(0XF4, ctx->r16) = ctx->r20;
    after_87:
    // 0x80078B68: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80078B6C: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // 0x80078B70: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x80078B74: jal         0x80079BC8
    // 0x80078B78: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    func_80079BC8(rdram, ctx);
        goto after_88;
    // 0x80078B78: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    after_88:
    // 0x80078B7C: lhu         $v0, 0x126($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X126);
    // 0x80078B80: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
    // 0x80078B84: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80078B88: sh          $v0, 0x126($s2)
    MEM_H(0X126, ctx->r18) = ctx->r2;
    // 0x80078B8C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80078B90: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80078B94: bne         $v0, $v1, L_80078D40
    if (ctx->r2 != ctx->r3) {
        // 0x80078B98: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_80078D40;
    }
    // 0x80078B98: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80078B9C: lbu         $t4, 0xBF($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0XBF);
    // 0x80078BA0: jal         0x80079A94
    // 0x80078BA4: sb          $t4, 0x125($s2)
    MEM_B(0X125, ctx->r18) = ctx->r12;
    func_80079A94(rdram, ctx);
        goto after_89;
    // 0x80078BA4: sb          $t4, 0x125($s2)
    MEM_B(0X125, ctx->r18) = ctx->r12;
    after_89:
    // 0x80078BA8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80078BAC: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // 0x80078BB0: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80078BB4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80078BB8: lwc1        $f0, -0x2BDC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2BDC);
    // 0x80078BBC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80078BC0: lwc1        $f2, -0x2BD8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2BD8);
    // 0x80078BC4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80078BC8: lwc1        $f4, -0x2BD4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2BD4);
    // 0x80078BCC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80078BD0: lwc1        $f6, -0x2BD0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2BD0);
    // 0x80078BD4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80078BD8: lwc1        $f8, -0x2BCC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X2BCC);
    // 0x80078BDC: addiu       $a2, $a2, -0x2CAC
    ctx->r6 = ADD32(ctx->r6, -0X2CAC);
    // 0x80078BE0: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    // 0x80078BE4: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
    // 0x80078BE8: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x80078BEC: swc1        $f24, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f24.u32l;
    // 0x80078BF0: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x80078BF4: swc1        $f2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f2.u32l;
    // 0x80078BF8: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    // 0x80078BFC: swc1        $f6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f6.u32l;
    // 0x80078C00: jal         0x80079BC8
    // 0x80078C04: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    func_80079BC8(rdram, ctx);
        goto after_90;
    // 0x80078C04: swc1        $f8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f8.u32l;
    after_90:
    // 0x80078C08: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80078C0C: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // 0x80078C10: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80078C14: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80078C18: lwc1        $f0, -0x2BC8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2BC8);
    // 0x80078C1C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80078C20: lwc1        $f2, -0x2BC4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2BC4);
    // 0x80078C24: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80078C28: lwc1        $f4, -0x2BC0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2BC0);
    // 0x80078C2C: addiu       $a2, $a2, -0x2CB4
    ctx->r6 = ADD32(ctx->r6, -0X2CB4);
    // 0x80078C30: sh          $v0, 0x104($s2)
    MEM_H(0X104, ctx->r18) = ctx->r2;
    // 0x80078C34: swc1        $f28, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f28.u32l;
    // 0x80078C38: swc1        $f30, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f30.u32l;
    // 0x80078C3C: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x80078C40: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x80078C44: swc1        $f2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f2.u32l;
    // 0x80078C48: jal         0x80079BC8
    // 0x80078C4C: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
    func_80079BC8(rdram, ctx);
        goto after_91;
    // 0x80078C4C: swc1        $f4, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f4.u32l;
    after_91:
    // 0x80078C50: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80078C54: lbu         $v1, 0xB39($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0XB39);
    // 0x80078C58: bne         $v1, $zero, L_80078CE0
    if (ctx->r3 != 0) {
        // 0x80078C5C: sh          $v0, 0x106($s2)
        MEM_H(0X106, ctx->r18) = ctx->r2;
            goto L_80078CE0;
    }
    // 0x80078C5C: sh          $v0, 0x106($s2)
    MEM_H(0X106, ctx->r18) = ctx->r2;
    // 0x80078C60: lhu         $a0, 0x146($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X146);
    // 0x80078C64: jal         0x8003E7D0
    // 0x80078C68: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    func_8003E7D0(rdram, ctx);
        goto after_92;
    // 0x80078C68: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    after_92:
    // 0x80078C6C: lhu         $a0, 0x148($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X148);
    // 0x80078C70: jal         0x8003E7D0
    // 0x80078C74: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    func_8003E7D0(rdram, ctx);
        goto after_93;
    // 0x80078C74: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    after_93:
    // 0x80078C78: lhu         $v0, 0x14A($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X14A);
    // 0x80078C7C: beql        $v0, $s4, L_80078C94
    if (ctx->r2 == ctx->r20) {
        // 0x80078C80: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_80078C94;
    }
    goto skip_6;
    // 0x80078C80: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    skip_6:
    // 0x80078C84: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x80078C88: jal         0x8003E7D0
    // 0x80078C8C: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    func_8003E7D0(rdram, ctx);
        goto after_94;
    // 0x80078C8C: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    after_94:
    // 0x80078C90: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
L_80078C94:
    // 0x80078C94: lhu         $a0, -0x6A8C($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A8C);
    // 0x80078C98: jal         0x8003E684
    // 0x80078C9C: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    func_8003E684(rdram, ctx);
        goto after_95;
    // 0x80078C9C: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    after_95:
    // 0x80078CA0: lw          $v1, 0x68($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X68);
    // 0x80078CA4: lw          $v0, 0x80($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X80);
    // 0x80078CA8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80078CAC: lw          $v0, 0x68($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X68);
    // 0x80078CB0: lw          $v0, 0x84($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X84);
    // 0x80078CB4: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x80078CB8: lw          $a0, 0x78($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X78);
    // 0x80078CBC: lw          $a1, 0x7C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X7C);
    // 0x80078CC0: lw          $a2, 0x70($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X70);
    // 0x80078CC4: lw          $a3, 0x74($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X74);
    // 0x80078CC8: jal         0x80065914
    // 0x80078CCC: nop

    datItemSetObjectiveBooleanCount(rdram, ctx);
        goto after_96;
    // 0x80078CCC: nop

    after_96:
    // 0x80078CD0: jal         0x800F3260
    // 0x80078CD4: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    func_800F3260(rdram, ctx);
        goto after_97;
    // 0x80078CD4: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    after_97:
    // 0x80078CD8: jal         0x800F2AA4
    // 0x80078CDC: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    func_800F2AA4(rdram, ctx);
        goto after_98;
    // 0x80078CDC: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    after_98:
L_80078CE0:
    // 0x80078CE0: lbu         $v1, 0x1D8($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X1D8);
    // 0x80078CE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80078CE8: bne         $v1, $v0, L_80078D40
    if (ctx->r3 != ctx->r2) {
        // 0x80078CEC: nop
    
            goto L_80078D40;
    }
    // 0x80078CEC: nop

    // 0x80078CF0: sb          $zero, 0x1D8($s2)
    MEM_B(0X1D8, ctx->r18) = 0;
    // 0x80078CF4: jal         0x80098DE0
    // 0x80078CF8: addiu       $a0, $s2, 0x150
    ctx->r4 = ADD32(ctx->r18, 0X150);
    func_80098DE0(rdram, ctx);
        goto after_99;
    // 0x80078CF8: addiu       $a0, $s2, 0x150
    ctx->r4 = ADD32(ctx->r18, 0X150);
    after_99:
    // 0x80078CFC: j           L_80078D40
    // 0x80078D00: nop

        goto L_80078D40;
    // 0x80078D00: nop

L_80078D04:
    // 0x80078D04: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_80078D08:
    // 0x80078D08: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80078D0C: addiu       $a2, $a1, 0x24
    ctx->r6 = ADD32(ctx->r5, 0X24);
    // 0x80078D10: lui         $a3, 0x4190
    ctx->r7 = S32(0X4190 << 16);
    // 0x80078D14: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80078D18: lwc1        $f0, -0x2BBC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2BBC);
    // 0x80078D1C: addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
    // 0x80078D20: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80078D24: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x80078D28: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80078D2C: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x80078D30: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80078D34: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80078D38: jal         0x800989D8
    // 0x80078D3C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800989D8(rdram, ctx);
        goto after_100;
    // 0x80078D3C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_100:
L_80078D40:
    // 0x80078D40: lhu         $v1, 0x0($s7)
    ctx->r3 = MEM_HU(ctx->r23, 0X0);
    // 0x80078D44: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x80078D48: beq         $v1, $v0, L_80078DF4
    if (ctx->r3 == ctx->r2) {
        // 0x80078D4C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80078DF4;
    }
    // 0x80078D4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80078D50: jal         0x8003ED74
    // 0x80078D54: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    func_8003ED74(rdram, ctx);
        goto after_101;
    // 0x80078D54: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    after_101:
    // 0x80078D58: j           L_80078DF4
    // 0x80078D5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80078DF4;
    // 0x80078D5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80078D60:
    // 0x80078D60: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x80078D64: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80078D68: lhu         $a1, 0x0($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X0);
    // 0x80078D6C: addu        $t1, $s2, $zero
    ctx->r9 = ADD32(ctx->r18, 0);
    // 0x80078D70: addu        $v0, $t1, $zero
    ctx->r2 = ADD32(ctx->r9, 0);
L_80078D74:
    // 0x80078D74: lhu         $t0, 0x104($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X104);
    // 0x80078D78: beq         $t0, $a1, L_80078D9C
    if (ctx->r8 == ctx->r5) {
        // 0x80078D7C: sll         $v1, $a3, 1
        ctx->r3 = S32(ctx->r7 << 1);
            goto L_80078D9C;
    }
    // 0x80078D7C: sll         $v1, $a3, 1
    ctx->r3 = S32(ctx->r7 << 1);
    // 0x80078D80: addiu       $t1, $v0, 0x2
    ctx->r9 = ADD32(ctx->r2, 0X2);
    // 0x80078D84: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80078D88: slti        $v0, $a3, 0x2
    ctx->r2 = SIGNED(ctx->r7) < 0X2 ? 1 : 0;
    // 0x80078D8C: bne         $v0, $zero, L_80078D74
    if (ctx->r2 != 0) {
        // 0x80078D90: addu        $v0, $t1, $zero
        ctx->r2 = ADD32(ctx->r9, 0);
            goto L_80078D74;
    }
    // 0x80078D90: addu        $v0, $t1, $zero
    ctx->r2 = ADD32(ctx->r9, 0);
    // 0x80078D94: j           L_80078DF4
    // 0x80078D98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80078DF4;
    // 0x80078D98: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80078D9C:
    // 0x80078D9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80078DA0: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x80078DA4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80078DA8: addu        $v1, $s2, $v1
    ctx->r3 = ADD32(ctx->r18, ctx->r3);
    // 0x80078DAC: sh          $t0, 0x108($t1)
    MEM_H(0X108, ctx->r9) = ctx->r8;
    // 0x80078DB0: lw          $t5, 0x4($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4);
    // 0x80078DB4: lw          $t2, 0x8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X8);
    // 0x80078DB8: lw          $t3, 0xC($a0)
    ctx->r11 = MEM_W(ctx->r4, 0XC);
    // 0x80078DBC: sw          $t5, 0x10C($v1)
    MEM_W(0X10C, ctx->r3) = ctx->r13;
    // 0x80078DC0: sw          $t2, 0x110($v1)
    MEM_W(0X110, ctx->r3) = ctx->r10;
    // 0x80078DC4: sw          $t3, 0x114($v1)
    MEM_W(0X114, ctx->r3) = ctx->r11;
    // 0x80078DC8: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // 0x80078DCC: j           L_80078DF4
    // 0x80078DD0: sh          $v1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r3;
        goto L_80078DF4;
    // 0x80078DD0: sh          $v1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r3;
L_80078DD4:
    // 0x80078DD4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80078DD8: lbu         $v0, 0xB39($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB39);
    // 0x80078DDC: bne         $v0, $zero, L_80078DF4
    if (ctx->r2 != 0) {
        // 0x80078DE0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80078DF4;
    }
    // 0x80078DE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80078DE4: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // 0x80078DE8: jal         0x800EFD80
    // 0x80078DEC: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    func_800EFD80(rdram, ctx);
        goto after_102;
    // 0x80078DEC: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_102:
L_80078DF0:
    // 0x80078DF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80078DF4:
    // 0x80078DF4: lw          $ra, 0xE4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XE4);
    // 0x80078DF8: lw          $fp, 0xE0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0XE0);
    // 0x80078DFC: lw          $s7, 0xDC($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XDC);
    // 0x80078E00: lw          $s6, 0xD8($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XD8);
    // 0x80078E04: lw          $s5, 0xD4($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XD4);
    // 0x80078E08: lw          $s4, 0xD0($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XD0);
    // 0x80078E0C: lw          $s3, 0xCC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XCC);
    // 0x80078E10: lw          $s2, 0xC8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC8);
    // 0x80078E14: lw          $s1, 0xC4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC4);
    // 0x80078E18: lw          $s0, 0xC0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XC0);
    // 0x80078E1C: ldc1        $f30, 0x110($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X110);
    // 0x80078E20: ldc1        $f28, 0x108($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X108);
    // 0x80078E24: ldc1        $f26, 0x100($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X100);
    // 0x80078E28: ldc1        $f24, 0xF8($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0XF8);
    // 0x80078E2C: ldc1        $f22, 0xF0($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0XF0);
    // 0x80078E30: ldc1        $f20, 0xE8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XE8);
    // 0x80078E34: jr          $ra
    // 0x80078E38: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
    return;
    // 0x80078E38: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
;}
RECOMP_FUNC void func_80078E3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078E3C: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x80078E40: sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // 0x80078E44: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x80078E48: sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // 0x80078E4C: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x80078E50: sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // 0x80078E54: addiu       $s2, $sp, 0x30
    ctx->r18 = ADD32(ctx->r29, 0X30);
    // 0x80078E58: sw          $s5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r21;
    // 0x80078E5C: addu        $s5, $a1, $zero
    ctx->r21 = ADD32(ctx->r5, 0);
    // 0x80078E60: andi        $v1, $s5, 0xFF
    ctx->r3 = ctx->r21 & 0XFF;
    // 0x80078E64: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80078E68: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80078E6C: sdc1        $f26, 0x90($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X90, ctx->r29);
    // 0x80078E70: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80078E74: lwc1        $f26, -0x2BA8($at)
    ctx->f26.u32l = MEM_W(ctx->r1, -0X2BA8);
    // 0x80078E78: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80078E7C: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x80078E80: addu        $s0, $v0, $s4
    ctx->r16 = ADD32(ctx->r2, ctx->r20);
    // 0x80078E84: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x80078E88: addiu       $s1, $s0, 0x10C
    ctx->r17 = ADD32(ctx->r16, 0X10C);
    // 0x80078E8C: sdc1        $f24, 0x88($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X88, ctx->r29);
    // 0x80078E90: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80078E94: lwc1        $f24, -0x2BA4($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X2BA4);
    // 0x80078E98: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80078E9C: sw          $ra, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r31;
    // 0x80078EA0: sdc1        $f30, 0xA0($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0XA0, ctx->r29);
    // 0x80078EA4: sdc1        $f28, 0x98($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X98, ctx->r29);
    // 0x80078EA8: sdc1        $f22, 0x80($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X80, ctx->r29);
    // 0x80078EAC: sdc1        $f20, 0x78($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X78, ctx->r29);
    // 0x80078EB0: addiu       $t3, $v0, -0x2BB8
    ctx->r11 = ADD32(ctx->r2, -0X2BB8);
    // 0x80078EB4: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x80078EB8: lw          $t1, 0x4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X4);
    // 0x80078EBC: lw          $t2, 0x8($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X8);
    // 0x80078EC0: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x80078EC4: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x80078EC8: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x80078ECC: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80078ED0: addiu       $t3, $v0, -0x2BAC
    ctx->r11 = ADD32(ctx->r2, -0X2BAC);
    // 0x80078ED4: lwl         $t0, 0x0($t3)
    ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r11, 0X0);
    // 0x80078ED8: lwr         $t0, 0x3($t3)
    ctx->r8 = do_lwr(rdram, ctx->r8, ctx->r11, 0X3);
    // 0x80078EDC: swl         $t0, 0x50($sp)
    do_swl(rdram, 0X50, ctx->r29, ctx->r8);
    // 0x80078EE0: swr         $t0, 0x53($sp)
    do_swr(rdram, 0X53, ctx->r29, ctx->r8);
    // 0x80078EE4: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
L_80078EE8:
    // 0x80078EE8: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80078EEC: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x80078EF0: addiu       $a3, $zero, 0x78
    ctx->r7 = ADD32(0, 0X78);
    // 0x80078EF4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80078EF8: jal         0x8007202C
    // 0x80078EFC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8007202C(rdram, ctx);
        goto after_0;
    // 0x80078EFC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_0:
    // 0x80078F00: lwc1        $f0, 0x10C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10C);
    // 0x80078F04: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80078F08: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80078F0C: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80078F10: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80078F14: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80078F18: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80078F1C: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80078F20: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80078F24: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80078F28: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80078F2C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80078F30: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x80078F34: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x80078F38: jal         0x80072300
    // 0x80078F3C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    func_80072300(rdram, ctx);
        goto after_1;
    // 0x80078F3C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80078F40: jal         0x80003430
    // 0x80078F44: nop

    rand_recomp(rdram, ctx);
        goto after_2;
    // 0x80078F44: nop

    after_2:
    // 0x80078F48: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80078F4C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80078F50: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80078F54: sub.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x80078F58: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80078F5C: lwc1        $f2, -0x2BA0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2BA0);
    // 0x80078F60: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80078F64: abs.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = fabsf(ctx->f0.fl);
    // 0x80078F68: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80078F6C: lwc1        $f30, -0x2B9C($at)
    ctx->f30.u32l = MEM_W(ctx->r1, -0X2B9C);
    // 0x80078F70: jal         0x80003430
    // 0x80078F74: add.s       $f22, $f22, $f30
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f30.fl;
    rand_recomp(rdram, ctx);
        goto after_3;
    // 0x80078F74: add.s       $f22, $f22, $f30
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f30.fl;
    after_3:
    // 0x80078F78: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80078F7C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80078F80: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80078F84: sub.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x80078F88: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80078F8C: lwc1        $f2, -0x2B98($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2B98);
    // 0x80078F90: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80078F94: abs.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = fabsf(ctx->f0.fl);
    // 0x80078F98: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80078F9C: lwc1        $f28, -0x2B94($at)
    ctx->f28.u32l = MEM_W(ctx->r1, -0X2B94);
    // 0x80078FA0: add.s       $f20, $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f28.fl;
    // 0x80078FA4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80078FA8: lwc1        $f0, -0x2B90($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2B90);
    // 0x80078FAC: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80078FB0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80078FB4: lwc1        $f0, -0x2B8C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2B8C);
    // 0x80078FB8: jal         0x80003430
    // 0x80078FBC: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
    rand_recomp(rdram, ctx);
        goto after_4;
    // 0x80078FBC: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
    after_4:
    // 0x80078FC0: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80078FC4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80078FC8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80078FCC: sub.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x80078FD0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80078FD4: lwc1        $f2, -0x2B88($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2B88);
    // 0x80078FD8: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80078FDC: abs.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = fabsf(ctx->f0.fl);
    // 0x80078FE0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80078FE4: lwc1        $f0, -0x2B84($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2B84);
    // 0x80078FE8: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80078FEC: mul.s       $f2, $f2, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f26.fl);
    // 0x80078FF0: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80078FF4: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80078FF8: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80078FFC: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80079000: jal         0x80072384
    // 0x80079004: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    func_80072384(rdram, ctx);
        goto after_5;
    // 0x80079004: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_5:
    // 0x80079008: andi        $v0, $s3, 0x1
    ctx->r2 = ctx->r19 & 0X1;
    // 0x8007900C: beq         $v0, $zero, L_800790A4
    if (ctx->r2 == 0) {
        // 0x80079010: addiu       $a0, $sp, 0x20
        ctx->r4 = ADD32(ctx->r29, 0X20);
            goto L_800790A4;
    }
    // 0x80079010: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x80079014: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x80079018: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
    // 0x8007901C: addiu       $a3, $zero, 0x78
    ctx->r7 = ADD32(0, 0X78);
    // 0x80079020: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80079024: jal         0x8007202C
    // 0x80079028: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8007202C(rdram, ctx);
        goto after_6;
    // 0x80079028: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_6:
    // 0x8007902C: lui         $a1, 0x3E80
    ctx->r5 = S32(0X3E80 << 16);
    // 0x80079030: mfc1        $a2, $f26
    ctx->r6 = (int32_t)ctx->f26.u32l;
    // 0x80079034: jal         0x80072300
    // 0x80079038: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    func_80072300(rdram, ctx);
        goto after_7;
    // 0x80079038: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_7:
    // 0x8007903C: lwc1        $f0, 0x10C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10C);
    // 0x80079040: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80079044: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80079048: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8007904C: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80079050: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80079054: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80079058: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007905C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80079060: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x80079064: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80079068: jal         0x80003430
    // 0x8007906C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    rand_recomp(rdram, ctx);
        goto after_8;
    // 0x8007906C: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x80079070: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x80079074: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x80079078: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8007907C: sub.s       $f2, $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f24.fl;
    // 0x80079080: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80079084: lwc1        $f0, -0x2B80($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2B80);
    // 0x80079088: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8007908C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80079090: lwc1        $f0, -0x2B7C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2B7C);
    // 0x80079094: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80079098: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8007909C: jal         0x800612A4
    // 0x800790A0: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    func_800612A4(rdram, ctx);
        goto after_9;
    // 0x800790A0: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_9:
L_800790A4:
    // 0x800790A4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800790A8: andi        $v0, $s3, 0xFF
    ctx->r2 = ctx->r19 & 0XFF;
    // 0x800790AC: sltiu       $v0, $v0, 0xC
    ctx->r2 = ctx->r2 < 0XC ? 1 : 0;
    // 0x800790B0: bne         $v0, $zero, L_80078EE8
    if (ctx->r2 != 0) {
        // 0x800790B4: addiu       $a0, $sp, 0x20
        ctx->r4 = ADD32(ctx->r29, 0X20);
            goto L_80078EE8;
    }
    // 0x800790B4: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x800790B8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800790BC: andi        $s0, $s5, 0xFF
    ctx->r16 = ctx->r21 & 0XFF;
    // 0x800790C0: sll         $s3, $s0, 1
    ctx->r19 = S32(ctx->r16 << 1);
    // 0x800790C4: addu        $s0, $s3, $s0
    ctx->r16 = ADD32(ctx->r19, ctx->r16);
    // 0x800790C8: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    // 0x800790CC: addiu       $s0, $s0, 0x10C
    ctx->r16 = ADD32(ctx->r16, 0X10C);
    // 0x800790D0: addu        $s0, $s4, $s0
    ctx->r16 = ADD32(ctx->r20, ctx->r16);
    // 0x800790D4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800790D8: addiu       $s1, $sp, 0x40
    ctx->r17 = ADD32(ctx->r29, 0X40);
    // 0x800790DC: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x800790E0: addiu       $s2, $sp, 0x50
    ctx->r18 = ADD32(ctx->r29, 0X50);
    // 0x800790E4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800790E8: lwc1        $f20, -0x2B78($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X2B78);
    // 0x800790EC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800790F0: lwc1        $f0, -0x2B74($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2B74);
    // 0x800790F4: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // 0x800790F8: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x800790FC: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80079100: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x80079104: jal         0x80072684
    // 0x80079108: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    func_80072684(rdram, ctx);
        goto after_10;
    // 0x80079108: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    after_10:
    // 0x8007910C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80079110: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80079114: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x80079118: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007911C: lwc1        $f0, -0x2B70($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2B70);
    // 0x80079120: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // 0x80079124: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80079128: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x8007912C: swc1        $f28, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f28.u32l;
    // 0x80079130: jal         0x80072684
    // 0x80079134: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_80072684(rdram, ctx);
        goto after_11;
    // 0x80079134: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_11:
    // 0x80079138: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8007913C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80079140: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x80079144: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80079148: lwc1        $f0, -0x2B6C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2B6C);
    // 0x8007914C: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // 0x80079150: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80079154: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x80079158: swc1        $f26, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f26.u32l;
    // 0x8007915C: jal         0x80072684
    // 0x80079160: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_80072684(rdram, ctx);
        goto after_12;
    // 0x80079160: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_12:
    // 0x80079164: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80079168: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8007916C: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x80079170: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80079174: lwc1        $f0, -0x2B68($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2B68);
    // 0x80079178: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007917C: lwc1        $f2, -0x2B64($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2B64);
    // 0x80079180: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    // 0x80079184: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x80079188: swc1        $f30, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f30.u32l;
    // 0x8007918C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80079190: jal         0x80072684
    // 0x80079194: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    func_80072684(rdram, ctx);
        goto after_13;
    // 0x80079194: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    after_13:
    // 0x80079198: addu        $s3, $s4, $s3
    ctx->r19 = ADD32(ctx->r20, ctx->r19);
    // 0x8007919C: lhu         $a0, 0x108($s3)
    ctx->r4 = MEM_HU(ctx->r19, 0X108);
    // 0x800791A0: jal         0x8003ED74
    // 0x800791A4: nop

    func_8003ED74(rdram, ctx);
        goto after_14;
    // 0x800791A4: nop

    after_14:
    // 0x800791A8: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800791AC: sh          $v0, 0x108($s3)
    MEM_H(0X108, ctx->r19) = ctx->r2;
    // 0x800791B0: sh          $v0, 0x104($s3)
    MEM_H(0X104, ctx->r19) = ctx->r2;
    // 0x800791B4: lbu         $v0, 0x124($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X124);
    // 0x800791B8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800791BC: sb          $v0, 0x124($s4)
    MEM_B(0X124, ctx->r20) = ctx->r2;
    // 0x800791C0: lw          $ra, 0x70($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X70);
    // 0x800791C4: lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X6C);
    // 0x800791C8: lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X68);
    // 0x800791CC: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x800791D0: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x800791D4: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x800791D8: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x800791DC: ldc1        $f30, 0xA0($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0XA0);
    // 0x800791E0: ldc1        $f28, 0x98($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X98);
    // 0x800791E4: ldc1        $f26, 0x90($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X90);
    // 0x800791E8: ldc1        $f24, 0x88($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X88);
    // 0x800791EC: ldc1        $f22, 0x80($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X80);
    // 0x800791F0: ldc1        $f20, 0x78($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X78);
    // 0x800791F4: jr          $ra
    // 0x800791F8: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x800791F8: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_800791FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800791FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80079200: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80079204: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80079208: lw          $s0, 0x4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X4);
    // 0x8007920C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80079210: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80079214: sb          $zero, 0x125($s0)
    MEM_B(0X125, ctx->r16) = 0;
    // 0x80079218: lw          $v0, 0x7CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7CE4);
    // 0x8007921C: addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
    // 0x80079220: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
L_80079224:
    // 0x80079224: lw          $v0, 0x68($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X68);
    // 0x80079228: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x8007922C: lw          $v0, 0x6C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6C);
    // 0x80079230: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80079234: sw          $v0, 0xD4($v1)
    MEM_W(0XD4, ctx->r3) = ctx->r2;
    // 0x80079238: slti        $v0, $a0, 0x8
    ctx->r2 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x8007923C: bne         $v0, $zero, L_80079224
    if (ctx->r2 != 0) {
        // 0x80079240: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80079224;
    }
    // 0x80079240: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80079244: lw          $a2, 0x68($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X68);
    // 0x80079248: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x8007924C: jal         0x800F2070
    // 0x80079250: addiu       $a1, $a2, 0x6C
    ctx->r5 = ADD32(ctx->r6, 0X6C);
    setNpcHealth(rdram, ctx);
        goto after_0;
    // 0x80079250: addiu       $a1, $a2, 0x6C
    ctx->r5 = ADD32(ctx->r6, 0X6C);
    after_0:
    // 0x80079254: lw          $v0, 0x68($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X68);
    // 0x80079258: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x8007925C: lw          $a1, 0x8C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8C);
    // 0x80079260: jal         0x800F2830
    // 0x80079264: nop

    func_800F2830(rdram, ctx);
        goto after_1;
    // 0x80079264: nop

    after_1:
    // 0x80079268: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007926C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80079270: jr          $ra
    // 0x80079274: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80079274: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void fake_func_80079278(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80079280(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079280: addiu       $sp, $sp, -0xF0
    ctx->r29 = ADD32(ctx->r29, -0XF0);
    // 0x80079284: sw          $s7, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r23;
    // 0x80079288: addu        $s7, $a0, $zero
    ctx->r23 = ADD32(ctx->r4, 0);
    // 0x8007928C: sw          $s5, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r21;
    // 0x80079290: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x80079294: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80079298: sw          $ra, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r31;
    // 0x8007929C: sw          $s6, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r22;
    // 0x800792A0: sw          $s4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r20;
    // 0x800792A4: sw          $s3, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r19;
    // 0x800792A8: sw          $s2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r18;
    // 0x800792AC: sw          $s1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r17;
    // 0x800792B0: sw          $s0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r16;
    // 0x800792B4: sdc1        $f22, 0xE8($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0XE8, ctx->r29);
    // 0x800792B8: sdc1        $f20, 0xE0($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XE0, ctx->r29);
    // 0x800792BC: lw          $s2, 0x4($s7)
    ctx->r18 = MEM_W(ctx->r23, 0X4);
    // 0x800792C0: beq         $a1, $v0, L_8007952C
    if (ctx->r5 == ctx->r2) {
        // 0x800792C4: addu        $s5, $a2, $zero
        ctx->r21 = ADD32(ctx->r6, 0);
            goto L_8007952C;
    }
    // 0x800792C4: addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // 0x800792C8: slti        $v0, $a1, 0x3
    ctx->r2 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
    // 0x800792CC: beq         $v0, $zero, L_800792E4
    if (ctx->r2 == 0) {
        // 0x800792D0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800792E4;
    }
    // 0x800792D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800792D4: beq         $a1, $v0, L_80079300
    if (ctx->r5 == ctx->r2) {
        // 0x800792D8: nop
    
            goto L_80079300;
    }
    // 0x800792D8: nop

    // 0x800792DC: j           L_80079988
    // 0x800792E0: nop

        goto L_80079988;
    // 0x800792E0: nop

L_800792E4:
    // 0x800792E4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800792E8: beq         $a1, $v0, L_80079540
    if (ctx->r5 == ctx->r2) {
        // 0x800792EC: addiu       $v0, $zero, 0xE
        ctx->r2 = ADD32(0, 0XE);
            goto L_80079540;
    }
    // 0x800792EC: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // 0x800792F0: beq         $a1, $v0, L_800798DC
    if (ctx->r5 == ctx->r2) {
        // 0x800792F4: addiu       $s0, $sp, 0x88
        ctx->r16 = ADD32(ctx->r29, 0X88);
            goto L_800798DC;
    }
    // 0x800792F4: addiu       $s0, $sp, 0x88
    ctx->r16 = ADD32(ctx->r29, 0X88);
    // 0x800792F8: j           L_80079988
    // 0x800792FC: nop

        goto L_80079988;
    // 0x800792FC: nop

L_80079300:
    // 0x80079300: lhu         $a0, 0x0($s5)
    ctx->r4 = MEM_HU(ctx->r21, 0X0);
    // 0x80079304: jal         0x8004013C
    // 0x80079308: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    func_8004013C(rdram, ctx);
        goto after_0;
    // 0x80079308: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    after_0:
    // 0x8007930C: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x80079310: lw          $a1, 0x4($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X4);
    // 0x80079314: jal         0x80059434
    // 0x80079318: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_80059434(rdram, ctx);
        goto after_1;
    // 0x80079318: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_1:
    // 0x8007931C: sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
    // 0x80079320: lhu         $a0, 0x16($s7)
    ctx->r4 = MEM_HU(ctx->r23, 0X16);
    // 0x80079324: lhu         $a1, 0x0($s5)
    ctx->r5 = MEM_HU(ctx->r21, 0X0);
    // 0x80079328: jal         0x80040188
    // 0x8007932C: addiu       $s4, $s2, 0x44
    ctx->r20 = ADD32(ctx->r18, 0X44);
    func_80040188(rdram, ctx);
        goto after_2;
    // 0x8007932C: addiu       $s4, $s2, 0x44
    ctx->r20 = ADD32(ctx->r18, 0X44);
    after_2:
    // 0x80079330: lw          $s1, 0x4($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X4);
    // 0x80079334: sh          $v0, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r2;
    // 0x80079338: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x8007933C: bne         $v0, $zero, L_8007935C
    if (ctx->r2 != 0) {
        // 0x80079340: addiu       $s6, $sp, 0x28
        ctx->r22 = ADD32(ctx->r29, 0X28);
            goto L_8007935C;
    }
    // 0x80079340: addiu       $s6, $sp, 0x28
    ctx->r22 = ADD32(ctx->r29, 0X28);
    // 0x80079344: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x80079348: addiu       $a1, $s1, 0x1C
    ctx->r5 = ADD32(ctx->r17, 0X1C);
    // 0x8007934C: jal         0x80018EF4
    // 0x80079350: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    zmemcpy(rdram, ctx);
        goto after_3;
    // 0x80079350: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_3:
    // 0x80079354: j           L_800793A0
    // 0x80079358: nop

        goto L_800793A0;
    // 0x80079358: nop

L_8007935C:
    // 0x8007935C: addiu       $a1, $s1, 0x1C
    ctx->r5 = ADD32(ctx->r17, 0X1C);
    // 0x80079360: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
L_80079364:
    // 0x80079364: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x80079368: beq         $v0, $zero, L_80079388
    if (ctx->r2 == 0) {
        // 0x8007936C: addu        $s0, $s4, $zero
        ctx->r16 = ADD32(ctx->r20, 0);
            goto L_80079388;
    }
    // 0x8007936C: addu        $s0, $s4, $zero
    ctx->r16 = ADD32(ctx->r20, 0);
    // 0x80079370: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80079374: andi        $v1, $s3, 0x1
    ctx->r3 = ctx->r19 & 0X1;
    // 0x80079378: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8007937C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80079380: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80079384: addu        $s0, $s6, $v0
    ctx->r16 = ADD32(ctx->r22, ctx->r2);
L_80079388:
    // 0x80079388: addiu       $a0, $s1, 0x1C
    ctx->r4 = ADD32(ctx->r17, 0X1C);
    // 0x8007938C: jal         0x800191C4
    // 0x80079390: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_800191C4(rdram, ctx);
        goto after_4;
    // 0x80079390: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_4:
    // 0x80079394: lw          $s1, 0x8($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X8);
    // 0x80079398: bne         $s1, $zero, L_80079364
    if (ctx->r17 != 0) {
        // 0x8007939C: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_80079364;
    }
    // 0x8007939C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
L_800793A0:
    // 0x800793A0: lw          $t0, 0x20($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X20);
    // 0x800793A4: lw          $t1, 0x24($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X24);
    // 0x800793A8: lw          $t2, 0x28($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X28);
    // 0x800793AC: sw          $t0, 0x74($s2)
    MEM_W(0X74, ctx->r18) = ctx->r8;
    // 0x800793B0: sw          $t1, 0x78($s2)
    MEM_W(0X78, ctx->r18) = ctx->r9;
    // 0x800793B4: sw          $t2, 0x7C($s2)
    MEM_W(0X7C, ctx->r18) = ctx->r10;
    // 0x800793B8: lwc1        $f2, 0x68($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X68);
    // 0x800793BC: lwc1        $f4, 0x6C($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X6C);
    // 0x800793C0: lwc1        $f0, 0x74($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X74);
    // 0x800793C4: lwc1        $f6, 0x70($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X70);
    // 0x800793C8: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800793CC: swc1        $f0, 0x68($s2)
    MEM_W(0X68, ctx->r18) = ctx->f0.u32l;
    // 0x800793D0: lwc1        $f0, 0x78($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X78);
    // 0x800793D4: swc1        $f2, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f2.u32l;
    // 0x800793D8: lwc1        $f2, 0x7C($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X7C);
    // 0x800793DC: swc1        $f4, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f4.u32l;
    // 0x800793E0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800793E4: lwc1        $f4, -0x2B60($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2B60);
    // 0x800793E8: swc1        $f6, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f6.u32l;
    // 0x800793EC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800793F0: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x800793F4: swc1        $f0, 0x6C($s2)
    MEM_W(0X6C, ctx->r18) = ctx->f0.u32l;
    // 0x800793F8: swc1        $f2, 0x70($s2)
    MEM_W(0X70, ctx->r18) = ctx->f2.u32l;
    // 0x800793FC: lw          $t0, 0x8($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X8);
    // 0x80079400: lw          $t1, 0xC($s5)
    ctx->r9 = MEM_W(ctx->r21, 0XC);
    // 0x80079404: lw          $t2, 0x10($s5)
    ctx->r10 = MEM_W(ctx->r21, 0X10);
    // 0x80079408: sw          $t0, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r8;
    // 0x8007940C: sw          $t1, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->r9;
    // 0x80079410: sw          $t2, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->r10;
    // 0x80079414: lwc1        $f0, 0x34($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X34);
    // 0x80079418: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8007941C: lwc1        $f6, 0x2C($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X2C);
    // 0x80079420: swc1        $f4, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f4.u32l;
    // 0x80079424: swc1        $f4, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f4.u32l;
    // 0x80079428: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8007942C: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x80079430: swc1        $f0, 0x80($s2)
    MEM_W(0X80, ctx->r18) = ctx->f0.u32l;
    // 0x80079434: swc1        $f2, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f2.u32l;
    // 0x80079438: swc1        $f2, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f2.u32l;
    // 0x8007943C: swc1        $f2, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f2.u32l;
    // 0x80079440: swc1        $f2, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f2.u32l;
    // 0x80079444: swc1        $f2, 0x84($s2)
    MEM_W(0X84, ctx->r18) = ctx->f2.u32l;
    // 0x80079448: bc1f        L_80079460
    if (!c1cs) {
        // 0x8007944C: swc1        $f6, 0x88($s2)
        MEM_W(0X88, ctx->r18) = ctx->f6.u32l;
            goto L_80079460;
    }
    // 0x8007944C: swc1        $f6, 0x88($s2)
    MEM_W(0X88, ctx->r18) = ctx->f6.u32l;
    // 0x80079450: c.eq.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl == ctx->f2.fl;
    // 0x80079454: nop

    // 0x80079458: bc1tl       L_80079460
    if (c1cs) {
        // 0x8007945C: swc1        $f4, 0x80($s2)
        MEM_W(0X80, ctx->r18) = ctx->f4.u32l;
            goto L_80079460;
    }
    goto skip_0;
    // 0x8007945C: swc1        $f4, 0x80($s2)
    MEM_W(0X80, ctx->r18) = ctx->f4.u32l;
    skip_0:
L_80079460:
    // 0x80079460: jal         0x8001CF58
    // 0x80079464: addiu       $a0, $s2, 0x80
    ctx->r4 = ADD32(ctx->r18, 0X80);
    normalize_vector(rdram, ctx);
        goto after_5;
    // 0x80079464: addiu       $a0, $s2, 0x80
    ctx->r4 = ADD32(ctx->r18, 0X80);
    after_5:
    // 0x80079468: lwc1        $f0, 0x2C($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X2C);
    // 0x8007946C: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x80079470: swc1        $f0, 0x8C($s2)
    MEM_W(0X8C, ctx->r18) = ctx->f0.u32l;
    // 0x80079474: lwc1        $f0, 0x14($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X14);
    // 0x80079478: swc1        $f0, 0x38($s2)
    MEM_W(0X38, ctx->r18) = ctx->f0.u32l;
    // 0x8007947C: lwc1        $f0, 0x18($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X18);
    // 0x80079480: swc1        $f0, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->f0.u32l;
    // 0x80079484: lwc1        $f0, 0x1C($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X1C);
    // 0x80079488: sw          $zero, 0x90($s2)
    MEM_W(0X90, ctx->r18) = 0;
    // 0x8007948C: swc1        $f0, 0x3C($s2)
    MEM_W(0X3C, ctx->r18) = ctx->f0.u32l;
    // 0x80079490: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x80079494: bne         $v1, $zero, L_800794CC
    if (ctx->r3 != 0) {
        // 0x80079498: nop
    
            goto L_800794CC;
    }
    // 0x80079498: nop

    // 0x8007949C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800794A0: beq         $v1, $zero, L_800794C0
    if (ctx->r3 == 0) {
        // 0x800794A4: nop
    
            goto L_800794C0;
    }
    // 0x800794A4: nop

    // 0x800794A8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800794AC: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x800794B0: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x800794B4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800794B8: j           L_800794E8
    // 0x800794BC: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
        goto L_800794E8;
    // 0x800794BC: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
L_800794C0:
    // 0x800794C0: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    // 0x800794C4: j           L_800794E8
    // 0x800794C8: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
        goto L_800794E8;
    // 0x800794C8: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
L_800794CC:
    // 0x800794CC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800794D0: beq         $v0, $zero, L_800794E8
    if (ctx->r2 == 0) {
        // 0x800794D4: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_800794E8;
    }
    // 0x800794D4: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800794D8: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x800794DC: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800794E0: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    // 0x800794E4: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_800794E8:
    // 0x800794E8: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x800794EC: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x800794F0: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x800794F4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800794F8: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800794FC: addiu       $v0, $s2, 0x8
    ctx->r2 = ADD32(ctx->r18, 0X8);
    // 0x80079500: sw          $v0, 0x8($s7)
    MEM_W(0X8, ctx->r23) = ctx->r2;
    // 0x80079504: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80079508: lhu         $a0, -0x6A8C($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A8C);
    // 0x8007950C: jal         0x8003E684
    // 0x80079510: addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    func_8003E684(rdram, ctx);
        goto after_6;
    // 0x80079510: addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    after_6:
    // 0x80079514: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x80079518: lhu         $a0, 0x16($s7)
    ctx->r4 = MEM_HU(ctx->r23, 0X16);
    // 0x8007951C: jal         0x8003E8DC
    // 0x80079520: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    slotDispatcherIter(rdram, ctx);
        goto after_7;
    // 0x80079520: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_7:
    // 0x80079524: j           L_80079988
    // 0x80079528: nop

        goto L_80079988;
    // 0x80079528: nop

L_8007952C:
    // 0x8007952C: lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X0);
    // 0x80079530: jal         0x8003F0C8
    // 0x80079534: nop

    func_8003F0C8(rdram, ctx);
        goto after_8;
    // 0x80079534: nop

    after_8:
    // 0x80079538: j           L_80079988
    // 0x8007953C: nop

        goto L_80079988;
    // 0x8007953C: nop

L_80079540:
    // 0x80079540: lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X0);
    // 0x80079544: lwc1        $f20, 0x0($s5)
    ctx->f20.u32l = MEM_W(ctx->r21, 0X0);
    // 0x80079548: jal         0x80040218
    // 0x8007954C: ori         $s0, $zero, 0xFFFF
    ctx->r16 = 0 | 0XFFFF;
    func_80040218(rdram, ctx);
        goto after_9;
    // 0x8007954C: ori         $s0, $zero, 0xFFFF
    ctx->r16 = 0 | 0XFFFF;
    after_9:
    // 0x80079550: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80079554: beq         $v0, $s0, L_80079604
    if (ctx->r2 == ctx->r16) {
        // 0x80079558: nop
    
            goto L_80079604;
    }
    // 0x80079558: nop

    // 0x8007955C: lw          $v0, 0x8($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X8);
    // 0x80079560: beq         $v0, $zero, L_80079988
    if (ctx->r2 == 0) {
        // 0x80079564: nop
    
            goto L_80079988;
    }
    // 0x80079564: nop

    // 0x80079568: lwc1        $f0, 0x40($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X40);
    // 0x8007956C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80079570: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x80079574: nop

    // 0x80079578: bc1f        L_80079618
    if (!c1cs) {
        // 0x8007957C: lui         $a2, 0x8014
        ctx->r6 = S32(0X8014 << 16);
            goto L_80079618;
    }
    // 0x8007957C: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x80079580: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x80079584: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80079588: nop

    // 0x8007958C: bc1f        L_80079618
    if (!c1cs) {
        // 0x80079590: swc1        $f0, 0x40($s2)
        MEM_W(0X40, ctx->r18) = ctx->f0.u32l;
            goto L_80079618;
    }
    // 0x80079590: swc1        $f0, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->f0.u32l;
    // 0x80079594: lhu         $a0, 0x0($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X0);
    // 0x80079598: jal         0x80040218
    // 0x8007959C: nop

    func_80040218(rdram, ctx);
        goto after_10;
    // 0x8007959C: nop

    after_10:
    // 0x800795A0: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x800795A4: beq         $a0, $s0, L_800795F8
    if (ctx->r4 == ctx->r16) {
        // 0x800795A8: addiu       $a1, $zero, 0xF
        ctx->r5 = ADD32(0, 0XF);
            goto L_800795F8;
    }
    // 0x800795A8: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x800795AC: lhu         $v0, 0x16($s7)
    ctx->r2 = MEM_HU(ctx->r23, 0X16);
    // 0x800795B0: sh          $v0, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r2;
    // 0x800795B4: lwc1        $f0, 0x8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8);
    // 0x800795B8: lwc1        $f2, 0x74($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X74);
    // 0x800795BC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800795C0: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x800795C4: lwc1        $f0, 0xC($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XC);
    // 0x800795C8: lwc1        $f2, 0x78($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X78);
    // 0x800795CC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800795D0: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    // 0x800795D4: lwc1        $f0, 0x10($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X10);
    // 0x800795D8: lwc1        $f2, 0x7C($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X7C);
    // 0x800795DC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800795E0: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    // 0x800795E4: jal         0x8003E8DC
    // 0x800795E8: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    slotDispatcherIter(rdram, ctx);
        goto after_11;
    // 0x800795E8: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    after_11:
    // 0x800795EC: lhu         $v0, 0x60($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X60);
    // 0x800795F0: beql        $v0, $s0, L_800795F8
    if (ctx->r2 == ctx->r16) {
        // 0x800795F4: sw          $zero, 0x8($s7)
        MEM_W(0X8, ctx->r23) = 0;
            goto L_800795F8;
    }
    goto skip_1;
    // 0x800795F4: sw          $zero, 0x8($s7)
    MEM_W(0X8, ctx->r23) = 0;
    skip_1:
L_800795F8:
    // 0x800795F8: lw          $v0, 0x8($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X8);
    // 0x800795FC: beq         $v0, $zero, L_80079988
    if (ctx->r2 == 0) {
        // 0x80079600: nop
    
            goto L_80079988;
    }
    // 0x80079600: nop

L_80079604:
    // 0x80079604: lhu         $a0, 0x16($s7)
    ctx->r4 = MEM_HU(ctx->r23, 0X16);
    // 0x80079608: jal         0x8003ED74
    // 0x8007960C: nop

    func_8003ED74(rdram, ctx);
        goto after_12;
    // 0x8007960C: nop

    after_12:
    // 0x80079610: j           L_80079988
    // 0x80079614: nop

        goto L_80079988;
    // 0x80079614: nop

L_80079618:
    // 0x80079618: lwc1        $f0, 0x90($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X90);
    // 0x8007961C: lwc1        $f2, 0x8($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80079620: add.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x80079624: lwc1        $f12, 0x74($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X74);
    // 0x80079628: lwc1        $f4, 0x10($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8007962C: add.s       $f12, $f2, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x80079630: lwc1        $f14, 0x7C($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X7C);
    // 0x80079634: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    // 0x80079638: add.s       $f14, $f4, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f14.fl;
    // 0x8007963C: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // 0x80079640: jal         0x80067D90
    // 0x80079644: swc1        $f0, 0x90($s2)
    MEM_W(0X90, ctx->r18) = ctx->f0.u32l;
    func_80067D90(rdram, ctx);
        goto after_13;
    // 0x80079644: swc1        $f0, 0x90($s2)
    MEM_W(0X90, ctx->r18) = ctx->f0.u32l;
    after_13:
    // 0x80079648: lwc1        $f2, 0xC($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8007964C: lwc1        $f4, 0x78($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X78);
    // 0x80079650: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x80079654: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80079658: add.s       $f2, $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f22.fl;
    // 0x8007965C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80079660: nop

    // 0x80079664: bc1f        L_8007980C
    if (!c1cs) {
        // 0x80079668: addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
            goto L_8007980C;
    }
    // 0x80079668: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8007966C: jal         0x8001CFA0
    // 0x80079670: addiu       $a1, $s2, 0x2C
    ctx->r5 = ADD32(ctx->r18, 0X2C);
    func_8001CFA0(rdram, ctx);
        goto after_14;
    // 0x80079670: addiu       $a1, $s2, 0x2C
    ctx->r5 = ADD32(ctx->r18, 0X2C);
    after_14:
    // 0x80079674: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80079678: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8007967C: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80079680: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80079684: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80079688: mul.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8007968C: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80079690: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80079694: mul.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80079698: add.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x8007969C: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800796A0: add.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x800796A4: c.lt.s      $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f22.fl < ctx->f8.fl;
    // 0x800796A8: nop

    // 0x800796AC: bc1f        L_8007980C
    if (!c1cs) {
        // 0x800796B0: mov.s       $f4, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.fl = ctx->f0.fl;
            goto L_8007980C;
    }
    // 0x800796B0: mov.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.fl = ctx->f0.fl;
    // 0x800796B4: lwc1        $f2, 0x90($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X90);
    // 0x800796B8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800796BC: lwc1        $f0, -0x2B5C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2B5C);
    // 0x800796C0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800796C4: nop

    // 0x800796C8: bc1f        L_800796FC
    if (!c1cs) {
        // 0x800796CC: nop
    
            goto L_800796FC;
    }
    // 0x800796CC: nop

    // 0x800796D0: lwc1        $f0, 0x2C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X2C);
    // 0x800796D4: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800796D8: lwc1        $f2, 0x34($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X34);
    // 0x800796DC: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800796E0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800796E4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800796E8: lwc1        $f2, -0x2B58($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2B58);
    // 0x800796EC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800796F0: nop

    // 0x800796F4: bc1tl       L_800796FC
    if (c1cs) {
        // 0x800796F8: mov.s       $f4, $f22
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    ctx->f4.fl = ctx->f22.fl;
            goto L_800796FC;
    }
    goto skip_2;
    // 0x800796F8: mov.s       $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    ctx->f4.fl = ctx->f22.fl;
    skip_2:
L_800796FC:
    // 0x800796FC: lwc1        $f0, 0x3C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X3C);
    // 0x80079700: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80079704: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80079708: lwc1        $f0, -0x2B54($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2B54);
    // 0x8007970C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80079710: nop

    // 0x80079714: bc1f        L_80079730
    if (!c1cs) {
        // 0x80079718: sw          $zero, 0x90($s2)
        MEM_W(0X90, ctx->r18) = 0;
            goto L_80079730;
    }
    // 0x80079718: sw          $zero, 0x90($s2)
    MEM_W(0X90, ctx->r18) = 0;
    // 0x8007971C: lwc1        $f0, 0x90($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X90);
    // 0x80079720: swc1        $f0, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->f0.u32l;
    // 0x80079724: swc1        $f0, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->f0.u32l;
    // 0x80079728: j           L_80079808
    // 0x8007972C: swc1        $f0, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f0.u32l;
        goto L_80079808;
    // 0x8007972C: swc1        $f0, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f0.u32l;
L_80079730:
    // 0x80079730: lwc1        $f2, 0x40($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X40);
    // 0x80079734: lwc1        $f6, 0x90($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X90);
    // 0x80079738: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x8007973C: nop

    // 0x80079740: bc1f        L_8007976C
    if (!c1cs) {
        // 0x80079744: nop
    
            goto L_8007976C;
    }
    // 0x80079744: nop

    // 0x80079748: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007974C: lwc1        $f0, -0x2B50($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2B50);
    // 0x80079750: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80079754: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x80079758: nop

    // 0x8007975C: bc1f        L_8007976C
    if (!c1cs) {
        // 0x80079760: swc1        $f0, 0x40($s2)
        MEM_W(0X40, ctx->r18) = ctx->f0.u32l;
            goto L_8007976C;
    }
    // 0x80079760: swc1        $f0, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->f0.u32l;
    // 0x80079764: j           L_80079988
    // 0x80079768: swc1        $f6, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->f6.u32l;
        goto L_80079988;
    // 0x80079768: swc1        $f6, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->f6.u32l;
L_8007976C:
    // 0x8007976C: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80079770: mul.s       $f2, $f8, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80079774: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80079778: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8007977C: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80079780: swc1        $f0, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f0.u32l;
    // 0x80079784: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80079788: mul.s       $f2, $f8, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8007978C: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80079790: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80079794: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80079798: swc1        $f0, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->f0.u32l;
    // 0x8007979C: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800797A0: mul.s       $f0, $f8, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800797A4: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800797A8: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800797AC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800797B0: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800797B4: lwc1        $f4, 0x2C($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X2C);
    // 0x800797B8: swc1        $f6, 0x84($s2)
    MEM_W(0X84, ctx->r18) = ctx->f6.u32l;
    // 0x800797BC: swc1        $f4, 0x88($s2)
    MEM_W(0X88, ctx->r18) = ctx->f4.u32l;
    // 0x800797C0: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    // 0x800797C4: swc1        $f0, 0x80($s2)
    MEM_W(0X80, ctx->r18) = ctx->f0.u32l;
    // 0x800797C8: c.eq.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl == ctx->f6.fl;
    // 0x800797CC: nop

    // 0x800797D0: bc1f        L_800797F4
    if (!c1cs) {
        // 0x800797D4: swc1        $f2, 0x34($s2)
        MEM_W(0X34, ctx->r18) = ctx->f2.u32l;
            goto L_800797F4;
    }
    // 0x800797D4: swc1        $f2, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->f2.u32l;
    // 0x800797D8: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x800797DC: nop

    // 0x800797E0: bc1f        L_800797F4
    if (!c1cs) {
        // 0x800797E4: nop
    
            goto L_800797F4;
    }
    // 0x800797E4: nop

    // 0x800797E8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800797EC: lwc1        $f0, -0x2B4C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2B4C);
    // 0x800797F0: swc1        $f0, 0x80($s2)
    MEM_W(0X80, ctx->r18) = ctx->f0.u32l;
L_800797F4:
    // 0x800797F4: jal         0x8001CF58
    // 0x800797F8: addiu       $a0, $s2, 0x80
    ctx->r4 = ADD32(ctx->r18, 0X80);
    normalize_vector(rdram, ctx);
        goto after_15;
    // 0x800797F8: addiu       $a0, $s2, 0x80
    ctx->r4 = ADD32(ctx->r18, 0X80);
    after_15:
    // 0x800797FC: lwc1        $f0, 0x8C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8C);
    // 0x80079800: lwc1        $f2, 0x3C($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X3C);
    // 0x80079804: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
L_80079808:
    // 0x80079808: swc1        $f0, 0x8C($s2)
    MEM_W(0X8C, ctx->r18) = ctx->f0.u32l;
L_8007980C:
    // 0x8007980C: lwc1        $f0, 0x8C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8C);
    // 0x80079810: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80079814: lwc1        $f2, 0x30($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X30);
    // 0x80079818: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x8007981C: lwc1        $f8, 0x34($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X34);
    // 0x80079820: mul.s       $f8, $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x80079824: lwc1        $f10, 0x38($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X38);
    // 0x80079828: mul.s       $f10, $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8007982C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80079830: lwc1        $f0, 0x2C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X2C);
    // 0x80079834: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80079838: lwc1        $f4, 0xC($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8007983C: add.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x80079840: lwc1        $f2, 0x30($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X30);
    // 0x80079844: addiu       $s1, $sp, 0x50
    ctx->r17 = ADD32(ctx->r29, 0X50);
    // 0x80079848: add.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x8007984C: lwc1        $f6, 0x8($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80079850: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x80079854: add.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80079858: lwc1        $f0, 0x10($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8007985C: addiu       $a1, $s2, 0x80
    ctx->r5 = ADD32(ctx->r18, 0X80);
    // 0x80079860: swc1        $f4, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f4.u32l;
    // 0x80079864: add.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80079868: swc1        $f2, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->f2.u32l;
    // 0x8007986C: swc1        $f6, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f6.u32l;
    // 0x80079870: jal         0x8001D240
    // 0x80079874: swc1        $f0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f0.u32l;
    func_8001D240(rdram, ctx);
        goto after_16;
    // 0x80079874: swc1        $f0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f0.u32l;
    after_16:
    // 0x80079878: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8007987C: addiu       $s0, $sp, 0x18
    ctx->r16 = ADD32(ctx->r29, 0X18);
    // 0x80079880: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x80079884: lw          $t0, 0x14($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X14);
    // 0x80079888: lw          $t1, 0x18($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X18);
    // 0x8007988C: lw          $t2, 0x1C($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X1C);
    // 0x80079890: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80079894: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80079898: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x8007989C: jal         0x8001D3C4
    // 0x800798A0: addiu       $a2, $s2, 0x14
    ctx->r6 = ADD32(ctx->r18, 0X14);
    func_8001D3C4(rdram, ctx);
        goto after_17;
    // 0x800798A0: addiu       $a2, $s2, 0x14
    ctx->r6 = ADD32(ctx->r18, 0X14);
    after_17:
    // 0x800798A4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800798A8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800798AC: lw          $t0, 0x20($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X20);
    // 0x800798B0: lw          $t1, 0x24($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X24);
    // 0x800798B4: lw          $t2, 0x28($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X28);
    // 0x800798B8: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800798BC: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800798C0: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x800798C4: jal         0x8001D3C4
    // 0x800798C8: addiu       $a2, $s2, 0x20
    ctx->r6 = ADD32(ctx->r18, 0X20);
    func_8001D3C4(rdram, ctx);
        goto after_18;
    // 0x800798C8: addiu       $a2, $s2, 0x20
    ctx->r6 = ADD32(ctx->r18, 0X20);
    after_18:
    // 0x800798CC: jal         0x80059F10
    // 0x800798D0: addiu       $a0, $s2, 0x8
    ctx->r4 = ADD32(ctx->r18, 0X8);
    func_80059F10(rdram, ctx);
        goto after_19;
    // 0x800798D0: addiu       $a0, $s2, 0x8
    ctx->r4 = ADD32(ctx->r18, 0X8);
    after_19:
    // 0x800798D4: j           L_80079988
    // 0x800798D8: nop

        goto L_80079988;
    // 0x800798D8: nop

L_800798DC:
    // 0x800798DC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800798E0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800798E4: lw          $s1, 0x4($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X4);
    // 0x800798E8: jal         0x80059B50
    // 0x800798EC: addiu       $a1, $s2, 0x8
    ctx->r5 = ADD32(ctx->r18, 0X8);
    func_80059B50(rdram, ctx);
        goto after_20;
    // 0x800798EC: addiu       $a1, $s2, 0x8
    ctx->r5 = ADD32(ctx->r18, 0X8);
    after_20:
    // 0x800798F0: lw          $a1, 0x74($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X74);
    // 0x800798F4: lw          $a2, 0x78($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X78);
    // 0x800798F8: lw          $a3, 0x7C($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X7C);
    // 0x800798FC: jal         0x8001CA90
    // 0x80079900: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8001CA90(rdram, ctx);
        goto after_21;
    // 0x80079900: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_21:
    // 0x80079904: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80079908: addiu       $a1, $s2, 0x44
    ctx->r5 = ADD32(ctx->r18, 0X44);
    // 0x8007990C: jal         0x800191C4
    // 0x80079910: addiu       $a2, $s1, 0x1C
    ctx->r6 = ADD32(ctx->r17, 0X1C);
    func_800191C4(rdram, ctx);
        goto after_22;
    // 0x80079910: addiu       $a2, $s1, 0x1C
    ctx->r6 = ADD32(ctx->r17, 0X1C);
    after_22:
    // 0x80079914: beq         $s5, $zero, L_80079988
    if (ctx->r21 == 0) {
        // 0x80079918: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_80079988;
    }
    // 0x80079918: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8007991C: lwc1        $f0, 0x8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8);
    // 0x80079920: lwc1        $f2, 0x74($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X74);
    // 0x80079924: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80079928: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x8007992C: lwc1        $f0, 0xC($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XC);
    // 0x80079930: lwc1        $f2, 0x78($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X78);
    // 0x80079934: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80079938: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x8007993C: lwc1        $f2, 0x10($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X10);
    // 0x80079940: lwc1        $f0, 0x7C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X7C);
    // 0x80079944: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80079948: lui         $a3, 0x40A0
    ctx->r7 = S32(0X40A0 << 16);
    // 0x8007994C: swc1        $f2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f2.u32l;
    // 0x80079950: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80079954: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x80079958: jal         0x8001DC34
    // 0x8007995C: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    func_8001DC34(rdram, ctx);
        goto after_23;
    // 0x8007995C: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    after_23:
    // 0x80079960: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80079964: beq         $v0, $zero, L_80079988
    if (ctx->r2 == 0) {
        // 0x80079968: nop
    
            goto L_80079988;
    }
    // 0x80079968: nop

    // 0x8007996C: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x80079970: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x80079974: beq         $v0, $zero, L_80079980
    if (ctx->r2 == 0) {
        // 0x80079978: sw          $v0, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r2;
            goto L_80079980;
    }
    // 0x80079978: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8007997C: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
L_80079980:
    // 0x80079980: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x80079984: sw          $s1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r17;
L_80079988:
    // 0x80079988: lw          $ra, 0xD8($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XD8);
    // 0x8007998C: lw          $s7, 0xD4($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XD4);
    // 0x80079990: lw          $s6, 0xD0($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XD0);
    // 0x80079994: lw          $s5, 0xCC($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XCC);
    // 0x80079998: lw          $s4, 0xC8($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XC8);
    // 0x8007999C: lw          $s3, 0xC4($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XC4);
    // 0x800799A0: lw          $s2, 0xC0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC0);
    // 0x800799A4: lw          $s1, 0xBC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XBC);
    // 0x800799A8: lw          $s0, 0xB8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XB8);
    // 0x800799AC: ldc1        $f22, 0xE8($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0XE8);
    // 0x800799B0: ldc1        $f20, 0xE0($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XE0);
    // 0x800799B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800799B8: jr          $ra
    // 0x800799BC: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    return;
    // 0x800799BC: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
;}
RECOMP_FUNC void func_800799C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800799C0: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x800799C4: sw          $s1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r17;
    // 0x800799C8: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800799CC: sw          $s3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r19;
    // 0x800799D0: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x800799D4: sw          $ra, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r31;
    // 0x800799D8: sw          $s4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r20;
    // 0x800799DC: sw          $s2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r18;
    // 0x800799E0: sw          $s0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r16;
    // 0x800799E4: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x800799E8: bne         $v0, $zero, L_80079A08
    if (ctx->r2 != 0) {
        // 0x800799EC: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_80079A08;
    }
    // 0x800799EC: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800799F0: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x800799F4: addiu       $a1, $s1, 0x1C
    ctx->r5 = ADD32(ctx->r17, 0X1C);
    // 0x800799F8: jal         0x80018EF4
    // 0x800799FC: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    zmemcpy(rdram, ctx);
        goto after_0;
    // 0x800799FC: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_0:
    // 0x80079A00: j           L_80079A50
    // 0x80079A04: nop

        goto L_80079A50;
    // 0x80079A04: nop

L_80079A08:
    // 0x80079A08: addiu       $a1, $s1, 0x1C
    ctx->r5 = ADD32(ctx->r17, 0X1C);
    // 0x80079A0C: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80079A10: addiu       $s4, $sp, 0x10
    ctx->r20 = ADD32(ctx->r29, 0X10);
L_80079A14:
    // 0x80079A14: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x80079A18: beq         $v0, $zero, L_80079A38
    if (ctx->r2 == 0) {
        // 0x80079A1C: addu        $s0, $s3, $zero
        ctx->r16 = ADD32(ctx->r19, 0);
            goto L_80079A38;
    }
    // 0x80079A1C: addu        $s0, $s3, $zero
    ctx->r16 = ADD32(ctx->r19, 0);
    // 0x80079A20: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80079A24: andi        $v1, $s2, 0x1
    ctx->r3 = ctx->r18 & 0X1;
    // 0x80079A28: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80079A2C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80079A30: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80079A34: addu        $s0, $s4, $v0
    ctx->r16 = ADD32(ctx->r20, ctx->r2);
L_80079A38:
    // 0x80079A38: addiu       $a0, $s1, 0x1C
    ctx->r4 = ADD32(ctx->r17, 0X1C);
    // 0x80079A3C: jal         0x800191C4
    // 0x80079A40: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_800191C4(rdram, ctx);
        goto after_1;
    // 0x80079A40: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_1:
    // 0x80079A44: lw          $s1, 0x8($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X8);
    // 0x80079A48: bne         $s1, $zero, L_80079A14
    if (ctx->r17 != 0) {
        // 0x80079A4C: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_80079A14;
    }
    // 0x80079A4C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
L_80079A50:
    // 0x80079A50: lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X84);
    // 0x80079A54: lw          $s4, 0x80($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X80);
    // 0x80079A58: lw          $s3, 0x7C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X7C);
    // 0x80079A5C: lw          $s2, 0x78($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X78);
    // 0x80079A60: lw          $s1, 0x74($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X74);
    // 0x80079A64: lw          $s0, 0x70($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X70);
    // 0x80079A68: jr          $ra
    // 0x80079A6C: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x80079A6C: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_80079A70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079A70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80079A74: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80079A78: jal         0x80071D20
    // 0x80079A7C: nop

    func_80071D20(rdram, ctx);
        goto after_0;
    // 0x80079A7C: nop

    after_0:
    // 0x80079A80: jal         0x80072CF0
    // 0x80079A84: nop

    func_80072CF0(rdram, ctx);
        goto after_1;
    // 0x80079A84: nop

    after_1:
    // 0x80079A88: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80079A8C: jr          $ra
    // 0x80079A90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80079A90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80079A94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079A94: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80079A98: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80079A9C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80079AA0: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x80079AA4: sw          $ra, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r31;
    // 0x80079AA8: jal         0x80003430
    // 0x80079AAC: addiu       $s1, $s0, 0x8
    ctx->r17 = ADD32(ctx->r16, 0X8);
    rand_recomp(rdram, ctx);
        goto after_0;
    // 0x80079AAC: addiu       $s1, $s0, 0x8
    ctx->r17 = ADD32(ctx->r16, 0X8);
    after_0:
    // 0x80079AB0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80079AB4: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80079AB8: addiu       $v1, $zero, 0x2D
    ctx->r3 = ADD32(0, 0X2D);
    // 0x80079ABC: div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // 0x80079AC0: bne         $v1, $zero, L_80079ACC
    if (ctx->r3 != 0) {
        // 0x80079AC4: nop
    
            goto L_80079ACC;
    }
    // 0x80079AC4: nop

    // 0x80079AC8: break       7
    do_break(2147982024);
L_80079ACC:
    // 0x80079ACC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80079AD0: bne         $v1, $at, L_80079AE4
    if (ctx->r3 != ctx->r1) {
        // 0x80079AD4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80079AE4;
    }
    // 0x80079AD4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80079AD8: bne         $v0, $at, L_80079AE4
    if (ctx->r2 != ctx->r1) {
        // 0x80079ADC: nop
    
            goto L_80079AE4;
    }
    // 0x80079ADC: nop

    // 0x80079AE0: break       6
    do_break(2147982048);
L_80079AE4:
    // 0x80079AE4: mfhi        $v1
    ctx->r3 = hi;
    // 0x80079AE8: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x80079AEC: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80079AF0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80079AF4: jal         0x8001CC3C
    // 0x80079AF8: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_8001CC3C(rdram, ctx);
        goto after_1;
    // 0x80079AF8: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_1:
    // 0x80079AFC: jal         0x80003430
    // 0x80079B00: nop

    rand_recomp(rdram, ctx);
        goto after_2;
    // 0x80079B00: nop

    after_2:
    // 0x80079B04: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80079B08: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80079B0C: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80079B10: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80079B14: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80079B18: jal         0x8001CCCC
    // 0x80079B1C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_8001CCCC(rdram, ctx);
        goto after_3;
    // 0x80079B1C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_3:
    // 0x80079B20: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80079B24: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80079B28: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x80079B2C: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80079B30: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80079B34: lwc1        $f2, -0x2B48($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2B48);
    // 0x80079B38: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80079B3C: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
    // 0x80079B40: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80079B44: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80079B48: lwc1        $f6, -0x2B44($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2B44);
    // 0x80079B4C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80079B50: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
    // 0x80079B54: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80079B58: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80079B5C: lwc1        $f0, -0x2B40($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2B40);
    // 0x80079B60: swc1        $f2, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f2.u32l;
    // 0x80079B64: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80079B68: lwc1        $f2, -0x2B3C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2B3C);
    // 0x80079B6C: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80079B70: mul.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x80079B74: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x80079B78: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x80079B7C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80079B80: lwc1        $f0, -0x2B38($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2B38);
    // 0x80079B84: mul.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80079B88: swc1        $f2, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f2.u32l;
    // 0x80079B8C: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x80079B90: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80079B94: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80079B98: lwc1        $f2, -0x2B34($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2B34);
    // 0x80079B9C: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80079BA0: sw          $zero, 0x28($s0)
    MEM_W(0X28, ctx->r16) = 0;
    // 0x80079BA4: swc1        $f2, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f2.u32l;
    // 0x80079BA8: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x80079BAC: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x80079BB0: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x80079BB4: lw          $ra, 0x48($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X48);
    // 0x80079BB8: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x80079BBC: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80079BC0: jr          $ra
    // 0x80079BC4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80079BC4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_80079BC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079BC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80079BCC: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x80079BD0: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x80079BD4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80079BD8: lhu         $v0, 0x16($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X16);
    // 0x80079BDC: addiu       $a0, $a0, -0x6D80
    ctx->r4 = ADD32(ctx->r4, -0X6D80);
    // 0x80079BE0: sw          $a2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r6;
    // 0x80079BE4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80079BE8: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x80079BEC: lbu         $a3, 0x19($a1)
    ctx->r7 = MEM_BU(ctx->r5, 0X19);
    // 0x80079BF0: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x80079BF4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80079BF8: jal         0x8003FFEC
    // 0x80079BFC: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    func_8003FFEC(rdram, ctx);
        goto after_0;
    // 0x80079BFC: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_0:
    // 0x80079C00: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80079C04: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80079C08: jr          $ra
    // 0x80079C0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80079C0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80079C10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079C10: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80079C14: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x80079C18: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80079C1C: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80079C20: sw          $ra, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r31;
    // 0x80079C24: jal         0x80003430
    // 0x80079C28: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    rand_recomp(rdram, ctx);
        goto after_0;
    // 0x80079C28: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    after_0:
    // 0x80079C2C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80079C30: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80079C34: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x80079C38: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80079C3C: div         $zero, $v0, $s0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r16)));
    // 0x80079C40: bne         $s0, $zero, L_80079C4C
    if (ctx->r16 != 0) {
        // 0x80079C44: nop
    
            goto L_80079C4C;
    }
    // 0x80079C44: nop

    // 0x80079C48: break       7
    do_break(2147982408);
L_80079C4C:
    // 0x80079C4C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80079C50: bne         $s0, $at, L_80079C64
    if (ctx->r16 != ctx->r1) {
        // 0x80079C54: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80079C64;
    }
    // 0x80079C54: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80079C58: bne         $v0, $at, L_80079C64
    if (ctx->r2 != ctx->r1) {
        // 0x80079C5C: nop
    
            goto L_80079C64;
    }
    // 0x80079C5C: nop

    // 0x80079C60: break       6
    do_break(2147982432);
L_80079C64:
    // 0x80079C64: mfhi        $v1
    ctx->r3 = hi;
    // 0x80079C68: mtc1        $v1, $f2
    ctx->f2.u32l = ctx->r3;
    // 0x80079C6C: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80079C70: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80079C74: jal         0x8001CC3C
    // 0x80079C78: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_8001CC3C(rdram, ctx);
        goto after_1;
    // 0x80079C78: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_1:
    // 0x80079C7C: jal         0x80003430
    // 0x80079C80: nop

    rand_recomp(rdram, ctx);
        goto after_2;
    // 0x80079C80: nop

    after_2:
    // 0x80079C84: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80079C88: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x80079C8C: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x80079C90: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80079C94: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x80079C98: jal         0x8001CCCC
    // 0x80079C9C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_8001CCCC(rdram, ctx);
        goto after_3;
    // 0x80079C9C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_3:
    // 0x80079CA0: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80079CA4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80079CA8: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
    // 0x80079CAC: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80079CB0: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80079CB4: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
    // 0x80079CB8: lwc1        $f0, 0x2C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80079CBC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80079CC0: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
    // 0x80079CC4: lw          $ra, 0x48($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X48);
    // 0x80079CC8: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x80079CCC: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80079CD0: jr          $ra
    // 0x80079CD4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80079CD4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void fake_func_80079CD8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void setNewAndPreviousButtonsPressed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079CE0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80079CE4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80079CE8: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80079CEC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80079CF0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80079CF4: addiu       $s0, $v0, -0x56B0
    ctx->r16 = ADD32(ctx->r2, -0X56B0);
    // 0x80079CF8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80079CFC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80079D00: addiu       $s1, $v0, -0x56A0
    ctx->r17 = ADD32(ctx->r2, -0X56A0);
    // 0x80079D04: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
L_80079D08:
    // 0x80079D08: jal         0x80079F20
    // 0x80079D0C: andi        $a0, $s2, 0xFF
    ctx->r4 = ctx->r18 & 0XFF;
    readControllerInputs(rdram, ctx);
        goto after_0;
    // 0x80079D0C: andi        $a0, $s2, 0xFF
    ctx->r4 = ctx->r18 & 0XFF;
    after_0:
    // 0x80079D10: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x80079D14: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80079D18: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80079D1C: nor         $v1, $zero, $v1
    ctx->r3 = ~(0 | ctx->r3);
    // 0x80079D20: and         $v1, $v0, $v1
    ctx->r3 = ctx->r2 & ctx->r3;
    // 0x80079D24: sw          $v1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r3;
    // 0x80079D28: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80079D2C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80079D30: sltiu       $v0, $s2, 0x4
    ctx->r2 = ctx->r18 < 0X4 ? 1 : 0;
    // 0x80079D34: bne         $v0, $zero, L_80079D08
    if (ctx->r2 != 0) {
        // 0x80079D38: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80079D08;
    }
    // 0x80079D38: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80079D3C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80079D40: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80079D44: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80079D48: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80079D4C: jr          $ra
    // 0x80079D50: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80079D50: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void getControllerButtonAndStick(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079D54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80079D58: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80079D5C: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x80079D60: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80079D64: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80079D68: addiu       $v1, $v1, 0xB88
    ctx->r3 = ADD32(ctx->r3, 0XB88);
    // 0x80079D6C: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    // 0x80079D70: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x80079D74: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80079D78: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80079D7C: addu        $a1, $v0, $v1
    ctx->r5 = ADD32(ctx->r2, ctx->r3);
    // 0x80079D80: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80079D84: lbu         $v1, 0x4($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X4);
    // 0x80079D88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80079D8C: bne         $v1, $v0, L_80079D98
    if (ctx->r3 != ctx->r2) {
        // 0x80079D90: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_80079D98;
    }
    // 0x80079D90: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x80079D94: lhu         $s0, 0x0($a1)
    ctx->r16 = MEM_HU(ctx->r5, 0X0);
L_80079D98:
    // 0x80079D98: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80079D9C: lbu         $v0, 0xB56($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB56);
    // 0x80079DA0: bne         $v0, $zero, L_80079DB8
    if (ctx->r2 != 0) {
        // 0x80079DA4: nop
    
            goto L_80079DB8;
    }
    // 0x80079DA4: nop

    // 0x80079DA8: jal         0x8007A068
    // 0x80079DAC: nop

    getControllerStickXPercentage(rdram, ctx);
        goto after_0;
    // 0x80079DAC: nop

    after_0:
    // 0x80079DB0: j           L_80079DBC
    // 0x80079DB4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_80079DBC;
    // 0x80079DB4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80079DB8:
    // 0x80079DB8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_80079DBC:
    // 0x80079DBC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80079DC0: lwc1        $f0, -0x2B30($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2B30);
    // 0x80079DC4: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80079DC8: nop

    // 0x80079DCC: bc1f        L_80079DD8
    if (!c1cs) {
        // 0x80079DD0: lui         $v0, 0x80
        ctx->r2 = S32(0X80 << 16);
            goto L_80079DD8;
    }
    // 0x80079DD0: lui         $v0, 0x80
    ctx->r2 = S32(0X80 << 16);
    // 0x80079DD4: or          $s0, $s0, $v0
    ctx->r16 = ctx->r16 | ctx->r2;
L_80079DD8:
    // 0x80079DD8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80079DDC: lbu         $v0, 0xB56($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB56);
    // 0x80079DE0: bne         $v0, $zero, L_80079DF8
    if (ctx->r2 != 0) {
        // 0x80079DE4: nop
    
            goto L_80079DF8;
    }
    // 0x80079DE4: nop

    // 0x80079DE8: jal         0x8007A068
    // 0x80079DEC: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    getControllerStickXPercentage(rdram, ctx);
        goto after_1;
    // 0x80079DEC: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_1:
    // 0x80079DF0: j           L_80079DFC
    // 0x80079DF4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_80079DFC;
    // 0x80079DF4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80079DF8:
    // 0x80079DF8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_80079DFC:
    // 0x80079DFC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80079E00: lwc1        $f0, -0x2B2C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2B2C);
    // 0x80079E04: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80079E08: nop

    // 0x80079E0C: bc1f        L_80079E18
    if (!c1cs) {
        // 0x80079E10: lui         $v0, 0x40
        ctx->r2 = S32(0X40 << 16);
            goto L_80079E18;
    }
    // 0x80079E10: lui         $v0, 0x40
    ctx->r2 = S32(0X40 << 16);
    // 0x80079E14: or          $s0, $s0, $v0
    ctx->r16 = ctx->r16 | ctx->r2;
L_80079E18:
    // 0x80079E18: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80079E1C: lbu         $v0, 0xB56($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB56);
    // 0x80079E20: bne         $v0, $zero, L_80079E38
    if (ctx->r2 != 0) {
        // 0x80079E24: nop
    
            goto L_80079E38;
    }
    // 0x80079E24: nop

    // 0x80079E28: jal         0x8007A0A8
    // 0x80079E2C: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    getControllerStickYPercentage(rdram, ctx);
        goto after_2;
    // 0x80079E2C: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_2:
    // 0x80079E30: j           L_80079E3C
    // 0x80079E34: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_80079E3C;
    // 0x80079E34: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80079E38:
    // 0x80079E38: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_80079E3C:
    // 0x80079E3C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80079E40: lwc1        $f0, -0x2B28($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2B28);
    // 0x80079E44: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80079E48: nop

    // 0x80079E4C: bc1f        L_80079E58
    if (!c1cs) {
        // 0x80079E50: lui         $v0, 0x10
        ctx->r2 = S32(0X10 << 16);
            goto L_80079E58;
    }
    // 0x80079E50: lui         $v0, 0x10
    ctx->r2 = S32(0X10 << 16);
    // 0x80079E54: or          $s0, $s0, $v0
    ctx->r16 = ctx->r16 | ctx->r2;
L_80079E58:
    // 0x80079E58: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80079E5C: lbu         $v0, 0xB56($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB56);
    // 0x80079E60: bne         $v0, $zero, L_80079E78
    if (ctx->r2 != 0) {
        // 0x80079E64: nop
    
            goto L_80079E78;
    }
    // 0x80079E64: nop

    // 0x80079E68: jal         0x8007A0A8
    // 0x80079E6C: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    getControllerStickYPercentage(rdram, ctx);
        goto after_3;
    // 0x80079E6C: andi        $a0, $s1, 0xFF
    ctx->r4 = ctx->r17 & 0XFF;
    after_3:
    // 0x80079E70: j           L_80079E7C
    // 0x80079E74: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_80079E7C;
    // 0x80079E74: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80079E78:
    // 0x80079E78: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_80079E7C:
    // 0x80079E7C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80079E80: lwc1        $f0, -0x2B24($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2B24);
    // 0x80079E84: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80079E88: nop

    // 0x80079E8C: bc1f        L_80079E98
    if (!c1cs) {
        // 0x80079E90: lui         $v0, 0x20
        ctx->r2 = S32(0X20 << 16);
            goto L_80079E98;
    }
    // 0x80079E90: lui         $v0, 0x20
    ctx->r2 = S32(0X20 << 16);
    // 0x80079E94: or          $s0, $s0, $v0
    ctx->r16 = ctx->r16 | ctx->r2;
L_80079E98:
    // 0x80079E98: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x80079E9C: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80079EA0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80079EA4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80079EA8: jr          $ra
    // 0x80079EAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80079EAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void initNewAndPreviousButtonsPressed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079EB0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80079EB4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80079EB8: addiu       $a2, $v0, -0x56A0
    ctx->r6 = ADD32(ctx->r2, -0X56A0);
    // 0x80079EBC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80079EC0: addiu       $a1, $v0, -0x56B0
    ctx->r5 = ADD32(ctx->r2, -0X56B0);
L_80079EC4:
    // 0x80079EC4: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x80079EC8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80079ECC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80079ED0: addu        $v0, $v1, $a2
    ctx->r2 = ADD32(ctx->r3, ctx->r6);
    // 0x80079ED4: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80079ED8: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80079EDC: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x80079EE0: sltiu       $v0, $v0, 0x4
    ctx->r2 = ctx->r2 < 0X4 ? 1 : 0;
    // 0x80079EE4: bne         $v0, $zero, L_80079EC4
    if (ctx->r2 != 0) {
        // 0x80079EE8: sw          $zero, 0x0($v1)
        MEM_W(0X0, ctx->r3) = 0;
            goto L_80079EC4;
    }
    // 0x80079EE8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80079EEC: jr          $ra
    // 0x80079EF0: nop

    return;
    // 0x80079EF0: nop

;}
RECOMP_FUNC void func_80079EF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079EF4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80079EF8: addiu       $v1, $v1, 0xB88
    ctx->r3 = ADD32(ctx->r3, 0XB88);
    // 0x80079EFC: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80079F00: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x80079F04: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80079F08: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80079F0C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80079F10: lbu         $v0, 0x4($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4);
    // 0x80079F14: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x80079F18: jr          $ra
    // 0x80079F1C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    return;
    // 0x80079F1C: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void readControllerInputs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079F20: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80079F24: lbu         $v0, 0xB56($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB56);
    // 0x80079F28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80079F2C: beq         $v0, $zero, L_80079F3C
    if (ctx->r2 == 0) {
        // 0x80079F30: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_80079F3C;
    }
    // 0x80079F30: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80079F34: j           L_80079F44
    // 0x80079F38: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80079F44;
    // 0x80079F38: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80079F3C:
    // 0x80079F3C: jal         0x80079D54
    // 0x80079F40: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    getControllerButtonAndStick(rdram, ctx);
        goto after_0;
    // 0x80079F40: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    after_0:
L_80079F44:
    // 0x80079F44: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80079F48: jr          $ra
    // 0x80079F4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80079F4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void getControllerNewButtonsPressed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079F50: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80079F54: addiu       $v0, $v0, -0x56A0
    ctx->r2 = ADD32(ctx->r2, -0X56A0);
    // 0x80079F58: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80079F5C: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80079F60: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80079F64: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80079F68: jr          $ra
    // 0x80079F6C: nop

    return;
    // 0x80079F6C: nop

;}
RECOMP_FUNC void func_80079F70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079F70: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80079F74: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80079F78: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x80079F7C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80079F80: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80079F84: addiu       $s1, $v0, 0xB40
    ctx->r17 = ADD32(ctx->r2, 0XB40);
    // 0x80079F88: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
L_80079F8C:
    // 0x80079F8C: lbu         $v0, 0x16($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X16);
    // 0x80079F90: bne         $v0, $zero, L_80079FA8
    if (ctx->r2 != 0) {
        // 0x80079F94: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80079FA8;
    }
    // 0x80079F94: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80079F98: jal         0x80079D54
    // 0x80079F9C: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    getControllerButtonAndStick(rdram, ctx);
        goto after_0;
    // 0x80079F9C: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    after_0:
    // 0x80079FA0: j           L_80079FAC
    // 0x80079FA4: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
        goto L_80079FAC;
    // 0x80079FA4: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_80079FA8:
    // 0x80079FA8: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_80079FAC:
    // 0x80079FAC: beq         $v0, $zero, L_80079FC4
    if (ctx->r2 == 0) {
        // 0x80079FB0: nop
    
            goto L_80079FC4;
    }
    // 0x80079FB0: nop

    // 0x80079FB4: jal         0x80002FF4
    // 0x80079FB8: nop

    func_80002FF4(rdram, ctx);
        goto after_1;
    // 0x80079FB8: nop

    after_1:
    // 0x80079FBC: j           L_80079F8C
    // 0x80079FC0: nop

        goto L_80079F8C;
    // 0x80079FC0: nop

L_80079FC4:
    // 0x80079FC4: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80079FC8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80079FCC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80079FD0: jr          $ra
    // 0x80079FD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80079FD4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void unsetControllerNewButtonsPressed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079FD8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80079FDC: addiu       $v0, $v0, -0x56A0
    ctx->r2 = ADD32(ctx->r2, -0X56A0);
    // 0x80079FE0: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80079FE4: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80079FE8: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x80079FEC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80079FF0: nor         $a1, $zero, $a1
    ctx->r5 = ~(0 | ctx->r5);
    // 0x80079FF4: and         $v0, $v0, $a1
    ctx->r2 = ctx->r2 & ctx->r5;
    // 0x80079FF8: jr          $ra
    // 0x80079FFC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    return;
    // 0x80079FFC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_8007A000(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A000: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8007A004: lbu         $v0, 0xB56($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB56);
    // 0x8007A008: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007A00C: beq         $v0, $zero, L_8007A020
    if (ctx->r2 == 0) {
        // 0x8007A010: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_8007A020;
    }
    // 0x8007A010: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8007A014: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8007A018: j           L_8007A028
    // 0x8007A01C: nop

        goto L_8007A028;
    // 0x8007A01C: nop

L_8007A020:
    // 0x8007A020: jal         0x8007A068
    // 0x8007A024: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    getControllerStickXPercentage(rdram, ctx);
        goto after_0;
    // 0x8007A024: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    after_0:
L_8007A028:
    // 0x8007A028: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8007A02C: jr          $ra
    // 0x8007A030: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8007A030: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_8007A034(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A034: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8007A038: lbu         $v0, 0xB56($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB56);
    // 0x8007A03C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007A040: beq         $v0, $zero, L_8007A054
    if (ctx->r2 == 0) {
        // 0x8007A044: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_8007A054;
    }
    // 0x8007A044: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8007A048: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8007A04C: j           L_8007A05C
    // 0x8007A050: nop

        goto L_8007A05C;
    // 0x8007A050: nop

L_8007A054:
    // 0x8007A054: jal         0x8007A0A8
    // 0x8007A058: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    getControllerStickYPercentage(rdram, ctx);
        goto after_0;
    // 0x8007A058: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    after_0:
L_8007A05C:
    // 0x8007A05C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8007A060: jr          $ra
    // 0x8007A064: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8007A064: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void getControllerStickXPercentage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A068: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8007A06C: addiu       $v1, $v1, 0xB88
    ctx->r3 = ADD32(ctx->r3, 0XB88);
    // 0x8007A070: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8007A074: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8007A078: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8007A07C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8007A080: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8007A084: lb          $v0, 0x2($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X2);
    // 0x8007A088: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007A08C: ldc1        $f2, -0x2B20($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2B20);
    // 0x8007A090: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8007A094: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007A098: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8007A09C: mul.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x8007A0A0: jr          $ra
    // 0x8007A0A4: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    return;
    // 0x8007A0A4: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
;}
RECOMP_FUNC void getControllerStickYPercentage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A0A8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8007A0AC: addiu       $v1, $v1, 0xB88
    ctx->r3 = ADD32(ctx->r3, 0XB88);
    // 0x8007A0B0: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8007A0B4: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8007A0B8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8007A0BC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8007A0C0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8007A0C4: lb          $v0, 0x3($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X3);
    // 0x8007A0C8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007A0CC: ldc1        $f2, -0x2B18($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X2B18);
    // 0x8007A0D0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8007A0D4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007A0D8: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x8007A0DC: mul.d       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f2.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f2.d);
    // 0x8007A0E0: jr          $ra
    // 0x8007A0E4: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
    return;
    // 0x8007A0E4: cvt.s.d     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f0.fl = CVT_S_D(ctx->f0.d);
;}
RECOMP_FUNC void fake_func_8007A0E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_8007A0F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A0F0: lwc1        $f6, 0x10($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X10);
    // 0x8007A0F4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8007A0F8: add.s       $f2, $f6, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8007A0FC: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x8007A100: add.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8007A104: trunc.w.s   $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    ctx->f8.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x8007A108: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8007A10C: mult        $a3, $a2
    result = S64(S32(ctx->r7)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007A110: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007A114: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x8007A118: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007A11C: lwc1        $f0, -0x2B10($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2B10);
    // 0x8007A120: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8007A124: add.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8007A128: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8007A12C: mfc1        $t2, $f8
    ctx->r10 = (int32_t)ctx->f8.u32l;
    // 0x8007A130: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8007A134: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x8007A138: mflo        $a3
    ctx->r7 = lo;
    // 0x8007A13C: addu        $v1, $t1, $a3
    ctx->r3 = ADD32(ctx->r9, ctx->r7);
    // 0x8007A140: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8007A144: addu        $t3, $v0, $v1
    ctx->r11 = ADD32(ctx->r2, ctx->r3);
    // 0x8007A148: addu        $v1, $a1, $t3
    ctx->r3 = ADD32(ctx->r5, ctx->r11);
    // 0x8007A14C: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8007A150: addu        $a3, $t2, $a3
    ctx->r7 = ADD32(ctx->r10, ctx->r7);
    // 0x8007A154: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x8007A158: lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1);
    // 0x8007A15C: mult        $t0, $a2
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007A160: sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
    // 0x8007A164: sll         $v0, $a3, 1
    ctx->r2 = S32(ctx->r7 << 1);
    // 0x8007A168: addu        $t3, $v0, $a3
    ctx->r11 = ADD32(ctx->r2, ctx->r7);
    // 0x8007A16C: lbu         $v1, 0x2($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X2);
    // 0x8007A170: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8007A174: addu        $a3, $a1, $t3
    ctx->r7 = ADD32(ctx->r5, ctx->r11);
    // 0x8007A178: sh          $v1, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r3;
    // 0x8007A17C: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x8007A180: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8007A184: mflo        $t0
    ctx->r8 = lo;
    // 0x8007A188: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x8007A18C: lbu         $v1, 0x1($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X1);
    // 0x8007A190: lhu         $v0, 0x2($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X2);
    // 0x8007A194: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x8007A198: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8007A19C: sll         $v1, $t1, 1
    ctx->r3 = S32(ctx->r9 << 1);
    // 0x8007A1A0: sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
    // 0x8007A1A4: lbu         $a2, 0x2($a3)
    ctx->r6 = MEM_BU(ctx->r7, 0X2);
    // 0x8007A1A8: lhu         $v0, 0x4($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X4);
    // 0x8007A1AC: addu        $t3, $v1, $t1
    ctx->r11 = ADD32(ctx->r3, ctx->r9);
    // 0x8007A1B0: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8007A1B4: addu        $a2, $a1, $t3
    ctx->r6 = ADD32(ctx->r5, ctx->r11);
    // 0x8007A1B8: sh          $v0, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r2;
    // 0x8007A1BC: lbu         $v1, 0x0($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X0);
    // 0x8007A1C0: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8007A1C4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8007A1C8: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x8007A1CC: lbu         $v1, 0x1($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X1);
    // 0x8007A1D0: lhu         $v0, 0x2($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X2);
    // 0x8007A1D4: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x8007A1D8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8007A1DC: sll         $v1, $t2, 1
    ctx->r3 = S32(ctx->r10 << 1);
    // 0x8007A1E0: addu        $t3, $v1, $t2
    ctx->r11 = ADD32(ctx->r3, ctx->r10);
    // 0x8007A1E4: sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
    // 0x8007A1E8: lbu         $a2, 0x2($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0X2);
    // 0x8007A1EC: lhu         $v0, 0x4($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X4);
    // 0x8007A1F0: addu        $a1, $a1, $t3
    ctx->r5 = ADD32(ctx->r5, ctx->r11);
    // 0x8007A1F4: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8007A1F8: sh          $v0, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r2;
    // 0x8007A1FC: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x8007A200: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8007A204: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8007A208: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x8007A20C: lbu         $v1, 0x1($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X1);
    // 0x8007A210: lhu         $v0, 0x2($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X2);
    // 0x8007A214: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8007A218: sh          $v0, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r2;
    // 0x8007A21C: lbu         $v1, 0x2($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X2);
    // 0x8007A220: lhu         $v0, 0x4($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X4);
    // 0x8007A224: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8007A228: sh          $v0, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r2;
    // 0x8007A22C: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x8007A230: lhu         $v1, 0x2($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X2);
    // 0x8007A234: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8007A238: sra         $v0, $v0, 2
    ctx->r2 = S32(SIGNED(ctx->r2) >> 2);
    // 0x8007A23C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8007A240: sh          $v0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r2;
    // 0x8007A244: lhu         $v0, 0x4($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X4);
    // 0x8007A248: sra         $v1, $v1, 2
    ctx->r3 = S32(SIGNED(ctx->r3) >> 2);
    // 0x8007A24C: sh          $v1, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r3;
    // 0x8007A250: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8007A254: sra         $v0, $v0, 2
    ctx->r2 = S32(SIGNED(ctx->r2) >> 2);
    // 0x8007A258: jr          $ra
    // 0x8007A25C: sh          $v0, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r2;
    return;
    // 0x8007A25C: sh          $v0, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_8007A260(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A260: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8007A264: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8007A268: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8007A26C: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8007A270: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8007A274: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8007A278: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8007A27C: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8007A280: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8007A284: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8007A288: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8007A28C: sdc1        $f24, 0x68($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X68, ctx->r29);
    // 0x8007A290: sdc1        $f22, 0x60($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X60, ctx->r29);
    // 0x8007A294: sdc1        $f20, 0x58($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X58, ctx->r29);
    // 0x8007A298: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x8007A29C: lhu         $v0, 0x28($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X28);
    // 0x8007A2A0: sll         $a3, $v0, 16
    ctx->r7 = S32(ctx->r2 << 16);
    // 0x8007A2A4: lhu         $v0, 0x2A($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X2A);
    // 0x8007A2A8: sra         $s3, $a3, 16
    ctx->r19 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8007A2AC: sll         $a2, $v0, 16
    ctx->r6 = S32(ctx->r2 << 16);
    // 0x8007A2B0: sra         $t0, $a2, 16
    ctx->r8 = S32(SIGNED(ctx->r6) >> 16);
    // 0x8007A2B4: slti        $v0, $s3, 0x3
    ctx->r2 = SIGNED(ctx->r19) < 0X3 ? 1 : 0;
    // 0x8007A2B8: beq         $v0, $zero, L_8007A2CC
    if (ctx->r2 == 0) {
        // 0x8007A2BC: sw          $t0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r8;
            goto L_8007A2CC;
    }
    // 0x8007A2BC: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8007A2C0: slti        $v0, $t0, 0x3
    ctx->r2 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
    // 0x8007A2C4: bne         $v0, $zero, L_8007A830
    if (ctx->r2 != 0) {
        // 0x8007A2C8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8007A830;
    }
    // 0x8007A2C8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8007A2CC:
    // 0x8007A2CC: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x8007A2D0: lhu         $a0, 0x2E($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0X2E);
    // 0x8007A2D4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8007A2D8: andi        $v1, $a0, 0xF
    ctx->r3 = ctx->r4 & 0XF;
    // 0x8007A2DC: bne         $v1, $v0, L_8007A830
    if (ctx->r3 != ctx->r2) {
        // 0x8007A2E0: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8007A830;
    }
    // 0x8007A2E0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8007A2E4: andi        $v0, $a0, 0x8000
    ctx->r2 = ctx->r4 & 0X8000;
    // 0x8007A2E8: bne         $v0, $zero, L_8007A824
    if (ctx->r2 != 0) {
        // 0x8007A2EC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8007A824;
    }
    // 0x8007A2EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007A2F0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8007A2F4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8007A2F8: mult        $s3, $t0
    result = S64(S32(ctx->r19)) * S64(S32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007A2FC: sra         $fp, $a3, 17
    ctx->r30 = S32(SIGNED(ctx->r7) >> 17);
    // 0x8007A300: sra         $a2, $a2, 17
    ctx->r6 = S32(SIGNED(ctx->r6) >> 17);
    // 0x8007A304: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x8007A308: lw          $s2, 0x0($t1)
    ctx->r18 = MEM_W(ctx->r9, 0X0);
    // 0x8007A30C: mflo        $v0
    ctx->r2 = lo;
    // 0x8007A310: sll         $s0, $v0, 1
    ctx->r16 = S32(ctx->r2 << 1);
    // 0x8007A314: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x8007A318: jal         0x80001ACC
    // 0x8007A31C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x8007A31C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8007A320: addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
    // 0x8007A324: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x8007A328: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8007A32C: jal         0x80018EF4
    // 0x8007A330: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    zmemcpy(rdram, ctx);
        goto after_1;
    // 0x8007A330: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_1:
    // 0x8007A334: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8007A338: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x8007A33C: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x8007A340: addiu       $v0, $s3, -0x2
    ctx->r2 = ADD32(ctx->r19, -0X2);
    // 0x8007A344: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x8007A348: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8007A34C: addiu       $v0, $fp, -0x2
    ctx->r2 = ADD32(ctx->r30, -0X2);
    // 0x8007A350: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8007A354: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8007A358: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8007A35C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8007A360: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8007A364: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007A368: div.s       $f24, $f2, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8007A36C: addiu       $v0, $t1, -0x2
    ctx->r2 = ADD32(ctx->r9, -0X2);
    // 0x8007A370: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8007A374: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007A378: addiu       $v0, $t0, -0x2
    ctx->r2 = ADD32(ctx->r8, -0X2);
    // 0x8007A37C: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x8007A380: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8007A384: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007A388: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007A38C: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x8007A390: jal         0x8007A0F0
    // 0x8007A394: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    func_8007A0F0(rdram, ctx);
        goto after_2;
    // 0x8007A394: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_2:
    // 0x8007A398: addiu       $s0, $zero, 0x3
    ctx->r16 = ADD32(0, 0X3);
    // 0x8007A39C: lbu         $v0, 0x19($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X19);
    // 0x8007A3A0: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x8007A3A4: sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
    // 0x8007A3A8: lbu         $v0, 0x1B($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1B);
    // 0x8007A3AC: sb          $v0, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r2;
    // 0x8007A3B0: lbu         $v0, 0x1D($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1D);
    // 0x8007A3B4: addiu       $v1, $fp, -0x1
    ctx->r3 = ADD32(ctx->r30, -0X1);
    // 0x8007A3B8: sb          $v0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r2;
    // 0x8007A3BC: slt         $v0, $s1, $v1
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007A3C0: beq         $v0, $zero, L_8007A464
    if (ctx->r2 == 0) {
        // 0x8007A3C4: addu        $a3, $s1, $zero
        ctx->r7 = ADD32(ctx->r17, 0);
            goto L_8007A464;
    }
    // 0x8007A3C4: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // 0x8007A3C8: addu        $s4, $v1, $zero
    ctx->r20 = ADD32(ctx->r3, 0);
L_8007A3CC:
    // 0x8007A3CC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8007A3D0: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x8007A3D4: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x8007A3D8: cvt.s.w     $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.fl = CVT_S_W(ctx->f20.u32l);
    // 0x8007A3DC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8007A3E0: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x8007A3E4: jal         0x8007A0F0
    // 0x8007A3E8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8007A0F0(rdram, ctx);
        goto after_3;
    // 0x8007A3E8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x8007A3EC: addu        $a0, $s2, $s0
    ctx->r4 = ADD32(ctx->r18, ctx->r16);
    // 0x8007A3F0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007A3F4: lhu         $v0, 0x18($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X18);
    // 0x8007A3F8: sltiu       $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 < 0XFF ? 1 : 0;
    // 0x8007A3FC: beq         $v0, $zero, L_8007A408
    if (ctx->r2 == 0) {
        // 0x8007A400: addiu       $v1, $zero, -0x1
        ctx->r3 = ADD32(0, -0X1);
            goto L_8007A408;
    }
    // 0x8007A400: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8007A404: lbu         $v1, 0x19($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X19);
L_8007A408:
    // 0x8007A408: addu        $a1, $s2, $s0
    ctx->r5 = ADD32(ctx->r18, ctx->r16);
    // 0x8007A40C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007A410: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // 0x8007A414: lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X1A);
    // 0x8007A418: sltiu       $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 < 0XFF ? 1 : 0;
    // 0x8007A41C: beq         $v0, $zero, L_8007A428
    if (ctx->r2 == 0) {
        // 0x8007A420: addiu       $v1, $zero, -0x1
        ctx->r3 = ADD32(0, -0X1);
            goto L_8007A428;
    }
    // 0x8007A420: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8007A424: lbu         $v1, 0x1B($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1B);
L_8007A428:
    // 0x8007A428: addu        $a0, $s2, $s0
    ctx->r4 = ADD32(ctx->r18, ctx->r16);
    // 0x8007A42C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007A430: sb          $v1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r3;
    // 0x8007A434: lhu         $v0, 0x1C($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X1C);
    // 0x8007A438: sltiu       $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 < 0XFF ? 1 : 0;
    // 0x8007A43C: beq         $v0, $zero, L_8007A448
    if (ctx->r2 == 0) {
        // 0x8007A440: addiu       $v1, $zero, -0x1
        ctx->r3 = ADD32(0, -0X1);
            goto L_8007A448;
    }
    // 0x8007A440: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8007A444: lbu         $v1, 0x1D($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1D);
L_8007A448:
    // 0x8007A448: add.s       $f0, $f20, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f20.fl + ctx->f24.fl;
    // 0x8007A44C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8007A450: slt         $v0, $s1, $s4
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8007A454: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007A458: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8007A45C: bne         $v0, $zero, L_8007A3CC
    if (ctx->r2 != 0) {
        // 0x8007A460: sb          $v1, 0x0($a0)
        MEM_B(0X0, ctx->r4) = ctx->r3;
            goto L_8007A3CC;
    }
    // 0x8007A460: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
L_8007A464:
    // 0x8007A464: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8007A468: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x8007A46C: addiu       $v0, $s3, -0x1
    ctx->r2 = ADD32(ctx->r19, -0X1);
    // 0x8007A470: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8007A474: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007A478: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8007A47C: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x8007A480: jal         0x8007A0F0
    // 0x8007A484: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8007A0F0(rdram, ctx);
        goto after_4;
    // 0x8007A484: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x8007A488: addu        $v1, $s2, $s0
    ctx->r3 = ADD32(ctx->r18, ctx->r16);
    // 0x8007A48C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007A490: addu        $a0, $s2, $s0
    ctx->r4 = ADD32(ctx->r18, ctx->r16);
    // 0x8007A494: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007A498: lbu         $v0, 0x19($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X19);
    // 0x8007A49C: addu        $a1, $s2, $s0
    ctx->r5 = ADD32(ctx->r18, ctx->r16);
    // 0x8007A4A0: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x8007A4A4: lbu         $v0, 0x1B($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1B);
    // 0x8007A4A8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007A4AC: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x8007A4B0: lbu         $v0, 0x1D($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1D);
    // 0x8007A4B4: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x8007A4B8: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x8007A4BC: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8007A4C0: j           L_8007A6A0
    // 0x8007A4C4: addu        $s7, $s6, $zero
    ctx->r23 = ADD32(ctx->r22, 0);
        goto L_8007A6A0;
    // 0x8007A4C4: addu        $s7, $s6, $zero
    ctx->r23 = ADD32(ctx->r22, 0);
L_8007A4C8:
    // 0x8007A4C8: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x8007A4CC: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x8007A4D0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8007A4D4: mtc1        $s6, $f20
    ctx->f20.u32l = ctx->r22;
    // 0x8007A4D8: cvt.s.w     $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.fl = CVT_S_W(ctx->f20.u32l);
    // 0x8007A4DC: jal         0x8007A0F0
    // 0x8007A4E0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    func_8007A0F0(rdram, ctx);
        goto after_5;
    // 0x8007A4E0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_5:
    // 0x8007A4E4: addu        $a0, $s2, $s0
    ctx->r4 = ADD32(ctx->r18, ctx->r16);
    // 0x8007A4E8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007A4EC: lhu         $v0, 0x18($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X18);
    // 0x8007A4F0: sltiu       $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 < 0XFF ? 1 : 0;
    // 0x8007A4F4: beq         $v0, $zero, L_8007A500
    if (ctx->r2 == 0) {
        // 0x8007A4F8: addiu       $v1, $zero, -0x1
        ctx->r3 = ADD32(0, -0X1);
            goto L_8007A500;
    }
    // 0x8007A4F8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8007A4FC: lbu         $v1, 0x19($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X19);
L_8007A500:
    // 0x8007A500: addu        $a1, $s2, $s0
    ctx->r5 = ADD32(ctx->r18, ctx->r16);
    // 0x8007A504: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007A508: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // 0x8007A50C: lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X1A);
    // 0x8007A510: sltiu       $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 < 0XFF ? 1 : 0;
    // 0x8007A514: beq         $v0, $zero, L_8007A520
    if (ctx->r2 == 0) {
        // 0x8007A518: addiu       $v1, $zero, -0x1
        ctx->r3 = ADD32(0, -0X1);
            goto L_8007A520;
    }
    // 0x8007A518: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8007A51C: lbu         $v1, 0x1B($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1B);
L_8007A520:
    // 0x8007A520: addu        $a0, $s2, $s0
    ctx->r4 = ADD32(ctx->r18, ctx->r16);
    // 0x8007A524: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007A528: sb          $v1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r3;
    // 0x8007A52C: lhu         $v0, 0x1C($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X1C);
    // 0x8007A530: sltiu       $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 < 0XFF ? 1 : 0;
    // 0x8007A534: beq         $v0, $zero, L_8007A540
    if (ctx->r2 == 0) {
        // 0x8007A538: addiu       $v1, $zero, -0x1
        ctx->r3 = ADD32(0, -0X1);
            goto L_8007A540;
    }
    // 0x8007A538: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8007A53C: lbu         $v1, 0x1D($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1D);
L_8007A540:
    // 0x8007A540: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // 0x8007A544: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8007A548: addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    // 0x8007A54C: addiu       $v1, $fp, -0x1
    ctx->r3 = ADD32(ctx->r30, -0X1);
    // 0x8007A550: slt         $v0, $s1, $v1
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007A554: beq         $v0, $zero, L_8007A600
    if (ctx->r2 == 0) {
        // 0x8007A558: addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
            goto L_8007A600;
    }
    // 0x8007A558: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8007A55C: mov.s       $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    ctx->f22.fl = ctx->f20.fl;
    // 0x8007A560: addu        $s4, $v1, $zero
    ctx->r20 = ADD32(ctx->r3, 0);
L_8007A564:
    // 0x8007A564: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8007A568: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x8007A56C: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x8007A570: cvt.s.w     $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.fl = CVT_S_W(ctx->f20.u32l);
    // 0x8007A574: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8007A578: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x8007A57C: jal         0x8007A0F0
    // 0x8007A580: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    func_8007A0F0(rdram, ctx);
        goto after_6;
    // 0x8007A580: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_6:
    // 0x8007A584: addu        $a0, $s2, $s0
    ctx->r4 = ADD32(ctx->r18, ctx->r16);
    // 0x8007A588: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007A58C: lhu         $v0, 0x18($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X18);
    // 0x8007A590: sltiu       $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 < 0XFF ? 1 : 0;
    // 0x8007A594: beq         $v0, $zero, L_8007A5A0
    if (ctx->r2 == 0) {
        // 0x8007A598: addiu       $v1, $zero, -0x1
        ctx->r3 = ADD32(0, -0X1);
            goto L_8007A5A0;
    }
    // 0x8007A598: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8007A59C: lbu         $v1, 0x19($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X19);
L_8007A5A0:
    // 0x8007A5A0: addu        $a1, $s2, $s0
    ctx->r5 = ADD32(ctx->r18, ctx->r16);
    // 0x8007A5A4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007A5A8: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // 0x8007A5AC: lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X1A);
    // 0x8007A5B0: sltiu       $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 < 0XFF ? 1 : 0;
    // 0x8007A5B4: beq         $v0, $zero, L_8007A5C0
    if (ctx->r2 == 0) {
        // 0x8007A5B8: addiu       $v1, $zero, -0x1
        ctx->r3 = ADD32(0, -0X1);
            goto L_8007A5C0;
    }
    // 0x8007A5B8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8007A5BC: lbu         $v1, 0x1B($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1B);
L_8007A5C0:
    // 0x8007A5C0: addu        $a0, $s2, $s0
    ctx->r4 = ADD32(ctx->r18, ctx->r16);
    // 0x8007A5C4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007A5C8: sb          $v1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r3;
    // 0x8007A5CC: lhu         $v0, 0x1C($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X1C);
    // 0x8007A5D0: sltiu       $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 < 0XFF ? 1 : 0;
    // 0x8007A5D4: beq         $v0, $zero, L_8007A5E0
    if (ctx->r2 == 0) {
        // 0x8007A5D8: addiu       $v1, $zero, -0x1
        ctx->r3 = ADD32(0, -0X1);
            goto L_8007A5E0;
    }
    // 0x8007A5D8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8007A5DC: lbu         $v1, 0x1D($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1D);
L_8007A5E0:
    // 0x8007A5E0: add.s       $f0, $f20, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f20.fl + ctx->f24.fl;
    // 0x8007A5E4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8007A5E8: slt         $v0, $s1, $s4
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8007A5EC: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007A5F0: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8007A5F4: bne         $v0, $zero, L_8007A564
    if (ctx->r2 != 0) {
        // 0x8007A5F8: sb          $v1, 0x0($a0)
        MEM_B(0X0, ctx->r4) = ctx->r3;
            goto L_8007A564;
    }
    // 0x8007A5F8: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // 0x8007A5FC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
L_8007A600:
    // 0x8007A600: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007A604: lwc1        $f2, -0x2B0C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2B0C);
    // 0x8007A608: mtc1        $s3, $f0
    ctx->f0.u32l = ctx->r19;
    // 0x8007A60C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007A610: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8007A614: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x8007A618: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x8007A61C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8007A620: mtc1        $s6, $f0
    ctx->f0.u32l = ctx->r22;
    // 0x8007A624: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007A628: jal         0x8007A0F0
    // 0x8007A62C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_8007A0F0(rdram, ctx);
        goto after_7;
    // 0x8007A62C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x8007A630: addu        $a0, $s2, $s0
    ctx->r4 = ADD32(ctx->r18, ctx->r16);
    // 0x8007A634: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007A638: lhu         $v0, 0x18($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X18);
    // 0x8007A63C: sltiu       $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 < 0XFF ? 1 : 0;
    // 0x8007A640: beq         $v0, $zero, L_8007A64C
    if (ctx->r2 == 0) {
        // 0x8007A644: addiu       $v1, $zero, -0x1
        ctx->r3 = ADD32(0, -0X1);
            goto L_8007A64C;
    }
    // 0x8007A644: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8007A648: lbu         $v1, 0x19($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X19);
L_8007A64C:
    // 0x8007A64C: addu        $a1, $s2, $s0
    ctx->r5 = ADD32(ctx->r18, ctx->r16);
    // 0x8007A650: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007A654: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // 0x8007A658: lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X1A);
    // 0x8007A65C: sltiu       $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 < 0XFF ? 1 : 0;
    // 0x8007A660: beq         $v0, $zero, L_8007A66C
    if (ctx->r2 == 0) {
        // 0x8007A664: addiu       $v1, $zero, -0x1
        ctx->r3 = ADD32(0, -0X1);
            goto L_8007A66C;
    }
    // 0x8007A664: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8007A668: lbu         $v1, 0x1B($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1B);
L_8007A66C:
    // 0x8007A66C: addu        $a0, $s2, $s0
    ctx->r4 = ADD32(ctx->r18, ctx->r16);
    // 0x8007A670: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007A674: sb          $v1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r3;
    // 0x8007A678: lhu         $v0, 0x1C($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X1C);
    // 0x8007A67C: sltiu       $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 < 0XFF ? 1 : 0;
    // 0x8007A680: beq         $v0, $zero, L_8007A68C
    if (ctx->r2 == 0) {
        // 0x8007A684: addiu       $v1, $zero, -0x1
        ctx->r3 = ADD32(0, -0X1);
            goto L_8007A68C;
    }
    // 0x8007A684: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8007A688: lbu         $v1, 0x1D($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1D);
L_8007A68C:
    // 0x8007A68C: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x8007A690: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // 0x8007A694: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8007A698: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8007A69C: addu        $s6, $s6, $t1
    ctx->r22 = ADD32(ctx->r22, ctx->r9);
L_8007A6A0:
    // 0x8007A6A0: addiu       $v0, $t0, -0x1
    ctx->r2 = ADD32(ctx->r8, -0X1);
    // 0x8007A6A4: slt         $v0, $s7, $v0
    ctx->r2 = SIGNED(ctx->r23) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8007A6A8: bne         $v0, $zero, L_8007A4C8
    if (ctx->r2 != 0) {
        // 0x8007A6AC: addiu       $a0, $sp, 0x18
        ctx->r4 = ADD32(ctx->r29, 0X18);
            goto L_8007A4C8;
    }
    // 0x8007A6AC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8007A6B0: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x8007A6B4: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x8007A6B8: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8007A6BC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8007A6C0: addiu       $v0, $t1, -0x1
    ctx->r2 = ADD32(ctx->r9, -0X1);
    // 0x8007A6C4: mtc1        $v0, $f20
    ctx->f20.u32l = ctx->r2;
    // 0x8007A6C8: cvt.s.w     $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.fl = CVT_S_W(ctx->f20.u32l);
    // 0x8007A6CC: jal         0x8007A0F0
    // 0x8007A6D0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    func_8007A0F0(rdram, ctx);
        goto after_8;
    // 0x8007A6D0: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_8:
    // 0x8007A6D4: addu        $v1, $s2, $s0
    ctx->r3 = ADD32(ctx->r18, ctx->r16);
    // 0x8007A6D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007A6DC: addu        $a0, $s2, $s0
    ctx->r4 = ADD32(ctx->r18, ctx->r16);
    // 0x8007A6E0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007A6E4: addu        $a1, $s2, $s0
    ctx->r5 = ADD32(ctx->r18, ctx->r16);
    // 0x8007A6E8: lbu         $v0, 0x19($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X19);
    // 0x8007A6EC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8007A6F0: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x8007A6F4: lbu         $v0, 0x1B($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1B);
    // 0x8007A6F8: addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    // 0x8007A6FC: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x8007A700: lbu         $v0, 0x1D($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1D);
    // 0x8007A704: addiu       $v1, $fp, -0x1
    ctx->r3 = ADD32(ctx->r30, -0X1);
    // 0x8007A708: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x8007A70C: slt         $v0, $s1, $v1
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007A710: beq         $v0, $zero, L_8007A7B8
    if (ctx->r2 == 0) {
        // 0x8007A714: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8007A7B8;
    }
    // 0x8007A714: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007A718: mov.s       $f22, $f20
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    ctx->f22.fl = ctx->f20.fl;
    // 0x8007A71C: addu        $s4, $v1, $zero
    ctx->r20 = ADD32(ctx->r3, 0);
L_8007A720:
    // 0x8007A720: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8007A724: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x8007A728: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x8007A72C: cvt.s.w     $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.fl = CVT_S_W(ctx->f20.u32l);
    // 0x8007A730: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x8007A734: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x8007A738: jal         0x8007A0F0
    // 0x8007A73C: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    func_8007A0F0(rdram, ctx);
        goto after_9;
    // 0x8007A73C: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_9:
    // 0x8007A740: addu        $a0, $s2, $s0
    ctx->r4 = ADD32(ctx->r18, ctx->r16);
    // 0x8007A744: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007A748: lhu         $v0, 0x18($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X18);
    // 0x8007A74C: sltiu       $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 < 0XFF ? 1 : 0;
    // 0x8007A750: beq         $v0, $zero, L_8007A75C
    if (ctx->r2 == 0) {
        // 0x8007A754: addiu       $v1, $zero, -0x1
        ctx->r3 = ADD32(0, -0X1);
            goto L_8007A75C;
    }
    // 0x8007A754: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8007A758: lbu         $v1, 0x19($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X19);
L_8007A75C:
    // 0x8007A75C: addu        $a1, $s2, $s0
    ctx->r5 = ADD32(ctx->r18, ctx->r16);
    // 0x8007A760: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007A764: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // 0x8007A768: lhu         $v0, 0x1A($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X1A);
    // 0x8007A76C: sltiu       $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 < 0XFF ? 1 : 0;
    // 0x8007A770: beq         $v0, $zero, L_8007A77C
    if (ctx->r2 == 0) {
        // 0x8007A774: addiu       $v1, $zero, -0x1
        ctx->r3 = ADD32(0, -0X1);
            goto L_8007A77C;
    }
    // 0x8007A774: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8007A778: lbu         $v1, 0x1B($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1B);
L_8007A77C:
    // 0x8007A77C: addu        $a0, $s2, $s0
    ctx->r4 = ADD32(ctx->r18, ctx->r16);
    // 0x8007A780: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007A784: sb          $v1, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r3;
    // 0x8007A788: lhu         $v0, 0x1C($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X1C);
    // 0x8007A78C: sltiu       $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 < 0XFF ? 1 : 0;
    // 0x8007A790: beq         $v0, $zero, L_8007A79C
    if (ctx->r2 == 0) {
        // 0x8007A794: addiu       $v1, $zero, -0x1
        ctx->r3 = ADD32(0, -0X1);
            goto L_8007A79C;
    }
    // 0x8007A794: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8007A798: lbu         $v1, 0x1D($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1D);
L_8007A79C:
    // 0x8007A79C: add.s       $f0, $f20, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f20.fl + ctx->f24.fl;
    // 0x8007A7A0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8007A7A4: slt         $v0, $s1, $s4
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x8007A7A8: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007A7AC: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8007A7B0: bne         $v0, $zero, L_8007A720
    if (ctx->r2 != 0) {
        // 0x8007A7B4: sb          $v1, 0x0($a0)
        MEM_B(0X0, ctx->r4) = ctx->r3;
            goto L_8007A720;
    }
    // 0x8007A7B4: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
L_8007A7B8:
    // 0x8007A7B8: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8007A7BC: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x8007A7C0: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x8007A7C4: addiu       $v0, $a2, -0x1
    ctx->r2 = ADD32(ctx->r6, -0X1);
    // 0x8007A7C8: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8007A7CC: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8007A7D0: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8007A7D4: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8007A7D8: addiu       $v0, $t0, -0x1
    ctx->r2 = ADD32(ctx->r8, -0X1);
    // 0x8007A7DC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8007A7E0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007A7E4: jal         0x8007A0F0
    // 0x8007A7E8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_8007A0F0(rdram, ctx);
        goto after_10;
    // 0x8007A7E8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_10:
    // 0x8007A7EC: addu        $v1, $s2, $s0
    ctx->r3 = ADD32(ctx->r18, ctx->r16);
    // 0x8007A7F0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007A7F4: lbu         $v0, 0x19($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X19);
    // 0x8007A7F8: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x8007A7FC: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x8007A800: lbu         $v1, 0x1B($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1B);
    // 0x8007A804: addu        $v0, $s2, $s0
    ctx->r2 = ADD32(ctx->r18, ctx->r16);
    // 0x8007A808: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x8007A80C: lbu         $v1, 0x1D($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X1D);
    // 0x8007A810: addu        $v0, $s0, $s2
    ctx->r2 = ADD32(ctx->r16, ctx->r18);
    // 0x8007A814: jal         0x80001C98
    // 0x8007A818: sb          $v1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r3;
    rs_free(rdram, ctx);
        goto after_11;
    // 0x8007A818: sb          $v1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r3;
    after_11:
    // 0x8007A81C: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x8007A820: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007A824:
    // 0x8007A824: sh          $fp, 0x28($t1)
    MEM_H(0X28, ctx->r9) = ctx->r30;
    // 0x8007A828: lhu         $t0, 0x26($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X26);
    // 0x8007A82C: sh          $t0, 0x2A($t1)
    MEM_H(0X2A, ctx->r9) = ctx->r8;
L_8007A830:
    // 0x8007A830: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8007A834: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8007A838: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x8007A83C: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8007A840: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8007A844: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8007A848: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8007A84C: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8007A850: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8007A854: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8007A858: ldc1        $f24, 0x68($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X68);
    // 0x8007A85C: ldc1        $f22, 0x60($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X60);
    // 0x8007A860: ldc1        $f20, 0x58($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X58);
    // 0x8007A864: jr          $ra
    // 0x8007A868: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8007A868: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void fake_func_8007A86C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_8007A870(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A870: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007A874: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007A878: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8007A87C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8007A880: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8007A884: lw          $v0, 0x1C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1C);
    // 0x8007A888: lw          $s0, 0x8($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X8);
    // 0x8007A88C: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8007A890: sw          $s0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r16;
    // 0x8007A894: lw          $v0, 0x1C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X1C);
    // 0x8007A898: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    // 0x8007A89C: lw          $s1, 0x20($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X20);
    // 0x8007A8A0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8007A8A4: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x8007A8A8: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    // 0x8007A8AC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8007A8B0: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x8007A8B4: jal         0x80001ACC
    // 0x8007A8B8: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x8007A8B8: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    after_0:
    // 0x8007A8BC: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x8007A8C0: sw          $t0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r8;
    // 0x8007A8C4: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x8007A8C8: beq         $v0, $zero, L_8007A984
    if (ctx->r2 == 0) {
        // 0x8007A8CC: addu        $t1, $zero, $zero
        ctx->r9 = ADD32(0, 0);
            goto L_8007A984;
    }
    // 0x8007A8CC: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x8007A8D0: addiu       $t5, $zero, 0x18
    ctx->r13 = ADD32(0, 0X18);
    // 0x8007A8D4: lui         $t4, 0xFC
    ctx->r12 = S32(0XFC << 16);
    // 0x8007A8D8: lui         $t2, 0x3
    ctx->r10 = S32(0X3 << 16);
    // 0x8007A8DC: ori         $t2, $t2, 0xF000
    ctx->r10 = ctx->r10 | 0XF000;
    // 0x8007A8E0: lui         $t3, 0x3F00
    ctx->r11 = S32(0X3F00 << 16);
L_8007A8E4:
    // 0x8007A8E4: lw          $a3, 0xC($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XC);
    // 0x8007A8E8: lw          $a1, 0x8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X8);
    // 0x8007A8EC: blezl       $a3, L_8007A970
    if (SIGNED(ctx->r7) <= 0) {
        // 0x8007A8F0: sw          $zero, 0x0($t0)
        MEM_W(0X0, ctx->r8) = 0;
            goto L_8007A970;
    }
    goto skip_0;
    // 0x8007A8F0: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    skip_0:
L_8007A8F4:
    // 0x8007A8F4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8007A8F8: andi        $v0, $v0, 0x18
    ctx->r2 = ctx->r2 & 0X18;
    // 0x8007A8FC: bne         $v0, $t5, L_8007A954
    if (ctx->r2 != ctx->r13) {
        // 0x8007A900: nop
    
            goto L_8007A954;
    }
    // 0x8007A900: nop

    // 0x8007A904: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x8007A908: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8007A90C: and         $v0, $v0, $t4
    ctx->r2 = ctx->r2 & ctx->r12;
    // 0x8007A910: srl         $v0, $v0, 16
    ctx->r2 = S32(U32(ctx->r2) >> 16);
    // 0x8007A914: addu        $a2, $a1, $v0
    ctx->r6 = ADD32(ctx->r5, ctx->r2);
L_8007A918:
    // 0x8007A918: lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X0);
    // 0x8007A91C: bnel        $v0, $t1, L_8007A948
    if (ctx->r2 != ctx->r9) {
        // 0x8007A920: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8007A948;
    }
    goto skip_1;
    // 0x8007A920: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_1:
    // 0x8007A924: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x8007A928: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x8007A92C: and         $v0, $v0, $t2
    ctx->r2 = ctx->r2 & ctx->r10;
    // 0x8007A930: srl         $v0, $v0, 10
    ctx->r2 = S32(U32(ctx->r2) >> 10);
    // 0x8007A934: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x8007A938: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8007A93C: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8007A940: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8007A944: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8007A948:
    // 0x8007A948: slti        $v0, $a0, 0x4
    ctx->r2 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x8007A94C: bne         $v0, $zero, L_8007A918
    if (ctx->r2 != 0) {
        // 0x8007A950: addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
            goto L_8007A918;
    }
    // 0x8007A950: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
L_8007A954:
    // 0x8007A954: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x8007A958: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x8007A95C: and         $v0, $v0, $t3
    ctx->r2 = ctx->r2 & ctx->r11;
    // 0x8007A960: srl         $v0, $v0, 22
    ctx->r2 = S32(U32(ctx->r2) >> 22);
    // 0x8007A964: bgtz        $a3, L_8007A8F4
    if (SIGNED(ctx->r7) > 0) {
        // 0x8007A968: addu        $a1, $a1, $v0
        ctx->r5 = ADD32(ctx->r5, ctx->r2);
            goto L_8007A8F4;
    }
    // 0x8007A968: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x8007A96C: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
L_8007A970:
    // 0x8007A970: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    // 0x8007A974: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8007A978: sltu        $v0, $t1, $v0
    ctx->r2 = ctx->r9 < ctx->r2 ? 1 : 0;
    // 0x8007A97C: bne         $v0, $zero, L_8007A8E4
    if (ctx->r2 != 0) {
        // 0x8007A980: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_8007A8E4;
    }
    // 0x8007A980: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
L_8007A984:
    // 0x8007A984: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x8007A988: addiu       $a0, $s2, 0xB4
    ctx->r4 = ADD32(ctx->r18, 0XB4);
L_8007A98C:
    // 0x8007A98C: sh          $zero, 0x28($a0)
    MEM_H(0X28, ctx->r4) = 0;
    // 0x8007A990: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x8007A994: bgez        $a3, L_8007A98C
    if (SIGNED(ctx->r7) >= 0) {
        // 0x8007A998: addiu       $a0, $a0, -0x3C
        ctx->r4 = ADD32(ctx->r4, -0X3C);
            goto L_8007A98C;
    }
    // 0x8007A998: addiu       $a0, $a0, -0x3C
    ctx->r4 = ADD32(ctx->r4, -0X3C);
    // 0x8007A99C: lui         $v1, 0x901
    ctx->r3 = S32(0X901 << 16);
    // 0x8007A9A0: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x8007A9A4: ori         $v1, $v1, 0x8
    ctx->r3 = ctx->r3 | 0X8;
    // 0x8007A9A8: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8007A9AC: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // 0x8007A9B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007A9B4: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8007A9B8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8007A9BC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8007A9C0: jr          $ra
    // 0x8007A9C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8007A9C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8007A9C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A9C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8007A9CC: addu        $t5, $a0, $zero
    ctx->r13 = ADD32(ctx->r4, 0);
    // 0x8007A9D0: sdc1        $f26, 0x18($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X18, ctx->r29);
    // 0x8007A9D4: sdc1        $f24, 0x10($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X10, ctx->r29);
    // 0x8007A9D8: sdc1        $f22, 0x8($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X8, ctx->r29);
    // 0x8007A9DC: sdc1        $f20, 0x0($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X0, ctx->r29);
    // 0x8007A9E0: lw          $v0, 0x4($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X4);
    // 0x8007A9E4: lw          $a3, 0x0($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X0);
    // 0x8007A9E8: lw          $t4, 0x14($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X14);
    // 0x8007A9EC: lw          $t3, 0x24($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X24);
    // 0x8007A9F0: blez        $t4, L_8007ACF4
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8007A9F4: nop
    
            goto L_8007ACF4;
    }
    // 0x8007A9F4: nop

    // 0x8007A9F8: addiu       $t0, $t3, 0x4
    ctx->r8 = ADD32(ctx->r11, 0X4);
    // 0x8007A9FC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8007AA00: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007AA04: lwc1        $f24, -0x2B00($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X2B00);
    // 0x8007AA08: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007AA0C: lwc1        $f22, -0x2AFC($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X2AFC);
L_8007AA10:
    // 0x8007AA10: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8007AA14: addu        $t2, $zero, $zero
    ctx->r10 = ADD32(0, 0);
    // 0x8007AA18: addiu       $t1, $t5, 0x8
    ctx->r9 = ADD32(ctx->r13, 0X8);
    // 0x8007AA1C: addiu       $a1, $t5, 0x18
    ctx->r5 = ADD32(ctx->r13, 0X18);
    // 0x8007AA20: mov.s       $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    ctx->f18.fl = ctx->f12.fl;
    // 0x8007AA24: mov.s       $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.fl = ctx->f12.fl;
    // 0x8007AA28: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
L_8007AA2C:
    // 0x8007AA2C: lhu         $v1, 0x10($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X10);
    // 0x8007AA30: beql        $v1, $zero, L_8007ABD0
    if (ctx->r3 == 0) {
        // 0x8007AA34: addiu       $a1, $a1, 0x3C
        ctx->r5 = ADD32(ctx->r5, 0X3C);
            goto L_8007ABD0;
    }
    goto skip_0;
    // 0x8007AA34: addiu       $a1, $a1, 0x3C
    ctx->r5 = ADD32(ctx->r5, 0X3C);
    skip_0:
    // 0x8007AA38: andi        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 & 0X2;
    // 0x8007AA3C: beq         $v0, $zero, L_8007AAB4
    if (ctx->r2 == 0) {
        // 0x8007AA40: andi        $v0, $v1, 0x4
        ctx->r2 = ctx->r3 & 0X4;
            goto L_8007AAB4;
    }
    // 0x8007AA40: andi        $v0, $v1, 0x4
    ctx->r2 = ctx->r3 & 0X4;
    // 0x8007AA44: lh          $v1, 0x0($t3)
    ctx->r3 = MEM_H(ctx->r11, 0X0);
    // 0x8007AA48: mult        $v1, $v1
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007AA4C: mflo        $v0
    ctx->r2 = lo;
    // 0x8007AA50: lh          $a0, 0x0($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X0);
    // 0x8007AA54: nop

    // 0x8007AA58: mult        $a0, $a0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007AA5C: mflo        $a2
    ctx->r6 = lo;
    // 0x8007AA60: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8007AA64: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8007AA68: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007AA6C: sqrt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = sqrtf(ctx->f0.fl);
    // 0x8007AA70: c.lt.s      $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f20.fl < ctx->f10.fl;
    // 0x8007AA74: nop

    // 0x8007AA78: bc1f        L_8007AB34
    if (!c1cs) {
        // 0x8007AA7C: nop
    
            goto L_8007AB34;
    }
    // 0x8007AA7C: nop

    // 0x8007AA80: lh          $v0, 0x8($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X8);
    // 0x8007AA84: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007AA88: mflo        $v1
    ctx->r3 = lo;
    // 0x8007AA8C: lh          $v0, 0xC($a1)
    ctx->r2 = MEM_H(ctx->r5, 0XC);
    // 0x8007AA90: nop

    // 0x8007AA94: mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007AA98: mflo        $v0
    ctx->r2 = lo;
    // 0x8007AA9C: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x8007AAA0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8007AAA4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007AAA8: mul.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x8007AAAC: j           L_8007AB34
    // 0x8007AAB0: div.s       $f10, $f0, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
        goto L_8007AB34;
    // 0x8007AAB0: div.s       $f10, $f0, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
L_8007AAB4:
    // 0x8007AAB4: beq         $v0, $zero, L_8007AAEC
    if (ctx->r2 == 0) {
        // 0x8007AAB8: nop
    
            goto L_8007AAEC;
    }
    // 0x8007AAB8: nop

    // 0x8007AABC: lh          $a0, -0x2($t0)
    ctx->r4 = MEM_H(ctx->r8, -0X2);
    // 0x8007AAC0: lh          $v1, 0xA($a1)
    ctx->r3 = MEM_H(ctx->r5, 0XA);
    // 0x8007AAC4: slt         $v0, $a0, $v1
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007AAC8: bne         $v0, $zero, L_8007AAD4
    if (ctx->r2 != 0) {
        // 0x8007AACC: subu        $v0, $v1, $a0
        ctx->r2 = SUB32(ctx->r3, ctx->r4);
            goto L_8007AAD4;
    }
    // 0x8007AACC: subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
    // 0x8007AAD0: subu        $v0, $a0, $v1
    ctx->r2 = SUB32(ctx->r4, ctx->r3);
L_8007AAD4:
    // 0x8007AAD4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8007AAD8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007AADC: sub.s       $f0, $f24, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f24.fl - ctx->f0.fl;
    // 0x8007AAE0: mul.s       $f10, $f0, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x8007AAE4: j           L_8007AB34
    // 0x8007AAE8: nop

        goto L_8007AB34;
    // 0x8007AAE8: nop

L_8007AAEC:
    // 0x8007AAEC: lh          $v1, 0x8($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X8);
    // 0x8007AAF0: lh          $v0, 0x0($t3)
    ctx->r2 = MEM_H(ctx->r11, 0X0);
    // 0x8007AAF4: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007AAF8: lh          $v1, 0xA($a1)
    ctx->r3 = MEM_H(ctx->r5, 0XA);
    // 0x8007AAFC: mflo        $a2
    ctx->r6 = lo;
    // 0x8007AB00: lh          $v0, -0x2($t0)
    ctx->r2 = MEM_H(ctx->r8, -0X2);
    // 0x8007AB04: nop

    // 0x8007AB08: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007AB0C: lh          $v1, 0xC($a1)
    ctx->r3 = MEM_H(ctx->r5, 0XC);
    // 0x8007AB10: mflo        $a0
    ctx->r4 = lo;
    // 0x8007AB14: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x8007AB18: nop

    // 0x8007AB1C: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007AB20: addu        $v0, $a2, $a0
    ctx->r2 = ADD32(ctx->r6, ctx->r4);
    // 0x8007AB24: mflo        $v1
    ctx->r3 = lo;
    // 0x8007AB28: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8007AB2C: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x8007AB30: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
L_8007AB34:
    // 0x8007AB34: lwc1        $f2, 0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8007AB38: sub.s       $f10, $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x8007AB3C: c.le.s      $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f10.fl <= ctx->f20.fl;
    // 0x8007AB40: nop

    // 0x8007AB44: bc1tl       L_8007ABD0
    if (c1cs) {
        // 0x8007AB48: addiu       $a1, $a1, 0x3C
        ctx->r5 = ADD32(ctx->r5, 0X3C);
            goto L_8007ABD0;
    }
    goto skip_1;
    // 0x8007AB48: addiu       $a1, $a1, 0x3C
    ctx->r5 = ADD32(ctx->r5, 0X3C);
    skip_1:
    // 0x8007AB4C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007AB50: lwc1        $f0, -0x2AF8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2AF8);
    // 0x8007AB54: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8007AB58: lwc1        $f2, -0xC($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, -0XC);
    // 0x8007AB5C: div.s       $f10, $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8007AB60: mul.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8007AB64: lwc1        $f4, -0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, -0X8);
    // 0x8007AB68: mul.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8007AB6C: lwc1        $f6, -0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, -0X4);
    // 0x8007AB70: mul.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8007AB74: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8007AB78: mul.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8007AB7C: lbu         $v0, 0x0($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X0);
    // 0x8007AB80: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8007AB84: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007AB88: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8007AB8C: lbu         $v0, -0xF($a1)
    ctx->r2 = MEM_BU(ctx->r5, -0XF);
    // 0x8007AB90: add.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f0.fl;
    // 0x8007AB94: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8007AB98: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007AB9C: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8007ABA0: lbu         $v0, -0xE($a1)
    ctx->r2 = MEM_BU(ctx->r5, -0XE);
    // 0x8007ABA4: add.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x8007ABA8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8007ABAC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007ABB0: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8007ABB4: lbu         $v0, -0xD($a1)
    ctx->r2 = MEM_BU(ctx->r5, -0XD);
    // 0x8007ABB8: add.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x8007ABBC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8007ABC0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007ABC4: add.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x8007ABC8: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x8007ABCC: addiu       $a1, $a1, 0x3C
    ctx->r5 = ADD32(ctx->r5, 0X3C);
L_8007ABD0:
    // 0x8007ABD0: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x8007ABD4: slti        $v0, $t2, 0x4
    ctx->r2 = SIGNED(ctx->r10) < 0X4 ? 1 : 0;
    // 0x8007ABD8: bne         $v0, $zero, L_8007AA2C
    if (ctx->r2 != 0) {
        // 0x8007ABDC: addiu       $t1, $t1, 0x3C
        ctx->r9 = ADD32(ctx->r9, 0X3C);
            goto L_8007AA2C;
    }
    // 0x8007ABDC: addiu       $t1, $t1, 0x3C
    ctx->r9 = ADD32(ctx->r9, 0X3C);
    // 0x8007ABE0: c.lt.s      $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f14.fl < ctx->f20.fl;
    // 0x8007ABE4: nop

    // 0x8007ABE8: bc1t        L_8007AC04
    if (c1cs) {
        // 0x8007ABEC: mov.s       $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
            goto L_8007AC04;
    }
    // 0x8007ABEC: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    // 0x8007ABF0: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    // 0x8007ABF4: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x8007ABF8: nop

    // 0x8007ABFC: bc1tl       L_8007AC04
    if (c1cs) {
        // 0x8007AC00: mov.s       $f0, $f22
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
            goto L_8007AC04;
    }
    goto skip_2;
    // 0x8007AC00: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
    skip_2:
L_8007AC04:
    // 0x8007AC04: c.lt.s      $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f16.fl < ctx->f20.fl;
    // 0x8007AC08: nop

    // 0x8007AC0C: bc1f        L_8007AC1C
    if (!c1cs) {
        // 0x8007AC10: mov.s       $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
            goto L_8007AC1C;
    }
    // 0x8007AC10: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x8007AC14: j           L_8007AC30
    // 0x8007AC18: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
        goto L_8007AC30;
    // 0x8007AC18: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
L_8007AC1C:
    // 0x8007AC1C: mov.s       $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = ctx->f16.fl;
    // 0x8007AC20: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x8007AC24: nop

    // 0x8007AC28: bc1tl       L_8007AC30
    if (c1cs) {
        // 0x8007AC2C: mov.s       $f0, $f22
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
            goto L_8007AC30;
    }
    goto skip_3;
    // 0x8007AC2C: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
    skip_3:
L_8007AC30:
    // 0x8007AC30: c.lt.s      $f18, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f18.fl < ctx->f20.fl;
    // 0x8007AC34: nop

    // 0x8007AC38: bc1f        L_8007AC48
    if (!c1cs) {
        // 0x8007AC3C: mov.s       $f16, $f0
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
            goto L_8007AC48;
    }
    // 0x8007AC3C: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
    // 0x8007AC40: j           L_8007AC5C
    // 0x8007AC44: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
        goto L_8007AC5C;
    // 0x8007AC44: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
L_8007AC48:
    // 0x8007AC48: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
    // 0x8007AC4C: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x8007AC50: nop

    // 0x8007AC54: bc1tl       L_8007AC5C
    if (c1cs) {
        // 0x8007AC58: mov.s       $f0, $f22
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
            goto L_8007AC5C;
    }
    goto skip_4;
    // 0x8007AC58: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
    skip_4:
L_8007AC5C:
    // 0x8007AC5C: c.lt.s      $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f12.fl < ctx->f20.fl;
    // 0x8007AC60: nop

    // 0x8007AC64: bc1f        L_8007AC74
    if (!c1cs) {
        // 0x8007AC68: mov.s       $f18, $f0
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
            goto L_8007AC74;
    }
    // 0x8007AC68: mov.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
    // 0x8007AC6C: j           L_8007AC88
    // 0x8007AC70: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
        goto L_8007AC88;
    // 0x8007AC70: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
L_8007AC74:
    // 0x8007AC74: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x8007AC78: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x8007AC7C: nop

    // 0x8007AC80: bc1tl       L_8007AC88
    if (c1cs) {
        // 0x8007AC84: mov.s       $f0, $f22
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
            goto L_8007AC88;
    }
    goto skip_5;
    // 0x8007AC84: mov.s       $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    ctx->f0.fl = ctx->f22.fl;
    skip_5:
L_8007AC88:
    // 0x8007AC88: trunc.w.s   $f26, $f14
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    ctx->f26.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x8007AC8C: mfc1        $v1, $f26
    ctx->r3 = (int32_t)ctx->f26.u32l;
    // 0x8007AC90: sll         $v1, $v1, 24
    ctx->r3 = S32(ctx->r3 << 24);
    // 0x8007AC94: trunc.w.s   $f26, $f16
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    ctx->f26.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8007AC98: mfc1        $v0, $f26
    ctx->r2 = (int32_t)ctx->f26.u32l;
    // 0x8007AC9C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8007ACA0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8007ACA4: trunc.w.s   $f26, $f18
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 18);
    ctx->f26.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8007ACA8: mfc1        $v0, $f26
    ctx->r2 = (int32_t)ctx->f26.u32l;
    // 0x8007ACAC: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x8007ACB0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8007ACB4: trunc.w.s   $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007ACB8: mfc1        $v0, $f26
    ctx->r2 = (int32_t)ctx->f26.u32l;
    // 0x8007ACBC: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x8007ACC0: beq         $a0, $zero, L_8007ACE0
    if (ctx->r4 == 0) {
        // 0x8007ACC4: or          $v1, $v1, $v0
        ctx->r3 = ctx->r3 | ctx->r2;
            goto L_8007ACE0;
    }
    // 0x8007ACC4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8007ACC8: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8007ACCC: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
L_8007ACD0:
    // 0x8007ACD0: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8007ACD4: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x8007ACD8: bnel        $v0, $zero, L_8007ACD0
    if (ctx->r2 != 0) {
        // 0x8007ACDC: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_8007ACD0;
    }
    goto skip_6;
    // 0x8007ACDC: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    skip_6:
L_8007ACE0:
    // 0x8007ACE0: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x8007ACE4: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x8007ACE8: addiu       $t3, $t3, 0x8
    ctx->r11 = ADD32(ctx->r11, 0X8);
    // 0x8007ACEC: bgtz        $t4, L_8007AA10
    if (SIGNED(ctx->r12) > 0) {
        // 0x8007ACF0: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_8007AA10;
    }
    // 0x8007ACF0: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
L_8007ACF4:
    // 0x8007ACF4: lw          $v1, 0x4($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X4);
    // 0x8007ACF8: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x8007ACFC: ori         $v0, $v0, 0x20
    ctx->r2 = ctx->r2 | 0X20;
    // 0x8007AD00: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x8007AD04: lw          $a0, 0x4($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X4);
    // 0x8007AD08: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x8007AD0C: addiu       $v1, $zero, -0x181
    ctx->r3 = ADD32(0, -0X181);
    // 0x8007AD10: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8007AD14: sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
    // 0x8007AD18: ldc1        $f26, 0x18($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X18);
    // 0x8007AD1C: ldc1        $f24, 0x10($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X10);
    // 0x8007AD20: ldc1        $f22, 0x8($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X8);
    // 0x8007AD24: ldc1        $f20, 0x0($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X0);
    // 0x8007AD28: jr          $ra
    // 0x8007AD2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8007AD2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8007AD30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007AD30: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8007AD34: sdc1        $f20, 0x70($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X70, ctx->r29);
    // 0x8007AD38: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x8007AD3C: sdc1        $f22, 0x78($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X78, ctx->r29);
    // 0x8007AD40: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8007AD44: sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // 0x8007AD48: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8007AD4C: sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // 0x8007AD50: addiu       $s0, $a0, 0x28
    ctx->r16 = ADD32(ctx->r4, 0X28);
    // 0x8007AD54: sw          $ra, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r31;
L_8007AD58:
    // 0x8007AD58: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x8007AD5C: beql        $v0, $zero, L_8007AED0
    if (ctx->r2 == 0) {
        // 0x8007AD60: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8007AED0;
    }
    goto skip_0;
    // 0x8007AD60: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x8007AD64: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8007AD68: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8007AD6C: lwc1        $f2, 0x10($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8007AD70: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8007AD74: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007AD78: lwc1        $f0, -0x2AF4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2AF4);
    // 0x8007AD7C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8007AD80: nop

    // 0x8007AD84: bc1f        L_8007AEC8
    if (!c1cs) {
        // 0x8007AD88: swc1        $f2, 0x10($s0)
        MEM_W(0X10, ctx->r16) = ctx->f2.u32l;
            goto L_8007AEC8;
    }
    // 0x8007AD88: swc1        $f2, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f2.u32l;
    // 0x8007AD8C: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8007AD90: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8007AD94: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8007AD98: jal         0x8001CC3C
    // 0x8007AD9C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_8001CC3C(rdram, ctx);
        goto after_0;
    // 0x8007AD9C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_0:
    // 0x8007ADA0: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8007ADA4: c.eq.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl == ctx->f22.fl;
    // 0x8007ADA8: nop

    // 0x8007ADAC: bc1t        L_8007ADC4
    if (c1cs) {
        // 0x8007ADB0: nop
    
            goto L_8007ADC4;
    }
    // 0x8007ADB0: nop

    // 0x8007ADB4: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8007ADB8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8007ADBC: jal         0x8001CCCC
    // 0x8007ADC0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_8001CCCC(rdram, ctx);
        goto after_1;
    // 0x8007ADC0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_1:
L_8007ADC4:
    // 0x8007ADC4: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8007ADC8: c.eq.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl == ctx->f22.fl;
    // 0x8007ADCC: nop

    // 0x8007ADD0: bc1t        L_8007ADE8
    if (c1cs) {
        // 0x8007ADD4: nop
    
            goto L_8007ADE8;
    }
    // 0x8007ADD4: nop

    // 0x8007ADD8: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8007ADDC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8007ADE0: jal         0x8001CDFC
    // 0x8007ADE4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_8001CDFC(rdram, ctx);
        goto after_2;
    // 0x8007ADE4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_2:
L_8007ADE8:
    // 0x8007ADE8: lh          $v0, -0x8($s0)
    ctx->r2 = MEM_H(ctx->r16, -0X8);
    // 0x8007ADEC: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8007ADF0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8007ADF4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007ADF8: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x8007ADFC: lh          $v0, -0x6($s0)
    ctx->r2 = MEM_H(ctx->r16, -0X6);
    // 0x8007AE00: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x8007AE04: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8007AE08: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007AE0C: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x8007AE10: lh          $v0, -0x4($s0)
    ctx->r2 = MEM_H(ctx->r16, -0X4);
    // 0x8007AE14: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x8007AE18: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8007AE1C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007AE20: jal         0x800194A4
    // 0x8007AE24: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    func_800194A4(rdram, ctx);
        goto after_3;
    // 0x8007AE24: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x8007AE28: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8007AE2C: mul.s       $f4, $f6, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8007AE30: lwc1        $f2, 0x54($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8007AE34: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8007AE38: lwc1        $f0, 0x58($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8007AE3C: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8007AE40: add.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8007AE44: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8007AE48: sqrt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = sqrtf(ctx->f4.fl);
    // 0x8007AE4C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007AE50: lwc1        $f0, -0x2AF0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2AF0);
    // 0x8007AE54: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8007AE58: c.lt.s      $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f22.fl < ctx->f2.fl;
    // 0x8007AE5C: nop

    // 0x8007AE60: bc1f        L_8007AEA0
    if (!c1cs) {
        // 0x8007AE64: nop
    
            goto L_8007AEA0;
    }
    // 0x8007AE64: nop

    // 0x8007AE68: div.s       $f0, $f6, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8007AE6C: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007AE70: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8007AE74: sh          $v0, -0x8($s0)
    MEM_H(-0X8, ctx->r16) = ctx->r2;
    // 0x8007AE78: lwc1        $f0, 0x54($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8007AE7C: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007AE80: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007AE84: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8007AE88: sh          $v0, -0x6($s0)
    MEM_H(-0X6, ctx->r16) = ctx->r2;
    // 0x8007AE8C: lwc1        $f0, 0x58($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8007AE90: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007AE94: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007AE98: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8007AE9C: sh          $v0, -0x4($s0)
    MEM_H(-0X4, ctx->r16) = ctx->r2;
L_8007AEA0:
    // 0x8007AEA0: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8007AEA4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007AEA8: lwc1        $f12, -0x2AEC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2AEC);
    // 0x8007AEAC: mul.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8007AEB0: jal         0x80033960
    // 0x8007AEB4: nop

    sinf_recomp(rdram, ctx);
        goto after_4;
    // 0x8007AEB4: nop

    after_4:
    // 0x8007AEB8: lwc1        $f2, 0x18($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8007AEBC: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8007AEC0: j           L_8007AECC
    // 0x8007AEC4: swc1        $f2, -0x10($s0)
    MEM_W(-0X10, ctx->r16) = ctx->f2.u32l;
        goto L_8007AECC;
    // 0x8007AEC4: swc1        $f2, -0x10($s0)
    MEM_W(-0X10, ctx->r16) = ctx->f2.u32l;
L_8007AEC8:
    // 0x8007AEC8: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
L_8007AECC:
    // 0x8007AECC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8007AED0:
    // 0x8007AED0: slti        $v0, $s1, 0x4
    ctx->r2 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x8007AED4: bne         $v0, $zero, L_8007AD58
    if (ctx->r2 != 0) {
        // 0x8007AED8: addiu       $s0, $s0, 0x3C
        ctx->r16 = ADD32(ctx->r16, 0X3C);
            goto L_8007AD58;
    }
    // 0x8007AED8: addiu       $s0, $s0, 0x3C
    ctx->r16 = ADD32(ctx->r16, 0X3C);
    // 0x8007AEDC: lw          $ra, 0x68($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X68);
    // 0x8007AEE0: lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X64);
    // 0x8007AEE4: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x8007AEE8: ldc1        $f22, 0x78($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X78);
    // 0x8007AEEC: ldc1        $f20, 0x70($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X70);
    // 0x8007AEF0: jr          $ra
    // 0x8007AEF4: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8007AEF4: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void func_8007AEF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007AEF8: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x8007AEFC: sw          $s4, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r20;
    // 0x8007AF00: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x8007AF04: sw          $s0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r16;
    // 0x8007AF08: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8007AF0C: addiu       $v1, $a1, -0x1
    ctx->r3 = ADD32(ctx->r5, -0X1);
    // 0x8007AF10: sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x8007AF14: sw          $ra, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r31;
    // 0x8007AF18: sw          $s3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r19;
    // 0x8007AF1C: sw          $s2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r18;
    // 0x8007AF20: sw          $s1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r17;
    // 0x8007AF24: sdc1        $f22, 0xB8($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0XB8, ctx->r29);
    // 0x8007AF28: sdc1        $f20, 0xB0($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XB0, ctx->r29);
    // 0x8007AF2C: lw          $s3, 0x4($s4)
    ctx->r19 = MEM_W(ctx->r20, 0X4);
    // 0x8007AF30: beq         $v0, $zero, L_8007BBEC
    if (ctx->r2 == 0) {
        // 0x8007AF34: addu        $s0, $a2, $zero
        ctx->r16 = ADD32(ctx->r6, 0);
            goto L_8007BBEC;
    }
    // 0x8007AF34: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x8007AF38: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8007AF3C: addiu       $v0, $v0, -0x2AE0
    ctx->r2 = ADD32(ctx->r2, -0X2AE0);
    // 0x8007AF40: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8007AF44: addu        $v1, $v1, $v0
    gpr jr_addend_8007AF4C = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8007AF48: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x8007AF4C: jr          $v0
    // 0x8007AF50: nop

    switch (jr_addend_8007AF4C >> 2) {
        case 0: goto L_8007AF60; break;
        case 1: goto L_8007B238; break;
        case 2: goto L_8007B27C; break;
        case 3: goto L_8007B8CC; break;
        case 4: goto L_8007B930; break;
        default: switch_error(__func__, 0x8007AF4C, 0x8003D520);
    }
    // 0x8007AF50: nop

L_8007AF54:
    // 0x8007AF54: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8007AF58: j           L_8007B050
    // 0x8007AF5C: addu        $s1, $s0, $v0
    ctx->r17 = ADD32(ctx->r16, ctx->r2);
        goto L_8007B050;
    // 0x8007AF5C: addu        $s1, $s0, $v0
    ctx->r17 = ADD32(ctx->r16, ctx->r2);
L_8007AF60:
    // 0x8007AF60: addu        $s2, $s0, $zero
    ctx->r18 = ADD32(ctx->r16, 0);
    // 0x8007AF64: addiu       $a0, $zero, 0x180
    ctx->r4 = ADD32(0, 0X180);
    // 0x8007AF68: jal         0x80001ACC
    // 0x8007AF6C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x8007AF6C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x8007AF70: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8007AF74: addiu       $v0, $s3, 0x8
    ctx->r2 = ADD32(ctx->r19, 0X8);
    // 0x8007AF78: sw          $s3, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r19;
    // 0x8007AF7C: sw          $v0, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r2;
    // 0x8007AF80: sw          $s2, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r18;
    // 0x8007AF84: lwc1        $f0, 0x10($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8007AF88: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007AF8C: lwc1        $f22, -0x2ACC($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X2ACC);
    // 0x8007AF90: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8007AF94: swc1        $f0, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f0.u32l;
    // 0x8007AF98: lwc1        $f0, 0x14($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8007AF9C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8007AFA0: swc1        $f0, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->f0.u32l;
    // 0x8007AFA4: lwc1        $f0, 0x18($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X18);
    // 0x8007AFA8: addiu       $a0, $a0, -0x2AE8
    ctx->r4 = ADD32(ctx->r4, -0X2AE8);
    // 0x8007AFAC: swc1        $f20, 0x20($s3)
    MEM_W(0X20, ctx->r19) = ctx->f20.u32l;
    // 0x8007AFB0: swc1        $f22, 0x24($s3)
    MEM_W(0X24, ctx->r19) = ctx->f22.u32l;
    // 0x8007AFB4: swc1        $f20, 0x28($s3)
    MEM_W(0X28, ctx->r19) = ctx->f20.u32l;
    // 0x8007AFB8: swc1        $f20, 0x14($s3)
    MEM_W(0X14, ctx->r19) = ctx->f20.u32l;
    // 0x8007AFBC: swc1        $f20, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->f20.u32l;
    // 0x8007AFC0: swc1        $f22, 0x1C($s3)
    MEM_W(0X1C, ctx->r19) = ctx->f22.u32l;
    // 0x8007AFC4: swc1        $f20, 0x34($s3)
    MEM_W(0X34, ctx->r19) = ctx->f20.u32l;
    // 0x8007AFC8: swc1        $f20, 0x30($s3)
    MEM_W(0X30, ctx->r19) = ctx->f20.u32l;
    // 0x8007AFCC: swc1        $f20, 0x2C($s3)
    MEM_W(0X2C, ctx->r19) = ctx->f20.u32l;
    // 0x8007AFD0: sh          $zero, 0x17A($s3)
    MEM_H(0X17A, ctx->r19) = 0;
    // 0x8007AFD4: sb          $zero, 0x17C($s3)
    MEM_B(0X17C, ctx->r19) = 0;
    // 0x8007AFD8: jal         0x80056EB0
    // 0x8007AFDC: swc1        $f0, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f0.u32l;
    walkMeshdef0List(rdram, ctx);
        goto after_1;
    // 0x8007AFDC: swc1        $f0, 0x10($s3)
    MEM_W(0X10, ctx->r19) = ctx->f0.u32l;
    after_1:
    // 0x8007AFE0: addiu       $s0, $s3, 0x38
    ctx->r16 = ADD32(ctx->r19, 0X38);
    // 0x8007AFE4: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x8007AFE8: sw          $v0, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->r2;
    // 0x8007AFEC: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    // 0x8007AFF0: jal         0x8007A870
    // 0x8007AFF4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_8007A870(rdram, ctx);
        goto after_2;
    // 0x8007AFF4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x8007AFF8: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8007AFFC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8007B000: sw          $zero, 0x58($v0)
    MEM_W(0X58, ctx->r2) = 0;
    // 0x8007B004: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8007B008: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8007B00C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8007B010: swc1        $f22, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f22.u32l;
    // 0x8007B014: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8007B018: addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
    // 0x8007B01C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8007B020: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // 0x8007B024: swc1        $f20, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f20.u32l;
    // 0x8007B028: swc1        $f20, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f20.u32l;
    // 0x8007B02C: swc1        $f20, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f20.u32l;
L_8007B030:
    // 0x8007B030: lhu         $v0, 0x28($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X28);
    // 0x8007B034: beq         $v0, $zero, L_8007AF54
    if (ctx->r2 == 0) {
        // 0x8007B038: addiu       $v1, $v1, 0x3C
        ctx->r3 = ADD32(ctx->r3, 0X3C);
            goto L_8007AF54;
    }
    // 0x8007B038: addiu       $v1, $v1, 0x3C
    ctx->r3 = ADD32(ctx->r3, 0X3C);
    // 0x8007B03C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8007B040: slti        $v0, $a1, 0x4
    ctx->r2 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x8007B044: bne         $v0, $zero, L_8007B030
    if (ctx->r2 != 0) {
        // 0x8007B048: addiu       $a0, $a0, 0x3C
        ctx->r4 = ADD32(ctx->r4, 0X3C);
            goto L_8007B030;
    }
    // 0x8007B048: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    // 0x8007B04C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_8007B050:
    // 0x8007B050: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8007B054: lw          $s0, -0x5690($v0)
    ctx->r16 = MEM_W(ctx->r2, -0X5690);
    // 0x8007B058: jal         0x80003430
    // 0x8007B05C: nop

    rand_recomp(rdram, ctx);
        goto after_3;
    // 0x8007B05C: nop

    after_3:
    // 0x8007B060: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8007B064: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8007B068: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8007B06C: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8007B070: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8007B074: jal         0x8001CD6C
    // 0x8007B078: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_8001CD6C(rdram, ctx);
        goto after_4;
    // 0x8007B078: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_4:
    // 0x8007B07C: jal         0x80003430
    // 0x8007B080: nop

    rand_recomp(rdram, ctx);
        goto after_5;
    // 0x8007B080: nop

    after_5:
    // 0x8007B084: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007B088: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007B08C: lwc1        $f2, -0x2AC8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2AC8);
    // 0x8007B090: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007B094: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007B098: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8007B09C: sh          $v0, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r2;
    // 0x8007B0A0: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8007B0A4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007B0A8: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007B0AC: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8007B0B0: sh          $v0, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r2;
    // 0x8007B0B4: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8007B0B8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007B0BC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007B0C0: lwc1        $f4, -0x2AC4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2AC4);
    // 0x8007B0C4: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007B0C8: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8007B0CC: sh          $v0, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r2;
    // 0x8007B0D0: lbu         $v0, 0x18($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X18);
    // 0x8007B0D4: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x8007B0D8: sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
    // 0x8007B0DC: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    // 0x8007B0E0: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
    // 0x8007B0E4: lbu         $v0, 0x2($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2);
    // 0x8007B0E8: sb          $zero, 0x3($s1)
    MEM_B(0X3, ctx->r17) = 0;
    // 0x8007B0EC: sb          $v0, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r2;
    // 0x8007B0F0: lbu         $v0, 0x4($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X4);
    // 0x8007B0F4: lbu         $v1, 0x18($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X18);
    // 0x8007B0F8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007B0FC: lwc1        $f6, -0x2AC0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2AC0);
    // 0x8007B100: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8007B104: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8007B108: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007B10C: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
    // 0x8007B110: lbu         $v0, 0x5($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X5);
    // 0x8007B114: lbu         $v1, 0x1($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X1);
    // 0x8007B118: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007B11C: lwc1        $f2, -0x2ABC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2ABC);
    // 0x8007B120: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8007B124: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8007B128: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007B12C: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
    // 0x8007B130: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007B134: lwc1        $f0, -0x2AB8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2AB8);
    // 0x8007B138: lbu         $v1, 0x6($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X6);
    // 0x8007B13C: lbu         $a0, 0x2($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X2);
    // 0x8007B140: sw          $zero, 0x14($s1)
    MEM_W(0X14, ctx->r17) = 0;
    // 0x8007B144: swc1        $f2, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f2.u32l;
    // 0x8007B148: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007B14C: lwc1        $f2, -0x2AB4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2AB4);
    // 0x8007B150: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007B154: sh          $v0, 0x20($s1)
    MEM_H(0X20, ctx->r17) = ctx->r2;
    // 0x8007B158: swc1        $f0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f0.u32l;
    // 0x8007B15C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007B160: lwc1        $f0, -0x2AB0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2AB0);
    // 0x8007B164: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x8007B168: swc1        $f0, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f0.u32l;
    // 0x8007B16C: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x8007B170: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007B174: swc1        $f0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f0.u32l;
    // 0x8007B178: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8007B17C: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    // 0x8007B180: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    // 0x8007B184: sw          $zero, 0x28($s1)
    MEM_W(0X28, ctx->r17) = 0;
    // 0x8007B188: sw          $zero, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = 0;
    // 0x8007B18C: sw          $zero, 0x30($s1)
    MEM_W(0X30, ctx->r17) = 0;
    // 0x8007B190: swc1        $f4, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f4.u32l;
    // 0x8007B194: sh          $v0, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r2;
    // 0x8007B198: sh          $zero, 0x1C($s1)
    MEM_H(0X1C, ctx->r17) = 0;
    // 0x8007B19C: lhu         $v0, 0x20($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X20);
    // 0x8007B1A0: sh          $zero, 0x1A($s1)
    MEM_H(0X1A, ctx->r17) = 0;
    // 0x8007B1A4: swc1        $f2, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f2.u32l;
    // 0x8007B1A8: swc1        $f6, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f6.u32l;
    // 0x8007B1AC: ori         $v0, $v0, 0x4
    ctx->r2 = ctx->r2 | 0X4;
    // 0x8007B1B0: swc1        $f0, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f0.u32l;
    // 0x8007B1B4: swc1        $f0, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f0.u32l;
    // 0x8007B1B8: swc1        $f0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f0.u32l;
    // 0x8007B1BC: sh          $v0, 0x20($s1)
    MEM_H(0X20, ctx->r17) = ctx->r2;
    // 0x8007B1C0: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8007B1C4: swc1        $f0, 0x130($s3)
    MEM_W(0X130, ctx->r19) = ctx->f0.u32l;
    // 0x8007B1C8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8007B1CC: lwc1        $f0, 0x34($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X34);
    // 0x8007B1D0: lwc1        $f2, 0x28($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X28);
    // 0x8007B1D4: div.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8007B1D8: mul.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8007B1DC: lw          $v1, 0x4($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X4);
    // 0x8007B1E0: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8007B1E4: swc1        $f4, 0x13C($s3)
    MEM_W(0X13C, ctx->r19) = ctx->f4.u32l;
    // 0x8007B1E8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8007B1EC: lwc1        $f0, 0x28($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X28);
    // 0x8007B1F0: lwc1        $f2, 0x44($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8007B1F4: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8007B1F8: addiu       $a1, $s3, 0x8
    ctx->r5 = ADD32(ctx->r19, 0X8);
    // 0x8007B1FC: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8007B200: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8007B204: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // 0x8007B208: jal         0x80059B50
    // 0x8007B20C: swc1        $f2, 0x138($s3)
    MEM_W(0X138, ctx->r19) = ctx->f2.u32l;
    func_80059B50(rdram, ctx);
        goto after_6;
    // 0x8007B20C: swc1        $f2, 0x138($s3)
    MEM_W(0X138, ctx->r19) = ctx->f2.u32l;
    after_6:
    // 0x8007B210: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x8007B214: addiu       $s0, $s0, -0x6AA0
    ctx->r16 = ADD32(ctx->r16, -0X6AA0);
    // 0x8007B218: lhu         $a0, 0xC($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0XC);
    // 0x8007B21C: jal         0x8003E684
    // 0x8007B220: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_8003E684(rdram, ctx);
        goto after_7;
    // 0x8007B220: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_7:
    // 0x8007B224: lhu         $a0, 0x1C($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X1C);
    // 0x8007B228: jal         0x8003E684
    // 0x8007B22C: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_8003E684(rdram, ctx);
        goto after_8;
    // 0x8007B22C: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_8:
    // 0x8007B230: j           L_8007BBF0
    // 0x8007B234: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8007BBF0;
    // 0x8007B234: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007B238:
    // 0x8007B238: lw          $a0, 0x38($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X38);
    // 0x8007B23C: jal         0x80001C98
    // 0x8007B240: nop

    rs_free(rdram, ctx);
        goto after_9;
    // 0x8007B240: nop

    after_9:
    // 0x8007B244: lw          $v0, 0x4($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X4);
    // 0x8007B248: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // 0x8007B24C: sh          $v1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r3;
    // 0x8007B250: lbu         $v0, 0x17C($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X17C);
    // 0x8007B254: bne         $v0, $zero, L_8007B268
    if (ctx->r2 != 0) {
        // 0x8007B258: nop
    
            goto L_8007B268;
    }
    // 0x8007B258: nop

    // 0x8007B25C: lw          $a0, 0x4($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X4);
    // 0x8007B260: jal         0x80046620
    // 0x8007B264: addiu       $a1, $a0, 0x10
    ctx->r5 = ADD32(ctx->r4, 0X10);
    parseDatItemCommon(rdram, ctx);
        goto after_10;
    // 0x8007B264: addiu       $a1, $a0, 0x10
    ctx->r5 = ADD32(ctx->r4, 0X10);
    after_10:
L_8007B268:
    // 0x8007B268: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x8007B26C: jal         0x8005779C
    // 0x8007B270: nop

    func_8005779C(rdram, ctx);
        goto after_11;
    // 0x8007B270: nop

    after_11:
    // 0x8007B274: j           L_8007BBF0
    // 0x8007B278: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8007BBF0;
    // 0x8007B278: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007B27C:
    // 0x8007B27C: lbu         $v1, 0x17C($s3)
    ctx->r3 = MEM_BU(ctx->r19, 0X17C);
    // 0x8007B280: lwc1        $f20, 0x0($s0)
    ctx->f20.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8007B284: bne         $v1, $zero, L_8007B5E4
    if (ctx->r3 != 0) {
        // 0x8007B288: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8007B5E4;
    }
    // 0x8007B288: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007B28C: lw          $v0, 0x4($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X4);
    // 0x8007B290: lw          $v0, 0x6C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6C);
    // 0x8007B294: beq         $v0, $zero, L_8007B2E4
    if (ctx->r2 == 0) {
        // 0x8007B298: nop
    
            goto L_8007B2E4;
    }
    // 0x8007B298: nop

    // 0x8007B29C: jal         0x80047D40
    // 0x8007B2A0: addiu       $a0, $s3, 0x8
    ctx->r4 = ADD32(ctx->r19, 0X8);
    func_80047D40(rdram, ctx);
        goto after_12;
    // 0x8007B2A0: addiu       $a0, $s3, 0x8
    ctx->r4 = ADD32(ctx->r19, 0X8);
    after_12:
    // 0x8007B2A4: bnel        $v0, $zero, L_8007B2E4
    if (ctx->r2 != 0) {
        // 0x8007B2A8: sh          $zero, 0x17A($s3)
        MEM_H(0X17A, ctx->r19) = 0;
            goto L_8007B2E4;
    }
    goto skip_0;
    // 0x8007B2A8: sh          $zero, 0x17A($s3)
    MEM_H(0X17A, ctx->r19) = 0;
    skip_0:
    // 0x8007B2AC: lhu         $v0, 0x17A($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X17A);
    // 0x8007B2B0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8007B2B4: sh          $v0, 0x17A($s3)
    MEM_H(0X17A, ctx->r19) = ctx->r2;
    // 0x8007B2B8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8007B2BC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8007B2C0: slti        $v0, $v0, 0x15
    ctx->r2 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x8007B2C4: bne         $v0, $zero, L_8007B2E4
    if (ctx->r2 != 0) {
        // 0x8007B2C8: nop
    
            goto L_8007B2E4;
    }
    // 0x8007B2C8: nop

    // 0x8007B2CC: lhu         $a0, 0x16($s4)
    ctx->r4 = MEM_HU(ctx->r20, 0X16);
    // 0x8007B2D0: j           L_8007BBE4
    // 0x8007B2D4: nop

        goto L_8007BBE4;
    // 0x8007B2D4: nop

L_8007B2D8:
    // 0x8007B2D8: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8007B2DC: j           L_8007B390
    // 0x8007B2E0: addu        $s1, $s0, $v0
    ctx->r17 = ADD32(ctx->r16, ctx->r2);
        goto L_8007B390;
    // 0x8007B2E0: addu        $s1, $s0, $v0
    ctx->r17 = ADD32(ctx->r16, ctx->r2);
L_8007B2E4:
    // 0x8007B2E4: lw          $s2, 0x4($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X4);
    // 0x8007B2E8: lw          $v1, 0x7C($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X7C);
    // 0x8007B2EC: beq         $v1, $zero, L_8007B310
    if (ctx->r3 == 0) {
        // 0x8007B2F0: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_8007B310;
    }
    // 0x8007B2F0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8007B2F4: addiu       $v0, $v0, -0x7760
    ctx->r2 = ADD32(ctx->r2, -0X7760);
    // 0x8007B2F8: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x8007B2FC: lbu         $v1, -0x1($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X1);
    // 0x8007B300: lw          $v0, 0x80($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X80);
    // 0x8007B304: bne         $v1, $v0, L_8007B310
    if (ctx->r3 != ctx->r2) {
        // 0x8007B308: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8007B310;
    }
    // 0x8007B308: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007B30C: sb          $v0, 0x17C($s3)
    MEM_B(0X17C, ctx->r19) = ctx->r2;
L_8007B310:
    // 0x8007B310: lw          $v0, 0x74($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X74);
    // 0x8007B314: beq         $v0, $zero, L_8007B344
    if (ctx->r2 == 0) {
        // 0x8007B318: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_8007B344;
    }
    // 0x8007B318: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8007B31C: addiu       $v1, $v1, -0x7FA0
    ctx->r3 = ADD32(ctx->r3, -0X7FA0);
    // 0x8007B320: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8007B324: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8007B328: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8007B32C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8007B330: lw          $v1, 0x78($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X78);
    // 0x8007B334: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007B338: bne         $v0, $zero, L_8007B344
    if (ctx->r2 != 0) {
        // 0x8007B33C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8007B344;
    }
    // 0x8007B33C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007B340: sb          $v0, 0x17C($s3)
    MEM_B(0X17C, ctx->r19) = ctx->r2;
L_8007B344:
    // 0x8007B344: lwc1        $f0, 0x130($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X130);
    // 0x8007B348: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x8007B34C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8007B350: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8007B354: nop

    // 0x8007B358: bc1f        L_8007B8B8
    if (!c1cs) {
        // 0x8007B35C: swc1        $f0, 0x130($s3)
        MEM_W(0X130, ctx->r19) = ctx->f0.u32l;
            goto L_8007B8B8;
    }
    // 0x8007B35C: swc1        $f0, 0x130($s3)
    MEM_W(0X130, ctx->r19) = ctx->f0.u32l;
    // 0x8007B360: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8007B364: addiu       $s0, $s3, 0x38
    ctx->r16 = ADD32(ctx->r19, 0X38);
    // 0x8007B368: addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
    // 0x8007B36C: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
L_8007B370:
    // 0x8007B370: lhu         $v0, 0x28($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X28);
    // 0x8007B374: beq         $v0, $zero, L_8007B2D8
    if (ctx->r2 == 0) {
        // 0x8007B378: addiu       $v1, $v1, 0x3C
        ctx->r3 = ADD32(ctx->r3, 0X3C);
            goto L_8007B2D8;
    }
    // 0x8007B378: addiu       $v1, $v1, 0x3C
    ctx->r3 = ADD32(ctx->r3, 0X3C);
    // 0x8007B37C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8007B380: slti        $v0, $a1, 0x4
    ctx->r2 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x8007B384: bne         $v0, $zero, L_8007B370
    if (ctx->r2 != 0) {
        // 0x8007B388: addiu       $a0, $a0, 0x3C
        ctx->r4 = ADD32(ctx->r4, 0X3C);
            goto L_8007B370;
    }
    // 0x8007B388: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    // 0x8007B38C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_8007B390:
    // 0x8007B390: beq         $s1, $zero, L_8007B8B8
    if (ctx->r17 == 0) {
        // 0x8007B394: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_8007B8B8;
    }
    // 0x8007B394: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8007B398: lw          $s0, -0x5690($v0)
    ctx->r16 = MEM_W(ctx->r2, -0X5690);
    // 0x8007B39C: jal         0x80003430
    // 0x8007B3A0: nop

    rand_recomp(rdram, ctx);
        goto after_13;
    // 0x8007B3A0: nop

    after_13:
    // 0x8007B3A4: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8007B3A8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8007B3AC: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8007B3B0: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8007B3B4: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8007B3B8: jal         0x8001CD6C
    // 0x8007B3BC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_8001CD6C(rdram, ctx);
        goto after_14;
    // 0x8007B3BC: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_14:
    // 0x8007B3C0: jal         0x80003430
    // 0x8007B3C4: nop

    rand_recomp(rdram, ctx);
        goto after_15;
    // 0x8007B3C4: nop

    after_15:
    // 0x8007B3C8: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x8007B3CC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8007B3D0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8007B3D4: div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // 0x8007B3D8: bne         $v1, $zero, L_8007B3E4
    if (ctx->r3 != 0) {
        // 0x8007B3DC: nop
    
            goto L_8007B3E4;
    }
    // 0x8007B3DC: nop

    // 0x8007B3E0: break       7
    do_break(2147988448);
L_8007B3E4:
    // 0x8007B3E4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007B3E8: bne         $v1, $at, L_8007B3FC
    if (ctx->r3 != ctx->r1) {
        // 0x8007B3EC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007B3FC;
    }
    // 0x8007B3EC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007B3F0: bne         $v0, $at, L_8007B3FC
    if (ctx->r2 != ctx->r1) {
        // 0x8007B3F4: nop
    
            goto L_8007B3FC;
    }
    // 0x8007B3F4: nop

    // 0x8007B3F8: break       6
    do_break(2147988472);
L_8007B3FC:
    // 0x8007B3FC: mfhi        $v1
    ctx->r3 = hi;
    // 0x8007B400: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007B404: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007B408: lwc1        $f2, -0x2AAC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2AAC);
    // 0x8007B40C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007B410: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007B414: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8007B418: sh          $v0, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r2;
    // 0x8007B41C: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8007B420: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007B424: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007B428: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8007B42C: sh          $v0, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r2;
    // 0x8007B430: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8007B434: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007B438: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007B43C: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8007B440: sh          $v0, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r2;
    // 0x8007B444: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x8007B448: addu        $s0, $s0, $v1
    ctx->r16 = ADD32(ctx->r16, ctx->r3);
    // 0x8007B44C: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x8007B450: sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
    // 0x8007B454: lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1);
    // 0x8007B458: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
    // 0x8007B45C: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x8007B460: sb          $zero, 0x3($s1)
    MEM_B(0X3, ctx->r17) = 0;
    // 0x8007B464: sb          $v0, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r2;
    // 0x8007B468: lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4);
    // 0x8007B46C: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x8007B470: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007B474: lwc1        $f4, -0x2AA8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2AA8);
    // 0x8007B478: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8007B47C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8007B480: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007B484: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
    // 0x8007B488: lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X5);
    // 0x8007B48C: lbu         $v1, 0x1($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X1);
    // 0x8007B490: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007B494: lwc1        $f2, -0x2AA4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2AA4);
    // 0x8007B498: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8007B49C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8007B4A0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007B4A4: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
    // 0x8007B4A8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007B4AC: lwc1        $f0, -0x2AA0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2AA0);
    // 0x8007B4B0: lbu         $v1, 0x6($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X6);
    // 0x8007B4B4: lbu         $a0, 0x2($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X2);
    // 0x8007B4B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007B4BC: sw          $zero, 0x14($s1)
    MEM_W(0X14, ctx->r17) = 0;
    // 0x8007B4C0: sh          $v0, 0x20($s1)
    MEM_H(0X20, ctx->r17) = ctx->r2;
    // 0x8007B4C4: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    // 0x8007B4C8: sw          $zero, 0x28($s1)
    MEM_W(0X28, ctx->r17) = 0;
    // 0x8007B4CC: sw          $zero, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = 0;
    // 0x8007B4D0: sw          $zero, 0x30($s1)
    MEM_W(0X30, ctx->r17) = 0;
    // 0x8007B4D4: swc1        $f2, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f2.u32l;
    // 0x8007B4D8: swc1        $f4, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f4.u32l;
    // 0x8007B4DC: swc1        $f0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f0.u32l;
    // 0x8007B4E0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007B4E4: lwc1        $f0, -0x2A9C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2A9C);
    // 0x8007B4E8: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x8007B4EC: swc1        $f0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f0.u32l;
    // 0x8007B4F0: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x8007B4F4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007B4F8: jal         0x80003430
    // 0x8007B4FC: swc1        $f0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f0.u32l;
    rand_recomp(rdram, ctx);
        goto after_16;
    // 0x8007B4FC: swc1        $f0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f0.u32l;
    after_16:
    // 0x8007B500: lui         $v1, 0xB60B
    ctx->r3 = S32(0XB60B << 16);
    // 0x8007B504: ori         $v1, $v1, 0x60B7
    ctx->r3 = ctx->r3 | 0X60B7;
    // 0x8007B508: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8007B50C: sra         $a1, $v0, 16
    ctx->r5 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8007B510: mult        $a1, $v1
    result = S64(S32(ctx->r5)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007B514: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x8007B518: mfhi        $v1
    ctx->r3 = hi;
    // 0x8007B51C: addu        $a0, $v1, $a1
    ctx->r4 = ADD32(ctx->r3, ctx->r5);
    // 0x8007B520: sra         $a0, $a0, 8
    ctx->r4 = S32(SIGNED(ctx->r4) >> 8);
    // 0x8007B524: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x8007B528: sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4 << 1);
    // 0x8007B52C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8007B530: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x8007B534: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8007B538: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8007B53C: subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    // 0x8007B540: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8007B544: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8007B548: addiu       $v0, $zero, 0xB4
    ctx->r2 = ADD32(0, 0XB4);
    // 0x8007B54C: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x8007B550: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x8007B554: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8007B558: swc1        $f2, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f2.u32l;
    // 0x8007B55C: abs.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = fabsf(ctx->f2.fl);
    // 0x8007B560: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007B564: lwc1        $f4, -0x2A98($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2A98);
    // 0x8007B568: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8007B56C: nop

    // 0x8007B570: bc1f        L_8007B59C
    if (!c1cs) {
        // 0x8007B574: nop
    
            goto L_8007B59C;
    }
    // 0x8007B574: nop

    // 0x8007B578: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8007B57C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8007B580: nop

    // 0x8007B584: bc1fl       L_8007B598
    if (!c1cs) {
        // 0x8007B588: add.s       $f0, $f2, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f4.fl;
            goto L_8007B598;
    }
    goto skip_1;
    // 0x8007B588: add.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f4.fl;
    skip_1:
    // 0x8007B58C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007B590: lwc1        $f0, -0x2A94($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2A94);
    // 0x8007B594: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
L_8007B598:
    // 0x8007B598: swc1        $f0, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f0.u32l;
L_8007B59C:
    // 0x8007B59C: lhu         $v0, 0x20($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X20);
    // 0x8007B5A0: ori         $v0, $v0, 0x2
    ctx->r2 = ctx->r2 | 0X2;
    // 0x8007B5A4: jal         0x80003430
    // 0x8007B5A8: sh          $v0, 0x20($s1)
    MEM_H(0X20, ctx->r17) = ctx->r2;
    rand_recomp(rdram, ctx);
        goto after_17;
    // 0x8007B5A8: sh          $v0, 0x20($s1)
    MEM_H(0X20, ctx->r17) = ctx->r2;
    after_17:
    // 0x8007B5AC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8007B5B0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8007B5B4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007B5B8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007B5BC: lwc1        $f2, -0x2A90($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2A90);
    // 0x8007B5C0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007B5C4: lwc1        $f4, -0x2A8C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2A8C);
    // 0x8007B5C8: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007B5CC: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8007B5D0: j           L_8007B8B8
    // 0x8007B5D4: swc1        $f0, 0x130($s3)
    MEM_W(0X130, ctx->r19) = ctx->f0.u32l;
        goto L_8007B8B8;
    // 0x8007B5D4: swc1        $f0, 0x130($s3)
    MEM_W(0X130, ctx->r19) = ctx->f0.u32l;
L_8007B5D8:
    // 0x8007B5D8: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8007B5DC: j           L_8007B660
    // 0x8007B5E0: addu        $s1, $s0, $v0
    ctx->r17 = ADD32(ctx->r16, ctx->r2);
        goto L_8007B660;
    // 0x8007B5E0: addu        $s1, $s0, $v0
    ctx->r17 = ADD32(ctx->r16, ctx->r2);
L_8007B5E4:
    // 0x8007B5E4: bne         $v1, $v0, L_8007B7E8
    if (ctx->r3 != ctx->r2) {
        // 0x8007B5E8: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_8007B7E8;
    }
    // 0x8007B5E8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8007B5EC: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x8007B5F0: addu        $v1, $s3, $zero
    ctx->r3 = ADD32(ctx->r19, 0);
    // 0x8007B5F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8007B5F8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007B5FC: lwc1        $f2, -0x2A88($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2A88);
L_8007B600:
    // 0x8007B600: lhu         $v0, 0x60($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X60);
    // 0x8007B604: beql        $v0, $zero, L_8007B624
    if (ctx->r2 == 0) {
        // 0x8007B608: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8007B624;
    }
    goto skip_2;
    // 0x8007B608: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_2:
    // 0x8007B60C: lwc1        $f0, 0x74($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X74);
    // 0x8007B610: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x8007B614: nop

    // 0x8007B618: bc1tl       L_8007B620
    if (c1cs) {
        // 0x8007B61C: swc1        $f2, 0x74($v1)
        MEM_W(0X74, ctx->r3) = ctx->f2.u32l;
            goto L_8007B620;
    }
    goto skip_3;
    // 0x8007B61C: swc1        $f2, 0x74($v1)
    MEM_W(0X74, ctx->r3) = ctx->f2.u32l;
    skip_3:
L_8007B620:
    // 0x8007B620: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8007B624:
    // 0x8007B624: slti        $v0, $s2, 0x4
    ctx->r2 = SIGNED(ctx->r18) < 0X4 ? 1 : 0;
    // 0x8007B628: bne         $v0, $zero, L_8007B600
    if (ctx->r2 != 0) {
        // 0x8007B62C: addiu       $v1, $v1, 0x3C
        ctx->r3 = ADD32(ctx->r3, 0X3C);
            goto L_8007B600;
    }
    // 0x8007B62C: addiu       $v1, $v1, 0x3C
    ctx->r3 = ADD32(ctx->r3, 0X3C);
    // 0x8007B630: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8007B634: addiu       $s0, $s3, 0x38
    ctx->r16 = ADD32(ctx->r19, 0X38);
    // 0x8007B638: addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
    // 0x8007B63C: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
L_8007B640:
    // 0x8007B640: lhu         $v0, 0x28($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X28);
    // 0x8007B644: beq         $v0, $zero, L_8007B5D8
    if (ctx->r2 == 0) {
        // 0x8007B648: addiu       $v1, $v1, 0x3C
        ctx->r3 = ADD32(ctx->r3, 0X3C);
            goto L_8007B5D8;
    }
    // 0x8007B648: addiu       $v1, $v1, 0x3C
    ctx->r3 = ADD32(ctx->r3, 0X3C);
    // 0x8007B64C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8007B650: slti        $v0, $a1, 0x4
    ctx->r2 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x8007B654: bne         $v0, $zero, L_8007B640
    if (ctx->r2 != 0) {
        // 0x8007B658: addiu       $a0, $a0, 0x3C
        ctx->r4 = ADD32(ctx->r4, 0X3C);
            goto L_8007B640;
    }
    // 0x8007B658: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    // 0x8007B65C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_8007B660:
    // 0x8007B660: beq         $s1, $zero, L_8007B8B8
    if (ctx->r17 == 0) {
        // 0x8007B664: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_8007B8B8;
    }
    // 0x8007B664: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8007B668: lw          $s0, -0x5690($v0)
    ctx->r16 = MEM_W(ctx->r2, -0X5690);
    // 0x8007B66C: jal         0x80003430
    // 0x8007B670: nop

    rand_recomp(rdram, ctx);
        goto after_18;
    // 0x8007B670: nop

    after_18:
    // 0x8007B674: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8007B678: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8007B67C: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8007B680: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8007B684: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8007B688: jal         0x8001CD6C
    // 0x8007B68C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_8001CD6C(rdram, ctx);
        goto after_19;
    // 0x8007B68C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_19:
    // 0x8007B690: jal         0x80003430
    // 0x8007B694: nop

    rand_recomp(rdram, ctx);
        goto after_20;
    // 0x8007B694: nop

    after_20:
    // 0x8007B698: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007B69C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007B6A0: lwc1        $f2, -0x2A84($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2A84);
    // 0x8007B6A4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007B6A8: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007B6AC: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8007B6B0: sh          $v0, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r2;
    // 0x8007B6B4: lwc1        $f0, 0x34($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8007B6B8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007B6BC: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007B6C0: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8007B6C4: sh          $v0, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r2;
    // 0x8007B6C8: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8007B6CC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007B6D0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007B6D4: lwc1        $f4, -0x2A80($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2A80);
    // 0x8007B6D8: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007B6DC: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8007B6E0: sh          $v0, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r2;
    // 0x8007B6E4: lbu         $v0, 0x18($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X18);
    // 0x8007B6E8: addiu       $a0, $s0, 0x18
    ctx->r4 = ADD32(ctx->r16, 0X18);
    // 0x8007B6EC: sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
    // 0x8007B6F0: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    // 0x8007B6F4: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
    // 0x8007B6F8: lbu         $v0, 0x2($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X2);
    // 0x8007B6FC: sb          $zero, 0x3($s1)
    MEM_B(0X3, ctx->r17) = 0;
    // 0x8007B700: sb          $v0, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r2;
    // 0x8007B704: lbu         $v0, 0x4($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X4);
    // 0x8007B708: lbu         $v1, 0x18($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X18);
    // 0x8007B70C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007B710: lwc1        $f6, -0x2A7C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2A7C);
    // 0x8007B714: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8007B718: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8007B71C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007B720: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
    // 0x8007B724: lbu         $v0, 0x5($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X5);
    // 0x8007B728: lbu         $v1, 0x1($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X1);
    // 0x8007B72C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007B730: lwc1        $f2, -0x2A78($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2A78);
    // 0x8007B734: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8007B738: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8007B73C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007B740: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
    // 0x8007B744: lbu         $v1, 0x6($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X6);
    // 0x8007B748: lbu         $a0, 0x2($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X2);
    // 0x8007B74C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007B750: lwc1        $f0, -0x2A74($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2A74);
    // 0x8007B754: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007B758: sh          $v0, 0x20($s1)
    MEM_H(0X20, ctx->r17) = ctx->r2;
    // 0x8007B75C: addiu       $v0, $zero, -0x100
    ctx->r2 = ADD32(0, -0X100);
    // 0x8007B760: swc1        $f4, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f4.u32l;
    // 0x8007B764: sw          $zero, 0x14($s1)
    MEM_W(0X14, ctx->r17) = 0;
    // 0x8007B768: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    // 0x8007B76C: sw          $zero, 0x28($s1)
    MEM_W(0X28, ctx->r17) = 0;
    // 0x8007B770: sw          $zero, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = 0;
    // 0x8007B774: sw          $zero, 0x30($s1)
    MEM_W(0X30, ctx->r17) = 0;
    // 0x8007B778: swc1        $f6, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f6.u32l;
    // 0x8007B77C: sh          $zero, 0x1C($s1)
    MEM_H(0X1C, ctx->r17) = 0;
    // 0x8007B780: sh          $zero, 0x18($s1)
    MEM_H(0X18, ctx->r17) = 0;
    // 0x8007B784: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x8007B788: swc1        $f0, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f0.u32l;
    // 0x8007B78C: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x8007B790: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007B794: swc1        $f0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f0.u32l;
    // 0x8007B798: sh          $v0, 0x1A($s1)
    MEM_H(0X1A, ctx->r17) = ctx->r2;
    // 0x8007B79C: lhu         $v0, 0x20($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X20);
    // 0x8007B7A0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007B7A4: lwc1        $f0, -0x2A70($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2A70);
    // 0x8007B7A8: swc1        $f4, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f4.u32l;
    // 0x8007B7AC: swc1        $f2, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f2.u32l;
    // 0x8007B7B0: sw          $zero, 0x34($s1)
    MEM_W(0X34, ctx->r17) = 0;
    // 0x8007B7B4: ori         $v0, $v0, 0x4
    ctx->r2 = ctx->r2 | 0X4;
    // 0x8007B7B8: sh          $v0, 0x20($s1)
    MEM_H(0X20, ctx->r17) = ctx->r2;
    // 0x8007B7BC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8007B7C0: swc1        $f0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f0.u32l;
    // 0x8007B7C4: swc1        $f6, 0x130($s3)
    MEM_W(0X130, ctx->r19) = ctx->f6.u32l;
    // 0x8007B7C8: j           L_8007B8B8
    // 0x8007B7CC: sb          $v0, 0x17C($s3)
    MEM_B(0X17C, ctx->r19) = ctx->r2;
        goto L_8007B8B8;
    // 0x8007B7CC: sb          $v0, 0x17C($s3)
    MEM_B(0X17C, ctx->r19) = ctx->r2;
L_8007B7D0:
    // 0x8007B7D0: lwc1        $f0, 0x130($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X130);
    // 0x8007B7D4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007B7D8: lwc1        $f2, -0x2A6C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2A6C);
    // 0x8007B7DC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007B7E0: j           L_8007B820
    // 0x8007B7E4: swc1        $f0, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->f0.u32l;
        goto L_8007B820;
    // 0x8007B7E4: swc1        $f0, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->f0.u32l;
L_8007B7E8:
    // 0x8007B7E8: bne         $v1, $v0, L_8007B868
    if (ctx->r3 != ctx->r2) {
        // 0x8007B7EC: addiu       $a0, $zero, -0x100
        ctx->r4 = ADD32(0, -0X100);
            goto L_8007B868;
    }
    // 0x8007B7EC: addiu       $a0, $zero, -0x100
    ctx->r4 = ADD32(0, -0X100);
    // 0x8007B7F0: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x8007B7F4: addu        $v1, $s3, $zero
    ctx->r3 = ADD32(ctx->r19, 0);
L_8007B7F8:
    // 0x8007B7F8: lhu         $v0, 0x60($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X60);
    // 0x8007B7FC: beql        $v0, $zero, L_8007B814
    if (ctx->r2 == 0) {
        // 0x8007B800: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8007B814;
    }
    goto skip_4;
    // 0x8007B800: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_4:
    // 0x8007B804: lh          $v0, 0x5A($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X5A);
    // 0x8007B808: beq         $v0, $a0, L_8007B7D0
    if (ctx->r2 == ctx->r4) {
        // 0x8007B80C: nop
    
            goto L_8007B7D0;
    }
    // 0x8007B80C: nop

    // 0x8007B810: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8007B814:
    // 0x8007B814: slti        $v0, $s2, 0x4
    ctx->r2 = SIGNED(ctx->r18) < 0X4 ? 1 : 0;
    // 0x8007B818: bne         $v0, $zero, L_8007B7F8
    if (ctx->r2 != 0) {
        // 0x8007B81C: addiu       $v1, $v1, 0x3C
        ctx->r3 = ADD32(ctx->r3, 0X3C);
            goto L_8007B7F8;
    }
    // 0x8007B81C: addiu       $v1, $v1, 0x3C
    ctx->r3 = ADD32(ctx->r3, 0X3C);
L_8007B820:
    // 0x8007B820: lwc1        $f0, 0x130($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X130);
    // 0x8007B824: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x8007B828: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007B82C: lwc1        $f2, -0x2A68($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2A68);
    // 0x8007B830: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8007B834: nop

    // 0x8007B838: bc1f        L_8007B8B8
    if (!c1cs) {
        // 0x8007B83C: swc1        $f0, 0x130($s3)
        MEM_W(0X130, ctx->r19) = ctx->f0.u32l;
            goto L_8007B8B8;
    }
    // 0x8007B83C: swc1        $f0, 0x130($s3)
    MEM_W(0X130, ctx->r19) = ctx->f0.u32l;
    // 0x8007B840: sll         $v0, $s2, 4
    ctx->r2 = S32(ctx->r18 << 4);
    // 0x8007B844: subu        $v0, $v0, $s2
    ctx->r2 = SUB32(ctx->r2, ctx->r18);
    // 0x8007B848: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8007B84C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007B850: lwc1        $f0, -0x2A64($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2A64);
    // 0x8007B854: addu        $v0, $s3, $v0
    ctx->r2 = ADD32(ctx->r19, ctx->r2);
    // 0x8007B858: swc1        $f0, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f0.u32l;
    // 0x8007B85C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8007B860: j           L_8007B8B8
    // 0x8007B864: sb          $v0, 0x17C($s3)
    MEM_B(0X17C, ctx->r19) = ctx->r2;
        goto L_8007B8B8;
    // 0x8007B864: sb          $v0, 0x17C($s3)
    MEM_B(0X17C, ctx->r19) = ctx->r2;
L_8007B868:
    // 0x8007B868: lhu         $v0, 0x60($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X60);
    // 0x8007B86C: bne         $v0, $zero, L_8007B8A0
    if (ctx->r2 != 0) {
        // 0x8007B870: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_8007B8A0;
    }
    // 0x8007B870: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x8007B874: addiu       $v1, $s3, 0x3C
    ctx->r3 = ADD32(ctx->r19, 0X3C);
    // 0x8007B878: lhu         $v0, 0x60($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X60);
    // 0x8007B87C: bne         $v0, $zero, L_8007B8A0
    if (ctx->r2 != 0) {
        // 0x8007B880: addiu       $s2, $zero, 0x1
        ctx->r18 = ADD32(0, 0X1);
            goto L_8007B8A0;
    }
    // 0x8007B880: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8007B884: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8007B888:
    // 0x8007B888: slti        $v0, $s2, 0x4
    ctx->r2 = SIGNED(ctx->r18) < 0X4 ? 1 : 0;
    // 0x8007B88C: beq         $v0, $zero, L_8007B8AC
    if (ctx->r2 == 0) {
        // 0x8007B890: addiu       $v1, $v1, 0x3C
        ctx->r3 = ADD32(ctx->r3, 0X3C);
            goto L_8007B8AC;
    }
    // 0x8007B890: addiu       $v1, $v1, 0x3C
    ctx->r3 = ADD32(ctx->r3, 0X3C);
    // 0x8007B894: lhu         $v0, 0x60($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X60);
    // 0x8007B898: beql        $v0, $zero, L_8007B888
    if (ctx->r2 == 0) {
        // 0x8007B89C: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_8007B888;
    }
    goto skip_5;
    // 0x8007B89C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    skip_5:
L_8007B8A0:
    // 0x8007B8A0: slti        $v0, $s2, 0x4
    ctx->r2 = SIGNED(ctx->r18) < 0X4 ? 1 : 0;
    // 0x8007B8A4: bne         $v0, $zero, L_8007B8B8
    if (ctx->r2 != 0) {
        // 0x8007B8A8: nop
    
            goto L_8007B8B8;
    }
    // 0x8007B8A8: nop

L_8007B8AC:
    // 0x8007B8AC: lhu         $a0, 0x16($s4)
    ctx->r4 = MEM_HU(ctx->r20, 0X16);
    // 0x8007B8B0: j           L_8007BBE4
    // 0x8007B8B4: nop

        goto L_8007BBE4;
    // 0x8007B8B4: nop

L_8007B8B8:
    // 0x8007B8B8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8007B8BC: jal         0x8007AD30
    // 0x8007B8C0: addiu       $a0, $s3, 0x38
    ctx->r4 = ADD32(ctx->r19, 0X38);
    func_8007AD30(rdram, ctx);
        goto after_21;
    // 0x8007B8C0: addiu       $a0, $s3, 0x38
    ctx->r4 = ADD32(ctx->r19, 0X38);
    after_21:
    // 0x8007B8C4: j           L_8007BBF0
    // 0x8007B8C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8007BBF0;
    // 0x8007B8C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007B8CC:
    // 0x8007B8CC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8007B8D0: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    // 0x8007B8D4: lw          $a3, 0x138($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X138);
    // 0x8007B8D8: jal         0x8005940C
    // 0x8007B8DC: addiu       $a2, $s3, 0x8
    ctx->r6 = ADD32(ctx->r19, 0X8);
    func_8005940C(rdram, ctx);
        goto after_22;
    // 0x8007B8DC: addiu       $a2, $s3, 0x8
    ctx->r6 = ADD32(ctx->r19, 0X8);
    after_22:
    // 0x8007B8E0: beq         $v0, $zero, L_8007BBF0
    if (ctx->r2 == 0) {
        // 0x8007B8E4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8007BBF0;
    }
    // 0x8007B8E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007B8E8: jal         0x8007A9C8
    // 0x8007B8EC: addiu       $a0, $s3, 0x38
    ctx->r4 = ADD32(ctx->r19, 0X38);
    func_8007A9C8(rdram, ctx);
        goto after_23;
    // 0x8007B8EC: addiu       $a0, $s3, 0x38
    ctx->r4 = ADD32(ctx->r19, 0X38);
    after_23:
    // 0x8007B8F0: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8007B8F4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8007B8F8: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8007B8FC: beq         $v1, $zero, L_8007B914
    if (ctx->r3 == 0) {
        // 0x8007B900: sw          $v1, 0xC($v0)
        MEM_W(0XC, ctx->r2) = ctx->r3;
            goto L_8007B914;
    }
    // 0x8007B900: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
    // 0x8007B904: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8007B908: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x8007B90C: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x8007B910: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_8007B914:
    // 0x8007B914: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8007B918: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x8007B91C: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x8007B920: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8007B924: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x8007B928: j           L_8007BBEC
    // 0x8007B92C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
        goto L_8007BBEC;
    // 0x8007B92C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_8007B930:
    // 0x8007B930: addu        $s4, $s0, $zero
    ctx->r20 = ADD32(ctx->r16, 0);
    // 0x8007B934: lhu         $v1, 0x4($s4)
    ctx->r3 = MEM_HU(ctx->r20, 0X4);
    // 0x8007B938: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x8007B93C: beq         $v1, $v0, L_8007BBD4
    if (ctx->r3 == ctx->r2) {
        // 0x8007B940: nop
    
            goto L_8007BBD4;
    }
    // 0x8007B940: nop

    // 0x8007B944: lw          $v0, 0x8($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X8);
    // 0x8007B948: beq         $v0, $zero, L_8007BBD4
    if (ctx->r2 == 0) {
        // 0x8007B94C: sltiu       $v0, $v1, 0x7
        ctx->r2 = ctx->r3 < 0X7 ? 1 : 0;
            goto L_8007BBD4;
    }
    // 0x8007B94C: sltiu       $v0, $v1, 0x7
    ctx->r2 = ctx->r3 < 0X7 ? 1 : 0;
    // 0x8007B950: beq         $v0, $zero, L_8007B99C
    if (ctx->r2 == 0) {
        // 0x8007B954: addiu       $s2, $zero, 0xC
        ctx->r18 = ADD32(0, 0XC);
            goto L_8007B99C;
    }
    // 0x8007B954: addiu       $s2, $zero, 0xC
    ctx->r18 = ADD32(0, 0XC);
    // 0x8007B958: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8007B95C: addiu       $v0, $v0, -0x2A60
    ctx->r2 = ADD32(ctx->r2, -0X2A60);
    // 0x8007B960: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8007B964: addu        $v1, $v1, $v0
    gpr jr_addend_8007B96C = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8007B968: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x8007B96C: jr          $v0
    // 0x8007B970: nop

    switch (jr_addend_8007B96C >> 2) {
        case 0: goto L_8007B974; break;
        case 1: goto L_8007B974; break;
        case 2: goto L_8007B980; break;
        case 3: goto L_8007B974; break;
        case 4: goto L_8007B980; break;
        case 5: goto L_8007B974; break;
        case 6: goto L_8007B974; break;
        default: switch_error(__func__, 0x8007B96C, 0x8003D5A0);
    }
    // 0x8007B970: nop

L_8007B974:
    // 0x8007B974: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8007B978: j           L_8007B9A0
    // 0x8007B97C: addiu       $a3, $v0, 0xD84
    ctx->r7 = ADD32(ctx->r2, 0XD84);
        goto L_8007B9A0;
    // 0x8007B97C: addiu       $a3, $v0, 0xD84
    ctx->r7 = ADD32(ctx->r2, 0XD84);
L_8007B980:
    // 0x8007B980: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8007B984: addiu       $a3, $v0, 0xD88
    ctx->r7 = ADD32(ctx->r2, 0XD88);
    // 0x8007B988: j           L_8007B9A0
    // 0x8007B98C: addiu       $s2, $zero, 0xE
    ctx->r18 = ADD32(0, 0XE);
        goto L_8007B9A0;
    // 0x8007B98C: addiu       $s2, $zero, 0xE
    ctx->r18 = ADD32(0, 0XE);
L_8007B990:
    // 0x8007B990: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8007B994: j           L_8007BA30
    // 0x8007B998: addu        $s1, $s0, $v0
    ctx->r17 = ADD32(ctx->r16, ctx->r2);
        goto L_8007BA30;
    // 0x8007B998: addu        $s1, $s0, $v0
    ctx->r17 = ADD32(ctx->r16, ctx->r2);
L_8007B99C:
    // 0x8007B99C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_8007B9A0:
    // 0x8007B9A0: lw          $a0, 0x8($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X8);
    // 0x8007B9A4: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x8007B9A8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8007B9AC: lui         $a2, 0x3FB3
    ctx->r6 = S32(0X3FB3 << 16);
    // 0x8007B9B0: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x8007B9B4: jal         0x8006133C
    // 0x8007B9B8: nop

    func_8006133C(rdram, ctx);
        goto after_24;
    // 0x8007B9B8: nop

    after_24:
    // 0x8007B9BC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8007B9C0: addiu       $a1, $s3, 0x8
    ctx->r5 = ADD32(ctx->r19, 0X8);
    // 0x8007B9C4: addiu       $a2, $s3, 0x2C
    ctx->r6 = ADD32(ctx->r19, 0X2C);
    // 0x8007B9C8: lui         $a3, 0x4180
    ctx->r7 = S32(0X4180 << 16);
    // 0x8007B9CC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007B9D0: lwc1        $f0, -0x2A44($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2A44);
    // 0x8007B9D4: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x8007B9D8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8007B9DC: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x8007B9E0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8007B9E4: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    // 0x8007B9E8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8007B9EC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8007B9F0: jal         0x800989D8
    // 0x8007B9F4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800989D8(rdram, ctx);
        goto after_25;
    // 0x8007B9F4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_25:
    // 0x8007B9F8: lbu         $v0, 0x17C($s3)
    ctx->r2 = MEM_BU(ctx->r19, 0X17C);
    // 0x8007B9FC: bne         $v0, $zero, L_8007BBD4
    if (ctx->r2 != 0) {
        // 0x8007BA00: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_8007BBD4;
    }
    // 0x8007BA00: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8007BA04: addiu       $s0, $s3, 0x38
    ctx->r16 = ADD32(ctx->r19, 0X38);
    // 0x8007BA08: addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
    // 0x8007BA0C: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
L_8007BA10:
    // 0x8007BA10: lhu         $v0, 0x28($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X28);
    // 0x8007BA14: beq         $v0, $zero, L_8007B990
    if (ctx->r2 == 0) {
        // 0x8007BA18: addiu       $v1, $v1, 0x3C
        ctx->r3 = ADD32(ctx->r3, 0X3C);
            goto L_8007B990;
    }
    // 0x8007BA18: addiu       $v1, $v1, 0x3C
    ctx->r3 = ADD32(ctx->r3, 0X3C);
    // 0x8007BA1C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8007BA20: slti        $v0, $a1, 0x4
    ctx->r2 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x8007BA24: bne         $v0, $zero, L_8007BA10
    if (ctx->r2 != 0) {
        // 0x8007BA28: addiu       $a0, $a0, 0x3C
        ctx->r4 = ADD32(ctx->r4, 0X3C);
            goto L_8007BA10;
    }
    // 0x8007BA28: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    // 0x8007BA2C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_8007BA30:
    // 0x8007BA30: beq         $s1, $zero, L_8007BBD4
    if (ctx->r17 == 0) {
        // 0x8007BA34: addiu       $a0, $sp, 0x28
        ctx->r4 = ADD32(ctx->r29, 0X28);
            goto L_8007BBD4;
    }
    // 0x8007BA34: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8007BA38: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    // 0x8007BA3C: jal         0x8001C774
    // 0x8007BA40: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    func_8001C774(rdram, ctx);
        goto after_26;
    // 0x8007BA40: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    after_26:
    // 0x8007BA44: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8007BA48: addiu       $s0, $sp, 0x58
    ctx->r16 = ADD32(ctx->r29, 0X58);
    // 0x8007BA4C: lw          $a1, 0x8($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X8);
    // 0x8007BA50: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8007BA54: jal         0x800194A4
    // 0x8007BA58: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_800194A4(rdram, ctx);
        goto after_27;
    // 0x8007BA58: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_27:
    // 0x8007BA5C: jal         0x8001CF58
    // 0x8007BA60: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    normalize_vector(rdram, ctx);
        goto after_28;
    // 0x8007BA60: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_28:
    // 0x8007BA64: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8007BA68: lw          $v0, -0x5690($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5690);
    // 0x8007BA6C: sll         $s0, $s2, 2
    ctx->r16 = S32(ctx->r18 << 2);
    // 0x8007BA70: jal         0x80003430
    // 0x8007BA74: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    rand_recomp(rdram, ctx);
        goto after_29;
    // 0x8007BA74: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    after_29:
    // 0x8007BA78: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8007BA7C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8007BA80: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x8007BA84: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8007BA88: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8007BA8C: jal         0x8001CD6C
    // 0x8007BA90: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    func_8001CD6C(rdram, ctx);
        goto after_30;
    // 0x8007BA90: addiu       $a0, $sp, 0x68
    ctx->r4 = ADD32(ctx->r29, 0X68);
    after_30:
    // 0x8007BA94: jal         0x80003430
    // 0x8007BA98: nop

    rand_recomp(rdram, ctx);
        goto after_31;
    // 0x8007BA98: nop

    after_31:
    // 0x8007BA9C: lwc1        $f0, 0x68($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8007BAA0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007BAA4: lwc1        $f2, -0x2A40($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2A40);
    // 0x8007BAA8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007BAAC: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007BAB0: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8007BAB4: sh          $v0, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r2;
    // 0x8007BAB8: lwc1        $f0, 0x74($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8007BABC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007BAC0: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007BAC4: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8007BAC8: sh          $v0, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r2;
    // 0x8007BACC: lwc1        $f0, 0x80($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8007BAD0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007BAD4: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007BAD8: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8007BADC: sh          $v0, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r2;
    // 0x8007BAE0: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x8007BAE4: sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
    // 0x8007BAE8: lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1);
    // 0x8007BAEC: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
    // 0x8007BAF0: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x8007BAF4: sb          $zero, 0x3($s1)
    MEM_B(0X3, ctx->r17) = 0;
    // 0x8007BAF8: sb          $v0, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r2;
    // 0x8007BAFC: lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4);
    // 0x8007BB00: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x8007BB04: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8007BB08: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8007BB0C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007BB10: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
    // 0x8007BB14: lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X5);
    // 0x8007BB18: lbu         $v1, 0x1($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X1);
    // 0x8007BB1C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007BB20: lwc1        $f2, -0x2A3C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2A3C);
    // 0x8007BB24: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8007BB28: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8007BB2C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007BB30: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8007BB34: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
    // 0x8007BB38: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007BB3C: lwc1        $f0, -0x2A38($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2A38);
    // 0x8007BB40: lbu         $v1, 0x6($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X6);
    // 0x8007BB44: lbu         $a0, 0x2($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X2);
    // 0x8007BB48: lwc1        $f4, 0xD80($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XD80);
    // 0x8007BB4C: swc1        $f2, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f2.u32l;
    // 0x8007BB50: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007BB54: lwc1        $f2, -0x2A34($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2A34);
    // 0x8007BB58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007BB5C: sw          $zero, 0x14($s1)
    MEM_W(0X14, ctx->r17) = 0;
    // 0x8007BB60: sh          $v0, 0x20($s1)
    MEM_H(0X20, ctx->r17) = ctx->r2;
    // 0x8007BB64: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    // 0x8007BB68: sw          $zero, 0x28($s1)
    MEM_W(0X28, ctx->r17) = 0;
    // 0x8007BB6C: sw          $zero, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = 0;
    // 0x8007BB70: sw          $zero, 0x30($s1)
    MEM_W(0X30, ctx->r17) = 0;
    // 0x8007BB74: swc1        $f0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f0.u32l;
    // 0x8007BB78: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007BB7C: lwc1        $f0, -0x2A30($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2A30);
    // 0x8007BB80: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x8007BB84: swc1        $f4, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f4.u32l;
    // 0x8007BB88: swc1        $f0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f0.u32l;
    // 0x8007BB8C: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x8007BB90: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007BB94: swc1        $f0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f0.u32l;
    // 0x8007BB98: lwc1        $f0, 0x58($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8007BB9C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007BBA0: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007BBA4: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8007BBA8: sh          $v0, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r2;
    // 0x8007BBAC: lwc1        $f0, 0x5C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8007BBB0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007BBB4: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007BBB8: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8007BBBC: sh          $v0, 0x1A($s1)
    MEM_H(0X1A, ctx->r17) = ctx->r2;
    // 0x8007BBC0: lwc1        $f0, 0x60($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8007BBC4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007BBC8: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007BBCC: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8007BBD0: sh          $v0, 0x1C($s1)
    MEM_H(0X1C, ctx->r17) = ctx->r2;
L_8007BBD4:
    // 0x8007BBD4: lhu         $v1, 0x0($s4)
    ctx->r3 = MEM_HU(ctx->r20, 0X0);
    // 0x8007BBD8: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8007BBDC: beq         $v1, $v0, L_8007BBEC
    if (ctx->r3 == ctx->r2) {
        // 0x8007BBE0: addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
            goto L_8007BBEC;
    }
    // 0x8007BBE0: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
L_8007BBE4:
    // 0x8007BBE4: jal         0x8003ED74
    // 0x8007BBE8: nop

    func_8003ED74(rdram, ctx);
        goto after_32;
    // 0x8007BBE8: nop

    after_32:
L_8007BBEC:
    // 0x8007BBEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8007BBF0:
    // 0x8007BBF0: lw          $ra, 0xAC($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XAC);
    // 0x8007BBF4: lw          $s4, 0xA8($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XA8);
    // 0x8007BBF8: lw          $s3, 0xA4($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XA4);
    // 0x8007BBFC: lw          $s2, 0xA0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XA0);
    // 0x8007BC00: lw          $s1, 0x9C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X9C);
    // 0x8007BC04: lw          $s0, 0x98($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X98);
    // 0x8007BC08: ldc1        $f22, 0xB8($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0XB8);
    // 0x8007BC0C: ldc1        $f20, 0xB0($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XB0);
    // 0x8007BC10: jr          $ra
    // 0x8007BC14: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x8007BC14: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void func_8007BC18(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007BC18: addiu       $sp, $sp, -0x1B8
    ctx->r29 = ADD32(ctx->r29, -0X1B8);
    // 0x8007BC1C: sw          $s3, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r19;
    // 0x8007BC20: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x8007BC24: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8007BC28: addiu       $v1, $a1, -0x1
    ctx->r3 = ADD32(ctx->r5, -0X1);
    // 0x8007BC2C: sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x8007BC30: sw          $ra, 0x1AC($sp)
    MEM_W(0X1AC, ctx->r29) = ctx->r31;
    // 0x8007BC34: sw          $s4, 0x1A8($sp)
    MEM_W(0X1A8, ctx->r29) = ctx->r20;
    // 0x8007BC38: sw          $s2, 0x1A0($sp)
    MEM_W(0X1A0, ctx->r29) = ctx->r18;
    // 0x8007BC3C: sw          $s1, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r17;
    // 0x8007BC40: sw          $s0, 0x198($sp)
    MEM_W(0X198, ctx->r29) = ctx->r16;
    // 0x8007BC44: sdc1        $f20, 0x1B0($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X1B0, ctx->r29);
    // 0x8007BC48: lw          $s2, 0x4($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X4);
    // 0x8007BC4C: beq         $v0, $zero, L_8007C240
    if (ctx->r2 == 0) {
        // 0x8007BC50: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_8007C240;
    }
    // 0x8007BC50: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8007BC54: addiu       $v0, $v0, -0x2A28
    ctx->r2 = ADD32(ctx->r2, -0X2A28);
    // 0x8007BC58: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8007BC5C: addu        $v1, $v1, $v0
    gpr jr_addend_8007BC64 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8007BC60: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x8007BC64: jr          $v0
    // 0x8007BC68: nop

    switch (jr_addend_8007BC64 >> 2) {
        case 0: goto L_8007BC6C; break;
        case 1: goto L_8007BE4C; break;
        case 2: goto L_8007BE6C; break;
        case 3: goto L_8007BEE0; break;
        case 4: goto L_8007BF88; break;
        default: switch_error(__func__, 0x8007BC64, 0x8003D5D8);
    }
    // 0x8007BC68: nop

L_8007BC6C:
    // 0x8007BC6C: addiu       $a0, $zero, 0x180
    ctx->r4 = ADD32(0, 0X180);
    // 0x8007BC70: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8007BC74: jal         0x80001ACC
    // 0x8007BC78: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x8007BC78: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    after_0:
    // 0x8007BC7C: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x8007BC80: addiu       $v0, $s2, 0x8
    ctx->r2 = ADD32(ctx->r18, 0X8);
    // 0x8007BC84: addu        $v1, $s1, $zero
    ctx->r3 = ADD32(ctx->r17, 0);
    // 0x8007BC88: addiu       $a0, $s1, 0x30
    ctx->r4 = ADD32(ctx->r17, 0X30);
    // 0x8007BC8C: sw          $s2, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r18;
    // 0x8007BC90: sw          $v0, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->r2;
L_8007BC94:
    // 0x8007BC94: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8007BC98: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x8007BC9C: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x8007BCA0: lw          $t3, 0xC($v1)
    ctx->r11 = MEM_W(ctx->r3, 0XC);
    // 0x8007BCA4: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8007BCA8: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8007BCAC: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
    // 0x8007BCB0: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
    // 0x8007BCB4: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8007BCB8: bne         $v1, $a0, L_8007BC94
    if (ctx->r3 != ctx->r4) {
        // 0x8007BCBC: addiu       $v0, $v0, 0x10
        ctx->r2 = ADD32(ctx->r2, 0X10);
            goto L_8007BC94;
    }
    // 0x8007BCBC: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8007BCC0: sb          $zero, 0x17C($s2)
    MEM_B(0X17C, ctx->r18) = 0;
    // 0x8007BCC4: lw          $a0, 0x40($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X40);
    // 0x8007BCC8: jal         0x80056EB0
    // 0x8007BCCC: nop

    walkMeshdef0List(rdram, ctx);
        goto after_1;
    // 0x8007BCCC: nop

    after_1:
    // 0x8007BCD0: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x8007BCD4: sw          $v0, 0xC($s3)
    MEM_W(0XC, ctx->r19) = ctx->r2;
    // 0x8007BCD8: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x8007BCDC: jal         0x8007A870
    // 0x8007BCE0: addiu       $a0, $s2, 0x38
    ctx->r4 = ADD32(ctx->r18, 0X38);
    func_8007A870(rdram, ctx);
        goto after_2;
    // 0x8007BCE0: addiu       $a0, $s2, 0x38
    ctx->r4 = ADD32(ctx->r18, 0X38);
    after_2:
    // 0x8007BCE4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8007BCE8: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8007BCEC: sw          $zero, 0x58($v0)
    MEM_W(0X58, ctx->r2) = 0;
    // 0x8007BCF0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8007BCF4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8007BCF8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007BCFC: lwc1        $f20, -0x2A14($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X2A14);
    // 0x8007BD00: lwc1        $f2, 0x34($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X34);
    // 0x8007BD04: lwc1        $f0, 0x30($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X30);
    // 0x8007BD08: div.s       $f2, $f20, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = DIV_S(ctx->f20.fl, ctx->f2.fl);
    // 0x8007BD0C: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8007BD10: swc1        $f0, 0x13C($s2)
    MEM_W(0X13C, ctx->r18) = ctx->f0.u32l;
    // 0x8007BD14: lwc1        $f0, 0x34($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X34);
    // 0x8007BD18: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8007BD1C: swc1        $f0, 0x140($s2)
    MEM_W(0X140, ctx->r18) = ctx->f0.u32l;
    // 0x8007BD20: lwc1        $f0, 0x38($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X38);
    // 0x8007BD24: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8007BD28: lwc1        $f4, 0x140($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X140);
    // 0x8007BD2C: lwc1        $f2, 0x13C($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X13C);
    // 0x8007BD30: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x8007BD34: nop

    // 0x8007BD38: bc1f        L_8007BD44
    if (!c1cs) {
        // 0x8007BD3C: swc1        $f0, 0x144($s2)
        MEM_W(0X144, ctx->r18) = ctx->f0.u32l;
            goto L_8007BD44;
    }
    // 0x8007BD3C: swc1        $f0, 0x144($s2)
    MEM_W(0X144, ctx->r18) = ctx->f0.u32l;
    // 0x8007BD40: mov.s       $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = ctx->f4.fl;
L_8007BD44:
    // 0x8007BD44: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8007BD48: nop

    // 0x8007BD4C: bc1tl       L_8007BD54
    if (c1cs) {
        // 0x8007BD50: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_8007BD54;
    }
    goto skip_0;
    // 0x8007BD50: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_0:
L_8007BD54:
    // 0x8007BD54: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8007BD58: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8007BD5C: lwc1        $f0, 0x44($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X44);
    // 0x8007BD60: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007BD64: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x8007BD68: addiu       $s0, $s0, -0x6AA0
    ctx->r16 = ADD32(ctx->r16, -0X6AA0);
    // 0x8007BD6C: swc1        $f0, 0x138($s2)
    MEM_W(0X138, ctx->r18) = ctx->f0.u32l;
    // 0x8007BD70: lhu         $a0, 0xC($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0XC);
    // 0x8007BD74: jal         0x8003E684
    // 0x8007BD78: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_8003E684(rdram, ctx);
        goto after_3;
    // 0x8007BD78: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_3:
    // 0x8007BD7C: lhu         $a0, 0x1C($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X1C);
    // 0x8007BD80: jal         0x8003E684
    // 0x8007BD84: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_8003E684(rdram, ctx);
        goto after_4;
    // 0x8007BD84: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_4:
    // 0x8007BD88: lhu         $v0, 0x3C($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X3C);
    // 0x8007BD8C: sh          $v0, 0x178($s2)
    MEM_H(0X178, ctx->r18) = ctx->r2;
    // 0x8007BD90: lhu         $a0, 0x3C($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X3C);
    // 0x8007BD94: jal         0x8004015C
    // 0x8007BD98: nop

    func_8004015C(rdram, ctx);
        goto after_5;
    // 0x8007BD98: nop

    after_5:
    // 0x8007BD9C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8007BDA0: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8007BDA4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8007BDA8: jal         0x80059B50
    // 0x8007BDAC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80059B50(rdram, ctx);
        goto after_6;
    // 0x8007BDAC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_6:
    // 0x8007BDB0: addiu       $s1, $sp, 0x58
    ctx->r17 = ADD32(ctx->r29, 0X58);
    // 0x8007BDB4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8007BDB8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8007BDBC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8007BDC0: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x8007BDC4: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x8007BDC8: jal         0x8001C774
    // 0x8007BDCC: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    func_8001C774(rdram, ctx);
        goto after_7;
    // 0x8007BDCC: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x8007BDD0: lwc1        $f0, 0x8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8007BDD4: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8007BDD8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8007BDDC: swc1        $f0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f0.u32l;
    // 0x8007BDE0: lwc1        $f0, 0xC($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8007BDE4: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8007BDE8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8007BDEC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8007BDF0: swc1        $f0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f0.u32l;
    // 0x8007BDF4: lwc1        $f0, 0x10($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8007BDF8: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8007BDFC: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    // 0x8007BE00: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8007BE04: addiu       $s0, $sp, 0x98
    ctx->r16 = ADD32(ctx->r29, 0X98);
    // 0x8007BE08: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8007BE0C: jal         0x800193E8
    // 0x8007BE10: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    func_800193E8(rdram, ctx);
        goto after_8;
    // 0x8007BE10: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x8007BE14: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8007BE18: addiu       $a1, $s2, 0x14
    ctx->r5 = ADD32(ctx->r18, 0X14);
    // 0x8007BE1C: jal         0x800193E8
    // 0x8007BE20: addiu       $a2, $sp, 0xA4
    ctx->r6 = ADD32(ctx->r29, 0XA4);
    func_800193E8(rdram, ctx);
        goto after_9;
    // 0x8007BE20: addiu       $a2, $sp, 0xA4
    ctx->r6 = ADD32(ctx->r29, 0XA4);
    after_9:
    // 0x8007BE24: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8007BE28: addiu       $a1, $s2, 0x20
    ctx->r5 = ADD32(ctx->r18, 0X20);
    // 0x8007BE2C: jal         0x800193E8
    // 0x8007BE30: addiu       $a2, $sp, 0xB0
    ctx->r6 = ADD32(ctx->r29, 0XB0);
    func_800193E8(rdram, ctx);
        goto after_10;
    // 0x8007BE30: addiu       $a2, $sp, 0xB0
    ctx->r6 = ADD32(ctx->r29, 0XB0);
    after_10:
    // 0x8007BE34: addiu       $a0, $s2, 0x148
    ctx->r4 = ADD32(ctx->r18, 0X148);
    // 0x8007BE38: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8007BE3C: jal         0x80059B50
    // 0x8007BE40: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80059B50(rdram, ctx);
        goto after_11;
    // 0x8007BE40: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_11:
    // 0x8007BE44: j           L_8007C240
    // 0x8007BE48: nop

        goto L_8007C240;
    // 0x8007BE48: nop

L_8007BE4C:
    // 0x8007BE4C: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x8007BE50: jal         0x80001C98
    // 0x8007BE54: nop

    rs_free(rdram, ctx);
        goto after_12;
    // 0x8007BE54: nop

    after_12:
    // 0x8007BE58: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8007BE5C: jal         0x8005779C
    // 0x8007BE60: nop

    func_8005779C(rdram, ctx);
        goto after_13;
    // 0x8007BE60: nop

    after_13:
    // 0x8007BE64: j           L_8007C240
    // 0x8007BE68: nop

        goto L_8007C240;
    // 0x8007BE68: nop

L_8007BE6C:
    // 0x8007BE6C: lhu         $a0, 0x178($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X178);
    // 0x8007BE70: lwc1        $f20, 0x0($a2)
    ctx->f20.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8007BE74: jal         0x8004015C
    // 0x8007BE78: nop

    func_8004015C(rdram, ctx);
        goto after_14;
    // 0x8007BE78: nop

    after_14:
    // 0x8007BE7C: addiu       $s0, $sp, 0xC8
    ctx->r16 = ADD32(ctx->r29, 0XC8);
    // 0x8007BE80: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8007BE84: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x8007BE88: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8007BE8C: jal         0x80059B50
    // 0x8007BE90: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_80059B50(rdram, ctx);
        goto after_15;
    // 0x8007BE90: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_15:
    // 0x8007BE94: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8007BE98: addiu       $a1, $s2, 0x148
    ctx->r5 = ADD32(ctx->r18, 0X148);
    // 0x8007BE9C: addiu       $s0, $sp, 0xF8
    ctx->r16 = ADD32(ctx->r29, 0XF8);
    // 0x8007BEA0: jal         0x800191C4
    // 0x8007BEA4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_800191C4(rdram, ctx);
        goto after_16;
    // 0x8007BEA4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_16:
    // 0x8007BEA8: addiu       $a0, $s2, 0x8
    ctx->r4 = ADD32(ctx->r18, 0X8);
    // 0x8007BEAC: jal         0x80059D18
    // 0x8007BEB0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_80059D18(rdram, ctx);
        goto after_17;
    // 0x8007BEB0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_17:
    // 0x8007BEB4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8007BEB8: lw          $t0, 0x24($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X24);
    // 0x8007BEBC: lw          $t1, 0x28($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X28);
    // 0x8007BEC0: lw          $t2, 0x2C($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X2C);
    // 0x8007BEC4: sw          $t0, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r8;
    // 0x8007BEC8: sw          $t1, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->r9;
    // 0x8007BECC: sw          $t2, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->r10;
    // 0x8007BED0: jal         0x8007AD30
    // 0x8007BED4: addiu       $a0, $s2, 0x38
    ctx->r4 = ADD32(ctx->r18, 0X38);
    func_8007AD30(rdram, ctx);
        goto after_18;
    // 0x8007BED4: addiu       $a0, $s2, 0x38
    ctx->r4 = ADD32(ctx->r18, 0X38);
    after_18:
    // 0x8007BED8: j           L_8007C240
    // 0x8007BEDC: nop

        goto L_8007C240;
    // 0x8007BEDC: nop

L_8007BEE0:
    // 0x8007BEE0: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x8007BEE4: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x8007BEE8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_8007BEEC:
    // 0x8007BEEC: lhu         $v0, 0x60($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X60);
    // 0x8007BEF0: bne         $v0, $zero, L_8007BF0C
    if (ctx->r2 != 0) {
        // 0x8007BEF4: slti        $v0, $v1, 0x4
        ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
            goto L_8007BF0C;
    }
    // 0x8007BEF4: slti        $v0, $v1, 0x4
    ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x8007BEF8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8007BEFC: slti        $v0, $v1, 0x4
    ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x8007BF00: bne         $v0, $zero, L_8007BEEC
    if (ctx->r2 != 0) {
        // 0x8007BF04: addiu       $a0, $a0, 0x3C
        ctx->r4 = ADD32(ctx->r4, 0X3C);
            goto L_8007BEEC;
    }
    // 0x8007BF04: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    // 0x8007BF08: slti        $v0, $v1, 0x4
    ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
L_8007BF0C:
    // 0x8007BF0C: beq         $v0, $zero, L_8007C240
    if (ctx->r2 == 0) {
        // 0x8007BF10: addiu       $s0, $s2, 0x8
        ctx->r16 = ADD32(ctx->r18, 0X8);
            goto L_8007C240;
    }
    // 0x8007BF10: addiu       $s0, $s2, 0x8
    ctx->r16 = ADD32(ctx->r18, 0X8);
    // 0x8007BF14: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8007BF18: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x8007BF1C: lw          $a3, 0x138($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X138);
    // 0x8007BF20: jal         0x8005940C
    // 0x8007BF24: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_8005940C(rdram, ctx);
        goto after_19;
    // 0x8007BF24: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_19:
    // 0x8007BF28: beq         $v0, $zero, L_8007C240
    if (ctx->r2 == 0) {
        // 0x8007BF2C: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_8007C240;
    }
    // 0x8007BF2C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8007BF30: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    // 0x8007BF34: addiu       $a2, $s2, 0x13C
    ctx->r6 = ADD32(ctx->r18, 0X13C);
    // 0x8007BF38: jal         0x80059C24
    // 0x8007BF3C: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_80059C24(rdram, ctx);
        goto after_20;
    // 0x8007BF3C: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_20:
    // 0x8007BF40: jal         0x8007A9C8
    // 0x8007BF44: addiu       $a0, $s2, 0x38
    ctx->r4 = ADD32(ctx->r18, 0X38);
    func_8007A9C8(rdram, ctx);
        goto after_21;
    // 0x8007BF44: addiu       $a0, $s2, 0x38
    ctx->r4 = ADD32(ctx->r18, 0X38);
    after_21:
    // 0x8007BF48: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x8007BF4C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8007BF50: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8007BF54: beq         $v0, $zero, L_8007BF6C
    if (ctx->r2 == 0) {
        // 0x8007BF58: sw          $v0, 0xC($v1)
        MEM_W(0XC, ctx->r3) = ctx->r2;
            goto L_8007BF6C;
    }
    // 0x8007BF58: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x8007BF5C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8007BF60: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x8007BF64: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x8007BF68: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_8007BF6C:
    // 0x8007BF6C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8007BF70: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x8007BF74: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x8007BF78: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8007BF7C: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x8007BF80: j           L_8007C240
    // 0x8007BF84: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
        goto L_8007C240;
    // 0x8007BF84: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_8007BF88:
    // 0x8007BF88: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x8007BF8C: lhu         $v1, 0x4($s3)
    ctx->r3 = MEM_HU(ctx->r19, 0X4);
    // 0x8007BF90: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x8007BF94: beq         $v1, $v0, L_8007C228
    if (ctx->r3 == ctx->r2) {
        // 0x8007BF98: nop
    
            goto L_8007C228;
    }
    // 0x8007BF98: nop

    // 0x8007BF9C: lw          $v0, 0x8($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X8);
    // 0x8007BFA0: beq         $v0, $zero, L_8007C228
    if (ctx->r2 == 0) {
        // 0x8007BFA4: addiu       $s4, $zero, 0xC
        ctx->r20 = ADD32(0, 0XC);
            goto L_8007C228;
    }
    // 0x8007BFA4: addiu       $s4, $zero, 0xC
    ctx->r20 = ADD32(0, 0XC);
    // 0x8007BFA8: sltiu       $v0, $v1, 0x7
    ctx->r2 = ctx->r3 < 0X7 ? 1 : 0;
    // 0x8007BFAC: beq         $v0, $zero, L_8007BFF4
    if (ctx->r2 == 0) {
        // 0x8007BFB0: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_8007BFF4;
    }
    // 0x8007BFB0: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8007BFB4: addiu       $v0, $v0, -0x2A10
    ctx->r2 = ADD32(ctx->r2, -0X2A10);
    // 0x8007BFB8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8007BFBC: addu        $v1, $v1, $v0
    gpr jr_addend_8007BFC4 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8007BFC0: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x8007BFC4: jr          $v0
    // 0x8007BFC8: nop

    switch (jr_addend_8007BFC4 >> 2) {
        case 0: goto L_8007BFCC; break;
        case 1: goto L_8007BFCC; break;
        case 2: goto L_8007BFD8; break;
        case 3: goto L_8007BFCC; break;
        case 4: goto L_8007BFD8; break;
        case 5: goto L_8007BFCC; break;
        case 6: goto L_8007BFCC; break;
        default: switch_error(__func__, 0x8007BFC4, 0x8003D5F0);
    }
    // 0x8007BFC8: nop

L_8007BFCC:
    // 0x8007BFCC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8007BFD0: j           L_8007BFF8
    // 0x8007BFD4: addiu       $a3, $v0, 0xD84
    ctx->r7 = ADD32(ctx->r2, 0XD84);
        goto L_8007BFF8;
    // 0x8007BFD4: addiu       $a3, $v0, 0xD84
    ctx->r7 = ADD32(ctx->r2, 0XD84);
L_8007BFD8:
    // 0x8007BFD8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8007BFDC: addiu       $a3, $v0, 0xD88
    ctx->r7 = ADD32(ctx->r2, 0XD88);
    // 0x8007BFE0: j           L_8007BFF8
    // 0x8007BFE4: addiu       $s4, $zero, 0xE
    ctx->r20 = ADD32(0, 0XE);
        goto L_8007BFF8;
    // 0x8007BFE4: addiu       $s4, $zero, 0xE
    ctx->r20 = ADD32(0, 0XE);
L_8007BFE8:
    // 0x8007BFE8: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x8007BFEC: j           L_8007C080
    // 0x8007BFF0: addu        $s1, $a2, $v0
    ctx->r17 = ADD32(ctx->r6, ctx->r2);
        goto L_8007C080;
    // 0x8007BFF0: addu        $s1, $a2, $v0
    ctx->r17 = ADD32(ctx->r6, ctx->r2);
L_8007BFF4:
    // 0x8007BFF4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
L_8007BFF8:
    // 0x8007BFF8: lw          $a0, 0x8($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X8);
    // 0x8007BFFC: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x8007C000: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8007C004: lui         $a2, 0x3FB3
    ctx->r6 = S32(0X3FB3 << 16);
    // 0x8007C008: ori         $a2, $a2, 0x3333
    ctx->r6 = ctx->r6 | 0X3333;
    // 0x8007C00C: jal         0x8006133C
    // 0x8007C010: nop

    func_8006133C(rdram, ctx);
        goto after_22;
    // 0x8007C010: nop

    after_22:
    // 0x8007C014: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8007C018: addiu       $a1, $s2, 0x8
    ctx->r5 = ADD32(ctx->r18, 0X8);
    // 0x8007C01C: addiu       $a2, $s2, 0x2C
    ctx->r6 = ADD32(ctx->r18, 0X2C);
    // 0x8007C020: lui         $a3, 0x4180
    ctx->r7 = S32(0X4180 << 16);
    // 0x8007C024: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007C028: lwc1        $f0, -0x29F4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X29F4);
    // 0x8007C02C: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x8007C030: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8007C034: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x8007C038: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8007C03C: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    // 0x8007C040: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8007C044: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8007C048: jal         0x800989D8
    // 0x8007C04C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800989D8(rdram, ctx);
        goto after_23;
    // 0x8007C04C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_23:
    // 0x8007C050: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8007C054: addiu       $a2, $s2, 0x38
    ctx->r6 = ADD32(ctx->r18, 0X38);
    // 0x8007C058: addu        $v1, $a2, $zero
    ctx->r3 = ADD32(ctx->r6, 0);
    // 0x8007C05C: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
L_8007C060:
    // 0x8007C060: lhu         $v0, 0x28($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X28);
    // 0x8007C064: beq         $v0, $zero, L_8007BFE8
    if (ctx->r2 == 0) {
        // 0x8007C068: addiu       $v1, $v1, 0x3C
        ctx->r3 = ADD32(ctx->r3, 0X3C);
            goto L_8007BFE8;
    }
    // 0x8007C068: addiu       $v1, $v1, 0x3C
    ctx->r3 = ADD32(ctx->r3, 0X3C);
    // 0x8007C06C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8007C070: slti        $v0, $a1, 0x4
    ctx->r2 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x8007C074: bne         $v0, $zero, L_8007C060
    if (ctx->r2 != 0) {
        // 0x8007C078: addiu       $a0, $a0, 0x3C
        ctx->r4 = ADD32(ctx->r4, 0X3C);
            goto L_8007C060;
    }
    // 0x8007C078: addiu       $a0, $a0, 0x3C
    ctx->r4 = ADD32(ctx->r4, 0X3C);
    // 0x8007C07C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
L_8007C080:
    // 0x8007C080: beq         $s1, $zero, L_8007C228
    if (ctx->r17 == 0) {
        // 0x8007C084: addiu       $s0, $sp, 0x128
        ctx->r16 = ADD32(ctx->r29, 0X128);
            goto L_8007C228;
    }
    // 0x8007C084: addiu       $s0, $sp, 0x128
    ctx->r16 = ADD32(ctx->r29, 0X128);
    // 0x8007C088: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x8007C08C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8007C090: jal         0x8001C774
    // 0x8007C094: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    func_8001C774(rdram, ctx);
        goto after_24;
    // 0x8007C094: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    after_24:
    // 0x8007C098: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8007C09C: addiu       $s0, $sp, 0x158
    ctx->r16 = ADD32(ctx->r29, 0X158);
    // 0x8007C0A0: lw          $a1, 0x8($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X8);
    // 0x8007C0A4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8007C0A8: jal         0x800194A4
    // 0x8007C0AC: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    func_800194A4(rdram, ctx);
        goto after_25;
    // 0x8007C0AC: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    after_25:
    // 0x8007C0B0: jal         0x8001CF58
    // 0x8007C0B4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    normalize_vector(rdram, ctx);
        goto after_26;
    // 0x8007C0B4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_26:
    // 0x8007C0B8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8007C0BC: lw          $v0, -0x5690($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5690);
    // 0x8007C0C0: sll         $s0, $s4, 2
    ctx->r16 = S32(ctx->r20 << 2);
    // 0x8007C0C4: jal         0x80003430
    // 0x8007C0C8: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    rand_recomp(rdram, ctx);
        goto after_27;
    // 0x8007C0C8: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    after_27:
    // 0x8007C0CC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8007C0D0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8007C0D4: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8007C0D8: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8007C0DC: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8007C0E0: jal         0x8001CD6C
    // 0x8007C0E4: addiu       $a0, $sp, 0x168
    ctx->r4 = ADD32(ctx->r29, 0X168);
    func_8001CD6C(rdram, ctx);
        goto after_28;
    // 0x8007C0E4: addiu       $a0, $sp, 0x168
    ctx->r4 = ADD32(ctx->r29, 0X168);
    after_28:
    // 0x8007C0E8: jal         0x80003430
    // 0x8007C0EC: nop

    rand_recomp(rdram, ctx);
        goto after_29;
    // 0x8007C0EC: nop

    after_29:
    // 0x8007C0F0: lwc1        $f0, 0x168($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X168);
    // 0x8007C0F4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007C0F8: lwc1        $f2, -0x29F0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X29F0);
    // 0x8007C0FC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007C100: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007C104: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x8007C108: sh          $v0, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r2;
    // 0x8007C10C: lwc1        $f0, 0x174($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X174);
    // 0x8007C110: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007C114: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007C118: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x8007C11C: sh          $v0, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r2;
    // 0x8007C120: lwc1        $f0, 0x180($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X180);
    // 0x8007C124: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007C128: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007C12C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x8007C130: sh          $v0, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r2;
    // 0x8007C134: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x8007C138: sb          $v0, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r2;
    // 0x8007C13C: lbu         $v0, 0x1($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1);
    // 0x8007C140: sb          $v0, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r2;
    // 0x8007C144: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x8007C148: sb          $zero, 0x3($s1)
    MEM_B(0X3, ctx->r17) = 0;
    // 0x8007C14C: sb          $v0, 0x2($s1)
    MEM_B(0X2, ctx->r17) = ctx->r2;
    // 0x8007C150: lbu         $v0, 0x4($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4);
    // 0x8007C154: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x8007C158: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8007C15C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8007C160: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007C164: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
    // 0x8007C168: lbu         $v0, 0x5($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X5);
    // 0x8007C16C: lbu         $v1, 0x1($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X1);
    // 0x8007C170: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007C174: lwc1        $f2, -0x29EC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X29EC);
    // 0x8007C178: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8007C17C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8007C180: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007C184: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8007C188: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
    // 0x8007C18C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007C190: lwc1        $f0, -0x29E8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X29E8);
    // 0x8007C194: lbu         $v1, 0x6($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X6);
    // 0x8007C198: lbu         $a0, 0x2($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X2);
    // 0x8007C19C: lwc1        $f4, 0xD80($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XD80);
    // 0x8007C1A0: swc1        $f2, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f2.u32l;
    // 0x8007C1A4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007C1A8: lwc1        $f2, -0x29E4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X29E4);
    // 0x8007C1AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007C1B0: sw          $zero, 0x14($s1)
    MEM_W(0X14, ctx->r17) = 0;
    // 0x8007C1B4: sh          $v0, 0x20($s1)
    MEM_H(0X20, ctx->r17) = ctx->r2;
    // 0x8007C1B8: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    // 0x8007C1BC: sw          $zero, 0x28($s1)
    MEM_W(0X28, ctx->r17) = 0;
    // 0x8007C1C0: sw          $zero, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = 0;
    // 0x8007C1C4: sw          $zero, 0x30($s1)
    MEM_W(0X30, ctx->r17) = 0;
    // 0x8007C1C8: swc1        $f0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f0.u32l;
    // 0x8007C1CC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007C1D0: lwc1        $f0, -0x29E0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X29E0);
    // 0x8007C1D4: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x8007C1D8: swc1        $f4, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f4.u32l;
    // 0x8007C1DC: swc1        $f0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f0.u32l;
    // 0x8007C1E0: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x8007C1E4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007C1E8: swc1        $f0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f0.u32l;
    // 0x8007C1EC: lwc1        $f0, 0x158($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X158);
    // 0x8007C1F0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007C1F4: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007C1F8: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x8007C1FC: sh          $v0, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r2;
    // 0x8007C200: lwc1        $f0, 0x15C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X15C);
    // 0x8007C204: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007C208: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007C20C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x8007C210: sh          $v0, 0x1A($s1)
    MEM_H(0X1A, ctx->r17) = ctx->r2;
    // 0x8007C214: lwc1        $f0, 0x160($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X160);
    // 0x8007C218: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007C21C: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007C220: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x8007C224: sh          $v0, 0x1C($s1)
    MEM_H(0X1C, ctx->r17) = ctx->r2;
L_8007C228:
    // 0x8007C228: lhu         $v1, 0x0($s3)
    ctx->r3 = MEM_HU(ctx->r19, 0X0);
    // 0x8007C22C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8007C230: beq         $v1, $v0, L_8007C240
    if (ctx->r3 == ctx->r2) {
        // 0x8007C234: nop
    
            goto L_8007C240;
    }
    // 0x8007C234: nop

    // 0x8007C238: jal         0x8003ED74
    // 0x8007C23C: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    func_8003ED74(rdram, ctx);
        goto after_30;
    // 0x8007C23C: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    after_30:
L_8007C240:
    // 0x8007C240: lw          $ra, 0x1AC($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1AC);
    // 0x8007C244: lw          $s4, 0x1A8($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X1A8);
    // 0x8007C248: lw          $s3, 0x1A4($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1A4);
    // 0x8007C24C: lw          $s2, 0x1A0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1A0);
    // 0x8007C250: lw          $s1, 0x19C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X19C);
    // 0x8007C254: lw          $s0, 0x198($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X198);
    // 0x8007C258: ldc1        $f20, 0x1B0($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X1B0);
    // 0x8007C25C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007C260: jr          $ra
    // 0x8007C264: addiu       $sp, $sp, 0x1B8
    ctx->r29 = ADD32(ctx->r29, 0X1B8);
    return;
    // 0x8007C264: addiu       $sp, $sp, 0x1B8
    ctx->r29 = ADD32(ctx->r29, 0X1B8);
;}
RECOMP_FUNC void func_8007C268(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C268: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007C26C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8007C270: addiu       $a0, $a0, -0x29DC
    ctx->r4 = ADD32(ctx->r4, -0X29DC);
    // 0x8007C274: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007C278: jal         0x8006488C
    // 0x8007C27C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    load_asset(rdram, ctx);
        goto after_0;
    // 0x8007C27C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x8007C280: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007C284: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x8007C288: sw          $v0, -0x5690($s0)
    MEM_W(-0X5690, ctx->r16) = ctx->r2;
    // 0x8007C28C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8007C290: jr          $ra
    // 0x8007C294: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8007C294: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void fake_func_8007C298(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_8007C2A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C2A0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8007C2A4: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x8007C2A8: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8007C2AC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8007C2B0: lw          $s1, 0x4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X4);
    // 0x8007C2B4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8007C2B8: lw          $s0, 0x34($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X34);
    // 0x8007C2BC: lw          $v1, 0x38($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X38);
    // 0x8007C2C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007C2C4: sh          $zero, 0xAC($s1)
    MEM_H(0XAC, ctx->r17) = 0;
    // 0x8007C2C8: sb          $v0, 0x1A7($v1)
    MEM_B(0X1A7, ctx->r3) = ctx->r2;
    // 0x8007C2CC: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x8007C2D0: jal         0x800F2070
    // 0x8007C2D4: addiu       $a1, $s0, 0x60
    ctx->r5 = ADD32(ctx->r16, 0X60);
    setNpcHealth(rdram, ctx);
        goto after_0;
    // 0x8007C2D4: addiu       $a1, $s0, 0x60
    ctx->r5 = ADD32(ctx->r16, 0X60);
    after_0:
    // 0x8007C2D8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8007C2DC: lw          $v0, 0x7CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7CE4);
    // 0x8007C2E0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007C2E4: lwc1        $f0, -0x2994($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2994);
    // 0x8007C2E8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8007C2EC: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8007C2F0: lwc1        $f2, 0x88($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X88);
    // 0x8007C2F4: lh          $v1, 0xA4($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XA4);
    // 0x8007C2F8: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8007C2FC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007C300: lwc1        $f0, -0x2990($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2990);
    // 0x8007C304: sw          $zero, 0x9C($s1)
    MEM_W(0X9C, ctx->r17) = 0;
    // 0x8007C308: sh          $zero, 0xAE($s1)
    MEM_H(0XAE, ctx->r17) = 0;
    // 0x8007C30C: swc1        $f0, 0x98($s1)
    MEM_W(0X98, ctx->r17) = ctx->f0.u32l;
    // 0x8007C310: swc1        $f2, 0x94($s1)
    MEM_W(0X94, ctx->r17) = ctx->f2.u32l;
    // 0x8007C314: lwc1        $f6, 0x84($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X84);
    // 0x8007C318: lwc1        $f4, 0x8C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8C);
    // 0x8007C31C: lwc1        $f8, 0x90($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X90);
    // 0x8007C320: lwc1        $f2, 0x94($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X94);
    // 0x8007C324: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8007C328: beql        $v1, $v0, L_8007C384
    if (ctx->r3 == ctx->r2) {
        // 0x8007C32C: swc1        $f2, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
            goto L_8007C384;
    }
    goto skip_0;
    // 0x8007C32C: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    skip_0:
    // 0x8007C330: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007C334: lwc1        $f0, -0x298C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X298C);
    // 0x8007C338: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8007C33C: nop

    // 0x8007C340: bc1tl       L_8007C348
    if (c1cs) {
        // 0x8007C344: mov.s       $f4, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.fl = ctx->f0.fl;
            goto L_8007C348;
    }
    goto skip_1;
    // 0x8007C344: mov.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.fl = ctx->f0.fl;
    skip_1:
L_8007C348:
    // 0x8007C348: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8007C34C: nop

    // 0x8007C350: bc1tl       L_8007C358
    if (c1cs) {
        // 0x8007C354: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_8007C358;
    }
    goto skip_2;
    // 0x8007C354: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_2:
L_8007C358:
    // 0x8007C358: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007C35C: lwc1        $f0, -0x2988($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2988);
    // 0x8007C360: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8007C364: nop

    // 0x8007C368: bc1tl       L_8007C370
    if (c1cs) {
        // 0x8007C36C: mov.s       $f6, $f0
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.fl = ctx->f0.fl;
            goto L_8007C370;
    }
    goto skip_3;
    // 0x8007C36C: mov.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.fl = ctx->f0.fl;
    skip_3:
L_8007C370:
    // 0x8007C370: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8007C374: nop

    // 0x8007C378: bc1tl       L_8007C380
    if (c1cs) {
        // 0x8007C37C: mov.s       $f8, $f0
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.fl = ctx->f0.fl;
            goto L_8007C380;
    }
    goto skip_4;
    // 0x8007C37C: mov.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.fl = ctx->f0.fl;
    skip_4:
L_8007C380:
    // 0x8007C380: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
L_8007C384:
    // 0x8007C384: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x8007C388: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8007C38C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8007C390: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8007C394: jal         0x800F2888
    // 0x8007C398: nop

    func_800F2888(rdram, ctx);
        goto after_1;
    // 0x8007C398: nop

    after_1:
    // 0x8007C39C: lh          $v1, 0xA4($s1)
    ctx->r3 = MEM_H(ctx->r17, 0XA4);
    // 0x8007C3A0: sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x8007C3A4: beq         $v0, $zero, L_8007C4D0
    if (ctx->r2 == 0) {
        // 0x8007C3A8: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_8007C4D0;
    }
    // 0x8007C3A8: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8007C3AC: addiu       $v0, $v0, -0x2980
    ctx->r2 = ADD32(ctx->r2, -0X2980);
    // 0x8007C3B0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8007C3B4: addu        $v1, $v1, $v0
    gpr jr_addend_8007C3BC = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8007C3B8: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x8007C3BC: jr          $v0
    // 0x8007C3C0: nop

    switch (jr_addend_8007C3BC >> 2) {
        case 0: goto L_8007C3C4; break;
        case 1: goto L_8007C3D0; break;
        case 2: goto L_8007C3DC; break;
        case 3: goto L_8007C3E8; break;
        case 4: goto L_8007C454; break;
        default: switch_error(__func__, 0x8007C3BC, 0x8003D680);
    }
    // 0x8007C3C0: nop

L_8007C3C4:
    // 0x8007C3C4: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8007C3C8: j           L_8007C3F0
    // 0x8007C3CC: addiu       $v0, $v0, -0x3B10
    ctx->r2 = ADD32(ctx->r2, -0X3B10);
        goto L_8007C3F0;
    // 0x8007C3CC: addiu       $v0, $v0, -0x3B10
    ctx->r2 = ADD32(ctx->r2, -0X3B10);
L_8007C3D0:
    // 0x8007C3D0: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8007C3D4: j           L_8007C3F0
    // 0x8007C3D8: addiu       $v0, $v0, -0x3650
    ctx->r2 = ADD32(ctx->r2, -0X3650);
        goto L_8007C3F0;
    // 0x8007C3D8: addiu       $v0, $v0, -0x3650
    ctx->r2 = ADD32(ctx->r2, -0X3650);
L_8007C3DC:
    // 0x8007C3DC: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8007C3E0: j           L_8007C3F0
    // 0x8007C3E4: addiu       $v0, $v0, -0x394C
    ctx->r2 = ADD32(ctx->r2, -0X394C);
        goto L_8007C3F0;
    // 0x8007C3E4: addiu       $v0, $v0, -0x394C
    ctx->r2 = ADD32(ctx->r2, -0X394C);
L_8007C3E8:
    // 0x8007C3E8: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8007C3EC: addiu       $v0, $v0, -0x3788
    ctx->r2 = ADD32(ctx->r2, -0X3788);
L_8007C3F0:
    // 0x8007C3F0: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8007C3F4: lwc1        $f0, 0xA4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XA4);
    // 0x8007C3F8: addiu       $v1, $v1, 0xD9C
    ctx->r3 = ADD32(ctx->r3, 0XD9C);
    // 0x8007C3FC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8007C400: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8007C404: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8007C408: lh          $a0, 0xA4($s1)
    ctx->r4 = MEM_H(ctx->r17, 0XA4);
    // 0x8007C40C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007C410: lwc1        $f0, -0x296C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X296C);
    // 0x8007C414: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x8007C418: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x8007C41C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8007C420: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8007C424: lwc1        $f2, 0x24($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8007C428: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8007C42C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8007C430: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x8007C434: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x8007C438: lw          $a1, 0x98($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X98);
    // 0x8007C43C: lw          $a2, 0x9C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X9C);
    // 0x8007C440: lw          $a3, 0xA0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XA0);
    // 0x8007C444: jal         0x800F2B88
    // 0x8007C448: nop

    func_800F2B88(rdram, ctx);
        goto after_2;
    // 0x8007C448: nop

    after_2:
    // 0x8007C44C: j           L_8007C4D0
    // 0x8007C450: nop

        goto L_8007C4D0;
    // 0x8007C450: nop

L_8007C454:
    // 0x8007C454: lui         $v0, 0x8008
    ctx->r2 = S32(0X8008 << 16);
    // 0x8007C458: addiu       $v0, $v0, -0x3518
    ctx->r2 = ADD32(ctx->r2, -0X3518);
    // 0x8007C45C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8007C460: lwc1        $f0, 0xA4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XA4);
    // 0x8007C464: addiu       $v1, $v1, 0xD9C
    ctx->r3 = ADD32(ctx->r3, 0XD9C);
    // 0x8007C468: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x8007C46C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8007C470: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8007C474: lh          $a0, 0xA4($s1)
    ctx->r4 = MEM_H(ctx->r17, 0XA4);
    // 0x8007C478: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007C47C: lwc1        $f0, -0x2968($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2968);
    // 0x8007C480: sll         $v0, $a0, 4
    ctx->r2 = S32(ctx->r4 << 4);
    // 0x8007C484: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x8007C488: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8007C48C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8007C490: lwc1        $f2, 0x24($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8007C494: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8007C498: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8007C49C: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x8007C4A0: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x8007C4A4: lw          $a1, 0x98($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X98);
    // 0x8007C4A8: lw          $a2, 0x9C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X9C);
    // 0x8007C4AC: lw          $a3, 0xA0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XA0);
    // 0x8007C4B0: jal         0x800F2B88
    // 0x8007C4B4: nop

    func_800F2B88(rdram, ctx);
        goto after_3;
    // 0x8007C4B4: nop

    after_3:
    // 0x8007C4B8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8007C4BC: lw          $v0, 0x7CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7CE4);
    // 0x8007C4C0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8007C4C4: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8007C4C8: lw          $v0, 0xA8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XA8);
    // 0x8007C4CC: sw          $v0, 0xA0($s1)
    MEM_W(0XA0, ctx->r17) = ctx->r2;
L_8007C4D0:
    // 0x8007C4D0: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x8007C4D4: jal         0x800F2830
    // 0x8007C4D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    func_800F2830(rdram, ctx);
        goto after_4;
    // 0x8007C4D8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x8007C4DC: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x8007C4E0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8007C4E4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8007C4E8: jr          $ra
    // 0x8007C4EC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8007C4EC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_8007C4F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C4F0: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x8007C4F4: sw          $s0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r16;
    // 0x8007C4F8: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x8007C4FC: addiu       $s0, $s0, -0x2964
    ctx->r16 = ADD32(ctx->r16, -0X2964);
    // 0x8007C500: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8007C504: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8007C508: sw          $ra, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r31;
    // 0x8007C50C: sw          $s3, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r19;
    // 0x8007C510: sw          $s2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r18;
    // 0x8007C514: sw          $s1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r17;
    // 0x8007C518: sdc1        $f20, 0xD8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XD8, ctx->r29);
    // 0x8007C51C: lw          $s2, 0x4($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X4);
    // 0x8007C520: addiu       $s1, $sp, 0x88
    ctx->r17 = ADD32(ctx->r29, 0X88);
    // 0x8007C524: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x8007C528: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8007C52C: lw          $a0, 0x30($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X30);
    // 0x8007C530: jal         0x80058360
    // 0x8007C534: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    func_80058360(rdram, ctx);
        goto after_0;
    // 0x8007C534: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x8007C538: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8007C53C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8007C540: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x8007C544: addiu       $s3, $sp, 0x58
    ctx->r19 = ADD32(ctx->r29, 0X58);
    // 0x8007C548: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x8007C54C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8007C550: lw          $a0, 0x30($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X30);
    // 0x8007C554: jal         0x80058360
    // 0x8007C558: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    func_80058360(rdram, ctx);
        goto after_1;
    // 0x8007C558: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    after_1:
    // 0x8007C55C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8007C560: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007C564: lwc1        $f20, -0x2960($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X2960);
    // 0x8007C568: addiu       $v0, $sp, 0xB8
    ctx->r2 = ADD32(ctx->r29, 0XB8);
    // 0x8007C56C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8007C570: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x8007C574: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8007C578: jal         0x800F2F10
    // 0x8007C57C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_800F2F10(rdram, ctx);
        goto after_2;
    // 0x8007C57C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_2:
    // 0x8007C580: andi        $s1, $v0, 0xFF
    ctx->r17 = ctx->r2 & 0XFF;
    // 0x8007C584: bne         $s1, $s0, L_8007C690
    if (ctx->r17 != ctx->r16) {
        // 0x8007C588: addu        $a1, $s3, $zero
        ctx->r5 = ADD32(ctx->r19, 0);
            goto L_8007C690;
    }
    // 0x8007C588: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8007C58C: addiu       $v0, $sp, 0xBC
    ctx->r2 = ADD32(ctx->r29, 0XBC);
    // 0x8007C590: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8007C594: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x8007C598: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8007C59C: jal         0x800F2F10
    // 0x8007C5A0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_800F2F10(rdram, ctx);
        goto after_3;
    // 0x8007C5A0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_3:
    // 0x8007C5A4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8007C5A8: bne         $v0, $s1, L_8007C690
    if (ctx->r2 != ctx->r17) {
        // 0x8007C5AC: lui         $s0, 0x800A
        ctx->r16 = S32(0X800A << 16);
            goto L_8007C690;
    }
    // 0x8007C5AC: lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // 0x8007C5B0: addiu       $s0, $s0, 0xDB4
    ctx->r16 = ADD32(ctx->r16, 0XDB4);
    // 0x8007C5B4: addiu       $s1, $s0, -0x18
    ctx->r17 = ADD32(ctx->r16, -0X18);
    // 0x8007C5B8: lh          $t0, 0xA4($s2)
    ctx->r8 = MEM_H(ctx->r18, 0XA4);
    // 0x8007C5BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8007C5C0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8007C5C4: lh          $v1, 0xA4($s2)
    ctx->r3 = MEM_H(ctx->r18, 0XA4);
    // 0x8007C5C8: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x8007C5CC: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x8007C5D0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8007C5D4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8007C5D8: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x8007C5DC: sll         $a3, $t0, 4
    ctx->r7 = S32(ctx->r8 << 4);
    // 0x8007C5E0: lwc1        $f0, 0x24($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8007C5E4: subu        $a3, $a3, $t0
    ctx->r7 = SUB32(ctx->r7, ctx->r8);
    // 0x8007C5E8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8007C5EC: lwc1        $f0, 0xB8($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x8007C5F0: sllv        $a3, $a3, $a1
    ctx->r7 = S32(ctx->r7 << (ctx->r5 & 31));
    // 0x8007C5F4: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8007C5F8: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x8007C5FC: jal         0x800F2FCC
    // 0x8007C600: addu        $a3, $a3, $s0
    ctx->r7 = ADD32(ctx->r7, ctx->r16);
    func_800F2FCC(rdram, ctx);
        goto after_4;
    // 0x8007C600: addu        $a3, $a3, $s0
    ctx->r7 = ADD32(ctx->r7, ctx->r16);
    after_4:
    // 0x8007C604: lh          $t0, 0xA4($s2)
    ctx->r8 = MEM_H(ctx->r18, 0XA4);
    // 0x8007C608: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8007C60C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8007C610: lh          $v1, 0xA4($s2)
    ctx->r3 = MEM_H(ctx->r18, 0XA4);
    // 0x8007C614: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x8007C618: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x8007C61C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8007C620: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8007C624: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x8007C628: sll         $a3, $t0, 4
    ctx->r7 = S32(ctx->r8 << 4);
    // 0x8007C62C: lwc1        $f0, 0x24($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8007C630: subu        $a3, $a3, $t0
    ctx->r7 = SUB32(ctx->r7, ctx->r8);
    // 0x8007C634: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8007C638: lwc1        $f0, 0xBC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x8007C63C: sllv        $a3, $a3, $a1
    ctx->r7 = S32(ctx->r7 << (ctx->r5 & 31));
    // 0x8007C640: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8007C644: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x8007C648: jal         0x800F2FCC
    // 0x8007C64C: addu        $a3, $a3, $s0
    ctx->r7 = ADD32(ctx->r7, ctx->r16);
    func_800F2FCC(rdram, ctx);
        goto after_5;
    // 0x8007C64C: addu        $a3, $a3, $s0
    ctx->r7 = ADD32(ctx->r7, ctx->r16);
    after_5:
    // 0x8007C650: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8007C654: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8007C658: addiu       $a2, $s2, 0x24
    ctx->r6 = ADD32(ctx->r18, 0X24);
    // 0x8007C65C: lui         $a3, 0x4140
    ctx->r7 = S32(0X4140 << 16);
    // 0x8007C660: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007C664: lwc1        $f0, -0x295C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X295C);
    // 0x8007C668: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
    // 0x8007C66C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8007C670: addiu       $v0, $zero, 0x6E
    ctx->r2 = ADD32(0, 0X6E);
    // 0x8007C674: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8007C678: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x8007C67C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8007C680: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8007C684: jal         0x800989D8
    // 0x8007C688: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800989D8(rdram, ctx);
        goto after_6;
    // 0x8007C688: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x8007C68C: sw          $zero, 0x98($s2)
    MEM_W(0X98, ctx->r18) = 0;
L_8007C690:
    // 0x8007C690: lw          $ra, 0xD0($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XD0);
    // 0x8007C694: lw          $s3, 0xCC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XCC);
    // 0x8007C698: lw          $s2, 0xC8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC8);
    // 0x8007C69C: lw          $s1, 0xC4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC4);
    // 0x8007C6A0: lw          $s0, 0xC0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XC0);
    // 0x8007C6A4: ldc1        $f20, 0xD8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XD8);
    // 0x8007C6A8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8007C6AC: jr          $ra
    // 0x8007C6B0: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    return;
    // 0x8007C6B0: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
;}
RECOMP_FUNC void func_8007C6B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C6B4: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x8007C6B8: sw          $s0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r16;
    // 0x8007C6BC: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x8007C6C0: addiu       $s0, $s0, -0x2964
    ctx->r16 = ADD32(ctx->r16, -0X2964);
    // 0x8007C6C4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8007C6C8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8007C6CC: sw          $ra, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r31;
    // 0x8007C6D0: sw          $s3, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r19;
    // 0x8007C6D4: sw          $s2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r18;
    // 0x8007C6D8: sw          $s1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r17;
    // 0x8007C6DC: sdc1        $f20, 0xD8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XD8, ctx->r29);
    // 0x8007C6E0: lw          $s2, 0x4($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X4);
    // 0x8007C6E4: addiu       $s1, $sp, 0x88
    ctx->r17 = ADD32(ctx->r29, 0X88);
    // 0x8007C6E8: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x8007C6EC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8007C6F0: lw          $a0, 0x30($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X30);
    // 0x8007C6F4: jal         0x80058360
    // 0x8007C6F8: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    func_80058360(rdram, ctx);
        goto after_0;
    // 0x8007C6F8: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x8007C6FC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8007C700: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8007C704: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x8007C708: addiu       $s3, $sp, 0x58
    ctx->r19 = ADD32(ctx->r29, 0X58);
    // 0x8007C70C: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x8007C710: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8007C714: lw          $a0, 0x30($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X30);
    // 0x8007C718: jal         0x80058360
    // 0x8007C71C: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    func_80058360(rdram, ctx);
        goto after_1;
    // 0x8007C71C: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    after_1:
    // 0x8007C720: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8007C724: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007C728: lwc1        $f20, -0x2958($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X2958);
    // 0x8007C72C: addiu       $v0, $sp, 0xB8
    ctx->r2 = ADD32(ctx->r29, 0XB8);
    // 0x8007C730: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8007C734: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x8007C738: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8007C73C: jal         0x800F2F10
    // 0x8007C740: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_800F2F10(rdram, ctx);
        goto after_2;
    // 0x8007C740: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_2:
    // 0x8007C744: andi        $s1, $v0, 0xFF
    ctx->r17 = ctx->r2 & 0XFF;
    // 0x8007C748: bne         $s1, $s0, L_8007C854
    if (ctx->r17 != ctx->r16) {
        // 0x8007C74C: addu        $a1, $s3, $zero
        ctx->r5 = ADD32(ctx->r19, 0);
            goto L_8007C854;
    }
    // 0x8007C74C: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8007C750: addiu       $v0, $sp, 0xBC
    ctx->r2 = ADD32(ctx->r29, 0XBC);
    // 0x8007C754: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8007C758: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x8007C75C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8007C760: jal         0x800F2F10
    // 0x8007C764: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_800F2F10(rdram, ctx);
        goto after_3;
    // 0x8007C764: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_3:
    // 0x8007C768: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8007C76C: bne         $v0, $s1, L_8007C854
    if (ctx->r2 != ctx->r17) {
        // 0x8007C770: lui         $s0, 0x800A
        ctx->r16 = S32(0X800A << 16);
            goto L_8007C854;
    }
    // 0x8007C770: lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // 0x8007C774: addiu       $s0, $s0, 0xDB4
    ctx->r16 = ADD32(ctx->r16, 0XDB4);
    // 0x8007C778: addiu       $s1, $s0, -0x18
    ctx->r17 = ADD32(ctx->r16, -0X18);
    // 0x8007C77C: lh          $t0, 0xA4($s2)
    ctx->r8 = MEM_H(ctx->r18, 0XA4);
    // 0x8007C780: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8007C784: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8007C788: lh          $v1, 0xA4($s2)
    ctx->r3 = MEM_H(ctx->r18, 0XA4);
    // 0x8007C78C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x8007C790: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x8007C794: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8007C798: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8007C79C: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x8007C7A0: sll         $a3, $t0, 4
    ctx->r7 = S32(ctx->r8 << 4);
    // 0x8007C7A4: lwc1        $f0, 0x24($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8007C7A8: subu        $a3, $a3, $t0
    ctx->r7 = SUB32(ctx->r7, ctx->r8);
    // 0x8007C7AC: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8007C7B0: lwc1        $f0, 0xB8($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x8007C7B4: sllv        $a3, $a3, $a1
    ctx->r7 = S32(ctx->r7 << (ctx->r5 & 31));
    // 0x8007C7B8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8007C7BC: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x8007C7C0: jal         0x800F2FCC
    // 0x8007C7C4: addu        $a3, $a3, $s0
    ctx->r7 = ADD32(ctx->r7, ctx->r16);
    func_800F2FCC(rdram, ctx);
        goto after_4;
    // 0x8007C7C4: addu        $a3, $a3, $s0
    ctx->r7 = ADD32(ctx->r7, ctx->r16);
    after_4:
    // 0x8007C7C8: lh          $t0, 0xA4($s2)
    ctx->r8 = MEM_H(ctx->r18, 0XA4);
    // 0x8007C7CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8007C7D0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8007C7D4: lh          $v1, 0xA4($s2)
    ctx->r3 = MEM_H(ctx->r18, 0XA4);
    // 0x8007C7D8: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x8007C7DC: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x8007C7E0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8007C7E4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8007C7E8: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x8007C7EC: sll         $a3, $t0, 4
    ctx->r7 = S32(ctx->r8 << 4);
    // 0x8007C7F0: lwc1        $f0, 0x24($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8007C7F4: subu        $a3, $a3, $t0
    ctx->r7 = SUB32(ctx->r7, ctx->r8);
    // 0x8007C7F8: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8007C7FC: lwc1        $f0, 0xBC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x8007C800: sllv        $a3, $a3, $a1
    ctx->r7 = S32(ctx->r7 << (ctx->r5 & 31));
    // 0x8007C804: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8007C808: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x8007C80C: jal         0x800F2FCC
    // 0x8007C810: addu        $a3, $a3, $s0
    ctx->r7 = ADD32(ctx->r7, ctx->r16);
    func_800F2FCC(rdram, ctx);
        goto after_5;
    // 0x8007C810: addu        $a3, $a3, $s0
    ctx->r7 = ADD32(ctx->r7, ctx->r16);
    after_5:
    // 0x8007C814: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8007C818: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8007C81C: addiu       $a2, $s2, 0x24
    ctx->r6 = ADD32(ctx->r18, 0X24);
    // 0x8007C820: lui         $a3, 0x4140
    ctx->r7 = S32(0X4140 << 16);
    // 0x8007C824: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007C828: lwc1        $f0, -0x2954($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2954);
    // 0x8007C82C: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
    // 0x8007C830: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8007C834: addiu       $v0, $zero, 0x6E
    ctx->r2 = ADD32(0, 0X6E);
    // 0x8007C838: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8007C83C: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x8007C840: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8007C844: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8007C848: jal         0x800989D8
    // 0x8007C84C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800989D8(rdram, ctx);
        goto after_6;
    // 0x8007C84C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x8007C850: sw          $zero, 0x98($s2)
    MEM_W(0X98, ctx->r18) = 0;
L_8007C854:
    // 0x8007C854: lw          $ra, 0xD0($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XD0);
    // 0x8007C858: lw          $s3, 0xCC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XCC);
    // 0x8007C85C: lw          $s2, 0xC8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC8);
    // 0x8007C860: lw          $s1, 0xC4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC4);
    // 0x8007C864: lw          $s0, 0xC0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XC0);
    // 0x8007C868: ldc1        $f20, 0xD8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XD8);
    // 0x8007C86C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8007C870: jr          $ra
    // 0x8007C874: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    return;
    // 0x8007C874: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
;}
RECOMP_FUNC void func_8007C878(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C878: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8007C87C: sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // 0x8007C880: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x8007C884: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8007C888: sw          $ra, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r31;
    // 0x8007C88C: sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // 0x8007C890: lw          $s0, 0x4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X4);
    // 0x8007C894: beq         $s1, $v0, L_8007C8C0
    if (ctx->r17 == ctx->r2) {
        // 0x8007C898: lui         $a1, 0x8004
        ctx->r5 = S32(0X8004 << 16);
            goto L_8007C8C0;
    }
    // 0x8007C898: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8007C89C: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x8007C8A0: lui         $a1, 0x3D88
    ctx->r5 = S32(0X3D88 << 16);
    // 0x8007C8A4: ori         $a1, $a1, 0x8889
    ctx->r5 = ctx->r5 | 0X8889;
    // 0x8007C8A8: jal         0x800F2D74
    // 0x8007C8AC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_800F2D74(rdram, ctx);
        goto after_0;
    // 0x8007C8AC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_0:
    // 0x8007C8B0: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8007C8B4: addiu       $a1, $a1, -0x2950
    ctx->r5 = ADD32(ctx->r5, -0X2950);
    // 0x8007C8B8: j           L_8007C8C8
    // 0x8007C8BC: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
        goto L_8007C8C8;
    // 0x8007C8BC: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
L_8007C8C0:
    // 0x8007C8C0: addiu       $a1, $a1, -0x2950
    ctx->r5 = ADD32(ctx->r5, -0X2950);
    // 0x8007C8C4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
L_8007C8C8:
    // 0x8007C8C8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8007C8CC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8007C8D0: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x8007C8D4: jal         0x80058360
    // 0x8007C8D8: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    func_80058360(rdram, ctx);
        goto after_1;
    // 0x8007C8D8: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x8007C8DC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8007C8E0: addiu       $v0, $sp, 0x58
    ctx->r2 = ADD32(ctx->r29, 0X58);
    // 0x8007C8E4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8007C8E8: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x8007C8EC: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x8007C8F0: jal         0x800F2F10
    // 0x8007C8F4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_800F2F10(rdram, ctx);
        goto after_2;
    // 0x8007C8F4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_2:
    // 0x8007C8F8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8007C8FC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8007C900: bne         $v0, $v1, L_8007C998
    if (ctx->r2 != ctx->r3) {
        // 0x8007C904: lui         $t0, 0x800A
        ctx->r8 = S32(0X800A << 16);
            goto L_8007C998;
    }
    // 0x8007C904: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x8007C908: addiu       $t0, $t0, 0xDB4
    ctx->r8 = ADD32(ctx->r8, 0XDB4);
    // 0x8007C90C: lh          $t1, 0xA4($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XA4);
    // 0x8007C910: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8007C914: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8007C918: lh          $v1, 0xA4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XA4);
    // 0x8007C91C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x8007C920: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x8007C924: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8007C928: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8007C92C: addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // 0x8007C930: sll         $a3, $t1, 4
    ctx->r7 = S32(ctx->r9 << 4);
    // 0x8007C934: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8007C938: subu        $a3, $a3, $t1
    ctx->r7 = SUB32(ctx->r7, ctx->r9);
    // 0x8007C93C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8007C940: lwc1        $f0, 0x58($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8007C944: sllv        $a3, $a3, $a1
    ctx->r7 = S32(ctx->r7 << (ctx->r5 & 31));
    // 0x8007C948: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8007C94C: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x8007C950: jal         0x800F2FCC
    // 0x8007C954: addu        $a3, $a3, $t0
    ctx->r7 = ADD32(ctx->r7, ctx->r8);
    func_800F2FCC(rdram, ctx);
        goto after_3;
    // 0x8007C954: addu        $a3, $a3, $t0
    ctx->r7 = ADD32(ctx->r7, ctx->r8);
    after_3:
    // 0x8007C958: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8007C95C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8007C960: addiu       $a2, $s0, 0x24
    ctx->r6 = ADD32(ctx->r16, 0X24);
    // 0x8007C964: lui         $a3, 0x4140
    ctx->r7 = S32(0X4140 << 16);
    // 0x8007C968: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007C96C: lwc1        $f0, -0x2948($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2948);
    // 0x8007C970: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
    // 0x8007C974: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8007C978: addiu       $v0, $zero, 0x6E
    ctx->r2 = ADD32(0, 0X6E);
    // 0x8007C97C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8007C980: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x8007C984: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8007C988: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8007C98C: jal         0x800989D8
    // 0x8007C990: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800989D8(rdram, ctx);
        goto after_4;
    // 0x8007C990: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x8007C994: sw          $zero, 0x98($s0)
    MEM_W(0X98, ctx->r16) = 0;
L_8007C998:
    // 0x8007C998: lw          $ra, 0x68($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X68);
    // 0x8007C99C: lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X64);
    // 0x8007C9A0: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x8007C9A4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8007C9A8: jr          $ra
    // 0x8007C9AC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8007C9AC: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_8007C9B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C9B0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8007C9B4: sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // 0x8007C9B8: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x8007C9BC: sw          $ra, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r31;
    // 0x8007C9C0: sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // 0x8007C9C4: lw          $s0, 0x4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X4);
    // 0x8007C9C8: beq         $s1, $zero, L_8007C9E0
    if (ctx->r17 == 0) {
        // 0x8007C9CC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8007C9E0;
    }
    // 0x8007C9CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007C9D0: beq         $s1, $v0, L_8007C9F4
    if (ctx->r17 == ctx->r2) {
        // 0x8007C9D4: addiu       $a1, $sp, 0x28
        ctx->r5 = ADD32(ctx->r29, 0X28);
            goto L_8007C9F4;
    }
    // 0x8007C9D4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8007C9D8: j           L_8007CA1C
    // 0x8007C9DC: addiu       $v0, $sp, 0x58
    ctx->r2 = ADD32(ctx->r29, 0X58);
        goto L_8007CA1C;
    // 0x8007C9DC: addiu       $v0, $sp, 0x58
    ctx->r2 = ADD32(ctx->r29, 0X58);
L_8007C9E0:
    // 0x8007C9E0: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x8007C9E4: lui         $a1, 0x3D08
    ctx->r5 = S32(0X3D08 << 16);
    // 0x8007C9E8: ori         $a1, $a1, 0x8889
    ctx->r5 = ctx->r5 | 0X8889;
    // 0x8007C9EC: jal         0x800F2D74
    // 0x8007C9F0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_800F2D74(rdram, ctx);
        goto after_0;
    // 0x8007C9F0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_0:
L_8007C9F4:
    // 0x8007C9F4: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8007C9F8: addiu       $a1, $a1, -0x2964
    ctx->r5 = ADD32(ctx->r5, -0X2964);
    // 0x8007C9FC: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8007CA00: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8007CA04: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8007CA08: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x8007CA0C: jal         0x80058360
    // 0x8007CA10: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    func_80058360(rdram, ctx);
        goto after_1;
    // 0x8007CA10: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x8007CA14: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8007CA18: addiu       $v0, $sp, 0x58
    ctx->r2 = ADD32(ctx->r29, 0X58);
L_8007CA1C:
    // 0x8007CA1C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8007CA20: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x8007CA24: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x8007CA28: jal         0x800F2F10
    // 0x8007CA2C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_800F2F10(rdram, ctx);
        goto after_2;
    // 0x8007CA2C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_2:
    // 0x8007CA30: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8007CA34: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8007CA38: bne         $v0, $v1, L_8007CAD0
    if (ctx->r2 != ctx->r3) {
        // 0x8007CA3C: lui         $t0, 0x800A
        ctx->r8 = S32(0X800A << 16);
            goto L_8007CAD0;
    }
    // 0x8007CA3C: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x8007CA40: addiu       $t0, $t0, 0xDB4
    ctx->r8 = ADD32(ctx->r8, 0XDB4);
    // 0x8007CA44: lh          $t1, 0xA4($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XA4);
    // 0x8007CA48: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8007CA4C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8007CA50: lh          $v1, 0xA4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0XA4);
    // 0x8007CA54: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x8007CA58: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x8007CA5C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8007CA60: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8007CA64: addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // 0x8007CA68: sll         $a3, $t1, 4
    ctx->r7 = S32(ctx->r9 << 4);
    // 0x8007CA6C: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8007CA70: subu        $a3, $a3, $t1
    ctx->r7 = SUB32(ctx->r7, ctx->r9);
    // 0x8007CA74: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8007CA78: lwc1        $f0, 0x58($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8007CA7C: sllv        $a3, $a3, $a1
    ctx->r7 = S32(ctx->r7 << (ctx->r5 & 31));
    // 0x8007CA80: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8007CA84: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x8007CA88: jal         0x800F2FCC
    // 0x8007CA8C: addu        $a3, $a3, $t0
    ctx->r7 = ADD32(ctx->r7, ctx->r8);
    func_800F2FCC(rdram, ctx);
        goto after_3;
    // 0x8007CA8C: addu        $a3, $a3, $t0
    ctx->r7 = ADD32(ctx->r7, ctx->r8);
    after_3:
    // 0x8007CA90: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8007CA94: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8007CA98: addiu       $a2, $s0, 0x24
    ctx->r6 = ADD32(ctx->r16, 0X24);
    // 0x8007CA9C: lui         $a3, 0x4140
    ctx->r7 = S32(0X4140 << 16);
    // 0x8007CAA0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007CAA4: lwc1        $f0, -0x2944($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2944);
    // 0x8007CAA8: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
    // 0x8007CAAC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8007CAB0: addiu       $v0, $zero, 0x6E
    ctx->r2 = ADD32(0, 0X6E);
    // 0x8007CAB4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8007CAB8: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x8007CABC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8007CAC0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8007CAC4: jal         0x800989D8
    // 0x8007CAC8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800989D8(rdram, ctx);
        goto after_4;
    // 0x8007CAC8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x8007CACC: sw          $zero, 0x98($s0)
    MEM_W(0X98, ctx->r16) = 0;
L_8007CAD0:
    // 0x8007CAD0: lw          $ra, 0x68($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X68);
    // 0x8007CAD4: lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X64);
    // 0x8007CAD8: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x8007CADC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8007CAE0: jr          $ra
    // 0x8007CAE4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8007CAE4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_8007CAE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CAE8: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x8007CAEC: sw          $ra, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r31;
    // 0x8007CAF0: sw          $s3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r19;
    // 0x8007CAF4: sw          $s2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r18;
    // 0x8007CAF8: sw          $s1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r17;
    // 0x8007CAFC: sw          $s0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r16;
    // 0x8007CB00: lw          $s2, 0x4($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X4);
    // 0x8007CB04: lw          $a0, 0x34($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X34);
    // 0x8007CB08: lw          $v1, 0xBC($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XBC);
    // 0x8007CB0C: beq         $v1, $zero, L_8007CB2C
    if (ctx->r3 == 0) {
        // 0x8007CB10: addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
            goto L_8007CB2C;
    }
    // 0x8007CB10: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x8007CB14: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8007CB18: addiu       $v0, $v0, -0x7760
    ctx->r2 = ADD32(ctx->r2, -0X7760);
    // 0x8007CB1C: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x8007CB20: lbu         $v0, -0x1($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X1);
    // 0x8007CB24: beq         $v0, $zero, L_8007CD68
    if (ctx->r2 == 0) {
        // 0x8007CB28: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8007CD68;
    }
    // 0x8007CB28: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8007CB2C:
    // 0x8007CB2C: lw          $v0, 0xC0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC0);
    // 0x8007CB30: beq         $v0, $zero, L_8007CB5C
    if (ctx->r2 == 0) {
        // 0x8007CB34: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_8007CB5C;
    }
    // 0x8007CB34: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8007CB38: addiu       $v1, $v1, -0x7FA0
    ctx->r3 = ADD32(ctx->r3, -0X7FA0);
    // 0x8007CB3C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8007CB40: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8007CB44: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8007CB48: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8007CB4C: lw          $v1, 0xC4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XC4);
    // 0x8007CB50: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007CB54: bne         $v0, $zero, L_8007CD68
    if (ctx->r2 != 0) {
        // 0x8007CB58: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8007CD68;
    }
    // 0x8007CB58: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8007CB5C:
    // 0x8007CB5C: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x8007CB60: jal         0x800F2988
    // 0x8007CB64: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    func_800F2988(rdram, ctx);
        goto after_0;
    // 0x8007CB64: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x8007CB68: lw          $v1, 0x34($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X34);
    // 0x8007CB6C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007CB70: lwc1        $f2, -0x293C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X293C);
    // 0x8007CB74: lwc1        $f0, 0xB4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XB4);
    // 0x8007CB78: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007CB7C: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8007CB80: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8007CB84: nop

    // 0x8007CB88: bc1t        L_8007CD68
    if (c1cs) {
        // 0x8007CB8C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8007CD68;
    }
    // 0x8007CB8C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8007CB90: lh          $v0, 0xAE($s2)
    ctx->r2 = MEM_H(ctx->r18, 0XAE);
    // 0x8007CB94: slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8007CB98: beq         $v0, $zero, L_8007CBAC
    if (ctx->r2 == 0) {
        // 0x8007CB9C: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_8007CBAC;
    }
    // 0x8007CB9C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8007CBA0: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8007CBA4: j           L_8007CBB0
    // 0x8007CBA8: addiu       $a1, $v0, -0x2964
    ctx->r5 = ADD32(ctx->r2, -0X2964);
        goto L_8007CBB0;
    // 0x8007CBA8: addiu       $a1, $v0, -0x2964
    ctx->r5 = ADD32(ctx->r2, -0X2964);
L_8007CBAC:
    // 0x8007CBAC: addiu       $a1, $v0, -0x2940
    ctx->r5 = ADD32(ctx->r2, -0X2940);
L_8007CBB0:
    // 0x8007CBB0: lhu         $a2, 0xAE($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0XAE);
    // 0x8007CBB4: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    // 0x8007CBB8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8007CBBC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8007CBC0: lw          $a0, 0x30($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X30);
    // 0x8007CBC4: jal         0x80058360
    // 0x8007CBC8: andi        $a2, $a2, 0x1
    ctx->r6 = ctx->r6 & 0X1;
    func_80058360(rdram, ctx);
        goto after_1;
    // 0x8007CBC8: andi        $a2, $a2, 0x1
    ctx->r6 = ctx->r6 & 0X1;
    after_1:
    // 0x8007CBCC: lh          $a0, 0xAE($s2)
    ctx->r4 = MEM_H(ctx->r18, 0XAE);
    // 0x8007CBD0: addiu       $v1, $a0, 0x1
    ctx->r3 = ADD32(ctx->r4, 0X1);
    // 0x8007CBD4: bgez        $v1, L_8007CBE0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8007CBD8: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_8007CBE0;
    }
    // 0x8007CBD8: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x8007CBDC: addiu       $v0, $a0, 0x4
    ctx->r2 = ADD32(ctx->r4, 0X4);
L_8007CBE0:
    // 0x8007CBE0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8007CBE4: sra         $v0, $v0, 2
    ctx->r2 = S32(SIGNED(ctx->r2) >> 2);
    // 0x8007CBE8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8007CBEC: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // 0x8007CBF0: sh          $v0, 0xAE($s2)
    MEM_H(0XAE, ctx->r18) = ctx->r2;
    // 0x8007CBF4: addiu       $v0, $sp, 0x78
    ctx->r2 = ADD32(ctx->r29, 0X78);
    // 0x8007CBF8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x8007CBFC: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x8007CC00: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    // 0x8007CC04: jal         0x800F2F10
    // 0x8007CC08: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_800F2F10(rdram, ctx);
        goto after_2;
    // 0x8007CC08: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_2:
    // 0x8007CC0C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8007CC10: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8007CC14: bne         $v0, $v1, L_8007CD68
    if (ctx->r2 != ctx->r3) {
        // 0x8007CC18: addu        $v0, $s3, $zero
        ctx->r2 = ADD32(ctx->r19, 0);
            goto L_8007CD68;
    }
    // 0x8007CC18: addu        $v0, $s3, $zero
    ctx->r2 = ADD32(ctx->r19, 0);
    // 0x8007CC1C: sh          $zero, 0x58($sp)
    MEM_H(0X58, ctx->r29) = 0;
    // 0x8007CC20: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x8007CC24: jal         0x800F2A00
    // 0x8007CC28: nop

    func_800F2A00(rdram, ctx);
        goto after_3;
    // 0x8007CC28: nop

    after_3:
    // 0x8007CC2C: sh          $v0, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r2;
    // 0x8007CC30: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8007CC34: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x8007CC38: lw          $v0, 0x7CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7CE4);
    // 0x8007CC3C: addiu       $t0, $t0, 0xDB4
    ctx->r8 = ADD32(ctx->r8, 0XDB4);
    // 0x8007CC40: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    // 0x8007CC44: lw          $v1, 0x34($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X34);
    // 0x8007CC48: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007CC4C: lwc1        $f2, -0x2938($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2938);
    // 0x8007CC50: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007CC54: lwc1        $f4, -0x2934($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2934);
    // 0x8007CC58: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8007CC5C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8007CC60: lwc1        $f0, 0xB0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XB0);
    // 0x8007CC64: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007CC68: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007CC6C: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x8007CC70: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
    // 0x8007CC74: swc1        $f4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f4.u32l;
    // 0x8007CC78: sb          $zero, 0x6C($sp)
    MEM_B(0X6C, ctx->r29) = 0;
    // 0x8007CC7C: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x8007CC80: lh          $t1, 0xA4($s2)
    ctx->r9 = MEM_H(ctx->r18, 0XA4);
    // 0x8007CC84: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x8007CC88: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8007CC8C: lh          $v1, 0xA4($s2)
    ctx->r3 = MEM_H(ctx->r18, 0XA4);
    // 0x8007CC90: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x8007CC94: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x8007CC98: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8007CC9C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8007CCA0: addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // 0x8007CCA4: sll         $a3, $t1, 4
    ctx->r7 = S32(ctx->r9 << 4);
    // 0x8007CCA8: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8007CCAC: subu        $a3, $a3, $t1
    ctx->r7 = SUB32(ctx->r7, ctx->r9);
    // 0x8007CCB0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8007CCB4: lwc1        $f0, 0x78($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8007CCB8: sll         $a3, $a3, 2
    ctx->r7 = S32(ctx->r7 << 2);
    // 0x8007CCBC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8007CCC0: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x8007CCC4: jal         0x800F2FCC
    // 0x8007CCC8: addu        $a3, $a3, $t0
    ctx->r7 = ADD32(ctx->r7, ctx->r8);
    func_800F2FCC(rdram, ctx);
        goto after_4;
    // 0x8007CCC8: addu        $a3, $a3, $t0
    ctx->r7 = ADD32(ctx->r7, ctx->r8);
    after_4:
    // 0x8007CCCC: lw          $v1, 0x34($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X34);
    // 0x8007CCD0: lw          $v1, 0xAC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XAC);
    // 0x8007CCD4: beq         $v1, $zero, L_8007CD14
    if (ctx->r3 == 0) {
        // 0x8007CCD8: andi        $s0, $v0, 0xFFFF
        ctx->r16 = ctx->r2 & 0XFFFF;
            goto L_8007CD14;
    }
    // 0x8007CCD8: andi        $s0, $v0, 0xFFFF
    ctx->r16 = ctx->r2 & 0XFFFF;
    // 0x8007CCDC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8007CCE0: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8007CCE4: addiu       $s1, $sp, 0x58
    ctx->r17 = ADD32(ctx->r29, 0X58);
    // 0x8007CCE8: jal         0x8003E8DC
    // 0x8007CCEC: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    slotDispatcherIter(rdram, ctx);
        goto after_5;
    // 0x8007CCEC: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_5:
    // 0x8007CCF0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8007CCF4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8007CCF8: sh          $v0, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r2;
    // 0x8007CCFC: lw          $v0, 0x34($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X34);
    // 0x8007CD00: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8007CD04: lwc1        $f0, 0xB8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XB8);
    // 0x8007CD08: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8007CD0C: jal         0x8003E8DC
    // 0x8007CD10: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    slotDispatcherIter(rdram, ctx);
        goto after_6;
    // 0x8007CD10: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    after_6:
L_8007CD14:
    // 0x8007CD14: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8007CD18: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8007CD1C: addiu       $a2, $s2, 0x24
    ctx->r6 = ADD32(ctx->r18, 0X24);
    // 0x8007CD20: lui         $a3, 0x4140
    ctx->r7 = S32(0X4140 << 16);
    // 0x8007CD24: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007CD28: lwc1        $f0, -0x2930($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2930);
    // 0x8007CD2C: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
    // 0x8007CD30: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8007CD34: addiu       $v0, $zero, 0x6E
    ctx->r2 = ADD32(0, 0X6E);
    // 0x8007CD38: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8007CD3C: addiu       $v0, $zero, 0x3C
    ctx->r2 = ADD32(0, 0X3C);
    // 0x8007CD40: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8007CD44: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8007CD48: jal         0x800989D8
    // 0x8007CD4C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800989D8(rdram, ctx);
        goto after_7;
    // 0x8007CD4C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x8007CD50: lw          $v0, 0xA0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XA0);
    // 0x8007CD54: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8007CD58: bne         $v0, $zero, L_8007CD64
    if (ctx->r2 != 0) {
        // 0x8007CD5C: sw          $v0, 0xA0($s2)
        MEM_W(0XA0, ctx->r18) = ctx->r2;
            goto L_8007CD64;
    }
    // 0x8007CD5C: sw          $v0, 0xA0($s2)
    MEM_W(0XA0, ctx->r18) = ctx->r2;
    // 0x8007CD60: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_8007CD64:
    // 0x8007CD64: addu        $v0, $s3, $zero
    ctx->r2 = ADD32(ctx->r19, 0);
L_8007CD68:
    // 0x8007CD68: lw          $ra, 0x90($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X90);
    // 0x8007CD6C: lw          $s3, 0x8C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X8C);
    // 0x8007CD70: lw          $s2, 0x88($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X88);
    // 0x8007CD74: lw          $s1, 0x84($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X84);
    // 0x8007CD78: lw          $s0, 0x80($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X80);
    // 0x8007CD7C: jr          $ra
    // 0x8007CD80: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8007CD80: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_8007CD84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CD84: addiu       $sp, $sp, -0x168
    ctx->r29 = ADD32(ctx->r29, -0X168);
    // 0x8007CD88: sw          $s2, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r18;
    // 0x8007CD8C: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8007CD90: sw          $ra, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r31;
    // 0x8007CD94: sw          $s7, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r23;
    // 0x8007CD98: sw          $s6, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r22;
    // 0x8007CD9C: sw          $s5, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r21;
    // 0x8007CDA0: sw          $s4, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r20;
    // 0x8007CDA4: sw          $s3, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r19;
    // 0x8007CDA8: sw          $s1, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r17;
    // 0x8007CDAC: sw          $s0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r16;
    // 0x8007CDB0: sdc1        $f26, 0x160($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X160, ctx->r29);
    // 0x8007CDB4: sdc1        $f24, 0x158($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X158, ctx->r29);
    // 0x8007CDB8: sdc1        $f22, 0x150($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X150, ctx->r29);
    // 0x8007CDBC: sdc1        $f20, 0x148($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X148, ctx->r29);
    // 0x8007CDC0: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x8007CDC4: mtc1        $a1, $f22
    ctx->f22.u32l = ctx->r5;
    // 0x8007CDC8: jal         0x800F06BC
    // 0x8007CDCC: nop

    func_800F06BC(rdram, ctx);
        goto after_0;
    // 0x8007CDCC: nop

    after_0:
    // 0x8007CDD0: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
    // 0x8007CDD4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007CDD8: bne         $s0, $v0, L_8007D174
    if (ctx->r16 != ctx->r2) {
        // 0x8007CDDC: nop
    
            goto L_8007D174;
    }
    // 0x8007CDDC: nop

    // 0x8007CDE0: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x8007CDE4: jal         0x800F09A8
    // 0x8007CDE8: nop

    func_800F09A8(rdram, ctx);
        goto after_1;
    // 0x8007CDE8: nop

    after_1:
    // 0x8007CDEC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8007CDF0: bne         $v0, $s0, L_8007D174
    if (ctx->r2 != ctx->r16) {
        // 0x8007CDF4: nop
    
            goto L_8007D174;
    }
    // 0x8007CDF4: nop

    // 0x8007CDF8: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x8007CDFC: jal         0x800F2988
    // 0x8007CE00: addiu       $a1, $sp, 0xA0
    ctx->r5 = ADD32(ctx->r29, 0XA0);
    func_800F2988(rdram, ctx);
        goto after_2;
    // 0x8007CE00: addiu       $a1, $sp, 0xA0
    ctx->r5 = ADD32(ctx->r29, 0XA0);
    after_2:
    // 0x8007CE04: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8007CE08: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x8007CE0C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8007CE10: addiu       $s6, $v0, 0xD9C
    ctx->r22 = ADD32(ctx->r2, 0XD9C);
    // 0x8007CE14: lh          $v1, 0xA4($s2)
    ctx->r3 = MEM_H(ctx->r18, 0XA4);
    // 0x8007CE18: addiu       $s1, $sp, 0x90
    ctx->r17 = ADD32(ctx->r29, 0X90);
    // 0x8007CE1C: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x8007CE20: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8007CE24: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8007CE28: addu        $v0, $v0, $s6
    ctx->r2 = ADD32(ctx->r2, ctx->r22);
    // 0x8007CE2C: lw          $a2, 0x24($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X24);
    // 0x8007CE30: jal         0x800F2AC4
    // 0x8007CE34: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    func_800F2AC4(rdram, ctx);
        goto after_3;
    // 0x8007CE34: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    after_3:
    // 0x8007CE38: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8007CE3C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8007CE40: jal         0x80059B50
    // 0x8007CE44: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_80059B50(rdram, ctx);
        goto after_4;
    // 0x8007CE44: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_4:
    // 0x8007CE48: addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
    // 0x8007CE4C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8007CE50: jal         0x8001C774
    // 0x8007CE54: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_8001C774(rdram, ctx);
        goto after_5;
    // 0x8007CE54: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_5:
    // 0x8007CE58: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8007CE5C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8007CE60: addiu       $s3, $sp, 0x80
    ctx->r19 = ADD32(ctx->r29, 0X80);
    // 0x8007CE64: jal         0x800193E8
    // 0x8007CE68: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    func_800193E8(rdram, ctx);
        goto after_6;
    // 0x8007CE68: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_6:
    // 0x8007CE6C: lh          $v1, 0xA4($s2)
    ctx->r3 = MEM_H(ctx->r18, 0XA4);
    // 0x8007CE70: lwc1        $f0, 0x84($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X84);
    // 0x8007CE74: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x8007CE78: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8007CE7C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8007CE80: addu        $v0, $v0, $s6
    ctx->r2 = ADD32(ctx->r2, ctx->r22);
    // 0x8007CE84: lwc1        $f2, 0xC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8007CE88: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8007CE8C: lwc1        $f0, 0x80($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8007CE90: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8007CE94: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
    // 0x8007CE98: lh          $v1, 0xA4($s2)
    ctx->r3 = MEM_H(ctx->r18, 0XA4);
    // 0x8007CE9C: lwc1        $f0, 0x84($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X84);
    // 0x8007CEA0: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x8007CEA4: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8007CEA8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8007CEAC: addu        $v0, $v0, $s6
    ctx->r2 = ADD32(ctx->r2, ctx->r22);
    // 0x8007CEB0: lwc1        $f2, 0x10($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8007CEB4: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8007CEB8: lwc1        $f0, 0x84($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8007CEBC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8007CEC0: swc1        $f0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f0.u32l;
    // 0x8007CEC4: lh          $v1, 0xA4($s2)
    ctx->r3 = MEM_H(ctx->r18, 0XA4);
    // 0x8007CEC8: lwc1        $f0, 0x84($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X84);
    // 0x8007CECC: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x8007CED0: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8007CED4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8007CED8: addu        $v0, $v0, $s6
    ctx->r2 = ADD32(ctx->r2, ctx->r22);
    // 0x8007CEDC: lwc1        $f2, 0x14($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8007CEE0: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8007CEE4: lwc1        $f0, 0x88($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8007CEE8: addiu       $s4, $sp, 0x70
    ctx->r20 = ADD32(ctx->r29, 0X70);
    // 0x8007CEEC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8007CEF0: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x8007CEF4: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8007CEF8: jal         0x8001CFA0
    // 0x8007CEFC: swc1        $f0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f0.u32l;
    func_8001CFA0(rdram, ctx);
        goto after_7;
    // 0x8007CEFC: swc1        $f0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x8007CF00: lw          $a1, 0x90($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X90);
    // 0x8007CF04: jal         0x8001CC3C
    // 0x8007CF08: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_8001CC3C(rdram, ctx);
        goto after_8;
    // 0x8007CF08: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_8:
    // 0x8007CF0C: lw          $a1, 0x8C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8C);
    // 0x8007CF10: jal         0x8001CCCC
    // 0x8007CF14: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_8001CCCC(rdram, ctx);
        goto after_9;
    // 0x8007CF14: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_9:
    // 0x8007CF18: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8007CF1C: lui         $s7, 0x800A
    ctx->r23 = S32(0X800A << 16);
    // 0x8007CF20: addiu       $s5, $s7, 0xD90
    ctx->r21 = ADD32(ctx->r23, 0XD90);
    // 0x8007CF24: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x8007CF28: jal         0x800193E8
    // 0x8007CF2C: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    func_800193E8(rdram, ctx);
        goto after_10;
    // 0x8007CF2C: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_10:
    // 0x8007CF30: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8007CF34: jal         0x8001CFE8
    // 0x8007CF38: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_8001CFE8(rdram, ctx);
        goto after_11;
    // 0x8007CF38: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_11:
    // 0x8007CF3C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007CF40: lwc1        $f26, -0x292C($at)
    ctx->f26.u32l = MEM_W(ctx->r1, -0X292C);
    // 0x8007CF44: jal         0x8001C5CC
    // 0x8007CF48: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_8001C5CC(rdram, ctx);
        goto after_12;
    // 0x8007CF48: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_12:
    // 0x8007CF4C: mul.s       $f20, $f0, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x8007CF50: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007CF54: lwc1        $f0, -0x2928($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2928);
    // 0x8007CF58: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8007CF5C: nop

    // 0x8007CF60: bc1f        L_8007D180
    if (!c1cs) {
        // 0x8007CF64: nop
    
            goto L_8007D180;
    }
    // 0x8007CF64: nop

    // 0x8007CF68: lwc1        $f0, 0x94($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X94);
    // 0x8007CF6C: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8007CF70: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8007CF74: nop

    // 0x8007CF78: bc1tl       L_8007CF80
    if (c1cs) {
        // 0x8007CF7C: mov.s       $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
            goto L_8007CF80;
    }
    goto skip_0;
    // 0x8007CF7C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    skip_0:
L_8007CF80:
    // 0x8007CF80: addiu       $s1, $sp, 0xD0
    ctx->r17 = ADD32(ctx->r29, 0XD0);
    // 0x8007CF84: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8007CF88: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8007CF8C: jal         0x80019548
    // 0x8007CF90: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    func_80019548(rdram, ctx);
        goto after_13;
    // 0x8007CF90: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    after_13:
    // 0x8007CF94: jal         0x8001CF58
    // 0x8007CF98: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    normalize_vector(rdram, ctx);
        goto after_14;
    // 0x8007CF98: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_14:
    // 0x8007CF9C: addiu       $s0, $sp, 0xE0
    ctx->r16 = ADD32(ctx->r29, 0XE0);
    // 0x8007CFA0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8007CFA4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8007CFA8: jal         0x8001D240
    // 0x8007CFAC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_8001D240(rdram, ctx);
        goto after_15;
    // 0x8007CFAC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_15:
    // 0x8007CFB0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8007CFB4: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8007CFB8: jal         0x8001D3C4
    // 0x8007CFBC: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    func_8001D3C4(rdram, ctx);
        goto after_16;
    // 0x8007CFBC: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    after_16:
    // 0x8007CFC0: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x8007CFC4: lwc1        $f0, 0x70($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8007CFC8: lwc1        $f2, 0x78($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8007CFCC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8007CFD0: sw          $zero, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = 0;
    // 0x8007CFD4: swc1        $f0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f0.u32l;
    // 0x8007CFD8: jal         0x8001CFE8
    // 0x8007CFDC: swc1        $f2, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f2.u32l;
    func_8001CFE8(rdram, ctx);
        goto after_17;
    // 0x8007CFDC: swc1        $f2, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f2.u32l;
    after_17:
    // 0x8007CFE0: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x8007CFE4: jal         0x8001CF2C
    // 0x8007CFE8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    func_8001CF2C(rdram, ctx);
        goto after_18;
    // 0x8007CFE8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_18:
    // 0x8007CFEC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8007CFF0: jal         0x8001CF2C
    // 0x8007CFF4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_8001CF2C(rdram, ctx);
        goto after_19;
    // 0x8007CFF4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_19:
    // 0x8007CFF8: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8007CFFC: jal         0x8001C5CC
    // 0x8007D000: div.s       $f12, $f22, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = DIV_S(ctx->f22.fl, ctx->f20.fl);
    func_8001C5CC(rdram, ctx);
        goto after_20;
    // 0x8007D000: div.s       $f12, $f22, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = DIV_S(ctx->f22.fl, ctx->f20.fl);
    after_20:
    // 0x8007D004: addiu       $a0, $sp, 0xF0
    ctx->r4 = ADD32(ctx->r29, 0XF0);
    // 0x8007D008: addiu       $a1, $sp, 0x100
    ctx->r5 = ADD32(ctx->r29, 0X100);
    // 0x8007D00C: addiu       $a2, $sp, 0x110
    ctx->r6 = ADD32(ctx->r29, 0X110);
    // 0x8007D010: mul.s       $f20, $f0, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x8007D014: addiu       $t3, $s7, 0xD90
    ctx->r11 = ADD32(ctx->r23, 0XD90);
    // 0x8007D018: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x8007D01C: lw          $t1, 0x4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X4);
    // 0x8007D020: lw          $t2, 0x8($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X8);
    // 0x8007D024: sw          $t0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r8;
    // 0x8007D028: sw          $t1, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r9;
    // 0x8007D02C: sw          $t2, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r10;
    // 0x8007D030: sw          $zero, 0x104($sp)
    MEM_W(0X104, ctx->r29) = 0;
    // 0x8007D034: lw          $t0, 0xD0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XD0);
    // 0x8007D038: lw          $t1, 0xD4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XD4);
    // 0x8007D03C: lw          $t2, 0xD8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XD8);
    // 0x8007D040: sw          $t0, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r8;
    // 0x8007D044: sw          $t1, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r9;
    // 0x8007D048: sw          $t2, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r10;
    // 0x8007D04C: jal         0x80019548
    // 0x8007D050: sw          $zero, 0x114($sp)
    MEM_W(0X114, ctx->r29) = 0;
    func_80019548(rdram, ctx);
        goto after_21;
    // 0x8007D050: sw          $zero, 0x114($sp)
    MEM_W(0X114, ctx->r29) = 0;
    after_21:
    // 0x8007D054: lwc1        $f0, 0xF4($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x8007D058: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x8007D05C: c.le.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl <= ctx->f0.fl;
    // 0x8007D060: nop

    // 0x8007D064: bc1fl       L_8007D06C
    if (!c1cs) {
        // 0x8007D068: neg.s       $f20, $f20
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
            goto L_8007D06C;
    }
    goto skip_1;
    // 0x8007D068: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    skip_1:
L_8007D06C:
    // 0x8007D06C: neg.s       $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = -ctx->f20.fl;
    // 0x8007D070: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8007D074: jal         0x8001CD6C
    // 0x8007D078: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_8001CD6C(rdram, ctx);
        goto after_22;
    // 0x8007D078: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_22:
    // 0x8007D07C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8007D080: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x8007D084: jal         0x800193E8
    // 0x8007D088: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_800193E8(rdram, ctx);
        goto after_23;
    // 0x8007D088: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_23:
    // 0x8007D08C: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x8007D090: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8007D094: swc1        $f24, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f24.u32l;
    // 0x8007D098: jal         0x8001CFE8
    // 0x8007D09C: swc1        $f20, 0x8C($s2)
    MEM_W(0X8C, ctx->r18) = ctx->f20.u32l;
    func_8001CFE8(rdram, ctx);
        goto after_24;
    // 0x8007D09C: swc1        $f20, 0x8C($s2)
    MEM_W(0X8C, ctx->r18) = ctx->f20.u32l;
    after_24:
    // 0x8007D0A0: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x8007D0A4: jal         0x8001CF2C
    // 0x8007D0A8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_8001CF2C(rdram, ctx);
        goto after_25;
    // 0x8007D0A8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_25:
    // 0x8007D0AC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8007D0B0: jal         0x8001CF2C
    // 0x8007D0B4: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    func_8001CF2C(rdram, ctx);
        goto after_26;
    // 0x8007D0B4: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_26:
    // 0x8007D0B8: mul.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x8007D0BC: jal         0x8001C5CC
    // 0x8007D0C0: div.s       $f12, $f20, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = DIV_S(ctx->f20.fl, ctx->f22.fl);
    func_8001C5CC(rdram, ctx);
        goto after_27;
    // 0x8007D0C0: div.s       $f12, $f20, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = DIV_S(ctx->f20.fl, ctx->f22.fl);
    after_27:
    // 0x8007D0C4: mul.s       $f2, $f0, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x8007D0C8: lwc1        $f0, 0xD4($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x8007D0CC: c.le.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl <= ctx->f24.fl;
    // 0x8007D0D0: nop

    // 0x8007D0D4: bc1fl       L_8007D0DC
    if (!c1cs) {
        // 0x8007D0D8: neg.s       $f2, $f2
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
            goto L_8007D0DC;
    }
    goto skip_2;
    // 0x8007D0D8: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    skip_2:
L_8007D0DC:
    // 0x8007D0DC: lh          $v1, 0xA4($s2)
    ctx->r3 = MEM_H(ctx->r18, 0XA4);
    // 0x8007D0E0: swc1        $f2, 0x90($s2)
    MEM_W(0X90, ctx->r18) = ctx->f2.u32l;
    // 0x8007D0E4: lwc1        $f2, 0x8C($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X8C);
    // 0x8007D0E8: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x8007D0EC: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x8007D0F0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8007D0F4: addu        $v0, $v0, $s6
    ctx->r2 = ADD32(ctx->r2, ctx->r22);
    // 0x8007D0F8: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8007D0FC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8007D100: nop

    // 0x8007D104: bc1tl       L_8007D124
    if (c1cs) {
        // 0x8007D108: swc1        $f0, 0x8C($s2)
        MEM_W(0X8C, ctx->r18) = ctx->f0.u32l;
            goto L_8007D124;
    }
    goto skip_3;
    // 0x8007D108: swc1        $f0, 0x8C($s2)
    MEM_W(0X8C, ctx->r18) = ctx->f0.u32l;
    skip_3:
    // 0x8007D10C: lwc1        $f0, 0x28($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X28);
    // 0x8007D110: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8007D114: nop

    // 0x8007D118: bc1f        L_8007D128
    if (!c1cs) {
        // 0x8007D11C: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_8007D128;
    }
    // 0x8007D11C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8007D120: swc1        $f0, 0x8C($s2)
    MEM_W(0X8C, ctx->r18) = ctx->f0.u32l;
L_8007D124:
    // 0x8007D124: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
L_8007D128:
    // 0x8007D128: addiu       $v0, $v0, 0xD9C
    ctx->r2 = ADD32(ctx->r2, 0XD9C);
    // 0x8007D12C: lh          $a0, 0xA4($s2)
    ctx->r4 = MEM_H(ctx->r18, 0XA4);
    // 0x8007D130: lwc1        $f2, 0x90($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X90);
    // 0x8007D134: sll         $v1, $a0, 4
    ctx->r3 = S32(ctx->r4 << 4);
    // 0x8007D138: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x8007D13C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8007D140: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8007D144: lwc1        $f0, 0x34($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X34);
    // 0x8007D148: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8007D14C: nop

    // 0x8007D150: bc1tl       L_8007D180
    if (c1cs) {
        // 0x8007D154: swc1        $f0, 0x90($s2)
        MEM_W(0X90, ctx->r18) = ctx->f0.u32l;
            goto L_8007D180;
    }
    goto skip_4;
    // 0x8007D154: swc1        $f0, 0x90($s2)
    MEM_W(0X90, ctx->r18) = ctx->f0.u32l;
    skip_4:
    // 0x8007D158: lwc1        $f0, 0x30($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X30);
    // 0x8007D15C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8007D160: nop

    // 0x8007D164: bc1f        L_8007D180
    if (!c1cs) {
        // 0x8007D168: nop
    
            goto L_8007D180;
    }
    // 0x8007D168: nop

    // 0x8007D16C: j           L_8007D180
    // 0x8007D170: swc1        $f0, 0x90($s2)
    MEM_W(0X90, ctx->r18) = ctx->f0.u32l;
        goto L_8007D180;
    // 0x8007D170: swc1        $f0, 0x90($s2)
    MEM_W(0X90, ctx->r18) = ctx->f0.u32l;
L_8007D174:
    // 0x8007D174: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x8007D178: jal         0x800F2A24
    // 0x8007D17C: nop

    func_800F2A24(rdram, ctx);
        goto after_28;
    // 0x8007D17C: nop

    after_28:
L_8007D180:
    // 0x8007D180: lw          $ra, 0x140($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X140);
    // 0x8007D184: lw          $s7, 0x13C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X13C);
    // 0x8007D188: lw          $s6, 0x138($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X138);
    // 0x8007D18C: lw          $s5, 0x134($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X134);
    // 0x8007D190: lw          $s4, 0x130($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X130);
    // 0x8007D194: lw          $s3, 0x12C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X12C);
    // 0x8007D198: lw          $s2, 0x128($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X128);
    // 0x8007D19C: lw          $s1, 0x124($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X124);
    // 0x8007D1A0: lw          $s0, 0x120($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X120);
    // 0x8007D1A4: ldc1        $f26, 0x160($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X160);
    // 0x8007D1A8: ldc1        $f24, 0x158($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X158);
    // 0x8007D1AC: ldc1        $f22, 0x150($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X150);
    // 0x8007D1B0: ldc1        $f20, 0x148($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X148);
    // 0x8007D1B4: jr          $ra
    // 0x8007D1B8: addiu       $sp, $sp, 0x168
    ctx->r29 = ADD32(ctx->r29, 0X168);
    return;
    // 0x8007D1B8: addiu       $sp, $sp, 0x168
    ctx->r29 = ADD32(ctx->r29, 0X168);
;}
RECOMP_FUNC void func_8007D1BC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D1BC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007D1C0: lwc1        $f0, -0x291C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X291C);
    // 0x8007D1C4: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x8007D1C8: sw          $s1, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r17;
    // 0x8007D1CC: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8007D1D0: sw          $ra, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r31;
    // 0x8007D1D4: sw          $s3, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r19;
    // 0x8007D1D8: sw          $s2, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r18;
    // 0x8007D1DC: sw          $s0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r16;
    // 0x8007D1E0: swc1        $f0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f0.u32l;
    // 0x8007D1E4: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x8007D1E8: lwc1        $f0, 0x28($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X28);
    // 0x8007D1EC: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x8007D1F0: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x8007D1F4: lw          $a0, 0xE4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XE4);
    // 0x8007D1F8: jal         0x80047B48
    // 0x8007D1FC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    getLevelDatItemByName(rdram, ctx);
        goto after_0;
    // 0x8007D1FC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    after_0:
    // 0x8007D200: sw          $v0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r2;
    // 0x8007D204: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x8007D208: lw          $a0, 0xE8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XE8);
    // 0x8007D20C: jal         0x80047B48
    // 0x8007D210: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    getLevelDatItemByName(rdram, ctx);
        goto after_1;
    // 0x8007D210: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    after_1:
    // 0x8007D214: sw          $v0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r2;
    // 0x8007D218: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x8007D21C: lw          $a0, 0xEC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XEC);
    // 0x8007D220: jal         0x80047B48
    // 0x8007D224: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    getLevelDatItemByName(rdram, ctx);
        goto after_2;
    // 0x8007D224: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    after_2:
    // 0x8007D228: sw          $v0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r2;
    // 0x8007D22C: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x8007D230: lw          $a0, 0xF0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XF0);
    // 0x8007D234: jal         0x80047B48
    // 0x8007D238: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    getLevelDatItemByName(rdram, ctx);
        goto after_3;
    // 0x8007D238: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    after_3:
    // 0x8007D23C: sw          $v0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r2;
    // 0x8007D240: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x8007D244: lw          $a0, 0xF4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XF4);
    // 0x8007D248: jal         0x80047B48
    // 0x8007D24C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    getLevelDatItemByName(rdram, ctx);
        goto after_4;
    // 0x8007D24C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    after_4:
    // 0x8007D250: sw          $v0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r2;
    // 0x8007D254: lw          $v0, 0x38($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X38);
    // 0x8007D258: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8007D25C: lhu         $v0, 0x198($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X198);
    // 0x8007D260: addiu       $v1, $sp, 0xB0
    ctx->r3 = ADD32(ctx->r29, 0XB0);
    // 0x8007D264: sh          $v0, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r2;
L_8007D268:
    // 0x8007D268: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8007D26C: beq         $v0, $zero, L_8007D454
    if (ctx->r2 == 0) {
        // 0x8007D270: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8007D454;
    }
    // 0x8007D270: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8007D274: slti        $v0, $a0, 0x5
    ctx->r2 = SIGNED(ctx->r4) < 0X5 ? 1 : 0;
    // 0x8007D278: bne         $v0, $zero, L_8007D268
    if (ctx->r2 != 0) {
        // 0x8007D27C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8007D268;
    }
    // 0x8007D27C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8007D280: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x8007D284: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x8007D288: jal         0x80059868
    // 0x8007D28C: sh          $zero, 0x1B4($s1)
    MEM_H(0X1B4, ctx->r17) = 0;
    func_80059868(rdram, ctx);
        goto after_5;
    // 0x8007D28C: sh          $zero, 0x1B4($s1)
    MEM_H(0X1B4, ctx->r17) = 0;
    after_5:
    // 0x8007D290: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8007D294: beq         $v0, $zero, L_8007D3C0
    if (ctx->r2 == 0) {
        // 0x8007D298: addiu       $s2, $sp, 0x28
        ctx->r18 = ADD32(ctx->r29, 0X28);
            goto L_8007D3C0;
    }
    // 0x8007D298: addiu       $s2, $sp, 0x28
    ctx->r18 = ADD32(ctx->r29, 0X28);
    // 0x8007D29C: lui         $s3, 0x8008
    ctx->r19 = S32(0X8008 << 16);
    // 0x8007D2A0: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
L_8007D2A4:
    // 0x8007D2A4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8007D2A8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8007D2AC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8007D2B0: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x8007D2B4: jal         0x80058360
    // 0x8007D2B8: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    func_80058360(rdram, ctx);
        goto after_6;
    // 0x8007D2B8: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    after_6:
    // 0x8007D2BC: lui         $a0, 0x7370
    ctx->r4 = S32(0X7370 << 16);
    // 0x8007D2C0: ori         $a0, $a0, 0x7400
    ctx->r4 = ctx->r4 | 0X7400;
    // 0x8007D2C4: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8007D2C8: addiu       $v0, $zero, -0x100
    ctx->r2 = ADD32(0, -0X100);
    // 0x8007D2CC: and         $v1, $v1, $v0
    ctx->r3 = ctx->r3 & ctx->r2;
    // 0x8007D2D0: bne         $v1, $a0, L_8007D2E4
    if (ctx->r3 != ctx->r4) {
        // 0x8007D2D4: lui         $v0, 0x6274
        ctx->r2 = S32(0X6274 << 16);
            goto L_8007D2E4;
    }
    // 0x8007D2D4: lui         $v0, 0x6274
    ctx->r2 = S32(0X6274 << 16);
    // 0x8007D2D8: lw          $v1, 0xC0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XC0);
    // 0x8007D2DC: j           L_8007D340
    // 0x8007D2E0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_8007D340;
    // 0x8007D2E0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_8007D2E4:
    // 0x8007D2E4: ori         $v0, $v0, 0x6D00
    ctx->r2 = ctx->r2 | 0X6D00;
    // 0x8007D2E8: bne         $v1, $v0, L_8007D2FC
    if (ctx->r3 != ctx->r2) {
        // 0x8007D2EC: lui         $v0, 0x7364
        ctx->r2 = S32(0X7364 << 16);
            goto L_8007D2FC;
    }
    // 0x8007D2EC: lui         $v0, 0x7364
    ctx->r2 = S32(0X7364 << 16);
    // 0x8007D2F0: lw          $v1, 0xBC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XBC);
    // 0x8007D2F4: j           L_8007D340
    // 0x8007D2F8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_8007D340;
    // 0x8007D2F8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8007D2FC:
    // 0x8007D2FC: ori         $v0, $v0, 0x6800
    ctx->r2 = ctx->r2 | 0X6800;
    // 0x8007D300: bne         $v1, $v0, L_8007D314
    if (ctx->r3 != ctx->r2) {
        // 0x8007D304: lui         $v0, 0x7470
        ctx->r2 = S32(0X7470 << 16);
            goto L_8007D314;
    }
    // 0x8007D304: lui         $v0, 0x7470
    ctx->r2 = S32(0X7470 << 16);
    // 0x8007D308: lw          $v1, 0xB4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB4);
    // 0x8007D30C: j           L_8007D340
    // 0x8007D310: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8007D340;
    // 0x8007D310: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8007D314:
    // 0x8007D314: ori         $v0, $v0, 0x7400
    ctx->r2 = ctx->r2 | 0X7400;
    // 0x8007D318: bne         $v1, $v0, L_8007D330
    if (ctx->r3 != ctx->r2) {
        // 0x8007D31C: lui         $v0, 0x6274
        ctx->r2 = S32(0X6274 << 16);
            goto L_8007D330;
    }
    // 0x8007D31C: lui         $v0, 0x6274
    ctx->r2 = S32(0X6274 << 16);
    // 0x8007D320: lw          $v0, 0xB0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XB0);
    // 0x8007D324: sh          $zero, 0x62($sp)
    MEM_H(0X62, ctx->r29) = 0;
    // 0x8007D328: j           L_8007D348
    // 0x8007D32C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
        goto L_8007D348;
    // 0x8007D32C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_8007D330:
    // 0x8007D330: ori         $v0, $v0, 0x6700
    ctx->r2 = ctx->r2 | 0X6700;
    // 0x8007D334: bne         $v1, $v0, L_8007D3AC
    if (ctx->r3 != ctx->r2) {
        // 0x8007D338: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8007D3AC;
    }
    // 0x8007D338: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007D33C: lw          $v1, 0xB8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB8);
L_8007D340:
    // 0x8007D340: sh          $v0, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r2;
    // 0x8007D344: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
L_8007D348:
    // 0x8007D348: lw          $v0, 0x38($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X38);
    // 0x8007D34C: lhu         $a0, 0x198($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X198);
    // 0x8007D350: jal         0x8004013C
    // 0x8007D354: nop

    func_8004013C(rdram, ctx);
        goto after_7;
    // 0x8007D354: nop

    after_7:
    // 0x8007D358: addiu       $a0, $s3, 0xC0
    ctx->r4 = ADD32(ctx->r19, 0XC0);
    // 0x8007D35C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8007D360: lbu         $a3, 0x19($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X19);
    // 0x8007D364: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8007D368: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8007D36C: jal         0x8003FFEC
    // 0x8007D370: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    func_8003FFEC(rdram, ctx);
        goto after_8;
    // 0x8007D370: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_8:
    // 0x8007D374: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8007D378: andi        $a0, $s0, 0xFFFF
    ctx->r4 = ctx->r16 & 0XFFFF;
    // 0x8007D37C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8007D380: beq         $a0, $v0, L_8007D3AC
    if (ctx->r4 == ctx->r2) {
        // 0x8007D384: addiu       $a1, $zero, 0x3
        ctx->r5 = ADD32(0, 0X3);
            goto L_8007D3AC;
    }
    // 0x8007D384: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8007D388: jal         0x8003E8DC
    // 0x8007D38C: addiu       $a2, $sp, 0xC8
    ctx->r6 = ADD32(ctx->r29, 0XC8);
    slotDispatcherIter(rdram, ctx);
        goto after_9;
    // 0x8007D38C: addiu       $a2, $sp, 0xC8
    ctx->r6 = ADD32(ctx->r29, 0XC8);
    after_9:
    // 0x8007D390: lhu         $v0, 0x1B4($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X1B4);
    // 0x8007D394: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x8007D398: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8007D39C: sra         $v0, $v0, 15
    ctx->r2 = S32(SIGNED(ctx->r2) >> 15);
    // 0x8007D3A0: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x8007D3A4: sh          $v1, 0x1B4($s1)
    MEM_H(0X1B4, ctx->r17) = ctx->r3;
    // 0x8007D3A8: sh          $s0, 0x1B6($v0)
    MEM_H(0X1B6, ctx->r2) = ctx->r16;
L_8007D3AC:
    // 0x8007D3AC: jal         0x800598F0
    // 0x8007D3B0: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_800598F0(rdram, ctx);
        goto after_10;
    // 0x8007D3B0: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_10:
    // 0x8007D3B4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8007D3B8: bnel        $v0, $zero, L_8007D2A4
    if (ctx->r2 != 0) {
        // 0x8007D3BC: addiu       $a1, $sp, 0x18
        ctx->r5 = ADD32(ctx->r29, 0X18);
            goto L_8007D2A4;
    }
    goto skip_0;
    // 0x8007D3BC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    skip_0:
L_8007D3C0:
    // 0x8007D3C0: addiu       $a0, $sp, 0x9C
    ctx->r4 = ADD32(ctx->r29, 0X9C);
    // 0x8007D3C4: lw          $a1, 0x34($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X34);
    // 0x8007D3C8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8007D3CC: jal         0x80018EF4
    // 0x8007D3D0: addiu       $a1, $a1, 0xBC
    ctx->r5 = ADD32(ctx->r5, 0XBC);
    zmemcpy(rdram, ctx);
        goto after_11;
    // 0x8007D3D0: addiu       $a1, $a1, 0xBC
    ctx->r5 = ADD32(ctx->r5, 0XBC);
    after_11:
    // 0x8007D3D4: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x8007D3D8: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8007D3DC: lwc1        $f0, 0x28($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X28);
    // 0x8007D3E0: addiu       $a1, $a1, -0x2924
    ctx->r5 = ADD32(ctx->r5, -0X2924);
    // 0x8007D3E4: swc1        $f0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f0.u32l;
    // 0x8007D3E8: lw          $v0, 0x38($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X38);
    // 0x8007D3EC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8007D3F0: lhu         $v0, 0x198($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X198);
    // 0x8007D3F4: addiu       $s0, $sp, 0x68
    ctx->r16 = ADD32(ctx->r29, 0X68);
    // 0x8007D3F8: sh          $v0, 0xAC($sp)
    MEM_H(0XAC, ctx->r29) = ctx->r2;
    // 0x8007D3FC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8007D400: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8007D404: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x8007D408: jal         0x80058360
    // 0x8007D40C: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    func_80058360(rdram, ctx);
        goto after_12;
    // 0x8007D40C: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_12:
    // 0x8007D410: lw          $v0, 0x38($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X38);
    // 0x8007D414: lhu         $a0, 0x198($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X198);
    // 0x8007D418: jal         0x8004013C
    // 0x8007D41C: nop

    func_8004013C(rdram, ctx);
        goto after_13;
    // 0x8007D41C: nop

    after_13:
    // 0x8007D420: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8007D424: addiu       $a0, $a0, 0x1350
    ctx->r4 = ADD32(ctx->r4, 0X1350);
    // 0x8007D428: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8007D42C: lbu         $a3, 0x19($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X19);
    // 0x8007D430: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8007D434: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8007D438: jal         0x8003FFEC
    // 0x8007D43C: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    func_8003FFEC(rdram, ctx);
        goto after_14;
    // 0x8007D43C: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_14:
    // 0x8007D440: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8007D444: sh          $v0, 0x1F6($s1)
    MEM_H(0X1F6, ctx->r17) = ctx->r2;
    // 0x8007D448: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x8007D44C: jal         0x8003E8DC
    // 0x8007D450: addiu       $a2, $sp, 0xC8
    ctx->r6 = ADD32(ctx->r29, 0XC8);
    slotDispatcherIter(rdram, ctx);
        goto after_15;
    // 0x8007D450: addiu       $a2, $sp, 0xC8
    ctx->r6 = ADD32(ctx->r29, 0XC8);
    after_15:
L_8007D454:
    // 0x8007D454: lw          $ra, 0xE0($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XE0);
    // 0x8007D458: lw          $s3, 0xDC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XDC);
    // 0x8007D45C: lw          $s2, 0xD8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XD8);
    // 0x8007D460: lw          $s1, 0xD4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XD4);
    // 0x8007D464: lw          $s0, 0xD0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XD0);
    // 0x8007D468: jr          $ra
    // 0x8007D46C: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    return;
    // 0x8007D46C: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
;}
RECOMP_FUNC void func_8007D470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D470: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8007D474: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007D478: lwc1        $f0, -0x2910($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2910);
    // 0x8007D47C: lbu         $v0, 0xB39($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB39);
    // 0x8007D480: addiu       $sp, $sp, -0x158
    ctx->r29 = ADD32(ctx->r29, -0X158);
    // 0x8007D484: sw          $s1, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r17;
    // 0x8007D488: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8007D48C: sw          $ra, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r31;
    // 0x8007D490: sw          $fp, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r30;
    // 0x8007D494: sw          $s7, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r23;
    // 0x8007D498: sw          $s6, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r22;
    // 0x8007D49C: sw          $s5, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r21;
    // 0x8007D4A0: sw          $s4, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r20;
    // 0x8007D4A4: sw          $s3, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r19;
    // 0x8007D4A8: sw          $s2, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r18;
    // 0x8007D4AC: sw          $s0, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r16;
    // 0x8007D4B0: sdc1        $f20, 0x150($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X150, ctx->r29);
    // 0x8007D4B4: sw          $a1, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r5;
    // 0x8007D4B8: bne         $v0, $zero, L_8007D508
    if (ctx->r2 != 0) {
        // 0x8007D4BC: swc1        $f0, 0x120($sp)
        MEM_W(0X120, ctx->r29) = ctx->f0.u32l;
            goto L_8007D508;
    }
    // 0x8007D4BC: swc1        $f0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f0.u32l;
    // 0x8007D4C0: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x8007D4C4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007D4C8: lwc1        $f2, -0x290C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X290C);
    // 0x8007D4CC: lwc1        $f0, 0x28($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X28);
    // 0x8007D4D0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007D4D4: swc1        $f0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f0.u32l;
    // 0x8007D4D8: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x8007D4DC: lwc1        $f0, 0x28($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X28);
    // 0x8007D4E0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007D4E4: swc1        $f0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f0.u32l;
    // 0x8007D4E8: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x8007D4EC: lwc1        $f0, 0x28($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X28);
    // 0x8007D4F0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007D4F4: swc1        $f0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f0.u32l;
    // 0x8007D4F8: lw          $v0, 0x38($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X38);
    // 0x8007D4FC: lhu         $v0, 0x198($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X198);
    // 0x8007D500: j           L_8007D52C
    // 0x8007D504: sh          $v0, 0xCC($sp)
    MEM_H(0XCC, ctx->r29) = ctx->r2;
        goto L_8007D52C;
    // 0x8007D504: sh          $v0, 0xCC($sp)
    MEM_H(0XCC, ctx->r29) = ctx->r2;
L_8007D508:
    // 0x8007D508: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007D50C: lwc1        $f0, -0x2908($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2908);
    // 0x8007D510: lw          $t0, 0x15C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X15C);
    // 0x8007D514: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8007D518: sh          $v0, 0xCC($sp)
    MEM_H(0XCC, ctx->r29) = ctx->r2;
    // 0x8007D51C: sw          $t0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r8;
    // 0x8007D520: swc1        $f0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f0.u32l;
    // 0x8007D524: swc1        $f0, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f0.u32l;
    // 0x8007D528: swc1        $f0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f0.u32l;
L_8007D52C:
    // 0x8007D52C: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x8007D530: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x8007D534: addiu       $s3, $sp, 0x90
    ctx->r19 = ADD32(ctx->r29, 0X90);
    // 0x8007D538: addiu       $s7, $sp, 0x30
    ctx->r23 = ADD32(ctx->r29, 0X30);
    // 0x8007D53C: addiu       $s6, $sp, 0x60
    ctx->r22 = ADD32(ctx->r29, 0X60);
    // 0x8007D540: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007D544: lwc1        $f20, -0x2904($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X2904);
    // 0x8007D548: addiu       $s5, $sp, 0x18
    ctx->r21 = ADD32(ctx->r29, 0X18);
    // 0x8007D54C: addu        $s0, $s1, $zero
    ctx->r16 = ADD32(ctx->r17, 0);
    // 0x8007D550: addiu       $s4, $zero, 0xA8
    ctx->r20 = ADD32(0, 0XA8);
L_8007D554:
    // 0x8007D554: lw          $a0, 0x15C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X15C);
    // 0x8007D558: lbu         $v1, 0xB39($fp)
    ctx->r3 = MEM_BU(ctx->r30, 0XB39);
    // 0x8007D55C: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x8007D560: sb          $v0, 0x18($sp)
    MEM_B(0X18, ctx->r29) = ctx->r2;
    // 0x8007D564: addiu       $v0, $s2, 0x31
    ctx->r2 = ADD32(ctx->r18, 0X31);
    // 0x8007D568: sb          $v0, 0x19($sp)
    MEM_B(0X19, ctx->r29) = ctx->r2;
    // 0x8007D56C: bne         $v1, $zero, L_8007D578
    if (ctx->r3 != 0) {
        // 0x8007D570: sb          $zero, 0x1A($sp)
        MEM_B(0X1A, ctx->r29) = 0;
            goto L_8007D578;
    }
    // 0x8007D570: sb          $zero, 0x1A($sp)
    MEM_B(0X1A, ctx->r29) = 0;
    // 0x8007D574: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
L_8007D578:
    // 0x8007D578: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x8007D57C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x8007D580: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // 0x8007D584: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8007D588: jal         0x80058360
    // 0x8007D58C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_80058360(rdram, ctx);
        goto after_0;
    // 0x8007D58C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_0:
    // 0x8007D590: lwc1        $f0, 0xA8($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8007D594: lwc1        $f2, 0xAC($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8007D598: lbu         $v0, 0xB39($fp)
    ctx->r2 = MEM_BU(ctx->r30, 0XB39);
    // 0x8007D59C: sh          $s2, 0xCE($sp)
    MEM_H(0XCE, ctx->r29) = ctx->r18;
    // 0x8007D5A0: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8007D5A4: swc1        $f0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f0.u32l;
    // 0x8007D5A8: lwc1        $f0, 0xB0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x8007D5AC: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x8007D5B0: swc1        $f2, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f2.u32l;
    // 0x8007D5B4: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8007D5B8: bne         $v0, $zero, L_8007D610
    if (ctx->r2 != 0) {
        // 0x8007D5BC: swc1        $f0, 0xB0($sp)
        MEM_W(0XB0, ctx->r29) = ctx->f0.u32l;
            goto L_8007D610;
    }
    // 0x8007D5BC: swc1        $f0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f0.u32l;
    // 0x8007D5C0: lw          $v0, 0x38($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X38);
    // 0x8007D5C4: lhu         $a0, 0x198($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X198);
    // 0x8007D5C8: jal         0x8004013C
    // 0x8007D5CC: nop

    func_8004013C(rdram, ctx);
        goto after_1;
    // 0x8007D5CC: nop

    after_1:
    // 0x8007D5D0: lui         $t1, 0x8008
    ctx->r9 = S32(0X8008 << 16);
    // 0x8007D5D4: addiu       $a0, $t1, 0x1ABC
    ctx->r4 = ADD32(ctx->r9, 0X1ABC);
    // 0x8007D5D8: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8007D5DC: lbu         $a3, 0x19($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X19);
    // 0x8007D5E0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8007D5E4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8007D5E8: jal         0x8003FFEC
    // 0x8007D5EC: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    func_8003FFEC(rdram, ctx);
        goto after_2;
    // 0x8007D5EC: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_2:
    // 0x8007D5F0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8007D5F4: sh          $v0, 0xFC($s0)
    MEM_H(0XFC, ctx->r16) = ctx->r2;
    // 0x8007D5F8: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x8007D5FC: jal         0x8003E8DC
    // 0x8007D600: addiu       $a2, $sp, 0x120
    ctx->r6 = ADD32(ctx->r29, 0X120);
    slotDispatcherIter(rdram, ctx);
        goto after_3;
    // 0x8007D600: addiu       $a2, $sp, 0x120
    ctx->r6 = ADD32(ctx->r29, 0X120);
    after_3:
    // 0x8007D604: ori         $t2, $zero, 0xFFFF
    ctx->r10 = 0 | 0XFFFF;
    // 0x8007D608: j           L_8007D638
    // 0x8007D60C: sh          $t2, 0x104($s0)
    MEM_H(0X104, ctx->r16) = ctx->r10;
        goto L_8007D638;
    // 0x8007D60C: sh          $t2, 0x104($s0)
    MEM_H(0X104, ctx->r16) = ctx->r10;
L_8007D610:
    // 0x8007D610: lui         $t3, 0x8008
    ctx->r11 = S32(0X8008 << 16);
    // 0x8007D614: addiu       $a0, $t3, 0x1ABC
    ctx->r4 = ADD32(ctx->r11, 0X1ABC);
    // 0x8007D618: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8007D61C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8007D620: jal         0x8003FFEC
    // 0x8007D624: addiu       $a3, $zero, 0x56
    ctx->r7 = ADD32(0, 0X56);
    func_8003FFEC(rdram, ctx);
        goto after_4;
    // 0x8007D624: addiu       $a3, $zero, 0x56
    ctx->r7 = ADD32(0, 0X56);
    after_4:
    // 0x8007D628: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x8007D62C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8007D630: jal         0x8003E8DC
    // 0x8007D634: addiu       $a2, $sp, 0x120
    ctx->r6 = ADD32(ctx->r29, 0X120);
    slotDispatcherIter(rdram, ctx);
        goto after_5;
    // 0x8007D634: addiu       $a2, $sp, 0x120
    ctx->r6 = ADD32(ctx->r29, 0X120);
    after_5:
L_8007D638:
    // 0x8007D638: lbu         $v0, 0xB39($fp)
    ctx->r2 = MEM_BU(ctx->r30, 0XB39);
    // 0x8007D63C: bnel        $v0, $zero, L_8007D7D8
    if (ctx->r2 != 0) {
        // 0x8007D640: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_8007D7D8;
    }
    goto skip_0;
    // 0x8007D640: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    skip_0:
    // 0x8007D644: lwc1        $f2, 0xC4($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x8007D648: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007D64C: lwc1        $f0, -0x2900($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2900);
    // 0x8007D650: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8007D654: lwc1        $f0, 0x94($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8007D658: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8007D65C: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    // 0x8007D660: lw          $v0, 0x38($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X38);
    // 0x8007D664: lhu         $a0, 0x198($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X198);
    // 0x8007D668: jal         0x8003F880
    // 0x8007D66C: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_8003F880(rdram, ctx);
        goto after_6;
    // 0x8007D66C: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_6:
    // 0x8007D670: addu        $a0, $s7, $zero
    ctx->r4 = ADD32(ctx->r23, 0);
    // 0x8007D674: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8007D678: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8007D67C: jal         0x80059B50
    // 0x8007D680: sh          $v0, 0x114($s0)
    MEM_H(0X114, ctx->r16) = ctx->r2;
    func_80059B50(rdram, ctx);
        goto after_7;
    // 0x8007D680: sh          $v0, 0x114($s0)
    MEM_H(0X114, ctx->r16) = ctx->r2;
    after_7:
    // 0x8007D684: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // 0x8007D688: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8007D68C: addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    // 0x8007D690: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x8007D694: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x8007D698: jal         0x8001C774
    // 0x8007D69C: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    func_8001C774(rdram, ctx);
        goto after_8;
    // 0x8007D69C: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x8007D6A0: lwc1        $f0, 0x90($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8007D6A4: lwc1        $f2, 0x0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8007D6A8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8007D6AC: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8007D6B0: lwc1        $f0, 0x94($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8007D6B4: lwc1        $f2, 0x4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8007D6B8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8007D6BC: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8007D6C0: lwc1        $f0, 0x98($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8007D6C4: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8007D6C8: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // 0x8007D6CC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8007D6D0: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8007D6D4: addu        $a2, $s1, $s4
    ctx->r6 = ADD32(ctx->r17, ctx->r20);
    // 0x8007D6D8: jal         0x800193E8
    // 0x8007D6DC: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    func_800193E8(rdram, ctx);
        goto after_9;
    // 0x8007D6DC: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_9:
    // 0x8007D6E0: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x8007D6E4: lwc1        $f0, 0x28($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X28);
    // 0x8007D6E8: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8007D6EC: swc1        $f0, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->f0.u32l;
    // 0x8007D6F0: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x8007D6F4: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8007D6F8: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8007D6FC: swc1        $f0, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->f0.u32l;
    // 0x8007D700: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x8007D704: lwc1        $f0, 0x30($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X30);
    // 0x8007D708: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8007D70C: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x8007D710: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8007D714: swc1        $f0, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->f0.u32l;
    // 0x8007D718: lw          $v0, 0x38($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X38);
    // 0x8007D71C: addiu       $a1, $a1, -0x2918
    ctx->r5 = ADD32(ctx->r5, -0X2918);
    // 0x8007D720: lhu         $v0, 0x198($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X198);
    // 0x8007D724: addiu       $a2, $s2, 0x1
    ctx->r6 = ADD32(ctx->r18, 0X1);
    // 0x8007D728: sw          $s5, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r21;
    // 0x8007D72C: jal         0x80033CC4
    // 0x8007D730: sh          $v0, 0x114($sp)
    MEM_H(0X114, ctx->r29) = ctx->r2;
    sprintf_recomp(rdram, ctx);
        goto after_10;
    // 0x8007D730: sh          $v0, 0x114($sp)
    MEM_H(0X114, ctx->r29) = ctx->r2;
    after_10:
    // 0x8007D734: addiu       $v1, $sp, 0xD8
    ctx->r3 = ADD32(ctx->r29, 0XD8);
    // 0x8007D738: addu        $v0, $s3, $zero
    ctx->r2 = ADD32(ctx->r19, 0);
    // 0x8007D73C: addiu       $a0, $sp, 0xC0
    ctx->r4 = ADD32(ctx->r29, 0XC0);
L_8007D740:
    // 0x8007D740: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8007D744: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x8007D748: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x8007D74C: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x8007D750: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8007D754: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x8007D758: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x8007D75C: sw          $t3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r11;
    // 0x8007D760: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8007D764: bne         $v0, $a0, L_8007D740
    if (ctx->r2 != ctx->r4) {
        // 0x8007D768: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_8007D740;
    }
    // 0x8007D768: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8007D76C: lwc1        $f2, 0x10C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x8007D770: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007D774: lwc1        $f0, -0x28FC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X28FC);
    // 0x8007D778: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8007D77C: lwc1        $f0, 0xDC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x8007D780: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8007D784: swc1        $f0, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f0.u32l;
    // 0x8007D788: lw          $v0, 0x38($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X38);
    // 0x8007D78C: lhu         $a0, 0x198($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X198);
    // 0x8007D790: jal         0x8004013C
    // 0x8007D794: nop

    func_8004013C(rdram, ctx);
        goto after_11;
    // 0x8007D794: nop

    after_11:
    // 0x8007D798: lui         $a0, 0x8008
    ctx->r4 = S32(0X8008 << 16);
    // 0x8007D79C: addiu       $a0, $a0, -0x43E8
    ctx->r4 = ADD32(ctx->r4, -0X43E8);
    // 0x8007D7A0: addiu       $a1, $sp, 0xD8
    ctx->r5 = ADD32(ctx->r29, 0XD8);
    // 0x8007D7A4: lbu         $a3, 0x19($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X19);
    // 0x8007D7A8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8007D7AC: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8007D7B0: jal         0x8003FFEC
    // 0x8007D7B4: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    func_8003FFEC(rdram, ctx);
        goto after_12;
    // 0x8007D7B4: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    after_12:
    // 0x8007D7B8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8007D7BC: sh          $v0, 0x10C($s0)
    MEM_H(0X10C, ctx->r16) = ctx->r2;
    // 0x8007D7C0: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x8007D7C4: jal         0x8003E8DC
    // 0x8007D7C8: addiu       $a2, $sp, 0x120
    ctx->r6 = ADD32(ctx->r29, 0X120);
    slotDispatcherIter(rdram, ctx);
        goto after_13;
    // 0x8007D7C8: addiu       $a2, $sp, 0x120
    ctx->r6 = ADD32(ctx->r29, 0X120);
    after_13:
    // 0x8007D7CC: ori         $t0, $zero, 0xFFFF
    ctx->r8 = 0 | 0XFFFF;
    // 0x8007D7D0: sh          $t0, 0x11C($s0)
    MEM_H(0X11C, ctx->r16) = ctx->r8;
    // 0x8007D7D4: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
L_8007D7D8:
    // 0x8007D7D8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8007D7DC: slti        $v0, $s2, 0x4
    ctx->r2 = SIGNED(ctx->r18) < 0X4 ? 1 : 0;
    // 0x8007D7E0: bne         $v0, $zero, L_8007D554
    if (ctx->r2 != 0) {
        // 0x8007D7E4: addiu       $s4, $s4, 0xC
        ctx->r20 = ADD32(ctx->r20, 0XC);
            goto L_8007D554;
    }
    // 0x8007D7E4: addiu       $s4, $s4, 0xC
    ctx->r20 = ADD32(ctx->r20, 0XC);
    // 0x8007D7E8: lw          $ra, 0x14C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14C);
    // 0x8007D7EC: lw          $fp, 0x148($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X148);
    // 0x8007D7F0: lw          $s7, 0x144($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X144);
    // 0x8007D7F4: lw          $s6, 0x140($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X140);
    // 0x8007D7F8: lw          $s5, 0x13C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X13C);
    // 0x8007D7FC: lw          $s4, 0x138($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X138);
    // 0x8007D800: lw          $s3, 0x134($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X134);
    // 0x8007D804: lw          $s2, 0x130($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X130);
    // 0x8007D808: lw          $s1, 0x12C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X12C);
    // 0x8007D80C: lw          $s0, 0x128($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X128);
    // 0x8007D810: ldc1        $f20, 0x150($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X150);
    // 0x8007D814: jr          $ra
    // 0x8007D818: addiu       $sp, $sp, 0x158
    ctx->r29 = ADD32(ctx->r29, 0X158);
    return;
    // 0x8007D818: addiu       $sp, $sp, 0x158
    ctx->r29 = ADD32(ctx->r29, 0X158);
;}
RECOMP_FUNC void func_8007D81C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D81C: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x8007D820: sw          $s2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r18;
    // 0x8007D824: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8007D828: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8007D82C: sdc1        $f20, 0x90($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X90, ctx->r29);
    // 0x8007D830: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x8007D834: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8007D838: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x8007D83C: sw          $ra, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r31;
    // 0x8007D840: sw          $s1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r17;
    // 0x8007D844: jal         0x80059B50
    // 0x8007D848: sw          $s0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r16;
    func_80059B50(rdram, ctx);
        goto after_0;
    // 0x8007D848: sw          $s0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r16;
    after_0:
    // 0x8007D84C: lh          $v1, 0xFA($s2)
    ctx->r3 = MEM_H(ctx->r18, 0XFA);
    // 0x8007D850: sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x8007D854: beq         $v0, $zero, L_8007DD78
    if (ctx->r2 == 0) {
        // 0x8007D858: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_8007DD78;
    }
    // 0x8007D858: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8007D85C: addiu       $v0, $v0, -0x28F0
    ctx->r2 = ADD32(ctx->r2, -0X28F0);
    // 0x8007D860: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8007D864: addu        $v1, $v1, $v0
    gpr jr_addend_8007D86C = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8007D868: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x8007D86C: jr          $v0
    // 0x8007D870: nop

    switch (jr_addend_8007D86C >> 2) {
        case 0: goto L_8007DD78; break;
        case 1: goto L_8007D874; break;
        case 2: goto L_8007D9A0; break;
        case 3: goto L_8007DC50; break;
        case 4: goto L_8007DC50; break;
        default: switch_error(__func__, 0x8007D86C, 0x8003D710);
    }
    // 0x8007D870: nop

L_8007D874:
    // 0x8007D874: lbu         $v0, 0xF9($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0XF9);
    // 0x8007D878: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8007D87C: sb          $v0, 0xD8($s2)
    MEM_B(0XD8, ctx->r18) = ctx->r2;
    // 0x8007D880: andi        $v0, $v1, 0x5
    ctx->r2 = ctx->r3 & 0X5;
    // 0x8007D884: beq         $v0, $zero, L_8007D8C8
    if (ctx->r2 == 0) {
        // 0x8007D888: andi        $v0, $v1, 0x1
        ctx->r2 = ctx->r3 & 0X1;
            goto L_8007D8C8;
    }
    // 0x8007D888: andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // 0x8007D88C: beq         $v0, $zero, L_8007D8AC
    if (ctx->r2 == 0) {
        // 0x8007D890: addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
            goto L_8007D8AC;
    }
    // 0x8007D890: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8007D894: addiu       $a1, $s2, 0xB4
    ctx->r5 = ADD32(ctx->r18, 0XB4);
    // 0x8007D898: jal         0x800193E8
    // 0x8007D89C: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    func_800193E8(rdram, ctx);
        goto after_1;
    // 0x8007D89C: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    after_1:
    // 0x8007D8A0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8007D8A4: j           L_8007D904
    // 0x8007D8A8: addiu       $a1, $s2, 0xCC
    ctx->r5 = ADD32(ctx->r18, 0XCC);
        goto L_8007D904;
    // 0x8007D8A8: addiu       $a1, $s2, 0xCC
    ctx->r5 = ADD32(ctx->r18, 0XCC);
L_8007D8AC:
    // 0x8007D8AC: addiu       $a1, $s2, 0xB4
    ctx->r5 = ADD32(ctx->r18, 0XB4);
    // 0x8007D8B0: jal         0x800193E8
    // 0x8007D8B4: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    func_800193E8(rdram, ctx);
        goto after_2;
    // 0x8007D8B4: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    after_2:
    // 0x8007D8B8: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8007D8BC: addiu       $a1, $s2, 0xCC
    ctx->r5 = ADD32(ctx->r18, 0XCC);
    // 0x8007D8C0: j           L_8007D908
    // 0x8007D8C4: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
        goto L_8007D908;
    // 0x8007D8C4: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
L_8007D8C8:
    // 0x8007D8C8: andi        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 & 0X2;
    // 0x8007D8CC: beq         $v0, $zero, L_8007D8F0
    if (ctx->r2 == 0) {
        // 0x8007D8D0: addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
            goto L_8007D8F0;
    }
    // 0x8007D8D0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8007D8D4: addiu       $a1, $s2, 0xA8
    ctx->r5 = ADD32(ctx->r18, 0XA8);
    // 0x8007D8D8: jal         0x800193E8
    // 0x8007D8DC: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    func_800193E8(rdram, ctx);
        goto after_3;
    // 0x8007D8DC: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    after_3:
    // 0x8007D8E0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8007D8E4: addiu       $a1, $s2, 0xC0
    ctx->r5 = ADD32(ctx->r18, 0XC0);
    // 0x8007D8E8: j           L_8007D908
    // 0x8007D8EC: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
        goto L_8007D908;
    // 0x8007D8EC: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
L_8007D8F0:
    // 0x8007D8F0: addiu       $a1, $s2, 0xA8
    ctx->r5 = ADD32(ctx->r18, 0XA8);
    // 0x8007D8F4: jal         0x800193E8
    // 0x8007D8F8: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    func_800193E8(rdram, ctx);
        goto after_4;
    // 0x8007D8F8: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    after_4:
    // 0x8007D8FC: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8007D900: addiu       $a1, $s2, 0xC0
    ctx->r5 = ADD32(ctx->r18, 0XC0);
L_8007D904:
    // 0x8007D904: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
L_8007D908:
    // 0x8007D908: jal         0x800193E8
    // 0x8007D90C: nop

    func_800193E8(rdram, ctx);
        goto after_5;
    // 0x8007D90C: nop

    after_5:
    // 0x8007D910: lwc1        $f0, 0x70($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8007D914: lwc1        $f2, 0x60($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8007D918: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8007D91C: swc1        $f0, 0x90($s2)
    MEM_W(0X90, ctx->r18) = ctx->f0.u32l;
    // 0x8007D920: lwc1        $f2, 0x74($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8007D924: lwc1        $f0, 0x64($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8007D928: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8007D92C: lwc1        $f4, 0x64($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X64);
    // 0x8007D930: mul.s       $f4, $f20, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x8007D934: swc1        $f2, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->f2.u32l;
    // 0x8007D938: lwc1        $f2, 0x78($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8007D93C: lwc1        $f0, 0x68($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8007D940: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8007D944: lwc1        $f0, 0x60($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X60);
    // 0x8007D948: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8007D94C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007D950: lwc1        $f4, -0x28DC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X28DC);
    // 0x8007D954: swc1        $f2, 0x98($s2)
    MEM_W(0X98, ctx->r18) = ctx->f2.u32l;
    // 0x8007D958: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8007D95C: nop

    // 0x8007D960: bc1f        L_8007D96C
    if (!c1cs) {
        // 0x8007D964: swc1        $f0, 0x60($s2)
        MEM_W(0X60, ctx->r18) = ctx->f0.u32l;
            goto L_8007D96C;
    }
    // 0x8007D964: swc1        $f0, 0x60($s2)
    MEM_W(0X60, ctx->r18) = ctx->f0.u32l;
    // 0x8007D968: swc1        $f4, 0x60($s2)
    MEM_W(0X60, ctx->r18) = ctx->f4.u32l;
L_8007D96C:
    // 0x8007D96C: lwc1        $f0, 0x60($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X60);
    // 0x8007D970: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007D974: lwc1        $f12, -0x28D8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X28D8);
    // 0x8007D978: mul.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8007D97C: jal         0x80033960
    // 0x8007D980: addiu       $s0, $s2, 0x70
    ctx->r16 = ADD32(ctx->r18, 0X70);
    sinf_recomp(rdram, ctx);
        goto after_6;
    // 0x8007D980: addiu       $s0, $s2, 0x70
    ctx->r16 = ADD32(ctx->r18, 0X70);
    after_6:
    // 0x8007D984: lwc1        $f2, 0x68($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X68);
    // 0x8007D988: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007D98C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8007D990: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8007D994: addiu       $a1, $s2, 0x90
    ctx->r5 = ADD32(ctx->r18, 0X90);
    // 0x8007D998: j           L_8007DBEC
    // 0x8007D99C: sw          $a2, 0x5C($s2)
    MEM_W(0X5C, ctx->r18) = ctx->r6;
        goto L_8007DBEC;
    // 0x8007D99C: sw          $a2, 0x5C($s2)
    MEM_W(0X5C, ctx->r18) = ctx->r6;
L_8007D9A0:
    // 0x8007D9A0: lbu         $v0, 0xF9($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0XF9);
    // 0x8007D9A4: addiu       $v1, $v0, -0x3
    ctx->r3 = ADD32(ctx->r2, -0X3);
    // 0x8007D9A8: sltiu       $v0, $v1, 0xA
    ctx->r2 = ctx->r3 < 0XA ? 1 : 0;
    // 0x8007D9AC: beq         $v0, $zero, L_8007DAE8
    if (ctx->r2 == 0) {
        // 0x8007D9B0: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_8007DAE8;
    }
    // 0x8007D9B0: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8007D9B4: addiu       $v0, $v0, -0x28D0
    ctx->r2 = ADD32(ctx->r2, -0X28D0);
    // 0x8007D9B8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8007D9BC: addu        $v1, $v1, $v0
    gpr jr_addend_8007D9C4 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8007D9C0: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x8007D9C4: jr          $v0
    // 0x8007D9C8: nop

    switch (jr_addend_8007D9C4 >> 2) {
        case 0: goto L_8007D9CC; break;
        case 1: goto L_8007DAE8; break;
        case 2: goto L_8007DA58; break;
        case 3: goto L_8007DA08; break;
        case 4: goto L_8007DAE8; break;
        case 5: goto L_8007DAE8; break;
        case 6: goto L_8007DA28; break;
        case 7: goto L_8007DA9C; break;
        case 8: goto L_8007DAE8; break;
        case 9: goto L_8007D9E8; break;
        default: switch_error(__func__, 0x8007D9C4, 0x8003D730);
    }
    // 0x8007D9C8: nop

L_8007D9CC:
    // 0x8007D9CC: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8007D9D0: addiu       $a1, $s2, 0xA8
    ctx->r5 = ADD32(ctx->r18, 0XA8);
    // 0x8007D9D4: jal         0x800193E8
    // 0x8007D9D8: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    func_800193E8(rdram, ctx);
        goto after_7;
    // 0x8007D9D8: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    after_7:
    // 0x8007D9DC: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8007D9E0: j           L_8007DA40
    // 0x8007D9E4: addiu       $a1, $s2, 0xB4
    ctx->r5 = ADD32(ctx->r18, 0XB4);
        goto L_8007DA40;
    // 0x8007D9E4: addiu       $a1, $s2, 0xB4
    ctx->r5 = ADD32(ctx->r18, 0XB4);
L_8007D9E8:
    // 0x8007D9E8: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8007D9EC: addiu       $a1, $s2, 0xA8
    ctx->r5 = ADD32(ctx->r18, 0XA8);
    // 0x8007D9F0: jal         0x800193E8
    // 0x8007D9F4: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    func_800193E8(rdram, ctx);
        goto after_8;
    // 0x8007D9F4: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    after_8:
    // 0x8007D9F8: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8007D9FC: addiu       $a1, $s2, 0xB4
    ctx->r5 = ADD32(ctx->r18, 0XB4);
    // 0x8007DA00: j           L_8007DA44
    // 0x8007DA04: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
        goto L_8007DA44;
    // 0x8007DA04: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
L_8007DA08:
    // 0x8007DA08: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8007DA0C: addiu       $a1, $s2, 0xB4
    ctx->r5 = ADD32(ctx->r18, 0XB4);
    // 0x8007DA10: jal         0x800193E8
    // 0x8007DA14: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    func_800193E8(rdram, ctx);
        goto after_9;
    // 0x8007DA14: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    after_9:
    // 0x8007DA18: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8007DA1C: addiu       $a1, $s2, 0xC0
    ctx->r5 = ADD32(ctx->r18, 0XC0);
    // 0x8007DA20: j           L_8007DA44
    // 0x8007DA24: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
        goto L_8007DA44;
    // 0x8007DA24: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
L_8007DA28:
    // 0x8007DA28: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8007DA2C: addiu       $a1, $s2, 0xB4
    ctx->r5 = ADD32(ctx->r18, 0XB4);
    // 0x8007DA30: jal         0x800193E8
    // 0x8007DA34: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    func_800193E8(rdram, ctx);
        goto after_10;
    // 0x8007DA34: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    after_10:
    // 0x8007DA38: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8007DA3C: addiu       $a1, $s2, 0xC0
    ctx->r5 = ADD32(ctx->r18, 0XC0);
L_8007DA40:
    // 0x8007DA40: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
L_8007DA44:
    // 0x8007DA44: jal         0x800193E8
    // 0x8007DA48: nop

    func_800193E8(rdram, ctx);
        goto after_11;
    // 0x8007DA48: nop

    after_11:
    // 0x8007DA4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007DA50: j           L_8007DAE8
    // 0x8007DA54: sb          $v0, 0xD9($s2)
    MEM_B(0XD9, ctx->r18) = ctx->r2;
        goto L_8007DAE8;
    // 0x8007DA54: sb          $v0, 0xD9($s2)
    MEM_B(0XD9, ctx->r18) = ctx->r2;
L_8007DA58:
    // 0x8007DA58: lbu         $v0, 0xD8($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0XD8);
    // 0x8007DA5C: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8007DA60: beq         $v0, $zero, L_8007DA80
    if (ctx->r2 == 0) {
        // 0x8007DA64: addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
            goto L_8007DA80;
    }
    // 0x8007DA64: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8007DA68: addiu       $a1, $s2, 0xA8
    ctx->r5 = ADD32(ctx->r18, 0XA8);
    // 0x8007DA6C: jal         0x800193E8
    // 0x8007DA70: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    func_800193E8(rdram, ctx);
        goto after_12;
    // 0x8007DA70: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    after_12:
    // 0x8007DA74: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8007DA78: j           L_8007DADC
    // 0x8007DA7C: addiu       $a1, $s2, 0xC0
    ctx->r5 = ADD32(ctx->r18, 0XC0);
        goto L_8007DADC;
    // 0x8007DA7C: addiu       $a1, $s2, 0xC0
    ctx->r5 = ADD32(ctx->r18, 0XC0);
L_8007DA80:
    // 0x8007DA80: addiu       $a1, $s2, 0xA8
    ctx->r5 = ADD32(ctx->r18, 0XA8);
    // 0x8007DA84: jal         0x800193E8
    // 0x8007DA88: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    func_800193E8(rdram, ctx);
        goto after_13;
    // 0x8007DA88: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    after_13:
    // 0x8007DA8C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8007DA90: addiu       $a1, $s2, 0xC0
    ctx->r5 = ADD32(ctx->r18, 0XC0);
    // 0x8007DA94: j           L_8007DAE0
    // 0x8007DA98: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
        goto L_8007DAE0;
    // 0x8007DA98: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
L_8007DA9C:
    // 0x8007DA9C: lbu         $v0, 0xD8($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0XD8);
    // 0x8007DAA0: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x8007DAA4: beq         $v0, $zero, L_8007DAC8
    if (ctx->r2 == 0) {
        // 0x8007DAA8: addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
            goto L_8007DAC8;
    }
    // 0x8007DAA8: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8007DAAC: addiu       $a1, $s2, 0xB4
    ctx->r5 = ADD32(ctx->r18, 0XB4);
    // 0x8007DAB0: jal         0x800193E8
    // 0x8007DAB4: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    func_800193E8(rdram, ctx);
        goto after_14;
    // 0x8007DAB4: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    after_14:
    // 0x8007DAB8: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8007DABC: addiu       $a1, $s2, 0xCC
    ctx->r5 = ADD32(ctx->r18, 0XCC);
    // 0x8007DAC0: j           L_8007DAE0
    // 0x8007DAC4: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
        goto L_8007DAE0;
    // 0x8007DAC4: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
L_8007DAC8:
    // 0x8007DAC8: addiu       $a1, $s2, 0xB4
    ctx->r5 = ADD32(ctx->r18, 0XB4);
    // 0x8007DACC: jal         0x800193E8
    // 0x8007DAD0: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    func_800193E8(rdram, ctx);
        goto after_15;
    // 0x8007DAD0: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    after_15:
    // 0x8007DAD4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8007DAD8: addiu       $a1, $s2, 0xCC
    ctx->r5 = ADD32(ctx->r18, 0XCC);
L_8007DADC:
    // 0x8007DADC: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
L_8007DAE0:
    // 0x8007DAE0: jal         0x800193E8
    // 0x8007DAE4: nop

    func_800193E8(rdram, ctx);
        goto after_16;
    // 0x8007DAE4: nop

    after_16:
L_8007DAE8:
    // 0x8007DAE8: lwc1        $f0, 0x70($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8007DAEC: lwc1        $f2, 0x60($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8007DAF0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8007DAF4: swc1        $f0, 0x90($s2)
    MEM_W(0X90, ctx->r18) = ctx->f0.u32l;
    // 0x8007DAF8: lwc1        $f2, 0x74($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8007DAFC: lwc1        $f0, 0x64($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8007DB00: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8007DB04: lwc1        $f4, 0x64($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X64);
    // 0x8007DB08: mul.s       $f4, $f20, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x8007DB0C: swc1        $f2, 0x94($s2)
    MEM_W(0X94, ctx->r18) = ctx->f2.u32l;
    // 0x8007DB10: lwc1        $f2, 0x78($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8007DB14: lwc1        $f0, 0x68($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8007DB18: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8007DB1C: lwc1        $f0, 0x60($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X60);
    // 0x8007DB20: add.s       $f4, $f0, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8007DB24: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007DB28: lwc1        $f0, -0x28A8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X28A8);
    // 0x8007DB2C: swc1        $f2, 0x98($s2)
    MEM_W(0X98, ctx->r18) = ctx->f2.u32l;
    // 0x8007DB30: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8007DB34: nop

    // 0x8007DB38: bc1f        L_8007DB5C
    if (!c1cs) {
        // 0x8007DB3C: swc1        $f4, 0x60($s2)
        MEM_W(0X60, ctx->r18) = ctx->f4.u32l;
            goto L_8007DB5C;
    }
    // 0x8007DB3C: swc1        $f4, 0x60($s2)
    MEM_W(0X60, ctx->r18) = ctx->f4.u32l;
    // 0x8007DB40: lbu         $v0, 0xD9($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0XD9);
    // 0x8007DB44: bnel        $v0, $zero, L_8007DB5C
    if (ctx->r2 != 0) {
        // 0x8007DB48: swc1        $f0, 0x60($s2)
        MEM_W(0X60, ctx->r18) = ctx->f0.u32l;
            goto L_8007DB5C;
    }
    goto skip_0;
    // 0x8007DB48: swc1        $f0, 0x60($s2)
    MEM_W(0X60, ctx->r18) = ctx->f0.u32l;
    skip_0:
    // 0x8007DB4C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007DB50: lwc1        $f0, -0x28A4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X28A4);
    // 0x8007DB54: sub.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8007DB58: swc1        $f0, 0x60($s2)
    MEM_W(0X60, ctx->r18) = ctx->f0.u32l;
L_8007DB5C:
    // 0x8007DB5C: lwc1        $f0, 0x60($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X60);
    // 0x8007DB60: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007DB64: lwc1        $f12, -0x28A0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X28A0);
    // 0x8007DB68: mul.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8007DB6C: jal         0x80033960
    // 0x8007DB70: nop

    sinf_recomp(rdram, ctx);
        goto after_17;
    // 0x8007DB70: nop

    after_17:
    // 0x8007DB74: lwc1        $f2, 0x68($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X68);
    // 0x8007DB78: mul.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007DB7C: lwc1        $f0, 0x64($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X64);
    // 0x8007DB80: mul.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8007DB84: lwc1        $f2, 0x6C($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X6C);
    // 0x8007DB88: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007DB8C: lwc1        $f4, -0x289C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X289C);
    // 0x8007DB90: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8007DB94: swc1        $f6, 0x5C($s2)
    MEM_W(0X5C, ctx->r18) = ctx->f6.u32l;
    // 0x8007DB98: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x8007DB9C: nop

    // 0x8007DBA0: bc1f        L_8007DBDC
    if (!c1cs) {
        // 0x8007DBA4: swc1        $f2, 0x6C($s2)
        MEM_W(0X6C, ctx->r18) = ctx->f2.u32l;
            goto L_8007DBDC;
    }
    // 0x8007DBA4: swc1        $f2, 0x6C($s2)
    MEM_W(0X6C, ctx->r18) = ctx->f2.u32l;
    // 0x8007DBA8: addiu       $s0, $s2, 0x80
    ctx->r16 = ADD32(ctx->r18, 0X80);
    // 0x8007DBAC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8007DBB0: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8007DBB4: jal         0x8001D144
    // 0x8007DBB8: addiu       $a1, $s2, 0x90
    ctx->r5 = ADD32(ctx->r18, 0X90);
    func_8001D144(rdram, ctx);
        goto after_18;
    // 0x8007DBB8: addiu       $a1, $s2, 0x90
    ctx->r5 = ADD32(ctx->r18, 0X90);
    after_18:
    // 0x8007DBBC: addiu       $a0, $s2, 0x70
    ctx->r4 = ADD32(ctx->r18, 0X70);
    // 0x8007DBC0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8007DBC4: addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
    // 0x8007DBC8: lw          $a2, 0x6C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X6C);
    // 0x8007DBCC: jal         0x8001D850
    // 0x8007DBD0: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    func_8001D850(rdram, ctx);
        goto after_19;
    // 0x8007DBD0: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_19:
    // 0x8007DBD4: j           L_8007DBF8
    // 0x8007DBD8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
        goto L_8007DBF8;
    // 0x8007DBD8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_8007DBDC:
    // 0x8007DBDC: addiu       $s0, $s2, 0x70
    ctx->r16 = ADD32(ctx->r18, 0X70);
    // 0x8007DBE0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8007DBE4: lw          $a2, 0x5C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X5C);
    // 0x8007DBE8: addiu       $a1, $s2, 0x90
    ctx->r5 = ADD32(ctx->r18, 0X90);
L_8007DBEC:
    // 0x8007DBEC: jal         0x8001D144
    // 0x8007DBF0: nop

    func_8001D144(rdram, ctx);
        goto after_20;
    // 0x8007DBF0: nop

    after_20:
    // 0x8007DBF4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_8007DBF8:
    // 0x8007DBF8: addiu       $a1, $s2, 0xC
    ctx->r5 = ADD32(ctx->r18, 0XC);
    // 0x8007DBFC: addiu       $s1, $sp, 0x50
    ctx->r17 = ADD32(ctx->r29, 0X50);
    // 0x8007DC00: jal         0x8001D3C4
    // 0x8007DC04: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_8001D3C4(rdram, ctx);
        goto after_21;
    // 0x8007DC04: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_21:
    // 0x8007DC08: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8007DC0C: addiu       $a1, $s2, 0x18
    ctx->r5 = ADD32(ctx->r18, 0X18);
    // 0x8007DC10: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8007DC14: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x8007DC18: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x8007DC1C: sw          $t0, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r8;
    // 0x8007DC20: sw          $t1, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r9;
    // 0x8007DC24: sw          $t2, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r10;
    // 0x8007DC28: jal         0x8001D3C4
    // 0x8007DC2C: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_8001D3C4(rdram, ctx);
        goto after_22;
    // 0x8007DC2C: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_22:
    // 0x8007DC30: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8007DC34: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x8007DC38: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x8007DC3C: sw          $t0, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r8;
    // 0x8007DC40: sw          $t1, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r9;
    // 0x8007DC44: sw          $t2, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r10;
    // 0x8007DC48: j           L_8007DD78
    // 0x8007DC4C: nop

        goto L_8007DD78;
    // 0x8007DC4C: nop

L_8007DC50:
    // 0x8007DC50: lwc1        $f0, 0x64($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X64);
    // 0x8007DC54: mul.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8007DC58: lwc1        $f2, 0x60($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X60);
    // 0x8007DC5C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007DC60: lwc1        $f4, -0x2898($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2898);
    // 0x8007DC64: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8007DC68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007DC6C: sb          $v0, 0xD9($s2)
    MEM_B(0XD9, ctx->r18) = ctx->r2;
    // 0x8007DC70: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x8007DC74: nop

    // 0x8007DC78: bc1f        L_8007DC84
    if (!c1cs) {
        // 0x8007DC7C: swc1        $f2, 0x60($s2)
        MEM_W(0X60, ctx->r18) = ctx->f2.u32l;
            goto L_8007DC84;
    }
    // 0x8007DC7C: swc1        $f2, 0x60($s2)
    MEM_W(0X60, ctx->r18) = ctx->f2.u32l;
    // 0x8007DC80: swc1        $f4, 0x60($s2)
    MEM_W(0X60, ctx->r18) = ctx->f4.u32l;
L_8007DC84:
    // 0x8007DC84: lwc1        $f0, 0x60($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X60);
    // 0x8007DC88: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007DC8C: lwc1        $f12, -0x2894($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2894);
    // 0x8007DC90: mul.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8007DC94: jal         0x80033960
    // 0x8007DC98: nop

    sinf_recomp(rdram, ctx);
        goto after_23;
    // 0x8007DC98: nop

    after_23:
    // 0x8007DC9C: lwc1        $f2, 0x68($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X68);
    // 0x8007DCA0: mul.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007DCA4: lwc1        $f0, 0x64($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X64);
    // 0x8007DCA8: mul.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8007DCAC: lwc1        $f2, 0x6C($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X6C);
    // 0x8007DCB0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007DCB4: lwc1        $f4, -0x2890($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2890);
    // 0x8007DCB8: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8007DCBC: swc1        $f6, 0x5C($s2)
    MEM_W(0X5C, ctx->r18) = ctx->f6.u32l;
    // 0x8007DCC0: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x8007DCC4: nop

    // 0x8007DCC8: bc1f        L_8007DD04
    if (!c1cs) {
        // 0x8007DCCC: swc1        $f2, 0x6C($s2)
        MEM_W(0X6C, ctx->r18) = ctx->f2.u32l;
            goto L_8007DD04;
    }
    // 0x8007DCCC: swc1        $f2, 0x6C($s2)
    MEM_W(0X6C, ctx->r18) = ctx->f2.u32l;
    // 0x8007DCD0: addiu       $s0, $s2, 0x80
    ctx->r16 = ADD32(ctx->r18, 0X80);
    // 0x8007DCD4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8007DCD8: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8007DCDC: jal         0x8001D144
    // 0x8007DCE0: addiu       $a1, $s2, 0x90
    ctx->r5 = ADD32(ctx->r18, 0X90);
    func_8001D144(rdram, ctx);
        goto after_24;
    // 0x8007DCE0: addiu       $a1, $s2, 0x90
    ctx->r5 = ADD32(ctx->r18, 0X90);
    after_24:
    // 0x8007DCE4: addiu       $a0, $s2, 0x70
    ctx->r4 = ADD32(ctx->r18, 0X70);
    // 0x8007DCE8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8007DCEC: addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
    // 0x8007DCF0: lw          $a2, 0x6C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X6C);
    // 0x8007DCF4: jal         0x8001D850
    // 0x8007DCF8: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    func_8001D850(rdram, ctx);
        goto after_25;
    // 0x8007DCF8: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_25:
    // 0x8007DCFC: j           L_8007DD1C
    // 0x8007DD00: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
        goto L_8007DD1C;
    // 0x8007DD00: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_8007DD04:
    // 0x8007DD04: addiu       $s0, $s2, 0x70
    ctx->r16 = ADD32(ctx->r18, 0X70);
    // 0x8007DD08: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8007DD0C: lw          $a2, 0x5C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X5C);
    // 0x8007DD10: jal         0x8001D144
    // 0x8007DD14: addiu       $a1, $s2, 0x90
    ctx->r5 = ADD32(ctx->r18, 0X90);
    func_8001D144(rdram, ctx);
        goto after_26;
    // 0x8007DD14: addiu       $a1, $s2, 0x90
    ctx->r5 = ADD32(ctx->r18, 0X90);
    after_26:
    // 0x8007DD18: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_8007DD1C:
    // 0x8007DD1C: addiu       $a1, $s2, 0xC
    ctx->r5 = ADD32(ctx->r18, 0XC);
    // 0x8007DD20: addiu       $s1, $sp, 0x50
    ctx->r17 = ADD32(ctx->r29, 0X50);
    // 0x8007DD24: jal         0x8001D3C4
    // 0x8007DD28: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_8001D3C4(rdram, ctx);
        goto after_27;
    // 0x8007DD28: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_27:
    // 0x8007DD2C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8007DD30: addiu       $a1, $s2, 0x18
    ctx->r5 = ADD32(ctx->r18, 0X18);
    // 0x8007DD34: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8007DD38: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x8007DD3C: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x8007DD40: sw          $t0, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r8;
    // 0x8007DD44: sw          $t1, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r9;
    // 0x8007DD48: sw          $t2, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r10;
    // 0x8007DD4C: jal         0x8001D3C4
    // 0x8007DD50: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_8001D3C4(rdram, ctx);
        goto after_28;
    // 0x8007DD50: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_28:
    // 0x8007DD54: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8007DD58: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8007DD5C: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x8007DD60: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x8007DD64: sw          $t0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r8;
    // 0x8007DD68: sw          $t1, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r9;
    // 0x8007DD6C: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x8007DD70: jal         0x80059F10
    // 0x8007DD74: nop

    func_80059F10(rdram, ctx);
        goto after_29;
    // 0x8007DD74: nop

    after_29:
L_8007DD78:
    // 0x8007DD78: lw          $ra, 0x8C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X8C);
    // 0x8007DD7C: lw          $s2, 0x88($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X88);
    // 0x8007DD80: lw          $s1, 0x84($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X84);
    // 0x8007DD84: lw          $s0, 0x80($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X80);
    // 0x8007DD88: ldc1        $f20, 0x90($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X90);
    // 0x8007DD8C: jr          $ra
    // 0x8007DD90: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8007DD90: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_8007DD94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007DD94: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x8007DD98: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8007DD9C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007DDA0: lwc1        $f2, -0x288C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X288C);
    // 0x8007DDA4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007DDA8: lwc1        $f4, -0x2888($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2888);
    // 0x8007DDAC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007DDB0: lwc1        $f0, -0x2884($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2884);
    // 0x8007DDB4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007DDB8: lwc1        $f6, -0x2880($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2880);
    // 0x8007DDBC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007DDC0: lwc1        $f8, -0x287C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X287C);
    // 0x8007DDC4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007DDC8: lwc1        $f10, -0x2878($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2878);
    // 0x8007DDCC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007DDD0: lwc1        $f12, -0x2874($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2874);
    // 0x8007DDD4: lw          $v0, 0xC08($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC08);
    // 0x8007DDD8: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x8007DDDC: sw          $ra, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r31;
    // 0x8007DDE0: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // 0x8007DDE4: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x8007DDE8: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x8007DDEC: lw          $a3, 0x4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X4);
    // 0x8007DDF0: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x8007DDF4: sw          $a1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r5;
    // 0x8007DDF8: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x8007DDFC: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x8007DE00: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x8007DE04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007DE08: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8007DE0C: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x8007DE10: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8007DE14: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8007DE18: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x8007DE1C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8007DE20: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8007DE24: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x8007DE28: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x8007DE2C: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x8007DE30: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x8007DE34: sh          $zero, 0x4C($sp)
    MEM_H(0X4C, ctx->r29) = 0;
    // 0x8007DE38: sh          $zero, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = 0;
    // 0x8007DE3C: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    // 0x8007DE40: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    // 0x8007DE44: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    // 0x8007DE48: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
    // 0x8007DE4C: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x8007DE50: swc1        $f12, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f12.u32l;
    // 0x8007DE54: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    // 0x8007DE58: sw          $zero, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = 0;
    // 0x8007DE5C: sb          $v0, 0x7C($sp)
    MEM_B(0X7C, ctx->r29) = ctx->r2;
    // 0x8007DE60: lwc1        $f12, 0x0($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8007DE64: lwc1        $f14, 0x8($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8007DE68: jal         0x800698F4
    // 0x8007DE6C: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    func_800698F4(rdram, ctx);
        goto after_0;
    // 0x8007DE6C: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    after_0:
    // 0x8007DE70: bnel        $v0, $zero, L_8007DE84
    if (ctx->r2 != 0) {
        // 0x8007DE74: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_8007DE84;
    }
    goto skip_0;
    // 0x8007DE74: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    skip_0:
    // 0x8007DE78: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8007DE7C: j           L_8007DE88
    // 0x8007DE80: addiu       $v0, $v0, -0x66E0
    ctx->r2 = ADD32(ctx->r2, -0X66E0);
        goto L_8007DE88;
    // 0x8007DE80: addiu       $v0, $v0, -0x66E0
    ctx->r2 = ADD32(ctx->r2, -0X66E0);
L_8007DE84:
    // 0x8007DE84: addiu       $v0, $v0, -0x6740
    ctx->r2 = ADD32(ctx->r2, -0X6740);
L_8007DE88:
    // 0x8007DE88: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007DE8C: lwc1        $f0, -0x2870($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2870);
    // 0x8007DE90: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007DE94: lwc1        $f2, -0x286C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X286C);
    // 0x8007DE98: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8007DE9C: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    // 0x8007DEA0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007DEA4: lwc1        $f2, -0x2868($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2868);
    // 0x8007DEA8: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x8007DEAC: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8007DEB0: nop

    // 0x8007DEB4: bc1t        L_8007DECC
    if (c1cs) {
        // 0x8007DEB8: sb          $v0, 0x7D($sp)
        MEM_B(0X7D, ctx->r29) = ctx->r2;
            goto L_8007DECC;
    }
    // 0x8007DEB8: sb          $v0, 0x7D($sp)
    MEM_B(0X7D, ctx->r29) = ctx->r2;
    // 0x8007DEBC: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007DEC0: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x8007DEC4: j           L_8007DEE0
    // 0x8007DEC8: nop

        goto L_8007DEE0;
    // 0x8007DEC8: nop

L_8007DECC:
    // 0x8007DECC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8007DED0: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8007DED4: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007DED8: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x8007DEDC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_8007DEE0:
    // 0x8007DEE0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007DEE4: lwc1        $f2, -0x2864($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2864);
    // 0x8007DEE8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007DEEC: lwc1        $f0, -0x2860($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2860);
    // 0x8007DEF0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007DEF4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007DEF8: lwc1        $f2, -0x285C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X285C);
    // 0x8007DEFC: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8007DF00: nop

    // 0x8007DF04: bc1t        L_8007DF1C
    if (c1cs) {
        // 0x8007DF08: sh          $v1, 0x80($sp)
        MEM_H(0X80, ctx->r29) = ctx->r3;
            goto L_8007DF1C;
    }
    // 0x8007DF08: sh          $v1, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r3;
    // 0x8007DF0C: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007DF10: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x8007DF14: j           L_8007DF34
    // 0x8007DF18: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_8007DF34;
    // 0x8007DF18: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8007DF1C:
    // 0x8007DF1C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8007DF20: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8007DF24: trunc.w.s   $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8007DF28: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x8007DF2C: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8007DF30: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8007DF34:
    // 0x8007DF34: sh          $v0, 0x84($sp)
    MEM_H(0X84, ctx->r29) = ctx->r2;
    // 0x8007DF38: lui         $v0, 0x900
    ctx->r2 = S32(0X900 << 16);
    // 0x8007DF3C: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    // 0x8007DF40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007DF44: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8007DF48: sh          $v1, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r3;
    // 0x8007DF4C: jal         0x80041CBC
    // 0x8007DF50: sh          $v0, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r2;
    func_80041CBC(rdram, ctx);
        goto after_1;
    // 0x8007DF50: sh          $v0, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8007DF54: lw          $ra, 0x90($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X90);
    // 0x8007DF58: jr          $ra
    // 0x8007DF5C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8007DF5C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_8007DF60(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007DF60: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8007DF64: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x8007DF68: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    // 0x8007DF6C: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x8007DF70: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8007DF74: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x8007DF78: addiu       $s1, $sp, 0x48
    ctx->r17 = ADD32(ctx->r29, 0X48);
    // 0x8007DF7C: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8007DF80: sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // 0x8007DF84: sdc1        $f22, 0x70($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X70, ctx->r29);
    // 0x8007DF88: sdc1        $f20, 0x68($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X68, ctx->r29);
    // 0x8007DF8C: lw          $v0, 0x38($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X38);
    // 0x8007DF90: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007DF94: lwc1        $f22, -0x2858($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X2858);
    // 0x8007DF98: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007DF9C: lwc1        $f0, -0x2854($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2854);
    // 0x8007DFA0: lhu         $a0, 0x198($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X198);
    // 0x8007DFA4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x8007DFA8: jal         0x8007602C
    // 0x8007DFAC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_8007602C(rdram, ctx);
        goto after_0;
    // 0x8007DFAC: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x8007DFB0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8007DFB4: addiu       $s2, $v0, -0x7FA8
    ctx->r18 = ADD32(ctx->r2, -0X7FA8);
L_8007DFB8:
    // 0x8007DFB8: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007DFBC: mtc1        $s0, $f20
    ctx->f20.u32l = ctx->r16;
    // 0x8007DFC0: cvt.s.w     $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.fl = CVT_S_W(ctx->f20.u32l);
    // 0x8007DFC4: div.s       $f2, $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f22.fl);
    // 0x8007DFC8: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x8007DFCC: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8007DFD0: div.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8007DFD4: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8007DFD8: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8007DFDC: add.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x8007DFE0: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8007DFE4: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8007DFE8: add.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f0.fl;
    // 0x8007DFEC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8007DFF0: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    // 0x8007DFF4: jal         0x80067D90
    // 0x8007DFF8: swc1        $f14, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f14.u32l;
    func_80067D90(rdram, ctx);
        goto after_1;
    // 0x8007DFF8: swc1        $f14, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x8007DFFC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8007E000: jal         0x8007DD94
    // 0x8007E004: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    func_8007DD94(rdram, ctx);
        goto after_2;
    // 0x8007E004: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x8007E008: lwc1        $f2, 0x28($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007E00C: div.s       $f2, $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f22.fl);
    // 0x8007E010: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x8007E014: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8007E018: div.s       $f4, $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = DIV_S(ctx->f4.fl, ctx->f22.fl);
    // 0x8007E01C: mul.s       $f4, $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8007E020: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8007E024: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8007E028: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8007E02C: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x8007E030: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8007E034: add.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f0.fl;
    // 0x8007E038: add.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x8007E03C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007E040: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8007E044: add.s       $f14, $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f4.fl;
    // 0x8007E048: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8007E04C: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    // 0x8007E050: jal         0x80067D90
    // 0x8007E054: swc1        $f14, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f14.u32l;
    func_80067D90(rdram, ctx);
        goto after_3;
    // 0x8007E054: swc1        $f14, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f14.u32l;
    after_3:
    // 0x8007E058: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8007E05C: jal         0x8007DD94
    // 0x8007E060: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    func_8007DD94(rdram, ctx);
        goto after_4;
    // 0x8007E060: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    after_4:
    // 0x8007E064: slti        $v0, $s0, 0x3
    ctx->r2 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x8007E068: bne         $v0, $zero, L_8007DFB8
    if (ctx->r2 != 0) {
        // 0x8007E06C: nop
    
            goto L_8007DFB8;
    }
    // 0x8007E06C: nop

    // 0x8007E070: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8007E074: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007E078: lwc1        $f22, -0x2850($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X2850);
L_8007E07C:
    // 0x8007E07C: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8007E080: mtc1        $s0, $f20
    ctx->f20.u32l = ctx->r16;
    // 0x8007E084: cvt.s.w     $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    ctx->f20.fl = CVT_S_W(ctx->f20.u32l);
    // 0x8007E088: div.s       $f2, $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f22.fl);
    // 0x8007E08C: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x8007E090: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8007E094: div.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8007E098: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8007E09C: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8007E0A0: add.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x8007E0A4: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8007E0A8: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8007E0AC: add.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f0.fl;
    // 0x8007E0B0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8007E0B4: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    // 0x8007E0B8: jal         0x80067D90
    // 0x8007E0BC: swc1        $f14, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f14.u32l;
    func_80067D90(rdram, ctx);
        goto after_5;
    // 0x8007E0BC: swc1        $f14, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f14.u32l;
    after_5:
    // 0x8007E0C0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8007E0C4: jal         0x8007DD94
    // 0x8007E0C8: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    func_8007DD94(rdram, ctx);
        goto after_6;
    // 0x8007E0C8: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    after_6:
    // 0x8007E0CC: lwc1        $f2, 0x38($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8007E0D0: div.s       $f2, $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f22.fl);
    // 0x8007E0D4: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x8007E0D8: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8007E0DC: div.s       $f4, $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = DIV_S(ctx->f4.fl, ctx->f22.fl);
    // 0x8007E0E0: mul.s       $f4, $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8007E0E4: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8007E0E8: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8007E0EC: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8007E0F0: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x8007E0F4: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8007E0F8: add.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f0.fl;
    // 0x8007E0FC: add.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x8007E100: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007E104: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8007E108: add.s       $f14, $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f4.fl;
    // 0x8007E10C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8007E110: swc1        $f12, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f12.u32l;
    // 0x8007E114: jal         0x80067D90
    // 0x8007E118: swc1        $f14, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f14.u32l;
    func_80067D90(rdram, ctx);
        goto after_7;
    // 0x8007E118: swc1        $f14, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f14.u32l;
    after_7:
    // 0x8007E11C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x8007E120: jal         0x8007DD94
    // 0x8007E124: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    func_8007DD94(rdram, ctx);
        goto after_8;
    // 0x8007E124: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    after_8:
    // 0x8007E128: slti        $v0, $s0, 0x4
    ctx->r2 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x8007E12C: bne         $v0, $zero, L_8007E07C
    if (ctx->r2 != 0) {
        // 0x8007E130: nop
    
            goto L_8007E07C;
    }
    // 0x8007E130: nop

    // 0x8007E134: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x8007E138: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x8007E13C: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x8007E140: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x8007E144: ldc1        $f22, 0x70($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X70);
    // 0x8007E148: ldc1        $f20, 0x68($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X68);
    // 0x8007E14C: jr          $ra
    // 0x8007E150: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x8007E150: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_8007E154(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007E154: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8007E158: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8007E15C: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x8007E160: sdc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X50, ctx->r29);
    // 0x8007E164: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x8007E168: addiu       $a1, $s3, 0x1F8
    ctx->r5 = ADD32(ctx->r19, 0X1F8);
    // 0x8007E16C: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    // 0x8007E170: sw          $ra, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r31;
    // 0x8007E174: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8007E178: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8007E17C: jal         0x80018EF4
    // 0x8007E180: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    zmemcpy(rdram, ctx);
        goto after_0;
    // 0x8007E180: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    after_0:
    // 0x8007E184: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007E188: lwc1        $f0, -0x284C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X284C);
    // 0x8007E18C: mul.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8007E190: lwc1        $f4, 0x24($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X24);
    // 0x8007E194: mul.s       $f4, $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8007E198: lwc1        $f2, 0x28($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X28);
    // 0x8007E19C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8007E1A0: lwc1        $f0, 0x2C($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X2C);
    // 0x8007E1A4: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8007E1A8: swc1        $f2, 0x28($s3)
    MEM_W(0X28, ctx->r19) = ctx->f2.u32l;
    // 0x8007E1AC: mov.s       $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    ctx->f6.fl = ctx->f2.fl;
    // 0x8007E1B0: mul.s       $f6, $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8007E1B4: lwc1        $f2, 0x0($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X0);
    // 0x8007E1B8: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x8007E1BC: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x8007E1C0: lwc1        $f14, 0x8($s3)
    ctx->f14.u32l = MEM_W(ctx->r19, 0X8);
    // 0x8007E1C4: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    // 0x8007E1C8: add.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f0.fl;
    // 0x8007E1CC: lwc1        $f0, 0x4($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X4);
    // 0x8007E1D0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8007E1D4: swc1        $f2, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f2.u32l;
    // 0x8007E1D8: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x8007E1DC: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x8007E1E0: swc1        $f14, 0x8($s3)
    MEM_W(0X8, ctx->r19) = ctx->f14.u32l;
    // 0x8007E1E4: jal         0x80067D90
    // 0x8007E1E8: swc1        $f0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f0.u32l;
    func_80067D90(rdram, ctx);
        goto after_1;
    // 0x8007E1E8: swc1        $f0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f0.u32l;
    after_1:
    // 0x8007E1EC: lwc1        $f2, 0x4($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X4);
    // 0x8007E1F0: mov.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.fl = ctx->f0.fl;
    // 0x8007E1F4: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x8007E1F8: nop

    // 0x8007E1FC: bc1f        L_8007E330
    if (!c1cs) {
        // 0x8007E200: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_8007E330;
    }
    // 0x8007E200: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8007E204: ori         $s2, $zero, 0xFFFF
    ctx->r18 = 0 | 0XFFFF;
    // 0x8007E208: lwc1        $f0, 0x40($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X40);
    // 0x8007E20C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007E210: lwc1        $f2, -0x2848($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2848);
    // 0x8007E214: addu        $s0, $s3, $zero
    ctx->r16 = ADD32(ctx->r19, 0);
    // 0x8007E218: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007E21C: lwc1        $f2, 0x40($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X40);
    // 0x8007E220: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8007E224: swc1        $f4, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->f4.u32l;
    // 0x8007E228: sh          $v0, 0x1B2($s3)
    MEM_H(0X1B2, ctx->r19) = ctx->r2;
    // 0x8007E22C: swc1        $f2, 0x44($s3)
    MEM_W(0X44, ctx->r19) = ctx->f2.u32l;
    // 0x8007E230: swc1        $f0, 0x48($s3)
    MEM_W(0X48, ctx->r19) = ctx->f0.u32l;
L_8007E234:
    // 0x8007E234: lhu         $v0, 0x114($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X114);
    // 0x8007E238: beql        $v0, $s2, L_8007E250
    if (ctx->r2 == ctx->r18) {
        // 0x8007E23C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8007E250;
    }
    goto skip_0;
    // 0x8007E23C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x8007E240: jal         0x8003ED74
    // 0x8007E244: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    func_8003ED74(rdram, ctx);
        goto after_2;
    // 0x8007E244: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_2:
    // 0x8007E248: sh          $s2, 0x114($s0)
    MEM_H(0X114, ctx->r16) = ctx->r18;
    // 0x8007E24C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8007E250:
    // 0x8007E250: slti        $v0, $s1, 0x4
    ctx->r2 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x8007E254: bne         $v0, $zero, L_8007E234
    if (ctx->r2 != 0) {
        // 0x8007E258: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_8007E234;
    }
    // 0x8007E258: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x8007E25C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8007E260: addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
    // 0x8007E264: sh          $v0, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r2;
    // 0x8007E268: sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    // 0x8007E26C: sh          $v1, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r3;
    // 0x8007E270: sh          $v0, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r2;
    // 0x8007E274: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x8007E278: lh          $v0, 0x1B4($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X1B4);
    // 0x8007E27C: blez        $v0, L_8007E2BC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8007E280: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_8007E2BC;
    }
    // 0x8007E280: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x8007E284: ori         $s2, $zero, 0xFFFF
    ctx->r18 = 0 | 0XFFFF;
    // 0x8007E288: addu        $s0, $s3, $zero
    ctx->r16 = ADD32(ctx->r19, 0);
L_8007E28C:
    // 0x8007E28C: lhu         $v0, 0x1B6($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X1B6);
    // 0x8007E290: beq         $v0, $s2, L_8007E2A8
    if (ctx->r2 == ctx->r18) {
        // 0x8007E294: addiu       $a1, $zero, 0x5
        ctx->r5 = ADD32(0, 0X5);
            goto L_8007E2A8;
    }
    // 0x8007E294: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8007E298: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x8007E29C: jal         0x8003E8DC
    // 0x8007E2A0: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    slotDispatcherIter(rdram, ctx);
        goto after_3;
    // 0x8007E2A0: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_3:
    // 0x8007E2A4: sh          $s2, 0x1B6($s0)
    MEM_H(0X1B6, ctx->r16) = ctx->r18;
L_8007E2A8:
    // 0x8007E2A8: lh          $v0, 0x1B4($s3)
    ctx->r2 = MEM_H(ctx->r19, 0X1B4);
    // 0x8007E2AC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8007E2B0: slt         $v0, $s1, $v0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8007E2B4: bne         $v0, $zero, L_8007E28C
    if (ctx->r2 != 0) {
        // 0x8007E2B8: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_8007E28C;
    }
    // 0x8007E2B8: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
L_8007E2BC:
    // 0x8007E2BC: jal         0x8007DF60
    // 0x8007E2C0: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    func_8007DF60(rdram, ctx);
        goto after_4;
    // 0x8007E2C0: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_4:
    // 0x8007E2C4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8007E2C8: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8007E2CC: addiu       $s1, $s3, 0x24
    ctx->r17 = ADD32(ctx->r19, 0X24);
    // 0x8007E2D0: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8007E2D4: addiu       $v0, $zero, 0x75
    ctx->r2 = ADD32(0, 0X75);
    // 0x8007E2D8: addiu       $s2, $zero, 0x7F
    ctx->r18 = ADD32(0, 0X7F);
    // 0x8007E2DC: lui         $a3, 0x41C8
    ctx->r7 = S32(0X41C8 << 16);
    // 0x8007E2E0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007E2E4: lwc1        $f20, -0x2844($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X2844);
    // 0x8007E2E8: addiu       $s0, $zero, 0x64
    ctx->r16 = ADD32(0, 0X64);
    // 0x8007E2EC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8007E2F0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8007E2F4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8007E2F8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8007E2FC: jal         0x800989D8
    // 0x8007E300: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    func_800989D8(rdram, ctx);
        goto after_5;
    // 0x8007E300: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    after_5:
    // 0x8007E304: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8007E308: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8007E30C: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x8007E310: lui         $a3, 0x41C8
    ctx->r7 = S32(0X41C8 << 16);
    // 0x8007E314: addiu       $v0, $zero, 0x77
    ctx->r2 = ADD32(0, 0X77);
    // 0x8007E318: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x8007E31C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8007E320: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8007E324: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8007E328: jal         0x800989D8
    // 0x8007E32C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    func_800989D8(rdram, ctx);
        goto after_6;
    // 0x8007E32C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    after_6:
L_8007E330:
    // 0x8007E330: addiu       $a0, $s3, 0x1F8
    ctx->r4 = ADD32(ctx->r19, 0X1F8);
    // 0x8007E334: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8007E338: jal         0x80018EF4
    // 0x8007E33C: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    zmemcpy(rdram, ctx);
        goto after_7;
    // 0x8007E33C: addiu       $a2, $zero, 0x30
    ctx->r6 = ADD32(0, 0X30);
    after_7:
    // 0x8007E340: lw          $ra, 0x48($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X48);
    // 0x8007E344: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8007E348: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8007E34C: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8007E350: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8007E354: ldc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X50);
    // 0x8007E358: jr          $ra
    // 0x8007E35C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8007E35C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_8007E360(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007E360: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8007E364: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8007E368: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x8007E36C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8007E370: addiu       $s0, $sp, 0x20
    ctx->r16 = ADD32(ctx->r29, 0X20);
    // 0x8007E374: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8007E378: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8007E37C: addiu       $s3, $s1, 0x18
    ctx->r19 = ADD32(ctx->r17, 0X18);
    // 0x8007E380: sdc1        $f22, 0x50($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X50, ctx->r29);
    // 0x8007E384: mtc1        $a1, $f22
    ctx->f22.u32l = ctx->r5;
    // 0x8007E388: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8007E38C: sw          $ra, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r31;
    // 0x8007E390: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8007E394: sdc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X48, ctx->r29);
    // 0x8007E398: addiu       $t1, $v0, -0x2840
    ctx->r9 = ADD32(ctx->r2, -0X2840);
    // 0x8007E39C: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x8007E3A0: lw          $a3, 0x4($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X4);
    // 0x8007E3A4: lw          $t0, 0x8($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X8);
    // 0x8007E3A8: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x8007E3AC: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8007E3B0: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8007E3B4: jal         0x8001CFE8
    // 0x8007E3B8: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_8001CFE8(rdram, ctx);
        goto after_0;
    // 0x8007E3B8: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_0:
    // 0x8007E3BC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007E3C0: lwc1        $f2, -0x2834($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2834);
    // 0x8007E3C4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8007E3C8: c.lt.s      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.fl < ctx->f2.fl;
    // 0x8007E3CC: nop

    // 0x8007E3D0: bc1f        L_8007E4E0
    if (!c1cs) {
        // 0x8007E3D4: addiu       $s2, $s1, 0x90
        ctx->r18 = ADD32(ctx->r17, 0X90);
            goto L_8007E4E0;
    }
    // 0x8007E3D4: addiu       $s2, $s1, 0x90
    ctx->r18 = ADD32(ctx->r17, 0X90);
    // 0x8007E3D8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8007E3DC: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8007E3E0: jal         0x80019548
    // 0x8007E3E4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_80019548(rdram, ctx);
        goto after_1;
    // 0x8007E3E4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_1:
    // 0x8007E3E8: jal         0x8001CF2C
    // 0x8007E3EC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_8001CF2C(rdram, ctx);
        goto after_2;
    // 0x8007E3EC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_2:
    // 0x8007E3F0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007E3F4: lwc1        $f2, -0x2830($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2830);
    // 0x8007E3F8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8007E3FC: nop

    // 0x8007E400: bc1f        L_8007E4E0
    if (!c1cs) {
        // 0x8007E404: nop
    
            goto L_8007E4E0;
    }
    // 0x8007E404: nop

    // 0x8007E408: jal         0x8001C5CC
    // 0x8007E40C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_8001C5CC(rdram, ctx);
        goto after_3;
    // 0x8007E40C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_3:
    // 0x8007E410: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007E414: lwc1        $f2, -0x282C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X282C);
    // 0x8007E418: mul.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007E41C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007E420: lwc1        $f0, -0x2828($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2828);
    // 0x8007E424: mul.s       $f0, $f22, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x8007E428: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8007E42C: nop

    // 0x8007E430: bc1tl       L_8007E438
    if (c1cs) {
        // 0x8007E434: mov.s       $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
            goto L_8007E438;
    }
    goto skip_0;
    // 0x8007E434: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    skip_0:
L_8007E438:
    // 0x8007E438: addiu       $s0, $s1, 0x70
    ctx->r16 = ADD32(ctx->r17, 0X70);
    // 0x8007E43C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8007E440: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8007E444: jal         0x8001D144
    // 0x8007E448: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_8001D144(rdram, ctx);
        goto after_4;
    // 0x8007E448: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_4:
    // 0x8007E44C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8007E450: addiu       $a1, $s1, 0xC
    ctx->r5 = ADD32(ctx->r17, 0XC);
    // 0x8007E454: jal         0x8001D3C4
    // 0x8007E458: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    func_8001D3C4(rdram, ctx);
        goto after_5;
    // 0x8007E458: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_5:
    // 0x8007E45C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8007E460: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8007E464: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x8007E468: lw          $a3, 0x14($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X14);
    // 0x8007E46C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8007E470: sw          $v1, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r3;
    // 0x8007E474: sw          $a3, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r7;
    // 0x8007E478: sw          $t0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r8;
    // 0x8007E47C: jal         0x8001D3C4
    // 0x8007E480: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    func_8001D3C4(rdram, ctx);
        goto after_6;
    // 0x8007E480: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_6:
    // 0x8007E484: lw          $v1, 0x10($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10);
    // 0x8007E488: lw          $a3, 0x14($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X14);
    // 0x8007E48C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8007E490: sw          $v1, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r3;
    // 0x8007E494: sw          $a3, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r7;
    // 0x8007E498: sw          $t0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r8;
    // 0x8007E49C: jal         0x80059F10
    // 0x8007E4A0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80059F10(rdram, ctx);
        goto after_7;
    // 0x8007E4A0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_7:
    // 0x8007E4A4: lwc1        $f0, 0x40($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X40);
    // 0x8007E4A8: lwc1        $f2, 0x48($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X48);
    // 0x8007E4AC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8007E4B0: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x8007E4B4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007E4B8: lwc1        $f2, -0x2824($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2824);
    // 0x8007E4BC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007E4C0: lwc1        $f2, 0x44($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X44);
    // 0x8007E4C4: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8007E4C8: lwc1        $f0, 0x48($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X48);
    // 0x8007E4CC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8007E4D0: nop

    // 0x8007E4D4: bc1f        L_8007E4E0
    if (!c1cs) {
        // 0x8007E4D8: swc1        $f2, 0x44($s1)
        MEM_W(0X44, ctx->r17) = ctx->f2.u32l;
            goto L_8007E4E0;
    }
    // 0x8007E4D8: swc1        $f2, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f2.u32l;
    // 0x8007E4DC: swc1        $f0, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f0.u32l;
L_8007E4E0:
    // 0x8007E4E0: lw          $ra, 0x40($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X40);
    // 0x8007E4E4: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8007E4E8: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8007E4EC: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8007E4F0: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8007E4F4: ldc1        $f22, 0x50($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X50);
    // 0x8007E4F8: ldc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X48);
    // 0x8007E4FC: jr          $ra
    // 0x8007E500: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8007E500: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_8007E504(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007E504: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8007E508: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8007E50C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8007E510: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8007E514: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x8007E518: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8007E51C: sdc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X40, ctx->r29);
    // 0x8007E520: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x8007E524: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x8007E528: lw          $s0, 0x4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X4);
    // 0x8007E52C: beq         $a1, $v0, L_8007E70C
    if (ctx->r5 == ctx->r2) {
        // 0x8007E530: addu        $s1, $a2, $zero
        ctx->r17 = ADD32(ctx->r6, 0);
            goto L_8007E70C;
    }
    // 0x8007E530: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x8007E534: slti        $v0, $a1, 0x3
    ctx->r2 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
    // 0x8007E538: beq         $v0, $zero, L_8007E550
    if (ctx->r2 == 0) {
        // 0x8007E53C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8007E550;
    }
    // 0x8007E53C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007E540: beq         $a1, $v0, L_8007E564
    if (ctx->r5 == ctx->r2) {
        // 0x8007E544: lui         $a0, 0x8004
        ctx->r4 = S32(0X8004 << 16);
            goto L_8007E564;
    }
    // 0x8007E544: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8007E548: j           L_8007E7EC
    // 0x8007E54C: nop

        goto L_8007E7EC;
    // 0x8007E54C: nop

L_8007E550:
    // 0x8007E550: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8007E554: beq         $a1, $v0, L_8007E720
    if (ctx->r5 == ctx->r2) {
        // 0x8007E558: addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
            goto L_8007E720;
    }
    // 0x8007E558: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8007E55C: j           L_8007E7EC
    // 0x8007E560: nop

        goto L_8007E7EC;
    // 0x8007E560: nop

L_8007E564:
    // 0x8007E564: jal         0x80056EB0
    // 0x8007E568: addiu       $a0, $a0, -0x2820
    ctx->r4 = ADD32(ctx->r4, -0X2820);
    walkMeshdef0List(rdram, ctx);
        goto after_0;
    // 0x8007E568: addiu       $a0, $a0, -0x2820
    ctx->r4 = ADD32(ctx->r4, -0X2820);
    after_0:
    // 0x8007E56C: sw          $v0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r2;
    // 0x8007E570: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8007E574: lw          $v1, 0x4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X4);
    // 0x8007E578: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8007E57C: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8007E580: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8007E584: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x8007E588: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8007E58C: lw          $v1, 0x4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X4);
    // 0x8007E590: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8007E594: lwc1        $f2, 0x8($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8007E598: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8007E59C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007E5A0: lwc1        $f2, -0x2818($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2818);
    // 0x8007E5A4: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x8007E5A8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8007E5AC: lw          $v1, 0x4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X4);
    // 0x8007E5B0: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8007E5B4: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8007E5B8: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x8007E5BC: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x8007E5C0: swc1        $f2, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f2.u32l;
    // 0x8007E5C4: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x8007E5C8: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8007E5CC: swc1        $f2, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f2.u32l;
    // 0x8007E5D0: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x8007E5D4: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x8007E5D8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8007E5DC: lhu         $v0, 0x70($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X70);
    // 0x8007E5E0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007E5E4: lwc1        $f6, -0x2814($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2814);
    // 0x8007E5E8: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x8007E5EC: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x8007E5F0: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8007E5F4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007E5F8: lwc1        $f4, -0x2810($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2810);
    // 0x8007E5FC: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8007E600: swc1        $f2, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f2.u32l;
    // 0x8007E604: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8007E608: lhu         $v0, 0x72($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X72);
    // 0x8007E60C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8007E610: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007E614: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8007E618: nop

    // 0x8007E61C: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8007E620: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x8007E624: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8007E628: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8007E62C: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8007E630: nop

    // 0x8007E634: bc1t        L_8007E648
    if (c1cs) {
        // 0x8007E638: sub.s       $f2, $f0, $f2
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_8007E648;
    }
    // 0x8007E638: sub.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8007E63C: div.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8007E640: j           L_8007E64C
    // 0x8007E644: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
        goto L_8007E64C;
    // 0x8007E644: swc1        $f0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f0.u32l;
L_8007E648:
    // 0x8007E648: swc1        $f6, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f6.u32l;
L_8007E64C:
    // 0x8007E64C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007E650: lwc1        $f22, -0x280C($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X280C);
    // 0x8007E654: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007E658: lwc1        $f20, -0x2808($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X2808);
    // 0x8007E65C: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
L_8007E660:
    // 0x8007E660: jal         0x80003430
    // 0x8007E664: nop

    rand_recomp(rdram, ctx);
        goto after_1;
    // 0x8007E664: nop

    after_1:
    // 0x8007E668: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x8007E66C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8007E670: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007E674: sub.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x8007E678: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8007E67C: jal         0x80003430
    // 0x8007E680: swc1        $f0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f0.u32l;
    rand_recomp(rdram, ctx);
        goto after_2;
    // 0x8007E680: swc1        $f0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f0.u32l;
    after_2:
    // 0x8007E684: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x8007E688: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8007E68C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007E690: sub.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x8007E694: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8007E698: jal         0x80003430
    // 0x8007E69C: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    rand_recomp(rdram, ctx);
        goto after_3;
    // 0x8007E69C: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    after_3:
    // 0x8007E6A0: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x8007E6A4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8007E6A8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007E6AC: sub.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x8007E6B0: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8007E6B4: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    // 0x8007E6B8: jal         0x8001CF2C
    // 0x8007E6BC: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    func_8001CF2C(rdram, ctx);
        goto after_4;
    // 0x8007E6BC: swc1        $f0, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f0.u32l;
    after_4:
    // 0x8007E6C0: c.eq.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl == ctx->f24.fl;
    // 0x8007E6C4: nop

    // 0x8007E6C8: bc1t        L_8007E660
    if (c1cs) {
        // 0x8007E6CC: nop
    
            goto L_8007E660;
    }
    // 0x8007E6CC: nop

    // 0x8007E6D0: jal         0x8001CF58
    // 0x8007E6D4: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    normalize_vector(rdram, ctx);
        goto after_5;
    // 0x8007E6D4: addiu       $a0, $s0, 0x3C
    ctx->r4 = ADD32(ctx->r16, 0X3C);
    after_5:
    // 0x8007E6D8: jal         0x80003430
    // 0x8007E6DC: nop

    rand_recomp(rdram, ctx);
        goto after_6;
    // 0x8007E6DC: nop

    after_6:
    // 0x8007E6E0: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x8007E6E4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007E6E8: lwc1        $f2, -0x2804($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2804);
    // 0x8007E6EC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8007E6F0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8007E6F4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8007E6F8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8007E6FC: lwc1        $f2, -0x2800($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X2800);
    // 0x8007E700: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8007E704: j           L_8007E7EC
    // 0x8007E708: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
        goto L_8007E7EC;
    // 0x8007E708: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
L_8007E70C:
    // 0x8007E70C: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x8007E710: jal         0x8005779C
    // 0x8007E714: nop

    func_8005779C(rdram, ctx);
        goto after_7;
    // 0x8007E714: nop

    after_7:
    // 0x8007E718: j           L_8007E7EC
    // 0x8007E71C: nop

        goto L_8007E7EC;
    // 0x8007E71C: nop

L_8007E720:
    // 0x8007E720: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8007E724: lw          $v1, 0x4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X4);
    // 0x8007E728: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8007E72C: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x8007E730: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8007E734: lwc1        $f20, 0x8($s1)
    ctx->f20.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8007E738: swc1        $f0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f0.u32l;
    // 0x8007E73C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8007E740: lw          $v1, 0x4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X4);
    // 0x8007E744: lwc1        $f2, 0x8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8007E748: lwc1        $f0, 0x8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X8);
    // 0x8007E74C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8007E750: lwc1        $f0, 0x48($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8007E754: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8007E758: swc1        $f2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f2.u32l;
    // 0x8007E75C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8007E760: lw          $v1, 0x4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X4);
    // 0x8007E764: lwc1        $f2, 0xC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8007E768: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8007E76C: lwc1        $f0, 0xC($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8007E770: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8007E774: addiu       $a1, $s0, 0x3C
    ctx->r5 = ADD32(ctx->r16, 0X3C);
    // 0x8007E778: jal         0x8001D240
    // 0x8007E77C: swc1        $f2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f2.u32l;
    func_8001D240(rdram, ctx);
        goto after_8;
    // 0x8007E77C: swc1        $f2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f2.u32l;
    after_8:
    // 0x8007E780: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8007E784: addiu       $a1, $s0, 0xC
    ctx->r5 = ADD32(ctx->r16, 0XC);
    // 0x8007E788: jal         0x8001D3C4
    // 0x8007E78C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    func_8001D3C4(rdram, ctx);
        goto after_9;
    // 0x8007E78C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_9:
    // 0x8007E790: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8007E794: addiu       $a1, $s0, 0x18
    ctx->r5 = ADD32(ctx->r16, 0X18);
    // 0x8007E798: jal         0x8001D3C4
    // 0x8007E79C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    func_8001D3C4(rdram, ctx);
        goto after_10;
    // 0x8007E79C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_10:
    // 0x8007E7A0: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x8007E7A4: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x8007E7A8: lwc1        $f2, 0x34($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X34);
    // 0x8007E7AC: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8007E7B0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8007E7B4: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x8007E7B8: nop

    // 0x8007E7BC: bc1t        L_8007E7EC
    if (c1cs) {
        // 0x8007E7C0: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_8007E7EC;
    }
    // 0x8007E7C0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8007E7C4: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x8007E7C8: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8007E7CC: jal         0x80059B50
    // 0x8007E7D0: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_80059B50(rdram, ctx);
        goto after_11;
    // 0x8007E7D0: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_11:
    // 0x8007E7D4: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x8007E7D8: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    // 0x8007E7DC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8007E7E0: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8007E7E4: jal         0x80057C8C
    // 0x8007E7E8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_80057C8C(rdram, ctx);
        goto after_12;
    // 0x8007E7E8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_12:
L_8007E7EC:
    // 0x8007E7EC: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x8007E7F0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8007E7F4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8007E7F8: ldc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X40);
    // 0x8007E7FC: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x8007E800: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x8007E804: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007E808: jr          $ra
    // 0x8007E80C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8007E80C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
