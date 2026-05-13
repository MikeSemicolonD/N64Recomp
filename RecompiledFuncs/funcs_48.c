#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void lvc_checkComplexObjectives(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106D3C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80106D40: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80106D44: mov.s       $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    ctx->f22.fl = ctx->f12.fl;
    // 0x80106D48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80106D4C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80106D50: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80106D54: jal         0x800C759C
    // 0x80106D58: addiu       $a0, $zero, 0x51
    ctx->r4 = ADD32(0, 0X51);
    getObjectiveBoolean(rdram, ctx);
        goto after_0;
    // 0x80106D58: addiu       $a0, $zero, 0x51
    ctx->r4 = ADD32(0, 0X51);
    after_0:
    // 0x80106D5C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80106D60: bne         $v0, $s0, L_80106D8C
    if (ctx->r2 != ctx->r16) {
        // 0x80106D64: nop
    
            goto L_80106D8C;
    }
    // 0x80106D64: nop

    // 0x80106D68: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80106D6C: jal         0x800C7738
    // 0x80106D70: nop

    setHudEnableBit4(rdram, ctx);
        goto after_1;
    // 0x80106D70: nop

    after_1:
    // 0x80106D74: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80106D78: jal         0x800C7D1C
    // 0x80106D7C: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_2;
    // 0x80106D7C: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    after_2:
    // 0x80106D80: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80106D84: jal         0x800C7D1C
    // 0x80106D88: addiu       $a0, $zero, 0x14B
    ctx->r4 = ADD32(0, 0X14B);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_3;
    // 0x80106D88: addiu       $a0, $zero, 0x14B
    ctx->r4 = ADD32(0, 0X14B);
    after_3:
L_80106D8C:
    // 0x80106D8C: jal         0x800C761C
    // 0x80106D90: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    getObjectiveCount(rdram, ctx);
        goto after_4;
    // 0x80106D90: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_4:
    // 0x80106D94: slti        $v0, $v0, 0x7
    ctx->r2 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x80106D98: bne         $v0, $zero, L_80106DC4
    if (ctx->r2 != 0) {
        // 0x80106D9C: nop
    
            goto L_80106DC4;
    }
    // 0x80106D9C: nop

    // 0x80106DA0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80106DA4: jal         0x800C7738
    // 0x80106DA8: nop

    setHudEnableBit4(rdram, ctx);
        goto after_5;
    // 0x80106DA8: nop

    after_5:
    // 0x80106DAC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80106DB0: jal         0x800C7D1C
    // 0x80106DB4: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_6;
    // 0x80106DB4: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    after_6:
    // 0x80106DB8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80106DBC: jal         0x800C7D1C
    // 0x80106DC0: addiu       $a0, $zero, 0x14B
    ctx->r4 = ADD32(0, 0X14B);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_7;
    // 0x80106DC0: addiu       $a0, $zero, 0x14B
    ctx->r4 = ADD32(0, 0X14B);
    after_7:
L_80106DC4:
    // 0x80106DC4: jal         0x800C761C
    // 0x80106DC8: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    getObjectiveCount(rdram, ctx);
        goto after_8;
    // 0x80106DC8: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_8:
    // 0x80106DCC: slti        $v0, $v0, 0x3
    ctx->r2 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80106DD0: bne         $v0, $zero, L_80106DFC
    if (ctx->r2 != 0) {
        // 0x80106DD4: nop
    
            goto L_80106DFC;
    }
    // 0x80106DD4: nop

    // 0x80106DD8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80106DDC: jal         0x800C7738
    // 0x80106DE0: nop

    setHudEnableBit4(rdram, ctx);
        goto after_9;
    // 0x80106DE0: nop

    after_9:
    // 0x80106DE4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80106DE8: jal         0x800C7D1C
    // 0x80106DEC: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_10;
    // 0x80106DEC: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    after_10:
    // 0x80106DF0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80106DF4: jal         0x800C7D1C
    // 0x80106DF8: addiu       $a0, $zero, 0x14B
    ctx->r4 = ADD32(0, 0X14B);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_11;
    // 0x80106DF8: addiu       $a0, $zero, 0x14B
    ctx->r4 = ADD32(0, 0X14B);
    after_11:
L_80106DFC:
    // 0x80106DFC: jal         0x800C761C
    // 0x80106E00: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    getObjectiveCount(rdram, ctx);
        goto after_12;
    // 0x80106E00: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_12:
    // 0x80106E04: slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80106E08: bne         $v0, $zero, L_80106E24
    if (ctx->r2 != 0) {
        // 0x80106E0C: nop
    
            goto L_80106E24;
    }
    // 0x80106E0C: nop

    // 0x80106E10: jal         0x800C7738
    // 0x80106E14: nop

    setHudEnableBit4(rdram, ctx);
        goto after_13;
    // 0x80106E14: nop

    after_13:
    // 0x80106E18: addiu       $a0, $zero, 0x1D0
    ctx->r4 = ADD32(0, 0X1D0);
    // 0x80106E1C: jal         0x800C7D1C
    // 0x80106E20: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_14;
    // 0x80106E20: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_14:
L_80106E24:
    // 0x80106E24: jal         0x800C761C
    // 0x80106E28: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    getObjectiveCount(rdram, ctx);
        goto after_15;
    // 0x80106E28: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_15:
    // 0x80106E2C: blez        $v0, L_80106E64
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80106E30: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_80106E64;
    }
    // 0x80106E30: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80106E34: jal         0x800C761C
    // 0x80106E38: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    getObjectiveCount(rdram, ctx);
        goto after_16;
    // 0x80106E38: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_16:
    // 0x80106E3C: slti        $v0, $v0, 0x3
    ctx->r2 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80106E40: bne         $v0, $zero, L_80106E64
    if (ctx->r2 != 0) {
        // 0x80106E44: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_80106E64;
    }
    // 0x80106E44: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80106E48: jal         0x800C759C
    // 0x80106E4C: addiu       $a0, $zero, 0x61
    ctx->r4 = ADD32(0, 0X61);
    getObjectiveBoolean(rdram, ctx);
        goto after_17;
    // 0x80106E4C: addiu       $a0, $zero, 0x61
    ctx->r4 = ADD32(0, 0X61);
    after_17:
    // 0x80106E50: bne         $v0, $s0, L_80106E64
    if (ctx->r2 != ctx->r16) {
        // 0x80106E54: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_80106E64;
    }
    // 0x80106E54: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80106E58: jal         0x800C776C
    // 0x80106E5C: nop

    setHudEnableBit8(rdram, ctx);
        goto after_18;
    // 0x80106E5C: nop

    after_18:
    // 0x80106E60: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_80106E64:
    // 0x80106E64: lw          $v0, -0x2EB8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2EB8);
    // 0x80106E68: beq         $v0, $zero, L_80106E78
    if (ctx->r2 == 0) {
        // 0x80106E6C: nop
    
            goto L_80106E78;
    }
    // 0x80106E6C: nop

    // 0x80106E70: jal         0x80106E94
    // 0x80106E74: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    func_80106E94(rdram, ctx);
        goto after_19;
    // 0x80106E74: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_19:
L_80106E78:
    // 0x80106E78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80106E7C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80106E80: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80106E84: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80106E88: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80106E8C: jr          $ra
    // 0x80106E90: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80106E90: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80106E94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106E94: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80106E98: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80106E9C: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x80106EA0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80106EA4: jal         0x800C761C
    // 0x80106EA8: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    getObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x80106EA8: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    after_0:
    // 0x80106EAC: bne         $v0, $zero, L_80106EBC
    if (ctx->r2 != 0) {
        // 0x80106EB0: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_80106EBC;
    }
    // 0x80106EB0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80106EB4: j           L_80106EDC
    // 0x80106EB8: addiu       $a0, $a0, -0x66BC
    ctx->r4 = ADD32(ctx->r4, -0X66BC);
        goto L_80106EDC;
    // 0x80106EB8: addiu       $a0, $a0, -0x66BC
    ctx->r4 = ADD32(ctx->r4, -0X66BC);
L_80106EBC:
    // 0x80106EBC: jal         0x800C761C
    // 0x80106EC0: addiu       $a0, $zero, 0x79
    ctx->r4 = ADD32(0, 0X79);
    getObjectiveCount(rdram, ctx);
        goto after_1;
    // 0x80106EC0: addiu       $a0, $zero, 0x79
    ctx->r4 = ADD32(0, 0X79);
    after_1:
    // 0x80106EC4: bnel        $v0, $zero, L_80106ED8
    if (ctx->r2 != 0) {
        // 0x80106EC8: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_80106ED8;
    }
    goto skip_0;
    // 0x80106EC8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    skip_0:
    // 0x80106ECC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80106ED0: j           L_80106EDC
    // 0x80106ED4: addiu       $a0, $a0, -0x66AC
    ctx->r4 = ADD32(ctx->r4, -0X66AC);
        goto L_80106EDC;
    // 0x80106ED4: addiu       $a0, $a0, -0x66AC
    ctx->r4 = ADD32(ctx->r4, -0X66AC);
L_80106ED8:
    // 0x80106ED8: addiu       $a0, $a0, -0x66CC
    ctx->r4 = ADD32(ctx->r4, -0X66CC);
L_80106EDC:
    // 0x80106EDC: jal         0x800C78A0
    // 0x80106EE0: nop

    calculateDatItemDistanceToPlayer(rdram, ctx);
        goto after_2;
    // 0x80106EE0: nop

    after_2:
    // 0x80106EE4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80106EE8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80106EEC: lwc1        $f0, -0x669C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X669C);
    // 0x80106EF0: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80106EF4: nop

    // 0x80106EF8: bc1f        L_80106F34
    if (!c1cs) {
        // 0x80106EFC: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_80106F34;
    }
    // 0x80106EFC: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80106F00: lw          $v0, -0x2EBC($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X2EBC);
    // 0x80106F04: bne         $v0, $zero, L_80106F20
    if (ctx->r2 != 0) {
        // 0x80106F08: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80106F20;
    }
    // 0x80106F08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80106F0C: sw          $v0, -0x2EBC($v1)
    MEM_W(-0X2EBC, ctx->r3) = ctx->r2;
    // 0x80106F10: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80106F14: addiu       $a0, $a0, -0x6700
    ctx->r4 = ADD32(ctx->r4, -0X6700);
    // 0x80106F18: jal         0x800C7D60
    // 0x80106F1C: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    delegateToLevelStageTick(rdram, ctx);
        goto after_3;
    // 0x80106F1C: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    after_3:
L_80106F20:
    // 0x80106F20: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80106F24: lwc1        $f0, -0x6698($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6698);
    // 0x80106F28: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80106F2C: j           L_80106F70
    // 0x80106F30: swc1        $f0, -0x2EC0($v0)
    MEM_W(-0X2EC0, ctx->r2) = ctx->f0.u32l;
        goto L_80106F70;
    // 0x80106F30: swc1        $f0, -0x2EC0($v0)
    MEM_W(-0X2EC0, ctx->r2) = ctx->f0.u32l;
L_80106F34:
    // 0x80106F34: lw          $v0, -0x2EBC($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X2EBC);
    // 0x80106F38: beq         $v0, $zero, L_80106F70
    if (ctx->r2 == 0) {
        // 0x80106F3C: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_80106F70;
    }
    // 0x80106F3C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80106F40: lwc1        $f0, -0x2EC0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X2EC0);
    // 0x80106F44: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x80106F48: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80106F4C: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80106F50: nop

    // 0x80106F54: bc1f        L_80106F70
    if (!c1cs) {
        // 0x80106F58: swc1        $f0, -0x2EC0($v0)
        MEM_W(-0X2EC0, ctx->r2) = ctx->f0.u32l;
            goto L_80106F70;
    }
    // 0x80106F58: swc1        $f0, -0x2EC0($v0)
    MEM_W(-0X2EC0, ctx->r2) = ctx->f0.u32l;
    // 0x80106F5C: sw          $zero, -0x2EBC($v1)
    MEM_W(-0X2EBC, ctx->r3) = 0;
    // 0x80106F60: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80106F64: addiu       $a0, $a0, -0x6700
    ctx->r4 = ADD32(ctx->r4, -0X6700);
    // 0x80106F68: jal         0x800C7D60
    // 0x80106F6C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    delegateToLevelStageTick(rdram, ctx);
        goto after_4;
    // 0x80106F6C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_4:
L_80106F70:
    // 0x80106F70: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80106F74: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80106F78: jr          $ra
    // 0x80106F7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80106F7C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void runDialogueSeq_037_11A_0BF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106F80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80106F84: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80106F88: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80106F8C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80106F90: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80106F94: jal         0x800C7D1C
    // 0x80106F98: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80106F98: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    after_0:
    // 0x80106F9C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80106FA0: jal         0x800C7D1C
    // 0x80106FA4: addiu       $a0, $zero, 0x11A
    ctx->r4 = ADD32(0, 0X11A);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x80106FA4: addiu       $a0, $zero, 0x11A
    ctx->r4 = ADD32(0, 0X11A);
    after_1:
    // 0x80106FA8: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    // 0x80106FAC: jal         0x800C7D1C
    // 0x80106FB0: addiu       $a0, $zero, 0xBF
    ctx->r4 = ADD32(0, 0XBF);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_2;
    // 0x80106FB0: addiu       $a0, $zero, 0xBF
    ctx->r4 = ADD32(0, 0XBF);
    after_2:
    // 0x80106FB4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80106FB8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80106FBC: jr          $ra
    // 0x80106FC0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80106FC0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void playPairedDialogue_0x038_0x11A(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106FC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80106FC8: addiu       $a0, $zero, 0x38
    ctx->r4 = ADD32(0, 0X38);
    // 0x80106FCC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80106FD0: jal         0x800C7D1C
    // 0x80106FD4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80106FD4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x80106FD8: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80106FDC: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80106FE0: jal         0x800C7D1C
    // 0x80106FE4: addiu       $a0, $zero, 0x11A
    ctx->r4 = ADD32(0, 0X11A);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x80106FE4: addiu       $a0, $zero, 0x11A
    ctx->r4 = ADD32(0, 0X11A);
    after_1:
    // 0x80106FE8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80106FEC: jr          $ra
    // 0x80106FF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80106FF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv10_scheduleDialogueA(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106FF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80106FF8: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80106FFC: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    // 0x80107000: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80107004: jal         0x800C7864
    // 0x80107008: addiu       $a0, $a0, 0x7018
    ctx->r4 = ADD32(ctx->r4, 0X7018);
    addTimerHandleWrapper(rdram, ctx);
        goto after_0;
    // 0x80107008: addiu       $a0, $a0, 0x7018
    ctx->r4 = ADD32(ctx->r4, 0X7018);
    after_0:
    // 0x8010700C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80107010: jr          $ra
    // 0x80107014: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80107014: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv10_dialogueHudAndSoundA(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107018: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010701C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80107020: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80107024: jal         0x800C7884
    // 0x80107028: addiu       $a0, $a0, -0x670C
    ctx->r4 = ADD32(ctx->r4, -0X670C);
    setHudFlagBit40AndStoreArg(rdram, ctx);
        goto after_0;
    // 0x80107028: addiu       $a0, $a0, -0x670C
    ctx->r4 = ADD32(ctx->r4, -0X670C);
    after_0:
    // 0x8010702C: addiu       $a0, $zero, 0x1D1
    ctx->r4 = ADD32(0, 0X1D1);
    // 0x80107030: jal         0x800C7D1C
    // 0x80107034: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x80107034: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // 0x80107038: jal         0x800C7D98
    // 0x8010703C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    triggerSoundCueByType(rdram, ctx);
        goto after_2;
    // 0x8010703C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_2:
    // 0x80107040: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    // 0x80107044: jal         0x800C7540
    // 0x80107048: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_3;
    // 0x80107048: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8010704C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80107050: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80107054: addiu       $a0, $a0, -0x6700
    ctx->r4 = ADD32(ctx->r4, -0X6700);
    // 0x80107058: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8010705C: jal         0x800C7D60
    // 0x80107060: sw          $zero, -0x2EB8($v0)
    MEM_W(-0X2EB8, ctx->r2) = 0;
    delegateToLevelStageTick(rdram, ctx);
        goto after_4;
    // 0x80107060: sw          $zero, -0x2EB8($v0)
    MEM_W(-0X2EB8, ctx->r2) = 0;
    after_4:
    // 0x80107064: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80107068: jr          $ra
    // 0x8010706C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8010706C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv10_scheduleDialogueB(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107070: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80107074: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80107078: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    // 0x8010707C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80107080: jal         0x800C7864
    // 0x80107084: addiu       $a0, $a0, 0x7094
    ctx->r4 = ADD32(ctx->r4, 0X7094);
    addTimerHandleWrapper(rdram, ctx);
        goto after_0;
    // 0x80107084: addiu       $a0, $a0, 0x7094
    ctx->r4 = ADD32(ctx->r4, 0X7094);
    after_0:
    // 0x80107088: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8010708C: jr          $ra
    // 0x80107090: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80107090: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv10_dialogueHudAndSoundB(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107094: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80107098: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8010709C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801070A0: jal         0x800C7884
    // 0x801070A4: addiu       $a0, $a0, -0x66E8
    ctx->r4 = ADD32(ctx->r4, -0X66E8);
    setHudFlagBit40AndStoreArg(rdram, ctx);
        goto after_0;
    // 0x801070A4: addiu       $a0, $a0, -0x66E8
    ctx->r4 = ADD32(ctx->r4, -0X66E8);
    after_0:
    // 0x801070A8: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    // 0x801070AC: jal         0x800C7D1C
    // 0x801070B0: addiu       $a0, $zero, 0x2CA
    ctx->r4 = ADD32(0, 0X2CA);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x801070B0: addiu       $a0, $zero, 0x2CA
    ctx->r4 = ADD32(0, 0X2CA);
    after_1:
    // 0x801070B4: jal         0x800C7D98
    // 0x801070B8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    triggerSoundCueByType(rdram, ctx);
        goto after_2;
    // 0x801070B8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_2:
    // 0x801070BC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801070C0: jr          $ra
    // 0x801070C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801070C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv10_scheduleDialogueC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801070C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801070CC: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x801070D0: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x801070D4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x801070D8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801070DC: jal         0x800C7864
    // 0x801070E0: addiu       $a0, $a0, 0x70F0
    ctx->r4 = ADD32(ctx->r4, 0X70F0);
    addTimerHandleWrapper(rdram, ctx);
        goto after_0;
    // 0x801070E0: addiu       $a0, $a0, 0x70F0
    ctx->r4 = ADD32(ctx->r4, 0X70F0);
    after_0:
    // 0x801070E4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801070E8: jr          $ra
    // 0x801070EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801070EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv10_dialogueHudAndSoundC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801070F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801070F4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x801070F8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801070FC: jal         0x800C7884
    // 0x80107100: addiu       $a0, $a0, -0x66D8
    ctx->r4 = ADD32(ctx->r4, -0X66D8);
    setHudFlagBit40AndStoreArg(rdram, ctx);
        goto after_0;
    // 0x80107100: addiu       $a0, $a0, -0x66D8
    ctx->r4 = ADD32(ctx->r4, -0X66D8);
    after_0:
    // 0x80107104: addiu       $a0, $zero, 0x2A5
    ctx->r4 = ADD32(0, 0X2A5);
    // 0x80107108: jal         0x800C7D1C
    // 0x8010710C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x8010710C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // 0x80107110: jal         0x800C7D98
    // 0x80107114: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    triggerSoundCueByType(rdram, ctx);
        goto after_2;
    // 0x80107114: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_2:
    // 0x80107118: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8010711C: jr          $ra
    // 0x80107120: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80107120: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playPairedDialogue_0x1E6_0x256(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107124: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80107128: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8010712C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80107130: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80107134: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80107138: jal         0x800C7D1C
    // 0x8010713C: addiu       $a0, $zero, 0x1E6
    ctx->r4 = ADD32(0, 0X1E6);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x8010713C: addiu       $a0, $zero, 0x1E6
    ctx->r4 = ADD32(0, 0X1E6);
    after_0:
    // 0x80107140: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80107144: jal         0x800C7D1C
    // 0x80107148: addiu       $a0, $zero, 0x256
    ctx->r4 = ADD32(0, 0X256);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x80107148: addiu       $a0, $zero, 0x256
    ctx->r4 = ADD32(0, 0X256);
    after_1:
    // 0x8010714C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80107150: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80107154: jr          $ra
    // 0x80107158: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80107158: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_8010715C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010715C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80107160: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80107164: addiu       $a0, $a0, -0x66CC
    ctx->r4 = ADD32(ctx->r4, -0X66CC);
    // 0x80107168: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8010716C: lui         $a3, 0x4000
    ctx->r7 = S32(0X4000 << 16);
    // 0x80107170: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80107174: jal         0x800C7978
    // 0x80107178: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    func_800C7978(rdram, ctx);
        goto after_0;
    // 0x80107178: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_0:
    // 0x8010717C: jal         0x800C76B0
    // 0x80107180: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_1;
    // 0x80107180: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80107184: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80107188: jr          $ra
    // 0x8010718C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8010718C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playPairedDialogue_0x0AB_0x11B(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107190: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80107194: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80107198: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8010719C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801071A0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801071A4: jal         0x800C7D1C
    // 0x801071A8: addiu       $a0, $zero, 0xAB
    ctx->r4 = ADD32(0, 0XAB);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x801071A8: addiu       $a0, $zero, 0xAB
    ctx->r4 = ADD32(0, 0XAB);
    after_0:
    // 0x801071AC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801071B0: jal         0x800C7D1C
    // 0x801071B4: addiu       $a0, $zero, 0x11B
    ctx->r4 = ADD32(0, 0X11B);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x801071B4: addiu       $a0, $zero, 0x11B
    ctx->r4 = ADD32(0, 0X11B);
    after_1:
    // 0x801071B8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801071BC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801071C0: jr          $ra
    // 0x801071C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801071C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void playVoice2_0x296(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801071C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801071CC: addiu       $a0, $zero, 0x296
    ctx->r4 = ADD32(0, 0X296);
    // 0x801071D0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801071D4: jal         0x800C7D1C
    // 0x801071D8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x801071D8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x801071DC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801071E0: jr          $ra
    // 0x801071E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801071E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lvc_801071E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801071E8: jr          $ra
    // 0x801071EC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x801071EC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void lvc_calculateFriendliesSaved(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801071F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801071F4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801071F8: jal         0x800C761C
    // 0x801071FC: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    getObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x801071FC: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x80107200: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80107204: jal         0x800C77B0
    // 0x80107208: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    setFriendliesSaved(rdram, ctx);
        goto after_1;
    // 0x80107208: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    after_1:
    // 0x8010720C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80107210: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80107214: jr          $ra
    // 0x80107218: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80107218: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void fake_func_8010721C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void lvd_initializeObjectTracking(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107220: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80107224: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80107228: lwc1        $f12, -0x666C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X666C);
    // 0x8010722C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80107230: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80107234: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80107238: jal         0x800C7CEC
    // 0x8010723C: sw          $zero, -0x2EB0($v0)
    MEM_W(-0X2EB0, ctx->r2) = 0;
    setLevelObjectTrackingScalar(rdram, ctx);
        goto after_0;
    // 0x8010723C: sw          $zero, -0x2EB0($v0)
    MEM_W(-0X2EB0, ctx->r2) = 0;
    after_0:
    // 0x80107240: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80107244: addiu       $a0, $a0, 0x7338
    ctx->r4 = ADD32(ctx->r4, 0X7338);
    // 0x80107248: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8010724C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80107250: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    // 0x80107254: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80107258: jal         0x800C7830
    // 0x8010725C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_1;
    // 0x8010725C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_1:
    // 0x80107260: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80107264: addiu       $a0, $a0, 0x7354
    ctx->r4 = ADD32(ctx->r4, 0X7354);
    // 0x80107268: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8010726C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80107270: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    // 0x80107274: jal         0x800C7830
    // 0x80107278: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_2;
    // 0x80107278: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_2:
    // 0x8010727C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80107280: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80107284: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80107288: jr          $ra
    // 0x8010728C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8010728C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void lvd_80107290(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107290: jr          $ra
    // 0x80107294: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80107294: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void lvd_calculateFriendliesSaved(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107298: jr          $ra
    // 0x8010729C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x8010729C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void lvd_checkComplexObjectives(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801072A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801072A4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801072A8: jal         0x800C761C
    // 0x801072AC: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    getObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x801072AC: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_0:
    // 0x801072B0: blez        $v0, L_801072C0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801072B4: nop
    
            goto L_801072C0;
    }
    // 0x801072B4: nop

    // 0x801072B8: jal         0x800C776C
    // 0x801072BC: nop

    setHudEnableBit8(rdram, ctx);
        goto after_1;
    // 0x801072BC: nop

    after_1:
