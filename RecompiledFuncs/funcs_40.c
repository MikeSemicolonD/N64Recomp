#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_800E9D74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9D74: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x800E9D78: sw          $s0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r16;
    // 0x800E9D7C: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x800E9D80: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800E9D84: addiu       $a1, $a1, -0x7918
    ctx->r5 = ADD32(ctx->r5, -0X7918);
    // 0x800E9D88: sw          $ra, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r31;
    // 0x800E9D8C: sw          $s1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r17;
    // 0x800E9D90: lw          $s1, 0x4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X4);
    // 0x800E9D94: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800E9D98: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800E9D9C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800E9DA0: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x800E9DA4: jal         0x80058360
    // 0x800E9DA8: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    func_80058360(rdram, ctx);
        goto after_0;
    // 0x800E9DA8: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x800E9DAC: bne         $s0, $zero, L_800E9DCC
    if (ctx->r16 != 0) {
        // 0x800E9DB0: nop
    
            goto L_800E9DCC;
    }
    // 0x800E9DB0: nop

    // 0x800E9DB4: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800E9DB8: lui         $a1, 0x3D88
    ctx->r5 = S32(0X3D88 << 16);
    // 0x800E9DBC: ori         $a1, $a1, 0x8889
    ctx->r5 = ctx->r5 | 0X8889;
    // 0x800E9DC0: jal         0x800F2D74
    // 0x800E9DC4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_800F2D74(rdram, ctx);
        goto after_1;
    // 0x800E9DC4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_1:
    // 0x800E9DC8: sw          $zero, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = 0;
L_800E9DCC:
    // 0x800E9DCC: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800E9DD0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x800E9DD4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800E9DD8: jal         0x800F1870
    // 0x800E9DDC: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    func_800F1870(rdram, ctx);
        goto after_2;
    // 0x800E9DDC: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    after_2:
    // 0x800E9DE0: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
    // 0x800E9DE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800E9DE8: bne         $s0, $v0, L_800E9EAC
    if (ctx->r16 != ctx->r2) {
        // 0x800E9DEC: nop
    
            goto L_800E9EAC;
    }
    // 0x800E9DEC: nop

    // 0x800E9DF0: sh          $zero, 0x58($sp)
    MEM_H(0X58, ctx->r29) = 0;
    // 0x800E9DF4: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800E9DF8: jal         0x800F2A00
    // 0x800E9DFC: nop

    func_800F2A00(rdram, ctx);
        goto after_3;
    // 0x800E9DFC: nop

    after_3:
    // 0x800E9E00: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800E9E04: sh          $v0, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r2;
    // 0x800E9E08: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E9E0C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800E9E10: lwc1        $f0, -0x7914($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7914);
    // 0x800E9E14: lw          $v0, 0x7CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7CE4);
    // 0x800E9E18: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800E9E1C: lwc1        $f2, -0x7910($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7910);
    // 0x800E9E20: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800E9E24: lwc1        $f4, -0x790C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X790C);
    // 0x800E9E28: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x800E9E2C: swc1        $f0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f0.u32l;
    // 0x800E9E30: lw          $v1, 0x34($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X34);
    // 0x800E9E34: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800E9E38: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800E9E3C: lwc1        $f0, 0xD8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XD8);
    // 0x800E9E40: lui         $a3, 0x8011
    ctx->r7 = S32(0X8011 << 16);
    // 0x800E9E44: swc1        $f0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f0.u32l;
    // 0x800E9E48: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800E9E4C: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x800E9E50: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x800E9E54: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800E9E58: jal         0x800F2FCC
    // 0x800E9E5C: addiu       $a3, $a3, -0x4E88
    ctx->r7 = ADD32(ctx->r7, -0X4E88);
    func_800F2FCC(rdram, ctx);
        goto after_4;
    // 0x800E9E5C: addiu       $a3, $a3, -0x4E88
    ctx->r7 = ADD32(ctx->r7, -0X4E88);
    after_4:
    // 0x800E9E60: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x800E9E64: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x800E9E68: jal         0x8003E8DC
    // 0x800E9E6C: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    func_8003E8DC(rdram, ctx);
        goto after_5;
    // 0x800E9E6C: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    after_5:
    // 0x800E9E70: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800E9E74: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800E9E78: addiu       $a2, $a1, 0x24
    ctx->r6 = ADD32(ctx->r5, 0X24);
    // 0x800E9E7C: lui         $a3, 0x41A0
    ctx->r7 = S32(0X41A0 << 16);
    // 0x800E9E80: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800E9E84: lwc1        $f0, -0x7908($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7908);
    // 0x800E9E88: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // 0x800E9E8C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800E9E90: addiu       $v0, $zero, 0x78
    ctx->r2 = ADD32(0, 0X78);
    // 0x800E9E94: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800E9E98: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // 0x800E9E9C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800E9EA0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800E9EA4: jal         0x800989D8
    // 0x800E9EA8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800989D8(rdram, ctx);
        goto after_6;
    // 0x800E9EA8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_6:
L_800E9EAC:
    // 0x800E9EAC: lw          $ra, 0x80($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X80);
    // 0x800E9EB0: lw          $s1, 0x7C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X7C);
    // 0x800E9EB4: lw          $s0, 0x78($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X78);
    // 0x800E9EB8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800E9EBC: jr          $ra
    // 0x800E9EC0: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x800E9EC0: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_800E9EC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9EC4: addiu       $sp, $sp, -0x1B0
    ctx->r29 = ADD32(ctx->r29, -0X1B0);
    // 0x800E9EC8: sw          $s3, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->r19;
    // 0x800E9ECC: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x800E9ED0: sw          $ra, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r31;
    // 0x800E9ED4: sw          $s6, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r22;
    // 0x800E9ED8: sw          $s5, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r21;
    // 0x800E9EDC: sw          $s4, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->r20;
    // 0x800E9EE0: sw          $s2, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r18;
    // 0x800E9EE4: sw          $s1, 0x174($sp)
    MEM_W(0X174, ctx->r29) = ctx->r17;
    // 0x800E9EE8: sw          $s0, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->r16;
    // 0x800E9EEC: sdc1        $f26, 0x1A8($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X1A8, ctx->r29);
    // 0x800E9EF0: sdc1        $f24, 0x1A0($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X1A0, ctx->r29);
    // 0x800E9EF4: sdc1        $f22, 0x198($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X198, ctx->r29);
    // 0x800E9EF8: sdc1        $f20, 0x190($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X190, ctx->r29);
    // 0x800E9EFC: lw          $a0, 0x38($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X38);
    // 0x800E9F00: mtc1        $a1, $f22
    ctx->f22.u32l = ctx->r5;
    // 0x800E9F04: jal         0x800F06BC
    // 0x800E9F08: nop

    func_800F06BC(rdram, ctx);
        goto after_0;
    // 0x800E9F08: nop

    after_0:
    // 0x800E9F0C: andi        $s0, $v0, 0xFF
    ctx->r16 = ctx->r2 & 0XFF;
    // 0x800E9F10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800E9F14: bne         $s0, $v0, L_800EA244
    if (ctx->r16 != ctx->r2) {
        // 0x800E9F18: addiu       $s4, $sp, 0xD0
        ctx->r20 = ADD32(ctx->r29, 0XD0);
            goto L_800EA244;
    }
    // 0x800E9F18: addiu       $s4, $sp, 0xD0
    ctx->r20 = ADD32(ctx->r29, 0XD0);
    // 0x800E9F1C: lw          $a0, 0x38($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X38);
    // 0x800E9F20: jal         0x800F09A8
    // 0x800E9F24: nop

    func_800F09A8(rdram, ctx);
        goto after_1;
    // 0x800E9F24: nop

    after_1:
    // 0x800E9F28: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800E9F2C: bne         $v0, $s0, L_800EA244
    if (ctx->r2 != ctx->r16) {
        // 0x800E9F30: addiu       $s4, $sp, 0xD0
        ctx->r20 = ADD32(ctx->r29, 0XD0);
            goto L_800EA244;
    }
    // 0x800E9F30: addiu       $s4, $sp, 0xD0
    ctx->r20 = ADD32(ctx->r29, 0XD0);
    // 0x800E9F34: lw          $a0, 0x38($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X38);
    // 0x800E9F38: jal         0x800F2988
    // 0x800E9F3C: addiu       $a1, $sp, 0xA0
    ctx->r5 = ADD32(ctx->r29, 0XA0);
    func_800F2988(rdram, ctx);
        goto after_2;
    // 0x800E9F3C: addiu       $a1, $sp, 0xA0
    ctx->r5 = ADD32(ctx->r29, 0XA0);
    after_2:
    // 0x800E9F40: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x800E9F44: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800E9F48: addiu       $s1, $sp, 0x90
    ctx->r17 = ADD32(ctx->r29, 0X90);
    // 0x800E9F4C: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    // 0x800E9F50: jal         0x800F2AC4
    // 0x800E9F54: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    func_800F2AC4(rdram, ctx);
        goto after_3;
    // 0x800E9F54: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    after_3:
    // 0x800E9F58: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800E9F5C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800E9F60: jal         0x80059B50
    // 0x800E9F64: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    func_80059B50(rdram, ctx);
        goto after_4;
    // 0x800E9F64: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_4:
    // 0x800E9F68: addiu       $s0, $sp, 0x40
    ctx->r16 = ADD32(ctx->r29, 0X40);
    // 0x800E9F6C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800E9F70: jal         0x8001C774
    // 0x800E9F74: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_8001C774(rdram, ctx);
        goto after_5;
    // 0x800E9F74: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_5:
    // 0x800E9F78: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800E9F7C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800E9F80: addiu       $s2, $sp, 0x80
    ctx->r18 = ADD32(ctx->r29, 0X80);
    // 0x800E9F84: jal         0x800193E8
    // 0x800E9F88: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_800193E8(rdram, ctx);
        goto after_6;
    // 0x800E9F88: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_6:
    // 0x800E9F8C: lwc1        $f2, 0x54($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X54);
    // 0x800E9F90: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800E9F94: lwc1        $f0, -0x7904($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7904);
    // 0x800E9F98: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800E9F9C: lwc1        $f0, 0x80($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800E9FA0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800E9FA4: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
    // 0x800E9FA8: lwc1        $f2, 0x54($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X54);
    // 0x800E9FAC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800E9FB0: lwc1        $f0, -0x7900($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7900);
    // 0x800E9FB4: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800E9FB8: lwc1        $f0, 0x84($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800E9FBC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800E9FC0: swc1        $f0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f0.u32l;
    // 0x800E9FC4: lwc1        $f2, 0x54($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X54);
    // 0x800E9FC8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800E9FCC: lwc1        $f0, -0x78FC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X78FC);
    // 0x800E9FD0: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800E9FD4: lwc1        $f0, 0x88($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X88);
    // 0x800E9FD8: addiu       $s4, $sp, 0x70
    ctx->r20 = ADD32(ctx->r29, 0X70);
    // 0x800E9FDC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800E9FE0: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800E9FE4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800E9FE8: jal         0x8001CFA0
    // 0x800E9FEC: swc1        $f0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f0.u32l;
    func_8001CFA0(rdram, ctx);
        goto after_7;
    // 0x800E9FEC: swc1        $f0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f0.u32l;
    after_7:
    // 0x800E9FF0: lw          $a1, 0x68($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X68);
    // 0x800E9FF4: jal         0x8001CC3C
    // 0x800E9FF8: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_8001CC3C(rdram, ctx);
        goto after_8;
    // 0x800E9FF8: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_8:
    // 0x800E9FFC: lw          $a1, 0x64($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X64);
    // 0x800EA000: jal         0x8001CCCC
    // 0x800EA004: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_8001CCCC(rdram, ctx);
        goto after_9;
    // 0x800EA004: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_9:
    // 0x800EA008: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800EA00C: lui         $s6, 0x8011
    ctx->r22 = S32(0X8011 << 16);
    // 0x800EA010: addiu       $s5, $s6, -0x4E94
    ctx->r21 = ADD32(ctx->r22, -0X4E94);
    // 0x800EA014: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x800EA018: jal         0x800193E8
    // 0x800EA01C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_800193E8(rdram, ctx);
        goto after_10;
    // 0x800EA01C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_10:
    // 0x800EA020: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800EA024: jal         0x8001CFE8
    // 0x800EA028: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_8001CFE8(rdram, ctx);
        goto after_11;
    // 0x800EA028: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_11:
    // 0x800EA02C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EA030: lwc1        $f26, -0x78F8($at)
    ctx->f26.u32l = MEM_W(ctx->r1, -0X78F8);
    // 0x800EA034: jal         0x8001C5CC
    // 0x800EA038: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_8001C5CC(rdram, ctx);
        goto after_12;
    // 0x800EA038: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_12:
    // 0x800EA03C: mul.s       $f20, $f0, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x800EA040: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EA044: lwc1        $f0, -0x78F4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X78F4);
    // 0x800EA048: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800EA04C: nop

    // 0x800EA050: bc1f        L_800EA438
    if (!c1cs) {
        // 0x800EA054: nop
    
            goto L_800EA438;
    }
    // 0x800EA054: nop

    // 0x800EA058: lwc1        $f0, 0x58($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X58);
    // 0x800EA05C: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800EA060: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800EA064: nop

    // 0x800EA068: bc1tl       L_800EA070
    if (c1cs) {
        // 0x800EA06C: mov.s       $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
            goto L_800EA070;
    }
    goto skip_0;
    // 0x800EA06C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    skip_0:
L_800EA070:
    // 0x800EA070: addiu       $s1, $sp, 0xD0
    ctx->r17 = ADD32(ctx->r29, 0XD0);
    // 0x800EA074: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800EA078: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800EA07C: jal         0x80019548
    // 0x800EA080: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    func_80019548(rdram, ctx);
        goto after_13;
    // 0x800EA080: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    after_13:
    // 0x800EA084: jal         0x8001CF58
    // 0x800EA088: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    normalize_vector(rdram, ctx);
        goto after_14;
    // 0x800EA088: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_14:
    // 0x800EA08C: addiu       $s0, $sp, 0xE0
    ctx->r16 = ADD32(ctx->r29, 0XE0);
    // 0x800EA090: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800EA094: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800EA098: jal         0x8001D240
    // 0x800EA09C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_8001D240(rdram, ctx);
        goto after_15;
    // 0x800EA09C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_15:
    // 0x800EA0A0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800EA0A4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800EA0A8: jal         0x8001D3C4
    // 0x800EA0AC: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    func_8001D3C4(rdram, ctx);
        goto after_16;
    // 0x800EA0AC: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    after_16:
    // 0x800EA0B0: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x800EA0B4: lwc1        $f0, 0x70($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800EA0B8: lwc1        $f2, 0x78($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800EA0BC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800EA0C0: sw          $zero, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = 0;
    // 0x800EA0C4: swc1        $f0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f0.u32l;
    // 0x800EA0C8: jal         0x8001CFE8
    // 0x800EA0CC: swc1        $f2, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f2.u32l;
    func_8001CFE8(rdram, ctx);
        goto after_17;
    // 0x800EA0CC: swc1        $f2, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f2.u32l;
    after_17:
    // 0x800EA0D0: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x800EA0D4: jal         0x8001CF2C
    // 0x800EA0D8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    func_8001CF2C(rdram, ctx);
        goto after_18;
    // 0x800EA0D8: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_18:
    // 0x800EA0DC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800EA0E0: jal         0x8001CF2C
    // 0x800EA0E4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_8001CF2C(rdram, ctx);
        goto after_19;
    // 0x800EA0E4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_19:
    // 0x800EA0E8: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800EA0EC: jal         0x8001C5CC
    // 0x800EA0F0: div.s       $f12, $f22, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = DIV_S(ctx->f22.fl, ctx->f20.fl);
    func_8001C5CC(rdram, ctx);
        goto after_20;
    // 0x800EA0F0: div.s       $f12, $f22, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = DIV_S(ctx->f22.fl, ctx->f20.fl);
    after_20:
    // 0x800EA0F4: addiu       $a0, $sp, 0xF0
    ctx->r4 = ADD32(ctx->r29, 0XF0);
    // 0x800EA0F8: addiu       $a1, $sp, 0x100
    ctx->r5 = ADD32(ctx->r29, 0X100);
    // 0x800EA0FC: addiu       $a2, $sp, 0x110
    ctx->r6 = ADD32(ctx->r29, 0X110);
    // 0x800EA100: mul.s       $f20, $f0, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x800EA104: addiu       $t2, $s6, -0x4E94
    ctx->r10 = ADD32(ctx->r22, -0X4E94);
    // 0x800EA108: lw          $v1, 0x0($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X0);
    // 0x800EA10C: lw          $t0, 0x4($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X4);
    // 0x800EA110: lw          $t1, 0x8($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X8);
    // 0x800EA114: sw          $v1, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r3;
    // 0x800EA118: sw          $t0, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r8;
    // 0x800EA11C: sw          $t1, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r9;
    // 0x800EA120: sw          $zero, 0x104($sp)
    MEM_W(0X104, ctx->r29) = 0;
    // 0x800EA124: lw          $v1, 0xD0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XD0);
    // 0x800EA128: lw          $t0, 0xD4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XD4);
    // 0x800EA12C: lw          $t1, 0xD8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XD8);
    // 0x800EA130: sw          $v1, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r3;
    // 0x800EA134: sw          $t0, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r8;
    // 0x800EA138: sw          $t1, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r9;
    // 0x800EA13C: jal         0x80019548
    // 0x800EA140: sw          $zero, 0x114($sp)
    MEM_W(0X114, ctx->r29) = 0;
    func_80019548(rdram, ctx);
        goto after_21;
    // 0x800EA140: sw          $zero, 0x114($sp)
    MEM_W(0X114, ctx->r29) = 0;
    after_21:
    // 0x800EA144: lwc1        $f0, 0xF4($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XF4);
    // 0x800EA148: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x800EA14C: c.le.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl <= ctx->f0.fl;
    // 0x800EA150: nop

    // 0x800EA154: bc1fl       L_800EA15C
    if (!c1cs) {
        // 0x800EA158: neg.s       $f20, $f20
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
            goto L_800EA15C;
    }
    goto skip_1;
    // 0x800EA158: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    skip_1:
L_800EA15C:
    // 0x800EA15C: neg.s       $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = -ctx->f20.fl;
    // 0x800EA160: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800EA164: jal         0x8001CD6C
    // 0x800EA168: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    func_8001CD6C(rdram, ctx);
        goto after_22;
    // 0x800EA168: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_22:
    // 0x800EA16C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800EA170: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x800EA174: jal         0x800193E8
    // 0x800EA178: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_800193E8(rdram, ctx);
        goto after_23;
    // 0x800EA178: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_23:
    // 0x800EA17C: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x800EA180: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800EA184: swc1        $f24, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f24.u32l;
    // 0x800EA188: jal         0x8001CFE8
    // 0x800EA18C: swc1        $f20, 0x64($s3)
    MEM_W(0X64, ctx->r19) = ctx->f20.u32l;
    func_8001CFE8(rdram, ctx);
        goto after_24;
    // 0x800EA18C: swc1        $f20, 0x64($s3)
    MEM_W(0X64, ctx->r19) = ctx->f20.u32l;
    after_24:
    // 0x800EA190: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x800EA194: jal         0x8001CF2C
    // 0x800EA198: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_8001CF2C(rdram, ctx);
        goto after_25;
    // 0x800EA198: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_25:
    // 0x800EA19C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800EA1A0: jal         0x8001CF2C
    // 0x800EA1A4: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    func_8001CF2C(rdram, ctx);
        goto after_26;
    // 0x800EA1A4: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_26:
    // 0x800EA1A8: mul.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x800EA1AC: jal         0x8001C5CC
    // 0x800EA1B0: div.s       $f12, $f20, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = DIV_S(ctx->f20.fl, ctx->f22.fl);
    func_8001C5CC(rdram, ctx);
        goto after_27;
    // 0x800EA1B0: div.s       $f12, $f20, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = DIV_S(ctx->f20.fl, ctx->f22.fl);
    after_27:
    // 0x800EA1B4: mul.s       $f2, $f0, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x800EA1B8: lwc1        $f0, 0xD4($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800EA1BC: c.le.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl <= ctx->f24.fl;
    // 0x800EA1C0: nop

    // 0x800EA1C4: bc1fl       L_800EA1CC
    if (!c1cs) {
        // 0x800EA1C8: neg.s       $f2, $f2
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
            goto L_800EA1CC;
    }
    goto skip_2;
    // 0x800EA1C8: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    skip_2:
L_800EA1CC:
    // 0x800EA1CC: lwc1        $f0, 0x64($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X64);
    // 0x800EA1D0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EA1D4: lwc1        $f4, -0x78F0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X78F0);
    // 0x800EA1D8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800EA1DC: nop

    // 0x800EA1E0: bc1f        L_800EA1F0
    if (!c1cs) {
        // 0x800EA1E4: swc1        $f2, 0x68($s3)
        MEM_W(0X68, ctx->r19) = ctx->f2.u32l;
            goto L_800EA1F0;
    }
    // 0x800EA1E4: swc1        $f2, 0x68($s3)
    MEM_W(0X68, ctx->r19) = ctx->f2.u32l;
    // 0x800EA1E8: j           L_800EA208
    // 0x800EA1EC: swc1        $f4, 0x64($s3)
    MEM_W(0X64, ctx->r19) = ctx->f4.u32l;
        goto L_800EA208;
    // 0x800EA1EC: swc1        $f4, 0x64($s3)
    MEM_W(0X64, ctx->r19) = ctx->f4.u32l;
L_800EA1F0:
    // 0x800EA1F0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EA1F4: lwc1        $f2, -0x78EC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X78EC);
    // 0x800EA1F8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800EA1FC: nop

    // 0x800EA200: bc1tl       L_800EA208
    if (c1cs) {
        // 0x800EA204: swc1        $f2, 0x64($s3)
        MEM_W(0X64, ctx->r19) = ctx->f2.u32l;
            goto L_800EA208;
    }
    goto skip_3;
    // 0x800EA204: swc1        $f2, 0x64($s3)
    MEM_W(0X64, ctx->r19) = ctx->f2.u32l;
    skip_3:
L_800EA208:
    // 0x800EA208: lwc1        $f0, 0x68($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X68);
    // 0x800EA20C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EA210: lwc1        $f2, -0x78E8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X78E8);
    // 0x800EA214: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800EA218: nop

    // 0x800EA21C: bc1tl       L_800EA438
    if (c1cs) {
        // 0x800EA220: swc1        $f2, 0x68($s3)
        MEM_W(0X68, ctx->r19) = ctx->f2.u32l;
            goto L_800EA438;
    }
    goto skip_4;
    // 0x800EA220: swc1        $f2, 0x68($s3)
    MEM_W(0X68, ctx->r19) = ctx->f2.u32l;
    skip_4:
    // 0x800EA224: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EA228: lwc1        $f2, -0x78E4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X78E4);
    // 0x800EA22C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800EA230: nop

    // 0x800EA234: bc1f        L_800EA438
    if (!c1cs) {
        // 0x800EA238: nop
    
            goto L_800EA438;
    }
    // 0x800EA238: nop

    // 0x800EA23C: j           L_800EA438
    // 0x800EA240: swc1        $f2, 0x68($s3)
    MEM_W(0X68, ctx->r19) = ctx->f2.u32l;
        goto L_800EA438;
    // 0x800EA240: swc1        $f2, 0x68($s3)
    MEM_W(0X68, ctx->r19) = ctx->f2.u32l;
L_800EA244:
    // 0x800EA244: lw          $a1, 0x68($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X68);
    // 0x800EA248: jal         0x8001CC3C
    // 0x800EA24C: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    func_8001CC3C(rdram, ctx);
        goto after_28;
    // 0x800EA24C: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    after_28:
    // 0x800EA250: lw          $a1, 0x64($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X64);
    // 0x800EA254: jal         0x8001CCCC
    // 0x800EA258: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    func_8001CCCC(rdram, ctx);
        goto after_29;
    // 0x800EA258: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    after_29:
    // 0x800EA25C: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800EA260: lui         $s6, 0x8011
    ctx->r22 = S32(0X8011 << 16);
    // 0x800EA264: addiu       $s5, $s6, -0x4E94
    ctx->r21 = ADD32(ctx->r22, -0X4E94);
    // 0x800EA268: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x800EA26C: addiu       $s2, $sp, 0x110
    ctx->r18 = ADD32(ctx->r29, 0X110);
    // 0x800EA270: jal         0x800193E8
    // 0x800EA274: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    func_800193E8(rdram, ctx);
        goto after_30;
    // 0x800EA274: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_30:
    // 0x800EA278: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x800EA27C: jal         0x8001CFE8
    // 0x800EA280: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_8001CFE8(rdram, ctx);
        goto after_31;
    // 0x800EA280: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_31:
    // 0x800EA284: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EA288: lwc1        $f26, -0x78E0($at)
    ctx->f26.u32l = MEM_W(ctx->r1, -0X78E0);
    // 0x800EA28C: jal         0x8001C5CC
    // 0x800EA290: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    func_8001C5CC(rdram, ctx);
        goto after_32;
    // 0x800EA290: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_32:
    // 0x800EA294: mul.s       $f20, $f0, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x800EA298: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EA29C: lwc1        $f0, -0x78DC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X78DC);
    // 0x800EA2A0: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800EA2A4: nop

    // 0x800EA2A8: bc1f        L_800EA438
    if (!c1cs) {
        // 0x800EA2AC: nop
    
            goto L_800EA438;
    }
    // 0x800EA2AC: nop

    // 0x800EA2B0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EA2B4: lwc1        $f0, -0x78D8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X78D8);
    // 0x800EA2B8: mul.s       $f0, $f22, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x800EA2BC: lwc1        $f2, 0x58($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X58);
    // 0x800EA2C0: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800EA2C4: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x800EA2C8: nop

    // 0x800EA2CC: bc1tl       L_800EA2D4
    if (c1cs) {
        // 0x800EA2D0: mov.s       $f20, $f2
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
            goto L_800EA2D4;
    }
    goto skip_5;
    // 0x800EA2D0: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
    skip_5:
L_800EA2D4:
    // 0x800EA2D4: addiu       $s1, $sp, 0x120
    ctx->r17 = ADD32(ctx->r29, 0X120);
    // 0x800EA2D8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800EA2DC: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800EA2E0: jal         0x80019548
    // 0x800EA2E4: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    func_80019548(rdram, ctx);
        goto after_33;
    // 0x800EA2E4: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    after_33:
    // 0x800EA2E8: jal         0x8001CF58
    // 0x800EA2EC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    normalize_vector(rdram, ctx);
        goto after_34;
    // 0x800EA2EC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_34:
    // 0x800EA2F0: addiu       $s0, $sp, 0x130
    ctx->r16 = ADD32(ctx->r29, 0X130);
    // 0x800EA2F4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800EA2F8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800EA2FC: jal         0x8001D240
    // 0x800EA300: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_8001D240(rdram, ctx);
        goto after_35;
    // 0x800EA300: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_35:
    // 0x800EA304: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800EA308: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800EA30C: addiu       $s0, $sp, 0x100
    ctx->r16 = ADD32(ctx->r29, 0X100);
    // 0x800EA310: jal         0x8001D3C4
    // 0x800EA314: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_8001D3C4(rdram, ctx);
        goto after_36;
    // 0x800EA314: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_36:
    // 0x800EA318: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x800EA31C: lwc1        $f0, 0x100($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X100);
    // 0x800EA320: lwc1        $f2, 0x108($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X108);
    // 0x800EA324: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800EA328: sw          $zero, 0x124($sp)
    MEM_W(0X124, ctx->r29) = 0;
    // 0x800EA32C: swc1        $f0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f0.u32l;
    // 0x800EA330: jal         0x8001CFE8
    // 0x800EA334: swc1        $f2, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->f2.u32l;
    func_8001CFE8(rdram, ctx);
        goto after_37;
    // 0x800EA334: swc1        $f2, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->f2.u32l;
    after_37:
    // 0x800EA338: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x800EA33C: jal         0x8001CF2C
    // 0x800EA340: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    func_8001CF2C(rdram, ctx);
        goto after_38;
    // 0x800EA340: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_38:
    // 0x800EA344: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800EA348: jal         0x8001CF2C
    // 0x800EA34C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_8001CF2C(rdram, ctx);
        goto after_39;
    // 0x800EA34C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_39:
    // 0x800EA350: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800EA354: jal         0x8001C5CC
    // 0x800EA358: div.s       $f12, $f22, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = DIV_S(ctx->f22.fl, ctx->f20.fl);
    func_8001C5CC(rdram, ctx);
        goto after_40;
    // 0x800EA358: div.s       $f12, $f22, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = DIV_S(ctx->f22.fl, ctx->f20.fl);
    after_40:
    // 0x800EA35C: addiu       $a0, $sp, 0x140
    ctx->r4 = ADD32(ctx->r29, 0X140);
    // 0x800EA360: addiu       $a1, $sp, 0x150
    ctx->r5 = ADD32(ctx->r29, 0X150);
    // 0x800EA364: addiu       $a2, $sp, 0x160
    ctx->r6 = ADD32(ctx->r29, 0X160);
    // 0x800EA368: mul.s       $f20, $f0, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x800EA36C: addiu       $t2, $s6, -0x4E94
    ctx->r10 = ADD32(ctx->r22, -0X4E94);
    // 0x800EA370: lw          $v1, 0x0($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X0);
    // 0x800EA374: lw          $t0, 0x4($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X4);
    // 0x800EA378: lw          $t1, 0x8($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X8);
    // 0x800EA37C: sw          $v1, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r3;
    // 0x800EA380: sw          $t0, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r8;
    // 0x800EA384: sw          $t1, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r9;
    // 0x800EA388: sw          $zero, 0x154($sp)
    MEM_W(0X154, ctx->r29) = 0;
    // 0x800EA38C: lw          $v1, 0x120($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X120);
    // 0x800EA390: lw          $t0, 0x124($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X124);
    // 0x800EA394: lw          $t1, 0x128($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X128);
    // 0x800EA398: sw          $v1, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r3;
    // 0x800EA39C: sw          $t0, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r8;
    // 0x800EA3A0: sw          $t1, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->r9;
    // 0x800EA3A4: jal         0x80019548
    // 0x800EA3A8: sw          $zero, 0x164($sp)
    MEM_W(0X164, ctx->r29) = 0;
    func_80019548(rdram, ctx);
        goto after_41;
    // 0x800EA3A8: sw          $zero, 0x164($sp)
    MEM_W(0X164, ctx->r29) = 0;
    after_41:
    // 0x800EA3AC: lwc1        $f0, 0x144($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X144);
    // 0x800EA3B0: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x800EA3B4: c.le.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl <= ctx->f0.fl;
    // 0x800EA3B8: nop

    // 0x800EA3BC: bc1fl       L_800EA3C4
    if (!c1cs) {
        // 0x800EA3C0: neg.s       $f20, $f20
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
            goto L_800EA3C4;
    }
    goto skip_6;
    // 0x800EA3C0: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    skip_6:
L_800EA3C4:
    // 0x800EA3C4: neg.s       $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = -ctx->f20.fl;
    // 0x800EA3C8: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800EA3CC: jal         0x8001CD6C
    // 0x800EA3D0: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    func_8001CD6C(rdram, ctx);
        goto after_42;
    // 0x800EA3D0: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    after_42:
    // 0x800EA3D4: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800EA3D8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800EA3DC: jal         0x800193E8
    // 0x800EA3E0: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_800193E8(rdram, ctx);
        goto after_43;
    // 0x800EA3E0: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_43:
    // 0x800EA3E4: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x800EA3E8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800EA3EC: swc1        $f24, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->f24.u32l;
    // 0x800EA3F0: jal         0x8001CFE8
    // 0x800EA3F4: swc1        $f20, 0x64($s3)
    MEM_W(0X64, ctx->r19) = ctx->f20.u32l;
    func_8001CFE8(rdram, ctx);
        goto after_44;
    // 0x800EA3F4: swc1        $f20, 0x64($s3)
    MEM_W(0X64, ctx->r19) = ctx->f20.u32l;
    after_44:
    // 0x800EA3F8: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x800EA3FC: jal         0x8001CF2C
    // 0x800EA400: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    func_8001CF2C(rdram, ctx);
        goto after_45;
    // 0x800EA400: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_45:
    // 0x800EA404: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800EA408: jal         0x8001CF2C
    // 0x800EA40C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    func_8001CF2C(rdram, ctx);
        goto after_46;
    // 0x800EA40C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_46:
    // 0x800EA410: mul.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x800EA414: jal         0x8001C5CC
    // 0x800EA418: div.s       $f12, $f20, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = DIV_S(ctx->f20.fl, ctx->f22.fl);
    func_8001C5CC(rdram, ctx);
        goto after_47;
    // 0x800EA418: div.s       $f12, $f20, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f12.fl = DIV_S(ctx->f20.fl, ctx->f22.fl);
    after_47:
    // 0x800EA41C: mul.s       $f2, $f0, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x800EA420: lwc1        $f0, 0x124($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X124);
    // 0x800EA424: c.le.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl <= ctx->f24.fl;
    // 0x800EA428: nop

    // 0x800EA42C: bc1fl       L_800EA434
    if (!c1cs) {
        // 0x800EA430: neg.s       $f2, $f2
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
            goto L_800EA434;
    }
    goto skip_7;
    // 0x800EA430: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    skip_7:
L_800EA434:
    // 0x800EA434: swc1        $f2, 0x68($s3)
    MEM_W(0X68, ctx->r19) = ctx->f2.u32l;
L_800EA438:
    // 0x800EA438: lw          $ra, 0x18C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18C);
    // 0x800EA43C: lw          $s6, 0x188($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X188);
    // 0x800EA440: lw          $s5, 0x184($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X184);
    // 0x800EA444: lw          $s4, 0x180($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X180);
    // 0x800EA448: lw          $s3, 0x17C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X17C);
    // 0x800EA44C: lw          $s2, 0x178($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X178);
    // 0x800EA450: lw          $s1, 0x174($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X174);
    // 0x800EA454: lw          $s0, 0x170($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X170);
    // 0x800EA458: ldc1        $f26, 0x1A8($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X1A8);
    // 0x800EA45C: ldc1        $f24, 0x1A0($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X1A0);
    // 0x800EA460: ldc1        $f22, 0x198($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X198);
    // 0x800EA464: ldc1        $f20, 0x190($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X190);
    // 0x800EA468: jr          $ra
    // 0x800EA46C: addiu       $sp, $sp, 0x1B0
    ctx->r29 = ADD32(ctx->r29, 0X1B0);
    return;
    // 0x800EA46C: addiu       $sp, $sp, 0x1B0
    ctx->r29 = ADD32(ctx->r29, 0X1B0);
;}
RECOMP_FUNC void func_800EA470(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA470: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EA474: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800EA478: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800EA47C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EA480: lw          $a0, 0x98($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X98);
    // 0x800EA484: jal         0x80082EA0
    // 0x800EA488: nop

    func_80082EA0(rdram, ctx);
        goto after_0;
    // 0x800EA488: nop

    after_0:
    // 0x800EA48C: lw          $a0, 0x94($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X94);
    // 0x800EA490: jal         0x80082CFC
    // 0x800EA494: nop

    func_80082CFC(rdram, ctx);
        goto after_1;
    // 0x800EA494: nop

    after_1:
    // 0x800EA498: lbu         $v1, 0xB3($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0XB3);
    // 0x800EA49C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800EA4A0: beq         $v1, $a0, L_800EA4FC
    if (ctx->r3 == ctx->r4) {
        // 0x800EA4A4: slti        $v0, $v1, 0x3
        ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
            goto L_800EA4FC;
    }
    // 0x800EA4A4: slti        $v0, $v1, 0x3
    ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800EA4A8: beq         $v0, $zero, L_800EA4C0
    if (ctx->r2 == 0) {
        // 0x800EA4AC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800EA4C0;
    }
    // 0x800EA4AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EA4B0: beq         $v1, $v0, L_800EA4D4
    if (ctx->r3 == ctx->r2) {
        // 0x800EA4B4: nop
    
            goto L_800EA4D4;
    }
    // 0x800EA4B4: nop

    // 0x800EA4B8: j           L_800EA5D0
    // 0x800EA4BC: nop

        goto L_800EA5D0;
    // 0x800EA4BC: nop

L_800EA4C0:
    // 0x800EA4C0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800EA4C4: beq         $v1, $v0, L_800EA52C
    if (ctx->r3 == ctx->r2) {
        // 0x800EA4C8: nop
    
            goto L_800EA52C;
    }
    // 0x800EA4C8: nop

    // 0x800EA4CC: j           L_800EA5D0
    // 0x800EA4D0: nop

        goto L_800EA5D0;
    // 0x800EA4D0: nop

L_800EA4D4:
    // 0x800EA4D4: lwc1        $f4, 0xA0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XA0);
    // 0x800EA4D8: lwc1        $f0, 0xA4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XA4);
    // 0x800EA4DC: lwc1        $f6, 0x54($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800EA4E0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EA4E4: lwc1        $f2, -0x78D4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X78D4);
    // 0x800EA4E8: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800EA4EC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EA4F0: lwc1        $f0, -0x78D0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X78D0);
    // 0x800EA4F4: j           L_800EA550
    // 0x800EA4F8: sh          $a0, 0x84($s0)
    MEM_H(0X84, ctx->r16) = ctx->r4;
        goto L_800EA550;
    // 0x800EA4F8: sh          $a0, 0x84($s0)
    MEM_H(0X84, ctx->r16) = ctx->r4;
L_800EA4FC:
    // 0x800EA4FC: lwc1        $f4, 0xA0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XA0);
    // 0x800EA500: lwc1        $f0, 0xA4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XA4);
    // 0x800EA504: lwc1        $f6, 0x54($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800EA508: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EA50C: lwc1        $f2, -0x78CC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X78CC);
    // 0x800EA510: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800EA514: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EA518: lwc1        $f0, -0x78C8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X78C8);
    // 0x800EA51C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EA520: sw          $zero, 0x9C($s0)
    MEM_W(0X9C, ctx->r16) = 0;
    // 0x800EA524: j           L_800EA550
    // 0x800EA528: sh          $v0, 0x84($s0)
    MEM_H(0X84, ctx->r16) = ctx->r2;
        goto L_800EA550;
    // 0x800EA528: sh          $v0, 0x84($s0)
    MEM_H(0X84, ctx->r16) = ctx->r2;
L_800EA52C:
    // 0x800EA52C: lwc1        $f4, 0xA0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XA0);
    // 0x800EA530: lwc1        $f0, 0xA4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XA4);
    // 0x800EA534: lwc1        $f6, 0x54($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800EA538: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EA53C: lwc1        $f2, -0x78C4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X78C4);
    // 0x800EA540: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800EA544: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EA548: lwc1        $f0, -0x78C0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X78C0);
    // 0x800EA54C: sh          $zero, 0x84($s0)
    MEM_H(0X84, ctx->r16) = 0;
L_800EA550:
    // 0x800EA550: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800EA554: swc1        $f0, 0xA4($s0)
    MEM_W(0XA4, ctx->r16) = ctx->f0.u32l;
    // 0x800EA558: div.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800EA55C: swc1        $f2, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->f2.u32l;
    // 0x800EA560: lwc1        $f2, 0xA0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0XA0);
    // 0x800EA564: lwc1        $f0, 0xA4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XA4);
    // 0x800EA568: lh          $v0, 0x84($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X84);
    // 0x800EA56C: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800EA570: lw          $v1, 0x30($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X30);
    // 0x800EA574: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800EA578: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EA57C: lwc1        $f0, -0x78BC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X78BC);
    // 0x800EA580: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x800EA584: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800EA588: swc1        $f0, 0xA0($s0)
    MEM_W(0XA0, ctx->r16) = ctx->f0.u32l;
    // 0x800EA58C: lw          $a0, 0x18($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X18);
    // 0x800EA590: lw          $a1, 0x88($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X88);
    // 0x800EA594: jal         0x80082B00
    // 0x800EA598: nop

    func_80082B00(rdram, ctx);
        goto after_2;
    // 0x800EA598: nop

    after_2:
    // 0x800EA59C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800EA5A0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800EA5A4: jal         0x80082E18
    // 0x800EA5A8: sw          $a0, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->r4;
    func_80082E18(rdram, ctx);
        goto after_3;
    // 0x800EA5A8: sw          $a0, 0x94($s0)
    MEM_W(0X94, ctx->r16) = ctx->r4;
    after_3:
    // 0x800EA5AC: lw          $a0, 0x94($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X94);
    // 0x800EA5B0: lw          $a1, 0xA0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XA0);
    // 0x800EA5B4: jal         0x80083258
    // 0x800EA5B8: sw          $v0, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->r2;
    func_80083258(rdram, ctx);
        goto after_4;
    // 0x800EA5B8: sw          $v0, 0x98($s0)
    MEM_W(0X98, ctx->r16) = ctx->r2;
    after_4:
    // 0x800EA5BC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800EA5C0: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x800EA5C4: jal         0x800E9BF4
    // 0x800EA5C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_800E9BF4(rdram, ctx);
        goto after_5;
    // 0x800EA5C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x800EA5CC: sb          $zero, 0xB3($s0)
    MEM_B(0XB3, ctx->r16) = 0;
L_800EA5D0:
    // 0x800EA5D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EA5D4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800EA5D8: jr          $ra
    // 0x800EA5DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800EA5DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void npcAtPtUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA5E0: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x800EA5E4: sw          $s4, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r20;
    // 0x800EA5E8: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x800EA5EC: sw          $s0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r16;
    // 0x800EA5F0: sw          $s6, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r22;
    // 0x800EA5F4: addu        $s6, $a1, $zero
    ctx->r22 = ADD32(ctx->r5, 0);
    // 0x800EA5F8: andi        $v0, $s6, 0xFFFF
    ctx->r2 = ctx->r22 & 0XFFFF;
    // 0x800EA5FC: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x800EA600: sltiu       $v0, $v1, 0x9
    ctx->r2 = ctx->r3 < 0X9 ? 1 : 0;
    // 0x800EA604: sw          $ra, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r31;
    // 0x800EA608: sw          $s7, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r23;
    // 0x800EA60C: sw          $s5, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r21;
    // 0x800EA610: sw          $s3, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r19;
    // 0x800EA614: sw          $s2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r18;
    // 0x800EA618: sw          $s1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r17;
    // 0x800EA61C: sdc1        $f24, 0xC0($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0XC0, ctx->r29);
    // 0x800EA620: sdc1        $f22, 0xB8($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0XB8, ctx->r29);
    // 0x800EA624: sdc1        $f20, 0xB0($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XB0, ctx->r29);
    // 0x800EA628: lw          $s1, 0x4($s4)
    ctx->r17 = MEM_W(ctx->r20, 0X4);
    // 0x800EA62C: beq         $v0, $zero, L_800EB948
    if (ctx->r2 == 0) {
        // 0x800EA630: addu        $s0, $a2, $zero
        ctx->r16 = ADD32(ctx->r6, 0);
            goto L_800EB948;
    }
    // 0x800EA630: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x800EA634: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800EA638: addiu       $v0, $v0, -0x7848
    ctx->r2 = ADD32(ctx->r2, -0X7848);
    // 0x800EA63C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800EA640: addu        $v1, $v1, $v0
    gpr jr_addend_800EA648 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800EA644: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x800EA648: jr          $v0
    // 0x800EA64C: nop

    switch (jr_addend_800EA648 >> 2) {
        case 0: goto L_800EA650; break;
        case 1: goto L_800EAABC; break;
        case 2: goto L_800EAB34; break;
        case 3: goto L_800EB2D4; break;
        case 4: goto L_800EB5D4; break;
        case 5: goto L_800EB948; break;
        case 6: goto L_800EB93C; break;
        case 7: goto L_800EA650; break;
        case 8: goto L_800EB7A8; break;
        default: switch_error(__func__, 0x800EA648, 0x800A87B8);
    }
    // 0x800EA64C: nop

L_800EA650:
    // 0x800EA650: addu        $s2, $s0, $zero
    ctx->r18 = ADD32(ctx->r16, 0);
    // 0x800EA654: lhu         $v0, 0x14($s4)
    ctx->r2 = MEM_HU(ctx->r20, 0X14);
    // 0x800EA658: andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // 0x800EA65C: bne         $v0, $zero, L_800EA68C
    if (ctx->r2 != 0) {
        // 0x800EA660: addu        $s7, $s0, $zero
        ctx->r23 = ADD32(ctx->r16, 0);
            goto L_800EA68C;
    }
    // 0x800EA660: addu        $s7, $s0, $zero
    ctx->r23 = ADD32(ctx->r16, 0);
    // 0x800EA664: sw          $s0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r16;
    // 0x800EA668: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800EA66C: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
    // 0x800EA670: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800EA674: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
    // 0x800EA678: lwc1        $f0, 0x18($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800EA67C: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
    // 0x800EA680: lw          $v0, 0x8C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8C);
    // 0x800EA684: j           L_800EA6E0
    // 0x800EA688: addu        $s5, $v0, $s0
    ctx->r21 = ADD32(ctx->r2, ctx->r16);
        goto L_800EA6E0;
    // 0x800EA688: addu        $s5, $v0, $s0
    ctx->r21 = ADD32(ctx->r2, ctx->r16);
L_800EA68C:
    // 0x800EA68C: lw          $s2, 0xC($s0)
    ctx->r18 = MEM_W(ctx->r16, 0XC);
    // 0x800EA690: sw          $s2, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r18;
    // 0x800EA694: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800EA698: lbu         $v1, 0x2($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X2);
    // 0x800EA69C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800EA6A0: bne         $v1, $v0, L_800EA6D0
    if (ctx->r3 != ctx->r2) {
        // 0x800EA6A4: lui         $v0, 0x800B
        ctx->r2 = S32(0X800B << 16);
            goto L_800EA6D0;
    }
    // 0x800EA6A4: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800EA6A8: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x800EA6AC: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800EA6B0: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x800EA6B4: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x800EA6B8: sw          $t0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r8;
    // 0x800EA6BC: sw          $t1, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r9;
    // 0x800EA6C0: sw          $t2, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r10;
    // 0x800EA6C4: lw          $s5, 0x0($s0)
    ctx->r21 = MEM_W(ctx->r16, 0X0);
    // 0x800EA6C8: j           L_800EA6E4
    // 0x800EA6CC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
        goto L_800EA6E4;
    // 0x800EA6CC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
L_800EA6D0:
    // 0x800EA6D0: addiu       $s5, $v0, -0x78B8
    ctx->r21 = ADD32(ctx->r2, -0X78B8);
    // 0x800EA6D4: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x800EA6D8: sw          $zero, 0x4($s1)
    MEM_W(0X4, ctx->r17) = 0;
    // 0x800EA6DC: sw          $zero, 0x8($s1)
    MEM_W(0X8, ctx->r17) = 0;
L_800EA6E0:
    // 0x800EA6E0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
L_800EA6E4:
    // 0x800EA6E4: jal         0x80056EB0
    // 0x800EA6E8: addiu       $a0, $a0, -0x78B4
    ctx->r4 = ADD32(ctx->r4, -0X78B4);
    func_80056EB0(rdram, ctx);
        goto after_0;
    // 0x800EA6E8: addiu       $a0, $a0, -0x78B4
    ctx->r4 = ADD32(ctx->r4, -0X78B4);
    after_0:
    // 0x800EA6EC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800EA6F0: sw          $v0, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r2;
    // 0x800EA6F4: lbu         $v1, 0xB63($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0XB63);
    // 0x800EA6F8: beq         $v1, $zero, L_800EA70C
    if (ctx->r3 == 0) {
        // 0x800EA6FC: addu        $a0, $v0, $zero
        ctx->r4 = ADD32(ctx->r2, 0);
            goto L_800EA70C;
    }
    // 0x800EA6FC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800EA700: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EA704: j           L_800EA714
    // 0x800EA708: addiu       $v0, $v0, -0x4EA0
    ctx->r2 = ADD32(ctx->r2, -0X4EA0);
        goto L_800EA714;
    // 0x800EA708: addiu       $v0, $v0, -0x4EA0
    ctx->r2 = ADD32(ctx->r2, -0X4EA0);
L_800EA70C:
    // 0x800EA70C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EA710: addiu       $v0, $v0, -0x4E98
    ctx->r2 = ADD32(ctx->r2, -0X4E98);
L_800EA714:
    // 0x800EA714: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x800EA718: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    // 0x800EA71C: lw          $a2, 0x20($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X20);
    // 0x800EA720: lw          $a3, 0x24($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X24);
    // 0x800EA724: jal         0x80059D78
    // 0x800EA728: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80059D78(rdram, ctx);
        goto after_1;
    // 0x800EA728: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_1:
    // 0x800EA72C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800EA730: lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X30);
    // 0x800EA734: swc1        $f0, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f0.u32l;
    // 0x800EA738: swc1        $f0, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f0.u32l;
    // 0x800EA73C: swc1        $f0, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f0.u32l;
    // 0x800EA740: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800EA744: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EA748: lwc1        $f2, -0x7824($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7824);
    // 0x800EA74C: lwc1        $f4, 0x34($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X34);
    // 0x800EA750: lwc1        $f0, 0x28($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X28);
    // 0x800EA754: div.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800EA758: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800EA75C: swc1        $f0, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f0.u32l;
    // 0x800EA760: lwc1        $f0, 0x28($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X28);
    // 0x800EA764: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800EA768: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800EA76C: lwc1        $f0, 0x2C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X2C);
    // 0x800EA770: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800EA774: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800EA778: lwc1        $f0, 0x30($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X30);
    // 0x800EA77C: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800EA780: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x800EA784: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800EA788: jal         0x8001CB64
    // 0x800EA78C: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_8001CB64(rdram, ctx);
        goto after_2;
    // 0x800EA78C: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_2:
    // 0x800EA790: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x800EA794: lw          $a1, 0x1C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X1C);
    // 0x800EA798: jal         0x8001CB9C
    // 0x800EA79C: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_8001CB9C(rdram, ctx);
        goto after_3;
    // 0x800EA79C: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_3:
    // 0x800EA7A0: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x800EA7A4: lw          $a1, 0x20($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X20);
    // 0x800EA7A8: jal         0x8001CCCC
    // 0x800EA7AC: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_8001CCCC(rdram, ctx);
        goto after_4;
    // 0x800EA7AC: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_4:
    // 0x800EA7B0: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x800EA7B4: lw          $a1, 0x24($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X24);
    // 0x800EA7B8: jal         0x8001CDFC
    // 0x800EA7BC: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_8001CDFC(rdram, ctx);
        goto after_5;
    // 0x800EA7BC: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_5:
    // 0x800EA7C0: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x800EA7C4: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    // 0x800EA7C8: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x800EA7CC: lw          $a3, 0x8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X8);
    // 0x800EA7D0: jal         0x8001CA90
    // 0x800EA7D4: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_8001CA90(rdram, ctx);
        goto after_6;
    // 0x800EA7D4: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_6:
    // 0x800EA7D8: sw          $s1, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r17;
    // 0x800EA7DC: lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X30);
    // 0x800EA7E0: sw          $v0, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->r2;
    // 0x800EA7E4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800EA7E8: addiu       $s3, $v0, -0x6AA0
    ctx->r19 = ADD32(ctx->r2, -0X6AA0);
    // 0x800EA7EC: lhu         $a0, 0x1C($s3)
    ctx->r4 = MEM_HU(ctx->r19, 0X1C);
    // 0x800EA7F0: jal         0x8003E684
    // 0x800EA7F4: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_8003E684(rdram, ctx);
        goto after_7;
    // 0x800EA7F4: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_7:
    // 0x800EA7F8: sh          $v0, 0x7A($s1)
    MEM_H(0X7A, ctx->r17) = ctx->r2;
    // 0x800EA7FC: lw          $v0, 0xA0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XA0);
    // 0x800EA800: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800EA804: bne         $v0, $s0, L_800EA810
    if (ctx->r2 != ctx->r16) {
        // 0x800EA808: addiu       $v1, $zero, 0x2C
        ctx->r3 = ADD32(0, 0X2C);
            goto L_800EA810;
    }
    // 0x800EA808: addiu       $v1, $zero, 0x2C
    ctx->r3 = ADD32(0, 0X2C);
    // 0x800EA80C: addiu       $v1, $zero, 0x2E
    ctx->r3 = ADD32(0, 0X2E);
L_800EA810:
    // 0x800EA810: addu        $v0, $v1, $s3
    ctx->r2 = ADD32(ctx->r3, ctx->r19);
    // 0x800EA814: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x800EA818: jal         0x8003E684
    // 0x800EA81C: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_8003E684(rdram, ctx);
        goto after_8;
    // 0x800EA81C: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_8:
    // 0x800EA820: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800EA824: addiu       $a1, $a1, -0x78A8
    ctx->r5 = ADD32(ctx->r5, -0X78A8);
    // 0x800EA828: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x800EA82C: addiu       $a2, $s1, 0x44
    ctx->r6 = ADD32(ctx->r17, 0X44);
    // 0x800EA830: jal         0x80059434
    // 0x800EA834: sh          $v0, 0x7C($s1)
    MEM_H(0X7C, ctx->r17) = ctx->r2;
    func_80059434(rdram, ctx);
        goto after_9;
    // 0x800EA834: sh          $v0, 0x7C($s1)
    MEM_H(0X7C, ctx->r17) = ctx->r2;
    after_9:
    // 0x800EA838: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800EA83C: addiu       $a1, $a1, -0x789C
    ctx->r5 = ADD32(ctx->r5, -0X789C);
    // 0x800EA840: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x800EA844: addiu       $a2, $s1, 0x48
    ctx->r6 = ADD32(ctx->r17, 0X48);
    // 0x800EA848: jal         0x80059434
    // 0x800EA84C: sw          $v0, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = ctx->r2;
    func_80059434(rdram, ctx);
        goto after_10;
    // 0x800EA84C: sw          $v0, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = ctx->r2;
    after_10:
    // 0x800EA850: sw          $v0, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->r2;
    // 0x800EA854: lw          $v0, 0xA0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XA0);
    // 0x800EA858: bne         $v0, $s0, L_800EA864
    if (ctx->r2 != ctx->r16) {
        // 0x800EA85C: addiu       $v1, $zero, 0x12
        ctx->r3 = ADD32(0, 0X12);
            goto L_800EA864;
    }
    // 0x800EA85C: addiu       $v1, $zero, 0x12
    ctx->r3 = ADD32(0, 0X12);
    // 0x800EA860: addiu       $v1, $zero, 0xE
    ctx->r3 = ADD32(0, 0XE);
L_800EA864:
    // 0x800EA864: addu        $v0, $v1, $s3
    ctx->r2 = ADD32(ctx->r3, ctx->r19);
    // 0x800EA868: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x800EA86C: jal         0x8003E684
    // 0x800EA870: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_8003E684(rdram, ctx);
        goto after_11;
    // 0x800EA870: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_11:
    // 0x800EA874: sh          $v0, 0x80($s1)
    MEM_H(0X80, ctx->r17) = ctx->r2;
    // 0x800EA878: lw          $v0, 0xA8($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XA8);
    // 0x800EA87C: beq         $v0, $zero, L_800EA8AC
    if (ctx->r2 == 0) {
        // 0x800EA880: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_800EA8AC;
    }
    // 0x800EA880: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800EA884: lw          $v0, 0xA0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0XA0);
    // 0x800EA888: bne         $v0, $s0, L_800EA894
    if (ctx->r2 != ctx->r16) {
        // 0x800EA88C: addiu       $v1, $zero, 0x18
        ctx->r3 = ADD32(0, 0X18);
            goto L_800EA894;
    }
    // 0x800EA88C: addiu       $v1, $zero, 0x18
    ctx->r3 = ADD32(0, 0X18);
    // 0x800EA890: addiu       $v1, $zero, 0x1A
    ctx->r3 = ADD32(0, 0X1A);
L_800EA894:
    // 0x800EA894: addu        $v0, $v1, $s3
    ctx->r2 = ADD32(ctx->r3, ctx->r19);
    // 0x800EA898: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x800EA89C: jal         0x8003E684
    // 0x800EA8A0: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_8003E684(rdram, ctx);
        goto after_12;
    // 0x800EA8A0: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_12:
    // 0x800EA8A4: j           L_800EA8B0
    // 0x800EA8A8: sh          $v0, 0x82($s1)
    MEM_H(0X82, ctx->r17) = ctx->r2;
        goto L_800EA8B0;
    // 0x800EA8A8: sh          $v0, 0x82($s1)
    MEM_H(0X82, ctx->r17) = ctx->r2;
L_800EA8AC:
    // 0x800EA8AC: sh          $v0, 0x82($s1)
    MEM_H(0X82, ctx->r17) = ctx->r2;
L_800EA8B0:
    // 0x800EA8B0: lwc1        $f0, 0x54($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X54);
    // 0x800EA8B4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EA8B8: lwc1        $f12, -0x7820($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7820);
    // 0x800EA8BC: lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X30);
    // 0x800EA8C0: mul.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800EA8C4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800EA8C8: lwc1        $f2, 0x44($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X44);
    // 0x800EA8CC: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800EA8D0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EA8D4: lwc1        $f14, -0x781C($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X781C);
    // 0x800EA8D8: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x800EA8DC: mul.s       $f14, $f0, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x800EA8E0: sw          $zero, 0x64($s1)
    MEM_W(0X64, ctx->r17) = 0;
    // 0x800EA8E4: sw          $zero, 0x68($s1)
    MEM_W(0X68, ctx->r17) = 0;
    // 0x800EA8E8: sw          $zero, 0xB4($s1)
    MEM_W(0XB4, ctx->r17) = 0;
    // 0x800EA8EC: jal         0x8006BD18
    // 0x800EA8F0: swc1        $f2, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f2.u32l;
    func_8006BD18(rdram, ctx);
        goto after_13;
    // 0x800EA8F0: swc1        $f2, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f2.u32l;
    after_13:
    // 0x800EA8F4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EA8F8: lwc1        $f0, -0x7818($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7818);
    // 0x800EA8FC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800EA900: sw          $v0, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->r2;
    // 0x800EA904: swc1        $f0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f0.u32l;
    // 0x800EA908: lwc1        $f0, 0x54($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X54);
    // 0x800EA90C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800EA910: lw          $v0, 0x4C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4C);
    // 0x800EA914: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x800EA918: lw          $v0, 0x4C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4C);
    // 0x800EA91C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EA920: lwc1        $f0, -0x7814($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7814);
    // 0x800EA924: swc1        $f2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f2.u32l;
    // 0x800EA928: lw          $v0, 0x4C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4C);
    // 0x800EA92C: andi        $v1, $s6, 0xFFFF
    ctx->r3 = ctx->r22 & 0XFFFF;
    // 0x800EA930: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x800EA934: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800EA938: addiu       $a3, $v0, -0x6520
    ctx->r7 = ADD32(ctx->r2, -0X6520);
    // 0x800EA93C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EA940: beq         $v1, $v0, L_800EA950
    if (ctx->r3 == ctx->r2) {
        // 0x800EA944: addiu       $a0, $s1, 0x38
        ctx->r4 = ADD32(ctx->r17, 0X38);
            goto L_800EA950;
    }
    // 0x800EA944: addiu       $a0, $s1, 0x38
    ctx->r4 = ADD32(ctx->r17, 0X38);
    // 0x800EA948: j           L_800EA954
    // 0x800EA94C: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
        goto L_800EA954;
    // 0x800EA94C: sw          $s7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r23;
L_800EA950:
    // 0x800EA950: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
L_800EA954:
    // 0x800EA954: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800EA958: jal         0x800EC588
    // 0x800EA95C: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    func_800EC588(rdram, ctx);
        goto after_14;
    // 0x800EA95C: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    after_14:
    // 0x800EA960: lbu         $v1, 0x0($s5)
    ctx->r3 = MEM_BU(ctx->r21, 0X0);
    // 0x800EA964: addiu       $v0, $zero, 0x2D
    ctx->r2 = ADD32(0, 0X2D);
    // 0x800EA968: beq         $v1, $v0, L_800EA9BC
    if (ctx->r3 == ctx->r2) {
        // 0x800EA96C: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800EA9BC;
    }
    // 0x800EA96C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EA970: jal         0x80047B48
    // 0x800EA974: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    getLevelDatItemByName(rdram, ctx);
        goto after_15;
    // 0x800EA974: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    after_15:
    // 0x800EA978: lw          $a1, 0x34($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X34);
    // 0x800EA97C: lwc1        $f0, 0x94($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X94);
    // 0x800EA980: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800EA984: lw          $v1, 0x34($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X34);
    // 0x800EA988: lwc1        $f0, 0x98($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X98);
    // 0x800EA98C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800EA990: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800EA994: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800EA998: lw          $a2, 0x90($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X90);
    // 0x800EA99C: lw          $a3, 0x9C($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X9C);
    // 0x800EA9A0: jal         0x800F947C
    // 0x800EA9A4: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    func_800F947C(rdram, ctx);
        goto after_16;
    // 0x800EA9A4: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_16:
    // 0x800EA9A8: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    // 0x800EA9AC: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800EA9B0: jal         0x800F9AF4
    // 0x800EA9B4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_800F9AF4(rdram, ctx);
        goto after_17;
    // 0x800EA9B4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_17:
    // 0x800EA9B8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_800EA9BC:
    // 0x800EA9BC: lwc1        $f2, 0x54($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X54);
    // 0x800EA9C0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EA9C4: lwc1        $f0, -0x7810($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7810);
    // 0x800EA9C8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800EA9CC: sh          $zero, 0x84($s1)
    MEM_H(0X84, ctx->r17) = 0;
    // 0x800EA9D0: sw          $zero, 0x70($s1)
    MEM_W(0X70, ctx->r17) = 0;
    // 0x800EA9D4: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800EA9D8: swc1        $f0, 0xA4($s1)
    MEM_W(0XA4, ctx->r17) = ctx->f0.u32l;
    // 0x800EA9DC: lwc1        $f0, -0x4E7C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X4E7C);
    // 0x800EA9E0: addiu       $a0, $a0, -0x7890
    ctx->r4 = ADD32(ctx->r4, -0X7890);
    // 0x800EA9E4: sh          $zero, 0x78($s1)
    MEM_H(0X78, ctx->r17) = 0;
    // 0x800EA9E8: sb          $zero, 0xB3($s1)
    MEM_B(0XB3, ctx->r17) = 0;
    // 0x800EA9EC: jal         0x800F9E40
    // 0x800EA9F0: swc1        $f0, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->f0.u32l;
    load_model_animation(rdram, ctx);
        goto after_18;
    // 0x800EA9F0: swc1        $f0, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->f0.u32l;
    after_18:
    // 0x800EA9F4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800EA9F8: addiu       $a0, $a0, -0x787C
    ctx->r4 = ADD32(ctx->r4, -0X787C);
    // 0x800EA9FC: jal         0x800F9E40
    // 0x800EAA00: sw          $v0, 0x88($s1)
    MEM_W(0X88, ctx->r17) = ctx->r2;
    load_model_animation(rdram, ctx);
        goto after_19;
    // 0x800EAA00: sw          $v0, 0x88($s1)
    MEM_W(0X88, ctx->r17) = ctx->r2;
    after_19:
    // 0x800EAA04: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800EAA08: addiu       $a0, $a0, -0x7864
    ctx->r4 = ADD32(ctx->r4, -0X7864);
    // 0x800EAA0C: jal         0x800F9E40
    // 0x800EAA10: sw          $v0, 0x8C($s1)
    MEM_W(0X8C, ctx->r17) = ctx->r2;
    load_model_animation(rdram, ctx);
        goto after_20;
    // 0x800EAA10: sw          $v0, 0x8C($s1)
    MEM_W(0X8C, ctx->r17) = ctx->r2;
    after_20:
    // 0x800EAA14: sw          $v0, 0x90($s1)
    MEM_W(0X90, ctx->r17) = ctx->r2;
    // 0x800EAA18: lh          $v0, 0x84($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X84);
    // 0x800EAA1C: lw          $v1, 0x30($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X30);
    // 0x800EAA20: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800EAA24: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x800EAA28: lw          $a0, 0x18($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X18);
    // 0x800EAA2C: lw          $a1, 0x88($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X88);
    // 0x800EAA30: jal         0x80082B00
    // 0x800EAA34: nop

    func_80082B00(rdram, ctx);
        goto after_21;
    // 0x800EAA34: nop

    after_21:
    // 0x800EAA38: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800EAA3C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800EAA40: jal         0x80082E18
    // 0x800EAA44: sw          $a0, 0x94($s1)
    MEM_W(0X94, ctx->r17) = ctx->r4;
    func_80082E18(rdram, ctx);
        goto after_22;
    // 0x800EAA44: sw          $a0, 0x94($s1)
    MEM_W(0X94, ctx->r17) = ctx->r4;
    after_22:
    // 0x800EAA48: jal         0x80003430
    // 0x800EAA4C: sw          $v0, 0x98($s1)
    MEM_W(0X98, ctx->r17) = ctx->r2;
    rand_recomp(rdram, ctx);
        goto after_23;
    // 0x800EAA4C: sw          $v0, 0x98($s1)
    MEM_W(0X98, ctx->r17) = ctx->r2;
    after_23:
    // 0x800EAA50: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800EAA54: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EAA58: lwc1        $f2, -0x780C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X780C);
    // 0x800EAA5C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800EAA60: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800EAA64: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800EAA68: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EAA6C: lwc1        $f2, -0x7808($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7808);
    // 0x800EAA70: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800EAA74: abs.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = fabsf(ctx->f0.fl);
    // 0x800EAA78: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x800EAA7C: lwc1        $f0, 0xA4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XA4);
    // 0x800EAA80: swc1        $f10, 0x9C($s1)
    MEM_W(0X9C, ctx->r17) = ctx->f10.u32l;
    // 0x800EAA84: lwc1        $f2, 0x90($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X90);
    // 0x800EAA88: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800EAA8C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EAA90: lwc1        $f0, -0x7804($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7804);
    // 0x800EAA94: lw          $a0, 0x94($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X94);
    // 0x800EAA98: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800EAA9C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800EAAA0: jal         0x80083258
    // 0x800EAAA4: sw          $a1, 0xA0($s1)
    MEM_W(0XA0, ctx->r17) = ctx->r5;
    func_80083258(rdram, ctx);
        goto after_24;
    // 0x800EAAA4: sw          $a1, 0xA0($s1)
    MEM_W(0XA0, ctx->r17) = ctx->r5;
    after_24:
    // 0x800EAAA8: lw          $a0, 0x94($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X94);
    // 0x800EAAAC: jal         0x80083008
    // 0x800EAAB0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    func_80083008(rdram, ctx);
        goto after_25;
    // 0x800EAAB0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_25:
    // 0x800EAAB4: j           L_800EB94C
    // 0x800EAAB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800EB94C;
    // 0x800EAAB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EAABC:
    // 0x800EAABC: lw          $v0, 0x88($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X88);
    // 0x800EAAC0: beq         $v0, $zero, L_800EAAE0
    if (ctx->r2 == 0) {
        // 0x800EAAC4: nop
    
            goto L_800EAAE0;
    }
    // 0x800EAAC4: nop

    // 0x800EAAC8: lw          $a0, 0x98($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X98);
    // 0x800EAACC: jal         0x80082EA0
    // 0x800EAAD0: sw          $zero, 0x88($s1)
    MEM_W(0X88, ctx->r17) = 0;
    func_80082EA0(rdram, ctx);
        goto after_26;
    // 0x800EAAD0: sw          $zero, 0x88($s1)
    MEM_W(0X88, ctx->r17) = 0;
    after_26:
    // 0x800EAAD4: lw          $a0, 0x94($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X94);
    // 0x800EAAD8: jal         0x80082CFC
    // 0x800EAADC: nop

    func_80082CFC(rdram, ctx);
        goto after_27;
    // 0x800EAADC: nop

    after_27:
L_800EAAE0:
    // 0x800EAAE0: lw          $a0, 0x4C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4C);
    // 0x800EAAE4: jal         0x80001C98
    // 0x800EAAE8: nop

    rs_free(rdram, ctx);
        goto after_28;
    // 0x800EAAE8: nop

    after_28:
    // 0x800EAAEC: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800EAAF0: jal         0x800F20EC
    // 0x800EAAF4: nop

    getNpcCurrentHealth(rdram, ctx);
        goto after_29;
    // 0x800EAAF4: nop

    after_29:
    // 0x800EAAF8: lw          $v1, 0x34($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X34);
    // 0x800EAAFC: slti        $a1, $v0, 0x1
    ctx->r5 = SIGNED(ctx->r2) < 0X1 ? 1 : 0;
    // 0x800EAB00: addiu       $v1, $v1, 0x70
    ctx->r3 = ADD32(ctx->r3, 0X70);
    // 0x800EAB04: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x800EAB08: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800EAB0C: lw          $a2, 0x34($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X34);
    // 0x800EAB10: jal         0x800F1E7C
    // 0x800EAB14: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_800F1E7C(rdram, ctx);
        goto after_30;
    // 0x800EAB14: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_30:
    // 0x800EAB18: jal         0x800EC684
    // 0x800EAB1C: addiu       $a0, $s1, 0x38
    ctx->r4 = ADD32(ctx->r17, 0X38);
    func_800EC684(rdram, ctx);
        goto after_31;
    // 0x800EAB1C: addiu       $a0, $s1, 0x38
    ctx->r4 = ADD32(ctx->r17, 0X38);
    after_31:
    // 0x800EAB20: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x800EAB24: jal         0x8005779C
    // 0x800EAB28: nop

    func_8005779C(rdram, ctx);
        goto after_32;
    // 0x800EAB28: nop

    after_32:
    // 0x800EAB2C: j           L_800EB94C
    // 0x800EAB30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800EB94C;
    // 0x800EAB30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EAB34:
    // 0x800EAB34: lwc1        $f20, 0x0($s0)
    ctx->f20.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800EAB38: lwc1        $f2, 0x5C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X5C);
    // 0x800EAB3C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EAB40: lwc1        $f4, -0x7800($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7800);
    // 0x800EAB44: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EAB48: lwc1        $f0, -0x77FC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X77FC);
    // 0x800EAB4C: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x800EAB50: mul.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800EAB54: bc1f        L_800EABBC
    if (!c1cs) {
        // 0x800EAB58: nop
    
            goto L_800EABBC;
    }
    // 0x800EAB58: nop

    // 0x800EAB5C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800EAB60: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x800EAB64: nop

    // 0x800EAB68: bc1f        L_800EAB7C
    if (!c1cs) {
        // 0x800EAB6C: swc1        $f2, 0x5C($s1)
        MEM_W(0X5C, ctx->r17) = ctx->f2.u32l;
            goto L_800EAB7C;
    }
    // 0x800EAB6C: swc1        $f2, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->f2.u32l;
    // 0x800EAB70: swc1        $f4, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->f4.u32l;
    // 0x800EAB74: j           L_800EABBC
    // 0x800EAB78: sw          $zero, 0x60($s1)
    MEM_W(0X60, ctx->r17) = 0;
        goto L_800EABBC;
    // 0x800EAB78: sw          $zero, 0x60($s1)
    MEM_W(0X60, ctx->r17) = 0;
L_800EAB7C:
    // 0x800EAB7C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EAB80: lwc1        $f0, -0x77F8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X77F8);
    // 0x800EAB84: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800EAB88: nop

    // 0x800EAB8C: bc1fl       L_800EABA8
    if (!c1cs) {
        // 0x800EAB90: sub.s       $f0, $f2, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_800EABA8;
    }
    goto skip_0;
    // 0x800EAB90: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    skip_0:
    // 0x800EAB94: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EAB98: lwc1        $f0, -0x77F4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X77F4);
    // 0x800EAB9C: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800EABA0: j           L_800EABBC
    // 0x800EABA4: swc1        $f0, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->f0.u32l;
        goto L_800EABBC;
    // 0x800EABA4: swc1        $f0, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->f0.u32l;
L_800EABA8:
    // 0x800EABA8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EABAC: lwc1        $f2, -0x77F0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X77F0);
    // 0x800EABB0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800EABB4: sub.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800EABB8: swc1        $f0, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->f0.u32l;
L_800EABBC:
    // 0x800EABBC: lh          $v1, 0x6C($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X6C);
    // 0x800EABC0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800EABC4: beq         $v1, $a0, L_800EABF4
    if (ctx->r3 == ctx->r4) {
        // 0x800EABC8: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_800EABF4;
    }
    // 0x800EABC8: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800EABCC: beq         $v0, $zero, L_800EABE4
    if (ctx->r2 == 0) {
        // 0x800EABD0: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800EABE4;
    }
    // 0x800EABD0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800EABD4: beql        $v1, $zero, L_800EABF4
    if (ctx->r3 == 0) {
        // 0x800EABD8: sh          $a0, 0x6C($s1)
        MEM_H(0X6C, ctx->r17) = ctx->r4;
            goto L_800EABF4;
    }
    goto skip_1;
    // 0x800EABD8: sh          $a0, 0x6C($s1)
    MEM_H(0X6C, ctx->r17) = ctx->r4;
    skip_1:
    // 0x800EABDC: j           L_800EB280
    // 0x800EABE0: nop

        goto L_800EB280;
    // 0x800EABE0: nop

L_800EABE4:
    // 0x800EABE4: beq         $v1, $v0, L_800EAF24
    if (ctx->r3 == ctx->r2) {
        // 0x800EABE8: addiu       $s0, $sp, 0x48
        ctx->r16 = ADD32(ctx->r29, 0X48);
            goto L_800EAF24;
    }
    // 0x800EABE8: addiu       $s0, $sp, 0x48
    ctx->r16 = ADD32(ctx->r29, 0X48);
    // 0x800EABEC: j           L_800EB280
    // 0x800EABF0: nop

        goto L_800EB280;
    // 0x800EABF0: nop

L_800EABF4:
    // 0x800EABF4: lh          $v1, 0x84($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X84);
    // 0x800EABF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EABFC: beq         $v1, $v0, L_800EAC94
    if (ctx->r3 == ctx->r2) {
        // 0x800EAC00: slti        $v0, $v1, 0x2
        ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_800EAC94;
    }
    // 0x800EAC00: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800EAC04: beq         $v0, $zero, L_800EAC1C
    if (ctx->r2 == 0) {
        // 0x800EAC08: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800EAC1C;
    }
    // 0x800EAC08: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800EAC0C: beq         $v1, $zero, L_800EAC2C
    if (ctx->r3 == 0) {
        // 0x800EAC10: addu        $a0, $s1, $zero
        ctx->r4 = ADD32(ctx->r17, 0);
            goto L_800EAC2C;
    }
    // 0x800EAC10: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800EAC14: j           L_800EADCC
    // 0x800EAC18: nop

        goto L_800EADCC;
    // 0x800EAC18: nop

L_800EAC1C:
    // 0x800EAC1C: beq         $v1, $v0, L_800EAD00
    if (ctx->r3 == ctx->r2) {
        // 0x800EAC20: nop
    
            goto L_800EAD00;
    }
    // 0x800EAC20: nop

    // 0x800EAC24: j           L_800EADCC
    // 0x800EAC28: nop

        goto L_800EADCC;
    // 0x800EAC28: nop

L_800EAC2C:
    // 0x800EAC2C: lw          $a2, 0x34($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X34);
    // 0x800EAC30: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800EAC34: jal         0x800AA6D0
    // 0x800EAC38: addiu       $a2, $a2, 0x34
    ctx->r6 = ADD32(ctx->r6, 0X34);
    func_800AA6D0(rdram, ctx);
        goto after_33;
    // 0x800EAC38: addiu       $a2, $a2, 0x34
    ctx->r6 = ADD32(ctx->r6, 0X34);
    after_33:
    // 0x800EAC3C: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800EAC40: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800EAC44: jal         0x800F9A14
    // 0x800EAC48: nop

    func_800F9A14(rdram, ctx);
        goto after_34;
    // 0x800EAC48: nop

    after_34:
    // 0x800EAC4C: lwc1        $f0, 0xA0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XA0);
    // 0x800EAC50: lwc1        $f2, 0x9C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x800EAC54: div.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800EAC58: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800EAC5C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EAC60: lwc1        $f2, -0x77EC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X77EC);
    // 0x800EAC64: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800EAC68: nop

    // 0x800EAC6C: bc1f        L_800EAD90
    if (!c1cs) {
        // 0x800EAC70: swc1        $f0, 0x9C($s1)
        MEM_W(0X9C, ctx->r17) = ctx->f0.u32l;
            goto L_800EAD90;
    }
    // 0x800EAC70: swc1        $f0, 0x9C($s1)
    MEM_W(0X9C, ctx->r17) = ctx->f0.u32l;
    // 0x800EAC74: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800EAC78: lbu         $v0, 0xB3($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XB3);
    // 0x800EAC7C: beq         $v0, $zero, L_800EAD90
    if (ctx->r2 == 0) {
        // 0x800EAC80: swc1        $f0, 0x9C($s1)
        MEM_W(0X9C, ctx->r17) = ctx->f0.u32l;
            goto L_800EAD90;
    }
    // 0x800EAC80: swc1        $f0, 0x9C($s1)
    MEM_W(0X9C, ctx->r17) = ctx->f0.u32l;
    // 0x800EAC84: jal         0x800EA470
    // 0x800EAC88: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_800EA470(rdram, ctx);
        goto after_35;
    // 0x800EAC88: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_35:
    // 0x800EAC8C: j           L_800EAD94
    // 0x800EAC90: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
        goto L_800EAD94;
    // 0x800EAC90: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_800EAC94:
    // 0x800EAC94: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800EAC98: lw          $a2, 0x34($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X34);
    // 0x800EAC9C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800EACA0: jal         0x800AA6D0
    // 0x800EACA4: addiu       $a2, $a2, 0x34
    ctx->r6 = ADD32(ctx->r6, 0X34);
    func_800AA6D0(rdram, ctx);
        goto after_36;
    // 0x800EACA4: addiu       $a2, $a2, 0x34
    ctx->r6 = ADD32(ctx->r6, 0X34);
    after_36:
    // 0x800EACA8: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800EACAC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800EACB0: jal         0x800F9A14
    // 0x800EACB4: nop

    func_800F9A14(rdram, ctx);
        goto after_37;
    // 0x800EACB4: nop

    after_37:
    // 0x800EACB8: lwc1        $f0, 0xA0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XA0);
    // 0x800EACBC: lwc1        $f2, 0x9C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x800EACC0: div.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800EACC4: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800EACC8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EACCC: lwc1        $f2, -0x77E8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X77E8);
    // 0x800EACD0: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800EACD4: nop

    // 0x800EACD8: bc1f        L_800EAD90
    if (!c1cs) {
        // 0x800EACDC: swc1        $f0, 0x9C($s1)
        MEM_W(0X9C, ctx->r17) = ctx->f0.u32l;
            goto L_800EAD90;
    }
    // 0x800EACDC: swc1        $f0, 0x9C($s1)
    MEM_W(0X9C, ctx->r17) = ctx->f0.u32l;
    // 0x800EACE0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800EACE4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800EACE8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800EACEC: sb          $v0, 0xB3($s1)
    MEM_B(0XB3, ctx->r17) = ctx->r2;
    // 0x800EACF0: jal         0x800EA470
    // 0x800EACF4: swc1        $f0, 0x9C($s1)
    MEM_W(0X9C, ctx->r17) = ctx->f0.u32l;
    func_800EA470(rdram, ctx);
        goto after_38;
    // 0x800EACF4: swc1        $f0, 0x9C($s1)
    MEM_W(0X9C, ctx->r17) = ctx->f0.u32l;
    after_38:
    // 0x800EACF8: j           L_800EAD94
    // 0x800EACFC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
        goto L_800EAD94;
    // 0x800EACFC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_800EAD00:
    // 0x800EAD00: lwc1        $f2, 0x9C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x800EAD04: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EAD08: lwc1        $f4, -0x77E4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X77E4);
    // 0x800EAD0C: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x800EAD10: nop

    // 0x800EAD14: bc1f        L_800EADA8
    if (!c1cs) {
        // 0x800EAD18: nop
    
            goto L_800EADA8;
    }
    // 0x800EAD18: nop

    // 0x800EAD1C: lwc1        $f0, 0xA0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XA0);
    // 0x800EAD20: div.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800EAD24: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800EAD28: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x800EAD2C: nop

    // 0x800EAD30: bc1f        L_800EAD6C
    if (!c1cs) {
        // 0x800EAD34: swc1        $f0, 0x9C($s1)
        MEM_W(0X9C, ctx->r17) = ctx->f0.u32l;
            goto L_800EAD6C;
    }
    // 0x800EAD34: swc1        $f0, 0x9C($s1)
    MEM_W(0X9C, ctx->r17) = ctx->f0.u32l;
    // 0x800EAD38: lbu         $a2, 0xB1($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0XB1);
    // 0x800EAD3C: lbu         $a3, 0xB2($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0XB2);
    // 0x800EAD40: lbu         $v0, 0xB0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XB0);
    // 0x800EAD44: swc1        $f4, 0x9C($s1)
    MEM_W(0X9C, ctx->r17) = ctx->f4.u32l;
    // 0x800EAD48: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800EAD4C: lw          $v0, 0xAC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XAC);
    // 0x800EAD50: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x800EAD54: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800EAD58: lw          $a1, 0xA8($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XA8);
    // 0x800EAD5C: jal         0x800F9AB8
    // 0x800EAD60: nop

    func_800F9AB8(rdram, ctx);
        goto after_39;
    // 0x800EAD60: nop

    after_39:
    // 0x800EAD64: j           L_800EADCC
    // 0x800EAD68: nop

        goto L_800EADCC;
    // 0x800EAD68: nop

L_800EAD6C:
    // 0x800EAD6C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800EAD70: lw          $a2, 0x34($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X34);
    // 0x800EAD74: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800EAD78: jal         0x800AA6D0
    // 0x800EAD7C: addiu       $a2, $a2, 0x34
    ctx->r6 = ADD32(ctx->r6, 0X34);
    func_800AA6D0(rdram, ctx);
        goto after_40;
    // 0x800EAD7C: addiu       $a2, $a2, 0x34
    ctx->r6 = ADD32(ctx->r6, 0X34);
    after_40:
    // 0x800EAD80: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800EAD84: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800EAD88: jal         0x800F9A14
    // 0x800EAD8C: nop

    func_800F9A14(rdram, ctx);
        goto after_41;
    // 0x800EAD8C: nop

    after_41:
L_800EAD90:
    // 0x800EAD90: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
L_800EAD94:
    // 0x800EAD94: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800EAD98: jal         0x800E9BF4
    // 0x800EAD9C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_800E9BF4(rdram, ctx);
        goto after_42;
    // 0x800EAD9C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_42:
    // 0x800EADA0: j           L_800EADCC
    // 0x800EADA4: nop

        goto L_800EADCC;
    // 0x800EADA4: nop

L_800EADA8:
    // 0x800EADA8: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800EADAC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800EADB0: jal         0x800F9A14
    // 0x800EADB4: nop

    func_800F9A14(rdram, ctx);
        goto after_43;
    // 0x800EADB4: nop

    after_43:
    // 0x800EADB8: lbu         $v0, 0xB3($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XB3);
    // 0x800EADBC: beq         $v0, $zero, L_800EADCC
    if (ctx->r2 == 0) {
        // 0x800EADC0: nop
    
            goto L_800EADCC;
    }
    // 0x800EADC0: nop

    // 0x800EADC4: jal         0x800EA470
    // 0x800EADC8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_800EA470(rdram, ctx);
        goto after_44;
    // 0x800EADC8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_44:
L_800EADCC:
    // 0x800EADCC: lwc1        $f2, 0x9C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X9C);
    // 0x800EADD0: lwc1        $f0, 0xA0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XA0);
    // 0x800EADD4: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800EADD8: lw          $a0, 0x94($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X94);
    // 0x800EADDC: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800EADE0: jal         0x80083008
    // 0x800EADE4: nop

    func_80083008(rdram, ctx);
        goto after_45;
    // 0x800EADE4: nop

    after_45:
    // 0x800EADE8: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800EADEC: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x800EADF0: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800EADF4: lw          $a1, 0xAC($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XAC);
    // 0x800EADF8: lw          $a2, 0xB0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XB0);
    // 0x800EADFC: jal         0x800EFDE0
    // 0x800EAE00: nop

    func_800EFDE0(rdram, ctx);
        goto after_46;
    // 0x800EAE00: nop

    after_46:
    // 0x800EAE04: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800EAE08: beq         $v0, $zero, L_800EAE14
    if (ctx->r2 == 0) {
        // 0x800EAE0C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800EAE14;
    }
    // 0x800EAE0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EAE10: sh          $v0, 0x6C($s1)
    MEM_H(0X6C, ctx->r17) = ctx->r2;
L_800EAE14:
    // 0x800EAE14: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800EAE18: jal         0x800E9EC4
    // 0x800EAE1C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_800E9EC4(rdram, ctx);
        goto after_47;
    // 0x800EAE1C: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_47:
    // 0x800EAE20: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800EAE24: jal         0x800F06BC
    // 0x800EAE28: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    func_800F06BC(rdram, ctx);
        goto after_48;
    // 0x800EAE28: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    after_48:
    // 0x800EAE2C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800EAE30: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800EAE34: bne         $v0, $v1, L_800EAF04
    if (ctx->r2 != ctx->r3) {
        // 0x800EAE38: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800EAF04;
    }
    // 0x800EAE38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EAE3C: addiu       $v1, $sp, 0x28
    ctx->r3 = ADD32(ctx->r29, 0X28);
    // 0x800EAE40: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // 0x800EAE44: addiu       $a0, $s1, 0x30
    ctx->r4 = ADD32(ctx->r17, 0X30);
L_800EAE48:
    // 0x800EAE48: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800EAE4C: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x800EAE50: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x800EAE54: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x800EAE58: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800EAE5C: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x800EAE60: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x800EAE64: sw          $t3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r11;
    // 0x800EAE68: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800EAE6C: bne         $v0, $a0, L_800EAE48
    if (ctx->r2 != ctx->r4) {
        // 0x800EAE70: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800EAE48;
    }
    // 0x800EAE70: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800EAE74: lw          $a1, 0x68($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X68);
    // 0x800EAE78: jal         0x8001CC3C
    // 0x800EAE7C: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    func_8001CC3C(rdram, ctx);
        goto after_49;
    // 0x800EAE7C: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    after_49:
    // 0x800EAE80: lw          $a1, 0x64($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X64);
    // 0x800EAE84: jal         0x8001CCCC
    // 0x800EAE88: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    func_8001CCCC(rdram, ctx);
        goto after_50;
    // 0x800EAE88: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    after_50:
    // 0x800EAE8C: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x800EAE90: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x800EAE94: jal         0x800193E8
    // 0x800EAE98: addiu       $a2, $s1, 0xC
    ctx->r6 = ADD32(ctx->r17, 0XC);
    func_800193E8(rdram, ctx);
        goto after_51;
    // 0x800EAE98: addiu       $a2, $s1, 0xC
    ctx->r6 = ADD32(ctx->r17, 0XC);
    after_51:
    // 0x800EAE9C: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x800EAEA0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800EAEA4: jal         0x800193E8
    // 0x800EAEA8: addiu       $a2, $s1, 0x18
    ctx->r6 = ADD32(ctx->r17, 0X18);
    func_800193E8(rdram, ctx);
        goto after_52;
    // 0x800EAEA8: addiu       $a2, $s1, 0x18
    ctx->r6 = ADD32(ctx->r17, 0X18);
    after_52:
    // 0x800EAEAC: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800EAEB0: jal         0x800F07AC
    // 0x800EAEB4: nop

    func_800F07AC(rdram, ctx);
        goto after_53;
    // 0x800EAEB4: nop

    after_53:
    // 0x800EAEB8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800EAEBC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800EAEC0: beql        $v0, $v1, L_800EAEC8
    if (ctx->r2 == ctx->r3) {
        // 0x800EAEC4: addu        $s0, $v1, $zero
        ctx->r16 = ADD32(ctx->r3, 0);
            goto L_800EAEC8;
    }
    goto skip_2;
    // 0x800EAEC4: addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
    skip_2:
L_800EAEC8:
    // 0x800EAEC8: addu        $v1, $s1, $zero
    ctx->r3 = ADD32(ctx->r17, 0);
    // 0x800EAECC: addiu       $v0, $sp, 0x28
    ctx->r2 = ADD32(ctx->r29, 0X28);
    // 0x800EAED0: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
L_800EAED4:
    // 0x800EAED4: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800EAED8: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x800EAEDC: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x800EAEE0: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x800EAEE4: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800EAEE8: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x800EAEEC: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x800EAEF0: sw          $t3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r11;
    // 0x800EAEF4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800EAEF8: bne         $v0, $a0, L_800EAED4
    if (ctx->r2 != ctx->r4) {
        // 0x800EAEFC: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800EAED4;
    }
    // 0x800EAEFC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800EAF00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EAF04:
    // 0x800EAF04: bne         $s0, $v0, L_800EB280
    if (ctx->r16 != ctx->r2) {
        // 0x800EAF08: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_800EB280;
    }
    // 0x800EAF08: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800EAF0C: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800EAF10: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x800EAF14: jal         0x800F2D38
    // 0x800EAF18: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_800F2D38(rdram, ctx);
        goto after_54;
    // 0x800EAF18: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_54:
    // 0x800EAF1C: j           L_800EB280
    // 0x800EAF20: nop

        goto L_800EB280;
    // 0x800EAF20: nop

L_800EAF24:
    // 0x800EAF24: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800EAF28: addiu       $t3, $v0, -0x7850
    ctx->r11 = ADD32(ctx->r2, -0X7850);
    // 0x800EAF2C: lwl         $t0, 0x0($t3)
    ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r11, 0X0);
    // 0x800EAF30: lwr         $t0, 0x3($t3)
    ctx->r8 = do_lwr(rdram, ctx->r8, ctx->r11, 0X3);
    // 0x800EAF34: swl         $t0, 0x58($sp)
    do_swl(rdram, 0X58, ctx->r29, ctx->r8);
    // 0x800EAF38: swr         $t0, 0x5B($sp)
    do_swr(rdram, 0X5B, ctx->r29, ctx->r8);
    // 0x800EAF3C: lwc1        $f2, 0x54($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X54);
    // 0x800EAF40: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EAF44: lwc1        $f0, -0x77E0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X77E0);
    // 0x800EAF48: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x800EAF4C: mul.s       $f24, $f2, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800EAF50: jal         0x8006AC7C
    // 0x800EAF54: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8006AC7C(rdram, ctx);
        goto after_55;
    // 0x800EAF54: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_55:
    // 0x800EAF58: lwc1        $f2, 0x50($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X50);
    // 0x800EAF5C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EAF60: lwc1        $f0, -0x77DC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X77DC);
    // 0x800EAF64: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800EAF68: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800EAF6C: jal         0x800612A4
    // 0x800EAF70: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800612A4(rdram, ctx);
        goto after_56;
    // 0x800EAF70: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_56:
    // 0x800EAF74: jal         0x8005EBD8
    // 0x800EAF78: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_8005EBD8(rdram, ctx);
        goto after_57;
    // 0x800EAF78: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_57:
    // 0x800EAF7C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800EAF80: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800EAF84: addiu       $a2, $s1, 0x24
    ctx->r6 = ADD32(ctx->r17, 0X24);
    // 0x800EAF88: lui         $a3, 0x41C0
    ctx->r7 = S32(0X41C0 << 16);
    // 0x800EAF8C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EAF90: lwc1        $f0, -0x77D8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X77D8);
    // 0x800EAF94: addiu       $v0, $zero, 0x21
    ctx->r2 = ADD32(0, 0X21);
    // 0x800EAF98: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800EAF9C: addiu       $v0, $zero, 0x7D
    ctx->r2 = ADD32(0, 0X7D);
    // 0x800EAFA0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800EAFA4: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    // 0x800EAFA8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800EAFAC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800EAFB0: jal         0x800989D8
    // 0x800EAFB4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800989D8(rdram, ctx);
        goto after_58;
    // 0x800EAFB4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_58:
    // 0x800EAFB8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800EAFBC: lbu         $v0, 0xB63($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB63);
    // 0x800EAFC0: beq         $v0, $zero, L_800EB048
    if (ctx->r2 == 0) {
        // 0x800EAFC4: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800EB048;
    }
    // 0x800EAFC4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800EAFC8: ori         $a0, $zero, 0x8002
    ctx->r4 = 0 | 0X8002;
L_800EAFCC:
    // 0x800EAFCC: addiu       $s0, $sp, 0x48
    ctx->r16 = ADD32(ctx->r29, 0X48);
L_800EAFD0:
    // 0x800EAFD0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EAFD4: lwc1        $f2, -0x77D4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X77D4);
    // 0x800EAFD8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800EAFDC: mul.s       $f2, $f24, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f24.fl, ctx->f2.fl);
    // 0x800EAFE0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800EAFE4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EAFE8: lwc1        $f0, -0x77D0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X77D0);
    // 0x800EAFEC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EAFF0: lwc1        $f22, -0x77CC($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X77CC);
    // 0x800EAFF4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EAFF8: lwc1        $f20, -0x77C8($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X77C8);
    // 0x800EAFFC: mul.s       $f0, $f24, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x800EB000: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // 0x800EB004: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x800EB008: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800EB00C: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x800EB010: jal         0x80072684
    // 0x800EB014: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    func_80072684(rdram, ctx);
        goto after_59;
    // 0x800EB014: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_59:
    // 0x800EB018: ori         $a0, $zero, 0x8003
    ctx->r4 = 0 | 0X8003;
    // 0x800EB01C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800EB020: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800EB024: mul.s       $f0, $f24, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f24.fl, ctx->f20.fl);
    // 0x800EB028: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    // 0x800EB02C: swc1        $f24, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f24.u32l;
    // 0x800EB030: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x800EB034: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800EB038: jal         0x80072684
    // 0x800EB03C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80072684(rdram, ctx);
        goto after_60;
    // 0x800EB03C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_60:
    // 0x800EB040: j           L_800EB084
    // 0x800EB044: nop

        goto L_800EB084;
    // 0x800EB044: nop

L_800EB048:
    // 0x800EB048: lw          $v1, 0xB70($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB70);
    // 0x800EB04C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x800EB050: beq         $v1, $v0, L_800EB084
    if (ctx->r3 == ctx->r2) {
        // 0x800EB054: slti        $v0, $v1, 0x7
        ctx->r2 = SIGNED(ctx->r3) < 0X7 ? 1 : 0;
            goto L_800EB084;
    }
    // 0x800EB054: slti        $v0, $v1, 0x7
    ctx->r2 = SIGNED(ctx->r3) < 0X7 ? 1 : 0;
    // 0x800EB058: beq         $v0, $zero, L_800EB070
    if (ctx->r2 == 0) {
        // 0x800EB05C: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_800EB070;
    }
    // 0x800EB05C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800EB060: beq         $v1, $v0, L_800EB084
    if (ctx->r3 == ctx->r2) {
        // 0x800EB064: ori         $a0, $zero, 0x8002
        ctx->r4 = 0 | 0X8002;
            goto L_800EB084;
    }
    // 0x800EB064: ori         $a0, $zero, 0x8002
    ctx->r4 = 0 | 0X8002;
    // 0x800EB068: j           L_800EAFD0
    // 0x800EB06C: addiu       $s0, $sp, 0x48
    ctx->r16 = ADD32(ctx->r29, 0X48);
        goto L_800EAFD0;
    // 0x800EB06C: addiu       $s0, $sp, 0x48
    ctx->r16 = ADD32(ctx->r29, 0X48);
L_800EB070:
    // 0x800EB070: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x800EB074: beq         $v1, $v0, L_800EB084
    if (ctx->r3 == ctx->r2) {
        // 0x800EB078: addiu       $v0, $zero, 0xD
        ctx->r2 = ADD32(0, 0XD);
            goto L_800EB084;
    }
    // 0x800EB078: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // 0x800EB07C: bne         $v1, $v0, L_800EAFCC
    if (ctx->r3 != ctx->r2) {
        // 0x800EB080: ori         $a0, $zero, 0x8002
        ctx->r4 = 0 | 0X8002;
            goto L_800EAFCC;
    }
    // 0x800EB080: ori         $a0, $zero, 0x8002
    ctx->r4 = 0 | 0X8002;
L_800EB084:
    // 0x800EB084: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EB088: lwc1        $f0, -0x77C4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X77C4);
    // 0x800EB08C: mul.s       $f24, $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x800EB090: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800EB094: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EB098: lwc1        $f2, -0x77C0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X77C0);
    // 0x800EB09C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800EB0A0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EB0A4: lwc1        $f0, -0x77BC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X77BC);
    // 0x800EB0A8: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x800EB0AC: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    // 0x800EB0B0: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x800EB0B4: jal         0x80073750
    // 0x800EB0B8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_80073750(rdram, ctx);
        goto after_61;
    // 0x800EB0B8: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_61:
    // 0x800EB0BC: jal         0x80003430
    // 0x800EB0C0: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    rand_recomp(rdram, ctx);
        goto after_62;
    // 0x800EB0C0: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    after_62:
    // 0x800EB0C4: lui         $v1, 0x5555
    ctx->r3 = S32(0X5555 << 16);
    // 0x800EB0C8: ori         $v1, $v1, 0x5556
    ctx->r3 = ctx->r3 | 0X5556;
    // 0x800EB0CC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800EB0D0: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800EB0D4: mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800EB0D8: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x800EB0DC: mfhi        $t0
    ctx->r8 = hi;
    // 0x800EB0E0: subu        $v0, $t0, $v0
    ctx->r2 = SUB32(ctx->r8, ctx->r2);
    // 0x800EB0E4: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x800EB0E8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800EB0EC: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x800EB0F0: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800EB0F4: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800EB0F8: addiu       $s3, $a0, 0x4
    ctx->r19 = ADD32(ctx->r4, 0X4);
    // 0x800EB0FC: blez        $s3, L_800EB234
    if (SIGNED(ctx->r19) <= 0) {
        // 0x800EB100: addiu       $s2, $sp, 0x38
        ctx->r18 = ADD32(ctx->r29, 0X38);
            goto L_800EB234;
    }
    // 0x800EB100: addiu       $s2, $sp, 0x38
    ctx->r18 = ADD32(ctx->r29, 0X38);
    // 0x800EB104: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EB108: lwc1        $f24, -0x77B8($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X77B8);
L_800EB10C:
    // 0x800EB10C: lwc1        $f2, 0x50($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X50);
    // 0x800EB110: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EB114: lwc1        $f0, -0x77B4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X77B4);
    // 0x800EB118: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800EB11C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800EB120: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800EB124: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800EB128: addiu       $a3, $zero, 0x3C
    ctx->r7 = ADD32(0, 0X3C);
    // 0x800EB12C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800EB130: jal         0x8007202C
    // 0x800EB134: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    func_8007202C(rdram, ctx);
        goto after_63;
    // 0x800EB134: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_63:
    // 0x800EB138: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800EB13C: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800EB140: lwc1        $f0, 0x48($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800EB144: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800EB148: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    // 0x800EB14C: add.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800EB150: lwc1        $f0, 0x4C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800EB154: lwc1        $f2, 0x50($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800EB158: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800EB15C: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800EB160: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x800EB164: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800EB168: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x800EB16C: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x800EB170: jal         0x80072300
    // 0x800EB174: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    func_80072300(rdram, ctx);
        goto after_64;
    // 0x800EB174: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_64:
    // 0x800EB178: jal         0x80003430
    // 0x800EB17C: nop

    rand_recomp(rdram, ctx);
        goto after_65;
    // 0x800EB17C: nop

    after_65:
    // 0x800EB180: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800EB184: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800EB188: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800EB18C: sub.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x800EB190: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EB194: lwc1        $f2, -0x77B0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X77B0);
    // 0x800EB198: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800EB19C: abs.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = fabsf(ctx->f0.fl);
    // 0x800EB1A0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EB1A4: lwc1        $f0, -0x77AC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X77AC);
    // 0x800EB1A8: jal         0x80003430
    // 0x800EB1AC: add.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f0.fl;
    rand_recomp(rdram, ctx);
        goto after_66;
    // 0x800EB1AC: add.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f0.fl;
    after_66:
    // 0x800EB1B0: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800EB1B4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800EB1B8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800EB1BC: sub.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x800EB1C0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EB1C4: lwc1        $f2, -0x77A8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X77A8);
    // 0x800EB1C8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800EB1CC: abs.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = fabsf(ctx->f0.fl);
    // 0x800EB1D0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EB1D4: lwc1        $f0, -0x77A4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X77A4);
    // 0x800EB1D8: jal         0x80003430
    // 0x800EB1DC: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
    rand_recomp(rdram, ctx);
        goto after_67;
    // 0x800EB1DC: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
    after_67:
    // 0x800EB1E0: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800EB1E4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800EB1E8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800EB1EC: sub.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x800EB1F0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EB1F4: lwc1        $f2, -0x77A0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X77A0);
    // 0x800EB1F8: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800EB1FC: abs.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = fabsf(ctx->f0.fl);
    // 0x800EB200: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800EB204: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800EB208: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EB20C: lwc1        $f0, -0x779C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X779C);
    // 0x800EB210: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x800EB214: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800EB218: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800EB21C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800EB220: jal         0x80072384
    // 0x800EB224: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    func_80072384(rdram, ctx);
        goto after_68;
    // 0x800EB224: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    after_68:
    // 0x800EB228: slt         $v0, $s0, $s3
    ctx->r2 = SIGNED(ctx->r16) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800EB22C: bne         $v0, $zero, L_800EB10C
    if (ctx->r2 != 0) {
        // 0x800EB230: nop
    
            goto L_800EB10C;
    }
    // 0x800EB230: nop

L_800EB234:
    // 0x800EB234: lwc1        $f2, 0x54($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X54);
    // 0x800EB238: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EB23C: lwc1        $f0, -0x7798($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7798);
    // 0x800EB240: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800EB244: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800EB248: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EB24C: lwc1        $f0, -0x7794($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7794);
    // 0x800EB250: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800EB254: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800EB258: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800EB25C: jal         0x8006C6FC
    // 0x800EB260: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    func_8006C6FC(rdram, ctx);
        goto after_69;
    // 0x800EB260: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    after_69:
    // 0x800EB264: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800EB268: sh          $v0, 0x6C($s1)
    MEM_H(0X6C, ctx->r17) = ctx->r2;
L_800EB26C:
    // 0x800EB26C: lhu         $a0, 0x16($s4)
    ctx->r4 = MEM_HU(ctx->r20, 0X16);
    // 0x800EB270: jal         0x8003ED74
    // 0x800EB274: nop

    func_8003ED74(rdram, ctx);
        goto after_70;
    // 0x800EB274: nop

    after_70:
    // 0x800EB278: j           L_800EB94C
    // 0x800EB27C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800EB94C;
    // 0x800EB27C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EB280:
    // 0x800EB280: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x800EB284: lw          $v0, 0x88($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X88);
    // 0x800EB288: beql        $v0, $zero, L_800EB2C0
    if (ctx->r2 == 0) {
        // 0x800EB28C: sw          $zero, 0xB4($s1)
        MEM_W(0XB4, ctx->r17) = 0;
            goto L_800EB2C0;
    }
    goto skip_3;
    // 0x800EB28C: sw          $zero, 0xB4($s1)
    MEM_W(0XB4, ctx->r17) = 0;
    skip_3:
    // 0x800EB290: jal         0x80047D40
    // 0x800EB294: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    func_80047D40(rdram, ctx);
        goto after_71;
    // 0x800EB294: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_71:
    // 0x800EB298: beq         $v0, $zero, L_800EB2A8
    if (ctx->r2 == 0) {
        // 0x800EB29C: nop
    
            goto L_800EB2A8;
    }
    // 0x800EB29C: nop

    // 0x800EB2A0: j           L_800EB2C0
    // 0x800EB2A4: sw          $zero, 0xB4($s1)
    MEM_W(0XB4, ctx->r17) = 0;
        goto L_800EB2C0;
    // 0x800EB2A4: sw          $zero, 0xB4($s1)
    MEM_W(0XB4, ctx->r17) = 0;
L_800EB2A8:
    // 0x800EB2A8: lw          $v0, 0xB4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XB4);
    // 0x800EB2AC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800EB2B0: sw          $v0, 0xB4($s1)
    MEM_W(0XB4, ctx->r17) = ctx->r2;
    // 0x800EB2B4: slti        $v0, $v0, 0x15
    ctx->r2 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x800EB2B8: beq         $v0, $zero, L_800EB26C
    if (ctx->r2 == 0) {
        // 0x800EB2BC: nop
    
            goto L_800EB26C;
    }
    // 0x800EB2BC: nop

L_800EB2C0:
    // 0x800EB2C0: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800EB2C4: jal         0x800EC6C0
    // 0x800EB2C8: nop

    func_800EC6C0(rdram, ctx);
        goto after_72;
    // 0x800EB2C8: nop

    after_72:
    // 0x800EB2CC: j           L_800EB94C
    // 0x800EB2D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800EB94C;
    // 0x800EB2D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EB2D4:
    // 0x800EB2D4: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x800EB2D8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800EB2DC: lw          $a1, 0x30($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X30);
    // 0x800EB2E0: lw          $a3, 0x50($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X50);
    // 0x800EB2E4: jal         0x8005940C
    // 0x800EB2E8: addu        $s3, $s0, $zero
    ctx->r19 = ADD32(ctx->r16, 0);
    func_8005940C(rdram, ctx);
        goto after_73;
    // 0x800EB2E8: addu        $s3, $s0, $zero
    ctx->r19 = ADD32(ctx->r16, 0);
    after_73:
    // 0x800EB2EC: beq         $v0, $zero, L_800EB590
    if (ctx->r2 == 0) {
        // 0x800EB2F0: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_800EB590;
    }
    // 0x800EB2F0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800EB2F4: lh          $v1, 0x6C($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X6C);
    // 0x800EB2F8: beq         $v1, $v0, L_800EB560
    if (ctx->r3 == ctx->r2) {
        // 0x800EB2FC: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800EB560;
    }
    // 0x800EB2FC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800EB300: lwc1        $f0, 0xC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800EB304: lwc1        $f2, 0x54($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X54);
    // 0x800EB308: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800EB30C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EB310: lwc1        $f8, -0x7790($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7790);
    // 0x800EB314: mul.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800EB318: lwc1        $f6, 0x0($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800EB31C: sub.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800EB320: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EB324: lwc1        $f2, -0x778C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X778C);
    // 0x800EB328: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x800EB32C: lwc1        $f0, 0x54($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X54);
    // 0x800EB330: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800EB334: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800EB338: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800EB33C: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x800EB340: lwc1        $f0, 0x14($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800EB344: lwc1        $f2, 0x54($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X54);
    // 0x800EB348: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800EB34C: nop

    // 0x800EB350: mul.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800EB354: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x800EB358: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800EB35C: lw          $v0, -0x72E4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X72E4);
    // 0x800EB360: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800EB364: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x800EB368: addiu       $s2, $v0, 0x28
    ctx->r18 = ADD32(ctx->r2, 0X28);
    // 0x800EB36C: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x800EB370: lwc1        $f0, 0x24($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X24);
    // 0x800EB374: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x800EB378: sub.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800EB37C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x800EB380: lwc1        $f0, 0x28($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X28);
    // 0x800EB384: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    // 0x800EB388: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800EB38C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x800EB390: lwc1        $f0, 0x2C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X2C);
    // 0x800EB394: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x800EB398: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800EB39C: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x800EB3A0: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x800EB3A4: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x800EB3A8: jal         0x80068D5C
    // 0x800EB3AC: swc1        $f2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f2.u32l;
    func_80068D5C(rdram, ctx);
        goto after_74;
    // 0x800EB3AC: swc1        $f2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f2.u32l;
    after_74:
    // 0x800EB3B0: bne         $v0, $zero, L_800EB3C4
    if (ctx->r2 != 0) {
        // 0x800EB3B4: nop
    
            goto L_800EB3C4;
    }
    // 0x800EB3B4: nop

    // 0x800EB3B8: lw          $a0, 0x94($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X94);
    // 0x800EB3BC: jal         0x80083468
    // 0x800EB3C0: nop

    func_80083468(rdram, ctx);
        goto after_75;
    // 0x800EB3C0: nop

    after_75:
L_800EB3C4:
    // 0x800EB3C4: lw          $v0, 0x3C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X3C);
    // 0x800EB3C8: lw          $s0, 0x44($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X44);
    // 0x800EB3CC: addiu       $s2, $v0, 0x1C
    ctx->r18 = ADD32(ctx->r2, 0X1C);
    // 0x800EB3D0: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800EB3D4: lwc1        $f2, 0x58($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800EB3D8: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800EB3DC: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x800EB3E0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800EB3E4: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800EB3E8: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800EB3EC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800EB3F0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800EB3F4: jal         0x8001CA90
    // 0x800EB3F8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_8001CA90(rdram, ctx);
        goto after_76;
    // 0x800EB3F8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_76:
    // 0x800EB3FC: lw          $a1, 0x68($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X68);
    // 0x800EB400: jal         0x8001CB9C
    // 0x800EB404: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_8001CB9C(rdram, ctx);
        goto after_77;
    // 0x800EB404: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_77:
    // 0x800EB408: lw          $a1, 0x64($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X64);
    // 0x800EB40C: jal         0x8001CCCC
    // 0x800EB410: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_8001CCCC(rdram, ctx);
        goto after_78;
    // 0x800EB410: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_78:
    // 0x800EB414: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    // 0x800EB418: lw          $a2, 0x54($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X54);
    // 0x800EB41C: lw          $a3, 0x58($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X58);
    // 0x800EB420: jal         0x8001CA90
    // 0x800EB424: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_8001CA90(rdram, ctx);
        goto after_79;
    // 0x800EB424: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_79:
    // 0x800EB428: lw          $v0, 0x40($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X40);
    // 0x800EB42C: lw          $s0, 0x48($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X48);
    // 0x800EB430: addiu       $s2, $v0, 0x1C
    ctx->r18 = ADD32(ctx->r2, 0X1C);
    // 0x800EB434: jal         0x8001CA50
    // 0x800EB438: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_8001CA50(rdram, ctx);
        goto after_80;
    // 0x800EB438: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_80:
    // 0x800EB43C: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x800EB440: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800EB444: beq         $v0, $zero, L_800EB478
    if (ctx->r2 == 0) {
        // 0x800EB448: nop
    
            goto L_800EB478;
    }
    // 0x800EB448: nop

    // 0x800EB44C: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800EB450: lwc1        $f2, 0x58($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800EB454: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800EB458: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x800EB45C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800EB460: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800EB464: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800EB468: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800EB46C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800EB470: jal         0x8001CA90
    // 0x800EB474: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_8001CA90(rdram, ctx);
        goto after_81;
    // 0x800EB474: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_81:
L_800EB478:
    // 0x800EB478: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x800EB47C: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x800EB480: beq         $v0, $zero, L_800EB49C
    if (ctx->r2 == 0) {
        // 0x800EB484: nop
    
            goto L_800EB49C;
    }
    // 0x800EB484: nop

    // 0x800EB488: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    // 0x800EB48C: lw          $a2, 0x60($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X60);
    // 0x800EB490: lw          $a3, 0x64($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X64);
    // 0x800EB494: jal         0x8001CB04
    // 0x800EB498: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_8001CB04(rdram, ctx);
        goto after_82;
    // 0x800EB498: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_82:
L_800EB49C:
    // 0x800EB49C: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x800EB4A0: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x800EB4A4: beq         $v0, $zero, L_800EB4B4
    if (ctx->r2 == 0) {
        // 0x800EB4A8: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_800EB4B4;
    }
    // 0x800EB4A8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800EB4AC: jal         0x8001DAEC
    // 0x800EB4B0: addiu       $a1, $s0, 0x68
    ctx->r5 = ADD32(ctx->r16, 0X68);
    func_8001DAEC(rdram, ctx);
        goto after_83;
    // 0x800EB4B0: addiu       $a1, $s0, 0x68
    ctx->r5 = ADD32(ctx->r16, 0X68);
    after_83:
L_800EB4B4:
    // 0x800EB4B4: lwc1        $f2, 0x60($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X60);
    // 0x800EB4B8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EB4BC: lwc1        $f0, -0x7788($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7788);
    // 0x800EB4C0: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800EB4C4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800EB4C8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800EB4CC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800EB4D0: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800EB4D4: jal         0x8001CA90
    // 0x800EB4D8: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    func_8001CA90(rdram, ctx);
        goto after_84;
    // 0x800EB4D8: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_84:
    // 0x800EB4DC: lw          $a0, 0x4C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4C);
    // 0x800EB4E0: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x800EB4E4: andi        $v1, $a0, 0x9
    ctx->r3 = ctx->r4 & 0X9;
    // 0x800EB4E8: bne         $v1, $v0, L_800EB528
    if (ctx->r3 != ctx->r2) {
        // 0x800EB4EC: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_800EB528;
    }
    // 0x800EB4EC: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800EB4F0: lwc1        $f2, 0x78($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800EB4F4: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800EB4F8: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800EB4FC: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800EB500: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800EB504: lwc1        $f2, 0x7C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x800EB508: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800EB50C: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800EB510: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800EB514: lwc1        $f2, 0x80($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X80);
    // 0x800EB518: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800EB51C: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800EB520: j           L_800EB558
    // 0x800EB524: nop

        goto L_800EB558;
    // 0x800EB524: nop

L_800EB528:
    // 0x800EB528: bne         $v1, $v0, L_800EB544
    if (ctx->r3 != ctx->r2) {
        // 0x800EB52C: andi        $v0, $a0, 0x1
        ctx->r2 = ctx->r4 & 0X1;
            goto L_800EB544;
    }
    // 0x800EB52C: andi        $v0, $a0, 0x1
    ctx->r2 = ctx->r4 & 0X1;
    // 0x800EB530: lw          $a1, 0x78($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X78);
    // 0x800EB534: lw          $a2, 0x7C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X7C);
    // 0x800EB538: lw          $a3, 0x80($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X80);
    // 0x800EB53C: j           L_800EB558
    // 0x800EB540: nop

        goto L_800EB558;
    // 0x800EB540: nop

L_800EB544:
    // 0x800EB544: beq         $v0, $zero, L_800EB564
    if (ctx->r2 == 0) {
        // 0x800EB548: addu        $a1, $s1, $zero
        ctx->r5 = ADD32(ctx->r17, 0);
            goto L_800EB564;
    }
    // 0x800EB548: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800EB54C: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    // 0x800EB550: lw          $a2, 0x54($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X54);
    // 0x800EB554: lw          $a3, 0x58($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X58);
L_800EB558:
    // 0x800EB558: jal         0x8001CA90
    // 0x800EB55C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_8001CA90(rdram, ctx);
        goto after_85;
    // 0x800EB55C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_85:
L_800EB560:
    // 0x800EB560: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
L_800EB564:
    // 0x800EB564: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x800EB568: lw          $a2, 0x54($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X54);
    // 0x800EB56C: jal         0x80059B50
    // 0x800EB570: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_80059B50(rdram, ctx);
        goto after_86;
    // 0x800EB570: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_86:
    // 0x800EB574: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x800EB578: lw          $a1, 0x30($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X30);
    // 0x800EB57C: lw          $a3, 0x50($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X50);
    // 0x800EB580: jal         0x80057C8C
    // 0x800EB584: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_80057C8C(rdram, ctx);
        goto after_87;
    // 0x800EB584: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_87:
    // 0x800EB588: j           L_800EB5B0
    // 0x800EB58C: nop

        goto L_800EB5B0;
    // 0x800EB58C: nop

L_800EB590:
    // 0x800EB590: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x800EB594: jal         0x80059970
    // 0x800EB598: nop

    func_80059970(rdram, ctx);
        goto after_88;
    // 0x800EB598: nop

    after_88:
    // 0x800EB59C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800EB5A0: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x800EB5A4: lw          $a2, 0x54($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X54);
    // 0x800EB5A8: jal         0x80059B50
    // 0x800EB5AC: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_80059B50(rdram, ctx);
        goto after_89;
    // 0x800EB5AC: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_89:
L_800EB5B0:
    // 0x800EB5B0: lw          $a3, 0x4C($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X4C);
    // 0x800EB5B4: beq         $a3, $zero, L_800EB94C
    if (ctx->r7 == 0) {
        // 0x800EB5B8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800EB94C;
    }
    // 0x800EB5B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EB5BC: lw          $a0, 0x8($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X8);
    // 0x800EB5C0: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    // 0x800EB5C4: jal         0x8006BEC8
    // 0x800EB5C8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    func_8006BEC8(rdram, ctx);
        goto after_90;
    // 0x800EB5C8: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_90:
    // 0x800EB5CC: j           L_800EB94C
    // 0x800EB5D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800EB94C;
    // 0x800EB5D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EB5D4:
    // 0x800EB5D4: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800EB5D8: jal         0x800F20EC
    // 0x800EB5DC: addu        $s2, $s0, $zero
    ctx->r18 = ADD32(ctx->r16, 0);
    getNpcCurrentHealth(rdram, ctx);
        goto after_91;
    // 0x800EB5DC: addu        $s2, $s0, $zero
    ctx->r18 = ADD32(ctx->r16, 0);
    after_91:
    // 0x800EB5E0: blez        $v0, L_800EB788
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800EB5E4: nop
    
            goto L_800EB788;
    }
    // 0x800EB5E4: nop

    // 0x800EB5E8: jal         0x80076250
    // 0x800EB5EC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80076250(rdram, ctx);
        goto after_92;
    // 0x800EB5EC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_92:
    // 0x800EB5F0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800EB5F4: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800EB5F8: addiu       $a2, $s1, 0x24
    ctx->r6 = ADD32(ctx->r17, 0X24);
    // 0x800EB5FC: lui         $a3, 0x41C0
    ctx->r7 = S32(0X41C0 << 16);
    // 0x800EB600: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EB604: lwc1        $f0, -0x7784($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7784);
    // 0x800EB608: addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
    // 0x800EB60C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800EB610: addiu       $v0, $zero, 0x7D
    ctx->r2 = ADD32(0, 0X7D);
    // 0x800EB614: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800EB618: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    // 0x800EB61C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800EB620: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800EB624: jal         0x800989D8
    // 0x800EB628: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800989D8(rdram, ctx);
        goto after_93;
    // 0x800EB628: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_93:
    // 0x800EB62C: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800EB630: lhu         $a1, 0x6($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X6);
    // 0x800EB634: jal         0x800F2120
    // 0x800EB638: nop

    dealDamageToNpc(rdram, ctx);
        goto after_94;
    // 0x800EB638: nop

    after_94:
    // 0x800EB63C: bgtz        $v0, L_800EB6EC
    if (SIGNED(ctx->r2) > 0) {
        // 0x800EB640: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_800EB6EC;
    }
    // 0x800EB640: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800EB644: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x800EB648: lhu         $a0, 0x7A($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X7A);
    // 0x800EB64C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800EB650: jal         0x8003E7D0
    // 0x800EB654: sh          $v0, 0x6C($s1)
    MEM_H(0X6C, ctx->r17) = ctx->r2;
    func_8003E7D0(rdram, ctx);
        goto after_95;
    // 0x800EB654: sh          $v0, 0x6C($s1)
    MEM_H(0X6C, ctx->r17) = ctx->r2;
    after_95:
    // 0x800EB658: lhu         $a0, 0x7C($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X7C);
    // 0x800EB65C: jal         0x8003E7D0
    // 0x800EB660: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_8003E7D0(rdram, ctx);
        goto after_96;
    // 0x800EB660: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_96:
    // 0x800EB664: lhu         $a0, 0x80($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X80);
    // 0x800EB668: jal         0x8003E7D0
    // 0x800EB66C: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_8003E7D0(rdram, ctx);
        goto after_97;
    // 0x800EB66C: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_97:
    // 0x800EB670: lhu         $v1, 0x82($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X82);
    // 0x800EB674: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800EB678: beq         $v1, $v0, L_800EB688
    if (ctx->r3 == ctx->r2) {
        // 0x800EB67C: addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
            goto L_800EB688;
    }
    // 0x800EB67C: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x800EB680: jal         0x8003E7D0
    // 0x800EB684: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_8003E7D0(rdram, ctx);
        goto after_98;
    // 0x800EB684: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_98:
L_800EB688:
    // 0x800EB688: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800EB68C: lhu         $a0, -0x6A8C($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A8C);
    // 0x800EB690: jal         0x8003E684
    // 0x800EB694: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_8003E684(rdram, ctx);
        goto after_99;
    // 0x800EB694: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_99:
    // 0x800EB698: lw          $v1, 0x34($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X34);
    // 0x800EB69C: lw          $v0, 0x80($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X80);
    // 0x800EB6A0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800EB6A4: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x800EB6A8: lw          $v0, 0x84($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X84);
    // 0x800EB6AC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x800EB6B0: lw          $a0, 0x78($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X78);
    // 0x800EB6B4: lw          $a1, 0x7C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X7C);
    // 0x800EB6B8: lw          $a2, 0x70($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X70);
    // 0x800EB6BC: lw          $a3, 0x74($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X74);
    // 0x800EB6C0: jal         0x80065914
    // 0x800EB6C4: nop

    datItemSetObjectiveBooleanCount(rdram, ctx);
        goto after_100;
    // 0x800EB6C4: nop

    after_100:
    // 0x800EB6C8: jal         0x800F3260
    // 0x800EB6CC: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    func_800F3260(rdram, ctx);
        goto after_101;
    // 0x800EB6CC: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    after_101:
    // 0x800EB6D0: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800EB6D4: jal         0x800F2A24
    // 0x800EB6D8: nop

    func_800F2A24(rdram, ctx);
        goto after_102;
    // 0x800EB6D8: nop

    after_102:
    // 0x800EB6DC: jal         0x800F2AA4
    // 0x800EB6E0: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    func_800F2AA4(rdram, ctx);
        goto after_103;
    // 0x800EB6E0: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    after_103:
    // 0x800EB6E4: j           L_800EB788
    // 0x800EB6E8: nop

        goto L_800EB788;
    // 0x800EB6E8: nop

L_800EB6EC:
    // 0x800EB6EC: lhu         $v1, 0x2($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X2);
    // 0x800EB6F0: beq         $v1, $v0, L_800EB788
    if (ctx->r3 == ctx->r2) {
        // 0x800EB6F4: nop
    
            goto L_800EB788;
    }
    // 0x800EB6F4: nop

    // 0x800EB6F8: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800EB6FC: jal         0x800F287C
    // 0x800EB700: nop

    func_800F287C(rdram, ctx);
        goto after_104;
    // 0x800EB700: nop

    after_104:
    // 0x800EB704: bne         $v0, $zero, L_800EB788
    if (ctx->r2 != 0) {
        // 0x800EB708: nop
    
            goto L_800EB788;
    }
    // 0x800EB708: nop

    // 0x800EB70C: jal         0x8006C994
    // 0x800EB710: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_8006C994(rdram, ctx);
        goto after_105;
    // 0x800EB710: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_105:
    // 0x800EB714: lhu         $v1, 0x2($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X2);
    // 0x800EB718: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800EB71C: bne         $v1, $v0, L_800EB788
    if (ctx->r3 != ctx->r2) {
        // 0x800EB720: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_800EB788;
    }
    // 0x800EB720: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800EB724: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800EB728: lwc1        $f0, -0x3F40($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, -0X3F40);
    // 0x800EB72C: lwc1        $f2, 0xBA4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XBA4);
    // 0x800EB730: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800EB734: nop

    // 0x800EB738: bc1f        L_800EB788
    if (!c1cs) {
        // 0x800EB73C: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_800EB788;
    }
    // 0x800EB73C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800EB740: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EB744: lwc1        $f0, -0x7780($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7780);
    // 0x800EB748: add.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800EB74C: swc1        $f0, -0x3F40($v1)
    MEM_W(-0X3F40, ctx->r3) = ctx->f0.u32l;
    // 0x800EB750: lw          $v1, 0xB70($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB70);
    // 0x800EB754: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x800EB758: bne         $v1, $v0, L_800EB778
    if (ctx->r3 != ctx->r2) {
        // 0x800EB75C: addiu       $a0, $zero, 0x217
        ctx->r4 = ADD32(0, 0X217);
            goto L_800EB778;
    }
    // 0x800EB75C: addiu       $a0, $zero, 0x217
    ctx->r4 = ADD32(0, 0X217);
    // 0x800EB760: jal         0x80003430
    // 0x800EB764: nop

    rand_recomp(rdram, ctx);
        goto after_106;
    // 0x800EB764: nop

    after_106:
    // 0x800EB768: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800EB76C: beq         $v0, $zero, L_800EB778
    if (ctx->r2 == 0) {
        // 0x800EB770: addiu       $a0, $zero, 0x217
        ctx->r4 = ADD32(0, 0X217);
            goto L_800EB778;
    }
    // 0x800EB770: addiu       $a0, $zero, 0x217
    ctx->r4 = ADD32(0, 0X217);
    // 0x800EB774: addiu       $a0, $zero, 0x1F0
    ctx->r4 = ADD32(0, 0X1F0);
L_800EB778:
    // 0x800EB778: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x800EB77C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800EB780: jal         0x80066EE4
    // 0x800EB784: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80066EE4(rdram, ctx);
        goto after_107;
    // 0x800EB784: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_107:
L_800EB788:
    // 0x800EB788: lhu         $v1, 0x0($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X0);
    // 0x800EB78C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800EB790: beq         $v1, $v0, L_800EB94C
    if (ctx->r3 == ctx->r2) {
        // 0x800EB794: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800EB94C;
    }
    // 0x800EB794: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EB798: jal         0x8003ED74
    // 0x800EB79C: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    func_8003ED74(rdram, ctx);
        goto after_108;
    // 0x800EB79C: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    after_108:
    // 0x800EB7A0: j           L_800EB94C
    // 0x800EB7A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800EB94C;
    // 0x800EB7A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EB7A8:
    // 0x800EB7A8: lbu         $v1, 0x18($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X18);
    // 0x800EB7AC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800EB7B0: beq         $v1, $a0, L_800EB820
    if (ctx->r3 == ctx->r4) {
        // 0x800EB7B4: addu        $s5, $s0, $zero
        ctx->r21 = ADD32(ctx->r16, 0);
            goto L_800EB820;
    }
    // 0x800EB7B4: addu        $s5, $s0, $zero
    ctx->r21 = ADD32(ctx->r16, 0);
    // 0x800EB7B8: slti        $v0, $v1, 0x3
    ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800EB7BC: beq         $v0, $zero, L_800EB7D4
    if (ctx->r2 == 0) {
        // 0x800EB7C0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800EB7D4;
    }
    // 0x800EB7C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EB7C4: beq         $v1, $v0, L_800EB7F0
    if (ctx->r3 == ctx->r2) {
        // 0x800EB7C8: nop
    
            goto L_800EB7F0;
    }
    // 0x800EB7C8: nop

    // 0x800EB7CC: j           L_800EB948
    // 0x800EB7D0: nop

        goto L_800EB948;
    // 0x800EB7D0: nop

L_800EB7D4:
    // 0x800EB7D4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800EB7D8: beq         $v1, $v0, L_800EB850
    if (ctx->r3 == ctx->r2) {
        // 0x800EB7DC: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_800EB850;
    }
    // 0x800EB7DC: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800EB7E0: beq         $v1, $v0, L_800EB858
    if (ctx->r3 == ctx->r2) {
        // 0x800EB7E4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800EB858;
    }
    // 0x800EB7E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EB7E8: j           L_800EB94C
    // 0x800EB7EC: nop

        goto L_800EB94C;
    // 0x800EB7EC: nop

L_800EB7F0:
    // 0x800EB7F0: lbu         $v0, 0x9($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X9);
    // 0x800EB7F4: sb          $v0, 0xB1($s1)
    MEM_B(0XB1, ctx->r17) = ctx->r2;
    // 0x800EB7F8: lbu         $v0, 0xA($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XA);
    // 0x800EB7FC: sb          $v0, 0xB2($s1)
    MEM_B(0XB2, ctx->r17) = ctx->r2;
    // 0x800EB800: lbu         $v0, 0x8($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X8);
    // 0x800EB804: sb          $v0, 0xB0($s1)
    MEM_B(0XB0, ctx->r17) = ctx->r2;
    // 0x800EB808: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800EB80C: sw          $v0, 0xAC($s1)
    MEM_W(0XAC, ctx->r17) = ctx->r2;
    // 0x800EB810: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800EB814: sb          $v1, 0xB3($s1)
    MEM_B(0XB3, ctx->r17) = ctx->r3;
    // 0x800EB818: j           L_800EB948
    // 0x800EB81C: swc1        $f0, 0xA8($s1)
    MEM_W(0XA8, ctx->r17) = ctx->f0.u32l;
        goto L_800EB948;
    // 0x800EB81C: swc1        $f0, 0xA8($s1)
    MEM_W(0XA8, ctx->r17) = ctx->f0.u32l;
L_800EB820:
    // 0x800EB820: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800EB824: lwc1        $f0, 0xA4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XA4);
    // 0x800EB828: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800EB82C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EB830: lwc1        $f0, -0x777C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X777C);
    // 0x800EB834: lw          $a0, 0x94($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X94);
    // 0x800EB838: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800EB83C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800EB840: jal         0x80083258
    // 0x800EB844: sw          $a1, 0xA0($s1)
    MEM_W(0XA0, ctx->r17) = ctx->r5;
    func_80083258(rdram, ctx);
        goto after_109;
    // 0x800EB844: sw          $a1, 0xA0($s1)
    MEM_W(0XA0, ctx->r17) = ctx->r5;
    after_109:
    // 0x800EB848: j           L_800EB94C
    // 0x800EB84C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800EB94C;
    // 0x800EB84C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EB850:
    // 0x800EB850: j           L_800EB948
    // 0x800EB854: sb          $a0, 0xB3($s1)
    MEM_B(0XB3, ctx->r17) = ctx->r4;
        goto L_800EB948;
    // 0x800EB854: sb          $a0, 0xB3($s1)
    MEM_B(0XB3, ctx->r17) = ctx->r4;
L_800EB858:
    // 0x800EB858: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800EB85C: jal         0x800F20EC
    // 0x800EB860: nop

    getNpcCurrentHealth(rdram, ctx);
        goto after_110;
    // 0x800EB860: nop

    after_110:
    // 0x800EB864: blez        $v0, L_800EB94C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800EB868: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800EB94C;
    }
    // 0x800EB868: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EB86C: lhu         $a0, 0x7C($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X7C);
    // 0x800EB870: jal         0x8003E7D0
    // 0x800EB874: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_8003E7D0(rdram, ctx);
        goto after_111;
    // 0x800EB874: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_111:
    // 0x800EB878: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800EB87C: addiu       $s3, $v0, -0x6AA0
    ctx->r19 = ADD32(ctx->r2, -0X6AA0);
    // 0x800EB880: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800EB884: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800EB888: bne         $v0, $s2, L_800EB894
    if (ctx->r2 != ctx->r18) {
        // 0x800EB88C: addiu       $v1, $zero, 0x2C
        ctx->r3 = ADD32(0, 0X2C);
            goto L_800EB894;
    }
    // 0x800EB88C: addiu       $v1, $zero, 0x2C
    ctx->r3 = ADD32(0, 0X2C);
    // 0x800EB890: addiu       $v1, $zero, 0x2E
    ctx->r3 = ADD32(0, 0X2E);
L_800EB894:
    // 0x800EB894: addu        $v0, $v1, $s3
    ctx->r2 = ADD32(ctx->r3, ctx->r19);
    // 0x800EB898: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x800EB89C: jal         0x8003E684
    // 0x800EB8A0: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_8003E684(rdram, ctx);
        goto after_112;
    // 0x800EB8A0: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_112:
    // 0x800EB8A4: lhu         $a0, 0x80($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X80);
    // 0x800EB8A8: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x800EB8AC: jal         0x8003E7D0
    // 0x800EB8B0: sh          $v0, 0x7C($s1)
    MEM_H(0X7C, ctx->r17) = ctx->r2;
    func_8003E7D0(rdram, ctx);
        goto after_113;
    // 0x800EB8B0: sh          $v0, 0x7C($s1)
    MEM_H(0X7C, ctx->r17) = ctx->r2;
    after_113:
    // 0x800EB8B4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800EB8B8: bne         $v0, $s2, L_800EB8C4
    if (ctx->r2 != ctx->r18) {
        // 0x800EB8BC: addiu       $v1, $zero, 0x12
        ctx->r3 = ADD32(0, 0X12);
            goto L_800EB8C4;
    }
    // 0x800EB8BC: addiu       $v1, $zero, 0x12
    ctx->r3 = ADD32(0, 0X12);
    // 0x800EB8C0: addiu       $v1, $zero, 0xE
    ctx->r3 = ADD32(0, 0XE);
L_800EB8C4:
    // 0x800EB8C4: addu        $v0, $v1, $s3
    ctx->r2 = ADD32(ctx->r3, ctx->r19);
    // 0x800EB8C8: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x800EB8CC: jal         0x8003E684
    // 0x800EB8D0: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_8003E684(rdram, ctx);
        goto after_114;
    // 0x800EB8D0: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_114:
    // 0x800EB8D4: lhu         $v1, 0x82($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X82);
    // 0x800EB8D8: sh          $v0, 0x80($s1)
    MEM_H(0X80, ctx->r17) = ctx->r2;
    // 0x800EB8DC: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800EB8E0: beq         $v1, $v0, L_800EB924
    if (ctx->r3 == ctx->r2) {
        // 0x800EB8E4: addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
            goto L_800EB924;
    }
    // 0x800EB8E4: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x800EB8E8: jal         0x8003E7D0
    // 0x800EB8EC: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_8003E7D0(rdram, ctx);
        goto after_115;
    // 0x800EB8EC: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_115:
    // 0x800EB8F0: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x800EB8F4: lw          $v0, 0xA8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XA8);
    // 0x800EB8F8: beq         $v0, $zero, L_800EB924
    if (ctx->r2 == 0) {
        // 0x800EB8FC: nop
    
            goto L_800EB924;
    }
    // 0x800EB8FC: nop

    // 0x800EB900: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800EB904: bne         $v0, $s2, L_800EB910
    if (ctx->r2 != ctx->r18) {
        // 0x800EB908: addiu       $v1, $zero, 0x18
        ctx->r3 = ADD32(0, 0X18);
            goto L_800EB910;
    }
    // 0x800EB908: addiu       $v1, $zero, 0x18
    ctx->r3 = ADD32(0, 0X18);
    // 0x800EB90C: addiu       $v1, $zero, 0x1A
    ctx->r3 = ADD32(0, 0X1A);
L_800EB910:
    // 0x800EB910: addu        $v0, $v1, $s3
    ctx->r2 = ADD32(ctx->r3, ctx->r19);
    // 0x800EB914: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x800EB918: jal         0x8003E684
    // 0x800EB91C: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    func_8003E684(rdram, ctx);
        goto after_116;
    // 0x800EB91C: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_116:
    // 0x800EB920: sh          $v0, 0x82($s1)
    MEM_H(0X82, ctx->r17) = ctx->r2;
L_800EB924:
    // 0x800EB924: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800EB928: lw          $a1, 0x0($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X0);
    // 0x800EB92C: jal         0x800F2830
    // 0x800EB930: nop

    func_800F2830(rdram, ctx);
        goto after_117;
    // 0x800EB930: nop

    after_117:
    // 0x800EB934: j           L_800EB94C
    // 0x800EB938: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800EB94C;
    // 0x800EB938: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EB93C:
    // 0x800EB93C: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800EB940: jal         0x800EFD80
    // 0x800EB944: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_800EFD80(rdram, ctx);
        goto after_118;
    // 0x800EB944: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_118:
L_800EB948:
    // 0x800EB948: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EB94C:
    // 0x800EB94C: lw          $ra, 0xA8($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XA8);
    // 0x800EB950: lw          $s7, 0xA4($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XA4);
    // 0x800EB954: lw          $s6, 0xA0($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XA0);
    // 0x800EB958: lw          $s5, 0x9C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X9C);
    // 0x800EB95C: lw          $s4, 0x98($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X98);
    // 0x800EB960: lw          $s3, 0x94($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X94);
    // 0x800EB964: lw          $s2, 0x90($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X90);
    // 0x800EB968: lw          $s1, 0x8C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X8C);
    // 0x800EB96C: lw          $s0, 0x88($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X88);
    // 0x800EB970: ldc1        $f24, 0xC0($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0XC0);
    // 0x800EB974: ldc1        $f22, 0xB8($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0XB8);
    // 0x800EB978: ldc1        $f20, 0xB0($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XB0);
    // 0x800EB97C: jr          $ra
    // 0x800EB980: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x800EB980: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void func_800EB984(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EB984: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EB988: jr          $ra
    // 0x800EB98C: sw          $zero, -0x3F40($v0)
    MEM_W(-0X3F40, ctx->r2) = 0;
    return;
    // 0x800EB98C: sw          $zero, -0x3F40($v0)
    MEM_W(-0X3F40, ctx->r2) = 0;
;}
RECOMP_FUNC void npcPowerUpUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EB990: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800EB994: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x800EB998: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x800EB99C: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x800EB9A0: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x800EB9A4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800EB9A8: sw          $ra, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r31;
    // 0x800EB9AC: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x800EB9B0: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x800EB9B4: sdc1        $f24, 0x60($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X60, ctx->r29);
    // 0x800EB9B8: sdc1        $f22, 0x58($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X58, ctx->r29);
    // 0x800EB9BC: sdc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X50, ctx->r29);
    // 0x800EB9C0: lw          $s1, 0x4($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X4);
    // 0x800EB9C4: beq         $a1, $v0, L_800EBB80
    if (ctx->r5 == ctx->r2) {
        // 0x800EB9C8: addu        $s3, $a2, $zero
        ctx->r19 = ADD32(ctx->r6, 0);
            goto L_800EBB80;
    }
    // 0x800EB9C8: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x800EB9CC: slti        $v0, $a1, 0x3
    ctx->r2 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
    // 0x800EB9D0: beq         $v0, $zero, L_800EB9E8
    if (ctx->r2 == 0) {
        // 0x800EB9D4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800EB9E8;
    }
    // 0x800EB9D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EB9D8: beq         $a1, $v0, L_800EBA04
    if (ctx->r5 == ctx->r2) {
        // 0x800EB9DC: addiu       $s0, $s1, 0x8
        ctx->r16 = ADD32(ctx->r17, 0X8);
            goto L_800EBA04;
    }
    // 0x800EB9DC: addiu       $s0, $s1, 0x8
    ctx->r16 = ADD32(ctx->r17, 0X8);
    // 0x800EB9E0: j           L_800EC0E0
    // 0x800EB9E4: nop

        goto L_800EC0E0;
    // 0x800EB9E4: nop

L_800EB9E8:
    // 0x800EB9E8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800EB9EC: beq         $a1, $v0, L_800EBBB8
    if (ctx->r5 == ctx->r2) {
        // 0x800EB9F0: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_800EBBB8;
    }
    // 0x800EB9F0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800EB9F4: beq         $a1, $v0, L_800EBF58
    if (ctx->r5 == ctx->r2) {
        // 0x800EB9F8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800EBF58;
    }
    // 0x800EB9F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EB9FC: j           L_800EC0E4
    // 0x800EBA00: nop

        goto L_800EC0E4;
    // 0x800EBA00: nop

L_800EBA04:
    // 0x800EBA04: lhu         $v0, 0x14($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X14);
    // 0x800EBA08: sw          $s0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r16;
    // 0x800EBA0C: ori         $v0, $v0, 0x110
    ctx->r2 = ctx->r2 | 0X110;
    // 0x800EBA10: sh          $v0, 0x14($s2)
    MEM_H(0X14, ctx->r18) = ctx->r2;
    // 0x800EBA14: lw          $a1, 0x1C($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X1C);
    // 0x800EBA18: lw          $a2, 0x20($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X20);
    // 0x800EBA1C: lw          $a3, 0x24($s3)
    ctx->r7 = MEM_W(ctx->r19, 0X24);
    // 0x800EBA20: jal         0x80059D78
    // 0x800EBA24: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80059D78(rdram, ctx);
        goto after_0;
    // 0x800EBA24: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_0:
    // 0x800EBA28: lwc1        $f0, 0x10($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X10);
    // 0x800EBA2C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800EBA30: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
    // 0x800EBA34: lwc1        $f0, 0x14($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X14);
    // 0x800EBA38: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x800EBA3C: swc1        $f0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f0.u32l;
    // 0x800EBA40: lwc1        $f0, 0x18($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X18);
    // 0x800EBA44: addiu       $a0, $a0, -0x7770
    ctx->r4 = ADD32(ctx->r4, -0X7770);
    // 0x800EBA48: swc1        $f20, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f20.u32l;
    // 0x800EBA4C: swc1        $f20, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f20.u32l;
    // 0x800EBA50: swc1        $f20, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f20.u32l;
    // 0x800EBA54: sb          $zero, 0x6C($s1)
    MEM_B(0X6C, ctx->r17) = 0;
    // 0x800EBA58: sw          $s3, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r19;
    // 0x800EBA5C: jal         0x80056EB0
    // 0x800EBA60: swc1        $f0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f0.u32l;
    func_80056EB0(rdram, ctx);
        goto after_1;
    // 0x800EBA60: swc1        $f0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f0.u32l;
    after_1:
    // 0x800EBA64: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x800EBA68: lwc1        $f0, 0x28($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X28);
    // 0x800EBA6C: swc1        $f0, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f0.u32l;
    // 0x800EBA70: lwc1        $f2, 0x70($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X70);
    // 0x800EBA74: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EBA78: lwc1        $f0, -0x7760($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7760);
    // 0x800EBA7C: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800EBA80: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800EBA84: lw          $a2, 0x44($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X44);
    // 0x800EBA88: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800EBA8C: swc1        $f20, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->f20.u32l;
    // 0x800EBA90: swc1        $f2, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f2.u32l;
    // 0x800EBA94: lwc1        $f0, 0x74($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X74);
    // 0x800EBA98: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // 0x800EBA9C: swc1        $f20, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f20.u32l;
    // 0x800EBAA0: swc1        $f20, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f20.u32l;
    // 0x800EBAA4: swc1        $f20, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->f20.u32l;
    // 0x800EBAA8: swc1        $f20, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->f20.u32l;
    // 0x800EBAAC: swc1        $f20, 0x64($s1)
    MEM_W(0X64, ctx->r17) = ctx->f20.u32l;
    // 0x800EBAB0: sb          $zero, 0x6D($s1)
    MEM_B(0X6D, ctx->r17) = 0;
    // 0x800EBAB4: jal         0x80059B50
    // 0x800EBAB8: swc1        $f0, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f0.u32l;
    func_80059B50(rdram, ctx);
        goto after_2;
    // 0x800EBAB8: swc1        $f0, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f0.u32l;
    after_2:
    // 0x800EBABC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800EBAC0: sw          $v0, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r2;
    // 0x800EBAC4: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x800EBAC8: lwc1        $f4, 0x2C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x800EBACC: lwc1        $f2, 0x28($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X28);
    // 0x800EBAD0: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x800EBAD4: nop

    // 0x800EBAD8: bc1f        L_800EBB14
    if (!c1cs) {
        // 0x800EBADC: nop
    
            goto L_800EBB14;
    }
    // 0x800EBADC: nop

    // 0x800EBAE0: lwc1        $f0, 0x30($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X30);
    // 0x800EBAE4: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800EBAE8: nop

    // 0x800EBAEC: bc1f        L_800EBB28
    if (!c1cs) {
        // 0x800EBAF0: nop
    
            goto L_800EBB28;
    }
    // 0x800EBAF0: nop

    // 0x800EBAF4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800EBAF8: lhu         $v1, 0x8($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X8);
    // 0x800EBAFC: ori         $v1, $v1, 0x400
    ctx->r3 = ctx->r3 | 0X400;
    // 0x800EBB00: sh          $v1, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r3;
    // 0x800EBB04: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x800EBB08: lwc1        $f2, 0x2C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x800EBB0C: j           L_800EBB40
    // 0x800EBB10: nop

        goto L_800EBB40;
    // 0x800EBB10: nop

L_800EBB14:
    // 0x800EBB14: lwc1        $f0, 0x30($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X30);
    // 0x800EBB18: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800EBB1C: nop

    // 0x800EBB20: bc1f        L_800EBB40
    if (!c1cs) {
        // 0x800EBB24: nop
    
            goto L_800EBB40;
    }
    // 0x800EBB24: nop

L_800EBB28:
    // 0x800EBB28: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800EBB2C: lhu         $v1, 0x8($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X8);
    // 0x800EBB30: ori         $v1, $v1, 0x800
    ctx->r3 = ctx->r3 | 0X800;
    // 0x800EBB34: sh          $v1, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r3;
    // 0x800EBB38: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x800EBB3C: lwc1        $f2, 0x30($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X30);
L_800EBB40:
    // 0x800EBB40: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800EBB44: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800EBB48: lwc1        $f0, 0x44($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X44);
    // 0x800EBB4C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800EBB50: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800EBB54: swc1        $f0, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f0.u32l;
    // 0x800EBB58: lhu         $a0, -0x6A8C($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A8C);
    // 0x800EBB5C: jal         0x8003E684
    // 0x800EBB60: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    func_8003E684(rdram, ctx);
        goto after_3;
    // 0x800EBB60: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_3:
    // 0x800EBB64: lui         $a1, 0x800B
    ctx->r5 = S32(0X800B << 16);
    // 0x800EBB68: addiu       $a1, $a1, -0x7768
    ctx->r5 = ADD32(ctx->r5, -0X7768);
    // 0x800EBB6C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800EBB70: jal         0x80059434
    // 0x800EBB74: addiu       $a2, $s1, 0x3C
    ctx->r6 = ADD32(ctx->r17, 0X3C);
    func_80059434(rdram, ctx);
        goto after_4;
    // 0x800EBB74: addiu       $a2, $s1, 0x3C
    ctx->r6 = ADD32(ctx->r17, 0X3C);
    after_4:
    // 0x800EBB78: j           L_800EC0E0
    // 0x800EBB7C: sw          $v0, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->r2;
        goto L_800EC0E0;
    // 0x800EBB7C: sw          $v0, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->r2;
L_800EBB80:
    // 0x800EBB80: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x800EBB84: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // 0x800EBB88: sh          $v1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r3;
    // 0x800EBB8C: lbu         $v0, 0x6D($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6D);
    // 0x800EBB90: bne         $v0, $zero, L_800EBBA4
    if (ctx->r2 != 0) {
        // 0x800EBB94: nop
    
            goto L_800EBBA4;
    }
    // 0x800EBB94: nop

    // 0x800EBB98: lw          $a0, 0x4($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4);
    // 0x800EBB9C: jal         0x80046620
    // 0x800EBBA0: addiu       $a1, $a0, 0x10
    ctx->r5 = ADD32(ctx->r4, 0X10);
    func_80046620(rdram, ctx);
        goto after_5;
    // 0x800EBBA0: addiu       $a1, $a0, 0x10
    ctx->r5 = ADD32(ctx->r4, 0X10);
    after_5:
L_800EBBA4:
    // 0x800EBBA4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800EBBA8: jal         0x8005779C
    // 0x800EBBAC: nop

    func_8005779C(rdram, ctx);
        goto after_6;
    // 0x800EBBAC: nop

    after_6:
    // 0x800EBBB0: j           L_800EC0E4
    // 0x800EBBB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800EC0E4;
    // 0x800EBBB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EBBB8:
    // 0x800EBBB8: lbu         $v0, 0x6D($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6D);
    // 0x800EBBBC: lwc1        $f24, 0x0($s3)
    ctx->f24.u32l = MEM_W(ctx->r19, 0X0);
    // 0x800EBBC0: bne         $v0, $zero, L_800EBE98
    if (ctx->r2 != 0) {
        // 0x800EBBC4: nop
    
            goto L_800EBE98;
    }
    // 0x800EBBC4: nop

    // 0x800EBBC8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800EBBCC: lwc1        $f0, 0x48($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X48);
    // 0x800EBBD0: c.eq.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl == ctx->f20.fl;
    // 0x800EBBD4: nop

    // 0x800EBBD8: bc1t        L_800EBC50
    if (c1cs) {
        // 0x800EBBDC: nop
    
            goto L_800EBC50;
    }
    // 0x800EBBDC: nop

    // 0x800EBBE0: lwc1        $f0, 0x50($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X50);
    // 0x800EBBE4: mul.s       $f0, $f24, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x800EBBE8: lwc1        $f2, 0x4C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X4C);
    // 0x800EBBEC: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800EBBF0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EBBF4: lwc1        $f22, -0x775C($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X775C);
    // 0x800EBBF8: c.lt.s      $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f22.fl < ctx->f2.fl;
    // 0x800EBBFC: nop

    // 0x800EBC00: bc1f        L_800EBC18
    if (!c1cs) {
        // 0x800EBC04: swc1        $f2, 0x4C($s1)
        MEM_W(0X4C, ctx->r17) = ctx->f2.u32l;
            goto L_800EBC18;
    }
    // 0x800EBC04: swc1        $f2, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->f2.u32l;
    // 0x800EBC08: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x800EBC0C: swc1        $f22, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->f22.u32l;
    // 0x800EBC10: lwc1        $f0, 0x7C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X7C);
    // 0x800EBC14: swc1        $f0, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->f0.u32l;
L_800EBC18:
    // 0x800EBC18: lwc1        $f12, 0x4C($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4C);
    // 0x800EBC1C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EBC20: lwc1        $f0, -0x7758($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7758);
    // 0x800EBC24: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800EBC28: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EBC2C: lwc1        $f0, -0x7754($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7754);
    // 0x800EBC30: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800EBC34: jal         0x8002B190
    // 0x800EBC38: nop

    cosf_recomp(rdram, ctx);
        goto after_7;
    // 0x800EBC38: nop

    after_7:
    // 0x800EBC3C: sub.s       $f0, $f22, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f22.fl - ctx->f0.fl;
    // 0x800EBC40: lwc1        $f2, 0x48($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X48);
    // 0x800EBC44: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800EBC48: swc1        $f0, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f0.u32l;
    // 0x800EBC4C: add.s       $f20, $f0, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = ctx->f0.fl + ctx->f20.fl;
L_800EBC50:
    // 0x800EBC50: lwc1        $f0, 0x5C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X5C);
    // 0x800EBC54: mul.s       $f0, $f24, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x800EBC58: lwc1        $f2, 0x58($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X58);
    // 0x800EBC5C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800EBC60: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EBC64: lwc1        $f0, -0x7750($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7750);
    // 0x800EBC68: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800EBC6C: nop

    // 0x800EBC70: bc1f        L_800EBC88
    if (!c1cs) {
        // 0x800EBC74: swc1        $f2, 0x58($s1)
        MEM_W(0X58, ctx->r17) = ctx->f2.u32l;
            goto L_800EBC88;
    }
    // 0x800EBC74: swc1        $f2, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f2.u32l;
    // 0x800EBC78: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EBC7C: lwc1        $f0, -0x774C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X774C);
    // 0x800EBC80: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800EBC84: swc1        $f0, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f0.u32l;
L_800EBC88:
    // 0x800EBC88: lwc1        $f0, 0x58($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X58);
    // 0x800EBC8C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EBC90: lwc1        $f12, -0x7748($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X7748);
    // 0x800EBC94: mul.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800EBC98: jal         0x80033960
    // 0x800EBC9C: nop

    sinf_recomp(rdram, ctx);
        goto after_8;
    // 0x800EBC9C: nop

    after_8:
    // 0x800EBCA0: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x800EBCA4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EBCA8: lwc1        $f4, -0x7744($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7744);
    // 0x800EBCAC: lwc1        $f2, 0x78($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X78);
    // 0x800EBCB0: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800EBCB4: nop

    // 0x800EBCB8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800EBCBC: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
    // 0x800EBCC0: lwc1        $f0, 0x14($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800EBCC4: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x800EBCC8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800EBCCC: jal         0x8006C8F0
    // 0x800EBCD0: swc1        $f0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f0.u32l;
    func_8006C8F0(rdram, ctx);
        goto after_9;
    // 0x800EBCD0: swc1        $f0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f0.u32l;
    after_9:
    // 0x800EBCD4: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800EBCD8: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800EBCDC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800EBCE0: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800EBCE4: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x800EBCE8: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800EBCEC: lwc1        $f2, 0xC($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800EBCF0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800EBCF4: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800EBCF8: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x800EBCFC: lwc1        $f0, 0x8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800EBD00: lwc1        $f2, 0x10($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800EBD04: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800EBD08: mul.s       $f2, $f0, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800EBD0C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x800EBD10: lwc1        $f0, 0x40($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X40);
    // 0x800EBD14: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800EBD18: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800EBD1C: add.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800EBD20: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x800EBD24: nop

    // 0x800EBD28: bc1f        L_800EBECC
    if (!c1cs) {
        // 0x800EBD2C: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800EBECC;
    }
    // 0x800EBD2C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800EBD30: addiu       $a1, $s1, 0x8
    ctx->r5 = ADD32(ctx->r17, 0X8);
    // 0x800EBD34: addiu       $a2, $s1, 0x2C
    ctx->r6 = ADD32(ctx->r17, 0X2C);
    // 0x800EBD38: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    // 0x800EBD3C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800EBD40: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    // 0x800EBD44: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800EBD48: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x800EBD4C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800EBD50: lui         $a3, 0x4190
    ctx->r7 = S32(0X4190 << 16);
    // 0x800EBD54: addiu       $v1, $v1, 0xB78
    ctx->r3 = ADD32(ctx->r3, 0XB78);
    // 0x800EBD58: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800EBD5C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800EBD60: lbu         $v0, 0xF($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XF);
    // 0x800EBD64: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EBD68: lwc1        $f0, -0x7740($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7740);
    // 0x800EBD6C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800EBD70: sb          $v0, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r2;
    // 0x800EBD74: jal         0x800989D8
    // 0x800EBD78: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    func_800989D8(rdram, ctx);
        goto after_10;
    // 0x800EBD78: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_10:
    // 0x800EBD7C: lw          $v0, 0x4($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X4);
    // 0x800EBD80: lw          $v1, 0x6C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X6C);
    // 0x800EBD84: sltiu       $v0, $v1, 0x8
    ctx->r2 = ctx->r3 < 0X8 ? 1 : 0;
    // 0x800EBD88: beq         $v0, $zero, L_800EBE50
    if (ctx->r2 == 0) {
        // 0x800EBD8C: lui         $v0, 0x800B
        ctx->r2 = S32(0X800B << 16);
            goto L_800EBE50;
    }
    // 0x800EBD8C: lui         $v0, 0x800B
    ctx->r2 = S32(0X800B << 16);
    // 0x800EBD90: addiu       $v0, $v0, -0x7738
    ctx->r2 = ADD32(ctx->r2, -0X7738);
    // 0x800EBD94: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800EBD98: addu        $v1, $v1, $v0
    gpr jr_addend_800EBDA0 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800EBD9C: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x800EBDA0: jr          $v0
    // 0x800EBDA4: nop

    switch (jr_addend_800EBDA0 >> 2) {
        case 0: goto L_800EBDA8; break;
        case 1: goto L_800EBDBC; break;
        case 2: goto L_800EBDD0; break;
        case 3: goto L_800EBDE4; break;
        case 4: goto L_800EBDF8; break;
        case 5: goto L_800EBE14; break;
        case 6: goto L_800EBE28; break;
        case 7: goto L_800EBE3C; break;
        default: switch_error(__func__, 0x800EBDA0, 0x800A88C8);
    }
    // 0x800EBDA4: nop

L_800EBDA8:
    // 0x800EBDA8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800EBDAC: addiu       $v1, $v1, 0xB40
    ctx->r3 = ADD32(ctx->r3, 0XB40);
    // 0x800EBDB0: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x800EBDB4: j           L_800EBE4C
    // 0x800EBDB8: ori         $v0, $v0, 0x200
    ctx->r2 = ctx->r2 | 0X200;
        goto L_800EBE4C;
    // 0x800EBDB8: ori         $v0, $v0, 0x200
    ctx->r2 = ctx->r2 | 0X200;
L_800EBDBC:
    // 0x800EBDBC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800EBDC0: addiu       $v1, $v1, 0xB40
    ctx->r3 = ADD32(ctx->r3, 0XB40);
    // 0x800EBDC4: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x800EBDC8: j           L_800EBE4C
    // 0x800EBDCC: ori         $v0, $v0, 0x800
    ctx->r2 = ctx->r2 | 0X800;
        goto L_800EBE4C;
    // 0x800EBDCC: ori         $v0, $v0, 0x800
    ctx->r2 = ctx->r2 | 0X800;
L_800EBDD0:
    // 0x800EBDD0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800EBDD4: addiu       $v1, $v1, 0xB40
    ctx->r3 = ADD32(ctx->r3, 0XB40);
    // 0x800EBDD8: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x800EBDDC: j           L_800EBE4C
    // 0x800EBDE0: ori         $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 | 0X2000;
        goto L_800EBE4C;
    // 0x800EBDE0: ori         $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 | 0X2000;
L_800EBDE4:
    // 0x800EBDE4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800EBDE8: addiu       $v1, $v1, 0xB40
    ctx->r3 = ADD32(ctx->r3, 0XB40);
    // 0x800EBDEC: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x800EBDF0: j           L_800EBE4C
    // 0x800EBDF4: ori         $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 | 0X4000;
        goto L_800EBE4C;
    // 0x800EBDF4: ori         $v0, $v0, 0x4000
    ctx->r2 = ctx->r2 | 0X4000;
L_800EBDF8:
    // 0x800EBDF8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800EBDFC: addiu       $v0, $v0, 0xB40
    ctx->r2 = ADD32(ctx->r2, 0XB40);
    // 0x800EBE00: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800EBE04: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    // 0x800EBE08: or          $v1, $v1, $a0
    ctx->r3 = ctx->r3 | ctx->r4;
    // 0x800EBE0C: j           L_800EBE50
    // 0x800EBE10: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
        goto L_800EBE50;
    // 0x800EBE10: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
L_800EBE14:
    // 0x800EBE14: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800EBE18: addiu       $v1, $v1, 0xB40
    ctx->r3 = ADD32(ctx->r3, 0XB40);
    // 0x800EBE1C: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x800EBE20: j           L_800EBE4C
    // 0x800EBE24: ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
        goto L_800EBE4C;
    // 0x800EBE24: ori         $v0, $v0, 0x400
    ctx->r2 = ctx->r2 | 0X400;
L_800EBE28:
    // 0x800EBE28: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800EBE2C: addiu       $v1, $v1, 0xB40
    ctx->r3 = ADD32(ctx->r3, 0XB40);
    // 0x800EBE30: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x800EBE34: j           L_800EBE4C
    // 0x800EBE38: ori         $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 | 0X1000;
        goto L_800EBE4C;
    // 0x800EBE38: ori         $v0, $v0, 0x1000
    ctx->r2 = ctx->r2 | 0X1000;
L_800EBE3C:
    // 0x800EBE3C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800EBE40: addiu       $v1, $v1, 0xB40
    ctx->r3 = ADD32(ctx->r3, 0XB40);
    // 0x800EBE44: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x800EBE48: ori         $v0, $v0, 0x8000
    ctx->r2 = ctx->r2 | 0X8000;
L_800EBE4C:
    // 0x800EBE4C: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
L_800EBE50:
    // 0x800EBE50: lwc1        $f2, 0x44($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X44);
    // 0x800EBE54: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EBE58: lwc1        $f0, -0x7718($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7718);
    // 0x800EBE5C: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800EBE60: lw          $v1, 0x4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X4);
    // 0x800EBE64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EBE68: sb          $v0, 0x6D($s1)
    MEM_B(0X6D, ctx->r17) = ctx->r2;
    // 0x800EBE6C: swc1        $f2, 0x68($s1)
    MEM_W(0X68, ctx->r17) = ctx->f2.u32l;
    // 0x800EBE70: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800EBE74: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800EBE78: lw          $a0, 0x88($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X88);
    // 0x800EBE7C: lw          $a1, 0x8C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8C);
    // 0x800EBE80: lw          $a2, 0x80($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X80);
    // 0x800EBE84: lw          $a3, 0x84($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X84);
    // 0x800EBE88: jal         0x80065914
    // 0x800EBE8C: nop

    datItemSetObjectiveBooleanCount(rdram, ctx);
        goto after_11;
    // 0x800EBE8C: nop

    after_11:
    // 0x800EBE90: j           L_800EBECC
    // 0x800EBE94: nop

        goto L_800EBECC;
    // 0x800EBE94: nop

L_800EBE98:
    // 0x800EBE98: lwc1        $f0, 0x44($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X44);
    // 0x800EBE9C: lwc1        $f2, 0x68($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X68);
    // 0x800EBEA0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800EBEA4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800EBEA8: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800EBEAC: nop

    // 0x800EBEB0: bc1f        L_800EBECC
    if (!c1cs) {
        // 0x800EBEB4: swc1        $f0, 0x44($s1)
        MEM_W(0X44, ctx->r17) = ctx->f0.u32l;
            goto L_800EBECC;
    }
    // 0x800EBEB4: swc1        $f0, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f0.u32l;
L_800EBEB8:
    // 0x800EBEB8: lhu         $a0, 0x16($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X16);
    // 0x800EBEBC: jal         0x8003ED74
    // 0x800EBEC0: nop

    func_8003ED74(rdram, ctx);
        goto after_12;
    // 0x800EBEC0: nop

    after_12:
    // 0x800EBEC4: j           L_800EC0E4
    // 0x800EBEC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800EC0E4;
    // 0x800EBEC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EBECC:
    // 0x800EBECC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EBED0: lwc1        $f0, -0x7714($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7714);
    // 0x800EBED4: mul.s       $f0, $f24, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x800EBED8: lwc1        $f12, 0x60($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X60);
    // 0x800EBEDC: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x800EBEE0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EBEE4: lwc1        $f14, -0x7710($at)
    ctx->f14.u32l = MEM_W(ctx->r1, -0X7710);
    // 0x800EBEE8: jal         0x8001E20C
    // 0x800EBEEC: swc1        $f12, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->f12.u32l;
    func_8001E20C(rdram, ctx);
        goto after_13;
    // 0x800EBEEC: swc1        $f12, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->f12.u32l;
    after_13:
    // 0x800EBEF0: lwc1        $f2, 0x64($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X64);
    // 0x800EBEF4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EBEF8: lwc1        $f4, -0x770C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X770C);
    // 0x800EBEFC: add.s       $f2, $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f24.fl;
    // 0x800EBF00: swc1        $f0, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->f0.u32l;
    // 0x800EBF04: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x800EBF08: nop

    // 0x800EBF0C: bc1f        L_800EBF18
    if (!c1cs) {
        // 0x800EBF10: swc1        $f2, 0x64($s1)
        MEM_W(0X64, ctx->r17) = ctx->f2.u32l;
            goto L_800EBF18;
    }
    // 0x800EBF10: swc1        $f2, 0x64($s1)
    MEM_W(0X64, ctx->r17) = ctx->f2.u32l;
    // 0x800EBF14: sw          $zero, 0x64($s1)
    MEM_W(0X64, ctx->r17) = 0;
L_800EBF18:
    // 0x800EBF18: jal         0x80047D40
    // 0x800EBF1C: addiu       $a0, $s1, 0x8
    ctx->r4 = ADD32(ctx->r17, 0X8);
    func_80047D40(rdram, ctx);
        goto after_14;
    // 0x800EBF1C: addiu       $a0, $s1, 0x8
    ctx->r4 = ADD32(ctx->r17, 0X8);
    after_14:
    // 0x800EBF20: beq         $v0, $zero, L_800EBF30
    if (ctx->r2 == 0) {
        // 0x800EBF24: nop
    
            goto L_800EBF30;
    }
    // 0x800EBF24: nop

    // 0x800EBF28: j           L_800EC0E0
    // 0x800EBF2C: sb          $zero, 0x6C($s1)
    MEM_B(0X6C, ctx->r17) = 0;
        goto L_800EC0E0;
    // 0x800EBF2C: sb          $zero, 0x6C($s1)
    MEM_B(0X6C, ctx->r17) = 0;
L_800EBF30:
    // 0x800EBF30: lbu         $v0, 0x6C($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X6C);
    // 0x800EBF34: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800EBF38: sb          $v0, 0x6C($s1)
    MEM_B(0X6C, ctx->r17) = ctx->r2;
    // 0x800EBF3C: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x800EBF40: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x800EBF44: slti        $v0, $v0, 0x15
    ctx->r2 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x800EBF48: bne         $v0, $zero, L_800EC0E4
    if (ctx->r2 != 0) {
        // 0x800EBF4C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800EC0E4;
    }
    // 0x800EBF4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EBF50: j           L_800EBEB8
    // 0x800EBF54: nop

        goto L_800EBEB8;
    // 0x800EBF54: nop

L_800EBF58:
    // 0x800EBF58: lw          $v0, 0x38($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X38);
    // 0x800EBF5C: lw          $s0, 0x3C($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X3C);
    // 0x800EBF60: addiu       $s2, $v0, 0x1C
    ctx->r18 = ADD32(ctx->r2, 0X1C);
    // 0x800EBF64: jal         0x8001CA50
    // 0x800EBF68: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_8001CA50(rdram, ctx);
        goto after_15;
    // 0x800EBF68: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_15:
    // 0x800EBF6C: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x800EBF70: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800EBF74: beq         $v0, $zero, L_800EBFA8
    if (ctx->r2 == 0) {
        // 0x800EBF78: nop
    
            goto L_800EBFA8;
    }
    // 0x800EBF78: nop

    // 0x800EBF7C: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800EBF80: lwc1        $f2, 0x58($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800EBF84: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800EBF88: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x800EBF8C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800EBF90: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800EBF94: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800EBF98: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800EBF9C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800EBFA0: jal         0x8001CA90
    // 0x800EBFA4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_8001CA90(rdram, ctx);
        goto after_16;
    // 0x800EBFA4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_16:
L_800EBFA8:
    // 0x800EBFA8: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x800EBFAC: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x800EBFB0: beq         $v0, $zero, L_800EBFCC
    if (ctx->r2 == 0) {
        // 0x800EBFB4: nop
    
            goto L_800EBFCC;
    }
    // 0x800EBFB4: nop

    // 0x800EBFB8: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    // 0x800EBFBC: lw          $a2, 0x60($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X60);
    // 0x800EBFC0: lw          $a3, 0x64($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X64);
    // 0x800EBFC4: jal         0x8001CB04
    // 0x800EBFC8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_8001CB04(rdram, ctx);
        goto after_17;
    // 0x800EBFC8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_17:
L_800EBFCC:
    // 0x800EBFCC: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x800EBFD0: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x800EBFD4: beq         $v0, $zero, L_800EBFE4
    if (ctx->r2 == 0) {
        // 0x800EBFD8: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_800EBFE4;
    }
    // 0x800EBFD8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800EBFDC: jal         0x8001DAEC
    // 0x800EBFE0: addiu       $a1, $s0, 0x68
    ctx->r5 = ADD32(ctx->r16, 0X68);
    func_8001DAEC(rdram, ctx);
        goto after_18;
    // 0x800EBFE0: addiu       $a1, $s0, 0x68
    ctx->r5 = ADD32(ctx->r16, 0X68);
    after_18:
L_800EBFE4:
    // 0x800EBFE4: lw          $a1, 0x60($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X60);
    // 0x800EBFE8: jal         0x8001CCCC
    // 0x800EBFEC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_8001CCCC(rdram, ctx);
        goto after_19;
    // 0x800EBFEC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_19:
    // 0x800EBFF0: lwc1        $f12, 0x64($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X64);
    // 0x800EBFF4: add.s       $f12, $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x800EBFF8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EBFFC: lwc1        $f0, -0x7708($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7708);
    // 0x800EC000: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800EC004: jal         0x80033960
    // 0x800EC008: nop

    sinf_recomp(rdram, ctx);
        goto after_20;
    // 0x800EC008: nop

    after_20:
    // 0x800EC00C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EC010: lwc1        $f2, -0x7704($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7704);
    // 0x800EC014: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800EC018: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800EC01C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800EC020: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800EC024: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800EC028: jal         0x8001CA90
    // 0x800EC02C: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    func_8001CA90(rdram, ctx);
        goto after_21;
    // 0x800EC02C: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_21:
    // 0x800EC030: lw          $a0, 0x4C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4C);
    // 0x800EC034: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x800EC038: andi        $v1, $a0, 0x9
    ctx->r3 = ctx->r4 & 0X9;
    // 0x800EC03C: bne         $v1, $v0, L_800EC07C
    if (ctx->r3 != ctx->r2) {
        // 0x800EC040: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_800EC07C;
    }
    // 0x800EC040: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800EC044: lwc1        $f2, 0x78($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800EC048: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800EC04C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800EC050: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800EC054: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800EC058: lwc1        $f2, 0x7C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x800EC05C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800EC060: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800EC064: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800EC068: lwc1        $f2, 0x80($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X80);
    // 0x800EC06C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800EC070: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800EC074: j           L_800EC0AC
    // 0x800EC078: nop

        goto L_800EC0AC;
    // 0x800EC078: nop

L_800EC07C:
    // 0x800EC07C: bne         $v1, $v0, L_800EC098
    if (ctx->r3 != ctx->r2) {
        // 0x800EC080: andi        $v0, $a0, 0x1
        ctx->r2 = ctx->r4 & 0X1;
            goto L_800EC098;
    }
    // 0x800EC080: andi        $v0, $a0, 0x1
    ctx->r2 = ctx->r4 & 0X1;
    // 0x800EC084: lw          $a1, 0x78($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X78);
    // 0x800EC088: lw          $a2, 0x7C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X7C);
    // 0x800EC08C: lw          $a3, 0x80($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X80);
    // 0x800EC090: j           L_800EC0AC
    // 0x800EC094: nop

        goto L_800EC0AC;
    // 0x800EC094: nop

L_800EC098:
    // 0x800EC098: beql        $v0, $zero, L_800EC0B8
    if (ctx->r2 == 0) {
        // 0x800EC09C: addiu       $s0, $s1, 0x8
        ctx->r16 = ADD32(ctx->r17, 0X8);
            goto L_800EC0B8;
    }
    goto skip_0;
    // 0x800EC09C: addiu       $s0, $s1, 0x8
    ctx->r16 = ADD32(ctx->r17, 0X8);
    skip_0:
    // 0x800EC0A0: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    // 0x800EC0A4: lw          $a2, 0x54($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X54);
    // 0x800EC0A8: lw          $a3, 0x58($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X58);
L_800EC0AC:
    // 0x800EC0AC: jal         0x8001CA90
    // 0x800EC0B0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    func_8001CA90(rdram, ctx);
        goto after_22;
    // 0x800EC0B0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_22:
    // 0x800EC0B4: addiu       $s0, $s1, 0x8
    ctx->r16 = ADD32(ctx->r17, 0X8);
L_800EC0B8:
    // 0x800EC0B8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800EC0BC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800EC0C0: lw          $a2, 0x44($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X44);
    // 0x800EC0C4: jal         0x80059B50
    // 0x800EC0C8: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    func_80059B50(rdram, ctx);
        goto after_23;
    // 0x800EC0C8: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_23:
    // 0x800EC0CC: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x800EC0D0: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x800EC0D4: lw          $a3, 0x40($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X40);
    // 0x800EC0D8: jal         0x80057C8C
    // 0x800EC0DC: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    func_80057C8C(rdram, ctx);
        goto after_24;
    // 0x800EC0DC: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_24:
L_800EC0E0:
    // 0x800EC0E0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EC0E4:
    // 0x800EC0E4: lw          $ra, 0x48($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X48);
    // 0x800EC0E8: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x800EC0EC: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x800EC0F0: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x800EC0F4: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800EC0F8: ldc1        $f24, 0x60($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X60);
    // 0x800EC0FC: ldc1        $f22, 0x58($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X58);
    // 0x800EC100: ldc1        $f20, 0x50($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X50);
    // 0x800EC104: jr          $ra
    // 0x800EC108: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800EC108: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void fake_func_800EC10C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_800EC110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EC110: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800EC114: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800EC118: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x800EC11C: lw          $v0, -0x3F30($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X3F30);
    // 0x800EC120: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800EC124: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x800EC128: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800EC12C: bne         $v0, $zero, L_800EC18C
    if (ctx->r2 != 0) {
        // 0x800EC130: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_800EC18C;
    }
    // 0x800EC130: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800EC134: addiu       $a0, $zero, 0x6C0
    ctx->r4 = ADD32(0, 0X6C0);
    // 0x800EC138: jal         0x80001ACC
    // 0x800EC13C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x800EC13C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x800EC140: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800EC144: bne         $v1, $zero, L_800EC154
    if (ctx->r3 != 0) {
        // 0x800EC148: sw          $v1, -0x3F30($s1)
        MEM_W(-0X3F30, ctx->r17) = ctx->r3;
            goto L_800EC154;
    }
    // 0x800EC148: sw          $v1, -0x3F30($s1)
    MEM_W(-0X3F30, ctx->r17) = ctx->r3;
    // 0x800EC14C: j           L_800EC370
    // 0x800EC150: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_800EC370;
    // 0x800EC150: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800EC154:
    // 0x800EC154: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800EC158: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800EC15C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800EC160: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800EC164: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x800EC168: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x800EC16C: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
L_800EC170:
    // 0x800EC170: lw          $v0, -0x3F30($a1)
    ctx->r2 = MEM_W(ctx->r5, -0X3F30);
    // 0x800EC174: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800EC178: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800EC17C: sb          $a0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r4;
    // 0x800EC180: slti        $v0, $s0, 0x4
    ctx->r2 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x800EC184: bne         $v0, $zero, L_800EC170
    if (ctx->r2 != 0) {
        // 0x800EC188: nop
    
            goto L_800EC170;
    }
    // 0x800EC188: nop

L_800EC18C:
    // 0x800EC18C: lui         $v1, 0x4C8F
    ctx->r3 = S32(0X4C8F << 16);
    // 0x800EC190: ori         $v1, $v1, 0x8D29
    ctx->r3 = ctx->r3 | 0X8D29;
    // 0x800EC194: addiu       $v0, $s2, 0x1AB
    ctx->r2 = ADD32(ctx->r18, 0X1AB);
    // 0x800EC198: srl         $v0, $v0, 2
    ctx->r2 = S32(U32(ctx->r2) >> 2);
    // 0x800EC19C: multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800EC1A0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EC1A4: lw          $a1, -0x3F30($v0)
    ctx->r5 = MEM_W(ctx->r2, -0X3F30);
    // 0x800EC1A8: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800EC1AC: mfhi        $t4
    ctx->r12 = hi;
    // 0x800EC1B0: beq         $a1, $zero, L_800EC254
    if (ctx->r5 == 0) {
        // 0x800EC1B4: srl         $s0, $t4, 5
        ctx->r16 = S32(U32(ctx->r12) >> 5);
            goto L_800EC254;
    }
    // 0x800EC1B4: srl         $s0, $t4, 5
    ctx->r16 = S32(U32(ctx->r12) >> 5);
    // 0x800EC1B8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800EC1BC: subu        $t3, $v0, $s0
    ctx->r11 = SUB32(ctx->r2, ctx->r16);
    // 0x800EC1C0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_800EC1C4:
    // 0x800EC1C4: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x800EC1C8: slt         $v0, $v0, $s0
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800EC1CC: bnel        $v0, $zero, L_800EC248
    if (ctx->r2 != 0) {
        // 0x800EC1D0: addu        $s1, $a1, $zero
        ctx->r17 = ADD32(ctx->r5, 0);
            goto L_800EC248;
    }
    goto skip_0;
    // 0x800EC1D0: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    skip_0:
    // 0x800EC1D4: blez        $t3, L_800EC244
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800EC1D8: addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
            goto L_800EC244;
    }
    // 0x800EC1D8: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x800EC1DC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800EC1E0: subu        $t1, $v0, $s0
    ctx->r9 = SUB32(ctx->r2, ctx->r16);
    // 0x800EC1E4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
L_800EC1E8:
    // 0x800EC1E8: addu        $v0, $a1, $t0
    ctx->r2 = ADD32(ctx->r5, ctx->r8);
    // 0x800EC1EC: lbu         $v0, 0x1($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1);
    // 0x800EC1F0: beql        $v0, $zero, L_800EC238
    if (ctx->r2 == 0) {
        // 0x800EC1F4: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_800EC238;
    }
    goto skip_1;
    // 0x800EC1F4: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    skip_1:
    // 0x800EC1F8: addu        $v1, $t0, $zero
    ctx->r3 = ADD32(ctx->r8, 0);
    // 0x800EC1FC: slt         $v0, $t0, $a2
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800EC200: beq         $v0, $zero, L_800EC22C
    if (ctx->r2 == 0) {
        // 0x800EC204: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800EC22C;
    }
    // 0x800EC204: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800EC208: addu        $a3, $a2, $zero
    ctx->r7 = ADD32(ctx->r6, 0);
    // 0x800EC20C: addu        $v0, $a1, $v1
    ctx->r2 = ADD32(ctx->r5, ctx->r3);
L_800EC210:
    // 0x800EC210: lbu         $v0, 0x1($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1);
    // 0x800EC214: beql        $v0, $t2, L_800EC21C
    if (ctx->r2 == ctx->r10) {
        // 0x800EC218: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800EC21C;
    }
    goto skip_2;
    // 0x800EC218: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_2:
L_800EC21C:
    // 0x800EC21C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800EC220: slt         $v0, $v1, $a3
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800EC224: bne         $v0, $zero, L_800EC210
    if (ctx->r2 != 0) {
        // 0x800EC228: addu        $v0, $a1, $v1
        ctx->r2 = ADD32(ctx->r5, ctx->r3);
            goto L_800EC210;
    }
    // 0x800EC228: addu        $v0, $a1, $v1
    ctx->r2 = ADD32(ctx->r5, ctx->r3);
L_800EC22C:
    // 0x800EC22C: beq         $a0, $s0, L_800EC29C
    if (ctx->r4 == ctx->r16) {
        // 0x800EC230: addu        $a0, $t0, $s0
        ctx->r4 = ADD32(ctx->r8, ctx->r16);
            goto L_800EC29C;
    }
    // 0x800EC230: addu        $a0, $t0, $s0
    ctx->r4 = ADD32(ctx->r8, ctx->r16);
    // 0x800EC234: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_800EC238:
    // 0x800EC238: slt         $v0, $t0, $t1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800EC23C: bne         $v0, $zero, L_800EC1E8
    if (ctx->r2 != 0) {
        // 0x800EC240: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_800EC1E8;
    }
    // 0x800EC240: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_800EC244:
    // 0x800EC244: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
L_800EC248:
    // 0x800EC248: lw          $a1, 0xC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0XC);
    // 0x800EC24C: bne         $a1, $zero, L_800EC1C4
    if (ctx->r5 != 0) {
        // 0x800EC250: nop
    
            goto L_800EC1C4;
    }
    // 0x800EC250: nop

L_800EC254:
    // 0x800EC254: addiu       $a0, $zero, 0x6C0
    ctx->r4 = ADD32(0, 0X6C0);
    // 0x800EC258: jal         0x80001ACC
    // 0x800EC25C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    rs_malloc(rdram, ctx);
        goto after_1;
    // 0x800EC25C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x800EC260: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800EC264: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800EC268: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x800EC26C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800EC270: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x800EC274: addu        $v0, $a1, $v1
    ctx->r2 = ADD32(ctx->r5, ctx->r3);
L_800EC278:
    // 0x800EC278: sb          $a0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r4;
    // 0x800EC27C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800EC280: bgez        $v1, L_800EC278
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800EC284: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_800EC278;
    }
    // 0x800EC284: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800EC288: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x800EC28C: sw          $zero, 0xC($a1)
    MEM_W(0XC, ctx->r5) = 0;
    // 0x800EC290: sw          $s1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r17;
    // 0x800EC294: sw          $a1, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r5;
    // 0x800EC298: addu        $a0, $t0, $s0
    ctx->r4 = ADD32(ctx->r8, ctx->r16);
L_800EC29C:
    // 0x800EC29C: slt         $v0, $t0, $a0
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800EC2A0: beq         $v0, $zero, L_800EC2C0
    if (ctx->r2 == 0) {
        // 0x800EC2A4: addu        $v1, $t0, $zero
        ctx->r3 = ADD32(ctx->r8, 0);
            goto L_800EC2C0;
    }
    // 0x800EC2A4: addu        $v1, $t0, $zero
    ctx->r3 = ADD32(ctx->r8, 0);
    // 0x800EC2A8: addu        $v0, $a1, $v1
    ctx->r2 = ADD32(ctx->r5, ctx->r3);
L_800EC2AC:
    // 0x800EC2AC: sb          $zero, 0x1($v0)
    MEM_B(0X1, ctx->r2) = 0;
    // 0x800EC2B0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800EC2B4: slt         $v0, $v1, $a0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800EC2B8: bne         $v0, $zero, L_800EC2AC
    if (ctx->r2 != 0) {
        // 0x800EC2BC: addu        $v0, $a1, $v1
        ctx->r2 = ADD32(ctx->r5, ctx->r3);
            goto L_800EC2AC;
    }
    // 0x800EC2BC: addu        $v0, $a1, $v1
    ctx->r2 = ADD32(ctx->r5, ctx->r3);
L_800EC2C0:
    // 0x800EC2C0: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x800EC2C4: subu        $v0, $v0, $s0
    ctx->r2 = SUB32(ctx->r2, ctx->r16);
    // 0x800EC2C8: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x800EC2CC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800EC2D0: bne         $v0, $zero, L_800EC344
    if (ctx->r2 != 0) {
        // 0x800EC2D4: sll         $v0, $t0, 3
        ctx->r2 = S32(ctx->r8 << 3);
            goto L_800EC344;
    }
    // 0x800EC2D4: sll         $v0, $t0, 3
    ctx->r2 = S32(ctx->r8 << 3);
    // 0x800EC2D8: lw          $v1, 0x8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X8);
    // 0x800EC2DC: beq         $v1, $zero, L_800EC2EC
    if (ctx->r3 == 0) {
        // 0x800EC2E0: nop
    
            goto L_800EC2EC;
    }
    // 0x800EC2E0: nop

    // 0x800EC2E4: lw          $v0, 0xC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XC);
    // 0x800EC2E8: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
L_800EC2EC:
    // 0x800EC2EC: lw          $v1, 0xC($a1)
    ctx->r3 = MEM_W(ctx->r5, 0XC);
    // 0x800EC2F0: beql        $v1, $zero, L_800EC304
    if (ctx->r3 == 0) {
        // 0x800EC2F4: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_800EC304;
    }
    goto skip_3;
    // 0x800EC2F4: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    skip_3:
    // 0x800EC2F8: lw          $v0, 0x8($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8);
    // 0x800EC2FC: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x800EC300: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
L_800EC304:
    // 0x800EC304: lw          $v0, -0x3F30($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X3F30);
    // 0x800EC308: bne         $a1, $v0, L_800EC31C
    if (ctx->r5 != ctx->r2) {
        // 0x800EC30C: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800EC31C;
    }
    // 0x800EC30C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EC310: lw          $v0, 0xC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XC);
    // 0x800EC314: sw          $v0, -0x3F30($v1)
    MEM_W(-0X3F30, ctx->r3) = ctx->r2;
    // 0x800EC318: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_800EC31C:
    // 0x800EC31C: lw          $v0, -0x3F2C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3F2C);
    // 0x800EC320: beq         $v0, $zero, L_800EC334
    if (ctx->r2 == 0) {
        // 0x800EC324: sw          $zero, 0x8($a1)
        MEM_W(0X8, ctx->r5) = 0;
            goto L_800EC334;
    }
    // 0x800EC324: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
    // 0x800EC328: sw          $v0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r2;
    // 0x800EC32C: j           L_800EC338
    // 0x800EC330: sw          $a1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r5;
        goto L_800EC338;
    // 0x800EC330: sw          $a1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r5;
L_800EC334:
    // 0x800EC334: sw          $zero, 0xC($a1)
    MEM_W(0XC, ctx->r5) = 0;
L_800EC338:
    // 0x800EC338: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EC33C: sw          $a1, -0x3F2C($v0)
    MEM_W(-0X3F2C, ctx->r2) = ctx->r5;
    // 0x800EC340: sll         $v0, $t0, 3
    ctx->r2 = S32(ctx->r8 << 3);
L_800EC344:
    // 0x800EC344: subu        $v0, $v0, $t0
    ctx->r2 = SUB32(ctx->r2, ctx->r8);
    // 0x800EC348: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800EC34C: subu        $v0, $v0, $t0
    ctx->r2 = SUB32(ctx->r2, ctx->r8);
    // 0x800EC350: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800EC354: subu        $v0, $v0, $t0
    ctx->r2 = SUB32(ctx->r2, ctx->r8);
    // 0x800EC358: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800EC35C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800EC360: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x800EC364: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x800EC368: sb          $s0, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r16;
    // 0x800EC36C: sb          $t0, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r8;
L_800EC370:
    // 0x800EC370: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800EC374: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800EC378: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800EC37C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800EC380: jr          $ra
    // 0x800EC384: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800EC384: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800EC388(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EC388: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EC38C: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x800EC390: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800EC394: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x800EC398: lbu         $a3, 0x4($a2)
    ctx->r7 = MEM_BU(ctx->r6, 0X4);
    // 0x800EC39C: lbu         $a1, 0x0($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X0);
    // 0x800EC3A0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800EC3A4: addu        $v1, $a1, $a3
    ctx->r3 = ADD32(ctx->r5, ctx->r7);
    // 0x800EC3A8: bne         $v1, $v0, L_800EC414
    if (ctx->r3 != ctx->r2) {
        // 0x800EC3AC: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_800EC414;
    }
    // 0x800EC3AC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800EC3B0: bne         $a1, $zero, L_800EC3C4
    if (ctx->r5 != 0) {
        // 0x800EC3B4: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800EC3C4;
    }
    // 0x800EC3B4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EC3B8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EC3BC: j           L_800EC3C8
    // 0x800EC3C0: addiu       $a1, $v0, -0x3F2C
    ctx->r5 = ADD32(ctx->r2, -0X3F2C);
        goto L_800EC3C8;
    // 0x800EC3C0: addiu       $a1, $v0, -0x3F2C
    ctx->r5 = ADD32(ctx->r2, -0X3F2C);
L_800EC3C4:
    // 0x800EC3C4: addiu       $a1, $v0, -0x3F30
    ctx->r5 = ADD32(ctx->r2, -0X3F30);
L_800EC3C8:
    // 0x800EC3C8: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x800EC3CC: beq         $v1, $zero, L_800EC3DC
    if (ctx->r3 == 0) {
        // 0x800EC3D0: nop
    
            goto L_800EC3DC;
    }
    // 0x800EC3D0: nop

    // 0x800EC3D4: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x800EC3D8: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
L_800EC3DC:
    // 0x800EC3DC: lw          $v1, 0xC($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XC);
    // 0x800EC3E0: beq         $v1, $zero, L_800EC3F0
    if (ctx->r3 == 0) {
        // 0x800EC3E4: nop
    
            goto L_800EC3F0;
    }
    // 0x800EC3E4: nop

    // 0x800EC3E8: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x800EC3EC: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
L_800EC3F0:
    // 0x800EC3F0: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800EC3F4: bne         $a0, $v0, L_800EC404
    if (ctx->r4 != ctx->r2) {
        // 0x800EC3F8: nop
    
            goto L_800EC404;
    }
    // 0x800EC3F8: nop

    // 0x800EC3FC: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x800EC400: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
L_800EC404:
    // 0x800EC404: jal         0x80001C98
    // 0x800EC408: nop

    rs_free(rdram, ctx);
        goto after_0;
    // 0x800EC408: nop

    after_0:
    // 0x800EC40C: j           L_800EC4CC
    // 0x800EC410: nop

        goto L_800EC4CC;
    // 0x800EC410: nop

L_800EC414:
    // 0x800EC414: sltiu       $v0, $a1, 0x1
    ctx->r2 = ctx->r5 < 0X1 ? 1 : 0;
    // 0x800EC418: beq         $a3, $zero, L_800EC448
    if (ctx->r7 == 0) {
        // 0x800EC41C: addu        $t0, $v0, $zero
        ctx->r8 = ADD32(ctx->r2, 0);
            goto L_800EC448;
    }
    // 0x800EC41C: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x800EC420: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_800EC424:
    // 0x800EC424: lbu         $v0, 0x5($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X5);
    // 0x800EC428: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800EC42C: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x800EC430: sb          $a1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r5;
    // 0x800EC434: lbu         $v0, 0x4($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X4);
    // 0x800EC438: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800EC43C: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800EC440: bne         $v0, $zero, L_800EC424
    if (ctx->r2 != 0) {
        // 0x800EC444: nop
    
            goto L_800EC424;
    }
    // 0x800EC444: nop

L_800EC448:
    // 0x800EC448: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800EC44C: lbu         $v1, 0x4($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X4);
    // 0x800EC450: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800EC454: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x800EC458: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EC45C: bne         $t0, $v0, L_800EC4CC
    if (ctx->r8 != ctx->r2) {
        // 0x800EC460: nop
    
            goto L_800EC4CC;
    }
    // 0x800EC460: nop

    // 0x800EC464: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x800EC468: beq         $v1, $zero, L_800EC478
    if (ctx->r3 == 0) {
        // 0x800EC46C: nop
    
            goto L_800EC478;
    }
    // 0x800EC46C: nop

    // 0x800EC470: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x800EC474: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
L_800EC478:
    // 0x800EC478: lw          $v1, 0xC($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XC);
    // 0x800EC47C: beql        $v1, $zero, L_800EC490
    if (ctx->r3 == 0) {
        // 0x800EC480: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_800EC490;
    }
    goto skip_0;
    // 0x800EC480: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    skip_0:
    // 0x800EC484: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x800EC488: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
    // 0x800EC48C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
L_800EC490:
    // 0x800EC490: lw          $v0, -0x3F2C($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X3F2C);
    // 0x800EC494: bnel        $a0, $v0, L_800EC4A8
    if (ctx->r4 != ctx->r2) {
        // 0x800EC498: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_800EC4A8;
    }
    goto skip_1;
    // 0x800EC498: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    skip_1:
    // 0x800EC49C: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x800EC4A0: sw          $v0, -0x3F2C($v1)
    MEM_W(-0X3F2C, ctx->r3) = ctx->r2;
    // 0x800EC4A4: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
L_800EC4A8:
    // 0x800EC4A8: lw          $v0, -0x3F30($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X3F30);
    // 0x800EC4AC: beq         $v0, $zero, L_800EC4C4
    if (ctx->r2 == 0) {
        // 0x800EC4B0: sw          $zero, 0x8($a0)
        MEM_W(0X8, ctx->r4) = 0;
            goto L_800EC4C4;
    }
    // 0x800EC4B0: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x800EC4B4: sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
    // 0x800EC4B8: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
    // 0x800EC4BC: j           L_800EC4CC
    // 0x800EC4C0: sw          $a0, -0x3F30($v1)
    MEM_W(-0X3F30, ctx->r3) = ctx->r4;
        goto L_800EC4CC;
    // 0x800EC4C0: sw          $a0, -0x3F30($v1)
    MEM_W(-0X3F30, ctx->r3) = ctx->r4;
L_800EC4C4:
    // 0x800EC4C4: sw          $a0, -0x3F30($v1)
    MEM_W(-0X3F30, ctx->r3) = ctx->r4;
    // 0x800EC4C8: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
L_800EC4CC:
    // 0x800EC4CC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800EC4D0: jr          $ra
    // 0x800EC4D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800EC4D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800EC4D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EC4D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EC4DC: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800EC4E0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EC4E4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800EC4E8: sw          $zero, -0x3F30($v1)
    MEM_W(-0X3F30, ctx->r3) = 0;
    // 0x800EC4EC: sw          $zero, -0x3F2C($v0)
    MEM_W(-0X3F2C, ctx->r2) = 0;
    // 0x800EC4F0: jal         0x800DFB78
    // 0x800EC4F4: sw          $zero, -0x3F30($v1)
    MEM_W(-0X3F30, ctx->r3) = 0;
    func_800DFB78(rdram, ctx);
        goto after_0;
    // 0x800EC4F4: sw          $zero, -0x3F30($v1)
    MEM_W(-0X3F30, ctx->r3) = 0;
    after_0:
    // 0x800EC4F8: jal         0x800EB984
    // 0x800EC4FC: nop

    func_800EB984(rdram, ctx);
        goto after_1;
    // 0x800EC4FC: nop

    after_1:
    // 0x800EC500: jal         0x800820E4
    // 0x800EC504: nop

    func_800820E4(rdram, ctx);
        goto after_2;
    // 0x800EC504: nop

    after_2:
    // 0x800EC508: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800EC50C: jr          $ra
    // 0x800EC510: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800EC510: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800EC514(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EC514: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800EC518: lw          $v0, -0x3F30($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X3F30);
    // 0x800EC51C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EC520: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EC524: beq         $v0, $zero, L_800EC54C
    if (ctx->r2 == 0) {
        // 0x800EC528: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_800EC54C;
    }
    // 0x800EC528: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800EC52C: addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
L_800EC530:
    // 0x800EC530: lw          $a0, -0x3F30($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X3F30);
    // 0x800EC534: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x800EC538: jal         0x80001C98
    // 0x800EC53C: sw          $v0, -0x3F30($s0)
    MEM_W(-0X3F30, ctx->r16) = ctx->r2;
    rs_free(rdram, ctx);
        goto after_0;
    // 0x800EC53C: sw          $v0, -0x3F30($s0)
    MEM_W(-0X3F30, ctx->r16) = ctx->r2;
    after_0:
    // 0x800EC540: lw          $v0, -0x3F30($s0)
    ctx->r2 = MEM_W(ctx->r16, -0X3F30);
    // 0x800EC544: bne         $v0, $zero, L_800EC530
    if (ctx->r2 != 0) {
        // 0x800EC548: nop
    
            goto L_800EC530;
    }
    // 0x800EC548: nop

L_800EC54C:
    // 0x800EC54C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800EC550: lw          $v0, -0x3F2C($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X3F2C);
    // 0x800EC554: beq         $v0, $zero, L_800EC578
    if (ctx->r2 == 0) {
        // 0x800EC558: addu        $s0, $v1, $zero
        ctx->r16 = ADD32(ctx->r3, 0);
            goto L_800EC578;
    }
    // 0x800EC558: addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
L_800EC55C:
    // 0x800EC55C: lw          $a0, -0x3F2C($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X3F2C);
    // 0x800EC560: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x800EC564: jal         0x80001C98
    // 0x800EC568: sw          $v0, -0x3F2C($s0)
    MEM_W(-0X3F2C, ctx->r16) = ctx->r2;
    rs_free(rdram, ctx);
        goto after_1;
    // 0x800EC568: sw          $v0, -0x3F2C($s0)
    MEM_W(-0X3F2C, ctx->r16) = ctx->r2;
    after_1:
    // 0x800EC56C: lw          $v0, -0x3F2C($s0)
    ctx->r2 = MEM_W(ctx->r16, -0X3F2C);
    // 0x800EC570: bne         $v0, $zero, L_800EC55C
    if (ctx->r2 != 0) {
        // 0x800EC574: nop
    
            goto L_800EC55C;
    }
    // 0x800EC574: nop

L_800EC578:
    // 0x800EC578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EC57C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800EC580: jr          $ra
    // 0x800EC584: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800EC584: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800EC588(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EC588: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800EC58C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800EC590: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800EC594: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800EC598: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x800EC59C: addiu       $a0, $a1, 0x1AC
    ctx->r4 = ADD32(ctx->r5, 0X1AC);
    // 0x800EC5A0: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800EC5A4: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x800EC5A8: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x800EC5AC: addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // 0x800EC5B0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800EC5B4: jal         0x800EC110
    // 0x800EC5B8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    func_800EC110(rdram, ctx);
        goto after_0;
    // 0x800EC5B8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x800EC5BC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800EC5C0: beq         $s0, $zero, L_800EC660
    if (ctx->r16 == 0) {
        // 0x800EC5C4: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_800EC660;
    }
    // 0x800EC5C4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800EC5C8: sw          $s0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r16;
    // 0x800EC5CC: lhu         $v1, 0x16($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X16);
    // 0x800EC5D0: sb          $zero, 0x1A4($s0)
    MEM_B(0X1A4, ctx->r16) = 0;
    // 0x800EC5D4: sb          $zero, 0x1A6($s0)
    MEM_B(0X1A6, ctx->r16) = 0;
    // 0x800EC5D8: sb          $zero, 0x1A5($s0)
    MEM_B(0X1A5, ctx->r16) = 0;
    // 0x800EC5DC: sh          $v0, 0x19A($s0)
    MEM_H(0X19A, ctx->r16) = ctx->r2;
    // 0x800EC5E0: bne         $s3, $zero, L_800EC5F0
    if (ctx->r19 != 0) {
        // 0x800EC5E4: sh          $v1, 0x198($s0)
        MEM_H(0X198, ctx->r16) = ctx->r3;
            goto L_800EC5F0;
    }
    // 0x800EC5E4: sh          $v1, 0x198($s0)
    MEM_H(0X198, ctx->r16) = ctx->r3;
    // 0x800EC5E8: j           L_800EC608
    // 0x800EC5EC: sb          $zero, 0x1A7($s0)
    MEM_B(0X1A7, ctx->r16) = 0;
        goto L_800EC608;
    // 0x800EC5EC: sb          $zero, 0x1A7($s0)
    MEM_B(0X1A7, ctx->r16) = 0;
L_800EC5F0:
    // 0x800EC5F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EC5F4: sb          $v0, 0x1A7($s0)
    MEM_B(0X1A7, ctx->r16) = ctx->r2;
    // 0x800EC5F8: lw          $v0, 0x14($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X14);
    // 0x800EC5FC: sw          $v0, 0x19C($s0)
    MEM_W(0X19C, ctx->r16) = ctx->r2;
    // 0x800EC600: lw          $v0, 0x10($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X10);
    // 0x800EC604: sw          $v0, 0x1A0($s0)
    MEM_W(0X1A0, ctx->r16) = ctx->r2;
L_800EC608:
    // 0x800EC608: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800EC60C: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x800EC610: sb          $zero, 0x112($s0)
    MEM_B(0X112, ctx->r16) = 0;
    // 0x800EC614: sh          $zero, 0x110($s0)
    MEM_H(0X110, ctx->r16) = 0;
    // 0x800EC618: sb          $zero, 0x134($s0)
    MEM_B(0X134, ctx->r16) = 0;
    // 0x800EC61C: sb          $zero, 0x135($s0)
    MEM_B(0X135, ctx->r16) = 0;
    // 0x800EC620: sw          $zero, 0x128($s0)
    MEM_W(0X128, ctx->r16) = 0;
    // 0x800EC624: sb          $v0, 0x12C($s0)
    MEM_B(0X12C, ctx->r16) = ctx->r2;
    // 0x800EC628: jal         0x8003E5F8
    // 0x800EC62C: sb          $v0, 0x12D($s0)
    MEM_B(0X12D, ctx->r16) = ctx->r2;
    func_8003E5F8(rdram, ctx);
        goto after_1;
    // 0x800EC62C: sb          $v0, 0x12D($s0)
    MEM_B(0X12D, ctx->r16) = ctx->r2;
    after_1:
    // 0x800EC630: addiu       $a1, $s0, 0x1AC
    ctx->r5 = ADD32(ctx->r16, 0X1AC);
    // 0x800EC634: sh          $v0, 0x130($s0)
    MEM_H(0X130, ctx->r16) = ctx->r2;
    // 0x800EC638: sw          $zero, 0x150($s0)
    MEM_W(0X150, ctx->r16) = 0;
    // 0x800EC63C: sw          $zero, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = 0;
    // 0x800EC640: sw          $s0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r16;
    // 0x800EC644: beq         $s4, $zero, L_800EC658
    if (ctx->r20 == 0) {
        // 0x800EC648: sw          $a1, 0x1A8($s0)
        MEM_W(0X1A8, ctx->r16) = ctx->r5;
            goto L_800EC658;
    }
    // 0x800EC648: sw          $a1, 0x1A8($s0)
    MEM_W(0X1A8, ctx->r16) = ctx->r5;
    // 0x800EC64C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800EC650: jalr        $s4
    // 0x800EC654: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    LOOKUP_FUNC(ctx->r20)(rdram, ctx);
        goto after_2;
    // 0x800EC654: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_2:
L_800EC658:
    // 0x800EC658: j           L_800EC664
    // 0x800EC65C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800EC664;
    // 0x800EC65C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EC660:
    // 0x800EC660: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800EC664:
    // 0x800EC664: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800EC668: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800EC66C: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800EC670: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800EC674: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800EC678: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800EC67C: jr          $ra
    // 0x800EC680: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800EC680: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800EC684(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EC684: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EC688: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800EC68C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800EC690: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EC694: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800EC698: jal         0x800F2A24
    // 0x800EC69C: nop

    func_800F2A24(rdram, ctx);
        goto after_0;
    // 0x800EC69C: nop

    after_0:
    // 0x800EC6A0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800EC6A4: jal         0x800EC388
    // 0x800EC6A8: nop

    func_800EC388(rdram, ctx);
        goto after_1;
    // 0x800EC6A8: nop

    after_1:
    // 0x800EC6AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EC6B0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800EC6B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EC6B8: jr          $ra
    // 0x800EC6BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800EC6BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800EC6C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EC6C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EC6C4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800EC6C8: lbu         $v0, 0x1A4($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1A4);
    // 0x800EC6CC: beq         $v0, $zero, L_800EC6E0
    if (ctx->r2 == 0) {
        // 0x800EC6D0: nop
    
            goto L_800EC6E0;
    }
    // 0x800EC6D0: nop

    // 0x800EC6D4: lhu         $a0, 0x198($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X198);
    // 0x800EC6D8: jal         0x8003ED74
    // 0x800EC6DC: nop

    func_8003ED74(rdram, ctx);
        goto after_0;
    // 0x800EC6DC: nop

    after_0:
L_800EC6E0:
    // 0x800EC6E0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800EC6E4: jr          $ra
    // 0x800EC6E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800EC6E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void fake_func_800EC6EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_800EC6F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EC6F0: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x800EC6F4: sw          $s0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r16;
    // 0x800EC6F8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800EC6FC: sw          $s2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r18;
    // 0x800EC700: sw          $ra, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r31;
    // 0x800EC704: sw          $s1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r17;
    // 0x800EC708: sdc1        $f20, 0x98($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X98, ctx->r29);
    // 0x800EC70C: lbu         $v0, 0x4C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4C);
    // 0x800EC710: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x800EC714: beq         $v0, $zero, L_800EC74C
    if (ctx->r2 == 0) {
        // 0x800EC718: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_800EC74C;
    }
    // 0x800EC718: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800EC71C: lwc1        $f0, 0x48($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X48);
    // 0x800EC720: add.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x800EC724: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800EC728: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x800EC72C: lwc1        $f2, 0x70($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X70);
    // 0x800EC730: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800EC734: nop

    // 0x800EC738: bc1tl       L_800EC748
    if (c1cs) {
        // 0x800EC73C: sw          $zero, 0x48($s0)
        MEM_W(0X48, ctx->r16) = 0;
            goto L_800EC748;
    }
    goto skip_0;
    // 0x800EC73C: sw          $zero, 0x48($s0)
    MEM_W(0X48, ctx->r16) = 0;
    skip_0:
    // 0x800EC740: j           L_800ECC0C
    // 0x800EC744: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_800ECC0C;
    // 0x800EC744: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800EC748:
    // 0x800EC748: sb          $zero, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = 0;
L_800EC74C:
    // 0x800EC74C: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800EC750: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800EC754: lwc1        $f2, 0x28($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X28);
    // 0x800EC758: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800EC75C: addiu       $s1, $s0, 0x8
    ctx->r17 = ADD32(ctx->r16, 0X8);
    // 0x800EC760: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800EC764: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800EC768: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800EC76C: lwc1        $f2, 0x30($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X30);
    // 0x800EC770: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800EC774: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800EC778: lhu         $a0, -0x6A9E($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A9E);
    // 0x800EC77C: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x800EC780: jal         0x8003FC28
    // 0x800EC784: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    func_8003FC28(rdram, ctx);
        goto after_0;
    // 0x800EC784: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x800EC788: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x800EC78C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800EC790: beq         $a0, $v0, L_800ECC0C
    if (ctx->r4 == ctx->r2) {
        // 0x800EC794: addu        $v0, $s2, $zero
        ctx->r2 = ADD32(ctx->r18, 0);
            goto L_800ECC0C;
    }
    // 0x800EC794: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    // 0x800EC798: jal         0x8004015C
    // 0x800EC79C: nop

    func_8004015C(rdram, ctx);
        goto after_1;
    // 0x800EC79C: nop

    after_1:
    // 0x800EC7A0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800EC7A4: lwc1        $f2, 0x24($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X24);
    // 0x800EC7A8: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800EC7AC: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800EC7B0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800EC7B4: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x800EC7B8: lwc1        $f2, 0x28($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X28);
    // 0x800EC7BC: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800EC7C0: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800EC7C4: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800EC7C8: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x800EC7CC: lwc1        $f2, 0x2C($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x800EC7D0: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800EC7D4: lwc1        $f0, 0x8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800EC7D8: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800EC7DC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x800EC7E0: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800EC7E4: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800EC7E8: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x800EC7EC: nop

    // 0x800EC7F0: bc1t        L_800EC838
    if (c1cs) {
        // 0x800EC7F4: nop
    
            goto L_800EC838;
    }
    // 0x800EC7F4: nop

    // 0x800EC7F8: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800EC7FC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800EC800: nop

    // 0x800EC804: bc1t        L_800EC838
    if (c1cs) {
        // 0x800EC808: nop
    
            goto L_800EC838;
    }
    // 0x800EC808: nop

    // 0x800EC80C: lwc1        $f2, 0x8($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800EC810: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800EC814: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800EC818: nop

    // 0x800EC81C: bc1t        L_800EC838
    if (c1cs) {
        // 0x800EC820: nop
    
            goto L_800EC838;
    }
    // 0x800EC820: nop

    // 0x800EC824: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800EC828: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800EC82C: nop

    // 0x800EC830: bc1f        L_800EC9BC
    if (!c1cs) {
        // 0x800EC834: nop
    
            goto L_800EC9BC;
    }
    // 0x800EC834: nop

L_800EC838:
    // 0x800EC838: lbu         $v1, 0x4D($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X4D);
    // 0x800EC83C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EC840: bne         $v1, $v0, L_800ECC0C
    if (ctx->r3 != ctx->r2) {
        // 0x800EC844: addu        $v0, $s2, $zero
        ctx->r2 = ADD32(ctx->r18, 0);
            goto L_800ECC0C;
    }
    // 0x800EC844: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    // 0x800EC848: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800EC84C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800EC850: sb          $zero, 0x4D($s0)
    MEM_B(0X4D, ctx->r16) = 0;
    // 0x800EC854: lwc1        $f0, 0x70($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X70);
    // 0x800EC858: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x800EC85C: nop

    // 0x800EC860: bc1t        L_800EC870
    if (c1cs) {
        // 0x800EC864: nop
    
            goto L_800EC870;
    }
    // 0x800EC864: nop

    // 0x800EC868: sb          $v1, 0x4C($s0)
    MEM_B(0X4C, ctx->r16) = ctx->r3;
    // 0x800EC86C: swc1        $f2, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f2.u32l;
L_800EC870:
    // 0x800EC870: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800EC874: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EC878: lwc1        $f0, -0x7700($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7700);
    // 0x800EC87C: lhu         $v0, 0x4A($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X4A);
    // 0x800EC880: sh          $v0, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r2;
    // 0x800EC884: lhu         $v0, 0x42($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X42);
    // 0x800EC888: sh          $v1, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r3;
    // 0x800EC88C: sh          $v0, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r2;
    // 0x800EC890: lhu         $v0, 0x46($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X46);
    // 0x800EC894: sh          $v0, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r2;
    // 0x800EC898: lwc1        $f2, 0x58($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X58);
    // 0x800EC89C: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800EC8A0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EC8A4: lwc1        $f2, -0x76FC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X76FC);
    // 0x800EC8A8: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800EC8AC: nop

    // 0x800EC8B0: bc1tl       L_800EC8C8
    if (c1cs) {
        // 0x800EC8B4: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800EC8C8;
    }
    goto skip_1;
    // 0x800EC8B4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_1:
    // 0x800EC8B8: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800EC8BC: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800EC8C0: j           L_800EC8DC
    // 0x800EC8C4: sh          $v1, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r3;
        goto L_800EC8DC;
    // 0x800EC8C4: sh          $v1, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r3;
L_800EC8C8:
    // 0x800EC8C8: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800EC8CC: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800EC8D0: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800EC8D4: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800EC8D8: sh          $v1, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r3;
L_800EC8DC:
    // 0x800EC8DC: lwc1        $f2, 0x5C($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X5C);
    // 0x800EC8E0: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EC8E4: lwc1        $f0, -0x76F8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X76F8);
    // 0x800EC8E8: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800EC8EC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EC8F0: lwc1        $f2, -0x76F4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X76F4);
    // 0x800EC8F4: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800EC8F8: nop

    // 0x800EC8FC: bc1tl       L_800EC914
    if (c1cs) {
        // 0x800EC900: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800EC914;
    }
    goto skip_2;
    // 0x800EC900: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_2:
    // 0x800EC904: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800EC908: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800EC90C: j           L_800EC928
    // 0x800EC910: lui         $v0, 0x7FFF
    ctx->r2 = S32(0X7FFF << 16);
        goto L_800EC928;
    // 0x800EC910: lui         $v0, 0x7FFF
    ctx->r2 = S32(0X7FFF << 16);
L_800EC914:
    // 0x800EC914: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800EC918: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800EC91C: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800EC920: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800EC924: lui         $v0, 0x7FFF
    ctx->r2 = S32(0X7FFF << 16);
L_800EC928:
    // 0x800EC928: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800EC92C: sh          $v1, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r3;
    // 0x800EC930: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x800EC934: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    // 0x800EC938: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800EC93C: sb          $zero, 0x69($sp)
    MEM_B(0X69, ctx->r29) = 0;
    // 0x800EC940: sb          $zero, 0x6A($sp)
    MEM_B(0X6A, ctx->r29) = 0;
    // 0x800EC944: sb          $zero, 0x67($sp)
    MEM_B(0X67, ctx->r29) = 0;
    // 0x800EC948: sb          $zero, 0x66($sp)
    MEM_B(0X66, ctx->r29) = 0;
    // 0x800EC94C: lhu         $v1, 0x4($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X4);
    // 0x800EC950: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x800EC954: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x800EC958: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x800EC95C: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x800EC960: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x800EC964: sh          $v1, 0x64($sp)
    MEM_H(0X64, ctx->r29) = ctx->r3;
    // 0x800EC968: lwc1        $f0, 0x78($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X78);
    // 0x800EC96C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x800EC970: lbu         $v0, 0x97($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X97);
    // 0x800EC974: sb          $v0, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r2;
    // 0x800EC978: lbu         $v0, 0x9B($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X9B);
    // 0x800EC97C: sb          $v0, 0x6C($sp)
    MEM_B(0X6C, ctx->r29) = ctx->r2;
    // 0x800EC980: lbu         $v0, 0x9F($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X9F);
    // 0x800EC984: sb          $v0, 0x6D($sp)
    MEM_B(0X6D, ctx->r29) = ctx->r2;
    // 0x800EC988: lw          $v0, 0xA0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XA0);
    // 0x800EC98C: sb          $zero, 0x68($sp)
    MEM_B(0X68, ctx->r29) = 0;
    // 0x800EC990: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
    // 0x800EC994: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800EC998: lw          $v0, 0x6C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X6C);
    // 0x800EC99C: beq         $v0, $zero, L_800EC9B4
    if (ctx->r2 == 0) {
        // 0x800EC9A0: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_800EC9B4;
    }
    // 0x800EC9A0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800EC9A4: bne         $v0, $zero, L_800EC9B4
    if (ctx->r2 != 0) {
        // 0x800EC9A8: sw          $v0, 0x6C($a0)
        MEM_W(0X6C, ctx->r4) = ctx->r2;
            goto L_800EC9B4;
    }
    // 0x800EC9A8: sw          $v0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r2;
    // 0x800EC9AC: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x800EC9B0: sb          $a1, 0x67($sp)
    MEM_B(0X67, ctx->r29) = ctx->r5;
L_800EC9B4:
    // 0x800EC9B4: j           L_800ECBF0
    // 0x800EC9B8: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
        goto L_800ECBF0;
    // 0x800EC9B8: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
L_800EC9BC:
    // 0x800EC9BC: lbu         $v0, 0x4E($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4E);
    // 0x800EC9C0: bne         $v0, $zero, L_800ECA40
    if (ctx->r2 != 0) {
        // 0x800EC9C4: nop
    
            goto L_800ECA40;
    }
    // 0x800EC9C4: nop

    // 0x800EC9C8: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800EC9CC: lwc1        $f4, 0x4C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x800EC9D0: lwc1        $f0, 0x28($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X28);
    // 0x800EC9D4: mul.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800EC9D8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800EC9DC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EC9E0: lwc1        $f6, -0x76F0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X76F0);
    // 0x800EC9E4: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800EC9E8: add.s       $f0, $f8, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800EC9EC: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    // 0x800EC9F0: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800EC9F4: lwc1        $f2, 0x28($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X28);
    // 0x800EC9F8: mul.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800EC9FC: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800ECA00: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800ECA04: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800ECA08: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800ECA0C: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
    // 0x800ECA10: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800ECA14: lwc1        $f2, 0x28($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X28);
    // 0x800ECA18: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800ECA1C: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800ECA20: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800ECA24: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800ECA28: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800ECA2C: lwc1        $f2, 0x30($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X30);
    // 0x800ECA30: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800ECA34: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800ECA38: j           L_800ECA5C
    // 0x800ECA3C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
        goto L_800ECA5C;
    // 0x800ECA3C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
L_800ECA40:
    // 0x800ECA40: lwc1        $f0, 0x38($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X38);
    // 0x800ECA44: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    // 0x800ECA48: lwc1        $f0, 0x3C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x800ECA4C: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
    // 0x800ECA50: lwc1        $f0, 0x40($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X40);
    // 0x800ECA54: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800ECA58: lwc1        $f0, 0x44($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X44);
L_800ECA5C:
    // 0x800ECA5C: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x800ECA60: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800ECA64: lwc1        $f0, 0x78($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800ECA68: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800ECA6C: nop

    // 0x800ECA70: bc1f        L_800ECC0C
    if (!c1cs) {
        // 0x800ECA74: addu        $v0, $s2, $zero
        ctx->r2 = ADD32(ctx->r18, 0);
            goto L_800ECC0C;
    }
    // 0x800ECA74: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    // 0x800ECA78: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800ECA7C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800ECA80: nop

    // 0x800ECA84: bc1f        L_800ECC0C
    if (!c1cs) {
        // 0x800ECA88: nop
    
            goto L_800ECC0C;
    }
    // 0x800ECA88: nop

    // 0x800ECA8C: lwc1        $f2, 0x8($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800ECA90: lwc1        $f0, 0x80($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800ECA94: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800ECA98: nop

    // 0x800ECA9C: bc1f        L_800ECC0C
    if (!c1cs) {
        // 0x800ECAA0: nop
    
            goto L_800ECC0C;
    }
    // 0x800ECAA0: nop

    // 0x800ECAA4: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800ECAA8: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800ECAAC: nop

    // 0x800ECAB0: bc1f        L_800ECC0C
    if (!c1cs) {
        // 0x800ECAB4: nop
    
            goto L_800ECC0C;
    }
    // 0x800ECAB4: nop

    // 0x800ECAB8: lbu         $v0, 0x4D($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4D);
    // 0x800ECABC: bne         $v0, $zero, L_800ECC0C
    if (ctx->r2 != 0) {
        // 0x800ECAC0: addu        $v0, $s2, $zero
        ctx->r2 = ADD32(ctx->r18, 0);
            goto L_800ECC0C;
    }
    // 0x800ECAC0: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
    // 0x800ECAC4: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800ECAC8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800ECACC: lwc1        $f0, -0x76EC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X76EC);
    // 0x800ECAD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800ECAD4: sb          $v0, 0x4D($s0)
    MEM_B(0X4D, ctx->r16) = ctx->r2;
    // 0x800ECAD8: lhu         $v0, 0x3E($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3E);
    // 0x800ECADC: sh          $v0, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r2;
    // 0x800ECAE0: lhu         $v1, 0x42($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X42);
    // 0x800ECAE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800ECAE8: sh          $v0, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r2;
    // 0x800ECAEC: sh          $v1, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r3;
    // 0x800ECAF0: lhu         $v0, 0x46($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X46);
    // 0x800ECAF4: sh          $v0, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r2;
    // 0x800ECAF8: lwc1        $f2, 0x50($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X50);
    // 0x800ECAFC: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800ECB00: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800ECB04: lwc1        $f2, -0x76E8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X76E8);
    // 0x800ECB08: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800ECB0C: nop

    // 0x800ECB10: bc1tl       L_800ECB28
    if (c1cs) {
        // 0x800ECB14: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800ECB28;
    }
    goto skip_3;
    // 0x800ECB14: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_3:
    // 0x800ECB18: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800ECB1C: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800ECB20: j           L_800ECB3C
    // 0x800ECB24: sh          $v1, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r3;
        goto L_800ECB3C;
    // 0x800ECB24: sh          $v1, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r3;
L_800ECB28:
    // 0x800ECB28: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800ECB2C: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800ECB30: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800ECB34: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800ECB38: sh          $v1, 0x60($sp)
    MEM_H(0X60, ctx->r29) = ctx->r3;
L_800ECB3C:
    // 0x800ECB3C: lwc1        $f2, 0x54($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X54);
    // 0x800ECB40: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800ECB44: lwc1        $f0, -0x76E4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X76E4);
    // 0x800ECB48: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800ECB4C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800ECB50: lwc1        $f2, -0x76E0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X76E0);
    // 0x800ECB54: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800ECB58: nop

    // 0x800ECB5C: bc1tl       L_800ECB74
    if (c1cs) {
        // 0x800ECB60: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800ECB74;
    }
    goto skip_4;
    // 0x800ECB60: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_4:
    // 0x800ECB64: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800ECB68: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800ECB6C: j           L_800ECB88
    // 0x800ECB70: sh          $v1, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r3;
        goto L_800ECB88;
    // 0x800ECB70: sh          $v1, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r3;
L_800ECB74:
    // 0x800ECB74: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800ECB78: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800ECB7C: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800ECB80: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800ECB84: sh          $v1, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r3;
L_800ECB88:
    // 0x800ECB88: lwc1        $f0, 0x60($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X60);
    // 0x800ECB8C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x800ECB90: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x800ECB94: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x800ECB98: lw          $v0, 0x68($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X68);
    // 0x800ECB9C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x800ECBA0: lbu         $v0, 0x77($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X77);
    // 0x800ECBA4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800ECBA8: sb          $zero, 0x6A($sp)
    MEM_B(0X6A, ctx->r29) = 0;
    // 0x800ECBAC: sb          $zero, 0x67($sp)
    MEM_B(0X67, ctx->r29) = 0;
    // 0x800ECBB0: sb          $v1, 0x66($sp)
    MEM_B(0X66, ctx->r29) = ctx->r3;
    // 0x800ECBB4: sb          $v0, 0x69($sp)
    MEM_B(0X69, ctx->r29) = ctx->r2;
    // 0x800ECBB8: lhu         $v0, 0x4($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X4);
    // 0x800ECBBC: sh          $v0, 0x64($sp)
    MEM_H(0X64, ctx->r29) = ctx->r2;
    // 0x800ECBC0: lwc1        $f0, 0x78($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X78);
    // 0x800ECBC4: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x800ECBC8: lbu         $v0, 0x97($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X97);
    // 0x800ECBCC: sb          $v0, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r2;
    // 0x800ECBD0: lbu         $v0, 0x9B($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X9B);
    // 0x800ECBD4: sb          $v0, 0x6C($sp)
    MEM_B(0X6C, ctx->r29) = ctx->r2;
    // 0x800ECBD8: lbu         $v0, 0x9F($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X9F);
    // 0x800ECBDC: sb          $v0, 0x6D($sp)
    MEM_B(0X6D, ctx->r29) = ctx->r2;
    // 0x800ECBE0: lw          $v0, 0xA0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XA0);
    // 0x800ECBE4: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x800ECBE8: sb          $v1, 0x68($sp)
    MEM_B(0X68, ctx->r29) = ctx->r3;
    // 0x800ECBEC: sw          $v0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r2;
L_800ECBF0:
    // 0x800ECBF0: jal         0x800EF510
    // 0x800ECBF4: nop

    func_800EF510(rdram, ctx);
        goto after_2;
    // 0x800ECBF4: nop

    after_2:
    // 0x800ECBF8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800ECBFC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800ECC00: beql        $v0, $v1, L_800ECC08
    if (ctx->r2 == ctx->r3) {
        // 0x800ECC04: addu        $s2, $v1, $zero
        ctx->r18 = ADD32(ctx->r3, 0);
            goto L_800ECC08;
    }
    goto skip_5;
    // 0x800ECC04: addu        $s2, $v1, $zero
    ctx->r18 = ADD32(ctx->r3, 0);
    skip_5:
L_800ECC08:
    // 0x800ECC08: addu        $v0, $s2, $zero
    ctx->r2 = ADD32(ctx->r18, 0);
L_800ECC0C:
    // 0x800ECC0C: lw          $ra, 0x94($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X94);
    // 0x800ECC10: lw          $s2, 0x90($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X90);
    // 0x800ECC14: lw          $s1, 0x8C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X8C);
    // 0x800ECC18: lw          $s0, 0x88($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X88);
    // 0x800ECC1C: ldc1        $f20, 0x98($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X98);
    // 0x800ECC20: jr          $ra
    // 0x800ECC24: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x800ECC24: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void func_800ECC28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ECC28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800ECC2C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800ECC30: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800ECC34: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x800ECC38: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800ECC3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800ECC40: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800ECC44: beq         $a1, $v0, L_800ECDC8
    if (ctx->r5 == ctx->r2) {
        // 0x800ECC48: slti        $v0, $a1, 0x3
        ctx->r2 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
            goto L_800ECDC8;
    }
    // 0x800ECC48: slti        $v0, $a1, 0x3
    ctx->r2 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
    // 0x800ECC4C: beq         $v0, $zero, L_800ECC64
    if (ctx->r2 == 0) {
        // 0x800ECC50: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800ECC64;
    }
    // 0x800ECC50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800ECC54: beq         $a1, $v0, L_800ECC80
    if (ctx->r5 == ctx->r2) {
        // 0x800ECC58: addiu       $v0, $a0, 0x8
        ctx->r2 = ADD32(ctx->r4, 0X8);
            goto L_800ECC80;
    }
    // 0x800ECC58: addiu       $v0, $a0, 0x8
    ctx->r2 = ADD32(ctx->r4, 0X8);
    // 0x800ECC5C: j           L_800ECDCC
    // 0x800ECC60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800ECDCC;
    // 0x800ECC60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800ECC64:
    // 0x800ECC64: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800ECC68: beq         $a1, $v0, L_800ECD30
    if (ctx->r5 == ctx->r2) {
        // 0x800ECC6C: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_800ECD30;
    }
    // 0x800ECC6C: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x800ECC70: beq         $a1, $v0, L_800ECDBC
    if (ctx->r5 == ctx->r2) {
        // 0x800ECC74: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800ECDBC;
    }
    // 0x800ECC74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800ECC78: j           L_800ECDCC
    // 0x800ECC7C: nop

        goto L_800ECDCC;
    // 0x800ECC7C: nop

L_800ECC80:
    // 0x800ECC80: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x800ECC84: sw          $a2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r6;
    // 0x800ECC88: lwc1        $f0, 0x10($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800ECC8C: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x800ECC90: lwc1        $f0, 0x14($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800ECC94: swc1        $f0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f0.u32l;
    // 0x800ECC98: lwc1        $f0, 0x18($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X18);
    // 0x800ECC9C: addu        $v1, $a2, $zero
    ctx->r3 = ADD32(ctx->r6, 0);
    // 0x800ECCA0: sb          $zero, 0x4D($a0)
    MEM_B(0X4D, ctx->r4) = 0;
    // 0x800ECCA4: sw          $zero, 0x48($a0)
    MEM_W(0X48, ctx->r4) = 0;
    // 0x800ECCA8: sb          $zero, 0x4C($a0)
    MEM_B(0X4C, ctx->r4) = 0;
    // 0x800ECCAC: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800ECCB0: swc1        $f0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f0.u32l;
    // 0x800ECCB4: lw          $v0, 0xA4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XA4);
    // 0x800ECCB8: beql        $v0, $zero, L_800ECD18
    if (ctx->r2 == 0) {
        // 0x800ECCBC: sb          $zero, 0x4E($a0)
        MEM_B(0X4E, ctx->r4) = 0;
            goto L_800ECD18;
    }
    goto skip_0;
    // 0x800ECCBC: sb          $zero, 0x4E($a0)
    MEM_B(0X4E, ctx->r4) = 0;
    skip_0:
    // 0x800ECCC0: lw          $v0, 0xA8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XA8);
    // 0x800ECCC4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800ECCC8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800ECCCC: lw          $v1, 0x75D8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X75D8);
    // 0x800ECCD0: lhu         $v0, 0xA6($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0XA6);
    // 0x800ECCD4: lw          $v1, 0x34($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X34);
    // 0x800ECCD8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800ECCDC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800ECCE0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800ECCE4: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800ECCE8: swc1        $f0, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f0.u32l;
    // 0x800ECCEC: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x800ECCF0: swc1        $f0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f0.u32l;
    // 0x800ECCF4: lwc1        $f0, 0x38($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X38);
    // 0x800ECCF8: lwc1        $f2, 0x28($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X28);
    // 0x800ECCFC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800ECD00: swc1        $f0, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f0.u32l;
    // 0x800ECD04: lwc1        $f0, 0x3C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x800ECD08: lwc1        $f2, 0x30($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X30);
    // 0x800ECD0C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800ECD10: sb          $a1, 0x4E($a0)
    MEM_B(0X4E, ctx->r4) = ctx->r5;
    // 0x800ECD14: swc1        $f0, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f0.u32l;
L_800ECD18:
    // 0x800ECD18: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800ECD1C: lhu         $a0, -0x6A64($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A64);
    // 0x800ECD20: jal         0x8003E684
    // 0x800ECD24: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_8003E684(rdram, ctx);
        goto after_0;
    // 0x800ECD24: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_0:
    // 0x800ECD28: j           L_800ECDCC
    // 0x800ECD2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800ECDCC;
    // 0x800ECD2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800ECD30:
    // 0x800ECD30: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    // 0x800ECD34: lw          $v1, 0x84($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X84);
    // 0x800ECD38: lwc1        $f0, 0x0($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800ECD3C: beq         $v1, $zero, L_800ECD5C
    if (ctx->r3 == 0) {
        // 0x800ECD40: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800ECD5C;
    }
    // 0x800ECD40: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800ECD44: addiu       $v0, $v0, -0x7760
    ctx->r2 = ADD32(ctx->r2, -0X7760);
    // 0x800ECD48: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x800ECD4C: lbu         $v1, -0x1($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X1);
    // 0x800ECD50: lw          $v0, 0x88($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X88);
    // 0x800ECD54: bne         $v1, $v0, L_800ECDCC
    if (ctx->r3 != ctx->r2) {
        // 0x800ECD58: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800ECDCC;
    }
    // 0x800ECD58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800ECD5C:
    // 0x800ECD5C: lw          $v0, 0x8C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X8C);
    // 0x800ECD60: beq         $v0, $zero, L_800ECD8C
    if (ctx->r2 == 0) {
        // 0x800ECD64: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_800ECD8C;
    }
    // 0x800ECD64: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800ECD68: addiu       $v1, $v1, -0x7FA0
    ctx->r3 = ADD32(ctx->r3, -0X7FA0);
    // 0x800ECD6C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800ECD70: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800ECD74: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800ECD78: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800ECD7C: lw          $v1, 0x90($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X90);
    // 0x800ECD80: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800ECD84: bne         $v0, $zero, L_800ECDCC
    if (ctx->r2 != 0) {
        // 0x800ECD88: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800ECDCC;
    }
    // 0x800ECD88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800ECD8C:
    // 0x800ECD8C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800ECD90: jal         0x800EC6F0
    // 0x800ECD94: nop

    func_800EC6F0(rdram, ctx);
        goto after_1;
    // 0x800ECD94: nop

    after_1:
    // 0x800ECD98: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800ECD9C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800ECDA0: bne         $v0, $v1, L_800ECDCC
    if (ctx->r2 != ctx->r3) {
        // 0x800ECDA4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800ECDCC;
    }
    // 0x800ECDA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800ECDA8: lhu         $a0, 0x16($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X16);
    // 0x800ECDAC: jal         0x8003ED74
    // 0x800ECDB0: nop

    func_8003ED74(rdram, ctx);
        goto after_2;
    // 0x800ECDB0: nop

    after_2:
    // 0x800ECDB4: j           L_800ECDCC
    // 0x800ECDB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800ECDCC;
    // 0x800ECDB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800ECDBC:
    // 0x800ECDBC: sb          $zero, 0x4D($a0)
    MEM_B(0X4D, ctx->r4) = 0;
    // 0x800ECDC0: sw          $zero, 0x48($a0)
    MEM_W(0X48, ctx->r4) = 0;
    // 0x800ECDC4: sb          $zero, 0x4C($a0)
    MEM_B(0X4C, ctx->r4) = 0;
L_800ECDC8:
    // 0x800ECDC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800ECDCC:
    // 0x800ECDCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800ECDD0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800ECDD4: jr          $ra
    // 0x800ECDD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800ECDD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800ECDDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ECDDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800ECDE0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800ECDE4: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x800ECDE8: lhu         $a0, -0x6A64($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A64);
    // 0x800ECDEC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800ECDF0: jal         0x8003E8DC
    // 0x800ECDF4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_8003E8DC(rdram, ctx);
        goto after_0;
    // 0x800ECDF4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_0:
    // 0x800ECDF8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800ECDFC: jr          $ra
    // 0x800ECE00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800ECE00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void fake_func_800ECE04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_800ECE10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ECE10: addiu       $sp, $sp, -0x140
    ctx->r29 = ADD32(ctx->r29, -0X140);
    // 0x800ECE14: sw          $s1, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r17;
    // 0x800ECE18: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800ECE1C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x800ECE20: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800ECE24: sw          $ra, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r31;
    // 0x800ECE28: sw          $s0, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r16;
    // 0x800ECE2C: sdc1        $f20, 0x138($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X138, ctx->r29);
    // 0x800ECE30: lw          $s0, 0x4($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4);
    // 0x800ECE34: beq         $a1, $v0, L_800ECEC8
    if (ctx->r5 == ctx->r2) {
        // 0x800ECE38: slti        $v0, $a1, 0x3
        ctx->r2 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
            goto L_800ECEC8;
    }
    // 0x800ECE38: slti        $v0, $a1, 0x3
    ctx->r2 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
    // 0x800ECE3C: beq         $v0, $zero, L_800ECE54
    if (ctx->r2 == 0) {
        // 0x800ECE40: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800ECE54;
    }
    // 0x800ECE40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800ECE44: beql        $a1, $v0, L_800ECE70
    if (ctx->r5 == ctx->r2) {
        // 0x800ECE48: sw          $a2, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r6;
            goto L_800ECE70;
    }
    goto skip_0;
    // 0x800ECE48: sw          $a2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r6;
    skip_0:
    // 0x800ECE4C: j           L_800ED12C
    // 0x800ECE50: nop

        goto L_800ED12C;
    // 0x800ECE50: nop

L_800ECE54:
    // 0x800ECE54: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800ECE58: beq         $a1, $v0, L_800ECF04
    if (ctx->r5 == ctx->r2) {
        // 0x800ECE5C: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_800ECF04;
    }
    // 0x800ECE5C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x800ECE60: beq         $a1, $v0, L_800ED120
    if (ctx->r5 == ctx->r2) {
        // 0x800ECE64: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800ED120;
    }
    // 0x800ECE64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800ECE68: j           L_800ED130
    // 0x800ECE6C: nop

        goto L_800ED130;
    // 0x800ECE6C: nop

L_800ECE70:
    // 0x800ECE70: lwc1        $f0, 0x10($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800ECE74: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800ECE78: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x800ECE7C: lwc1        $f0, 0x14($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800ECE80: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x800ECE84: lwc1        $f0, 0x18($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X18);
    // 0x800ECE88: addiu       $v0, $s0, 0x4
    ctx->r2 = ADD32(ctx->r16, 0X4);
    // 0x800ECE8C: swc1        $f20, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f20.u32l;
    // 0x800ECE90: swc1        $f20, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f20.u32l;
    // 0x800ECE94: swc1        $f20, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f20.u32l;
    // 0x800ECE98: swc1        $f20, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f20.u32l;
    // 0x800ECE9C: swc1        $f20, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f20.u32l;
    // 0x800ECEA0: swc1        $f20, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f20.u32l;
    // 0x800ECEA4: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x800ECEA8: sw          $v0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r2;
    // 0x800ECEAC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800ECEB0: lhu         $a0, -0x6A8C($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A8C);
    // 0x800ECEB4: jal         0x8003E684
    // 0x800ECEB8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    func_8003E684(rdram, ctx);
        goto after_0;
    // 0x800ECEB8: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_0:
    // 0x800ECEBC: sw          $zero, 0x38($s0)
    MEM_W(0X38, ctx->r16) = 0;
    // 0x800ECEC0: j           L_800ED12C
    // 0x800ECEC4: swc1        $f20, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f20.u32l;
        goto L_800ED12C;
    // 0x800ECEC4: swc1        $f20, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f20.u32l;
L_800ECEC8:
    // 0x800ECEC8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800ECECC: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800ECED0: sh          $v0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r2;
    // 0x800ECED4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800ECED8: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x800ECEDC: lw          $v1, 0x6C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X6C);
    // 0x800ECEE0: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800ECEE4: bne         $v0, $zero, L_800ECEF4
    if (ctx->r2 != 0) {
        // 0x800ECEE8: nop
    
            goto L_800ECEF4;
    }
    // 0x800ECEE8: nop

    // 0x800ECEEC: bgtz        $v1, L_800ED130
    if (SIGNED(ctx->r3) > 0) {
        // 0x800ECEF0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800ED130;
    }
    // 0x800ECEF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800ECEF4:
    // 0x800ECEF4: jal         0x80046620
    // 0x800ECEF8: addiu       $a1, $a0, 0x10
    ctx->r5 = ADD32(ctx->r4, 0X10);
    func_80046620(rdram, ctx);
        goto after_1;
    // 0x800ECEF8: addiu       $a1, $a0, 0x10
    ctx->r5 = ADD32(ctx->r4, 0X10);
    after_1:
    // 0x800ECEFC: j           L_800ED130
    // 0x800ECF00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800ED130;
    // 0x800ECF00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800ECF04:
    // 0x800ECF04: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800ECF08: lw          $v1, 0x34($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X34);
    // 0x800ECF0C: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800ECF10: beq         $v1, $zero, L_800ECF2C
    if (ctx->r3 == 0) {
        // 0x800ECF14: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800ECF2C;
    }
    // 0x800ECF14: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800ECF18: addiu       $v0, $v0, -0x7760
    ctx->r2 = ADD32(ctx->r2, -0X7760);
    // 0x800ECF1C: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x800ECF20: lbu         $v0, -0x1($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X1);
    // 0x800ECF24: beq         $v0, $zero, L_800ED130
    if (ctx->r2 == 0) {
        // 0x800ECF28: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800ED130;
    }
    // 0x800ECF28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800ECF2C:
    // 0x800ECF2C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800ECF30: lw          $v0, 0x38($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X38);
    // 0x800ECF34: beq         $v0, $zero, L_800ECF60
    if (ctx->r2 == 0) {
        // 0x800ECF38: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_800ECF60;
    }
    // 0x800ECF38: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800ECF3C: addiu       $v1, $v1, -0x7FA0
    ctx->r3 = ADD32(ctx->r3, -0X7FA0);
    // 0x800ECF40: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800ECF44: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800ECF48: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800ECF4C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800ECF50: lw          $v1, 0x3C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X3C);
    // 0x800ECF54: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800ECF58: bne         $v0, $zero, L_800ED130
    if (ctx->r2 != 0) {
        // 0x800ECF5C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800ED130;
    }
    // 0x800ECF5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800ECF60:
    // 0x800ECF60: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800ECF64: lw          $v0, 0x30($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X30);
    // 0x800ECF68: lw          $v1, 0x6C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6C);
    // 0x800ECF6C: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800ECF70: bne         $v0, $zero, L_800ECF94
    if (ctx->r2 != 0) {
        // 0x800ECF74: nop
    
            goto L_800ECF94;
    }
    // 0x800ECF74: nop

    // 0x800ECF78: blez        $v1, L_800ECF94
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800ECF7C: nop
    
            goto L_800ECF94;
    }
    // 0x800ECF7C: nop

L_800ECF80:
    // 0x800ECF80: lhu         $a0, 0x16($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X16);
    // 0x800ECF84: jal         0x8003ED74
    // 0x800ECF88: nop

    func_8003ED74(rdram, ctx);
        goto after_2;
    // 0x800ECF88: nop

    after_2:
    // 0x800ECF8C: j           L_800ED130
    // 0x800ECF90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800ED130;
    // 0x800ECF90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800ECF94:
    // 0x800ECF94: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800ECF98: lw          $a0, 0x2C($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X2C);
    // 0x800ECF9C: lw          $v0, 0x70($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X70);
    // 0x800ECFA0: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800ECFA4: beq         $v0, $zero, L_800ED0E8
    if (ctx->r2 == 0) {
        // 0x800ECFA8: nop
    
            goto L_800ED0E8;
    }
    // 0x800ECFA8: nop

    // 0x800ECFAC: lw          $v0, 0x30($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X30);
    // 0x800ECFB0: lw          $v1, 0x6C($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X6C);
    // 0x800ECFB4: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x800ECFB8: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800ECFBC: bne         $v0, $zero, L_800ECFCC
    if (ctx->r2 != 0) {
        // 0x800ECFC0: nop
    
            goto L_800ECFCC;
    }
    // 0x800ECFC0: nop

    // 0x800ECFC4: bgtz        $v1, L_800ED0E8
    if (SIGNED(ctx->r3) > 0) {
        // 0x800ECFC8: nop
    
            goto L_800ED0E8;
    }
    // 0x800ECFC8: nop

L_800ECFCC:
    // 0x800ECFCC: lwc1        $f2, 0x34($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X34);
    // 0x800ECFD0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800ECFD4: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800ECFD8: nop

    // 0x800ECFDC: bc1fl       L_800ED0E4
    if (!c1cs) {
        // 0x800ECFE0: sub.s       $f0, $f2, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f4.fl;
            goto L_800ED0E4;
    }
    goto skip_1;
    // 0x800ECFE0: sub.s       $f0, $f2, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f4.fl;
    skip_1:
    // 0x800ECFE4: lw          $v0, 0x78($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X78);
    // 0x800ECFE8: lw          $v1, 0x7C($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X7C);
    // 0x800ECFEC: beq         $v1, $zero, L_800ED004
    if (ctx->r3 == 0) {
        // 0x800ECFF0: addu        $a0, $v0, $a1
        ctx->r4 = ADD32(ctx->r2, ctx->r5);
            goto L_800ED004;
    }
    // 0x800ECFF0: addu        $a0, $v0, $a1
    ctx->r4 = ADD32(ctx->r2, ctx->r5);
    // 0x800ECFF4: jal         0x800F3144
    // 0x800ECFF8: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    func_800F3144(rdram, ctx);
        goto after_3;
    // 0x800ECFF8: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    after_3:
    // 0x800ECFFC: j           L_800ED018
    // 0x800ED000: nop

        goto L_800ED018;
    // 0x800ED000: nop

L_800ED004:
    // 0x800ED004: lw          $a1, 0x28($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X28);
    // 0x800ED008: jal         0x800F30AC
    // 0x800ED00C: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    func_800F30AC(rdram, ctx);
        goto after_4;
    // 0x800ED00C: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_4:
    // 0x800ED010: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800ED014: sw          $v0, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->r2;
L_800ED018:
    // 0x800ED018: jal         0x80047B48
    // 0x800ED01C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    getLevelDatItemByName(rdram, ctx);
        goto after_5;
    // 0x800ED01C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    after_5:
    // 0x800ED020: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800ED024: lbu         $a0, 0x2($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X2);
    // 0x800ED028: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x800ED02C: beq         $a0, $v0, L_800ED058
    if (ctx->r4 == ctx->r2) {
        // 0x800ED030: slti        $v0, $a0, 0x7
        ctx->r2 = SIGNED(ctx->r4) < 0X7 ? 1 : 0;
            goto L_800ED058;
    }
    // 0x800ED030: slti        $v0, $a0, 0x7
    ctx->r2 = SIGNED(ctx->r4) < 0X7 ? 1 : 0;
    // 0x800ED034: beq         $v0, $zero, L_800ED04C
    if (ctx->r2 == 0) {
        // 0x800ED038: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_800ED04C;
    }
    // 0x800ED038: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800ED03C: beq         $a0, $v0, L_800ED05C
    if (ctx->r4 == ctx->r2) {
        // 0x800ED040: addiu       $v0, $v1, 0x10
        ctx->r2 = ADD32(ctx->r3, 0X10);
            goto L_800ED05C;
    }
    // 0x800ED040: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
    // 0x800ED044: j           L_800ED064
    // 0x800ED048: sw          $zero, 0x114($sp)
    MEM_W(0X114, ctx->r29) = 0;
        goto L_800ED064;
    // 0x800ED048: sw          $zero, 0x114($sp)
    MEM_W(0X114, ctx->r29) = 0;
L_800ED04C:
    // 0x800ED04C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x800ED050: bnel        $a0, $v0, L_800ED064
    if (ctx->r4 != ctx->r2) {
        // 0x800ED054: sw          $zero, 0x114($sp)
        MEM_W(0X114, ctx->r29) = 0;
            goto L_800ED064;
    }
    goto skip_2;
    // 0x800ED054: sw          $zero, 0x114($sp)
    MEM_W(0X114, ctx->r29) = 0;
    skip_2:
L_800ED058:
    // 0x800ED058: addiu       $v0, $v1, 0x10
    ctx->r2 = ADD32(ctx->r3, 0X10);
L_800ED05C:
    // 0x800ED05C: sw          $v1, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r3;
    // 0x800ED060: sw          $v0, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r2;
L_800ED064:
    // 0x800ED064: lw          $v0, 0x114($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X114);
    // 0x800ED068: beq         $v0, $zero, L_800ED0E8
    if (ctx->r2 == 0) {
        // 0x800ED06C: nop
    
            goto L_800ED0E8;
    }
    // 0x800ED06C: nop

    // 0x800ED070: lw          $a0, 0x118($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X118);
    // 0x800ED074: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x800ED078: jal         0x800F2760
    // 0x800ED07C: nop

    func_800F2760(rdram, ctx);
        goto after_6;
    // 0x800ED07C: nop

    after_6:
    // 0x800ED080: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800ED084: bne         $v0, $zero, L_800ED0E8
    if (ctx->r2 != 0) {
        // 0x800ED088: addiu       $v0, $sp, 0x10
        ctx->r2 = ADD32(ctx->r29, 0X10);
            goto L_800ED0E8;
    }
    // 0x800ED088: addiu       $v0, $sp, 0x10
    ctx->r2 = ADD32(ctx->r29, 0X10);
    // 0x800ED08C: sw          $v0, 0x110($sp)
    MEM_W(0X110, ctx->r29) = ctx->r2;
    // 0x800ED090: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800ED094: lw          $a0, 0x80($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X80);
    // 0x800ED098: jal         0x80047B48
    // 0x800ED09C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    getLevelDatItemByName(rdram, ctx);
        goto after_7;
    // 0x800ED09C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    after_7:
    // 0x800ED0A0: sw          $v0, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r2;
    // 0x800ED0A4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800ED0A8: addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
    // 0x800ED0AC: sw          $v0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r2;
    // 0x800ED0B0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800ED0B4: addiu       $v0, $v0, 0x2C
    ctx->r2 = ADD32(ctx->r2, 0X2C);
    // 0x800ED0B8: sw          $v0, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r2;
    // 0x800ED0BC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x800ED0C0: lw          $v0, 0x2C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2C);
    // 0x800ED0C4: addiu       $a0, $sp, 0x110
    ctx->r4 = ADD32(ctx->r29, 0X110);
    // 0x800ED0C8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800ED0CC: jal         0x800656B4
    // 0x800ED0D0: sw          $v0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r2;
    func_800656B4(rdram, ctx);
        goto after_8;
    // 0x800ED0D0: sw          $v0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->r2;
    after_8:
    // 0x800ED0D4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800ED0D8: lwc1        $f0, 0x74($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X74);
    // 0x800ED0DC: j           L_800ED0E8
    // 0x800ED0E0: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
        goto L_800ED0E8;
    // 0x800ED0E0: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
L_800ED0E4:
    // 0x800ED0E4: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
L_800ED0E8:
    // 0x800ED0E8: jal         0x80047D40
    // 0x800ED0EC: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    func_80047D40(rdram, ctx);
        goto after_9;
    // 0x800ED0EC: addiu       $a0, $s0, 0x4
    ctx->r4 = ADD32(ctx->r16, 0X4);
    after_9:
    // 0x800ED0F0: beq         $v0, $zero, L_800ED100
    if (ctx->r2 == 0) {
        // 0x800ED0F4: nop
    
            goto L_800ED100;
    }
    // 0x800ED0F4: nop

    // 0x800ED0F8: j           L_800ED12C
    // 0x800ED0FC: sw          $zero, 0x38($s0)
    MEM_W(0X38, ctx->r16) = 0;
        goto L_800ED12C;
    // 0x800ED0FC: sw          $zero, 0x38($s0)
    MEM_W(0X38, ctx->r16) = 0;
L_800ED100:
    // 0x800ED100: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
    // 0x800ED104: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800ED108: sw          $v0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r2;
    // 0x800ED10C: slti        $v0, $v0, 0x15
    ctx->r2 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x800ED110: bne         $v0, $zero, L_800ED130
    if (ctx->r2 != 0) {
        // 0x800ED114: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800ED130;
    }
    // 0x800ED114: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800ED118: j           L_800ECF80
    // 0x800ED11C: nop

        goto L_800ECF80;
    // 0x800ED11C: nop

L_800ED120:
    // 0x800ED120: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800ED124: jal         0x800EFD80
    // 0x800ED128: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    func_800EFD80(rdram, ctx);
        goto after_10;
    // 0x800ED128: addu        $a1, $a2, $zero
    ctx->r5 = ADD32(ctx->r6, 0);
    after_10:
L_800ED12C:
    // 0x800ED12C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800ED130:
    // 0x800ED130: lw          $ra, 0x130($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X130);
    // 0x800ED134: lw          $s1, 0x12C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X12C);
    // 0x800ED138: lw          $s0, 0x128($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X128);
    // 0x800ED13C: ldc1        $f20, 0x138($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X138);
    // 0x800ED140: jr          $ra
    // 0x800ED144: addiu       $sp, $sp, 0x140
    ctx->r29 = ADD32(ctx->r29, 0X140);
    return;
    // 0x800ED144: addiu       $sp, $sp, 0x140
    ctx->r29 = ADD32(ctx->r29, 0X140);
;}
RECOMP_FUNC void fake_func_800ED148(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_800ED150(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ED150: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x800ED154: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x800ED158: addiu       $t0, $t1, -0x3F20
    ctx->r8 = ADD32(ctx->r9, -0X3F20);
    // 0x800ED15C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800ED160: addiu       $a2, $v0, -0x3D90
    ctx->r6 = ADD32(ctx->r2, -0X3D90);
L_800ED164:
    // 0x800ED164: lhu         $v0, 0x4($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X4);
    // 0x800ED168: lhu         $v1, 0x6($t0)
    ctx->r3 = MEM_HU(ctx->r8, 0X6);
    // 0x800ED16C: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x800ED170: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800ED174: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800ED178: bne         $a1, $v0, L_800ED194
    if (ctx->r5 != ctx->r2) {
        // 0x800ED17C: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_800ED194;
    }
    // 0x800ED17C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800ED180: lw          $v0, -0x3F20($t1)
    ctx->r2 = MEM_W(ctx->r9, -0X3F20);
    // 0x800ED184: sb          $a0, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r4;
    // 0x800ED188: sw          $zero, 0x8($a2)
    MEM_W(0X8, ctx->r6) = 0;
    // 0x800ED18C: jr          $ra
    // 0x800ED190: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    return;
    // 0x800ED190: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
L_800ED194:
    // 0x800ED194: slti        $v0, $a3, 0x8
    ctx->r2 = SIGNED(ctx->r7) < 0X8 ? 1 : 0;
    // 0x800ED198: bne         $v0, $zero, L_800ED164
    if (ctx->r2 != 0) {
        // 0x800ED19C: addiu       $a2, $a2, 0x10
        ctx->r6 = ADD32(ctx->r6, 0X10);
            goto L_800ED164;
    }
    // 0x800ED19C: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x800ED1A0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x800ED1A4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x800ED1A8: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x800ED1AC: addiu       $v1, $a2, -0x3F20
    ctx->r3 = ADD32(ctx->r6, -0X3F20);
    // 0x800ED1B0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800ED1B4: addiu       $a1, $v0, -0x3D90
    ctx->r5 = ADD32(ctx->r2, -0X3D90);
L_800ED1B8:
    // 0x800ED1B8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800ED1BC: bne         $v0, $t0, L_800ED1EC
    if (ctx->r2 != ctx->r8) {
        // 0x800ED1C0: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_800ED1EC;
    }
    // 0x800ED1C0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800ED1C4: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
    // 0x800ED1C8: lhu         $v1, 0x6($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X6);
    // 0x800ED1CC: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800ED1D0: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800ED1D4: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800ED1D8: lw          $v0, -0x3F20($a2)
    ctx->r2 = MEM_W(ctx->r6, -0X3F20);
    // 0x800ED1DC: sb          $a0, 0xC($a1)
    MEM_B(0XC, ctx->r5) = ctx->r4;
    // 0x800ED1E0: sw          $zero, 0x8($a1)
    MEM_W(0X8, ctx->r5) = 0;
    // 0x800ED1E4: jr          $ra
    // 0x800ED1E8: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
    return;
    // 0x800ED1E8: sw          $v0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r2;
L_800ED1EC:
    // 0x800ED1EC: slti        $v0, $a3, 0x8
    ctx->r2 = SIGNED(ctx->r7) < 0X8 ? 1 : 0;
    // 0x800ED1F0: bne         $v0, $zero, L_800ED1B8
    if (ctx->r2 != 0) {
        // 0x800ED1F4: addiu       $a1, $a1, 0x10
        ctx->r5 = ADD32(ctx->r5, 0X10);
            goto L_800ED1B8;
    }
    // 0x800ED1F4: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800ED1F8: jr          $ra
    // 0x800ED1FC: nop

    return;
    // 0x800ED1FC: nop

;}
RECOMP_FUNC void func_800ED200(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ED200: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800ED204: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800ED208: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800ED20C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800ED210: addiu       $v1, $v0, -0x3D90
    ctx->r3 = ADD32(ctx->r2, -0X3D90);
    // 0x800ED214: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800ED218: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x800ED21C: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x800ED220: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x800ED224: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x800ED228: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
L_800ED22C:
    // 0x800ED22C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800ED230: beq         $v0, $a1, L_800ED244
    if (ctx->r2 == ctx->r5) {
        // 0x800ED234: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800ED244;
    }
    // 0x800ED234: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800ED238: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800ED23C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800ED240: sw          $v0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r2;
L_800ED244:
    // 0x800ED244: slti        $v0, $a0, 0x8
    ctx->r2 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800ED248: bne         $v0, $zero, L_800ED22C
    if (ctx->r2 != 0) {
        // 0x800ED24C: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800ED22C;
    }
    // 0x800ED24C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800ED250: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800ED254: lbu         $v0, -0x3D9D($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X3D9D);
    // 0x800ED258: bne         $v0, $zero, L_800ED498
    if (ctx->r2 != 0) {
        // 0x800ED25C: lui         $t0, 0x8011
        ctx->r8 = S32(0X8011 << 16);
            goto L_800ED498;
    }
    // 0x800ED25C: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x800ED260: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800ED264: addiu       $a2, $v0, -0x3EC0
    ctx->r6 = ADD32(ctx->r2, -0X3EC0);
    // 0x800ED268: lh          $v0, 0xA($a2)
    ctx->r2 = MEM_H(ctx->r6, 0XA);
    // 0x800ED26C: bnel        $v0, $zero, L_800ED2D0
    if (ctx->r2 != 0) {
        // 0x800ED270: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_800ED2D0;
    }
    goto skip_0;
    // 0x800ED270: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    skip_0:
    // 0x800ED274: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800ED278: addiu       $v1, $v0, -0x3F20
    ctx->r3 = ADD32(ctx->r2, -0X3F20);
    // 0x800ED27C: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    // 0x800ED280: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
L_800ED284:
    // 0x800ED284: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800ED288: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x800ED28C: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x800ED290: lw          $t4, 0xC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XC);
    // 0x800ED294: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800ED298: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x800ED29C: sw          $t3, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r11;
    // 0x800ED2A0: sw          $t4, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r12;
    // 0x800ED2A4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800ED2A8: bne         $v0, $a0, L_800ED284
    if (ctx->r2 != ctx->r4) {
        // 0x800ED2AC: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800ED284;
    }
    // 0x800ED2AC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800ED2B0: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800ED2B4: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800ED2B8: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800ED2BC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800ED2C0: j           L_800EDB90
    // 0x800ED2C4: sw          $v0, -0x3F20($v1)
    MEM_W(-0X3F20, ctx->r3) = ctx->r2;
        goto L_800EDB90;
    // 0x800ED2C4: sw          $v0, -0x3F20($v1)
    MEM_W(-0X3F20, ctx->r3) = ctx->r2;
L_800ED2C8:
    // 0x800ED2C8: j           L_800ED304
    // 0x800ED2CC: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
        goto L_800ED304;
    // 0x800ED2CC: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
L_800ED2D0:
    // 0x800ED2D0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800ED2D4: addiu       $a0, $v0, -0x3D90
    ctx->r4 = ADD32(ctx->r2, -0X3D90);
    // 0x800ED2D8: lhu         $v0, 0x4($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X4);
    // 0x800ED2DC: lhu         $v1, 0x6($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X6);
    // 0x800ED2E0: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800ED2E4: or          $v1, $v0, $v1
    ctx->r3 = ctx->r2 | ctx->r3;
L_800ED2E8:
    // 0x800ED2E8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800ED2EC: beq         $v0, $v1, L_800ED2C8
    if (ctx->r2 == ctx->r3) {
        // 0x800ED2F0: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800ED2C8;
    }
    // 0x800ED2F0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800ED2F4: slti        $v0, $a1, 0x8
    ctx->r2 = SIGNED(ctx->r5) < 0X8 ? 1 : 0;
    // 0x800ED2F8: bne         $v0, $zero, L_800ED2E8
    if (ctx->r2 != 0) {
        // 0x800ED2FC: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_800ED2E8;
    }
    // 0x800ED2FC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800ED300: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_800ED304:
    // 0x800ED304: beq         $s0, $zero, L_800ED398
    if (ctx->r16 == 0) {
        // 0x800ED308: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800ED398;
    }
    // 0x800ED308: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800ED30C: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800ED310: jal         0x800957AC
    // 0x800ED314: nop

    func_800957AC(rdram, ctx);
        goto after_0;
    // 0x800ED314: nop

    after_0:
    // 0x800ED318: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800ED31C: beq         $v0, $zero, L_800ED370
    if (ctx->r2 == 0) {
        // 0x800ED320: nop
    
            goto L_800ED370;
    }
    // 0x800ED320: nop

    // 0x800ED324: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800ED328: jal         0x800960D0
    // 0x800ED32C: nop

    func_800960D0(rdram, ctx);
        goto after_1;
    // 0x800ED32C: nop

    after_1:
    // 0x800ED330: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800ED334: addiu       $v0, $v0, -0x3EC0
    ctx->r2 = ADD32(ctx->r2, -0X3EC0);
    // 0x800ED338: lbu         $a0, 0x8($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X8);
    // 0x800ED33C: lhu         $a1, 0x12($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X12);
    // 0x800ED340: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x800ED344: jal         0x800964C8
    // 0x800ED348: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_800964C8(rdram, ctx);
        goto after_2;
    // 0x800ED348: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_2:
    // 0x800ED34C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800ED350: lbu         $v1, -0x3D10($a0)
    ctx->r3 = MEM_BU(ctx->r4, -0X3D10);
    // 0x800ED354: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800ED358: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800ED35C: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800ED360: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x800ED364: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800ED368: j           L_800ED440
    // 0x800ED36C: sb          $v1, -0x3D10($a0)
    MEM_B(-0X3D10, ctx->r4) = ctx->r3;
        goto L_800ED440;
    // 0x800ED36C: sb          $v1, -0x3D10($a0)
    MEM_B(-0X3D10, ctx->r4) = ctx->r3;
L_800ED370:
    // 0x800ED370: beq         $s0, $zero, L_800ED394
    if (ctx->r16 == 0) {
        // 0x800ED374: lui         $a0, 0x8011
        ctx->r4 = S32(0X8011 << 16);
            goto L_800ED394;
    }
    // 0x800ED374: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800ED378: lbu         $v1, -0x3D10($a0)
    ctx->r3 = MEM_BU(ctx->r4, -0X3D10);
    // 0x800ED37C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800ED380: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800ED384: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800ED388: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x800ED38C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800ED390: sb          $v1, -0x3D10($a0)
    MEM_B(-0X3D10, ctx->r4) = ctx->r3;
L_800ED394:
    // 0x800ED394: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_800ED398:
    // 0x800ED398: lb          $v1, -0x3D10($v0)
    ctx->r3 = MEM_B(ctx->r2, -0X3D10);
    // 0x800ED39C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800ED3A0: bne         $v1, $v0, L_800ED408
    if (ctx->r3 != ctx->r2) {
        // 0x800ED3A4: lui         $s1, 0x8011
        ctx->r17 = S32(0X8011 << 16);
            goto L_800ED408;
    }
    // 0x800ED3A4: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x800ED3A8: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800ED3AC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800ED3B0: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800ED3B4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800ED3B8: addiu       $a1, $v0, -0x3D90
    ctx->r5 = ADD32(ctx->r2, -0X3D90);
L_800ED3BC:
    // 0x800ED3BC: lw          $v1, 0x8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X8);
    // 0x800ED3C0: sltu        $v0, $a2, $v1
    ctx->r2 = ctx->r6 < ctx->r3 ? 1 : 0;
    // 0x800ED3C4: beql        $v0, $zero, L_800ED3D8
    if (ctx->r2 == 0) {
        // 0x800ED3C8: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800ED3D8;
    }
    goto skip_1;
    // 0x800ED3C8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_1:
    // 0x800ED3CC: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    // 0x800ED3D0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800ED3D4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_800ED3D8:
    // 0x800ED3D8: slti        $v0, $a0, 0x8
    ctx->r2 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800ED3DC: bne         $v0, $zero, L_800ED3BC
    if (ctx->r2 != 0) {
        // 0x800ED3E0: addiu       $a1, $a1, 0x10
        ctx->r5 = ADD32(ctx->r5, 0X10);
            goto L_800ED3BC;
    }
    // 0x800ED3E0: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800ED3E4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800ED3E8: addiu       $v0, $v0, -0x3D90
    ctx->r2 = ADD32(ctx->r2, -0X3D90);
    // 0x800ED3EC: sll         $s0, $s0, 4
    ctx->r16 = S32(ctx->r16 << 4);
    // 0x800ED3F0: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x800ED3F4: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800ED3F8: jal         0x80095D58
    // 0x800ED3FC: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    func_80095D58(rdram, ctx);
        goto after_3;
    // 0x800ED3FC: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    after_3:
    // 0x800ED400: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800ED404: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
L_800ED408:
    // 0x800ED408: addiu       $s0, $s1, -0x3EC0
    ctx->r16 = ADD32(ctx->r17, -0X3EC0);
    // 0x800ED40C: lhu         $a0, 0x6($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X6);
    // 0x800ED410: jal         0x80066A18
    // 0x800ED414: nop

    func_80066A18(rdram, ctx);
        goto after_4;
    // 0x800ED414: nop

    after_4:
    // 0x800ED418: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x800ED41C: lhu         $a0, 0x4($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X4);
    // 0x800ED420: lhu         $a1, 0x6($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X6);
    // 0x800ED424: jal         0x80097C2C
    // 0x800ED428: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80097C2C(rdram, ctx);
        goto after_5;
    // 0x800ED428: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_5:
    // 0x800ED42C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800ED430: lbu         $a0, 0x8($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X8);
    // 0x800ED434: addiu       $a2, $zero, 0xFD
    ctx->r6 = ADD32(0, 0XFD);
    // 0x800ED438: jal         0x8008E0B0
    // 0x800ED43C: sw          $v0, -0x3EC0($s1)
    MEM_W(-0X3EC0, ctx->r17) = ctx->r2;
    func_8008E0B0(rdram, ctx);
        goto after_6;
    // 0x800ED43C: sw          $v0, -0x3EC0($s1)
    MEM_W(-0X3EC0, ctx->r17) = ctx->r2;
    after_6:
L_800ED440:
    // 0x800ED440: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800ED444: addiu       $v1, $v0, -0x3F20
    ctx->r3 = ADD32(ctx->r2, -0X3F20);
    // 0x800ED448: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800ED44C: addiu       $v0, $v0, -0x3EC0
    ctx->r2 = ADD32(ctx->r2, -0X3EC0);
    // 0x800ED450: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
L_800ED454:
    // 0x800ED454: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800ED458: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x800ED45C: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x800ED460: lw          $t4, 0xC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XC);
    // 0x800ED464: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800ED468: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x800ED46C: sw          $t3, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r11;
    // 0x800ED470: sw          $t4, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r12;
    // 0x800ED474: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800ED478: bne         $v0, $a0, L_800ED454
    if (ctx->r2 != ctx->r4) {
        // 0x800ED47C: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800ED454;
    }
    // 0x800ED47C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800ED480: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800ED484: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800ED488: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800ED48C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800ED490: j           L_800EDB90
    // 0x800ED494: sb          $v0, -0x3D9D($v1)
    MEM_B(-0X3D9D, ctx->r3) = ctx->r2;
        goto L_800EDB90;
    // 0x800ED494: sb          $v0, -0x3D9D($v1)
    MEM_B(-0X3D9D, ctx->r3) = ctx->r2;
L_800ED498:
    // 0x800ED498: addiu       $s0, $t0, -0x3EC0
    ctx->r16 = ADD32(ctx->r8, -0X3EC0);
    // 0x800ED49C: lh          $v0, 0xA($s0)
    ctx->r2 = MEM_H(ctx->r16, 0XA);
    // 0x800ED4A0: bne         $v0, $zero, L_800ED4E0
    if (ctx->r2 != 0) {
        // 0x800ED4A4: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800ED4E0;
    }
    // 0x800ED4A4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800ED4A8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800ED4AC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800ED4B0: lw          $a2, -0x3F20($v0)
    ctx->r6 = MEM_W(ctx->r2, -0X3F20);
    // 0x800ED4B4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800ED4B8: lhu         $a1, 0x10($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X10);
    // 0x800ED4BC: addu        $v1, $a3, $zero
    ctx->r3 = ADD32(ctx->r7, 0);
    // 0x800ED4C0: sb          $v1, -0x3DA0($v0)
    MEM_B(-0X3DA0, ctx->r2) = ctx->r3;
    // 0x800ED4C4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800ED4C8: sb          $v1, -0x3D9F($v0)
    MEM_B(-0X3D9F, ctx->r2) = ctx->r3;
    // 0x800ED4CC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800ED4D0: jal         0x800964C8
    // 0x800ED4D4: sw          $v0, -0x3EC0($t0)
    MEM_W(-0X3EC0, ctx->r8) = ctx->r2;
    func_800964C8(rdram, ctx);
        goto after_7;
    // 0x800ED4D4: sw          $v0, -0x3EC0($t0)
    MEM_W(-0X3EC0, ctx->r8) = ctx->r2;
    after_7:
    // 0x800ED4D8: j           L_800EDB90
    // 0x800ED4DC: nop

        goto L_800EDB90;
    // 0x800ED4DC: nop

L_800ED4E0:
    // 0x800ED4E0: lw          $a0, -0x3F20($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X3F20);
    // 0x800ED4E4: jal         0x800957AC
    // 0x800ED4E8: nop

    func_800957AC(rdram, ctx);
        goto after_8;
    // 0x800ED4E8: nop

    after_8:
    // 0x800ED4EC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800ED4F0: beq         $v0, $zero, L_800ED8A8
    if (ctx->r2 == 0) {
        // 0x800ED4F4: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_800ED8A8;
    }
    // 0x800ED4F4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800ED4F8: lbu         $v0, 0xC($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XC);
    // 0x800ED4FC: bne         $v0, $zero, L_800ED520
    if (ctx->r2 != 0) {
        // 0x800ED500: addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
            goto L_800ED520;
    }
    // 0x800ED500: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x800ED504: lbu         $v0, 0xD($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XD);
    // 0x800ED508: beq         $v0, $zero, L_800ED520
    if (ctx->r2 == 0) {
        // 0x800ED50C: addiu       $s3, $zero, 0x1
        ctx->r19 = ADD32(0, 0X1);
            goto L_800ED520;
    }
    // 0x800ED50C: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x800ED510: j           L_800ED520
    // 0x800ED514: addiu       $s3, $zero, 0x40
    ctx->r19 = ADD32(0, 0X40);
        goto L_800ED520;
    // 0x800ED514: addiu       $s3, $zero, 0x40
    ctx->r19 = ADD32(0, 0X40);
L_800ED518:
    // 0x800ED518: j           L_800ED570
    // 0x800ED51C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
        goto L_800ED570;
    // 0x800ED51C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
L_800ED520:
    // 0x800ED520: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800ED524: addiu       $a2, $v0, -0x3EC0
    ctx->r6 = ADD32(ctx->r2, -0X3EC0);
    // 0x800ED528: lbu         $v1, 0xF($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0XF);
    // 0x800ED52C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800ED530: beql        $v1, $v0, L_800ED538
    if (ctx->r3 == ctx->r2) {
        // 0x800ED534: ori         $s3, $s3, 0x4
        ctx->r19 = ctx->r19 | 0X4;
            goto L_800ED538;
    }
    goto skip_2;
    // 0x800ED534: ori         $s3, $s3, 0x4
    ctx->r19 = ctx->r19 | 0X4;
    skip_2:
L_800ED538:
    // 0x800ED538: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800ED53C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800ED540: addiu       $a0, $v0, -0x3D90
    ctx->r4 = ADD32(ctx->r2, -0X3D90);
    // 0x800ED544: lhu         $v0, 0x4($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X4);
    // 0x800ED548: lhu         $v1, 0x6($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X6);
    // 0x800ED54C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800ED550: or          $v1, $v0, $v1
    ctx->r3 = ctx->r2 | ctx->r3;
L_800ED554:
    // 0x800ED554: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800ED558: beq         $v0, $v1, L_800ED518
    if (ctx->r2 == ctx->r3) {
        // 0x800ED55C: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800ED518;
    }
    // 0x800ED55C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800ED560: slti        $v0, $a1, 0x8
    ctx->r2 = SIGNED(ctx->r5) < 0X8 ? 1 : 0;
    // 0x800ED564: bne         $v0, $zero, L_800ED554
    if (ctx->r2 != 0) {
        // 0x800ED568: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_800ED554;
    }
    // 0x800ED568: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800ED56C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_800ED570:
    // 0x800ED570: lui         $s4, 0x8011
    ctx->r20 = S32(0X8011 << 16);
    // 0x800ED574: addiu       $s1, $s4, -0x3EC0
    ctx->r17 = ADD32(ctx->r20, -0X3EC0);
    // 0x800ED578: lbu         $s2, 0xE($s1)
    ctx->r18 = MEM_BU(ctx->r17, 0XE);
    // 0x800ED57C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800ED580: bne         $s2, $v0, L_800ED6F4
    if (ctx->r18 != ctx->r2) {
        // 0x800ED584: nop
    
            goto L_800ED6F4;
    }
    // 0x800ED584: nop

    // 0x800ED588: bne         $s0, $zero, L_800ED604
    if (ctx->r16 != 0) {
        // 0x800ED58C: nop
    
            goto L_800ED604;
    }
    // 0x800ED58C: nop

    // 0x800ED590: lhu         $a0, 0x6($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X6);
    // 0x800ED594: jal         0x80066A18
    // 0x800ED598: nop

    func_80066A18(rdram, ctx);
        goto after_9;
    // 0x800ED598: nop

    after_9:
    // 0x800ED59C: lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X4);
    // 0x800ED5A0: lhu         $a0, 0x6($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X6);
    // 0x800ED5A4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800ED5A8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800ED5AC: sh          $v1, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r3;
    // 0x800ED5B0: lb          $v1, -0x3D10($v0)
    ctx->r3 = MEM_B(ctx->r2, -0X3D10);
    // 0x800ED5B4: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800ED5B8: bne         $v1, $v0, L_800ED7B8
    if (ctx->r3 != ctx->r2) {
        // 0x800ED5BC: sh          $a0, 0x26($sp)
        MEM_H(0X26, ctx->r29) = ctx->r4;
            goto L_800ED7B8;
    }
    // 0x800ED5BC: sh          $a0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r4;
    // 0x800ED5C0: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800ED5C4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800ED5C8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800ED5CC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800ED5D0: addiu       $a1, $v0, -0x3D90
    ctx->r5 = ADD32(ctx->r2, -0X3D90);
L_800ED5D4:
    // 0x800ED5D4: lw          $v1, 0x8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X8);
    // 0x800ED5D8: sltu        $v0, $a2, $v1
    ctx->r2 = ctx->r6 < ctx->r3 ? 1 : 0;
    // 0x800ED5DC: beql        $v0, $zero, L_800ED5F0
    if (ctx->r2 == 0) {
        // 0x800ED5E0: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800ED5F0;
    }
    goto skip_3;
    // 0x800ED5E0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_3:
    // 0x800ED5E4: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    // 0x800ED5E8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800ED5EC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_800ED5F0:
    // 0x800ED5F0: slti        $v0, $a0, 0x8
    ctx->r2 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800ED5F4: bne         $v0, $zero, L_800ED5D4
    if (ctx->r2 != 0) {
        // 0x800ED5F8: addiu       $a1, $a1, 0x10
        ctx->r5 = ADD32(ctx->r5, 0X10);
            goto L_800ED5D4;
    }
    // 0x800ED5F8: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800ED5FC: j           L_800ED798
    // 0x800ED600: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
        goto L_800ED798;
    // 0x800ED600: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_800ED604:
    // 0x800ED604: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800ED608: jal         0x800957AC
    // 0x800ED60C: nop

    func_800957AC(rdram, ctx);
        goto after_10;
    // 0x800ED60C: nop

    after_10:
    // 0x800ED610: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800ED614: beq         $v0, $zero, L_800ED66C
    if (ctx->r2 == 0) {
        // 0x800ED618: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_800ED66C;
    }
    // 0x800ED618: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800ED61C: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800ED620: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800ED624: lbu         $v0, 0xC($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XC);
    // 0x800ED628: bne         $v0, $s2, L_800ED640
    if (ctx->r2 != ctx->r18) {
        // 0x800ED62C: ori         $s3, $s3, 0x2
        ctx->r19 = ctx->r19 | 0X2;
            goto L_800ED640;
    }
    // 0x800ED62C: ori         $s3, $s3, 0x2
    ctx->r19 = ctx->r19 | 0X2;
    // 0x800ED630: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800ED634: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800ED638: jal         0x8009621C
    // 0x800ED63C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    func_8009621C(rdram, ctx);
        goto after_11;
    // 0x800ED63C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_11:
L_800ED640:
    // 0x800ED640: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800ED644: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800ED648: lbu         $v1, -0x3D10($a0)
    ctx->r3 = MEM_BU(ctx->r4, -0X3D10);
    // 0x800ED64C: sw          $v0, -0x3EC0($s4)
    MEM_W(-0X3EC0, ctx->r20) = ctx->r2;
    // 0x800ED650: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800ED654: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800ED658: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800ED65C: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800ED660: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x800ED664: j           L_800ED7B8
    // 0x800ED668: sb          $v1, -0x3D10($a0)
    MEM_B(-0X3D10, ctx->r4) = ctx->r3;
        goto L_800ED7B8;
    // 0x800ED668: sb          $v1, -0x3D10($a0)
    MEM_B(-0X3D10, ctx->r4) = ctx->r3;
L_800ED66C:
    // 0x800ED66C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800ED670: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800ED674: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x800ED678: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800ED67C: lbu         $v0, -0x3D10($s0)
    ctx->r2 = MEM_BU(ctx->r16, -0X3D10);
    // 0x800ED680: lhu         $a0, 0x6($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X6);
    // 0x800ED684: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800ED688: jal         0x80066A18
    // 0x800ED68C: sb          $v0, -0x3D10($s0)
    MEM_B(-0X3D10, ctx->r16) = ctx->r2;
    func_80066A18(rdram, ctx);
        goto after_12;
    // 0x800ED68C: sb          $v0, -0x3D10($s0)
    MEM_B(-0X3D10, ctx->r16) = ctx->r2;
    after_12:
    // 0x800ED690: lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X4);
    // 0x800ED694: lhu         $a0, 0x6($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X6);
    // 0x800ED698: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800ED69C: sh          $v1, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r3;
    // 0x800ED6A0: lb          $v1, -0x3D10($s0)
    ctx->r3 = MEM_B(ctx->r16, -0X3D10);
    // 0x800ED6A4: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800ED6A8: bne         $v1, $v0, L_800ED7B8
    if (ctx->r3 != ctx->r2) {
        // 0x800ED6AC: sh          $a0, 0x26($sp)
        MEM_H(0X26, ctx->r29) = ctx->r4;
            goto L_800ED7B8;
    }
    // 0x800ED6AC: sh          $a0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r4;
    // 0x800ED6B0: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800ED6B4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800ED6B8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800ED6BC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800ED6C0: addiu       $a1, $v0, -0x3D90
    ctx->r5 = ADD32(ctx->r2, -0X3D90);
L_800ED6C4:
    // 0x800ED6C4: lw          $v1, 0x8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X8);
    // 0x800ED6C8: sltu        $v0, $a2, $v1
    ctx->r2 = ctx->r6 < ctx->r3 ? 1 : 0;
    // 0x800ED6CC: beql        $v0, $zero, L_800ED6E0
    if (ctx->r2 == 0) {
        // 0x800ED6D0: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800ED6E0;
    }
    goto skip_4;
    // 0x800ED6D0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_4:
    // 0x800ED6D4: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    // 0x800ED6D8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800ED6DC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_800ED6E0:
    // 0x800ED6E0: slti        $v0, $a0, 0x8
    ctx->r2 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800ED6E4: bne         $v0, $zero, L_800ED6C4
    if (ctx->r2 != 0) {
        // 0x800ED6E8: addiu       $a1, $a1, 0x10
        ctx->r5 = ADD32(ctx->r5, 0X10);
            goto L_800ED6C4;
    }
    // 0x800ED6E8: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800ED6EC: j           L_800ED798
    // 0x800ED6F0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
        goto L_800ED798;
    // 0x800ED6F0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_800ED6F4:
    // 0x800ED6F4: beq         $s0, $zero, L_800ED728
    if (ctx->r16 == 0) {
        // 0x800ED6F8: nop
    
            goto L_800ED728;
    }
    // 0x800ED6F8: nop

    // 0x800ED6FC: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800ED700: jal         0x80095D58
    // 0x800ED704: nop

    func_80095D58(rdram, ctx);
        goto after_13;
    // 0x800ED704: nop

    after_13:
    // 0x800ED708: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800ED70C: lbu         $v1, -0x3D10($a0)
    ctx->r3 = MEM_BU(ctx->r4, -0X3D10);
    // 0x800ED710: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800ED714: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800ED718: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800ED71C: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x800ED720: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800ED724: sb          $v1, -0x3D10($a0)
    MEM_B(-0X3D10, ctx->r4) = ctx->r3;
L_800ED728:
    // 0x800ED728: lhu         $a0, 0x6($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X6);
    // 0x800ED72C: jal         0x80066A18
    // 0x800ED730: nop

    func_80066A18(rdram, ctx);
        goto after_14;
    // 0x800ED730: nop

    after_14:
    // 0x800ED734: lhu         $v1, 0x4($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X4);
    // 0x800ED738: lhu         $a0, 0x6($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X6);
    // 0x800ED73C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800ED740: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800ED744: sh          $v1, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r3;
    // 0x800ED748: lb          $v1, -0x3D10($v0)
    ctx->r3 = MEM_B(ctx->r2, -0X3D10);
    // 0x800ED74C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800ED750: bne         $v1, $v0, L_800ED7B8
    if (ctx->r3 != ctx->r2) {
        // 0x800ED754: sh          $a0, 0x26($sp)
        MEM_H(0X26, ctx->r29) = ctx->r4;
            goto L_800ED7B8;
    }
    // 0x800ED754: sh          $a0, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r4;
    // 0x800ED758: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800ED75C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800ED760: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800ED764: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800ED768: addiu       $a1, $v0, -0x3D90
    ctx->r5 = ADD32(ctx->r2, -0X3D90);
L_800ED76C:
    // 0x800ED76C: lw          $v1, 0x8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X8);
    // 0x800ED770: sltu        $v0, $a2, $v1
    ctx->r2 = ctx->r6 < ctx->r3 ? 1 : 0;
    // 0x800ED774: beql        $v0, $zero, L_800ED788
    if (ctx->r2 == 0) {
        // 0x800ED778: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800ED788;
    }
    goto skip_5;
    // 0x800ED778: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_5:
    // 0x800ED77C: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    // 0x800ED780: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800ED784: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_800ED788:
    // 0x800ED788: slti        $v0, $a0, 0x8
    ctx->r2 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800ED78C: bne         $v0, $zero, L_800ED76C
    if (ctx->r2 != 0) {
        // 0x800ED790: addiu       $a1, $a1, 0x10
        ctx->r5 = ADD32(ctx->r5, 0X10);
            goto L_800ED76C;
    }
    // 0x800ED790: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800ED794: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_800ED798:
    // 0x800ED798: addiu       $v0, $v0, -0x3D90
    ctx->r2 = ADD32(ctx->r2, -0X3D90);
    // 0x800ED79C: sll         $s0, $s0, 4
    ctx->r16 = S32(ctx->r16 << 4);
    // 0x800ED7A0: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x800ED7A4: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800ED7A8: jal         0x80095D58
    // 0x800ED7AC: nop

    func_80095D58(rdram, ctx);
        goto after_15;
    // 0x800ED7AC: nop

    after_15:
    // 0x800ED7B0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800ED7B4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
L_800ED7B8:
    // 0x800ED7B8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800ED7BC: lbu         $v0, -0x3EB4($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X3EB4);
    // 0x800ED7C0: bne         $v0, $zero, L_800ED850
    if (ctx->r2 != 0) {
        // 0x800ED7C4: addiu       $a0, $sp, 0x10
        ctx->r4 = ADD32(ctx->r29, 0X10);
            goto L_800ED850;
    }
    // 0x800ED7C4: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800ED7C8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800ED7CC: lb          $v1, -0x3D10($v0)
    ctx->r3 = MEM_B(ctx->r2, -0X3D10);
    // 0x800ED7D0: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800ED7D4: bne         $v1, $v0, L_800ED840
    if (ctx->r3 != ctx->r2) {
        // 0x800ED7D8: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800ED840;
    }
    // 0x800ED7D8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800ED7DC: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800ED7E0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800ED7E4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800ED7E8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800ED7EC: addiu       $a1, $v0, -0x3D90
    ctx->r5 = ADD32(ctx->r2, -0X3D90);
L_800ED7F0:
    // 0x800ED7F0: lw          $v1, 0x8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X8);
    // 0x800ED7F4: sltu        $v0, $a2, $v1
    ctx->r2 = ctx->r6 < ctx->r3 ? 1 : 0;
    // 0x800ED7F8: beql        $v0, $zero, L_800ED80C
    if (ctx->r2 == 0) {
        // 0x800ED7FC: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800ED80C;
    }
    goto skip_6;
    // 0x800ED7FC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_6:
    // 0x800ED800: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    // 0x800ED804: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800ED808: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_800ED80C:
    // 0x800ED80C: slti        $v0, $a0, 0x8
    ctx->r2 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800ED810: bne         $v0, $zero, L_800ED7F0
    if (ctx->r2 != 0) {
        // 0x800ED814: addiu       $a1, $a1, 0x10
        ctx->r5 = ADD32(ctx->r5, 0X10);
            goto L_800ED7F0;
    }
    // 0x800ED814: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800ED818: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800ED81C: addiu       $v0, $v0, -0x3D90
    ctx->r2 = ADD32(ctx->r2, -0X3D90);
    // 0x800ED820: sll         $s0, $s0, 4
    ctx->r16 = S32(ctx->r16 << 4);
    // 0x800ED824: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x800ED828: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800ED82C: jal         0x80095D58
    // 0x800ED830: nop

    func_80095D58(rdram, ctx);
        goto after_16;
    // 0x800ED830: nop

    after_16:
    // 0x800ED834: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800ED838: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800ED83C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_800ED840:
    // 0x800ED840: lbu         $a0, -0x3EB3($v0)
    ctx->r4 = MEM_BU(ctx->r2, -0X3EB3);
    // 0x800ED844: jal         0x800ED150
    // 0x800ED848: nop

    func_800ED150(rdram, ctx);
        goto after_17;
    // 0x800ED848: nop

    after_17:
    // 0x800ED84C: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
L_800ED850:
    // 0x800ED850: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800ED854: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800ED858: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800ED85C: sb          $v0, -0x3DA0($v1)
    MEM_B(-0X3DA0, ctx->r3) = ctx->r2;
    // 0x800ED860: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800ED864: lw          $v1, -0x3F20($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X3F20);
    // 0x800ED868: addiu       $a1, $a1, -0x3EC0
    ctx->r5 = ADD32(ctx->r5, -0X3EC0);
    // 0x800ED86C: sb          $s3, 0x36($sp)
    MEM_B(0X36, ctx->r29) = ctx->r19;
    // 0x800ED870: lhu         $a2, 0x10($a1)
    ctx->r6 = MEM_HU(ctx->r5, 0X10);
    // 0x800ED874: lhu         $a3, 0x12($a1)
    ctx->r7 = MEM_HU(ctx->r5, 0X12);
    // 0x800ED878: lbu         $t0, 0x8($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X8);
    // 0x800ED87C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800ED880: sb          $zero, -0x3D9F($v0)
    MEM_B(-0X3D9F, ctx->r2) = 0;
    // 0x800ED884: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x800ED888: sh          $a2, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r6;
    // 0x800ED88C: sh          $a3, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r7;
    // 0x800ED890: jal         0x80096C88
    // 0x800ED894: sb          $t0, 0x28($sp)
    MEM_B(0X28, ctx->r29) = ctx->r8;
    func_80096C88(rdram, ctx);
        goto after_18;
    // 0x800ED894: sb          $t0, 0x28($sp)
    MEM_B(0X28, ctx->r29) = ctx->r8;
    after_18:
    // 0x800ED898: j           L_800EDB90
    // 0x800ED89C: nop

        goto L_800EDB90;
    // 0x800ED89C: nop

L_800ED8A0:
    // 0x800ED8A0: j           L_800ED8DC
    // 0x800ED8A4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
        goto L_800ED8DC;
    // 0x800ED8A4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
L_800ED8A8:
    // 0x800ED8A8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800ED8AC: addiu       $a0, $v0, -0x3D90
    ctx->r4 = ADD32(ctx->r2, -0X3D90);
    // 0x800ED8B0: lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4);
    // 0x800ED8B4: lhu         $v1, 0x6($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X6);
    // 0x800ED8B8: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800ED8BC: or          $v1, $v0, $v1
    ctx->r3 = ctx->r2 | ctx->r3;
L_800ED8C0:
    // 0x800ED8C0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800ED8C4: beq         $v0, $v1, L_800ED8A0
    if (ctx->r2 == ctx->r3) {
        // 0x800ED8C8: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800ED8A0;
    }
    // 0x800ED8C8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800ED8CC: slti        $v0, $a1, 0x8
    ctx->r2 = SIGNED(ctx->r5) < 0X8 ? 1 : 0;
    // 0x800ED8D0: bne         $v0, $zero, L_800ED8C0
    if (ctx->r2 != 0) {
        // 0x800ED8D4: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_800ED8C0;
    }
    // 0x800ED8D4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800ED8D8: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_800ED8DC:
    // 0x800ED8DC: lui         $s3, 0x8011
    ctx->r19 = S32(0X8011 << 16);
    // 0x800ED8E0: addiu       $s2, $s3, -0x3EC0
    ctx->r18 = ADD32(ctx->r19, -0X3EC0);
    // 0x800ED8E4: lbu         $s1, 0xE($s2)
    ctx->r17 = MEM_BU(ctx->r18, 0XE);
    // 0x800ED8E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800ED8EC: bne         $s1, $v0, L_800EDA40
    if (ctx->r17 != ctx->r2) {
        // 0x800ED8F0: nop
    
            goto L_800EDA40;
    }
    // 0x800ED8F0: nop

    // 0x800ED8F4: bne         $s0, $zero, L_800ED950
    if (ctx->r16 != 0) {
        // 0x800ED8F8: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800ED950;
    }
    // 0x800ED8F8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800ED8FC: lb          $v1, -0x3D10($v0)
    ctx->r3 = MEM_B(ctx->r2, -0X3D10);
    // 0x800ED900: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800ED904: bnel        $v1, $v0, L_800EDB00
    if (ctx->r3 != ctx->r2) {
        // 0x800ED908: lui         $s1, 0x8011
        ctx->r17 = S32(0X8011 << 16);
            goto L_800EDB00;
    }
    goto skip_7;
    // 0x800ED908: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    skip_7:
    // 0x800ED90C: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800ED910: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800ED914: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800ED918: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800ED91C: addiu       $a1, $v0, -0x3D90
    ctx->r5 = ADD32(ctx->r2, -0X3D90);
L_800ED920:
    // 0x800ED920: lw          $v1, 0x8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X8);
    // 0x800ED924: sltu        $v0, $a2, $v1
    ctx->r2 = ctx->r6 < ctx->r3 ? 1 : 0;
    // 0x800ED928: beql        $v0, $zero, L_800ED93C
    if (ctx->r2 == 0) {
        // 0x800ED92C: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800ED93C;
    }
    goto skip_8;
    // 0x800ED92C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_8:
    // 0x800ED930: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    // 0x800ED934: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800ED938: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_800ED93C:
    // 0x800ED93C: slti        $v0, $a0, 0x8
    ctx->r2 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800ED940: bne         $v0, $zero, L_800ED920
    if (ctx->r2 != 0) {
        // 0x800ED944: addiu       $a1, $a1, 0x10
        ctx->r5 = ADD32(ctx->r5, 0X10);
            goto L_800ED920;
    }
    // 0x800ED944: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800ED948: j           L_800EDAE0
    // 0x800ED94C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
        goto L_800EDAE0;
    // 0x800ED94C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_800ED950:
    // 0x800ED950: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800ED954: jal         0x800957AC
    // 0x800ED958: nop

    func_800957AC(rdram, ctx);
        goto after_19;
    // 0x800ED958: nop

    after_19:
    // 0x800ED95C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800ED960: beq         $v0, $zero, L_800ED9CC
    if (ctx->r2 == 0) {
        // 0x800ED964: lui         $a0, 0x8011
        ctx->r4 = S32(0X8011 << 16);
            goto L_800ED9CC;
    }
    // 0x800ED964: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800ED968: lbu         $v0, 0xC($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XC);
    // 0x800ED96C: bne         $v0, $s1, L_800ED980
    if (ctx->r2 != ctx->r17) {
        // 0x800ED970: addiu       $a1, $zero, -0x1
        ctx->r5 = ADD32(0, -0X1);
            goto L_800ED980;
    }
    // 0x800ED970: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800ED974: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800ED978: jal         0x8009621C
    // 0x800ED97C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    func_8009621C(rdram, ctx);
        goto after_20;
    // 0x800ED97C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_20:
L_800ED980:
    // 0x800ED980: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800ED984: jal         0x800960D0
    // 0x800ED988: nop

    func_800960D0(rdram, ctx);
        goto after_21;
    // 0x800ED988: nop

    after_21:
    // 0x800ED98C: lbu         $a0, 0x8($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X8);
    // 0x800ED990: lhu         $a1, 0x12($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X12);
    // 0x800ED994: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x800ED998: jal         0x800964C8
    // 0x800ED99C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_800964C8(rdram, ctx);
        goto after_22;
    // 0x800ED99C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_22:
    // 0x800ED9A0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800ED9A4: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800ED9A8: lbu         $v1, -0x3D10($a0)
    ctx->r3 = MEM_BU(ctx->r4, -0X3D10);
    // 0x800ED9AC: sw          $v0, -0x3EC0($s3)
    MEM_W(-0X3EC0, ctx->r19) = ctx->r2;
    // 0x800ED9B0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800ED9B4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800ED9B8: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800ED9BC: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800ED9C0: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x800ED9C4: j           L_800EDB38
    // 0x800ED9C8: sb          $v1, -0x3D10($a0)
    MEM_B(-0X3D10, ctx->r4) = ctx->r3;
        goto L_800EDB38;
    // 0x800ED9C8: sb          $v1, -0x3D10($a0)
    MEM_B(-0X3D10, ctx->r4) = ctx->r3;
L_800ED9CC:
    // 0x800ED9CC: lbu         $v0, -0x3D10($a0)
    ctx->r2 = MEM_BU(ctx->r4, -0X3D10);
    // 0x800ED9D0: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800ED9D4: sw          $v1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r3;
    // 0x800ED9D8: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800ED9DC: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x800ED9E0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800ED9E4: sb          $v0, -0x3D10($a0)
    MEM_B(-0X3D10, ctx->r4) = ctx->r2;
    // 0x800ED9E8: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x800ED9EC: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x800ED9F0: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
    // 0x800ED9F4: bne         $v0, $v1, L_800EDB00
    if (ctx->r2 != ctx->r3) {
        // 0x800ED9F8: lui         $s1, 0x8011
        ctx->r17 = S32(0X8011 << 16);
            goto L_800EDB00;
    }
    // 0x800ED9F8: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x800ED9FC: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800EDA00: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800EDA04: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800EDA08: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EDA0C: addiu       $a1, $v0, -0x3D90
    ctx->r5 = ADD32(ctx->r2, -0X3D90);
L_800EDA10:
    // 0x800EDA10: lw          $v1, 0x8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X8);
    // 0x800EDA14: sltu        $v0, $a2, $v1
    ctx->r2 = ctx->r6 < ctx->r3 ? 1 : 0;
    // 0x800EDA18: beql        $v0, $zero, L_800EDA2C
    if (ctx->r2 == 0) {
        // 0x800EDA1C: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800EDA2C;
    }
    goto skip_9;
    // 0x800EDA1C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_9:
    // 0x800EDA20: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    // 0x800EDA24: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800EDA28: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_800EDA2C:
    // 0x800EDA2C: slti        $v0, $a0, 0x8
    ctx->r2 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800EDA30: bne         $v0, $zero, L_800EDA10
    if (ctx->r2 != 0) {
        // 0x800EDA34: addiu       $a1, $a1, 0x10
        ctx->r5 = ADD32(ctx->r5, 0X10);
            goto L_800EDA10;
    }
    // 0x800EDA34: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800EDA38: j           L_800EDAE0
    // 0x800EDA3C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
        goto L_800EDAE0;
    // 0x800EDA3C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_800EDA40:
    // 0x800EDA40: beq         $s0, $zero, L_800EDA90
    if (ctx->r16 == 0) {
        // 0x800EDA44: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800EDA90;
    }
    // 0x800EDA44: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EDA48: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800EDA4C: jal         0x800957AC
    // 0x800EDA50: nop

    func_800957AC(rdram, ctx);
        goto after_23;
    // 0x800EDA50: nop

    after_23:
    // 0x800EDA54: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800EDA58: beq         $v0, $zero, L_800EDA70
    if (ctx->r2 == 0) {
        // 0x800EDA5C: lui         $a0, 0x8011
        ctx->r4 = S32(0X8011 << 16);
            goto L_800EDA70;
    }
    // 0x800EDA5C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800EDA60: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800EDA64: jal         0x80095D58
    // 0x800EDA68: nop

    func_80095D58(rdram, ctx);
        goto after_24;
    // 0x800EDA68: nop

    after_24:
    // 0x800EDA6C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
L_800EDA70:
    // 0x800EDA70: lbu         $v1, -0x3D10($a0)
    ctx->r3 = MEM_BU(ctx->r4, -0X3D10);
    // 0x800EDA74: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800EDA78: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800EDA7C: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800EDA80: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x800EDA84: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800EDA88: sb          $v1, -0x3D10($a0)
    MEM_B(-0X3D10, ctx->r4) = ctx->r3;
    // 0x800EDA8C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_800EDA90:
    // 0x800EDA90: lb          $v1, -0x3D10($v0)
    ctx->r3 = MEM_B(ctx->r2, -0X3D10);
    // 0x800EDA94: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800EDA98: bne         $v1, $v0, L_800EDB00
    if (ctx->r3 != ctx->r2) {
        // 0x800EDA9C: lui         $s1, 0x8011
        ctx->r17 = S32(0X8011 << 16);
            goto L_800EDB00;
    }
    // 0x800EDA9C: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x800EDAA0: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800EDAA4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800EDAA8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800EDAAC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EDAB0: addiu       $a1, $v0, -0x3D90
    ctx->r5 = ADD32(ctx->r2, -0X3D90);
L_800EDAB4:
    // 0x800EDAB4: lw          $v1, 0x8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X8);
    // 0x800EDAB8: sltu        $v0, $a2, $v1
    ctx->r2 = ctx->r6 < ctx->r3 ? 1 : 0;
    // 0x800EDABC: beql        $v0, $zero, L_800EDAD0
    if (ctx->r2 == 0) {
        // 0x800EDAC0: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800EDAD0;
    }
    goto skip_10;
    // 0x800EDAC0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_10:
    // 0x800EDAC4: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    // 0x800EDAC8: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800EDACC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_800EDAD0:
    // 0x800EDAD0: slti        $v0, $a0, 0x8
    ctx->r2 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800EDAD4: bne         $v0, $zero, L_800EDAB4
    if (ctx->r2 != 0) {
        // 0x800EDAD8: addiu       $a1, $a1, 0x10
        ctx->r5 = ADD32(ctx->r5, 0X10);
            goto L_800EDAB4;
    }
    // 0x800EDAD8: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800EDADC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_800EDAE0:
    // 0x800EDAE0: addiu       $v0, $v0, -0x3D90
    ctx->r2 = ADD32(ctx->r2, -0X3D90);
    // 0x800EDAE4: sll         $s0, $s0, 4
    ctx->r16 = S32(ctx->r16 << 4);
    // 0x800EDAE8: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x800EDAEC: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800EDAF0: jal         0x80095D58
    // 0x800EDAF4: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    func_80095D58(rdram, ctx);
        goto after_25;
    // 0x800EDAF4: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    after_25:
    // 0x800EDAF8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800EDAFC: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
L_800EDB00:
    // 0x800EDB00: addiu       $s0, $s1, -0x3EC0
    ctx->r16 = ADD32(ctx->r17, -0X3EC0);
    // 0x800EDB04: lhu         $a0, 0x6($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X6);
    // 0x800EDB08: jal         0x80066A18
    // 0x800EDB0C: nop

    func_80066A18(rdram, ctx);
        goto after_26;
    // 0x800EDB0C: nop

    after_26:
    // 0x800EDB10: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x800EDB14: lhu         $a0, 0x4($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X4);
    // 0x800EDB18: lhu         $a1, 0x6($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X6);
    // 0x800EDB1C: jal         0x80097C2C
    // 0x800EDB20: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    func_80097C2C(rdram, ctx);
        goto after_27;
    // 0x800EDB20: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_27:
    // 0x800EDB24: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800EDB28: lbu         $a0, 0x8($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X8);
    // 0x800EDB2C: addiu       $a2, $zero, 0xFD
    ctx->r6 = ADD32(0, 0XFD);
    // 0x800EDB30: jal         0x8008E0B0
    // 0x800EDB34: sw          $v0, -0x3EC0($s1)
    MEM_W(-0X3EC0, ctx->r17) = ctx->r2;
    func_8008E0B0(rdram, ctx);
        goto after_28;
    // 0x800EDB34: sw          $v0, -0x3EC0($s1)
    MEM_W(-0X3EC0, ctx->r17) = ctx->r2;
    after_28:
L_800EDB38:
    // 0x800EDB38: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EDB3C: addiu       $v1, $v0, -0x3F20
    ctx->r3 = ADD32(ctx->r2, -0X3F20);
    // 0x800EDB40: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EDB44: addiu       $v0, $v0, -0x3EC0
    ctx->r2 = ADD32(ctx->r2, -0X3EC0);
    // 0x800EDB48: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
L_800EDB4C:
    // 0x800EDB4C: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800EDB50: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x800EDB54: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x800EDB58: lw          $t4, 0xC($v0)
    ctx->r12 = MEM_W(ctx->r2, 0XC);
    // 0x800EDB5C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800EDB60: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x800EDB64: sw          $t3, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r11;
    // 0x800EDB68: sw          $t4, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r12;
    // 0x800EDB6C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800EDB70: bne         $v0, $a0, L_800EDB4C
    if (ctx->r2 != ctx->r4) {
        // 0x800EDB74: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800EDB4C;
    }
    // 0x800EDB74: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800EDB78: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800EDB7C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800EDB80: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EDB84: sb          $zero, -0x3DA0($v0)
    MEM_B(-0X3DA0, ctx->r2) = 0;
    // 0x800EDB88: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EDB8C: sb          $zero, -0x3D9F($v0)
    MEM_B(-0X3D9F, ctx->r2) = 0;
L_800EDB90:
    // 0x800EDB90: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800EDB94: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x800EDB98: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x800EDB9C: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x800EDBA0: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x800EDBA4: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800EDBA8: jr          $ra
    // 0x800EDBAC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800EDBAC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_800EDBB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EDBB0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EDBB4: lbu         $v1, -0x3D0F($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X3D0F);
    // 0x800EDBB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EDBBC: bne         $v1, $v0, L_800EDC50
    if (ctx->r3 != ctx->r2) {
        // 0x800EDBC0: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800EDC50;
    }
    // 0x800EDBC0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800EDBC4: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800EDBC8: lbu         $v0, -0x3D0B($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X3D0B);
    // 0x800EDBCC: beq         $v0, $zero, L_800EDBFC
    if (ctx->r2 == 0) {
        // 0x800EDBD0: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800EDBFC;
    }
    // 0x800EDBD0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800EDBD4: lbu         $v1, -0x3D0B($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X3D0B);
    // 0x800EDBD8: addiu       $v0, $v0, -0x7760
    ctx->r2 = ADD32(ctx->r2, -0X7760);
    // 0x800EDBDC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800EDBE0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EDBE4: lbu         $v1, -0x1($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X1);
    // 0x800EDBE8: lbu         $v0, -0x3D0A($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X3D0A);
    // 0x800EDBEC: beq         $v1, $v0, L_800EDC0C
    if (ctx->r3 == ctx->r2) {
        // 0x800EDBF0: lui         $a1, 0x8011
        ctx->r5 = S32(0X8011 << 16);
            goto L_800EDC0C;
    }
    // 0x800EDBF0: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800EDBF4: jr          $ra
    // 0x800EDBF8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x800EDBF8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800EDBFC:
    // 0x800EDBFC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EDC00: lbu         $v0, -0x3D09($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X3D09);
    // 0x800EDC04: beq         $v0, $zero, L_800EDC84
    if (ctx->r2 == 0) {
        // 0x800EDC08: lui         $a1, 0x8011
        ctx->r5 = S32(0X8011 << 16);
            goto L_800EDC84;
    }
    // 0x800EDC08: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
L_800EDC0C:
    // 0x800EDC0C: lbu         $v0, -0x3D09($a1)
    ctx->r2 = MEM_BU(ctx->r5, -0X3D09);
    // 0x800EDC10: beq         $v0, $zero, L_800EDC7C
    if (ctx->r2 == 0) {
        // 0x800EDC14: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800EDC7C;
    }
    // 0x800EDC14: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EDC18: lw          $a0, -0x3D08($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X3D08);
    // 0x800EDC1C: bgez        $a0, L_800EDC58
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800EDC20: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800EDC58;
    }
    // 0x800EDC20: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800EDC24: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800EDC28: lbu         $v0, -0x3D09($a1)
    ctx->r2 = MEM_BU(ctx->r5, -0X3D09);
    // 0x800EDC2C: addiu       $v1, $v1, -0x7FA0
    ctx->r3 = ADD32(ctx->r3, -0X7FA0);
    // 0x800EDC30: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800EDC34: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800EDC38: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800EDC3C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800EDC40: negu        $v1, $a0
    ctx->r3 = SUB32(0, ctx->r4);
    // 0x800EDC44: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800EDC48: bne         $v0, $zero, L_800EDC7C
    if (ctx->r2 != 0) {
        // 0x800EDC4C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800EDC7C;
    }
    // 0x800EDC4C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800EDC50:
    // 0x800EDC50: jr          $ra
    // 0x800EDC54: nop

    return;
    // 0x800EDC54: nop

L_800EDC58:
    // 0x800EDC58: lbu         $v1, -0x3D09($a1)
    ctx->r3 = MEM_BU(ctx->r5, -0X3D09);
    // 0x800EDC5C: addiu       $v0, $v0, -0x7FA0
    ctx->r2 = ADD32(ctx->r2, -0X7FA0);
    // 0x800EDC60: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800EDC64: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800EDC68: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800EDC6C: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800EDC70: slt         $v1, $v1, $a0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800EDC74: bne         $v1, $zero, L_800EDC50
    if (ctx->r3 != 0) {
        // 0x800EDC78: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800EDC50;
    }
    // 0x800EDC78: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800EDC7C:
    // 0x800EDC7C: jr          $ra
    // 0x800EDC80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800EDC80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EDC84:
    // 0x800EDC84: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800EDC88: jr          $ra
    // 0x800EDC8C: nop

    return;
    // 0x800EDC8C: nop

;}
RECOMP_FUNC void func_800EDC90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EDC90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EDC94: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800EDC98: jal         0x800EDBB0
    // 0x800EDC9C: nop

    func_800EDBB0(rdram, ctx);
        goto after_0;
    // 0x800EDC9C: nop

    after_0:
    // 0x800EDCA0: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x800EDCA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EDCA8: bne         $a0, $v0, L_800EDD80
    if (ctx->r4 != ctx->r2) {
        // 0x800EDCAC: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800EDD80;
    }
    // 0x800EDCAC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800EDCB0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EDCB4: lhu         $v1, -0x3DAE($v0)
    ctx->r3 = MEM_HU(ctx->r2, -0X3DAE);
    // 0x800EDCB8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EDCBC: sb          $a0, -0x3D0E($v0)
    MEM_B(-0X3D0E, ctx->r2) = ctx->r4;
    // 0x800EDCC0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EDCC4: sb          $a0, -0x3D0D($v0)
    MEM_B(-0X3D0D, ctx->r2) = ctx->r4;
    // 0x800EDCC8: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800EDCCC: beq         $v0, $zero, L_800EDCD8
    if (ctx->r2 == 0) {
        // 0x800EDCD0: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800EDCD8;
    }
    // 0x800EDCD0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EDCD4: lhu         $v1, -0x3BAE($v0)
    ctx->r3 = MEM_HU(ctx->r2, -0X3BAE);
L_800EDCD8:
    // 0x800EDCD8: bne         $v1, $a0, L_800EDD30
    if (ctx->r3 != ctx->r4) {
        // 0x800EDCDC: lui         $a0, 0x8011
        ctx->r4 = S32(0X8011 << 16);
            goto L_800EDD30;
    }
    // 0x800EDCDC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800EDCE0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EDCE4: addiu       $v1, $v0, -0x3E90
    ctx->r3 = ADD32(ctx->r2, -0X3E90);
    // 0x800EDCE8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EDCEC: addiu       $v0, $v0, -0x3F20
    ctx->r2 = ADD32(ctx->r2, -0X3F20);
    // 0x800EDCF0: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
L_800EDCF4:
    // 0x800EDCF4: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x800EDCF8: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x800EDCFC: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x800EDD00: lw          $t1, 0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XC);
    // 0x800EDD04: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x800EDD08: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x800EDD0C: sw          $t0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r8;
    // 0x800EDD10: sw          $t1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r9;
    // 0x800EDD14: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800EDD18: bne         $v0, $a0, L_800EDCF4
    if (ctx->r2 != ctx->r4) {
        // 0x800EDD1C: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800EDCF4;
    }
    // 0x800EDD1C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800EDD20: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x800EDD24: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x800EDD28: j           L_800EDD80
    // 0x800EDD2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800EDD80;
    // 0x800EDD2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EDD30:
    // 0x800EDD30: addiu       $a0, $a0, -0x3E90
    ctx->r4 = ADD32(ctx->r4, -0X3E90);
    // 0x800EDD34: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800EDD38: addiu       $a1, $a1, -0x4E40
    ctx->r5 = ADD32(ctx->r5, -0X4E40);
    // 0x800EDD3C: sh          $v1, 0xA($a0)
    MEM_H(0XA, ctx->r4) = ctx->r3;
    // 0x800EDD40: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x800EDD44: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800EDD48: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800EDD4C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800EDD50: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800EDD54: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x800EDD58: sh          $v1, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r3;
    // 0x800EDD5C: lhu         $v1, 0x2($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X2);
    // 0x800EDD60: sh          $v1, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r3;
    // 0x800EDD64: lbu         $v1, 0x4($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X4);
    // 0x800EDD68: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EDD6C: sb          $zero, 0xE($a0)
    MEM_B(0XE, ctx->r4) = 0;
    // 0x800EDD70: sb          $zero, 0xC($a0)
    MEM_B(0XC, ctx->r4) = 0;
    // 0x800EDD74: sb          $zero, 0xD($a0)
    MEM_B(0XD, ctx->r4) = 0;
    // 0x800EDD78: sb          $zero, 0xF($a0)
    MEM_B(0XF, ctx->r4) = 0;
    // 0x800EDD7C: sb          $v1, 0x8($a0)
    MEM_B(0X8, ctx->r4) = ctx->r3;
L_800EDD80:
    // 0x800EDD80: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800EDD84: jr          $ra
    // 0x800EDD88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800EDD88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800EDD8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EDD8C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800EDD90: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800EDD94: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800EDD98: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800EDD9C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EDDA0: addiu       $a0, $v0, -0x3D90
    ctx->r4 = ADD32(ctx->r2, -0X3D90);
    // 0x800EDDA4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EDDA8: addiu       $v0, $v0, -0x3E60
    ctx->r2 = ADD32(ctx->r2, -0X3E60);
    // 0x800EDDAC: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800EDDB0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800EDDB4: lhu         $v1, 0x4($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X4);
    // 0x800EDDB8: lhu         $v0, 0x6($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6);
    // 0x800EDDBC: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x800EDDC0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
L_800EDDC4:
    // 0x800EDDC4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800EDDC8: bne         $v0, $v1, L_800EDDD8
    if (ctx->r2 != ctx->r3) {
        // 0x800EDDCC: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800EDDD8;
    }
    // 0x800EDDCC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800EDDD0: j           L_800EDDE8
    // 0x800EDDD4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
        goto L_800EDDE8;
    // 0x800EDDD4: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
L_800EDDD8:
    // 0x800EDDD8: slti        $v0, $a1, 0x8
    ctx->r2 = SIGNED(ctx->r5) < 0X8 ? 1 : 0;
    // 0x800EDDDC: bne         $v0, $zero, L_800EDDC4
    if (ctx->r2 != 0) {
        // 0x800EDDE0: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_800EDDC4;
    }
    // 0x800EDDE0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800EDDE4: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
L_800EDDE8:
    // 0x800EDDE8: beq         $s0, $zero, L_800EDE08
    if (ctx->r16 == 0) {
        // 0x800EDDEC: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800EDE08;
    }
    // 0x800EDDEC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800EDDF0: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800EDDF4: jal         0x80095D58
    // 0x800EDDF8: nop

    func_80095D58(rdram, ctx);
        goto after_0;
    // 0x800EDDF8: nop

    after_0:
    // 0x800EDDFC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800EDE00: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800EDE04: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_800EDE08:
    // 0x800EDE08: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EDE0C: addiu       $a2, $v0, -0x3E60
    ctx->r6 = ADD32(ctx->r2, -0X3E60);
    // 0x800EDE10: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EDE14: addiu       $a1, $v0, -0x3E30
    ctx->r5 = ADD32(ctx->r2, -0X3E30);
    // 0x800EDE18: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x800EDE1C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EDE20: addiu       $v1, $v0, -0x3CE0
    ctx->r3 = ADD32(ctx->r2, -0X3CE0);
L_800EDE24:
    // 0x800EDE24: lhu         $v0, 0x4($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X4);
    // 0x800EDE28: sh          $v0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r2;
    // 0x800EDE2C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800EDE30: beq         $v0, $zero, L_800EDE60
    if (ctx->r2 == 0) {
        // 0x800EDE34: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800EDE60;
    }
    // 0x800EDE34: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800EDE38: lhu         $v0, 0x6($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X6);
    // 0x800EDE3C: sh          $v0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r2;
    // 0x800EDE40: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800EDE44: beq         $v0, $zero, L_800EDE60
    if (ctx->r2 == 0) {
        // 0x800EDE48: nop
    
            goto L_800EDE60;
    }
    // 0x800EDE48: nop

    // 0x800EDE4C: lhu         $v0, 0x4($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X4);
    // 0x800EDE50: sh          $v0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r2;
    // 0x800EDE54: lhu         $v0, 0x6($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X6);
    // 0x800EDE58: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x800EDE5C: sh          $v0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r2;
L_800EDE60:
    // 0x800EDE60: slti        $v0, $a0, 0x8
    ctx->r2 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800EDE64: bne         $v0, $zero, L_800EDE24
    if (ctx->r2 != 0) {
        // 0x800EDE68: addiu       $v1, $v1, 0x1C
        ctx->r3 = ADD32(ctx->r3, 0X1C);
            goto L_800EDE24;
    }
    // 0x800EDE68: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x800EDE6C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EDE70: sb          $zero, -0x3D97($v0)
    MEM_B(-0X3D97, ctx->r2) = 0;
    // 0x800EDE74: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EDE78: addiu       $v1, $v0, -0x3EF0
    ctx->r3 = ADD32(ctx->r2, -0X3EF0);
    // 0x800EDE7C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EDE80: addiu       $v0, $v0, -0x3E30
    ctx->r2 = ADD32(ctx->r2, -0X3E30);
    // 0x800EDE84: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
L_800EDE88:
    // 0x800EDE88: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800EDE8C: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x800EDE90: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x800EDE94: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x800EDE98: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800EDE9C: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x800EDEA0: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x800EDEA4: sw          $t3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r11;
    // 0x800EDEA8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800EDEAC: bne         $v0, $a0, L_800EDE88
    if (ctx->r2 != ctx->r4) {
        // 0x800EDEB0: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800EDE88;
    }
    // 0x800EDEB0: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800EDEB4: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800EDEB8: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800EDEBC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EDEC0: addiu       $v1, $v0, -0x3C00
    ctx->r3 = ADD32(ctx->r2, -0X3C00);
    // 0x800EDEC4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EDEC8: addiu       $v0, $v0, -0x3E30
    ctx->r2 = ADD32(ctx->r2, -0X3E30);
    // 0x800EDECC: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
L_800EDED0:
    // 0x800EDED0: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800EDED4: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x800EDED8: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x800EDEDC: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x800EDEE0: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800EDEE4: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x800EDEE8: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x800EDEEC: sw          $t3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r11;
    // 0x800EDEF0: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800EDEF4: bne         $v0, $a0, L_800EDED0
    if (ctx->r2 != ctx->r4) {
        // 0x800EDEF8: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800EDED0;
    }
    // 0x800EDEF8: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800EDEFC: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800EDF00: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800EDF04: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EDF08: addiu       $v1, $v0, -0x3E60
    ctx->r3 = ADD32(ctx->r2, -0X3E60);
    // 0x800EDF0C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EDF10: addiu       $v0, $v0, -0x3E30
    ctx->r2 = ADD32(ctx->r2, -0X3E30);
    // 0x800EDF14: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
L_800EDF18:
    // 0x800EDF18: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800EDF1C: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x800EDF20: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x800EDF24: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x800EDF28: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800EDF2C: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x800EDF30: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x800EDF34: sw          $t3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r11;
    // 0x800EDF38: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800EDF3C: bne         $v0, $a0, L_800EDF18
    if (ctx->r2 != ctx->r4) {
        // 0x800EDF40: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800EDF18;
    }
    // 0x800EDF40: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800EDF44: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800EDF48: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800EDF4C: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800EDF50: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EDF54: sb          $s1, -0x3D9E($v0)
    MEM_B(-0X3D9E, ctx->r2) = ctx->r17;
    // 0x800EDF58: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800EDF5C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800EDF60: jr          $ra
    // 0x800EDF64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800EDF64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800EDF68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EDF68: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EDF6C: lbu         $v0, -0x3D98($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X3D98);
    // 0x800EDF70: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800EDF74: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x800EDF78: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800EDF7C: sw          $ra, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r31;
    // 0x800EDF80: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x800EDF84: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x800EDF88: bne         $v0, $s1, L_800EE030
    if (ctx->r2 != ctx->r17) {
        // 0x800EDF8C: sw          $s0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r16;
            goto L_800EE030;
    }
    // 0x800EDF8C: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x800EDF90: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EDF94: lbu         $v0, -0x3D9C($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X3D9C);
    // 0x800EDF98: bne         $v0, $zero, L_800EE028
    if (ctx->r2 != 0) {
        // 0x800EDF9C: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800EE028;
    }
    // 0x800EDF9C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EDFA0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EDFA4: lbu         $v0, -0x3D9B($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X3D9B);
    // 0x800EDFA8: bne         $v0, $zero, L_800EE028
    if (ctx->r2 != 0) {
        // 0x800EDFAC: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800EE028;
    }
    // 0x800EDFAC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EDFB0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EDFB4: addiu       $v1, $v0, -0x3EF0
    ctx->r3 = ADD32(ctx->r2, -0X3EF0);
    // 0x800EDFB8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EDFBC: addiu       $v0, $v0, -0x3E00
    ctx->r2 = ADD32(ctx->r2, -0X3E00);
    // 0x800EDFC0: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
L_800EDFC4:
    // 0x800EDFC4: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800EDFC8: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x800EDFCC: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x800EDFD0: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x800EDFD4: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x800EDFD8: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x800EDFDC: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
    // 0x800EDFE0: sw          $t2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r10;
    // 0x800EDFE4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800EDFE8: bne         $v0, $a0, L_800EDFC4
    if (ctx->r2 != ctx->r4) {
        // 0x800EDFEC: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800EDFC4;
    }
    // 0x800EDFEC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800EDFF0: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800EDFF4: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x800EDFF8: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800EDFFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EE000: sb          $v0, -0x3D9B($v1)
    MEM_B(-0X3D9B, ctx->r3) = ctx->r2;
    // 0x800EE004: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE008: sb          $zero, -0x3D9C($v0)
    MEM_B(-0X3D9C, ctx->r2) = 0;
    // 0x800EE00C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE010: sb          $zero, -0x3D9A($v0)
    MEM_B(-0X3D9A, ctx->r2) = 0;
    // 0x800EE014: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE018: sb          $zero, -0x3D03($v0)
    MEM_B(-0X3D03, ctx->r2) = 0;
    // 0x800EE01C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE020: sb          $zero, -0x3D04($v0)
    MEM_B(-0X3D04, ctx->r2) = 0;
    // 0x800EE024: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_800EE028:
    // 0x800EE028: j           L_800EE6E4
    // 0x800EE02C: sb          $zero, -0x3D98($v0)
    MEM_B(-0X3D98, ctx->r2) = 0;
        goto L_800EE6E4;
    // 0x800EE02C: sb          $zero, -0x3D98($v0)
    MEM_B(-0X3D98, ctx->r2) = 0;
L_800EE030:
    // 0x800EE030: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE034: lbu         $v0, -0x3D9C($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X3D9C);
    // 0x800EE038: bne         $v0, $zero, L_800EE6E8
    if (ctx->r2 != 0) {
        // 0x800EE03C: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800EE6E8;
    }
    // 0x800EE03C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE040: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE044: lbu         $v0, -0x3D9B($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X3D9B);
    // 0x800EE048: bne         $v0, $zero, L_800EE6E8
    if (ctx->r2 != 0) {
        // 0x800EE04C: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800EE6E8;
    }
    // 0x800EE04C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE050: lui         $s2, 0x8011
    ctx->r18 = S32(0X8011 << 16);
    // 0x800EE054: lbu         $v0, -0x3D99($s2)
    ctx->r2 = MEM_BU(ctx->r18, -0X3D99);
    // 0x800EE058: bne         $v0, $s1, L_800EE35C
    if (ctx->r2 != ctx->r17) {
        // 0x800EE05C: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_800EE35C;
    }
    // 0x800EE05C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800EE060: lui         $s3, 0x8011
    ctx->r19 = S32(0X8011 << 16);
    // 0x800EE064: addiu       $s0, $s3, -0x3DD0
    ctx->r16 = ADD32(ctx->r19, -0X3DD0);
    // 0x800EE068: lbu         $v0, 0x28($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X28);
    // 0x800EE06C: bne         $v0, $zero, L_800EE158
    if (ctx->r2 != 0) {
        // 0x800EE070: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800EE158;
    }
    // 0x800EE070: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE074: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800EE078: lbu         $v0, -0x3D0E($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X3D0E);
    // 0x800EE07C: bne         $v0, $s1, L_800EE0D4
    if (ctx->r2 != ctx->r17) {
        // 0x800EE080: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800EE0D4;
    }
    // 0x800EE080: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE084: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800EE088: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800EE08C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800EE090: nop

    // 0x800EE094: bc1f        L_800EE0D0
    if (!c1cs) {
        // 0x800EE098: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800EE0D0;
    }
    // 0x800EE098: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE09C: sb          $s1, -0x3D04($v0)
    MEM_B(-0X3D04, ctx->r2) = ctx->r17;
    // 0x800EE0A0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE0A4: sb          $zero, -0x3D03($v0)
    MEM_B(-0X3D03, ctx->r2) = 0;
    // 0x800EE0A8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE0AC: swc1        $f2, -0x3CFC($v0)
    MEM_W(-0X3CFC, ctx->r2) = ctx->f2.u32l;
    // 0x800EE0B0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE0B4: swc1        $f0, -0x3D00($v0)
    MEM_W(-0X3D00, ctx->r2) = ctx->f0.u32l;
    // 0x800EE0B8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE0BC: swc1        $f0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f0.u32l;
    // 0x800EE0C0: sb          $zero, -0x3D99($s2)
    MEM_B(-0X3D99, ctx->r18) = 0;
    // 0x800EE0C4: sb          $zero, -0x3D0D($v0)
    MEM_B(-0X3D0D, ctx->r2) = 0;
    // 0x800EE0C8: j           L_800EE14C
    // 0x800EE0CC: sb          $zero, -0x3D0E($v1)
    MEM_B(-0X3D0E, ctx->r3) = 0;
        goto L_800EE14C;
    // 0x800EE0CC: sb          $zero, -0x3D0E($v1)
    MEM_B(-0X3D0E, ctx->r3) = 0;
L_800EE0D0:
    // 0x800EE0D0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_800EE0D4:
    // 0x800EE0D4: sb          $zero, -0x3D0D($v0)
    MEM_B(-0X3D0D, ctx->r2) = 0;
    // 0x800EE0D8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE0DC: sb          $zero, -0x3D0E($v0)
    MEM_B(-0X3D0E, ctx->r2) = 0;
    // 0x800EE0E0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE0E4: lbu         $v1, -0x3D04($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X3D04);
    // 0x800EE0E8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE0EC: bne         $v1, $zero, L_800EE14C
    if (ctx->r3 != 0) {
        // 0x800EE0F0: sb          $zero, -0x3D99($v0)
        MEM_B(-0X3D99, ctx->r2) = 0;
            goto L_800EE14C;
    }
    // 0x800EE0F0: sb          $zero, -0x3D99($v0)
    MEM_B(-0X3D99, ctx->r2) = 0;
    // 0x800EE0F4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE0F8: lbu         $v0, -0x3D03($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X3D03);
    // 0x800EE0FC: bne         $v0, $zero, L_800EE150
    if (ctx->r2 != 0) {
        // 0x800EE100: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800EE150;
    }
    // 0x800EE100: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE104: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE108: addiu       $v1, $v0, -0x3EF0
    ctx->r3 = ADD32(ctx->r2, -0X3EF0);
    // 0x800EE10C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE110: addiu       $v0, $v0, -0x3E90
    ctx->r2 = ADD32(ctx->r2, -0X3E90);
    // 0x800EE114: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
L_800EE118:
    // 0x800EE118: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800EE11C: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x800EE120: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x800EE124: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x800EE128: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x800EE12C: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x800EE130: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
    // 0x800EE134: sw          $t2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r10;
    // 0x800EE138: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800EE13C: bne         $v0, $a0, L_800EE118
    if (ctx->r2 != ctx->r4) {
        // 0x800EE140: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800EE118;
    }
    // 0x800EE140: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800EE144: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800EE148: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
L_800EE14C:
    // 0x800EE14C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_800EE150:
    // 0x800EE150: j           L_800EE6E4
    // 0x800EE154: sb          $zero, -0x3D0F($v0)
    MEM_B(-0X3D0F, ctx->r2) = 0;
        goto L_800EE6E4;
    // 0x800EE154: sb          $zero, -0x3D0F($v0)
    MEM_B(-0X3D0F, ctx->r2) = 0;
L_800EE158:
    // 0x800EE158: sb          $zero, -0x3D0D($v0)
    MEM_B(-0X3D0D, ctx->r2) = 0;
    // 0x800EE15C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE160: sb          $zero, -0x3D0E($v0)
    MEM_B(-0X3D0E, ctx->r2) = 0;
    // 0x800EE164: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE168: sb          $s1, -0x3D0F($v0)
    MEM_B(-0X3D0F, ctx->r2) = ctx->r17;
    // 0x800EE16C: lbu         $v1, 0x29($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X29);
    // 0x800EE170: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE174: sb          $v1, -0x3D0B($v0)
    MEM_B(-0X3D0B, ctx->r2) = ctx->r3;
    // 0x800EE178: lbu         $v1, 0x2A($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2A);
    // 0x800EE17C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE180: sb          $v1, -0x3D0A($v0)
    MEM_B(-0X3D0A, ctx->r2) = ctx->r3;
    // 0x800EE184: lbu         $v1, 0x2B($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X2B);
    // 0x800EE188: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE18C: sb          $v1, -0x3D09($v0)
    MEM_B(-0X3D09, ctx->r2) = ctx->r3;
    // 0x800EE190: lw          $v1, 0x2C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X2C);
    // 0x800EE194: lbu         $a0, 0x27($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X27);
    // 0x800EE198: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE19C: bne         $a0, $s1, L_800EE1B4
    if (ctx->r4 != ctx->r17) {
        // 0x800EE1A0: sw          $v1, -0x3D08($v0)
        MEM_W(-0X3D08, ctx->r2) = ctx->r3;
            goto L_800EE1B4;
    }
    // 0x800EE1A0: sw          $v1, -0x3D08($v0)
    MEM_W(-0X3D08, ctx->r2) = ctx->r3;
    // 0x800EE1A4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE1A8: sb          $zero, -0x3D03($v0)
    MEM_B(-0X3D03, ctx->r2) = 0;
    // 0x800EE1AC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE1B0: sb          $zero, -0x3D04($v0)
    MEM_B(-0X3D04, ctx->r2) = 0;
L_800EE1B4:
    // 0x800EE1B4: jal         0x800EDC90
    // 0x800EE1B8: nop

    func_800EDC90(rdram, ctx);
        goto after_0;
    // 0x800EE1B8: nop

    after_0:
    // 0x800EE1BC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800EE1C0: bnel        $v0, $zero, L_800EE310
    if (ctx->r2 != 0) {
        // 0x800EE1C4: sb          $zero, -0x3D99($s2)
        MEM_B(-0X3D99, ctx->r18) = 0;
            goto L_800EE310;
    }
    goto skip_0;
    // 0x800EE1C4: sb          $zero, -0x3D99($s2)
    MEM_B(-0X3D99, ctx->r18) = 0;
    skip_0:
    // 0x800EE1C8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800EE1CC: lbu         $v0, -0x3D04($a0)
    ctx->r2 = MEM_BU(ctx->r4, -0X3D04);
    // 0x800EE1D0: bne         $v0, $zero, L_800EE2C8
    if (ctx->r2 != 0) {
        // 0x800EE1D4: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800EE2C8;
    }
    // 0x800EE1D4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE1D8: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800EE1DC: lbu         $v0, -0x3D03($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X3D03);
    // 0x800EE1E0: bne         $v0, $zero, L_800EE2C8
    if (ctx->r2 != 0) {
        // 0x800EE1E4: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800EE2C8;
    }
    // 0x800EE1E4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE1E8: lwc1        $f2, -0x3DD0($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, -0X3DD0);
    // 0x800EE1EC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800EE1F0: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x800EE1F4: nop

    // 0x800EE1F8: bc1t        L_800EE210
    if (c1cs) {
        // 0x800EE1FC: sb          $zero, -0x3D99($s2)
        MEM_B(-0X3D99, ctx->r18) = 0;
            goto L_800EE210;
    }
    // 0x800EE1FC: sb          $zero, -0x3D99($s2)
    MEM_B(-0X3D99, ctx->r18) = 0;
    // 0x800EE200: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE204: swc1        $f2, -0x3CFC($v0)
    MEM_W(-0X3CFC, ctx->r2) = ctx->f2.u32l;
    // 0x800EE208: j           L_800EE27C
    // 0x800EE20C: sb          $s1, -0x3D04($a0)
    MEM_B(-0X3D04, ctx->r4) = ctx->r17;
        goto L_800EE27C;
    // 0x800EE20C: sb          $s1, -0x3D04($a0)
    MEM_B(-0X3D04, ctx->r4) = ctx->r17;
L_800EE210:
    // 0x800EE210: lw          $a0, 0x18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X18);
    // 0x800EE214: beq         $a0, $s1, L_800EE27C
    if (ctx->r4 == ctx->r17) {
        // 0x800EE218: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_800EE27C;
    }
    // 0x800EE218: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800EE21C: sb          $s1, -0x3D03($v1)
    MEM_B(-0X3D03, ctx->r3) = ctx->r17;
    // 0x800EE220: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800EE224: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x800EE228: sw          $v0, -0x3CF4($v1)
    MEM_W(-0X3CF4, ctx->r3) = ctx->r2;
    // 0x800EE22C: bne         $a0, $zero, L_800EE27C
    if (ctx->r4 != 0) {
        // 0x800EE230: sw          $a0, -0x3CF8($s1)
        MEM_W(-0X3CF8, ctx->r17) = ctx->r4;
            goto L_800EE27C;
    }
    // 0x800EE230: sw          $a0, -0x3CF8($s1)
    MEM_W(-0X3CF8, ctx->r17) = ctx->r4;
    // 0x800EE234: jal         0x80003430
    // 0x800EE238: nop

    rand_recomp(rdram, ctx);
        goto after_1;
    // 0x800EE238: nop

    after_1:
    // 0x800EE23C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800EE240: lw          $v1, 0x1C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X1C);
    // 0x800EE244: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800EE248: div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // 0x800EE24C: bne         $v1, $zero, L_800EE258
    if (ctx->r3 != 0) {
        // 0x800EE250: nop
    
            goto L_800EE258;
    }
    // 0x800EE250: nop

    // 0x800EE254: break       7
    do_break(2148459092);
L_800EE258:
    // 0x800EE258: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800EE25C: bne         $v1, $at, L_800EE270
    if (ctx->r3 != ctx->r1) {
        // 0x800EE260: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800EE270;
    }
    // 0x800EE260: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800EE264: bne         $v0, $at, L_800EE270
    if (ctx->r2 != ctx->r1) {
        // 0x800EE268: nop
    
            goto L_800EE270;
    }
    // 0x800EE268: nop

    // 0x800EE26C: break       6
    do_break(2148459116);
L_800EE270:
    // 0x800EE270: mfhi        $v1
    ctx->r3 = hi;
    // 0x800EE274: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800EE278: sw          $v1, -0x3CF8($s1)
    MEM_W(-0X3CF8, ctx->r17) = ctx->r3;
L_800EE27C:
    // 0x800EE27C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE280: addiu       $v1, $v0, -0x3EF0
    ctx->r3 = ADD32(ctx->r2, -0X3EF0);
    // 0x800EE284: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE288: addiu       $v0, $v0, -0x3E90
    ctx->r2 = ADD32(ctx->r2, -0X3E90);
    // 0x800EE28C: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
L_800EE290:
    // 0x800EE290: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800EE294: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x800EE298: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x800EE29C: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x800EE2A0: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x800EE2A4: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x800EE2A8: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
    // 0x800EE2AC: sw          $t2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r10;
    // 0x800EE2B0: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800EE2B4: bne         $v0, $a0, L_800EE290
    if (ctx->r2 != ctx->r4) {
        // 0x800EE2B8: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800EE290;
    }
    // 0x800EE2B8: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800EE2BC: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800EE2C0: j           L_800EE6E4
    // 0x800EE2C4: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
        goto L_800EE6E4;
    // 0x800EE2C4: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
L_800EE2C8:
    // 0x800EE2C8: addiu       $v1, $v0, -0x3EF0
    ctx->r3 = ADD32(ctx->r2, -0X3EF0);
    // 0x800EE2CC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE2D0: addiu       $v0, $v0, -0x3F20
    ctx->r2 = ADD32(ctx->r2, -0X3F20);
    // 0x800EE2D4: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
L_800EE2D8:
    // 0x800EE2D8: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800EE2DC: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x800EE2E0: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x800EE2E4: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x800EE2E8: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x800EE2EC: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x800EE2F0: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
    // 0x800EE2F4: sw          $t2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r10;
    // 0x800EE2F8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800EE2FC: bne         $v0, $a0, L_800EE2D8
    if (ctx->r2 != ctx->r4) {
        // 0x800EE300: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800EE2D8;
    }
    // 0x800EE300: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800EE304: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800EE308: j           L_800EE6E4
    // 0x800EE30C: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
        goto L_800EE6E4;
    // 0x800EE30C: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
L_800EE310:
    // 0x800EE310: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE314: addiu       $v1, $v0, -0x3EF0
    ctx->r3 = ADD32(ctx->r2, -0X3EF0);
    // 0x800EE318: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE31C: addiu       $v0, $v0, -0x3E90
    ctx->r2 = ADD32(ctx->r2, -0X3E90);
    // 0x800EE320: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
L_800EE324:
    // 0x800EE324: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800EE328: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x800EE32C: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x800EE330: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x800EE334: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x800EE338: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x800EE33C: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
    // 0x800EE340: sw          $t2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r10;
    // 0x800EE344: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800EE348: bne         $v0, $a0, L_800EE324
    if (ctx->r2 != ctx->r4) {
        // 0x800EE34C: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800EE324;
    }
    // 0x800EE34C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800EE350: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800EE354: j           L_800EE6E4
    // 0x800EE358: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
        goto L_800EE6E4;
    // 0x800EE358: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
L_800EE35C:
    // 0x800EE35C: lbu         $v0, -0x3D9A($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X3D9A);
    // 0x800EE360: beq         $v0, $zero, L_800EE434
    if (ctx->r2 == 0) {
        // 0x800EE364: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800EE434;
    }
    // 0x800EE364: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE368: lbu         $v0, -0x3D0E($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X3D0E);
    // 0x800EE36C: bne         $v0, $zero, L_800EE3BC
    if (ctx->r2 != 0) {
        // 0x800EE370: sb          $zero, -0x3D9A($v1)
        MEM_B(-0X3D9A, ctx->r3) = 0;
            goto L_800EE3BC;
    }
    // 0x800EE370: sb          $zero, -0x3D9A($v1)
    MEM_B(-0X3D9A, ctx->r3) = 0;
    // 0x800EE374: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE378: addiu       $v1, $v0, -0x3EF0
    ctx->r3 = ADD32(ctx->r2, -0X3EF0);
    // 0x800EE37C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE380: addiu       $v0, $v0, -0x3C00
    ctx->r2 = ADD32(ctx->r2, -0X3C00);
    // 0x800EE384: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
L_800EE388:
    // 0x800EE388: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800EE38C: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x800EE390: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x800EE394: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x800EE398: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x800EE39C: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x800EE3A0: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
    // 0x800EE3A4: sw          $t2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r10;
    // 0x800EE3A8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800EE3AC: bne         $v0, $a0, L_800EE388
    if (ctx->r2 != ctx->r4) {
        // 0x800EE3B0: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800EE388;
    }
    // 0x800EE3B0: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800EE3B4: j           L_800EE3FC
    // 0x800EE3B8: nop

        goto L_800EE3FC;
    // 0x800EE3B8: nop

L_800EE3BC:
    // 0x800EE3BC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE3C0: addiu       $v1, $v0, -0x3EF0
    ctx->r3 = ADD32(ctx->r2, -0X3EF0);
    // 0x800EE3C4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE3C8: addiu       $v0, $v0, -0x3E90
    ctx->r2 = ADD32(ctx->r2, -0X3E90);
    // 0x800EE3CC: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
L_800EE3D0:
    // 0x800EE3D0: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800EE3D4: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x800EE3D8: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x800EE3DC: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x800EE3E0: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x800EE3E4: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x800EE3E8: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
    // 0x800EE3EC: sw          $t2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r10;
    // 0x800EE3F0: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800EE3F4: bne         $v0, $a0, L_800EE3D0
    if (ctx->r2 != ctx->r4) {
        // 0x800EE3F8: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800EE3D0;
    }
    // 0x800EE3F8: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_800EE3FC:
    // 0x800EE3FC: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800EE400: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x800EE404: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE408: addiu       $v0, $v0, -0x3EF0
    ctx->r2 = ADD32(ctx->r2, -0X3EF0);
    // 0x800EE40C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800EE410: addiu       $v1, $zero, 0x64
    ctx->r3 = ADD32(0, 0X64);
    // 0x800EE414: sh          $a0, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r4;
    // 0x800EE418: sb          $zero, 0xF($v0)
    MEM_B(0XF, ctx->r2) = 0;
    // 0x800EE41C: sh          $v1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r3;
    // 0x800EE420: sh          $v1, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r3;
    // 0x800EE424: sb          $a0, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r4;
    // 0x800EE428: sb          $zero, 0xD($v0)
    MEM_B(0XD, ctx->r2) = 0;
    // 0x800EE42C: j           L_800EE6E4
    // 0x800EE430: sb          $a0, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r4;
        goto L_800EE6E4;
    // 0x800EE430: sb          $a0, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r4;
L_800EE434:
    // 0x800EE434: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE438: lbu         $v0, -0x3D0C($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X3D0C);
    // 0x800EE43C: bne         $v0, $s1, L_800EE594
    if (ctx->r2 != ctx->r17) {
        // 0x800EE440: lui         $a1, 0x8011
        ctx->r5 = S32(0X8011 << 16);
            goto L_800EE594;
    }
    // 0x800EE440: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800EE444: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE448: lbu         $v0, -0x3D0E($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X3D0E);
    // 0x800EE44C: bne         $v0, $zero, L_800EE544
    if (ctx->r2 != 0) {
        // 0x800EE450: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800EE544;
    }
    // 0x800EE450: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE454: addiu       $v1, $v0, -0x3EF0
    ctx->r3 = ADD32(ctx->r2, -0X3EF0);
    // 0x800EE458: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE45C: addiu       $v0, $v0, -0x3C00
    ctx->r2 = ADD32(ctx->r2, -0X3C00);
    // 0x800EE460: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
L_800EE464:
    // 0x800EE464: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800EE468: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x800EE46C: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x800EE470: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x800EE474: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x800EE478: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x800EE47C: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
    // 0x800EE480: sw          $t2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r10;
    // 0x800EE484: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800EE488: bne         $v0, $a0, L_800EE464
    if (ctx->r2 != ctx->r4) {
        // 0x800EE48C: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800EE464;
    }
    // 0x800EE48C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800EE490: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800EE494: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x800EE498: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE49C: lwc1        $f2, -0x3DD0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, -0X3DD0);
    // 0x800EE4A0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800EE4A4: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x800EE4A8: nop

    // 0x800EE4AC: bc1t        L_800EE4CC
    if (c1cs) {
        // 0x800EE4B0: addiu       $s1, $v0, -0x3DD0
        ctx->r17 = ADD32(ctx->r2, -0X3DD0);
            goto L_800EE4CC;
    }
    // 0x800EE4B0: addiu       $s1, $v0, -0x3DD0
    ctx->r17 = ADD32(ctx->r2, -0X3DD0);
    // 0x800EE4B4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE4B8: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800EE4BC: swc1        $f2, -0x3CFC($v0)
    MEM_W(-0X3CFC, ctx->r2) = ctx->f2.u32l;
    // 0x800EE4C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EE4C4: j           L_800EE6DC
    // 0x800EE4C8: sb          $v0, -0x3D04($v1)
    MEM_B(-0X3D04, ctx->r3) = ctx->r2;
        goto L_800EE6DC;
    // 0x800EE4C8: sb          $v0, -0x3D04($v1)
    MEM_B(-0X3D04, ctx->r3) = ctx->r2;
L_800EE4CC:
    // 0x800EE4CC: lw          $a0, 0x18($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X18);
    // 0x800EE4D0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800EE4D4: beq         $a0, $v1, L_800EE6DC
    if (ctx->r4 == ctx->r3) {
        // 0x800EE4D8: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800EE6DC;
    }
    // 0x800EE4D8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE4DC: sb          $v1, -0x3D03($v0)
    MEM_B(-0X3D03, ctx->r2) = ctx->r3;
    // 0x800EE4E0: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800EE4E4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800EE4E8: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800EE4EC: sw          $v0, -0x3CF4($v1)
    MEM_W(-0X3CF4, ctx->r3) = ctx->r2;
    // 0x800EE4F0: bne         $a0, $zero, L_800EE6DC
    if (ctx->r4 != 0) {
        // 0x800EE4F4: sw          $a0, -0x3CF8($s0)
        MEM_W(-0X3CF8, ctx->r16) = ctx->r4;
            goto L_800EE6DC;
    }
    // 0x800EE4F4: sw          $a0, -0x3CF8($s0)
    MEM_W(-0X3CF8, ctx->r16) = ctx->r4;
    // 0x800EE4F8: jal         0x80003430
    // 0x800EE4FC: nop

    rand_recomp(rdram, ctx);
        goto after_2;
    // 0x800EE4FC: nop

    after_2:
    // 0x800EE500: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800EE504: lw          $v1, 0x1C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X1C);
    // 0x800EE508: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800EE50C: div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // 0x800EE510: bne         $v1, $zero, L_800EE51C
    if (ctx->r3 != 0) {
        // 0x800EE514: nop
    
            goto L_800EE51C;
    }
    // 0x800EE514: nop

    // 0x800EE518: break       7
    do_break(2148459800);
L_800EE51C:
    // 0x800EE51C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800EE520: bne         $v1, $at, L_800EE534
    if (ctx->r3 != ctx->r1) {
        // 0x800EE524: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800EE534;
    }
    // 0x800EE524: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800EE528: bne         $v0, $at, L_800EE534
    if (ctx->r2 != ctx->r1) {
        // 0x800EE52C: nop
    
            goto L_800EE534;
    }
    // 0x800EE52C: nop

    // 0x800EE530: break       6
    do_break(2148459824);
L_800EE534:
    // 0x800EE534: mfhi        $v1
    ctx->r3 = hi;
    // 0x800EE538: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800EE53C: j           L_800EE6DC
    // 0x800EE540: sw          $v1, -0x3CF8($s0)
    MEM_W(-0X3CF8, ctx->r16) = ctx->r3;
        goto L_800EE6DC;
    // 0x800EE540: sw          $v1, -0x3CF8($s0)
    MEM_W(-0X3CF8, ctx->r16) = ctx->r3;
L_800EE544:
    // 0x800EE544: jal         0x800EDC90
    // 0x800EE548: nop

    func_800EDC90(rdram, ctx);
        goto after_3;
    // 0x800EE548: nop

    after_3:
    // 0x800EE54C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE550: addiu       $v1, $v0, -0x3EF0
    ctx->r3 = ADD32(ctx->r2, -0X3EF0);
    // 0x800EE554: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE558: addiu       $v0, $v0, -0x3E90
    ctx->r2 = ADD32(ctx->r2, -0X3E90);
    // 0x800EE55C: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
L_800EE560:
    // 0x800EE560: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800EE564: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x800EE568: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x800EE56C: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x800EE570: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x800EE574: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x800EE578: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
    // 0x800EE57C: sw          $t2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r10;
    // 0x800EE580: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800EE584: bne         $v0, $a0, L_800EE560
    if (ctx->r2 != ctx->r4) {
        // 0x800EE588: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800EE560;
    }
    // 0x800EE588: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800EE58C: j           L_800EE6D4
    // 0x800EE590: nop

        goto L_800EE6D4;
    // 0x800EE590: nop

L_800EE594:
    // 0x800EE594: lw          $v0, -0x3CF4($a1)
    ctx->r2 = MEM_W(ctx->r5, -0X3CF4);
    // 0x800EE598: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800EE59C: beq         $v0, $a0, L_800EE694
    if (ctx->r2 == ctx->r4) {
        // 0x800EE5A0: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800EE694;
    }
    // 0x800EE5A0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE5A4: lhu         $v1, -0x3DB0($v0)
    ctx->r3 = MEM_HU(ctx->r2, -0X3DB0);
    // 0x800EE5A8: slti        $v0, $v1, 0x2
    ctx->r2 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800EE5AC: bne         $v0, $zero, L_800EE6DC
    if (ctx->r2 != 0) {
        // 0x800EE5B0: sw          $a0, -0x3CF4($a1)
        MEM_W(-0X3CF4, ctx->r5) = ctx->r4;
            goto L_800EE6DC;
    }
    // 0x800EE5B0: sw          $a0, -0x3CF4($a1)
    MEM_W(-0X3CF4, ctx->r5) = ctx->r4;
    // 0x800EE5B4: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x800EE5B8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE5BC: addiu       $a0, $v0, -0x3F20
    ctx->r4 = ADD32(ctx->r2, -0X3F20);
    // 0x800EE5C0: addiu       $v0, $a0, 0x20
    ctx->r2 = ADD32(ctx->r4, 0X20);
L_800EE5C4:
    // 0x800EE5C4: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x800EE5C8: lw          $t0, 0x4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4);
    // 0x800EE5CC: lw          $t1, 0x8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X8);
    // 0x800EE5D0: lw          $t2, 0xC($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XC);
    // 0x800EE5D4: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x800EE5D8: sw          $t0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r8;
    // 0x800EE5DC: sw          $t1, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r9;
    // 0x800EE5E0: sw          $t2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r10;
    // 0x800EE5E4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800EE5E8: bne         $a0, $v0, L_800EE5C4
    if (ctx->r4 != ctx->r2) {
        // 0x800EE5EC: addiu       $a1, $a1, 0x10
        ctx->r5 = ADD32(ctx->r5, 0X10);
            goto L_800EE5C4;
    }
    // 0x800EE5EC: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800EE5F0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE5F4: addiu       $a2, $v0, -0x3EF0
    ctx->r6 = ADD32(ctx->r2, -0X3EF0);
    // 0x800EE5F8: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x800EE5FC: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x800EE600: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800EE604: addiu       $a0, $a0, -0x4E40
    ctx->r4 = ADD32(ctx->r4, -0X4E40);
    // 0x800EE608: sh          $v1, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r3;
    // 0x800EE60C: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x800EE610: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800EE614: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800EE618: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800EE61C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800EE620: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x800EE624: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800EE628: sh          $v1, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r3;
    // 0x800EE62C: lhu         $v1, 0x2($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X2);
    // 0x800EE630: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x800EE634: sh          $v1, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r3;
    // 0x800EE638: lbu         $v1, 0x4($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X4);
    // 0x800EE63C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EE640: sb          $v0, 0x1C($sp)
    MEM_B(0X1C, ctx->r29) = ctx->r2;
    // 0x800EE644: sb          $zero, 0x1D($sp)
    MEM_B(0X1D, ctx->r29) = 0;
    // 0x800EE648: sb          $v0, 0x1E($sp)
    MEM_B(0X1E, ctx->r29) = ctx->r2;
    // 0x800EE64C: sb          $zero, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = 0;
    // 0x800EE650: sh          $zero, 0x20($sp)
    MEM_H(0X20, ctx->r29) = 0;
    // 0x800EE654: sh          $zero, 0x22($sp)
    MEM_H(0X22, ctx->r29) = 0;
    // 0x800EE658: sb          $v1, 0x18($sp)
    MEM_B(0X18, ctx->r29) = ctx->r3;
L_800EE65C:
    // 0x800EE65C: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x800EE660: lw          $t0, 0x4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4);
    // 0x800EE664: lw          $t1, 0x8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X8);
    // 0x800EE668: lw          $t2, 0xC($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XC);
    // 0x800EE66C: sw          $a3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r7;
    // 0x800EE670: sw          $t0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r8;
    // 0x800EE674: sw          $t1, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r9;
    // 0x800EE678: sw          $t2, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r10;
    // 0x800EE67C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800EE680: bne         $a0, $a1, L_800EE65C
    if (ctx->r4 != ctx->r5) {
        // 0x800EE684: addiu       $a2, $a2, 0x10
        ctx->r6 = ADD32(ctx->r6, 0X10);
            goto L_800EE65C;
    }
    // 0x800EE684: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x800EE688: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x800EE68C: j           L_800EE6DC
    // 0x800EE690: sw          $a3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r7;
        goto L_800EE6DC;
    // 0x800EE690: sw          $a3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r7;
L_800EE694:
    // 0x800EE694: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE698: addiu       $v1, $v0, -0x3EF0
    ctx->r3 = ADD32(ctx->r2, -0X3EF0);
    // 0x800EE69C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE6A0: addiu       $v0, $v0, -0x3C00
    ctx->r2 = ADD32(ctx->r2, -0X3C00);
    // 0x800EE6A4: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
L_800EE6A8:
    // 0x800EE6A8: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800EE6AC: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x800EE6B0: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x800EE6B4: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x800EE6B8: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x800EE6BC: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x800EE6C0: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
    // 0x800EE6C4: sw          $t2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r10;
    // 0x800EE6C8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800EE6CC: bne         $v0, $a0, L_800EE6A8
    if (ctx->r2 != ctx->r4) {
        // 0x800EE6D0: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800EE6A8;
    }
    // 0x800EE6D0: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_800EE6D4:
    // 0x800EE6D4: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800EE6D8: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
L_800EE6DC:
    // 0x800EE6DC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE6E0: sb          $zero, -0x3D0C($v0)
    MEM_B(-0X3D0C, ctx->r2) = 0;
L_800EE6E4:
    // 0x800EE6E4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_800EE6E8:
    // 0x800EE6E8: lbu         $v1, -0x3D97($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X3D97);
    // 0x800EE6EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EE6F0: bne         $v1, $v0, L_800EE714
    if (ctx->r3 != ctx->r2) {
        // 0x800EE6F4: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800EE714;
    }
    // 0x800EE6F4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE6F8: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800EE6FC: lw          $a0, -0x3EEC($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X3EEC);
    // 0x800EE700: lw          $v0, -0x3E5C($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X3E5C);
    // 0x800EE704: bne         $a0, $v0, L_800EE714
    if (ctx->r4 != ctx->r2) {
        // 0x800EE708: nop
    
            goto L_800EE714;
    }
    // 0x800EE708: nop

    // 0x800EE70C: jal         0x800EDD8C
    // 0x800EE710: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_800EDD8C(rdram, ctx);
        goto after_4;
    // 0x800EE710: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_4:
L_800EE714:
    // 0x800EE714: lw          $ra, 0x48($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X48);
    // 0x800EE718: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x800EE71C: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x800EE720: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x800EE724: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800EE728: jr          $ra
    // 0x800EE72C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800EE72C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_800EE730(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EE730: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800EE734: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800EE738: lbu         $v0, -0x3D04($a1)
    ctx->r2 = MEM_BU(ctx->r5, -0X3D04);
    // 0x800EE73C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800EE740: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800EE744: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800EE748: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800EE74C: bne         $v0, $a0, L_800EE78C
    if (ctx->r2 != ctx->r4) {
        // 0x800EE750: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_800EE78C;
    }
    // 0x800EE750: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800EE754: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800EE758: lwc1        $f0, -0x3D00($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, -0X3D00);
    // 0x800EE75C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE760: add.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x800EE764: lwc1        $f2, -0x3CFC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, -0X3CFC);
    // 0x800EE768: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800EE76C: nop

    // 0x800EE770: bc1f        L_800EE810
    if (!c1cs) {
        // 0x800EE774: swc1        $f0, -0x3D00($v1)
        MEM_W(-0X3D00, ctx->r3) = ctx->f0.u32l;
            goto L_800EE810;
    }
    // 0x800EE774: swc1        $f0, -0x3D00($v1)
    MEM_W(-0X3D00, ctx->r3) = ctx->f0.u32l;
    // 0x800EE778: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE77C: sb          $a0, -0x3D9E($v0)
    MEM_B(-0X3D9E, ctx->r2) = ctx->r4;
    // 0x800EE780: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE784: j           L_800EE80C
    // 0x800EE788: sb          $zero, -0x3D04($a1)
    MEM_B(-0X3D04, ctx->r5) = 0;
        goto L_800EE80C;
    // 0x800EE788: sb          $zero, -0x3D04($a1)
    MEM_B(-0X3D04, ctx->r5) = 0;
L_800EE78C:
    // 0x800EE78C: lui         $s2, 0x8011
    ctx->r18 = S32(0X8011 << 16);
    // 0x800EE790: lbu         $s1, -0x3D03($s2)
    ctx->r17 = MEM_BU(ctx->r18, -0X3D03);
    // 0x800EE794: bne         $s1, $a0, L_800EE814
    if (ctx->r17 != ctx->r4) {
        // 0x800EE798: lui         $s0, 0x8011
        ctx->r16 = S32(0X8011 << 16);
            goto L_800EE814;
    }
    // 0x800EE798: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800EE79C: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800EE7A0: lw          $v1, -0x3CF4($s0)
    ctx->r3 = MEM_W(ctx->r16, -0X3CF4);
    // 0x800EE7A4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800EE7A8: bne         $v1, $v0, L_800EE7D8
    if (ctx->r3 != ctx->r2) {
        // 0x800EE7AC: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800EE7D8;
    }
    // 0x800EE7AC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE7B0: lw          $a0, -0x3F20($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X3F20);
    // 0x800EE7B4: jal         0x80095700
    // 0x800EE7B8: nop

    func_80095700(rdram, ctx);
        goto after_0;
    // 0x800EE7B8: nop

    after_0:
    // 0x800EE7BC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800EE7C0: lw          $v1, -0x3CF8($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X3CF8);
    // 0x800EE7C4: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800EE7C8: sw          $v0, -0x3CF4($s0)
    MEM_W(-0X3CF4, ctx->r16) = ctx->r2;
    // 0x800EE7CC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800EE7D0: sw          $v1, -0x3CF8($a0)
    MEM_W(-0X3CF8, ctx->r4) = ctx->r3;
    // 0x800EE7D4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_800EE7D8:
    // 0x800EE7D8: lw          $a0, -0x3F20($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X3F20);
    // 0x800EE7DC: jal         0x80095700
    // 0x800EE7E0: nop

    func_80095700(rdram, ctx);
        goto after_1;
    // 0x800EE7E0: nop

    after_1:
    // 0x800EE7E4: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800EE7E8: lw          $v1, -0x3CF8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X3CF8);
    // 0x800EE7EC: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800EE7F0: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800EE7F4: bne         $v0, $zero, L_800EE814
    if (ctx->r2 != 0) {
        // 0x800EE7F8: lui         $s0, 0x8011
        ctx->r16 = S32(0X8011 << 16);
            goto L_800EE814;
    }
    // 0x800EE7F8: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800EE7FC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE800: sb          $s1, -0x3D9E($v0)
    MEM_B(-0X3D9E, ctx->r2) = ctx->r17;
    // 0x800EE804: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE808: sb          $zero, -0x3D03($s2)
    MEM_B(-0X3D03, ctx->r18) = 0;
L_800EE80C:
    // 0x800EE80C: sb          $zero, -0x3D0E($v0)
    MEM_B(-0X3D0E, ctx->r2) = 0;
L_800EE810:
    // 0x800EE810: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
L_800EE814:
    // 0x800EE814: lbu         $v0, -0x3D9C($s0)
    ctx->r2 = MEM_BU(ctx->r16, -0X3D9C);
    // 0x800EE818: beq         $v0, $zero, L_800EE860
    if (ctx->r2 == 0) {
        // 0x800EE81C: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800EE860;
    }
    // 0x800EE81C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE820: lw          $a0, -0x3F20($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X3F20);
    // 0x800EE824: jal         0x800957AC
    // 0x800EE828: nop

    func_800957AC(rdram, ctx);
        goto after_2;
    // 0x800EE828: nop

    after_2:
    // 0x800EE82C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800EE830: bne         $v0, $zero, L_800EE864
    if (ctx->r2 != 0) {
        // 0x800EE834: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800EE864;
    }
    // 0x800EE834: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE838: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE83C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800EE840: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800EE844: sb          $a0, -0x3D9A($v0)
    MEM_B(-0X3D9A, ctx->r2) = ctx->r4;
    // 0x800EE848: lw          $v0, -0x3620($a1)
    ctx->r2 = MEM_W(ctx->r5, -0X3620);
    // 0x800EE84C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800EE850: sb          $zero, -0x3D9C($s0)
    MEM_B(-0X3D9C, ctx->r16) = 0;
    // 0x800EE854: sb          $a0, -0x3D9E($v1)
    MEM_B(-0X3D9E, ctx->r3) = ctx->r4;
    // 0x800EE858: ori         $v0, $v0, 0x100
    ctx->r2 = ctx->r2 | 0X100;
    // 0x800EE85C: sw          $v0, -0x3620($a1)
    MEM_W(-0X3620, ctx->r5) = ctx->r2;
L_800EE860:
    // 0x800EE860: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_800EE864:
    // 0x800EE864: lbu         $s1, -0x3D0F($v0)
    ctx->r17 = MEM_BU(ctx->r2, -0X3D0F);
    // 0x800EE868: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EE86C: bne         $s1, $v0, L_800EE8B4
    if (ctx->r17 != ctx->r2) {
        // 0x800EE870: lui         $s0, 0x8011
        ctx->r16 = S32(0X8011 << 16);
            goto L_800EE8B4;
    }
    // 0x800EE870: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800EE874: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800EE878: lbu         $v0, -0x3D0E($s0)
    ctx->r2 = MEM_BU(ctx->r16, -0X3D0E);
    // 0x800EE87C: lui         $s2, 0x8011
    ctx->r18 = S32(0X8011 << 16);
    // 0x800EE880: jal         0x800EDBB0
    // 0x800EE884: sb          $v0, -0x3D0D($s2)
    MEM_B(-0X3D0D, ctx->r18) = ctx->r2;
    func_800EDBB0(rdram, ctx);
        goto after_3;
    // 0x800EE884: sb          $v0, -0x3D0D($s2)
    MEM_B(-0X3D0D, ctx->r18) = ctx->r2;
    after_3:
    // 0x800EE888: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800EE88C: lbu         $v1, -0x3D0D($s2)
    ctx->r3 = MEM_BU(ctx->r18, -0X3D0D);
    // 0x800EE890: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x800EE894: beq         $v0, $v1, L_800EE8B0
    if (ctx->r2 == ctx->r3) {
        // 0x800EE898: sb          $a0, -0x3D0E($s0)
        MEM_B(-0X3D0E, ctx->r16) = ctx->r4;
            goto L_800EE8B0;
    }
    // 0x800EE898: sb          $a0, -0x3D0E($s0)
    MEM_B(-0X3D0E, ctx->r16) = ctx->r4;
    // 0x800EE89C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE8A0: sb          $s1, -0x3D0C($v0)
    MEM_B(-0X3D0C, ctx->r2) = ctx->r17;
    // 0x800EE8A4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE8A8: sb          $a0, -0x3D0D($s2)
    MEM_B(-0X3D0D, ctx->r18) = ctx->r4;
    // 0x800EE8AC: sb          $s1, -0x3D9E($v0)
    MEM_B(-0X3D9E, ctx->r2) = ctx->r17;
L_800EE8B0:
    // 0x800EE8B0: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
L_800EE8B4:
    // 0x800EE8B4: lbu         $v0, -0x3D9E($s0)
    ctx->r2 = MEM_BU(ctx->r16, -0X3D9E);
    // 0x800EE8B8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800EE8BC: bne         $v0, $v1, L_800EE944
    if (ctx->r2 != ctx->r3) {
        // 0x800EE8C0: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800EE944;
    }
    // 0x800EE8C0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE8C4: jal         0x800EDF68
    // 0x800EE8C8: nop

    func_800EDF68(rdram, ctx);
        goto after_4;
    // 0x800EE8C8: nop

    after_4:
    // 0x800EE8CC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE8D0: lbu         $v0, -0x3DA0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X3DA0);
    // 0x800EE8D4: bne         $v0, $zero, L_800EE96C
    if (ctx->r2 != 0) {
        // 0x800EE8D8: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_800EE96C;
    }
    // 0x800EE8D8: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800EE8DC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE8E0: addiu       $a0, $v0, -0x3EF0
    ctx->r4 = ADD32(ctx->r2, -0X3EF0);
    // 0x800EE8E4: lw          $v1, -0x3F1C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X3F1C);
    // 0x800EE8E8: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x800EE8EC: beq         $v1, $v0, L_800EE96C
    if (ctx->r3 == ctx->r2) {
        // 0x800EE8F0: sb          $zero, -0x3D9E($s0)
        MEM_B(-0X3D9E, ctx->r16) = 0;
            goto L_800EE96C;
    }
    // 0x800EE8F0: sb          $zero, -0x3D9E($s0)
    MEM_B(-0X3D9E, ctx->r16) = 0;
    // 0x800EE8F4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE8F8: addiu       $v1, $v0, -0x3EC0
    ctx->r3 = ADD32(ctx->r2, -0X3EC0);
    // 0x800EE8FC: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x800EE900: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
L_800EE904:
    // 0x800EE904: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x800EE908: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x800EE90C: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x800EE910: lw          $t1, 0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XC);
    // 0x800EE914: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    // 0x800EE918: sw          $a3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r7;
    // 0x800EE91C: sw          $t0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r8;
    // 0x800EE920: sw          $t1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r9;
    // 0x800EE924: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800EE928: bne         $v0, $a0, L_800EE904
    if (ctx->r2 != ctx->r4) {
        // 0x800EE92C: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800EE904;
    }
    // 0x800EE92C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800EE930: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x800EE934: jal         0x800ED200
    // 0x800EE938: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    func_800ED200(rdram, ctx);
        goto after_5;
    // 0x800EE938: sw          $a2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r6;
    after_5:
    // 0x800EE93C: j           L_800EE96C
    // 0x800EE940: nop

        goto L_800EE96C;
    // 0x800EE940: nop

L_800EE944:
    // 0x800EE944: lbu         $v0, -0x3D97($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X3D97);
    // 0x800EE948: bne         $v0, $v1, L_800EE96C
    if (ctx->r2 != ctx->r3) {
        // 0x800EE94C: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800EE96C;
    }
    // 0x800EE94C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EE950: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800EE954: lw          $a0, -0x3F1C($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X3F1C);
    // 0x800EE958: lw          $v0, -0x3E5C($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X3E5C);
    // 0x800EE95C: bne         $a0, $v0, L_800EE96C
    if (ctx->r4 != ctx->r2) {
        // 0x800EE960: nop
    
            goto L_800EE96C;
    }
    // 0x800EE960: nop

    // 0x800EE964: jal         0x800EDD8C
    // 0x800EE968: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800EDD8C(rdram, ctx);
        goto after_6;
    // 0x800EE968: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
L_800EE96C:
    // 0x800EE96C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800EE970: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800EE974: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800EE978: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800EE97C: jr          $ra
    // 0x800EE980: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800EE980: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800EE984(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EE984: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800EE988: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x800EE98C: addiu       $a1, $a1, -0x3CE0
    ctx->r5 = ADD32(ctx->r5, -0X3CE0);
    // 0x800EE990: lbu         $v1, -0x3CF0($a2)
    ctx->r3 = MEM_BU(ctx->r6, -0X3CF0);
    // 0x800EE994: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800EE998: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x800EE99C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800EE9A0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800EE9A4: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800EE9A8: lw          $v1, -0x3C00($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X3C00);
    // 0x800EE9AC: addiu       $a0, $a0, -0x3C00
    ctx->r4 = ADD32(ctx->r4, -0X3C00);
    // 0x800EE9B0: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x800EE9B4: lhu         $v1, 0x4($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X4);
    // 0x800EE9B8: sh          $v1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r3;
    // 0x800EE9BC: lhu         $v1, 0x6($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X6);
    // 0x800EE9C0: sh          $v1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r3;
    // 0x800EE9C4: lbu         $v1, 0x8($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X8);
    // 0x800EE9C8: sb          $v1, 0xA($v0)
    MEM_B(0XA, ctx->r2) = ctx->r3;
    // 0x800EE9CC: lbu         $v1, -0x3CF0($a2)
    ctx->r3 = MEM_BU(ctx->r6, -0X3CF0);
    // 0x800EE9D0: lhu         $a0, 0xA($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0XA);
    // 0x800EE9D4: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x800EE9D8: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800EE9DC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800EE9E0: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800EE9E4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800EE9E8: sh          $a0, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r4;
    // 0x800EE9EC: jr          $ra
    // 0x800EE9F0: sb          $v1, -0x3CF0($a2)
    MEM_B(-0X3CF0, ctx->r6) = ctx->r3;
    return;
    // 0x800EE9F0: sb          $v1, -0x3CF0($a2)
    MEM_B(-0X3CF0, ctx->r6) = ctx->r3;
;}
RECOMP_FUNC void func_800EE9F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EE9F4: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800EE9F8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800EE9FC: lbu         $v0, -0x3CF0($v1)
    ctx->r2 = MEM_BU(ctx->r3, -0X3CF0);
    // 0x800EEA00: addiu       $a0, $a0, -0x3CE0
    ctx->r4 = ADD32(ctx->r4, -0X3CE0);
    // 0x800EEA04: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800EEA08: sb          $v0, -0x3CF0($v1)
    MEM_B(-0X3CF0, ctx->r3) = ctx->r2;
    // 0x800EEA0C: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x800EEA10: sll         $v0, $v1, 3
    ctx->r2 = S32(ctx->r3 << 3);
    // 0x800EEA14: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800EEA18: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800EEA1C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800EEA20: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800EEA24: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800EEA28: sw          $a0, -0x3E90($v1)
    MEM_W(-0X3E90, ctx->r3) = ctx->r4;
    // 0x800EEA2C: lhu         $a0, 0x4($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X4);
    // 0x800EEA30: addiu       $v1, $v1, -0x3E90
    ctx->r3 = ADD32(ctx->r3, -0X3E90);
    // 0x800EEA34: sh          $a0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r4;
    // 0x800EEA38: lhu         $a0, 0x6($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X6);
    // 0x800EEA3C: sh          $a0, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r4;
    // 0x800EEA40: lbu         $a0, 0xA($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0XA);
    // 0x800EEA44: sb          $a0, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r4;
    // 0x800EEA48: lhu         $v0, 0x8($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X8);
    // 0x800EEA4C: jr          $ra
    // 0x800EEA50: sh          $v0, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r2;
    return;
    // 0x800EEA50: sh          $v0, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_800EEA54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EEA54: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800EEA58: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x800EEA5C: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x800EEA60: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800EEA64: lhu         $v1, -0x4E40($a1)
    ctx->r3 = MEM_HU(ctx->r5, -0X4E40);
    // 0x800EEA68: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800EEA6C: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x800EEA70: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x800EEA74: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800EEA78: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800EEA7C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800EEA80: beq         $v1, $v0, L_800EEAA0
    if (ctx->r3 == ctx->r2) {
        // 0x800EEA84: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_800EEAA0;
    }
    // 0x800EEA84: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800EEA88: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800EEA8C: addiu       $v1, $a1, -0x4E40
    ctx->r3 = ADD32(ctx->r5, -0X4E40);
L_800EEA90:
    // 0x800EEA90: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
    // 0x800EEA94: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x800EEA98: bne         $v0, $a0, L_800EEA90
    if (ctx->r2 != ctx->r4) {
        // 0x800EEA9C: addiu       $s4, $s4, 0x1
        ctx->r20 = ADD32(ctx->r20, 0X1);
            goto L_800EEA90;
    }
    // 0x800EEA9C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
L_800EEAA0:
    // 0x800EEAA0: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800EEAA4: jal         0x80001ACC
    // 0x800EEAA8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x800EEAA8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x800EEAAC: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x800EEAB0: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x800EEAB4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800EEAB8: jal         0x800078E0
    // 0x800EEABC: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    rs_memset(rdram, ctx);
        goto after_1;
    // 0x800EEABC: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    after_1:
    // 0x800EEAC0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800EEAC4: lw          $v0, 0x75D8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X75D8);
    // 0x800EEAC8: lw          $v0, 0x30($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X30);
    // 0x800EEACC: beq         $v0, $zero, L_800EEB70
    if (ctx->r2 == 0) {
        // 0x800EEAD0: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_800EEB70;
    }
    // 0x800EEAD0: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800EEAD4: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
    // 0x800EEAD8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_800EEADC:
    // 0x800EEADC: lw          $v0, 0x75D8($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X75D8);
    // 0x800EEAE0: lw          $v1, 0x34($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X34);
    // 0x800EEAE4: sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17 << 2);
    // 0x800EEAE8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800EEAEC: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800EEAF0: lw          $v0, 0x34($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X34);
    // 0x800EEAF4: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    // 0x800EEAF8: beq         $v0, $zero, L_800EEB58
    if (ctx->r2 == 0) {
        // 0x800EEAFC: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_800EEB58;
    }
    // 0x800EEAFC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800EEB00: lw          $v1, 0x3C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X3C);
    // 0x800EEB04: sltiu       $v0, $v1, 0x2
    ctx->r2 = ctx->r3 < 0X2 ? 1 : 0;
    // 0x800EEB08: bne         $v0, $zero, L_800EEB14
    if (ctx->r2 != 0) {
        // 0x800EEB0C: addu        $v0, $v1, $s3
        ctx->r2 = ADD32(ctx->r3, ctx->r19);
            goto L_800EEB14;
    }
    // 0x800EEB0C: addu        $v0, $v1, $s3
    ctx->r2 = ADD32(ctx->r3, ctx->r19);
    // 0x800EEB10: sb          $a1, -0x2($v0)
    MEM_B(-0X2, ctx->r2) = ctx->r5;
L_800EEB14:
    // 0x800EEB14: lw          $v1, 0x40($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X40);
    // 0x800EEB18: sltiu       $v0, $v1, 0x2
    ctx->r2 = ctx->r3 < 0X2 ? 1 : 0;
    // 0x800EEB1C: bne         $v0, $zero, L_800EEB28
    if (ctx->r2 != 0) {
        // 0x800EEB20: addu        $v0, $v1, $s3
        ctx->r2 = ADD32(ctx->r3, ctx->r19);
            goto L_800EEB28;
    }
    // 0x800EEB20: addu        $v0, $v1, $s3
    ctx->r2 = ADD32(ctx->r3, ctx->r19);
    // 0x800EEB24: sb          $a1, -0x2($v0)
    MEM_B(-0X2, ctx->r2) = ctx->r5;
L_800EEB28:
    // 0x800EEB28: lw          $v1, 0x44($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X44);
    // 0x800EEB2C: sltiu       $v0, $v1, 0x2
    ctx->r2 = ctx->r3 < 0X2 ? 1 : 0;
    // 0x800EEB30: bne         $v0, $zero, L_800EEB3C
    if (ctx->r2 != 0) {
        // 0x800EEB34: addu        $v0, $v1, $s3
        ctx->r2 = ADD32(ctx->r3, ctx->r19);
            goto L_800EEB3C;
    }
    // 0x800EEB34: addu        $v0, $v1, $s3
    ctx->r2 = ADD32(ctx->r3, ctx->r19);
    // 0x800EEB38: sb          $a1, -0x2($v0)
    MEM_B(-0X2, ctx->r2) = ctx->r5;
L_800EEB3C:
    // 0x800EEB3C: lw          $v1, 0x48($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X48);
    // 0x800EEB40: sltiu       $v0, $v1, 0x2
    ctx->r2 = ctx->r3 < 0X2 ? 1 : 0;
    // 0x800EEB44: bnel        $v0, $zero, L_800EEB58
    if (ctx->r2 != 0) {
        // 0x800EEB48: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_800EEB58;
    }
    goto skip_0;
    // 0x800EEB48: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    skip_0:
    // 0x800EEB4C: addu        $v0, $v1, $s3
    ctx->r2 = ADD32(ctx->r3, ctx->r19);
    // 0x800EEB50: sb          $a1, -0x2($v0)
    MEM_B(-0X2, ctx->r2) = ctx->r5;
    // 0x800EEB54: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
L_800EEB58:
    // 0x800EEB58: lw          $v0, 0x75D8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X75D8);
    // 0x800EEB5C: lw          $v0, 0x30($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X30);
    // 0x800EEB60: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800EEB64: sltu        $v0, $s1, $v0
    ctx->r2 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x800EEB68: bne         $v0, $zero, L_800EEADC
    if (ctx->r2 != 0) {
        // 0x800EEB6C: nop
    
            goto L_800EEADC;
    }
    // 0x800EEB6C: nop

L_800EEB70:
    // 0x800EEB70: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800EEB74: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EEB78: addiu       $a2, $v0, -0x4E40
    ctx->r6 = ADD32(ctx->r2, -0X4E40);
    // 0x800EEB7C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EEB80: lw          $v1, 0xB70($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XB70);
    // 0x800EEB84: addiu       $v0, $v0, -0x4D14
    ctx->r2 = ADD32(ctx->r2, -0X4D14);
    // 0x800EEB88: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800EEB8C: lhu         $v0, 0x2($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X2);
    // 0x800EEB90: lbu         $v1, 0x0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X0);
    // 0x800EEB94: beq         $v0, $v1, L_800EEBB4
    if (ctx->r2 == ctx->r3) {
        // 0x800EEB98: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800EEBB4;
    }
    // 0x800EEB98: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800EEB9C: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x800EEBA0: addu        $v1, $a2, $zero
    ctx->r3 = ADD32(ctx->r6, 0);
L_800EEBA4:
    // 0x800EEBA4: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
    // 0x800EEBA8: lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2);
    // 0x800EEBAC: bne         $v0, $a1, L_800EEBA4
    if (ctx->r2 != ctx->r5) {
        // 0x800EEBB0: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800EEBA4;
    }
    // 0x800EEBB0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_800EEBB4:
    // 0x800EEBB4: addu        $v1, $s3, $a0
    ctx->r3 = ADD32(ctx->r19, ctx->r4);
    // 0x800EEBB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EEBBC: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x800EEBC0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800EEBC4: blez        $s4, L_800EEBEC
    if (SIGNED(ctx->r20) <= 0) {
        // 0x800EEBC8: addu        $s1, $a0, $zero
        ctx->r17 = ADD32(ctx->r4, 0);
            goto L_800EEBEC;
    }
    // 0x800EEBC8: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800EEBCC: addu        $v0, $s3, $s1
    ctx->r2 = ADD32(ctx->r19, ctx->r17);
L_800EEBD0:
    // 0x800EEBD0: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800EEBD4: bnel        $v0, $zero, L_800EEBDC
    if (ctx->r2 != 0) {
        // 0x800EEBD8: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_800EEBDC;
    }
    goto skip_1;
    // 0x800EEBD8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_1:
L_800EEBDC:
    // 0x800EEBDC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800EEBE0: slt         $v0, $s1, $s4
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800EEBE4: bne         $v0, $zero, L_800EEBD0
    if (ctx->r2 != 0) {
        // 0x800EEBE8: addu        $v0, $s3, $s1
        ctx->r2 = ADD32(ctx->r19, ctx->r17);
            goto L_800EEBD0;
    }
    // 0x800EEBE8: addu        $v0, $s3, $s1
    ctx->r2 = ADD32(ctx->r19, ctx->r17);
L_800EEBEC:
    // 0x800EEBEC: blez        $a0, L_800EED50
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800EEBF0: addiu       $s0, $a0, 0x1
        ctx->r16 = ADD32(ctx->r4, 0X1);
            goto L_800EED50;
    }
    // 0x800EEBF0: addiu       $s0, $a0, 0x1
    ctx->r16 = ADD32(ctx->r4, 0X1);
    // 0x800EEBF4: sll         $a0, $s0, 3
    ctx->r4 = S32(ctx->r16 << 3);
    // 0x800EEBF8: jal         0x80001ACC
    // 0x800EEBFC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_2;
    // 0x800EEBFC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_2:
    // 0x800EEC00: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800EEC04: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800EEC08: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x800EEC0C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800EEC10: sh          $v0, 0x2($s2)
    MEM_H(0X2, ctx->r18) = ctx->r2;
    // 0x800EEC14: blez        $s0, L_800EEC38
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800EEC18: sh          $v0, 0x6($s2)
        MEM_H(0X6, ctx->r18) = ctx->r2;
            goto L_800EEC38;
    }
    // 0x800EEC18: sh          $v0, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r2;
    // 0x800EEC1C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800EEC20: addu        $v1, $s2, $zero
    ctx->r3 = ADD32(ctx->r18, 0);
L_800EEC24:
    // 0x800EEC24: sh          $s1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r17;
    // 0x800EEC28: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800EEC2C: slt         $v0, $s1, $a0
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800EEC30: bne         $v0, $zero, L_800EEC24
    if (ctx->r2 != 0) {
        // 0x800EEC34: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_800EEC24;
    }
    // 0x800EEC34: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_800EEC38:
    // 0x800EEC38: blez        $s4, L_800EECD0
    if (SIGNED(ctx->r20) <= 0) {
        // 0x800EEC3C: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_800EECD0;
    }
    // 0x800EEC3C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800EEC40: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800EEC44: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EEC48: addiu       $a2, $v0, -0x4E40
    ctx->r6 = ADD32(ctx->r2, -0X4E40);
L_800EEC4C:
    // 0x800EEC4C: addu        $v0, $s3, $s1
    ctx->r2 = ADD32(ctx->r19, ctx->r17);
    // 0x800EEC50: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800EEC54: beq         $v0, $zero, L_800EECC0
    if (ctx->r2 == 0) {
        // 0x800EEC58: sll         $v0, $t0, 3
        ctx->r2 = S32(ctx->r8 << 3);
            goto L_800EECC0;
    }
    // 0x800EEC58: sll         $v0, $t0, 3
    ctx->r2 = S32(ctx->r8 << 3);
    // 0x800EEC5C: lbu         $v1, 0x5($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X5);
    // 0x800EEC60: addu        $a0, $s2, $v0
    ctx->r4 = ADD32(ctx->r18, ctx->r2);
    // 0x800EEC64: sh          $v1, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r3;
    // 0x800EEC68: lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X0);
    // 0x800EEC6C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800EEC70: sh          $v0, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r2;
    // 0x800EEC74: lh          $v0, 0x6($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X6);
    // 0x800EEC78: beq         $v0, $t1, L_800EECB0
    if (ctx->r2 == ctx->r9) {
        // 0x800EEC7C: addu        $s0, $s2, $zero
        ctx->r16 = ADD32(ctx->r18, 0);
            goto L_800EECB0;
    }
    // 0x800EEC7C: addu        $s0, $s2, $zero
    ctx->r16 = ADD32(ctx->r18, 0);
    // 0x800EEC80: lh          $a1, 0x2($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X2);
    // 0x800EEC84: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_800EEC88:
    // 0x800EEC88: lh          $v0, 0x6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6);
    // 0x800EEC8C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800EEC90: addu        $v1, $v0, $s2
    ctx->r3 = ADD32(ctx->r2, ctx->r18);
    // 0x800EEC94: lh          $v0, 0x2($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X2);
    // 0x800EEC98: slt         $v0, $a1, $v0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800EEC9C: bne         $v0, $zero, L_800EECB0
    if (ctx->r2 != 0) {
        // 0x800EECA0: nop
    
            goto L_800EECB0;
    }
    // 0x800EECA0: nop

    // 0x800EECA4: lh          $v0, 0x6($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X6);
    // 0x800EECA8: bne         $v0, $a3, L_800EEC88
    if (ctx->r2 != ctx->r7) {
        // 0x800EECAC: addu        $s0, $v1, $zero
        ctx->r16 = ADD32(ctx->r3, 0);
            goto L_800EEC88;
    }
    // 0x800EECAC: addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
L_800EECB0:
    // 0x800EECB0: lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X6);
    // 0x800EECB4: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x800EECB8: sh          $v0, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r2;
    // 0x800EECBC: sh          $v1, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r3;
L_800EECC0:
    // 0x800EECC0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800EECC4: slt         $v0, $s1, $s4
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800EECC8: bne         $v0, $zero, L_800EEC4C
    if (ctx->r2 != 0) {
        // 0x800EECCC: addiu       $a2, $a2, 0x6
        ctx->r6 = ADD32(ctx->r6, 0X6);
            goto L_800EEC4C;
    }
    // 0x800EECCC: addiu       $a2, $a2, 0x6
    ctx->r6 = ADD32(ctx->r6, 0X6);
L_800EECD0:
    // 0x800EECD0: lh          $v1, 0x6($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X6);
    // 0x800EECD4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800EECD8: beq         $v1, $v0, L_800EED08
    if (ctx->r3 == ctx->r2) {
        // 0x800EECDC: addu        $s0, $s2, $zero
        ctx->r16 = ADD32(ctx->r18, 0);
            goto L_800EED08;
    }
    // 0x800EECDC: addu        $s0, $s2, $zero
    ctx->r16 = ADD32(ctx->r18, 0);
    // 0x800EECE0: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x800EECE4: lh          $v0, 0x6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6);
    // 0x800EECE8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
L_800EECEC:
    // 0x800EECEC: addu        $s0, $s2, $v0
    ctx->r16 = ADD32(ctx->r18, ctx->r2);
    // 0x800EECF0: lh          $a0, 0x4($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X4);
    // 0x800EECF4: jal         0x80066918
    // 0x800EECF8: nop

    func_80066918(rdram, ctx);
        goto after_3;
    // 0x800EECF8: nop

    after_3:
    // 0x800EECFC: lh          $v0, 0x6($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X6);
    // 0x800EED00: bne         $v0, $s1, L_800EECEC
    if (ctx->r2 != ctx->r17) {
        // 0x800EED04: sll         $v0, $v0, 3
        ctx->r2 = S32(ctx->r2 << 3);
            goto L_800EECEC;
    }
    // 0x800EED04: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
L_800EED08:
    // 0x800EED08: blez        $s4, L_800EED48
    if (SIGNED(ctx->r20) <= 0) {
        // 0x800EED0C: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_800EED48;
    }
    // 0x800EED0C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800EED10: lui         $s5, 0x8014
    ctx->r21 = S32(0X8014 << 16);
    // 0x800EED14: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EED18: addiu       $s0, $v0, -0x4E40
    ctx->r16 = ADD32(ctx->r2, -0X4E40);
L_800EED1C:
    // 0x800EED1C: addu        $v0, $s3, $s1
    ctx->r2 = ADD32(ctx->r19, ctx->r17);
    // 0x800EED20: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800EED24: beq         $v0, $zero, L_800EED3C
    if (ctx->r2 == 0) {
        // 0x800EED28: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800EED3C;
    }
    // 0x800EED28: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800EED2C: lw          $a0, -0x76E0($s5)
    ctx->r4 = MEM_W(ctx->r21, -0X76E0);
    // 0x800EED30: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x800EED34: jal         0x8006657C
    // 0x800EED38: nop

    func_8006657C(rdram, ctx);
        goto after_4;
    // 0x800EED38: nop

    after_4:
L_800EED3C:
    // 0x800EED3C: slt         $v0, $s1, $s4
    ctx->r2 = SIGNED(ctx->r17) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800EED40: bne         $v0, $zero, L_800EED1C
    if (ctx->r2 != 0) {
        // 0x800EED44: addiu       $s0, $s0, 0x6
        ctx->r16 = ADD32(ctx->r16, 0X6);
            goto L_800EED1C;
    }
    // 0x800EED44: addiu       $s0, $s0, 0x6
    ctx->r16 = ADD32(ctx->r16, 0X6);
L_800EED48:
    // 0x800EED48: jal         0x80001C98
    // 0x800EED4C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    rs_free(rdram, ctx);
        goto after_5;
    // 0x800EED4C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_5:
L_800EED50:
    // 0x800EED50: jal         0x80001C98
    // 0x800EED54: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    rs_free(rdram, ctx);
        goto after_6;
    // 0x800EED54: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    after_6:
    // 0x800EED58: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x800EED5C: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x800EED60: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800EED64: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800EED68: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800EED6C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800EED70: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800EED74: jr          $ra
    // 0x800EED78: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800EED78: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800EED7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EED7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EED80: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x800EED84: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800EED88: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800EED8C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800EED90: sw          $v0, -0x3E60($v1)
    MEM_W(-0X3E60, ctx->r3) = ctx->r2;
    // 0x800EED94: lhu         $v0, 0x20($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X20);
    // 0x800EED98: addiu       $a1, $v1, -0x3E60
    ctx->r5 = ADD32(ctx->r3, -0X3E60);
    // 0x800EED9C: sh          $v0, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r2;
    // 0x800EEDA0: lhu         $v0, 0x20($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X20);
    // 0x800EEDA4: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x800EEDA8: bne         $v0, $zero, L_800EEE1C
    if (ctx->r2 != 0) {
        // 0x800EEDAC: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_800EEE1C;
    }
    // 0x800EEDAC: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800EEDB0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800EEDB4: lhu         $v1, 0x20($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X20);
    // 0x800EEDB8: addiu       $a0, $a0, -0x4E40
    ctx->r4 = ADD32(ctx->r4, -0X4E40);
    // 0x800EEDBC: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x800EEDC0: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800EEDC4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800EEDC8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800EEDCC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800EEDD0: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x800EEDD4: sh          $v0, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r2;
    // 0x800EEDD8: lhu         $v1, 0x20($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X20);
    // 0x800EEDDC: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x800EEDE0: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800EEDE4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800EEDE8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800EEDEC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800EEDF0: lhu         $v0, 0x2($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X2);
    // 0x800EEDF4: sh          $v0, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r2;
    // 0x800EEDF8: lhu         $v1, 0x20($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X20);
    // 0x800EEDFC: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x800EEE00: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800EEE04: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800EEE08: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800EEE0C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800EEE10: lbu         $v0, 0x4($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4);
    // 0x800EEE14: j           L_800EEE28
    // 0x800EEE18: sb          $v0, 0x8($a1)
    MEM_B(0X8, ctx->r5) = ctx->r2;
        goto L_800EEE28;
    // 0x800EEE18: sb          $v0, 0x8($a1)
    MEM_B(0X8, ctx->r5) = ctx->r2;
L_800EEE1C:
    // 0x800EEE1C: sh          $v0, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r2;
    // 0x800EEE20: sh          $v0, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r2;
    // 0x800EEE24: sb          $zero, 0x8($a1)
    MEM_B(0X8, ctx->r5) = 0;
L_800EEE28:
    // 0x800EEE28: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800EEE2C: addiu       $a0, $a0, -0x3E60
    ctx->r4 = ADD32(ctx->r4, -0X3E60);
    // 0x800EEE30: sb          $zero, 0xC($a0)
    MEM_B(0XC, ctx->r4) = 0;
    // 0x800EEE34: sb          $zero, 0xD($a0)
    MEM_B(0XD, ctx->r4) = 0;
    // 0x800EEE38: sb          $zero, 0xE($a0)
    MEM_B(0XE, ctx->r4) = 0;
    // 0x800EEE3C: sb          $zero, 0xF($a0)
    MEM_B(0XF, ctx->r4) = 0;
    // 0x800EEE40: sh          $zero, 0x10($a0)
    MEM_H(0X10, ctx->r4) = 0;
    // 0x800EEE44: sh          $zero, 0x12($a0)
    MEM_H(0X12, ctx->r4) = 0;
    // 0x800EEE48: lwc1        $f0, 0x0($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800EEE4C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800EEE50: swc1        $f0, -0x3BD0($v1)
    MEM_W(-0X3BD0, ctx->r3) = ctx->f0.u32l;
    // 0x800EEE54: lw          $v0, 0x8($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X8);
    // 0x800EEE58: addiu       $v1, $v1, -0x3BD0
    ctx->r3 = ADD32(ctx->r3, -0X3BD0);
    // 0x800EEE5C: sw          $v0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r2;
    // 0x800EEE60: lw          $v0, 0xC($a3)
    ctx->r2 = MEM_W(ctx->r7, 0XC);
    // 0x800EEE64: sw          $v0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r2;
    // 0x800EEE68: lhu         $v0, 0x22($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X22);
    // 0x800EEE6C: sh          $v0, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r2;
    // 0x800EEE70: lhu         $v0, 0x24($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X24);
    // 0x800EEE74: sh          $v0, 0x22($v1)
    MEM_H(0X22, ctx->r3) = ctx->r2;
    // 0x800EEE78: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EEE7C: lhu         $a1, 0x26($a3)
    ctx->r5 = MEM_HU(ctx->r7, 0X26);
    // 0x800EEE80: addiu       $a2, $v0, -0x3EC0
    ctx->r6 = ADD32(ctx->r2, -0X3EC0);
    // 0x800EEE84: sh          $a1, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r5;
    // 0x800EEE88: lbu         $v0, 0x30($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X30);
    // 0x800EEE8C: sb          $v0, 0x26($v1)
    MEM_B(0X26, ctx->r3) = ctx->r2;
    // 0x800EEE90: lbu         $v0, 0x31($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X31);
    // 0x800EEE94: addiu       $a1, $a0, 0x20
    ctx->r5 = ADD32(ctx->r4, 0X20);
    // 0x800EEE98: sb          $v0, 0x27($v1)
    MEM_B(0X27, ctx->r3) = ctx->r2;
L_800EEE9C:
    // 0x800EEE9C: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x800EEEA0: lw          $t1, 0x4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4);
    // 0x800EEEA4: lw          $t2, 0x8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X8);
    // 0x800EEEA8: lw          $t3, 0xC($a0)
    ctx->r11 = MEM_W(ctx->r4, 0XC);
    // 0x800EEEAC: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x800EEEB0: sw          $t1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r9;
    // 0x800EEEB4: sw          $t2, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r10;
    // 0x800EEEB8: sw          $t3, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r11;
    // 0x800EEEBC: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800EEEC0: bne         $a0, $a1, L_800EEE9C
    if (ctx->r4 != ctx->r5) {
        // 0x800EEEC4: addiu       $a2, $a2, 0x10
        ctx->r6 = ADD32(ctx->r6, 0X10);
            goto L_800EEE9C;
    }
    // 0x800EEEC4: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x800EEEC8: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x800EEECC: jal         0x800ED200
    // 0x800EEED0: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    func_800ED200(rdram, ctx);
        goto after_0;
    // 0x800EEED0: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    after_0:
    // 0x800EEED4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EEED8: addiu       $a1, $v0, -0x3C00
    ctx->r5 = ADD32(ctx->r2, -0X3C00);
    // 0x800EEEDC: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800EEEE0: addiu       $a0, $v1, -0x3E60
    ctx->r4 = ADD32(ctx->r3, -0X3E60);
    // 0x800EEEE4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EEEE8: lw          $v0, -0x3F20($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3F20);
    // 0x800EEEEC: addiu       $a2, $a0, 0x20
    ctx->r6 = ADD32(ctx->r4, 0X20);
    // 0x800EEEF0: sw          $v0, -0x3E60($v1)
    MEM_W(-0X3E60, ctx->r3) = ctx->r2;
L_800EEEF4:
    // 0x800EEEF4: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x800EEEF8: lw          $t1, 0x4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4);
    // 0x800EEEFC: lw          $t2, 0x8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X8);
    // 0x800EEF00: lw          $t3, 0xC($a0)
    ctx->r11 = MEM_W(ctx->r4, 0XC);
    // 0x800EEF04: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x800EEF08: sw          $t1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r9;
    // 0x800EEF0C: sw          $t2, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r10;
    // 0x800EEF10: sw          $t3, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r11;
    // 0x800EEF14: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800EEF18: bne         $a0, $a2, L_800EEEF4
    if (ctx->r4 != ctx->r6) {
        // 0x800EEF1C: addiu       $a1, $a1, 0x10
        ctx->r5 = ADD32(ctx->r5, 0X10);
            goto L_800EEEF4;
    }
    // 0x800EEF1C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800EEF20: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x800EEF24: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x800EEF28: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800EEF2C: jr          $ra
    // 0x800EEF30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800EEF30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800EEF34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EEF34: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EEF38: sb          $zero, -0x3B9F($v0)
    MEM_B(-0X3B9F, ctx->r2) = 0;
    // 0x800EEF3C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EEF40: sb          $zero, -0x3BA0($v0)
    MEM_B(-0X3BA0, ctx->r2) = 0;
    // 0x800EEF44: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EEF48: sb          $zero, -0x3B9E($v0)
    MEM_B(-0X3B9E, ctx->r2) = 0;
    // 0x800EEF4C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EEF50: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EEF54: lwc1        $f0, -0x76D0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X76D0);
    // 0x800EEF58: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x800EEF5C: beq         $a0, $zero, L_800EEF80
    if (ctx->r4 == 0) {
        // 0x800EEF60: swc1        $f0, -0x6020($v0)
        MEM_W(-0X6020, ctx->r2) = ctx->f0.u32l;
            goto L_800EEF80;
    }
    // 0x800EEF60: swc1        $f0, -0x6020($v0)
    MEM_W(-0X6020, ctx->r2) = ctx->f0.u32l;
    // 0x800EEF64: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EEF68: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800EEF6C: sw          $v1, -0x3EF0($v0)
    MEM_W(-0X3EF0, ctx->r2) = ctx->r3;
    // 0x800EEF70: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EEF74: sw          $v1, -0x3F20($v0)
    MEM_W(-0X3F20, ctx->r2) = ctx->r3;
    // 0x800EEF78: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EEF7C: sb          $zero, -0x3DA0($v0)
    MEM_B(-0X3DA0, ctx->r2) = 0;
L_800EEF80:
    // 0x800EEF80: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800EEF84: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800EEF88: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EEF8C: addiu       $v1, $v0, -0x3D90
    ctx->r3 = ADD32(ctx->r2, -0X3D90);
    // 0x800EEF90: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EEF94: sb          $zero, -0x3D9C($v0)
    MEM_B(-0X3D9C, ctx->r2) = 0;
    // 0x800EEF98: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EEF9C: sb          $zero, -0x3D9D($v0)
    MEM_B(-0X3D9D, ctx->r2) = 0;
    // 0x800EEFA0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EEFA4: sb          $zero, -0x3D9E($v0)
    MEM_B(-0X3D9E, ctx->r2) = 0;
    // 0x800EEFA8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EEFAC: sb          $zero, -0x3D9A($v0)
    MEM_B(-0X3D9A, ctx->r2) = 0;
    // 0x800EEFB0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EEFB4: sb          $zero, -0x3D9B($v0)
    MEM_B(-0X3D9B, ctx->r2) = 0;
    // 0x800EEFB8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EEFBC: sb          $zero, -0x3D98($v0)
    MEM_B(-0X3D98, ctx->r2) = 0;
    // 0x800EEFC0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EEFC4: sb          $zero, -0x3D99($v0)
    MEM_B(-0X3D99, ctx->r2) = 0;
    // 0x800EEFC8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EEFCC: sb          $zero, -0x3D97($v0)
    MEM_B(-0X3D97, ctx->r2) = 0;
    // 0x800EEFD0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EEFD4: sb          $zero, -0x3D10($v0)
    MEM_B(-0X3D10, ctx->r2) = 0;
    // 0x800EEFD8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EEFDC: sb          $zero, -0x3D03($v0)
    MEM_B(-0X3D03, ctx->r2) = 0;
    // 0x800EEFE0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EEFE4: sb          $zero, -0x3D04($v0)
    MEM_B(-0X3D04, ctx->r2) = 0;
    // 0x800EEFE8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EEFEC: sw          $zero, -0x3D00($v0)
    MEM_W(-0X3D00, ctx->r2) = 0;
    // 0x800EEFF0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EEFF4: sw          $zero, -0x3CF8($v0)
    MEM_W(-0X3CF8, ctx->r2) = 0;
    // 0x800EEFF8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EEFFC: sb          $zero, -0x3D0F($v0)
    MEM_B(-0X3D0F, ctx->r2) = 0;
    // 0x800EF000: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EF004: sb          $zero, -0x3D0C($v0)
    MEM_B(-0X3D0C, ctx->r2) = 0;
    // 0x800EF008: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EF00C: sb          $zero, -0x3D0D($v0)
    MEM_B(-0X3D0D, ctx->r2) = 0;
    // 0x800EF010: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EF014: sb          $zero, -0x3D0E($v0)
    MEM_B(-0X3D0E, ctx->r2) = 0;
L_800EF018:
    // 0x800EF018: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800EF01C: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x800EF020: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800EF024: slti        $v0, $a0, 0x8
    ctx->r2 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800EF028: bne         $v0, $zero, L_800EF018
    if (ctx->r2 != 0) {
        // 0x800EF02C: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800EF018;
    }
    // 0x800EF02C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800EF030: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EF034: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800EF038: sb          $zero, -0x3CF0($v0)
    MEM_B(-0X3CF0, ctx->r2) = 0;
    // 0x800EF03C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800EF040: jr          $ra
    // 0x800EF044: sw          $v0, -0x3CF4($v1)
    MEM_W(-0X3CF4, ctx->r3) = ctx->r2;
    return;
    // 0x800EF044: sw          $v0, -0x3CF4($v1)
    MEM_W(-0X3CF4, ctx->r3) = ctx->r2;
;}
RECOMP_FUNC void func_800EF048(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EF048: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800EF04C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800EF050: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800EF054: jal         0x800EEF34
    // 0x800EF058: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_800EEF34(rdram, ctx);
        goto after_0;
    // 0x800EF058: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x800EF05C: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    // 0x800EF060: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800EF064: lw          $a0, -0x64AC($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X64AC);
    // 0x800EF068: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800EF06C: lw          $a2, -0x330($v0)
    ctx->r6 = MEM_W(ctx->r2, -0X330);
    // 0x800EF070: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800EF074: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x800EF078: lw          $a3, -0x64B4($v0)
    ctx->r7 = MEM_W(ctx->r2, -0X64B4);
    // 0x800EF07C: lw          $v1, -0x64B0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X64B0);
    // 0x800EF080: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EF084: sb          $zero, -0x3BDC($v0)
    MEM_B(-0X3BDC, ctx->r2) = 0;
    // 0x800EF088: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EF08C: sw          $zero, -0x3DD0($v0)
    MEM_W(-0X3DD0, ctx->r2) = 0;
    // 0x800EF090: addiu       $v0, $v0, -0x3DD0
    ctx->r2 = ADD32(ctx->r2, -0X3DD0);
    // 0x800EF094: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x800EF098: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x800EF09C: sb          $zero, 0x27($v0)
    MEM_B(0X27, ctx->r2) = 0;
    // 0x800EF0A0: sb          $zero, 0x26($v0)
    MEM_B(0X26, ctx->r2) = 0;
    // 0x800EF0A4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800EF0A8: jal         0x80097518
    // 0x800EF0AC: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    func_80097518(rdram, ctx);
        goto after_1;
    // 0x800EF0AC: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    after_1:
    // 0x800EF0B0: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x800EF0B4: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x800EF0B8: jal         0x8006657C
    // 0x800EF0BC: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    func_8006657C(rdram, ctx);
        goto after_2;
    // 0x800EF0BC: addiu       $a1, $zero, 0x35
    ctx->r5 = ADD32(0, 0X35);
    after_2:
    // 0x800EF0C0: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x800EF0C4: jal         0x8006657C
    // 0x800EF0C8: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    func_8006657C(rdram, ctx);
        goto after_3;
    // 0x800EF0C8: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    after_3:
    // 0x800EF0CC: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x800EF0D0: jal         0x8006657C
    // 0x800EF0D4: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    func_8006657C(rdram, ctx);
        goto after_4;
    // 0x800EF0D4: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    after_4:
    // 0x800EF0D8: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x800EF0DC: jal         0x8006657C
    // 0x800EF0E0: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    func_8006657C(rdram, ctx);
        goto after_5;
    // 0x800EF0E0: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    after_5:
    // 0x800EF0E4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800EF0E8: lw          $v1, 0xB70($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB70);
    // 0x800EF0EC: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800EF0F0: beq         $v1, $v0, L_800EF138
    if (ctx->r3 == ctx->r2) {
        // 0x800EF0F4: slti        $v0, $v1, 0x9
        ctx->r2 = SIGNED(ctx->r3) < 0X9 ? 1 : 0;
            goto L_800EF138;
    }
    // 0x800EF0F4: slti        $v0, $v1, 0x9
    ctx->r2 = SIGNED(ctx->r3) < 0X9 ? 1 : 0;
    // 0x800EF0F8: beq         $v0, $zero, L_800EF110
    if (ctx->r2 == 0) {
        // 0x800EF0FC: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_800EF110;
    }
    // 0x800EF0FC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800EF100: beq         $v1, $v0, L_800EF12C
    if (ctx->r3 == ctx->r2) {
        // 0x800EF104: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800EF12C;
    }
    // 0x800EF104: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800EF108: j           L_800EF164
    // 0x800EF10C: nop

        goto L_800EF164;
    // 0x800EF10C: nop

L_800EF110:
    // 0x800EF110: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x800EF114: beq         $v1, $v0, L_800EF144
    if (ctx->r3 == ctx->r2) {
        // 0x800EF118: addiu       $v0, $zero, 0x12
        ctx->r2 = ADD32(0, 0X12);
            goto L_800EF144;
    }
    // 0x800EF118: addiu       $v0, $zero, 0x12
    ctx->r2 = ADD32(0, 0X12);
    // 0x800EF11C: beq         $v1, $v0, L_800EF150
    if (ctx->r3 == ctx->r2) {
        // 0x800EF120: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800EF150;
    }
    // 0x800EF120: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800EF124: j           L_800EF164
    // 0x800EF128: nop

        goto L_800EF164;
    // 0x800EF128: nop

L_800EF12C:
    // 0x800EF12C: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x800EF130: j           L_800EF158
    // 0x800EF134: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
        goto L_800EF158;
    // 0x800EF134: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
L_800EF138:
    // 0x800EF138: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x800EF13C: j           L_800EF158
    // 0x800EF140: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
        goto L_800EF158;
    // 0x800EF140: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
L_800EF144:
    // 0x800EF144: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x800EF148: jal         0x8006657C
    // 0x800EF14C: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    func_8006657C(rdram, ctx);
        goto after_6;
    // 0x800EF14C: addiu       $a1, $zero, 0x3A
    ctx->r5 = ADD32(0, 0X3A);
    after_6:
L_800EF150:
    // 0x800EF150: lw          $a0, -0x76E0($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X76E0);
    // 0x800EF154: addiu       $a1, $zero, 0x3B
    ctx->r5 = ADD32(0, 0X3B);
L_800EF158:
    // 0x800EF158: jal         0x8006657C
    // 0x800EF15C: nop

    func_8006657C(rdram, ctx);
        goto after_7;
    // 0x800EF15C: nop

    after_7:
    // 0x800EF160: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
L_800EF164:
    // 0x800EF164: lw          $a0, -0x64AC($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X64AC);
    // 0x800EF168: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800EF16C: lw          $a2, -0x330($v0)
    ctx->r6 = MEM_W(ctx->r2, -0X330);
    // 0x800EF170: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800EF174: lw          $a3, -0x64B4($v0)
    ctx->r7 = MEM_W(ctx->r2, -0X64B4);
    // 0x800EF178: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800EF17C: lw          $v0, -0x64B0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X64B0);
    // 0x800EF180: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    // 0x800EF184: jal         0x80097518
    // 0x800EF188: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    func_80097518(rdram, ctx);
        goto after_8;
    // 0x800EF188: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_8:
    // 0x800EF18C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800EF190: lw          $a0, -0x76E0($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X76E0);
    // 0x800EF194: jal         0x8006657C
    // 0x800EF198: addiu       $a1, $zero, 0x59
    ctx->r5 = ADD32(0, 0X59);
    func_8006657C(rdram, ctx);
        goto after_9;
    // 0x800EF198: addiu       $a1, $zero, 0x59
    ctx->r5 = ADD32(0, 0X59);
    after_9:
    // 0x800EF19C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800EF1A0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800EF1A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EF1A8: jr          $ra
    // 0x800EF1AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800EF1AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800EF1B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EF1B0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800EF1B4: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800EF1B8: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x800EF1BC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800EF1C0: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800EF1C4: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800EF1C8: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x800EF1CC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EF1D0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800EF1D4: addiu       $s0, $v0, -0x3D90
    ctx->r16 = ADD32(ctx->r2, -0X3D90);
    // 0x800EF1D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
L_800EF1DC:
    // 0x800EF1DC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800EF1E0: beql        $v0, $s2, L_800EF1F8
    if (ctx->r2 == ctx->r18) {
        // 0x800EF1E4: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800EF1F8;
    }
    goto skip_0;
    // 0x800EF1E4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x800EF1E8: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800EF1EC: jal         0x80095D58
    // 0x800EF1F0: sw          $s2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r18;
    func_80095D58(rdram, ctx);
        goto after_0;
    // 0x800EF1F0: sw          $s2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r18;
    after_0:
    // 0x800EF1F4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800EF1F8:
    // 0x800EF1F8: slti        $v0, $s1, 0x8
    ctx->r2 = SIGNED(ctx->r17) < 0X8 ? 1 : 0;
    // 0x800EF1FC: bne         $v0, $zero, L_800EF1DC
    if (ctx->r2 != 0) {
        // 0x800EF200: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_800EF1DC;
    }
    // 0x800EF200: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x800EF204: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EF208: lbu         $v0, -0x3DA0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X3DA0);
    // 0x800EF20C: beq         $v0, $zero, L_800EF278
    if (ctx->r2 == 0) {
        // 0x800EF210: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800EF278;
    }
    // 0x800EF210: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EF214: lw          $a0, -0x3F20($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X3F20);
    // 0x800EF218: jal         0x80095D58
    // 0x800EF21C: nop

    func_80095D58(rdram, ctx);
        goto after_1;
    // 0x800EF21C: nop

    after_1:
    // 0x800EF220: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EF224: lwc1        $f0, -0x76CC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X76CC);
    // 0x800EF228: mul.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800EF22C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EF230: lwc1        $f2, -0x76C8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X76C8);
    // 0x800EF234: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800EF238: nop

    // 0x800EF23C: bc1tl       L_800EF254
    if (c1cs) {
        // 0x800EF240: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800EF254;
    }
    goto skip_1;
    // 0x800EF240: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_1:
    // 0x800EF244: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800EF248: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800EF24C: j           L_800EF268
    // 0x800EF250: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
        goto L_800EF268;
    // 0x800EF250: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_800EF254:
    // 0x800EF254: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800EF258: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800EF25C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800EF260: or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    // 0x800EF264: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_800EF268:
    // 0x800EF268: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EF26C: lw          $a2, -0x3EC0($v0)
    ctx->r6 = MEM_W(ctx->r2, -0X3EC0);
    // 0x800EF270: j           L_800EF2CC
    // 0x800EF274: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
        goto L_800EF2CC;
    // 0x800EF274: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
L_800EF278:
    // 0x800EF278: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EF27C: lwc1        $f0, -0x76C4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X76C4);
    // 0x800EF280: mul.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800EF284: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EF288: lwc1        $f2, -0x76C0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X76C0);
    // 0x800EF28C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800EF290: nop

    // 0x800EF294: bc1tl       L_800EF2AC
    if (c1cs) {
        // 0x800EF298: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800EF2AC;
    }
    goto skip_2;
    // 0x800EF298: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_2:
    // 0x800EF29C: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800EF2A0: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800EF2A4: j           L_800EF2C0
    // 0x800EF2A8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
        goto L_800EF2C0;
    // 0x800EF2A8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_800EF2AC:
    // 0x800EF2AC: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800EF2B0: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800EF2B4: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800EF2B8: or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    // 0x800EF2BC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_800EF2C0:
    // 0x800EF2C0: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x800EF2C4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EF2C8: lw          $a2, -0x3F20($v0)
    ctx->r6 = MEM_W(ctx->r2, -0X3F20);
L_800EF2CC:
    // 0x800EF2CC: jal         0x800964C8
    // 0x800EF2D0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    func_800964C8(rdram, ctx);
        goto after_2;
    // 0x800EF2D0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x800EF2D4: jal         0x800EEF34
    // 0x800EF2D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800EEF34(rdram, ctx);
        goto after_3;
    // 0x800EF2D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x800EF2DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800EF2E0: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800EF2E4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800EF2E8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800EF2EC: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800EF2F0: jr          $ra
    // 0x800EF2F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800EF2F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800EF2F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EF2F8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EF2FC: lbu         $v0, -0x3BDC($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X3BDC);
    // 0x800EF300: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800EF304: sdc1        $f20, 0x60($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X60, ctx->r29);
    // 0x800EF308: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x800EF30C: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x800EF310: sw          $s2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r18;
    // 0x800EF314: sw          $s1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r17;
    // 0x800EF318: bne         $v0, $zero, L_800EF3B8
    if (ctx->r2 != 0) {
        // 0x800EF31C: sw          $s0, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r16;
            goto L_800EF3B8;
    }
    // 0x800EF31C: sw          $s0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r16;
    // 0x800EF320: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800EF324: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EF328: addiu       $a2, $v0, -0x4E40
    ctx->r6 = ADD32(ctx->r2, -0X4E40);
    // 0x800EF32C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EF330: lw          $v1, 0xB70($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XB70);
    // 0x800EF334: addiu       $v0, $v0, -0x4D14
    ctx->r2 = ADD32(ctx->r2, -0X4D14);
    // 0x800EF338: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800EF33C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800EF340: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800EF344: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800EF348: lhu         $v0, 0x2($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X2);
    // 0x800EF34C: lbu         $v1, 0x0($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X0);
    // 0x800EF350: beq         $v0, $v1, L_800EF370
    if (ctx->r2 == ctx->r3) {
        // 0x800EF354: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_800EF370;
    }
    // 0x800EF354: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800EF358: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x800EF35C: addu        $v1, $a2, $zero
    ctx->r3 = ADD32(ctx->r6, 0);
L_800EF360:
    // 0x800EF360: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
    // 0x800EF364: lhu         $v0, 0x2($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X2);
    // 0x800EF368: bne         $v0, $a0, L_800EF360
    if (ctx->r2 != ctx->r4) {
        // 0x800EF36C: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800EF360;
    }
    // 0x800EF36C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_800EF370:
    // 0x800EF370: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800EF374: addiu       $v0, $a1, 0x2
    ctx->r2 = ADD32(ctx->r5, 0X2);
    // 0x800EF378: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800EF37C: sh          $v0, 0x30($sp)
    MEM_H(0X30, ctx->r29) = ctx->r2;
    // 0x800EF380: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800EF384: sh          $v0, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r2;
    // 0x800EF388: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EF38C: sh          $v1, 0x32($sp)
    MEM_H(0X32, ctx->r29) = ctx->r3;
    // 0x800EF390: sh          $v1, 0x34($sp)
    MEM_H(0X34, ctx->r29) = ctx->r3;
    // 0x800EF394: sh          $v1, 0x36($sp)
    MEM_H(0X36, ctx->r29) = ctx->r3;
    // 0x800EF398: sh          $zero, 0x38($sp)
    MEM_H(0X38, ctx->r29) = 0;
    // 0x800EF39C: sh          $zero, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = 0;
    // 0x800EF3A0: sb          $v1, 0x3E($sp)
    MEM_B(0X3E, ctx->r29) = ctx->r3;
    // 0x800EF3A4: sb          $v1, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r3;
    // 0x800EF3A8: sb          $zero, 0x40($sp)
    MEM_B(0X40, ctx->r29) = 0;
    // 0x800EF3AC: sb          $zero, 0x41($sp)
    MEM_B(0X41, ctx->r29) = 0;
    // 0x800EF3B0: jal         0x800EED7C
    // 0x800EF3B4: sb          $v1, -0x3BDC($v0)
    MEM_B(-0X3BDC, ctx->r2) = ctx->r3;
    func_800EED7C(rdram, ctx);
        goto after_0;
    // 0x800EF3B4: sb          $v1, -0x3BDC($v0)
    MEM_B(-0X3BDC, ctx->r2) = ctx->r3;
    after_0:
L_800EF3B8:
    // 0x800EF3B8: lui         $s2, 0x8011
    ctx->r18 = S32(0X8011 << 16);
    // 0x800EF3BC: lbu         $v1, -0x3DA0($s2)
    ctx->r3 = MEM_BU(ctx->r18, -0X3DA0);
    // 0x800EF3C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EF3C4: bne         $v1, $v0, L_800EF4EC
    if (ctx->r3 != ctx->r2) {
        // 0x800EF3C8: lui         $s1, 0x8011
        ctx->r17 = S32(0X8011 << 16);
            goto L_800EF4EC;
    }
    // 0x800EF3C8: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x800EF3CC: lbu         $v0, -0x3D9F($s1)
    ctx->r2 = MEM_BU(ctx->r17, -0X3D9F);
    // 0x800EF3D0: bne         $v0, $v1, L_800EF450
    if (ctx->r2 != ctx->r3) {
        // 0x800EF3D4: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800EF450;
    }
    // 0x800EF3D4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EF3D8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EF3DC: lw          $a0, -0x3F20($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X3F20);
    // 0x800EF3E0: jal         0x800957AC
    // 0x800EF3E4: addiu       $s0, $v0, -0x3F20
    ctx->r16 = ADD32(ctx->r2, -0X3F20);
    func_800957AC(rdram, ctx);
        goto after_1;
    // 0x800EF3E4: addiu       $s0, $v0, -0x3F20
    ctx->r16 = ADD32(ctx->r2, -0X3F20);
    after_1:
    // 0x800EF3E8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800EF3EC: bne         $v0, $zero, L_800EF4F4
    if (ctx->r2 != 0) {
        // 0x800EF3F0: addu        $v1, $s0, $zero
        ctx->r3 = ADD32(ctx->r16, 0);
            goto L_800EF4F4;
    }
    // 0x800EF3F0: addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
    // 0x800EF3F4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EF3F8: addiu       $v0, $v0, -0x3EC0
    ctx->r2 = ADD32(ctx->r2, -0X3EC0);
    // 0x800EF3FC: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
    // 0x800EF400: sb          $zero, -0x3D9F($s1)
    MEM_B(-0X3D9F, ctx->r17) = 0;
    // 0x800EF404: sb          $zero, -0x3DA0($s2)
    MEM_B(-0X3DA0, ctx->r18) = 0;
L_800EF408:
    // 0x800EF408: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800EF40C: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x800EF410: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x800EF414: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x800EF418: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x800EF41C: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x800EF420: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
    // 0x800EF424: sw          $t2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r10;
    // 0x800EF428: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800EF42C: bne         $v0, $a0, L_800EF408
    if (ctx->r2 != ctx->r4) {
        // 0x800EF430: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800EF408;
    }
    // 0x800EF430: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800EF434: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800EF438: sw          $a3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r7;
    // 0x800EF43C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EF440: sb          $zero, -0x3D9D($v0)
    MEM_B(-0X3D9D, ctx->r2) = 0;
    // 0x800EF444: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EF448: j           L_800EF4F4
    // 0x800EF44C: sw          $zero, -0x3D00($v0)
    MEM_W(-0X3D00, ctx->r2) = 0;
        goto L_800EF4F4;
    // 0x800EF44C: sw          $zero, -0x3D00($v0)
    MEM_W(-0X3D00, ctx->r2) = 0;
L_800EF450:
    // 0x800EF450: addiu       $s0, $v0, -0x3EC0
    ctx->r16 = ADD32(ctx->r2, -0X3EC0);
    // 0x800EF454: jal         0x80096CE4
    // 0x800EF458: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_80096CE4(rdram, ctx);
        goto after_2;
    // 0x800EF458: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_2:
    // 0x800EF45C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800EF460: beq         $v0, $zero, L_800EF4F4
    if (ctx->r2 == 0) {
        // 0x800EF464: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800EF4F4;
    }
    // 0x800EF464: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EF468: addiu       $v0, $v0, -0x3F20
    ctx->r2 = ADD32(ctx->r2, -0X3F20);
    // 0x800EF46C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800EF470: addiu       $v1, $a0, 0x20
    ctx->r3 = ADD32(ctx->r4, 0X20);
    // 0x800EF474: sb          $zero, -0x3D9F($s1)
    MEM_B(-0X3D9F, ctx->r17) = 0;
    // 0x800EF478: sb          $zero, -0x3DA0($s2)
    MEM_B(-0X3DA0, ctx->r18) = 0;
L_800EF47C:
    // 0x800EF47C: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x800EF480: lw          $t0, 0x4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4);
    // 0x800EF484: lw          $t1, 0x8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X8);
    // 0x800EF488: lw          $t2, 0xC($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XC);
    // 0x800EF48C: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x800EF490: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800EF494: sw          $t1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r9;
    // 0x800EF498: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x800EF49C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800EF4A0: bne         $a0, $v1, L_800EF47C
    if (ctx->r4 != ctx->r3) {
        // 0x800EF4A4: addiu       $v0, $v0, 0x10
        ctx->r2 = ADD32(ctx->r2, 0X10);
            goto L_800EF47C;
    }
    // 0x800EF4A4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800EF4A8: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800EF4AC: lbu         $v1, -0x3D9B($a1)
    ctx->r3 = MEM_BU(ctx->r5, -0X3D9B);
    // 0x800EF4B0: lw          $a3, 0x0($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X0);
    // 0x800EF4B4: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x800EF4B8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EF4BC: beq         $v1, $zero, L_800EF4F4
    if (ctx->r3 == 0) {
        // 0x800EF4C0: sw          $zero, -0x3D00($v0)
        MEM_W(-0X3D00, ctx->r2) = 0;
            goto L_800EF4F4;
    }
    // 0x800EF4C0: sw          $zero, -0x3D00($v0)
    MEM_W(-0X3D00, ctx->r2) = 0;
    // 0x800EF4C4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EF4C8: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800EF4CC: lw          $a0, -0x3F20($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X3F20);
    // 0x800EF4D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EF4D4: sb          $zero, -0x3D9B($a1)
    MEM_B(-0X3D9B, ctx->r5) = 0;
    // 0x800EF4D8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800EF4DC: jal         0x80095DF4
    // 0x800EF4E0: sb          $v0, -0x3D9C($v1)
    MEM_B(-0X3D9C, ctx->r3) = ctx->r2;
    func_80095DF4(rdram, ctx);
        goto after_3;
    // 0x800EF4E0: sb          $v0, -0x3D9C($v1)
    MEM_B(-0X3D9C, ctx->r3) = ctx->r2;
    after_3:
    // 0x800EF4E4: j           L_800EF4F4
    // 0x800EF4E8: nop

        goto L_800EF4F4;
    // 0x800EF4E8: nop

L_800EF4EC:
    // 0x800EF4EC: jal         0x800EE730
    // 0x800EF4F0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    func_800EE730(rdram, ctx);
        goto after_4;
    // 0x800EF4F0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_4:
L_800EF4F4:
    // 0x800EF4F4: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x800EF4F8: lw          $s2, 0x58($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X58);
    // 0x800EF4FC: lw          $s1, 0x54($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X54);
    // 0x800EF500: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x800EF504: ldc1        $f20, 0x60($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X60);
    // 0x800EF508: jr          $ra
    // 0x800EF50C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800EF50C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_800EF510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EF510: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EF514: lw          $v0, -0x35E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X35E0);
    // 0x800EF518: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800EF51C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800EF520: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800EF524: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800EF528: beq         $v0, $zero, L_800EF538
    if (ctx->r2 == 0) {
        // 0x800EF52C: sw          $s1, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r17;
            goto L_800EF538;
    }
    // 0x800EF52C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800EF530: j           L_800EF75C
    // 0x800EF534: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_800EF75C;
    // 0x800EF534: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800EF538:
    // 0x800EF538: lbu         $v0, 0x2E($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2E);
    // 0x800EF53C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800EF540: bne         $v0, $s1, L_800EF594
    if (ctx->r2 != ctx->r17) {
        // 0x800EF544: nop
    
            goto L_800EF594;
    }
    // 0x800EF544: nop

    // 0x800EF548: jal         0x800EE984
    // 0x800EF54C: nop

    func_800EE984(rdram, ctx);
        goto after_0;
    // 0x800EF54C: nop

    after_0:
    // 0x800EF550: lhu         $v0, 0x20($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X20);
    // 0x800EF554: beql        $v0, $zero, L_800EF5A8
    if (ctx->r2 == 0) {
        // 0x800EF558: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800EF5A8;
    }
    goto skip_0;
    // 0x800EF558: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    skip_0:
    // 0x800EF55C: bne         $v0, $s1, L_800EF5D4
    if (ctx->r2 != ctx->r17) {
        // 0x800EF560: lui         $a1, 0x8011
        ctx->r5 = S32(0X8011 << 16);
            goto L_800EF5D4;
    }
    // 0x800EF560: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800EF564: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800EF568: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EF56C: addiu       $v0, $v0, -0x3C00
    ctx->r2 = ADD32(ctx->r2, -0X3C00);
    // 0x800EF570: lhu         $a0, 0x4($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X4);
    // 0x800EF574: lhu         $a1, 0x6($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X6);
    // 0x800EF578: lbu         $v0, 0x8($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X8);
    // 0x800EF57C: addiu       $v1, $v1, -0x3E90
    ctx->r3 = ADD32(ctx->r3, -0X3E90);
    // 0x800EF580: sh          $s1, 0xA($v1)
    MEM_H(0XA, ctx->r3) = ctx->r17;
    // 0x800EF584: sh          $a0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r4;
    // 0x800EF588: sh          $a1, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r5;
    // 0x800EF58C: j           L_800EF648
    // 0x800EF590: sb          $v0, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r2;
        goto L_800EF648;
    // 0x800EF590: sb          $v0, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r2;
L_800EF594:
    // 0x800EF594: jal         0x800EE9F4
    // 0x800EF598: nop

    func_800EE9F4(rdram, ctx);
        goto after_1;
    // 0x800EF598: nop

    after_1:
    // 0x800EF59C: lhu         $v1, 0x20($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X20);
    // 0x800EF5A0: bne         $v1, $zero, L_800EF5C0
    if (ctx->r3 != 0) {
        // 0x800EF5A4: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800EF5C0;
    }
    // 0x800EF5A4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_800EF5A8:
    // 0x800EF5A8: addiu       $v0, $v0, -0x3E90
    ctx->r2 = ADD32(ctx->r2, -0X3E90);
    // 0x800EF5AC: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // 0x800EF5B0: sh          $zero, 0xA($v0)
    MEM_H(0XA, ctx->r2) = 0;
    // 0x800EF5B4: sh          $v1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r3;
    // 0x800EF5B8: j           L_800EF648
    // 0x800EF5BC: sh          $v1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r3;
        goto L_800EF648;
    // 0x800EF5BC: sh          $v1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r3;
L_800EF5C0:
    // 0x800EF5C0: bne         $v1, $s1, L_800EF5D4
    if (ctx->r3 != ctx->r17) {
        // 0x800EF5C4: lui         $a1, 0x8011
        ctx->r5 = S32(0X8011 << 16);
            goto L_800EF5D4;
    }
    // 0x800EF5C4: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800EF5C8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EF5CC: j           L_800EF648
    // 0x800EF5D0: sh          $v1, -0x3E86($v0)
    MEM_H(-0X3E86, ctx->r2) = ctx->r3;
        goto L_800EF648;
    // 0x800EF5D0: sh          $v1, -0x3E86($v0)
    MEM_H(-0X3E86, ctx->r2) = ctx->r3;
L_800EF5D4:
    // 0x800EF5D4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800EF5D8: lhu         $v1, 0x20($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X20);
    // 0x800EF5DC: addiu       $a0, $a0, -0x4E40
    ctx->r4 = ADD32(ctx->r4, -0X4E40);
    // 0x800EF5E0: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x800EF5E4: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800EF5E8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800EF5EC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800EF5F0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800EF5F4: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x800EF5F8: addiu       $a1, $a1, -0x3E90
    ctx->r5 = ADD32(ctx->r5, -0X3E90);
    // 0x800EF5FC: sh          $v0, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r2;
    // 0x800EF600: lhu         $v1, 0x20($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X20);
    // 0x800EF604: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x800EF608: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800EF60C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800EF610: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800EF614: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800EF618: lhu         $v0, 0x2($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X2);
    // 0x800EF61C: sh          $v0, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r2;
    // 0x800EF620: lhu         $v1, 0x20($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X20);
    // 0x800EF624: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x800EF628: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800EF62C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800EF630: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800EF634: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800EF638: lbu         $v0, 0x4($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4);
    // 0x800EF63C: sb          $v0, 0x8($a1)
    MEM_B(0X8, ctx->r5) = ctx->r2;
    // 0x800EF640: lhu         $v0, 0x20($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X20);
    // 0x800EF644: sh          $v0, 0xA($a1)
    MEM_H(0XA, ctx->r5) = ctx->r2;
L_800EF648:
    // 0x800EF648: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EF64C: addiu       $v0, $v0, -0x3E90
    ctx->r2 = ADD32(ctx->r2, -0X3E90);
    // 0x800EF650: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800EF654: lbu         $a1, 0x2F($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X2F);
    // 0x800EF658: lh          $v1, 0xA($v0)
    ctx->r3 = MEM_H(ctx->r2, 0XA);
    // 0x800EF65C: addiu       $a2, $a0, -0x3C00
    ctx->r6 = ADD32(ctx->r4, -0X3C00);
    // 0x800EF660: sb          $zero, 0xD($v0)
    MEM_B(0XD, ctx->r2) = 0;
    // 0x800EF664: xori        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 ^ 0X1;
    // 0x800EF668: sltiu       $v1, $v1, 0x1
    ctx->r3 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x800EF66C: sb          $a1, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r5;
    // 0x800EF670: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800EF674: sb          $v1, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r3;
    // 0x800EF678: lbu         $v1, 0x32($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X32);
    // 0x800EF67C: addiu       $a3, $a1, 0x20
    ctx->r7 = ADD32(ctx->r5, 0X20);
    // 0x800EF680: sb          $v1, 0xF($a1)
    MEM_B(0XF, ctx->r5) = ctx->r3;
    // 0x800EF684: lhu         $v0, 0x2A($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2A);
    // 0x800EF688: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800EF68C: sh          $v0, 0x10($a1)
    MEM_H(0X10, ctx->r5) = ctx->r2;
    // 0x800EF690: lhu         $a0, 0x28($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X28);
    // 0x800EF694: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EF698: sb          $v0, -0x3D99($v1)
    MEM_B(-0X3D99, ctx->r3) = ctx->r2;
    // 0x800EF69C: sh          $a0, 0x12($a1)
    MEM_H(0X12, ctx->r5) = ctx->r4;
L_800EF6A0:
    // 0x800EF6A0: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x800EF6A4: lw          $t1, 0x4($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X4);
    // 0x800EF6A8: lw          $t2, 0x8($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X8);
    // 0x800EF6AC: lw          $t3, 0xC($a1)
    ctx->r11 = MEM_W(ctx->r5, 0XC);
    // 0x800EF6B0: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x800EF6B4: sw          $t1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r9;
    // 0x800EF6B8: sw          $t2, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r10;
    // 0x800EF6BC: sw          $t3, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r11;
    // 0x800EF6C0: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800EF6C4: bne         $a1, $a3, L_800EF6A0
    if (ctx->r5 != ctx->r7) {
        // 0x800EF6C8: addiu       $a2, $a2, 0x10
        ctx->r6 = ADD32(ctx->r6, 0X10);
            goto L_800EF6A0;
    }
    // 0x800EF6C8: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x800EF6CC: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800EF6D0: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x800EF6D4: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x800EF6D8: lbu         $v0, 0x2E($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2E);
    // 0x800EF6DC: addiu       $a0, $v1, -0x3DD0
    ctx->r4 = ADD32(ctx->r3, -0X3DD0);
    // 0x800EF6E0: sb          $v0, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r2;
    // 0x800EF6E4: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800EF6E8: swc1        $f0, -0x3DD0($v1)
    MEM_W(-0X3DD0, ctx->r3) = ctx->f0.u32l;
    // 0x800EF6EC: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800EF6F0: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x800EF6F4: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x800EF6F8: sw          $v0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r2;
    // 0x800EF6FC: lw          $v0, 0xC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XC);
    // 0x800EF700: sw          $v0, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r2;
    // 0x800EF704: lhu         $v0, 0x22($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X22);
    // 0x800EF708: sh          $v0, 0x20($a0)
    MEM_H(0X20, ctx->r4) = ctx->r2;
    // 0x800EF70C: lhu         $v0, 0x24($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X24);
    // 0x800EF710: sh          $v0, 0x22($a0)
    MEM_H(0X22, ctx->r4) = ctx->r2;
    // 0x800EF714: lhu         $v0, 0x26($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X26);
    // 0x800EF718: sh          $v0, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r2;
    // 0x800EF71C: lbu         $v0, 0x30($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X30);
    // 0x800EF720: sb          $v0, 0x26($a0)
    MEM_B(0X26, ctx->r4) = ctx->r2;
    // 0x800EF724: lbu         $v0, 0x33($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X33);
    // 0x800EF728: sb          $v0, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r2;
    // 0x800EF72C: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x800EF730: sb          $v0, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r2;
    // 0x800EF734: lbu         $v0, 0x35($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X35);
    // 0x800EF738: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800EF73C: sb          $v0, 0x2B($a0)
    MEM_B(0X2B, ctx->r4) = ctx->r2;
    // 0x800EF740: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
    // 0x800EF744: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800EF748: sw          $v1, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r3;
    // 0x800EF74C: lbu         $a2, 0x31($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X31);
    // 0x800EF750: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800EF754: sb          $v1, -0x3D9E($a1)
    MEM_B(-0X3D9E, ctx->r5) = ctx->r3;
    // 0x800EF758: sb          $a2, 0x27($a0)
    MEM_B(0X27, ctx->r4) = ctx->r6;
L_800EF75C:
    // 0x800EF75C: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800EF760: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800EF764: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800EF768: jr          $ra
    // 0x800EF76C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800EF76C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800EF770(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EF770: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EF774: lw          $v0, -0x35E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X35E0);
    // 0x800EF778: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EF77C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800EF780: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x800EF784: bne         $v0, $zero, L_800EF94C
    if (ctx->r2 != 0) {
        // 0x800EF788: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800EF94C;
    }
    // 0x800EF788: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EF78C: jal         0x80047B48
    // 0x800EF790: nop

    getLevelDatItemByName(rdram, ctx);
        goto after_0;
    // 0x800EF790: nop

    after_0:
    // 0x800EF794: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x800EF798: beq         $a3, $zero, L_800EF94C
    if (ctx->r7 == 0) {
        // 0x800EF79C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800EF94C;
    }
    // 0x800EF79C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EF7A0: beq         $s0, $v0, L_800EF7E4
    if (ctx->r16 == ctx->r2) {
        // 0x800EF7A4: slti        $v0, $s0, 0x2
        ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
            goto L_800EF7E4;
    }
    // 0x800EF7A4: slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x800EF7A8: beql        $v0, $zero, L_800EF7C0
    if (ctx->r2 == 0) {
        // 0x800EF7AC: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800EF7C0;
    }
    goto skip_0;
    // 0x800EF7AC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x800EF7B0: beq         $s0, $zero, L_800EF7D8
    if (ctx->r16 == 0) {
        // 0x800EF7B4: nop
    
            goto L_800EF7D8;
    }
    // 0x800EF7B4: nop

    // 0x800EF7B8: j           L_800EF94C
    // 0x800EF7BC: nop

        goto L_800EF94C;
    // 0x800EF7BC: nop

L_800EF7C0:
    // 0x800EF7C0: beq         $s0, $v0, L_800EF7F0
    if (ctx->r16 == ctx->r2) {
        // 0x800EF7C4: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_800EF7F0;
    }
    // 0x800EF7C4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800EF7C8: beq         $s0, $v0, L_800EF7FC
    if (ctx->r16 == ctx->r2) {
        // 0x800EF7CC: nop
    
            goto L_800EF7FC;
    }
    // 0x800EF7CC: nop

    // 0x800EF7D0: j           L_800EF94C
    // 0x800EF7D4: nop

        goto L_800EF94C;
    // 0x800EF7D4: nop

L_800EF7D8:
    // 0x800EF7D8: lw          $v1, 0x3C($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X3C);
    // 0x800EF7DC: j           L_800EF804
    // 0x800EF7E0: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
        goto L_800EF804;
    // 0x800EF7E0: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
L_800EF7E4:
    // 0x800EF7E4: lw          $v1, 0x40($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X40);
    // 0x800EF7E8: j           L_800EF804
    // 0x800EF7EC: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
        goto L_800EF804;
    // 0x800EF7EC: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
L_800EF7F0:
    // 0x800EF7F0: lw          $v1, 0x44($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X44);
    // 0x800EF7F4: j           L_800EF804
    // 0x800EF7F8: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
        goto L_800EF804;
    // 0x800EF7F8: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
L_800EF7FC:
    // 0x800EF7FC: lw          $v1, 0x48($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X48);
    // 0x800EF800: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
L_800EF804:
    // 0x800EF804: bltz        $v1, L_800EF94C
    if (SIGNED(ctx->r3) < 0) {
        // 0x800EF808: lui         $a0, 0x8011
        ctx->r4 = S32(0X8011 << 16);
            goto L_800EF94C;
    }
    // 0x800EF808: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800EF80C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800EF810: sw          $v0, -0x3E30($a0)
    MEM_W(-0X3E30, ctx->r4) = ctx->r2;
    // 0x800EF814: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EF818: addiu       $t1, $v0, -0x4E40
    ctx->r9 = ADD32(ctx->r2, -0X4E40);
    // 0x800EF81C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800EF820: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800EF824: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800EF828: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x800EF82C: addiu       $a0, $a0, -0x3E30
    ctx->r4 = ADD32(ctx->r4, -0X3E30);
    // 0x800EF830: lhu         $t0, 0x0($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X0);
    // 0x800EF834: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800EF838: sh          $t0, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r8;
    // 0x800EF83C: lhu         $a2, 0x2($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X2);
    // 0x800EF840: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800EF844: sb          $v1, -0x3D97($a1)
    MEM_B(-0X3D97, ctx->r5) = ctx->r3;
    // 0x800EF848: sh          $a2, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r6;
    // 0x800EF84C: lbu         $v0, 0x4($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4);
    // 0x800EF850: sb          $v0, 0x8($a0)
    MEM_B(0X8, ctx->r4) = ctx->r2;
    // 0x800EF854: lhu         $v0, 0x2($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X2);
    // 0x800EF858: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x800EF85C: beq         $v0, $a2, L_800EF888
    if (ctx->r2 == ctx->r6) {
        // 0x800EF860: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_800EF888;
    }
    // 0x800EF860: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800EF864: andi        $a1, $t0, 0xFFFF
    ctx->r5 = ctx->r8 & 0XFFFF;
    // 0x800EF868: addu        $a0, $t1, $zero
    ctx->r4 = ADD32(ctx->r9, 0);
L_800EF86C:
    // 0x800EF86C: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x800EF870: beq         $v0, $a1, L_800EF88C
    if (ctx->r2 == ctx->r5) {
        // 0x800EF874: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800EF88C;
    }
    // 0x800EF874: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EF878: addiu       $a0, $a0, 0x6
    ctx->r4 = ADD32(ctx->r4, 0X6);
    // 0x800EF87C: lhu         $v0, 0x2($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X2);
    // 0x800EF880: bne         $v0, $a2, L_800EF86C
    if (ctx->r2 != ctx->r6) {
        // 0x800EF884: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800EF86C;
    }
    // 0x800EF884: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800EF888:
    // 0x800EF888: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_800EF88C:
    // 0x800EF88C: addiu       $v0, $v0, -0x3E30
    ctx->r2 = ADD32(ctx->r2, -0X3E30);
    // 0x800EF890: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800EF894: sh          $v1, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r3;
    // 0x800EF898: sb          $zero, 0xC($v0)
    MEM_B(0XC, ctx->r2) = 0;
    // 0x800EF89C: sb          $zero, 0xD($v0)
    MEM_B(0XD, ctx->r2) = 0;
    // 0x800EF8A0: sb          $zero, 0xE($v0)
    MEM_B(0XE, ctx->r2) = 0;
    // 0x800EF8A4: sb          $zero, 0xF($v0)
    MEM_B(0XF, ctx->r2) = 0;
    // 0x800EF8A8: lwc1        $f2, 0x54($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X54);
    // 0x800EF8AC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EF8B0: lwc1        $f0, -0x76BC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X76BC);
    // 0x800EF8B4: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800EF8B8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EF8BC: lwc1        $f2, -0x76B8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X76B8);
    // 0x800EF8C0: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800EF8C4: nop

    // 0x800EF8C8: bc1t        L_800EF8E0
    if (c1cs) {
        // 0x800EF8CC: addu        $a0, $v0, $zero
        ctx->r4 = ADD32(ctx->r2, 0);
            goto L_800EF8E0;
    }
    // 0x800EF8CC: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800EF8D0: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800EF8D4: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x800EF8D8: j           L_800EF8F8
    // 0x800EF8DC: sh          $v1, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r3;
        goto L_800EF8F8;
    // 0x800EF8DC: sh          $v1, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r3;
L_800EF8E0:
    // 0x800EF8E0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800EF8E4: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800EF8E8: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800EF8EC: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x800EF8F0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800EF8F4: sh          $v1, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r3;
L_800EF8F8:
    // 0x800EF8F8: lwc1        $f0, 0x50($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X50);
    // 0x800EF8FC: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EF900: lwc1        $f2, -0x76B4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X76B4);
    // 0x800EF904: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800EF908: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EF90C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EF910: lwc1        $f2, -0x76B0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X76B0);
    // 0x800EF914: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800EF918: nop

    // 0x800EF91C: bc1t        L_800EF934
    if (c1cs) {
        // 0x800EF920: addiu       $a0, $v0, -0x3E30
        ctx->r4 = ADD32(ctx->r2, -0X3E30);
            goto L_800EF934;
    }
    // 0x800EF920: addiu       $a0, $v0, -0x3E30
    ctx->r4 = ADD32(ctx->r2, -0X3E30);
    // 0x800EF924: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800EF928: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x800EF92C: j           L_800EF94C
    // 0x800EF930: sh          $v1, 0x12($a0)
    MEM_H(0X12, ctx->r4) = ctx->r3;
        goto L_800EF94C;
    // 0x800EF930: sh          $v1, 0x12($a0)
    MEM_H(0X12, ctx->r4) = ctx->r3;
L_800EF934:
    // 0x800EF934: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800EF938: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800EF93C: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800EF940: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x800EF944: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800EF948: sh          $v1, 0x12($a0)
    MEM_H(0X12, ctx->r4) = ctx->r3;
L_800EF94C:
    // 0x800EF94C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EF950: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800EF954: jr          $ra
    // 0x800EF958: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800EF958: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800EF95C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EF95C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EF960: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800EF964: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EF968: jal         0x80047B48
    // 0x800EF96C: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    getLevelDatItemByName(rdram, ctx);
        goto after_0;
    // 0x800EF96C: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    after_0:
    // 0x800EF970: addu        $a3, $v0, $zero
    ctx->r7 = ADD32(ctx->r2, 0);
    // 0x800EF974: beq         $a3, $zero, L_800EFB30
    if (ctx->r7 == 0) {
        // 0x800EF978: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800EFB30;
    }
    // 0x800EF978: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EF97C: beq         $s0, $v0, L_800EF9C0
    if (ctx->r16 == ctx->r2) {
        // 0x800EF980: slti        $v0, $s0, 0x2
        ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
            goto L_800EF9C0;
    }
    // 0x800EF980: slti        $v0, $s0, 0x2
    ctx->r2 = SIGNED(ctx->r16) < 0X2 ? 1 : 0;
    // 0x800EF984: beql        $v0, $zero, L_800EF99C
    if (ctx->r2 == 0) {
        // 0x800EF988: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800EF99C;
    }
    goto skip_0;
    // 0x800EF988: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    skip_0:
    // 0x800EF98C: beq         $s0, $zero, L_800EF9B4
    if (ctx->r16 == 0) {
        // 0x800EF990: nop
    
            goto L_800EF9B4;
    }
    // 0x800EF990: nop

    // 0x800EF994: j           L_800EFB30
    // 0x800EF998: nop

        goto L_800EFB30;
    // 0x800EF998: nop

L_800EF99C:
    // 0x800EF99C: beq         $s0, $v0, L_800EF9CC
    if (ctx->r16 == ctx->r2) {
        // 0x800EF9A0: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_800EF9CC;
    }
    // 0x800EF9A0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800EF9A4: beq         $s0, $v0, L_800EF9D8
    if (ctx->r16 == ctx->r2) {
        // 0x800EF9A8: nop
    
            goto L_800EF9D8;
    }
    // 0x800EF9A8: nop

    // 0x800EF9AC: j           L_800EFB30
    // 0x800EF9B0: nop

        goto L_800EFB30;
    // 0x800EF9B0: nop

L_800EF9B4:
    // 0x800EF9B4: lw          $v1, 0x3C($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X3C);
    // 0x800EF9B8: j           L_800EF9E0
    // 0x800EF9BC: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
        goto L_800EF9E0;
    // 0x800EF9BC: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
L_800EF9C0:
    // 0x800EF9C0: lw          $v1, 0x40($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X40);
    // 0x800EF9C4: j           L_800EF9E0
    // 0x800EF9C8: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
        goto L_800EF9E0;
    // 0x800EF9C8: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
L_800EF9CC:
    // 0x800EF9CC: lw          $v1, 0x44($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X44);
    // 0x800EF9D0: j           L_800EF9E0
    // 0x800EF9D4: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
        goto L_800EF9E0;
    // 0x800EF9D4: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
L_800EF9D8:
    // 0x800EF9D8: lw          $v1, 0x48($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X48);
    // 0x800EF9DC: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
L_800EF9E0:
    // 0x800EF9E0: bltz        $v1, L_800EFB30
    if (SIGNED(ctx->r3) < 0) {
        // 0x800EF9E4: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_800EFB30;
    }
    // 0x800EF9E4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800EF9E8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800EF9EC: sw          $v0, -0x3E30($a0)
    MEM_W(-0X3E30, ctx->r4) = ctx->r2;
    // 0x800EF9F0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EF9F4: addiu       $t1, $v0, -0x4E40
    ctx->r9 = ADD32(ctx->r2, -0X4E40);
    // 0x800EF9F8: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800EF9FC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800EFA00: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800EFA04: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x800EFA08: addiu       $a0, $a0, -0x3E30
    ctx->r4 = ADD32(ctx->r4, -0X3E30);
    // 0x800EFA0C: lhu         $t0, 0x0($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X0);
    // 0x800EFA10: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800EFA14: sh          $t0, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r8;
    // 0x800EFA18: lhu         $a2, 0x2($v0)
    ctx->r6 = MEM_HU(ctx->r2, 0X2);
    // 0x800EFA1C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800EFA20: sb          $v1, -0x3D97($a1)
    MEM_B(-0X3D97, ctx->r5) = ctx->r3;
    // 0x800EFA24: sh          $a2, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r6;
    // 0x800EFA28: lbu         $v0, 0x4($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4);
    // 0x800EFA2C: sb          $v0, 0x8($a0)
    MEM_B(0X8, ctx->r4) = ctx->r2;
    // 0x800EFA30: lhu         $v0, 0x2($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X2);
    // 0x800EFA34: andi        $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 & 0XFFFF;
    // 0x800EFA38: beq         $v0, $a2, L_800EFA64
    if (ctx->r2 == ctx->r6) {
        // 0x800EFA3C: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_800EFA64;
    }
    // 0x800EFA3C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800EFA40: andi        $a1, $t0, 0xFFFF
    ctx->r5 = ctx->r8 & 0XFFFF;
    // 0x800EFA44: addu        $a0, $t1, $zero
    ctx->r4 = ADD32(ctx->r9, 0);
L_800EFA48:
    // 0x800EFA48: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x800EFA4C: beq         $v0, $a1, L_800EFA68
    if (ctx->r2 == ctx->r5) {
        // 0x800EFA50: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_800EFA68;
    }
    // 0x800EFA50: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EFA54: addiu       $a0, $a0, 0x6
    ctx->r4 = ADD32(ctx->r4, 0X6);
    // 0x800EFA58: lhu         $v0, 0x2($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X2);
    // 0x800EFA5C: bne         $v0, $a2, L_800EFA48
    if (ctx->r2 != ctx->r6) {
        // 0x800EFA60: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800EFA48;
    }
    // 0x800EFA60: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800EFA64:
    // 0x800EFA64: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_800EFA68:
    // 0x800EFA68: addiu       $v0, $v0, -0x3E30
    ctx->r2 = ADD32(ctx->r2, -0X3E30);
    // 0x800EFA6C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800EFA70: sh          $v1, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r3;
    // 0x800EFA74: sb          $zero, 0xC($v0)
    MEM_B(0XC, ctx->r2) = 0;
    // 0x800EFA78: sb          $zero, 0xD($v0)
    MEM_B(0XD, ctx->r2) = 0;
    // 0x800EFA7C: sb          $zero, 0xE($v0)
    MEM_B(0XE, ctx->r2) = 0;
    // 0x800EFA80: sb          $zero, 0xF($v0)
    MEM_B(0XF, ctx->r2) = 0;
    // 0x800EFA84: lwc1        $f2, 0x54($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X54);
    // 0x800EFA88: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EFA8C: lwc1        $f0, -0x76AC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X76AC);
    // 0x800EFA90: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800EFA94: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EFA98: lwc1        $f2, -0x76A8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X76A8);
    // 0x800EFA9C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800EFAA0: nop

    // 0x800EFAA4: bc1t        L_800EFABC
    if (c1cs) {
        // 0x800EFAA8: addu        $a0, $v0, $zero
        ctx->r4 = ADD32(ctx->r2, 0);
            goto L_800EFABC;
    }
    // 0x800EFAA8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800EFAAC: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800EFAB0: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x800EFAB4: j           L_800EFAD4
    // 0x800EFAB8: sh          $v1, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r3;
        goto L_800EFAD4;
    // 0x800EFAB8: sh          $v1, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r3;
L_800EFABC:
    // 0x800EFABC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800EFAC0: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800EFAC4: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800EFAC8: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x800EFACC: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800EFAD0: sh          $v1, 0x10($a0)
    MEM_H(0X10, ctx->r4) = ctx->r3;
L_800EFAD4:
    // 0x800EFAD4: lwc1        $f0, 0x50($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X50);
    // 0x800EFAD8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EFADC: lwc1        $f2, -0x76A4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X76A4);
    // 0x800EFAE0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800EFAE4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EFAE8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x800EFAEC: lwc1        $f2, -0x76A0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X76A0);
    // 0x800EFAF0: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x800EFAF4: nop

    // 0x800EFAF8: bc1t        L_800EFB10
    if (c1cs) {
        // 0x800EFAFC: addiu       $a0, $v0, -0x3E30
        ctx->r4 = ADD32(ctx->r2, -0X3E30);
            goto L_800EFB10;
    }
    // 0x800EFAFC: addiu       $a0, $v0, -0x3E30
    ctx->r4 = ADD32(ctx->r2, -0X3E30);
    // 0x800EFB00: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800EFB04: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x800EFB08: j           L_800EFB28
    // 0x800EFB0C: sh          $v1, 0x12($a0)
    MEM_H(0X12, ctx->r4) = ctx->r3;
        goto L_800EFB28;
    // 0x800EFB0C: sh          $v1, 0x12($a0)
    MEM_H(0X12, ctx->r4) = ctx->r3;
L_800EFB10:
    // 0x800EFB10: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800EFB14: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x800EFB18: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800EFB1C: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x800EFB20: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x800EFB24: sh          $v1, 0x12($a0)
    MEM_H(0X12, ctx->r4) = ctx->r3;
L_800EFB28:
    // 0x800EFB28: jal         0x800EDD8C
    // 0x800EFB2C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800EDD8C(rdram, ctx);
        goto after_1;
    // 0x800EFB2C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
L_800EFB30:
    // 0x800EFB30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EFB34: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800EFB38: jr          $ra
    // 0x800EFB3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800EFB3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800EFB40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EFB40: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EFB44: lbu         $v0, -0x3DA0($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X3DA0);
    // 0x800EFB48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EFB4C: beq         $v0, $zero, L_800EFB64
    if (ctx->r2 == 0) {
        // 0x800EFB50: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_800EFB64;
    }
    // 0x800EFB50: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800EFB54: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EFB58: lw          $a0, -0x3EC0($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X3EC0);
    // 0x800EFB5C: jal         0x80095D58
    // 0x800EFB60: nop

    func_80095D58(rdram, ctx);
        goto after_0;
    // 0x800EFB60: nop

    after_0:
L_800EFB64:
    // 0x800EFB64: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EFB68: lw          $a0, -0x3F20($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X3F20);
    // 0x800EFB6C: jal         0x80095D58
    // 0x800EFB70: nop

    func_80095D58(rdram, ctx);
        goto after_1;
    // 0x800EFB70: nop

    after_1:
    // 0x800EFB74: jal         0x80066960
    // 0x800EFB78: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    func_80066960(rdram, ctx);
        goto after_2;
    // 0x800EFB78: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_2:
    // 0x800EFB7C: jal         0x800EEF34
    // 0x800EFB80: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800EEF34(rdram, ctx);
        goto after_3;
    // 0x800EFB80: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x800EFB84: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800EFB88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EFB8C: jr          $ra
    // 0x800EFB90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800EFB90: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800EFB94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EFB94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EFB98: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800EFB9C: jal         0x800EEA54
    // 0x800EFBA0: nop

    func_800EEA54(rdram, ctx);
        goto after_0;
    // 0x800EFBA0: nop

    after_0:
    // 0x800EFBA4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800EFBA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EFBAC: jr          $ra
    // 0x800EFBB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800EFBB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800EFBB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EFBB4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EFBB8: lbu         $v0, -0x3BDC($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X3BDC);
    // 0x800EFBBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EFBC0: bne         $v0, $zero, L_800EFBD0
    if (ctx->r2 != 0) {
        // 0x800EFBC4: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_800EFBD0;
    }
    // 0x800EFBC4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800EFBC8: j           L_800EFC78
    // 0x800EFBCC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_800EFC78;
    // 0x800EFBCC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800EFBD0:
    // 0x800EFBD0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EFBD4: addiu       $v1, $v0, -0x3EC0
    ctx->r3 = ADD32(ctx->r2, -0X3EC0);
    // 0x800EFBD8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EFBDC: addiu       $v0, $v0, -0x3E60
    ctx->r2 = ADD32(ctx->r2, -0X3E60);
    // 0x800EFBE0: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
L_800EFBE4:
    // 0x800EFBE4: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x800EFBE8: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x800EFBEC: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x800EFBF0: lw          $t0, 0xC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XC);
    // 0x800EFBF4: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800EFBF8: sw          $a2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r6;
    // 0x800EFBFC: sw          $a3, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r7;
    // 0x800EFC00: sw          $t0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r8;
    // 0x800EFC04: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800EFC08: bne         $v0, $a0, L_800EFBE4
    if (ctx->r2 != ctx->r4) {
        // 0x800EFC0C: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800EFBE4;
    }
    // 0x800EFC0C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800EFC10: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x800EFC14: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800EFC18: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EFC1C: addiu       $v1, $v0, -0x3C00
    ctx->r3 = ADD32(ctx->r2, -0X3C00);
    // 0x800EFC20: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EFC24: addiu       $v0, $v0, -0x3E60
    ctx->r2 = ADD32(ctx->r2, -0X3E60);
    // 0x800EFC28: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
L_800EFC2C:
    // 0x800EFC2C: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x800EFC30: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x800EFC34: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x800EFC38: lw          $t0, 0xC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XC);
    // 0x800EFC3C: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    // 0x800EFC40: sw          $a2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r6;
    // 0x800EFC44: sw          $a3, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r7;
    // 0x800EFC48: sw          $t0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r8;
    // 0x800EFC4C: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x800EFC50: bne         $v0, $a0, L_800EFC2C
    if (ctx->r2 != ctx->r4) {
        // 0x800EFC54: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800EFC2C;
    }
    // 0x800EFC54: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800EFC58: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x800EFC5C: jal         0x800ED200
    // 0x800EFC60: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    func_800ED200(rdram, ctx);
        goto after_0;
    // 0x800EFC60: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
    after_0:
    // 0x800EFC64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EFC68: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800EFC6C: lw          $a0, -0x3F20($v1)
    ctx->r4 = MEM_W(ctx->r3, -0X3F20);
    // 0x800EFC70: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800EFC74: sw          $a0, -0x3E60($v1)
    MEM_W(-0X3E60, ctx->r3) = ctx->r4;
L_800EFC78:
    // 0x800EFC78: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800EFC7C: jr          $ra
    // 0x800EFC80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800EFC80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800EFC84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EFC84: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EFC88: addiu       $v0, $v0, -0x3E00
    ctx->r2 = ADD32(ctx->r2, -0X3E00);
    // 0x800EFC8C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800EFC90: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
    // 0x800EFC94: sb          $v1, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r3;
    // 0x800EFC98: addiu       $v1, $zero, 0x64
    ctx->r3 = ADD32(0, 0X64);
    // 0x800EFC9C: sh          $a2, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r6;
    // 0x800EFCA0: sh          $a0, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r4;
    // 0x800EFCA4: sh          $a1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r5;
    // 0x800EFCA8: sb          $zero, 0xF($v0)
    MEM_B(0XF, ctx->r2) = 0;
    // 0x800EFCAC: sh          $v1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r3;
    // 0x800EFCB0: sh          $v1, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r3;
    // 0x800EFCB4: sb          $zero, 0xC($v0)
    MEM_B(0XC, ctx->r2) = 0;
    // 0x800EFCB8: sb          $zero, 0xD($v0)
    MEM_B(0XD, ctx->r2) = 0;
    // 0x800EFCBC: sb          $zero, 0xE($v0)
    MEM_B(0XE, ctx->r2) = 0;
    // 0x800EFCC0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EFCC4: sb          $a2, -0x3D98($v0)
    MEM_B(-0X3D98, ctx->r2) = ctx->r6;
    // 0x800EFCC8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EFCCC: jr          $ra
    // 0x800EFCD0: sb          $a2, -0x3D9E($v0)
    MEM_B(-0X3D9E, ctx->r2) = ctx->r6;
    return;
    // 0x800EFCD0: sb          $a2, -0x3D9E($v0)
    MEM_B(-0X3D9E, ctx->r2) = ctx->r6;
;}
RECOMP_FUNC void func_800EFCD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EFCD4: sltiu       $v0, $a0, 0x8
    ctx->r2 = ctx->r4 < 0X8 ? 1 : 0;
    // 0x800EFCD8: beq         $v0, $zero, L_800EFD4C
    if (ctx->r2 == 0) {
        // 0x800EFCDC: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_800EFD4C;
    }
    // 0x800EFCDC: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800EFCE0: bne         $a0, $v0, L_800EFCEC
    if (ctx->r4 != ctx->r2) {
        // 0x800EFCE4: addiu       $a2, $zero, 0x1D
        ctx->r6 = ADD32(0, 0X1D);
            goto L_800EFCEC;
    }
    // 0x800EFCE4: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    // 0x800EFCE8: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
L_800EFCEC:
    // 0x800EFCEC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EFCF0: addiu       $v0, $v0, -0x4CFC
    ctx->r2 = ADD32(ctx->r2, -0X4CFC);
    // 0x800EFCF4: sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4 << 1);
    // 0x800EFCF8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800EFCFC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EFD00: addiu       $v0, $v0, -0x3E00
    ctx->r2 = ADD32(ctx->r2, -0X3E00);
    // 0x800EFD04: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800EFD08: lhu         $a1, 0x0($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X0);
    // 0x800EFD0C: addiu       $v1, $zero, 0x7F
    ctx->r3 = ADD32(0, 0X7F);
    // 0x800EFD10: sb          $v1, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r3;
    // 0x800EFD14: addiu       $v1, $zero, 0x64
    ctx->r3 = ADD32(0, 0X64);
    // 0x800EFD18: sh          $v1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r3;
    // 0x800EFD1C: sh          $v1, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r3;
    // 0x800EFD20: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800EFD24: sb          $zero, 0xF($v0)
    MEM_B(0XF, ctx->r2) = 0;
    // 0x800EFD28: sb          $zero, 0xC($v0)
    MEM_B(0XC, ctx->r2) = 0;
    // 0x800EFD2C: sb          $zero, 0xD($v0)
    MEM_B(0XD, ctx->r2) = 0;
    // 0x800EFD30: sb          $zero, 0xE($v0)
    MEM_B(0XE, ctx->r2) = 0;
    // 0x800EFD34: sb          $a0, -0x3D98($v1)
    MEM_B(-0X3D98, ctx->r3) = ctx->r4;
    // 0x800EFD38: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800EFD3C: sh          $a0, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r4;
    // 0x800EFD40: sh          $a2, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r6;
    // 0x800EFD44: sb          $a0, -0x3D9E($v1)
    MEM_B(-0X3D9E, ctx->r3) = ctx->r4;
    // 0x800EFD48: sh          $a1, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r5;
L_800EFD4C:
    // 0x800EFD4C: jr          $ra
    // 0x800EFD50: nop

    return;
    // 0x800EFD50: nop

;}
RECOMP_FUNC void func_800EFD54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EFD54: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800EFD58: lbu         $v0, -0x3F18($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X3F18);
    // 0x800EFD5C: jr          $ra
    // 0x800EFD60: nop

    return;
    // 0x800EFD60: nop

;}
RECOMP_FUNC void func_800EFD64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EFD64: jr          $ra
    // 0x800EFD68: nop

    return;
    // 0x800EFD68: nop

;}
RECOMP_FUNC void func_800EFD6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EFD6C: jr          $ra
    // 0x800EFD70: nop

    return;
    // 0x800EFD70: nop

;}
RECOMP_FUNC void fake_func_800EFD74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_800EFD80(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EFD80: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800EFD84: addu        $a0, $a1, $zero
    ctx->r4 = ADD32(ctx->r5, 0);
    // 0x800EFD88: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800EFD8C: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x800EFD90: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EFD94: bnel        $v1, $v0, L_800EFDD0
    if (ctx->r3 != ctx->r2) {
        // 0x800EFD98: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800EFDD0;
    }
    goto skip_0;
    // 0x800EFD98: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    skip_0:
    // 0x800EFD9C: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x800EFDA0: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800EFDA4: sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // 0x800EFDA8: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x800EFDAC: sh          $v0, 0x14($sp)
    MEM_H(0X14, ctx->r29) = ctx->r2;
    // 0x800EFDB0: lhu         $v0, 0x0($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X0);
    // 0x800EFDB4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x800EFDB8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800EFDBC: sh          $v0, 0x16($sp)
    MEM_H(0X16, ctx->r29) = ctx->r2;
    // 0x800EFDC0: lhu         $a0, 0x2($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X2);
    // 0x800EFDC4: jal         0x8003E8DC
    // 0x800EFDC8: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    func_8003E8DC(rdram, ctx);
        goto after_0;
    // 0x800EFDC8: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_0:
    // 0x800EFDCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EFDD0:
    // 0x800EFDD0: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x800EFDD4: jr          $ra
    // 0x800EFDD8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800EFDD8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void fake_func_800EFDDC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
