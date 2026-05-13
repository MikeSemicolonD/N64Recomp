#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void func_800C7718(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7718: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C771C: lwc1        $f0, 0xBA4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XBA4);
    // 0x800C7720: jr          $ra
    // 0x800C7724: nop

    return;
    // 0x800C7724: nop

;}
RECOMP_FUNC void func_800C7728(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7728: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800C772C: lwc1        $f0, -0x361C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X361C);
    // 0x800C7730: jr          $ra
    // 0x800C7734: nop

    return;
    // 0x800C7734: nop

;}
RECOMP_FUNC void setHudEnableBit4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7738: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800C773C: lw          $v0, -0x35E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X35E0);
    // 0x800C7740: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C7744: bne         $v0, $zero, L_800C7760
    if (ctx->r2 != 0) {
        // 0x800C7748: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_800C7760;
    }
    // 0x800C7748: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800C774C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800C7750: lw          $v0, -0x3620($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X3620);
    // 0x800C7754: ori         $v0, $v0, 0x4
    ctx->r2 = ctx->r2 | 0X4;
    // 0x800C7758: jal         0x80067938
    // 0x800C775C: sw          $v0, -0x3620($v1)
    MEM_W(-0X3620, ctx->r3) = ctx->r2;
    func_80067938(rdram, ctx);
        goto after_0;
    // 0x800C775C: sw          $v0, -0x3620($v1)
    MEM_W(-0X3620, ctx->r3) = ctx->r2;
    after_0:
L_800C7760:
    // 0x800C7760: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800C7764: jr          $ra
    // 0x800C7768: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C7768: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void setHudEnableBit8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C776C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800C7770: lw          $v0, -0x35E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X35E0);
    // 0x800C7774: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C7778: bne         $v0, $zero, L_800C7794
    if (ctx->r2 != 0) {
        // 0x800C777C: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_800C7794;
    }
    // 0x800C777C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800C7780: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800C7784: lw          $v0, -0x3620($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X3620);
    // 0x800C7788: ori         $v0, $v0, 0x8
    ctx->r2 = ctx->r2 | 0X8;
    // 0x800C778C: jal         0x80067938
    // 0x800C7790: sw          $v0, -0x3620($v1)
    MEM_W(-0X3620, ctx->r3) = ctx->r2;
    func_80067938(rdram, ctx);
        goto after_0;
    // 0x800C7790: sw          $v0, -0x3620($v1)
    MEM_W(-0X3620, ctx->r3) = ctx->r2;
    after_0:
L_800C7794:
    // 0x800C7794: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800C7798: jr          $ra
    // 0x800C779C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C779C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800C77A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C77A0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C77A4: lbu         $v0, 0x7CE0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7CE0);
    // 0x800C77A8: jr          $ra
    // 0x800C77AC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
    return;
    // 0x800C77AC: sltiu       $v0, $v0, 0x1
    ctx->r2 = ctx->r2 < 0X1 ? 1 : 0;
;}
RECOMP_FUNC void setFriendliesSaved(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C77B0: bltzl       $a0, L_800C77B8
    if (SIGNED(ctx->r4) < 0) {
        // 0x800C77B4: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800C77B8;
    }
    goto skip_0;
    // 0x800C77B4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    skip_0:
L_800C77B8:
    // 0x800C77B8: slti        $v0, $a0, 0x100
    ctx->r2 = SIGNED(ctx->r4) < 0X100 ? 1 : 0;
    // 0x800C77BC: beql        $v0, $zero, L_800C77C4
    if (ctx->r2 == 0) {
        // 0x800C77C0: addiu       $a0, $zero, 0xFF
        ctx->r4 = ADD32(0, 0XFF);
            goto L_800C77C4;
    }
    goto skip_1;
    // 0x800C77C0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    skip_1:
L_800C77C4:
    // 0x800C77C4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C77C8: jr          $ra
    // 0x800C77CC: sb          $a0, 0xB86($v0)
    MEM_B(0XB86, ctx->r2) = ctx->r4;
    return;
    // 0x800C77CC: sb          $a0, 0xB86($v0)
    MEM_B(0XB86, ctx->r2) = ctx->r4;
;}
RECOMP_FUNC void func_800C77D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C77D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C77D4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800C77D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C77DC: jal         0x80003430
    // 0x800C77E0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    rand_recomp(rdram, ctx);
        goto after_0;
    // 0x800C77E0: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    after_0:
    // 0x800C77E4: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800C77E8: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800C77EC: div         $zero, $v0, $s0
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r16)));
    // 0x800C77F0: bne         $s0, $zero, L_800C77FC
    if (ctx->r16 != 0) {
        // 0x800C77F4: nop
    
            goto L_800C77FC;
    }
    // 0x800C77F4: nop

    // 0x800C77F8: break       7
    do_break(2148300792);
L_800C77FC:
    // 0x800C77FC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C7800: bne         $s0, $at, L_800C7814
    if (ctx->r16 != ctx->r1) {
        // 0x800C7804: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C7814;
    }
    // 0x800C7804: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C7808: bne         $v0, $at, L_800C7814
    if (ctx->r2 != ctx->r1) {
        // 0x800C780C: nop
    
            goto L_800C7814;
    }
    // 0x800C780C: nop

    // 0x800C7810: break       6
    do_break(2148300816);
L_800C7814:
    // 0x800C7814: mfhi        $v1
    ctx->r3 = hi;
    // 0x800C7818: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C781C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800C7820: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x800C7824: sra         $v0, $v1, 16
    ctx->r2 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800C7828: jr          $ra
    // 0x800C782C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C782C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void addBooleanCountHandleWrapper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7830: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C7834: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x800C7838: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x800C783C: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x800C7840: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x800C7844: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800C7848: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800C784C: jal         0x800FA15C
    // 0x800C7850: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    addBooleanCountHandle(rdram, ctx);
        goto after_0;
    // 0x800C7850: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_0:
    // 0x800C7854: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800C7858: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800C785C: jr          $ra
    // 0x800C7860: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C7860: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void addTimerHandleWrapper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7864: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C7868: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800C786C: jal         0x800FA1DC
    // 0x800C7870: nop

    addTimerHandle(rdram, ctx);
        goto after_0;
    // 0x800C7870: nop

    after_0:
    // 0x800C7874: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800C7878: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800C787C: jr          $ra
    // 0x800C7880: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C7880: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void setHudFlagBit40AndStoreArg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7884: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800C7888: lw          $v1, -0x3620($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X3620);
    // 0x800C788C: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800C7890: sw          $a0, -0x13F0($a1)
    MEM_W(-0X13F0, ctx->r5) = ctx->r4;
    // 0x800C7894: ori         $v1, $v1, 0x40
    ctx->r3 = ctx->r3 | 0X40;
    // 0x800C7898: jr          $ra
    // 0x800C789C: sw          $v1, -0x3620($v0)
    MEM_W(-0X3620, ctx->r2) = ctx->r3;
    return;
    // 0x800C789C: sw          $v1, -0x3620($v0)
    MEM_W(-0X3620, ctx->r2) = ctx->r3;
;}
RECOMP_FUNC void calculateDatItemDistanceToPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C78A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C78A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C78A8: jal         0x80047B48
    // 0x800C78AC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    getLevelDatItemByName(rdram, ctx);
        goto after_0;
    // 0x800C78AC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    after_0:
    // 0x800C78B0: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800C78B4: beq         $a0, $zero, L_800C7934
    if (ctx->r4 == 0) {
        // 0x800C78B8: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_800C7934;
    }
    // 0x800C78B8: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800C78BC: lhu         $v1, 0x6($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X6);
    // 0x800C78C0: beq         $v1, $v0, L_800C7934
    if (ctx->r3 == ctx->r2) {
        // 0x800C78C4: nop
    
            goto L_800C7934;
    }
    // 0x800C78C4: nop

    // 0x800C78C8: jal         0x8004015C
    // 0x800C78CC: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    getNpcContextField8(rdram, ctx);
        goto after_1;
    // 0x800C78CC: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    after_1:
    // 0x800C78D0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800C78D4: jal         0x8006C994
    // 0x800C78D8: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    getPlayerField2(rdram, ctx);
        goto after_2;
    // 0x800C78D8: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_2:
    // 0x800C78DC: jal         0x8004015C
    // 0x800C78E0: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    getNpcContextField8(rdram, ctx);
        goto after_3;
    // 0x800C78E0: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    after_3:
    // 0x800C78E4: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800C78E8: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800C78EC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800C78F0: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800C78F4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800C78F8: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800C78FC: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800C7900: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800C7904: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800C7908: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800C790C: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800C7910: lwc1        $f2, 0x8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800C7914: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800C7918: mul.s       $f2, $f0, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800C791C: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800C7920: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800C7924: add.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800C7928: sqrt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = sqrtf(ctx->f4.fl);
    // 0x800C792C: j           L_800C793C
    // 0x800C7930: nop

        goto L_800C793C;
    // 0x800C7930: nop

L_800C7934:
    // 0x800C7934: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C7938: lwc1        $f0, 0x6960($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6960);
L_800C793C:
    // 0x800C793C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C7940: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C7944: jr          $ra
    // 0x800C7948: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C7948: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800C794C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C794C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C7950: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800C7954: jal         0x8006C8F0
    // 0x800C7958: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    getCraftRecordByIdx(rdram, ctx);
        goto after_0;
    // 0x800C7958: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_0:
    // 0x800C795C: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800C7960: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C7964: lwc1        $f0, 0x6964($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6964);
    // 0x800C7968: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800C796C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800C7970: jr          $ra
    // 0x800C7974: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C7974: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800C7970(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7970: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800C7974: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800C7978: addu        $s6, $a0, $zero
    ctx->r22 = ADD32(ctx->r4, 0);
    // 0x800C797C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800C7980: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800C7984: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800C7988: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800C798C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800C7990: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800C7994: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800C7998: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800C799C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C79A0: lhu         $v0, 0x7CC($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X7CC);
    // 0x800C79A4: beq         $v0, $zero, L_800C7B0C
    if (ctx->r2 == 0) {
        // 0x800C79A8: addu        $t0, $zero, $zero
        ctx->r8 = ADD32(0, 0);
            goto L_800C7B0C;
    }
    // 0x800C79A8: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
L_800C79AC:
    // 0x800C79AC: lhu         $v0, 0x7CE($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X7CE);
    // 0x800C79B0: beq         $v0, $zero, L_800C79F8
    if (ctx->r2 == 0) {
        // 0x800C79B4: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_800C79F8;
    }
    // 0x800C79B4: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800C79B8: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
L_800C79BC:
    // 0x800C79BC: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x800C79C0: addu        $v1, $s6, $v0
    ctx->r3 = ADD32(ctx->r22, ctx->r2);
    // 0x800C79C4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C79C8: addu        $v0, $s6, $v0
    ctx->r2 = ADD32(ctx->r22, ctx->r2);
    // 0x800C79CC: lbu         $a1, 0x7BC($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X7BC);
    // 0x800C79D0: lw          $a2, 0x77C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X77C);
    // 0x800C79D4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800C79D8: jal         0x800C821C
    // 0x800C79DC: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    func_800C821C(rdram, ctx);
        goto after_0;
    // 0x800C79DC: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_0:
    // 0x800C79E0: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x800C79E4: lhu         $v1, 0x7CE($s6)
    ctx->r3 = MEM_HU(ctx->r22, 0X7CE);
    // 0x800C79E8: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800C79EC: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800C79F0: bne         $v0, $zero, L_800C79BC
    if (ctx->r2 != 0) {
        // 0x800C79F4: addu        $a0, $s6, $zero
        ctx->r4 = ADD32(ctx->r22, 0);
            goto L_800C79BC;
    }
    // 0x800C79F4: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
L_800C79F8:
    // 0x800C79F8: addu        $fp, $zero, $zero
    ctx->r30 = ADD32(0, 0);
    // 0x800C79FC: lbu         $v0, 0x4C($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X4C);
    // 0x800C7A00: beq         $v0, $zero, L_800C7AF4
    if (ctx->r2 == 0) {
        // 0x800C7A04: addu        $s5, $fp, $zero
        ctx->r21 = ADD32(ctx->r30, 0);
            goto L_800C7AF4;
    }
    // 0x800C7A04: addu        $s5, $fp, $zero
    ctx->r21 = ADD32(ctx->r30, 0);
    // 0x800C7A08: andi        $t1, $t0, 0xFF
    ctx->r9 = ctx->r8 & 0XFF;
    // 0x800C7A0C: andi        $v1, $s5, 0xFF
    ctx->r3 = ctx->r21 & 0XFF;
L_800C7A10:
    // 0x800C7A10: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800C7A14: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C7A18: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C7A1C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800C7A20: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C7A24: addiu       $v0, $v0, 0x6F8
    ctx->r2 = ADD32(ctx->r2, 0X6F8);
    // 0x800C7A28: addu        $s2, $s6, $v0
    ctx->r18 = ADD32(ctx->r22, ctx->r2);
    // 0x800C7A2C: lbu         $v0, 0x4B($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X4B);
    // 0x800C7A30: lbu         $v1, 0x2($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X2);
    // 0x800C7A34: addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
    // 0x800C7A38: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800C7A3C: lhu         $v1, 0x7EC($s6)
    ctx->r3 = MEM_HU(ctx->r22, 0X7EC);
    // 0x800C7A40: lw          $a0, 0x18($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X18);
    // 0x800C7A44: blez        $a0, L_800C7ADC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800C7A48: srav        $s3, $v1, $v0
        ctx->r19 = S32(SIGNED(ctx->r3) >> (ctx->r2 & 31));
            goto L_800C7ADC;
    }
    // 0x800C7A48: srav        $s3, $v1, $v0
    ctx->r19 = S32(SIGNED(ctx->r3) >> (ctx->r2 & 31));
L_800C7A4C:
    // 0x800C7A4C: lw          $v0, 0x20($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X20);
    // 0x800C7A50: mult        $t1, $v0
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C7A54: lw          $v1, 0x14($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X14);
    // 0x800C7A58: mflo        $s1
    ctx->r17 = lo;
    // 0x800C7A5C: blez        $v1, L_800C7ABC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800C7A60: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_800C7ABC;
    }
    // 0x800C7A60: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x800C7A64: andi        $s4, $fp, 0xFF
    ctx->r20 = ctx->r30 & 0XFF;
    // 0x800C7A68: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
L_800C7A6C:
    // 0x800C7A6C: andi        $a1, $s5, 0xFF
    ctx->r5 = ctx->r21 & 0XFF;
    // 0x800C7A70: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // 0x800C7A74: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x800C7A78: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x800C7A7C: addu        $v0, $s4, $v0
    ctx->r2 = ADD32(ctx->r20, ctx->r2);
    // 0x800C7A80: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C7A84: addu        $v0, $s6, $v0
    ctx->r2 = ADD32(ctx->r22, ctx->r2);
    // 0x800C7A88: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x800C7A8C: lw          $a2, 0x77C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X77C);
    // 0x800C7A90: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800C7A94: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x800C7A98: jal         0x800C7B68
    // 0x800C7A9C: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    func_800C7B68(rdram, ctx);
        goto after_1;
    // 0x800C7A9C: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    after_1:
    // 0x800C7AA0: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x800C7AA4: lw          $v1, 0x14($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X14);
    // 0x800C7AA8: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x800C7AAC: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800C7AB0: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800C7AB4: bne         $v0, $zero, L_800C7A6C
    if (ctx->r2 != 0) {
        // 0x800C7AB8: addu        $a0, $s6, $zero
        ctx->r4 = ADD32(ctx->r22, 0);
            goto L_800C7A6C;
    }
    // 0x800C7AB8: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
L_800C7ABC:
    // 0x800C7ABC: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800C7AC0: lbu         $v0, 0x17($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X17);
    // 0x800C7AC4: lw          $v1, 0x18($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X18);
    // 0x800C7AC8: addu        $fp, $fp, $v0
    ctx->r30 = ADD32(ctx->r30, ctx->r2);
    // 0x800C7ACC: andi        $v0, $s7, 0xFF
    ctx->r2 = ctx->r23 & 0XFF;
    // 0x800C7AD0: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800C7AD4: bne         $v0, $zero, L_800C7A4C
    if (ctx->r2 != 0) {
        // 0x800C7AD8: addiu       $s3, $s3, 0x8
        ctx->r19 = ADD32(ctx->r19, 0X8);
            goto L_800C7A4C;
    }
    // 0x800C7AD8: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
L_800C7ADC:
    // 0x800C7ADC: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800C7AE0: lbu         $v1, 0x4C($s6)
    ctx->r3 = MEM_BU(ctx->r22, 0X4C);
    // 0x800C7AE4: andi        $v0, $s5, 0xFF
    ctx->r2 = ctx->r21 & 0XFF;
    // 0x800C7AE8: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800C7AEC: bne         $v0, $zero, L_800C7A10
    if (ctx->r2 != 0) {
        // 0x800C7AF0: andi        $v1, $s5, 0xFF
        ctx->r3 = ctx->r21 & 0XFF;
            goto L_800C7A10;
    }
    // 0x800C7AF0: andi        $v1, $s5, 0xFF
    ctx->r3 = ctx->r21 & 0XFF;
L_800C7AF4:
    // 0x800C7AF4: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800C7AF8: lhu         $v1, 0x7CC($s6)
    ctx->r3 = MEM_HU(ctx->r22, 0X7CC);
    // 0x800C7AFC: andi        $v0, $t0, 0xFF
    ctx->r2 = ctx->r8 & 0XFF;
    // 0x800C7B00: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800C7B04: bne         $v0, $zero, L_800C79AC
    if (ctx->r2 != 0) {
        // 0x800C7B08: nop
    
            goto L_800C79AC;
    }
    // 0x800C7B08: nop

L_800C7B0C:
    // 0x800C7B0C: lhu         $v0, 0x7D2($s6)
    ctx->r2 = MEM_HU(ctx->r22, 0X7D2);
    // 0x800C7B10: lhu         $v1, 0x7EC($s6)
    ctx->r3 = MEM_HU(ctx->r22, 0X7EC);
    // 0x800C7B14: lhu         $a0, 0x7D4($s6)
    ctx->r4 = MEM_HU(ctx->r22, 0X7D4);
    // 0x800C7B18: lhu         $a1, 0x7D0($s6)
    ctx->r5 = MEM_HU(ctx->r22, 0X7D0);
    // 0x800C7B1C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C7B20: sh          $v0, 0x7D2($s6)
    MEM_H(0X7D2, ctx->r22) = ctx->r2;
    // 0x800C7B24: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800C7B28: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800C7B2C: sltu        $v0, $v0, $a1
    ctx->r2 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x800C7B30: sh          $v1, 0x7EC($s6)
    MEM_H(0X7EC, ctx->r22) = ctx->r3;
    // 0x800C7B34: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800C7B38: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800C7B3C: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800C7B40: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800C7B44: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800C7B48: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800C7B4C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800C7B50: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800C7B54: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800C7B58: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C7B5C: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x800C7B60: jr          $ra
    // 0x800C7B64: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800C7B64: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_800C7978(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7978: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800C797C: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x800C7980: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x800C7984: sdc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X40, ctx->r29);
    // 0x800C7988: mtc1        $a3, $f22
    ctx->f22.u32l = ctx->r7;
    // 0x800C798C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800C7990: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800C7994: jal         0x80047B48
    // 0x800C7998: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    getLevelDatItemByName(rdram, ctx);
        goto after_0;
    // 0x800C7998: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    after_0:
    // 0x800C799C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800C79A0: beq         $a0, $zero, L_800C79D8
    if (ctx->r4 == 0) {
        // 0x800C79A4: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_800C79D8;
    }
    // 0x800C79A4: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800C79A8: lhu         $v1, 0x6($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X6);
    // 0x800C79AC: beq         $v1, $v0, L_800C79D8
    if (ctx->r3 == ctx->r2) {
        // 0x800C79B0: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_800C79D8;
    }
    // 0x800C79B0: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x800C79B4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800C79B8: sb          $v0, 0x28($sp)
    MEM_B(0X28, ctx->r29) = ctx->r2;
    // 0x800C79BC: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800C79C0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800C79C4: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x800C79C8: sb          $s0, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r16;
    // 0x800C79CC: lhu         $a0, 0x6($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X6);
    // 0x800C79D0: jal         0x8003E8DC
    // 0x800C79D4: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    slotDispatcherIter(rdram, ctx);
        goto after_1;
    // 0x800C79D4: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_1:
L_800C79D8:
    // 0x800C79D8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800C79DC: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800C79E0: ldc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X40);
    // 0x800C79E4: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x800C79E8: jr          $ra
    // 0x800C79EC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800C79EC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_800C79F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C79F0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C79F4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800C79F8: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x800C79FC: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x800C7A00: jal         0x80047B48
    // 0x800C7A04: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    getLevelDatItemByName(rdram, ctx);
        goto after_0;
    // 0x800C7A04: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    after_0:
    // 0x800C7A08: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800C7A0C: beq         $s0, $zero, L_800C7A98
    if (ctx->r16 == 0) {
        // 0x800C7A10: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_800C7A98;
    }
    // 0x800C7A10: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800C7A14: lhu         $v1, 0x6($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X6);
    // 0x800C7A18: beq         $v1, $v0, L_800C7A9C
    if (ctx->r3 == ctx->r2) {
        // 0x800C7A1C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800C7A9C;
    }
    // 0x800C7A1C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800C7A20: jal         0x80047B48
    // 0x800C7A24: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    getLevelDatItemByName(rdram, ctx);
        goto after_1;
    // 0x800C7A24: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_1:
    // 0x800C7A28: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x800C7A2C: beq         $s1, $zero, L_800C7A9C
    if (ctx->r17 == 0) {
        // 0x800C7A30: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800C7A9C;
    }
    // 0x800C7A30: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800C7A34: lhu         $a0, 0x6($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X6);
    // 0x800C7A38: jal         0x8004013C
    // 0x800C7A3C: nop

    getNpcContextByIndex(rdram, ctx);
        goto after_2;
    // 0x800C7A3C: nop

    after_2:
    // 0x800C7A40: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    // 0x800C7A44: beq         $a0, $zero, L_800C7A98
    if (ctx->r4 == 0) {
        // 0x800C7A48: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800C7A98;
    }
    // 0x800C7A48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C7A4C: lbu         $v1, 0x112($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X112);
    // 0x800C7A50: bne         $v1, $v0, L_800C7A68
    if (ctx->r3 != ctx->r2) {
        // 0x800C7A54: nop
    
            goto L_800C7A68;
    }
    // 0x800C7A54: nop

    // 0x800C7A58: lwc1        $f4, 0x4C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x800C7A5C: lwc1        $f2, 0x50($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X50);
    // 0x800C7A60: j           L_800C7A70
    // 0x800C7A64: nop

        goto L_800C7A70;
    // 0x800C7A64: nop

L_800C7A68:
    // 0x800C7A68: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800C7A6C: mov.s       $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.fl = ctx->f2.fl;
L_800C7A70:
    // 0x800C7A70: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800C7A74: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800C7A78: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800C7A7C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800C7A80: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x800C7A84: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800C7A88: jal         0x800F947C
    // 0x800C7A8C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    initActorAsType1(rdram, ctx);
        goto after_3;
    // 0x800C7A8C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x800C7A90: j           L_800C7A9C
    // 0x800C7A94: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
        goto L_800C7A9C;
    // 0x800C7A94: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_800C7A98:
    // 0x800C7A98: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800C7A9C:
    // 0x800C7A9C: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x800C7AA0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800C7AA4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C7AA8: jr          $ra
    // 0x800C7AAC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800C7AAC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_800C7AB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7AB0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800C7AB4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800C7AB8: addu        $s1, $a1, $zero
    ctx->r17 = ADD32(ctx->r5, 0);
    // 0x800C7ABC: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x800C7AC0: jal         0x80047B48
    // 0x800C7AC4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    getLevelDatItemByName(rdram, ctx);
        goto after_0;
    // 0x800C7AC4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    after_0:
    // 0x800C7AC8: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800C7ACC: beq         $s0, $zero, L_800C7B48
    if (ctx->r16 == 0) {
        // 0x800C7AD0: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_800C7B48;
    }
    // 0x800C7AD0: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800C7AD4: lhu         $v1, 0x6($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X6);
    // 0x800C7AD8: beq         $v1, $v0, L_800C7B4C
    if (ctx->r3 == ctx->r2) {
        // 0x800C7ADC: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800C7B4C;
    }
    // 0x800C7ADC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800C7AE0: jal         0x80047B48
    // 0x800C7AE4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    getLevelDatItemByName(rdram, ctx);
        goto after_1;
    // 0x800C7AE4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_1:
    // 0x800C7AE8: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x800C7AEC: beq         $s1, $zero, L_800C7B4C
    if (ctx->r17 == 0) {
        // 0x800C7AF0: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800C7B4C;
    }
    // 0x800C7AF0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800C7AF4: lhu         $a0, 0x6($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X6);
    // 0x800C7AF8: jal         0x8004013C
    // 0x800C7AFC: nop

    getNpcContextByIndex(rdram, ctx);
        goto after_2;
    // 0x800C7AFC: nop

    after_2:
    // 0x800C7B00: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    // 0x800C7B04: beq         $a0, $zero, L_800C7B48
    if (ctx->r4 == 0) {
        // 0x800C7B08: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800C7B48;
    }
    // 0x800C7B08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C7B0C: lbu         $v1, 0x112($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X112);
    // 0x800C7B10: bnel        $v1, $v0, L_800C7B4C
    if (ctx->r3 != ctx->r2) {
        // 0x800C7B14: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800C7B4C;
    }
    goto skip_0;
    // 0x800C7B14: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    skip_0:
    // 0x800C7B18: lwc1        $f0, 0x4C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x800C7B1C: lwc1        $f4, 0x50($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X50);
    // 0x800C7B20: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800C7B24: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800C7B28: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800C7B2C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800C7B30: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x800C7B34: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x800C7B38: jal         0x800F9674
    // 0x800C7B3C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    initActorAsType1WithAnchor(rdram, ctx);
        goto after_3;
    // 0x800C7B3C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x800C7B40: j           L_800C7B4C
    // 0x800C7B44: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
        goto L_800C7B4C;
    // 0x800C7B44: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_800C7B48:
    // 0x800C7B48: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800C7B4C:
    // 0x800C7B4C: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x800C7B50: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800C7B54: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C7B58: jr          $ra
    // 0x800C7B5C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800C7B5C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void getDatItemHealth(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7B60: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C7B64: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x800C7B68: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C7B6C: jal         0x80047B48
    // 0x800C7B70: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    getLevelDatItemByName(rdram, ctx);
        goto after_0;
    // 0x800C7B70: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x800C7B74: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800C7B78: beq         $s0, $zero, L_800C7C0C
    if (ctx->r16 == 0) {
        // 0x800C7B7C: ori         $s1, $zero, 0xFFFF
        ctx->r17 = 0 | 0XFFFF;
            goto L_800C7C0C;
    }
    // 0x800C7B7C: ori         $s1, $zero, 0xFFFF
    ctx->r17 = 0 | 0XFFFF;
    // 0x800C7B80: lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X6);
    // 0x800C7B84: beq         $v0, $s1, L_800C7BE4
    if (ctx->r2 == ctx->r17) {
        // 0x800C7B88: nop
    
            goto L_800C7BE4;
    }
    // 0x800C7B88: nop

    // 0x800C7B8C: jal         0x8004013C
    // 0x800C7B90: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    getNpcContextByIndex(rdram, ctx);
        goto after_1;
    // 0x800C7B90: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_1:
    // 0x800C7B94: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    // 0x800C7B98: beq         $a0, $zero, L_800C7BB0
    if (ctx->r4 == 0) {
        // 0x800C7B9C: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_800C7BB0;
    }
    // 0x800C7B9C: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800C7BA0: jal         0x800F20EC
    // 0x800C7BA4: nop

    getNpcCurrentHealth(rdram, ctx);
        goto after_2;
    // 0x800C7BA4: nop

    after_2:
    // 0x800C7BA8: j           L_800C7C14
    // 0x800C7BAC: nop

        goto L_800C7C14;
    // 0x800C7BAC: nop

L_800C7BB0:
    // 0x800C7BB0: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x800C7BB4: sh          $s1, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r17;
    // 0x800C7BB8: sh          $v0, 0x12($sp)
    MEM_H(0X12, ctx->r29) = ctx->r2;
    // 0x800C7BBC: lhu         $a0, 0x6($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X6);
    // 0x800C7BC0: jal         0x8003E8DC
    // 0x800C7BC4: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    slotDispatcherIter(rdram, ctx);
        goto after_3;
    // 0x800C7BC4: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_3:
    // 0x800C7BC8: lh          $v1, 0x12($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X12);
    // 0x800C7BCC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800C7BD0: beq         $v1, $v0, L_800C7C10
    if (ctx->r3 == ctx->r2) {
        // 0x800C7BD4: lui         $v0, 0x7FFF
        ctx->r2 = S32(0X7FFF << 16);
            goto L_800C7C10;
    }
    // 0x800C7BD4: lui         $v0, 0x7FFF
    ctx->r2 = S32(0X7FFF << 16);
    // 0x800C7BD8: lw          $v0, 0x14($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X14);
    // 0x800C7BDC: j           L_800C7C14
    // 0x800C7BE0: nop

        goto L_800C7C14;
    // 0x800C7BE0: nop

L_800C7BE4:
    // 0x800C7BE4: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x800C7BE8: bne         $v0, $zero, L_800C7C10
    if (ctx->r2 != 0) {
        // 0x800C7BEC: lui         $v0, 0x7FFF
        ctx->r2 = S32(0X7FFF << 16);
            goto L_800C7C10;
    }
    // 0x800C7BEC: lui         $v0, 0x7FFF
    ctx->r2 = S32(0X7FFF << 16);
    // 0x800C7BF0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C7BF4: lw          $v0, 0x7CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7CE4);
    // 0x800C7BF8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C7BFC: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800C7C00: lw          $v0, 0x6C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6C);
    // 0x800C7C04: j           L_800C7C14
    // 0x800C7C08: nop

        goto L_800C7C14;
    // 0x800C7C08: nop

L_800C7C0C:
    // 0x800C7C0C: lui         $v0, 0x7FFF
    ctx->r2 = S32(0X7FFF << 16);
L_800C7C10:
    // 0x800C7C10: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
L_800C7C14:
    // 0x800C7C14: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x800C7C18: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C7C1C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C7C20: jr          $ra
    // 0x800C7C24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C7C24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800C7B68(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7B68: addiu       $sp, $sp, -0x138
    ctx->r29 = ADD32(ctx->r29, -0X138);
    // 0x800C7B6C: addu        $t3, $sp, $zero
    ctx->r11 = ADD32(ctx->r29, 0);
    // 0x800C7B70: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x800C7B74: addiu       $t1, $sp, 0x60
    ctx->r9 = ADD32(ctx->r29, 0X60);
    // 0x800C7B78: addiu       $t0, $a2, 0x70
    ctx->r8 = ADD32(ctx->r6, 0X70);
    // 0x800C7B7C: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // 0x800C7B80: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800C7B84: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C7B88: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C7B8C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800C7B90: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C7B94: lw          $t6, 0x148($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X148);
    // 0x800C7B98: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x800C7B9C: sdc1        $f30, 0x130($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X130, ctx->r29);
    // 0x800C7BA0: sdc1        $f28, 0x128($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X128, ctx->r29);
    // 0x800C7BA4: sdc1        $f26, 0x120($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X120, ctx->r29);
    // 0x800C7BA8: sdc1        $f24, 0x118($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X118, ctx->r29);
    // 0x800C7BAC: sdc1        $f22, 0x110($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X110, ctx->r29);
    // 0x800C7BB0: sdc1        $f20, 0x108($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X108, ctx->r29);
    // 0x800C7BB4: lbu         $v0, 0x6FB($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6FB);
    // 0x800C7BB8: lw          $v1, 0x50($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X50);
    // 0x800C7BBC: sllv        $v0, $v0, $t5
    ctx->r2 = S32(ctx->r2 << (ctx->r13 & 31));
    // 0x800C7BC0: addiu       $v0, $v0, 0x2F8
    ctx->r2 = ADD32(ctx->r2, 0X2F8);
    // 0x800C7BC4: addu        $t2, $a0, $v0
    ctx->r10 = ADD32(ctx->r4, ctx->r2);
    // 0x800C7BC8: addiu       $t4, $v1, 0x80
    ctx->r12 = ADD32(ctx->r3, 0X80);
    // 0x800C7BCC: addiu       $v1, $t2, 0xE0
    ctx->r3 = ADD32(ctx->r10, 0XE0);
L_800C7BD0:
    // 0x800C7BD0: lh          $v0, -0x60($t0)
    ctx->r2 = MEM_H(ctx->r8, -0X60);
    // 0x800C7BD4: bne         $v0, $zero, L_800C7C74
    if (ctx->r2 != 0) {
        // 0x800C7BD8: nop
    
            goto L_800C7C74;
    }
    // 0x800C7BD8: nop

    // 0x800C7BDC: lh          $v0, -0x50($t0)
    ctx->r2 = MEM_H(ctx->r8, -0X50);
    // 0x800C7BE0: bne         $v0, $zero, L_800C7C74
    if (ctx->r2 != 0) {
        // 0x800C7BE4: nop
    
            goto L_800C7C74;
    }
    // 0x800C7BE4: nop

    // 0x800C7BE8: lh          $v0, -0x40($t0)
    ctx->r2 = MEM_H(ctx->r8, -0X40);
    // 0x800C7BEC: bne         $v0, $zero, L_800C7C74
    if (ctx->r2 != 0) {
        // 0x800C7BF0: nop
    
            goto L_800C7C74;
    }
    // 0x800C7BF0: nop

    // 0x800C7BF4: lh          $v0, -0x30($t0)
    ctx->r2 = MEM_H(ctx->r8, -0X30);
    // 0x800C7BF8: bne         $v0, $zero, L_800C7C74
    if (ctx->r2 != 0) {
        // 0x800C7BFC: nop
    
            goto L_800C7C74;
    }
    // 0x800C7BFC: nop

    // 0x800C7C00: lh          $v0, -0x20($t0)
    ctx->r2 = MEM_H(ctx->r8, -0X20);
    // 0x800C7C04: bne         $v0, $zero, L_800C7C74
    if (ctx->r2 != 0) {
        // 0x800C7C08: nop
    
            goto L_800C7C74;
    }
    // 0x800C7C08: nop

    // 0x800C7C0C: lh          $v0, -0x10($t0)
    ctx->r2 = MEM_H(ctx->r8, -0X10);
    // 0x800C7C10: bne         $v0, $zero, L_800C7C74
    if (ctx->r2 != 0) {
        // 0x800C7C14: nop
    
            goto L_800C7C74;
    }
    // 0x800C7C14: nop

    // 0x800C7C18: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x800C7C1C: bne         $v0, $zero, L_800C7C74
    if (ctx->r2 != 0) {
        // 0x800C7C20: nop
    
            goto L_800C7C74;
    }
    // 0x800C7C20: nop

    // 0x800C7C24: lh          $v0, 0x0($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X0);
    // 0x800C7C28: lwc1        $f2, 0x0($t2)
    ctx->f2.u32l = MEM_W(ctx->r10, 0X0);
    // 0x800C7C2C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800C7C30: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800C7C34: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C7C38: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x800C7C3C: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x800C7C40: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800C7C44: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x800C7C48: swc1        $f0, 0x80($t1)
    MEM_W(0X80, ctx->r9) = ctx->f0.u32l;
    // 0x800C7C4C: swc1        $f0, 0x60($t1)
    MEM_W(0X60, ctx->r9) = ctx->f0.u32l;
    // 0x800C7C50: swc1        $f0, 0x40($t1)
    MEM_W(0X40, ctx->r9) = ctx->f0.u32l;
    // 0x800C7C54: swc1        $f0, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->f0.u32l;
    // 0x800C7C58: swc1        $f0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f0.u32l;
    // 0x800C7C5C: swc1        $f0, -0x20($t1)
    MEM_W(-0X20, ctx->r9) = ctx->f0.u32l;
    // 0x800C7C60: swc1        $f0, -0x40($t1)
    MEM_W(-0X40, ctx->r9) = ctx->f0.u32l;
    // 0x800C7C64: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x800C7C68: swc1        $f0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f0.u32l;
    // 0x800C7C6C: j           L_800C7DFC
    // 0x800C7C70: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
        goto L_800C7DFC;
    // 0x800C7C70: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
L_800C7C74:
    // 0x800C7C74: lh          $v0, 0x0($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X0);
    // 0x800C7C78: lwc1        $f2, 0x0($t2)
    ctx->f2.u32l = MEM_W(ctx->r10, 0X0);
    // 0x800C7C7C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800C7C80: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800C7C84: mul.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C7C88: lh          $v0, -0x50($t0)
    ctx->r2 = MEM_H(ctx->r8, -0X50);
    // 0x800C7C8C: lwc1        $f2, -0xA0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, -0XA0);
    // 0x800C7C90: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800C7C94: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800C7C98: mul.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C7C9C: lh          $v0, -0x30($t0)
    ctx->r2 = MEM_H(ctx->r8, -0X30);
    // 0x800C7CA0: lwc1        $f2, -0x60($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, -0X60);
    // 0x800C7CA4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800C7CA8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800C7CAC: mul.s       $f24, $f0, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C7CB0: lh          $v0, -0x10($t0)
    ctx->r2 = MEM_H(ctx->r8, -0X10);
    // 0x800C7CB4: lwc1        $f2, -0x20($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, -0X20);
    // 0x800C7CB8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800C7CBC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800C7CC0: mul.s       $f26, $f0, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f26.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C7CC4: lh          $v0, -0x60($t0)
    ctx->r2 = MEM_H(ctx->r8, -0X60);
    // 0x800C7CC8: lwc1        $f2, -0xC0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, -0XC0);
    // 0x800C7CCC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800C7CD0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800C7CD4: mul.s       $f20, $f0, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C7CD8: lh          $v0, -0x40($t0)
    ctx->r2 = MEM_H(ctx->r8, -0X40);
    // 0x800C7CDC: lwc1        $f2, -0x80($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, -0X80);
    // 0x800C7CE0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800C7CE4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800C7CE8: mul.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C7CEC: lh          $v0, -0x20($t0)
    ctx->r2 = MEM_H(ctx->r8, -0X20);
    // 0x800C7CF0: lwc1        $f2, -0x40($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, -0X40);
    // 0x800C7CF4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800C7CF8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800C7CFC: mul.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C7D00: lh          $v0, 0x0($t0)
    ctx->r2 = MEM_H(ctx->r8, 0X0);
    // 0x800C7D04: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800C7D08: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800C7D0C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800C7D10: mul.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C7D14: sub.s       $f22, $f16, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f22.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x800C7D18: sub.s       $f28, $f20, $f8
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f28.fl = ctx->f20.fl - ctx->f8.fl;
    // 0x800C7D1C: add.s       $f2, $f22, $f28
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f2.fl = ctx->f22.fl + ctx->f28.fl;
    // 0x800C7D20: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C7D24: lwc1        $f0, 0x7874($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7874);
    // 0x800C7D28: mul.s       $f30, $f2, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f30.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800C7D2C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C7D30: lwc1        $f2, 0x7878($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7878);
    // 0x800C7D34: mul.s       $f2, $f28, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f28.fl, ctx->f2.fl);
    // 0x800C7D38: swc1        $f22, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f22.u32l;
    // 0x800C7D3C: sub.s       $f0, $f6, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f26.fl;
    // 0x800C7D40: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C7D44: lwc1        $f22, 0x787C($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X787C);
    // 0x800C7D48: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800C7D4C: add.s       $f14, $f10, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f24.fl;
    // 0x800C7D50: sub.s       $f18, $f10, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f24.fl;
    // 0x800C7D54: add.s       $f4, $f6, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f26.fl;
    // 0x800C7D58: add.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x800C7D5C: add.s       $f8, $f20, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f20.fl + ctx->f8.fl;
    // 0x800C7D60: sub.s       $f16, $f0, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800C7D64: sub.s       $f0, $f8, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x800C7D68: add.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800C7D6C: sub.s       $f24, $f18, $f16
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f24.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x800C7D70: mul.s       $f18, $f0, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800C7D74: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C7D78: lwc1        $f0, 0x7880($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7880);
    // 0x800C7D7C: lwc1        $f22, 0x100($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X100);
    // 0x800C7D80: mul.s       $f0, $f22, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x800C7D84: add.s       $f10, $f14, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f4.fl;
    // 0x800C7D88: sub.s       $f26, $f14, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f26.fl = ctx->f14.fl - ctx->f4.fl;
    // 0x800C7D8C: sub.s       $f14, $f2, $f30
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f30.fl;
    // 0x800C7D90: add.s       $f8, $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x800C7D94: add.s       $f2, $f10, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800C7D98: add.s       $f16, $f0, $f30
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f30.fl;
    // 0x800C7D9C: sub.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x800C7DA0: sub.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800C7DA4: sub.s       $f12, $f18, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x800C7DA8: add.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800C7DAC: sub.s       $f6, $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x800C7DB0: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x800C7DB4: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x800C7DB8: add.s       $f20, $f14, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f20.fl = ctx->f14.fl + ctx->f12.fl;
    // 0x800C7DBC: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x800C7DC0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800C7DC4: add.s       $f0, $f24, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f24.fl + ctx->f12.fl;
    // 0x800C7DC8: swc1        $f2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f2.u32l;
    // 0x800C7DCC: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
    // 0x800C7DD0: sub.s       $f4, $f24, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f24.fl - ctx->f12.fl;
    // 0x800C7DD4: swc1        $f8, 0x80($t1)
    MEM_W(0X80, ctx->r9) = ctx->f8.u32l;
    // 0x800C7DD8: swc1        $f10, -0x40($t1)
    MEM_W(-0X40, ctx->r9) = ctx->f10.u32l;
    // 0x800C7DDC: add.s       $f2, $f26, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f26.fl + ctx->f20.fl;
    // 0x800C7DE0: swc1        $f6, 0x60($t1)
    MEM_W(0X60, ctx->r9) = ctx->f6.u32l;
    // 0x800C7DE4: swc1        $f0, -0x20($t1)
    MEM_W(-0X20, ctx->r9) = ctx->f0.u32l;
    // 0x800C7DE8: sub.s       $f0, $f26, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f26.fl - ctx->f20.fl;
    // 0x800C7DEC: swc1        $f4, 0x40($t1)
    MEM_W(0X40, ctx->r9) = ctx->f4.u32l;
    // 0x800C7DF0: swc1        $f2, 0x20($t1)
    MEM_W(0X20, ctx->r9) = ctx->f2.u32l;
    // 0x800C7DF4: swc1        $f0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f0.u32l;
    // 0x800C7DF8: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
L_800C7DFC:
    // 0x800C7DFC: addiu       $t5, $t5, -0x1
    ctx->r13 = ADD32(ctx->r13, -0X1);
    // 0x800C7E00: bne         $t5, $zero, L_800C7BD0
    if (ctx->r13 != 0) {
        // 0x800C7E04: nop
    
            goto L_800C7BD0;
    }
    // 0x800C7E04: nop

    // 0x800C7E08: addu        $t3, $sp, $zero
    ctx->r11 = ADD32(ctx->r29, 0);
    // 0x800C7E0C: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // 0x800C7E10: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800C7E14: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C7E18: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C7E1C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800C7E20: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C7E24: addu        $a2, $a0, $v0
    ctx->r6 = ADD32(ctx->r4, ctx->r2);
    // 0x800C7E28: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
L_800C7E2C:
    // 0x800C7E2C: lwc1        $f16, -0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, -0X8);
    // 0x800C7E30: lwc1        $f12, -0x10($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, -0X10);
    // 0x800C7E34: sub.s       $f22, $f16, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f22.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x800C7E38: swc1        $f22, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->f22.u32l;
    // 0x800C7E3C: lw          $v1, 0x700($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X700);
    // 0x800C7E40: addu        $v0, $t6, $t5
    ctx->r2 = ADD32(ctx->r14, ctx->r13);
    // 0x800C7E44: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C7E48: lwc1        $f8, -0x18($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, -0X18);
    // 0x800C7E4C: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800C7E50: sub.s       $f28, $f8, $f6
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f28.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800C7E54: add.s       $f2, $f22, $f28
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f2.fl = ctx->f22.fl + ctx->f28.fl;
    // 0x800C7E58: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C7E5C: lwc1        $f0, 0x7884($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7884);
    // 0x800C7E60: mul.s       $f30, $f2, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f30.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800C7E64: lwc1        $f4, -0x14($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, -0X14);
    // 0x800C7E68: lwc1        $f2, -0x4($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, -0X4);
    // 0x800C7E6C: sub.s       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x800C7E70: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C7E74: lwc1        $f22, 0x7888($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X7888);
    // 0x800C7E78: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800C7E7C: add.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x800C7E80: lwc1        $f14, 0x0($t3)
    ctx->f14.u32l = MEM_W(ctx->r11, 0X0);
    // 0x800C7E84: lwc1        $f10, -0xC($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, -0XC);
    // 0x800C7E88: sub.s       $f18, $f14, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f14.fl - ctx->f10.fl;
    // 0x800C7E8C: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800C7E90: add.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800C7E94: sub.s       $f16, $f0, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800C7E98: sub.s       $f0, $f8, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f12.fl;
    // 0x800C7E9C: add.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800C7EA0: sub.s       $f24, $f18, $f16
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f24.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x800C7EA4: mul.s       $f18, $f0, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800C7EA8: add.s       $f14, $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x800C7EAC: mflo        $t7
    ctx->r15 = lo;
    // 0x800C7EB0: add.s       $f10, $f14, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f4.fl;
    // 0x800C7EB4: add.s       $f8, $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x800C7EB8: lw          $v1, 0x708($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X708);
    // 0x800C7EBC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C7EC0: lwc1        $f0, 0x788C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X788C);
    // 0x800C7EC4: add.s       $f2, $f10, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800C7EC8: lwc1        $f22, 0x100($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X100);
    // 0x800C7ECC: addu        $a0, $a3, $t7
    ctx->r4 = ADD32(ctx->r7, ctx->r15);
    // 0x800C7ED0: mul.s       $f0, $f22, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x800C7ED4: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800C7ED8: trunc.w.s   $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    ctx->f22.u32l = TRUNC_W_S(ctx->f2.fl);
    // 0x800C7EDC: mfc1        $v0, $f22
    ctx->r2 = (int32_t)ctx->f22.u32l;
    // 0x800C7EE0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800C7EE4: sra         $v0, $v0, 3
    ctx->r2 = S32(SIGNED(ctx->r2) >> 3);
    // 0x800C7EE8: add.s       $f16, $f0, $f30
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f30.fl;
    // 0x800C7EEC: andi        $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 & 0X3FF;
    // 0x800C7EF0: addu        $v0, $t4, $v0
    ctx->r2 = ADD32(ctx->r12, ctx->r2);
    // 0x800C7EF4: sub.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800C7EF8: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800C7EFC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C7F00: lwc1        $f2, 0x7890($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7890);
    // 0x800C7F04: sub.s       $f26, $f14, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f26.fl = ctx->f14.fl - ctx->f4.fl;
    // 0x800C7F08: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x800C7F0C: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C7F10: mfc1        $v0, $f22
    ctx->r2 = (int32_t)ctx->f22.u32l;
    // 0x800C7F14: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800C7F18: sub.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x800C7F1C: sra         $v0, $v0, 3
    ctx->r2 = S32(SIGNED(ctx->r2) >> 3);
    // 0x800C7F20: andi        $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 & 0X3FF;
    // 0x800C7F24: add.s       $f0, $f6, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800C7F28: addu        $v0, $t4, $v0
    ctx->r2 = ADD32(ctx->r12, ctx->r2);
    // 0x800C7F2C: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800C7F30: mul.s       $f2, $f28, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f28.fl, ctx->f2.fl);
    // 0x800C7F34: sb          $v0, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r2;
    // 0x800C7F38: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C7F3C: mfc1        $v0, $f22
    ctx->r2 = (int32_t)ctx->f22.u32l;
    // 0x800C7F40: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800C7F44: sra         $v0, $v0, 3
    ctx->r2 = S32(SIGNED(ctx->r2) >> 3);
    // 0x800C7F48: andi        $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 & 0X3FF;
    // 0x800C7F4C: sub.s       $f0, $f6, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x800C7F50: addu        $v0, $t4, $v0
    ctx->r2 = ADD32(ctx->r12, ctx->r2);
    // 0x800C7F54: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800C7F58: sub.s       $f12, $f18, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x800C7F5C: sb          $v0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r2;
    // 0x800C7F60: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C7F64: mfc1        $v0, $f22
    ctx->r2 = (int32_t)ctx->f22.u32l;
    // 0x800C7F68: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800C7F6C: sra         $v0, $v0, 3
    ctx->r2 = S32(SIGNED(ctx->r2) >> 3);
    // 0x800C7F70: andi        $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 & 0X3FF;
    // 0x800C7F74: add.s       $f0, $f24, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f24.fl + ctx->f12.fl;
    // 0x800C7F78: addu        $v0, $t4, $v0
    ctx->r2 = ADD32(ctx->r12, ctx->r2);
    // 0x800C7F7C: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800C7F80: sub.s       $f14, $f2, $f30
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f30.fl;
    // 0x800C7F84: sb          $v0, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r2;
    // 0x800C7F88: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C7F8C: mfc1        $v0, $f22
    ctx->r2 = (int32_t)ctx->f22.u32l;
    // 0x800C7F90: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800C7F94: sra         $v0, $v0, 3
    ctx->r2 = S32(SIGNED(ctx->r2) >> 3);
    // 0x800C7F98: andi        $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 & 0X3FF;
    // 0x800C7F9C: sub.s       $f0, $f24, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f24.fl - ctx->f12.fl;
    // 0x800C7FA0: addu        $v0, $t4, $v0
    ctx->r2 = ADD32(ctx->r12, ctx->r2);
    // 0x800C7FA4: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800C7FA8: add.s       $f20, $f14, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f20.fl = ctx->f14.fl + ctx->f12.fl;
    // 0x800C7FAC: sb          $v0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r2;
    // 0x800C7FB0: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C7FB4: mfc1        $v0, $f22
    ctx->r2 = (int32_t)ctx->f22.u32l;
    // 0x800C7FB8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800C7FBC: sra         $v0, $v0, 3
    ctx->r2 = S32(SIGNED(ctx->r2) >> 3);
    // 0x800C7FC0: andi        $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 & 0X3FF;
    // 0x800C7FC4: addu        $v0, $t4, $v0
    ctx->r2 = ADD32(ctx->r12, ctx->r2);
    // 0x800C7FC8: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800C7FCC: add.s       $f0, $f26, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f26.fl + ctx->f20.fl;
    // 0x800C7FD0: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x800C7FD4: sb          $v0, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r2;
    // 0x800C7FD8: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C7FDC: mfc1        $v0, $f22
    ctx->r2 = (int32_t)ctx->f22.u32l;
    // 0x800C7FE0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800C7FE4: sra         $v0, $v0, 3
    ctx->r2 = S32(SIGNED(ctx->r2) >> 3);
    // 0x800C7FE8: andi        $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 & 0X3FF;
    // 0x800C7FEC: addu        $v0, $t4, $v0
    ctx->r2 = ADD32(ctx->r12, ctx->r2);
    // 0x800C7FF0: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800C7FF4: sub.s       $f0, $f26, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f26.fl - ctx->f20.fl;
    // 0x800C7FF8: addiu       $t3, $t3, 0x20
    ctx->r11 = ADD32(ctx->r11, 0X20);
    // 0x800C7FFC: sb          $v0, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r2;
    // 0x800C8000: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C8004: mfc1        $v0, $f22
    ctx->r2 = (int32_t)ctx->f22.u32l;
    // 0x800C8008: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800C800C: sra         $v0, $v0, 3
    ctx->r2 = S32(SIGNED(ctx->r2) >> 3);
    // 0x800C8010: andi        $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 & 0X3FF;
    // 0x800C8014: addu        $v0, $t4, $v0
    ctx->r2 = ADD32(ctx->r12, ctx->r2);
    // 0x800C8018: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800C801C: sb          $v0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r2;
    // 0x800C8020: sltiu       $v0, $t5, 0x8
    ctx->r2 = ctx->r13 < 0X8 ? 1 : 0;
    // 0x800C8024: bne         $v0, $zero, L_800C7E2C
    if (ctx->r2 != 0) {
        // 0x800C8028: addiu       $a1, $a1, 0x20
        ctx->r5 = ADD32(ctx->r5, 0X20);
            goto L_800C7E2C;
    }
    // 0x800C8028: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // 0x800C802C: ldc1        $f30, 0x130($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X130);
    // 0x800C8030: ldc1        $f28, 0x128($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X128);
    // 0x800C8034: ldc1        $f26, 0x120($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X120);
    // 0x800C8038: ldc1        $f24, 0x118($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X118);
    // 0x800C803C: ldc1        $f22, 0x110($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X110);
    // 0x800C8040: ldc1        $f20, 0x108($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X108);
    // 0x800C8044: jr          $ra
    // 0x800C8048: addiu       $sp, $sp, 0x138
    ctx->r29 = ADD32(ctx->r29, 0X138);
    return;
    // 0x800C8048: addiu       $sp, $sp, 0x138
    ctx->r29 = ADD32(ctx->r29, 0X138);
;}
RECOMP_FUNC void getDatItemHealthPercentage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7C28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C7C2C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800C7C30: jal         0x80047B48
    // 0x800C7C34: nop

    getLevelDatItemByName(rdram, ctx);
        goto after_0;
    // 0x800C7C34: nop

    after_0:
    // 0x800C7C38: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800C7C3C: beq         $a0, $zero, L_800C7C74
    if (ctx->r4 == 0) {
        // 0x800C7C40: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_800C7C74;
    }
    // 0x800C7C40: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800C7C44: lhu         $v1, 0x6($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X6);
    // 0x800C7C48: beq         $v1, $v0, L_800C7C74
    if (ctx->r3 == ctx->r2) {
        // 0x800C7C4C: nop
    
            goto L_800C7C74;
    }
    // 0x800C7C4C: nop

    // 0x800C7C50: jal         0x8004013C
    // 0x800C7C54: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    getNpcContextByIndex(rdram, ctx);
        goto after_1;
    // 0x800C7C54: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    after_1:
    // 0x800C7C58: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    // 0x800C7C5C: beq         $a0, $zero, L_800C7C74
    if (ctx->r4 == 0) {
        // 0x800C7C60: nop
    
            goto L_800C7C74;
    }
    // 0x800C7C60: nop

    // 0x800C7C64: jal         0x800F219C
    // 0x800C7C68: nop

    getNpcHealthPercentage(rdram, ctx);
        goto after_2;
    // 0x800C7C68: nop

    after_2:
    // 0x800C7C6C: j           L_800C7C7C
    // 0x800C7C70: nop

        goto L_800C7C7C;
    // 0x800C7C70: nop

L_800C7C74:
    // 0x800C7C74: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C7C78: lwc1        $f0, 0x6968($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6968);
L_800C7C7C:
    // 0x800C7C7C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800C7C80: jr          $ra
    // 0x800C7C84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C7C84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800C7C88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7C88: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C7C8C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800C7C90: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800C7C94: jal         0x80047B48
    // 0x800C7C98: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    getLevelDatItemByName(rdram, ctx);
        goto after_0;
    // 0x800C7C98: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    after_0:
    // 0x800C7C9C: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800C7CA0: beq         $a0, $zero, L_800C7CDC
    if (ctx->r4 == 0) {
        // 0x800C7CA4: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_800C7CDC;
    }
    // 0x800C7CA4: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800C7CA8: lhu         $v1, 0x6($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X6);
    // 0x800C7CAC: beq         $v1, $v0, L_800C7CDC
    if (ctx->r3 == ctx->r2) {
        // 0x800C7CB0: nop
    
            goto L_800C7CDC;
    }
    // 0x800C7CB0: nop

    // 0x800C7CB4: bltz        $s0, L_800C7CDC
    if (SIGNED(ctx->r16) < 0) {
        // 0x800C7CB8: slti        $v0, $s0, 0x3
        ctx->r2 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
            goto L_800C7CDC;
    }
    // 0x800C7CB8: slti        $v0, $s0, 0x3
    ctx->r2 = SIGNED(ctx->r16) < 0X3 ? 1 : 0;
    // 0x800C7CBC: beq         $v0, $zero, L_800C7CDC
    if (ctx->r2 == 0) {
        // 0x800C7CC0: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_800C7CDC;
    }
    // 0x800C7CC0: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800C7CC4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800C7CC8: sb          $v0, 0x28($sp)
    MEM_B(0X28, ctx->r29) = ctx->r2;
    // 0x800C7CCC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800C7CD0: lhu         $a0, 0x6($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X6);
    // 0x800C7CD4: jal         0x8003E8DC
    // 0x800C7CD8: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    slotDispatcherIter(rdram, ctx);
        goto after_1;
    // 0x800C7CD8: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    after_1:
L_800C7CDC:
    // 0x800C7CDC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800C7CE0: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800C7CE4: jr          $ra
    // 0x800C7CE8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800C7CE8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void setLevelObjectTrackingScalar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7CEC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800C7CF0: jr          $ra
    // 0x800C7CF4: swc1        $f12, -0x68C4($v0)
    MEM_W(-0X68C4, ctx->r2) = ctx->f12.u32l;
    return;
    // 0x800C7CF4: swc1        $f12, -0x68C4($v0)
    MEM_W(-0X68C4, ctx->r2) = ctx->f12.u32l;
;}
RECOMP_FUNC void playObjectiveVoiceLine1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7CF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C7CFC: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x800C7D00: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800C7D04: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800C7D08: jal         0x80066EE4
    // 0x800C7D0C: addiu       $a3, $zero, 0x43
    ctx->r7 = ADD32(0, 0X43);
    playSpeechClip(rdram, ctx);
        goto after_0;
    // 0x800C7D0C: addiu       $a3, $zero, 0x43
    ctx->r7 = ADD32(0, 0X43);
    after_0:
    // 0x800C7D10: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800C7D14: jr          $ra
    // 0x800C7D18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C7D18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playObjectiveVoiceLine2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7D1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C7D20: mtc1        $a1, $f0
    ctx->f0.u32l = ctx->r5;
    // 0x800C7D24: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x800C7D28: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800C7D2C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800C7D30: jal         0x80066EE4
    // 0x800C7D34: addiu       $a3, $zero, 0x43
    ctx->r7 = ADD32(0, 0X43);
    playSpeechClip(rdram, ctx);
        goto after_0;
    // 0x800C7D34: addiu       $a3, $zero, 0x43
    ctx->r7 = ADD32(0, 0X43);
    after_0:
    // 0x800C7D38: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800C7D3C: jr          $ra
    // 0x800C7D40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C7D40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800C7D44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7D44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C7D48: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800C7D4C: jal         0x80067938
    // 0x800C7D50: nop

    func_80067938(rdram, ctx);
        goto after_0;
    // 0x800C7D50: nop

    after_0:
    // 0x800C7D54: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800C7D58: jr          $ra
    // 0x800C7D5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C7D5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void delegateToLevelStageTick(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7D60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C7D64: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800C7D68: jal         0x800EF770
    // 0x800C7D6C: nop

    func_800EF770(rdram, ctx);
        goto after_0;
    // 0x800C7D6C: nop

    after_0:
    // 0x800C7D70: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800C7D74: jr          $ra
    // 0x800C7D78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C7D78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800C7D7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7D7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C7D80: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800C7D84: jal         0x800EF95C
    // 0x800C7D88: nop

    func_800EF95C(rdram, ctx);
        goto after_0;
    // 0x800C7D88: nop

    after_0:
    // 0x800C7D8C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800C7D90: jr          $ra
    // 0x800C7D94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C7D94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void triggerSoundCueByType(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7D98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C7D9C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x800C7DA0: jal         0x800EFCD4
    // 0x800C7DA4: nop

    initSoundCueRequest(rdram, ctx);
        goto after_0;
    // 0x800C7DA4: nop

    after_0:
    // 0x800C7DA8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x800C7DAC: jr          $ra
    // 0x800C7DB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C7DB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void fake_func_800C7DB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_800C7DC0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7DC0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C7DC4: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x800C7DC8: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800C7DCC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800C7DD0: lw          $s0, 0x4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X4);
    // 0x800C7DD4: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x800C7DD8: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x800C7DDC: jal         0x800F2070
    // 0x800C7DE0: addiu       $a1, $a2, 0x6C
    ctx->r5 = ADD32(ctx->r6, 0X6C);
    setNpcHealth(rdram, ctx);
        goto after_0;
    // 0x800C7DE0: addiu       $a1, $a2, 0x6C
    ctx->r5 = ADD32(ctx->r6, 0X6C);
    after_0:
    // 0x800C7DE4: blez        $v0, L_800C7DF4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800C7DE8: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_800C7DF4;
    }
    // 0x800C7DE8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800C7DEC: j           L_800C7DF8
    // 0x800C7DF0: sh          $zero, 0x72($s0)
    MEM_H(0X72, ctx->r16) = 0;
        goto L_800C7DF8;
    // 0x800C7DF0: sh          $zero, 0x72($s0)
    MEM_H(0X72, ctx->r16) = 0;
L_800C7DF4:
    // 0x800C7DF4: sh          $v0, 0x72($s0)
    MEM_H(0X72, ctx->r16) = ctx->r2;
L_800C7DF8:
    // 0x800C7DF8: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800C7DFC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C7E00: lwc1        $f0, 0x6970($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6970);
    // 0x800C7E04: lw          $v1, 0x7CE4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X7CE4);
    // 0x800C7E08: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x800C7E0C: sw          $zero, 0x84($s0)
    MEM_W(0X84, ctx->r16) = 0;
    // 0x800C7E10: sw          $zero, 0x80($s0)
    MEM_W(0X80, ctx->r16) = 0;
    // 0x800C7E14: sh          $zero, 0x74($s0)
    MEM_H(0X74, ctx->r16) = 0;
    // 0x800C7E18: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800C7E1C: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x800C7E20: swc1        $f0, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f0.u32l;
    // 0x800C7E24: lwc1        $f0, 0x9C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X9C);
    // 0x800C7E28: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x800C7E2C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C7E30: swc1        $f0, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f0.u32l;
    // 0x800C7E34: lwc1        $f0, 0xA8($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XA8);
    // 0x800C7E38: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800C7E3C: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x800C7E40: lw          $a1, 0x98($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X98);
    // 0x800C7E44: lw          $a2, 0xA0($v1)
    ctx->r6 = MEM_W(ctx->r3, 0XA0);
    // 0x800C7E48: lw          $a3, 0xA4($v1)
    ctx->r7 = MEM_W(ctx->r3, 0XA4);
    // 0x800C7E4C: jal         0x800F2888
    // 0x800C7E50: nop

    initActorMotionParams(rdram, ctx);
        goto after_1;
    // 0x800C7E50: nop

    after_1:
    // 0x800C7E54: lw          $v0, 0x34($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X34);
    // 0x800C7E58: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x800C7E5C: lw          $a1, 0x8C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8C);
    // 0x800C7E60: jal         0x800F2830
    // 0x800C7E64: nop

    setObjectDetailLevel(rdram, ctx);
        goto after_2;
    // 0x800C7E64: nop

    after_2:
    // 0x800C7E68: lh          $v1, 0x70($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X70);
    // 0x800C7E6C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800C7E70: beq         $v1, $v0, L_800C7EF0
    if (ctx->r3 == ctx->r2) {
        // 0x800C7E74: slti        $v0, $v1, 0x4
        ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
            goto L_800C7EF0;
    }
    // 0x800C7E74: slti        $v0, $v1, 0x4
    ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x800C7E78: beq         $v0, $zero, L_800C7E90
    if (ctx->r2 == 0) {
        // 0x800C7E7C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800C7E90;
    }
    // 0x800C7E7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C7E80: beq         $v1, $v0, L_800C7EA4
    if (ctx->r3 == ctx->r2) {
        // 0x800C7E84: lui         $v1, 0x800C
        ctx->r3 = S32(0X800C << 16);
            goto L_800C7EA4;
    }
    // 0x800C7E84: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x800C7E88: j           L_800C7F88
    // 0x800C7E8C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
        goto L_800C7F88;
    // 0x800C7E8C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_800C7E90:
    // 0x800C7E90: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800C7E94: beq         $v1, $v0, L_800C7F3C
    if (ctx->r3 == ctx->r2) {
        // 0x800C7E98: lui         $v1, 0x800C
        ctx->r3 = S32(0X800C << 16);
            goto L_800C7F3C;
    }
    // 0x800C7E98: lui         $v1, 0x800C
    ctx->r3 = S32(0X800C << 16);
    // 0x800C7E9C: j           L_800C7F88
    // 0x800C7EA0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
        goto L_800C7F88;
    // 0x800C7EA0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_800C7EA4:
    // 0x800C7EA4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800C7EA8: addiu       $v0, $v0, -0x7E88
    ctx->r2 = ADD32(ctx->r2, -0X7E88);
    // 0x800C7EAC: lw          $a3, 0x34($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X34);
    // 0x800C7EB0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C7EB4: lwc1        $f0, 0x6974($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6974);
    // 0x800C7EB8: lw          $v1, 0x7CE4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X7CE4);
    // 0x800C7EBC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C7EC0: lwc1        $f2, 0x6978($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6978);
    // 0x800C7EC4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800C7EC8: lwc1        $f4, 0xB8($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0XB8);
    // 0x800C7ECC: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x800C7ED0: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x800C7ED4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800C7ED8: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800C7EDC: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    // 0x800C7EE0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800C7EE4: lwc1        $f0, 0xBC($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XBC);
    // 0x800C7EE8: j           L_800C7FCC
    // 0x800C7EEC: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
        goto L_800C7FCC;
    // 0x800C7EEC: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
L_800C7EF0:
    // 0x800C7EF0: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800C7EF4: addiu       $v0, $v0, -0x5E74
    ctx->r2 = ADD32(ctx->r2, -0X5E74);
    // 0x800C7EF8: lw          $a3, 0x34($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X34);
    // 0x800C7EFC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C7F00: lwc1        $f0, 0x697C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X697C);
    // 0x800C7F04: lw          $v1, 0x7CE4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X7CE4);
    // 0x800C7F08: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C7F0C: lwc1        $f2, 0x6980($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6980);
    // 0x800C7F10: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800C7F14: lwc1        $f4, 0xB8($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0XB8);
    // 0x800C7F18: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x800C7F1C: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x800C7F20: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800C7F24: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800C7F28: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    // 0x800C7F2C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800C7F30: lwc1        $f0, 0xBC($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XBC);
    // 0x800C7F34: j           L_800C7FCC
    // 0x800C7F38: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
        goto L_800C7FCC;
    // 0x800C7F38: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
L_800C7F3C:
    // 0x800C7F3C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800C7F40: addiu       $v0, $v0, -0x7AFC
    ctx->r2 = ADD32(ctx->r2, -0X7AFC);
    // 0x800C7F44: lw          $a3, 0x34($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X34);
    // 0x800C7F48: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C7F4C: lwc1        $f0, 0x6984($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6984);
    // 0x800C7F50: lw          $v1, 0x7CE4($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X7CE4);
    // 0x800C7F54: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C7F58: lwc1        $f2, 0x6988($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6988);
    // 0x800C7F5C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800C7F60: lwc1        $f4, 0xB8($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0XB8);
    // 0x800C7F64: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x800C7F68: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x800C7F6C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800C7F70: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800C7F74: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    // 0x800C7F78: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800C7F7C: lwc1        $f0, 0xBC($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XBC);
    // 0x800C7F80: j           L_800C7FCC
    // 0x800C7F84: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
        goto L_800C7FCC;
    // 0x800C7F84: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
L_800C7F88:
    // 0x800C7F88: addiu       $v1, $v1, 0x7FF8
    ctx->r3 = ADD32(ctx->r3, 0X7FF8);
    // 0x800C7F8C: lw          $a3, 0x34($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X34);
    // 0x800C7F90: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C7F94: lwc1        $f0, 0x698C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X698C);
    // 0x800C7F98: lw          $v0, 0x7CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7CE4);
    // 0x800C7F9C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C7FA0: lwc1        $f2, 0x6990($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6990);
    // 0x800C7FA4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C7FA8: lwc1        $f4, 0xB8($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0XB8);
    // 0x800C7FAC: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x800C7FB0: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x800C7FB4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800C7FB8: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800C7FBC: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    // 0x800C7FC0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800C7FC4: lwc1        $f0, 0xBC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XBC);
    // 0x800C7FC8: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
L_800C7FCC:
    // 0x800C7FCC: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x800C7FD0: lw          $a1, 0xAC($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XAC);
    // 0x800C7FD4: lw          $a2, 0xB0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0XB0);
    // 0x800C7FD8: lw          $a3, 0xB4($a3)
    ctx->r7 = MEM_W(ctx->r7, 0XB4);
    // 0x800C7FDC: jal         0x800F2B88
    // 0x800C7FE0: nop

    initObjectAnimSubstruct(rdram, ctx);
        goto after_3;
    // 0x800C7FE0: nop

    after_3:
    // 0x800C7FE4: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x800C7FE8: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800C7FEC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800C7FF0: jr          $ra
    // 0x800C7FF4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800C7FF4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800C7FF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7FF8: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x800C7FFC: sw          $s0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r16;
    // 0x800C8000: lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // 0x800C8004: addiu       $s0, $s0, 0x6994
    ctx->r16 = ADD32(ctx->r16, 0X6994);
    // 0x800C8008: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800C800C: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800C8010: sw          $ra, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r31;
    // 0x800C8014: sw          $s3, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r19;
    // 0x800C8018: sw          $s2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r18;
    // 0x800C801C: sw          $s1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r17;
    // 0x800C8020: sdc1        $f20, 0xD8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XD8, ctx->r29);
    // 0x800C8024: lw          $s2, 0x4($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X4);
    // 0x800C8028: addiu       $s1, $sp, 0x88
    ctx->r17 = ADD32(ctx->r29, 0X88);
    // 0x800C802C: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x800C8030: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800C8034: lw          $a0, 0x30($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X30);
    // 0x800C8038: jal         0x80058360
    // 0x800C803C: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    lookupHmtTextureByName(rdram, ctx);
        goto after_0;
    // 0x800C803C: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x800C8040: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800C8044: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800C8048: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x800C804C: addiu       $s3, $sp, 0x58
    ctx->r19 = ADD32(ctx->r29, 0X58);
    // 0x800C8050: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x800C8054: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C8058: lw          $a0, 0x30($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X30);
    // 0x800C805C: jal         0x80058360
    // 0x800C8060: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    lookupHmtTextureByName(rdram, ctx);
        goto after_1;
    // 0x800C8060: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    after_1:
    // 0x800C8064: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x800C8068: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x800C806C: jal         0x800F2DC8
    // 0x800C8070: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    generatePerpEmitDirectionWithJitter(rdram, ctx);
        goto after_2;
    // 0x800C8070: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_2:
    // 0x800C8074: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x800C8078: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x800C807C: jal         0x800F2DC8
    // 0x800C8080: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    generatePerpEmitDirectionWithJitter(rdram, ctx);
        goto after_3;
    // 0x800C8080: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x800C8084: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x800C8088: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800C808C: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x800C8090: jal         0x800F1870
    // 0x800C8094: addiu       $a3, $sp, 0xB8
    ctx->r7 = ADD32(ctx->r29, 0XB8);
    tickProgressChannel(rdram, ctx);
        goto after_4;
    // 0x800C8094: addiu       $a3, $sp, 0xB8
    ctx->r7 = ADD32(ctx->r29, 0XB8);
    after_4:
    // 0x800C8098: andi        $s1, $v0, 0xFF
    ctx->r17 = ctx->r2 & 0XFF;
    // 0x800C809C: bne         $s1, $s0, L_800C8154
    if (ctx->r17 != ctx->r16) {
        // 0x800C80A0: addu        $a1, $s3, $zero
        ctx->r5 = ADD32(ctx->r19, 0);
            goto L_800C8154;
    }
    // 0x800C80A0: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x800C80A4: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x800C80A8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800C80AC: jal         0x800F1870
    // 0x800C80B0: addiu       $a3, $sp, 0xBC
    ctx->r7 = ADD32(ctx->r29, 0XBC);
    tickProgressChannel(rdram, ctx);
        goto after_5;
    // 0x800C80B0: addiu       $a3, $sp, 0xBC
    ctx->r7 = ADD32(ctx->r29, 0XBC);
    after_5:
    // 0x800C80B4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800C80B8: bne         $v0, $s1, L_800C8154
    if (ctx->r2 != ctx->r17) {
        // 0x800C80BC: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_800C8154;
    }
    // 0x800C80BC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800C80C0: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x800C80C4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C80C8: lwc1        $f20, 0x6998($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X6998);
    // 0x800C80CC: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800C80D0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800C80D4: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800C80D8: lwc1        $f0, 0xB8($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XB8);
    // 0x800C80DC: addiu       $s0, $s0, -0x5A54
    ctx->r16 = ADD32(ctx->r16, -0X5A54);
    // 0x800C80E0: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800C80E4: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x800C80E8: jal         0x800F2FCC
    // 0x800C80EC: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    triggerCueWithSlotEffect(rdram, ctx);
        goto after_6;
    // 0x800C80EC: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_6:
    // 0x800C80F0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800C80F4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800C80F8: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800C80FC: lwc1        $f0, 0xBC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x800C8100: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x800C8104: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800C8108: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x800C810C: jal         0x800F2FCC
    // 0x800C8110: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    triggerCueWithSlotEffect(rdram, ctx);
        goto after_7;
    // 0x800C8110: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_7:
    // 0x800C8114: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800C8118: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800C811C: addiu       $a2, $a1, 0x24
    ctx->r6 = ADD32(ctx->r5, 0X24);
    // 0x800C8120: lui         $a3, 0x4190
    ctx->r7 = S32(0X4190 << 16);
    // 0x800C8124: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C8128: lwc1        $f0, 0x699C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X699C);
    // 0x800C812C: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
    // 0x800C8130: sw          $zero, 0x7C($a1)
    MEM_W(0X7C, ctx->r5) = 0;
    // 0x800C8134: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800C8138: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x800C813C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800C8140: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // 0x800C8144: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800C8148: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800C814C: jal         0x800989D8
    // 0x800C8150: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    play3DSoundEvent(rdram, ctx);
        goto after_8;
    // 0x800C8150: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_8:
L_800C8154:
    // 0x800C8154: lw          $ra, 0xD0($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XD0);
    // 0x800C8158: lw          $s3, 0xCC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XCC);
    // 0x800C815C: lw          $s2, 0xC8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC8);
    // 0x800C8160: lw          $s1, 0xC4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC4);
    // 0x800C8164: lw          $s0, 0xC0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XC0);
    // 0x800C8168: ldc1        $f20, 0xD8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XD8);
    // 0x800C816C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800C8170: jr          $ra
    // 0x800C8174: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    return;
    // 0x800C8174: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
;}
RECOMP_FUNC void func_800C804C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C804C: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x800C8050: lhu         $a0, 0x3C($a3)
    ctx->r4 = MEM_HU(ctx->r7, 0X3C);
    // 0x800C8054: lbu         $v0, 0x4A($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X4A);
    // 0x800C8058: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800C805C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800C8060: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800C8064: div         $zero, $a0, $v0
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r2)));
    // 0x800C8068: bne         $v0, $zero, L_800C8074
    if (ctx->r2 != 0) {
        // 0x800C806C: nop
    
            goto L_800C8074;
    }
    // 0x800C806C: nop

    // 0x800C8070: break       7
    do_break(2148302960);
L_800C8074:
    // 0x800C8074: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C8078: bne         $v0, $at, L_800C808C
    if (ctx->r2 != ctx->r1) {
        // 0x800C807C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C808C;
    }
    // 0x800C807C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C8080: bne         $a0, $at, L_800C808C
    if (ctx->r4 != ctx->r1) {
        // 0x800C8084: nop
    
            goto L_800C808C;
    }
    // 0x800C8084: nop

    // 0x800C8088: break       6
    do_break(2148302984);
L_800C808C:
    // 0x800C808C: mflo        $a0
    ctx->r4 = lo;
    // 0x800C8090: lhu         $v1, 0x3E($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X3E);
    // 0x800C8094: lbu         $v0, 0x4B($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X4B);
    // 0x800C8098: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800C809C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800C80A0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C80A4: div         $zero, $v1, $v0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r2)));
    // 0x800C80A8: bne         $v0, $zero, L_800C80B4
    if (ctx->r2 != 0) {
        // 0x800C80AC: nop
    
            goto L_800C80B4;
    }
    // 0x800C80AC: nop

    // 0x800C80B0: break       7
    do_break(2148303024);
L_800C80B4:
    // 0x800C80B4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C80B8: bne         $v0, $at, L_800C80CC
    if (ctx->r2 != ctx->r1) {
        // 0x800C80BC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C80CC;
    }
    // 0x800C80BC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C80C0: bne         $v1, $at, L_800C80CC
    if (ctx->r3 != ctx->r1) {
        // 0x800C80C4: nop
    
            goto L_800C80CC;
    }
    // 0x800C80C4: nop

    // 0x800C80C8: break       6
    do_break(2148303048);
L_800C80CC:
    // 0x800C80CC: mflo        $v1
    ctx->r3 = lo;
    // 0x800C80D0: lbu         $v0, 0x4C($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X4C);
    // 0x800C80D4: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x800C80D8: sh          $zero, 0x7CE($a3)
    MEM_H(0X7CE, ctx->r7) = 0;
    // 0x800C80DC: sh          $a0, 0x7CC($a3)
    MEM_H(0X7CC, ctx->r7) = ctx->r4;
    // 0x800C80E0: beq         $v0, $zero, L_800C8214
    if (ctx->r2 == 0) {
        // 0x800C80E4: sh          $v1, 0x7D0($a3)
        MEM_H(0X7D0, ctx->r7) = ctx->r3;
            goto L_800C8214;
    }
    // 0x800C80E4: sh          $v1, 0x7D0($a3)
    MEM_H(0X7D0, ctx->r7) = ctx->r3;
    // 0x800C80E8: addiu       $t1, $zero, 0x6F8
    ctx->r9 = ADD32(0, 0X6F8);
L_800C80EC:
    // 0x800C80EC: addu        $a2, $a3, $t1
    ctx->r6 = ADD32(ctx->r7, ctx->r9);
    // 0x800C80F0: lhu         $v1, 0x3C($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X3C);
    // 0x800C80F4: lbu         $v0, 0x1($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X1);
    // 0x800C80F8: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C80FC: lbu         $v1, 0x4A($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X4A);
    // 0x800C8100: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800C8104: mflo        $a1
    ctx->r5 = lo;
    // 0x800C8108: addiu       $v0, $a1, -0x1
    ctx->r2 = ADD32(ctx->r5, -0X1);
    // 0x800C810C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C8110: div         $zero, $v0, $v1
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r3)));
    // 0x800C8114: bne         $v1, $zero, L_800C8120
    if (ctx->r3 != 0) {
        // 0x800C8118: nop
    
            goto L_800C8120;
    }
    // 0x800C8118: nop

    // 0x800C811C: break       7
    do_break(2148303132);
L_800C8120:
    // 0x800C8120: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C8124: bne         $v1, $at, L_800C8138
    if (ctx->r3 != ctx->r1) {
        // 0x800C8128: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C8138;
    }
    // 0x800C8128: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C812C: bne         $v0, $at, L_800C8138
    if (ctx->r2 != ctx->r1) {
        // 0x800C8130: nop
    
            goto L_800C8138;
    }
    // 0x800C8130: nop

    // 0x800C8134: break       6
    do_break(2148303156);
L_800C8138:
    // 0x800C8138: mflo        $v0
    ctx->r2 = lo;
    // 0x800C813C: sw          $v0, 0x28($a2)
    MEM_W(0X28, ctx->r6) = ctx->r2;
    // 0x800C8140: lhu         $v1, 0x3E($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X3E);
    // 0x800C8144: lbu         $v0, 0x2($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X2);
    // 0x800C8148: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C814C: lbu         $v0, 0x4B($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X4B);
    // 0x800C8150: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800C8154: mflo        $v1
    ctx->r3 = lo;
    // 0x800C8158: addiu       $a0, $v1, -0x1
    ctx->r4 = ADD32(ctx->r3, -0X1);
    // 0x800C815C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800C8160: div         $zero, $a0, $v0
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r2)));
    // 0x800C8164: bne         $v0, $zero, L_800C8170
    if (ctx->r2 != 0) {
        // 0x800C8168: nop
    
            goto L_800C8170;
    }
    // 0x800C8168: nop

    // 0x800C816C: break       7
    do_break(2148303212);
L_800C8170:
    // 0x800C8170: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C8174: bne         $v0, $at, L_800C8188
    if (ctx->r2 != ctx->r1) {
        // 0x800C8178: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C8188;
    }
    // 0x800C8178: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C817C: bne         $a0, $at, L_800C8188
    if (ctx->r4 != ctx->r1) {
        // 0x800C8180: nop
    
            goto L_800C8188;
    }
    // 0x800C8180: nop

    // 0x800C8184: break       6
    do_break(2148303236);
L_800C8188:
    // 0x800C8188: mflo        $a0
    ctx->r4 = lo;
    // 0x800C818C: lbu         $v0, 0x1($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X1);
    // 0x800C8190: lbu         $v1, 0x2($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X2);
    // 0x800C8194: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C8198: sw          $v0, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r2;
    // 0x800C819C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800C81A0: sw          $v1, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r3;
    // 0x800C81A4: sw          $v0, 0x20($a2)
    MEM_W(0X20, ctx->r6) = ctx->r2;
    // 0x800C81A8: mflo        $a1
    ctx->r5 = lo;
    // 0x800C81AC: sw          $a1, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r5;
    // 0x800C81B0: sw          $a0, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r4;
    // 0x800C81B4: lhu         $v0, 0x7CE($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X7CE);
    // 0x800C81B8: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800C81BC: slti        $v0, $v0, 0x11
    ctx->r2 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
    // 0x800C81C0: bne         $v0, $zero, L_800C81D0
    if (ctx->r2 != 0) {
        // 0x800C81C4: addu        $v0, $a1, $zero
        ctx->r2 = ADD32(ctx->r5, 0);
            goto L_800C81D0;
    }
    // 0x800C81C4: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // 0x800C81C8: jr          $ra
    // 0x800C81CC: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    return;
    // 0x800C81CC: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
L_800C81D0:
    // 0x800C81D0: blez        $v0, L_800C81FC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800C81D4: addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
            goto L_800C81FC;
    }
    // 0x800C81D4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
L_800C81D8:
    // 0x800C81D8: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
    // 0x800C81DC: lhu         $v1, 0x7CE($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X7CE);
    // 0x800C81E0: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800C81E4: addiu       $a0, $v1, 0x1
    ctx->r4 = ADD32(ctx->r3, 0X1);
    // 0x800C81E8: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x800C81EC: addu        $v1, $a3, $v1
    ctx->r3 = ADD32(ctx->r7, ctx->r3);
    // 0x800C81F0: sh          $a0, 0x7CE($a3)
    MEM_H(0X7CE, ctx->r7) = ctx->r4;
    // 0x800C81F4: bgtz        $v0, L_800C81D8
    if (SIGNED(ctx->r2) > 0) {
        // 0x800C81F8: sb          $t0, 0x7BC($v1)
        MEM_B(0X7BC, ctx->r3) = ctx->r8;
            goto L_800C81D8;
    }
    // 0x800C81F8: sb          $t0, 0x7BC($v1)
    MEM_B(0X7BC, ctx->r3) = ctx->r8;
L_800C81FC:
    // 0x800C81FC: sh          $zero, 0x6($a2)
    MEM_H(0X6, ctx->r6) = 0;
    // 0x800C8200: lbu         $v0, 0x4C($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X4C);
    // 0x800C8204: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800C8208: sltu        $v0, $t0, $v0
    ctx->r2 = ctx->r8 < ctx->r2 ? 1 : 0;
    // 0x800C820C: bne         $v0, $zero, L_800C80EC
    if (ctx->r2 != 0) {
        // 0x800C8210: addiu       $t1, $t1, 0x2C
        ctx->r9 = ADD32(ctx->r9, 0X2C);
            goto L_800C80EC;
    }
    // 0x800C8210: addiu       $t1, $t1, 0x2C
    ctx->r9 = ADD32(ctx->r9, 0X2C);
L_800C8214:
    // 0x800C8214: jr          $ra
    // 0x800C8218: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x800C8218: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_800C8178(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8178: addiu       $sp, $sp, -0x108
    ctx->r29 = ADD32(ctx->r29, -0X108);
    // 0x800C817C: sw          $ra, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r31;
    // 0x800C8180: sw          $s7, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r23;
    // 0x800C8184: sw          $s6, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r22;
    // 0x800C8188: sw          $s5, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r21;
    // 0x800C818C: sw          $s4, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r20;
    // 0x800C8190: sw          $s3, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r19;
    // 0x800C8194: sw          $s2, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r18;
    // 0x800C8198: sw          $s1, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r17;
    // 0x800C819C: sw          $s0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r16;
    // 0x800C81A0: lw          $s3, 0x4($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X4);
    // 0x800C81A4: lw          $a0, 0x38($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X38);
    // 0x800C81A8: lw          $s5, 0x34($s3)
    ctx->r21 = MEM_W(ctx->r19, 0X34);
    // 0x800C81AC: jal         0x800F2988
    // 0x800C81B0: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    getObjectMeshTransformOrLocal(rdram, ctx);
        goto after_0;
    // 0x800C81B0: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    after_0:
    // 0x800C81B4: lwc1        $f0, 0xD0($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0XD0);
    // 0x800C81B8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C81BC: lwc1        $f2, 0x69A4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X69A4);
    // 0x800C81C0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C81C4: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800C81C8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800C81CC: nop

    // 0x800C81D0: bc1t        L_800C84D8
    if (c1cs) {
        // 0x800C81D4: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800C84D8;
    }
    // 0x800C81D4: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800C81D8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C81DC: lw          $v0, 0x7CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7CE4);
    // 0x800C81E0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C81E4: addiu       $v0, $v0, 0xC0
    ctx->r2 = ADD32(ctx->r2, 0XC0);
    // 0x800C81E8: addu        $a0, $s5, $v0
    ctx->r4 = ADD32(ctx->r21, ctx->r2);
    // 0x800C81EC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800C81F0: blez        $v1, L_800C84D4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800C81F4: addu        $s7, $zero, $zero
        ctx->r23 = ADD32(0, 0);
            goto L_800C84D4;
    }
    // 0x800C81F4: addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
    // 0x800C81F8: lw          $v0, 0xC4($s5)
    ctx->r2 = MEM_W(ctx->r21, 0XC4);
    // 0x800C81FC: bne         $v0, $zero, L_800C8208
    if (ctx->r2 != 0) {
        // 0x800C8200: addiu       $v0, $v1, -0x1
        ctx->r2 = ADD32(ctx->r3, -0X1);
            goto L_800C8208;
    }
    // 0x800C8200: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x800C8204: addiu       $v0, $v1, -0x2
    ctx->r2 = ADD32(ctx->r3, -0X2);
L_800C8208:
    // 0x800C8208: bgtz        $v0, L_800C8214
    if (SIGNED(ctx->r2) > 0) {
        // 0x800C820C: sw          $v0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r2;
            goto L_800C8214;
    }
    // 0x800C820C: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800C8210: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
L_800C8214:
    // 0x800C8214: sh          $zero, 0x28($sp)
    MEM_H(0X28, ctx->r29) = 0;
    // 0x800C8218: lw          $a0, 0x38($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X38);
    // 0x800C821C: jal         0x800F2A00
    // 0x800C8220: ori         $s6, $zero, 0xFFFF
    ctx->r22 = 0 | 0XFFFF;
    getObjectNpcTypeId(rdram, ctx);
        goto after_1;
    // 0x800C8220: ori         $s6, $zero, 0xFFFF
    ctx->r22 = 0 | 0XFFFF;
    after_1:
    // 0x800C8224: lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // 0x800C8228: addiu       $s0, $s0, 0x6994
    ctx->r16 = ADD32(ctx->r16, 0X6994);
    // 0x800C822C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800C8230: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800C8234: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800C8238: sh          $v0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r2;
    // 0x800C823C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800C8240: addiu       $s1, $sp, 0xA8
    ctx->r17 = ADD32(ctx->r29, 0XA8);
    // 0x800C8244: addiu       $s2, $sp, 0x48
    ctx->r18 = ADD32(ctx->r29, 0X48);
    // 0x800C8248: lw          $v1, 0x7CE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7CE4);
    // 0x800C824C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C8250: lwc1        $f0, 0x69A8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X69A8);
    // 0x800C8254: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C8258: lwc1        $f4, 0x69AC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X69AC);
    // 0x800C825C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800C8260: addu        $v1, $v1, $s5
    ctx->r3 = ADD32(ctx->r3, ctx->r21);
    // 0x800C8264: lwc1        $f2, 0xCC($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0XCC);
    // 0x800C8268: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800C826C: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800C8270: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x800C8274: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x800C8278: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x800C827C: sb          $v0, 0x3C($sp)
    MEM_B(0X3C, ctx->r29) = ctx->r2;
    // 0x800C8280: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    // 0x800C8284: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x800C8288: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800C828C: lw          $a0, 0x30($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X30);
    // 0x800C8290: jal         0x80058360
    // 0x800C8294: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    lookupHmtTextureByName(rdram, ctx);
        goto after_2;
    // 0x800C8294: addu        $a3, $s2, $zero
    ctx->r7 = ADD32(ctx->r18, 0);
    after_2:
    // 0x800C8298: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800C829C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800C82A0: addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // 0x800C82A4: addiu       $s0, $sp, 0x78
    ctx->r16 = ADD32(ctx->r29, 0X78);
    // 0x800C82A8: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x800C82AC: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x800C82B0: lw          $a0, 0x30($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X30);
    // 0x800C82B4: jal         0x80058360
    // 0x800C82B8: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    lookupHmtTextureByName(rdram, ctx);
        goto after_3;
    // 0x800C82B8: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_3:
    // 0x800C82BC: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800C82C0: lw          $a0, 0x38($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X38);
    // 0x800C82C4: jal         0x800F2DC8
    // 0x800C82C8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    generatePerpEmitDirectionWithJitter(rdram, ctx);
        goto after_4;
    // 0x800C82C8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_4:
    // 0x800C82CC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800C82D0: lw          $a0, 0x38($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X38);
    // 0x800C82D4: jal         0x800F2DC8
    // 0x800C82D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    generatePerpEmitDirectionWithJitter(rdram, ctx);
        goto after_5;
    // 0x800C82D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x800C82DC: lw          $v0, 0xC4($s5)
    ctx->r2 = MEM_W(ctx->r21, 0XC4);
    // 0x800C82E0: bne         $v0, $zero, L_800C8390
    if (ctx->r2 != 0) {
        // 0x800C82E4: addu        $s1, $s6, $zero
        ctx->r17 = ADD32(ctx->r22, 0);
            goto L_800C8390;
    }
    // 0x800C82E4: addu        $s1, $s6, $zero
    ctx->r17 = ADD32(ctx->r22, 0);
    // 0x800C82E8: lw          $a0, 0x38($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X38);
    // 0x800C82EC: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800C82F0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800C82F4: jal         0x800F1870
    // 0x800C82F8: addiu       $a3, $sp, 0xD8
    ctx->r7 = ADD32(ctx->r29, 0XD8);
    tickProgressChannel(rdram, ctx);
        goto after_6;
    // 0x800C82F8: addiu       $a3, $sp, 0xD8
    ctx->r7 = ADD32(ctx->r29, 0XD8);
    after_6:
    // 0x800C82FC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800C8300: bne         $v0, $s4, L_800C8340
    if (ctx->r2 != ctx->r20) {
        // 0x800C8304: addiu       $a1, $zero, 0xB
        ctx->r5 = ADD32(0, 0XB);
            goto L_800C8340;
    }
    // 0x800C8304: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x800C8308: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C830C: lwc1        $f0, 0x69B0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X69B0);
    // 0x800C8310: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800C8314: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800C8318: lwc1        $f0, 0xD8($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800C831C: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x800C8320: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800C8324: lw          $a0, 0x38($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X38);
    // 0x800C8328: jal         0x800F2FCC
    // 0x800C832C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    triggerCueWithSlotEffect(rdram, ctx);
        goto after_7;
    // 0x800C832C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_7:
    // 0x800C8330: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x800C8334: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800C8338: jal         0x8005EC60
    // 0x800C833C: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    spawnByteAnimDebrisWithParam(rdram, ctx);
        goto after_8;
    // 0x800C833C: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_8:
L_800C8340:
    // 0x800C8340: lw          $a0, 0x38($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X38);
    // 0x800C8344: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800C8348: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800C834C: jal         0x800F1870
    // 0x800C8350: addiu       $a3, $sp, 0xDC
    ctx->r7 = ADD32(ctx->r29, 0XDC);
    tickProgressChannel(rdram, ctx);
        goto after_9;
    // 0x800C8350: addiu       $a3, $sp, 0xDC
    ctx->r7 = ADD32(ctx->r29, 0XDC);
    after_9:
    // 0x800C8354: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800C8358: bne         $v0, $s4, L_800C844C
    if (ctx->r2 != ctx->r20) {
        // 0x800C835C: addu        $a2, $s0, $zero
        ctx->r6 = ADD32(ctx->r16, 0);
            goto L_800C844C;
    }
    // 0x800C835C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800C8360: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C8364: lwc1        $f0, 0x69B4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X69B4);
    // 0x800C8368: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x800C836C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800C8370: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800C8374: lwc1        $f0, 0xDC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x800C8378: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800C837C: lw          $a0, 0x38($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X38);
    // 0x800C8380: jal         0x800F2FCC
    // 0x800C8384: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    triggerCueWithSlotEffect(rdram, ctx);
        goto after_10;
    // 0x800C8384: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_10:
    // 0x800C8388: j           L_800C8440
    // 0x800C838C: addu        $s6, $v0, $zero
    ctx->r22 = ADD32(ctx->r2, 0);
        goto L_800C8440;
    // 0x800C838C: addu        $s6, $v0, $zero
    ctx->r22 = ADD32(ctx->r2, 0);
L_800C8390:
    // 0x800C8390: lhu         $v0, 0x74($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X74);
    // 0x800C8394: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x800C8398: beq         $v0, $zero, L_800C83F4
    if (ctx->r2 == 0) {
        // 0x800C839C: sh          $v0, 0x74($s3)
        MEM_H(0X74, ctx->r19) = ctx->r2;
            goto L_800C83F4;
    }
    // 0x800C839C: sh          $v0, 0x74($s3)
    MEM_H(0X74, ctx->r19) = ctx->r2;
    // 0x800C83A0: lw          $a0, 0x38($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X38);
    // 0x800C83A4: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800C83A8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800C83AC: jal         0x800F1870
    // 0x800C83B0: addiu       $a3, $sp, 0xD8
    ctx->r7 = ADD32(ctx->r29, 0XD8);
    tickProgressChannel(rdram, ctx);
        goto after_11;
    // 0x800C83B0: addiu       $a3, $sp, 0xD8
    ctx->r7 = ADD32(ctx->r29, 0XD8);
    after_11:
    // 0x800C83B4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800C83B8: bne         $v0, $s4, L_800C844C
    if (ctx->r2 != ctx->r20) {
        // 0x800C83BC: addu        $a2, $s2, $zero
        ctx->r6 = ADD32(ctx->r18, 0);
            goto L_800C844C;
    }
    // 0x800C83BC: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x800C83C0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C83C4: lwc1        $f0, 0x69B8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X69B8);
    // 0x800C83C8: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x800C83CC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800C83D0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800C83D4: lwc1        $f0, 0xD8($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800C83D8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800C83DC: lw          $a0, 0x38($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X38);
    // 0x800C83E0: jal         0x800F2FCC
    // 0x800C83E4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    triggerCueWithSlotEffect(rdram, ctx);
        goto after_12;
    // 0x800C83E4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_12:
    // 0x800C83E8: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x800C83EC: j           L_800C8444
    // 0x800C83F0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
        goto L_800C8444;
    // 0x800C83F0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_800C83F4:
    // 0x800C83F4: lw          $a0, 0x38($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X38);
    // 0x800C83F8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800C83FC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800C8400: jal         0x800F1870
    // 0x800C8404: addiu       $a3, $sp, 0xDC
    ctx->r7 = ADD32(ctx->r29, 0XDC);
    tickProgressChannel(rdram, ctx);
        goto after_13;
    // 0x800C8404: addiu       $a3, $sp, 0xDC
    ctx->r7 = ADD32(ctx->r29, 0XDC);
    after_13:
    // 0x800C8408: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800C840C: bne         $v0, $s4, L_800C844C
    if (ctx->r2 != ctx->r20) {
        // 0x800C8410: addu        $a2, $s0, $zero
        ctx->r6 = ADD32(ctx->r16, 0);
            goto L_800C844C;
    }
    // 0x800C8410: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800C8414: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C8418: lwc1        $f0, 0x69BC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X69BC);
    // 0x800C841C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x800C8420: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800C8424: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800C8428: lwc1        $f0, 0xDC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x800C842C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800C8430: lw          $a0, 0x38($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X38);
    // 0x800C8434: jal         0x800F2FCC
    // 0x800C8438: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    triggerCueWithSlotEffect(rdram, ctx);
        goto after_14;
    // 0x800C8438: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_14:
    // 0x800C843C: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
L_800C8440:
    // 0x800C8440: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
L_800C8444:
    // 0x800C8444: jal         0x8005EC60
    // 0x800C8448: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    spawnByteAnimDebrisWithParam(rdram, ctx);
        goto after_15;
    // 0x800C8448: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    after_15:
L_800C844C:
    // 0x800C844C: lw          $v0, 0xC8($s5)
    ctx->r2 = MEM_W(ctx->r21, 0XC8);
    // 0x800C8450: beq         $v0, $zero, L_800C8480
    if (ctx->r2 == 0) {
        // 0x800C8454: andi        $a0, $s1, 0xFFFF
        ctx->r4 = ctx->r17 & 0XFFFF;
            goto L_800C8480;
    }
    // 0x800C8454: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    // 0x800C8458: ori         $s0, $zero, 0xFFFF
    ctx->r16 = 0 | 0XFFFF;
    // 0x800C845C: beq         $a0, $s0, L_800C846C
    if (ctx->r4 == ctx->r16) {
        // 0x800C8460: addiu       $a1, $zero, 0xA
        ctx->r5 = ADD32(0, 0XA);
            goto L_800C846C;
    }
    // 0x800C8460: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x800C8464: jal         0x8003E8DC
    // 0x800C8468: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    slotDispatcherIter(rdram, ctx);
        goto after_16;
    // 0x800C8468: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_16:
L_800C846C:
    // 0x800C846C: andi        $a0, $s6, 0xFFFF
    ctx->r4 = ctx->r22 & 0XFFFF;
    // 0x800C8470: beq         $a0, $s0, L_800C8480
    if (ctx->r4 == ctx->r16) {
        // 0x800C8474: addiu       $a1, $zero, 0xA
        ctx->r5 = ADD32(0, 0XA);
            goto L_800C8480;
    }
    // 0x800C8474: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x800C8478: jal         0x8003E8DC
    // 0x800C847C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    slotDispatcherIter(rdram, ctx);
        goto after_17;
    // 0x800C847C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_17:
L_800C8480:
    // 0x800C8480: andi        $v1, $s1, 0xFFFF
    ctx->r3 = ctx->r17 & 0XFFFF;
    // 0x800C8484: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800C8488: bne         $v1, $v0, L_800C849C
    if (ctx->r3 != ctx->r2) {
        // 0x800C848C: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800C849C;
    }
    // 0x800C848C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800C8490: andi        $v0, $s6, 0xFFFF
    ctx->r2 = ctx->r22 & 0XFFFF;
    // 0x800C8494: beq         $v0, $v1, L_800C84D8
    if (ctx->r2 == ctx->r3) {
        // 0x800C8498: addu        $v0, $s7, $zero
        ctx->r2 = ADD32(ctx->r23, 0);
            goto L_800C84D8;
    }
    // 0x800C8498: addu        $v0, $s7, $zero
    ctx->r2 = ADD32(ctx->r23, 0);
L_800C849C:
    // 0x800C849C: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x800C84A0: addiu       $a2, $a1, 0x24
    ctx->r6 = ADD32(ctx->r5, 0X24);
    // 0x800C84A4: lui         $a3, 0x4198
    ctx->r7 = S32(0X4198 << 16);
    // 0x800C84A8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C84AC: lwc1        $f0, 0x69C0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X69C0);
    // 0x800C84B0: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x800C84B4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800C84B8: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x800C84BC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800C84C0: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // 0x800C84C4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800C84C8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800C84CC: jal         0x800989D8
    // 0x800C84D0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    play3DSoundEvent(rdram, ctx);
        goto after_18;
    // 0x800C84D0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_18:
L_800C84D4:
    // 0x800C84D4: addu        $v0, $s7, $zero
    ctx->r2 = ADD32(ctx->r23, 0);
L_800C84D8:
    // 0x800C84D8: lw          $ra, 0x100($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X100);
    // 0x800C84DC: lw          $s7, 0xFC($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XFC);
    // 0x800C84E0: lw          $s6, 0xF8($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XF8);
    // 0x800C84E4: lw          $s5, 0xF4($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XF4);
    // 0x800C84E8: lw          $s4, 0xF0($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XF0);
    // 0x800C84EC: lw          $s3, 0xEC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XEC);
    // 0x800C84F0: lw          $s2, 0xE8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XE8);
    // 0x800C84F4: lw          $s1, 0xE4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XE4);
    // 0x800C84F8: lw          $s0, 0xE0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XE0);
    // 0x800C84FC: jr          $ra
    // 0x800C8500: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
    return;
    // 0x800C8500: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
;}
RECOMP_FUNC void func_800C821C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C821C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C8220: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800C8224: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x800C8228: sw          $s5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r21;
    // 0x800C822C: addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // 0x800C8230: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x800C8234: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x800C8238: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x800C823C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800C8240: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x800C8244: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800C8248: sw          $fp, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r30;
    // 0x800C824C: sw          $s7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r23;
    // 0x800C8250: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x800C8254: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800C8258: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800C825C: jal         0x800078E0
    // 0x800C8260: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    rs_memset(rdram, ctx);
        goto after_0;
    // 0x800C8260: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x800C8264: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x800C8268: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800C826C: andi        $v1, $s4, 0xFF
    ctx->r3 = ctx->r20 & 0XFF;
    // 0x800C8270: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800C8274: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C8278: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C827C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800C8280: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C8284: addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // 0x800C8288: lbu         $a1, 0x6FC($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X6FC);
    // 0x800C828C: lbu         $v0, 0x6FD($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6FD);
    // 0x800C8290: sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5 << 1);
    // 0x800C8294: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800C8298: ori         $s6, $v0, 0x1
    ctx->r22 = ctx->r2 | 0X1;
    // 0x800C829C: jal         0x800C888C
    // 0x800C82A0: andi        $a1, $a1, 0xFE
    ctx->r5 = ctx->r5 & 0XFE;
    func_800C888C(rdram, ctx);
        goto after_1;
    // 0x800C82A0: andi        $a1, $a1, 0xFE
    ctx->r5 = ctx->r5 & 0XFE;
    after_1:
    // 0x800C82A4: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800C82A8: beq         $s0, $zero, L_800C82F4
    if (ctx->r16 == 0) {
        // 0x800C82AC: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_800C82F4;
    }
    // 0x800C82AC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800C82B0: jal         0x800C87B0
    // 0x800C82B4: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    func_800C87B0(rdram, ctx);
        goto after_2;
    // 0x800C82B4: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    after_2:
    // 0x800C82B8: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800C82BC: sll         $v0, $a1, 16
    ctx->r2 = S32(ctx->r5 << 16);
    // 0x800C82C0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800C82C4: addiu       $a0, $s0, -0x1
    ctx->r4 = ADD32(ctx->r16, -0X1);
    // 0x800C82C8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800C82CC: sllv        $v1, $v1, $a0
    ctx->r3 = S32(ctx->r3 << (ctx->r4 & 31));
    // 0x800C82D0: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800C82D4: beq         $v0, $zero, L_800C82EC
    if (ctx->r2 == 0) {
        // 0x800C82D8: addiu       $v1, $a1, 0x1
        ctx->r3 = ADD32(ctx->r5, 0X1);
            goto L_800C82EC;
    }
    // 0x800C82D8: addiu       $v1, $a1, 0x1
    ctx->r3 = ADD32(ctx->r5, 0X1);
    // 0x800C82DC: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800C82E0: sllv        $v0, $v0, $s0
    ctx->r2 = S32(ctx->r2 << (ctx->r16 & 31));
    // 0x800C82E4: j           L_800C82F0
    // 0x800C82E8: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
        goto L_800C82F0;
    // 0x800C82E8: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
L_800C82EC:
    // 0x800C82EC: addu        $v0, $a1, $zero
    ctx->r2 = ADD32(ctx->r5, 0);
L_800C82F0:
    // 0x800C82F0: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
L_800C82F4:
    // 0x800C82F4: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800C82F8: addiu       $fp, $zero, -0x1
    ctx->r30 = ADD32(0, -0X1);
    // 0x800C82FC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800C8300: addiu       $s7, $v0, 0x76E0
    ctx->r23 = ADD32(ctx->r2, 0X76E0);
    // 0x800C8304: andi        $v1, $s4, 0xFF
    ctx->r3 = ctx->r20 & 0XFF;
    // 0x800C8308: sllv        $v0, $v1, $s1
    ctx->r2 = S32(ctx->r3 << (ctx->r17 & 31));
    // 0x800C830C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C8310: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C8314: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800C8318: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C831C: addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // 0x800C8320: lhu         $v1, 0x6FE($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X6FE);
    // 0x800C8324: addiu       $s4, $zero, 0xF
    ctx->r20 = ADD32(0, 0XF);
    // 0x800C8328: addu        $v1, $v1, $s3
    ctx->r3 = ADD32(ctx->r3, ctx->r19);
    // 0x800C832C: sh          $v1, 0x6FE($v0)
    MEM_H(0X6FE, ctx->r2) = ctx->r3;
    // 0x800C8330: sh          $v1, 0x0($s5)
    MEM_H(0X0, ctx->r21) = ctx->r3;
    // 0x800C8334: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_800C8338:
    // 0x800C8338: jal         0x800C888C
    // 0x800C833C: andi        $a1, $s6, 0xFF
    ctx->r5 = ctx->r22 & 0XFF;
    func_800C888C(rdram, ctx);
        goto after_3;
    // 0x800C833C: andi        $a1, $s6, 0xFF
    ctx->r5 = ctx->r22 & 0XFF;
    after_3:
    // 0x800C8340: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800C8344: sra         $v1, $s0, 4
    ctx->r3 = S32(SIGNED(ctx->r16) >> 4);
    // 0x800C8348: andi        $s0, $s0, 0xF
    ctx->r16 = ctx->r16 & 0XF;
    // 0x800C834C: beq         $s0, $zero, L_800C839C
    if (ctx->r16 == 0) {
        // 0x800C8350: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_800C839C;
    }
    // 0x800C8350: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800C8354: addu        $s1, $s1, $v1
    ctx->r17 = ADD32(ctx->r17, ctx->r3);
    // 0x800C8358: jal         0x800C87B0
    // 0x800C835C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    func_800C87B0(rdram, ctx);
        goto after_4;
    // 0x800C835C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_4:
    // 0x800C8360: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x800C8364: addiu       $v0, $s0, -0x1
    ctx->r2 = ADD32(ctx->r16, -0X1);
    // 0x800C8368: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800C836C: sllv        $v0, $a3, $v0
    ctx->r2 = S32(ctx->r7 << (ctx->r2 & 31));
    // 0x800C8370: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800C8374: beq         $v0, $zero, L_800C8384
    if (ctx->r2 == 0) {
        // 0x800C8378: sllv        $v0, $fp, $s0
        ctx->r2 = S32(ctx->r30 << (ctx->r16 & 31));
            goto L_800C8384;
    }
    // 0x800C8378: sllv        $v0, $fp, $s0
    ctx->r2 = S32(ctx->r30 << (ctx->r16 & 31));
    // 0x800C837C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800C8380: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
L_800C8384:
    // 0x800C8384: addu        $v0, $s1, $s7
    ctx->r2 = ADD32(ctx->r17, ctx->r23);
    // 0x800C8388: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800C838C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800C8390: addu        $v0, $v0, $s5
    ctx->r2 = ADD32(ctx->r2, ctx->r21);
    // 0x800C8394: j           L_800C83A4
    // 0x800C8398: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
        goto L_800C83A4;
    // 0x800C8398: sh          $v1, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r3;
L_800C839C:
    // 0x800C839C: bne         $v1, $s4, L_800C83B4
    if (ctx->r3 != ctx->r20) {
        // 0x800C83A0: addiu       $s1, $s1, 0xF
        ctx->r17 = ADD32(ctx->r17, 0XF);
            goto L_800C83B4;
    }
    // 0x800C83A0: addiu       $s1, $s1, 0xF
    ctx->r17 = ADD32(ctx->r17, 0XF);
L_800C83A4:
    // 0x800C83A4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800C83A8: slti        $v0, $s1, 0x40
    ctx->r2 = SIGNED(ctx->r17) < 0X40 ? 1 : 0;
    // 0x800C83AC: bne         $v0, $zero, L_800C8338
    if (ctx->r2 != 0) {
        // 0x800C83B0: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_800C8338;
    }
    // 0x800C83B0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
L_800C83B4:
    // 0x800C83B4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800C83B8: lw          $fp, 0x30($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X30);
    // 0x800C83BC: lw          $s7, 0x2C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X2C);
    // 0x800C83C0: lw          $s6, 0x28($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X28);
    // 0x800C83C4: lw          $s5, 0x24($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X24);
    // 0x800C83C8: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x800C83CC: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x800C83D0: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800C83D4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800C83D8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800C83DC: jr          $ra
    // 0x800C83E0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800C83E0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_800C83E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C83E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C83E8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800C83EC: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800C83F0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800C83F4: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x800C83F8: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800C83FC: addu        $s2, $a1, $zero
    ctx->r18 = ADD32(ctx->r5, 0);
    // 0x800C8400: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800C8404: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800C8408: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C840C: addu        $v0, $a1, $s1
    ctx->r2 = ADD32(ctx->r5, ctx->r17);
L_800C8410:
    // 0x800C8410: lbu         $a0, -0x1($v0)
    ctx->r4 = MEM_BU(ctx->r2, -0X1);
    // 0x800C8414: bltz        $a0, L_800C8428
    if (SIGNED(ctx->r4) < 0) {
        // 0x800C8418: addu        $v0, $a2, $a0
        ctx->r2 = ADD32(ctx->r6, ctx->r4);
            goto L_800C8428;
    }
    // 0x800C8418: addu        $v0, $a2, $a0
    ctx->r2 = ADD32(ctx->r6, ctx->r4);
    // 0x800C841C: slti        $v0, $v0, 0x101
    ctx->r2 = SIGNED(ctx->r2) < 0X101 ? 1 : 0;
    // 0x800C8420: bne         $v0, $zero, L_800C8438
    if (ctx->r2 != 0) {
        // 0x800C8424: addu        $v0, $a0, $zero
        ctx->r2 = ADD32(ctx->r4, 0);
            goto L_800C8438;
    }
    // 0x800C8424: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
L_800C8428:
    // 0x800C8428: j           L_800C8508
    // 0x800C842C: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
        goto L_800C8508;
    // 0x800C842C: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_800C8430:
    // 0x800C8430: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800C8434: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
L_800C8438:
    // 0x800C8438: bne         $v0, $zero, L_800C8430
    if (ctx->r2 != 0) {
        // 0x800C843C: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_800C8430;
    }
    // 0x800C843C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800C8440: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800C8444: slti        $v0, $a1, 0x11
    ctx->r2 = SIGNED(ctx->r5) < 0X11 ? 1 : 0;
    // 0x800C8448: bne         $v0, $zero, L_800C8410
    if (ctx->r2 != 0) {
        // 0x800C844C: addu        $v0, $a1, $s1
        ctx->r2 = ADD32(ctx->r5, ctx->r17);
            goto L_800C8410;
    }
    // 0x800C844C: addu        $v0, $a1, $s1
    ctx->r2 = ADD32(ctx->r5, ctx->r17);
    // 0x800C8450: lhu         $a1, 0xE($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0XE);
    // 0x800C8454: jal         0x80001ACC
    // 0x800C8458: addiu       $a0, $a2, 0x1
    ctx->r4 = ADD32(ctx->r6, 0X1);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x800C8458: addiu       $a0, $a2, 0x1
    ctx->r4 = ADD32(ctx->r6, 0X1);
    after_0:
    // 0x800C845C: andi        $a0, $s2, 0xFF
    ctx->r4 = ctx->r18 & 0XFF;
    // 0x800C8460: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800C8464: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800C8468: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800C846C: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800C8470: sll         $a0, $v1, 3
    ctx->r4 = S32(ctx->r3 << 3);
    // 0x800C8474: addu        $v1, $s0, $a0
    ctx->r3 = ADD32(ctx->r16, ctx->r4);
    // 0x800C8478: bne         $v0, $zero, L_800C8488
    if (ctx->r2 != 0) {
        // 0x800C847C: sw          $v0, 0x5C($v1)
        MEM_W(0X5C, ctx->r3) = ctx->r2;
            goto L_800C8488;
    }
    // 0x800C847C: sw          $v0, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r2;
    // 0x800C8480: j           L_800C8508
    // 0x800C8484: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_800C8508;
    // 0x800C8484: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_800C8488:
    // 0x800C8488: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800C848C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800C8490: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x800C8494: addu        $v0, $a1, $s1
    ctx->r2 = ADD32(ctx->r5, ctx->r17);
L_800C8498:
    // 0x800C8498: lbu         $a0, -0x1($v0)
    ctx->r4 = MEM_BU(ctx->r2, -0X1);
    // 0x800C849C: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x800C84A0: beq         $v0, $zero, L_800C84C8
    if (ctx->r2 == 0) {
        // 0x800C84A4: addiu       $a0, $a0, -0x1
        ctx->r4 = ADD32(ctx->r4, -0X1);
            goto L_800C84C8;
    }
    // 0x800C84A4: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800C84A8: addu        $a3, $s0, $t0
    ctx->r7 = ADD32(ctx->r16, ctx->r8);
L_800C84AC:
    // 0x800C84AC: addu        $v1, $a0, $zero
    ctx->r3 = ADD32(ctx->r4, 0);
    // 0x800C84B0: lw          $v0, 0x5C($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X5C);
    // 0x800C84B4: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800C84B8: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800C84BC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800C84C0: bne         $v1, $zero, L_800C84AC
    if (ctx->r3 != 0) {
        // 0x800C84C4: sb          $a1, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r5;
            goto L_800C84AC;
    }
    // 0x800C84C4: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
L_800C84C8:
    // 0x800C84C8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800C84CC: slti        $v0, $a1, 0x11
    ctx->r2 = SIGNED(ctx->r5) < 0X11 ? 1 : 0;
    // 0x800C84D0: bne         $v0, $zero, L_800C8498
    if (ctx->r2 != 0) {
        // 0x800C84D4: addu        $v0, $a1, $s1
        ctx->r2 = ADD32(ctx->r5, ctx->r17);
            goto L_800C8498;
    }
    // 0x800C84D4: addu        $v0, $a1, $s1
    ctx->r2 = ADD32(ctx->r5, ctx->r17);
    // 0x800C84D8: andi        $v0, $s2, 0xFF
    ctx->r2 = ctx->r18 & 0XFF;
    // 0x800C84DC: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800C84E0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C84E4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800C84E8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C84EC: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800C84F0: addu        $v1, $s0, $v1
    ctx->r3 = ADD32(ctx->r16, ctx->r3);
    // 0x800C84F4: lw          $a0, 0x5C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X5C);
    // 0x800C84F8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800C84FC: addu        $a0, $a0, $a2
    ctx->r4 = ADD32(ctx->r4, ctx->r6);
    // 0x800C8500: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
    // 0x800C8504: sw          $a2, 0xFC($v1)
    MEM_W(0XFC, ctx->r3) = ctx->r6;
L_800C8508:
    // 0x800C8508: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C850C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800C8510: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800C8514: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800C8518: jr          $ra
    // 0x800C851C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C851C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800C8504(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8504: addiu       $sp, $sp, -0x108
    ctx->r29 = ADD32(ctx->r29, -0X108);
    // 0x800C8508: sw          $ra, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r31;
    // 0x800C850C: sw          $s5, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r21;
    // 0x800C8510: sw          $s4, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r20;
    // 0x800C8514: sw          $s3, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r19;
    // 0x800C8518: sw          $s2, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r18;
    // 0x800C851C: sw          $s1, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r17;
    // 0x800C8520: sw          $s0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r16;
    // 0x800C8524: sdc1        $f20, 0x100($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X100, ctx->r29);
    // 0x800C8528: lw          $s2, 0x4($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X4);
    // 0x800C852C: lw          $s3, 0x34($s2)
    ctx->r19 = MEM_W(ctx->r18, 0X34);
    // 0x800C8530: lw          $v0, 0xC0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0XC0);
    // 0x800C8534: bne         $v0, $zero, L_800C865C
    if (ctx->r2 != 0) {
        // 0x800C8538: lui         $s0, 0x800A
        ctx->r16 = S32(0X800A << 16);
            goto L_800C865C;
    }
    // 0x800C8538: lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // 0x800C853C: addiu       $s0, $s0, 0x6994
    ctx->r16 = ADD32(ctx->r16, 0X6994);
    // 0x800C8540: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800C8544: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800C8548: addiu       $s1, $sp, 0x88
    ctx->r17 = ADD32(ctx->r29, 0X88);
    // 0x800C854C: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x800C8550: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800C8554: lw          $a0, 0x30($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X30);
    // 0x800C8558: jal         0x80058360
    // 0x800C855C: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    lookupHmtTextureByName(rdram, ctx);
        goto after_0;
    // 0x800C855C: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x800C8560: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800C8564: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800C8568: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x800C856C: addiu       $s3, $sp, 0x58
    ctx->r19 = ADD32(ctx->r29, 0X58);
    // 0x800C8570: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x800C8574: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C8578: lw          $a0, 0x30($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X30);
    // 0x800C857C: jal         0x80058360
    // 0x800C8580: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    lookupHmtTextureByName(rdram, ctx);
        goto after_1;
    // 0x800C8580: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    after_1:
    // 0x800C8584: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x800C8588: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x800C858C: jal         0x800F2DC8
    // 0x800C8590: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    generatePerpEmitDirectionWithJitter(rdram, ctx);
        goto after_2;
    // 0x800C8590: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_2:
    // 0x800C8594: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x800C8598: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x800C859C: jal         0x800F2DC8
    // 0x800C85A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    generatePerpEmitDirectionWithJitter(rdram, ctx);
        goto after_3;
    // 0x800C85A0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_3:
    // 0x800C85A4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x800C85A8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800C85AC: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x800C85B0: jal         0x800F1870
    // 0x800C85B4: addiu       $a3, $sp, 0xD8
    ctx->r7 = ADD32(ctx->r29, 0XD8);
    tickProgressChannel(rdram, ctx);
        goto after_4;
    // 0x800C85B4: addiu       $a3, $sp, 0xD8
    ctx->r7 = ADD32(ctx->r29, 0XD8);
    after_4:
    // 0x800C85B8: andi        $s1, $v0, 0xFF
    ctx->r17 = ctx->r2 & 0XFF;
    // 0x800C85BC: bne         $s1, $s0, L_800C8950
    if (ctx->r17 != ctx->r16) {
        // 0x800C85C0: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800C8950;
    }
    // 0x800C85C0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800C85C4: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x800C85C8: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x800C85CC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800C85D0: jal         0x800F1870
    // 0x800C85D4: addiu       $a3, $sp, 0xDC
    ctx->r7 = ADD32(ctx->r29, 0XDC);
    tickProgressChannel(rdram, ctx);
        goto after_5;
    // 0x800C85D4: addiu       $a3, $sp, 0xDC
    ctx->r7 = ADD32(ctx->r29, 0XDC);
    after_5:
    // 0x800C85D8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800C85DC: bnel        $v0, $s1, L_800C8950
    if (ctx->r2 != ctx->r17) {
        // 0x800C85E0: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800C8950;
    }
    goto skip_0;
    // 0x800C85E0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    skip_0:
    // 0x800C85E4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800C85E8: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x800C85EC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C85F0: lwc1        $f20, 0x69C4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X69C4);
    // 0x800C85F4: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800C85F8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800C85FC: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800C8600: lwc1        $f0, 0xD8($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800C8604: addiu       $s0, $s0, -0x5A54
    ctx->r16 = ADD32(ctx->r16, -0X5A54);
    // 0x800C8608: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800C860C: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x800C8610: jal         0x800F2FCC
    // 0x800C8614: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    triggerCueWithSlotEffect(rdram, ctx);
        goto after_6;
    // 0x800C8614: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_6:
    // 0x800C8618: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800C861C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800C8620: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800C8624: lwc1        $f0, 0xDC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x800C8628: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x800C862C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800C8630: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x800C8634: jal         0x800F2FCC
    // 0x800C8638: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    triggerCueWithSlotEffect(rdram, ctx);
        goto after_7;
    // 0x800C8638: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_7:
    // 0x800C863C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800C8640: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800C8644: addiu       $a2, $a1, 0x24
    ctx->r6 = ADD32(ctx->r5, 0X24);
    // 0x800C8648: lui         $a3, 0x4190
    ctx->r7 = S32(0X4190 << 16);
    // 0x800C864C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C8650: lwc1        $f0, 0x69C8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X69C8);
    // 0x800C8654: j           L_800C892C
    // 0x800C8658: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
        goto L_800C892C;
    // 0x800C8658: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
L_800C865C:
    // 0x800C865C: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x800C8660: jal         0x800F2988
    // 0x800C8664: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    getObjectMeshTransformOrLocal(rdram, ctx);
        goto after_8;
    // 0x800C8664: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_8:
    // 0x800C8668: lwc1        $f0, 0xD4($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0XD4);
    // 0x800C866C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C8670: lwc1        $f2, 0x69CC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X69CC);
    // 0x800C8674: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C8678: lwc1        $f2, 0x4($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800C867C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800C8680: nop

    // 0x800C8684: bc1t        L_800C8950
    if (c1cs) {
        // 0x800C8688: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800C8950;
    }
    // 0x800C8688: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800C868C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C8690: lw          $v0, 0x7CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7CE4);
    // 0x800C8694: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C8698: addiu       $v0, $v0, 0xC4
    ctx->r2 = ADD32(ctx->r2, 0XC4);
    // 0x800C869C: addu        $a0, $s3, $v0
    ctx->r4 = ADD32(ctx->r19, ctx->r2);
    // 0x800C86A0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800C86A4: blez        $v1, L_800C8950
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800C86A8: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800C8950;
    }
    // 0x800C86A8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800C86AC: lw          $v0, 0xC8($s3)
    ctx->r2 = MEM_W(ctx->r19, 0XC8);
    // 0x800C86B0: bne         $v0, $zero, L_800C86BC
    if (ctx->r2 != 0) {
        // 0x800C86B4: addiu       $v0, $v1, -0x1
        ctx->r2 = ADD32(ctx->r3, -0X1);
            goto L_800C86BC;
    }
    // 0x800C86B4: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x800C86B8: addiu       $v0, $v1, -0x2
    ctx->r2 = ADD32(ctx->r3, -0X2);
L_800C86BC:
    // 0x800C86BC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800C86C0: sh          $zero, 0xB8($sp)
    MEM_H(0XB8, ctx->r29) = 0;
    // 0x800C86C4: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x800C86C8: jal         0x800F2A00
    // 0x800C86CC: ori         $s5, $zero, 0xFFFF
    ctx->r21 = 0 | 0XFFFF;
    getObjectNpcTypeId(rdram, ctx);
        goto after_9;
    // 0x800C86CC: ori         $s5, $zero, 0xFFFF
    ctx->r21 = 0 | 0XFFFF;
    after_9:
    // 0x800C86D0: lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // 0x800C86D4: addiu       $s0, $s0, 0x6994
    ctx->r16 = ADD32(ctx->r16, 0X6994);
    // 0x800C86D8: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800C86DC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800C86E0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800C86E4: sh          $v0, 0xBA($sp)
    MEM_H(0XBA, ctx->r29) = ctx->r2;
    // 0x800C86E8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800C86EC: addiu       $s1, $sp, 0x88
    ctx->r17 = ADD32(ctx->r29, 0X88);
    // 0x800C86F0: lw          $v1, 0x7CE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X7CE4);
    // 0x800C86F4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C86F8: lwc1        $f0, 0x69D0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X69D0);
    // 0x800C86FC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C8700: lwc1        $f4, 0x69D4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X69D4);
    // 0x800C8704: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800C8708: addu        $v1, $v1, $s3
    ctx->r3 = ADD32(ctx->r3, ctx->r19);
    // 0x800C870C: lwc1        $f2, 0xD0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0XD0);
    // 0x800C8710: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800C8714: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800C8718: sw          $zero, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = 0;
    // 0x800C871C: sw          $zero, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = 0;
    // 0x800C8720: swc1        $f4, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f4.u32l;
    // 0x800C8724: sb          $v0, 0xCC($sp)
    MEM_B(0XCC, ctx->r29) = ctx->r2;
    // 0x800C8728: swc1        $f2, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f2.u32l;
    // 0x800C872C: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x800C8730: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800C8734: lw          $a0, 0x30($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X30);
    // 0x800C8738: jal         0x80058360
    // 0x800C873C: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    lookupHmtTextureByName(rdram, ctx);
        goto after_10;
    // 0x800C873C: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    after_10:
    // 0x800C8740: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800C8744: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800C8748: addu        $s4, $a2, $zero
    ctx->r20 = ADD32(ctx->r6, 0);
    // 0x800C874C: addiu       $s0, $sp, 0x58
    ctx->r16 = ADD32(ctx->r29, 0X58);
    // 0x800C8750: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x800C8754: sw          $s4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r20;
    // 0x800C8758: lw          $a0, 0x30($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X30);
    // 0x800C875C: jal         0x80058360
    // 0x800C8760: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    lookupHmtTextureByName(rdram, ctx);
        goto after_11;
    // 0x800C8760: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_11:
    // 0x800C8764: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x800C8768: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x800C876C: jal         0x800F2DC8
    // 0x800C8770: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    generatePerpEmitDirectionWithJitter(rdram, ctx);
        goto after_12;
    // 0x800C8770: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_12:
    // 0x800C8774: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800C8778: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x800C877C: jal         0x800F2DC8
    // 0x800C8780: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    generatePerpEmitDirectionWithJitter(rdram, ctx);
        goto after_13;
    // 0x800C8780: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_13:
    // 0x800C8784: lw          $v0, 0xC8($s3)
    ctx->r2 = MEM_W(ctx->r19, 0XC8);
    // 0x800C8788: bne         $v0, $zero, L_800C882C
    if (ctx->r2 != 0) {
        // 0x800C878C: addu        $s1, $s5, $zero
        ctx->r17 = ADD32(ctx->r21, 0);
            goto L_800C882C;
    }
    // 0x800C878C: addu        $s1, $s5, $zero
    ctx->r17 = ADD32(ctx->r21, 0);
    // 0x800C8790: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x800C8794: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x800C8798: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800C879C: jal         0x800F1870
    // 0x800C87A0: addiu       $a3, $sp, 0xD8
    ctx->r7 = ADD32(ctx->r29, 0XD8);
    tickProgressChannel(rdram, ctx);
        goto after_14;
    // 0x800C87A0: addiu       $a3, $sp, 0xD8
    ctx->r7 = ADD32(ctx->r29, 0XD8);
    after_14:
    // 0x800C87A4: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800C87A8: bne         $v0, $s4, L_800C87DC
    if (ctx->r2 != ctx->r20) {
        // 0x800C87AC: addiu       $a1, $zero, 0xB
        ctx->r5 = ADD32(0, 0XB);
            goto L_800C87DC;
    }
    // 0x800C87AC: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x800C87B0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C87B4: lwc1        $f0, 0x69D8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X69D8);
    // 0x800C87B8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800C87BC: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800C87C0: lwc1        $f0, 0xD8($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800C87C4: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x800C87C8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800C87CC: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x800C87D0: jal         0x800F2FCC
    // 0x800C87D4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    triggerCueWithSlotEffect(rdram, ctx);
        goto after_15;
    // 0x800C87D4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_15:
    // 0x800C87D8: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
L_800C87DC:
    // 0x800C87DC: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x800C87E0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800C87E4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800C87E8: jal         0x800F1870
    // 0x800C87EC: addiu       $a3, $sp, 0xDC
    ctx->r7 = ADD32(ctx->r29, 0XDC);
    tickProgressChannel(rdram, ctx);
        goto after_16;
    // 0x800C87EC: addiu       $a3, $sp, 0xDC
    ctx->r7 = ADD32(ctx->r29, 0XDC);
    after_16:
    // 0x800C87F0: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800C87F4: bne         $v0, $s4, L_800C88C4
    if (ctx->r2 != ctx->r20) {
        // 0x800C87F8: addiu       $a1, $zero, 0xB
        ctx->r5 = ADD32(0, 0XB);
            goto L_800C88C4;
    }
    // 0x800C87F8: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x800C87FC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C8800: lwc1        $f0, 0x69DC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X69DC);
    // 0x800C8804: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800C8808: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800C880C: lwc1        $f0, 0xDC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x800C8810: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800C8814: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800C8818: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x800C881C: jal         0x800F2FCC
    // 0x800C8820: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    triggerCueWithSlotEffect(rdram, ctx);
        goto after_17;
    // 0x800C8820: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_17:
    // 0x800C8824: j           L_800C88C4
    // 0x800C8828: addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
        goto L_800C88C4;
    // 0x800C8828: addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
L_800C882C:
    // 0x800C882C: lhu         $v0, 0x74($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X74);
    // 0x800C8830: xori        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 ^ 0X1;
    // 0x800C8834: beq         $v0, $zero, L_800C8878
    if (ctx->r2 == 0) {
        // 0x800C8838: sh          $v0, 0x74($s2)
        MEM_H(0X74, ctx->r18) = ctx->r2;
            goto L_800C8878;
    }
    // 0x800C8838: sh          $v0, 0x74($s2)
    MEM_H(0X74, ctx->r18) = ctx->r2;
    // 0x800C883C: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x800C8840: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x800C8844: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800C8848: jal         0x800F1870
    // 0x800C884C: addiu       $a3, $sp, 0xD8
    ctx->r7 = ADD32(ctx->r29, 0XD8);
    tickProgressChannel(rdram, ctx);
        goto after_18;
    // 0x800C884C: addiu       $a3, $sp, 0xD8
    ctx->r7 = ADD32(ctx->r29, 0XD8);
    after_18:
    // 0x800C8850: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800C8854: bne         $v0, $s4, L_800C88C4
    if (ctx->r2 != ctx->r20) {
        // 0x800C8858: addiu       $a1, $zero, 0xB
        ctx->r5 = ADD32(0, 0XB);
            goto L_800C88C4;
    }
    // 0x800C8858: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x800C885C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C8860: lwc1        $f0, 0x69E0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X69E0);
    // 0x800C8864: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800C8868: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800C886C: lwc1        $f0, 0xD8($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800C8870: j           L_800C88B0
    // 0x800C8874: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
        goto L_800C88B0;
    // 0x800C8874: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
L_800C8878:
    // 0x800C8878: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x800C887C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800C8880: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800C8884: jal         0x800F1870
    // 0x800C8888: addiu       $a3, $sp, 0xDC
    ctx->r7 = ADD32(ctx->r29, 0XDC);
    tickProgressChannel(rdram, ctx);
        goto after_19;
    // 0x800C8888: addiu       $a3, $sp, 0xDC
    ctx->r7 = ADD32(ctx->r29, 0XDC);
    after_19:
    // 0x800C888C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800C8890: bne         $v0, $s4, L_800C88C4
    if (ctx->r2 != ctx->r20) {
        // 0x800C8894: addiu       $a1, $zero, 0xB
        ctx->r5 = ADD32(0, 0XB);
            goto L_800C88C4;
    }
    // 0x800C8894: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x800C8898: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C889C: lwc1        $f0, 0x69E4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X69E4);
    // 0x800C88A0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800C88A4: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800C88A8: lwc1        $f0, 0xDC($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XDC);
    // 0x800C88AC: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
L_800C88B0:
    // 0x800C88B0: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800C88B4: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x800C88B8: jal         0x800F2FCC
    // 0x800C88BC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    triggerCueWithSlotEffect(rdram, ctx);
        goto after_20;
    // 0x800C88BC: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_20:
    // 0x800C88C0: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
L_800C88C4:
    // 0x800C88C4: lw          $v0, 0xCC($s3)
    ctx->r2 = MEM_W(ctx->r19, 0XCC);
    // 0x800C88C8: beq         $v0, $zero, L_800C88F8
    if (ctx->r2 == 0) {
        // 0x800C88CC: andi        $a0, $s1, 0xFFFF
        ctx->r4 = ctx->r17 & 0XFFFF;
            goto L_800C88F8;
    }
    // 0x800C88CC: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    // 0x800C88D0: ori         $s0, $zero, 0xFFFF
    ctx->r16 = 0 | 0XFFFF;
    // 0x800C88D4: beq         $a0, $s0, L_800C88E4
    if (ctx->r4 == ctx->r16) {
        // 0x800C88D8: addiu       $a1, $zero, 0xA
        ctx->r5 = ADD32(0, 0XA);
            goto L_800C88E4;
    }
    // 0x800C88D8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x800C88DC: jal         0x8003E8DC
    // 0x800C88E0: addiu       $a2, $sp, 0xB8
    ctx->r6 = ADD32(ctx->r29, 0XB8);
    slotDispatcherIter(rdram, ctx);
        goto after_21;
    // 0x800C88E0: addiu       $a2, $sp, 0xB8
    ctx->r6 = ADD32(ctx->r29, 0XB8);
    after_21:
L_800C88E4:
    // 0x800C88E4: andi        $a0, $s5, 0xFFFF
    ctx->r4 = ctx->r21 & 0XFFFF;
    // 0x800C88E8: beq         $a0, $s0, L_800C88F8
    if (ctx->r4 == ctx->r16) {
        // 0x800C88EC: addiu       $a1, $zero, 0xA
        ctx->r5 = ADD32(0, 0XA);
            goto L_800C88F8;
    }
    // 0x800C88EC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x800C88F0: jal         0x8003E8DC
    // 0x800C88F4: addiu       $a2, $sp, 0xB8
    ctx->r6 = ADD32(ctx->r29, 0XB8);
    slotDispatcherIter(rdram, ctx);
        goto after_22;
    // 0x800C88F4: addiu       $a2, $sp, 0xB8
    ctx->r6 = ADD32(ctx->r29, 0XB8);
    after_22:
L_800C88F8:
    // 0x800C88F8: andi        $v1, $s1, 0xFFFF
    ctx->r3 = ctx->r17 & 0XFFFF;
    // 0x800C88FC: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800C8900: bne         $v1, $v0, L_800C8914
    if (ctx->r3 != ctx->r2) {
        // 0x800C8904: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800C8914;
    }
    // 0x800C8904: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800C8908: andi        $v0, $s5, 0xFFFF
    ctx->r2 = ctx->r21 & 0XFFFF;
    // 0x800C890C: beq         $v0, $v1, L_800C8950
    if (ctx->r2 == ctx->r3) {
        // 0x800C8910: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800C8950;
    }
    // 0x800C8910: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800C8914:
    // 0x800C8914: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800C8918: addiu       $a2, $a1, 0x24
    ctx->r6 = ADD32(ctx->r5, 0X24);
    // 0x800C891C: lui         $a3, 0x4198
    ctx->r7 = S32(0X4198 << 16);
    // 0x800C8920: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C8924: lwc1        $f0, 0x69E8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X69E8);
    // 0x800C8928: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
L_800C892C:
    // 0x800C892C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800C8930: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x800C8934: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800C8938: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // 0x800C893C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800C8940: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800C8944: jal         0x800989D8
    // 0x800C8948: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    play3DSoundEvent(rdram, ctx);
        goto after_23;
    // 0x800C8948: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_23:
    // 0x800C894C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800C8950:
    // 0x800C8950: lw          $ra, 0xF8($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XF8);
    // 0x800C8954: lw          $s5, 0xF4($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XF4);
    // 0x800C8958: lw          $s4, 0xF0($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XF0);
    // 0x800C895C: lw          $s3, 0xEC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XEC);
    // 0x800C8960: lw          $s2, 0xE8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XE8);
    // 0x800C8964: lw          $s1, 0xE4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XE4);
    // 0x800C8968: lw          $s0, 0xE0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XE0);
    // 0x800C896C: ldc1        $f20, 0x100($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X100);
    // 0x800C8970: jr          $ra
    // 0x800C8974: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
    return;
    // 0x800C8974: addiu       $sp, $sp, 0x108
    ctx->r29 = ADD32(ctx->r29, 0X108);
;}
RECOMP_FUNC void func_800C8520(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8520: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C8524: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800C8528: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800C852C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800C8530: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x800C8534: andi        $v1, $s0, 0xFF
    ctx->r3 = ctx->r16 & 0XFF;
    // 0x800C8538: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800C853C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C8540: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C8544: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C8548: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800C854C: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x800C8550: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800C8554: lw          $v0, 0x5C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5C);
    // 0x800C8558: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800C855C: lb          $t1, 0x0($v0)
    ctx->r9 = MEM_B(ctx->r2, 0X0);
    // 0x800C8560: beq         $t1, $zero, L_800C85EC
    if (ctx->r9 == 0) {
        // 0x800C8564: addu        $t0, $a2, $zero
        ctx->r8 = ADD32(ctx->r6, 0);
            goto L_800C85EC;
    }
    // 0x800C8564: addu        $t0, $a2, $zero
    ctx->r8 = ADD32(ctx->r6, 0);
    // 0x800C8568: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800C856C:
    // 0x800C856C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800C8570: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C8574: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C8578: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C857C: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800C8580: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x800C8584: lw          $v1, 0x5C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X5C);
    // 0x800C8588: addu        $v0, $v1, $a2
    ctx->r2 = ADD32(ctx->r3, ctx->r6);
    // 0x800C858C: lb          $v0, 0x0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X0);
    // 0x800C8590: bne         $v0, $t1, L_800C85B0
    if (ctx->r2 != ctx->r9) {
        // 0x800C8594: sllv        $v0, $a0, $t1
        ctx->r2 = S32(ctx->r4 << (ctx->r9 & 31));
            goto L_800C85B0;
    }
    // 0x800C8594: sllv        $v0, $a0, $t1
    ctx->r2 = S32(ctx->r4 << (ctx->r9 & 31));
L_800C8598:
    // 0x800C8598: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800C859C: addu        $v0, $v1, $a2
    ctx->r2 = ADD32(ctx->r3, ctx->r6);
    // 0x800C85A0: lb          $v0, 0x0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X0);
    // 0x800C85A4: beq         $v0, $t1, L_800C8598
    if (ctx->r2 == ctx->r9) {
        // 0x800C85A8: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_800C8598;
    }
    // 0x800C85A8: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800C85AC: sllv        $v0, $a0, $t1
    ctx->r2 = S32(ctx->r4 << (ctx->r9 & 31));
L_800C85B0:
    // 0x800C85B0: slt         $v0, $t0, $v0
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800C85B4: beq         $v0, $zero, L_800C8624
    if (ctx->r2 == 0) {
        // 0x800C85B8: andi        $v1, $s0, 0xFF
        ctx->r3 = ctx->r16 & 0XFF;
            goto L_800C8624;
    }
    // 0x800C85B8: andi        $v1, $s0, 0xFF
    ctx->r3 = ctx->r16 & 0XFF;
    // 0x800C85BC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800C85C0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C85C4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C85C8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C85CC: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800C85D0: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x800C85D4: lw          $v0, 0x5C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5C);
    // 0x800C85D8: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x800C85DC: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800C85E0: lb          $v0, 0x0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X0);
    // 0x800C85E4: bne         $v0, $zero, L_800C856C
    if (ctx->r2 != 0) {
        // 0x800C85E8: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_800C856C;
    }
    // 0x800C85E8: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_800C85EC:
    // 0x800C85EC: lhu         $a1, 0xE($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0XE);
    // 0x800C85F0: jal         0x80001ACC
    // 0x800C85F4: sll         $a0, $a2, 2
    ctx->r4 = S32(ctx->r6 << 2);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x800C85F4: sll         $a0, $a2, 2
    ctx->r4 = S32(ctx->r6 << 2);
    after_0:
    // 0x800C85F8: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    // 0x800C85FC: sll         $v1, $a1, 2
    ctx->r3 = S32(ctx->r5 << 2);
    // 0x800C8600: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800C8604: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800C8608: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x800C860C: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800C8610: addu        $v1, $s1, $v1
    ctx->r3 = ADD32(ctx->r17, ctx->r3);
    // 0x800C8614: bne         $v0, $zero, L_800C862C
    if (ctx->r2 != 0) {
        // 0x800C8618: sw          $v0, 0x60($v1)
        MEM_W(0X60, ctx->r3) = ctx->r2;
            goto L_800C862C;
    }
    // 0x800C8618: sw          $v0, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->r2;
    // 0x800C861C: j           L_800C86B4
    // 0x800C8620: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
        goto L_800C86B4;
    // 0x800C8620: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
L_800C8624:
    // 0x800C8624: j           L_800C86B4
    // 0x800C8628: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
        goto L_800C86B4;
    // 0x800C8628: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_800C862C:
    // 0x800C862C: lw          $v0, 0x5C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X5C);
    // 0x800C8630: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800C8634: lb          $t1, 0x0($v0)
    ctx->r9 = MEM_B(ctx->r2, 0X0);
    // 0x800C8638: beq         $t1, $zero, L_800C86B0
    if (ctx->r9 == 0) {
        // 0x800C863C: addu        $t0, $a2, $zero
        ctx->r8 = ADD32(ctx->r6, 0);
            goto L_800C86B0;
    }
    // 0x800C863C: addu        $t0, $a2, $zero
    ctx->r8 = ADD32(ctx->r6, 0);
    // 0x800C8640: addu        $t2, $v1, $zero
    ctx->r10 = ADD32(ctx->r3, 0);
L_800C8644:
    // 0x800C8644: lw          $v0, 0x5C($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X5C);
    // 0x800C8648: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800C864C: lb          $v0, 0x0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X0);
    // 0x800C8650: bne         $v0, $t1, L_800C8698
    if (ctx->r2 != ctx->r9) {
        // 0x800C8654: addu        $a3, $a1, $zero
        ctx->r7 = ADD32(ctx->r5, 0);
            goto L_800C8698;
    }
    // 0x800C8654: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
L_800C8658:
    // 0x800C8658: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
    // 0x800C865C: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x800C8660: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C8664: addu        $v0, $v0, $a3
    ctx->r2 = ADD32(ctx->r2, ctx->r7);
    // 0x800C8668: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800C866C: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x800C8670: lw          $a0, 0x60($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X60);
    // 0x800C8674: sll         $v1, $a2, 2
    ctx->r3 = S32(ctx->r6 << 2);
    // 0x800C8678: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800C867C: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800C8680: lw          $v0, 0x5C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5C);
    // 0x800C8684: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800C8688: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800C868C: lb          $v0, 0x0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X0);
    // 0x800C8690: beq         $v0, $t1, L_800C8658
    if (ctx->r2 == ctx->r9) {
        // 0x800C8694: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_800C8658;
    }
    // 0x800C8694: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_800C8698:
    // 0x800C8698: lw          $v0, 0x5C($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X5C);
    // 0x800C869C: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x800C86A0: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x800C86A4: lb          $v0, 0x0($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X0);
    // 0x800C86A8: bne         $v0, $zero, L_800C8644
    if (ctx->r2 != 0) {
        // 0x800C86AC: addiu       $t1, $t1, 0x1
        ctx->r9 = ADD32(ctx->r9, 0X1);
            goto L_800C8644;
    }
    // 0x800C86AC: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
L_800C86B0:
    // 0x800C86B0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_800C86B4:
    // 0x800C86B4: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800C86B8: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800C86BC: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800C86C0: jr          $ra
    // 0x800C86C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C86C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800C86C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C86C8: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x800C86CC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800C86D0: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800C86D4: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
    // 0x800C86D8: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800C86DC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C86E0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C86E4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C86E8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800C86EC: addiu       $v0, $v0, 0x58
    ctx->r2 = ADD32(ctx->r2, 0X58);
    // 0x800C86F0: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800C86F4: addiu       $a2, $a0, 0x4
    ctx->r6 = ADD32(ctx->r4, 0X4);
L_800C86F8:
    // 0x800C86F8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C86FC: addu        $v0, $a3, $v0
    ctx->r2 = ADD32(ctx->r7, ctx->r2);
    // 0x800C8700: lbu         $v0, -0x1($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X1);
    // 0x800C8704: beq         $v0, $zero, L_800C8748
    if (ctx->r2 == 0) {
        // 0x800C8708: sll         $v0, $t0, 2
        ctx->r2 = S32(ctx->r8 << 2);
            goto L_800C8748;
    }
    // 0x800C8708: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x800C870C: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x800C8710: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C8714: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800C8718: subu        $v0, $t0, $v0
    ctx->r2 = SUB32(ctx->r8, ctx->r2);
    // 0x800C871C: sw          $v0, 0x5C($a2)
    MEM_W(0X5C, ctx->r6) = ctx->r2;
    // 0x800C8720: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C8724: addu        $v0, $a3, $v0
    ctx->r2 = ADD32(ctx->r7, ctx->r2);
    // 0x800C8728: lbu         $v0, -0x1($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X1);
    // 0x800C872C: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x800C8730: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // 0x800C8734: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x800C8738: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C873C: lw          $v0, -0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4);
    // 0x800C8740: j           L_800C8750
    // 0x800C8744: sw          $v0, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r2;
        goto L_800C8750;
    // 0x800C8744: sw          $v0, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r2;
L_800C8748:
    // 0x800C8748: sw          $t1, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r9;
    // 0x800C874C: sw          $t1, 0x5C($a2)
    MEM_W(0X5C, ctx->r6) = ctx->r9;
L_800C8750:
    // 0x800C8750: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800C8754: slti        $v0, $a3, 0x11
    ctx->r2 = SIGNED(ctx->r7) < 0X11 ? 1 : 0;
    // 0x800C8758: bne         $v0, $zero, L_800C86F8
    if (ctx->r2 != 0) {
        // 0x800C875C: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_800C86F8;
    }
    // 0x800C875C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800C8760: lui         $v0, 0xF
    ctx->r2 = S32(0XF << 16);
    // 0x800C8764: ori         $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 | 0XFFFF;
    // 0x800C8768: sw          $v0, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->r2;
    // 0x800C876C: andi        $v0, $a1, 0x1
    ctx->r2 = ctx->r5 & 0X1;
    // 0x800C8770: bne         $v0, $zero, L_800C87A8
    if (ctx->r2 != 0) {
        // 0x800C8774: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_800C87A8;
    }
    // 0x800C8774: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800C8778: lw          $a1, 0x10($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X10);
    // 0x800C877C: lw          $a0, 0xA4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XA4);
    // 0x800C8780: addu        $v0, $a1, $v1
    ctx->r2 = ADD32(ctx->r5, ctx->r3);
L_800C8784:
    // 0x800C8784: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800C8788: sltiu       $v0, $v0, 0x10
    ctx->r2 = ctx->r2 < 0X10 ? 1 : 0;
    // 0x800C878C: bne         $v0, $zero, L_800C879C
    if (ctx->r2 != 0) {
        // 0x800C8790: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800C879C;
    }
    // 0x800C8790: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800C8794: jr          $ra
    // 0x800C8798: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    return;
    // 0x800C8798: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_800C879C:
    // 0x800C879C: sltu        $v0, $a0, $v1
    ctx->r2 = ctx->r4 < ctx->r3 ? 1 : 0;
    // 0x800C87A0: beq         $v0, $zero, L_800C8784
    if (ctx->r2 == 0) {
        // 0x800C87A4: addu        $v0, $a1, $v1
        ctx->r2 = ADD32(ctx->r5, ctx->r3);
            goto L_800C8784;
    }
    // 0x800C87A4: addu        $v0, $a1, $v1
    ctx->r2 = ADD32(ctx->r5, ctx->r3);
L_800C87A8:
    // 0x800C87A8: jr          $ra
    // 0x800C87AC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x800C87AC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void func_800C87B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C87B0: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x800C87B4: addu        $t0, $zero, $zero
    ctx->r8 = ADD32(0, 0);
    // 0x800C87B8: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x800C87BC: beq         $a1, $zero, L_800C8884
    if (ctx->r5 == 0) {
        // 0x800C87C0: addu        $a3, $zero, $zero
        ctx->r7 = ADD32(0, 0);
            goto L_800C8884;
    }
    // 0x800C87C0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x800C87C4: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x800C87C8: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800C87CC: addiu       $t2, $zero, 0xD9
    ctx->r10 = ADD32(0, 0XD9);
    // 0x800C87D0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_800C87D4:
    // 0x800C87D4: lhu         $v0, 0x46($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X46);
    // 0x800C87D8: bne         $v0, $zero, L_800C8850
    if (ctx->r2 != 0) {
        // 0x800C87DC: sll         $a3, $a3, 1
        ctx->r7 = S32(ctx->r7 << 1);
            goto L_800C8850;
    }
    // 0x800C87DC: sll         $a3, $a3, 1
    ctx->r7 = S32(ctx->r7 << 1);
    // 0x800C87E0: lbu         $v0, 0x4D($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X4D);
    // 0x800C87E4: bne         $v0, $zero, L_800C8800
    if (ctx->r2 != 0) {
        // 0x800C87E8: sh          $t4, 0x46($a2)
        MEM_H(0X46, ctx->r6) = ctx->r12;
            goto L_800C8800;
    }
    // 0x800C87E8: sh          $t4, 0x46($a2)
    MEM_H(0X46, ctx->r6) = ctx->r12;
    // 0x800C87EC: lw          $v0, 0x34($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X34);
    // 0x800C87F0: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x800C87F4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C87F8: j           L_800C8804
    // 0x800C87FC: sw          $v0, 0x34($a2)
    MEM_W(0X34, ctx->r6) = ctx->r2;
        goto L_800C8804;
    // 0x800C87FC: sw          $v0, 0x34($a2)
    MEM_W(0X34, ctx->r6) = ctx->r2;
L_800C8800:
    // 0x800C8800: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800C8804:
    // 0x800C8804: bne         $v1, $t3, L_800C8828
    if (ctx->r3 != ctx->r11) {
        // 0x800C8808: sh          $v1, 0x44($a2)
        MEM_H(0X44, ctx->r6) = ctx->r3;
            goto L_800C8828;
    }
    // 0x800C8808: sh          $v1, 0x44($a2)
    MEM_H(0X44, ctx->r6) = ctx->r3;
    // 0x800C880C: lw          $v0, 0x34($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X34);
    // 0x800C8810: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x800C8814: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C8818: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x800C881C: bne         $v1, $t2, L_800C8828
    if (ctx->r3 != ctx->r10) {
        // 0x800C8820: sw          $v0, 0x34($a2)
        MEM_W(0X34, ctx->r6) = ctx->r2;
            goto L_800C8828;
    }
    // 0x800C8820: sw          $v0, 0x34($a2)
    MEM_W(0X34, ctx->r6) = ctx->r2;
    // 0x800C8824: sb          $t1, 0x4D($a2)
    MEM_B(0X4D, ctx->r6) = ctx->r9;
L_800C8828:
    // 0x800C8828: lhu         $v0, 0x44($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X44);
    // 0x800C882C: lhu         $a0, 0x46($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X46);
    // 0x800C8830: srl         $v1, $v0, 7
    ctx->r3 = S32(U32(ctx->r2) >> 7);
    // 0x800C8834: andi        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 & 0X1;
    // 0x800C8838: addu        $a3, $a3, $v1
    ctx->r7 = ADD32(ctx->r7, ctx->r3);
    // 0x800C883C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800C8840: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800C8844: sh          $a0, 0x46($a2)
    MEM_H(0X46, ctx->r6) = ctx->r4;
    // 0x800C8848: j           L_800C8870
    // 0x800C884C: sh          $v0, 0x44($a2)
    MEM_H(0X44, ctx->r6) = ctx->r2;
        goto L_800C8870;
    // 0x800C884C: sh          $v0, 0x44($a2)
    MEM_H(0X44, ctx->r6) = ctx->r2;
L_800C8850:
    // 0x800C8850: lhu         $v1, 0x44($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X44);
    // 0x800C8854: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800C8858: sh          $v0, 0x46($a2)
    MEM_H(0X46, ctx->r6) = ctx->r2;
    // 0x800C885C: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800C8860: srl         $v0, $v1, 8
    ctx->r2 = S32(U32(ctx->r3) >> 8);
    // 0x800C8864: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800C8868: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x800C886C: sh          $v1, 0x44($a2)
    MEM_H(0X44, ctx->r6) = ctx->r3;
L_800C8870:
    // 0x800C8870: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800C8874: andi        $v0, $t0, 0xFF
    ctx->r2 = ctx->r8 & 0XFF;
    // 0x800C8878: sltu        $v0, $v0, $a1
    ctx->r2 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x800C887C: bne         $v0, $zero, L_800C87D4
    if (ctx->r2 != 0) {
        // 0x800C8880: nop
    
            goto L_800C87D4;
    }
    // 0x800C8880: nop

L_800C8884:
    // 0x800C8884: jr          $ra
    // 0x800C8888: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
    return;
    // 0x800C8888: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
;}
RECOMP_FUNC void func_800C888C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C888C: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x800C8890: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800C8894: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x800C8898: sll         $v0, $a1, 2
    ctx->r2 = S32(ctx->r5 << 2);
    // 0x800C889C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800C88A0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C88A4: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800C88A8: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800C88AC: addiu       $v0, $v0, 0x58
    ctx->r2 = ADD32(ctx->r2, 0X58);
    // 0x800C88B0: lhu         $v1, 0x46($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X46);
    // 0x800C88B4: bne         $v1, $zero, L_800C8934
    if (ctx->r3 != 0) {
        // 0x800C88B8: addu        $t1, $a2, $v0
        ctx->r9 = ADD32(ctx->r6, ctx->r2);
            goto L_800C8934;
    }
    // 0x800C88B8: addu        $t1, $a2, $v0
    ctx->r9 = ADD32(ctx->r6, ctx->r2);
    // 0x800C88BC: lbu         $v1, 0x4D($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X4D);
    // 0x800C88C0: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800C88C4: bne         $v1, $zero, L_800C88E0
    if (ctx->r3 != 0) {
        // 0x800C88C8: sh          $v0, 0x46($a2)
        MEM_H(0X46, ctx->r6) = ctx->r2;
            goto L_800C88E0;
    }
    // 0x800C88C8: sh          $v0, 0x46($a2)
    MEM_H(0X46, ctx->r6) = ctx->r2;
    // 0x800C88CC: lw          $v0, 0x34($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X34);
    // 0x800C88D0: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x800C88D4: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x800C88D8: j           L_800C88E4
    // 0x800C88DC: sw          $v0, 0x34($a2)
    MEM_W(0X34, ctx->r6) = ctx->r2;
        goto L_800C88E4;
    // 0x800C88DC: sw          $v0, 0x34($a2)
    MEM_W(0X34, ctx->r6) = ctx->r2;
L_800C88E0:
    // 0x800C88E0: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800C88E4:
    // 0x800C88E4: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x800C88E8: bne         $v1, $v0, L_800C8914
    if (ctx->r3 != ctx->r2) {
        // 0x800C88EC: sh          $v1, 0x44($a2)
        MEM_H(0X44, ctx->r6) = ctx->r3;
            goto L_800C8914;
    }
    // 0x800C88EC: sh          $v1, 0x44($a2)
    MEM_H(0X44, ctx->r6) = ctx->r3;
    // 0x800C88F0: lw          $v0, 0x34($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X34);
    // 0x800C88F4: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x800C88F8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C88FC: sw          $v0, 0x34($a2)
    MEM_W(0X34, ctx->r6) = ctx->r2;
    // 0x800C8900: addiu       $v0, $zero, 0xD9
    ctx->r2 = ADD32(0, 0XD9);
    // 0x800C8904: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x800C8908: bne         $v1, $v0, L_800C8914
    if (ctx->r3 != ctx->r2) {
        // 0x800C890C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800C8914;
    }
    // 0x800C890C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C8910: sb          $v0, 0x4D($a2)
    MEM_B(0X4D, ctx->r6) = ctx->r2;
L_800C8914:
    // 0x800C8914: lhu         $v0, 0x44($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X44);
    // 0x800C8918: lhu         $v1, 0x46($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X46);
    // 0x800C891C: srl         $a0, $v0, 7
    ctx->r4 = S32(U32(ctx->r2) >> 7);
    // 0x800C8920: andi        $a1, $a0, 0x1
    ctx->r5 = ctx->r4 & 0X1;
    // 0x800C8924: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800C8928: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800C892C: j           L_800C894C
    // 0x800C8930: sh          $v1, 0x46($a2)
    MEM_H(0X46, ctx->r6) = ctx->r3;
        goto L_800C894C;
    // 0x800C8930: sh          $v1, 0x46($a2)
    MEM_H(0X46, ctx->r6) = ctx->r3;
L_800C8934:
    // 0x800C8934: lhu         $v0, 0x44($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X44);
    // 0x800C8938: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800C893C: sh          $v1, 0x46($a2)
    MEM_H(0X46, ctx->r6) = ctx->r3;
    // 0x800C8940: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800C8944: srl         $v1, $v0, 8
    ctx->r3 = S32(U32(ctx->r2) >> 8);
    // 0x800C8948: andi        $a1, $v1, 0x1
    ctx->r5 = ctx->r3 & 0X1;
L_800C894C:
    // 0x800C894C: sh          $v0, 0x44($a2)
    MEM_H(0X44, ctx->r6) = ctx->r2;
    // 0x800C8950: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x800C8954: addu        $v1, $t1, $v0
    ctx->r3 = ADD32(ctx->r9, ctx->r2);
    // 0x800C8958: lw          $v0, 0x14($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X14);
    // 0x800C895C: slt         $v0, $v0, $a1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800C8960: beq         $v0, $zero, L_800C8A30
    if (ctx->r2 == 0) {
        // 0x800C8964: slti        $v0, $t0, 0x11
        ctx->r2 = SIGNED(ctx->r8) < 0X11 ? 1 : 0;
            goto L_800C8A30;
    }
    // 0x800C8964: slti        $v0, $t0, 0x11
    ctx->r2 = SIGNED(ctx->r8) < 0X11 ? 1 : 0;
    // 0x800C8968: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x800C896C: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800C8970: addiu       $t3, $zero, 0xD9
    ctx->r11 = ADD32(0, 0XD9);
    // 0x800C8974: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800C8978: addu        $a3, $v1, $zero
    ctx->r7 = ADD32(ctx->r3, 0);
L_800C897C:
    // 0x800C897C: lhu         $v0, 0x46($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X46);
    // 0x800C8980: bne         $v0, $zero, L_800C89F8
    if (ctx->r2 != 0) {
        // 0x800C8984: sll         $a1, $a1, 1
        ctx->r5 = S32(ctx->r5 << 1);
            goto L_800C89F8;
    }
    // 0x800C8984: sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5 << 1);
    // 0x800C8988: lbu         $v0, 0x4D($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X4D);
    // 0x800C898C: bne         $v0, $zero, L_800C89A8
    if (ctx->r2 != 0) {
        // 0x800C8990: sh          $t5, 0x46($a2)
        MEM_H(0X46, ctx->r6) = ctx->r13;
            goto L_800C89A8;
    }
    // 0x800C8990: sh          $t5, 0x46($a2)
    MEM_H(0X46, ctx->r6) = ctx->r13;
    // 0x800C8994: lw          $v0, 0x34($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X34);
    // 0x800C8998: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x800C899C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C89A0: j           L_800C89AC
    // 0x800C89A4: sw          $v0, 0x34($a2)
    MEM_W(0X34, ctx->r6) = ctx->r2;
        goto L_800C89AC;
    // 0x800C89A4: sw          $v0, 0x34($a2)
    MEM_W(0X34, ctx->r6) = ctx->r2;
L_800C89A8:
    // 0x800C89A8: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_800C89AC:
    // 0x800C89AC: bne         $v1, $t4, L_800C89D0
    if (ctx->r3 != ctx->r12) {
        // 0x800C89B0: sh          $v1, 0x44($a2)
        MEM_H(0X44, ctx->r6) = ctx->r3;
            goto L_800C89D0;
    }
    // 0x800C89B0: sh          $v1, 0x44($a2)
    MEM_H(0X44, ctx->r6) = ctx->r3;
    // 0x800C89B4: lw          $v0, 0x34($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X34);
    // 0x800C89B8: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x800C89BC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C89C0: andi        $v1, $v1, 0xFF
    ctx->r3 = ctx->r3 & 0XFF;
    // 0x800C89C4: bne         $v1, $t3, L_800C89D0
    if (ctx->r3 != ctx->r11) {
        // 0x800C89C8: sw          $v0, 0x34($a2)
        MEM_W(0X34, ctx->r6) = ctx->r2;
            goto L_800C89D0;
    }
    // 0x800C89C8: sw          $v0, 0x34($a2)
    MEM_W(0X34, ctx->r6) = ctx->r2;
    // 0x800C89CC: sb          $t2, 0x4D($a2)
    MEM_B(0X4D, ctx->r6) = ctx->r10;
L_800C89D0:
    // 0x800C89D0: lhu         $v0, 0x44($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X44);
    // 0x800C89D4: lhu         $a0, 0x46($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0X46);
    // 0x800C89D8: srl         $v1, $v0, 7
    ctx->r3 = S32(U32(ctx->r2) >> 7);
    // 0x800C89DC: andi        $v1, $v1, 0x1
    ctx->r3 = ctx->r3 & 0X1;
    // 0x800C89E0: or          $a1, $a1, $v1
    ctx->r5 = ctx->r5 | ctx->r3;
    // 0x800C89E4: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800C89E8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800C89EC: sh          $a0, 0x46($a2)
    MEM_H(0X46, ctx->r6) = ctx->r4;
    // 0x800C89F0: j           L_800C8A18
    // 0x800C89F4: sh          $v0, 0x44($a2)
    MEM_H(0X44, ctx->r6) = ctx->r2;
        goto L_800C8A18;
    // 0x800C89F4: sh          $v0, 0x44($a2)
    MEM_H(0X44, ctx->r6) = ctx->r2;
L_800C89F8:
    // 0x800C89F8: lhu         $v1, 0x44($a2)
    ctx->r3 = MEM_HU(ctx->r6, 0X44);
    // 0x800C89FC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800C8A00: sh          $v0, 0x46($a2)
    MEM_H(0X46, ctx->r6) = ctx->r2;
    // 0x800C8A04: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800C8A08: srl         $v0, $v1, 8
    ctx->r2 = S32(U32(ctx->r3) >> 8);
    // 0x800C8A0C: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800C8A10: or          $a1, $a1, $v0
    ctx->r5 = ctx->r5 | ctx->r2;
    // 0x800C8A14: sh          $v1, 0x44($a2)
    MEM_H(0X44, ctx->r6) = ctx->r3;
L_800C8A18:
    // 0x800C8A18: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800C8A1C: lw          $v0, 0x14($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X14);
    // 0x800C8A20: slt         $v0, $v0, $a1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800C8A24: bne         $v0, $zero, L_800C897C
    if (ctx->r2 != 0) {
        // 0x800C8A28: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_800C897C;
    }
    // 0x800C8A28: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800C8A2C: slti        $v0, $t0, 0x11
    ctx->r2 = SIGNED(ctx->r8) < 0X11 ? 1 : 0;
L_800C8A30:
    // 0x800C8A30: bne         $v0, $zero, L_800C8A44
    if (ctx->r2 != 0) {
        // 0x800C8A34: sll         $v0, $t0, 2
        ctx->r2 = S32(ctx->r8 << 2);
            goto L_800C8A44;
    }
    // 0x800C8A34: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x800C8A38: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800C8A3C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800C8A40: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
L_800C8A44:
    // 0x800C8A44: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x800C8A48: lw          $v0, 0x5C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X5C);
    // 0x800C8A4C: lw          $v1, 0x10($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X10);
    // 0x800C8A50: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x800C8A54: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C8A58: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800C8A5C: jr          $ra
    // 0x800C8A60: nop

    return;
    // 0x800C8A60: nop

;}
RECOMP_FUNC void func_800C8978(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8978: addiu       $sp, $sp, -0x1C8
    ctx->r29 = ADD32(ctx->r29, -0X1C8);
    // 0x800C897C: sw          $s2, 0x180($sp)
    MEM_W(0X180, ctx->r29) = ctx->r18;
    // 0x800C8980: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x800C8984: sw          $s0, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r16;
    // 0x800C8988: addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
    // 0x800C898C: sdc1        $f22, 0x1A8($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X1A8, ctx->r29);
    // 0x800C8990: mtc1        $a1, $f22
    ctx->f22.u32l = ctx->r5;
    // 0x800C8994: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800C8998: sw          $ra, 0x19C($sp)
    MEM_W(0X19C, ctx->r29) = ctx->r31;
    // 0x800C899C: sw          $fp, 0x198($sp)
    MEM_W(0X198, ctx->r29) = ctx->r30;
    // 0x800C89A0: sw          $s7, 0x194($sp)
    MEM_W(0X194, ctx->r29) = ctx->r23;
    // 0x800C89A4: sw          $s6, 0x190($sp)
    MEM_W(0X190, ctx->r29) = ctx->r22;
    // 0x800C89A8: sw          $s5, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r21;
    // 0x800C89AC: sw          $s4, 0x188($sp)
    MEM_W(0X188, ctx->r29) = ctx->r20;
    // 0x800C89B0: sw          $s3, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r19;
    // 0x800C89B4: sw          $s1, 0x17C($sp)
    MEM_W(0X17C, ctx->r29) = ctx->r17;
    // 0x800C89B8: sdc1        $f28, 0x1C0($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X1C0, ctx->r29);
    // 0x800C89BC: sdc1        $f26, 0x1B8($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X1B8, ctx->r29);
    // 0x800C89C0: sdc1        $f24, 0x1B0($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X1B0, ctx->r29);
    // 0x800C89C4: sdc1        $f20, 0x1A0($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X1A0, ctx->r29);
    // 0x800C89C8: lw          $t0, 0xC($s2)
    ctx->r8 = MEM_W(ctx->r18, 0XC);
    // 0x800C89CC: lw          $t1, 0x10($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X10);
    // 0x800C89D0: lw          $t2, 0x14($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X14);
    // 0x800C89D4: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800C89D8: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x800C89DC: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x800C89E0: lw          $a1, 0x60($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X60);
    // 0x800C89E4: jal         0x8001CC3C
    // 0x800C89E8: addiu       $s1, $s2, 0xC
    ctx->r17 = ADD32(ctx->r18, 0XC);
    buildRotationMatrixSlot0(rdram, ctx);
        goto after_0;
    // 0x800C89E8: addiu       $s1, $s2, 0xC
    ctx->r17 = ADD32(ctx->r18, 0XC);
    after_0:
    // 0x800C89EC: lwc1        $f2, 0x5C($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X5C);
    // 0x800C89F0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C89F4: lwc1        $f0, 0x69EC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X69EC);
    // 0x800C89F8: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800C89FC: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800C8A00: jal         0x8001CCCC
    // 0x800C8A04: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    composeRotationMatrixSlot1(rdram, ctx);
        goto after_1;
    // 0x800C8A04: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x800C8A08: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800C8A0C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x800C8A10: jal         0x800193E8
    // 0x800C8A14: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    transformVec3ByMat34(rdram, ctx);
        goto after_2;
    // 0x800C8A14: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_2:
    // 0x800C8A18: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x800C8A1C: jal         0x800F06BC
    // 0x800C8A20: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    isPendingChildNpcActive(rdram, ctx);
        goto after_3;
    // 0x800C8A20: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    after_3:
    // 0x800C8A24: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800C8A28: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x800C8A2C: bne         $v0, $s1, L_800C8A50
    if (ctx->r2 != ctx->r17) {
        // 0x800C8A30: nop
    
            goto L_800C8A50;
    }
    // 0x800C8A30: nop

    // 0x800C8A34: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x800C8A38: jal         0x800F09A8
    // 0x800C8A3C: nop

    computeActorAnchorDeltaAfterLOS(rdram, ctx);
        goto after_4;
    // 0x800C8A3C: nop

    after_4:
    // 0x800C8A40: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800C8A44: xor         $v0, $v0, $s1
    ctx->r2 = ctx->r2 ^ ctx->r17;
    // 0x800C8A48: sltu        $v0, $v0, $s1
    ctx->r2 = ctx->r2 < ctx->r17 ? 1 : 0;
    // 0x800C8A4C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
L_800C8A50:
    // 0x800C8A50: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800C8A54: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800C8A58: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800C8A5C: sw          $t0, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r8;
    // 0x800C8A60: sw          $t1, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r9;
    // 0x800C8A64: sw          $t2, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r10;
    // 0x800C8A68: andi        $s0, $s0, 0xFF
    ctx->r16 = ctx->r16 & 0XFF;
    // 0x800C8A6C: bne         $s0, $s1, L_800C8E4C
    if (ctx->r16 != ctx->r17) {
        // 0x800C8A70: nop
    
            goto L_800C8E4C;
    }
    // 0x800C8A70: nop

    // 0x800C8A74: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    // 0x800C8A78: jal         0x800F2988
    // 0x800C8A7C: addiu       $a1, $sp, 0x98
    ctx->r5 = ADD32(ctx->r29, 0X98);
    getObjectMeshTransformOrLocal(rdram, ctx);
        goto after_5;
    // 0x800C8A7C: addiu       $a1, $sp, 0x98
    ctx->r5 = ADD32(ctx->r29, 0X98);
    after_5:
    // 0x800C8A80: lh          $v1, 0x70($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X70);
    // 0x800C8A84: beq         $v1, $s0, L_800C8A98
    if (ctx->r3 == ctx->r16) {
        // 0x800C8A88: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_800C8A98;
    }
    // 0x800C8A88: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800C8A8C: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    // 0x800C8A90: j           L_800C8AA0
    // 0x800C8A94: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
        goto L_800C8AA0;
    // 0x800C8A94: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
L_800C8A98:
    // 0x800C8A98: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800C8A9C: lui         $a2, 0x40A0
    ctx->r6 = S32(0X40A0 << 16);
L_800C8AA0:
    // 0x800C8AA0: jal         0x800F2AC4
    // 0x800C8AA4: addiu       $a3, $sp, 0x88
    ctx->r7 = ADD32(ctx->r29, 0X88);
    func_800F2AC4(rdram, ctx);
        goto after_6;
    // 0x800C8AA4: addiu       $a3, $sp, 0x88
    ctx->r7 = ADD32(ctx->r29, 0X88);
    after_6:
    // 0x800C8AA8: addiu       $s4, $sp, 0xC8
    ctx->r20 = ADD32(ctx->r29, 0XC8);
    // 0x800C8AAC: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800C8AB0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x800C8AB4: jal         0x80059B50
    // 0x800C8AB8: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    mat34CrossRowsAndCopyPos(rdram, ctx);
        goto after_7;
    // 0x800C8AB8: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    after_7:
    // 0x800C8ABC: addiu       $s0, $sp, 0xF8
    ctx->r16 = ADD32(ctx->r29, 0XF8);
    // 0x800C8AC0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800C8AC4: jal         0x8001C774
    // 0x800C8AC8: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    mat3x3InverseInto(rdram, ctx);
        goto after_8;
    // 0x800C8AC8: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    after_8:
    // 0x800C8ACC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800C8AD0: addiu       $a1, $sp, 0x88
    ctx->r5 = ADD32(ctx->r29, 0X88);
    // 0x800C8AD4: addiu       $s3, $sp, 0x78
    ctx->r19 = ADD32(ctx->r29, 0X78);
    // 0x800C8AD8: jal         0x800193E8
    // 0x800C8ADC: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    transformVec3ByMat34(rdram, ctx);
        goto after_9;
    // 0x800C8ADC: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_9:
    // 0x800C8AE0: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x800C8AE4: addiu       $v1, $v1, -0x5A48
    ctx->r3 = ADD32(ctx->r3, -0X5A48);
    // 0x800C8AE8: lh          $v0, 0x70($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X70);
    // 0x800C8AEC: lwc1        $f0, 0x54($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X54);
    // 0x800C8AF0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C8AF4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C8AF8: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800C8AFC: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800C8B00: lwc1        $f0, 0x7C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800C8B04: addiu       $s5, $sp, 0x68
    ctx->r21 = ADD32(ctx->r29, 0X68);
    // 0x800C8B08: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800C8B0C: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x800C8B10: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x800C8B14: jal         0x8001CFA0
    // 0x800C8B18: swc1        $f0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f0.u32l;
    vec3NormalizeInto(rdram, ctx);
        goto after_10;
    // 0x800C8B18: swc1        $f0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f0.u32l;
    after_10:
    // 0x800C8B1C: lwc1        $f0, 0x60($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X60);
    // 0x800C8B20: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C8B24: lwc1        $f26, 0x69F0($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X69F0);
    // 0x800C8B28: add.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f26.fl;
    // 0x800C8B2C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800C8B30: jal         0x8001CC3C
    // 0x800C8B34: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    buildRotationMatrixSlot0(rdram, ctx);
        goto after_11;
    // 0x800C8B34: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    after_11:
    // 0x800C8B38: lw          $a1, 0x5C($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X5C);
    // 0x800C8B3C: jal         0x8001CCCC
    // 0x800C8B40: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    composeRotationMatrixSlot1(rdram, ctx);
        goto after_12;
    // 0x800C8B40: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    after_12:
    // 0x800C8B44: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800C8B48: lui         $fp, 0x8011
    ctx->r30 = S32(0X8011 << 16);
    // 0x800C8B4C: addiu       $s6, $fp, -0x5A60
    ctx->r22 = ADD32(ctx->r30, -0X5A60);
    // 0x800C8B50: addu        $a1, $s6, $zero
    ctx->r5 = ADD32(ctx->r22, 0);
    // 0x800C8B54: jal         0x800193E8
    // 0x800C8B58: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    transformVec3ByMat34(rdram, ctx);
        goto after_13;
    // 0x800C8B58: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    after_13:
    // 0x800C8B5C: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x800C8B60: jal         0x8001CFE8
    // 0x800C8B64: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    vec3Dot(rdram, ctx);
        goto after_14;
    // 0x800C8B64: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_14:
    // 0x800C8B68: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C8B6C: lwc1        $f28, 0x69F4($at)
    ctx->f28.u32l = MEM_W(ctx->r1, 0X69F4);
    // 0x800C8B70: jal         0x8001C5CC
    // 0x800C8B74: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    constMinusSinfApprox(rdram, ctx);
        goto after_15;
    // 0x800C8B74: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_15:
    // 0x800C8B78: mul.s       $f20, $f0, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x800C8B7C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C8B80: lwc1        $f0, 0x69F8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X69F8);
    // 0x800C8B84: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800C8B88: nop

    // 0x800C8B8C: bc1f        L_800C8E30
    if (!c1cs) {
        // 0x800C8B90: nop
    
            goto L_800C8E30;
    }
    // 0x800C8B90: nop

    // 0x800C8B94: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C8B98: lwc1        $f0, 0x69FC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X69FC);
    // 0x800C8B9C: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x800C8BA0: nop

    // 0x800C8BA4: bc1f        L_800C8BB0
    if (!c1cs) {
        // 0x800C8BA8: addu        $s7, $zero, $zero
        ctx->r23 = ADD32(0, 0);
            goto L_800C8BB0;
    }
    // 0x800C8BA8: addu        $s7, $zero, $zero
    ctx->r23 = ADD32(0, 0);
    // 0x800C8BAC: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
L_800C8BB0:
    // 0x800C8BB0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C8BB4: lwc1        $f0, 0x6A00($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6A00);
    // 0x800C8BB8: mul.s       $f0, $f22, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x800C8BBC: lwc1        $f2, 0x78($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X78);
    // 0x800C8BC0: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800C8BC4: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x800C8BC8: nop

    // 0x800C8BCC: bc1tl       L_800C8BD4
    if (c1cs) {
        // 0x800C8BD0: mov.s       $f20, $f2
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
            goto L_800C8BD4;
    }
    goto skip_0;
    // 0x800C8BD0: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
    skip_0:
L_800C8BD4:
    // 0x800C8BD4: addiu       $s1, $sp, 0x128
    ctx->r17 = ADD32(ctx->r29, 0X128);
    // 0x800C8BD8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800C8BDC: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x800C8BE0: jal         0x80019548
    // 0x800C8BE4: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    vec3Cross(rdram, ctx);
        goto after_16;
    // 0x800C8BE4: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    after_16:
    // 0x800C8BE8: jal         0x8001CF58
    // 0x800C8BEC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    normalize_vector(rdram, ctx);
        goto after_17;
    // 0x800C8BEC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_17:
    // 0x800C8BF0: addiu       $s0, $sp, 0x138
    ctx->r16 = ADD32(ctx->r29, 0X138);
    // 0x800C8BF4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800C8BF8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800C8BFC: jal         0x8001D240
    // 0x800C8C00: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    quatFromAxisAngle(rdram, ctx);
        goto after_18;
    // 0x800C8C00: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    after_18:
    // 0x800C8C04: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800C8C08: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x800C8C0C: jal         0x8001D3C4
    // 0x800C8C10: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    rotateVec3ByQuat(rdram, ctx);
        goto after_19;
    // 0x800C8C10: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    after_19:
    // 0x800C8C14: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // 0x800C8C18: lwc1        $f0, 0x68($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800C8C1C: lwc1        $f2, 0x70($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800C8C20: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800C8C24: sw          $zero, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = 0;
    // 0x800C8C28: swc1        $f0, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->f0.u32l;
    // 0x800C8C2C: jal         0x8001CFE8
    // 0x800C8C30: swc1        $f2, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->f2.u32l;
    vec3Dot(rdram, ctx);
        goto after_20;
    // 0x800C8C30: swc1        $f2, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->f2.u32l;
    after_20:
    // 0x800C8C34: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // 0x800C8C38: jal         0x8001CF2C
    // 0x800C8C3C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    vec3Length(rdram, ctx);
        goto after_21;
    // 0x800C8C3C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_21:
    // 0x800C8C40: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800C8C44: jal         0x8001CF2C
    // 0x800C8C48: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    vec3Length(rdram, ctx);
        goto after_22;
    // 0x800C8C48: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_22:
    // 0x800C8C4C: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800C8C50: jal         0x8001C5CC
    // 0x800C8C54: div.s       $f12, $f22, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = DIV_S(ctx->f22.fl, ctx->f20.fl);
    constMinusSinfApprox(rdram, ctx);
        goto after_23;
    // 0x800C8C54: div.s       $f12, $f22, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = DIV_S(ctx->f22.fl, ctx->f20.fl);
    after_23:
    // 0x800C8C58: addiu       $a0, $sp, 0x148
    ctx->r4 = ADD32(ctx->r29, 0X148);
    // 0x800C8C5C: addiu       $a1, $sp, 0x158
    ctx->r5 = ADD32(ctx->r29, 0X158);
    // 0x800C8C60: addiu       $a2, $sp, 0x168
    ctx->r6 = ADD32(ctx->r29, 0X168);
    // 0x800C8C64: mul.s       $f20, $f0, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x800C8C68: addiu       $t3, $fp, -0x5A60
    ctx->r11 = ADD32(ctx->r30, -0X5A60);
    // 0x800C8C6C: lw          $t0, 0x0($t3)
    ctx->r8 = MEM_W(ctx->r11, 0X0);
    // 0x800C8C70: lw          $t1, 0x4($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X4);
    // 0x800C8C74: lw          $t2, 0x8($t3)
    ctx->r10 = MEM_W(ctx->r11, 0X8);
    // 0x800C8C78: sw          $t0, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r8;
    // 0x800C8C7C: sw          $t1, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r9;
    // 0x800C8C80: sw          $t2, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r10;
    // 0x800C8C84: sw          $zero, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = 0;
    // 0x800C8C88: lw          $t0, 0x128($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X128);
    // 0x800C8C8C: lw          $t1, 0x12C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X12C);
    // 0x800C8C90: lw          $t2, 0x130($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X130);
    // 0x800C8C94: sw          $t0, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->r8;
    // 0x800C8C98: sw          $t1, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r9;
    // 0x800C8C9C: sw          $t2, 0x170($sp)
    MEM_W(0X170, ctx->r29) = ctx->r10;
    // 0x800C8CA0: jal         0x80019548
    // 0x800C8CA4: sw          $zero, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = 0;
    vec3Cross(rdram, ctx);
        goto after_24;
    // 0x800C8CA4: sw          $zero, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = 0;
    after_24:
    // 0x800C8CA8: lwc1        $f0, 0x14C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14C);
    // 0x800C8CAC: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x800C8CB0: c.le.s      $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f24.fl <= ctx->f0.fl;
    // 0x800C8CB4: nop

    // 0x800C8CB8: bc1fl       L_800C8CC0
    if (!c1cs) {
        // 0x800C8CBC: neg.s       $f20, $f20
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
            goto L_800C8CC0;
    }
    goto skip_1;
    // 0x800C8CBC: neg.s       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = -ctx->f20.fl;
    skip_1:
L_800C8CC0:
    // 0x800C8CC0: neg.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = -ctx->f20.fl;
    // 0x800C8CC4: add.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f26.fl;
    // 0x800C8CC8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800C8CCC: jal         0x8001CD6C
    // 0x800C8CD0: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    buildRotationMatrixSlot1(rdram, ctx);
        goto after_25;
    // 0x800C8CD0: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    after_25:
    // 0x800C8CD4: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800C8CD8: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x800C8CDC: jal         0x800193E8
    // 0x800C8CE0: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    transformVec3ByMat34(rdram, ctx);
        goto after_26;
    // 0x800C8CE0: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_26:
    // 0x800C8CE4: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // 0x800C8CE8: add.s       $f0, $f20, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = ctx->f20.fl + ctx->f26.fl;
    // 0x800C8CEC: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800C8CF0: swc1        $f24, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->f24.u32l;
    // 0x800C8CF4: jal         0x8001CFE8
    // 0x800C8CF8: swc1        $f0, 0x5C($s2)
    MEM_W(0X5C, ctx->r18) = ctx->f0.u32l;
    vec3Dot(rdram, ctx);
        goto after_27;
    // 0x800C8CF8: swc1        $f0, 0x5C($s2)
    MEM_W(0X5C, ctx->r18) = ctx->f0.u32l;
    after_27:
    // 0x800C8CFC: addu        $a0, $s6, $zero
    ctx->r4 = ADD32(ctx->r22, 0);
    // 0x800C8D00: jal         0x8001CF2C
    // 0x800C8D04: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    vec3Length(rdram, ctx);
        goto after_28;
    // 0x800C8D04: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    after_28:
    // 0x800C8D08: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800C8D0C: jal         0x8001CF2C
    // 0x800C8D10: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    vec3Length(rdram, ctx);
        goto after_29;
    // 0x800C8D10: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    after_29:
    // 0x800C8D14: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800C8D18: jal         0x8001C5CC
    // 0x800C8D1C: div.s       $f12, $f22, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = DIV_S(ctx->f22.fl, ctx->f20.fl);
    constMinusSinfApprox(rdram, ctx);
        goto after_30;
    // 0x800C8D1C: div.s       $f12, $f22, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = DIV_S(ctx->f22.fl, ctx->f20.fl);
    after_30:
    // 0x800C8D20: mul.s       $f2, $f0, $f28
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x800C8D24: lwc1        $f0, 0x12C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x800C8D28: c.le.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl <= ctx->f24.fl;
    // 0x800C8D2C: nop

    // 0x800C8D30: bc1fl       L_800C8D38
    if (!c1cs) {
        // 0x800C8D34: neg.s       $f2, $f2
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
            goto L_800C8D38;
    }
    goto skip_2;
    // 0x800C8D34: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    skip_2:
L_800C8D38:
    // 0x800C8D38: add.s       $f0, $f2, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f26.fl;
    // 0x800C8D3C: c.lt.s      $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f26.fl < ctx->f0.fl;
    // 0x800C8D40: nop

    // 0x800C8D44: bc1f        L_800C8D88
    if (!c1cs) {
        // 0x800C8D48: swc1        $f0, 0x60($s2)
        MEM_W(0X60, ctx->r18) = ctx->f0.u32l;
            goto L_800C8D88;
    }
    // 0x800C8D48: swc1        $f0, 0x60($s2)
    MEM_W(0X60, ctx->r18) = ctx->f0.u32l;
    // 0x800C8D4C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800C8D50: addiu       $v0, $v0, -0x5A34
    ctx->r2 = ADD32(ctx->r2, -0X5A34);
    // 0x800C8D54: lh          $v1, 0x70($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X70);
    // 0x800C8D58: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C8D5C: lwc1        $f4, 0x6A04($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6A04);
    // 0x800C8D60: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800C8D64: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C8D68: sub.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800C8D6C: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800C8D70: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800C8D74: nop

    // 0x800C8D78: bc1f        L_800C8DC0
    if (!c1cs) {
        // 0x800C8D7C: andi        $v0, $s7, 0xFF
        ctx->r2 = ctx->r23 & 0XFF;
            goto L_800C8DC0;
    }
    // 0x800C8D7C: andi        $v0, $s7, 0xFF
    ctx->r2 = ctx->r23 & 0XFF;
    // 0x800C8D80: j           L_800C8DB8
    // 0x800C8D84: sub.s       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f2.fl;
        goto L_800C8DB8;
    // 0x800C8D84: sub.s       $f0, $f4, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f2.fl;
L_800C8D88:
    // 0x800C8D88: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800C8D8C: lh          $v1, 0x70($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X70);
    // 0x800C8D90: addiu       $v0, $v0, -0x5A34
    ctx->r2 = ADD32(ctx->r2, -0X5A34);
    // 0x800C8D94: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800C8D98: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C8D9C: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800C8DA0: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800C8DA4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800C8DA8: nop

    // 0x800C8DAC: bc1f        L_800C8DC0
    if (!c1cs) {
        // 0x800C8DB0: andi        $v0, $s7, 0xFF
        ctx->r2 = ctx->r23 & 0XFF;
            goto L_800C8DC0;
    }
    // 0x800C8DB0: andi        $v0, $s7, 0xFF
    ctx->r2 = ctx->r23 & 0XFF;
    // 0x800C8DB4: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
L_800C8DB8:
    // 0x800C8DB8: swc1        $f0, 0x60($s2)
    MEM_W(0X60, ctx->r18) = ctx->f0.u32l;
    // 0x800C8DBC: andi        $v0, $s7, 0xFF
    ctx->r2 = ctx->r23 & 0XFF;
L_800C8DC0:
    // 0x800C8DC0: beq         $v0, $zero, L_800C8E30
    if (ctx->r2 == 0) {
        // 0x800C8DC4: nop
    
            goto L_800C8E30;
    }
    // 0x800C8DC4: nop

    // 0x800C8DC8: lbu         $v0, 0xD2($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0XD2);
    // 0x800C8DCC: bne         $v0, $zero, L_800C8E4C
    if (ctx->r2 != 0) {
        // 0x800C8DD0: addu        $a1, $s2, $zero
        ctx->r5 = ADD32(ctx->r18, 0);
            goto L_800C8E4C;
    }
    // 0x800C8DD0: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800C8DD4: addiu       $a0, $s2, 0x8C
    ctx->r4 = ADD32(ctx->r18, 0X8C);
    // 0x800C8DD8: addiu       $a2, $a1, 0x24
    ctx->r6 = ADD32(ctx->r5, 0X24);
    // 0x800C8DDC: lui         $a3, 0x4100
    ctx->r7 = S32(0X4100 << 16);
    // 0x800C8DE0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C8DE4: lwc1        $f0, 0x6A08($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6A08);
    // 0x800C8DE8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C8DEC: sb          $v0, 0xD2($a1)
    MEM_B(0XD2, ctx->r5) = ctx->r2;
    // 0x800C8DF0: addiu       $v0, $zero, 0x2000
    ctx->r2 = ADD32(0, 0X2000);
    // 0x800C8DF4: sh          $v0, 0xD0($a1)
    MEM_H(0XD0, ctx->r5) = ctx->r2;
    // 0x800C8DF8: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x800C8DFC: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x800C8E00: addiu       $v0, $zero, 0x27
    ctx->r2 = ADD32(0, 0X27);
    // 0x800C8E04: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800C8E08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C8E0C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800C8E10: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // 0x800C8E14: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800C8E18: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // 0x800C8E1C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800C8E20: jal         0x80098BDC
    // 0x800C8E24: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    play3DSoundEventVariant(rdram, ctx);
        goto after_31;
    // 0x800C8E24: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_31:
    // 0x800C8E28: j           L_800C8E4C
    // 0x800C8E2C: nop

        goto L_800C8E4C;
    // 0x800C8E2C: nop

L_800C8E30:
    // 0x800C8E30: lbu         $v1, 0xD2($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0XD2);
    // 0x800C8E34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C8E38: bne         $v1, $v0, L_800C8E4C
    if (ctx->r3 != ctx->r2) {
        // 0x800C8E3C: nop
    
            goto L_800C8E4C;
    }
    // 0x800C8E3C: nop

    // 0x800C8E40: sb          $zero, 0xD2($s2)
    MEM_B(0XD2, ctx->r18) = 0;
    // 0x800C8E44: jal         0x80098DE0
    // 0x800C8E48: addiu       $a0, $s2, 0x8C
    ctx->r4 = ADD32(ctx->r18, 0X8C);
    factor5RemoveListNode(rdram, ctx);
        goto after_32;
    // 0x800C8E48: addiu       $a0, $s2, 0x8C
    ctx->r4 = ADD32(ctx->r18, 0X8C);
    after_32:
L_800C8E4C:
    // 0x800C8E4C: lw          $ra, 0x19C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X19C);
    // 0x800C8E50: lw          $fp, 0x198($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X198);
    // 0x800C8E54: lw          $s7, 0x194($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X194);
    // 0x800C8E58: lw          $s6, 0x190($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X190);
    // 0x800C8E5C: lw          $s5, 0x18C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X18C);
    // 0x800C8E60: lw          $s4, 0x188($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X188);
    // 0x800C8E64: lw          $s3, 0x184($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X184);
    // 0x800C8E68: lw          $s2, 0x180($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X180);
    // 0x800C8E6C: lw          $s1, 0x17C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X17C);
    // 0x800C8E70: lw          $s0, 0x178($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X178);
    // 0x800C8E74: ldc1        $f28, 0x1C0($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X1C0);
    // 0x800C8E78: ldc1        $f26, 0x1B8($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X1B8);
    // 0x800C8E7C: ldc1        $f24, 0x1B0($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X1B0);
    // 0x800C8E80: ldc1        $f22, 0x1A8($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X1A8);
    // 0x800C8E84: ldc1        $f20, 0x1A0($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X1A0);
    // 0x800C8E88: jr          $ra
    // 0x800C8E8C: addiu       $sp, $sp, 0x1C8
    ctx->r29 = ADD32(ctx->r29, 0X1C8);
    return;
    // 0x800C8E8C: addiu       $sp, $sp, 0x1C8
    ctx->r29 = ADD32(ctx->r29, 0X1C8);
;}
RECOMP_FUNC void func_800C8A64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8A64: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C8A68: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C8A6C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800C8A70: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C8A74: lhu         $v0, 0x4($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X4);
    // 0x800C8A78: andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    // 0x800C8A7C: beq         $v0, $zero, L_800C8AB0
    if (ctx->r2 == 0) {
        // 0x800C8A80: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_800C8AB0;
    }
    // 0x800C8A80: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800C8A84: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x800C8A88: addu        $v1, $s0, $zero
    ctx->r3 = ADD32(ctx->r16, 0);
L_800C8A8C:
    // 0x800C8A8C: lwc1        $f0, 0x18($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X18);
    // 0x800C8A90: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800C8A94: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800C8A98: slti        $v0, $a1, 0x4
    ctx->r2 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x800C8A9C: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x800C8AA0: bne         $v0, $zero, L_800C8A8C
    if (ctx->r2 != 0) {
        // 0x800C8AA4: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800C8A8C;
    }
    // 0x800C8AA4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800C8AA8: j           L_800C8AE0
    // 0x800C8AAC: nop

        goto L_800C8AE0;
    // 0x800C8AAC: nop

L_800C8AB0:
    // 0x800C8AB0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C8AB4: lwc1        $f0, 0x7894($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7894);
    // 0x800C8AB8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C8ABC: lwc1        $f2, 0x7898($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7898);
    // 0x800C8AC0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C8AC4: lwc1        $f4, 0x789C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X789C);
    // 0x800C8AC8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C8ACC: lwc1        $f6, 0x78A0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X78A0);
    // 0x800C8AD0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800C8AD4: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x800C8AD8: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x800C8ADC: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
L_800C8AE0:
    // 0x800C8AE0: lhu         $a1, 0xE($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0XE);
    // 0x800C8AE4: jal         0x80001ACC
    // 0x800C8AE8: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x800C8AE8: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    after_0:
    // 0x800C8AEC: lhu         $a1, 0xE($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0XE);
    // 0x800C8AF0: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    // 0x800C8AF4: jal         0x80001ACC
    // 0x800C8AF8: sw          $v0, 0x7D8($s0)
    MEM_W(0X7D8, ctx->r16) = ctx->r2;
    rs_malloc(rdram, ctx);
        goto after_1;
    // 0x800C8AF8: sw          $v0, 0x7D8($s0)
    MEM_W(0X7D8, ctx->r16) = ctx->r2;
    after_1:
    // 0x800C8AFC: lhu         $a1, 0xE($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0XE);
    // 0x800C8B00: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    // 0x800C8B04: jal         0x80001ACC
    // 0x800C8B08: sw          $v0, 0x7DC($s0)
    MEM_W(0X7DC, ctx->r16) = ctx->r2;
    rs_malloc(rdram, ctx);
        goto after_2;
    // 0x800C8B08: sw          $v0, 0x7DC($s0)
    MEM_W(0X7DC, ctx->r16) = ctx->r2;
    after_2:
    // 0x800C8B0C: lhu         $a1, 0xE($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0XE);
    // 0x800C8B10: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    // 0x800C8B14: jal         0x80001ACC
    // 0x800C8B18: sw          $v0, 0x7E0($s0)
    MEM_W(0X7E0, ctx->r16) = ctx->r2;
    rs_malloc(rdram, ctx);
        goto after_3;
    // 0x800C8B18: sw          $v0, 0x7E0($s0)
    MEM_W(0X7E0, ctx->r16) = ctx->r2;
    after_3:
    // 0x800C8B1C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800C8B20: addiu       $a2, $zero, -0x80
    ctx->r6 = ADD32(0, -0X80);
    // 0x800C8B24: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C8B28: lwc1        $f4, 0x78A4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X78A4);
    // 0x800C8B2C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C8B30: lwc1        $f2, 0x78A8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X78A8);
    // 0x800C8B34: ori         $a3, $zero, 0x8000
    ctx->r7 = 0 | 0X8000;
    // 0x800C8B38: sw          $v0, 0x7E4($s0)
    MEM_W(0X7E4, ctx->r16) = ctx->r2;
L_800C8B3C:
    // 0x800C8B3C: lwc1        $f0, 0x10($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800C8B40: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800C8B44: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800C8B48: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C8B4C: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x800C8B50: mult        $v0, $a2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C8B54: lw          $v1, 0x7D8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X7D8);
    // 0x800C8B58: sll         $a0, $a1, 2
    ctx->r4 = S32(ctx->r5 << 2);
    // 0x800C8B5C: addu        $v1, $a0, $v1
    ctx->r3 = ADD32(ctx->r4, ctx->r3);
    // 0x800C8B60: mflo        $t0
    ctx->r8 = lo;
    // 0x800C8B64: addu        $v0, $t0, $a3
    ctx->r2 = ADD32(ctx->r8, ctx->r7);
    // 0x800C8B68: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800C8B6C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800C8B70: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800C8B74: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800C8B78: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800C8B7C: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C8B80: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x800C8B84: mult        $v0, $a2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C8B88: lw          $v1, 0x7DC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X7DC);
    // 0x800C8B8C: addu        $v1, $a0, $v1
    ctx->r3 = ADD32(ctx->r4, ctx->r3);
    // 0x800C8B90: mflo        $t0
    ctx->r8 = lo;
    // 0x800C8B94: addu        $v0, $t0, $a3
    ctx->r2 = ADD32(ctx->r8, ctx->r7);
    // 0x800C8B98: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800C8B9C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800C8BA0: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800C8BA4: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800C8BA8: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800C8BAC: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C8BB0: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x800C8BB4: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x800C8BB8: mult        $v0, $a2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C8BBC: lw          $v0, 0x7E0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7E0);
    // 0x800C8BC0: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x800C8BC4: mflo        $t0
    ctx->r8 = lo;
    // 0x800C8BC8: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x800C8BCC: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800C8BD0: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800C8BD4: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800C8BD8: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800C8BDC: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x800C8BE0: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x800C8BE4: mult        $v0, $a2
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C8BE8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800C8BEC: lw          $v0, 0x7E4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7E4);
    // 0x800C8BF0: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800C8BF4: mflo        $t0
    ctx->r8 = lo;
    // 0x800C8BF8: addu        $v0, $t0, $a3
    ctx->r2 = ADD32(ctx->r8, ctx->r7);
    // 0x800C8BFC: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800C8C00: slti        $v0, $a1, 0x100
    ctx->r2 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
    // 0x800C8C04: bne         $v0, $zero, L_800C8B3C
    if (ctx->r2 != 0) {
        // 0x800C8C08: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_800C8B3C;
    }
    // 0x800C8C08: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800C8C0C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C8C10: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C8C14: jr          $ra
    // 0x800C8C18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C8C18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_800C8C1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8C1C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800C8C20: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C8C24: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800C8C28: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800C8C2C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800C8C30: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800C8C34: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800C8C38: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800C8C3C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800C8C40: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800C8C44: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800C8C48: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800C8C4C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x800C8C50: lw          $v1, 0x7E8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X7E8);
    // 0x800C8C54: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
    // 0x800C8C58: beq         $v1, $v0, L_800C9A58
    if (ctx->r3 == ctx->r2) {
        // 0x800C8C5C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800C9A58;
    }
    // 0x800C8C5C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800C8C60: lhu         $a0, 0x7EA($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X7EA);
    // 0x800C8C64: lhu         $v0, 0x42($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X42);
    // 0x800C8C68: lhu         $v1, 0x7EE($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X7EE);
    // 0x800C8C6C: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x800C8C70: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800C8C74: beq         $v0, $zero, L_800C8D60
    if (ctx->r2 == 0) {
        // 0x800C8C78: subu        $v0, $v1, $a0
        ctx->r2 = SUB32(ctx->r3, ctx->r4);
            goto L_800C8D60;
    }
    // 0x800C8C78: subu        $v0, $v1, $a0
    ctx->r2 = SUB32(ctx->r3, ctx->r4);
    // 0x800C8C7C: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x800C8C80: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800C8C84: sra         $a2, $v0, 16
    ctx->r6 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800C8C88: blezl       $a2, L_800C8D10
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800C8C8C: sh          $zero, 0x7EC($s0)
        MEM_H(0X7EC, ctx->r16) = 0;
            goto L_800C8D10;
    }
    goto skip_0;
    // 0x800C8C8C: sh          $zero, 0x7EC($s0)
    MEM_H(0X7EC, ctx->r16) = 0;
    skip_0:
    // 0x800C8C90: lbu         $v0, 0x4C($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X4C);
    // 0x800C8C94: beq         $v0, $zero, L_800C8D0C
    if (ctx->r2 == 0) {
        // 0x800C8C98: addu        $s1, $zero, $zero
        ctx->r17 = ADD32(0, 0);
            goto L_800C8D0C;
    }
    // 0x800C8C98: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x800C8C9C: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x800C8CA0: sll         $v1, $s1, 16
    ctx->r3 = S32(ctx->r17 << 16);
L_800C8CA4:
    // 0x800C8CA4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800C8CA8: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800C8CAC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C8CB0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C8CB4: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800C8CB8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C8CBC: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x800C8CC0: lhu         $v1, 0x42($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X42);
    // 0x800C8CC4: lw          $a2, 0x700($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X700);
    // 0x800C8CC8: mult        $a2, $v1
    result = S64(S32(ctx->r6)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C8CCC: mflo        $v1
    ctx->r3 = lo;
    // 0x800C8CD0: nop

    // 0x800C8CD4: nop

    // 0x800C8CD8: mult        $s2, $a2
    result = S64(S32(ctx->r18)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C8CDC: lw          $a0, 0x708($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X708);
    // 0x800C8CE0: mflo        $a2
    ctx->r6 = lo;
    // 0x800C8CE4: jal         0x80018EF4
    // 0x800C8CE8: addu        $a1, $a0, $v1
    ctx->r5 = ADD32(ctx->r4, ctx->r3);
    zmemcpy(rdram, ctx);
        goto after_0;
    // 0x800C8CE8: addu        $a1, $a0, $v1
    ctx->r5 = ADD32(ctx->r4, ctx->r3);
    after_0:
    // 0x800C8CEC: addiu       $v0, $s1, 0x1
    ctx->r2 = ADD32(ctx->r17, 0X1);
    // 0x800C8CF0: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x800C8CF4: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800C8CF8: lbu         $v1, 0x4C($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X4C);
    // 0x800C8CFC: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800C8D00: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800C8D04: bne         $v0, $zero, L_800C8CA4
    if (ctx->r2 != 0) {
        // 0x800C8D08: sll         $v1, $s1, 16
        ctx->r3 = S32(ctx->r17 << 16);
            goto L_800C8CA4;
    }
    // 0x800C8D08: sll         $v1, $s1, 16
    ctx->r3 = S32(ctx->r17 << 16);
L_800C8D0C:
    // 0x800C8D0C: sh          $s3, 0x7EC($s0)
    MEM_H(0X7EC, ctx->r16) = ctx->r19;
L_800C8D10:
    // 0x800C8D10: lhu         $v0, 0x7EA($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X7EA);
    // 0x800C8D14: lhu         $a0, 0x42($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X42);
    // 0x800C8D18: lhu         $v1, 0x7EE($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X7EE);
    // 0x800C8D1C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800C8D20: slt         $v1, $v1, $v0
    ctx->r3 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800C8D24: beq         $v1, $zero, L_800C8D64
    if (ctx->r3 == 0) {
        // 0x800C8D28: addu        $t8, $zero, $zero
        ctx->r24 = ADD32(0, 0);
            goto L_800C8D64;
    }
    // 0x800C8D28: addu        $t8, $zero, $zero
    ctx->r24 = ADD32(0, 0);
L_800C8D2C:
    // 0x800C8D2C: jal         0x800C7970
    // 0x800C8D30: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800C7970(rdram, ctx);
        goto after_1;
    // 0x800C8D30: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_1:
    // 0x800C8D34: lhu         $v0, 0x7EE($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X7EE);
    // 0x800C8D38: lhu         $v1, 0x7D4($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X7D4);
    // 0x800C8D3C: lhu         $a0, 0x42($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X42);
    // 0x800C8D40: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C8D44: lhu         $v1, 0x7EA($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X7EA);
    // 0x800C8D48: sh          $v0, 0x7EE($s0)
    MEM_H(0X7EE, ctx->r16) = ctx->r2;
    // 0x800C8D4C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800C8D50: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800C8D54: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800C8D58: bne         $v0, $zero, L_800C8D2C
    if (ctx->r2 != 0) {
        // 0x800C8D5C: nop
    
            goto L_800C8D2C;
    }
    // 0x800C8D5C: nop

L_800C8D60:
    // 0x800C8D60: addu        $t8, $zero, $zero
    ctx->r24 = ADD32(0, 0);
L_800C8D64:
    // 0x800C8D64: addu        $t9, $t8, $zero
    ctx->r25 = ADD32(ctx->r24, 0);
    // 0x800C8D68: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x800C8D6C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800C8D70: bne         $v1, $v0, L_800C8DB8
    if (ctx->r3 != ctx->r2) {
        // 0x800C8D74: addu        $s2, $t8, $zero
        ctx->r18 = ADD32(ctx->r24, 0);
            goto L_800C8DB8;
    }
    // 0x800C8D74: addu        $s2, $t8, $zero
    ctx->r18 = ADD32(ctx->r24, 0);
    // 0x800C8D78: lhu         $v1, 0x4($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X4);
    // 0x800C8D7C: lw          $s2, 0x54($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X54);
    // 0x800C8D80: andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // 0x800C8D84: beq         $v0, $zero, L_800C8D94
    if (ctx->r2 == 0) {
        // 0x800C8D88: nop
    
            goto L_800C8D94;
    }
    // 0x800C8D88: nop

    // 0x800C8D8C: lh          $v0, 0x10($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X10);
    // 0x800C8D90: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
L_800C8D94:
    // 0x800C8D94: lw          $t9, 0x54($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X54);
    // 0x800C8D98: andi        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 & 0X2;
    // 0x800C8D9C: beq         $v0, $zero, L_800C8DAC
    if (ctx->r2 == 0) {
        // 0x800C8DA0: nop
    
            goto L_800C8DAC;
    }
    // 0x800C8DA0: nop

    // 0x800C8DA4: lh          $v0, 0x12($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X12);
    // 0x800C8DA8: addu        $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
L_800C8DAC:
    // 0x800C8DAC: lw          $t8, 0x54($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X54);
    // 0x800C8DB0: j           L_800C8E00
    // 0x800C8DB4: andi        $v0, $v1, 0x4
    ctx->r2 = ctx->r3 & 0X4;
        goto L_800C8E00;
    // 0x800C8DB4: andi        $v0, $v1, 0x4
    ctx->r2 = ctx->r3 & 0X4;
L_800C8DB8:
    // 0x800C8DB8: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800C8DBC: bne         $v1, $v0, L_800C8E10
    if (ctx->r3 != ctx->r2) {
        // 0x800C8DC0: nop
    
            goto L_800C8E10;
    }
    // 0x800C8DC0: nop

    // 0x800C8DC4: lhu         $v1, 0x4($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X4);
    // 0x800C8DC8: lw          $s2, 0x50($s0)
    ctx->r18 = MEM_W(ctx->r16, 0X50);
    // 0x800C8DCC: andi        $v0, $v1, 0x1
    ctx->r2 = ctx->r3 & 0X1;
    // 0x800C8DD0: beq         $v0, $zero, L_800C8DE0
    if (ctx->r2 == 0) {
        // 0x800C8DD4: nop
    
            goto L_800C8DE0;
    }
    // 0x800C8DD4: nop

    // 0x800C8DD8: lh          $v0, 0x10($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X10);
    // 0x800C8DDC: addu        $s2, $s2, $v0
    ctx->r18 = ADD32(ctx->r18, ctx->r2);
L_800C8DE0:
    // 0x800C8DE0: lw          $t9, 0x50($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X50);
    // 0x800C8DE4: andi        $v0, $v1, 0x2
    ctx->r2 = ctx->r3 & 0X2;
    // 0x800C8DE8: beq         $v0, $zero, L_800C8DF8
    if (ctx->r2 == 0) {
        // 0x800C8DEC: nop
    
            goto L_800C8DF8;
    }
    // 0x800C8DEC: nop

    // 0x800C8DF0: lh          $v0, 0x12($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X12);
    // 0x800C8DF4: addu        $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
L_800C8DF8:
    // 0x800C8DF8: lw          $t8, 0x50($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X50);
    // 0x800C8DFC: andi        $v0, $v1, 0x4
    ctx->r2 = ctx->r3 & 0X4;
L_800C8E00:
    // 0x800C8E00: beq         $v0, $zero, L_800C8E10
    if (ctx->r2 == 0) {
        // 0x800C8E04: nop
    
            goto L_800C8E10;
    }
    // 0x800C8E04: nop

    // 0x800C8E08: lh          $v0, 0x14($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X14);
    // 0x800C8E0C: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
L_800C8E10:
    // 0x800C8E10: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x800C8E14: lw          $s5, 0x700($s0)
    ctx->r21 = MEM_W(ctx->r16, 0X700);
    // 0x800C8E18: addiu       $v0, $a2, -0x4
    ctx->r2 = ADD32(ctx->r6, -0X4);
    // 0x800C8E1C: sltiu       $v0, $v0, 0x2
    ctx->r2 = ctx->r2 < 0X2 ? 1 : 0;
    // 0x800C8E20: beq         $v0, $zero, L_800C8F84
    if (ctx->r2 == 0) {
        // 0x800C8E24: addu        $t7, $zero, $zero
        ctx->r15 = ADD32(0, 0);
            goto L_800C8F84;
    }
    // 0x800C8E24: addu        $t7, $zero, $zero
    ctx->r15 = ADD32(0, 0);
    // 0x800C8E28: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800C8E2C: bne         $a2, $v0, L_800C8EF0
    if (ctx->r6 != ctx->r2) {
        // 0x800C8E30: nop
    
            goto L_800C8EF0;
    }
    // 0x800C8E30: nop

    // 0x800C8E34: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x800C8E38: sltu        $v0, $t7, $v0
    ctx->r2 = ctx->r15 < ctx->r2 ? 1 : 0;
    // 0x800C8E3C: beq         $v0, $zero, L_800C9A20
    if (ctx->r2 == 0) {
        // 0x800C8E40: addu        $t6, $t7, $zero
        ctx->r14 = ADD32(ctx->r15, 0);
            goto L_800C9A20;
    }
    // 0x800C8E40: addu        $t6, $t7, $zero
    ctx->r14 = ADD32(ctx->r15, 0);
L_800C8E44:
    // 0x800C8E44: lhu         $t3, 0x7E8($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X7E8);
    // 0x800C8E48: lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X0);
    // 0x800C8E4C: andi        $v0, $t3, 0xFFFF
    ctx->r2 = ctx->r11 & 0XFFFF;
    // 0x800C8E50: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800C8E54: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C8E58: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800C8E5C: beq         $v0, $zero, L_800C8ED0
    if (ctx->r2 == 0) {
        // 0x800C8E60: andi        $v0, $t6, 0xFFFF
        ctx->r2 = ctx->r14 & 0XFFFF;
            goto L_800C8ED0;
    }
    // 0x800C8E60: andi        $v0, $t6, 0xFFFF
    ctx->r2 = ctx->r14 & 0XFFFF;
    // 0x800C8E64: lw          $s6, 0x4C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X4C);
    // 0x800C8E68: addu        $a1, $t7, $s6
    ctx->r5 = ADD32(ctx->r15, ctx->r22);
    // 0x800C8E6C: mult        $v0, $s5
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C8E70: mflo        $a2
    ctx->r6 = lo;
L_800C8E74:
    // 0x800C8E74: lw          $v0, 0x708($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X708);
    // 0x800C8E78: addu        $v1, $a0, $a2
    ctx->r3 = ADD32(ctx->r4, ctx->r6);
    // 0x800C8E7C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C8E80: lbu         $t4, 0x0($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X0);
    // 0x800C8E84: andi        $v0, $t3, 0x1
    ctx->r2 = ctx->r11 & 0X1;
    // 0x800C8E88: beq         $v0, $zero, L_800C8EA8
    if (ctx->r2 == 0) {
        // 0x800C8E8C: andi        $v1, $t4, 0xF0
        ctx->r3 = ctx->r12 & 0XF0;
            goto L_800C8EA8;
    }
    // 0x800C8E8C: andi        $v1, $t4, 0xF0
    ctx->r3 = ctx->r12 & 0XF0;
    // 0x800C8E90: addiu       $t7, $t7, 0x1
    ctx->r15 = ADD32(ctx->r15, 0X1);
    // 0x800C8E94: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x800C8E98: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800C8E9C: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
    // 0x800C8EA0: j           L_800C8EB0
    // 0x800C8EA4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_800C8EB0;
    // 0x800C8EA4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_800C8EA8:
    // 0x800C8EA8: srl         $v0, $t4, 4
    ctx->r2 = S32(U32(ctx->r12) >> 4);
    // 0x800C8EAC: sb          $v0, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r2;
L_800C8EB0:
    // 0x800C8EB0: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800C8EB4: lhu         $v0, 0x7E8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X7E8);
    // 0x800C8EB8: lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X0);
    // 0x800C8EBC: andi        $a0, $t3, 0xFFFF
    ctx->r4 = ctx->r11 & 0XFFFF;
    // 0x800C8EC0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C8EC4: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800C8EC8: bne         $v0, $zero, L_800C8E74
    if (ctx->r2 != 0) {
        // 0x800C8ECC: nop
    
            goto L_800C8E74;
    }
    // 0x800C8ECC: nop

L_800C8ED0:
    // 0x800C8ED0: addiu       $t6, $t6, 0x1
    ctx->r14 = ADD32(ctx->r14, 0X1);
    // 0x800C8ED4: lhu         $v1, 0x2($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X2);
    // 0x800C8ED8: andi        $v0, $t6, 0xFFFF
    ctx->r2 = ctx->r14 & 0XFFFF;
    // 0x800C8EDC: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800C8EE0: beq         $v0, $zero, L_800C9A20
    if (ctx->r2 == 0) {
        // 0x800C8EE4: nop
    
            goto L_800C9A20;
    }
    // 0x800C8EE4: nop

    // 0x800C8EE8: j           L_800C8E44
    // 0x800C8EEC: nop

        goto L_800C8E44;
    // 0x800C8EEC: nop

L_800C8EF0:
    // 0x800C8EF0: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x800C8EF4: sltu        $v0, $t7, $v0
    ctx->r2 = ctx->r15 < ctx->r2 ? 1 : 0;
    // 0x800C8EF8: beq         $v0, $zero, L_800C9A20
    if (ctx->r2 == 0) {
        // 0x800C8EFC: addu        $t6, $zero, $zero
        ctx->r14 = ADD32(0, 0);
            goto L_800C9A20;
    }
    // 0x800C8EFC: addu        $t6, $zero, $zero
    ctx->r14 = ADD32(0, 0);
L_800C8F00:
    // 0x800C8F00: lhu         $t3, 0x7E8($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X7E8);
    // 0x800C8F04: lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X0);
    // 0x800C8F08: andi        $v0, $t3, 0xFFFF
    ctx->r2 = ctx->r11 & 0XFFFF;
    // 0x800C8F0C: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800C8F10: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C8F14: slt         $v0, $a1, $v0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800C8F18: beq         $v0, $zero, L_800C8F64
    if (ctx->r2 == 0) {
        // 0x800C8F1C: andi        $v0, $t6, 0xFFFF
        ctx->r2 = ctx->r14 & 0XFFFF;
            goto L_800C8F64;
    }
    // 0x800C8F1C: andi        $v0, $t6, 0xFFFF
    ctx->r2 = ctx->r14 & 0XFFFF;
    // 0x800C8F20: mult        $v0, $s5
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C8F24: mflo        $a2
    ctx->r6 = lo;
L_800C8F28:
    // 0x800C8F28: addu        $v1, $a1, $a2
    ctx->r3 = ADD32(ctx->r5, ctx->r6);
    // 0x800C8F2C: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800C8F30: andi        $a1, $t3, 0xFFFF
    ctx->r5 = ctx->r11 & 0XFFFF;
    // 0x800C8F34: lw          $v0, 0x708($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X708);
    // 0x800C8F38: lw          $s6, 0x4C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X4C);
    // 0x800C8F3C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C8F40: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800C8F44: addu        $a0, $s6, $t7
    ctx->r4 = ADD32(ctx->r22, ctx->r15);
    // 0x800C8F48: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x800C8F4C: lhu         $v0, 0x7E8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X7E8);
    // 0x800C8F50: lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X0);
    // 0x800C8F54: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C8F58: slt         $v0, $a1, $v0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800C8F5C: bne         $v0, $zero, L_800C8F28
    if (ctx->r2 != 0) {
        // 0x800C8F60: addiu       $t7, $t7, 0x1
        ctx->r15 = ADD32(ctx->r15, 0X1);
            goto L_800C8F28;
    }
    // 0x800C8F60: addiu       $t7, $t7, 0x1
    ctx->r15 = ADD32(ctx->r15, 0X1);
L_800C8F64:
    // 0x800C8F64: addiu       $t6, $t6, 0x1
    ctx->r14 = ADD32(ctx->r14, 0X1);
    // 0x800C8F68: lhu         $v1, 0x2($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X2);
    // 0x800C8F6C: andi        $v0, $t6, 0xFFFF
    ctx->r2 = ctx->r14 & 0XFFFF;
    // 0x800C8F70: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800C8F74: beq         $v0, $zero, L_800C9A20
    if (ctx->r2 == 0) {
        // 0x800C8F78: nop
    
            goto L_800C9A20;
    }
    // 0x800C8F78: nop

    // 0x800C8F7C: j           L_800C8F00
    // 0x800C8F80: nop

        goto L_800C8F00;
    // 0x800C8F80: nop

L_800C8F84:
    // 0x800C8F84: lbu         $a1, 0x4A($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X4A);
    // 0x800C8F88: lbu         $v1, 0x725($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X725);
    // 0x800C8F8C: lbu         $a0, 0x4B($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X4B);
    // 0x800C8F90: lbu         $v0, 0x726($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X726);
    // 0x800C8F94: lw          $s3, 0x72C($s0)
    ctx->r19 = MEM_W(ctx->r16, 0X72C);
    // 0x800C8F98: subu        $s1, $a0, $v0
    ctx->r17 = SUB32(ctx->r4, ctx->r2);
    // 0x800C8F9C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800C8FA0: bne         $a2, $v0, L_800C97C4
    if (ctx->r6 != ctx->r2) {
        // 0x800C8FA4: subu        $s7, $a1, $v1
        ctx->r23 = SUB32(ctx->r5, ctx->r3);
            goto L_800C97C4;
    }
    // 0x800C8FA4: subu        $s7, $a1, $v1
    ctx->r23 = SUB32(ctx->r5, ctx->r3);
    // 0x800C8FA8: lhu         $v1, 0x4($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X4);
    // 0x800C8FAC: andi        $v0, $v1, 0x8
    ctx->r2 = ctx->r3 & 0X8;
    // 0x800C8FB0: beq         $v0, $zero, L_800C92D0
    if (ctx->r2 == 0) {
        // 0x800C8FB4: andi        $v0, $v1, 0x80
        ctx->r2 = ctx->r3 & 0X80;
            goto L_800C92D0;
    }
    // 0x800C8FB4: andi        $v0, $v1, 0x80
    ctx->r2 = ctx->r3 & 0X80;
    // 0x800C8FB8: beq         $v0, $zero, L_800C918C
    if (ctx->r2 == 0) {
        // 0x800C8FBC: nop
    
            goto L_800C918C;
    }
    // 0x800C8FBC: nop

    // 0x800C8FC0: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x800C8FC4: sltu        $v0, $t7, $v0
    ctx->r2 = ctx->r15 < ctx->r2 ? 1 : 0;
    // 0x800C8FC8: beq         $v0, $zero, L_800C9A20
    if (ctx->r2 == 0) {
        // 0x800C8FCC: addu        $t6, $zero, $zero
        ctx->r14 = ADD32(0, 0);
            goto L_800C9A20;
    }
    // 0x800C8FCC: addu        $t6, $zero, $zero
    ctx->r14 = ADD32(0, 0);
    // 0x800C8FD0: addu        $t5, $zero, $zero
    ctx->r13 = ADD32(0, 0);
    // 0x800C8FD4: andi        $t4, $s7, 0xFF
    ctx->r12 = ctx->r23 & 0XFF;
    // 0x800C8FD8: andi        $t2, $s1, 0xFF
    ctx->r10 = ctx->r17 & 0XFF;
L_800C8FDC:
    // 0x800C8FDC: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x800C8FE0: sltu        $v0, $t5, $v0
    ctx->r2 = ctx->r13 < ctx->r2 ? 1 : 0;
    // 0x800C8FE4: beq         $v0, $zero, L_800C916C
    if (ctx->r2 == 0) {
        // 0x800C8FE8: addu        $t3, $zero, $zero
        ctx->r11 = ADD32(0, 0);
            goto L_800C916C;
    }
    // 0x800C8FE8: addu        $t3, $zero, $zero
    ctx->r11 = ADD32(0, 0);
    // 0x800C8FEC: andi        $t1, $t6, 0xFFFF
    ctx->r9 = ctx->r14 & 0XFFFF;
    // 0x800C8FF0: lw          $s6, 0x4C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X4C);
    // 0x800C8FF4: sll         $v0, $t7, 1
    ctx->r2 = S32(ctx->r15 << 1);
    // 0x800C8FF8: addu        $t0, $v0, $s6
    ctx->r8 = ADD32(ctx->r2, ctx->r22);
L_800C8FFC:
    // 0x800C8FFC: lhu         $v0, 0x3E($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X3E);
    // 0x800C9000: mult        $t1, $v0
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C9004: mflo        $v1
    ctx->r3 = lo;
    // 0x800C9008: lhu         $a0, 0x2A($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X2A);
    // 0x800C900C: nop

    // 0x800C9010: div         $zero, $v1, $a0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r4)));
    // 0x800C9014: bne         $a0, $zero, L_800C9020
    if (ctx->r4 != 0) {
        // 0x800C9018: nop
    
            goto L_800C9020;
    }
    // 0x800C9018: nop

    // 0x800C901C: break       7
    do_break(2148306972);
L_800C9020:
    // 0x800C9020: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C9024: bne         $a0, $at, L_800C9038
    if (ctx->r4 != ctx->r1) {
        // 0x800C9028: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C9038;
    }
    // 0x800C9028: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C902C: bne         $v1, $at, L_800C9038
    if (ctx->r3 != ctx->r1) {
        // 0x800C9030: nop
    
            goto L_800C9038;
    }
    // 0x800C9030: nop

    // 0x800C9034: break       6
    do_break(2148306996);
L_800C9038:
    // 0x800C9038: mflo        $a0
    ctx->r4 = lo;
    // 0x800C903C: lhu         $v1, 0x3C($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X3C);
    // 0x800C9040: andi        $v0, $t3, 0xFFFF
    ctx->r2 = ctx->r11 & 0XFFFF;
    // 0x800C9044: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C9048: mflo        $v1
    ctx->r3 = lo;
    // 0x800C904C: lhu         $v0, 0x28($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X28);
    // 0x800C9050: nop

    // 0x800C9054: div         $zero, $v1, $v0
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r2)));
    // 0x800C9058: bne         $v0, $zero, L_800C9064
    if (ctx->r2 != 0) {
        // 0x800C905C: nop
    
            goto L_800C9064;
    }
    // 0x800C905C: nop

    // 0x800C9060: break       7
    do_break(2148307040);
L_800C9064:
    // 0x800C9064: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C9068: bne         $v0, $at, L_800C907C
    if (ctx->r2 != ctx->r1) {
        // 0x800C906C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C907C;
    }
    // 0x800C906C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C9070: bne         $v1, $at, L_800C907C
    if (ctx->r3 != ctx->r1) {
        // 0x800C9074: nop
    
            goto L_800C907C;
    }
    // 0x800C9074: nop

    // 0x800C9078: break       6
    do_break(2148307064);
L_800C907C:
    // 0x800C907C: mflo        $v0
    ctx->r2 = lo;
    // 0x800C9080: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800C9084: nop

    // 0x800C9088: mult        $a0, $s5
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C908C: addiu       $t7, $t7, 0x1
    ctx->r15 = ADD32(ctx->r15, 0X1);
    // 0x800C9090: lw          $a1, 0x708($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X708);
    // 0x800C9094: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800C9098: mflo        $a2
    ctx->r6 = lo;
    // 0x800C909C: lhu         $v1, 0x7E8($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X7E8);
    // 0x800C90A0: srav        $a0, $a0, $t2
    ctx->r4 = S32(SIGNED(ctx->r4) >> (ctx->r10 & 31));
    // 0x800C90A4: mult        $a0, $s3
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C90A8: lw          $a0, 0x734($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X734);
    // 0x800C90AC: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C90B0: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x800C90B4: addu        $v0, $v1, $a2
    ctx->r2 = ADD32(ctx->r3, ctx->r6);
    // 0x800C90B8: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800C90BC: srav        $v1, $v1, $t4
    ctx->r3 = S32(SIGNED(ctx->r3) >> (ctx->r12 & 31));
    // 0x800C90C0: lw          $v0, 0x760($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X760);
    // 0x800C90C4: lbu         $a2, 0x0($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0X0);
    // 0x800C90C8: mflo        $a3
    ctx->r7 = lo;
    // 0x800C90CC: addu        $v1, $v1, $a3
    ctx->r3 = ADD32(ctx->r3, ctx->r7);
    // 0x800C90D0: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x800C90D4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C90D8: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x800C90DC: lw          $v0, 0x7D8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7D8);
    // 0x800C90E0: lbu         $a1, 0x0($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X0);
    // 0x800C90E4: lw          $a0, 0x7E0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X7E0);
    // 0x800C90E8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800C90EC: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x800C90F0: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x800C90F4: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800C90F8: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800C90FC: lw          $v0, 0x7E4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7E4);
    // 0x800C9100: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800C9104: addu        $a3, $a2, $a3
    ctx->r7 = ADD32(ctx->r6, ctx->r7);
    // 0x800C9108: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x800C910C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800C9110: addu        $a3, $s2, $a3
    ctx->r7 = ADD32(ctx->r18, ctx->r7);
    // 0x800C9114: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C9118: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800C911C: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x800C9120: addu        $v0, $t9, $v0
    ctx->r2 = ADD32(ctx->r25, ctx->r2);
    // 0x800C9124: lw          $v1, 0x7DC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X7DC);
    // 0x800C9128: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x800C912C: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // 0x800C9130: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800C9134: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    // 0x800C9138: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x800C913C: addu        $a2, $t8, $a2
    ctx->r6 = ADD32(ctx->r24, ctx->r6);
    // 0x800C9140: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
    // 0x800C9144: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x800C9148: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x800C914C: sll         $v1, $v1, 10
    ctx->r3 = S32(ctx->r3 << 10);
    // 0x800C9150: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800C9154: sh          $v0, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r2;
    // 0x800C9158: lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X0);
    // 0x800C915C: andi        $v0, $t3, 0xFFFF
    ctx->r2 = ctx->r11 & 0XFFFF;
    // 0x800C9160: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800C9164: bne         $v0, $zero, L_800C8FFC
    if (ctx->r2 != 0) {
        // 0x800C9168: addiu       $t0, $t0, 0x2
        ctx->r8 = ADD32(ctx->r8, 0X2);
            goto L_800C8FFC;
    }
    // 0x800C9168: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
L_800C916C:
    // 0x800C916C: addiu       $t6, $t6, 0x1
    ctx->r14 = ADD32(ctx->r14, 0X1);
    // 0x800C9170: lhu         $v1, 0x2($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X2);
    // 0x800C9174: andi        $v0, $t6, 0xFFFF
    ctx->r2 = ctx->r14 & 0XFFFF;
    // 0x800C9178: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800C917C: beq         $v0, $zero, L_800C9A20
    if (ctx->r2 == 0) {
        // 0x800C9180: nop
    
            goto L_800C9A20;
    }
    // 0x800C9180: nop

    // 0x800C9184: j           L_800C8FDC
    // 0x800C9188: nop

        goto L_800C8FDC;
    // 0x800C9188: nop

L_800C918C:
    // 0x800C918C: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x800C9190: sltu        $v0, $t7, $v0
    ctx->r2 = ctx->r15 < ctx->r2 ? 1 : 0;
    // 0x800C9194: beq         $v0, $zero, L_800C9A20
    if (ctx->r2 == 0) {
        // 0x800C9198: addu        $t6, $zero, $zero
        ctx->r14 = ADD32(0, 0);
            goto L_800C9A20;
    }
    // 0x800C9198: addu        $t6, $zero, $zero
    ctx->r14 = ADD32(0, 0);
    // 0x800C919C: andi        $t5, $s7, 0xFF
    ctx->r13 = ctx->r23 & 0XFF;
    // 0x800C91A0: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
L_800C91A4:
    // 0x800C91A4: lhu         $t3, 0x7E8($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X7E8);
    // 0x800C91A8: lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X0);
    // 0x800C91AC: andi        $v0, $t3, 0xFFFF
    ctx->r2 = ctx->r11 & 0XFFFF;
    // 0x800C91B0: addu        $t0, $v0, $zero
    ctx->r8 = ADD32(ctx->r2, 0);
    // 0x800C91B4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C91B8: slt         $v0, $t0, $v0
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800C91BC: beq         $v0, $zero, L_800C92B0
    if (ctx->r2 == 0) {
        // 0x800C91C0: andi        $v1, $t6, 0xFFFF
        ctx->r3 = ctx->r14 & 0XFFFF;
            goto L_800C92B0;
    }
    // 0x800C91C0: andi        $v1, $t6, 0xFFFF
    ctx->r3 = ctx->r14 & 0XFFFF;
    // 0x800C91C4: mult        $v1, $s5
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C91C8: sll         $v0, $t7, 1
    ctx->r2 = S32(ctx->r15 << 1);
    // 0x800C91CC: lw          $s6, 0x4C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X4C);
    // 0x800C91D0: mflo        $t4
    ctx->r12 = lo;
    // 0x800C91D4: srav        $v1, $v1, $s1
    ctx->r3 = S32(SIGNED(ctx->r3) >> (ctx->r17 & 31));
    // 0x800C91D8: addu        $t1, $v0, $s6
    ctx->r9 = ADD32(ctx->r2, ctx->r22);
    // 0x800C91DC: mult        $v1, $s3
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C91E0: mflo        $t2
    ctx->r10 = lo;
L_800C91E4:
    // 0x800C91E4: addiu       $t7, $t7, 0x1
    ctx->r15 = ADD32(ctx->r15, 0X1);
    // 0x800C91E8: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800C91EC: addu        $v0, $t0, $t4
    ctx->r2 = ADD32(ctx->r8, ctx->r12);
    // 0x800C91F0: srav        $v1, $t0, $t5
    ctx->r3 = S32(SIGNED(ctx->r8) >> (ctx->r13 & 31));
    // 0x800C91F4: andi        $t0, $t3, 0xFFFF
    ctx->r8 = ctx->r11 & 0XFFFF;
    // 0x800C91F8: addu        $v1, $v1, $t2
    ctx->r3 = ADD32(ctx->r3, ctx->r10);
    // 0x800C91FC: lw          $a1, 0x708($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X708);
    // 0x800C9200: lw          $a0, 0x734($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X734);
    // 0x800C9204: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800C9208: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x800C920C: lw          $v0, 0x760($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X760);
    // 0x800C9210: lbu         $a2, 0x0($a1)
    ctx->r6 = MEM_BU(ctx->r5, 0X0);
    // 0x800C9214: lbu         $a1, 0x0($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0X0);
    // 0x800C9218: lw          $a0, 0x7E0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X7E0);
    // 0x800C921C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C9220: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x800C9224: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x800C9228: lw          $v0, 0x7D8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7D8);
    // 0x800C922C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800C9230: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x800C9234: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800C9238: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800C923C: lw          $v0, 0x7E4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7E4);
    // 0x800C9240: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x800C9244: addu        $a3, $a2, $a3
    ctx->r7 = ADD32(ctx->r6, ctx->r7);
    // 0x800C9248: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x800C924C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800C9250: addu        $a3, $s2, $a3
    ctx->r7 = ADD32(ctx->r18, ctx->r7);
    // 0x800C9254: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C9258: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800C925C: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x800C9260: addu        $v0, $t9, $v0
    ctx->r2 = ADD32(ctx->r25, ctx->r2);
    // 0x800C9264: lw          $v1, 0x7DC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X7DC);
    // 0x800C9268: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x800C926C: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // 0x800C9270: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800C9274: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    // 0x800C9278: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x800C927C: addu        $a2, $t8, $a2
    ctx->r6 = ADD32(ctx->r24, ctx->r6);
    // 0x800C9280: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
    // 0x800C9284: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x800C9288: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x800C928C: sll         $v1, $v1, 10
    ctx->r3 = S32(ctx->r3 << 10);
    // 0x800C9290: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800C9294: sh          $v0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r2;
    // 0x800C9298: lhu         $v0, 0x7E8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X7E8);
    // 0x800C929C: lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X0);
    // 0x800C92A0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C92A4: slt         $v0, $t0, $v0
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800C92A8: bne         $v0, $zero, L_800C91E4
    if (ctx->r2 != 0) {
        // 0x800C92AC: addiu       $t1, $t1, 0x2
        ctx->r9 = ADD32(ctx->r9, 0X2);
            goto L_800C91E4;
    }
    // 0x800C92AC: addiu       $t1, $t1, 0x2
    ctx->r9 = ADD32(ctx->r9, 0X2);
L_800C92B0:
    // 0x800C92B0: addiu       $t6, $t6, 0x1
    ctx->r14 = ADD32(ctx->r14, 0X1);
    // 0x800C92B4: lhu         $v1, 0x2($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X2);
    // 0x800C92B8: andi        $v0, $t6, 0xFFFF
    ctx->r2 = ctx->r14 & 0XFFFF;
    // 0x800C92BC: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800C92C0: beq         $v0, $zero, L_800C9A20
    if (ctx->r2 == 0) {
        // 0x800C92C4: nop
    
            goto L_800C9A20;
    }
    // 0x800C92C4: nop

    // 0x800C92C8: j           L_800C91A4
    // 0x800C92CC: nop

        goto L_800C91A4;
    // 0x800C92CC: nop

L_800C92D0:
    // 0x800C92D0: andi        $v0, $v1, 0x10
    ctx->r2 = ctx->r3 & 0X10;
    // 0x800C92D4: beq         $v0, $zero, L_800C97C4
    if (ctx->r2 == 0) {
        // 0x800C92D8: andi        $v0, $v1, 0x80
        ctx->r2 = ctx->r3 & 0X80;
            goto L_800C97C4;
    }
    // 0x800C92D8: andi        $v0, $v1, 0x80
    ctx->r2 = ctx->r3 & 0X80;
    // 0x800C92DC: beq         $v0, $zero, L_800C9590
    if (ctx->r2 == 0) {
        // 0x800C92E0: nop
    
            goto L_800C9590;
    }
    // 0x800C92E0: nop

    // 0x800C92E4: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x800C92E8: sltu        $v0, $t7, $v0
    ctx->r2 = ctx->r15 < ctx->r2 ? 1 : 0;
    // 0x800C92EC: beq         $v0, $zero, L_800C9A20
    if (ctx->r2 == 0) {
        // 0x800C92F0: addu        $t6, $zero, $zero
        ctx->r14 = ADD32(0, 0);
            goto L_800C9A20;
    }
    // 0x800C92F0: addu        $t6, $zero, $zero
    ctx->r14 = ADD32(0, 0);
    // 0x800C92F4: addu        $fp, $zero, $zero
    ctx->r30 = ADD32(0, 0);
    // 0x800C92F8: andi        $v1, $t6, 0xFFFF
    ctx->r3 = ctx->r14 & 0XFFFF;
L_800C92FC:
    // 0x800C92FC: beq         $v1, $zero, L_800C9320
    if (ctx->r3 == 0) {
        // 0x800C9300: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800C9320;
    }
    // 0x800C9300: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800C9304: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x800C9308: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800C930C: beq         $v1, $v0, L_800C9320
    if (ctx->r3 == ctx->r2) {
        // 0x800C9310: andi        $v0, $t6, 0x1
        ctx->r2 = ctx->r14 & 0X1;
            goto L_800C9320;
    }
    // 0x800C9310: andi        $v0, $t6, 0x1
    ctx->r2 = ctx->r14 & 0X1;
    // 0x800C9314: beq         $v0, $zero, L_800C9320
    if (ctx->r2 == 0) {
        // 0x800C9318: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_800C9320;
    }
    // 0x800C9318: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800C931C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800C9320:
    // 0x800C9320: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x800C9324: sltu        $v0, $fp, $v0
    ctx->r2 = ctx->r30 < ctx->r2 ? 1 : 0;
    // 0x800C9328: beq         $v0, $zero, L_800C9570
    if (ctx->r2 == 0) {
        // 0x800C932C: addu        $t3, $zero, $zero
        ctx->r11 = ADD32(0, 0);
            goto L_800C9570;
    }
    // 0x800C932C: addu        $t3, $zero, $zero
    ctx->r11 = ADD32(0, 0);
    // 0x800C9330: andi        $s6, $t6, 0xFFFF
    ctx->r22 = ctx->r14 & 0XFFFF;
    // 0x800C9334: sw          $s6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r22;
    // 0x800C9338: lw          $s6, 0x4C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X4C);
    // 0x800C933C: sll         $v0, $t7, 1
    ctx->r2 = S32(ctx->r15 << 1);
    // 0x800C9340: addu        $t5, $v0, $s6
    ctx->r13 = ADD32(ctx->r2, ctx->r22);
    // 0x800C9344: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x800C9348: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800C934C: mult        $v0, $s3
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C9350: mflo        $s4
    ctx->r20 = lo;
L_800C9354:
    // 0x800C9354: lhu         $v0, 0x3E($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X3E);
    // 0x800C9358: lw          $s6, 0x18($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X18);
    // 0x800C935C: mult        $s6, $v0
    result = S64(S32(ctx->r22)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C9360: mflo        $a3
    ctx->r7 = lo;
    // 0x800C9364: lhu         $v1, 0x2A($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X2A);
    // 0x800C9368: nop

    // 0x800C936C: div         $zero, $a3, $v1
    lo = S32(S64(S32(ctx->r7)) / S64(S32(ctx->r3))); hi = S32(S64(S32(ctx->r7)) % S64(S32(ctx->r3)));
    // 0x800C9370: bne         $v1, $zero, L_800C937C
    if (ctx->r3 != 0) {
        // 0x800C9374: nop
    
            goto L_800C937C;
    }
    // 0x800C9374: nop

    // 0x800C9378: break       7
    do_break(2148307832);
L_800C937C:
    // 0x800C937C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C9380: bne         $v1, $at, L_800C9394
    if (ctx->r3 != ctx->r1) {
        // 0x800C9384: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C9394;
    }
    // 0x800C9384: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C9388: bne         $a3, $at, L_800C9394
    if (ctx->r7 != ctx->r1) {
        // 0x800C938C: nop
    
            goto L_800C9394;
    }
    // 0x800C938C: nop

    // 0x800C9390: break       6
    do_break(2148307856);
L_800C9394:
    // 0x800C9394: mflo        $v1
    ctx->r3 = lo;
    // 0x800C9398: lhu         $a0, 0x3C($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X3C);
    // 0x800C939C: andi        $v0, $t3, 0xFFFF
    ctx->r2 = ctx->r11 & 0XFFFF;
    // 0x800C93A0: mult        $v0, $a0
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C93A4: mflo        $a3
    ctx->r7 = lo;
    // 0x800C93A8: lhu         $a0, 0x28($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X28);
    // 0x800C93AC: nop

    // 0x800C93B0: div         $zero, $a3, $a0
    lo = S32(S64(S32(ctx->r7)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r7)) % S64(S32(ctx->r4)));
    // 0x800C93B4: bne         $a0, $zero, L_800C93C0
    if (ctx->r4 != 0) {
        // 0x800C93B8: nop
    
            goto L_800C93C0;
    }
    // 0x800C93B8: nop

    // 0x800C93BC: break       7
    do_break(2148307900);
L_800C93C0:
    // 0x800C93C0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C93C4: bne         $a0, $at, L_800C93D8
    if (ctx->r4 != ctx->r1) {
        // 0x800C93C8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C93D8;
    }
    // 0x800C93C8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C93CC: bne         $a3, $at, L_800C93D8
    if (ctx->r7 != ctx->r1) {
        // 0x800C93D0: nop
    
            goto L_800C93D8;
    }
    // 0x800C93D0: nop

    // 0x800C93D4: break       6
    do_break(2148307924);
L_800C93D8:
    // 0x800C93D8: mflo        $a0
    ctx->r4 = lo;
    // 0x800C93DC: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x800C93E0: srav        $v0, $v1, $s1
    ctx->r2 = S32(SIGNED(ctx->r3) >> (ctx->r17 & 31));
    // 0x800C93E4: mult        $v0, $s3
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C93E8: lhu         $v0, 0x7E8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X7E8);
    // 0x800C93EC: mflo        $a2
    ctx->r6 = lo;
    // 0x800C93F0: addu        $a1, $v0, $a0
    ctx->r5 = ADD32(ctx->r2, ctx->r4);
    // 0x800C93F4: nop

    // 0x800C93F8: mult        $v1, $s5
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C93FC: andi        $a0, $a1, 0xFFFF
    ctx->r4 = ctx->r5 & 0XFFFF;
    // 0x800C9400: srav        $v0, $a0, $s7
    ctx->r2 = S32(SIGNED(ctx->r4) >> (ctx->r23 & 31));
    // 0x800C9404: addu        $t2, $v0, $a2
    ctx->r10 = ADD32(ctx->r2, ctx->r6);
    // 0x800C9408: lw          $v0, 0x708($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X708);
    // 0x800C940C: mflo        $v1
    ctx->r3 = lo;
    // 0x800C9410: addu        $v1, $a0, $v1
    ctx->r3 = ADD32(ctx->r4, ctx->r3);
    // 0x800C9414: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C9418: lbu         $t4, 0x0($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X0);
    // 0x800C941C: beq         $a0, $zero, L_800C9440
    if (ctx->r4 == 0) {
        // 0x800C9420: addu        $t1, $zero, $zero
        ctx->r9 = ADD32(0, 0);
            goto L_800C9440;
    }
    // 0x800C9420: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
    // 0x800C9424: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x800C9428: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800C942C: beq         $a0, $v0, L_800C9440
    if (ctx->r4 == ctx->r2) {
        // 0x800C9430: andi        $v0, $a1, 0x1
        ctx->r2 = ctx->r5 & 0X1;
            goto L_800C9440;
    }
    // 0x800C9430: andi        $v0, $a1, 0x1
    ctx->r2 = ctx->r5 & 0X1;
    // 0x800C9434: beq         $v0, $zero, L_800C9440
    if (ctx->r2 == 0) {
        // 0x800C9438: addiu       $t1, $zero, -0x1
        ctx->r9 = ADD32(0, -0X1);
            goto L_800C9440;
    }
    // 0x800C9438: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800C943C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_800C9440:
    // 0x800C9440: addiu       $t7, $t7, 0x1
    ctx->r15 = ADD32(ctx->r15, 0X1);
    // 0x800C9444: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800C9448: sll         $v0, $t1, 16
    ctx->r2 = S32(ctx->r9 << 16);
    // 0x800C944C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800C9450: lw          $a2, 0x734($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X734);
    // 0x800C9454: lw          $a3, 0x760($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X760);
    // 0x800C9458: addu        $v1, $a2, $t2
    ctx->r3 = ADD32(ctx->r6, ctx->r10);
    // 0x800C945C: addu        $a0, $a3, $t2
    ctx->r4 = ADD32(ctx->r7, ctx->r10);
    // 0x800C9460: addu        $t2, $t2, $v0
    ctx->r10 = ADD32(ctx->r10, ctx->r2);
    // 0x800C9464: addu        $t0, $a2, $t2
    ctx->r8 = ADD32(ctx->r6, ctx->r10);
    // 0x800C9468: addu        $t1, $a3, $t2
    ctx->r9 = ADD32(ctx->r7, ctx->r10);
    // 0x800C946C: addu        $t2, $t2, $s4
    ctx->r10 = ADD32(ctx->r10, ctx->r20);
    // 0x800C9470: addu        $a2, $a2, $t2
    ctx->r6 = ADD32(ctx->r6, ctx->r10);
    // 0x800C9474: addu        $a3, $a3, $t2
    ctx->r7 = ADD32(ctx->r7, ctx->r10);
    // 0x800C9478: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800C947C: lbu         $v1, 0x0($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0X0);
    // 0x800C9480: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    // 0x800C9484: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800C9488: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800C948C: sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5 << 1);
    // 0x800C9490: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x800C9494: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800C9498: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    // 0x800C949C: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800C94A0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C94A4: lbu         $v1, 0x0($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X0);
    // 0x800C94A8: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800C94AC: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800C94B0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C94B4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800C94B8: lbu         $v1, 0x0($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X0);
    // 0x800C94BC: andi        $a2, $t4, 0xFFFF
    ctx->r6 = ctx->r12 & 0XFFFF;
    // 0x800C94C0: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800C94C4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C94C8: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800C94CC: srl         $a1, $a1, 4
    ctx->r5 = S32(U32(ctx->r5) >> 4);
    // 0x800C94D0: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x800C94D4: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x800C94D8: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800C94DC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C94E0: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800C94E4: srl         $a0, $a0, 4
    ctx->r4 = S32(U32(ctx->r4) >> 4);
    // 0x800C94E8: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800C94EC: lw          $v0, 0x7D8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7D8);
    // 0x800C94F0: lw          $v1, 0x7E0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X7E0);
    // 0x800C94F4: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x800C94F8: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x800C94FC: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800C9500: lw          $v0, 0x7E4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7E4);
    // 0x800C9504: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800C9508: addu        $a3, $a2, $a3
    ctx->r7 = ADD32(ctx->r6, ctx->r7);
    // 0x800C950C: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x800C9510: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800C9514: addu        $a3, $s2, $a3
    ctx->r7 = ADD32(ctx->r18, ctx->r7);
    // 0x800C9518: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C951C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800C9520: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x800C9524: addu        $v0, $t9, $v0
    ctx->r2 = ADD32(ctx->r25, ctx->r2);
    // 0x800C9528: lw          $v1, 0x7DC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X7DC);
    // 0x800C952C: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x800C9530: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // 0x800C9534: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800C9538: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    // 0x800C953C: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x800C9540: addu        $a2, $t8, $a2
    ctx->r6 = ADD32(ctx->r24, ctx->r6);
    // 0x800C9544: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
    // 0x800C9548: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x800C954C: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x800C9550: sll         $v1, $v1, 10
    ctx->r3 = S32(ctx->r3 << 10);
    // 0x800C9554: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800C9558: sh          $v0, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r2;
    // 0x800C955C: lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X0);
    // 0x800C9560: andi        $v0, $t3, 0xFFFF
    ctx->r2 = ctx->r11 & 0XFFFF;
    // 0x800C9564: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800C9568: bne         $v0, $zero, L_800C9354
    if (ctx->r2 != 0) {
        // 0x800C956C: addiu       $t5, $t5, 0x2
        ctx->r13 = ADD32(ctx->r13, 0X2);
            goto L_800C9354;
    }
    // 0x800C956C: addiu       $t5, $t5, 0x2
    ctx->r13 = ADD32(ctx->r13, 0X2);
L_800C9570:
    // 0x800C9570: addiu       $t6, $t6, 0x1
    ctx->r14 = ADD32(ctx->r14, 0X1);
    // 0x800C9574: lhu         $v1, 0x2($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X2);
    // 0x800C9578: andi        $v0, $t6, 0xFFFF
    ctx->r2 = ctx->r14 & 0XFFFF;
    // 0x800C957C: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800C9580: bne         $v0, $zero, L_800C92FC
    if (ctx->r2 != 0) {
        // 0x800C9584: andi        $v1, $t6, 0xFFFF
        ctx->r3 = ctx->r14 & 0XFFFF;
            goto L_800C92FC;
    }
    // 0x800C9584: andi        $v1, $t6, 0xFFFF
    ctx->r3 = ctx->r14 & 0XFFFF;
    // 0x800C9588: j           L_800C9A20
    // 0x800C958C: nop

        goto L_800C9A20;
    // 0x800C958C: nop

L_800C9590:
    // 0x800C9590: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x800C9594: sltu        $v0, $t7, $v0
    ctx->r2 = ctx->r15 < ctx->r2 ? 1 : 0;
    // 0x800C9598: beq         $v0, $zero, L_800C9A20
    if (ctx->r2 == 0) {
        // 0x800C959C: addu        $t6, $zero, $zero
        ctx->r14 = ADD32(0, 0);
            goto L_800C9A20;
    }
    // 0x800C959C: addu        $t6, $zero, $zero
    ctx->r14 = ADD32(0, 0);
    // 0x800C95A0: andi        $s1, $s1, 0xFF
    ctx->r17 = ctx->r17 & 0XFF;
    // 0x800C95A4: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    // 0x800C95A8: andi        $v1, $t6, 0xFFFF
    ctx->r3 = ctx->r14 & 0XFFFF;
L_800C95AC:
    // 0x800C95AC: beq         $v1, $zero, L_800C95D0
    if (ctx->r3 == 0) {
        // 0x800C95B0: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800C95D0;
    }
    // 0x800C95B0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800C95B4: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x800C95B8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800C95BC: beq         $v1, $v0, L_800C95D0
    if (ctx->r3 == ctx->r2) {
        // 0x800C95C0: andi        $v0, $t6, 0x1
        ctx->r2 = ctx->r14 & 0X1;
            goto L_800C95D0;
    }
    // 0x800C95C0: andi        $v0, $t6, 0x1
    ctx->r2 = ctx->r14 & 0X1;
    // 0x800C95C4: beq         $v0, $zero, L_800C95D0
    if (ctx->r2 == 0) {
        // 0x800C95C8: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_800C95D0;
    }
    // 0x800C95C8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800C95CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800C95D0:
    // 0x800C95D0: lhu         $t3, 0x7E8($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X7E8);
    // 0x800C95D4: lhu         $a1, 0x0($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X0);
    // 0x800C95D8: andi        $v0, $t3, 0xFFFF
    ctx->r2 = ctx->r11 & 0XFFFF;
    // 0x800C95DC: addu        $t5, $v0, $zero
    ctx->r13 = ADD32(ctx->r2, 0);
    // 0x800C95E0: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800C95E4: slt         $v0, $t5, $v0
    ctx->r2 = SIGNED(ctx->r13) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800C95E8: beq         $v0, $zero, L_800C97A4
    if (ctx->r2 == 0) {
        // 0x800C95EC: andi        $v0, $t6, 0xFFFF
        ctx->r2 = ctx->r14 & 0XFFFF;
            goto L_800C97A4;
    }
    // 0x800C95EC: andi        $v0, $t6, 0xFFFF
    ctx->r2 = ctx->r14 & 0XFFFF;
    // 0x800C95F0: mult        $v0, $s5
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C95F4: lw          $s6, 0x10($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X10);
    // 0x800C95F8: mflo        $fp
    ctx->r30 = lo;
    // 0x800C95FC: srav        $v0, $v0, $s6
    ctx->r2 = S32(SIGNED(ctx->r2) >> (ctx->r22 & 31));
    // 0x800C9600: nop

    // 0x800C9604: mult        $v0, $s3
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C9608: mflo        $s6
    ctx->r22 = lo;
    // 0x800C960C: sw          $s6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r22;
    // 0x800C9610: lw          $s6, 0x4C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X4C);
    // 0x800C9614: sll         $v0, $t7, 1
    ctx->r2 = S32(ctx->r15 << 1);
    // 0x800C9618: addu        $s1, $v0, $s6
    ctx->r17 = ADD32(ctx->r2, ctx->r22);
    // 0x800C961C: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x800C9620: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800C9624: mult        $v0, $s3
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C9628: mflo        $s4
    ctx->r20 = lo;
L_800C962C:
    // 0x800C962C: lw          $s6, 0x18($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X18);
    // 0x800C9630: srav        $v0, $t5, $s7
    ctx->r2 = S32(SIGNED(ctx->r13) >> (ctx->r23 & 31));
    // 0x800C9634: addu        $t2, $v0, $s6
    ctx->r10 = ADD32(ctx->r2, ctx->r22);
    // 0x800C9638: lw          $v0, 0x708($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X708);
    // 0x800C963C: addu        $v1, $t5, $fp
    ctx->r3 = ADD32(ctx->r13, ctx->r30);
    // 0x800C9640: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C9644: lbu         $t4, 0x0($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X0);
    // 0x800C9648: beq         $t5, $zero, L_800C9668
    if (ctx->r13 == 0) {
        // 0x800C964C: addiu       $v0, $a1, -0x1
        ctx->r2 = ADD32(ctx->r5, -0X1);
            goto L_800C9668;
    }
    // 0x800C964C: addiu       $v0, $a1, -0x1
    ctx->r2 = ADD32(ctx->r5, -0X1);
    // 0x800C9650: beq         $t5, $v0, L_800C9668
    if (ctx->r13 == ctx->r2) {
        // 0x800C9654: andi        $v0, $t3, 0x1
        ctx->r2 = ctx->r11 & 0X1;
            goto L_800C9668;
    }
    // 0x800C9654: andi        $v0, $t3, 0x1
    ctx->r2 = ctx->r11 & 0X1;
    // 0x800C9658: beq         $v0, $zero, L_800C966C
    if (ctx->r2 == 0) {
        // 0x800C965C: addiu       $t1, $zero, -0x1
        ctx->r9 = ADD32(0, -0X1);
            goto L_800C966C;
    }
    // 0x800C965C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800C9660: j           L_800C966C
    // 0x800C9664: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_800C966C;
    // 0x800C9664: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_800C9668:
    // 0x800C9668: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
L_800C966C:
    // 0x800C966C: addiu       $t7, $t7, 0x1
    ctx->r15 = ADD32(ctx->r15, 0X1);
    // 0x800C9670: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800C9674: andi        $t5, $t3, 0xFFFF
    ctx->r13 = ctx->r11 & 0XFFFF;
    // 0x800C9678: sll         $v0, $t1, 16
    ctx->r2 = S32(ctx->r9 << 16);
    // 0x800C967C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800C9680: lw          $a2, 0x734($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X734);
    // 0x800C9684: lw          $a3, 0x760($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X760);
    // 0x800C9688: addu        $v1, $a2, $t2
    ctx->r3 = ADD32(ctx->r6, ctx->r10);
    // 0x800C968C: addu        $a0, $a3, $t2
    ctx->r4 = ADD32(ctx->r7, ctx->r10);
    // 0x800C9690: addu        $t2, $t2, $v0
    ctx->r10 = ADD32(ctx->r10, ctx->r2);
    // 0x800C9694: addu        $t0, $a2, $t2
    ctx->r8 = ADD32(ctx->r6, ctx->r10);
    // 0x800C9698: addu        $t1, $a3, $t2
    ctx->r9 = ADD32(ctx->r7, ctx->r10);
    // 0x800C969C: addu        $t2, $t2, $s4
    ctx->r10 = ADD32(ctx->r10, ctx->r20);
    // 0x800C96A0: addu        $a2, $a2, $t2
    ctx->r6 = ADD32(ctx->r6, ctx->r10);
    // 0x800C96A4: addu        $a3, $a3, $t2
    ctx->r7 = ADD32(ctx->r7, ctx->r10);
    // 0x800C96A8: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800C96AC: lbu         $v1, 0x0($t0)
    ctx->r3 = MEM_BU(ctx->r8, 0X0);
    // 0x800C96B0: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    // 0x800C96B4: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800C96B8: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800C96BC: sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5 << 1);
    // 0x800C96C0: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x800C96C4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800C96C8: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    // 0x800C96CC: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800C96D0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C96D4: lbu         $v1, 0x0($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X0);
    // 0x800C96D8: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800C96DC: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800C96E0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C96E4: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800C96E8: lbu         $v1, 0x0($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X0);
    // 0x800C96EC: andi        $a2, $t4, 0xFFFF
    ctx->r6 = ctx->r12 & 0XFFFF;
    // 0x800C96F0: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800C96F4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C96F8: addu        $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x800C96FC: srl         $a1, $a1, 4
    ctx->r5 = S32(U32(ctx->r5) >> 4);
    // 0x800C9700: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x800C9704: sll         $a1, $a1, 2
    ctx->r5 = S32(ctx->r5 << 2);
    // 0x800C9708: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800C970C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C9710: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800C9714: srl         $a0, $a0, 4
    ctx->r4 = S32(U32(ctx->r4) >> 4);
    // 0x800C9718: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800C971C: lw          $v0, 0x7D8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7D8);
    // 0x800C9720: lw          $v1, 0x7E0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X7E0);
    // 0x800C9724: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x800C9728: addu        $a0, $a0, $v1
    ctx->r4 = ADD32(ctx->r4, ctx->r3);
    // 0x800C972C: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800C9730: lw          $v0, 0x7E4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7E4);
    // 0x800C9734: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800C9738: addu        $a3, $a2, $a3
    ctx->r7 = ADD32(ctx->r6, ctx->r7);
    // 0x800C973C: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x800C9740: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800C9744: addu        $a3, $s2, $a3
    ctx->r7 = ADD32(ctx->r18, ctx->r7);
    // 0x800C9748: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C974C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800C9750: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x800C9754: addu        $v0, $t9, $v0
    ctx->r2 = ADD32(ctx->r25, ctx->r2);
    // 0x800C9758: lw          $v1, 0x7DC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X7DC);
    // 0x800C975C: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x800C9760: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // 0x800C9764: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800C9768: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    // 0x800C976C: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x800C9770: addu        $a2, $t8, $a2
    ctx->r6 = ADD32(ctx->r24, ctx->r6);
    // 0x800C9774: lbu         $v0, 0x0($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X0);
    // 0x800C9778: lbu         $v1, 0x0($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X0);
    // 0x800C977C: or          $v0, $v0, $a0
    ctx->r2 = ctx->r2 | ctx->r4;
    // 0x800C9780: sll         $v1, $v1, 10
    ctx->r3 = S32(ctx->r3 << 10);
    // 0x800C9784: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x800C9788: sh          $v0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r2;
    // 0x800C978C: lhu         $a1, 0x0($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X0);
    // 0x800C9790: lhu         $v0, 0x7E8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X7E8);
    // 0x800C9794: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800C9798: slt         $v0, $t5, $v0
    ctx->r2 = SIGNED(ctx->r13) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800C979C: bne         $v0, $zero, L_800C962C
    if (ctx->r2 != 0) {
        // 0x800C97A0: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_800C962C;
    }
    // 0x800C97A0: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
L_800C97A4:
    // 0x800C97A4: addiu       $t6, $t6, 0x1
    ctx->r14 = ADD32(ctx->r14, 0X1);
    // 0x800C97A8: lhu         $v1, 0x2($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X2);
    // 0x800C97AC: andi        $v0, $t6, 0xFFFF
    ctx->r2 = ctx->r14 & 0XFFFF;
    // 0x800C97B0: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800C97B4: bne         $v0, $zero, L_800C95AC
    if (ctx->r2 != 0) {
        // 0x800C97B8: andi        $v1, $t6, 0xFFFF
        ctx->r3 = ctx->r14 & 0XFFFF;
            goto L_800C95AC;
    }
    // 0x800C97B8: andi        $v1, $t6, 0xFFFF
    ctx->r3 = ctx->r14 & 0XFFFF;
    // 0x800C97BC: j           L_800C9A20
    // 0x800C97C0: nop

        goto L_800C9A20;
    // 0x800C97C0: nop

L_800C97C4:
    // 0x800C97C4: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x800C97C8: beq         $v0, $zero, L_800C9A20
    if (ctx->r2 == 0) {
        // 0x800C97CC: addu        $t6, $zero, $zero
        ctx->r14 = ADD32(0, 0);
            goto L_800C9A20;
    }
    // 0x800C97CC: addu        $t6, $zero, $zero
    ctx->r14 = ADD32(0, 0);
    // 0x800C97D0: andi        $s4, $s7, 0xFF
    ctx->r20 = ctx->r23 & 0XFF;
    // 0x800C97D4: andi        $fp, $s1, 0xFF
    ctx->r30 = ctx->r17 & 0XFF;
    // 0x800C97D8: andi        $v1, $t6, 0xFFFF
    ctx->r3 = ctx->r14 & 0XFFFF;
L_800C97DC:
    // 0x800C97DC: beq         $v1, $zero, L_800C9800
    if (ctx->r3 == 0) {
        // 0x800C97E0: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800C9800;
    }
    // 0x800C97E0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800C97E4: lhu         $v0, 0x2($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X2);
    // 0x800C97E8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800C97EC: beq         $v1, $v0, L_800C9800
    if (ctx->r3 == ctx->r2) {
        // 0x800C97F0: andi        $v0, $t6, 0x1
        ctx->r2 = ctx->r14 & 0X1;
            goto L_800C9800;
    }
    // 0x800C97F0: andi        $v0, $t6, 0x1
    ctx->r2 = ctx->r14 & 0X1;
    // 0x800C97F4: beq         $v0, $zero, L_800C9800
    if (ctx->r2 == 0) {
        // 0x800C97F8: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_800C9800;
    }
    // 0x800C97F8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800C97FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800C9800:
    // 0x800C9800: lhu         $t3, 0x7E8($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X7E8);
    // 0x800C9804: lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X0);
    // 0x800C9808: andi        $v0, $t3, 0xFFFF
    ctx->r2 = ctx->r11 & 0XFFFF;
    // 0x800C980C: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800C9810: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C9814: slt         $v0, $a1, $v0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800C9818: beq         $v0, $zero, L_800C9A08
    if (ctx->r2 == 0) {
        // 0x800C981C: andi        $v0, $t6, 0xFFFF
        ctx->r2 = ctx->r14 & 0XFFFF;
            goto L_800C9A08;
    }
    // 0x800C981C: andi        $v0, $t6, 0xFFFF
    ctx->r2 = ctx->r14 & 0XFFFF;
    // 0x800C9820: mult        $v0, $s5
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C9824: mflo        $s7
    ctx->r23 = lo;
    // 0x800C9828: srav        $v0, $v0, $fp
    ctx->r2 = S32(SIGNED(ctx->r2) >> (ctx->r30 & 31));
    // 0x800C982C: nop

    // 0x800C9830: mult        $v0, $s3
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C9834: lw          $s6, 0x4C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X4C);
    // 0x800C9838: addu        $t5, $t7, $s6
    ctx->r13 = ADD32(ctx->r15, ctx->r22);
    // 0x800C983C: mflo        $s1
    ctx->r17 = lo;
    // 0x800C9840: sll         $v0, $a0, 16
    ctx->r2 = S32(ctx->r4 << 16);
    // 0x800C9844: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800C9848: mult        $v0, $s3
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C984C: mflo        $s6
    ctx->r22 = lo;
    // 0x800C9850: sw          $s6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r22;
L_800C9854:
    // 0x800C9854: addu        $v0, $a1, $s7
    ctx->r2 = ADD32(ctx->r5, ctx->r23);
    // 0x800C9858: lw          $v1, 0x708($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X708);
    // 0x800C985C: lhu         $a0, 0x4($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X4);
    // 0x800C9860: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C9864: andi        $a0, $a0, 0x18
    ctx->r4 = ctx->r4 & 0X18;
    // 0x800C9868: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800C986C: lbu         $t4, 0x0($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X0);
    // 0x800C9870: bne         $a0, $v0, L_800C98A0
    if (ctx->r4 != ctx->r2) {
        // 0x800C9874: srav        $v0, $a1, $s4
        ctx->r2 = S32(SIGNED(ctx->r5) >> (ctx->r20 & 31));
            goto L_800C98A0;
    }
    // 0x800C9874: srav        $v0, $a1, $s4
    ctx->r2 = S32(SIGNED(ctx->r5) >> (ctx->r20 & 31));
    // 0x800C9878: srav        $a0, $a1, $s4
    ctx->r4 = S32(SIGNED(ctx->r5) >> (ctx->r20 & 31));
    // 0x800C987C: addu        $a0, $a0, $s1
    ctx->r4 = ADD32(ctx->r4, ctx->r17);
    // 0x800C9880: lw          $v1, 0x734($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X734);
    // 0x800C9884: lw          $v0, 0x760($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X760);
    // 0x800C9888: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800C988C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x800C9890: lbu         $t0, 0x0($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X0);
    // 0x800C9894: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x800C9898: j           L_800C9968
    // 0x800C989C: nop

        goto L_800C9968;
    // 0x800C989C: nop

L_800C98A0:
    // 0x800C98A0: beq         $a1, $zero, L_800C98C8
    if (ctx->r5 == 0) {
        // 0x800C98A4: addu        $t2, $v0, $s1
        ctx->r10 = ADD32(ctx->r2, ctx->r17);
            goto L_800C98C8;
    }
    // 0x800C98A4: addu        $t2, $v0, $s1
    ctx->r10 = ADD32(ctx->r2, ctx->r17);
    // 0x800C98A8: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x800C98AC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800C98B0: beq         $a1, $v0, L_800C98C8
    if (ctx->r5 == ctx->r2) {
        // 0x800C98B4: andi        $v0, $t3, 0x1
        ctx->r2 = ctx->r11 & 0X1;
            goto L_800C98C8;
    }
    // 0x800C98B4: andi        $v0, $t3, 0x1
    ctx->r2 = ctx->r11 & 0X1;
    // 0x800C98B8: beq         $v0, $zero, L_800C98CC
    if (ctx->r2 == 0) {
        // 0x800C98BC: addiu       $t1, $zero, -0x1
        ctx->r9 = ADD32(0, -0X1);
            goto L_800C98CC;
    }
    // 0x800C98BC: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800C98C0: j           L_800C98CC
    // 0x800C98C4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_800C98CC;
    // 0x800C98C4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_800C98C8:
    // 0x800C98C8: addu        $t1, $zero, $zero
    ctx->r9 = ADD32(0, 0);
L_800C98CC:
    // 0x800C98CC: sll         $v0, $t1, 16
    ctx->r2 = S32(ctx->r9 << 16);
    // 0x800C98D0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800C98D4: lw          $a1, 0x734($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X734);
    // 0x800C98D8: lw          $a2, 0x760($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X760);
    // 0x800C98DC: lw          $s6, 0x18($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X18);
    // 0x800C98E0: addu        $v1, $a1, $t2
    ctx->r3 = ADD32(ctx->r5, ctx->r10);
    // 0x800C98E4: addu        $t0, $a2, $t2
    ctx->r8 = ADD32(ctx->r6, ctx->r10);
    // 0x800C98E8: addu        $t2, $t2, $v0
    ctx->r10 = ADD32(ctx->r10, ctx->r2);
    // 0x800C98EC: addu        $a0, $a1, $t2
    ctx->r4 = ADD32(ctx->r5, ctx->r10);
    // 0x800C98F0: addu        $a3, $a2, $t2
    ctx->r7 = ADD32(ctx->r6, ctx->r10);
    // 0x800C98F4: addu        $t2, $t2, $s6
    ctx->r10 = ADD32(ctx->r10, ctx->r22);
    // 0x800C98F8: addu        $a1, $a1, $t2
    ctx->r5 = ADD32(ctx->r5, ctx->r10);
    // 0x800C98FC: addu        $a2, $a2, $t2
    ctx->r6 = ADD32(ctx->r6, ctx->r10);
    // 0x800C9900: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800C9904: lbu         $a1, 0x0($a1)
    ctx->r5 = MEM_BU(ctx->r5, 0X0);
    // 0x800C9908: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800C990C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C9910: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800C9914: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800C9918: sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2 << 1);
    // 0x800C991C: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800C9920: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800C9924: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x800C9928: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800C992C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C9930: lbu         $v0, 0x0($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X0);
    // 0x800C9934: srl         $t0, $v1, 4
    ctx->r8 = S32(U32(ctx->r3) >> 4);
    // 0x800C9938: lbu         $a1, 0x0($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X0);
    // 0x800C993C: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800C9940: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C9944: lbu         $v0, 0x0($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X0);
    // 0x800C9948: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800C994C: sll         $a0, $v0, 1
    ctx->r4 = S32(ctx->r2 << 1);
    // 0x800C9950: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800C9954: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x800C9958: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x800C995C: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800C9960: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C9964: srl         $v1, $v1, 4
    ctx->r3 = S32(U32(ctx->r3) >> 4);
L_800C9968:
    // 0x800C9968: lw          $v0, 0x7D8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7D8);
    // 0x800C996C: sll         $a1, $v1, 2
    ctx->r5 = S32(ctx->r3 << 2);
    // 0x800C9970: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x800C9974: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800C9978: andi        $a0, $t4, 0xFFFF
    ctx->r4 = ctx->r12 & 0XFFFF;
    // 0x800C997C: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x800C9980: addu        $v0, $s2, $v0
    ctx->r2 = ADD32(ctx->r18, ctx->r2);
    // 0x800C9984: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800C9988: sll         $a2, $t0, 2
    ctx->r6 = S32(ctx->r8 << 2);
    // 0x800C998C: sb          $v0, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r2;
    // 0x800C9990: lw          $v0, 0x7E4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7E4);
    // 0x800C9994: lw          $v1, 0x7E0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X7E0);
    // 0x800C9998: addu        $v0, $a2, $v0
    ctx->r2 = ADD32(ctx->r6, ctx->r2);
    // 0x800C999C: addu        $a1, $a1, $v1
    ctx->r5 = ADD32(ctx->r5, ctx->r3);
    // 0x800C99A0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800C99A4: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800C99A8: addiu       $t7, $t7, 0x3
    ctx->r15 = ADD32(ctx->r15, 0X3);
    // 0x800C99AC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C99B0: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800C99B4: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x800C99B8: addu        $v0, $t9, $v0
    ctx->r2 = ADD32(ctx->r25, ctx->r2);
    // 0x800C99BC: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800C99C0: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x800C99C4: sb          $v0, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r2;
    // 0x800C99C8: lw          $v0, 0x7DC($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7DC);
    // 0x800C99CC: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800C99D0: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x800C99D4: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800C99D8: andi        $a1, $t3, 0xFFFF
    ctx->r5 = ctx->r11 & 0XFFFF;
    // 0x800C99DC: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800C99E0: addu        $a0, $t8, $a0
    ctx->r4 = ADD32(ctx->r24, ctx->r4);
    // 0x800C99E4: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800C99E8: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x800C99EC: sb          $v0, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r2;
    // 0x800C99F0: lhu         $v0, 0x7E8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X7E8);
    // 0x800C99F4: lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X0);
    // 0x800C99F8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C99FC: slt         $v0, $a1, $v0
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800C9A00: bne         $v0, $zero, L_800C9854
    if (ctx->r2 != 0) {
        // 0x800C9A04: addiu       $t5, $t5, 0x1
        ctx->r13 = ADD32(ctx->r13, 0X1);
            goto L_800C9854;
    }
    // 0x800C9A04: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
L_800C9A08:
    // 0x800C9A08: addiu       $t6, $t6, 0x1
    ctx->r14 = ADD32(ctx->r14, 0X1);
    // 0x800C9A0C: lhu         $v1, 0x2($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X2);
    // 0x800C9A10: andi        $v0, $t6, 0xFFFF
    ctx->r2 = ctx->r14 & 0XFFFF;
    // 0x800C9A14: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800C9A18: bne         $v0, $zero, L_800C97DC
    if (ctx->r2 != 0) {
        // 0x800C9A1C: andi        $v1, $t6, 0xFFFF
        ctx->r3 = ctx->r14 & 0XFFFF;
            goto L_800C97DC;
    }
    // 0x800C9A1C: andi        $v1, $t6, 0xFFFF
    ctx->r3 = ctx->r14 & 0XFFFF;
L_800C9A20:
    // 0x800C9A20: lhu         $v0, 0x7E8($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X7E8);
    // 0x800C9A24: lhu         $v1, 0x40($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X40);
    // 0x800C9A28: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C9A2C: lhu         $v1, 0x3C($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X3C);
    // 0x800C9A30: sh          $v0, 0x7E8($s0)
    MEM_H(0X7E8, ctx->r16) = ctx->r2;
    // 0x800C9A34: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x800C9A38: bne         $v0, $v1, L_800C9A58
    if (ctx->r2 != ctx->r3) {
        // 0x800C9A3C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800C9A58;
    }
    // 0x800C9A3C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C9A40: lhu         $v0, 0x7EA($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X7EA);
    // 0x800C9A44: lhu         $v1, 0x42($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X42);
    // 0x800C9A48: sh          $zero, 0x7E8($s0)
    MEM_H(0X7E8, ctx->r16) = 0;
    // 0x800C9A4C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C9A50: sh          $v0, 0x7EA($s0)
    MEM_H(0X7EA, ctx->r16) = ctx->r2;
    // 0x800C9A54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800C9A58:
    // 0x800C9A58: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800C9A5C: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800C9A60: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800C9A64: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800C9A68: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800C9A6C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800C9A70: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800C9A74: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800C9A78: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800C9A7C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C9A80: jr          $ra
    // 0x800C9A84: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800C9A84: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_800C8E90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8E90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C8E94: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800C8E98: addu        $s1, $a0, $zero
    ctx->r17 = ADD32(ctx->r4, 0);
    // 0x800C8E9C: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x800C8EA0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800C8EA4: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x800C8EA8: jal         0x8005779C
    // 0x800C8EAC: nop

    releaseMeshAsset(rdram, ctx);
        goto after_0;
    // 0x800C8EAC: nop

    after_0:
    // 0x800C8EB0: lh          $v1, 0x70($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X70);
    // 0x800C8EB4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800C8EB8: beq         $v1, $v0, L_800C8EF4
    if (ctx->r3 == ctx->r2) {
        // 0x800C8EBC: slti        $v0, $v1, 0x4
        ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
            goto L_800C8EF4;
    }
    // 0x800C8EBC: slti        $v0, $v1, 0x4
    ctx->r2 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x800C8EC0: beq         $v0, $zero, L_800C8ED8
    if (ctx->r2 == 0) {
        // 0x800C8EC4: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800C8ED8;
    }
    // 0x800C8EC4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800C8EC8: beql        $v1, $v0, L_800C8EEC
    if (ctx->r3 == ctx->r2) {
        // 0x800C8ECC: lui         $a0, 0x800A
        ctx->r4 = S32(0X800A << 16);
            goto L_800C8EEC;
    }
    goto skip_0;
    // 0x800C8ECC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    skip_0:
    // 0x800C8ED0: j           L_800C8F08
    // 0x800C8ED4: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
        goto L_800C8F08;
    // 0x800C8ED4: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
L_800C8ED8:
    // 0x800C8ED8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800C8EDC: beql        $v1, $v0, L_800C8F00
    if (ctx->r3 == ctx->r2) {
        // 0x800C8EE0: lui         $a0, 0x800A
        ctx->r4 = S32(0X800A << 16);
            goto L_800C8F00;
    }
    goto skip_1;
    // 0x800C8EE0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    skip_1:
    // 0x800C8EE4: j           L_800C8F08
    // 0x800C8EE8: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
        goto L_800C8F08;
    // 0x800C8EE8: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
L_800C8EEC:
    // 0x800C8EEC: j           L_800C8F0C
    // 0x800C8EF0: addiu       $a0, $a0, 0x6A0C
    ctx->r4 = ADD32(ctx->r4, 0X6A0C);
        goto L_800C8F0C;
    // 0x800C8EF0: addiu       $a0, $a0, 0x6A0C
    ctx->r4 = ADD32(ctx->r4, 0X6A0C);
L_800C8EF4:
    // 0x800C8EF4: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800C8EF8: j           L_800C8F0C
    // 0x800C8EFC: addiu       $a0, $a0, 0x6A18
    ctx->r4 = ADD32(ctx->r4, 0X6A18);
        goto L_800C8F0C;
    // 0x800C8EFC: addiu       $a0, $a0, 0x6A18
    ctx->r4 = ADD32(ctx->r4, 0X6A18);
L_800C8F00:
    // 0x800C8F00: j           L_800C8F0C
    // 0x800C8F04: addiu       $a0, $a0, 0x6A24
    ctx->r4 = ADD32(ctx->r4, 0X6A24);
        goto L_800C8F0C;
    // 0x800C8F04: addiu       $a0, $a0, 0x6A24
    ctx->r4 = ADD32(ctx->r4, 0X6A24);
L_800C8F08:
    // 0x800C8F08: addiu       $a0, $a0, 0x6A30
    ctx->r4 = ADD32(ctx->r4, 0X6A30);
L_800C8F0C:
    // 0x800C8F0C: jal         0x80056EB0
    // 0x800C8F10: nop

    walkMeshdef0List(rdram, ctx);
        goto after_1;
    // 0x800C8F10: nop

    after_1:
    // 0x800C8F14: sw          $v0, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r2;
    // 0x800C8F18: lw          $s0, 0x34($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X34);
    // 0x800C8F1C: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x800C8F20: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    // 0x800C8F24: lw          $a2, 0x2C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X2C);
    // 0x800C8F28: lw          $a3, 0x30($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X30);
    // 0x800C8F2C: jal         0x8001CB64
    // 0x800C8F30: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    initVec4TripletFromArgs(rdram, ctx);
        goto after_2;
    // 0x800C8F30: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_2:
    // 0x800C8F34: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x800C8F38: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x800C8F3C: jal         0x8001CB9C
    // 0x800C8F40: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    composeRotationMatrixSlot0(rdram, ctx);
        goto after_3;
    // 0x800C8F40: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_3:
    // 0x800C8F44: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x800C8F48: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    // 0x800C8F4C: jal         0x8001CCCC
    // 0x800C8F50: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    composeRotationMatrixSlot1(rdram, ctx);
        goto after_4;
    // 0x800C8F50: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_4:
    // 0x800C8F54: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x800C8F58: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    // 0x800C8F5C: jal         0x8001CDFC
    // 0x800C8F60: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    composeRotationMatrixSlot2(rdram, ctx);
        goto after_5;
    // 0x800C8F60: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_5:
    // 0x800C8F64: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x800C8F68: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    // 0x800C8F6C: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x800C8F70: lw          $a3, 0x8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X8);
    // 0x800C8F74: jal         0x8001CA90
    // 0x800C8F78: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    addVec3At0x24(rdram, ctx);
        goto after_6;
    // 0x800C8F78: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_6:
    // 0x800C8F7C: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x800C8F80: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800C8F84: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800C8F88: jr          $ra
    // 0x800C8F8C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C8F8C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void npcTurretUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C8F90: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x800C8F94: sw          $s5, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r21;
    // 0x800C8F98: addu        $s5, $a0, $zero
    ctx->r21 = ADD32(ctx->r4, 0);
    // 0x800C8F9C: sw          $s0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r16;
    // 0x800C8FA0: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x800C8FA4: addiu       $v1, $a1, -0x1
    ctx->r3 = ADD32(ctx->r5, -0X1);
    // 0x800C8FA8: sltiu       $v0, $v1, 0xB
    ctx->r2 = ctx->r3 < 0XB ? 1 : 0;
    // 0x800C8FAC: sw          $ra, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r31;
    // 0x800C8FB0: sw          $s4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r20;
    // 0x800C8FB4: sw          $s3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r19;
    // 0x800C8FB8: sw          $s2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r18;
    // 0x800C8FBC: sw          $s1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r17;
    // 0x800C8FC0: sdc1        $f30, 0xB0($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0XB0, ctx->r29);
    // 0x800C8FC4: sdc1        $f28, 0xA8($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0XA8, ctx->r29);
    // 0x800C8FC8: sdc1        $f26, 0xA0($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0XA0, ctx->r29);
    // 0x800C8FCC: sdc1        $f24, 0x98($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X98, ctx->r29);
    // 0x800C8FD0: sdc1        $f22, 0x90($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X90, ctx->r29);
    // 0x800C8FD4: sdc1        $f20, 0x88($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X88, ctx->r29);
    // 0x800C8FD8: lw          $s1, 0x4($s5)
    ctx->r17 = MEM_W(ctx->r21, 0X4);
    // 0x800C8FDC: beq         $v0, $zero, L_800CA14C
    if (ctx->r2 == 0) {
        // 0x800C8FE0: addu        $s0, $a2, $zero
        ctx->r16 = ADD32(ctx->r6, 0);
            goto L_800CA14C;
    }
    // 0x800C8FE0: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x800C8FE4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800C8FE8: addiu       $v0, $v0, 0x6AA8
    ctx->r2 = ADD32(ctx->r2, 0X6AA8);
    // 0x800C8FEC: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800C8FF0: addu        $v1, $v1, $v0
    gpr jr_addend_800C8FF8 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C8FF4: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x800C8FF8: jr          $v0
    // 0x800C8FFC: nop

    switch (jr_addend_800C8FF8 >> 2) {
        case 0: goto L_800C9000; break;
        case 1: goto L_800C9390; break;
        case 2: goto L_800C93E8; break;
        case 3: goto L_800C9AA0; break;
        case 4: goto L_800C9E70; break;
        case 5: goto L_800CA14C; break;
        case 6: goto L_800CA124; break;
        case 7: goto L_800CA14C; break;
        case 8: goto L_800CA038; break;
        case 9: goto L_800CA14C; break;
        case 10: goto L_800CA138; break;
        default: switch_error(__func__, 0x800C8FF8, 0x800A6AA8);
    }
    // 0x800C8FFC: nop

L_800C9000:
    // 0x800C9000: lhu         $v1, 0x0($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X0);
    // 0x800C9004: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // 0x800C9008: beq         $v1, $v0, L_800C9054
    if (ctx->r3 == ctx->r2) {
        // 0x800C900C: slti        $v0, $v1, 0x29
        ctx->r2 = SIGNED(ctx->r3) < 0X29 ? 1 : 0;
            goto L_800C9054;
    }
    // 0x800C900C: slti        $v0, $v1, 0x29
    ctx->r2 = SIGNED(ctx->r3) < 0X29 ? 1 : 0;
    // 0x800C9010: beq         $v0, $zero, L_800C9030
    if (ctx->r2 == 0) {
        // 0x800C9014: addiu       $v0, $zero, 0xD
        ctx->r2 = ADD32(0, 0XD);
            goto L_800C9030;
    }
    // 0x800C9014: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // 0x800C9018: beq         $v1, $v0, L_800C9044
    if (ctx->r3 == ctx->r2) {
        // 0x800C901C: addiu       $v0, $zero, 0x1E
        ctx->r2 = ADD32(0, 0X1E);
            goto L_800C9044;
    }
    // 0x800C901C: addiu       $v0, $zero, 0x1E
    ctx->r2 = ADD32(0, 0X1E);
    // 0x800C9020: beq         $v1, $v0, L_800C904C
    if (ctx->r3 == ctx->r2) {
        // 0x800C9024: addu        $s4, $zero, $zero
        ctx->r20 = ADD32(0, 0);
            goto L_800C904C;
    }
    // 0x800C9024: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
    // 0x800C9028: j           L_800C9064
    // 0x800C902C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
        goto L_800C9064;
    // 0x800C902C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_800C9030:
    // 0x800C9030: addiu       $v0, $zero, 0x41
    ctx->r2 = ADD32(0, 0X41);
    // 0x800C9034: beq         $v1, $v0, L_800C905C
    if (ctx->r3 == ctx->r2) {
        // 0x800C9038: addiu       $v0, $zero, 0x42
        ctx->r2 = ADD32(0, 0X42);
            goto L_800C905C;
    }
    // 0x800C9038: addiu       $v0, $zero, 0x42
    ctx->r2 = ADD32(0, 0X42);
    // 0x800C903C: beq         $v1, $v0, L_800C9060
    if (ctx->r3 == ctx->r2) {
        // 0x800C9040: addiu       $s4, $zero, 0x4
        ctx->r20 = ADD32(0, 0X4);
            goto L_800C9060;
    }
    // 0x800C9040: addiu       $s4, $zero, 0x4
    ctx->r20 = ADD32(0, 0X4);
L_800C9044:
    // 0x800C9044: j           L_800C9060
    // 0x800C9048: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
        goto L_800C9060;
    // 0x800C9048: addu        $s4, $zero, $zero
    ctx->r20 = ADD32(0, 0);
L_800C904C:
    // 0x800C904C: j           L_800C9060
    // 0x800C9050: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
        goto L_800C9060;
    // 0x800C9050: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_800C9054:
    // 0x800C9054: j           L_800C9060
    // 0x800C9058: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
        goto L_800C9060;
    // 0x800C9058: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
L_800C905C:
    // 0x800C905C: addiu       $s4, $zero, 0x3
    ctx->r20 = ADD32(0, 0X3);
L_800C9060:
    // 0x800C9060: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_800C9064:
    // 0x800C9064: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x800C9068: lw          $v0, 0x7CE4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7CE4);
    // 0x800C906C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800C9070: sw          $s0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r16;
    // 0x800C9074: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C9078: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800C907C: lw          $s2, 0x6C($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X6C);
    // 0x800C9080: beq         $a0, $v1, L_800C90E0
    if (ctx->r4 == ctx->r3) {
        // 0x800C9084: slti        $v0, $a0, 0x3
        ctx->r2 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
            goto L_800C90E0;
    }
    // 0x800C9084: slti        $v0, $a0, 0x3
    ctx->r2 = SIGNED(ctx->r4) < 0X3 ? 1 : 0;
    // 0x800C9088: beq         $v0, $zero, L_800C90A0
    if (ctx->r2 == 0) {
        // 0x800C908C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800C90A0;
    }
    // 0x800C908C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C9090: beq         $a0, $v0, L_800C90C4
    if (ctx->r4 == ctx->r2) {
        // 0x800C9094: nop
    
            goto L_800C90C4;
    }
    // 0x800C9094: nop

    // 0x800C9098: j           L_800C90B4
    // 0x800C909C: nop

        goto L_800C90B4;
    // 0x800C909C: nop

L_800C90A0:
    // 0x800C90A0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800C90A4: beq         $a0, $v0, L_800C90FC
    if (ctx->r4 == ctx->r2) {
        // 0x800C90A8: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_800C90FC;
    }
    // 0x800C90A8: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800C90AC: beq         $a0, $v0, L_800C9118
    if (ctx->r4 == ctx->r2) {
        // 0x800C90B0: nop
    
            goto L_800C9118;
    }
    // 0x800C90B0: nop

L_800C90B4:
    // 0x800C90B4: blez        $s2, L_800C90D4
    if (SIGNED(ctx->r18) <= 0) {
        // 0x800C90B8: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_800C90D4;
    }
    // 0x800C90B8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800C90BC: j           L_800C9130
    // 0x800C90C0: addiu       $a0, $v0, 0x6A40
    ctx->r4 = ADD32(ctx->r2, 0X6A40);
        goto L_800C9130;
    // 0x800C90C0: addiu       $a0, $v0, 0x6A40
    ctx->r4 = ADD32(ctx->r2, 0X6A40);
L_800C90C4:
    // 0x800C90C4: blez        $s2, L_800C90D4
    if (SIGNED(ctx->r18) <= 0) {
        // 0x800C90C8: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_800C90D4;
    }
    // 0x800C90C8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800C90CC: j           L_800C9130
    // 0x800C90D0: addiu       $a0, $v0, 0x6A4C
    ctx->r4 = ADD32(ctx->r2, 0X6A4C);
        goto L_800C9130;
    // 0x800C90D0: addiu       $a0, $v0, 0x6A4C
    ctx->r4 = ADD32(ctx->r2, 0X6A4C);
L_800C90D4:
    // 0x800C90D4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800C90D8: j           L_800C9130
    // 0x800C90DC: addiu       $a0, $v0, 0x6A30
    ctx->r4 = ADD32(ctx->r2, 0X6A30);
        goto L_800C9130;
    // 0x800C90DC: addiu       $a0, $v0, 0x6A30
    ctx->r4 = ADD32(ctx->r2, 0X6A30);
L_800C90E0:
    // 0x800C90E0: blez        $s2, L_800C90F0
    if (SIGNED(ctx->r18) <= 0) {
        // 0x800C90E4: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_800C90F0;
    }
    // 0x800C90E4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800C90E8: j           L_800C9130
    // 0x800C90EC: addiu       $a0, $v0, 0x6A58
    ctx->r4 = ADD32(ctx->r2, 0X6A58);
        goto L_800C9130;
    // 0x800C90EC: addiu       $a0, $v0, 0x6A58
    ctx->r4 = ADD32(ctx->r2, 0X6A58);
L_800C90F0:
    // 0x800C90F0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800C90F4: j           L_800C9130
    // 0x800C90F8: addiu       $a0, $v0, 0x6A0C
    ctx->r4 = ADD32(ctx->r2, 0X6A0C);
        goto L_800C9130;
    // 0x800C90F8: addiu       $a0, $v0, 0x6A0C
    ctx->r4 = ADD32(ctx->r2, 0X6A0C);
L_800C90FC:
    // 0x800C90FC: blez        $s2, L_800C910C
    if (SIGNED(ctx->r18) <= 0) {
        // 0x800C9100: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_800C910C;
    }
    // 0x800C9100: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800C9104: j           L_800C9130
    // 0x800C9108: addiu       $a0, $v0, 0x6A64
    ctx->r4 = ADD32(ctx->r2, 0X6A64);
        goto L_800C9130;
    // 0x800C9108: addiu       $a0, $v0, 0x6A64
    ctx->r4 = ADD32(ctx->r2, 0X6A64);
L_800C910C:
    // 0x800C910C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800C9110: j           L_800C9130
    // 0x800C9114: addiu       $a0, $v0, 0x6A18
    ctx->r4 = ADD32(ctx->r2, 0X6A18);
        goto L_800C9130;
    // 0x800C9114: addiu       $a0, $v0, 0x6A18
    ctx->r4 = ADD32(ctx->r2, 0X6A18);
L_800C9118:
    // 0x800C9118: blez        $s2, L_800C9128
    if (SIGNED(ctx->r18) <= 0) {
        // 0x800C911C: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_800C9128;
    }
    // 0x800C911C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800C9120: j           L_800C9130
    // 0x800C9124: addiu       $a0, $v0, 0x6A70
    ctx->r4 = ADD32(ctx->r2, 0X6A70);
        goto L_800C9130;
    // 0x800C9124: addiu       $a0, $v0, 0x6A70
    ctx->r4 = ADD32(ctx->r2, 0X6A70);
L_800C9128:
    // 0x800C9128: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800C912C: addiu       $a0, $v0, 0x6A24
    ctx->r4 = ADD32(ctx->r2, 0X6A24);
L_800C9130:
    // 0x800C9130: jal         0x80056EB0
    // 0x800C9134: nop

    walkMeshdef0List(rdram, ctx);
        goto after_0;
    // 0x800C9134: nop

    after_0:
    // 0x800C9138: sw          $v0, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r2;
    // 0x800C913C: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800C9140: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
    // 0x800C9144: lwc1        $f0, 0x14($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800C9148: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
    // 0x800C914C: lwc1        $f0, 0x18($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
    // 0x800C9150: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
    // 0x800C9154: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x800C9158: lw          $a2, 0x20($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X20);
    // 0x800C915C: lw          $a3, 0x24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X24);
    // 0x800C9160: jal         0x80059D78
    // 0x800C9164: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    composeEulerRotationXYZ(rdram, ctx);
        goto after_1;
    // 0x800C9164: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_1:
    // 0x800C9168: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800C916C: lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X30);
    // 0x800C9170: swc1        $f0, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f0.u32l;
    // 0x800C9174: swc1        $f0, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f0.u32l;
    // 0x800C9178: swc1        $f0, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f0.u32l;
    // 0x800C917C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800C9180: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C9184: lwc1        $f0, 0x6AD4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6AD4);
    // 0x800C9188: lwc1        $f4, 0x34($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X34);
    // 0x800C918C: lwc1        $f2, 0x28($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800C9190: div.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800C9194: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C9198: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x800C919C: swc1        $f0, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f0.u32l;
    // 0x800C91A0: lw          $a1, 0x28($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X28);
    // 0x800C91A4: lw          $a2, 0x2C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X2C);
    // 0x800C91A8: lw          $a3, 0x30($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X30);
    // 0x800C91AC: jal         0x8001CB64
    // 0x800C91B0: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    initVec4TripletFromArgs(rdram, ctx);
        goto after_2;
    // 0x800C91B0: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_2:
    // 0x800C91B4: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x800C91B8: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x800C91BC: jal         0x8001CB9C
    // 0x800C91C0: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    composeRotationMatrixSlot0(rdram, ctx);
        goto after_3;
    // 0x800C91C0: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_3:
    // 0x800C91C4: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x800C91C8: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    // 0x800C91CC: jal         0x8001CCCC
    // 0x800C91D0: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    composeRotationMatrixSlot1(rdram, ctx);
        goto after_4;
    // 0x800C91D0: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_4:
    // 0x800C91D4: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x800C91D8: lw          $a1, 0x24($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X24);
    // 0x800C91DC: jal         0x8001CDFC
    // 0x800C91E0: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    composeRotationMatrixSlot2(rdram, ctx);
        goto after_5;
    // 0x800C91E0: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_5:
    // 0x800C91E4: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x800C91E8: lw          $a2, 0x4($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X4);
    // 0x800C91EC: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x800C91F0: lw          $a3, 0x8($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X8);
    // 0x800C91F4: jal         0x8001CA90
    // 0x800C91F8: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    addVec3At0x24(rdram, ctx);
        goto after_6;
    // 0x800C91F8: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_6:
    // 0x800C91FC: sw          $s1, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->r17;
    // 0x800C9200: lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X30);
    // 0x800C9204: blez        $s2, L_800C9334
    if (SIGNED(ctx->r18) <= 0) {
        // 0x800C9208: sw          $v0, 0xC($s5)
        MEM_W(0XC, ctx->r21) = ctx->r2;
            goto L_800C9334;
    }
    // 0x800C9208: sw          $v0, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r2;
    // 0x800C920C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800C9210: addiu       $s2, $v0, -0x6AA0
    ctx->r18 = ADD32(ctx->r2, -0X6AA0);
    // 0x800C9214: lhu         $a0, 0x1C($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X1C);
    // 0x800C9218: jal         0x8003E684
    // 0x800C921C: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    popNpcSlotFromTail(rdram, ctx);
        goto after_7;
    // 0x800C921C: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_7:
    // 0x800C9220: sh          $v0, 0x64($s1)
    MEM_H(0X64, ctx->r17) = ctx->r2;
    // 0x800C9224: lw          $v1, 0x8C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8C);
    // 0x800C9228: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C922C: bne         $v1, $v0, L_800C9238
    if (ctx->r3 != ctx->r2) {
        // 0x800C9230: addiu       $a0, $zero, 0x2C
        ctx->r4 = ADD32(0, 0X2C);
            goto L_800C9238;
    }
    // 0x800C9230: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    // 0x800C9234: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
L_800C9238:
    // 0x800C9238: addu        $v0, $a0, $s2
    ctx->r2 = ADD32(ctx->r4, ctx->r18);
    // 0x800C923C: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x800C9240: jal         0x8003E684
    // 0x800C9244: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    popNpcSlotFromTail(rdram, ctx);
        goto after_8;
    // 0x800C9244: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_8:
    // 0x800C9248: sh          $v0, 0x66($s1)
    MEM_H(0X66, ctx->r17) = ctx->r2;
    // 0x800C924C: addu        $v0, $s4, $zero
    ctx->r2 = ADD32(ctx->r20, 0);
    // 0x800C9250: beq         $v0, $zero, L_800C9260
    if (ctx->r2 == 0) {
        // 0x800C9254: slti        $v0, $v0, 0x3
        ctx->r2 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
            goto L_800C9260;
    }
    // 0x800C9254: slti        $v0, $v0, 0x3
    ctx->r2 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800C9258: bne         $v0, $zero, L_800C927C
    if (ctx->r2 != 0) {
        // 0x800C925C: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_800C927C;
    }
    // 0x800C925C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
L_800C9260:
    // 0x800C9260: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800C9264: addiu       $a1, $v0, 0x6A7C
    ctx->r5 = ADD32(ctx->r2, 0X6A7C);
    // 0x800C9268: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800C926C: addiu       $s2, $v0, 0x6A88
    ctx->r18 = ADD32(ctx->r2, 0X6A88);
    // 0x800C9270: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800C9274: j           L_800C9290
    // 0x800C9278: addiu       $s3, $v0, 0x6A94
    ctx->r19 = ADD32(ctx->r2, 0X6A94);
        goto L_800C9290;
    // 0x800C9278: addiu       $s3, $v0, 0x6A94
    ctx->r19 = ADD32(ctx->r2, 0X6A94);
L_800C927C:
    // 0x800C927C: addiu       $a1, $v0, 0x6A7C
    ctx->r5 = ADD32(ctx->r2, 0X6A7C);
    // 0x800C9280: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800C9284: addiu       $s2, $v0, 0x6A88
    ctx->r18 = ADD32(ctx->r2, 0X6A88);
    // 0x800C9288: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800C928C: addiu       $s3, $v0, 0x6AA0
    ctx->r19 = ADD32(ctx->r2, 0X6AA0);
L_800C9290:
    // 0x800C9290: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x800C9294: jal         0x80059434
    // 0x800C9298: addiu       $a2, $s1, 0x48
    ctx->r6 = ADD32(ctx->r17, 0X48);
    lookupHmtMaterialByName(rdram, ctx);
        goto after_9;
    // 0x800C9298: addiu       $a2, $s1, 0x48
    ctx->r6 = ADD32(ctx->r17, 0X48);
    after_9:
    // 0x800C929C: addu        $a1, $s2, $zero
    ctx->r5 = ADD32(ctx->r18, 0);
    // 0x800C92A0: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x800C92A4: addiu       $a2, $s1, 0x4C
    ctx->r6 = ADD32(ctx->r17, 0X4C);
    // 0x800C92A8: jal         0x80059434
    // 0x800C92AC: sw          $v0, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = ctx->r2;
    lookupHmtMaterialByName(rdram, ctx);
        goto after_10;
    // 0x800C92AC: sw          $v0, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = ctx->r2;
    after_10:
    // 0x800C92B0: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x800C92B4: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x800C92B8: addiu       $a2, $s1, 0x50
    ctx->r6 = ADD32(ctx->r17, 0X50);
    // 0x800C92BC: jal         0x80059434
    // 0x800C92C0: sw          $v0, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->r2;
    lookupHmtMaterialByName(rdram, ctx);
        goto after_11;
    // 0x800C92C0: sw          $v0, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->r2;
    after_11:
    // 0x800C92C4: sw          $v0, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->r2;
    // 0x800C92C8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800C92CC: addiu       $s3, $v0, -0x6AA0
    ctx->r19 = ADD32(ctx->r2, -0X6AA0);
    // 0x800C92D0: lw          $v0, 0x8C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8C);
    // 0x800C92D4: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800C92D8: bne         $v0, $s2, L_800C92E4
    if (ctx->r2 != ctx->r18) {
        // 0x800C92DC: addiu       $v1, $zero, 0x10
        ctx->r3 = ADD32(0, 0X10);
            goto L_800C92E4;
    }
    // 0x800C92DC: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
    // 0x800C92E0: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
L_800C92E4:
    // 0x800C92E4: addu        $v0, $v1, $s3
    ctx->r2 = ADD32(ctx->r3, ctx->r19);
    // 0x800C92E8: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x800C92EC: jal         0x8003E684
    // 0x800C92F0: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    popNpcSlotFromTail(rdram, ctx);
        goto after_12;
    // 0x800C92F0: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_12:
    // 0x800C92F4: sh          $v0, 0x68($s1)
    MEM_H(0X68, ctx->r17) = ctx->r2;
    // 0x800C92F8: lw          $v0, 0x90($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X90);
    // 0x800C92FC: beq         $v0, $zero, L_800C932C
    if (ctx->r2 == 0) {
        // 0x800C9300: ori         $v0, $zero, 0xFFFF
        ctx->r2 = 0 | 0XFFFF;
            goto L_800C932C;
    }
    // 0x800C9300: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800C9304: lw          $v0, 0x8C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8C);
    // 0x800C9308: bne         $v0, $s2, L_800C9314
    if (ctx->r2 != ctx->r18) {
        // 0x800C930C: addiu       $v1, $zero, 0x18
        ctx->r3 = ADD32(0, 0X18);
            goto L_800C9314;
    }
    // 0x800C930C: addiu       $v1, $zero, 0x18
    ctx->r3 = ADD32(0, 0X18);
    // 0x800C9310: addiu       $v1, $zero, 0x1A
    ctx->r3 = ADD32(0, 0X1A);
L_800C9314:
    // 0x800C9314: addu        $v0, $v1, $s3
    ctx->r2 = ADD32(ctx->r3, ctx->r19);
    // 0x800C9318: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x800C931C: jal         0x8003E684
    // 0x800C9320: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    popNpcSlotFromTail(rdram, ctx);
        goto after_13;
    // 0x800C9320: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_13:
    // 0x800C9324: j           L_800C9344
    // 0x800C9328: sh          $v0, 0x6A($s1)
    MEM_H(0X6A, ctx->r17) = ctx->r2;
        goto L_800C9344;
    // 0x800C9328: sh          $v0, 0x6A($s1)
    MEM_H(0X6A, ctx->r17) = ctx->r2;
L_800C932C:
    // 0x800C932C: j           L_800C9344
    // 0x800C9330: sh          $v0, 0x6A($s1)
    MEM_H(0X6A, ctx->r17) = ctx->r2;
        goto L_800C9344;
    // 0x800C9330: sh          $v0, 0x6A($s1)
    MEM_H(0X6A, ctx->r17) = ctx->r2;
L_800C9334:
    // 0x800C9334: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800C9338: lhu         $a0, -0x6A8C($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A8C);
    // 0x800C933C: jal         0x8003E684
    // 0x800C9340: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    popNpcSlotFromTail(rdram, ctx);
        goto after_14;
    // 0x800C9340: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_14:
L_800C9344:
    // 0x800C9344: lw          $v0, 0x30($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X30);
    // 0x800C9348: addiu       $a0, $s1, 0x38
    ctx->r4 = ADD32(ctx->r17, 0X38);
    // 0x800C934C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800C9350: lwc1        $f2, 0x54($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X54);
    // 0x800C9354: lwc1        $f0, 0x44($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X44);
    // 0x800C9358: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800C935C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C9360: addu        $a2, $s5, $zero
    ctx->r6 = ADD32(ctx->r21, 0);
    // 0x800C9364: lui         $a3, 0x800C
    ctx->r7 = S32(0X800C << 16);
    // 0x800C9368: addiu       $a3, $a3, 0x7DC0
    ctx->r7 = ADD32(ctx->r7, 0X7DC0);
    // 0x800C936C: sh          $s4, 0x70($s1)
    MEM_H(0X70, ctx->r17) = ctx->r20;
    // 0x800C9370: swc1        $f0, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f0.u32l;
    // 0x800C9374: jal         0x800EC588
    // 0x800C9378: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    createAndInitObject(rdram, ctx);
        goto after_15;
    // 0x800C9378: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_15:
    // 0x800C937C: sw          $zero, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = 0;
    // 0x800C9380: sw          $zero, 0x60($s1)
    MEM_W(0X60, ctx->r17) = 0;
    // 0x800C9384: sw          $zero, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = 0;
    // 0x800C9388: j           L_800CA14C
    // 0x800C938C: sb          $zero, 0xD2($s1)
    MEM_B(0XD2, ctx->r17) = 0;
        goto L_800CA14C;
    // 0x800C938C: sb          $zero, 0xD2($s1)
    MEM_B(0XD2, ctx->r17) = 0;
L_800C9390:
    // 0x800C9390: lbu         $v1, 0xD2($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0XD2);
    // 0x800C9394: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C9398: bne         $v1, $v0, L_800C93AC
    if (ctx->r3 != ctx->r2) {
        // 0x800C939C: nop
    
            goto L_800C93AC;
    }
    // 0x800C939C: nop

    // 0x800C93A0: sb          $zero, 0xD2($s1)
    MEM_B(0XD2, ctx->r17) = 0;
    // 0x800C93A4: jal         0x80098DE0
    // 0x800C93A8: addiu       $a0, $s1, 0x8C
    ctx->r4 = ADD32(ctx->r17, 0X8C);
    factor5RemoveListNode(rdram, ctx);
        goto after_16;
    // 0x800C93A8: addiu       $a0, $s1, 0x8C
    ctx->r4 = ADD32(ctx->r17, 0X8C);
    after_16:
L_800C93AC:
    // 0x800C93AC: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x800C93B0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800C93B4: addiu       $v0, $v0, 0x70
    ctx->r2 = ADD32(ctx->r2, 0X70);
    // 0x800C93B8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800C93BC: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800C93C0: lw          $a2, 0x34($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X34);
    // 0x800C93C4: jal         0x800F1E7C
    // 0x800C93C8: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    initActorRenderDescriptorIfUninit(rdram, ctx);
        goto after_17;
    // 0x800C93C8: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_17:
    // 0x800C93CC: jal         0x800EC684
    // 0x800C93D0: addiu       $a0, $s1, 0x38
    ctx->r4 = ADD32(ctx->r17, 0X38);
    clearPendingAndDestroyChildNpc(rdram, ctx);
        goto after_18;
    // 0x800C93D0: addiu       $a0, $s1, 0x38
    ctx->r4 = ADD32(ctx->r17, 0X38);
    after_18:
    // 0x800C93D4: lw          $a0, 0x30($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X30);
    // 0x800C93D8: jal         0x8005779C
    // 0x800C93DC: nop

    releaseMeshAsset(rdram, ctx);
        goto after_19;
    // 0x800C93DC: nop

    after_19:
    // 0x800C93E0: j           L_800CA150
    // 0x800C93E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800CA150;
    // 0x800C93E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800C93E8:
    // 0x800C93E8: lwc1        $f30, 0x0($s0)
    ctx->f30.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800C93EC: lwc1        $f0, 0x84($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X84);
    // 0x800C93F0: sub.s       $f0, $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f30.fl;
    // 0x800C93F4: lh          $s2, 0x72($s1)
    ctx->r18 = MEM_H(ctx->r17, 0X72);
    // 0x800C93F8: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800C93FC: beq         $s2, $s0, L_800C9450
    if (ctx->r18 == ctx->r16) {
        // 0x800C9400: swc1        $f0, 0x84($s1)
        MEM_W(0X84, ctx->r17) = ctx->f0.u32l;
            goto L_800C9450;
    }
    // 0x800C9400: swc1        $f0, 0x84($s1)
    MEM_W(0X84, ctx->r17) = ctx->f0.u32l;
    // 0x800C9404: slti        $v0, $s2, 0x2
    ctx->r2 = SIGNED(ctx->r18) < 0X2 ? 1 : 0;
    // 0x800C9408: beq         $v0, $zero, L_800C9420
    if (ctx->r2 == 0) {
        // 0x800C940C: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800C9420;
    }
    // 0x800C940C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800C9410: beq         $s2, $zero, L_800C9430
    if (ctx->r18 == 0) {
        // 0x800C9414: nop
    
            goto L_800C9430;
    }
    // 0x800C9414: nop

    // 0x800C9418: j           L_800C99BC
    // 0x800C941C: nop

        goto L_800C99BC;
    // 0x800C941C: nop

L_800C9420:
    // 0x800C9420: beql        $s2, $v0, L_800C9580
    if (ctx->r18 == ctx->r2) {
        // 0x800C9424: sub.s       $f0, $f0, $f30
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f30.fl;
            goto L_800C9580;
    }
    goto skip_0;
    // 0x800C9424: sub.s       $f0, $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f30.fl;
    skip_0:
    // 0x800C9428: j           L_800C99BC
    // 0x800C942C: nop

        goto L_800C99BC;
    // 0x800C942C: nop

L_800C9430:
    // 0x800C9430: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800C9434: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x800C9438: lui         $a3, 0x4120
    ctx->r7 = S32(0X4120 << 16);
    // 0x800C943C: lw          $a1, 0x94($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X94);
    // 0x800C9440: jal         0x800EFDE0
    // 0x800C9444: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    updateNpcEventTimer(rdram, ctx);
        goto after_20;
    // 0x800C9444: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_20:
    // 0x800C9448: j           L_800C99BC
    // 0x800C944C: sh          $s0, 0x72($s1)
    MEM_H(0X72, ctx->r17) = ctx->r16;
        goto L_800C99BC;
    // 0x800C944C: sh          $s0, 0x72($s1)
    MEM_H(0X72, ctx->r17) = ctx->r16;
L_800C9450:
    // 0x800C9450: lh          $v1, 0x70($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X70);
    // 0x800C9454: sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x800C9458: beq         $v0, $zero, L_800C94A0
    if (ctx->r2 == 0) {
        // 0x800C945C: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800C94A0;
    }
    // 0x800C945C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800C9460: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800C9464: addiu       $v0, $v0, 0x6AD8
    ctx->r2 = ADD32(ctx->r2, 0X6AD8);
    // 0x800C9468: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800C946C: addu        $v1, $v1, $v0
    gpr jr_addend_800C9474 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C9470: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x800C9474: jr          $v0
    // 0x800C9478: nop

    switch (jr_addend_800C9474 >> 2) {
        case 0: goto L_800C947C; break;
        case 1: goto L_800C9484; break;
        case 2: goto L_800C948C; break;
        case 3: goto L_800C9494; break;
        case 4: goto L_800C949C; break;
        default: switch_error(__func__, 0x800C9474, 0x800A6AD8);
    }
    // 0x800C9478: nop

L_800C947C:
    // 0x800C947C: j           L_800C94A0
    // 0x800C9480: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
        goto L_800C94A0;
    // 0x800C9480: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_800C9484:
    // 0x800C9484: j           L_800C94A0
    // 0x800C9488: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800C94A0;
    // 0x800C9488: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800C948C:
    // 0x800C948C: j           L_800C94A0
    // 0x800C9490: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
        goto L_800C94A0;
    // 0x800C9490: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_800C9494:
    // 0x800C9494: j           L_800C94A0
    // 0x800C9498: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
        goto L_800C94A0;
    // 0x800C9498: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
L_800C949C:
    // 0x800C949C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
L_800C94A0:
    // 0x800C94A0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800C94A4: addiu       $v0, $v0, -0x6608
    ctx->r2 = ADD32(ctx->r2, -0X6608);
    // 0x800C94A8: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x800C94AC: lbu         $s0, 0x0($v0)
    ctx->r16 = MEM_BU(ctx->r2, 0X0);
    // 0x800C94B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C94B4: bne         $s0, $v0, L_800C99BC
    if (ctx->r16 != ctx->r2) {
        // 0x800C94B8: nop
    
            goto L_800C99BC;
    }
    // 0x800C94B8: nop

    // 0x800C94BC: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800C94C0: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x800C94C4: mfc1        $a3, $f30
    ctx->r7 = (int32_t)ctx->f30.u32l;
    // 0x800C94C8: lw          $a1, 0x94($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X94);
    // 0x800C94CC: jal         0x800EFDE0
    // 0x800C94D0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    updateNpcEventTimer(rdram, ctx);
        goto after_21;
    // 0x800C94D0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_21:
    // 0x800C94D4: mfc1        $a1, $f30
    ctx->r5 = (int32_t)ctx->f30.u32l;
    // 0x800C94D8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800C94DC: jal         0x800C8978
    // 0x800C94E0: sh          $s0, 0x72($s1)
    MEM_H(0X72, ctx->r17) = ctx->r16;
    func_800C8978(rdram, ctx);
        goto after_22;
    // 0x800C94E0: sh          $s0, 0x72($s1)
    MEM_H(0X72, ctx->r17) = ctx->r16;
    after_22:
    // 0x800C94E4: addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
    // 0x800C94E8: lw          $t0, 0xC($s1)
    ctx->r8 = MEM_W(ctx->r17, 0XC);
    // 0x800C94EC: lw          $t1, 0x10($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X10);
    // 0x800C94F0: lw          $t2, 0x14($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X14);
    // 0x800C94F4: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800C94F8: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x800C94FC: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x800C9500: lw          $a1, 0x60($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X60);
    // 0x800C9504: jal         0x8001CC3C
    // 0x800C9508: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    buildRotationMatrixSlot0(rdram, ctx);
        goto after_23;
    // 0x800C9508: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_23:
    // 0x800C950C: lwc1        $f2, 0x5C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X5C);
    // 0x800C9510: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C9514: lwc1        $f0, 0x6AEC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6AEC);
    // 0x800C9518: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800C951C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800C9520: jal         0x8001CCCC
    // 0x800C9524: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    composeRotationMatrixSlot1(rdram, ctx);
        goto after_24;
    // 0x800C9524: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_24:
    // 0x800C9528: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800C952C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x800C9530: jal         0x800193E8
    // 0x800C9534: addiu       $a2, $s1, 0xC
    ctx->r6 = ADD32(ctx->r17, 0XC);
    transformVec3ByMat34(rdram, ctx);
        goto after_25;
    // 0x800C9534: addiu       $a2, $s1, 0xC
    ctx->r6 = ADD32(ctx->r17, 0XC);
    after_25:
    // 0x800C9538: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800C953C: jal         0x800F07AC
    // 0x800C9540: nop

    validateActorTargetLOS(rdram, ctx);
        goto after_26;
    // 0x800C9540: nop

    after_26:
    // 0x800C9544: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800C9548: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800C954C: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800C9550: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800C9554: sw          $t0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r8;
    // 0x800C9558: sw          $t1, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r9;
    // 0x800C955C: sw          $t2, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r10;
    // 0x800C9560: beq         $v0, $zero, L_800C99BC
    if (ctx->r2 == 0) {
        // 0x800C9564: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_800C99BC;
    }
    // 0x800C9564: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800C9568: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800C956C: mfc1        $a1, $f30
    ctx->r5 = (int32_t)ctx->f30.u32l;
    // 0x800C9570: jal         0x800F2D38
    // 0x800C9574: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    applyToObjectSubstructByFlag(rdram, ctx);
        goto after_27;
    // 0x800C9574: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_27:
    // 0x800C9578: j           L_800C99BC
    // 0x800C957C: nop

        goto L_800C99BC;
    // 0x800C957C: nop

L_800C9580:
    // 0x800C9580: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800C9584: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    // 0x800C9588: swc1        $f0, 0x84($s1)
    MEM_W(0X84, ctx->r17) = ctx->f0.u32l;
    // 0x800C958C: cvt.d.s     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.d = CVT_D_S(ctx->f0.fl);
    // 0x800C9590: c.le.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d <= ctx->f2.d;
    // 0x800C9594: nop

    // 0x800C9598: bc1f        L_800C99BC
    if (!c1cs) {
        // 0x800C959C: nop
    
            goto L_800C99BC;
    }
    // 0x800C959C: nop

    // 0x800C95A0: jal         0x80003430
    // 0x800C95A4: addiu       $s0, $s1, 0x24
    ctx->r16 = ADD32(ctx->r17, 0X24);
    rand_recomp(rdram, ctx);
        goto after_28;
    // 0x800C95A4: addiu       $s0, $s1, 0x24
    ctx->r16 = ADD32(ctx->r17, 0X24);
    after_28:
    // 0x800C95A8: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800C95AC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C95B0: lwc1        $f22, 0x6AF0($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X6AF0);
    // 0x800C95B4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800C95B8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800C95BC: sub.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x800C95C0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C95C4: lwc1        $f2, 0x6AF4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6AF4);
    // 0x800C95C8: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C95CC: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800C95D0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C95D4: lwc1        $f2, 0x6AF8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6AF8);
    // 0x800C95D8: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800C95DC: jal         0x80003430
    // 0x800C95E0: swc1        $f0, 0x84($s1)
    MEM_W(0X84, ctx->r17) = ctx->f0.u32l;
    rand_recomp(rdram, ctx);
        goto after_29;
    // 0x800C95E0: swc1        $f0, 0x84($s1)
    MEM_W(0X84, ctx->r17) = ctx->f0.u32l;
    after_29:
    // 0x800C95E4: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800C95E8: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800C95EC: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800C95F0: sub.s       $f2, $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f22.fl;
    // 0x800C95F4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C95F8: lwc1        $f24, 0x6AFC($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X6AFC);
    // 0x800C95FC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C9600: lwc1        $f20, 0x6B00($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X6B00);
    // 0x800C9604: div.s       $f2, $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f24.fl);
    // 0x800C9608: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x800C960C: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800C9610: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800C9614: jal         0x80003430
    // 0x800C9618: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    rand_recomp(rdram, ctx);
        goto after_30;
    // 0x800C9618: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    after_30:
    // 0x800C961C: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800C9620: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800C9624: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800C9628: sub.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x800C962C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C9630: lwc1        $f2, 0x6B04($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6B04);
    // 0x800C9634: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C9638: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800C963C: abs.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = fabsf(ctx->f0.fl);
    // 0x800C9640: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800C9644: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800C9648: jal         0x80003430
    // 0x800C964C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    rand_recomp(rdram, ctx);
        goto after_31;
    // 0x800C964C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    after_31:
    // 0x800C9650: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800C9654: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800C9658: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800C965C: sub.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x800C9660: div.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800C9664: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800C9668: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800C966C: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800C9670: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800C9674: jal         0x80061268
    // 0x800C9678: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    spawnRandomScaleEffectDefault(rdram, ctx);
        goto after_32;
    // 0x800C9678: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    after_32:
    // 0x800C967C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800C9680: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800C9684: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800C9688: addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
    // 0x800C968C: lui         $a3, 0x41C0
    ctx->r7 = S32(0X41C0 << 16);
    // 0x800C9690: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C9694: lwc1        $f0, 0x6B08($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6B08);
    // 0x800C9698: addiu       $s3, $zero, 0x7F
    ctx->r19 = ADD32(0, 0X7F);
    // 0x800C969C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800C96A0: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    // 0x800C96A4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800C96A8: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800C96AC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800C96B0: jal         0x800989D8
    // 0x800C96B4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    play3DSoundEvent(rdram, ctx);
        goto after_33;
    // 0x800C96B4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_33:
    // 0x800C96B8: lw          $v0, 0x88($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X88);
    // 0x800C96BC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800C96C0: bgtz        $v0, L_800C99BC
    if (SIGNED(ctx->r2) > 0) {
        // 0x800C96C4: sw          $v0, 0x88($s1)
        MEM_W(0X88, ctx->r17) = ctx->r2;
            goto L_800C99BC;
    }
    // 0x800C96C4: sw          $v0, 0x88($s1)
    MEM_W(0X88, ctx->r17) = ctx->r2;
    // 0x800C96C8: lwc1        $f2, 0x58($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X58);
    // 0x800C96CC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C96D0: lwc1        $f0, 0x6B0C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6B0C);
    // 0x800C96D4: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800C96D8: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800C96DC: jal         0x800612A4
    // 0x800C96E0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    spawnNpcType0xAFromTemplate(rdram, ctx);
        goto after_34;
    // 0x800C96E0: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_34:
    // 0x800C96E4: jal         0x8005EBD8
    // 0x800C96E8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    spawnByteAnimDebrisDefault(rdram, ctx);
        goto after_35;
    // 0x800C96E8: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_35:
    // 0x800C96EC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800C96F0: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800C96F4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800C96F8: lui         $a3, 0x41C8
    ctx->r7 = S32(0X41C8 << 16);
    // 0x800C96FC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C9700: lwc1        $f0, 0x6B10($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6B10);
    // 0x800C9704: addiu       $v0, $zero, 0x26
    ctx->r2 = ADD32(0, 0X26);
    // 0x800C9708: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800C970C: addiu       $v0, $zero, 0x5A
    ctx->r2 = ADD32(0, 0X5A);
    // 0x800C9710: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800C9714: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x800C9718: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800C971C: jal         0x800989D8
    // 0x800C9720: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    play3DSoundEvent(rdram, ctx);
        goto after_36;
    // 0x800C9720: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_36:
    // 0x800C9724: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800C9728: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800C972C: jal         0x800C8E90
    // 0x800C9730: sh          $v0, 0x72($s1)
    MEM_H(0X72, ctx->r17) = ctx->r2;
    func_800C8E90(rdram, ctx);
        goto after_37;
    // 0x800C9730: sh          $v0, 0x72($s1)
    MEM_H(0X72, ctx->r17) = ctx->r2;
    after_37:
    // 0x800C9734: sw          $zero, 0xC($s5)
    MEM_W(0XC, ctx->r21) = 0;
    // 0x800C9738: lhu         $a0, 0x64($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X64);
    // 0x800C973C: jal         0x8003E7D0
    // 0x800C9740: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    unregisterAndFreeNpcSlot(rdram, ctx);
        goto after_38;
    // 0x800C9740: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_38:
    // 0x800C9744: lh          $v0, 0x70($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X70);
    // 0x800C9748: beq         $v0, $s2, L_800C9788
    if (ctx->r2 == ctx->r18) {
        // 0x800C974C: nop
    
            goto L_800C9788;
    }
    // 0x800C974C: nop

    // 0x800C9750: jal         0x80003430
    // 0x800C9754: nop

    rand_recomp(rdram, ctx);
        goto after_39;
    // 0x800C9754: nop

    after_39:
    // 0x800C9758: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800C975C: sra         $v1, $v0, 16
    ctx->r3 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800C9760: bgez        $v1, L_800C976C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800C9764: addu        $v0, $v1, $zero
        ctx->r2 = ADD32(ctx->r3, 0);
            goto L_800C976C;
    }
    // 0x800C9764: addu        $v0, $v1, $zero
    ctx->r2 = ADD32(ctx->r3, 0);
    // 0x800C9768: addiu       $v0, $v1, 0x3
    ctx->r2 = ADD32(ctx->r3, 0X3);
L_800C976C:
    // 0x800C976C: sra         $v0, $v0, 2
    ctx->r2 = S32(SIGNED(ctx->r2) >> 2);
    // 0x800C9770: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800C9774: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // 0x800C9778: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800C977C: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800C9780: j           L_800C97C8
    // 0x800C9784: addiu       $s4, $v0, 0x3
    ctx->r20 = ADD32(ctx->r2, 0X3);
        goto L_800C97C8;
    // 0x800C9784: addiu       $s4, $v0, 0x3
    ctx->r20 = ADD32(ctx->r2, 0X3);
L_800C9788:
    // 0x800C9788: jal         0x80003430
    // 0x800C978C: nop

    rand_recomp(rdram, ctx);
        goto after_40;
    // 0x800C978C: nop

    after_40:
    // 0x800C9790: lui         $v1, 0x5555
    ctx->r3 = S32(0X5555 << 16);
    // 0x800C9794: ori         $v1, $v1, 0x5556
    ctx->r3 = ctx->r3 | 0X5556;
    // 0x800C9798: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800C979C: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800C97A0: mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C97A4: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x800C97A8: mfhi        $t0
    ctx->r8 = hi;
    // 0x800C97AC: subu        $v0, $t0, $v0
    ctx->r2 = SUB32(ctx->r8, ctx->r2);
    // 0x800C97B0: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x800C97B4: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C97B8: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x800C97BC: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800C97C0: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800C97C4: addiu       $s4, $a0, 0x5
    ctx->r20 = ADD32(ctx->r4, 0X5);
L_800C97C8:
    // 0x800C97C8: blez        $s4, L_800C99BC
    if (SIGNED(ctx->r20) <= 0) {
        // 0x800C97CC: addu        $s2, $zero, $zero
        ctx->r18 = ADD32(0, 0);
            goto L_800C99BC;
    }
    // 0x800C97CC: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x800C97D0: addiu       $s3, $sp, 0x38
    ctx->r19 = ADD32(ctx->r29, 0X38);
    // 0x800C97D4: addiu       $s0, $sp, 0x48
    ctx->r16 = ADD32(ctx->r29, 0X48);
    // 0x800C97D8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C97DC: lwc1        $f28, 0x6B14($at)
    ctx->f28.u32l = MEM_W(ctx->r1, 0X6B14);
    // 0x800C97E0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C97E4: lwc1        $f26, 0x6B18($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X6B18);
    // 0x800C97E8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C97EC: lwc1        $f24, 0x6B1C($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X6B1C);
L_800C97F0:
    // 0x800C97F0: lwc1        $f0, 0x58($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X58);
    // 0x800C97F4: mul.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x800C97F8: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x800C97FC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800C9800: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800C9804: addiu       $a3, $zero, 0x3C
    ctx->r7 = ADD32(0, 0X3C);
    // 0x800C9808: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800C980C: jal         0x8007202C
    // 0x800C9810: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    composeRandomRotationMatrix(rdram, ctx);
        goto after_41;
    // 0x800C9810: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_41:
    // 0x800C9814: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800C9818: lwc1        $f2, 0x0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800C981C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800C9820: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x800C9824: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800C9828: lwc1        $f2, 0x4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800C982C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800C9830: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x800C9834: lwc1        $f0, 0x40($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800C9838: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800C983C: mfc1        $a1, $f26
    ctx->r5 = (int32_t)ctx->f26.u32l;
    // 0x800C9840: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800C9844: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x800C9848: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800C984C: jal         0x80072300
    // 0x800C9850: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    scaleVec3ByRandomRange(rdram, ctx);
        goto after_42;
    // 0x800C9850: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    after_42:
    // 0x800C9854: lh          $v1, 0x70($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X70);
    // 0x800C9858: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800C985C: beq         $v1, $v0, L_800C9910
    if (ctx->r3 == ctx->r2) {
        // 0x800C9860: nop
    
            goto L_800C9910;
    }
    // 0x800C9860: nop

    // 0x800C9864: jal         0x80003430
    // 0x800C9868: nop

    rand_recomp(rdram, ctx);
        goto after_43;
    // 0x800C9868: nop

    after_43:
    // 0x800C986C: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800C9870: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800C9874: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800C9878: sub.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x800C987C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C9880: lwc1        $f2, 0x6B20($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6B20);
    // 0x800C9884: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C9888: abs.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = fabsf(ctx->f0.fl);
    // 0x800C988C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C9890: lwc1        $f0, 0x6B24($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6B24);
    // 0x800C9894: jal         0x80003430
    // 0x800C9898: add.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f0.fl;
    rand_recomp(rdram, ctx);
        goto after_44;
    // 0x800C9898: add.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f0.fl;
    after_44:
    // 0x800C989C: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800C98A0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800C98A4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800C98A8: sub.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x800C98AC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C98B0: lwc1        $f2, 0x6B28($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6B28);
    // 0x800C98B4: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C98B8: abs.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = fabsf(ctx->f0.fl);
    // 0x800C98BC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C98C0: lwc1        $f0, 0x6B2C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6B2C);
    // 0x800C98C4: jal         0x80003430
    // 0x800C98C8: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
    rand_recomp(rdram, ctx);
        goto after_45;
    // 0x800C98C8: add.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f0.fl;
    after_45:
    // 0x800C98CC: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800C98D0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800C98D4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800C98D8: sub.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x800C98DC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C98E0: lwc1        $f2, 0x6B30($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6B30);
    // 0x800C98E4: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C98E8: abs.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = fabsf(ctx->f0.fl);
    // 0x800C98EC: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x800C98F0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C98F4: lwc1        $f0, 0x6B34($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6B34);
    // 0x800C98F8: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x800C98FC: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800C9900: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800C9904: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800C9908: j           L_800C99A8
    // 0x800C990C: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
        goto L_800C99A8;
    // 0x800C990C: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
L_800C9910:
    // 0x800C9910: jal         0x80003430
    // 0x800C9914: nop

    rand_recomp(rdram, ctx);
        goto after_46;
    // 0x800C9914: nop

    after_46:
    // 0x800C9918: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800C991C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800C9920: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800C9924: sub.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x800C9928: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C992C: lwc1        $f2, 0x6B38($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6B38);
    // 0x800C9930: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C9934: abs.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = fabsf(ctx->f0.fl);
    // 0x800C9938: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C993C: lwc1        $f0, 0x6B3C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6B3C);
    // 0x800C9940: jal         0x80003430
    // 0x800C9944: add.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f0.fl;
    rand_recomp(rdram, ctx);
        goto after_47;
    // 0x800C9944: add.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f0.fl;
    after_47:
    // 0x800C9948: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800C994C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800C9950: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800C9954: sub.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x800C9958: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C995C: lwc1        $f2, 0x6B40($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6B40);
    // 0x800C9960: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C9964: abs.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = fabsf(ctx->f0.fl);
    // 0x800C9968: jal         0x80003430
    // 0x800C996C: add.s       $f20, $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f26.fl;
    rand_recomp(rdram, ctx);
        goto after_48;
    // 0x800C996C: add.s       $f20, $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f26.fl;
    after_48:
    // 0x800C9970: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800C9974: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800C9978: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800C997C: sub.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x800C9980: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C9984: lwc1        $f2, 0x6B44($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6B44);
    // 0x800C9988: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C998C: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800C9990: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x800C9994: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x800C9998: add.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f28.fl;
    // 0x800C999C: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800C99A0: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800C99A4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
L_800C99A8:
    // 0x800C99A8: jal         0x80072384
    // 0x800C99AC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    spawnDebris1Npc(rdram, ctx);
        goto after_49;
    // 0x800C99AC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    after_49:
    // 0x800C99B0: slt         $v0, $s2, $s4
    ctx->r2 = SIGNED(ctx->r18) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800C99B4: bne         $v0, $zero, L_800C97F0
    if (ctx->r2 != 0) {
        // 0x800C99B8: nop
    
            goto L_800C97F0;
    }
    // 0x800C99B8: nop

L_800C99BC:
    // 0x800C99BC: lh          $v1, 0x70($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X70);
    // 0x800C99C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C99C4: beq         $v1, $v0, L_800C9A50
    if (ctx->r3 == ctx->r2) {
        // 0x800C99C8: nop
    
            goto L_800C9A50;
    }
    // 0x800C99C8: nop

    // 0x800C99CC: lwc1        $f2, 0x7C($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X7C);
    // 0x800C99D0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C99D4: lwc1        $f4, 0x6B48($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6B48);
    // 0x800C99D8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C99DC: lwc1        $f0, 0x6B4C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6B4C);
    // 0x800C99E0: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x800C99E4: mul.s       $f0, $f30, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f30.fl, ctx->f0.fl);
    // 0x800C99E8: bc1f        L_800C9A50
    if (!c1cs) {
        // 0x800C99EC: nop
    
            goto L_800C9A50;
    }
    // 0x800C99EC: nop

    // 0x800C99F0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800C99F4: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x800C99F8: nop

    // 0x800C99FC: bc1f        L_800C9A10
    if (!c1cs) {
        // 0x800C9A00: swc1        $f2, 0x7C($s1)
        MEM_W(0X7C, ctx->r17) = ctx->f2.u32l;
            goto L_800C9A10;
    }
    // 0x800C9A00: swc1        $f2, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->f2.u32l;
    // 0x800C9A04: swc1        $f4, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->f4.u32l;
    // 0x800C9A08: j           L_800C9A50
    // 0x800C9A0C: sw          $zero, 0x80($s1)
    MEM_W(0X80, ctx->r17) = 0;
        goto L_800C9A50;
    // 0x800C9A0C: sw          $zero, 0x80($s1)
    MEM_W(0X80, ctx->r17) = 0;
L_800C9A10:
    // 0x800C9A10: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C9A14: lwc1        $f0, 0x6B50($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6B50);
    // 0x800C9A18: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800C9A1C: nop

    // 0x800C9A20: bc1fl       L_800C9A3C
    if (!c1cs) {
        // 0x800C9A24: sub.s       $f0, $f2, $f0
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_800C9A3C;
    }
    goto skip_1;
    // 0x800C9A24: sub.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f0.fl;
    skip_1:
    // 0x800C9A28: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C9A2C: lwc1        $f0, 0x6B54($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6B54);
    // 0x800C9A30: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800C9A34: j           L_800C9A50
    // 0x800C9A38: swc1        $f0, 0x80($s1)
    MEM_W(0X80, ctx->r17) = ctx->f0.u32l;
        goto L_800C9A50;
    // 0x800C9A38: swc1        $f0, 0x80($s1)
    MEM_W(0X80, ctx->r17) = ctx->f0.u32l;
L_800C9A3C:
    // 0x800C9A3C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C9A40: lwc1        $f2, 0x6B58($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6B58);
    // 0x800C9A44: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C9A48: sub.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800C9A4C: swc1        $f0, 0x80($s1)
    MEM_W(0X80, ctx->r17) = ctx->f0.u32l;
L_800C9A50:
    // 0x800C9A50: jal         0x80047D40
    // 0x800C9A54: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    isNpcWithinActiveReferenceRange(rdram, ctx);
        goto after_50;
    // 0x800C9A54: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_50:
    // 0x800C9A58: bnel        $v0, $zero, L_800C9A8C
    if (ctx->r2 != 0) {
        // 0x800C9A5C: sw          $zero, 0x6C($s1)
        MEM_W(0X6C, ctx->r17) = 0;
            goto L_800C9A8C;
    }
    goto skip_2;
    // 0x800C9A5C: sw          $zero, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = 0;
    skip_2:
    // 0x800C9A60: lw          $v0, 0x6C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X6C);
    // 0x800C9A64: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800C9A68: sw          $v0, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = ctx->r2;
    // 0x800C9A6C: slti        $v0, $v0, 0x15
    ctx->r2 = SIGNED(ctx->r2) < 0X15 ? 1 : 0;
    // 0x800C9A70: bne         $v0, $zero, L_800C9A8C
    if (ctx->r2 != 0) {
        // 0x800C9A74: nop
    
            goto L_800C9A8C;
    }
    // 0x800C9A74: nop

    // 0x800C9A78: lhu         $a0, 0x16($s5)
    ctx->r4 = MEM_HU(ctx->r21, 0X16);
    // 0x800C9A7C: jal         0x8003ED74
    // 0x800C9A80: nop

    destroyNpcSlotByIndex(rdram, ctx);
        goto after_51;
    // 0x800C9A80: nop

    after_51:
    // 0x800C9A84: j           L_800CA150
    // 0x800C9A88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800CA150;
    // 0x800C9A88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800C9A8C:
    // 0x800C9A8C: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800C9A90: jal         0x800EC6C0
    // 0x800C9A94: nop

    destroyObjectOwnedNpcSlot(rdram, ctx);
        goto after_52;
    // 0x800C9A94: nop

    after_52:
    // 0x800C9A98: j           L_800CA150
    // 0x800C9A9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800CA150;
    // 0x800C9A9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800C9AA0:
    // 0x800C9AA0: lh          $v1, 0x72($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X72);
    // 0x800C9AA4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800C9AA8: beq         $v1, $v0, L_800C9E20
    if (ctx->r3 == ctx->r2) {
        // 0x800C9AAC: addu        $s3, $s0, $zero
        ctx->r19 = ADD32(ctx->r16, 0);
            goto L_800C9E20;
    }
    // 0x800C9AAC: addu        $s3, $s0, $zero
    ctx->r19 = ADD32(ctx->r16, 0);
    // 0x800C9AB0: lw          $v0, 0x3C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X3C);
    // 0x800C9AB4: lw          $s0, 0x48($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X48);
    // 0x800C9AB8: addiu       $s2, $v0, 0x1C
    ctx->r18 = ADD32(ctx->r2, 0X1C);
    // 0x800C9ABC: jal         0x8001CA50
    // 0x800C9AC0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    clearVec4QuadStruct(rdram, ctx);
        goto after_53;
    // 0x800C9AC0: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_53:
    // 0x800C9AC4: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x800C9AC8: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800C9ACC: beq         $v0, $zero, L_800C9B00
    if (ctx->r2 == 0) {
        // 0x800C9AD0: nop
    
            goto L_800C9B00;
    }
    // 0x800C9AD0: nop

    // 0x800C9AD4: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800C9AD8: lwc1        $f2, 0x58($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800C9ADC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800C9AE0: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x800C9AE4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800C9AE8: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800C9AEC: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800C9AF0: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800C9AF4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800C9AF8: jal         0x8001CA90
    // 0x800C9AFC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    addVec3At0x24(rdram, ctx);
        goto after_54;
    // 0x800C9AFC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_54:
L_800C9B00:
    // 0x800C9B00: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x800C9B04: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x800C9B08: beq         $v0, $zero, L_800C9B24
    if (ctx->r2 == 0) {
        // 0x800C9B0C: nop
    
            goto L_800C9B24;
    }
    // 0x800C9B0C: nop

    // 0x800C9B10: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    // 0x800C9B14: lw          $a2, 0x60($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X60);
    // 0x800C9B18: lw          $a3, 0x64($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X64);
    // 0x800C9B1C: jal         0x8001CB04
    // 0x800C9B20: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    applyScaleToMat3x4(rdram, ctx);
        goto after_55;
    // 0x800C9B20: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_55:
L_800C9B24:
    // 0x800C9B24: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x800C9B28: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x800C9B2C: beq         $v0, $zero, L_800C9B3C
    if (ctx->r2 == 0) {
        // 0x800C9B30: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_800C9B3C;
    }
    // 0x800C9B30: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800C9B34: jal         0x8001DAEC
    // 0x800C9B38: addiu       $a1, $s0, 0x68
    ctx->r5 = ADD32(ctx->r16, 0X68);
    composeQuatToMat3x4(rdram, ctx);
        goto after_56;
    // 0x800C9B38: addiu       $a1, $s0, 0x68
    ctx->r5 = ADD32(ctx->r16, 0X68);
    after_56:
L_800C9B3C:
    // 0x800C9B3C: lw          $a1, 0x5C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X5C);
    // 0x800C9B40: jal         0x8001CCCC
    // 0x800C9B44: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    composeRotationMatrixSlot1(rdram, ctx);
        goto after_57;
    // 0x800C9B44: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_57:
    // 0x800C9B48: lw          $a0, 0x4C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4C);
    // 0x800C9B4C: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x800C9B50: andi        $v1, $a0, 0x9
    ctx->r3 = ctx->r4 & 0X9;
    // 0x800C9B54: bne         $v1, $v0, L_800C9B94
    if (ctx->r3 != ctx->r2) {
        // 0x800C9B58: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_800C9B94;
    }
    // 0x800C9B58: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800C9B5C: lwc1        $f2, 0x78($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800C9B60: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800C9B64: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800C9B68: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800C9B6C: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800C9B70: lwc1        $f2, 0x7C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x800C9B74: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800C9B78: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800C9B7C: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800C9B80: lwc1        $f2, 0x80($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X80);
    // 0x800C9B84: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800C9B88: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800C9B8C: j           L_800C9BC4
    // 0x800C9B90: nop

        goto L_800C9BC4;
    // 0x800C9B90: nop

L_800C9B94:
    // 0x800C9B94: bne         $v1, $v0, L_800C9BB0
    if (ctx->r3 != ctx->r2) {
        // 0x800C9B98: andi        $v0, $a0, 0x1
        ctx->r2 = ctx->r4 & 0X1;
            goto L_800C9BB0;
    }
    // 0x800C9B98: andi        $v0, $a0, 0x1
    ctx->r2 = ctx->r4 & 0X1;
    // 0x800C9B9C: lw          $a1, 0x78($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X78);
    // 0x800C9BA0: lw          $a2, 0x7C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X7C);
    // 0x800C9BA4: lw          $a3, 0x80($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X80);
    // 0x800C9BA8: j           L_800C9BC4
    // 0x800C9BAC: nop

        goto L_800C9BC4;
    // 0x800C9BAC: nop

L_800C9BB0:
    // 0x800C9BB0: beq         $v0, $zero, L_800C9BCC
    if (ctx->r2 == 0) {
        // 0x800C9BB4: nop
    
            goto L_800C9BCC;
    }
    // 0x800C9BB4: nop

    // 0x800C9BB8: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    // 0x800C9BBC: lw          $a2, 0x54($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X54);
    // 0x800C9BC0: lw          $a3, 0x58($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X58);
L_800C9BC4:
    // 0x800C9BC4: jal         0x8001CA90
    // 0x800C9BC8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    addVec3At0x24(rdram, ctx);
        goto after_58;
    // 0x800C9BC8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_58:
L_800C9BCC:
    // 0x800C9BCC: lw          $v0, 0x40($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X40);
    // 0x800C9BD0: lw          $s0, 0x4C($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X4C);
    // 0x800C9BD4: addiu       $s2, $v0, 0x1C
    ctx->r18 = ADD32(ctx->r2, 0X1C);
    // 0x800C9BD8: jal         0x8001CA50
    // 0x800C9BDC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    clearVec4QuadStruct(rdram, ctx);
        goto after_59;
    // 0x800C9BDC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_59:
    // 0x800C9BE0: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x800C9BE4: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800C9BE8: beq         $v0, $zero, L_800C9C1C
    if (ctx->r2 == 0) {
        // 0x800C9BEC: nop
    
            goto L_800C9C1C;
    }
    // 0x800C9BEC: nop

    // 0x800C9BF0: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800C9BF4: lwc1        $f2, 0x58($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800C9BF8: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800C9BFC: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x800C9C00: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800C9C04: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800C9C08: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800C9C0C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800C9C10: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800C9C14: jal         0x8001CA90
    // 0x800C9C18: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    addVec3At0x24(rdram, ctx);
        goto after_60;
    // 0x800C9C18: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_60:
L_800C9C1C:
    // 0x800C9C1C: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x800C9C20: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x800C9C24: beq         $v0, $zero, L_800C9C40
    if (ctx->r2 == 0) {
        // 0x800C9C28: nop
    
            goto L_800C9C40;
    }
    // 0x800C9C28: nop

    // 0x800C9C2C: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    // 0x800C9C30: lw          $a2, 0x60($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X60);
    // 0x800C9C34: lw          $a3, 0x64($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X64);
    // 0x800C9C38: jal         0x8001CB04
    // 0x800C9C3C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    applyScaleToMat3x4(rdram, ctx);
        goto after_61;
    // 0x800C9C3C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_61:
L_800C9C40:
    // 0x800C9C40: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x800C9C44: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x800C9C48: beq         $v0, $zero, L_800C9C58
    if (ctx->r2 == 0) {
        // 0x800C9C4C: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_800C9C58;
    }
    // 0x800C9C4C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800C9C50: jal         0x8001DAEC
    // 0x800C9C54: addiu       $a1, $s0, 0x68
    ctx->r5 = ADD32(ctx->r16, 0X68);
    composeQuatToMat3x4(rdram, ctx);
        goto after_62;
    // 0x800C9C54: addiu       $a1, $s0, 0x68
    ctx->r5 = ADD32(ctx->r16, 0X68);
    after_62:
L_800C9C58:
    // 0x800C9C58: lw          $a1, 0x60($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X60);
    // 0x800C9C5C: jal         0x8001CB9C
    // 0x800C9C60: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    composeRotationMatrixSlot0(rdram, ctx);
        goto after_63;
    // 0x800C9C60: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_63:
    // 0x800C9C64: lw          $a0, 0x4C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4C);
    // 0x800C9C68: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x800C9C6C: andi        $v1, $a0, 0x9
    ctx->r3 = ctx->r4 & 0X9;
    // 0x800C9C70: bne         $v1, $v0, L_800C9CB0
    if (ctx->r3 != ctx->r2) {
        // 0x800C9C74: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_800C9CB0;
    }
    // 0x800C9C74: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800C9C78: lwc1        $f2, 0x78($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800C9C7C: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800C9C80: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800C9C84: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800C9C88: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800C9C8C: lwc1        $f2, 0x7C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x800C9C90: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800C9C94: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800C9C98: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800C9C9C: lwc1        $f2, 0x80($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X80);
    // 0x800C9CA0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800C9CA4: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800C9CA8: j           L_800C9CE0
    // 0x800C9CAC: nop

        goto L_800C9CE0;
    // 0x800C9CAC: nop

L_800C9CB0:
    // 0x800C9CB0: bne         $v1, $v0, L_800C9CCC
    if (ctx->r3 != ctx->r2) {
        // 0x800C9CB4: andi        $v0, $a0, 0x1
        ctx->r2 = ctx->r4 & 0X1;
            goto L_800C9CCC;
    }
    // 0x800C9CB4: andi        $v0, $a0, 0x1
    ctx->r2 = ctx->r4 & 0X1;
    // 0x800C9CB8: lw          $a1, 0x78($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X78);
    // 0x800C9CBC: lw          $a2, 0x7C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X7C);
    // 0x800C9CC0: lw          $a3, 0x80($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X80);
    // 0x800C9CC4: j           L_800C9CE0
    // 0x800C9CC8: nop

        goto L_800C9CE0;
    // 0x800C9CC8: nop

L_800C9CCC:
    // 0x800C9CCC: beq         $v0, $zero, L_800C9CE8
    if (ctx->r2 == 0) {
        // 0x800C9CD0: nop
    
            goto L_800C9CE8;
    }
    // 0x800C9CD0: nop

    // 0x800C9CD4: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    // 0x800C9CD8: lw          $a2, 0x54($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X54);
    // 0x800C9CDC: lw          $a3, 0x58($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X58);
L_800C9CE0:
    // 0x800C9CE0: jal         0x8001CA90
    // 0x800C9CE4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    addVec3At0x24(rdram, ctx);
        goto after_64;
    // 0x800C9CE4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_64:
L_800C9CE8:
    // 0x800C9CE8: lw          $v0, 0x44($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X44);
    // 0x800C9CEC: lw          $s0, 0x50($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X50);
    // 0x800C9CF0: addiu       $s2, $v0, 0x1C
    ctx->r18 = ADD32(ctx->r2, 0X1C);
    // 0x800C9CF4: jal         0x8001CA50
    // 0x800C9CF8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    clearVec4QuadStruct(rdram, ctx);
        goto after_65;
    // 0x800C9CF8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_65:
    // 0x800C9CFC: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x800C9D00: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x800C9D04: beq         $v0, $zero, L_800C9D38
    if (ctx->r2 == 0) {
        // 0x800C9D08: nop
    
            goto L_800C9D38;
    }
    // 0x800C9D08: nop

    // 0x800C9D0C: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800C9D10: lwc1        $f2, 0x58($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800C9D14: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800C9D18: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x800C9D1C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800C9D20: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800C9D24: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800C9D28: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800C9D2C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800C9D30: jal         0x8001CA90
    // 0x800C9D34: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    addVec3At0x24(rdram, ctx);
        goto after_66;
    // 0x800C9D34: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_66:
L_800C9D38:
    // 0x800C9D38: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x800C9D3C: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    // 0x800C9D40: beq         $v0, $zero, L_800C9D5C
    if (ctx->r2 == 0) {
        // 0x800C9D44: nop
    
            goto L_800C9D5C;
    }
    // 0x800C9D44: nop

    // 0x800C9D48: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    // 0x800C9D4C: lw          $a2, 0x60($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X60);
    // 0x800C9D50: lw          $a3, 0x64($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X64);
    // 0x800C9D54: jal         0x8001CB04
    // 0x800C9D58: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    applyScaleToMat3x4(rdram, ctx);
        goto after_67;
    // 0x800C9D58: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_67:
L_800C9D5C:
    // 0x800C9D5C: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x800C9D60: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    // 0x800C9D64: beq         $v0, $zero, L_800C9D74
    if (ctx->r2 == 0) {
        // 0x800C9D68: addu        $a0, $s2, $zero
        ctx->r4 = ADD32(ctx->r18, 0);
            goto L_800C9D74;
    }
    // 0x800C9D68: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800C9D6C: jal         0x8001DAEC
    // 0x800C9D70: addiu       $a1, $s0, 0x68
    ctx->r5 = ADD32(ctx->r16, 0X68);
    composeQuatToMat3x4(rdram, ctx);
        goto after_68;
    // 0x800C9D70: addiu       $a1, $s0, 0x68
    ctx->r5 = ADD32(ctx->r16, 0X68);
    after_68:
L_800C9D74:
    // 0x800C9D74: lwc1        $f2, 0x80($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X80);
    // 0x800C9D78: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C9D7C: lwc1        $f0, 0x6B5C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6B5C);
    // 0x800C9D80: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800C9D84: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800C9D88: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800C9D8C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800C9D90: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800C9D94: jal         0x8001CA90
    // 0x800C9D98: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    addVec3At0x24(rdram, ctx);
        goto after_69;
    // 0x800C9D98: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    after_69:
    // 0x800C9D9C: lw          $a0, 0x4C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4C);
    // 0x800C9DA0: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x800C9DA4: andi        $v1, $a0, 0x9
    ctx->r3 = ctx->r4 & 0X9;
    // 0x800C9DA8: bne         $v1, $v0, L_800C9DE8
    if (ctx->r3 != ctx->r2) {
        // 0x800C9DAC: addiu       $v0, $zero, 0x8
        ctx->r2 = ADD32(0, 0X8);
            goto L_800C9DE8;
    }
    // 0x800C9DAC: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800C9DB0: lwc1        $f2, 0x78($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X78);
    // 0x800C9DB4: lwc1        $f0, 0x50($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800C9DB8: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800C9DBC: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800C9DC0: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x800C9DC4: lwc1        $f2, 0x7C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x800C9DC8: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800C9DCC: lwc1        $f0, 0x58($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X58);
    // 0x800C9DD0: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x800C9DD4: lwc1        $f2, 0x80($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X80);
    // 0x800C9DD8: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800C9DDC: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x800C9DE0: j           L_800C9E18
    // 0x800C9DE4: nop

        goto L_800C9E18;
    // 0x800C9DE4: nop

L_800C9DE8:
    // 0x800C9DE8: bne         $v1, $v0, L_800C9E04
    if (ctx->r3 != ctx->r2) {
        // 0x800C9DEC: andi        $v0, $a0, 0x1
        ctx->r2 = ctx->r4 & 0X1;
            goto L_800C9E04;
    }
    // 0x800C9DEC: andi        $v0, $a0, 0x1
    ctx->r2 = ctx->r4 & 0X1;
    // 0x800C9DF0: lw          $a1, 0x78($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X78);
    // 0x800C9DF4: lw          $a2, 0x7C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X7C);
    // 0x800C9DF8: lw          $a3, 0x80($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X80);
    // 0x800C9DFC: j           L_800C9E18
    // 0x800C9E00: nop

        goto L_800C9E18;
    // 0x800C9E00: nop

L_800C9E04:
    // 0x800C9E04: beq         $v0, $zero, L_800C9E20
    if (ctx->r2 == 0) {
        // 0x800C9E08: nop
    
            goto L_800C9E20;
    }
    // 0x800C9E08: nop

    // 0x800C9E0C: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    // 0x800C9E10: lw          $a2, 0x54($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X54);
    // 0x800C9E14: lw          $a3, 0x58($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X58);
L_800C9E18:
    // 0x800C9E18: jal         0x8001CA90
    // 0x800C9E1C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    addVec3At0x24(rdram, ctx);
        goto after_70;
    // 0x800C9E1C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_70:
L_800C9E20:
    // 0x800C9E20: lbu         $v0, 0xD2($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0XD2);
    // 0x800C9E24: beq         $v0, $zero, L_800C9E54
    if (ctx->r2 == 0) {
        // 0x800C9E28: addiu       $s0, $s1, 0x8C
        ctx->r16 = ADD32(ctx->r17, 0X8C);
            goto L_800C9E54;
    }
    // 0x800C9E28: addiu       $s0, $s1, 0x8C
    ctx->r16 = ADD32(ctx->r17, 0X8C);
    // 0x800C9E2C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800C9E30: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800C9E34: addiu       $a2, $s1, 0x24
    ctx->r6 = ADD32(ctx->r17, 0X24);
    // 0x800C9E38: jal         0x800988E8
    // 0x800C9E3C: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    updateActive3DAudioSource(rdram, ctx);
        goto after_71;
    // 0x800C9E3C: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    after_71:
    // 0x800C9E40: jal         0x80098E84
    // 0x800C9E44: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    mostlyMusyxFlagGatedHelper(rdram, ctx);
        goto after_72;
    // 0x800C9E44: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_72:
    // 0x800C9E48: lhu         $a1, 0xD0($s1)
    ctx->r5 = MEM_HU(ctx->r17, 0XD0);
    // 0x800C9E4C: jal         0x80088D1C
    // 0x800C9E50: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    safeLookup3DSoundEntry(rdram, ctx);
        goto after_73;
    // 0x800C9E50: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_73:
L_800C9E54:
    // 0x800C9E54: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x800C9E58: lw          $a1, 0x30($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X30);
    // 0x800C9E5C: lw          $a3, 0x58($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X58);
    // 0x800C9E60: jal         0x80057C8C
    // 0x800C9E64: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    addNpcToVisibilityBucket(rdram, ctx);
        goto after_74;
    // 0x800C9E64: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_74:
    // 0x800C9E68: j           L_800CA150
    // 0x800C9E6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800CA150;
    // 0x800C9E6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800C9E70:
    // 0x800C9E70: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800C9E74: jal         0x800F20EC
    // 0x800C9E78: addu        $s2, $s0, $zero
    ctx->r18 = ADD32(ctx->r16, 0);
    getNpcCurrentHealth(rdram, ctx);
        goto after_75;
    // 0x800C9E78: addu        $s2, $s0, $zero
    ctx->r18 = ADD32(ctx->r16, 0);
    after_75:
    // 0x800C9E7C: blez        $v0, L_800CA018
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800C9E80: nop
    
            goto L_800CA018;
    }
    // 0x800C9E80: nop

    // 0x800C9E84: jal         0x80076250
    // 0x800C9E88: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    extrapolateNpcPositionForCurrentMode(rdram, ctx);
        goto after_76;
    // 0x800C9E88: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_76:
    // 0x800C9E8C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800C9E90: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800C9E94: addiu       $a2, $s1, 0x24
    ctx->r6 = ADD32(ctx->r17, 0X24);
    // 0x800C9E98: lui         $a3, 0x41C0
    ctx->r7 = S32(0X41C0 << 16);
    // 0x800C9E9C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C9EA0: lwc1        $f0, 0x6B60($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6B60);
    // 0x800C9EA4: addiu       $v0, $zero, 0x2A
    ctx->r2 = ADD32(0, 0X2A);
    // 0x800C9EA8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800C9EAC: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x800C9EB0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800C9EB4: addiu       $v0, $zero, 0x50
    ctx->r2 = ADD32(0, 0X50);
    // 0x800C9EB8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800C9EBC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800C9EC0: jal         0x800989D8
    // 0x800C9EC4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    play3DSoundEvent(rdram, ctx);
        goto after_77;
    // 0x800C9EC4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_77:
    // 0x800C9EC8: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800C9ECC: lhu         $a1, 0x6($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X6);
    // 0x800C9ED0: jal         0x800F2120
    // 0x800C9ED4: nop

    dealDamageToNpc(rdram, ctx);
        goto after_78;
    // 0x800C9ED4: nop

    after_78:
    // 0x800C9ED8: bgtz        $v0, L_800CA018
    if (SIGNED(ctx->r2) > 0) {
        // 0x800C9EDC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800CA018;
    }
    // 0x800C9EDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C9EE0: lbu         $v1, 0xD2($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0XD2);
    // 0x800C9EE4: bne         $v1, $v0, L_800C9EFC
    if (ctx->r3 != ctx->r2) {
        // 0x800C9EE8: addiu       $v0, $zero, 0x2
        ctx->r2 = ADD32(0, 0X2);
            goto L_800C9EFC;
    }
    // 0x800C9EE8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800C9EEC: sb          $zero, 0xD2($s1)
    MEM_B(0XD2, ctx->r17) = 0;
    // 0x800C9EF0: jal         0x80098DE0
    // 0x800C9EF4: addiu       $a0, $s1, 0x8C
    ctx->r4 = ADD32(ctx->r17, 0X8C);
    factor5RemoveListNode(rdram, ctx);
        goto after_79;
    // 0x800C9EF4: addiu       $a0, $s1, 0x8C
    ctx->r4 = ADD32(ctx->r17, 0X8C);
    after_79:
    // 0x800C9EF8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_800C9EFC:
    // 0x800C9EFC: sh          $v0, 0x72($s1)
    MEM_H(0X72, ctx->r17) = ctx->r2;
    // 0x800C9F00: jal         0x80003430
    // 0x800C9F04: sw          $zero, 0x84($s1)
    MEM_W(0X84, ctx->r17) = 0;
    rand_recomp(rdram, ctx);
        goto after_80;
    // 0x800C9F04: sw          $zero, 0x84($s1)
    MEM_W(0X84, ctx->r17) = 0;
    after_80:
    // 0x800C9F08: lui         $v1, 0x5555
    ctx->r3 = S32(0X5555 << 16);
    // 0x800C9F0C: ori         $v1, $v1, 0x5556
    ctx->r3 = ctx->r3 | 0X5556;
    // 0x800C9F10: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x800C9F14: sra         $a0, $v0, 16
    ctx->r4 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800C9F18: mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C9F1C: sra         $v0, $v0, 31
    ctx->r2 = S32(SIGNED(ctx->r2) >> 31);
    // 0x800C9F20: mfhi        $t0
    ctx->r8 = hi;
    // 0x800C9F24: subu        $v0, $t0, $v0
    ctx->r2 = SUB32(ctx->r8, ctx->r2);
    // 0x800C9F28: sll         $v1, $v0, 1
    ctx->r3 = S32(ctx->r2 << 1);
    // 0x800C9F2C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C9F30: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x800C9F34: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x800C9F38: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800C9F3C: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x800C9F40: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C9F44: lw          $v1, 0xB70($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB70);
    // 0x800C9F48: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
    // 0x800C9F4C: beq         $v1, $v0, L_800C9F88
    if (ctx->r3 == ctx->r2) {
        // 0x800C9F50: sw          $a0, 0x88($s1)
        MEM_W(0X88, ctx->r17) = ctx->r4;
            goto L_800C9F88;
    }
    // 0x800C9F50: sw          $a0, 0x88($s1)
    MEM_W(0X88, ctx->r17) = ctx->r4;
    // 0x800C9F54: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800C9F58: lui         $a2, 0x3FCC
    ctx->r6 = S32(0X3FCC << 16);
    // 0x800C9F5C: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x800C9F60: lui         $a3, 0x3F33
    ctx->r7 = S32(0X3F33 << 16);
    // 0x800C9F64: ori         $a3, $a3, 0x3333
    ctx->r7 = ctx->r7 | 0X3333;
    // 0x800C9F68: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C9F6C: lwc1        $f0, 0x6B64($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6B64);
    // 0x800C9F70: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C9F74: lwc1        $f2, 0x6B68($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6B68);
    // 0x800C9F78: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    // 0x800C9F7C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800C9F80: jal         0x80073750
    // 0x800C9F84: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    spawnDestructionEffectBurst(rdram, ctx);
        goto after_81;
    // 0x800C9F84: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    after_81:
L_800C9F88:
    // 0x800C9F88: lhu         $a0, 0x66($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X66);
    // 0x800C9F8C: jal         0x8003E7D0
    // 0x800C9F90: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    unregisterAndFreeNpcSlot(rdram, ctx);
        goto after_82;
    // 0x800C9F90: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_82:
    // 0x800C9F94: lhu         $a0, 0x68($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X68);
    // 0x800C9F98: jal         0x8003E7D0
    // 0x800C9F9C: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    unregisterAndFreeNpcSlot(rdram, ctx);
        goto after_83;
    // 0x800C9F9C: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_83:
    // 0x800C9FA0: lhu         $v1, 0x6A($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X6A);
    // 0x800C9FA4: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800C9FA8: beq         $v1, $v0, L_800C9FC0
    if (ctx->r3 == ctx->r2) {
        // 0x800C9FAC: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_800C9FC0;
    }
    // 0x800C9FAC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800C9FB0: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x800C9FB4: jal         0x8003E7D0
    // 0x800C9FB8: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    unregisterAndFreeNpcSlot(rdram, ctx);
        goto after_84;
    // 0x800C9FB8: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_84:
    // 0x800C9FBC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
L_800C9FC0:
    // 0x800C9FC0: lhu         $a0, -0x6A8C($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A8C);
    // 0x800C9FC4: jal         0x8003E684
    // 0x800C9FC8: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    popNpcSlotFromTail(rdram, ctx);
        goto after_85;
    // 0x800C9FC8: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_85:
    // 0x800C9FCC: lw          $v1, 0x34($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X34);
    // 0x800C9FD0: lw          $v0, 0x80($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X80);
    // 0x800C9FD4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800C9FD8: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x800C9FDC: lw          $v0, 0x84($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X84);
    // 0x800C9FE0: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x800C9FE4: lw          $a0, 0x78($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X78);
    // 0x800C9FE8: lw          $a1, 0x7C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X7C);
    // 0x800C9FEC: lw          $a2, 0x70($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X70);
    // 0x800C9FF0: lw          $a3, 0x74($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X74);
    // 0x800C9FF4: jal         0x80065914
    // 0x800C9FF8: nop

    datItemSetObjectiveBooleanCount(rdram, ctx);
        goto after_86;
    // 0x800C9FF8: nop

    after_86:
    // 0x800C9FFC: jal         0x800F3260
    // 0x800CA000: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    tallyMidDetailObject(rdram, ctx);
        goto after_87;
    // 0x800CA000: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    after_87:
    // 0x800CA004: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800CA008: jal         0x800F2A24
    // 0x800CA00C: nop

    clearPendingChildNpc(rdram, ctx);
        goto after_88;
    // 0x800CA00C: nop

    after_88:
    // 0x800CA010: jal         0x800F2AA4
    // 0x800CA014: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    setObjectFlagBit4(rdram, ctx);
        goto after_89;
    // 0x800CA014: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    after_89:
L_800CA018:
    // 0x800CA018: lhu         $v1, 0x0($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X0);
    // 0x800CA01C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800CA020: beq         $v1, $v0, L_800CA150
    if (ctx->r3 == ctx->r2) {
        // 0x800CA024: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800CA150;
    }
    // 0x800CA024: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800CA028: jal         0x8003ED74
    // 0x800CA02C: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    destroyNpcSlotByIndex(rdram, ctx);
        goto after_90;
    // 0x800CA02C: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    after_90:
    // 0x800CA030: j           L_800CA150
    // 0x800CA034: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800CA150;
    // 0x800CA034: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800CA038:
    // 0x800CA038: lbu         $v1, 0x18($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X18);
    // 0x800CA03C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800CA040: bne         $v1, $v0, L_800CA124
    if (ctx->r3 != ctx->r2) {
        // 0x800CA044: addu        $s4, $s0, $zero
        ctx->r20 = ADD32(ctx->r16, 0);
            goto L_800CA124;
    }
    // 0x800CA044: addu        $s4, $s0, $zero
    ctx->r20 = ADD32(ctx->r16, 0);
    // 0x800CA048: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800CA04C: jal         0x800F20EC
    // 0x800CA050: nop

    getNpcCurrentHealth(rdram, ctx);
        goto after_91;
    // 0x800CA050: nop

    after_91:
    // 0x800CA054: blez        $v0, L_800CA128
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800CA058: addu        $a0, $s5, $zero
        ctx->r4 = ADD32(ctx->r21, 0);
            goto L_800CA128;
    }
    // 0x800CA058: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    // 0x800CA05C: lhu         $a0, 0x66($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X66);
    // 0x800CA060: jal         0x8003E7D0
    // 0x800CA064: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    unregisterAndFreeNpcSlot(rdram, ctx);
        goto after_92;
    // 0x800CA064: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_92:
    // 0x800CA068: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800CA06C: addiu       $s3, $v0, -0x6AA0
    ctx->r19 = ADD32(ctx->r2, -0X6AA0);
    // 0x800CA070: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800CA074: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800CA078: bne         $v0, $s2, L_800CA084
    if (ctx->r2 != ctx->r18) {
        // 0x800CA07C: addiu       $v1, $zero, 0x2C
        ctx->r3 = ADD32(0, 0X2C);
            goto L_800CA084;
    }
    // 0x800CA07C: addiu       $v1, $zero, 0x2C
    ctx->r3 = ADD32(0, 0X2C);
    // 0x800CA080: addiu       $v1, $zero, 0x2E
    ctx->r3 = ADD32(0, 0X2E);
L_800CA084:
    // 0x800CA084: addu        $v0, $v1, $s3
    ctx->r2 = ADD32(ctx->r3, ctx->r19);
    // 0x800CA088: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x800CA08C: jal         0x8003E684
    // 0x800CA090: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    popNpcSlotFromTail(rdram, ctx);
        goto after_93;
    // 0x800CA090: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_93:
    // 0x800CA094: lhu         $a0, 0x68($s1)
    ctx->r4 = MEM_HU(ctx->r17, 0X68);
    // 0x800CA098: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    // 0x800CA09C: jal         0x8003E7D0
    // 0x800CA0A0: sh          $v0, 0x66($s1)
    MEM_H(0X66, ctx->r17) = ctx->r2;
    unregisterAndFreeNpcSlot(rdram, ctx);
        goto after_94;
    // 0x800CA0A0: sh          $v0, 0x66($s1)
    MEM_H(0X66, ctx->r17) = ctx->r2;
    after_94:
    // 0x800CA0A4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800CA0A8: bne         $v0, $s2, L_800CA0B4
    if (ctx->r2 != ctx->r18) {
        // 0x800CA0AC: addiu       $v1, $zero, 0x12
        ctx->r3 = ADD32(0, 0X12);
            goto L_800CA0B4;
    }
    // 0x800CA0AC: addiu       $v1, $zero, 0x12
    ctx->r3 = ADD32(0, 0X12);
    // 0x800CA0B0: addiu       $v1, $zero, 0xE
    ctx->r3 = ADD32(0, 0XE);
L_800CA0B4:
    // 0x800CA0B4: addu        $v0, $v1, $s3
    ctx->r2 = ADD32(ctx->r3, ctx->r19);
    // 0x800CA0B8: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x800CA0BC: jal         0x8003E684
    // 0x800CA0C0: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    popNpcSlotFromTail(rdram, ctx);
        goto after_95;
    // 0x800CA0C0: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_95:
    // 0x800CA0C4: lhu         $v1, 0x6A($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X6A);
    // 0x800CA0C8: sh          $v0, 0x68($s1)
    MEM_H(0X68, ctx->r17) = ctx->r2;
    // 0x800CA0CC: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x800CA0D0: beq         $v1, $v0, L_800CA114
    if (ctx->r3 == ctx->r2) {
        // 0x800CA0D4: addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
            goto L_800CA114;
    }
    // 0x800CA0D4: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x800CA0D8: jal         0x8003E7D0
    // 0x800CA0DC: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    unregisterAndFreeNpcSlot(rdram, ctx);
        goto after_96;
    // 0x800CA0DC: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_96:
    // 0x800CA0E0: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x800CA0E4: lw          $v0, 0x90($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X90);
    // 0x800CA0E8: beq         $v0, $zero, L_800CA114
    if (ctx->r2 == 0) {
        // 0x800CA0EC: nop
    
            goto L_800CA114;
    }
    // 0x800CA0EC: nop

    // 0x800CA0F0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800CA0F4: bne         $v0, $s2, L_800CA100
    if (ctx->r2 != ctx->r18) {
        // 0x800CA0F8: addiu       $v1, $zero, 0x18
        ctx->r3 = ADD32(0, 0X18);
            goto L_800CA100;
    }
    // 0x800CA0F8: addiu       $v1, $zero, 0x18
    ctx->r3 = ADD32(0, 0X18);
    // 0x800CA0FC: addiu       $v1, $zero, 0x1A
    ctx->r3 = ADD32(0, 0X1A);
L_800CA100:
    // 0x800CA100: addu        $v0, $v1, $s3
    ctx->r2 = ADD32(ctx->r3, ctx->r19);
    // 0x800CA104: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x800CA108: jal         0x8003E684
    // 0x800CA10C: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    popNpcSlotFromTail(rdram, ctx);
        goto after_97;
    // 0x800CA10C: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_97:
    // 0x800CA110: sh          $v0, 0x6A($s1)
    MEM_H(0X6A, ctx->r17) = ctx->r2;
L_800CA114:
    // 0x800CA114: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800CA118: lw          $a1, 0x0($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X0);
    // 0x800CA11C: jal         0x800F2830
    // 0x800CA120: nop

    setObjectDetailLevel(rdram, ctx);
        goto after_98;
    // 0x800CA120: nop

    after_98:
L_800CA124:
    // 0x800CA124: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
L_800CA128:
    // 0x800CA128: jal         0x800EFD80
    // 0x800CA12C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    dispatchSlotAction5IfActive(rdram, ctx);
        goto after_99;
    // 0x800CA12C: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_99:
    // 0x800CA130: j           L_800CA150
    // 0x800CA134: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800CA150;
    // 0x800CA134: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800CA138:
    // 0x800CA138: lw          $v0, 0x34($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X34);
    // 0x800CA13C: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x800CA140: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800CA144: j           L_800CA150
    // 0x800CA148: sh          $v1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r3;
        goto L_800CA150;
    // 0x800CA148: sh          $v1, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r3;
L_800CA14C:
    // 0x800CA14C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800CA150:
    // 0x800CA150: lw          $ra, 0x80($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X80);
    // 0x800CA154: lw          $s5, 0x7C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X7C);
    // 0x800CA158: lw          $s4, 0x78($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X78);
    // 0x800CA15C: lw          $s3, 0x74($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X74);
    // 0x800CA160: lw          $s2, 0x70($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X70);
    // 0x800CA164: lw          $s1, 0x6C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X6C);
    // 0x800CA168: lw          $s0, 0x68($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X68);
    // 0x800CA16C: ldc1        $f30, 0xB0($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0XB0);
    // 0x800CA170: ldc1        $f28, 0xA8($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0XA8);
    // 0x800CA174: ldc1        $f26, 0xA0($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0XA0);
    // 0x800CA178: ldc1        $f24, 0x98($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X98);
    // 0x800CA17C: ldc1        $f22, 0x90($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X90);
    // 0x800CA180: ldc1        $f20, 0x88($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X88);
    // 0x800CA184: jr          $ra
    // 0x800CA188: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x800CA188: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void func_800C9A88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9A88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C9A8C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800C9A90: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800C9A94: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x800C9A98: addiu       $s2, $zero, 0x580
    ctx->r18 = ADD32(0, 0X580);
    // 0x800C9A9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C9AA0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800C9AA4: lhu         $a1, 0xE($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0XE);
    // 0x800C9AA8: jal         0x80001ACC
    // 0x800C9AAC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x800C9AAC: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_0:
    // 0x800C9AB0: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    // 0x800C9AB4: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    // 0x800C9AB8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800C9ABC: jal         0x800078E0
    // 0x800C9AC0: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    rs_memset(rdram, ctx);
        goto after_1;
    // 0x800C9AC0: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    after_1:
    // 0x800C9AC4: addiu       $a0, $s1, 0x100
    ctx->r4 = ADD32(ctx->r17, 0X100);
    // 0x800C9AC8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800C9ACC: sw          $a0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r4;
L_800C9AD0:
    // 0x800C9AD0: lw          $v0, 0x50($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X50);
    // 0x800C9AD4: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800C9AD8: sb          $a1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r5;
    // 0x800C9ADC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800C9AE0: slti        $v0, $a1, 0x100
    ctx->r2 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
    // 0x800C9AE4: bne         $v0, $zero, L_800C9AD0
    if (ctx->r2 != 0) {
        // 0x800C9AE8: addiu       $v1, $zero, 0xFF
        ctx->r3 = ADD32(0, 0XFF);
            goto L_800C9AD0;
    }
    // 0x800C9AE8: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x800C9AEC: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    // 0x800C9AF0: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x800C9AF4: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
L_800C9AF8:
    // 0x800C9AF8: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x800C9AFC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800C9B00: slti        $v0, $a1, 0x200
    ctx->r2 = SIGNED(ctx->r5) < 0X200 ? 1 : 0;
    // 0x800C9B04: bne         $v0, $zero, L_800C9AF8
    if (ctx->r2 != 0) {
        // 0x800C9B08: addu        $v0, $a0, $a1
        ctx->r2 = ADD32(ctx->r4, ctx->r5);
            goto L_800C9AF8;
    }
    // 0x800C9B08: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x800C9B0C: addiu       $a0, $a0, 0x380
    ctx->r4 = ADD32(ctx->r4, 0X380);
    // 0x800C9B10: lw          $a1, 0x50($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X50);
    // 0x800C9B14: jal         0x80018EF4
    // 0x800C9B18: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    zmemcpy(rdram, ctx);
        goto after_2;
    // 0x800C9B18: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    after_2:
    // 0x800C9B1C: lhu         $a1, 0xE($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0XE);
    // 0x800C9B20: jal         0x80001ACC
    // 0x800C9B24: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    rs_malloc(rdram, ctx);
        goto after_3;
    // 0x800C9B24: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_3:
    // 0x800C9B28: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800C9B2C: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x800C9B30: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x800C9B34: jal         0x80018EF4
    // 0x800C9B38: sw          $a0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r4;
    zmemcpy(rdram, ctx);
        goto after_4;
    // 0x800C9B38: sw          $a0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r4;
    after_4:
    // 0x800C9B3C: beq         $s2, $zero, L_800C9B68
    if (ctx->r18 == 0) {
        // 0x800C9B40: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_800C9B68;
    }
    // 0x800C9B40: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
L_800C9B44:
    // 0x800C9B44: lw          $v0, 0x54($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X54);
    // 0x800C9B48: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x800C9B4C: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x800C9B50: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800C9B54: srl         $v1, $v1, 3
    ctx->r3 = S32(U32(ctx->r3) >> 3);
    // 0x800C9B58: sb          $v1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r3;
    // 0x800C9B5C: slt         $v0, $a1, $s2
    ctx->r2 = SIGNED(ctx->r5) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x800C9B60: bne         $v0, $zero, L_800C9B44
    if (ctx->r2 != 0) {
        // 0x800C9B64: nop
    
            goto L_800C9B44;
    }
    // 0x800C9B64: nop

L_800C9B68:
    // 0x800C9B68: lw          $v0, 0x54($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X54);
    // 0x800C9B6C: addiu       $v0, $v0, 0x100
    ctx->r2 = ADD32(ctx->r2, 0X100);
    // 0x800C9B70: sw          $v0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r2;
    // 0x800C9B74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9B78: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x800C9B7C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x800C9B80: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800C9B84: jr          $ra
    // 0x800C9B88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C9B88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_800C9B8C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9B8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C9B90: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800C9B94: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x800C9B98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9B9C: lhu         $a1, 0xE($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0XE);
    // 0x800C9BA0: jal         0x80001ACC
    // 0x800C9BA4: addiu       $a0, $zero, 0x800
    ctx->r4 = ADD32(0, 0X800);
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x800C9BA4: addiu       $a0, $zero, 0x800
    ctx->r4 = ADD32(0, 0X800);
    after_0:
    // 0x800C9BA8: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800C9BAC: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800C9BB0: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
L_800C9BB4:
    // 0x800C9BB4: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800C9BB8: addu        $v1, $s0, $v1
    ctx->r3 = ADD32(ctx->r16, ctx->r3);
    // 0x800C9BBC: sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2 << 7);
    // 0x800C9BC0: addu        $v0, $a1, $v0
    ctx->r2 = ADD32(ctx->r5, ctx->r2);
    // 0x800C9BC4: sw          $v0, 0x77C($v1)
    MEM_W(0X77C, ctx->r3) = ctx->r2;
    // 0x800C9BC8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800C9BCC: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x800C9BD0: sltiu       $v0, $v0, 0x10
    ctx->r2 = ctx->r2 < 0X10 ? 1 : 0;
    // 0x800C9BD4: bnel        $v0, $zero, L_800C9BB4
    if (ctx->r2 != 0) {
        // 0x800C9BD8: andi        $v0, $a0, 0xFF
        ctx->r2 = ctx->r4 & 0XFF;
            goto L_800C9BB4;
    }
    goto skip_0;
    // 0x800C9BD8: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    skip_0:
    // 0x800C9BDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C9BE0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x800C9BE4: jr          $ra
    // 0x800C9BE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C9BE8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_800C9BF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9BF0: addiu       $sp, $sp, -0x138
    ctx->r29 = ADD32(ctx->r29, -0X138);
    // 0x800C9BF4: sw          $ra, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r31;
    // 0x800C9BF8: sw          $fp, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r30;
    // 0x800C9BFC: sw          $s7, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r23;
    // 0x800C9C00: sw          $s6, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r22;
    // 0x800C9C04: sw          $s5, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r21;
    // 0x800C9C08: sw          $s4, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r20;
    // 0x800C9C0C: sw          $s3, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r19;
    // 0x800C9C10: sw          $s2, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r18;
    // 0x800C9C14: sw          $s1, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r17;
    // 0x800C9C18: sw          $s0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r16;
    // 0x800C9C1C: sdc1        $f30, 0x130($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X130, ctx->r29);
    // 0x800C9C20: sdc1        $f28, 0x128($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X128, ctx->r29);
    // 0x800C9C24: sdc1        $f26, 0x120($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X120, ctx->r29);
    // 0x800C9C28: sdc1        $f24, 0x118($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X118, ctx->r29);
    // 0x800C9C2C: sdc1        $f22, 0x110($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X110, ctx->r29);
    // 0x800C9C30: sdc1        $f20, 0x108($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X108, ctx->r29);
    // 0x800C9C34: sb          $a0, 0xA0($sp)
    MEM_B(0XA0, ctx->r29) = ctx->r4;
    // 0x800C9C38: jal         0x800CA638
    // 0x800C9C3C: sb          $a1, 0xAF($sp)
    MEM_B(0XAF, ctx->r29) = ctx->r5;
    func_800CA638(rdram, ctx);
        goto after_0;
    // 0x800C9C3C: sb          $a1, 0xAF($sp)
    MEM_B(0XAF, ctx->r29) = ctx->r5;
    after_0:
    // 0x800C9C40: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x800C9C44: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800C9C48: lbu         $s0, 0xAF($sp)
    ctx->r16 = MEM_BU(ctx->r29, 0XAF);
    // 0x800C9C4C: addiu       $a1, $a1, 0x78F8
    ctx->r5 = ADD32(ctx->r5, 0X78F8);
    // 0x800C9C50: jal         0x80033CC4
    // 0x800C9C54: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    sprintf_recomp(rdram, ctx);
        goto after_1;
    // 0x800C9C54: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_1:
    // 0x800C9C58: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x800C9C5C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800C9C60: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    // 0x800C9C64: addu        $v0, $sp, $a2
    ctx->r2 = ADD32(ctx->r29, ctx->r6);
    // 0x800C9C68: addu        $s7, $v0, $zero
    ctx->r23 = ADD32(ctx->r2, 0);
    // 0x800C9C6C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x800C9C70: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C9C74: lwc1        $f6, 0x7930($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7930);
    // 0x800C9C78: lw          $v0, -0x76E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X76E0);
    // 0x800C9C7C: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x800C9C80: swc1        $f6, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f6.u32l;
    // 0x800C9C84: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C9C88: lwc1        $f6, 0x7934($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7934);
    // 0x800C9C8C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800C9C90: swc1        $f6, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f6.u32l;
    // 0x800C9C94: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C9C98: lwc1        $f6, 0x7938($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7938);
    // 0x800C9C9C: lui         $s6, 0x800D
    ctx->r22 = S32(0X800D << 16);
    // 0x800C9CA0: swc1        $f6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f6.u32l;
    // 0x800C9CA4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C9CA8: lwc1        $f6, 0x793C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X793C);
    // 0x800C9CAC: addiu       $fp, $sp, 0x5C
    ctx->r30 = ADD32(ctx->r29, 0X5C);
    // 0x800C9CB0: sb          $t0, 0xB7($sp)
    MEM_B(0XB7, ctx->r29) = ctx->r8;
    // 0x800C9CB4: sw          $zero, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = 0;
    // 0x800C9CB8: sb          $zero, 0xB9($sp)
    MEM_B(0XB9, ctx->r29) = 0;
    // 0x800C9CBC: sb          $zero, 0xBA($sp)
    MEM_B(0XBA, ctx->r29) = 0;
    // 0x800C9CC0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800C9CC4: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x800C9CC8: jal         0x800B3AFC
    // 0x800C9CCC: swc1        $f6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f6.u32l;
    func_800B3AFC(rdram, ctx);
        goto after_2;
    // 0x800C9CCC: swc1        $f6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x800C9CD0: sw          $v0, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r2;
    // 0x800C9CD4: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x800C9CD8: addiu       $a1, $zero, -0x140
    ctx->r5 = ADD32(0, -0X140);
    // 0x800C9CDC: jal         0x800B3CD4
    // 0x800C9CE0: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    setChildPosFromI16Pair(rdram, ctx);
        goto after_3;
    // 0x800C9CE0: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    after_3:
    // 0x800C9CE4: lw          $a0, 0xDC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XDC);
    // 0x800C9CE8: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x800C9CEC: jal         0x800B3D08
    // 0x800C9CF0: mov.s       $f30, $f26
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    ctx->f30.fl = ctx->f26.fl;
    getStructField0xC(rdram, ctx);
        goto after_4;
    // 0x800C9CF0: mov.s       $f30, $f26
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 26);
    ctx->f30.fl = ctx->f26.fl;
    after_4:
    // 0x800C9CF4: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800C9CF8: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x800C9CFC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800C9D00: lw          $a0, 0x360($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X360);
    // 0x800C9D04: swc1        $f26, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f26.u32l;
    // 0x800C9D08: jal         0x800642A0
    // 0x800C9D0C: swc1        $f26, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f26.u32l;
    findLookupEntryByKey(rdram, ctx);
        goto after_5;
    // 0x800C9D0C: swc1        $f26, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f26.u32l;
    after_5:
    // 0x800C9D10: jal         0x80056350
    // 0x800C9D14: nop

    initNpcBookkeepingTables(rdram, ctx);
        goto after_6;
    // 0x800C9D14: nop

    after_6:
    // 0x800C9D18: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800C9D1C: addiu       $a0, $a0, 0x7904
    ctx->r4 = ADD32(ctx->r4, 0X7904);
    // 0x800C9D20: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800C9D24: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x800C9D28: jal         0x8005645C
    // 0x800C9D2C: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    load_hmt_and_hob(rdram, ctx);
        goto after_7;
    // 0x800C9D2C: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    after_7:
    // 0x800C9D30: jal         0x800CB9BC
    // 0x800C9D34: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    selectPostCrawlCraft(rdram, ctx);
        goto after_8;
    // 0x800C9D34: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_8:
    // 0x800C9D38: jal         0x800CB604
    // 0x800C9D3C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800CB604(rdram, ctx);
        goto after_9;
    // 0x800C9D3C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_9:
    // 0x800C9D40: jal         0x800CADB8
    // 0x800C9D44: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800CADB8(rdram, ctx);
        goto after_10;
    // 0x800C9D44: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_10:
    // 0x800C9D48: jal         0x80054A18
    // 0x800C9D4C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    func_80054A18(rdram, ctx);
        goto after_11;
    // 0x800C9D4C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_11:
    // 0x800C9D50: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800C9D54: jal         0x800543F4
    // 0x800C9D58: addiu       $a0, $a0, 0x7920
    ctx->r4 = ADD32(ctx->r4, 0X7920);
    load_full_header_image(rdram, ctx);
        goto after_12;
    // 0x800C9D58: addiu       $a0, $a0, 0x7920
    ctx->r4 = ADD32(ctx->r4, 0X7920);
    after_12:
    // 0x800C9D5C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800C9D60: jal         0x800CA714
    // 0x800C9D64: addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    func_800CA714(rdram, ctx);
        goto after_13;
    // 0x800C9D64: addu        $a1, $s7, $zero
    ctx->r5 = ADD32(ctx->r23, 0);
    after_13:
    // 0x800C9D68: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800C9D6C: addiu       $s5, $v0, 0xB0
    ctx->r21 = ADD32(ctx->r2, 0XB0);
    // 0x800C9D70: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C9D74: lwc1        $f2, 0x7940($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7940);
    // 0x800C9D78: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C9D7C: lwc1        $f4, 0x7944($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7944);
    // 0x800C9D80: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C9D84: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800C9D88: swc1        $f0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f0.u32l;
L_800C9D8C:
    // 0x800C9D8C: jal         0x800C6660
    // 0x800C9D90: nop

    func_800C6660(rdram, ctx);
        goto after_14;
    // 0x800C9D90: nop

    after_14:
    // 0x800C9D94: jal         0x80002FF4
    // 0x800C9D98: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    pollControllerInputs(rdram, ctx);
        goto after_15;
    // 0x800C9D98: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    after_15:
    // 0x800C9D9C: jal         0x80079CE0
    // 0x800C9DA0: nop

    setNewAndPreviousButtonsPressed(rdram, ctx);
        goto after_16;
    // 0x800C9DA0: nop

    after_16:
    // 0x800C9DA4: jal         0x8000A86C
    // 0x800C9DA8: sb          $zero, 0xB8($sp)
    MEM_B(0XB8, ctx->r29) = 0;
    waitForPrevFrameDone(rdram, ctx);
        goto after_17;
    // 0x800C9DA8: sb          $zero, 0xB8($sp)
    MEM_B(0XB8, ctx->r29) = 0;
    after_17:
    // 0x800C9DAC: jal         0x8000A6CC
    // 0x800C9DB0: nop

    frameStartReset(rdram, ctx);
        goto after_18;
    // 0x800C9DB0: nop

    after_18:
    // 0x800C9DB4: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800C9DB8: lwc1        $f6, 0xD4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800C9DBC: lw          $a0, 0x360($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X360);
    // 0x800C9DC0: add.s       $f6, $f6, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f24.fl;
    // 0x800C9DC4: sw          $zero, 0x370($s6)
    MEM_W(0X370, ctx->r22) = 0;
    // 0x800C9DC8: jal         0x80064488
    // 0x800C9DCC: swc1        $f6, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f6.u32l;
    func_80064488(rdram, ctx);
        goto after_19;
    // 0x800C9DCC: swc1        $f6, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f6.u32l;
    after_19:
    // 0x800C9DD0: mov.s       $f12, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 26);
    ctx->f12.fl = ctx->f26.fl;
    // 0x800C9DD4: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800C9DD8: addiu       $t0, $t0, 0x370
    ctx->r8 = ADD32(ctx->r8, 0X370);
    // 0x800C9DDC: jal         0x800CBCF4
    // 0x800C9DE0: sw          $v0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r2;
    func_800CBCF4(rdram, ctx);
        goto after_20;
    // 0x800C9DE0: sw          $v0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r2;
    after_20:
    // 0x800C9DE4: mov.s       $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    ctx->f12.fl = ctx->f24.fl;
    // 0x800C9DE8: lbu         $a2, 0xAF($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0XAF);
    // 0x800C9DEC: jal         0x800CB30C
    // 0x800C9DF0: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    func_800CB30C(rdram, ctx);
        goto after_21;
    // 0x800C9DF0: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    after_21:
    // 0x800C9DF4: lw          $v1, 0x4($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X4);
    // 0x800C9DF8: lw          $v0, 0x370($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X370);
    // 0x800C9DFC: beq         $v0, $zero, L_800C9E14
    if (ctx->r2 == 0) {
        // 0x800C9E00: sw          $v0, 0xC($v1)
        MEM_W(0XC, ctx->r3) = ctx->r2;
            goto L_800C9E14;
    }
    // 0x800C9E00: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x800C9E04: lw          $v0, 0x4($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X4);
    // 0x800C9E08: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800C9E0C: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800C9E10: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_800C9E14:
    // 0x800C9E14: lw          $v0, 0x4($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X4);
    // 0x800C9E18: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x800C9E1C: lw          $v0, 0x4($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X4);
    // 0x800C9E20: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800C9E24: sw          $v0, 0x370($s6)
    MEM_W(0X370, ctx->r22) = ctx->r2;
    // 0x800C9E28: jal         0x80017AB0
    // 0x800C9E2C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_80017AB0(rdram, ctx);
        goto after_22;
    // 0x800C9E2C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_22:
    // 0x800C9E30: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800C9E34: addiu       $a0, $a0, 0x370
    ctx->r4 = ADD32(ctx->r4, 0X370);
    // 0x800C9E38: jal         0x80016C44
    // 0x800C9E3C: nop

    setupCameraMatrices(rdram, ctx);
        goto after_23;
    // 0x800C9E3C: nop

    after_23:
    // 0x800C9E40: jal         0x8000B654
    // 0x800C9E44: nop

    initRenderStateArrays(rdram, ctx);
        goto after_24;
    // 0x800C9E44: nop

    after_24:
    // 0x800C9E48: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800C9E4C: lw          $a0, 0x364($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X364);
    // 0x800C9E50: jal         0x80064488
    // 0x800C9E54: sw          $zero, 0x370($s6)
    MEM_W(0X370, ctx->r22) = 0;
    func_80064488(rdram, ctx);
        goto after_25;
    // 0x800C9E54: sw          $zero, 0x370($s6)
    MEM_W(0X370, ctx->r22) = 0;
    after_25:
    // 0x800C9E58: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800C9E5C: addiu       $t0, $t0, 0x370
    ctx->r8 = ADD32(ctx->r8, 0X370);
    // 0x800C9E60: sw          $v0, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r2;
    // 0x800C9E64: lbu         $v1, 0xBA($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0XBA);
    // 0x800C9E68: sltiu       $v0, $v1, 0x5
    ctx->r2 = ctx->r3 < 0X5 ? 1 : 0;
    // 0x800C9E6C: beq         $v0, $zero, L_800CA348
    if (ctx->r2 == 0) {
        // 0x800C9E70: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_800CA348;
    }
    // 0x800C9E70: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800C9E74: addiu       $v0, $v0, 0x7948
    ctx->r2 = ADD32(ctx->r2, 0X7948);
    // 0x800C9E78: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800C9E7C: addu        $v1, $v1, $v0
    gpr jr_addend_800C9E84 = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800C9E80: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x800C9E84: jr          $v0
    // 0x800C9E88: nop

    switch (jr_addend_800C9E84 >> 2) {
        case 0: goto L_800C9E8C; break;
        case 1: goto L_800C9EEC; break;
        case 2: goto L_800C9F7C; break;
        case 3: goto L_800CA044; break;
        case 4: goto L_800CA11C; break;
        default: switch_error(__func__, 0x800C9E84, 0x800A7948);
    }
    // 0x800C9E88: nop

L_800C9E8C:
    // 0x800C9E8C: lui         $a1, 0x3F19
    ctx->r5 = S32(0X3F19 << 16);
    // 0x800C9E90: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x800C9E94: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x800C9E98: lui         $a3, 0x4086
    ctx->r7 = S32(0X4086 << 16);
    // 0x800C9E9C: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x800C9EA0: jal         0x8001CAC4
    // 0x800C9EA4: addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    setVec3At0x24(rdram, ctx);
        goto after_26;
    // 0x800C9EA4: addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    after_26:
    // 0x800C9EA8: lui         $a1, 0xC290
    ctx->r5 = S32(0XC290 << 16);
    // 0x800C9EAC: jal         0x8001CB9C
    // 0x800C9EB0: addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    composeRotationMatrixSlot0(rdram, ctx);
        goto after_27;
    // 0x800C9EB0: addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    after_27:
    // 0x800C9EB4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800C9EB8: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x800C9EBC: lui         $a2, 0xBDF5
    ctx->r6 = S32(0XBDF5 << 16);
    // 0x800C9EC0: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x800C9EC4: jal         0x8001CA90
    // 0x800C9EC8: addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    addVec3At0x24(rdram, ctx);
        goto after_28;
    // 0x800C9EC8: addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    after_28:
    // 0x800C9ECC: lw          $v0, 0x370($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X370);
    // 0x800C9ED0: beq         $v0, $zero, L_800C9EDC
    if (ctx->r2 == 0) {
        // 0x800C9ED4: sw          $v0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r2;
            goto L_800C9EDC;
    }
    // 0x800C9ED4: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x800C9ED8: sw          $s7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r23;
L_800C9EDC:
    // 0x800C9EDC: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x800C9EE0: sw          $s7, 0x370($s6)
    MEM_W(0X370, ctx->r22) = ctx->r23;
    // 0x800C9EE4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800C9EE8: sb          $t0, 0xBA($sp)
    MEM_B(0XBA, ctx->r29) = ctx->r8;
L_800C9EEC:
    // 0x800C9EEC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C9EF0: lwc1        $f0, 0x795C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X795C);
    // 0x800C9EF4: mul.s       $f0, $f24, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x800C9EF8: lwc1        $f6, 0xC4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x800C9EFC: add.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800C9F00: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C9F04: lwc1        $f0, 0x7960($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7960);
    // 0x800C9F08: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800C9F0C: nop

    // 0x800C9F10: bc1f        L_800C9F3C
    if (!c1cs) {
        // 0x800C9F14: swc1        $f6, 0xC4($sp)
        MEM_W(0XC4, ctx->r29) = ctx->f6.u32l;
            goto L_800C9F3C;
    }
    // 0x800C9F14: swc1        $f6, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f6.u32l;
    // 0x800C9F18: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C9F1C: lwc1        $f6, 0x7964($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7964);
    // 0x800C9F20: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800C9F24: sb          $zero, 0xB7($sp)
    MEM_B(0XB7, ctx->r29) = 0;
    // 0x800C9F28: sb          $t0, 0xBA($sp)
    MEM_B(0XBA, ctx->r29) = ctx->r8;
    // 0x800C9F2C: swc1        $f6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f6.u32l;
    // 0x800C9F30: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C9F34: lwc1        $f6, 0x7968($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7968);
    // 0x800C9F38: swc1        $f6, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f6.u32l;
L_800C9F3C:
    // 0x800C9F3C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C9F40: lwc1        $f0, 0x796C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X796C);
    // 0x800C9F44: lwc1        $f6, 0xC4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x800C9F48: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800C9F4C: nop

    // 0x800C9F50: bc1f        L_800CA348
    if (!c1cs) {
        // 0x800C9F54: nop
    
            goto L_800CA348;
    }
    // 0x800C9F54: nop

    // 0x800C9F58: lwc1        $f6, 0xD0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x800C9F5C: mul.s       $f0, $f24, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f24.fl, ctx->f6.fl);
    // 0x800C9F60: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C9F64: lwc1        $f2, 0x7970($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7970);
    // 0x800C9F68: lwc1        $f6, 0xC0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x800C9F6C: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800C9F70: sub.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800C9F74: j           L_800C9FE8
    // 0x800C9F78: swc1        $f6, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f6.u32l;
        goto L_800C9FE8;
    // 0x800C9F78: swc1        $f6, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f6.u32l;
L_800C9F7C:
    // 0x800C9F7C: lwc1        $f6, 0xD0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x800C9F80: mul.s       $f0, $f24, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f24.fl, ctx->f6.fl);
    // 0x800C9F84: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C9F88: lwc1        $f2, 0x7974($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7974);
    // 0x800C9F8C: lwc1        $f6, 0xD4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x800C9F90: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C9F94: lwc1        $f4, 0x7978($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7978);
    // 0x800C9F98: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x800C9F9C: lwc1        $f6, 0xC0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x800C9FA0: div.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800C9FA4: sub.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800C9FA8: bc1f        L_800C9FE8
    if (!c1cs) {
        // 0x800C9FAC: swc1        $f6, 0xC0($sp)
        MEM_W(0XC0, ctx->r29) = ctx->f6.u32l;
            goto L_800C9FE8;
    }
    // 0x800C9FAC: swc1        $f6, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f6.u32l;
    // 0x800C9FB0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C9FB4: lwc1        $f0, 0x797C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X797C);
    // 0x800C9FB8: mul.s       $f0, $f24, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x800C9FBC: lwc1        $f6, 0xCC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800C9FC0: add.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800C9FC4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800C9FC8: lwc1        $f0, 0x7980($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7980);
    // 0x800C9FCC: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x800C9FD0: nop

    // 0x800C9FD4: bc1f        L_800C9FE8
    if (!c1cs) {
        // 0x800C9FD8: swc1        $f6, 0xCC($sp)
        MEM_W(0XCC, ctx->r29) = ctx->f6.u32l;
            goto L_800C9FE8;
    }
    // 0x800C9FD8: swc1        $f6, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f6.u32l;
    // 0x800C9FDC: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x800C9FE0: j           L_800CA348
    // 0x800C9FE4: sb          $t0, 0xBA($sp)
    MEM_B(0XBA, ctx->r29) = ctx->r8;
        goto L_800CA348;
    // 0x800C9FE4: sb          $t0, 0xBA($sp)
    MEM_B(0XBA, ctx->r29) = ctx->r8;
L_800C9FE8:
    // 0x800C9FE8: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x800C9FEC: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x800C9FF0: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x800C9FF4: lui         $a3, 0x4086
    ctx->r7 = S32(0X4086 << 16);
    // 0x800C9FF8: ori         $a3, $a3, 0x6666
    ctx->r7 = ctx->r7 | 0X6666;
    // 0x800C9FFC: jal         0x8001CAC4
    // 0x800CA000: addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    setVec3At0x24(rdram, ctx);
        goto after_29;
    // 0x800CA000: addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    after_29:
    // 0x800CA004: lui         $a1, 0xC290
    ctx->r5 = S32(0XC290 << 16);
    // 0x800CA008: jal         0x8001CB9C
    // 0x800CA00C: addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    composeRotationMatrixSlot0(rdram, ctx);
        goto after_30;
    // 0x800CA00C: addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    after_30:
    // 0x800CA010: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800CA014: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x800CA018: lui         $a2, 0xBDF5
    ctx->r6 = S32(0XBDF5 << 16);
    // 0x800CA01C: ori         $a2, $a2, 0xC28F
    ctx->r6 = ctx->r6 | 0XC28F;
    // 0x800CA020: jal         0x8001CA90
    // 0x800CA024: addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    addVec3At0x24(rdram, ctx);
        goto after_31;
    // 0x800CA024: addu        $a0, $fp, $zero
    ctx->r4 = ADD32(ctx->r30, 0);
    after_31:
    // 0x800CA028: lw          $v0, 0x370($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X370);
    // 0x800CA02C: beq         $v0, $zero, L_800CA038
    if (ctx->r2 == 0) {
        // 0x800CA030: sw          $v0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r2;
            goto L_800CA038;
    }
    // 0x800CA030: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x800CA034: sw          $s7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r23;
L_800CA038:
    // 0x800CA038: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x800CA03C: j           L_800CA348
    // 0x800CA040: sw          $s7, 0x370($s6)
    MEM_W(0X370, ctx->r22) = ctx->r23;
        goto L_800CA348;
    // 0x800CA040: sw          $s7, 0x370($s6)
    MEM_W(0X370, ctx->r22) = ctx->r23;
L_800CA044:
    // 0x800CA044: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800CA048: lwc1        $f0, 0x7984($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7984);
    // 0x800CA04C: mul.s       $f0, $f24, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x800CA050: add.s       $f30, $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f30.fl = ctx->f30.fl + ctx->f0.fl;
    // 0x800CA054: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800CA058: lwc1        $f6, 0x7988($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7988);
    // 0x800CA05C: c.lt.s      $f6, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f6.fl < ctx->f30.fl;
    // 0x800CA060: nop

    // 0x800CA064: bc1tl       L_800CA06C
    if (c1cs) {
        // 0x800CA068: mov.s       $f30, $f6
        CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 6);
    ctx->f30.fl = ctx->f6.fl;
            goto L_800CA06C;
    }
    goto skip_0;
    // 0x800CA068: mov.s       $f30, $f6
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 6);
    ctx->f30.fl = ctx->f6.fl;
    skip_0:
L_800CA06C:
    // 0x800CA06C: jal         0x800662E0
    // 0x800CA070: mov.s       $f12, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    ctx->f12.fl = ctx->f30.fl;
    quadraticEaseInOut(rdram, ctx);
        goto after_32;
    // 0x800CA070: mov.s       $f12, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 30);
    ctx->f12.fl = ctx->f30.fl;
    after_32:
    // 0x800CA074: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800CA078: lwc1        $f2, 0x798C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X798C);
    // 0x800CA07C: mul.s       $f26, $f0, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f26.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800CA080: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800CA084: lwc1        $f0, 0x7990($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X7990);
    // 0x800CA088: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800CA08C: lwc1        $f4, 0x7994($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7994);
    // 0x800CA090: c.lt.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl < ctx->f26.fl;
    // 0x800CA094: nop

    // 0x800CA098: bc1f        L_800CA0C0
    if (!c1cs) {
        // 0x800CA09C: addiu       $a1, $zero, -0x140
        ctx->r5 = ADD32(0, -0X140);
            goto L_800CA0C0;
    }
    // 0x800CA09C: addiu       $a1, $zero, -0x140
    ctx->r5 = ADD32(0, -0X140);
    // 0x800CA0A0: sub.s       $f0, $f26, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f26.fl - ctx->f0.fl;
    // 0x800CA0A4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800CA0A8: lwc1        $f2, 0x7998($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X7998);
    // 0x800CA0AC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800CA0B0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800CA0B4: lwc1        $f2, 0x799C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X799C);
    // 0x800CA0B8: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800CA0BC: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
L_800CA0C0:
    // 0x800CA0C0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800CA0C4: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800CA0C8: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x800CA0CC: lw          $a0, 0xDC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XDC);
    // 0x800CA0D0: jal         0x800B3CD4
    // 0x800CA0D4: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    setChildPosFromI16Pair(rdram, ctx);
        goto after_33;
    // 0x800CA0D4: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    after_33:
    // 0x800CA0D8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800CA0DC: lwc1        $f6, 0x79A0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X79A0);
    // 0x800CA0E0: c.eq.s      $f30, $f6
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f30.fl == ctx->f6.fl;
    // 0x800CA0E4: nop

    // 0x800CA0E8: bc1f        L_800CA348
    if (!c1cs) {
        // 0x800CA0EC: nop
    
            goto L_800CA348;
    }
    // 0x800CA0EC: nop

    // 0x800CA0F0: jal         0x800CBB7C
    // 0x800CA0F4: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    func_800CBB7C(rdram, ctx);
        goto after_34;
    // 0x800CA0F4: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_34:
    // 0x800CA0F8: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800CA0FC: lwc1        $f6, 0x79A4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X79A4);
    // 0x800CA100: swc1        $f6, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f6.u32l;
    // 0x800CA104: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800CA108: lwc1        $f6, 0x79A8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X79A8);
    // 0x800CA10C: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x800CA110: sb          $t0, 0xBA($sp)
    MEM_B(0XBA, ctx->r29) = ctx->r8;
    // 0x800CA114: j           L_800CA348
    // 0x800CA118: swc1        $f6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f6.u32l;
        goto L_800CA348;
    // 0x800CA118: swc1        $f6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f6.u32l;
L_800CA11C:
    // 0x800CA11C: lwc1        $f6, 0xD8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800CA120: add.s       $f6, $f6, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f24.fl;
    // 0x800CA124: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800CA128: lwc1        $f0, 0x79AC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X79AC);
    // 0x800CA12C: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800CA130: nop

    // 0x800CA134: bc1f        L_800CA160
    if (!c1cs) {
        // 0x800CA138: swc1        $f6, 0xD8($sp)
        MEM_W(0XD8, ctx->r29) = ctx->f6.u32l;
            goto L_800CA160;
    }
    // 0x800CA138: swc1        $f6, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f6.u32l;
    // 0x800CA13C: lbu         $v0, 0xB9($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0XB9);
    // 0x800CA140: bne         $v0, $zero, L_800CA164
    if (ctx->r2 != 0) {
        // 0x800CA144: lui         $v0, 0x800D
        ctx->r2 = S32(0X800D << 16);
            goto L_800CA164;
    }
    // 0x800CA144: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800CA148: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    // 0x800CA14C: addiu       $a1, $zero, 0x73
    ctx->r5 = ADD32(0, 0X73);
    // 0x800CA150: jal         0x80087EE8
    // 0x800CA154: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    bsearchFactor5TableByU16Key(rdram, ctx);
        goto after_35;
    // 0x800CA154: addiu       $a2, $zero, 0x40
    ctx->r6 = ADD32(0, 0X40);
    after_35:
    // 0x800CA158: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800CA15C: sb          $t0, 0xB9($sp)
    MEM_B(0XB9, ctx->r29) = ctx->r8;
L_800CA160:
    // 0x800CA160: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
L_800CA164:
    // 0x800CA164: addiu       $v1, $v0, -0x2B8C
    ctx->r3 = ADD32(ctx->r2, -0X2B8C);
    // 0x800CA168: lbu         $v0, 0xAF($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0XAF);
    // 0x800CA16C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800CA170: lbu         $v0, 0x0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X0);
    // 0x800CA174: beq         $v0, $zero, L_800CA348
    if (ctx->r2 == 0) {
        // 0x800CA178: addu        $s3, $zero, $zero
        ctx->r19 = ADD32(0, 0);
            goto L_800CA348;
    }
    // 0x800CA178: addu        $s3, $zero, $zero
    ctx->r19 = ADD32(0, 0);
    // 0x800CA17C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800CA180: addiu       $s4, $v0, 0x194
    ctx->r20 = ADD32(ctx->r2, 0X194);
    // 0x800CA184: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800CA188: lwc1        $f0, 0x79B0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X79B0);
    // 0x800CA18C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800CA190: lwc1        $f22, 0x79B4($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X79B4);
    // 0x800CA194: div.s       $f28, $f24, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f28.fl = DIV_S(ctx->f24.fl, ctx->f0.fl);
    // 0x800CA198: andi        $v0, $s3, 0xFF
    ctx->r2 = ctx->r19 & 0XFF;
L_800CA19C:
    // 0x800CA19C: sll         $v1, $v0, 3
    ctx->r3 = S32(ctx->r2 << 3);
    // 0x800CA1A0: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800CA1A4: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x800CA1A8: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800CA1AC: addiu       $t0, $t0, 0x120
    ctx->r8 = ADD32(ctx->r8, 0X120);
    // 0x800CA1B0: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x800CA1B4: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800CA1B8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800CA1BC: add.s       $f2, $f0, $f28
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f2.fl = ctx->f0.fl + ctx->f28.fl;
    // 0x800CA1C0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800CA1C4: lwc1        $f0, 0x79B8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X79B8);
    // 0x800CA1C8: addiu       $s2, $v0, 0x28
    ctx->r18 = ADD32(ctx->r2, 0X28);
    // 0x800CA1CC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800CA1D0: nop

    // 0x800CA1D4: bc1f        L_800CA1E4
    if (!c1cs) {
        // 0x800CA1D8: swc1        $f2, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
            goto L_800CA1E4;
    }
    // 0x800CA1D8: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
    // 0x800CA1DC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800CA1E0: sb          $t0, 0xB8($sp)
    MEM_B(0XB8, ctx->r29) = ctx->r8;
L_800CA1E4:
    // 0x800CA1E4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800CA1E8: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
    // 0x800CA1EC: c.lt.s      $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f20.fl < ctx->f6.fl;
    // 0x800CA1F0: nop

    // 0x800CA1F4: bc1t        L_800CA218
    if (c1cs) {
        // 0x800CA1F8: mov.s       $f0, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = ctx->f6.fl;
            goto L_800CA218;
    }
    // 0x800CA1F8: mov.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = ctx->f6.fl;
    // 0x800CA1FC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800CA200: lwc1        $f6, 0x79BC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X79BC);
    // 0x800CA204: c.lt.s      $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f6.fl < ctx->f20.fl;
    // 0x800CA208: nop

    // 0x800CA20C: bc1t        L_800CA218
    if (c1cs) {
        // 0x800CA210: mov.s       $f0, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = ctx->f6.fl;
            goto L_800CA218;
    }
    // 0x800CA210: mov.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = ctx->f6.fl;
    // 0x800CA214: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
L_800CA218:
    // 0x800CA218: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800CA21C: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x800CA220: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x800CA224: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x800CA228: jal         0x8001CB64
    // 0x800CA22C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    initVec4TripletFromArgs(rdram, ctx);
        goto after_36;
    // 0x800CA22C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_36:
    // 0x800CA230: andi        $v0, $s3, 0xFF
    ctx->r2 = ctx->r19 & 0XFF;
    // 0x800CA234: sll         $s0, $v0, 3
    ctx->r16 = S32(ctx->r2 << 3);
    // 0x800CA238: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x800CA23C: sll         $s0, $s0, 4
    ctx->r16 = S32(ctx->r16 << 4);
    // 0x800CA240: addu        $a0, $s0, $s4
    ctx->r4 = ADD32(ctx->r16, ctx->r20);
    // 0x800CA244: addiu       $a1, $s4, 0xC
    ctx->r5 = ADD32(ctx->r20, 0XC);
    // 0x800CA248: addu        $a1, $s0, $a1
    ctx->r5 = ADD32(ctx->r16, ctx->r5);
    // 0x800CA24C: addiu       $s1, $s4, -0x24
    ctx->r17 = ADD32(ctx->r20, -0X24);
    // 0x800CA250: addu        $s1, $s0, $s1
    ctx->r17 = ADD32(ctx->r16, ctx->r17);
    // 0x800CA254: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    // 0x800CA258: addiu       $a3, $s4, -0x18
    ctx->r7 = ADD32(ctx->r20, -0X18);
    // 0x800CA25C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800CA260: lwc1        $f0, 0x79C0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X79C0);
    // 0x800CA264: addu        $a3, $s0, $a3
    ctx->r7 = ADD32(ctx->r16, ctx->r7);
    // 0x800CA268: swc1        $f22, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f22.u32l;
    // 0x800CA26C: swc1        $f20, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f20.u32l;
    // 0x800CA270: jal         0x80065A60
    // 0x800CA274: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    buildPositionAndCallTransformHelper(rdram, ctx);
        goto after_37;
    // 0x800CA274: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_37:
    // 0x800CA278: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800CA27C: addiu       $t0, $t0, 0x120
    ctx->r8 = ADD32(ctx->r8, 0X120);
    // 0x800CA280: addu        $s0, $s0, $t0
    ctx->r16 = ADD32(ctx->r16, ctx->r8);
    // 0x800CA284: lw          $a1, 0x64($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X64);
    // 0x800CA288: jal         0x8001CDFC
    // 0x800CA28C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    composeRotationMatrixSlot2(rdram, ctx);
        goto after_38;
    // 0x800CA28C: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_38:
    // 0x800CA290: lw          $a1, 0x5C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X5C);
    // 0x800CA294: jal         0x8001CB9C
    // 0x800CA298: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    composeRotationMatrixSlot0(rdram, ctx);
        goto after_39;
    // 0x800CA298: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_39:
    // 0x800CA29C: lw          $a1, 0x60($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X60);
    // 0x800CA2A0: jal         0x8001CCCC
    // 0x800CA2A4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    composeRotationMatrixSlot1(rdram, ctx);
        goto after_40;
    // 0x800CA2A4: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_40:
    // 0x800CA2A8: lwc1        $f4, 0x50($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800CA2AC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800CA2B0: lwc1        $f0, 0x79C4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X79C4);
    // 0x800CA2B4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800CA2B8: lwc1        $f2, 0x79C8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X79C8);
    // 0x800CA2BC: add.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800CA2C0: lwc1        $f0, 0x54($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800CA2C4: lw          $a3, 0x58($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X58);
    // 0x800CA2C8: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800CA2CC: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
    // 0x800CA2D0: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800CA2D4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800CA2D8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x800CA2DC: jal         0x8001CA90
    // 0x800CA2E0: sw          $a2, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r6;
    addVec3At0x24(rdram, ctx);
        goto after_41;
    // 0x800CA2E0: sw          $a2, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r6;
    after_41:
    // 0x800CA2E4: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800CA2E8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800CA2EC: lwc1        $f0, 0x44($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X44);
    // 0x800CA2F0: mul.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800CA2F4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800CA2F8: addiu       $a0, $s6, 0x370
    ctx->r4 = ADD32(ctx->r22, 0X370);
    // 0x800CA2FC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800CA300: jal         0x80057C8C
    // 0x800CA304: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    addNpcToVisibilityBucket(rdram, ctx);
        goto after_42;
    // 0x800CA304: addu        $a2, $s1, $zero
    ctx->r6 = ADD32(ctx->r17, 0);
    after_42:
    // 0x800CA308: sw          $zero, 0x90($sp)
    MEM_W(0X90, ctx->r29) = 0;
    // 0x800CA30C: swc1        $f26, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f26.u32l;
    // 0x800CA310: sw          $zero, 0x98($sp)
    MEM_W(0X98, ctx->r29) = 0;
    // 0x800CA314: lw          $a0, 0x8C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8C);
    // 0x800CA318: lui         $a2, 0x40C0
    ctx->r6 = S32(0X40C0 << 16);
    // 0x800CA31C: jal         0x80053F7C
    // 0x800CA320: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    func_80053F7C(rdram, ctx);
        goto after_43;
    // 0x800CA320: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    after_43:
    // 0x800CA324: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800CA328: lbu         $v0, 0xAF($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0XAF);
    // 0x800CA32C: addiu       $t0, $t0, -0x2B8C
    ctx->r8 = ADD32(ctx->r8, -0X2B8C);
    // 0x800CA330: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x800CA334: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x800CA338: andi        $v0, $s3, 0xFF
    ctx->r2 = ctx->r19 & 0XFF;
    // 0x800CA33C: sltu        $v0, $v0, $v1
    ctx->r2 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x800CA340: bne         $v0, $zero, L_800CA19C
    if (ctx->r2 != 0) {
        // 0x800CA344: andi        $v0, $s3, 0xFF
        ctx->r2 = ctx->r19 & 0XFF;
            goto L_800CA19C;
    }
    // 0x800CA344: andi        $v0, $s3, 0xFF
    ctx->r2 = ctx->r19 & 0XFF;
L_800CA348:
    // 0x800CA348: lbu         $t0, 0xB7($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0XB7);
    // 0x800CA34C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800CA350: bne         $t0, $v0, L_800CA418
    if (ctx->r8 != ctx->r2) {
        // 0x800CA354: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_800CA418;
    }
    // 0x800CA354: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x800CA358: addiu       $s1, $s5, 0x30
    ctx->r17 = ADD32(ctx->r21, 0X30);
    // 0x800CA35C: lwc1        $f0, 0x24($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X24);
    // 0x800CA360: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800CA364: lwc1        $f20, 0x79CC($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X79CC);
    // 0x800CA368: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800CA36C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800CA370: lwc1        $f0, 0x28($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X28);
    // 0x800CA374: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800CA378: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800CA37C: lwc1        $f0, 0x2C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x800CA380: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800CA384: lw          $s0, 0x34($s5)
    ctx->r16 = MEM_W(ctx->r21, 0X34);
    // 0x800CA388: lwc1        $f6, 0xC4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x800CA38C: addiu       $s0, $s0, 0x28
    ctx->r16 = ADD32(ctx->r16, 0X28);
    // 0x800CA390: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800CA394: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x800CA398: jal         0x8001CB64
    // 0x800CA39C: swc1        $f6, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f6.u32l;
    initVec4TripletFromArgs(rdram, ctx);
        goto after_44;
    // 0x800CA39C: swc1        $f6, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f6.u32l;
    after_44:
    // 0x800CA3A0: lw          $a1, 0x18($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X18);
    // 0x800CA3A4: jal         0x8001CB9C
    // 0x800CA3A8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    composeRotationMatrixSlot0(rdram, ctx);
        goto after_45;
    // 0x800CA3A8: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_45:
    // 0x800CA3AC: lw          $a1, 0x1C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X1C);
    // 0x800CA3B0: jal         0x8001CCCC
    // 0x800CA3B4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    composeRotationMatrixSlot1(rdram, ctx);
        goto after_46;
    // 0x800CA3B4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_46:
    // 0x800CA3B8: lw          $a1, 0x20($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X20);
    // 0x800CA3BC: jal         0x8001CDFC
    // 0x800CA3C0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    composeRotationMatrixSlot2(rdram, ctx);
        goto after_47;
    // 0x800CA3C0: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_47:
    // 0x800CA3C4: lwc1        $f0, 0x14($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800CA3C8: mul.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800CA3CC: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x800CA3D0: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x800CA3D4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800CA3D8: jal         0x8001CA90
    // 0x800CA3DC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    addVec3At0x24(rdram, ctx);
        goto after_48;
    // 0x800CA3DC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_48:
    // 0x800CA3E0: lw          $v1, 0x34($s5)
    ctx->r3 = MEM_W(ctx->r21, 0X34);
    // 0x800CA3E4: lw          $v0, 0x370($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X370);
    // 0x800CA3E8: beq         $v0, $zero, L_800CA400
    if (ctx->r2 == 0) {
        // 0x800CA3EC: sw          $v0, 0xC($v1)
        MEM_W(0XC, ctx->r3) = ctx->r2;
            goto L_800CA400;
    }
    // 0x800CA3EC: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    // 0x800CA3F0: lw          $v0, 0x34($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X34);
    // 0x800CA3F4: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x800CA3F8: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800CA3FC: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_800CA400:
    // 0x800CA400: lw          $v0, 0x34($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X34);
    // 0x800CA404: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x800CA408: lw          $v0, 0x34($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X34);
    // 0x800CA40C: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x800CA410: j           L_800CA468
    // 0x800CA414: sw          $v0, 0x370($s6)
    MEM_W(0X370, ctx->r22) = ctx->r2;
        goto L_800CA468;
    // 0x800CA414: sw          $v0, 0x370($s6)
    MEM_W(0X370, ctx->r22) = ctx->r2;
L_800CA418:
    // 0x800CA418: lw          $t0, 0xBC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XBC);
    // 0x800CA41C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800CA420: bne         $t0, $v0, L_800CA438
    if (ctx->r8 != ctx->r2) {
        // 0x800CA424: sw          $t0, 0xBC($sp)
        MEM_W(0XBC, ctx->r29) = ctx->r8;
            goto L_800CA438;
    }
    // 0x800CA424: sw          $t0, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r8;
    // 0x800CA428: lw          $a0, 0x34($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X34);
    // 0x800CA42C: jal         0x8005779C
    // 0x800CA430: nop

    releaseMeshAsset(rdram, ctx);
        goto after_49;
    // 0x800CA430: nop

    after_49:
    // 0x800CA434: sw          $zero, 0x34($s5)
    MEM_W(0X34, ctx->r21) = 0;
L_800CA438:
    // 0x800CA438: lw          $t0, 0xBC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XBC);
    // 0x800CA43C: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x800CA440: bnel        $t0, $v0, L_800CA46C
    if (ctx->r8 != ctx->r2) {
        // 0x800CA444: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800CA46C;
    }
    goto skip_1;
    // 0x800CA444: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    skip_1:
    // 0x800CA448: lw          $a0, 0xDC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XDC);
    // 0x800CA44C: jal         0x800B3D08
    // 0x800CA450: nop

    getStructField0xC(rdram, ctx);
        goto after_50;
    // 0x800CA450: nop

    after_50:
    // 0x800CA454: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800CA458: addu        $a1, $v0, $zero
    ctx->r5 = ADD32(ctx->r2, 0);
    // 0x800CA45C: lw          $a0, 0x360($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X360);
    // 0x800CA460: jal         0x800646AC
    // 0x800CA464: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    setLookupEntryField5ByKey(rdram, ctx);
        goto after_51;
    // 0x800CA464: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_51:
L_800CA468:
    // 0x800CA468: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
L_800CA46C:
    // 0x800CA46C: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x800CA470: lw          $a3, 0xC8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC8);
    // 0x800CA474: lwc1        $f6, 0xCC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x800CA478: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x800CA47C: jal         0x80017AE0
    // 0x800CA480: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_80017AE0(rdram, ctx);
        goto after_52;
    // 0x800CA480: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_52:
    // 0x800CA484: jal         0x80017AB0
    // 0x800CA488: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    func_80017AB0(rdram, ctx);
        goto after_53;
    // 0x800CA488: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_53:
    // 0x800CA48C: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800CA490: addiu       $a0, $a0, 0x370
    ctx->r4 = ADD32(ctx->r4, 0X370);
    // 0x800CA494: jal         0x80016C44
    // 0x800CA498: nop

    setupCameraMatrices(rdram, ctx);
        goto after_54;
    // 0x800CA498: nop

    after_54:
    // 0x800CA49C: jal         0x8000B6F4
    // 0x800CA4A0: nop

    drawFrameProfilerBars(rdram, ctx);
        goto after_55;
    // 0x800CA4A0: nop

    after_55:
    // 0x800CA4A4: jal         0x8000C07C
    // 0x800CA4A8: nop

    submitGfxFrame(rdram, ctx);
        goto after_56;
    // 0x800CA4A8: nop

    after_56:
    // 0x800CA4AC: lbu         $t0, 0xAF($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0XAF);
    // 0x800CA4B0: addiu       $a0, $t0, 0x1
    ctx->r4 = ADD32(ctx->r8, 0X1);
    // 0x800CA4B4: jal         0x8006ED90
    // 0x800CA4B8: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    isUnlockBitSet(rdram, ctx);
        goto after_57;
    // 0x800CA4B8: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    after_57:
    // 0x800CA4BC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800CA4C0: beq         $v0, $zero, L_800CA4E0
    if (ctx->r2 == 0) {
        // 0x800CA4C4: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_800CA4E0;
    }
    // 0x800CA4C4: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x800CA4C8: lbu         $a0, 0xA0($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0XA0);
    // 0x800CA4CC: jal         0x80079F50
    // 0x800CA4D0: nop

    getControllerNewButtonsPressed(rdram, ctx);
        goto after_58;
    // 0x800CA4D0: nop

    after_58:
    // 0x800CA4D4: andi        $v0, $v0, 0x9000
    ctx->r2 = ctx->r2 & 0X9000;
    // 0x800CA4D8: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    // 0x800CA4DC: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_800CA4E0:
    // 0x800CA4E0: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800CA4E4: addiu       $a1, $a1, 0x370
    ctx->r5 = ADD32(ctx->r5, 0X370);
    // 0x800CA4E8: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800CA4EC: lw          $a0, 0x364($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X364);
    // 0x800CA4F0: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x800CA4F4: jal         0x800B4168
    // 0x800CA4F8: addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
    func_800B4168(rdram, ctx);
        goto after_59;
    // 0x800CA4F8: addu        $s0, $v1, $zero
    ctx->r16 = ADD32(ctx->r3, 0);
    after_59:
    // 0x800CA4FC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800CA500: bne         $v0, $zero, L_800CA578
    if (ctx->r2 != 0) {
        // 0x800CA504: andi        $v0, $s0, 0xFF
        ctx->r2 = ctx->r16 & 0XFF;
            goto L_800CA578;
    }
    // 0x800CA504: andi        $v0, $s0, 0xFF
    ctx->r2 = ctx->r16 & 0XFF;
    // 0x800CA508: bne         $v0, $zero, L_800CA51C
    if (ctx->r2 != 0) {
        // 0x800CA50C: nop
    
            goto L_800CA51C;
    }
    // 0x800CA50C: nop

    // 0x800CA510: lbu         $v0, 0xB8($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0XB8);
    // 0x800CA514: beq         $v0, $zero, L_800C9D8C
    if (ctx->r2 == 0) {
        // 0x800CA518: nop
    
            goto L_800C9D8C;
    }
    // 0x800CA518: nop

L_800CA51C:
    // 0x800CA51C: jal         0x800B4264
    // 0x800CA520: nop

    func_800B4264(rdram, ctx);
        goto after_60;
    // 0x800CA520: nop

    after_60:
    // 0x800CA524: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800CA528: bne         $v0, $zero, L_800C9D8C
    if (ctx->r2 != 0) {
        // 0x800CA52C: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_800C9D8C;
    }
    // 0x800CA52C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800CA530: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    // 0x800CA534: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800CA538: lw          $a2, 0xA8($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XA8);
    // 0x800CA53C: jal         0x800964C8
    // 0x800CA540: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    queueAudioVoiceCmd(rdram, ctx);
        goto after_61;
    // 0x800CA540: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_61:
    // 0x800CA544: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800CA548: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    // 0x800CA54C: jal         0x8008E0B0
    // 0x800CA550: addiu       $a2, $zero, 0xFE
    ctx->r6 = ADD32(0, 0XFE);
    playSimpleAudioCmd(rdram, ctx);
        goto after_62;
    // 0x800CA550: addiu       $a2, $zero, 0xFE
    ctx->r6 = ADD32(0, 0XFE);
    after_62:
    // 0x800CA554: lui         $t0, 0x800D
    ctx->r8 = S32(0X800D << 16);
    // 0x800CA558: lw          $a0, 0x364($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X364);
    // 0x800CA55C: lui         $a2, 0x4180
    ctx->r6 = S32(0X4180 << 16);
    // 0x800CA560: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800CA564: addiu       $a1, $a1, 0x370
    ctx->r5 = ADD32(ctx->r5, 0X370);
    // 0x800CA568: jal         0x800B4048
    // 0x800CA56C: nop

    func_800B4048(rdram, ctx);
        goto after_63;
    // 0x800CA56C: nop

    after_63:
    // 0x800CA570: j           L_800C9D8C
    // 0x800CA574: nop

        goto L_800C9D8C;
    // 0x800CA574: nop

L_800CA578:
    // 0x800CA578: jal         0x8008DA00
    // 0x800CA57C: nop

    tickMusyXIfActive(rdram, ctx);
        goto after_64;
    // 0x800CA57C: nop

    after_64:
L_800CA580:
    // 0x800CA580: jal         0x8008E57C
    // 0x800CA584: nop

    anyAudioSlotActive(rdram, ctx);
        goto after_65;
    // 0x800CA584: nop

    after_65:
    // 0x800CA588: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x800CA58C: beq         $v0, $zero, L_800CA580
    if (ctx->r2 == 0) {
        // 0x800CA590: nop
    
            goto L_800CA580;
    }
    // 0x800CA590: nop

    // 0x800CA594: jal         0x8000BF60
    // 0x800CA598: nop

    bufferArbiterProducerScanWait(rdram, ctx);
        goto after_66;
    // 0x800CA598: nop

    after_66:
    // 0x800CA59C: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800CA5A0: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800CA5A4: lw          $a0, 0x364($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X364);
    // 0x800CA5A8: jal         0x800B4274
    // 0x800CA5AC: addiu       $a1, $a1, 0x370
    ctx->r5 = ADD32(ctx->r5, 0X370);
    func_800B4274(rdram, ctx);
        goto after_67;
    // 0x800CA5AC: addiu       $a1, $a1, 0x370
    ctx->r5 = ADD32(ctx->r5, 0X370);
    after_67:
    // 0x800CA5B0: lw          $a0, 0xDC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XDC);
    // 0x800CA5B4: jal         0x800B3CC0
    // 0x800CA5B8: nop

    func_800B3CC0(rdram, ctx);
        goto after_68;
    // 0x800CA5B8: nop

    after_68:
    // 0x800CA5BC: lbu         $s0, 0xAF($sp)
    ctx->r16 = MEM_BU(ctx->r29, 0XAF);
    // 0x800CA5C0: jal         0x800CBD6C
    // 0x800CA5C4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800CBD6C(rdram, ctx);
        goto after_69;
    // 0x800CA5C4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_69:
    // 0x800CA5C8: jal         0x800CBC24
    // 0x800CA5CC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    func_800CBC24(rdram, ctx);
        goto after_70;
    // 0x800CA5CC: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    after_70:
    // 0x800CA5D0: jal         0x800CBBB8
    // 0x800CA5D4: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    func_800CBBB8(rdram, ctx);
        goto after_71;
    // 0x800CA5D4: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_71:
    // 0x800CA5D8: jal         0x800CBB30
    // 0x800CA5DC: nop

    func_800CBB30(rdram, ctx);
        goto after_72;
    // 0x800CA5DC: nop

    after_72:
    // 0x800CA5E0: lbu         $t0, 0xAF($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0XAF);
    // 0x800CA5E4: addiu       $a0, $t0, 0x1
    ctx->r4 = ADD32(ctx->r8, 0X1);
    // 0x800CA5E8: jal         0x8006E360
    // 0x800CA5EC: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    setUnlockBitAndPersist(rdram, ctx);
        goto after_73;
    // 0x800CA5EC: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    after_73:
    // 0x800CA5F0: lw          $ra, 0x104($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X104);
    // 0x800CA5F4: lw          $fp, 0x100($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X100);
    // 0x800CA5F8: lw          $s7, 0xFC($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XFC);
    // 0x800CA5FC: lw          $s6, 0xF8($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XF8);
    // 0x800CA600: lw          $s5, 0xF4($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XF4);
    // 0x800CA604: lw          $s4, 0xF0($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XF0);
    // 0x800CA608: lw          $s3, 0xEC($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XEC);
    // 0x800CA60C: lw          $s2, 0xE8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XE8);
    // 0x800CA610: lw          $s1, 0xE4($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XE4);
    // 0x800CA614: lw          $s0, 0xE0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XE0);
    // 0x800CA618: ldc1        $f30, 0x130($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X130);
    // 0x800CA61C: ldc1        $f28, 0x128($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X128);
    // 0x800CA620: ldc1        $f26, 0x120($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X120);
    // 0x800CA624: ldc1        $f24, 0x118($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X118);
    // 0x800CA628: ldc1        $f22, 0x110($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X110);
    // 0x800CA62C: ldc1        $f20, 0x108($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X108);
    // 0x800CA630: jr          $ra
    // 0x800CA634: addiu       $sp, $sp, 0x138
    ctx->r29 = ADD32(ctx->r29, 0X138);
    return;
    // 0x800CA634: addiu       $sp, $sp, 0x138
    ctx->r29 = ADD32(ctx->r29, 0X138);
;}
RECOMP_FUNC void func_800CA18C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA18C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800CA190: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800CA194: addiu       $a1, $a1, 0x69A0
    ctx->r5 = ADD32(ctx->r5, 0X69A0);
    // 0x800CA198: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x800CA19C: sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // 0x800CA1A0: lw          $s0, 0x4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X4);
    // 0x800CA1A4: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800CA1A8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800CA1AC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800CA1B0: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x800CA1B4: jal         0x80058360
    // 0x800CA1B8: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    lookupHmtTextureByName(rdram, ctx);
        goto after_0;
    // 0x800CA1B8: addiu       $a3, $sp, 0x28
    ctx->r7 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x800CA1BC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x800CA1C0: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x800CA1C4: jal         0x800F2DC8
    // 0x800CA1C8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    generatePerpEmitDirectionWithJitter(rdram, ctx);
        goto after_1;
    // 0x800CA1C8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_1:
    // 0x800CA1CC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x800CA1D0: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x800CA1D4: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x800CA1D8: jal         0x800F1870
    // 0x800CA1DC: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    tickProgressChannel(rdram, ctx);
        goto after_2;
    // 0x800CA1DC: addiu       $a3, $sp, 0x58
    ctx->r7 = ADD32(ctx->r29, 0X58);
    after_2:
    // 0x800CA1E0: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x800CA1E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800CA1E8: bne         $v1, $v0, L_800CA258
    if (ctx->r3 != ctx->r2) {
        // 0x800CA1EC: addu        $a1, $zero, $zero
        ctx->r5 = ADD32(0, 0);
            goto L_800CA258;
    }
    // 0x800CA1EC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x800CA1F0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800CA1F4: lwc1        $f0, 0x6B6C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6B6C);
    // 0x800CA1F8: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x800CA1FC: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x800CA200: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x800CA204: lwc1        $f0, 0x58($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800CA208: lui         $a3, 0x8011
    ctx->r7 = S32(0X8011 << 16);
    // 0x800CA20C: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x800CA210: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x800CA214: jal         0x800F2FCC
    // 0x800CA218: addiu       $a3, $a3, -0x5A54
    ctx->r7 = ADD32(ctx->r7, -0X5A54);
    triggerCueWithSlotEffect(rdram, ctx);
        goto after_3;
    // 0x800CA218: addiu       $a3, $a3, -0x5A54
    ctx->r7 = ADD32(ctx->r7, -0X5A54);
    after_3:
    // 0x800CA21C: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x800CA220: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x800CA224: addiu       $a2, $a1, 0x24
    ctx->r6 = ADD32(ctx->r5, 0X24);
    // 0x800CA228: lui         $a3, 0x4170
    ctx->r7 = S32(0X4170 << 16);
    // 0x800CA22C: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800CA230: lwc1        $f0, 0x6B70($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6B70);
    // 0x800CA234: addiu       $v0, $zero, 0x16
    ctx->r2 = ADD32(0, 0X16);
    // 0x800CA238: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x800CA23C: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x800CA240: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800CA244: addiu       $v0, $zero, 0x28
    ctx->r2 = ADD32(0, 0X28);
    // 0x800CA248: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800CA24C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800CA250: jal         0x800989D8
    // 0x800CA254: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    play3DSoundEvent(rdram, ctx);
        goto after_4;
    // 0x800CA254: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    after_4:
L_800CA258:
    // 0x800CA258: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x800CA25C: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x800CA260: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x800CA264: jr          $ra
    // 0x800CA268: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800CA268: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void fake_func_800CA26C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_800CA270(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA270: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800CA274: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800CA278: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800CA27C: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800CA280: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800CA284: lw          $s1, 0x4($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X4);
    // 0x800CA288: sh          $zero, 0xE2($s1)
    MEM_H(0XE2, ctx->r17) = 0;
    // 0x800CA28C: jal         0x80003430
    // 0x800CA290: sw          $zero, 0x54($s1)
    MEM_W(0X54, ctx->r17) = 0;
    rand_recomp(rdram, ctx);
        goto after_0;
    // 0x800CA290: sw          $zero, 0x54($s1)
    MEM_W(0X54, ctx->r17) = 0;
    after_0:
    // 0x800CA294: andi        $v0, $v0, 0x7F
    ctx->r2 = ctx->r2 & 0X7F;
    // 0x800CA298: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800CA29C: lwc1        $f2, 0x6B80($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6B80);
    // 0x800CA2A0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800CA2A4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800CA2A8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800CA2AC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800CA2B0: lwc1        $f2, 0x6B84($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6B84);
    // 0x800CA2B4: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800CA2B8: abs.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = fabsf(ctx->f0.fl);
    // 0x800CA2BC: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800CA2C0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800CA2C4: lwc1        $f2, 0x6B88($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6B88);
    // 0x800CA2C8: lw          $s0, 0x34($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X34);
    // 0x800CA2CC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800CA2D0: addiu       $a1, $s0, 0x6C
    ctx->r5 = ADD32(ctx->r16, 0X6C);
    // 0x800CA2D4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x800CA2D8: jal         0x800F2070
    // 0x800CA2DC: swc1        $f0, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f0.u32l;
    setNpcHealth(rdram, ctx);
        goto after_1;
    // 0x800CA2DC: swc1        $f0, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f0.u32l;
    after_1:
    // 0x800CA2E0: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800CA2E4: lw          $v0, 0x7CE4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X7CE4);
    // 0x800CA2E8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800CA2EC: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x800CA2F0: lwc1        $f0, 0xAC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XAC);
    // 0x800CA2F4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800CA2F8: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800CA2FC: lw          $a1, 0xA0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XA0);
    // 0x800CA300: lw          $a2, 0xA4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XA4);
    // 0x800CA304: lw          $a3, 0xA8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XA8);
    // 0x800CA308: jal         0x800F2888
    // 0x800CA30C: nop

    initActorMotionParams(rdram, ctx);
        goto after_2;
    // 0x800CA30C: nop

    after_2:
    // 0x800CA310: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800CA314: lw          $a1, 0x90($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X90);
    // 0x800CA318: jal         0x800F2830
    // 0x800CA31C: nop

    setObjectDetailLevel(rdram, ctx);
        goto after_3;
    // 0x800CA31C: nop

    after_3:
    // 0x800CA320: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800CA324: lwc1        $f0, 0xBC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XBC);
    // 0x800CA328: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800CA32C: lwc1        $f2, 0x6B8C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X6B8C);
    // 0x800CA330: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800CA334: lwc1        $f4, 0x6B90($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6B90);
    // 0x800CA338: lw          $v1, 0x7CE4($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X7CE4);
    // 0x800CA33C: addiu       $v0, $v0, -0x5C5C
    ctx->r2 = ADD32(ctx->r2, -0X5C5C);
    // 0x800CA340: sw          $v0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r2;
    // 0x800CA344: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800CA348: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800CA34C: addu        $v1, $v1, $s0
    ctx->r3 = ADD32(ctx->r3, ctx->r16);
    // 0x800CA350: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x800CA354: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x800CA358: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x800CA35C: lwc1        $f0, 0xC0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XC0);
    // 0x800CA360: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x800CA364: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800CA368: lw          $a1, 0xB0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XB0);
    // 0x800CA36C: lw          $a2, 0xB4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XB4);
    // 0x800CA370: lw          $a3, 0xB8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XB8);
    // 0x800CA374: jal         0x800F2B88
    // 0x800CA378: nop

    initObjectAnimSubstruct(rdram, ctx);
        goto after_4;
    // 0x800CA378: nop

    after_4:
    // 0x800CA37C: lw          $a0, 0x38($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X38);
    // 0x800CA380: lw          $a1, 0xC4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC4);
    // 0x800CA384: jal         0x800F2FC0
    // 0x800CA388: nop

    setEffectIntensity(rdram, ctx);
        goto after_5;
    // 0x800CA388: nop

    after_5:
    // 0x800CA38C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800CA390: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800CA394: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800CA398: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800CA39C: jr          $ra
    // 0x800CA3A0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800CA3A0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