L_801072C0:
    // 0x801072C0: jal         0x800C761C
    // 0x801072C4: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    getObjectiveCount(rdram, ctx);
        goto after_2;
    // 0x801072C4: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    after_2:
    // 0x801072C8: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
    // 0x801072CC: bne         $v0, $v1, L_80107328
    if (ctx->r2 != ctx->r3) {
        // 0x801072D0: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_80107328;
    }
    // 0x801072D0: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x801072D4: lw          $v0, -0x2EB0($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X2EB0);
    // 0x801072D8: bne         $v0, $zero, L_80107328
    if (ctx->r2 != 0) {
        // 0x801072DC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80107328;
    }
    // 0x801072DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801072E0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x801072E4: addiu       $a0, $a0, -0x6690
    ctx->r4 = ADD32(ctx->r4, -0X6690);
    // 0x801072E8: jal         0x800C7884
    // 0x801072EC: sw          $v0, -0x2EB0($v1)
    MEM_W(-0X2EB0, ctx->r3) = ctx->r2;
    setHudFlagBit40AndStoreArg(rdram, ctx);
        goto after_3;
    // 0x801072EC: sw          $v0, -0x2EB0($v1)
    MEM_W(-0X2EB0, ctx->r3) = ctx->r2;
    after_3:
    // 0x801072F0: jal         0x800C76B0
    // 0x801072F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_4;
    // 0x801072F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x801072F8: addiu       $a0, $zero, 0xF5
    ctx->r4 = ADD32(0, 0XF5);
    // 0x801072FC: jal         0x800C7D1C
    // 0x80107300: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_5;
    // 0x80107300: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_5:
    // 0x80107304: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80107308: jal         0x800C7D1C
    // 0x8010730C: addiu       $a0, $zero, 0x172
    ctx->r4 = ADD32(0, 0X172);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_6;
    // 0x8010730C: addiu       $a0, $zero, 0x172
    ctx->r4 = ADD32(0, 0X172);
    after_6:
    // 0x80107310: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80107314: addiu       $a0, $a0, -0x6684
    ctx->r4 = ADD32(ctx->r4, -0X6684);
    // 0x80107318: jal         0x800C7D60
    // 0x8010731C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    delegateToLevelStageTick(rdram, ctx);
        goto after_7;
    // 0x8010731C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_7:
    // 0x80107320: jal         0x800C7D98
    // 0x80107324: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    triggerSoundCueByType(rdram, ctx);
        goto after_8;
    // 0x80107324: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_8:
L_80107328:
    // 0x80107328: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8010732C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80107330: jr          $ra
    // 0x80107334: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80107334: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice_0x171(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107338: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010733C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80107340: jal         0x800C7CF8
    // 0x80107344: addiu       $a0, $zero, 0x171
    ctx->r4 = ADD32(0, 0X171);
    playObjectiveVoiceLine1(rdram, ctx);
        goto after_0;
    // 0x80107344: addiu       $a0, $zero, 0x171
    ctx->r4 = ADD32(0, 0X171);
    after_0:
    // 0x80107348: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8010734C: jr          $ra
    // 0x80107350: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80107350: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice_0x2F2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107354: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80107358: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8010735C: jal         0x800C7CF8
    // 0x80107360: addiu       $a0, $zero, 0x2F2
    ctx->r4 = ADD32(0, 0X2F2);
    playObjectiveVoiceLine1(rdram, ctx);
        goto after_0;
    // 0x80107360: addiu       $a0, $zero, 0x2F2
    ctx->r4 = ADD32(0, 0X2F2);
    after_0:
    // 0x80107364: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80107368: jr          $ra
    // 0x8010736C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8010736C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lve_initializeObjectTracking(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107370: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80107374: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x80107378: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8010737C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80107380: sw          $zero, -0x2EA0($v0)
    MEM_W(-0X2EA0, ctx->r2) = 0;
    // 0x80107384: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80107388: sw          $zero, -0x2E9C($v0)
    MEM_W(-0X2E9C, ctx->r2) = 0;
    // 0x8010738C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80107390: sw          $zero, -0x2E98($v0)
    MEM_W(-0X2E98, ctx->r2) = 0;
    // 0x80107394: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80107398: sw          $zero, -0x2E94($v0)
    MEM_W(-0X2E94, ctx->r2) = 0;
    // 0x8010739C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801073A0: sw          $zero, -0x2E90($v0)
    MEM_W(-0X2E90, ctx->r2) = 0;
    // 0x801073A4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801073A8: sw          $zero, -0x2E8C($v0)
    MEM_W(-0X2E8C, ctx->r2) = 0;
    // 0x801073AC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801073B0: sw          $zero, -0x2E88($v0)
    MEM_W(-0X2E88, ctx->r2) = 0;
    // 0x801073B4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801073B8: sw          $zero, -0x2E84($v0)
    MEM_W(-0X2E84, ctx->r2) = 0;
    // 0x801073BC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801073C0: sw          $zero, -0x2E80($v0)
    MEM_W(-0X2E80, ctx->r2) = 0;
    // 0x801073C4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801073C8: sw          $zero, -0x2E7C($v0)
    MEM_W(-0X2E7C, ctx->r2) = 0;
    // 0x801073CC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801073D0: sw          $zero, -0x2E78($v0)
    MEM_W(-0X2E78, ctx->r2) = 0;
    // 0x801073D4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801073D8: sw          $zero, -0x2E74($v0)
    MEM_W(-0X2E74, ctx->r2) = 0;
    // 0x801073DC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801073E0: sw          $zero, -0x2E70($v0)
    MEM_W(-0X2E70, ctx->r2) = 0;
    // 0x801073E4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801073E8: sw          $zero, -0x2E6C($v0)
    MEM_W(-0X2E6C, ctx->r2) = 0;
    // 0x801073EC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801073F0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801073F4: jal         0x800C7540
    // 0x801073F8: sw          $zero, -0x2E68($v0)
    MEM_W(-0X2E68, ctx->r2) = 0;
    setObjectiveBoolean(rdram, ctx);
        goto after_0;
    // 0x801073F8: sw          $zero, -0x2E68($v0)
    MEM_W(-0X2E68, ctx->r2) = 0;
    after_0:
    // 0x801073FC: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x80107400: jal         0x800C7540
    // 0x80107404: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_1;
    // 0x80107404: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80107408: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x8010740C: jal         0x800C7540
    // 0x80107410: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_2;
    // 0x80107410: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80107414: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x80107418: jal         0x800C7540
    // 0x8010741C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_3;
    // 0x8010741C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x80107420: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x80107424: jal         0x800C7540
    // 0x80107428: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_4;
    // 0x80107428: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x8010742C: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x80107430: jal         0x800C7540
    // 0x80107434: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_5;
    // 0x80107434: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x80107438: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x8010743C: jal         0x800C7540
    // 0x80107440: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_6;
    // 0x80107440: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80107444: addiu       $a0, $zero, 0x21
    ctx->r4 = ADD32(0, 0X21);
    // 0x80107448: jal         0x800C7540
    // 0x8010744C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_7;
    // 0x8010744C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80107450: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    // 0x80107454: jal         0x800C7540
    // 0x80107458: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_8;
    // 0x80107458: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x8010745C: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    // 0x80107460: jal         0x800C7540
    // 0x80107464: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_9;
    // 0x80107464: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x80107468: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    // 0x8010746C: jal         0x800C7540
    // 0x80107470: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_10;
    // 0x80107470: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x80107474: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x80107478: jal         0x800C7540
    // 0x8010747C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_11;
    // 0x8010747C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80107480: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    // 0x80107484: jal         0x800C7540
    // 0x80107488: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_12;
    // 0x80107488: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
    // 0x8010748C: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    // 0x80107490: jal         0x800C7540
    // 0x80107494: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_13;
    // 0x80107494: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x80107498: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    // 0x8010749C: jal         0x800C7540
    // 0x801074A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_14;
    // 0x801074A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x801074A4: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    // 0x801074A8: jal         0x800C7540
    // 0x801074AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_15;
    // 0x801074AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x801074B0: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    // 0x801074B4: jal         0x800C7540
    // 0x801074B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_16;
    // 0x801074B8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
    // 0x801074BC: addiu       $a0, $zero, 0x2F
    ctx->r4 = ADD32(0, 0X2F);
    // 0x801074C0: jal         0x800C7540
    // 0x801074C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_17;
    // 0x801074C4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_17:
    // 0x801074C8: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    // 0x801074CC: jal         0x800C7540
    // 0x801074D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_18;
    // 0x801074D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_18:
    // 0x801074D4: addiu       $a0, $zero, 0x31
    ctx->r4 = ADD32(0, 0X31);
    // 0x801074D8: jal         0x800C7540
    // 0x801074DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_19;
    // 0x801074DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x801074E0: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x801074E4: jal         0x800C7540
    // 0x801074E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_20;
    // 0x801074E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_20:
    // 0x801074EC: addiu       $a0, $zero, 0x56
    ctx->r4 = ADD32(0, 0X56);
    // 0x801074F0: jal         0x800C7540
    // 0x801074F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_21;
    // 0x801074F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_21:
    // 0x801074F8: addiu       $a0, $zero, 0x57
    ctx->r4 = ADD32(0, 0X57);
    // 0x801074FC: jal         0x800C7540
    // 0x80107500: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_22;
    // 0x80107500: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_22:
    // 0x80107504: addiu       $a0, $zero, 0x58
    ctx->r4 = ADD32(0, 0X58);
    // 0x80107508: jal         0x800C7540
    // 0x8010750C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_23;
    // 0x8010750C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_23:
    // 0x80107510: addiu       $a0, $zero, 0x59
    ctx->r4 = ADD32(0, 0X59);
    // 0x80107514: jal         0x800C7540
    // 0x80107518: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_24;
    // 0x80107518: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_24:
    // 0x8010751C: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    // 0x80107520: jal         0x800C7540
    // 0x80107524: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_25;
    // 0x80107524: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_25:
    // 0x80107528: addiu       $a0, $zero, 0x5B
    ctx->r4 = ADD32(0, 0X5B);
    // 0x8010752C: jal         0x800C7540
    // 0x80107530: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_26;
    // 0x80107530: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_26:
    // 0x80107534: addiu       $a0, $zero, 0x5C
    ctx->r4 = ADD32(0, 0X5C);
    // 0x80107538: jal         0x800C7540
    // 0x8010753C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_27;
    // 0x8010753C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_27:
    // 0x80107540: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    // 0x80107544: jal         0x800C7540
    // 0x80107548: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_28;
    // 0x80107548: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_28:
    // 0x8010754C: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    // 0x80107550: jal         0x800C76FC
    // 0x80107554: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    setObjectiveTimer(rdram, ctx);
        goto after_29;
    // 0x80107554: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_29:
    // 0x80107558: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8010755C: lwc1        $f12, -0x6660($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X6660);
    // 0x80107560: jal         0x800C7CEC
    // 0x80107564: nop

    setLevelObjectTrackingScalar(rdram, ctx);
        goto after_30;
    // 0x80107564: nop

    after_30:
    // 0x80107568: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8010756C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80107570: jr          $ra
    // 0x80107574: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80107574: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lve_checkComplexObjectives(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107578: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8010757C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80107580: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80107584: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80107588: jal         0x800C761C
    // 0x8010758C: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    getObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x8010758C: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_0:
    // 0x80107590: slti        $v0, $v0, 0x5
    ctx->r2 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x80107594: bne         $v0, $zero, L_801075B4
    if (ctx->r2 != 0) {
        // 0x80107598: nop
    
            goto L_801075B4;
    }
    // 0x80107598: nop

    // 0x8010759C: jal         0x800C7738
    // 0x801075A0: nop

    setHudEnableBit4(rdram, ctx);
        goto after_1;
    // 0x801075A0: nop

    after_1:
    // 0x801075A4: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x801075A8: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x801075AC: j           L_80107E38
    // 0x801075B0: addiu       $a0, $zero, 0x17C
    ctx->r4 = ADD32(0, 0X17C);
        goto L_80107E38;
    // 0x801075B0: addiu       $a0, $zero, 0x17C
    ctx->r4 = ADD32(0, 0X17C);
L_801075B4:
    // 0x801075B4: jal         0x800C761C
    // 0x801075B8: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    getObjectiveCount(rdram, ctx);
        goto after_2;
    // 0x801075B8: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_2:
    // 0x801075BC: slti        $v0, $v0, 0xD
    ctx->r2 = SIGNED(ctx->r2) < 0XD ? 1 : 0;
    // 0x801075C0: bne         $v0, $zero, L_801075E0
    if (ctx->r2 != 0) {
        // 0x801075C4: nop
    
            goto L_801075E0;
    }
    // 0x801075C4: nop

    // 0x801075C8: jal         0x800C7738
    // 0x801075CC: nop

    setHudEnableBit4(rdram, ctx);
        goto after_3;
    // 0x801075CC: nop

    after_3:
    // 0x801075D0: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x801075D4: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x801075D8: j           L_80107E38
    // 0x801075DC: addiu       $a0, $zero, 0x17D
    ctx->r4 = ADD32(0, 0X17D);
        goto L_80107E38;
    // 0x801075DC: addiu       $a0, $zero, 0x17D
    ctx->r4 = ADD32(0, 0X17D);
L_801075E0:
    // 0x801075E0: jal         0x800C759C
    // 0x801075E4: addiu       $a0, $zero, 0x66
    ctx->r4 = ADD32(0, 0X66);
    getObjectiveBoolean(rdram, ctx);
        goto after_4;
    // 0x801075E4: addiu       $a0, $zero, 0x66
    ctx->r4 = ADD32(0, 0X66);
    after_4:
    // 0x801075E8: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x801075EC: bne         $v0, $s0, L_80107614
    if (ctx->r2 != ctx->r16) {
        // 0x801075F0: nop
    
            goto L_80107614;
    }
    // 0x801075F0: nop

    // 0x801075F4: jal         0x800C76B0
    // 0x801075F8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_5;
    // 0x801075F8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_5:
    // 0x801075FC: jal         0x800C776C
    // 0x80107600: nop

    setHudEnableBit8(rdram, ctx);
        goto after_6;
    // 0x80107600: nop

    after_6:
    // 0x80107604: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80107608: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x8010760C: j           L_80107E38
    // 0x80107610: addiu       $a0, $zero, 0x1E1
    ctx->r4 = ADD32(0, 0X1E1);
        goto L_80107E38;
    // 0x80107610: addiu       $a0, $zero, 0x1E1
    ctx->r4 = ADD32(0, 0X1E1);
L_80107614:
    // 0x80107614: jal         0x800C761C
    // 0x80107618: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    getObjectiveCount(rdram, ctx);
        goto after_7;
    // 0x80107618: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_7:
    // 0x8010761C: slti        $v0, $v0, 0x1A
    ctx->r2 = SIGNED(ctx->r2) < 0X1A ? 1 : 0;
    // 0x80107620: bne         $v0, $zero, L_80107654
    if (ctx->r2 != 0) {
        // 0x80107624: nop
    
            goto L_80107654;
    }
    // 0x80107624: nop

    // 0x80107628: jal         0x800C761C
    // 0x8010762C: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    getObjectiveCount(rdram, ctx);
        goto after_8;
    // 0x8010762C: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    after_8:
    // 0x80107630: slti        $v0, $v0, 0xE
    ctx->r2 = SIGNED(ctx->r2) < 0XE ? 1 : 0;
    // 0x80107634: bne         $v0, $zero, L_80107654
    if (ctx->r2 != 0) {
        // 0x80107638: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_80107654;
    }
    // 0x80107638: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8010763C: lw          $v0, -0x2E68($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X2E68);
    // 0x80107640: bne         $v0, $zero, L_80107654
    if (ctx->r2 != 0) {
        // 0x80107644: nop
    
            goto L_80107654;
    }
    // 0x80107644: nop

    // 0x80107648: sw          $s0, -0x2E68($v1)
    MEM_W(-0X2E68, ctx->r3) = ctx->r16;
    // 0x8010764C: jal         0x800C76B0
    // 0x80107650: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_9;
    // 0x80107650: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_9:
L_80107654:
    // 0x80107654: jal         0x800C761C
    // 0x80107658: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    getObjectiveCount(rdram, ctx);
        goto after_10;
    // 0x80107658: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_10:
    // 0x8010765C: slti        $v0, $v0, 0x1A
    ctx->r2 = SIGNED(ctx->r2) < 0X1A ? 1 : 0;
    // 0x80107660: bne         $v0, $zero, L_80107680
    if (ctx->r2 != 0) {
        // 0x80107664: nop
    
            goto L_80107680;
    }
    // 0x80107664: nop

    // 0x80107668: jal         0x800C759C
    // 0x8010766C: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    getObjectiveBoolean(rdram, ctx);
        goto after_11;
    // 0x8010766C: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    after_11:
    // 0x80107670: bne         $v0, $zero, L_80107680
    if (ctx->r2 != 0) {
        // 0x80107674: addiu       $a0, $zero, 0x1A
        ctx->r4 = ADD32(0, 0X1A);
            goto L_80107680;
    }
    // 0x80107674: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    // 0x80107678: jal         0x800C7540
    // 0x8010767C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_12;
    // 0x8010767C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_12:
L_80107680:
    // 0x80107680: jal         0x800C759C
    // 0x80107684: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    getObjectiveBoolean(rdram, ctx);
        goto after_13;
    // 0x80107684: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    after_13:
    // 0x80107688: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8010768C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80107690: bne         $s0, $v0, L_80107744
    if (ctx->r16 != ctx->r2) {
        // 0x80107694: nop
    
            goto L_80107744;
    }
    // 0x80107694: nop

    // 0x80107698: jal         0x800C759C
    // 0x8010769C: addiu       $a0, $zero, 0x6C
    ctx->r4 = ADD32(0, 0X6C);
    getObjectiveBoolean(rdram, ctx);
        goto after_14;
    // 0x8010769C: addiu       $a0, $zero, 0x6C
    ctx->r4 = ADD32(0, 0X6C);
    after_14:
    // 0x801076A0: bne         $v0, $s0, L_801076C0
    if (ctx->r2 != ctx->r16) {
        // 0x801076A4: nop
    
            goto L_801076C0;
    }
    // 0x801076A4: nop

    // 0x801076A8: jal         0x800C759C
    // 0x801076AC: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    getObjectiveBoolean(rdram, ctx);
        goto after_15;
    // 0x801076AC: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    after_15:
    // 0x801076B0: bne         $v0, $zero, L_801076C0
    if (ctx->r2 != 0) {
        // 0x801076B4: addiu       $a0, $zero, 0x33
        ctx->r4 = ADD32(0, 0X33);
            goto L_801076C0;
    }
    // 0x801076B4: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    // 0x801076B8: jal         0x800C7540
    // 0x801076BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_16;
    // 0x801076BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_16:
L_801076C0:
    // 0x801076C0: jal         0x800C759C
    // 0x801076C4: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    getObjectiveBoolean(rdram, ctx);
        goto after_17;
    // 0x801076C4: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_17:
    // 0x801076C8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801076CC: bne         $v0, $v1, L_801076EC
    if (ctx->r2 != ctx->r3) {
        // 0x801076D0: nop
    
            goto L_801076EC;
    }
    // 0x801076D0: nop

    // 0x801076D4: jal         0x800C759C
    // 0x801076D8: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    getObjectiveBoolean(rdram, ctx);
        goto after_18;
    // 0x801076D8: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    after_18:
    // 0x801076DC: bne         $v0, $zero, L_801076EC
    if (ctx->r2 != 0) {
        // 0x801076E0: addiu       $a0, $zero, 0x34
        ctx->r4 = ADD32(0, 0X34);
            goto L_801076EC;
    }
    // 0x801076E0: addiu       $a0, $zero, 0x34
    ctx->r4 = ADD32(0, 0X34);
    // 0x801076E4: jal         0x800C7540
    // 0x801076E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_19;
    // 0x801076E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
L_801076EC:
    // 0x801076EC: jal         0x800C759C
    // 0x801076F0: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    getObjectiveBoolean(rdram, ctx);
        goto after_20;
    // 0x801076F0: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_20:
    // 0x801076F4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801076F8: bne         $v0, $v1, L_80107718
    if (ctx->r2 != ctx->r3) {
        // 0x801076FC: nop
    
            goto L_80107718;
    }
    // 0x801076FC: nop

    // 0x80107700: jal         0x800C759C
    // 0x80107704: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    getObjectiveBoolean(rdram, ctx);
        goto after_21;
    // 0x80107704: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    after_21:
    // 0x80107708: bne         $v0, $zero, L_80107718
    if (ctx->r2 != 0) {
        // 0x8010770C: addiu       $a0, $zero, 0x35
        ctx->r4 = ADD32(0, 0X35);
            goto L_80107718;
    }
    // 0x8010770C: addiu       $a0, $zero, 0x35
    ctx->r4 = ADD32(0, 0X35);
    // 0x80107710: jal         0x800C7540
    // 0x80107714: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_22;
    // 0x80107714: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_22:
L_80107718:
    // 0x80107718: jal         0x800C759C
    // 0x8010771C: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    getObjectiveBoolean(rdram, ctx);
        goto after_23;
    // 0x8010771C: addiu       $a0, $zero, 0x13
    ctx->r4 = ADD32(0, 0X13);
    after_23:
    // 0x80107720: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80107724: bne         $v0, $v1, L_80107744
    if (ctx->r2 != ctx->r3) {
        // 0x80107728: nop
    
            goto L_80107744;
    }
    // 0x80107728: nop

    // 0x8010772C: jal         0x800C759C
    // 0x80107730: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    getObjectiveBoolean(rdram, ctx);
        goto after_24;
    // 0x80107730: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    after_24:
    // 0x80107734: bne         $v0, $zero, L_80107744
    if (ctx->r2 != 0) {
        // 0x80107738: addiu       $a0, $zero, 0x36
        ctx->r4 = ADD32(0, 0X36);
            goto L_80107744;
    }
    // 0x80107738: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    // 0x8010773C: jal         0x800C7540
    // 0x80107740: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_25;
    // 0x80107740: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_25:
L_80107744:
    // 0x80107744: jal         0x800C759C
    // 0x80107748: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    getObjectiveBoolean(rdram, ctx);
        goto after_26;
    // 0x80107748: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_26:
    // 0x8010774C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80107750: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80107754: bne         $s0, $v0, L_80107784
    if (ctx->r16 != ctx->r2) {
        // 0x80107758: nop
    
            goto L_80107784;
    }
    // 0x80107758: nop

    // 0x8010775C: jal         0x800C759C
    // 0x80107760: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    getObjectiveBoolean(rdram, ctx);
        goto after_27;
    // 0x80107760: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_27:
    // 0x80107764: bne         $v0, $s0, L_80107784
    if (ctx->r2 != ctx->r16) {
        // 0x80107768: nop
    
            goto L_80107784;
    }
    // 0x80107768: nop

    // 0x8010776C: jal         0x800C759C
    // 0x80107770: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    getObjectiveBoolean(rdram, ctx);
        goto after_28;
    // 0x80107770: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    after_28:
    // 0x80107774: bne         $v0, $zero, L_80107784
    if (ctx->r2 != 0) {
        // 0x80107778: addiu       $a0, $zero, 0x43
        ctx->r4 = ADD32(0, 0X43);
            goto L_80107784;
    }
    // 0x80107778: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    // 0x8010777C: jal         0x800C7540
    // 0x80107780: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_29;
    // 0x80107780: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_29:
L_80107784:
    // 0x80107784: jal         0x800C759C
    // 0x80107788: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    getObjectiveBoolean(rdram, ctx);
        goto after_30;
    // 0x80107788: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_30:
    // 0x8010778C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80107790: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80107794: bne         $s0, $v0, L_801077C4
    if (ctx->r16 != ctx->r2) {
        // 0x80107798: nop
    
            goto L_801077C4;
    }
    // 0x80107798: nop

    // 0x8010779C: jal         0x800C759C
    // 0x801077A0: addiu       $a0, $zero, 0x55
    ctx->r4 = ADD32(0, 0X55);
    getObjectiveBoolean(rdram, ctx);
        goto after_31;
    // 0x801077A0: addiu       $a0, $zero, 0x55
    ctx->r4 = ADD32(0, 0X55);
    after_31:
    // 0x801077A4: bne         $v0, $s0, L_801077C4
    if (ctx->r2 != ctx->r16) {
        // 0x801077A8: nop
    
            goto L_801077C4;
    }
    // 0x801077A8: nop

    // 0x801077AC: jal         0x800C759C
    // 0x801077B0: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    getObjectiveBoolean(rdram, ctx);
        goto after_32;
    // 0x801077B0: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    after_32:
    // 0x801077B4: bne         $v0, $zero, L_801077C4
    if (ctx->r2 != 0) {
        // 0x801077B8: addiu       $a0, $zero, 0x44
        ctx->r4 = ADD32(0, 0X44);
            goto L_801077C4;
    }
    // 0x801077B8: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    // 0x801077BC: jal         0x800C7540
    // 0x801077C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_33;
    // 0x801077C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_33:
L_801077C4:
    // 0x801077C4: jal         0x800C759C
    // 0x801077C8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    getObjectiveBoolean(rdram, ctx);
        goto after_34;
    // 0x801077C8: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_34:
    // 0x801077CC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801077D0: bne         $v0, $v1, L_801077F0
    if (ctx->r2 != ctx->r3) {
        // 0x801077D4: nop
    
            goto L_801077F0;
    }
    // 0x801077D4: nop

    // 0x801077D8: jal         0x800C759C
    // 0x801077DC: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    getObjectiveBoolean(rdram, ctx);
        goto after_35;
    // 0x801077DC: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    after_35:
    // 0x801077E0: bne         $v0, $zero, L_801077F0
    if (ctx->r2 != 0) {
        // 0x801077E4: addiu       $a0, $zero, 0x45
        ctx->r4 = ADD32(0, 0X45);
            goto L_801077F0;
    }
    // 0x801077E4: addiu       $a0, $zero, 0x45
    ctx->r4 = ADD32(0, 0X45);
    // 0x801077E8: jal         0x800C7540
    // 0x801077EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_36;
    // 0x801077EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_36:
L_801077F0:
    // 0x801077F0: jal         0x800C761C
    // 0x801077F4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    getObjectiveCount(rdram, ctx);
        goto after_37;
    // 0x801077F4: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_37:
    // 0x801077F8: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x801077FC: bne         $v0, $v1, L_8010781C
    if (ctx->r2 != ctx->r3) {
        // 0x80107800: nop
    
            goto L_8010781C;
    }
    // 0x80107800: nop

    // 0x80107804: jal         0x800C759C
    // 0x80107808: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    getObjectiveBoolean(rdram, ctx);
        goto after_38;
    // 0x80107808: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    after_38:
    // 0x8010780C: bne         $v0, $zero, L_8010781C
    if (ctx->r2 != 0) {
        // 0x80107810: addiu       $a0, $zero, 0x46
        ctx->r4 = ADD32(0, 0X46);
            goto L_8010781C;
    }
    // 0x80107810: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    // 0x80107814: jal         0x800C7540
    // 0x80107818: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_39;
    // 0x80107818: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_39:
L_8010781C:
    // 0x8010781C: jal         0x800C761C
    // 0x80107820: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    getObjectiveCount(rdram, ctx);
        goto after_40;
    // 0x80107820: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_40:
    // 0x80107824: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80107828: bne         $v0, $v1, L_80107848
    if (ctx->r2 != ctx->r3) {
        // 0x8010782C: nop
    
            goto L_80107848;
    }
    // 0x8010782C: nop

    // 0x80107830: jal         0x800C759C
    // 0x80107834: addiu       $a0, $zero, 0x47
    ctx->r4 = ADD32(0, 0X47);
    getObjectiveBoolean(rdram, ctx);
        goto after_41;
    // 0x80107834: addiu       $a0, $zero, 0x47
    ctx->r4 = ADD32(0, 0X47);
    after_41:
    // 0x80107838: bne         $v0, $zero, L_80107848
    if (ctx->r2 != 0) {
        // 0x8010783C: addiu       $a0, $zero, 0x47
        ctx->r4 = ADD32(0, 0X47);
            goto L_80107848;
    }
    // 0x8010783C: addiu       $a0, $zero, 0x47
    ctx->r4 = ADD32(0, 0X47);
    // 0x80107840: jal         0x800C7540
    // 0x80107844: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_42;
    // 0x80107844: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_42:
L_80107848:
    // 0x80107848: jal         0x800C761C
    // 0x8010784C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    getObjectiveCount(rdram, ctx);
        goto after_43;
    // 0x8010784C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_43:
    // 0x80107850: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80107854: bne         $v0, $v1, L_80107874
    if (ctx->r2 != ctx->r3) {
        // 0x80107858: nop
    
            goto L_80107874;
    }
    // 0x80107858: nop

    // 0x8010785C: jal         0x800C759C
    // 0x80107860: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    getObjectiveBoolean(rdram, ctx);
        goto after_44;
    // 0x80107860: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    after_44:
    // 0x80107864: bne         $v0, $zero, L_80107874
    if (ctx->r2 != 0) {
        // 0x80107868: addiu       $a0, $zero, 0x48
        ctx->r4 = ADD32(0, 0X48);
            goto L_80107874;
    }
    // 0x80107868: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    // 0x8010786C: jal         0x800C7540
    // 0x80107870: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_45;
    // 0x80107870: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_45:
L_80107874:
    // 0x80107874: jal         0x800C761C
    // 0x80107878: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    getObjectiveCount(rdram, ctx);
        goto after_46;
    // 0x80107878: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_46:
    // 0x8010787C: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // 0x80107880: bne         $v0, $v1, L_801078A0
    if (ctx->r2 != ctx->r3) {
        // 0x80107884: nop
    
            goto L_801078A0;
    }
    // 0x80107884: nop

    // 0x80107888: jal         0x800C759C
    // 0x8010788C: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    getObjectiveBoolean(rdram, ctx);
        goto after_47;
    // 0x8010788C: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    after_47:
    // 0x80107890: bne         $v0, $zero, L_801078A0
    if (ctx->r2 != 0) {
        // 0x80107894: addiu       $a0, $zero, 0x49
        ctx->r4 = ADD32(0, 0X49);
            goto L_801078A0;
    }
    // 0x80107894: addiu       $a0, $zero, 0x49
    ctx->r4 = ADD32(0, 0X49);
    // 0x80107898: jal         0x800C7540
    // 0x8010789C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_48;
    // 0x8010789C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_48:
L_801078A0:
    // 0x801078A0: jal         0x800C761C
    // 0x801078A4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    getObjectiveCount(rdram, ctx);
        goto after_49;
    // 0x801078A4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_49:
    // 0x801078A8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801078AC: bne         $v0, $v1, L_801078CC
    if (ctx->r2 != ctx->r3) {
        // 0x801078B0: nop
    
            goto L_801078CC;
    }
    // 0x801078B0: nop

    // 0x801078B4: jal         0x800C759C
    // 0x801078B8: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    getObjectiveBoolean(rdram, ctx);
        goto after_50;
    // 0x801078B8: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    after_50:
    // 0x801078BC: bne         $v0, $zero, L_801078CC
    if (ctx->r2 != 0) {
        // 0x801078C0: addiu       $a0, $zero, 0x4A
        ctx->r4 = ADD32(0, 0X4A);
            goto L_801078CC;
    }
    // 0x801078C0: addiu       $a0, $zero, 0x4A
    ctx->r4 = ADD32(0, 0X4A);
    // 0x801078C4: jal         0x800C7540
    // 0x801078C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_51;
    // 0x801078C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_51:
L_801078CC:
    // 0x801078CC: jal         0x800C761C
    // 0x801078D0: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    getObjectiveCount(rdram, ctx);
        goto after_52;
    // 0x801078D0: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_52:
    // 0x801078D4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801078D8: bne         $v0, $v1, L_801078F8
    if (ctx->r2 != ctx->r3) {
        // 0x801078DC: nop
    
            goto L_801078F8;
    }
    // 0x801078DC: nop

    // 0x801078E0: jal         0x800C759C
    // 0x801078E4: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    getObjectiveBoolean(rdram, ctx);
        goto after_53;
    // 0x801078E4: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    after_53:
    // 0x801078E8: bne         $v0, $zero, L_801078F8
    if (ctx->r2 != 0) {
        // 0x801078EC: addiu       $a0, $zero, 0x4B
        ctx->r4 = ADD32(0, 0X4B);
            goto L_801078F8;
    }
    // 0x801078EC: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    // 0x801078F0: jal         0x800C7540
    // 0x801078F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_54;
    // 0x801078F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_54:
L_801078F8:
    // 0x801078F8: jal         0x800C761C
    // 0x801078FC: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    getObjectiveCount(rdram, ctx);
        goto after_55;
    // 0x801078FC: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    after_55:
    // 0x80107900: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
    // 0x80107904: bne         $v0, $v1, L_80107924
    if (ctx->r2 != ctx->r3) {
        // 0x80107908: nop
    
            goto L_80107924;
    }
    // 0x80107908: nop

    // 0x8010790C: jal         0x800C759C
    // 0x80107910: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    getObjectiveBoolean(rdram, ctx);
        goto after_56;
    // 0x80107910: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    after_56:
    // 0x80107914: bne         $v0, $zero, L_80107924
    if (ctx->r2 != 0) {
        // 0x80107918: addiu       $a0, $zero, 0x4C
        ctx->r4 = ADD32(0, 0X4C);
            goto L_80107924;
    }
    // 0x80107918: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    // 0x8010791C: jal         0x800C7540
    // 0x80107920: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_57;
    // 0x80107920: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_57:
L_80107924:
    // 0x80107924: jal         0x800C761C
    // 0x80107928: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    getObjectiveCount(rdram, ctx);
        goto after_58;
    // 0x80107928: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_58:
    // 0x8010792C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80107930: bne         $v0, $v1, L_80107950
    if (ctx->r2 != ctx->r3) {
        // 0x80107934: nop
    
            goto L_80107950;
    }
    // 0x80107934: nop

    // 0x80107938: jal         0x800C759C
    // 0x8010793C: addiu       $a0, $zero, 0x4D
    ctx->r4 = ADD32(0, 0X4D);
    getObjectiveBoolean(rdram, ctx);
        goto after_59;
    // 0x8010793C: addiu       $a0, $zero, 0x4D
    ctx->r4 = ADD32(0, 0X4D);
    after_59:
    // 0x80107940: bne         $v0, $zero, L_80107950
    if (ctx->r2 != 0) {
        // 0x80107944: addiu       $a0, $zero, 0x4D
        ctx->r4 = ADD32(0, 0X4D);
            goto L_80107950;
    }
    // 0x80107944: addiu       $a0, $zero, 0x4D
    ctx->r4 = ADD32(0, 0X4D);
    // 0x80107948: jal         0x800C7540
    // 0x8010794C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_60;
    // 0x8010794C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_60:
L_80107950:
    // 0x80107950: jal         0x800C761C
    // 0x80107954: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    getObjectiveCount(rdram, ctx);
        goto after_61;
    // 0x80107954: addiu       $a0, $zero, 0xD
    ctx->r4 = ADD32(0, 0XD);
    after_61:
    // 0x80107958: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8010795C: bne         $v0, $v1, L_8010797C
    if (ctx->r2 != ctx->r3) {
        // 0x80107960: nop
    
            goto L_8010797C;
    }
    // 0x80107960: nop

    // 0x80107964: jal         0x800C759C
    // 0x80107968: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    getObjectiveBoolean(rdram, ctx);
        goto after_62;
    // 0x80107968: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    after_62:
    // 0x8010796C: bne         $v0, $zero, L_8010797C
    if (ctx->r2 != 0) {
        // 0x80107970: addiu       $a0, $zero, 0x4E
        ctx->r4 = ADD32(0, 0X4E);
            goto L_8010797C;
    }
    // 0x80107970: addiu       $a0, $zero, 0x4E
    ctx->r4 = ADD32(0, 0X4E);
    // 0x80107974: jal         0x800C7540
    // 0x80107978: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_63;
    // 0x80107978: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_63:
L_8010797C:
    // 0x8010797C: jal         0x800C761C
    // 0x80107980: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    getObjectiveCount(rdram, ctx);
        goto after_64;
    // 0x80107980: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_64:
    // 0x80107984: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80107988: bne         $v0, $v1, L_801079B0
    if (ctx->r2 != ctx->r3) {
        // 0x8010798C: lui         $s0, 0x8011
        ctx->r16 = S32(0X8011 << 16);
            goto L_801079B0;
    }
    // 0x8010798C: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80107990: jal         0x800C759C
    // 0x80107994: addiu       $a0, $zero, 0x4F
    ctx->r4 = ADD32(0, 0X4F);
    getObjectiveBoolean(rdram, ctx);
        goto after_65;
    // 0x80107994: addiu       $a0, $zero, 0x4F
    ctx->r4 = ADD32(0, 0X4F);
    after_65:
    // 0x80107998: bne         $v0, $zero, L_801079B0
    if (ctx->r2 != 0) {
        // 0x8010799C: lui         $s0, 0x8011
        ctx->r16 = S32(0X8011 << 16);
            goto L_801079B0;
    }
    // 0x8010799C: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x801079A0: addiu       $a0, $zero, 0x4F
    ctx->r4 = ADD32(0, 0X4F);
    // 0x801079A4: jal         0x800C7540
    // 0x801079A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_66;
    // 0x801079A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_66:
    // 0x801079AC: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
L_801079B0:
    // 0x801079B0: lw          $v1, -0x2EA0($s0)
    ctx->r3 = MEM_W(ctx->r16, -0X2EA0);
    // 0x801079B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801079B8: bnel        $v1, $v0, L_801079E4
    if (ctx->r3 != ctx->r2) {
        // 0x801079BC: lui         $s0, 0x8011
        ctx->r16 = S32(0X8011 << 16);
            goto L_801079E4;
    }
    goto skip_0;
    // 0x801079BC: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    skip_0:
    // 0x801079C0: jal         0x800C76E0
    // 0x801079C4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    getObjectiveTimer(rdram, ctx);
        goto after_67;
    // 0x801079C4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_67:
    // 0x801079C8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x801079CC: lwc1        $f2, -0x6620($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6620);
    // 0x801079D0: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x801079D4: nop

    // 0x801079D8: bc1tl       L_801079E0
    if (c1cs) {
        // 0x801079DC: sw          $zero, -0x2EA0($s0)
        MEM_W(-0X2EA0, ctx->r16) = 0;
            goto L_801079E0;
    }
    goto skip_1;
    // 0x801079DC: sw          $zero, -0x2EA0($s0)
    MEM_W(-0X2EA0, ctx->r16) = 0;
    skip_1:
L_801079E0:
    // 0x801079E0: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
L_801079E4:
    // 0x801079E4: lw          $v0, -0x2EA0($s0)
    ctx->r2 = MEM_W(ctx->r16, -0X2EA0);
    // 0x801079E8: bne         $v0, $zero, L_80107E44
    if (ctx->r2 != 0) {
        // 0x801079EC: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80107E44;
    }
    // 0x801079EC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x801079F0: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x801079F4: lw          $v0, -0x2E9C($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X2E9C);
    // 0x801079F8: bne         $v0, $zero, L_80107A24
    if (ctx->r2 != 0) {
        // 0x801079FC: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_80107A24;
    }
    // 0x801079FC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80107A00: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    // 0x80107A04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80107A08: sw          $v0, -0x2E9C($v1)
    MEM_W(-0X2E9C, ctx->r3) = ctx->r2;
    // 0x80107A0C: jal         0x800C76FC
    // 0x80107A10: sw          $v0, -0x2EA0($s0)
    MEM_W(-0X2EA0, ctx->r16) = ctx->r2;
    setObjectiveTimer(rdram, ctx);
        goto after_68;
    // 0x80107A10: sw          $v0, -0x2EA0($s0)
    MEM_W(-0X2EA0, ctx->r16) = ctx->r2;
    after_68:
    // 0x80107A14: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80107A18: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80107A1C: j           L_80107E38
    // 0x80107A20: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
        goto L_80107E38;
    // 0x80107A20: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
L_80107A24:
    // 0x80107A24: jal         0x800C759C
    // 0x80107A28: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    getObjectiveBoolean(rdram, ctx);
        goto after_69;
    // 0x80107A28: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    after_69:
    // 0x80107A2C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80107A30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80107A34: bne         $v1, $v0, L_80107A68
    if (ctx->r3 != ctx->r2) {
        // 0x80107A38: lui         $a2, 0x8011
        ctx->r6 = S32(0X8011 << 16);
            goto L_80107A68;
    }
    // 0x80107A38: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80107A3C: lw          $v0, -0x2E98($a2)
    ctx->r2 = MEM_W(ctx->r6, -0X2E98);
    // 0x80107A40: bne         $v0, $zero, L_80107A68
    if (ctx->r2 != 0) {
        // 0x80107A44: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_80107A68;
    }
    // 0x80107A44: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80107A48: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    // 0x80107A4C: sw          $v1, -0x2E98($a2)
    MEM_W(-0X2E98, ctx->r6) = ctx->r3;
    // 0x80107A50: jal         0x800C76FC
    // 0x80107A54: sw          $v1, -0x2EA0($s0)
    MEM_W(-0X2EA0, ctx->r16) = ctx->r3;
    setObjectiveTimer(rdram, ctx);
        goto after_70;
    // 0x80107A54: sw          $v1, -0x2EA0($s0)
    MEM_W(-0X2EA0, ctx->r16) = ctx->r3;
    after_70:
    // 0x80107A58: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80107A5C: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80107A60: j           L_80107E38
    // 0x80107A64: addiu       $a0, $zero, 0x29B
    ctx->r4 = ADD32(0, 0X29B);
        goto L_80107E38;
    // 0x80107A64: addiu       $a0, $zero, 0x29B
    ctx->r4 = ADD32(0, 0X29B);
L_80107A68:
    // 0x80107A68: jal         0x800C761C
    // 0x80107A6C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    getObjectiveCount(rdram, ctx);
        goto after_71;
    // 0x80107A6C: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_71:
    // 0x80107A70: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80107A74: bne         $v0, $v1, L_80107AB0
    if (ctx->r2 != ctx->r3) {
        // 0x80107A78: lui         $a2, 0x8011
        ctx->r6 = S32(0X8011 << 16);
            goto L_80107AB0;
    }
    // 0x80107A78: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80107A7C: lw          $v0, -0x2E94($a2)
    ctx->r2 = MEM_W(ctx->r6, -0X2E94);
    // 0x80107A80: bne         $v0, $zero, L_80107AB0
    if (ctx->r2 != 0) {
        // 0x80107A84: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_80107AB0;
    }
    // 0x80107A84: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80107A88: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80107A8C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80107A90: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80107A94: sw          $v1, -0x2E94($a2)
    MEM_W(-0X2E94, ctx->r6) = ctx->r3;
    // 0x80107A98: jal         0x800C76FC
    // 0x80107A9C: sw          $v1, -0x2EA0($v0)
    MEM_W(-0X2EA0, ctx->r2) = ctx->r3;
    setObjectiveTimer(rdram, ctx);
        goto after_72;
    // 0x80107A9C: sw          $v1, -0x2EA0($v0)
    MEM_W(-0X2EA0, ctx->r2) = ctx->r3;
    after_72:
    // 0x80107AA0: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80107AA4: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80107AA8: j           L_80107E38
    // 0x80107AAC: addiu       $a0, $zero, 0x2AA
    ctx->r4 = ADD32(0, 0X2AA);
        goto L_80107E38;
    // 0x80107AAC: addiu       $a0, $zero, 0x2AA
    ctx->r4 = ADD32(0, 0X2AA);
L_80107AB0:
    // 0x80107AB0: jal         0x800C761C
    // 0x80107AB4: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    getObjectiveCount(rdram, ctx);
        goto after_73;
    // 0x80107AB4: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_73:
    // 0x80107AB8: addiu       $v1, $zero, 0x7
    ctx->r3 = ADD32(0, 0X7);
    // 0x80107ABC: bne         $v0, $v1, L_80107AF8
    if (ctx->r2 != ctx->r3) {
        // 0x80107AC0: lui         $a2, 0x8011
        ctx->r6 = S32(0X8011 << 16);
            goto L_80107AF8;
    }
    // 0x80107AC0: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80107AC4: lw          $v0, -0x2E90($a2)
    ctx->r2 = MEM_W(ctx->r6, -0X2E90);
    // 0x80107AC8: bne         $v0, $zero, L_80107AF8
    if (ctx->r2 != 0) {
        // 0x80107ACC: addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
            goto L_80107AF8;
    }
    // 0x80107ACC: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x80107AD0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80107AD4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80107AD8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80107ADC: sw          $v1, -0x2E90($a2)
    MEM_W(-0X2E90, ctx->r6) = ctx->r3;
    // 0x80107AE0: jal         0x800C76FC
    // 0x80107AE4: sw          $v1, -0x2EA0($v0)
    MEM_W(-0X2EA0, ctx->r2) = ctx->r3;
    setObjectiveTimer(rdram, ctx);
        goto after_74;
    // 0x80107AE4: sw          $v1, -0x2EA0($v0)
    MEM_W(-0X2EA0, ctx->r2) = ctx->r3;
    after_74:
    // 0x80107AE8: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80107AEC: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80107AF0: j           L_80107E38
    // 0x80107AF4: addiu       $a0, $zero, 0x2A9
    ctx->r4 = ADD32(0, 0X2A9);
        goto L_80107E38;
    // 0x80107AF4: addiu       $a0, $zero, 0x2A9
    ctx->r4 = ADD32(0, 0X2A9);
L_80107AF8:
    // 0x80107AF8: jal         0x800C761C
    // 0x80107AFC: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    getObjectiveCount(rdram, ctx);
        goto after_75;
    // 0x80107AFC: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    after_75:
    // 0x80107B00: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x80107B04: bne         $v0, $v1, L_80107B40
    if (ctx->r2 != ctx->r3) {
        // 0x80107B08: lui         $a2, 0x8011
        ctx->r6 = S32(0X8011 << 16);
            goto L_80107B40;
    }
    // 0x80107B08: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80107B0C: lw          $v0, -0x2E8C($a2)
    ctx->r2 = MEM_W(ctx->r6, -0X2E8C);
    // 0x80107B10: bne         $v0, $zero, L_80107B40
    if (ctx->r2 != 0) {
        // 0x80107B14: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_80107B40;
    }
    // 0x80107B14: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80107B18: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80107B1C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80107B20: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80107B24: sw          $v1, -0x2E8C($a2)
    MEM_W(-0X2E8C, ctx->r6) = ctx->r3;
    // 0x80107B28: jal         0x800C76FC
    // 0x80107B2C: sw          $v1, -0x2EA0($v0)
    MEM_W(-0X2EA0, ctx->r2) = ctx->r3;
    setObjectiveTimer(rdram, ctx);
        goto after_76;
    // 0x80107B2C: sw          $v1, -0x2EA0($v0)
    MEM_W(-0X2EA0, ctx->r2) = ctx->r3;
    after_76:
    // 0x80107B30: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80107B34: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80107B38: j           L_80107E38
    // 0x80107B3C: addiu       $a0, $zero, 0x2A8
    ctx->r4 = ADD32(0, 0X2A8);
        goto L_80107E38;
    // 0x80107B3C: addiu       $a0, $zero, 0x2A8
    ctx->r4 = ADD32(0, 0X2A8);
L_80107B40:
    // 0x80107B40: jal         0x800C761C
    // 0x80107B44: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    getObjectiveCount(rdram, ctx);
        goto after_77;
    // 0x80107B44: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    after_77:
    // 0x80107B48: slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80107B4C: bne         $v0, $zero, L_80107B88
    if (ctx->r2 != 0) {
        // 0x80107B50: lui         $a2, 0x8011
        ctx->r6 = S32(0X8011 << 16);
            goto L_80107B88;
    }
    // 0x80107B50: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80107B54: lw          $v0, -0x2E88($a2)
    ctx->r2 = MEM_W(ctx->r6, -0X2E88);
    // 0x80107B58: bne         $v0, $zero, L_80107B88
    if (ctx->r2 != 0) {
        // 0x80107B5C: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_80107B88;
    }
    // 0x80107B5C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80107B60: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80107B64: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80107B68: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80107B6C: sw          $v1, -0x2E88($a2)
    MEM_W(-0X2E88, ctx->r6) = ctx->r3;
    // 0x80107B70: jal         0x800C76FC
    // 0x80107B74: sw          $v1, -0x2EA0($v0)
    MEM_W(-0X2EA0, ctx->r2) = ctx->r3;
    setObjectiveTimer(rdram, ctx);
        goto after_78;
    // 0x80107B74: sw          $v1, -0x2EA0($v0)
    MEM_W(-0X2EA0, ctx->r2) = ctx->r3;
    after_78:
    // 0x80107B78: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80107B7C: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80107B80: j           L_80107E38
    // 0x80107B84: addiu       $a0, $zero, 0x179
    ctx->r4 = ADD32(0, 0X179);
        goto L_80107E38;
    // 0x80107B84: addiu       $a0, $zero, 0x179
    ctx->r4 = ADD32(0, 0X179);
L_80107B88:
    // 0x80107B88: jal         0x800C761C
    // 0x80107B8C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    getObjectiveCount(rdram, ctx);
        goto after_79;
    // 0x80107B8C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_79:
    // 0x80107B90: slti        $v0, $v0, 0x1A
    ctx->r2 = SIGNED(ctx->r2) < 0X1A ? 1 : 0;
    // 0x80107B94: bne         $v0, $zero, L_80107C50
    if (ctx->r2 != 0) {
        // 0x80107B98: nop
    
            goto L_80107C50;
    }
    // 0x80107B98: nop

    // 0x80107B9C: jal         0x800C761C
    // 0x80107BA0: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    getObjectiveCount(rdram, ctx);
        goto after_80;
    // 0x80107BA0: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    after_80:
    // 0x80107BA4: slti        $v0, $v0, 0xE
    ctx->r2 = SIGNED(ctx->r2) < 0XE ? 1 : 0;
    // 0x80107BA8: bne         $v0, $zero, L_80107C50
    if (ctx->r2 != 0) {
        // 0x80107BAC: nop
    
            goto L_80107C50;
    }
    // 0x80107BAC: nop

    // 0x80107BB0: jal         0x800C761C
    // 0x80107BB4: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    getObjectiveCount(rdram, ctx);
        goto after_81;
    // 0x80107BB4: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_81:
    // 0x80107BB8: slti        $v0, $v0, 0x4
    ctx->r2 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80107BBC: bne         $v0, $zero, L_80107C50
    if (ctx->r2 != 0) {
        // 0x80107BC0: nop
    
            goto L_80107C50;
    }
    // 0x80107BC0: nop

    // 0x80107BC4: jal         0x800C759C
    // 0x80107BC8: addiu       $a0, $zero, 0x65
    ctx->r4 = ADD32(0, 0X65);
    getObjectiveBoolean(rdram, ctx);
        goto after_82;
    // 0x80107BC8: addiu       $a0, $zero, 0x65
    ctx->r4 = ADD32(0, 0X65);
    after_82:
    // 0x80107BCC: bne         $v0, $zero, L_80107C50
    if (ctx->r2 != 0) {
        // 0x80107BD0: lui         $a1, 0x8011
        ctx->r5 = S32(0X8011 << 16);
            goto L_80107C50;
    }
    // 0x80107BD0: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80107BD4: lw          $v0, -0x2E84($a1)
    ctx->r2 = MEM_W(ctx->r5, -0X2E84);
    // 0x80107BD8: bne         $v0, $zero, L_80107C50
    if (ctx->r2 != 0) {
        // 0x80107BDC: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80107C50;
    }
    // 0x80107BDC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80107BE0: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x80107BE4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80107BE8: sw          $v1, -0x2E84($a1)
    MEM_W(-0X2E84, ctx->r5) = ctx->r3;
    // 0x80107BEC: jal         0x800C76B0
    // 0x80107BF0: sw          $v1, -0x2EA0($v0)
    MEM_W(-0X2EA0, ctx->r2) = ctx->r3;
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_83;
    // 0x80107BF0: sw          $v1, -0x2EA0($v0)
    MEM_W(-0X2EA0, ctx->r2) = ctx->r3;
    after_83:
    // 0x80107BF4: jal         0x800C76B0
    // 0x80107BF8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_84;
    // 0x80107BF8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_84:
    // 0x80107BFC: addiu       $a0, $zero, 0x65
    ctx->r4 = ADD32(0, 0X65);
    // 0x80107C00: jal         0x800C7540
    // 0x80107C04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_85;
    // 0x80107C04: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_85:
    // 0x80107C08: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80107C0C: jal         0x800C7884
    // 0x80107C10: addiu       $a0, $a0, -0x665C
    ctx->r4 = ADD32(ctx->r4, -0X665C);
    setHudFlagBit40AndStoreArg(rdram, ctx);
        goto after_86;
    // 0x80107C10: addiu       $a0, $a0, -0x665C
    ctx->r4 = ADD32(ctx->r4, -0X665C);
    after_86:
    // 0x80107C14: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80107C18: jal         0x800C76FC
    // 0x80107C1C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    setObjectiveTimer(rdram, ctx);
        goto after_87;
    // 0x80107C1C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_87:
    // 0x80107C20: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80107C24: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80107C28: jal         0x800C7D1C
    // 0x80107C2C: addiu       $a0, $zero, 0x1D7
    ctx->r4 = ADD32(0, 0X1D7);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_88;
    // 0x80107C2C: addiu       $a0, $zero, 0x1D7
    ctx->r4 = ADD32(0, 0X1D7);
    after_88:
    // 0x80107C30: jal         0x800C7D98
    // 0x80107C34: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    triggerSoundCueByType(rdram, ctx);
        goto after_89;
    // 0x80107C34: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_89:
    // 0x80107C38: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80107C3C: addiu       $a0, $a0, -0x6648
    ctx->r4 = ADD32(ctx->r4, -0X6648);
    // 0x80107C40: jal         0x800C7D60
    // 0x80107C44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    delegateToLevelStageTick(rdram, ctx);
        goto after_90;
    // 0x80107C44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_90:
    // 0x80107C48: j           L_80107E44
    // 0x80107C4C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80107E44;
    // 0x80107C4C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80107C50:
    // 0x80107C50: jal         0x800C759C
    // 0x80107C54: addiu       $a0, $zero, 0x65
    ctx->r4 = ADD32(0, 0X65);
    getObjectiveBoolean(rdram, ctx);
        goto after_91;
    // 0x80107C54: addiu       $a0, $zero, 0x65
    ctx->r4 = ADD32(0, 0X65);
    after_91:
    // 0x80107C58: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80107C5C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80107C60: bnel        $v1, $v0, L_80107CB0
    if (ctx->r3 != ctx->r2) {
        // 0x80107C64: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_80107CB0;
    }
    goto skip_2;
    // 0x80107C64: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    skip_2:
    // 0x80107C68: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80107C6C: lw          $v0, -0x2E80($a2)
    ctx->r2 = MEM_W(ctx->r6, -0X2E80);
    // 0x80107C70: bnel        $v0, $zero, L_80107CB0
    if (ctx->r2 != 0) {
        // 0x80107C74: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_80107CB0;
    }
    goto skip_3;
    // 0x80107C74: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    skip_3:
    // 0x80107C78: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80107C7C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80107C80: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80107C84: lwc1        $f20, -0x661C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X661C);
    // 0x80107C88: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80107C8C: sw          $v1, -0x2E80($a2)
    MEM_W(-0X2E80, ctx->r6) = ctx->r3;
    // 0x80107C90: jal         0x800C76FC
    // 0x80107C94: sw          $v1, -0x2EA0($v0)
    MEM_W(-0X2EA0, ctx->r2) = ctx->r3;
    setObjectiveTimer(rdram, ctx);
        goto after_92;
    // 0x80107C94: sw          $v1, -0x2EA0($v0)
    MEM_W(-0X2EA0, ctx->r2) = ctx->r3;
    after_92:
    // 0x80107C98: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80107C9C: jal         0x800C7D1C
    // 0x80107CA0: addiu       $a0, $zero, 0x17A
    ctx->r4 = ADD32(0, 0X17A);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_93;
    // 0x80107CA0: addiu       $a0, $zero, 0x17A
    ctx->r4 = ADD32(0, 0X17A);
    after_93:
    // 0x80107CA4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80107CA8: j           L_80107E38
    // 0x80107CAC: addiu       $a0, $zero, 0x1D8
    ctx->r4 = ADD32(0, 0X1D8);
        goto L_80107E38;
    // 0x80107CAC: addiu       $a0, $zero, 0x1D8
    ctx->r4 = ADD32(0, 0X1D8);
L_80107CB0:
    // 0x80107CB0: jal         0x800C7B60
    // 0x80107CB4: addiu       $a0, $a0, -0x6630
    ctx->r4 = ADD32(ctx->r4, -0X6630);
    getDatItemHealth(rdram, ctx);
        goto after_94;
    // 0x80107CB4: addiu       $a0, $a0, -0x6630
    ctx->r4 = ADD32(ctx->r4, -0X6630);
    after_94:
    // 0x80107CB8: slti        $v0, $v0, 0x3EA
    ctx->r2 = SIGNED(ctx->r2) < 0X3EA ? 1 : 0;
    // 0x80107CBC: beq         $v0, $zero, L_80107CFC
    if (ctx->r2 == 0) {
        // 0x80107CC0: lui         $a2, 0x8011
        ctx->r6 = S32(0X8011 << 16);
            goto L_80107CFC;
    }
    // 0x80107CC0: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80107CC4: lw          $v0, -0x2E7C($a2)
    ctx->r2 = MEM_W(ctx->r6, -0X2E7C);
    // 0x80107CC8: bnel        $v0, $zero, L_80107D00
    if (ctx->r2 != 0) {
        // 0x80107CCC: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_80107D00;
    }
    goto skip_4;
    // 0x80107CCC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    skip_4:
    // 0x80107CD0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80107CD4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80107CD8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80107CDC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80107CE0: sw          $v1, -0x2E7C($a2)
    MEM_W(-0X2E7C, ctx->r6) = ctx->r3;
    // 0x80107CE4: jal         0x800C76FC
    // 0x80107CE8: sw          $v1, -0x2EA0($v0)
    MEM_W(-0X2EA0, ctx->r2) = ctx->r3;
    setObjectiveTimer(rdram, ctx);
        goto after_95;
    // 0x80107CE8: sw          $v1, -0x2EA0($v0)
    MEM_W(-0X2EA0, ctx->r2) = ctx->r3;
    after_95:
    // 0x80107CEC: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80107CF0: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80107CF4: j           L_80107E38
    // 0x80107CF8: addiu       $a0, $zero, 0x1D9
    ctx->r4 = ADD32(0, 0X1D9);
        goto L_80107E38;
    // 0x80107CF8: addiu       $a0, $zero, 0x1D9
    ctx->r4 = ADD32(0, 0X1D9);
L_80107CFC:
    // 0x80107CFC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
L_80107D00:
    // 0x80107D00: jal         0x800C7B60
    // 0x80107D04: addiu       $a0, $a0, -0x6630
    ctx->r4 = ADD32(ctx->r4, -0X6630);
    getDatItemHealth(rdram, ctx);
        goto after_96;
    // 0x80107D04: addiu       $a0, $a0, -0x6630
    ctx->r4 = ADD32(ctx->r4, -0X6630);
    after_96:
    // 0x80107D08: slti        $v0, $v0, 0x322
    ctx->r2 = SIGNED(ctx->r2) < 0X322 ? 1 : 0;
    // 0x80107D0C: beq         $v0, $zero, L_80107D4C
    if (ctx->r2 == 0) {
        // 0x80107D10: lui         $a2, 0x8011
        ctx->r6 = S32(0X8011 << 16);
            goto L_80107D4C;
    }
    // 0x80107D10: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80107D14: lw          $v0, -0x2E78($a2)
    ctx->r2 = MEM_W(ctx->r6, -0X2E78);
    // 0x80107D18: bnel        $v0, $zero, L_80107D50
    if (ctx->r2 != 0) {
        // 0x80107D1C: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_80107D50;
    }
    goto skip_5;
    // 0x80107D1C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    skip_5:
    // 0x80107D20: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80107D24: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80107D28: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80107D2C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80107D30: sw          $v1, -0x2E78($a2)
    MEM_W(-0X2E78, ctx->r6) = ctx->r3;
    // 0x80107D34: jal         0x800C76FC
    // 0x80107D38: sw          $v1, -0x2EA0($v0)
    MEM_W(-0X2EA0, ctx->r2) = ctx->r3;
    setObjectiveTimer(rdram, ctx);
        goto after_97;
    // 0x80107D38: sw          $v1, -0x2EA0($v0)
    MEM_W(-0X2EA0, ctx->r2) = ctx->r3;
    after_97:
    // 0x80107D3C: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80107D40: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80107D44: j           L_80107E38
    // 0x80107D48: addiu       $a0, $zero, 0x1DA
    ctx->r4 = ADD32(0, 0X1DA);
        goto L_80107E38;
    // 0x80107D48: addiu       $a0, $zero, 0x1DA
    ctx->r4 = ADD32(0, 0X1DA);
L_80107D4C:
    // 0x80107D4C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
L_80107D50:
    // 0x80107D50: jal         0x800C7B60
    // 0x80107D54: addiu       $a0, $a0, -0x6630
    ctx->r4 = ADD32(ctx->r4, -0X6630);
    getDatItemHealth(rdram, ctx);
        goto after_98;
    // 0x80107D54: addiu       $a0, $a0, -0x6630
    ctx->r4 = ADD32(ctx->r4, -0X6630);
    after_98:
    // 0x80107D58: slti        $v0, $v0, 0x25A
    ctx->r2 = SIGNED(ctx->r2) < 0X25A ? 1 : 0;
    // 0x80107D5C: beq         $v0, $zero, L_80107D9C
    if (ctx->r2 == 0) {
        // 0x80107D60: lui         $a2, 0x8011
        ctx->r6 = S32(0X8011 << 16);
            goto L_80107D9C;
    }
    // 0x80107D60: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80107D64: lw          $v0, -0x2E74($a2)
    ctx->r2 = MEM_W(ctx->r6, -0X2E74);
    // 0x80107D68: bnel        $v0, $zero, L_80107DA0
    if (ctx->r2 != 0) {
        // 0x80107D6C: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_80107DA0;
    }
    goto skip_6;
    // 0x80107D6C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    skip_6:
    // 0x80107D70: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80107D74: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80107D78: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80107D7C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80107D80: sw          $v1, -0x2E74($a2)
    MEM_W(-0X2E74, ctx->r6) = ctx->r3;
    // 0x80107D84: jal         0x800C76FC
    // 0x80107D88: sw          $v1, -0x2EA0($v0)
    MEM_W(-0X2EA0, ctx->r2) = ctx->r3;
    setObjectiveTimer(rdram, ctx);
        goto after_99;
    // 0x80107D88: sw          $v1, -0x2EA0($v0)
    MEM_W(-0X2EA0, ctx->r2) = ctx->r3;
    after_99:
    // 0x80107D8C: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80107D90: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80107D94: j           L_80107E38
    // 0x80107D98: addiu       $a0, $zero, 0x1DC
    ctx->r4 = ADD32(0, 0X1DC);
        goto L_80107E38;
    // 0x80107D98: addiu       $a0, $zero, 0x1DC
    ctx->r4 = ADD32(0, 0X1DC);
L_80107D9C:
    // 0x80107D9C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
L_80107DA0:
    // 0x80107DA0: jal         0x800C7B60
    // 0x80107DA4: addiu       $a0, $a0, -0x6630
    ctx->r4 = ADD32(ctx->r4, -0X6630);
    getDatItemHealth(rdram, ctx);
        goto after_100;
    // 0x80107DA4: addiu       $a0, $a0, -0x6630
    ctx->r4 = ADD32(ctx->r4, -0X6630);
    after_100:
    // 0x80107DA8: slti        $v0, $v0, 0x192
    ctx->r2 = SIGNED(ctx->r2) < 0X192 ? 1 : 0;
    // 0x80107DAC: beq         $v0, $zero, L_80107DEC
    if (ctx->r2 == 0) {
        // 0x80107DB0: lui         $a2, 0x8011
        ctx->r6 = S32(0X8011 << 16);
            goto L_80107DEC;
    }
    // 0x80107DB0: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80107DB4: lw          $v0, -0x2E70($a2)
    ctx->r2 = MEM_W(ctx->r6, -0X2E70);
    // 0x80107DB8: bnel        $v0, $zero, L_80107DF0
    if (ctx->r2 != 0) {
        // 0x80107DBC: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_80107DF0;
    }
    goto skip_7;
    // 0x80107DBC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    skip_7:
    // 0x80107DC0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80107DC4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80107DC8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80107DCC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80107DD0: sw          $v1, -0x2E70($a2)
    MEM_W(-0X2E70, ctx->r6) = ctx->r3;
    // 0x80107DD4: jal         0x800C76FC
    // 0x80107DD8: sw          $v1, -0x2EA0($v0)
    MEM_W(-0X2EA0, ctx->r2) = ctx->r3;
    setObjectiveTimer(rdram, ctx);
        goto after_101;
    // 0x80107DD8: sw          $v1, -0x2EA0($v0)
    MEM_W(-0X2EA0, ctx->r2) = ctx->r3;
    after_101:
    // 0x80107DDC: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80107DE0: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80107DE4: j           L_80107E38
    // 0x80107DE8: addiu       $a0, $zero, 0x1DE
    ctx->r4 = ADD32(0, 0X1DE);
        goto L_80107E38;
    // 0x80107DE8: addiu       $a0, $zero, 0x1DE
    ctx->r4 = ADD32(0, 0X1DE);
L_80107DEC:
    // 0x80107DEC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
L_80107DF0:
    // 0x80107DF0: jal         0x800C7B60
    // 0x80107DF4: addiu       $a0, $a0, -0x6630
    ctx->r4 = ADD32(ctx->r4, -0X6630);
    getDatItemHealth(rdram, ctx);
        goto after_102;
    // 0x80107DF4: addiu       $a0, $a0, -0x6630
    ctx->r4 = ADD32(ctx->r4, -0X6630);
    after_102:
    // 0x80107DF8: slti        $v0, $v0, 0xCA
    ctx->r2 = SIGNED(ctx->r2) < 0XCA ? 1 : 0;
    // 0x80107DFC: beq         $v0, $zero, L_80107E40
    if (ctx->r2 == 0) {
        // 0x80107E00: lui         $a2, 0x8011
        ctx->r6 = S32(0X8011 << 16);
            goto L_80107E40;
    }
    // 0x80107E00: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80107E04: lw          $v0, -0x2E6C($a2)
    ctx->r2 = MEM_W(ctx->r6, -0X2E6C);
    // 0x80107E08: bne         $v0, $zero, L_80107E44
    if (ctx->r2 != 0) {
        // 0x80107E0C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80107E44;
    }
    // 0x80107E0C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80107E10: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80107E14: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80107E18: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80107E1C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80107E20: sw          $v1, -0x2E6C($a2)
    MEM_W(-0X2E6C, ctx->r6) = ctx->r3;
    // 0x80107E24: jal         0x800C76FC
    // 0x80107E28: sw          $v1, -0x2EA0($v0)
    MEM_W(-0X2EA0, ctx->r2) = ctx->r3;
    setObjectiveTimer(rdram, ctx);
        goto after_103;
    // 0x80107E28: sw          $v1, -0x2EA0($v0)
    MEM_W(-0X2EA0, ctx->r2) = ctx->r3;
    after_103:
    // 0x80107E2C: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80107E30: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80107E34: addiu       $a0, $zero, 0x1DD
    ctx->r4 = ADD32(0, 0X1DD);
L_80107E38:
    // 0x80107E38: jal         0x800C7D1C
    // 0x80107E3C: nop

    playObjectiveVoiceLine2(rdram, ctx);
        goto after_104;
    // 0x80107E3C: nop

    after_104:
L_80107E40:
    // 0x80107E40: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80107E44:
    // 0x80107E44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80107E48: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80107E4C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80107E50: jr          $ra
    // 0x80107E54: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80107E54: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void lve_80107E58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107E58: jr          $ra
    // 0x80107E5C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80107E5C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void lve_calculateFriendliesSaved(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107E60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80107E64: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80107E68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80107E6C: jal         0x800C761C
    // 0x80107E70: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    getObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x80107E70: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x80107E74: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x80107E78: jal         0x800C761C
    // 0x80107E7C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    getObjectiveCount(rdram, ctx);
        goto after_1;
    // 0x80107E7C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_1:
    // 0x80107E80: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x80107E84: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    // 0x80107E88: jal         0x800C77B0
    // 0x80107E8C: subu        $a0, $a0, $s0
    ctx->r4 = SUB32(ctx->r4, ctx->r16);
    setFriendliesSaved(rdram, ctx);
        goto after_2;
    // 0x80107E8C: subu        $a0, $a0, $s0
    ctx->r4 = SUB32(ctx->r4, ctx->r16);
    after_2:
    // 0x80107E90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80107E94: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80107E98: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80107E9C: jr          $ra
    // 0x80107EA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80107EA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void fake_func_80107EA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void lvf_initializeObjectTracking(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107EB0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80107EB4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80107EB8: addiu       $a0, $a0, -0x7C78
    ctx->r4 = ADD32(ctx->r4, -0X7C78);
    // 0x80107EBC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80107EC0: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80107EC4: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80107EC8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80107ECC: sw          $zero, -0x2E58($v0)
    MEM_W(-0X2E58, ctx->r2) = 0;
    // 0x80107ED0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80107ED4: sw          $zero, -0x2E54($v0)
    MEM_W(-0X2E54, ctx->r2) = 0;
    // 0x80107ED8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80107EDC: sw          $zero, -0x2E50($v0)
    MEM_W(-0X2E50, ctx->r2) = 0;
    // 0x80107EE0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80107EE4: sw          $zero, -0x2E60($v0)
    MEM_W(-0X2E60, ctx->r2) = 0;
    // 0x80107EE8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80107EEC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80107EF0: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80107EF4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80107EF8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80107EFC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80107F00: sw          $zero, -0x2E5C($v0)
    MEM_W(-0X2E5C, ctx->r2) = 0;
    // 0x80107F04: jal         0x800C7830
    // 0x80107F08: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_0;
    // 0x80107F08: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_0:
    // 0x80107F0C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80107F10: addiu       $a0, $a0, -0x7C50
    ctx->r4 = ADD32(ctx->r4, -0X7C50);
    // 0x80107F14: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80107F18: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80107F1C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80107F20: addu        $s2, $a3, $zero
    ctx->r18 = ADD32(ctx->r7, 0);
    // 0x80107F24: jal         0x800C7830
    // 0x80107F28: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_1;
    // 0x80107F28: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_1:
    // 0x80107F2C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80107F30: addiu       $a0, $a0, -0x7C28
    ctx->r4 = ADD32(ctx->r4, -0X7C28);
    // 0x80107F34: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80107F38: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80107F3C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80107F40: addiu       $s0, $zero, 0x5
    ctx->r16 = ADD32(0, 0X5);
    // 0x80107F44: jal         0x800C7830
    // 0x80107F48: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_2;
    // 0x80107F48: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_2:
    // 0x80107F4C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80107F50: addiu       $a0, $a0, -0x7C0C
    ctx->r4 = ADD32(ctx->r4, -0X7C0C);
    // 0x80107F54: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x80107F58: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x80107F5C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80107F60: jal         0x800C7830
    // 0x80107F64: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_3;
    // 0x80107F64: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x80107F68: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80107F6C: addiu       $a0, $a0, -0x7BD4
    ctx->r4 = ADD32(ctx->r4, -0X7BD4);
    // 0x80107F70: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80107F74: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80107F78: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // 0x80107F7C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80107F80: jal         0x800C7830
    // 0x80107F84: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_4;
    // 0x80107F84: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_4:
    // 0x80107F88: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80107F8C: addiu       $a0, $a0, -0x7BB8
    ctx->r4 = ADD32(ctx->r4, -0X7BB8);
    // 0x80107F90: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80107F94: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80107F98: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // 0x80107F9C: jal         0x800C7830
    // 0x80107FA0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_5;
    // 0x80107FA0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_5:
    // 0x80107FA4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80107FA8: addiu       $a0, $a0, -0x7B98
    ctx->r4 = ADD32(ctx->r4, -0X7B98);
    // 0x80107FAC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80107FB0: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80107FB4: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // 0x80107FB8: jal         0x800C7830
    // 0x80107FBC: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_6;
    // 0x80107FBC: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_6:
    // 0x80107FC0: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80107FC4: addiu       $s0, $s0, -0x7B78
    ctx->r16 = ADD32(ctx->r16, -0X7B78);
    // 0x80107FC8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80107FCC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80107FD0: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80107FD4: addiu       $a3, $zero, 0x78
    ctx->r7 = ADD32(0, 0X78);
    // 0x80107FD8: jal         0x800C7830
    // 0x80107FDC: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_7;
    // 0x80107FDC: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_7:
    // 0x80107FE0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80107FE4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80107FE8: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80107FEC: addiu       $a3, $zero, 0x79
    ctx->r7 = ADD32(0, 0X79);
    // 0x80107FF0: jal         0x800C7830
    // 0x80107FF4: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_8;
    // 0x80107FF4: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_8:
    // 0x80107FF8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80107FFC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80108000: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80108004: addiu       $a3, $zero, 0x7A
    ctx->r7 = ADD32(0, 0X7A);
    // 0x80108008: jal         0x800C7830
    // 0x8010800C: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_9;
    // 0x8010800C: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_9:
    // 0x80108010: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80108014: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80108018: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8010801C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80108020: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80108024: jr          $ra
    // 0x80108028: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80108028: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void lvf_checkComplexObjectives(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010802C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80108030: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80108034: mov.s       $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    ctx->f22.fl = ctx->f12.fl;
    // 0x80108038: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8010803C: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80108040: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80108044: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80108048: jal         0x800C761C
    // 0x8010804C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    getObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x8010804C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x80108050: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x80108054: jal         0x800C761C
    // 0x80108058: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    getObjectiveCount(rdram, ctx);
        goto after_1;
    // 0x80108058: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_1:
    // 0x8010805C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x80108060: jal         0x800C761C
    // 0x80108064: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    getObjectiveCount(rdram, ctx);
        goto after_2;
    // 0x80108064: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    after_2:
    // 0x80108068: addu        $s0, $s0, $s1
    ctx->r16 = ADD32(ctx->r16, ctx->r17);
    // 0x8010806C: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x80108070: lw          $v1, -0x2E58($s1)
    ctx->r3 = MEM_W(ctx->r17, -0X2E58);
    // 0x80108074: bne         $v1, $zero, L_80108238
    if (ctx->r3 != 0) {
        // 0x80108078: addu        $s0, $s0, $v0
        ctx->r16 = ADD32(ctx->r16, ctx->r2);
            goto L_80108238;
    }
    // 0x80108078: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x8010807C: jal         0x800C761C
    // 0x80108080: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    getObjectiveCount(rdram, ctx);
        goto after_3;
    // 0x80108080: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80108084: slti        $v0, $v0, 0x19
    ctx->r2 = SIGNED(ctx->r2) < 0X19 ? 1 : 0;
    // 0x80108088: bne         $v0, $zero, L_801080B0
    if (ctx->r2 != 0) {
        // 0x8010808C: nop
    
            goto L_801080B0;
    }
    // 0x8010808C: nop

    // 0x80108090: jal         0x800C7514
    // 0x80108094: nop

    func_800C7514(rdram, ctx);
        goto after_4;
    // 0x80108094: nop

    after_4:
    // 0x80108098: bne         $v0, $zero, L_801080B0
    if (ctx->r2 != 0) {
        // 0x8010809C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_801080B0;
    }
    // 0x8010809C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801080A0: jal         0x800C7738
    // 0x801080A4: sw          $v0, -0x2E58($s1)
    MEM_W(-0X2E58, ctx->r17) = ctx->r2;
    setHudEnableBit4(rdram, ctx);
        goto after_5;
    // 0x801080A4: sw          $v0, -0x2E58($s1)
    MEM_W(-0X2E58, ctx->r17) = ctx->r2;
    after_5:
    // 0x801080A8: jal         0x800C7CF8
    // 0x801080AC: addiu       $a0, $zero, 0x250
    ctx->r4 = ADD32(0, 0X250);
    playObjectiveVoiceLine1(rdram, ctx);
        goto after_6;
    // 0x801080AC: addiu       $a0, $zero, 0x250
    ctx->r4 = ADD32(0, 0X250);
    after_6:
L_801080B0:
    // 0x801080B0: jal         0x800C761C
    // 0x801080B4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    getObjectiveCount(rdram, ctx);
        goto after_7;
    // 0x801080B4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x801080B8: slti        $v0, $v0, 0x12
    ctx->r2 = SIGNED(ctx->r2) < 0X12 ? 1 : 0;
    // 0x801080BC: bne         $v0, $zero, L_801080EC
    if (ctx->r2 != 0) {
        // 0x801080C0: nop
    
            goto L_801080EC;
    }
    // 0x801080C0: nop

    // 0x801080C4: jal         0x800C7514
    // 0x801080C8: nop

    func_800C7514(rdram, ctx);
        goto after_8;
    // 0x801080C8: nop

    after_8:
    // 0x801080CC: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x801080D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801080D4: bne         $v1, $v0, L_801080EC
    if (ctx->r3 != ctx->r2) {
        // 0x801080D8: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_801080EC;
    }
    // 0x801080D8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801080DC: jal         0x800C7738
    // 0x801080E0: sw          $v1, -0x2E58($v0)
    MEM_W(-0X2E58, ctx->r2) = ctx->r3;
    setHudEnableBit4(rdram, ctx);
        goto after_9;
    // 0x801080E0: sw          $v1, -0x2E58($v0)
    MEM_W(-0X2E58, ctx->r2) = ctx->r3;
    after_9:
    // 0x801080E4: jal         0x800C7CF8
    // 0x801080E8: addiu       $a0, $zero, 0x250
    ctx->r4 = ADD32(0, 0X250);
    playObjectiveVoiceLine1(rdram, ctx);
        goto after_10;
    // 0x801080E8: addiu       $a0, $zero, 0x250
    ctx->r4 = ADD32(0, 0X250);
    after_10:
L_801080EC:
    // 0x801080EC: jal         0x800C761C
    // 0x801080F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    getObjectiveCount(rdram, ctx);
        goto after_11;
    // 0x801080F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_11:
    // 0x801080F4: slti        $v0, $v0, 0xB
    ctx->r2 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x801080F8: bne         $v0, $zero, L_80108128
    if (ctx->r2 != 0) {
        // 0x801080FC: nop
    
            goto L_80108128;
    }
    // 0x801080FC: nop

    // 0x80108100: jal         0x800C7514
    // 0x80108104: nop

    func_800C7514(rdram, ctx);
        goto after_12;
    // 0x80108104: nop

    after_12:
    // 0x80108108: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8010810C: bne         $v0, $v1, L_80108128
    if (ctx->r2 != ctx->r3) {
        // 0x80108110: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_80108128;
    }
    // 0x80108110: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80108114: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80108118: jal         0x800C7738
    // 0x8010811C: sw          $v0, -0x2E58($v1)
    MEM_W(-0X2E58, ctx->r3) = ctx->r2;
    setHudEnableBit4(rdram, ctx);
        goto after_13;
    // 0x8010811C: sw          $v0, -0x2E58($v1)
    MEM_W(-0X2E58, ctx->r3) = ctx->r2;
    after_13:
    // 0x80108120: jal         0x800C7CF8
    // 0x80108124: addiu       $a0, $zero, 0x250
    ctx->r4 = ADD32(0, 0X250);
    playObjectiveVoiceLine1(rdram, ctx);
        goto after_14;
    // 0x80108124: addiu       $a0, $zero, 0x250
    ctx->r4 = ADD32(0, 0X250);
    after_14:
L_80108128:
    // 0x80108128: jal         0x800C761C
    // 0x8010812C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    getObjectiveCount(rdram, ctx);
        goto after_15;
    // 0x8010812C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_15:
    // 0x80108130: slti        $v0, $v0, 0x9
    ctx->r2 = SIGNED(ctx->r2) < 0X9 ? 1 : 0;
    // 0x80108134: bne         $v0, $zero, L_80108164
    if (ctx->r2 != 0) {
        // 0x80108138: nop
    
            goto L_80108164;
    }
    // 0x80108138: nop

    // 0x8010813C: jal         0x800C7514
    // 0x80108140: nop

    func_800C7514(rdram, ctx);
        goto after_16;
    // 0x80108140: nop

    after_16:
    // 0x80108144: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80108148: bne         $v0, $v1, L_80108164
    if (ctx->r2 != ctx->r3) {
        // 0x8010814C: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_80108164;
    }
    // 0x8010814C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80108150: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80108154: jal         0x800C7738
    // 0x80108158: sw          $v0, -0x2E58($v1)
    MEM_W(-0X2E58, ctx->r3) = ctx->r2;
    setHudEnableBit4(rdram, ctx);
        goto after_17;
    // 0x80108158: sw          $v0, -0x2E58($v1)
    MEM_W(-0X2E58, ctx->r3) = ctx->r2;
    after_17:
    // 0x8010815C: jal         0x800C7CF8
    // 0x80108160: addiu       $a0, $zero, 0x250
    ctx->r4 = ADD32(0, 0X250);
    playObjectiveVoiceLine1(rdram, ctx);
        goto after_18;
    // 0x80108160: addiu       $a0, $zero, 0x250
    ctx->r4 = ADD32(0, 0X250);
    after_18:
L_80108164:
    // 0x80108164: jal         0x800C761C
    // 0x80108168: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    getObjectiveCount(rdram, ctx);
        goto after_19;
    // 0x80108168: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_19:
    // 0x8010816C: slti        $v0, $v0, 0x3
    ctx->r2 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80108170: bne         $v0, $zero, L_8010819C
    if (ctx->r2 != 0) {
        // 0x80108174: lui         $s1, 0x8011
        ctx->r17 = S32(0X8011 << 16);
            goto L_8010819C;
    }
    // 0x80108174: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x80108178: addiu       $v0, $zero, 0x14
    ctx->r2 = ADD32(0, 0X14);
    // 0x8010817C: bne         $s0, $v0, L_8010819C
    if (ctx->r16 != ctx->r2) {
        // 0x80108180: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_8010819C;
    }
    // 0x80108180: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80108184: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80108188: jal         0x800C776C
    // 0x8010818C: sw          $v0, -0x2E58($v1)
    MEM_W(-0X2E58, ctx->r3) = ctx->r2;
    setHudEnableBit8(rdram, ctx);
        goto after_20;
    // 0x8010818C: sw          $v0, -0x2E58($v1)
    MEM_W(-0X2E58, ctx->r3) = ctx->r2;
    after_20:
    // 0x80108190: jal         0x800C76B0
    // 0x80108194: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_21;
    // 0x80108194: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_21:
    // 0x80108198: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
L_8010819C:
    // 0x8010819C: lw          $v0, -0x2E54($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X2E54);
    // 0x801081A0: bnel        $v0, $zero, L_801081EC
    if (ctx->r2 != 0) {
        // 0x801081A4: lui         $s1, 0x8011
        ctx->r17 = S32(0X8011 << 16);
            goto L_801081EC;
    }
    goto skip_0;
    // 0x801081A4: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    skip_0:
    // 0x801081A8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x801081AC: jal         0x800C78A0
    // 0x801081B0: addiu       $a0, $a0, -0x6610
    ctx->r4 = ADD32(ctx->r4, -0X6610);
    calculateDatItemDistanceToPlayer(rdram, ctx);
        goto after_22;
    // 0x801081B0: addiu       $a0, $a0, -0x6610
    ctx->r4 = ADD32(ctx->r4, -0X6610);
    after_22:
    // 0x801081B4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x801081B8: lwc1        $f2, -0x6604($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6604);
    // 0x801081BC: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x801081C0: nop

    // 0x801081C4: bc1f        L_801081E8
    if (!c1cs) {
        // 0x801081C8: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_801081E8;
    }
    // 0x801081C8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x801081CC: addiu       $a0, $zero, 0x270
    ctx->r4 = ADD32(0, 0X270);
    // 0x801081D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801081D4: jal         0x800C7D1C
    // 0x801081D8: sw          $v0, -0x2E54($s1)
    MEM_W(-0X2E54, ctx->r17) = ctx->r2;
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_23;
    // 0x801081D8: sw          $v0, -0x2E54($s1)
    MEM_W(-0X2E54, ctx->r17) = ctx->r2;
    after_23:
    // 0x801081DC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x801081E0: jal         0x800C7D1C
    // 0x801081E4: addiu       $a0, $zero, 0x2AE
    ctx->r4 = ADD32(0, 0X2AE);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_24;
    // 0x801081E4: addiu       $a0, $zero, 0x2AE
    ctx->r4 = ADD32(0, 0X2AE);
    after_24:
L_801081E8:
    // 0x801081E8: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
L_801081EC:
    // 0x801081EC: lw          $v0, -0x2E50($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X2E50);
    // 0x801081F0: bne         $v0, $zero, L_80108238
    if (ctx->r2 != 0) {
        // 0x801081F4: slti        $v0, $s0, 0x14
        ctx->r2 = SIGNED(ctx->r16) < 0X14 ? 1 : 0;
            goto L_80108238;
    }
    // 0x801081F4: slti        $v0, $s0, 0x14
    ctx->r2 = SIGNED(ctx->r16) < 0X14 ? 1 : 0;
    // 0x801081F8: beq         $v0, $zero, L_80108238
    if (ctx->r2 == 0) {
        // 0x801081FC: nop
    
            goto L_80108238;
    }
    // 0x801081FC: nop

    // 0x80108200: jal         0x800C761C
    // 0x80108204: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    getObjectiveCount(rdram, ctx);
        goto after_25;
    // 0x80108204: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_25:
    // 0x80108208: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x8010820C: bne         $v0, $v1, L_80108238
    if (ctx->r2 != ctx->r3) {
        // 0x80108210: addiu       $a0, $zero, 0x24F
        ctx->r4 = ADD32(0, 0X24F);
            goto L_80108238;
    }
    // 0x80108210: addiu       $a0, $zero, 0x24F
    ctx->r4 = ADD32(0, 0X24F);
    // 0x80108214: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80108218: lwc1        $f20, -0x6600($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X6600);
    // 0x8010821C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80108220: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80108224: jal         0x800C7D1C
    // 0x80108228: sw          $v0, -0x2E50($s1)
    MEM_W(-0X2E50, ctx->r17) = ctx->r2;
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_26;
    // 0x80108228: sw          $v0, -0x2E50($s1)
    MEM_W(-0X2E50, ctx->r17) = ctx->r2;
    after_26:
    // 0x8010822C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80108230: jal         0x800C7D1C
    // 0x80108234: addiu       $a0, $zero, 0x2AD
    ctx->r4 = ADD32(0, 0X2AD);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_27;
    // 0x80108234: addiu       $a0, $zero, 0x2AD
    ctx->r4 = ADD32(0, 0X2AD);
    after_27:
L_80108238:
    // 0x80108238: jal         0x80108260
    // 0x8010823C: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    func_80108260(rdram, ctx);
        goto after_28;
    // 0x8010823C: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_28:
    // 0x80108240: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80108244: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80108248: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8010824C: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80108250: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80108254: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80108258: jr          $ra
    // 0x8010825C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8010825C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80108260(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108260: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80108264: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80108268: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x8010826C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80108270: jal         0x800C761C
    // 0x80108274: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    getObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x80108274: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    after_0:
    // 0x80108278: bne         $v0, $zero, L_80108288
    if (ctx->r2 != 0) {
        // 0x8010827C: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_80108288;
    }
    // 0x8010827C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80108280: j           L_801082D8
    // 0x80108284: addiu       $a0, $a0, -0x6610
    ctx->r4 = ADD32(ctx->r4, -0X6610);
        goto L_801082D8;
    // 0x80108284: addiu       $a0, $a0, -0x6610
    ctx->r4 = ADD32(ctx->r4, -0X6610);
L_80108288:
    // 0x80108288: jal         0x800C761C
    // 0x8010828C: addiu       $a0, $zero, 0x79
    ctx->r4 = ADD32(0, 0X79);
    getObjectiveCount(rdram, ctx);
        goto after_1;
    // 0x8010828C: addiu       $a0, $zero, 0x79
    ctx->r4 = ADD32(0, 0X79);
    after_1:
    // 0x80108290: bne         $v0, $zero, L_801082A0
    if (ctx->r2 != 0) {
        // 0x80108294: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_801082A0;
    }
    // 0x80108294: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80108298: j           L_801082D8
    // 0x8010829C: addiu       $a0, $a0, -0x65FC
    ctx->r4 = ADD32(ctx->r4, -0X65FC);
        goto L_801082D8;
    // 0x8010829C: addiu       $a0, $a0, -0x65FC
    ctx->r4 = ADD32(ctx->r4, -0X65FC);
L_801082A0:
    // 0x801082A0: jal         0x800C761C
    // 0x801082A4: addiu       $a0, $zero, 0x7A
    ctx->r4 = ADD32(0, 0X7A);
    getObjectiveCount(rdram, ctx);
        goto after_2;
    // 0x801082A4: addiu       $a0, $zero, 0x7A
    ctx->r4 = ADD32(0, 0X7A);
    after_2:
    // 0x801082A8: beq         $v0, $zero, L_801082D0
    if (ctx->r2 == 0) {
        // 0x801082AC: lui         $a0, 0x8011
        ctx->r4 = S32(0X8011 << 16);
            goto L_801082D0;
    }
    // 0x801082AC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x801082B0: lw          $v0, -0x2E60($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X2E60);
    // 0x801082B4: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x801082B8: beq         $v0, $v1, L_80108378
    if (ctx->r2 == ctx->r3) {
        // 0x801082BC: addu        $a1, $v1, $zero
        ctx->r5 = ADD32(ctx->r3, 0);
            goto L_80108378;
    }
    // 0x801082BC: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    // 0x801082C0: sw          $v1, -0x2E60($a0)
    MEM_W(-0X2E60, ctx->r4) = ctx->r3;
    // 0x801082C4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x801082C8: j           L_80108370
    // 0x801082CC: addiu       $a0, $a0, -0x65E4
    ctx->r4 = ADD32(ctx->r4, -0X65E4);
        goto L_80108370;
    // 0x801082CC: addiu       $a0, $a0, -0x65E4
    ctx->r4 = ADD32(ctx->r4, -0X65E4);
L_801082D0:
    // 0x801082D0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x801082D4: addiu       $a0, $a0, -0x65F0
    ctx->r4 = ADD32(ctx->r4, -0X65F0);
L_801082D8:
    // 0x801082D8: jal         0x800C78A0
    // 0x801082DC: nop

    calculateDatItemDistanceToPlayer(rdram, ctx);
        goto after_3;
    // 0x801082DC: nop

    after_3:
    // 0x801082E0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x801082E4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x801082E8: lwc1        $f0, -0x65CC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X65CC);
    // 0x801082EC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x801082F0: nop

    // 0x801082F4: bc1f        L_80108334
    if (!c1cs) {
        // 0x801082F8: lui         $a0, 0x8011
        ctx->r4 = S32(0X8011 << 16);
            goto L_80108334;
    }
    // 0x801082F8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x801082FC: lw          $v0, -0x2E60($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X2E60);
    // 0x80108300: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80108304: beq         $v0, $v1, L_80108320
    if (ctx->r2 == ctx->r3) {
        // 0x80108308: nop
    
            goto L_80108320;
    }
    // 0x80108308: nop

    // 0x8010830C: sw          $v1, -0x2E60($a0)
    MEM_W(-0X2E60, ctx->r4) = ctx->r3;
    // 0x80108310: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80108314: addiu       $a0, $a0, -0x65E4
    ctx->r4 = ADD32(ctx->r4, -0X65E4);
    // 0x80108318: jal         0x800C7D60
    // 0x8010831C: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    delegateToLevelStageTick(rdram, ctx);
        goto after_4;
    // 0x8010831C: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    after_4:
L_80108320:
    // 0x80108320: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80108324: lwc1        $f0, -0x65C8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X65C8);
    // 0x80108328: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8010832C: j           L_80108378
    // 0x80108330: swc1        $f0, -0x2E5C($v0)
    MEM_W(-0X2E5C, ctx->r2) = ctx->f0.u32l;
        goto L_80108378;
    // 0x80108330: swc1        $f0, -0x2E5C($v0)
    MEM_W(-0X2E5C, ctx->r2) = ctx->f0.u32l;
L_80108334:
    // 0x80108334: lw          $v1, -0x2E60($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X2E60);
    // 0x80108338: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8010833C: bne         $v1, $v0, L_80108378
    if (ctx->r3 != ctx->r2) {
        // 0x80108340: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_80108378;
    }
    // 0x80108340: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80108344: lwc1        $f0, -0x2E5C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X2E5C);
    // 0x80108348: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x8010834C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80108350: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80108354: nop

    // 0x80108358: bc1f        L_80108378
    if (!c1cs) {
        // 0x8010835C: swc1        $f0, -0x2E5C($v0)
        MEM_W(-0X2E5C, ctx->r2) = ctx->f0.u32l;
            goto L_80108378;
    }
    // 0x8010835C: swc1        $f0, -0x2E5C($v0)
    MEM_W(-0X2E5C, ctx->r2) = ctx->f0.u32l;
    // 0x80108360: sw          $zero, -0x2E60($a0)
    MEM_W(-0X2E60, ctx->r4) = 0;
    // 0x80108364: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80108368: addiu       $a0, $a0, -0x65E4
    ctx->r4 = ADD32(ctx->r4, -0X65E4);
    // 0x8010836C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_80108370:
    // 0x80108370: jal         0x800C7D60
    // 0x80108374: nop

    delegateToLevelStageTick(rdram, ctx);
        goto after_5;
    // 0x80108374: nop

    after_5:
L_80108378:
    // 0x80108378: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8010837C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80108380: jr          $ra
    // 0x80108384: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80108384: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void playVoice_0x1FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108388: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010838C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80108390: jal         0x800C7CF8
    // 0x80108394: addiu       $a0, $zero, 0x1FC
    ctx->r4 = ADD32(0, 0X1FC);
    playObjectiveVoiceLine1(rdram, ctx);
        goto after_0;
    // 0x80108394: addiu       $a0, $zero, 0x1FC
    ctx->r4 = ADD32(0, 0X1FC);
    after_0:
    // 0x80108398: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8010839C: jal         0x800C7540
    // 0x801083A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_1;
    // 0x801083A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x801083A4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801083A8: jr          $ra
    // 0x801083AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801083AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice_0x1EB(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801083B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801083B4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801083B8: jal         0x800C7CF8
    // 0x801083BC: addiu       $a0, $zero, 0x1EB
    ctx->r4 = ADD32(0, 0X1EB);
    playObjectiveVoiceLine1(rdram, ctx);
        goto after_0;
    // 0x801083BC: addiu       $a0, $zero, 0x1EB
    ctx->r4 = ADD32(0, 0X1EB);
    after_0:
    // 0x801083C0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x801083C4: jal         0x800C7540
    // 0x801083C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_1;
    // 0x801083C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x801083CC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801083D0: jr          $ra
    // 0x801083D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801083D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice_0x230(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801083D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801083DC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801083E0: jal         0x800C7CF8
    // 0x801083E4: addiu       $a0, $zero, 0x230
    ctx->r4 = ADD32(0, 0X230);
    playObjectiveVoiceLine1(rdram, ctx);
        goto after_0;
    // 0x801083E4: addiu       $a0, $zero, 0x230
    ctx->r4 = ADD32(0, 0X230);
    after_0:
    // 0x801083E8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801083EC: jr          $ra
    // 0x801083F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801083F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv11_playPairedDialogue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801083F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801083F8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801083FC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80108400: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80108404: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80108408: jal         0x800C7D1C
    // 0x8010840C: addiu       $a0, $zero, 0x2AF
    ctx->r4 = ADD32(0, 0X2AF);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x8010840C: addiu       $a0, $zero, 0x2AF
    ctx->r4 = ADD32(0, 0X2AF);
    after_0:
    // 0x80108410: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80108414: jal         0x800C7D1C
    // 0x80108418: addiu       $a0, $zero, 0x2B0
    ctx->r4 = ADD32(0, 0X2B0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x80108418: addiu       $a0, $zero, 0x2B0
    ctx->r4 = ADD32(0, 0X2B0);
    after_1:
    // 0x8010841C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80108420: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80108424: jr          $ra
    // 0x80108428: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80108428: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void playVoice_0x48(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010842C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80108430: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80108434: jal         0x800C7CF8
    // 0x80108438: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    playObjectiveVoiceLine1(rdram, ctx);
        goto after_0;
    // 0x80108438: addiu       $a0, $zero, 0x48
    ctx->r4 = ADD32(0, 0X48);
    after_0:
    // 0x8010843C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80108440: jr          $ra
    // 0x80108444: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80108444: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice2_0x293(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108448: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010844C: addiu       $a0, $zero, 0x293
    ctx->r4 = ADD32(0, 0X293);
    // 0x80108450: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80108454: jal         0x800C7D1C
    // 0x80108458: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80108458: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x8010845C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80108460: jr          $ra
    // 0x80108464: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80108464: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice2_0x0BA(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108468: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010846C: addiu       $a0, $zero, 0xBA
    ctx->r4 = ADD32(0, 0XBA);
    // 0x80108470: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80108474: jal         0x800C7D1C
    // 0x80108478: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80108478: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x8010847C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80108480: jr          $ra
    // 0x80108484: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80108484: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice_0x26B(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108488: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8010848C: jr          $ra
    // 0x80108490: sw          $zero, -0x2E5C($v0)
    MEM_W(-0X2E5C, ctx->r2) = 0;
    return;
    // 0x80108490: sw          $zero, -0x2E5C($v0)
    MEM_W(-0X2E5C, ctx->r2) = 0;
;}
RECOMP_FUNC void lvf_80108494(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108494: jr          $ra
    // 0x80108498: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80108498: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void lvf_calculateFriendliesSaved(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010849C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801084A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801084A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801084A8: jal         0x800C761C
    // 0x801084AC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    getObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x801084AC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x801084B0: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x801084B4: jal         0x800C761C
    // 0x801084B8: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    getObjectiveCount(rdram, ctx);
        goto after_1;
    // 0x801084B8: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_1:
    // 0x801084BC: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x801084C0: addiu       $a0, $zero, 0x5C
    ctx->r4 = ADD32(0, 0X5C);
    // 0x801084C4: jal         0x800C77B0
    // 0x801084C8: subu        $a0, $a0, $s0
    ctx->r4 = SUB32(ctx->r4, ctx->r16);
    setFriendliesSaved(rdram, ctx);
        goto after_2;
    // 0x801084C8: subu        $a0, $a0, $s0
    ctx->r4 = SUB32(ctx->r4, ctx->r16);
    after_2:
    // 0x801084CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801084D0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x801084D4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x801084D8: jr          $ra
    // 0x801084DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801084DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lvg_checkComplexObjectives(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801084E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801084E4: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x801084E8: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x801084EC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x801084F0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x801084F4: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x801084F8: jal         0x800C77A0
    // 0x801084FC: mov.s       $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    ctx->f22.fl = ctx->f12.fl;
    func_800C77A0(rdram, ctx);
        goto after_0;
    // 0x801084FC: mov.s       $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    ctx->f22.fl = ctx->f12.fl;
    after_0:
    // 0x80108500: bne         $v0, $zero, L_80108564
    if (ctx->r2 != 0) {
        // 0x80108504: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_80108564;
    }
    // 0x80108504: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80108508: lw          $v0, -0x2E38($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X2E38);
    // 0x8010850C: bne         $v0, $zero, L_80108564
    if (ctx->r2 != 0) {
        // 0x80108510: addiu       $a0, $zero, 0x17E
        ctx->r4 = ADD32(0, 0X17E);
            goto L_80108564;
    }
    // 0x80108510: addiu       $a0, $zero, 0x17E
    ctx->r4 = ADD32(0, 0X17E);
    // 0x80108514: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80108518: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8010851C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80108520: jal         0x800C7D1C
    // 0x80108524: sw          $v0, -0x2E38($v1)
    MEM_W(-0X2E38, ctx->r3) = ctx->r2;
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x80108524: sw          $v0, -0x2E38($v1)
    MEM_W(-0X2E38, ctx->r3) = ctx->r2;
    after_1:
    // 0x80108528: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8010852C: jal         0x800C7D1C
    // 0x80108530: addiu       $a0, $zero, 0x17F
    ctx->r4 = ADD32(0, 0X17F);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_2;
    // 0x80108530: addiu       $a0, $zero, 0x17F
    ctx->r4 = ADD32(0, 0X17F);
    after_2:
    // 0x80108534: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80108538: jal         0x800C7D1C
    // 0x8010853C: addiu       $a0, $zero, 0x26A
    ctx->r4 = ADD32(0, 0X26A);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_3;
    // 0x8010853C: addiu       $a0, $zero, 0x26A
    ctx->r4 = ADD32(0, 0X26A);
    after_3:
    // 0x80108540: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80108544: jal         0x800C7D1C
    // 0x80108548: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_4;
    // 0x80108548: addiu       $a0, $zero, 0x39
    ctx->r4 = ADD32(0, 0X39);
    after_4:
    // 0x8010854C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80108550: jal         0x800C7D1C
    // 0x80108554: addiu       $a0, $zero, 0x180
    ctx->r4 = ADD32(0, 0X180);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_5;
    // 0x80108554: addiu       $a0, $zero, 0x180
    ctx->r4 = ADD32(0, 0X180);
    after_5:
    // 0x80108558: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8010855C: jal         0x800C7D1C
    // 0x80108560: addiu       $a0, $zero, 0x252
    ctx->r4 = ADD32(0, 0X252);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_6;
    // 0x80108560: addiu       $a0, $zero, 0x252
    ctx->r4 = ADD32(0, 0X252);
    after_6:
L_80108564:
    // 0x80108564: jal         0x800C759C
    // 0x80108568: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    getObjectiveBoolean(rdram, ctx);
        goto after_7;
    // 0x80108568: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_7:
    // 0x8010856C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80108570: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80108574: bne         $s0, $v0, L_801085F0
    if (ctx->r16 != ctx->r2) {
        // 0x80108578: nop
    
            goto L_801085F0;
    }
    // 0x80108578: nop

    // 0x8010857C: jal         0x800C759C
    // 0x80108580: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    getObjectiveBoolean(rdram, ctx);
        goto after_8;
    // 0x80108580: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_8:
    // 0x80108584: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80108588: bne         $s1, $s0, L_801085F0
    if (ctx->r17 != ctx->r16) {
        // 0x8010858C: lui         $s0, 0x8011
        ctx->r16 = S32(0X8011 << 16);
            goto L_801085F0;
    }
    // 0x8010858C: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80108590: lw          $v0, -0x2E34($s0)
    ctx->r2 = MEM_W(ctx->r16, -0X2E34);
    // 0x80108594: bne         $v0, $zero, L_801085F0
    if (ctx->r2 != 0) {
        // 0x80108598: nop
    
            goto L_801085F0;
    }
    // 0x80108598: nop

    // 0x8010859C: jal         0x800C776C
    // 0x801085A0: nop

    setHudEnableBit8(rdram, ctx);
        goto after_9;
    // 0x801085A0: nop

    after_9:
    // 0x801085A4: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x801085A8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801085AC: jal         0x800C7884
    // 0x801085B0: addiu       $a0, $a0, -0x65C0
    ctx->r4 = ADD32(ctx->r4, -0X65C0);
    setHudFlagBit40AndStoreArg(rdram, ctx);
        goto after_10;
    // 0x801085B0: addiu       $a0, $a0, -0x65C0
    ctx->r4 = ADD32(ctx->r4, -0X65C0);
    after_10:
    // 0x801085B4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801085B8: jal         0x800C7D1C
    // 0x801085BC: addiu       $a0, $zero, 0x182
    ctx->r4 = ADD32(0, 0X182);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_11;
    // 0x801085BC: addiu       $a0, $zero, 0x182
    ctx->r4 = ADD32(0, 0X182);
    after_11:
    // 0x801085C0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801085C4: jal         0x800C7D1C
    // 0x801085C8: addiu       $a0, $zero, 0x253
    ctx->r4 = ADD32(0, 0X253);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_12;
    // 0x801085C8: addiu       $a0, $zero, 0x253
    ctx->r4 = ADD32(0, 0X253);
    after_12:
    // 0x801085CC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801085D0: jal         0x800C7D1C
    // 0x801085D4: addiu       $a0, $zero, 0x148
    ctx->r4 = ADD32(0, 0X148);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_13;
    // 0x801085D4: addiu       $a0, $zero, 0x148
    ctx->r4 = ADD32(0, 0X148);
    after_13:
    // 0x801085D8: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x801085DC: jal         0x800C7540
    // 0x801085E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_14;
    // 0x801085E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x801085E4: jal         0x800C77B0
    // 0x801085E8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    setFriendliesSaved(rdram, ctx);
        goto after_15;
    // 0x801085E8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_15:
    // 0x801085EC: sw          $s1, -0x2E34($s0)
    MEM_W(-0X2E34, ctx->r16) = ctx->r17;
L_801085F0:
    // 0x801085F0: jal         0x800C759C
    // 0x801085F4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    getObjectiveBoolean(rdram, ctx);
        goto after_16;
    // 0x801085F4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_16:
    // 0x801085F8: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x801085FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80108600: bne         $s0, $v0, L_80108660
    if (ctx->r16 != ctx->r2) {
        // 0x80108604: nop
    
            goto L_80108660;
    }
    // 0x80108604: nop

    // 0x80108608: jal         0x800C759C
    // 0x8010860C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    getObjectiveBoolean(rdram, ctx);
        goto after_17;
    // 0x8010860C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_17:
    // 0x80108610: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80108614: bne         $s1, $s0, L_80108660
    if (ctx->r17 != ctx->r16) {
        // 0x80108618: lui         $s0, 0x8011
        ctx->r16 = S32(0X8011 << 16);
            goto L_80108660;
    }
    // 0x80108618: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x8010861C: lw          $v0, -0x2E34($s0)
    ctx->r2 = MEM_W(ctx->r16, -0X2E34);
    // 0x80108620: bne         $v0, $zero, L_80108660
    if (ctx->r2 != 0) {
        // 0x80108624: nop
    
            goto L_80108660;
    }
    // 0x80108624: nop

    // 0x80108628: jal         0x800C776C
    // 0x8010862C: nop

    setHudEnableBit8(rdram, ctx);
        goto after_18;
    // 0x8010862C: nop

    after_18:
    // 0x80108630: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80108634: jal         0x800C7884
    // 0x80108638: addiu       $a0, $a0, -0x65C0
    ctx->r4 = ADD32(ctx->r4, -0X65C0);
    setHudFlagBit40AndStoreArg(rdram, ctx);
        goto after_19;
    // 0x80108638: addiu       $a0, $a0, -0x65C0
    ctx->r4 = ADD32(ctx->r4, -0X65C0);
    after_19:
    // 0x8010863C: addiu       $a0, $zero, 0x181
    ctx->r4 = ADD32(0, 0X181);
    // 0x80108640: jal         0x800C7D1C
    // 0x80108644: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_20;
    // 0x80108644: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_20:
    // 0x80108648: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x8010864C: jal         0x800C7540
    // 0x80108650: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_21;
    // 0x80108650: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_21:
    // 0x80108654: jal         0x800C77B0
    // 0x80108658: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    setFriendliesSaved(rdram, ctx);
        goto after_22;
    // 0x80108658: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_22:
    // 0x8010865C: sw          $s1, -0x2E34($s0)
    MEM_W(-0X2E34, ctx->r16) = ctx->r17;
L_80108660:
    // 0x80108660: jal         0x800C759C
    // 0x80108664: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    getObjectiveBoolean(rdram, ctx);
        goto after_23;
    // 0x80108664: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_23:
    // 0x80108668: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8010866C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80108670: bne         $s0, $v0, L_801086D0
    if (ctx->r16 != ctx->r2) {
        // 0x80108674: nop
    
            goto L_801086D0;
    }
    // 0x80108674: nop

    // 0x80108678: jal         0x800C759C
    // 0x8010867C: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    getObjectiveBoolean(rdram, ctx);
        goto after_24;
    // 0x8010867C: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_24:
    // 0x80108680: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80108684: bne         $s1, $s0, L_801086D0
    if (ctx->r17 != ctx->r16) {
        // 0x80108688: lui         $s0, 0x8011
        ctx->r16 = S32(0X8011 << 16);
            goto L_801086D0;
    }
    // 0x80108688: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x8010868C: lw          $v0, -0x2E34($s0)
    ctx->r2 = MEM_W(ctx->r16, -0X2E34);
    // 0x80108690: bne         $v0, $zero, L_801086D0
    if (ctx->r2 != 0) {
        // 0x80108694: nop
    
            goto L_801086D0;
    }
    // 0x80108694: nop

    // 0x80108698: jal         0x800C776C
    // 0x8010869C: nop

    setHudEnableBit8(rdram, ctx);
        goto after_25;
    // 0x8010869C: nop

    after_25:
    // 0x801086A0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x801086A4: jal         0x800C7884
    // 0x801086A8: addiu       $a0, $a0, -0x65C0
    ctx->r4 = ADD32(ctx->r4, -0X65C0);
    setHudFlagBit40AndStoreArg(rdram, ctx);
        goto after_26;
    // 0x801086A8: addiu       $a0, $a0, -0x65C0
    ctx->r4 = ADD32(ctx->r4, -0X65C0);
    after_26:
    // 0x801086AC: addiu       $a0, $zero, 0x181
    ctx->r4 = ADD32(0, 0X181);
    // 0x801086B0: jal         0x800C7D1C
    // 0x801086B4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_27;
    // 0x801086B4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_27:
    // 0x801086B8: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x801086BC: jal         0x800C7540
    // 0x801086C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_28;
    // 0x801086C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_28:
    // 0x801086C4: jal         0x800C77B0
    // 0x801086C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    setFriendliesSaved(rdram, ctx);
        goto after_29;
    // 0x801086C8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_29:
    // 0x801086CC: sw          $s1, -0x2E34($s0)
    MEM_W(-0X2E34, ctx->r16) = ctx->r17;
L_801086D0:
    // 0x801086D0: jal         0x800C759C
    // 0x801086D4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    getObjectiveBoolean(rdram, ctx);
        goto after_30;
    // 0x801086D4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_30:
    // 0x801086D8: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x801086DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801086E0: bne         $s0, $v0, L_80108740
    if (ctx->r16 != ctx->r2) {
        // 0x801086E4: nop
    
            goto L_80108740;
    }
    // 0x801086E4: nop

    // 0x801086E8: jal         0x800C759C
    // 0x801086EC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    getObjectiveBoolean(rdram, ctx);
        goto after_31;
    // 0x801086EC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_31:
    // 0x801086F0: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x801086F4: bne         $s1, $s0, L_80108740
    if (ctx->r17 != ctx->r16) {
        // 0x801086F8: lui         $s0, 0x8011
        ctx->r16 = S32(0X8011 << 16);
            goto L_80108740;
    }
    // 0x801086F8: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x801086FC: lw          $v0, -0x2E34($s0)
    ctx->r2 = MEM_W(ctx->r16, -0X2E34);
    // 0x80108700: bne         $v0, $zero, L_80108740
    if (ctx->r2 != 0) {
        // 0x80108704: nop
    
            goto L_80108740;
    }
    // 0x80108704: nop

    // 0x80108708: jal         0x800C7738
    // 0x8010870C: nop

    setHudEnableBit4(rdram, ctx);
        goto after_32;
    // 0x8010870C: nop

    after_32:
    // 0x80108710: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80108714: jal         0x800C7884
    // 0x80108718: addiu       $a0, $a0, -0x65B4
    ctx->r4 = ADD32(ctx->r4, -0X65B4);
    setHudFlagBit40AndStoreArg(rdram, ctx);
        goto after_33;
    // 0x80108718: addiu       $a0, $a0, -0x65B4
    ctx->r4 = ADD32(ctx->r4, -0X65B4);
    after_33:
    // 0x8010871C: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    // 0x80108720: jal         0x800C7D1C
    // 0x80108724: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_34;
    // 0x80108724: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_34:
    // 0x80108728: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8010872C: jal         0x800C7540
    // 0x80108730: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_35;
    // 0x80108730: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_35:
    // 0x80108734: jal         0x800C77B0
    // 0x80108738: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    setFriendliesSaved(rdram, ctx);
        goto after_36;
    // 0x80108738: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_36:
    // 0x8010873C: sw          $s1, -0x2E34($s0)
    MEM_W(-0X2E34, ctx->r16) = ctx->r17;
L_80108740:
    // 0x80108740: jal         0x800C759C
    // 0x80108744: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    getObjectiveBoolean(rdram, ctx);
        goto after_37;
    // 0x80108744: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_37:
    // 0x80108748: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8010874C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80108750: bne         $s0, $v0, L_801087B0
    if (ctx->r16 != ctx->r2) {
        // 0x80108754: nop
    
            goto L_801087B0;
    }
    // 0x80108754: nop

    // 0x80108758: jal         0x800C759C
    // 0x8010875C: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    getObjectiveBoolean(rdram, ctx);
        goto after_38;
    // 0x8010875C: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_38:
    // 0x80108760: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x80108764: bne         $s1, $s0, L_801087B0
    if (ctx->r17 != ctx->r16) {
        // 0x80108768: lui         $s0, 0x8011
        ctx->r16 = S32(0X8011 << 16);
            goto L_801087B0;
    }
    // 0x80108768: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x8010876C: lw          $v0, -0x2E34($s0)
    ctx->r2 = MEM_W(ctx->r16, -0X2E34);
    // 0x80108770: bne         $v0, $zero, L_801087B0
    if (ctx->r2 != 0) {
        // 0x80108774: nop
    
            goto L_801087B0;
    }
    // 0x80108774: nop

    // 0x80108778: jal         0x800C7738
    // 0x8010877C: nop

    setHudEnableBit4(rdram, ctx);
        goto after_39;
    // 0x8010877C: nop

    after_39:
    // 0x80108780: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80108784: jal         0x800C7884
    // 0x80108788: addiu       $a0, $a0, -0x65B4
    ctx->r4 = ADD32(ctx->r4, -0X65B4);
    setHudFlagBit40AndStoreArg(rdram, ctx);
        goto after_40;
    // 0x80108788: addiu       $a0, $a0, -0x65B4
    ctx->r4 = ADD32(ctx->r4, -0X65B4);
    after_40:
    // 0x8010878C: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    // 0x80108790: jal         0x800C7D1C
    // 0x80108794: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_41;
    // 0x80108794: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_41:
    // 0x80108798: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8010879C: jal         0x800C7540
    // 0x801087A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_42;
    // 0x801087A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_42:
    // 0x801087A4: jal         0x800C77B0
    // 0x801087A8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    setFriendliesSaved(rdram, ctx);
        goto after_43;
    // 0x801087A8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_43:
    // 0x801087AC: sw          $s1, -0x2E34($s0)
    MEM_W(-0X2E34, ctx->r16) = ctx->r17;
L_801087B0:
    // 0x801087B0: jal         0x800C759C
    // 0x801087B4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    getObjectiveBoolean(rdram, ctx);
        goto after_44;
    // 0x801087B4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_44:
    // 0x801087B8: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x801087BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801087C0: bne         $s0, $v0, L_80108830
    if (ctx->r16 != ctx->r2) {
        // 0x801087C4: nop
    
            goto L_80108830;
    }
    // 0x801087C4: nop

    // 0x801087C8: jal         0x800C759C
    // 0x801087CC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    getObjectiveBoolean(rdram, ctx);
        goto after_45;
    // 0x801087CC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_45:
    // 0x801087D0: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x801087D4: bne         $s1, $s0, L_80108830
    if (ctx->r17 != ctx->r16) {
        // 0x801087D8: lui         $s0, 0x8011
        ctx->r16 = S32(0X8011 << 16);
            goto L_80108830;
    }
    // 0x801087D8: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x801087DC: lw          $v0, -0x2E34($s0)
    ctx->r2 = MEM_W(ctx->r16, -0X2E34);
    // 0x801087E0: bne         $v0, $zero, L_80108830
    if (ctx->r2 != 0) {
        // 0x801087E4: nop
    
            goto L_80108830;
    }
    // 0x801087E4: nop

    // 0x801087E8: jal         0x800C7738
    // 0x801087EC: nop

    setHudEnableBit4(rdram, ctx);
        goto after_46;
    // 0x801087EC: nop

    after_46:
    // 0x801087F0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x801087F4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801087F8: jal         0x800C7884
    // 0x801087FC: addiu       $a0, $a0, -0x65B4
    ctx->r4 = ADD32(ctx->r4, -0X65B4);
    setHudFlagBit40AndStoreArg(rdram, ctx);
        goto after_47;
    // 0x801087FC: addiu       $a0, $a0, -0x65B4
    ctx->r4 = ADD32(ctx->r4, -0X65B4);
    after_47:
    // 0x80108800: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80108804: jal         0x800C7D1C
    // 0x80108808: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_48;
    // 0x80108808: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    after_48:
    // 0x8010880C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80108810: jal         0x800C7D1C
    // 0x80108814: addiu       $a0, $zero, 0x143
    ctx->r4 = ADD32(0, 0X143);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_49;
    // 0x80108814: addiu       $a0, $zero, 0x143
    ctx->r4 = ADD32(0, 0X143);
    after_49:
    // 0x80108818: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8010881C: jal         0x800C7540
    // 0x80108820: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_50;
    // 0x80108820: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_50:
    // 0x80108824: jal         0x800C77B0
    // 0x80108828: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    setFriendliesSaved(rdram, ctx);
        goto after_51;
    // 0x80108828: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_51:
    // 0x8010882C: sw          $s1, -0x2E34($s0)
    MEM_W(-0X2E34, ctx->r16) = ctx->r17;
L_80108830:
    // 0x80108830: jal         0x800C759C
    // 0x80108834: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    getObjectiveBoolean(rdram, ctx);
        goto after_52;
    // 0x80108834: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_52:
    // 0x80108838: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8010883C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80108840: bne         $s0, $v0, L_801088D0
    if (ctx->r16 != ctx->r2) {
        // 0x80108844: nop
    
            goto L_801088D0;
    }
    // 0x80108844: nop

    // 0x80108848: jal         0x800C759C
    // 0x8010884C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    getObjectiveBoolean(rdram, ctx);
        goto after_53;
    // 0x8010884C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_53:
    // 0x80108850: bne         $v0, $zero, L_801088D0
    if (ctx->r2 != 0) {
        // 0x80108854: nop
    
            goto L_801088D0;
    }
    // 0x80108854: nop

    // 0x80108858: jal         0x800C759C
    // 0x8010885C: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    getObjectiveBoolean(rdram, ctx);
        goto after_54;
    // 0x8010885C: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_54:
    // 0x80108860: bne         $v0, $zero, L_801088D0
    if (ctx->r2 != 0) {
        // 0x80108864: nop
    
            goto L_801088D0;
    }
    // 0x80108864: nop

    // 0x80108868: jal         0x800C759C
    // 0x8010886C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    getObjectiveBoolean(rdram, ctx);
        goto after_55;
    // 0x8010886C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_55:
    // 0x80108870: bne         $v0, $zero, L_801088D0
    if (ctx->r2 != 0) {
        // 0x80108874: nop
    
            goto L_801088D0;
    }
    // 0x80108874: nop

    // 0x80108878: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x8010887C: lw          $v0, -0x2E34($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X2E34);
    // 0x80108880: bne         $v0, $zero, L_801088D0
    if (ctx->r2 != 0) {
        // 0x80108884: nop
    
            goto L_801088D0;
    }
    // 0x80108884: nop

    // 0x80108888: jal         0x800C7738
    // 0x8010888C: nop

    setHudEnableBit4(rdram, ctx);
        goto after_56;
    // 0x8010888C: nop

    after_56:
    // 0x80108890: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80108894: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80108898: jal         0x800C7884
    // 0x8010889C: addiu       $a0, $a0, -0x65B4
    ctx->r4 = ADD32(ctx->r4, -0X65B4);
    setHudFlagBit40AndStoreArg(rdram, ctx);
        goto after_57;
    // 0x8010889C: addiu       $a0, $a0, -0x65B4
    ctx->r4 = ADD32(ctx->r4, -0X65B4);
    after_57:
    // 0x801088A0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801088A4: jal         0x800C7D1C
    // 0x801088A8: addiu       $a0, $zero, 0x26B
    ctx->r4 = ADD32(0, 0X26B);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_58;
    // 0x801088A8: addiu       $a0, $zero, 0x26B
    ctx->r4 = ADD32(0, 0X26B);
    after_58:
    // 0x801088AC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801088B0: jal         0x800C7D1C
    // 0x801088B4: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_59;
    // 0x801088B4: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    after_59:
    // 0x801088B8: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x801088BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801088C0: jal         0x800C7540
    // 0x801088C4: sw          $s0, -0x2E34($s1)
    MEM_W(-0X2E34, ctx->r17) = ctx->r16;
    setObjectiveBoolean(rdram, ctx);
        goto after_60;
    // 0x801088C4: sw          $s0, -0x2E34($s1)
    MEM_W(-0X2E34, ctx->r17) = ctx->r16;
    after_60:
    // 0x801088C8: jal         0x800C77B0
    // 0x801088CC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    setFriendliesSaved(rdram, ctx);
        goto after_61;
    // 0x801088CC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_61:
L_801088D0:
    // 0x801088D0: jal         0x800C794C
    // 0x801088D4: nop

    func_800C794C(rdram, ctx);
        goto after_62;
    // 0x801088D4: nop

    after_62:
    // 0x801088D8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x801088DC: lwc1        $f2, -0x65A8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X65A8);
    // 0x801088E0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x801088E4: nop

    // 0x801088E8: bc1f        L_80108924
    if (!c1cs) {
        // 0x801088EC: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_80108924;
    }
    // 0x801088EC: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x801088F0: lw          $v0, -0x2E30($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X2E30);
    // 0x801088F4: bne         $v0, $zero, L_80108924
    if (ctx->r2 != 0) {
        // 0x801088F8: addiu       $a0, $zero, 0x26B
        ctx->r4 = ADD32(0, 0X26B);
            goto L_80108924;
    }
    // 0x801088F8: addiu       $a0, $zero, 0x26B
    ctx->r4 = ADD32(0, 0X26B);
    // 0x801088FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80108900: jal         0x800C7CF8
    // 0x80108904: sw          $v0, -0x2E30($v1)
    MEM_W(-0X2E30, ctx->r3) = ctx->r2;
    playObjectiveVoiceLine1(rdram, ctx);
        goto after_63;
    // 0x80108904: sw          $v0, -0x2E30($v1)
    MEM_W(-0X2E30, ctx->r3) = ctx->r2;
    after_63:
    // 0x80108908: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8010890C: jal         0x800C75EC
    // 0x80108910: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    increaseObjectiveCount(rdram, ctx);
        goto after_64;
    // 0x80108910: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_64:
    // 0x80108914: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80108918: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    // 0x8010891C: jal         0x800C7864
    // 0x80108920: addiu       $a0, $a0, -0x759C
    ctx->r4 = ADD32(ctx->r4, -0X759C);
    addTimerHandleWrapper(rdram, ctx);
        goto after_65;
    // 0x80108920: addiu       $a0, $a0, -0x759C
    ctx->r4 = ADD32(ctx->r4, -0X759C);
    after_65:
L_80108924:
    // 0x80108924: jal         0x800C761C
    // 0x80108928: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    getObjectiveCount(rdram, ctx);
        goto after_66;
    // 0x80108928: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_66:
    // 0x8010892C: slti        $v0, $v0, 0x2
    ctx->r2 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80108930: bne         $v0, $zero, L_80108988
    if (ctx->r2 != 0) {
        // 0x80108934: nop
    
            goto L_80108988;
    }
    // 0x80108934: nop

    // 0x80108938: jal         0x800C7738
    // 0x8010893C: nop

    setHudEnableBit4(rdram, ctx);
        goto after_67;
    // 0x8010893C: nop

    after_67:
    // 0x80108940: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80108944: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80108948: jal         0x800C7884
    // 0x8010894C: addiu       $a0, $a0, -0x65B4
    ctx->r4 = ADD32(ctx->r4, -0X65B4);
    setHudFlagBit40AndStoreArg(rdram, ctx);
        goto after_68;
    // 0x8010894C: addiu       $a0, $a0, -0x65B4
    ctx->r4 = ADD32(ctx->r4, -0X65B4);
    after_68:
    // 0x80108950: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80108954: jal         0x800C7D1C
    // 0x80108958: addiu       $a0, $zero, 0x26B
    ctx->r4 = ADD32(0, 0X26B);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_69;
    // 0x80108958: addiu       $a0, $zero, 0x26B
    ctx->r4 = ADD32(0, 0X26B);
    after_69:
    // 0x8010895C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80108960: jal         0x800C7D1C
    // 0x80108964: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_70;
    // 0x80108964: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    after_70:
    // 0x80108968: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8010896C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80108970: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80108974: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // 0x80108978: jal         0x800C7540
    // 0x8010897C: sw          $v0, -0x2E34($v1)
    MEM_W(-0X2E34, ctx->r3) = ctx->r2;
    setObjectiveBoolean(rdram, ctx);
        goto after_71;
    // 0x8010897C: sw          $v0, -0x2E34($v1)
    MEM_W(-0X2E34, ctx->r3) = ctx->r2;
    after_71:
    // 0x80108980: jal         0x800C77B0
    // 0x80108984: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    setFriendliesSaved(rdram, ctx);
        goto after_72;
    // 0x80108984: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_72:
L_80108988:
    // 0x80108988: jal         0x800C759C
    // 0x8010898C: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    getObjectiveBoolean(rdram, ctx);
        goto after_73;
    // 0x8010898C: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_73:
    // 0x80108990: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80108994: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80108998: bne         $s0, $v0, L_801089C4
    if (ctx->r16 != ctx->r2) {
        // 0x8010899C: lui         $s1, 0x8011
        ctx->r17 = S32(0X8011 << 16);
            goto L_801089C4;
    }
    // 0x8010899C: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x801089A0: lw          $v0, -0x2E2C($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X2E2C);
    // 0x801089A4: bne         $v0, $zero, L_801089C4
    if (ctx->r2 != 0) {
        // 0x801089A8: nop
    
            goto L_801089C4;
    }
    // 0x801089A8: nop

    // 0x801089AC: jal         0x800C7738
    // 0x801089B0: nop

    setHudEnableBit4(rdram, ctx);
        goto after_74;
    // 0x801089B0: nop

    after_74:
    // 0x801089B4: addiu       $a0, $zero, 0x1F0
    ctx->r4 = ADD32(0, 0X1F0);
    // 0x801089B8: jal         0x800C7D1C
    // 0x801089BC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_75;
    // 0x801089BC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_75:
    // 0x801089C0: sw          $s0, -0x2E2C($s1)
    MEM_W(-0X2E2C, ctx->r17) = ctx->r16;
L_801089C4:
    // 0x801089C4: jal         0x800C759C
    // 0x801089C8: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    getObjectiveBoolean(rdram, ctx);
        goto after_76;
    // 0x801089C8: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_76:
    // 0x801089CC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x801089D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801089D4: bne         $s0, $v0, L_80108A00
    if (ctx->r16 != ctx->r2) {
        // 0x801089D8: lui         $s1, 0x8011
        ctx->r17 = S32(0X8011 << 16);
            goto L_80108A00;
    }
    // 0x801089D8: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x801089DC: lw          $v0, -0x2E28($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X2E28);
    // 0x801089E0: bne         $v0, $zero, L_80108A00
    if (ctx->r2 != 0) {
        // 0x801089E4: nop
    
            goto L_80108A00;
    }
    // 0x801089E4: nop

    // 0x801089E8: jal         0x800C7738
    // 0x801089EC: nop

    setHudEnableBit4(rdram, ctx);
        goto after_77;
    // 0x801089EC: nop

    after_77:
    // 0x801089F0: addiu       $a0, $zero, 0x1F0
    ctx->r4 = ADD32(0, 0X1F0);
    // 0x801089F4: jal         0x800C7D1C
    // 0x801089F8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_78;
    // 0x801089F8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_78:
    // 0x801089FC: sw          $s0, -0x2E28($s1)
    MEM_W(-0X2E28, ctx->r17) = ctx->r16;
L_80108A00:
    // 0x80108A00: jal         0x800C759C
    // 0x80108A04: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    getObjectiveBoolean(rdram, ctx);
        goto after_79;
    // 0x80108A04: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_79:
    // 0x80108A08: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x80108A0C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80108A10: bne         $s0, $v0, L_80108A3C
    if (ctx->r16 != ctx->r2) {
        // 0x80108A14: lui         $s1, 0x8011
        ctx->r17 = S32(0X8011 << 16);
            goto L_80108A3C;
    }
    // 0x80108A14: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x80108A18: lw          $v0, -0x2E24($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X2E24);
    // 0x80108A1C: bne         $v0, $zero, L_80108A3C
    if (ctx->r2 != 0) {
        // 0x80108A20: nop
    
            goto L_80108A3C;
    }
    // 0x80108A20: nop

    // 0x80108A24: jal         0x800C7738
    // 0x80108A28: nop

    setHudEnableBit4(rdram, ctx);
        goto after_80;
    // 0x80108A28: nop

    after_80:
    // 0x80108A2C: addiu       $a0, $zero, 0x1F0
    ctx->r4 = ADD32(0, 0X1F0);
    // 0x80108A30: jal         0x800C7D1C
    // 0x80108A34: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_81;
    // 0x80108A34: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_81:
    // 0x80108A38: sw          $s0, -0x2E24($s1)
    MEM_W(-0X2E24, ctx->r17) = ctx->r16;
L_80108A3C:
    // 0x80108A3C: jal         0x80108A70
    // 0x80108A40: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    func_80108A70(rdram, ctx);
        goto after_82;
    // 0x80108A40: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_82:
    // 0x80108A44: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80108A48: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80108A4C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80108A50: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80108A54: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80108A58: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80108A5C: jr          $ra
    // 0x80108A60: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80108A60: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_80108A64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108A64: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80108A68: jr          $ra
    // 0x80108A6C: sw          $zero, -0x2E30($v0)
    MEM_W(-0X2E30, ctx->r2) = 0;
    return;
    // 0x80108A6C: sw          $zero, -0x2E30($v0)
    MEM_W(-0X2E30, ctx->r2) = 0;
;}
RECOMP_FUNC void func_80108A70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108A70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80108A74: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80108A78: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80108A7C: lw          $v0, -0x2E40($s0)
    ctx->r2 = MEM_W(ctx->r16, -0X2E40);
    // 0x80108A80: bne         $v0, $zero, L_80108AD8
    if (ctx->r2 != 0) {
        // 0x80108A84: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80108AD8;
    }
    // 0x80108A84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80108A88: jal         0x800C759C
    // 0x80108A8C: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    getObjectiveBoolean(rdram, ctx);
        goto after_0;
    // 0x80108A8C: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_0:
    // 0x80108A90: bne         $v0, $zero, L_80108AB8
    if (ctx->r2 != 0) {
        // 0x80108A94: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80108AB8;
    }
    // 0x80108A94: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80108A98: jal         0x800C759C
    // 0x80108A9C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    getObjectiveBoolean(rdram, ctx);
        goto after_1;
    // 0x80108A9C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_1:
    // 0x80108AA0: bne         $v0, $zero, L_80108AB8
    if (ctx->r2 != 0) {
        // 0x80108AA4: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_80108AB8;
    }
    // 0x80108AA4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80108AA8: jal         0x800C759C
    // 0x80108AAC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    getObjectiveBoolean(rdram, ctx);
        goto after_2;
    // 0x80108AAC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_2:
    // 0x80108AB0: beq         $v0, $zero, L_80108ABC
    if (ctx->r2 == 0) {
        // 0x80108AB4: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_80108ABC;
    }
    // 0x80108AB4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80108AB8:
    // 0x80108AB8: sw          $v0, -0x2E40($s0)
    MEM_W(-0X2E40, ctx->r16) = ctx->r2;
L_80108ABC:
    // 0x80108ABC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80108AC0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80108AC4: lw          $a1, -0x2E40($v0)
    ctx->r5 = MEM_W(ctx->r2, -0X2E40);
    // 0x80108AC8: jal         0x800C7D60
    // 0x80108ACC: addiu       $a0, $a0, -0x65A4
    ctx->r4 = ADD32(ctx->r4, -0X65A4);
    delegateToLevelStageTick(rdram, ctx);
        goto after_3;
    // 0x80108ACC: addiu       $a0, $a0, -0x65A4
    ctx->r4 = ADD32(ctx->r4, -0X65A4);
    after_3:
    // 0x80108AD0: j           L_80108B24
    // 0x80108AD4: nop

        goto L_80108B24;
    // 0x80108AD4: nop

L_80108AD8:
    // 0x80108AD8: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80108ADC: lw          $v0, -0x2E3C($s0)
    ctx->r2 = MEM_W(ctx->r16, -0X2E3C);
    // 0x80108AE0: bne         $v0, $zero, L_80108B24
    if (ctx->r2 != 0) {
        // 0x80108AE4: nop
    
            goto L_80108B24;
    }
    // 0x80108AE4: nop

    // 0x80108AE8: jal         0x800C759C
    // 0x80108AEC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    getObjectiveBoolean(rdram, ctx);
        goto after_4;
    // 0x80108AEC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_4:
    // 0x80108AF0: beq         $v0, $zero, L_80108B04
    if (ctx->r2 == 0) {
        // 0x80108AF4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80108B04;
    }
    // 0x80108AF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80108AF8: sw          $v0, -0x2E3C($s0)
    MEM_W(-0X2E3C, ctx->r16) = ctx->r2;
    // 0x80108AFC: j           L_80108B1C
    // 0x80108B00: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
        goto L_80108B1C;
    // 0x80108B00: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_80108B04:
    // 0x80108B04: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80108B08: lw          $v0, -0x2E34($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2E34);
    // 0x80108B0C: beq         $v0, $zero, L_80108B24
    if (ctx->r2 == 0) {
        // 0x80108B10: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80108B24;
    }
    // 0x80108B10: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80108B14: sw          $v0, -0x2E3C($s0)
    MEM_W(-0X2E3C, ctx->r16) = ctx->r2;
    // 0x80108B18: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
L_80108B1C:
    // 0x80108B1C: jal         0x800C7D98
    // 0x80108B20: nop

    triggerSoundCueByType(rdram, ctx);
        goto after_5;
    // 0x80108B20: nop

    after_5:
L_80108B24:
    // 0x80108B24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80108B28: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80108B2C: jr          $ra
    // 0x80108B30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80108B30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lvg_initializeObjectTracking(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108B34: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80108B38: sw          $zero, -0x2E38($v0)
    MEM_W(-0X2E38, ctx->r2) = 0;
    // 0x80108B3C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80108B40: sw          $zero, -0x2E34($v0)
    MEM_W(-0X2E34, ctx->r2) = 0;
    // 0x80108B44: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80108B48: sw          $zero, -0x2E30($v0)
    MEM_W(-0X2E30, ctx->r2) = 0;
    // 0x80108B4C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80108B50: sw          $zero, -0x2E2C($v0)
    MEM_W(-0X2E2C, ctx->r2) = 0;
    // 0x80108B54: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80108B58: sw          $zero, -0x2E28($v0)
    MEM_W(-0X2E28, ctx->r2) = 0;
    // 0x80108B5C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80108B60: sw          $zero, -0x2E24($v0)
    MEM_W(-0X2E24, ctx->r2) = 0;
    // 0x80108B64: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80108B68: sw          $zero, -0x2E40($v0)
    MEM_W(-0X2E40, ctx->r2) = 0;
    // 0x80108B6C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80108B70: sw          $zero, -0x2E3C($v0)
    MEM_W(-0X2E3C, ctx->r2) = 0;
    // 0x80108B74: jr          $ra
    // 0x80108B78: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80108B78: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void lvg_80108B7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108B7C: jr          $ra
    // 0x80108B80: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80108B80: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void lvg_calculateFriendliesSaved(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108B84: jr          $ra
    // 0x80108B88: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80108B88: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void fake_func_80108B8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void lvh_initializeObjectTracking(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108B90: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80108B94: lwc1        $f12, -0x6580($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X6580);
    // 0x80108B98: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80108B9C: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80108BA0: jal         0x800C7CEC
    // 0x80108BA4: nop

    setLevelObjectTrackingScalar(rdram, ctx);
        goto after_0;
    // 0x80108BA4: nop

    after_0:
    // 0x80108BA8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80108BAC: addiu       $a0, $a0, -0x7368
    ctx->r4 = ADD32(ctx->r4, -0X7368);
    // 0x80108BB0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80108BB4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80108BB8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80108BBC: jal         0x800C7830
    // 0x80108BC0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_1;
    // 0x80108BC0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x80108BC4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80108BC8: addiu       $a0, $a0, -0x72E4
    ctx->r4 = ADD32(ctx->r4, -0X72E4);
    // 0x80108BCC: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x80108BD0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80108BD4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80108BD8: jal         0x800C7830
    // 0x80108BDC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_2;
    // 0x80108BDC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x80108BE0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80108BE4: addiu       $a0, $a0, -0x7294
    ctx->r4 = ADD32(ctx->r4, -0X7294);
    // 0x80108BE8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80108BEC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80108BF0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80108BF4: jal         0x800C7830
    // 0x80108BF8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_3;
    // 0x80108BF8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x80108BFC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80108C00: addiu       $a0, $a0, -0x7268
    ctx->r4 = ADD32(ctx->r4, -0X7268);
    // 0x80108C04: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x80108C08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80108C0C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80108C10: jal         0x800C7830
    // 0x80108C14: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_4;
    // 0x80108C14: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x80108C18: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80108C1C: addiu       $a0, $a0, -0x7210
    ctx->r4 = ADD32(ctx->r4, -0X7210);
    // 0x80108C20: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    // 0x80108C24: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80108C28: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80108C2C: jal         0x800C7830
    // 0x80108C30: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_5;
    // 0x80108C30: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x80108C34: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80108C38: addiu       $a0, $a0, -0x71F0
    ctx->r4 = ADD32(ctx->r4, -0X71F0);
    // 0x80108C3C: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    // 0x80108C40: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80108C44: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80108C48: jal         0x800C7830
    // 0x80108C4C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_6;
    // 0x80108C4C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_6:
    // 0x80108C50: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80108C54: addiu       $a0, $a0, -0x723C
    ctx->r4 = ADD32(ctx->r4, -0X723C);
    // 0x80108C58: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    // 0x80108C5C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80108C60: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80108C64: jal         0x800C7830
    // 0x80108C68: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_7;
    // 0x80108C68: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_7:
    // 0x80108C6C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80108C70: addiu       $a0, $a0, -0x71B8
    ctx->r4 = ADD32(ctx->r4, -0X71B8);
    // 0x80108C74: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x80108C78: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80108C7C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80108C80: jal         0x800C7830
    // 0x80108C84: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_8;
    // 0x80108C84: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_8:
    // 0x80108C88: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80108C8C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80108C90: jr          $ra
    // 0x80108C94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80108C94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80108C98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108C98: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80108C9C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80108CA0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80108CA4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80108CA8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80108CAC: jal         0x800C7884
    // 0x80108CB0: addiu       $a0, $a0, -0x657C
    ctx->r4 = ADD32(ctx->r4, -0X657C);
    setHudFlagBit40AndStoreArg(rdram, ctx);
        goto after_0;
    // 0x80108CB0: addiu       $a0, $a0, -0x657C
    ctx->r4 = ADD32(ctx->r4, -0X657C);
    after_0:
    // 0x80108CB4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80108CB8: jal         0x800C7D1C
    // 0x80108CBC: addiu       $a0, $zero, 0x8D
    ctx->r4 = ADD32(0, 0X8D);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x80108CBC: addiu       $a0, $zero, 0x8D
    ctx->r4 = ADD32(0, 0X8D);
    after_1:
    // 0x80108CC0: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80108CC4: jal         0x800C7D1C
    // 0x80108CC8: addiu       $a0, $zero, 0x13D
    ctx->r4 = ADD32(0, 0X13D);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_2;
    // 0x80108CC8: addiu       $a0, $zero, 0x13D
    ctx->r4 = ADD32(0, 0X13D);
    after_2:
    // 0x80108CCC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80108CD0: jal         0x800C7D1C
    // 0x80108CD4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_3;
    // 0x80108CD4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80108CD8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80108CDC: jal         0x800C7D1C
    // 0x80108CE0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_4;
    // 0x80108CE0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
    // 0x80108CE4: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80108CE8: jal         0x800C7D1C
    // 0x80108CEC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_5;
    // 0x80108CEC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_5:
    // 0x80108CF0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80108CF4: jal         0x800C7D1C
    // 0x80108CF8: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_6;
    // 0x80108CF8: addiu       $a0, $zero, 0x13F
    ctx->r4 = ADD32(0, 0X13F);
    after_6:
    // 0x80108CFC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80108D00: addiu       $a0, $a0, -0x6574
    ctx->r4 = ADD32(ctx->r4, -0X6574);
    // 0x80108D04: jal         0x800C7D60
    // 0x80108D08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    delegateToLevelStageTick(rdram, ctx);
        goto after_7;
    // 0x80108D08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x80108D0C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80108D10: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80108D14: jr          $ra
    // 0x80108D18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80108D18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
