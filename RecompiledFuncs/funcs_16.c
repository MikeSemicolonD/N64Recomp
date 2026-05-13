#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void setSpeechVolume(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067AFC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067B00: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80067B04: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x80067B08: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80067B0C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80067B10: lwc1        $f2, -0x383C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X383C);
    // 0x80067B14: lwc1        $f12, -0x6378($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, -0X6378);
    // 0x80067B18: mtc1        $a0, $f0
    ctx->f0.u32l = ctx->r4;
    // 0x80067B1C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80067B20: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80067B24: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80067B28: jal         0x80066D8C
    // 0x80067B2C: swc1        $f0, -0x6380($v1)
    MEM_W(-0X6380, ctx->r3) = ctx->f0.u32l;
    applySpeechVolumeScalar(rdram, ctx);
        goto after_0;
    // 0x80067B2C: swc1        $f0, -0x6380($v1)
    MEM_W(-0X6380, ctx->r3) = ctx->f0.u32l;
    after_0:
    // 0x80067B30: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80067B34: jr          $ra
    // 0x80067B38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80067B38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void isSpeechSlotActive(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067B3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067B40: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
    // 0x80067B44: beq         $v1, $zero, L_80067B80
    if (ctx->r3 == 0) {
        // 0x80067B48: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_80067B80;
    }
    // 0x80067B48: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80067B4C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80067B50: addiu       $v0, $v0, -0x6480
    ctx->r2 = ADD32(ctx->r2, -0X6480);
    // 0x80067B54: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80067B58: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80067B5C: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80067B60: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x80067B64: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80067B68: beql        $a0, $v0, L_80067B84
    if (ctx->r4 == ctx->r2) {
        // 0x80067B6C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_80067B84;
    }
    goto skip_0;
    // 0x80067B6C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    skip_0:
    // 0x80067B70: jal         0x8009B3CC
    // 0x80067B74: nop

    isVoiceHandleActive(rdram, ctx);
        goto after_0;
    // 0x80067B74: nop

    after_0:
    // 0x80067B78: j           L_80067B84
    // 0x80067B7C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
        goto L_80067B84;
    // 0x80067B7C: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
L_80067B80:
    // 0x80067B80: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80067B84:
    // 0x80067B84: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80067B88: jr          $ra
    // 0x80067B8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80067B8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void stopSpeechSlotIfActive(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067B90: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80067B94: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80067B98: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x80067B9C: sltiu       $v0, $v0, 0x8
    ctx->r2 = ctx->r2 < 0X8 ? 1 : 0;
    // 0x80067BA0: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80067BA4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80067BA8: beq         $v0, $zero, L_80067BF8
    if (ctx->r2 == 0) {
        // 0x80067BAC: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_80067BF8;
    }
    // 0x80067BAC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80067BB0: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80067BB4: addiu       $v1, $v1, -0x6480
    ctx->r3 = ADD32(ctx->r3, -0X6480);
    // 0x80067BB8: andi        $v0, $a0, 0xFF
    ctx->r2 = ctx->r4 & 0XFF;
    // 0x80067BBC: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80067BC0: addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // 0x80067BC4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80067BC8: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x80067BCC: beq         $a0, $s1, L_80067BF8
    if (ctx->r4 == ctx->r17) {
        // 0x80067BD0: nop
    
            goto L_80067BF8;
    }
    // 0x80067BD0: nop

    // 0x80067BD4: jal         0x8009B3CC
    // 0x80067BD8: nop

    isVoiceHandleActive(rdram, ctx);
        goto after_0;
    // 0x80067BD8: nop

    after_0:
    // 0x80067BDC: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80067BE0: beql        $v0, $zero, L_80067BF8
    if (ctx->r2 == 0) {
        // 0x80067BE4: sw          $s1, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r17;
            goto L_80067BF8;
    }
    goto skip_0;
    // 0x80067BE4: sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
    skip_0:
    // 0x80067BE8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80067BEC: jal         0x8009B33C
    // 0x80067BF0: nop

    stopVoiceByHandle(rdram, ctx);
        goto after_1;
    // 0x80067BF0: nop

    after_1:
    // 0x80067BF4: sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
L_80067BF8:
    // 0x80067BF8: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80067BFC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80067C00: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80067C04: jr          $ra
    // 0x80067C08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80067C08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void stopAllSpeechSlots(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067C0C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80067C10: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80067C14: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80067C18: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80067C1C: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x80067C20: addiu       $s3, $v0, -0x6480
    ctx->r19 = ADD32(ctx->r2, -0X6480);
    // 0x80067C24: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x80067C28: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x80067C2C: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x80067C30: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80067C34: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
L_80067C38:
    // 0x80067C38: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80067C3C: addu        $s0, $v0, $s3
    ctx->r16 = ADD32(ctx->r2, ctx->r19);
    // 0x80067C40: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80067C44: beql        $a0, $s2, L_80067C74
    if (ctx->r4 == ctx->r18) {
        // 0x80067C48: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80067C74;
    }
    goto skip_0;
    // 0x80067C48: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x80067C4C: jal         0x8009B3CC
    // 0x80067C50: nop

    isVoiceHandleActive(rdram, ctx);
        goto after_0;
    // 0x80067C50: nop

    after_0:
    // 0x80067C54: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80067C58: beql        $v0, $zero, L_80067C70
    if (ctx->r2 == 0) {
        // 0x80067C5C: sw          $s2, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r18;
            goto L_80067C70;
    }
    goto skip_1;
    // 0x80067C5C: sw          $s2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r18;
    skip_1:
    // 0x80067C60: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80067C64: jal         0x8009B33C
    // 0x80067C68: nop

    stopVoiceByHandle(rdram, ctx);
        goto after_1;
    // 0x80067C68: nop

    after_1:
    // 0x80067C6C: sw          $s2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r18;
L_80067C70:
    // 0x80067C70: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80067C74:
    // 0x80067C74: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // 0x80067C78: sltiu       $v0, $v0, 0x8
    ctx->r2 = ctx->r2 < 0X8 ? 1 : 0;
    // 0x80067C7C: bne         $v0, $zero, L_80067C38
    if (ctx->r2 != 0) {
        // 0x80067C80: andi        $v0, $s1, 0xFF
        ctx->r2 = ctx->r17 & 0XFF;
            goto L_80067C38;
    }
    // 0x80067C80: andi        $v0, $s1, 0xFF
    ctx->r2 = ctx->r17 & 0XFF;
    // 0x80067C84: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x80067C88: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x80067C8C: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x80067C90: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80067C94: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80067C98: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80067C9C: sh          $zero, -0x6458($v0)
    MEM_H(-0X6458, ctx->r2) = 0;
    // 0x80067CA0: jr          $ra
    // 0x80067CA4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80067CA4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void advanceSpeechRingAndStopHead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067CA8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80067CAC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80067CB0: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80067CB4: lbu         $v0, -0x6457($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X6457);
    // 0x80067CB8: addiu       $v1, $v1, -0x6480
    ctx->r3 = ADD32(ctx->r3, -0X6480);
    // 0x80067CBC: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80067CC0: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80067CC4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80067CC8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80067CCC: addu        $s0, $v0, $v1
    ctx->r16 = ADD32(ctx->r2, ctx->r3);
    // 0x80067CD0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80067CD4: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x80067CD8: beq         $a0, $s1, L_80067D08
    if (ctx->r4 == ctx->r17) {
        // 0x80067CDC: lui         $v1, 0x8014
        ctx->r3 = S32(0X8014 << 16);
            goto L_80067D08;
    }
    // 0x80067CDC: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80067CE0: jal         0x8009B3CC
    // 0x80067CE4: nop

    isVoiceHandleActive(rdram, ctx);
        goto after_0;
    // 0x80067CE4: nop

    after_0:
    // 0x80067CE8: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x80067CEC: beql        $v0, $zero, L_80067D04
    if (ctx->r2 == 0) {
        // 0x80067CF0: sw          $s1, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r17;
            goto L_80067D04;
    }
    goto skip_0;
    // 0x80067CF0: sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
    skip_0:
    // 0x80067CF4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80067CF8: jal         0x8009B33C
    // 0x80067CFC: nop

    stopVoiceByHandle(rdram, ctx);
        goto after_1;
    // 0x80067CFC: nop

    after_1:
    // 0x80067D00: sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
L_80067D04:
    // 0x80067D04: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
L_80067D08:
    // 0x80067D08: lhu         $a0, -0x6458($v1)
    ctx->r4 = MEM_HU(ctx->r3, -0X6458);
    // 0x80067D0C: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    // 0x80067D10: sh          $v0, -0x6458($v1)
    MEM_H(-0X6458, ctx->r3) = ctx->r2;
    // 0x80067D14: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x80067D18: bgez        $v0, L_80067D24
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80067D1C: addiu       $v0, $a0, 0x7
        ctx->r2 = ADD32(ctx->r4, 0X7);
            goto L_80067D24;
    }
    // 0x80067D1C: addiu       $v0, $a0, 0x7
    ctx->r2 = ADD32(ctx->r4, 0X7);
    // 0x80067D20: sh          $v0, -0x6458($v1)
    MEM_H(-0X6458, ctx->r3) = ctx->r2;
L_80067D24:
    // 0x80067D24: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80067D28: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80067D2C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80067D30: jr          $ra
    // 0x80067D34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80067D34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80067D38(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067D38: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80067D3C: lw          $v0, -0x35E0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X35E0);
    // 0x80067D40: mtc1        $a2, $f0
    ctx->f0.u32l = ctx->r6;
    // 0x80067D44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80067D48: bne         $v0, $zero, L_80067D80
    if (ctx->r2 != 0) {
        // 0x80067D4C: sw          $ra, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r31;
            goto L_80067D80;
    }
    // 0x80067D4C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80067D50: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x80067D54: beq         $a3, $zero, L_80067D6C
    if (ctx->r7 == 0) {
        // 0x80067D58: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_80067D6C;
    }
    // 0x80067D58: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80067D5C: lbu         $v1, -0x638E($v0)
    ctx->r3 = MEM_BU(ctx->r2, -0X638E);
    // 0x80067D60: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x80067D64: bne         $v1, $v0, L_80067D80
    if (ctx->r3 != ctx->r2) {
        // 0x80067D68: nop
    
            goto L_80067D80;
    }
    // 0x80067D68: nop

L_80067D6C:
    // 0x80067D6C: sltu        $a3, $zero, $a3
    ctx->r7 = 0 < ctx->r7 ? 1 : 0;
    // 0x80067D70: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80067D74: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80067D78: jal         0x80066EE4
    // 0x80067D7C: sll         $a3, $a3, 3
    ctx->r7 = S32(ctx->r7 << 3);
    playSpeechClip(rdram, ctx);
        goto after_0;
    // 0x80067D7C: sll         $a3, $a3, 3
    ctx->r7 = S32(ctx->r7 << 3);
    after_0:
L_80067D80:
    // 0x80067D80: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80067D84: jr          $ra
    // 0x80067D88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80067D88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void wrapAngleToCyclicRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067D90: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80067D94: addiu       $v0, $v0, 0x6DC0
    ctx->r2 = ADD32(ctx->r2, 0X6DC0);
    // 0x80067D98: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80067D9C: sub.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x80067DA0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80067DA4: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80067DA8: nop

    // 0x80067DAC: bc1f        L_80067DE8
    if (!c1cs) {
        // 0x80067DB0: nop
    
            goto L_80067DE8;
    }
    // 0x80067DB0: nop

    // 0x80067DB4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80067DB8: lwc1        $f0, -0x3830($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3830);
    // 0x80067DBC: mul.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80067DC0: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80067DC4: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x80067DC8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80067DCC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80067DD0: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80067DD4: sub.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80067DD8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80067DDC: lwc1        $f2, -0x382C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X382C);
    // 0x80067DE0: j           L_80067E20
    // 0x80067DE4: add.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
        goto L_80067E20;
    // 0x80067DE4: add.s       $f6, $f0, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f2.fl;
L_80067DE8:
    // 0x80067DE8: lwc1        $f0, 0x24($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80067DEC: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x80067DF0: nop

    // 0x80067DF4: bc1fl       L_80067E24
    if (!c1cs) {
        // 0x80067DF8: add.s       $f6, $f6, $f6
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f6.fl;
            goto L_80067E24;
    }
    goto skip_0;
    // 0x80067DF8: add.s       $f6, $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f6.fl;
    skip_0:
    // 0x80067DFC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80067E00: lwc1        $f0, -0x3828($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3828);
    // 0x80067E04: mul.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80067E08: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80067E0C: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x80067E10: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80067E14: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80067E18: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80067E1C: sub.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f0.fl;
L_80067E20:
    // 0x80067E20: add.s       $f6, $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f6.fl;
L_80067E24:
    // 0x80067E24: trunc.w.s   $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80067E28: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80067E2C: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    // 0x80067E30: mtc1        $a2, $f0
    ctx->f0.u32l = ctx->r6;
    // 0x80067E34: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80067E38: bgez        $a2, L_80067E44
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80067E3C: sub.s       $f6, $f6, $f0
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f0.fl;
            goto L_80067E44;
    }
    // 0x80067E3C: sub.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80067E40: addiu       $v0, $a2, 0x3
    ctx->r2 = ADD32(ctx->r6, 0X3);
L_80067E44:
    // 0x80067E44: sra         $t1, $v0, 2
    ctx->r9 = S32(SIGNED(ctx->r2) >> 2);
    // 0x80067E48: addu        $a0, $t1, $zero
    ctx->r4 = ADD32(ctx->r9, 0);
    // 0x80067E4C: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x80067E50: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80067E54: addiu       $v0, $v0, 0x6DC0
    ctx->r2 = ADD32(ctx->r2, 0X6DC0);
    // 0x80067E58: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80067E5C: subu        $t1, $a2, $v1
    ctx->r9 = SUB32(ctx->r6, ctx->r3);
    // 0x80067E60: sub.s       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x80067E64: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80067E68: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80067E6C: nop

    // 0x80067E70: bc1f        L_80067EAC
    if (!c1cs) {
        // 0x80067E74: addu        $a2, $a0, $zero
        ctx->r6 = ADD32(ctx->r4, 0);
            goto L_80067EAC;
    }
    // 0x80067E74: addu        $a2, $a0, $zero
    ctx->r6 = ADD32(ctx->r4, 0);
    // 0x80067E78: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80067E7C: lwc1        $f0, -0x3824($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3824);
    // 0x80067E80: mul.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80067E84: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80067E88: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x80067E8C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80067E90: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80067E94: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80067E98: sub.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80067E9C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80067EA0: lwc1        $f2, -0x3820($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3820);
    // 0x80067EA4: j           L_80067EE4
    // 0x80067EA8: add.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f2.fl;
        goto L_80067EE4;
    // 0x80067EA8: add.s       $f4, $f0, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f2.fl;
L_80067EAC:
    // 0x80067EAC: lwc1        $f0, 0x30($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80067EB0: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x80067EB4: nop

    // 0x80067EB8: bc1fl       L_80067EE8
    if (!c1cs) {
        // 0x80067EBC: add.s       $f4, $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f4.fl;
            goto L_80067EE8;
    }
    goto skip_1;
    // 0x80067EBC: add.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f4.fl;
    skip_1:
    // 0x80067EC0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80067EC4: lwc1        $f0, -0x381C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X381C);
    // 0x80067EC8: mul.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80067ECC: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80067ED0: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x80067ED4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80067ED8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80067EDC: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80067EE0: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
L_80067EE4:
    // 0x80067EE4: add.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f4.fl;
L_80067EE8:
    // 0x80067EE8: trunc.w.s   $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80067EEC: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x80067EF0: addu        $v0, $a0, $zero
    ctx->r2 = ADD32(ctx->r4, 0);
    // 0x80067EF4: mtc1        $a0, $f0
    ctx->f0.u32l = ctx->r4;
    // 0x80067EF8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80067EFC: bgez        $a0, L_80067F08
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80067F00: sub.s       $f4, $f4, $f0
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
            goto L_80067F08;
    }
    // 0x80067F00: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x80067F04: addiu       $v0, $a0, 0x3
    ctx->r2 = ADD32(ctx->r4, 0X3);
L_80067F08:
    // 0x80067F08: sra         $t0, $v0, 2
    ctx->r8 = S32(SIGNED(ctx->r2) >> 2);
    // 0x80067F0C: addu        $v1, $t0, $zero
    ctx->r3 = ADD32(ctx->r8, 0);
    // 0x80067F10: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80067F14: subu        $t0, $a0, $v0
    ctx->r8 = SUB32(ctx->r4, ctx->r2);
    // 0x80067F18: bltz        $a2, L_80067F54
    if (SIGNED(ctx->r6) < 0) {
        // 0x80067F1C: addu        $a0, $v1, $zero
        ctx->r4 = ADD32(ctx->r3, 0);
            goto L_80067F54;
    }
    // 0x80067F1C: addu        $a0, $v1, $zero
    ctx->r4 = ADD32(ctx->r3, 0);
    // 0x80067F20: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80067F24: addiu       $a1, $t2, 0x6DC0
    ctx->r5 = ADD32(ctx->r10, 0X6DC0);
    // 0x80067F28: lhu         $v1, 0x38($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X38);
    // 0x80067F2C: slt         $v0, $a2, $v1
    ctx->r2 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80067F30: beq         $v0, $zero, L_80067F54
    if (ctx->r2 == 0) {
        // 0x80067F34: nop
    
            goto L_80067F54;
    }
    // 0x80067F34: nop

    // 0x80067F38: bltz        $a0, L_80067F54
    if (SIGNED(ctx->r4) < 0) {
        // 0x80067F3C: nop
    
            goto L_80067F54;
    }
    // 0x80067F3C: nop

    // 0x80067F40: lhu         $v0, 0x3A($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X3A);
    // 0x80067F44: slt         $v0, $a0, $v0
    ctx->r2 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80067F48: mult        $a0, $v1
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80067F4C: bne         $v0, $zero, L_80067F88
    if (ctx->r2 != 0) {
        // 0x80067F50: nop
    
            goto L_80067F88;
    }
    // 0x80067F50: nop

L_80067F54:
    // 0x80067F54: beq         $a3, $zero, L_80067F7C
    if (ctx->r7 == 0) {
        // 0x80067F58: nop
    
            goto L_80067F7C;
    }
    // 0x80067F58: nop

    // 0x80067F5C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80067F60: lwc1        $f0, -0x3818($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3818);
    // 0x80067F64: swc1        $f12, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f12.u32l;
    // 0x80067F68: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x80067F6C: swc1        $f14, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f14.u32l;
    // 0x80067F70: sw          $zero, 0xC($a3)
    MEM_W(0XC, ctx->r7) = 0;
    // 0x80067F74: sw          $zero, 0x14($a3)
    MEM_W(0X14, ctx->r7) = 0;
    // 0x80067F78: swc1        $f0, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f0.u32l;
L_80067F7C:
    // 0x80067F7C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80067F80: jr          $ra
    // 0x80067F84: nop

    return;
    // 0x80067F84: nop

L_80067F88:
    // 0x80067F88: lwc1        $f2, 0x10($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80067F8C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80067F90: lwc1        $f0, -0x3814($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3814);
    // 0x80067F94: mul.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80067F98: sub.s       $f2, $f6, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80067F9C: lw          $v1, 0x6DC0($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X6DC0);
    // 0x80067FA0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80067FA4: mflo        $t3
    ctx->r11 = lo;
    // 0x80067FA8: addu        $v0, $a2, $t3
    ctx->r2 = ADD32(ctx->r6, ctx->r11);
    // 0x80067FAC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80067FB0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80067FB4: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x80067FB8: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80067FBC: andi        $v1, $v1, 0x1FFF
    ctx->r3 = ctx->r3 & 0X1FFF;
    // 0x80067FC0: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80067FC4: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80067FC8: lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X4);
    // 0x80067FCC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80067FD0: bc1f        L_80068074
    if (!c1cs) {
        // 0x80067FD4: addu        $a0, $v1, $v0
        ctx->r4 = ADD32(ctx->r3, ctx->r2);
            goto L_80068074;
    }
    // 0x80067FD4: addu        $a0, $v1, $v0
    ctx->r4 = ADD32(ctx->r3, ctx->r2);
    // 0x80067FD8: sll         $v1, $t0, 2
    ctx->r3 = S32(ctx->r8 << 2);
    // 0x80067FDC: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x80067FE0: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80067FE4: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x80067FE8: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x80067FEC: addu        $v1, $t1, $v1
    ctx->r3 = ADD32(ctx->r9, ctx->r3);
    // 0x80067FF0: addu        $v1, $a0, $v1
    ctx->r3 = ADD32(ctx->r4, ctx->r3);
    // 0x80067FF4: lb          $a1, 0x5($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X5);
    // 0x80067FF8: lb          $v0, 0x5($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X5);
    // 0x80067FFC: addiu       $v1, $t0, 0x1
    ctx->r3 = ADD32(ctx->r8, 0X1);
    // 0x80068000: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80068004: lwc1        $f16, -0x3810($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3810);
    // 0x80068008: subu        $a2, $v0, $a1
    ctx->r6 = SUB32(ctx->r2, ctx->r5);
    // 0x8006800C: mtc1        $a2, $f2
    ctx->f2.u32l = ctx->r6;
    // 0x80068010: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80068014: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80068018: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006801C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80068020: sub.s       $f0, $f16, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x80068024: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x80068028: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x8006802C: mul.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80068030: lb          $v0, 0x5($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X5);
    // 0x80068034: subu        $a0, $v0, $a1
    ctx->r4 = SUB32(ctx->r2, ctx->r5);
    // 0x80068038: mtc1        $a0, $f0
    ctx->f0.u32l = ctx->r4;
    // 0x8006803C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80068040: mul.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80068044: add.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x80068048: mtc1        $a1, $f0
    ctx->f0.u32l = ctx->r5;
    // 0x8006804C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80068050: beq         $a3, $zero, L_80068114
    if (ctx->r7 == 0) {
        // 0x80068054: add.s       $f8, $f8, $f0
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f0.fl;
            goto L_80068114;
    }
    // 0x80068054: add.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x80068058: mul.s       $f0, $f2, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8006805C: negu        $v0, $a0
    ctx->r2 = SUB32(0, ctx->r4);
    // 0x80068060: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x80068064: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80068068: mul.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x8006806C: j           L_8006810C
    // 0x80068070: swc1        $f16, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f16.u32l;
        goto L_8006810C;
    // 0x80068070: swc1        $f16, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f16.u32l;
L_80068074:
    // 0x80068074: addiu       $v1, $t0, 0x1
    ctx->r3 = ADD32(ctx->r8, 0X1);
    // 0x80068078: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8006807C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80068080: addu        $v1, $t1, $v0
    ctx->r3 = ADD32(ctx->r9, ctx->r2);
    // 0x80068084: addu        $v1, $a0, $v1
    ctx->r3 = ADD32(ctx->r4, ctx->r3);
    // 0x80068088: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8006808C: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x80068090: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x80068094: lb          $a1, 0x5($v1)
    ctx->r5 = MEM_B(ctx->r3, 0X5);
    // 0x80068098: lb          $v0, 0x5($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X5);
    // 0x8006809C: subu        $a2, $v0, $a1
    ctx->r6 = SUB32(ctx->r2, ctx->r5);
    // 0x800680A0: mtc1        $a2, $f0
    ctx->f0.u32l = ctx->r6;
    // 0x800680A4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800680A8: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x800680AC: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    // 0x800680B0: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800680B4: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x800680B8: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x800680BC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800680C0: lwc1        $f6, -0x380C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X380C);
    // 0x800680C4: lb          $v0, 0x5($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X5);
    // 0x800680C8: sub.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800680CC: subu        $a0, $v0, $a1
    ctx->r4 = SUB32(ctx->r2, ctx->r5);
    // 0x800680D0: mtc1        $a0, $f2
    ctx->f2.u32l = ctx->r4;
    // 0x800680D4: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800680D8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800680DC: add.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800680E0: mtc1        $a1, $f0
    ctx->f0.u32l = ctx->r5;
    // 0x800680E4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800680E8: beq         $a3, $zero, L_80068114
    if (ctx->r7 == 0) {
        // 0x800680EC: add.s       $f8, $f8, $f0
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f0.fl;
            goto L_80068114;
    }
    // 0x800680EC: add.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800680F0: negu        $v0, $a2
    ctx->r2 = SUB32(0, ctx->r6);
    // 0x800680F4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800680F8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800680FC: mul.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80068100: nop

    // 0x80068104: mul.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80068108: swc1        $f6, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f6.u32l;
L_8006810C:
    // 0x8006810C: swc1        $f0, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f0.u32l;
    // 0x80068110: swc1        $f2, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f2.u32l;
L_80068114:
    // 0x80068114: mul.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80068118: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006811C: lwc1        $f0, 0x6DD8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X6DD8);
    // 0x80068120: beq         $a3, $zero, L_80068178
    if (ctx->r7 == 0) {
        // 0x80068124: add.s       $f8, $f8, $f0
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f0.fl;
            goto L_80068178;
    }
    // 0x80068124: add.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x80068128: lwc1        $f6, 0xC($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8006812C: mul.s       $f2, $f6, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x80068130: lwc1        $f0, 0x14($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80068134: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80068138: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006813C: lwc1        $f4, -0x3808($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3808);
    // 0x80068140: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x80068144: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80068148: sqrt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = sqrtf(ctx->f2.fl);
    // 0x8006814C: lwc1        $f0, 0x10($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80068150: lwc1        $f2, 0x14($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80068154: div.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80068158: swc1        $f6, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f6.u32l;
    // 0x8006815C: swc1        $f12, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f12.u32l;
    // 0x80068160: swc1        $f8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f8.u32l;
    // 0x80068164: swc1        $f14, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f14.u32l;
    // 0x80068168: div.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8006816C: div.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80068170: swc1        $f0, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f0.u32l;
    // 0x80068174: swc1        $f2, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f2.u32l;
L_80068178:
    // 0x80068178: jr          $ra
    // 0x8006817C: mov.s       $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = ctx->f8.fl;
    return;
    // 0x8006817C: mov.s       $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = ctx->f8.fl;
;}
RECOMP_FUNC void func_80068180(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068180: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80068184: sdc1        $f30, 0x70($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X70, ctx->r29);
    // 0x80068188: mov.s       $f30, $f12
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 12);
    ctx->f30.fl = ctx->f12.fl;
    // 0x8006818C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80068190: addiu       $v0, $v0, 0x6DC0
    ctx->r2 = ADD32(ctx->r2, 0X6DC0);
    // 0x80068194: sdc1        $f28, 0x68($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X68, ctx->r29);
    // 0x80068198: sdc1        $f26, 0x60($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X60, ctx->r29);
    // 0x8006819C: sdc1        $f24, 0x58($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X58, ctx->r29);
    // 0x800681A0: sdc1        $f22, 0x50($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X50, ctx->r29);
    // 0x800681A4: sdc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X48, ctx->r29);
    // 0x800681A8: swc1        $f14, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f14.u32l;
    // 0x800681AC: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800681B0: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800681B4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800681B8: lwc1        $f2, -0x3804($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3804);
    // 0x800681BC: sub.s       $f14, $f30, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f30.fl - ctx->f0.fl;
    // 0x800681C0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800681C4: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x800681C8: nop

    // 0x800681CC: bc1f        L_80068208
    if (!c1cs) {
        // 0x800681D0: div.s       $f26, $f2, $f4
        CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f26.fl = DIV_S(ctx->f2.fl, ctx->f4.fl);
            goto L_80068208;
    }
    // 0x800681D0: div.s       $f26, $f2, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f26.fl = DIV_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800681D4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800681D8: lwc1        $f0, -0x3800($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3800);
    // 0x800681DC: mul.s       $f0, $f14, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800681E0: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800681E4: mfc1        $v0, $f22
    ctx->r2 = (int32_t)ctx->f22.u32l;
    // 0x800681E8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800681EC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800681F0: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800681F4: sub.s       $f0, $f14, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x800681F8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800681FC: lwc1        $f2, -0x37FC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X37FC);
    // 0x80068200: j           L_80068240
    // 0x80068204: add.s       $f14, $f0, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f2.fl;
        goto L_80068240;
    // 0x80068204: add.s       $f14, $f0, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f2.fl;
L_80068208:
    // 0x80068208: lwc1        $f0, 0x24($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8006820C: c.le.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl <= ctx->f14.fl;
    // 0x80068210: nop

    // 0x80068214: bc1fl       L_80068244
    if (!c1cs) {
        // 0x80068218: add.s       $f14, $f14, $f14
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f14.fl;
            goto L_80068244;
    }
    goto skip_0;
    // 0x80068218: add.s       $f14, $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f14.fl;
    skip_0:
    // 0x8006821C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80068220: lwc1        $f0, -0x37F8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X37F8);
    // 0x80068224: mul.s       $f0, $f14, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80068228: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8006822C: mfc1        $v0, $f22
    ctx->r2 = (int32_t)ctx->f22.u32l;
    // 0x80068230: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80068234: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80068238: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8006823C: sub.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f0.fl;
L_80068240:
    // 0x80068240: add.s       $f14, $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f14.fl;
L_80068244:
    // 0x80068244: trunc.w.s   $f22, $f14
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    ctx->f22.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x80068248: mfc1        $t2, $f22
    ctx->r10 = (int32_t)ctx->f22.u32l;
    // 0x8006824C: addu        $v0, $t2, $zero
    ctx->r2 = ADD32(ctx->r10, 0);
    // 0x80068250: mtc1        $t2, $f0
    ctx->f0.u32l = ctx->r10;
    // 0x80068254: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80068258: bgez        $t2, L_80068264
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8006825C: sub.s       $f14, $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f0.fl;
            goto L_80068264;
    }
    // 0x8006825C: sub.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x80068260: addiu       $v0, $t2, 0x3
    ctx->r2 = ADD32(ctx->r10, 0X3);
L_80068264:
    // 0x80068264: sra         $t3, $v0, 2
    ctx->r11 = S32(SIGNED(ctx->r2) >> 2);
    // 0x80068268: addu        $a0, $t3, $zero
    ctx->r4 = ADD32(ctx->r11, 0);
    // 0x8006826C: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x80068270: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80068274: addiu       $v0, $v0, 0x6DC0
    ctx->r2 = ADD32(ctx->r2, 0X6DC0);
    // 0x80068278: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8006827C: lwc1        $f22, 0x7C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80068280: subu        $t3, $t2, $v1
    ctx->r11 = SUB32(ctx->r10, ctx->r3);
    // 0x80068284: sub.s       $f12, $f22, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f22.fl - ctx->f0.fl;
    // 0x80068288: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8006828C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80068290: nop

    // 0x80068294: bc1f        L_800682D0
    if (!c1cs) {
        // 0x80068298: addu        $t2, $a0, $zero
        ctx->r10 = ADD32(ctx->r4, 0);
            goto L_800682D0;
    }
    // 0x80068298: addu        $t2, $a0, $zero
    ctx->r10 = ADD32(ctx->r4, 0);
    // 0x8006829C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800682A0: lwc1        $f0, -0x37F4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X37F4);
    // 0x800682A4: mul.s       $f0, $f12, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800682A8: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800682AC: mfc1        $v0, $f22
    ctx->r2 = (int32_t)ctx->f22.u32l;
    // 0x800682B0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800682B4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800682B8: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800682BC: sub.s       $f0, $f12, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x800682C0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800682C4: lwc1        $f2, -0x37F0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X37F0);
    // 0x800682C8: j           L_80068308
    // 0x800682CC: add.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f2.fl;
        goto L_80068308;
    // 0x800682CC: add.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f2.fl;
L_800682D0:
    // 0x800682D0: lwc1        $f0, 0x30($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X30);
    // 0x800682D4: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x800682D8: nop

    // 0x800682DC: bc1fl       L_8006830C
    if (!c1cs) {
        // 0x800682E0: add.s       $f12, $f12, $f12
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f12.fl;
            goto L_8006830C;
    }
    goto skip_1;
    // 0x800682E0: add.s       $f12, $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f12.fl;
    skip_1:
    // 0x800682E4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800682E8: lwc1        $f0, -0x37EC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X37EC);
    // 0x800682EC: mul.s       $f0, $f12, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800682F0: trunc.w.s   $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800682F4: mfc1        $v0, $f22
    ctx->r2 = (int32_t)ctx->f22.u32l;
    // 0x800682F8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800682FC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80068300: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80068304: sub.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f0.fl;
L_80068308:
    // 0x80068308: add.s       $f12, $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f12.fl;
L_8006830C:
    // 0x8006830C: trunc.w.s   $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    ctx->f22.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x80068310: mfc1        $t0, $f22
    ctx->r8 = (int32_t)ctx->f22.u32l;
    // 0x80068314: addu        $v0, $t0, $zero
    ctx->r2 = ADD32(ctx->r8, 0);
    // 0x80068318: mtc1        $t0, $f0
    ctx->f0.u32l = ctx->r8;
    // 0x8006831C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80068320: bgez        $t0, L_8006832C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80068324: sub.s       $f12, $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f0.fl;
            goto L_8006832C;
    }
    // 0x80068324: sub.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x80068328: addiu       $v0, $t0, 0x3
    ctx->r2 = ADD32(ctx->r8, 0X3);
L_8006832C:
    // 0x8006832C: sra         $a2, $v0, 2
    ctx->r6 = S32(SIGNED(ctx->r2) >> 2);
    // 0x80068330: addu        $v1, $a2, $zero
    ctx->r3 = ADD32(ctx->r6, 0);
    // 0x80068334: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80068338: subu        $a2, $t0, $v0
    ctx->r6 = SUB32(ctx->r8, ctx->r2);
    // 0x8006833C: bltz        $t2, L_80068378
    if (SIGNED(ctx->r10) < 0) {
        // 0x80068340: addu        $t0, $v1, $zero
        ctx->r8 = ADD32(ctx->r3, 0);
            goto L_80068378;
    }
    // 0x80068340: addu        $t0, $v1, $zero
    ctx->r8 = ADD32(ctx->r3, 0);
    // 0x80068344: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80068348: addiu       $a1, $a0, 0x6DC0
    ctx->r5 = ADD32(ctx->r4, 0X6DC0);
    // 0x8006834C: lhu         $v1, 0x38($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X38);
    // 0x80068350: slt         $v0, $t2, $v1
    ctx->r2 = SIGNED(ctx->r10) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80068354: beq         $v0, $zero, L_80068378
    if (ctx->r2 == 0) {
        // 0x80068358: nop
    
            goto L_80068378;
    }
    // 0x80068358: nop

    // 0x8006835C: bltz        $t0, L_80068378
    if (SIGNED(ctx->r8) < 0) {
        // 0x80068360: nop
    
            goto L_80068378;
    }
    // 0x80068360: nop

    // 0x80068364: lhu         $v0, 0x3A($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X3A);
    // 0x80068368: slt         $v0, $t0, $v0
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006836C: mult        $t0, $v1
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80068370: bne         $v0, $zero, L_800683B0
    if (ctx->r2 != 0) {
        // 0x80068374: nop
    
            goto L_800683B0;
    }
    // 0x80068374: nop

L_80068378:
    // 0x80068378: beq         $a3, $zero, L_800683A4
    if (ctx->r7 == 0) {
        // 0x8006837C: nop
    
            goto L_800683A4;
    }
    // 0x8006837C: nop

    // 0x80068380: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80068384: lwc1        $f0, -0x37E8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X37E8);
    // 0x80068388: lwc1        $f22, 0x7C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8006838C: swc1        $f30, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f30.u32l;
    // 0x80068390: sw          $zero, 0x4($a3)
    MEM_W(0X4, ctx->r7) = 0;
    // 0x80068394: sw          $zero, 0xC($a3)
    MEM_W(0XC, ctx->r7) = 0;
    // 0x80068398: sw          $zero, 0x14($a3)
    MEM_W(0X14, ctx->r7) = 0;
    // 0x8006839C: swc1        $f22, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f22.u32l;
    // 0x800683A0: swc1        $f0, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f0.u32l;
L_800683A4:
    // 0x800683A4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800683A8: j           L_80068A70
    // 0x800683AC: nop

        goto L_80068A70;
    // 0x800683AC: nop

L_800683B0:
    // 0x800683B0: lw          $t5, 0x6DC0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X6DC0);
    // 0x800683B4: lw          $t4, 0x4($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X4);
    // 0x800683B8: mflo        $t6
    ctx->r14 = lo;
    // 0x800683BC: addu        $v0, $t2, $t6
    ctx->r2 = ADD32(ctx->r10, ctx->r14);
    // 0x800683C0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800683C4: addu        $v0, $v0, $t5
    ctx->r2 = ADD32(ctx->r2, ctx->r13);
    // 0x800683C8: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x800683CC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800683D0: lwc1        $f0, -0x37E4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X37E4);
    // 0x800683D4: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
    // 0x800683D8: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x800683DC: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800683E0: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800683E4: addu        $t1, $t4, $v1
    ctx->r9 = ADD32(ctx->r12, ctx->r3);
    // 0x800683E8: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x800683EC: addu        $a0, $v0, $a2
    ctx->r4 = ADD32(ctx->r2, ctx->r6);
    // 0x800683F0: addu        $v0, $t3, $a0
    ctx->r2 = ADD32(ctx->r11, ctx->r4);
    // 0x800683F4: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x800683F8: lbu         $v0, 0x5($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5);
    // 0x800683FC: sb          $v0, 0x5($sp)
    MEM_B(0X5, ctx->r29) = ctx->r2;
    // 0x80068400: addiu       $v0, $a0, 0x1
    ctx->r2 = ADD32(ctx->r4, 0X1);
    // 0x80068404: addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // 0x80068408: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x8006840C: lbu         $v0, 0x5($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5);
    // 0x80068410: addiu       $v1, $a2, 0x1
    ctx->r3 = ADD32(ctx->r6, 0X1);
    // 0x80068414: sb          $v0, 0x6($sp)
    MEM_B(0X6, ctx->r29) = ctx->r2;
    // 0x80068418: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8006841C: addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // 0x80068420: addu        $v0, $t3, $v1
    ctx->r2 = ADD32(ctx->r11, ctx->r3);
    // 0x80068424: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x80068428: lbu         $v0, 0x5($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5);
    // 0x8006842C: sb          $v0, 0x9($sp)
    MEM_B(0X9, ctx->r29) = ctx->r2;
    // 0x80068430: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x80068434: lwc1        $f2, 0x10($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80068438: addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // 0x8006843C: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80068440: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x80068444: lbu         $v0, 0x5($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5);
    // 0x80068448: sb          $v0, 0xA($sp)
    MEM_B(0XA, ctx->r29) = ctx->r2;
    // 0x8006844C: bne         $t3, $zero, L_800684BC
    if (ctx->r11 != 0) {
        // 0x80068450: swc1        $f2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
            goto L_800684BC;
    }
    // 0x80068450: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x80068454: blez        $t2, L_8006848C
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80068458: addu        $a0, $t1, $zero
        ctx->r4 = ADD32(ctx->r9, 0);
            goto L_8006848C;
    }
    // 0x80068458: addu        $a0, $t1, $zero
    ctx->r4 = ADD32(ctx->r9, 0);
    // 0x8006845C: lhu         $v0, 0x38($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X38);
    // 0x80068460: mult        $t0, $v0
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80068464: mflo        $t6
    ctx->r14 = lo;
    // 0x80068468: addu        $v0, $t6, $t2
    ctx->r2 = ADD32(ctx->r14, ctx->r10);
    // 0x8006846C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80068470: addu        $v0, $v0, $t5
    ctx->r2 = ADD32(ctx->r2, ctx->r13);
    // 0x80068474: lhu         $v1, -0x2($v0)
    ctx->r3 = MEM_HU(ctx->r2, -0X2);
    // 0x80068478: andi        $v1, $v1, 0x1FFF
    ctx->r3 = ctx->r3 & 0X1FFF;
    // 0x8006847C: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80068480: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80068484: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80068488: addu        $a0, $t4, $v0
    ctx->r4 = ADD32(ctx->r12, ctx->r2);
L_8006848C:
    // 0x8006848C: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x80068490: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80068494: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x80068498: lbu         $v0, 0x7($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7);
    // 0x8006849C: addiu       $v1, $a2, 0x1
    ctx->r3 = ADD32(ctx->r6, 0X1);
    // 0x800684A0: sb          $v0, 0x4($sp)
    MEM_B(0X4, ctx->r29) = ctx->r2;
    // 0x800684A4: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x800684A8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800684AC: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x800684B0: lbu         $v0, 0x7($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X7);
    // 0x800684B4: j           L_800684E4
    // 0x800684B8: sb          $v0, 0x8($sp)
    MEM_B(0X8, ctx->r29) = ctx->r2;
        goto L_800684E4;
    // 0x800684B8: sb          $v0, 0x8($sp)
    MEM_B(0X8, ctx->r29) = ctx->r2;
L_800684BC:
    // 0x800684BC: addiu       $v0, $a0, -0x1
    ctx->r2 = ADD32(ctx->r4, -0X1);
    // 0x800684C0: addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // 0x800684C4: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x800684C8: lbu         $v0, 0x5($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5);
    // 0x800684CC: sb          $v0, 0x4($sp)
    MEM_B(0X4, ctx->r29) = ctx->r2;
    // 0x800684D0: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x800684D4: addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // 0x800684D8: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x800684DC: lbu         $v0, 0x5($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5);
    // 0x800684E0: sb          $v0, 0x8($sp)
    MEM_B(0X8, ctx->r29) = ctx->r2;
L_800684E4:
    // 0x800684E4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800684E8: bne         $t3, $v0, L_80068578
    if (ctx->r11 != ctx->r2) {
        // 0x800684EC: sll         $v0, $a2, 2
        ctx->r2 = S32(ctx->r6 << 2);
            goto L_80068578;
    }
    // 0x800684EC: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x800684F0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800684F4: addiu       $a1, $a0, 0x6DC0
    ctx->r5 = ADD32(ctx->r4, 0X6DC0);
    // 0x800684F8: lhu         $v1, 0x38($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X38);
    // 0x800684FC: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x80068500: slt         $v0, $t2, $v0
    ctx->r2 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80068504: mult        $t0, $v1
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80068508: beq         $v0, $zero, L_80068544
    if (ctx->r2 == 0) {
        // 0x8006850C: nop
    
            goto L_80068544;
    }
    // 0x8006850C: nop

    // 0x80068510: lw          $v1, 0x6DC0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X6DC0);
    // 0x80068514: mflo        $t6
    ctx->r14 = lo;
    // 0x80068518: addu        $v0, $t6, $t2
    ctx->r2 = ADD32(ctx->r14, ctx->r10);
    // 0x8006851C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80068520: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80068524: lhu         $v0, 0x2($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X2);
    // 0x80068528: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
    // 0x8006852C: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80068530: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80068534: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x80068538: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8006853C: j           L_80068548
    // 0x80068540: addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
        goto L_80068548;
    // 0x80068540: addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
L_80068544:
    // 0x80068544: addu        $a0, $t1, $zero
    ctx->r4 = ADD32(ctx->r9, 0);
L_80068548:
    // 0x80068548: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x8006854C: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x80068550: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x80068554: lbu         $v0, 0x6($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6);
    // 0x80068558: addiu       $v1, $a2, 0x1
    ctx->r3 = ADD32(ctx->r6, 0X1);
    // 0x8006855C: sb          $v0, 0x7($sp)
    MEM_B(0X7, ctx->r29) = ctx->r2;
    // 0x80068560: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80068564: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80068568: addu        $v0, $a0, $v0
    ctx->r2 = ADD32(ctx->r4, ctx->r2);
    // 0x8006856C: lbu         $v0, 0x6($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6);
    // 0x80068570: j           L_800685B0
    // 0x80068574: sb          $v0, 0xB($sp)
    MEM_B(0XB, ctx->r29) = ctx->r2;
        goto L_800685B0;
    // 0x80068574: sb          $v0, 0xB($sp)
    MEM_B(0XB, ctx->r29) = ctx->r2;
L_80068578:
    // 0x80068578: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8006857C: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x80068580: addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // 0x80068584: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x80068588: lbu         $v0, 0x5($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5);
    // 0x8006858C: addiu       $v1, $a2, 0x1
    ctx->r3 = ADD32(ctx->r6, 0X1);
    // 0x80068590: sb          $v0, 0x7($sp)
    MEM_B(0X7, ctx->r29) = ctx->r2;
    // 0x80068594: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x80068598: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006859C: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800685A0: addu        $v0, $t3, $v0
    ctx->r2 = ADD32(ctx->r11, ctx->r2);
    // 0x800685A4: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x800685A8: lbu         $v0, 0x5($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5);
    // 0x800685AC: sb          $v0, 0xB($sp)
    MEM_B(0XB, ctx->r29) = ctx->r2;
L_800685B0:
    // 0x800685B0: bne         $a2, $zero, L_80068624
    if (ctx->r6 != 0) {
        // 0x800685B4: addiu       $v0, $a2, -0x1
        ctx->r2 = ADD32(ctx->r6, -0X1);
            goto L_80068624;
    }
    // 0x800685B4: addiu       $v0, $a2, -0x1
    ctx->r2 = ADD32(ctx->r6, -0X1);
    // 0x800685B8: blez        $t0, L_80068604
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800685BC: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_80068604;
    }
    // 0x800685BC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800685C0: addiu       $a1, $a0, 0x6DC0
    ctx->r5 = ADD32(ctx->r4, 0X6DC0);
    // 0x800685C4: lhu         $v1, 0x38($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X38);
    // 0x800685C8: addiu       $v0, $t0, -0x1
    ctx->r2 = ADD32(ctx->r8, -0X1);
    // 0x800685CC: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800685D0: lw          $v1, 0x6DC0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X6DC0);
    // 0x800685D4: mflo        $t6
    ctx->r14 = lo;
    // 0x800685D8: addu        $v0, $t2, $t6
    ctx->r2 = ADD32(ctx->r10, ctx->r14);
    // 0x800685DC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800685E0: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800685E4: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x800685E8: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
    // 0x800685EC: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x800685F0: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800685F4: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    // 0x800685F8: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800685FC: j           L_80068608
    // 0x80068600: addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
        goto L_80068608;
    // 0x80068600: addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
L_80068604:
    // 0x80068604: addu        $a0, $t1, $zero
    ctx->r4 = ADD32(ctx->r9, 0);
L_80068608:
    // 0x80068608: addu        $v0, $a0, $t3
    ctx->r2 = ADD32(ctx->r4, ctx->r11);
    // 0x8006860C: lbu         $v0, 0xF($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XF);
    // 0x80068610: sb          $v0, 0x1($sp)
    MEM_B(0X1, ctx->r29) = ctx->r2;
    // 0x80068614: addu        $v0, $t3, $a0
    ctx->r2 = ADD32(ctx->r11, ctx->r4);
    // 0x80068618: lbu         $v0, 0x10($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X10);
    // 0x8006861C: j           L_80068650
    // 0x80068620: sb          $v0, 0x2($sp)
    MEM_B(0X2, ctx->r29) = ctx->r2;
        goto L_80068650;
    // 0x80068620: sb          $v0, 0x2($sp)
    MEM_B(0X2, ctx->r29) = ctx->r2;
L_80068624:
    // 0x80068624: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80068628: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8006862C: addu        $v0, $t3, $v1
    ctx->r2 = ADD32(ctx->r11, ctx->r3);
    // 0x80068630: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x80068634: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80068638: addu        $v1, $t3, $v1
    ctx->r3 = ADD32(ctx->r11, ctx->r3);
    // 0x8006863C: lbu         $v0, 0x5($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5);
    // 0x80068640: addu        $v1, $t1, $v1
    ctx->r3 = ADD32(ctx->r9, ctx->r3);
    // 0x80068644: sb          $v0, 0x1($sp)
    MEM_B(0X1, ctx->r29) = ctx->r2;
    // 0x80068648: lbu         $v0, 0x5($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X5);
    // 0x8006864C: sb          $v0, 0x2($sp)
    MEM_B(0X2, ctx->r29) = ctx->r2;
L_80068650:
    // 0x80068650: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80068654: bne         $a2, $v0, L_800686D4
    if (ctx->r6 != ctx->r2) {
        // 0x80068658: addiu       $v0, $a2, 0x2
        ctx->r2 = ADD32(ctx->r6, 0X2);
            goto L_800686D4;
    }
    // 0x80068658: addiu       $v0, $a2, 0x2
    ctx->r2 = ADD32(ctx->r6, 0X2);
    // 0x8006865C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80068660: addiu       $a0, $a1, 0x6DC0
    ctx->r4 = ADD32(ctx->r5, 0X6DC0);
    // 0x80068664: lhu         $v0, 0x3A($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X3A);
    // 0x80068668: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8006866C: slt         $v0, $t0, $v0
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80068670: beq         $v0, $zero, L_800686B4
    if (ctx->r2 == 0) {
        // 0x80068674: addiu       $v0, $t0, 0x1
        ctx->r2 = ADD32(ctx->r8, 0X1);
            goto L_800686B4;
    }
    // 0x80068674: addiu       $v0, $t0, 0x1
    ctx->r2 = ADD32(ctx->r8, 0X1);
    // 0x80068678: lhu         $v1, 0x38($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X38);
    // 0x8006867C: mult        $v0, $v1
    result = S64(S32(ctx->r2)) * S64(S32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80068680: lw          $v1, 0x6DC0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X6DC0);
    // 0x80068684: mflo        $t6
    ctx->r14 = lo;
    // 0x80068688: addu        $v0, $t2, $t6
    ctx->r2 = ADD32(ctx->r10, ctx->r14);
    // 0x8006868C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80068690: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80068694: lhu         $v0, 0x0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X0);
    // 0x80068698: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
    // 0x8006869C: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x800686A0: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x800686A4: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x800686A8: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800686AC: j           L_800686B8
    // 0x800686B0: addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
        goto L_800686B8;
    // 0x800686B0: addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
L_800686B4:
    // 0x800686B4: addu        $a0, $t1, $zero
    ctx->r4 = ADD32(ctx->r9, 0);
L_800686B8:
    // 0x800686B8: addu        $v0, $a0, $t3
    ctx->r2 = ADD32(ctx->r4, ctx->r11);
    // 0x800686BC: lbu         $v0, 0xA($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XA);
    // 0x800686C0: sb          $v0, 0xD($sp)
    MEM_B(0XD, ctx->r29) = ctx->r2;
    // 0x800686C4: addu        $v0, $t3, $a0
    ctx->r2 = ADD32(ctx->r11, ctx->r4);
    // 0x800686C8: lbu         $v0, 0xB($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB);
    // 0x800686CC: j           L_80068700
    // 0x800686D0: sb          $v0, 0xE($sp)
    MEM_B(0XE, ctx->r29) = ctx->r2;
        goto L_80068700;
    // 0x800686D0: sb          $v0, 0xE($sp)
    MEM_B(0XE, ctx->r29) = ctx->r2;
L_800686D4:
    // 0x800686D4: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x800686D8: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x800686DC: addu        $v0, $t3, $v1
    ctx->r2 = ADD32(ctx->r11, ctx->r3);
    // 0x800686E0: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x800686E4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800686E8: addu        $v1, $t3, $v1
    ctx->r3 = ADD32(ctx->r11, ctx->r3);
    // 0x800686EC: lbu         $v0, 0x5($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X5);
    // 0x800686F0: addu        $v1, $t1, $v1
    ctx->r3 = ADD32(ctx->r9, ctx->r3);
    // 0x800686F4: sb          $v0, 0xD($sp)
    MEM_B(0XD, ctx->r29) = ctx->r2;
    // 0x800686F8: lbu         $v0, 0x5($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X5);
    // 0x800686FC: sb          $v0, 0xE($sp)
    MEM_B(0XE, ctx->r29) = ctx->r2;
L_80068700:
    // 0x80068700: lbu         $v0, 0x4($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X4);
    // 0x80068704: lbu         $v1, 0x6($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X6);
    // 0x80068708: lb          $a0, 0x9($sp)
    ctx->r4 = MEM_B(ctx->r29, 0X9);
    // 0x8006870C: mul.s       $f20, $f26, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f20.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x80068710: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80068714: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80068718: sll         $v1, $v1, 24
    ctx->r3 = S32(ctx->r3 << 24);
    // 0x8006871C: sra         $v1, $v1, 24
    ctx->r3 = S32(SIGNED(ctx->r3) >> 24);
    // 0x80068720: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80068724: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80068728: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8006872C: lbu         $v0, 0x1($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1);
    // 0x80068730: mul.s       $f0, $f10, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x80068734: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80068738: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8006873C: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80068740: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x80068744: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80068748: mul.s       $f2, $f16, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8006874C: add.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x80068750: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80068754: sqrt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = sqrtf(ctx->f0.fl);
    // 0x80068758: lb          $v0, 0xB($sp)
    ctx->r2 = MEM_B(ctx->r29, 0XB);
    // 0x8006875C: div.s       $f24, $f10, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f24.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80068760: subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
    // 0x80068764: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80068768: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8006876C: mul.s       $f0, $f10, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x80068770: lb          $v0, 0xE($sp)
    ctx->r2 = MEM_B(ctx->r29, 0XE);
    // 0x80068774: div.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f8.fl);
    // 0x80068778: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // 0x8006877C: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x80068780: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80068784: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80068788: div.s       $f2, $f26, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f26.fl, ctx->f8.fl);
    // 0x8006878C: swc1        $f24, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f24.u32l;
    // 0x80068790: add.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x80068794: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    // 0x80068798: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x8006879C: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x800687A0: sqrt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = sqrtf(ctx->f0.fl);
    // 0x800687A4: div.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800687A8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800687AC: div.s       $f0, $f26, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f26.fl, ctx->f8.fl);
    // 0x800687B0: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x800687B4: div.s       $f0, $f16, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f16.fl, ctx->f8.fl);
    // 0x800687B8: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x800687BC: sub.s       $f2, $f14, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f14.fl - ctx->f12.fl;
    // 0x800687C0: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x800687C4: c.le.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl <= ctx->f2.fl;
    // 0x800687C8: nop

    // 0x800687CC: bc1f        L_800688F4
    if (!c1cs) {
        // 0x800687D0: swc1        $f0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
            goto L_800688F4;
    }
    // 0x800687D0: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x800687D4: lbu         $v0, 0x5($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X5);
    // 0x800687D8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800687DC: lwc1        $f28, -0x37E0($at)
    ctx->f28.u32l = MEM_W(ctx->r1, -0X37E0);
    // 0x800687E0: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x800687E4: sra         $a0, $v0, 24
    ctx->r4 = S32(SIGNED(ctx->r2) >> 24);
    // 0x800687E8: sub.s       $f6, $f28, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f28.fl - ctx->f14.fl;
    // 0x800687EC: subu        $t2, $a0, $v1
    ctx->r10 = SUB32(ctx->r4, ctx->r3);
    // 0x800687F0: mtc1        $t2, $f0
    ctx->f0.u32l = ctx->r10;
    // 0x800687F4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800687F8: mul.s       $f18, $f6, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800687FC: lb          $a1, 0xA($sp)
    ctx->r5 = MEM_B(ctx->r29, 0XA);
    // 0x80068800: subu        $t0, $a1, $v1
    ctx->r8 = SUB32(ctx->r5, ctx->r3);
    // 0x80068804: mtc1        $t0, $f0
    ctx->f0.u32l = ctx->r8;
    // 0x80068808: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8006880C: mul.s       $f0, $f12, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80068810: add.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x80068814: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x80068818: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8006881C: beq         $a3, $zero, L_80068A44
    if (ctx->r7 == 0) {
        // 0x80068820: add.s       $f18, $f18, $f0
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f0.fl;
            goto L_80068A44;
    }
    // 0x80068820: add.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x80068824: lbu         $v0, 0x7($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X7);
    // 0x80068828: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x8006882C: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x80068830: subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
    // 0x80068834: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80068838: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8006883C: lbu         $v0, 0x2($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X2);
    // 0x80068840: mul.s       $f0, $f10, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x80068844: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80068848: sra         $v0, $v0, 24
    ctx->r2 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8006884C: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x80068850: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x80068854: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80068858: mul.s       $f2, $f16, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8006885C: add.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x80068860: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80068864: sqrt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = sqrtf(ctx->f0.fl);
    // 0x80068868: div.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8006886C: sub.s       $f2, $f24, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f24.fl - ctx->f0.fl;
    // 0x80068870: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80068874: lwc1        $f22, 0x40($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80068878: sub.s       $f4, $f22, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f22.fl - ctx->f0.fl;
    // 0x8006887C: mul.s       $f4, $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80068880: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80068884: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80068888: div.s       $f2, $f26, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f26.fl, ctx->f8.fl);
    // 0x8006888C: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x80068890: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80068894: div.s       $f2, $f16, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f16.fl, ctx->f8.fl);
    // 0x80068898: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x8006889C: swc1        $f0, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f0.u32l;
    // 0x800688A0: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800688A4: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800688A8: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800688AC: mul.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800688B0: lwc1        $f2, 0x2C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800688B4: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800688B8: mul.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x800688BC: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x800688C0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800688C4: swc1        $f0, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f0.u32l;
    // 0x800688C8: lwc1        $f2, 0x10($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X10);
    // 0x800688CC: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800688D0: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800688D4: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800688D8: sub.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800688DC: mul.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800688E0: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800688E4: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800688E8: mul.s       $f4, $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800688EC: j           L_800689FC
    // 0x800688F0: nop

        goto L_800689FC;
    // 0x800688F0: nop

L_800688F4:
    // 0x800688F4: lb          $a1, 0xA($sp)
    ctx->r5 = MEM_B(ctx->r29, 0XA);
    // 0x800688F8: subu        $t2, $a1, $a0
    ctx->r10 = SUB32(ctx->r5, ctx->r4);
    // 0x800688FC: mtc1        $t2, $f0
    ctx->f0.u32l = ctx->r10;
    // 0x80068900: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80068904: mul.s       $f18, $f14, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80068908: lbu         $v0, 0x5($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X5);
    // 0x8006890C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80068910: lwc1        $f28, -0x37DC($at)
    ctx->f28.u32l = MEM_W(ctx->r1, -0X37DC);
    // 0x80068914: sll         $v0, $v0, 24
    ctx->r2 = S32(ctx->r2 << 24);
    // 0x80068918: sra         $v1, $v0, 24
    ctx->r3 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8006891C: sub.s       $f6, $f28, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f28.fl - ctx->f12.fl;
    // 0x80068920: subu        $t0, $v1, $a0
    ctx->r8 = SUB32(ctx->r3, ctx->r4);
    // 0x80068924: mtc1        $t0, $f0
    ctx->f0.u32l = ctx->r8;
    // 0x80068928: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8006892C: mul.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80068930: add.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x80068934: mtc1        $a0, $f0
    ctx->f0.u32l = ctx->r4;
    // 0x80068938: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8006893C: beq         $a3, $zero, L_80068A44
    if (ctx->r7 == 0) {
        // 0x80068940: add.s       $f18, $f18, $f0
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f0.fl;
            goto L_80068A44;
    }
    // 0x80068940: add.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x80068944: lb          $v0, 0x8($sp)
    ctx->r2 = MEM_B(ctx->r29, 0X8);
    // 0x80068948: subu        $v0, $v0, $a1
    ctx->r2 = SUB32(ctx->r2, ctx->r5);
    // 0x8006894C: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80068950: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80068954: mul.s       $f0, $f10, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x80068958: lb          $v0, 0xD($sp)
    ctx->r2 = MEM_B(ctx->r29, 0XD);
    // 0x8006895C: subu        $v0, $v1, $v0
    ctx->r2 = SUB32(ctx->r3, ctx->r2);
    // 0x80068960: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x80068964: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80068968: mul.s       $f2, $f16, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8006896C: add.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x80068970: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80068974: sqrt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = sqrtf(ctx->f0.fl);
    // 0x80068978: div.s       $f0, $f10, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8006897C: sub.s       $f4, $f24, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f24.fl - ctx->f0.fl;
    // 0x80068980: mul.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80068984: lwc1        $f22, 0x40($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80068988: sub.s       $f2, $f22, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f22.fl - ctx->f0.fl;
    // 0x8006898C: mul.s       $f2, $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x80068990: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80068994: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80068998: div.s       $f2, $f26, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f26.fl, ctx->f8.fl);
    // 0x8006899C: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x800689A0: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x800689A4: div.s       $f2, $f16, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f16.fl, ctx->f8.fl);
    // 0x800689A8: swc1        $f2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f2.u32l;
    // 0x800689AC: swc1        $f0, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f0.u32l;
    // 0x800689B0: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800689B4: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800689B8: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800689BC: mul.s       $f4, $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800689C0: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800689C4: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800689C8: mul.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800689CC: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x800689D0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x800689D4: swc1        $f0, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f0.u32l;
    // 0x800689D8: lwc1        $f2, 0x10($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X10);
    // 0x800689DC: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800689E0: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800689E4: lwc1        $f0, 0x18($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800689E8: sub.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800689EC: mul.s       $f8, $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800689F0: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800689F4: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800689F8: mul.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
L_800689FC:
    // 0x800689FC: lwc1        $f10, 0xC($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80068A00: mul.s       $f6, $f10, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x80068A04: add.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80068A08: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80068A0C: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80068A10: add.s       $f6, $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x80068A14: swc1        $f0, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f0.u32l;
    // 0x80068A18: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80068A1C: sqrt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = sqrtf(ctx->f6.fl);
    // 0x80068A20: div.s       $f8, $f28, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f28.fl, ctx->f0.fl);
    // 0x80068A24: mul.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80068A28: lwc1        $f2, 0x10($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80068A2C: mul.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80068A30: lwc1        $f0, 0x14($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80068A34: mul.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80068A38: swc1        $f10, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f10.u32l;
    // 0x80068A3C: swc1        $f2, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f2.u32l;
    // 0x80068A40: swc1        $f0, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f0.u32l;
L_80068A44:
    // 0x80068A44: lwc1        $f22, 0x38($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80068A48: mul.s       $f18, $f18, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x80068A4C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80068A50: lwc1        $f0, 0x6DD8($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X6DD8);
    // 0x80068A54: beq         $a3, $zero, L_80068A6C
    if (ctx->r7 == 0) {
        // 0x80068A58: add.s       $f18, $f18, $f0
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f0.fl;
            goto L_80068A6C;
    }
    // 0x80068A58: add.s       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x80068A5C: lwc1        $f22, 0x7C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80068A60: swc1        $f30, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f30.u32l;
    // 0x80068A64: swc1        $f18, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f18.u32l;
    // 0x80068A68: swc1        $f22, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f22.u32l;
L_80068A6C:
    // 0x80068A6C: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
L_80068A70:
    // 0x80068A70: ldc1        $f30, 0x70($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X70);
    // 0x80068A74: ldc1        $f28, 0x68($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X68);
    // 0x80068A78: ldc1        $f26, 0x60($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X60);
    // 0x80068A7C: ldc1        $f24, 0x58($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X58);
    // 0x80068A80: ldc1        $f22, 0x50($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X50);
    // 0x80068A84: ldc1        $f20, 0x48($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X48);
    // 0x80068A88: jr          $ra
    // 0x80068A8C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80068A8C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void sampleHmpTileHeightBicubic(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068A90: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80068A94: sdc1        $f28, 0x20($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X20, ctx->r29);
    // 0x80068A98: mov.s       $f28, $f14
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 14);
    ctx->f28.fl = ctx->f14.fl;
    // 0x80068A9C: mtc1        $a2, $f16
    ctx->f16.u32l = ctx->r6;
    // 0x80068AA0: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x80068AA4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80068AA8: lwc1        $f2, -0x37D8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X37D8);
    // 0x80068AAC: sdc1        $f26, 0x18($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X18, ctx->r29);
    // 0x80068AB0: lwc1        $f26, 0x40($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80068AB4: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80068AB8: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x80068ABC: sdc1        $f30, 0x28($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X28, ctx->r29);
    // 0x80068AC0: sdc1        $f24, 0x10($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X10, ctx->r29);
    // 0x80068AC4: add.s       $f0, $f12, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x80068AC8: sdc1        $f22, 0x8($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X8, ctx->r29);
    // 0x80068ACC: sdc1        $f20, 0x0($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X0, ctx->r29);
    // 0x80068AD0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80068AD4: nop

    // 0x80068AD8: bc1fl       L_80068AF0
    if (!c1cs) {
        // 0x80068ADC: add.s       $f0, $f16, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
            goto L_80068AF0;
    }
    goto skip_0;
    // 0x80068ADC: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
    skip_0:
    // 0x80068AE0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80068AE4: lwc1        $f0, -0x37D4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X37D4);
    // 0x80068AE8: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x80068AEC: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
L_80068AF0:
    // 0x80068AF0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80068AF4: nop

    // 0x80068AF8: bc1f        L_80068B0C
    if (!c1cs) {
        // 0x80068AFC: addu        $a2, $zero, $zero
        ctx->r6 = ADD32(0, 0);
            goto L_80068B0C;
    }
    // 0x80068AFC: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    // 0x80068B00: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80068B04: lwc1        $f0, -0x37D0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X37D0);
    // 0x80068B08: add.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f0.fl;
L_80068B0C:
    // 0x80068B0C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80068B10: addu        $t3, $a2, $zero
    ctx->r11 = ADD32(ctx->r6, 0);
    // 0x80068B14: addiu       $t2, $zero, 0x6
    ctx->r10 = ADD32(0, 0X6);
    // 0x80068B18: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x80068B1C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80068B20: lwc1        $f10, -0x37CC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X37CC);
    // 0x80068B24: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80068B28: mov.s       $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    ctx->f24.fl = ctx->f10.fl;
L_80068B2C:
    // 0x80068B2C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80068B30: mtc1        $a2, $f0
    ctx->f0.u32l = ctx->r6;
    // 0x80068B34: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80068B38: add.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f24.fl;
    // 0x80068B3C: addu        $t0, $t4, $zero
    ctx->r8 = ADD32(ctx->r12, 0);
    // 0x80068B40: addu        $a3, $t5, $zero
    ctx->r7 = ADD32(ctx->r13, 0);
    // 0x80068B44: sub.s       $f20, $f0, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f0.fl - ctx->f16.fl;
L_80068B48:
    // 0x80068B48: addu        $v0, $a1, $t2
    ctx->r2 = ADD32(ctx->r5, ctx->r10);
    // 0x80068B4C: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x80068B50: lb          $a0, 0x5($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X5);
    // 0x80068B54: addu        $v0, $t1, $a3
    ctx->r2 = ADD32(ctx->r9, ctx->r7);
    // 0x80068B58: lb          $v0, 0x5($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X5);
    // 0x80068B5C: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x80068B60: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80068B64: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80068B68: mul.s       $f6, $f20, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x80068B6C: nop

    // 0x80068B70: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80068B74: mtc1        $a1, $f2
    ctx->f2.u32l = ctx->r5;
    // 0x80068B78: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80068B7C: add.s       $f2, $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f24.fl;
    // 0x80068B80: addu        $v1, $t1, $t0
    ctx->r3 = ADD32(ctx->r9, ctx->r8);
    // 0x80068B84: lb          $v1, 0x5($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X5);
    // 0x80068B88: sub.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80068B8C: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x80068B90: mtc1        $v1, $f0
    ctx->f0.u32l = ctx->r3;
    // 0x80068B94: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80068B98: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80068B9C: nop

    // 0x80068BA0: mul.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x80068BA4: add.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f26.fl;
    // 0x80068BA8: add.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80068BAC: mtc1        $a0, $f0
    ctx->f0.u32l = ctx->r4;
    // 0x80068BB0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80068BB4: sub.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f28.fl;
    // 0x80068BB8: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80068BBC: add.s       $f0, $f2, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x80068BC0: c.le.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl <= ctx->f0.fl;
    // 0x80068BC4: nop

    // 0x80068BC8: bc1f        L_80068C28
    if (!c1cs) {
        // 0x80068BCC: addu        $v0, $a1, $t3
        ctx->r2 = ADD32(ctx->r5, ctx->r11);
            goto L_80068C28;
    }
    // 0x80068BCC: addu        $v0, $a1, $t3
    ctx->r2 = ADD32(ctx->r5, ctx->r11);
    // 0x80068BD0: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80068BD4: nop

    // 0x80068BD8: bc1f        L_80068C2C
    if (!c1cs) {
        // 0x80068BDC: addu        $v0, $t1, $v0
        ctx->r2 = ADD32(ctx->r9, ctx->r2);
            goto L_80068C2C;
    }
    // 0x80068BDC: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
    // 0x80068BE0: div.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80068BE4: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x80068BE8: nop

    // 0x80068BEC: bc1f        L_80068C2C
    if (!c1cs) {
        // 0x80068BF0: nop
    
            goto L_80068C2C;
    }
    // 0x80068BF0: nop

    // 0x80068BF4: mul.s       $f0, $f14, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80068BF8: add.s       $f0, $f12, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x80068BFC: trunc.w.s   $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80068C00: mfc1        $v0, $f30
    ctx->r2 = (int32_t)ctx->f30.u32l;
    // 0x80068C04: bne         $v0, $a1, L_80068C28
    if (ctx->r2 != ctx->r5) {
        // 0x80068C08: addu        $v0, $a1, $t3
        ctx->r2 = ADD32(ctx->r5, ctx->r11);
            goto L_80068C28;
    }
    // 0x80068C08: addu        $v0, $a1, $t3
    ctx->r2 = ADD32(ctx->r5, ctx->r11);
    // 0x80068C0C: mul.s       $f0, $f18, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80068C10: add.s       $f0, $f16, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x80068C14: trunc.w.s   $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80068C18: mfc1        $v0, $f30
    ctx->r2 = (int32_t)ctx->f30.u32l;
    // 0x80068C1C: beql        $v0, $a2, L_80068C24
    if (ctx->r2 == ctx->r6) {
        // 0x80068C20: mov.s       $f10, $f2
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.fl = ctx->f2.fl;
            goto L_80068C24;
    }
    goto skip_1;
    // 0x80068C20: mov.s       $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.fl = ctx->f2.fl;
    skip_1:
L_80068C24:
    // 0x80068C24: addu        $v0, $a1, $t3
    ctx->r2 = ADD32(ctx->r5, ctx->r11);
L_80068C28:
    // 0x80068C28: addu        $v0, $t1, $v0
    ctx->r2 = ADD32(ctx->r9, ctx->r2);
L_80068C2C:
    // 0x80068C2C: addu        $v1, $t1, $a3
    ctx->r3 = ADD32(ctx->r9, ctx->r7);
    // 0x80068C30: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x80068C34: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80068C38: lb          $a0, 0x5($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X5);
    // 0x80068C3C: lb          $v0, 0x5($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X5);
    // 0x80068C40: sub.s       $f6, $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x80068C44: subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
    // 0x80068C48: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80068C4C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80068C50: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80068C54: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x80068C58: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80068C5C: addu        $v0, $t1, $t0
    ctx->r2 = ADD32(ctx->r9, ctx->r8);
    // 0x80068C60: lb          $v0, 0x5($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X5);
    // 0x80068C64: sub.s       $f4, $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x80068C68: subu        $v0, $a0, $v0
    ctx->r2 = SUB32(ctx->r4, ctx->r2);
    // 0x80068C6C: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80068C70: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80068C74: mul.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80068C78: nop

    // 0x80068C7C: mul.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x80068C80: nop

    // 0x80068C84: mul.s       $f2, $f8, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80068C88: add.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f26.fl;
    // 0x80068C8C: add.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80068C90: mtc1        $a0, $f0
    ctx->f0.u32l = ctx->r4;
    // 0x80068C94: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80068C98: sub.s       $f0, $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f28.fl;
    // 0x80068C9C: add.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80068CA0: add.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80068CA4: c.le.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl <= ctx->f0.fl;
    // 0x80068CA8: nop

    // 0x80068CAC: bc1fl       L_80068D0C
    if (!c1cs) {
        // 0x80068CB0: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_80068D0C;
    }
    goto skip_2;
    // 0x80068CB0: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    skip_2:
    // 0x80068CB4: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80068CB8: nop

    // 0x80068CBC: bc1fl       L_80068D0C
    if (!c1cs) {
        // 0x80068CC0: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_80068D0C;
    }
    goto skip_3;
    // 0x80068CC0: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    skip_3:
    // 0x80068CC4: div.s       $f2, $f0, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80068CC8: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x80068CCC: nop

    // 0x80068CD0: bc1fl       L_80068D0C
    if (!c1cs) {
        // 0x80068CD4: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_80068D0C;
    }
    goto skip_4;
    // 0x80068CD4: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    skip_4:
    // 0x80068CD8: mul.s       $f0, $f14, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80068CDC: add.s       $f0, $f12, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x80068CE0: trunc.w.s   $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80068CE4: mfc1        $v0, $f30
    ctx->r2 = (int32_t)ctx->f30.u32l;
    // 0x80068CE8: bnel        $v0, $a1, L_80068D0C
    if (ctx->r2 != ctx->r5) {
        // 0x80068CEC: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_80068D0C;
    }
    goto skip_5;
    // 0x80068CEC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    skip_5:
    // 0x80068CF0: mul.s       $f0, $f18, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80068CF4: add.s       $f0, $f16, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x80068CF8: trunc.w.s   $f30, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    ctx->f30.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80068CFC: mfc1        $v0, $f30
    ctx->r2 = (int32_t)ctx->f30.u32l;
    // 0x80068D00: beql        $v0, $a2, L_80068D08
    if (ctx->r2 == ctx->r6) {
        // 0x80068D04: mov.s       $f10, $f2
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.fl = ctx->f2.fl;
            goto L_80068D08;
    }
    goto skip_6;
    // 0x80068D04: mov.s       $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    ctx->f10.fl = ctx->f2.fl;
    skip_6:
L_80068D08:
    // 0x80068D08: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_80068D0C:
    // 0x80068D0C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80068D10: slti        $v0, $a1, 0x4
    ctx->r2 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x80068D14: bne         $v0, $zero, L_80068B48
    if (ctx->r2 != 0) {
        // 0x80068D18: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_80068B48;
    }
    // 0x80068D18: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80068D1C: addiu       $t5, $t5, 0x5
    ctx->r13 = ADD32(ctx->r13, 0X5);
    // 0x80068D20: addiu       $t3, $t3, 0x5
    ctx->r11 = ADD32(ctx->r11, 0X5);
    // 0x80068D24: addiu       $t2, $t2, 0x5
    ctx->r10 = ADD32(ctx->r10, 0X5);
    // 0x80068D28: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80068D2C: slti        $v0, $a2, 0x4
    ctx->r2 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    // 0x80068D30: bne         $v0, $zero, L_80068B2C
    if (ctx->r2 != 0) {
        // 0x80068D34: addiu       $t4, $t4, 0x5
        ctx->r12 = ADD32(ctx->r12, 0X5);
            goto L_80068B2C;
    }
    // 0x80068D34: addiu       $t4, $t4, 0x5
    ctx->r12 = ADD32(ctx->r12, 0X5);
    // 0x80068D38: ldc1        $f30, 0x28($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X28);
    // 0x80068D3C: ldc1        $f28, 0x20($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X20);
    // 0x80068D40: ldc1        $f26, 0x18($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X18);
    // 0x80068D44: ldc1        $f24, 0x10($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X10);
    // 0x80068D48: ldc1        $f22, 0x8($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X8);
    // 0x80068D4C: ldc1        $f20, 0x0($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X0);
    // 0x80068D50: mov.s       $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = ctx->f10.fl;
    // 0x80068D54: jr          $ra
    // 0x80068D58: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80068D58: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void sampleTerrainAtNpcPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068D5C: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80068D60: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80068D64: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x80068D68: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80068D6C: addiu       $v0, $v1, 0x6DC0
    ctx->r2 = ADD32(ctx->r3, 0X6DC0);
    // 0x80068D70: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80068D74: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80068D78: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80068D7C: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80068D80: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80068D84: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80068D88: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80068D8C: sdc1        $f30, 0x90($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X90, ctx->r29);
    // 0x80068D90: sdc1        $f28, 0x88($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X88, ctx->r29);
    // 0x80068D94: sdc1        $f26, 0x80($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X80, ctx->r29);
    // 0x80068D98: sdc1        $f24, 0x78($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X78, ctx->r29);
    // 0x80068D9C: sdc1        $f22, 0x70($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X70, ctx->r29);
    // 0x80068DA0: sdc1        $f20, 0x68($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X68, ctx->r29);
    // 0x80068DA4: lwc1        $f0, 0x0($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80068DA8: lwc1        $f2, 0x20($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80068DAC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80068DB0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80068DB4: lwc1        $f4, -0x37C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X37C8);
    // 0x80068DB8: mul.s       $f24, $f0, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f24.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80068DBC: addu        $s3, $a1, $zero
    ctx->r19 = ADD32(ctx->r5, 0);
    // 0x80068DC0: addu        $s6, $a2, $zero
    ctx->r22 = ADD32(ctx->r6, 0);
    // 0x80068DC4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80068DC8: c.eq.s      $f24, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f24.fl == ctx->f8.fl;
    // 0x80068DCC: nop

    // 0x80068DD0: bc1f        L_80068DE0
    if (!c1cs) {
        // 0x80068DD4: addu        $s5, $a3, $zero
        ctx->r21 = ADD32(ctx->r7, 0);
            goto L_80068DE0;
    }
    // 0x80068DD4: addu        $s5, $a3, $zero
    ctx->r21 = ADD32(ctx->r7, 0);
    // 0x80068DD8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80068DDC: lwc1        $f24, -0x37C4($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X37C4);
L_80068DE0:
    // 0x80068DE0: lwc1        $f0, 0x8($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X8);
    // 0x80068DE4: lwc1        $f2, 0x2C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x80068DE8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80068DEC: mul.s       $f26, $f0, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f26.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80068DF0: c.eq.s      $f26, $f8
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f26.fl == ctx->f8.fl;
    // 0x80068DF4: nop

    // 0x80068DF8: bc1f        L_80068E08
    if (!c1cs) {
        // 0x80068DFC: nop
    
            goto L_80068E08;
    }
    // 0x80068DFC: nop

    // 0x80068E00: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80068E04: lwc1        $f26, -0x37C0($at)
    ctx->f26.u32l = MEM_W(ctx->r1, -0X37C0);
L_80068E08:
    // 0x80068E08: lwc1        $f0, 0x0($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80068E0C: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80068E10: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80068E14: lwc1        $f0, 0x8($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80068E18: mul.s       $f18, $f0, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80068E1C: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80068E20: lwc1        $f0, 0x4($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80068E24: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80068E28: lwc1        $f4, -0x37BC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X37BC);
    // 0x80068E2C: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80068E30: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80068E34: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80068E38: lwc1        $f0, 0x4($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X4);
    // 0x80068E3C: lwc1        $f2, 0x18($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80068E40: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80068E44: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80068E48: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80068E4C: addu        $s1, $zero, $zero
    ctx->r17 = ADD32(0, 0);
    // 0x80068E50: c.lt.s      $f24, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f24.fl < ctx->f8.fl;
    // 0x80068E54: nop

    // 0x80068E58: bc1f        L_80068E6C
    if (!c1cs) {
        // 0x80068E5C: swc1        $f0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
            goto L_80068E6C;
    }
    // 0x80068E5C: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80068E60: lw          $s0, 0x6DC0($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X6DC0);
    // 0x80068E64: j           L_80068EF8
    // 0x80068E68: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_80068EF8;
    // 0x80068E68: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_80068E6C:
    // 0x80068E6C: lhu         $v0, 0x38($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X38);
    // 0x80068E70: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80068E74: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80068E78: c.le.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl <= ctx->f24.fl;
    // 0x80068E7C: nop

    // 0x80068E80: bc1f        L_80068E9C
    if (!c1cs) {
        // 0x80068E84: nop
    
            goto L_80068E9C;
    }
    // 0x80068E84: nop

    // 0x80068E88: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80068E8C: sllv        $v0, $v0, $s1
    ctx->r2 = S32(ctx->r2 << (ctx->r17 & 31));
    // 0x80068E90: lw          $v1, 0x6DC0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6DC0);
    // 0x80068E94: j           L_80068EF4
    // 0x80068E98: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
        goto L_80068EF4;
    // 0x80068E98: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
L_80068E9C:
    // 0x80068E9C: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80068EA0: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80068EA4: nop

    // 0x80068EA8: bc1fl       L_80068EE4
    if (!c1cs) {
        // 0x80068EAC: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_80068EE4;
    }
    goto skip_0;
    // 0x80068EAC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    skip_0:
    // 0x80068EB0: trunc.w.s   $f28, $f24
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 24);
    ctx->f28.u32l = TRUNC_W_S(ctx->f24.fl);
    // 0x80068EB4: mfc1        $v0, $f28
    ctx->r2 = (int32_t)ctx->f28.u32l;
    // 0x80068EB8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80068EBC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80068EC0: sub.s       $f0, $f24, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f24.fl - ctx->f0.fl;
    // 0x80068EC4: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x80068EC8: nop

    // 0x80068ECC: bc1f        L_80068EE0
    if (!c1cs) {
        // 0x80068ED0: sll         $v0, $v0, 1
        ctx->r2 = S32(ctx->r2 << 1);
            goto L_80068EE0;
    }
    // 0x80068ED0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80068ED4: lw          $v1, 0x6DC0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6DC0);
    // 0x80068ED8: j           L_80068EF4
    // 0x80068EDC: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
        goto L_80068EF4;
    // 0x80068EDC: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
L_80068EE0:
    // 0x80068EE0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
L_80068EE4:
    // 0x80068EE4: trunc.w.s   $f6, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    ctx->f6.u32l = TRUNC_W_S(ctx->f24.fl);
    // 0x80068EE8: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80068EEC: lw          $v1, 0x6DC0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6DC0);
    // 0x80068EF0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
L_80068EF4:
    // 0x80068EF4: addu        $s0, $v1, $v0
    ctx->r16 = ADD32(ctx->r3, ctx->r2);
L_80068EF8:
    // 0x80068EF8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80068EFC: addiu       $v1, $v0, 0x6DC0
    ctx->r3 = ADD32(ctx->r2, 0X6DC0);
    // 0x80068F00: lhu         $v0, 0x3A($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X3A);
    // 0x80068F04: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80068F08: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80068F0C: c.le.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl <= ctx->f26.fl;
    // 0x80068F10: nop

    // 0x80068F14: bc1f        L_80068F34
    if (!c1cs) {
        // 0x80068F18: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_80068F34;
    }
    // 0x80068F18: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80068F1C: lhu         $v1, 0x38($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X38);
    // 0x80068F20: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80068F24: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x80068F28: mflo        $t0
    ctx->r8 = lo;
    // 0x80068F2C: j           L_80068FD0
    // 0x80068F30: sllv        $v0, $t0, $s1
    ctx->r2 = S32(ctx->r8 << (ctx->r17 & 31));
        goto L_80068FD0;
    // 0x80068F30: sllv        $v0, $t0, $s1
    ctx->r2 = S32(ctx->r8 << (ctx->r17 & 31));
L_80068F34:
    // 0x80068F34: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80068F38: c.lt.s      $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f26.fl < ctx->f2.fl;
    // 0x80068F3C: nop

    // 0x80068F40: bc1f        L_80068F50
    if (!c1cs) {
        // 0x80068F44: nop
    
            goto L_80068F50;
    }
    // 0x80068F44: nop

    // 0x80068F48: j           L_80068FD4
    // 0x80068F4C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
        goto L_80068FD4;
    // 0x80068F4C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_80068F50:
    // 0x80068F50: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x80068F54: nop

    // 0x80068F58: bc1f        L_80068FB8
    if (!c1cs) {
        // 0x80068F5C: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80068FB8;
    }
    // 0x80068F5C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80068F60: trunc.w.s   $f6, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    ctx->f6.u32l = TRUNC_W_S(ctx->f26.fl);
    // 0x80068F64: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80068F68: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80068F6C: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80068F70: sub.s       $f0, $f26, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f26.fl - ctx->f0.fl;
    // 0x80068F74: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x80068F78: nop

    // 0x80068F7C: bc1f        L_80068FB4
    if (!c1cs) {
        // 0x80068F80: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_80068FB4;
    }
    // 0x80068F80: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80068F84: lhu         $v1, 0x38($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X38);
    // 0x80068F88: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80068F8C: j           L_80068FC8
    // 0x80068F90: nop

        goto L_80068FC8;
    // 0x80068F90: nop

L_80068F94:
    // 0x80068F94: mul.s       $f0, $f20, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x80068F98: j           L_80068FA4
    // 0x80068F9C: sub.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f8.fl;
        goto L_80068FA4;
    // 0x80068F9C: sub.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f8.fl;
L_80068FA0:
    // 0x80068FA0: mul.s       $f0, $f22, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f22.fl, ctx->f20.fl);
L_80068FA4:
    // 0x80068FA4: nop

    // 0x80068FA8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80068FAC: j           L_80069830
    // 0x80068FB0: add.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f0.fl;
        goto L_80069830;
    // 0x80068FB0: add.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f0.fl;
L_80068FB4:
    // 0x80068FB4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_80068FB8:
    // 0x80068FB8: lhu         $v1, 0x6DF8($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X6DF8);
    // 0x80068FBC: trunc.w.s   $f6, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    ctx->f6.u32l = TRUNC_W_S(ctx->f26.fl);
    // 0x80068FC0: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80068FC4: mult        $v1, $v0
    result = S64(S32(ctx->r3)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
L_80068FC8:
    // 0x80068FC8: mflo        $t0
    ctx->r8 = lo;
    // 0x80068FCC: sll         $v0, $t0, 1
    ctx->r2 = S32(ctx->r8 << 1);
L_80068FD0:
    // 0x80068FD0: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
L_80068FD4:
    // 0x80068FD4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80068FD8: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80068FDC: lhu         $v0, 0x6DF8($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6DF8);
    // 0x80068FE0: add.s       $f2, $f24, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f24.fl + ctx->f6.fl;
    // 0x80068FE4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80068FE8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80068FEC: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80068FF0: nop

    // 0x80068FF4: bc1tl       L_80069014
    if (c1cs) {
        // 0x80068FF8: addiu       $s1, $zero, 0x1
        ctx->r17 = ADD32(0, 0X1);
            goto L_80069014;
    }
    goto skip_1;
    // 0x80068FF8: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    skip_1:
    // 0x80068FFC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80069000: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80069004: nop

    // 0x80069008: bc1f        L_80069018
    if (!c1cs) {
        // 0x8006900C: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80069018;
    }
    // 0x8006900C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80069010: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_80069014:
    // 0x80069014: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_80069018:
    // 0x80069018: lhu         $v0, 0x6DFA($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X6DFA);
    // 0x8006901C: add.s       $f2, $f26, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f26.fl + ctx->f18.fl;
    // 0x80069020: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80069024: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80069028: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8006902C: nop

    // 0x80069030: bc1tl       L_80069050
    if (c1cs) {
        // 0x80069034: addiu       $s1, $zero, 0x1
        ctx->r17 = ADD32(0, 0X1);
            goto L_80069050;
    }
    goto skip_2;
    // 0x80069034: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    skip_2:
    // 0x80069038: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8006903C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80069040: nop

    // 0x80069044: bc1f        L_80069054
    if (!c1cs) {
        // 0x80069048: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80069054;
    }
    // 0x80069048: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006904C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_80069050:
    // 0x80069050: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
L_80069054:
    // 0x80069054: addiu       $s2, $v0, 0x6DC0
    ctx->r18 = ADD32(ctx->r2, 0X6DC0);
    // 0x80069058: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8006905C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80069060: lwc1        $f16, -0x37B8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X37B8);
L_80069064:
    // 0x80069064: c.lt.s      $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f24.fl < ctx->f10.fl;
    // 0x80069068: nop

    // 0x8006906C: bc1f        L_800690D0
    if (!c1cs) {
        // 0x80069070: nop
    
            goto L_800690D0;
    }
    // 0x80069070: nop

    // 0x80069074: lwc1        $f28, 0x24($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80069078: c.lt.s      $f28, $f10
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f28.fl < ctx->f10.fl;
    // 0x8006907C: nop

    // 0x80069080: bc1f        L_800690AC
    if (!c1cs) {
        // 0x80069084: nop
    
            goto L_800690AC;
    }
    // 0x80069084: nop

    // 0x80069088: trunc.w.s   $f6, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    ctx->f6.u32l = TRUNC_W_S(ctx->f24.fl);
    // 0x8006908C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80069090: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80069094: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80069098: sub.s       $f0, $f24, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f24.fl - ctx->f0.fl;
    // 0x8006909C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800690A0: lwc1        $f2, -0x37B4($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X37B4);
    // 0x800690A4: j           L_80069124
    // 0x800690A8: sub.s       $f30, $f2, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f30.fl = ctx->f2.fl - ctx->f0.fl;
        goto L_80069124;
    // 0x800690A8: sub.s       $f30, $f2, $f0
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f30.fl = ctx->f2.fl - ctx->f0.fl;
L_800690AC:
    // 0x800690AC: trunc.w.s   $f6, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    ctx->f6.u32l = TRUNC_W_S(ctx->f24.fl);
    // 0x800690B0: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800690B4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800690B8: lwc1        $f6, -0x37B0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X37B0);
    // 0x800690BC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800690C0: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800690C4: sub.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x800690C8: j           L_80069124
    // 0x800690CC: sub.s       $f30, $f0, $f24
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f30.fl = ctx->f0.fl - ctx->f24.fl;
        goto L_80069124;
    // 0x800690CC: sub.s       $f30, $f0, $f24
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f30.fl = ctx->f0.fl - ctx->f24.fl;
L_800690D0:
    // 0x800690D0: lwc1        $f28, 0x24($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800690D4: c.lt.s      $f28, $f10
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f28.fl < ctx->f10.fl;
    // 0x800690D8: nop

    // 0x800690DC: bc1f        L_800690F4
    if (!c1cs) {
        // 0x800690E0: nop
    
            goto L_800690F4;
    }
    // 0x800690E0: nop

    // 0x800690E4: trunc.w.s   $f6, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    ctx->f6.u32l = TRUNC_W_S(ctx->f24.fl);
    // 0x800690E8: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800690EC: j           L_80069100
    // 0x800690F0: nop

        goto L_80069100;
    // 0x800690F0: nop

L_800690F4:
    // 0x800690F4: trunc.w.s   $f6, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    ctx->f6.u32l = TRUNC_W_S(ctx->f24.fl);
    // 0x800690F8: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800690FC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80069100:
    // 0x80069100: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80069104: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80069108: sub.s       $f30, $f0, $f24
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f30.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x8006910C: c.eq.s      $f30, $f10
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f30.fl == ctx->f10.fl;
    // 0x80069110: nop

    // 0x80069114: bc1f        L_80069124
    if (!c1cs) {
        // 0x80069118: nop
    
            goto L_80069124;
    }
    // 0x80069118: nop

    // 0x8006911C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80069120: lwc1        $f30, -0x37AC($at)
    ctx->f30.u32l = MEM_W(ctx->r1, -0X37AC);
L_80069124:
    // 0x80069124: c.lt.s      $f26, $f10
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f26.fl < ctx->f10.fl;
    // 0x80069128: nop

    // 0x8006912C: bc1f        L_80069194
    if (!c1cs) {
        // 0x80069130: nop
    
            goto L_80069194;
    }
    // 0x80069130: nop

    // 0x80069134: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x80069138: nop

    // 0x8006913C: bc1f        L_8006916C
    if (!c1cs) {
        // 0x80069140: nop
    
            goto L_8006916C;
    }
    // 0x80069140: nop

    // 0x80069144: trunc.w.s   $f6, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    ctx->f6.u32l = TRUNC_W_S(ctx->f26.fl);
    // 0x80069148: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x8006914C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80069150: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80069154: sub.s       $f0, $f26, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f26.fl - ctx->f0.fl;
    // 0x80069158: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006915C: lwc1        $f2, -0x37A8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X37A8);
    // 0x80069160: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80069164: j           L_800691F0
    // 0x80069168: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
        goto L_800691F0;
    // 0x80069168: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
L_8006916C:
    // 0x8006916C: trunc.w.s   $f6, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    ctx->f6.u32l = TRUNC_W_S(ctx->f26.fl);
    // 0x80069170: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80069174: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80069178: lwc1        $f6, -0x37A4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X37A4);
    // 0x8006917C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80069180: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80069184: sub.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80069188: sub.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f26.fl;
    // 0x8006918C: j           L_800691F0
    // 0x80069190: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
        goto L_800691F0;
    // 0x80069190: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
L_80069194:
    // 0x80069194: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x80069198: nop

    // 0x8006919C: bc1f        L_800691B4
    if (!c1cs) {
        // 0x800691A0: nop
    
            goto L_800691B4;
    }
    // 0x800691A0: nop

    // 0x800691A4: trunc.w.s   $f28, $f26
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    ctx->f28.u32l = TRUNC_W_S(ctx->f26.fl);
    // 0x800691A8: mfc1        $v0, $f28
    ctx->r2 = (int32_t)ctx->f28.u32l;
    // 0x800691AC: j           L_800691C0
    // 0x800691B0: nop

        goto L_800691C0;
    // 0x800691B0: nop

L_800691B4:
    // 0x800691B4: trunc.w.s   $f6, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    ctx->f6.u32l = TRUNC_W_S(ctx->f26.fl);
    // 0x800691B8: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800691BC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800691C0:
    // 0x800691C0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800691C4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800691C8: sub.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f26.fl;
    // 0x800691CC: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x800691D0: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800691D4: c.eq.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl == ctx->f10.fl;
    // 0x800691D8: nop

    // 0x800691DC: bc1f        L_800691F0
    if (!c1cs) {
        // 0x800691E0: nop
    
            goto L_800691F0;
    }
    // 0x800691E0: nop

    // 0x800691E4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800691E8: lwc1        $f28, -0x37A0($at)
    ctx->f28.u32l = MEM_W(ctx->r1, -0X37A0);
    // 0x800691EC: swc1        $f28, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f28.u32l;
L_800691F0:
    // 0x800691F0: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800691F4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800691F8: lwc1        $f20, -0x379C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X379C);
    // 0x800691FC: c.eq.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl == ctx->f10.fl;
    // 0x80069200: nop

    // 0x80069204: bc1fl       L_8006920C
    if (!c1cs) {
        // 0x80069208: div.s       $f20, $f30, $f6
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = DIV_S(ctx->f30.fl, ctx->f6.fl);
            goto L_8006920C;
    }
    goto skip_3;
    // 0x80069208: div.s       $f20, $f30, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = DIV_S(ctx->f30.fl, ctx->f6.fl);
    skip_3:
L_8006920C:
    // 0x8006920C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80069210: lwc1        $f22, -0x3798($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X3798);
    // 0x80069214: c.eq.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl == ctx->f10.fl;
    // 0x80069218: nop

    // 0x8006921C: bc1t        L_8006922C
    if (c1cs) {
        // 0x80069220: nop
    
            goto L_8006922C;
    }
    // 0x80069220: nop

    // 0x80069224: lwc1        $f28, 0x40($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80069228: div.s       $f22, $f28, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f22.fl = DIV_S(ctx->f28.fl, ctx->f18.fl);
L_8006922C:
    // 0x8006922C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80069230: ldc1        $f2, -0x3790($at)
    CHECK_FR(ctx, 2);
    ctx->f2.u64 = LD(ctx->r1, -0X3790);
    // 0x80069234: cvt.d.s     $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f0.d = CVT_D_S(ctx->f20.fl);
    // 0x80069238: c.le.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d <= ctx->f0.d;
    // 0x8006923C: nop

    // 0x80069240: bc1f        L_800693F4
    if (!c1cs) {
        // 0x80069244: nop
    
            goto L_800693F4;
    }
    // 0x80069244: nop

    // 0x80069248: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006924C: lwc1        $f6, -0x3788($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3788);
    // 0x80069250: c.le.s      $f6, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f6.fl <= ctx->f22.fl;
    // 0x80069254: nop

    // 0x80069258: bc1f        L_800693F4
    if (!c1cs) {
        // 0x8006925C: nop
    
            goto L_800693F4;
    }
    // 0x8006925C: nop

    // 0x80069260: lwc1        $f28, 0x24($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80069264: c.eq.s      $f28, $f10
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f28.fl == ctx->f10.fl;
    // 0x80069268: nop

    // 0x8006926C: bc1f        L_80069284
    if (!c1cs) {
        // 0x80069270: nop
    
            goto L_80069284;
    }
    // 0x80069270: nop

    // 0x80069274: c.eq.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl == ctx->f10.fl;
    // 0x80069278: nop

    // 0x8006927C: bc1t        L_80069830
    if (c1cs) {
        // 0x80069280: nop
    
            goto L_80069830;
    }
    // 0x80069280: nop

L_80069284:
    // 0x80069284: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x80069288: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
    // 0x8006928C: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80069290: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80069294: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x80069298: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8006929C: addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // 0x800692A0: lb          $v0, 0x3($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X3);
    // 0x800692A4: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800692A8: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x800692AC: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x800692B0: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x800692B4: nop

    // 0x800692B8: bc1t        L_800692D8
    if (c1cs) {
        // 0x800692BC: nop
    
            goto L_800692D8;
    }
    // 0x800692BC: nop

    // 0x800692C0: lwc1        $f28, 0x28($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800692C4: add.s       $f0, $f6, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f28.fl;
    // 0x800692C8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800692CC: nop

    // 0x800692D0: bc1f        L_800693E4
    if (!c1cs) {
        // 0x800692D4: nop
    
            goto L_800693E4;
    }
    // 0x800692D4: nop

L_800692D8:
    // 0x800692D8: c.lt.s      $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f24.fl < ctx->f10.fl;
    // 0x800692DC: nop

    // 0x800692E0: bc1f        L_80069314
    if (!c1cs) {
        // 0x800692E4: nop
    
            goto L_80069314;
    }
    // 0x800692E4: nop

    // 0x800692E8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800692EC: lwc1        $f6, -0x3784($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3784);
    // 0x800692F0: add.s       $f2, $f24, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f24.fl + ctx->f6.fl;
    // 0x800692F4: trunc.w.s   $f28, $f24
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 24);
    ctx->f28.u32l = TRUNC_W_S(ctx->f24.fl);
    // 0x800692F8: mfc1        $v0, $f28
    ctx->r2 = (int32_t)ctx->f28.u32l;
    // 0x800692FC: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80069300: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80069304: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80069308: mul.s       $f12, $f2, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x8006930C: j           L_8006932C
    // 0x80069310: nop

        goto L_8006932C;
    // 0x80069310: nop

L_80069314:
    // 0x80069314: trunc.w.s   $f6, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    ctx->f6.u32l = TRUNC_W_S(ctx->f24.fl);
    // 0x80069318: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x8006931C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80069320: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80069324: sub.s       $f0, $f24, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f24.fl - ctx->f0.fl;
    // 0x80069328: mul.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
L_8006932C:
    // 0x8006932C: c.lt.s      $f26, $f10
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f26.fl < ctx->f10.fl;
    // 0x80069330: nop

    // 0x80069334: bc1f        L_80069368
    if (!c1cs) {
        // 0x80069338: nop
    
            goto L_80069368;
    }
    // 0x80069338: nop

    // 0x8006933C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80069340: lwc1        $f6, -0x3780($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3780);
    // 0x80069344: add.s       $f2, $f26, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f26.fl + ctx->f6.fl;
    // 0x80069348: trunc.w.s   $f28, $f26
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    ctx->f28.u32l = TRUNC_W_S(ctx->f26.fl);
    // 0x8006934C: mfc1        $v0, $f28
    ctx->r2 = (int32_t)ctx->f28.u32l;
    // 0x80069350: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80069354: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80069358: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8006935C: mul.s       $f2, $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x80069360: j           L_80069380
    // 0x80069364: nop

        goto L_80069380;
    // 0x80069364: nop

L_80069368:
    // 0x80069368: trunc.w.s   $f6, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    ctx->f6.u32l = TRUNC_W_S(ctx->f26.fl);
    // 0x8006936C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80069370: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80069374: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80069378: sub.s       $f0, $f26, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f26.fl - ctx->f0.fl;
    // 0x8006937C: mul.s       $f2, $f0, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
L_80069380:
    // 0x80069380: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80069384: mul.s       $f6, $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80069388: nop

    // 0x8006938C: mul.s       $f0, $f18, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80069390: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80069394: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80069398: lwc1        $f28, 0x28($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8006939C: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x800693A0: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x800693A4: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x800693A8: swc1        $f28, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f28.u32l;
    // 0x800693AC: jal         0x80068A90
    // 0x800693B0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    sampleHmpTileHeightBicubic(rdram, ctx);
        goto after_0;
    // 0x800693B0: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x800693B4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800693B8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800693BC: lwc1        $f6, -0x377C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X377C);
    // 0x800693C0: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800693C4: c.le.s      $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f6.fl <= ctx->f20.fl;
    // 0x800693C8: nop

    // 0x800693CC: bc1t        L_800693E4
    if (c1cs) {
        // 0x800693D0: nop
    
            goto L_800693E4;
    }
    // 0x800693D0: nop

    // 0x800693D4: mul.s       $f0, $f20, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x800693D8: sub.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x800693DC: j           L_80069830
    // 0x800693E0: add.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f0.fl;
        goto L_80069830;
    // 0x800693E0: add.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f0.fl;
L_800693E4:
    // 0x800693E4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800693E8: lwc1        $f8, -0x3778($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3778);
    // 0x800693EC: j           L_80069830
    // 0x800693F0: nop

        goto L_80069830;
    // 0x800693F0: nop

L_800693F4:
    // 0x800693F4: c.lt.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl < ctx->f22.fl;
    // 0x800693F8: nop

    // 0x800693FC: bc1f        L_80069608
    if (!c1cs) {
        // 0x80069400: nop
    
            goto L_80069608;
    }
    // 0x80069400: nop

    // 0x80069404: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x80069408: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
    // 0x8006940C: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80069410: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80069414: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x80069418: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x8006941C: addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // 0x80069420: lb          $v0, 0x3($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X3);
    // 0x80069424: lwc1        $f28, 0x20($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80069428: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x8006942C: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80069430: c.lt.s      $f2, $f28
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f2.fl < ctx->f28.fl;
    // 0x80069434: nop

    // 0x80069438: bc1t        L_8006945C
    if (c1cs) {
        // 0x8006943C: nop
    
            goto L_8006945C;
    }
    // 0x8006943C: nop

    // 0x80069440: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80069444: mul.s       $f0, $f6, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80069448: add.s       $f0, $f28, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f28.fl + ctx->f0.fl;
    // 0x8006944C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80069450: nop

    // 0x80069454: bc1f        L_80069578
    if (!c1cs) {
        // 0x80069458: nop
    
            goto L_80069578;
    }
    // 0x80069458: nop

L_8006945C:
    // 0x8006945C: c.lt.s      $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f24.fl < ctx->f10.fl;
    // 0x80069460: nop

    // 0x80069464: bc1f        L_80069498
    if (!c1cs) {
        // 0x80069468: nop
    
            goto L_80069498;
    }
    // 0x80069468: nop

    // 0x8006946C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80069470: lwc1        $f28, -0x3774($at)
    ctx->f28.u32l = MEM_W(ctx->r1, -0X3774);
    // 0x80069474: add.s       $f2, $f24, $f28
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f2.fl = ctx->f24.fl + ctx->f28.fl;
    // 0x80069478: trunc.w.s   $f6, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    ctx->f6.u32l = TRUNC_W_S(ctx->f24.fl);
    // 0x8006947C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80069480: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80069484: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80069488: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8006948C: mul.s       $f12, $f2, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x80069490: j           L_800694B0
    // 0x80069494: nop

        goto L_800694B0;
    // 0x80069494: nop

L_80069498:
    // 0x80069498: trunc.w.s   $f6, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    ctx->f6.u32l = TRUNC_W_S(ctx->f24.fl);
    // 0x8006949C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800694A0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800694A4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800694A8: sub.s       $f0, $f24, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f24.fl - ctx->f0.fl;
    // 0x800694AC: mul.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
L_800694B0:
    // 0x800694B0: c.lt.s      $f26, $f10
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f26.fl < ctx->f10.fl;
    // 0x800694B4: nop

    // 0x800694B8: bc1f        L_800694EC
    if (!c1cs) {
        // 0x800694BC: nop
    
            goto L_800694EC;
    }
    // 0x800694BC: nop

    // 0x800694C0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800694C4: lwc1        $f6, -0x3770($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3770);
    // 0x800694C8: add.s       $f2, $f26, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f26.fl + ctx->f6.fl;
    // 0x800694CC: trunc.w.s   $f28, $f26
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    ctx->f28.u32l = TRUNC_W_S(ctx->f26.fl);
    // 0x800694D0: mfc1        $v0, $f28
    ctx->r2 = (int32_t)ctx->f28.u32l;
    // 0x800694D4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800694D8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800694DC: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800694E0: mul.s       $f4, $f2, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x800694E4: j           L_80069504
    // 0x800694E8: nop

        goto L_80069504;
    // 0x800694E8: nop

L_800694EC:
    // 0x800694EC: trunc.w.s   $f6, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    ctx->f6.u32l = TRUNC_W_S(ctx->f26.fl);
    // 0x800694F0: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800694F4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800694F8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800694FC: sub.s       $f0, $f26, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f26.fl - ctx->f0.fl;
    // 0x80069500: mul.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
L_80069504:
    // 0x80069504: nop

    // 0x80069508: mul.s       $f0, $f18, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8006950C: nop

    // 0x80069510: mul.s       $f28, $f30, $f16
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f28.fl = MUL_S(ctx->f30.fl, ctx->f16.fl);
    // 0x80069514: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80069518: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8006951C: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80069520: mul.s       $f2, $f6, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80069524: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x80069528: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x8006952C: mfc1        $a3, $f28
    ctx->r7 = (int32_t)ctx->f28.u32l;
    // 0x80069530: mul.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80069534: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x80069538: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x8006953C: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x80069540: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x80069544: jal         0x80068A90
    // 0x80069548: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    sampleHmpTileHeightBicubic(rdram, ctx);
        goto after_1;
    // 0x80069548: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8006954C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x80069550: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80069554: lwc1        $f6, -0x376C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X376C);
    // 0x80069558: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8006955C: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80069560: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80069564: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80069568: c.lt.s      $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f22.fl < ctx->f6.fl;
    // 0x8006956C: nop

    // 0x80069570: bc1t        L_80068F94
    if (c1cs) {
        // 0x80069574: nop
    
            goto L_80068F94;
    }
    // 0x80069574: nop

L_80069578:
    // 0x80069578: mul.s       $f2, $f18, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8006957C: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80069580: mul.s       $f4, $f6, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80069584: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80069588: lwc1        $f28, -0x3768($at)
    ctx->f28.u32l = MEM_W(ctx->r1, -0X3768);
    // 0x8006958C: sub.s       $f0, $f28, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f28.fl - ctx->f8.fl;
    // 0x80069590: mul.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80069594: add.s       $f24, $f24, $f30
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f30.fl;
    // 0x80069598: lwc1        $f28, 0x24($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8006959C: sub.s       $f28, $f28, $f30
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f28.fl = ctx->f28.fl - ctx->f30.fl;
    // 0x800695A0: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800695A4: add.s       $f26, $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f26.fl = ctx->f26.fl + ctx->f2.fl;
    // 0x800695A8: swc1        $f28, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f28.u32l;
    // 0x800695AC: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800695B0: lwc1        $f28, 0x28($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800695B4: sub.s       $f28, $f28, $f4
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f28.fl = ctx->f28.fl - ctx->f4.fl;
    // 0x800695B8: sub.s       $f18, $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x800695BC: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x800695C0: swc1        $f28, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f28.u32l;
    // 0x800695C4: beq         $s1, $zero, L_800695EC
    if (ctx->r17 == 0) {
        // 0x800695C8: add.s       $f8, $f8, $f0
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f0.fl;
            goto L_800695EC;
    }
    // 0x800695C8: add.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800695CC: trunc.w.s   $f6, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    ctx->f6.u32l = TRUNC_W_S(ctx->f24.fl);
    // 0x800695D0: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800695D4: blez        $v1, L_80069064
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800695D8: nop
    
            goto L_80069064;
    }
    // 0x800695D8: nop

    // 0x800695DC: lhu         $v0, 0x38($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X38);
    // 0x800695E0: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800695E4: beq         $v0, $zero, L_80069064
    if (ctx->r2 == 0) {
        // 0x800695E8: nop
    
            goto L_80069064;
    }
    // 0x800695E8: nop

L_800695EC:
    // 0x800695EC: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800695F0: c.le.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl <= ctx->f6.fl;
    // 0x800695F4: nop

    // 0x800695F8: bc1fl       L_80069064
    if (!c1cs) {
        // 0x800695FC: addiu       $s0, $s0, -0x2
        ctx->r16 = ADD32(ctx->r16, -0X2);
            goto L_80069064;
    }
    goto skip_4;
    // 0x800695FC: addiu       $s0, $s0, -0x2
    ctx->r16 = ADD32(ctx->r16, -0X2);
    skip_4:
    // 0x80069600: j           L_80069064
    // 0x80069604: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
        goto L_80069064;
    // 0x80069604: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
L_80069608:
    // 0x80069608: lhu         $v0, 0x0($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X0);
    // 0x8006960C: andi        $v0, $v0, 0x1FFF
    ctx->r2 = ctx->r2 & 0X1FFF;
    // 0x80069610: sll         $v1, $v0, 4
    ctx->r3 = S32(ctx->r2 << 4);
    // 0x80069614: subu        $v1, $v1, $v0
    ctx->r3 = SUB32(ctx->r3, ctx->r2);
    // 0x80069618: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x8006961C: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x80069620: addu        $v1, $v0, $v1
    ctx->r3 = ADD32(ctx->r2, ctx->r3);
    // 0x80069624: lb          $v0, 0x3($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X3);
    // 0x80069628: lwc1        $f28, 0x20($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8006962C: mtc1        $v0, $f2
    ctx->f2.u32l = ctx->r2;
    // 0x80069630: cvt.s.w     $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    ctx->f2.fl = CVT_S_W(ctx->f2.u32l);
    // 0x80069634: c.lt.s      $f2, $f28
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f2.fl < ctx->f28.fl;
    // 0x80069638: nop

    // 0x8006963C: bc1t        L_80069660
    if (c1cs) {
        // 0x80069640: nop
    
            goto L_80069660;
    }
    // 0x80069640: nop

    // 0x80069644: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80069648: mul.s       $f0, $f6, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x8006964C: add.s       $f0, $f28, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f28.fl + ctx->f0.fl;
    // 0x80069650: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80069654: nop

    // 0x80069658: bc1f        L_80069780
    if (!c1cs) {
        // 0x8006965C: nop
    
            goto L_80069780;
    }
    // 0x8006965C: nop

L_80069660:
    // 0x80069660: c.lt.s      $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f24.fl < ctx->f10.fl;
    // 0x80069664: nop

    // 0x80069668: bc1f        L_8006969C
    if (!c1cs) {
        // 0x8006966C: nop
    
            goto L_8006969C;
    }
    // 0x8006966C: nop

    // 0x80069670: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80069674: lwc1        $f28, -0x3764($at)
    ctx->f28.u32l = MEM_W(ctx->r1, -0X3764);
    // 0x80069678: add.s       $f2, $f24, $f28
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f2.fl = ctx->f24.fl + ctx->f28.fl;
    // 0x8006967C: trunc.w.s   $f6, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    ctx->f6.u32l = TRUNC_W_S(ctx->f24.fl);
    // 0x80069680: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80069684: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80069688: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8006968C: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80069690: mul.s       $f12, $f2, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x80069694: j           L_800696B4
    // 0x80069698: nop

        goto L_800696B4;
    // 0x80069698: nop

L_8006969C:
    // 0x8006969C: trunc.w.s   $f6, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    ctx->f6.u32l = TRUNC_W_S(ctx->f24.fl);
    // 0x800696A0: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800696A4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800696A8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800696AC: sub.s       $f0, $f24, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f24.fl - ctx->f0.fl;
    // 0x800696B0: mul.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
L_800696B4:
    // 0x800696B4: c.lt.s      $f26, $f10
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f26.fl < ctx->f10.fl;
    // 0x800696B8: nop

    // 0x800696BC: bc1f        L_800696F0
    if (!c1cs) {
        // 0x800696C0: nop
    
            goto L_800696F0;
    }
    // 0x800696C0: nop

    // 0x800696C4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800696C8: lwc1        $f6, -0x3760($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3760);
    // 0x800696CC: add.s       $f2, $f26, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f26.fl + ctx->f6.fl;
    // 0x800696D0: trunc.w.s   $f28, $f26
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    ctx->f28.u32l = TRUNC_W_S(ctx->f26.fl);
    // 0x800696D4: mfc1        $v0, $f28
    ctx->r2 = (int32_t)ctx->f28.u32l;
    // 0x800696D8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800696DC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800696E0: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800696E4: mul.s       $f20, $f2, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x800696E8: j           L_80069708
    // 0x800696EC: nop

        goto L_80069708;
    // 0x800696EC: nop

L_800696F0:
    // 0x800696F0: trunc.w.s   $f6, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    ctx->f6.u32l = TRUNC_W_S(ctx->f26.fl);
    // 0x800696F4: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800696F8: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800696FC: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80069700: sub.s       $f0, $f26, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f26.fl - ctx->f0.fl;
    // 0x80069704: mul.s       $f20, $f0, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
L_80069708:
    // 0x80069708: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8006970C: mul.s       $f0, $f6, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x80069710: nop

    // 0x80069714: mul.s       $f0, $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80069718: lwc1        $f28, 0x28($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8006971C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80069720: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80069724: mul.s       $f2, $f28, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = MUL_S(ctx->f28.fl, ctx->f22.fl);
    // 0x80069728: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    // 0x8006972C: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x80069730: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80069734: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80069738: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x8006973C: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x80069740: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x80069744: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x80069748: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x8006974C: jal         0x80068A90
    // 0x80069750: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    sampleHmpTileHeightBicubic(rdram, ctx);
        goto after_2;
    // 0x80069750: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80069754: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80069758: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006975C: lwc1        $f28, -0x375C($at)
    ctx->f28.u32l = MEM_W(ctx->r1, -0X375C);
    // 0x80069760: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80069764: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80069768: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8006976C: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80069770: c.lt.s      $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f20.fl < ctx->f28.fl;
    // 0x80069774: nop

    // 0x80069778: bc1tl       L_80068FA0
    if (c1cs) {
        // 0x8006977C: sub.s       $f2, $f28, $f8
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f28.fl - ctx->f8.fl;
            goto L_80068FA0;
    }
    goto skip_5;
    // 0x8006977C: sub.s       $f2, $f28, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f28.fl - ctx->f8.fl;
    skip_5:
L_80069780:
    // 0x80069780: lwc1        $f28, 0x24($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80069784: mul.s       $f2, $f28, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = MUL_S(ctx->f28.fl, ctx->f22.fl);
    // 0x80069788: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006978C: lwc1        $f6, -0x3758($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3758);
    // 0x80069790: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80069794: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80069798: mul.s       $f4, $f6, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x8006979C: nop

    // 0x800697A0: mul.s       $f0, $f22, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x800697A4: lwc1        $f28, 0x40($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800697A8: add.s       $f26, $f26, $f28
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f26.fl = ctx->f26.fl + ctx->f28.fl;
    // 0x800697AC: sub.s       $f18, $f18, $f28
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f28.fl;
    // 0x800697B0: add.s       $f24, $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f2.fl;
    // 0x800697B4: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800697B8: sub.s       $f6, $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f2.fl;
    // 0x800697BC: lwc1        $f28, 0x20($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800697C0: add.s       $f28, $f28, $f4
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f28.fl = ctx->f28.fl + ctx->f4.fl;
    // 0x800697C4: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x800697C8: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800697CC: sub.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800697D0: add.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800697D4: swc1        $f28, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f28.u32l;
    // 0x800697D8: beq         $s1, $zero, L_80069800
    if (ctx->r17 == 0) {
        // 0x800697DC: swc1        $f6, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
            goto L_80069800;
    }
    // 0x800697DC: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x800697E0: trunc.w.s   $f28, $f26
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    ctx->f28.u32l = TRUNC_W_S(ctx->f26.fl);
    // 0x800697E4: mfc1        $v1, $f28
    ctx->r3 = (int32_t)ctx->f28.u32l;
    // 0x800697E8: blez        $v1, L_80069064
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800697EC: nop
    
            goto L_80069064;
    }
    // 0x800697EC: nop

    // 0x800697F0: lhu         $v0, 0x3A($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X3A);
    // 0x800697F4: slt         $v0, $v1, $v0
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800697F8: beq         $v0, $zero, L_80069064
    if (ctx->r2 == 0) {
        // 0x800697FC: nop
    
            goto L_80069064;
    }
    // 0x800697FC: nop

L_80069800:
    // 0x80069800: c.le.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl <= ctx->f18.fl;
    // 0x80069804: nop

    // 0x80069808: bc1f        L_80069820
    if (!c1cs) {
        // 0x8006980C: nop
    
            goto L_80069820;
    }
    // 0x8006980C: nop

    // 0x80069810: lhu         $v0, 0x38($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X38);
    // 0x80069814: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80069818: j           L_80069064
    // 0x8006981C: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
        goto L_80069064;
    // 0x8006981C: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
L_80069820:
    // 0x80069820: lhu         $v0, 0x38($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X38);
    // 0x80069824: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80069828: j           L_80069064
    // 0x8006982C: subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
        goto L_80069064;
    // 0x8006982C: subu        $s0, $s0, $v0
    ctx->r16 = SUB32(ctx->r16, ctx->r2);
L_80069830:
    // 0x80069830: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80069834: lwc1        $f0, -0x3754($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3754);
    // 0x80069838: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8006983C: nop

    // 0x80069840: bc1f        L_800698B4
    if (!c1cs) {
        // 0x80069844: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_800698B4;
    }
    // 0x80069844: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80069848: beq         $s5, $zero, L_800698B0
    if (ctx->r21 == 0) {
        // 0x8006984C: addu        $a2, $s6, $zero
        ctx->r6 = ADD32(ctx->r22, 0);
            goto L_800698B0;
    }
    // 0x8006984C: addu        $a2, $s6, $zero
    ctx->r6 = ADD32(ctx->r22, 0);
    // 0x80069850: lwc1        $f0, 0x0($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80069854: mul.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80069858: lwc1        $f2, 0x8($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X8);
    // 0x8006985C: mul.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80069860: lwc1        $f12, 0x0($s4)
    ctx->f12.u32l = MEM_W(ctx->r20, 0X0);
    // 0x80069864: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x80069868: lwc1        $f14, 0x8($s4)
    ctx->f14.u32l = MEM_W(ctx->r20, 0X8);
    // 0x8006986C: add.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f2.fl;
    // 0x80069870: addu        $a3, $s5, $zero
    ctx->r7 = ADD32(ctx->r21, 0);
    // 0x80069874: jal         0x80067D90
    // 0x80069878: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    wrapAngleToCyclicRange(rdram, ctx);
        goto after_3;
    // 0x80069878: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x8006987C: lwc1        $f0, 0x0($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80069880: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80069884: lwc1        $f4, 0x4($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80069888: mul.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8006988C: lwc1        $f2, 0x8($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80069890: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80069894: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80069898: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8006989C: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x800698A0: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800698A4: mul.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800698A8: swc1        $f8, 0x18($s5)
    MEM_W(0X18, ctx->r21) = ctx->f8.u32l;
    // 0x800698AC: swc1        $f0, 0x1C($s5)
    MEM_W(0X1C, ctx->r21) = ctx->f0.u32l;
L_800698B0:
    // 0x800698B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800698B4:
    // 0x800698B4: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x800698B8: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x800698BC: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x800698C0: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x800698C4: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x800698C8: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x800698CC: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x800698D0: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x800698D4: ldc1        $f30, 0x90($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X90);
    // 0x800698D8: ldc1        $f28, 0x88($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X88);
    // 0x800698DC: ldc1        $f26, 0x80($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X80);
    // 0x800698E0: ldc1        $f24, 0x78($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X78);
    // 0x800698E4: ldc1        $f22, 0x70($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X70);
    // 0x800698E8: ldc1        $f20, 0x68($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X68);
    // 0x800698EC: jr          $ra
    // 0x800698F0: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x800698F0: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_800698F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800698F4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800698F8: addiu       $v0, $v0, 0x6DC0
    ctx->r2 = ADD32(ctx->r2, 0X6DC0);
    // 0x800698FC: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80069900: sub.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x80069904: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80069908: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8006990C: nop

    // 0x80069910: bc1f        L_8006994C
    if (!c1cs) {
        // 0x80069914: nop
    
            goto L_8006994C;
    }
    // 0x80069914: nop

    // 0x80069918: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006991C: lwc1        $f0, -0x3750($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3750);
    // 0x80069920: mul.s       $f0, $f12, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80069924: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80069928: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8006992C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80069930: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80069934: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80069938: sub.s       $f0, $f12, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x8006993C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80069940: lwc1        $f2, -0x374C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X374C);
    // 0x80069944: j           L_80069984
    // 0x80069948: add.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f2.fl;
        goto L_80069984;
    // 0x80069948: add.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f2.fl;
L_8006994C:
    // 0x8006994C: lwc1        $f0, 0x24($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80069950: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x80069954: nop

    // 0x80069958: bc1fl       L_80069988
    if (!c1cs) {
        // 0x8006995C: add.s       $f12, $f12, $f12
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f12.fl;
            goto L_80069988;
    }
    goto skip_0;
    // 0x8006995C: add.s       $f12, $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f12.fl;
    skip_0:
    // 0x80069960: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80069964: lwc1        $f0, -0x3748($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3748);
    // 0x80069968: mul.s       $f0, $f12, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8006996C: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80069970: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80069974: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80069978: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8006997C: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80069980: sub.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f0.fl;
L_80069984:
    // 0x80069984: add.s       $f12, $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f12.fl;
L_80069988:
    // 0x80069988: trunc.w.s   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x8006998C: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x80069990: bgez        $a3, L_8006999C
    if (SIGNED(ctx->r7) >= 0) {
        // 0x80069994: addu        $v0, $a3, $zero
        ctx->r2 = ADD32(ctx->r7, 0);
            goto L_8006999C;
    }
    // 0x80069994: addu        $v0, $a3, $zero
    ctx->r2 = ADD32(ctx->r7, 0);
    // 0x80069998: addiu       $v0, $a3, 0x3
    ctx->r2 = ADD32(ctx->r7, 0X3);
L_8006999C:
    // 0x8006999C: sra         $t0, $v0, 2
    ctx->r8 = S32(SIGNED(ctx->r2) >> 2);
    // 0x800699A0: addu        $a0, $t0, $zero
    ctx->r4 = ADD32(ctx->r8, 0);
    // 0x800699A4: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x800699A8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800699AC: addiu       $v0, $v0, 0x6DC0
    ctx->r2 = ADD32(ctx->r2, 0X6DC0);
    // 0x800699B0: lwc1        $f0, 0x2C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x800699B4: subu        $t0, $a3, $v1
    ctx->r8 = SUB32(ctx->r7, ctx->r3);
    // 0x800699B8: sub.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x800699BC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800699C0: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x800699C4: nop

    // 0x800699C8: bc1f        L_80069A04
    if (!c1cs) {
        // 0x800699CC: addu        $a3, $a0, $zero
        ctx->r7 = ADD32(ctx->r4, 0);
            goto L_80069A04;
    }
    // 0x800699CC: addu        $a3, $a0, $zero
    ctx->r7 = ADD32(ctx->r4, 0);
    // 0x800699D0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800699D4: lwc1        $f0, -0x3744($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3744);
    // 0x800699D8: mul.s       $f0, $f14, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800699DC: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800699E0: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800699E4: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x800699E8: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x800699EC: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800699F0: sub.s       $f0, $f14, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x800699F4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800699F8: lwc1        $f2, -0x3740($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3740);
    // 0x800699FC: j           L_80069A3C
    // 0x80069A00: add.s       $f14, $f0, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f2.fl;
        goto L_80069A3C;
    // 0x80069A00: add.s       $f14, $f0, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f2.fl;
L_80069A04:
    // 0x80069A04: lwc1        $f0, 0x30($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80069A08: c.le.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl <= ctx->f14.fl;
    // 0x80069A0C: nop

    // 0x80069A10: bc1fl       L_80069A40
    if (!c1cs) {
        // 0x80069A14: add.s       $f14, $f14, $f14
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f14.fl;
            goto L_80069A40;
    }
    goto skip_1;
    // 0x80069A14: add.s       $f14, $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f14.fl;
    skip_1:
    // 0x80069A18: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80069A1C: lwc1        $f0, -0x373C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X373C);
    // 0x80069A20: mul.s       $f0, $f14, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80069A24: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80069A28: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80069A2C: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x80069A30: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80069A34: add.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80069A38: sub.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f0.fl;
L_80069A3C:
    // 0x80069A3C: add.s       $f14, $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f14.fl;
L_80069A40:
    // 0x80069A40: trunc.w.s   $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    ctx->f4.u32l = TRUNC_W_S(ctx->f14.fl);
    // 0x80069A44: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80069A48: bgez        $a2, L_80069A54
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80069A4C: addu        $v0, $a2, $zero
        ctx->r2 = ADD32(ctx->r6, 0);
            goto L_80069A54;
    }
    // 0x80069A4C: addu        $v0, $a2, $zero
    ctx->r2 = ADD32(ctx->r6, 0);
    // 0x80069A50: addiu       $v0, $a2, 0x3
    ctx->r2 = ADD32(ctx->r6, 0X3);
L_80069A54:
    // 0x80069A54: sra         $a0, $v0, 2
    ctx->r4 = S32(SIGNED(ctx->r2) >> 2);
    // 0x80069A58: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80069A5C: addiu       $a1, $v1, 0x6DC0
    ctx->r5 = ADD32(ctx->r3, 0X6DC0);
    // 0x80069A60: lhu         $v0, 0x38($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X38);
    // 0x80069A64: mult        $a0, $v0
    result = S64(S32(ctx->r4)) * S64(S32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80069A68: lw          $v1, 0x6DC0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6DC0);
    // 0x80069A6C: mflo        $t1
    ctx->r9 = lo;
    // 0x80069A70: addu        $v0, $a3, $t1
    ctx->r2 = ADD32(ctx->r7, ctx->r9);
    // 0x80069A74: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80069A78: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80069A7C: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x80069A80: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80069A84: andi        $v1, $v1, 0x1FFF
    ctx->r3 = ctx->r3 & 0X1FFF;
    // 0x80069A88: sll         $v0, $v1, 4
    ctx->r2 = S32(ctx->r3 << 4);
    // 0x80069A8C: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x80069A90: lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X4);
    // 0x80069A94: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80069A98: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x80069A9C: lbu         $a1, 0x2($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X2);
    // 0x80069AA0: andi        $v0, $a1, 0x8
    ctx->r2 = ctx->r5 & 0X8;
    // 0x80069AA4: bne         $v0, $zero, L_80069ADC
    if (ctx->r2 != 0) {
        // 0x80069AA8: subu        $a0, $a2, $a0
        ctx->r4 = SUB32(ctx->r6, ctx->r4);
            goto L_80069ADC;
    }
    // 0x80069AA8: subu        $a0, $a2, $a0
    ctx->r4 = SUB32(ctx->r6, ctx->r4);
    // 0x80069AAC: andi        $v0, $a1, 0x10
    ctx->r2 = ctx->r5 & 0X10;
    // 0x80069AB0: beq         $v0, $zero, L_80069AE4
    if (ctx->r2 == 0) {
        // 0x80069AB4: sll         $v0, $a0, 2
        ctx->r2 = S32(ctx->r4 << 2);
            goto L_80069AE4;
    }
    // 0x80069AB4: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80069AB8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x80069ABC: addu        $v0, $t0, $v0
    ctx->r2 = ADD32(ctx->r8, ctx->r2);
    // 0x80069AC0: addu        $v0, $v1, $v0
    ctx->r2 = ADD32(ctx->r3, ctx->r2);
    // 0x80069AC4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80069AC8: lb          $v0, 0x5($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X5);
    // 0x80069ACC: lw          $v1, 0x75C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X75C0);
    // 0x80069AD0: slt         $v0, $v0, $v1
    ctx->r2 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80069AD4: bne         $v0, $zero, L_80069AE4
    if (ctx->r2 != 0) {
        // 0x80069AD8: nop
    
            goto L_80069AE4;
    }
    // 0x80069AD8: nop

L_80069ADC:
    // 0x80069ADC: jr          $ra
    // 0x80069AE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80069AE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80069AE4:
    // 0x80069AE4: jr          $ra
    // 0x80069AE8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80069AE8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void fake_func_80069AEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_80069AF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069AF0: addiu       $sp, $sp, -0xF0
    ctx->r29 = ADD32(ctx->r29, -0XF0);
    // 0x80069AF4: sw          $s6, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r22;
    // 0x80069AF8: addu        $s6, $a1, $zero
    ctx->r22 = ADD32(ctx->r5, 0);
    // 0x80069AFC: sw          $s5, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r21;
    // 0x80069B00: addu        $s5, $a2, $zero
    ctx->r21 = ADD32(ctx->r6, 0);
    // 0x80069B04: sw          $ra, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r31;
    // 0x80069B08: sw          $fp, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r30;
    // 0x80069B0C: sw          $s7, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r23;
    // 0x80069B10: sw          $s4, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r20;
    // 0x80069B14: sw          $s3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r19;
    // 0x80069B18: sw          $s2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r18;
    // 0x80069B1C: sw          $s1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r17;
    // 0x80069B20: sw          $s0, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r16;
    // 0x80069B24: sdc1        $f30, 0xE8($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0XE8, ctx->r29);
    // 0x80069B28: sdc1        $f28, 0xE0($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0XE0, ctx->r29);
    // 0x80069B2C: sdc1        $f26, 0xD8($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0XD8, ctx->r29);
    // 0x80069B30: sdc1        $f24, 0xD0($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0XD0, ctx->r29);
    // 0x80069B34: sdc1        $f22, 0xC8($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0XC8, ctx->r29);
    // 0x80069B38: sdc1        $f20, 0xC0($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0XC0, ctx->r29);
    // 0x80069B3C: sw          $a0, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r4;
    // 0x80069B40: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80069B44: addu        $s4, $a3, $zero
    ctx->r20 = ADD32(ctx->r7, 0);
    // 0x80069B48: sw          $zero, 0x90($sp)
    MEM_W(0X90, ctx->r29) = 0;
    // 0x80069B4C: lw          $fp, 0x58($v0)
    ctx->r30 = MEM_W(ctx->r2, 0X58);
    // 0x80069B50: lbu         $v1, 0x1($fp)
    ctx->r3 = MEM_BU(ctx->r30, 0X1);
    // 0x80069B54: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80069B58: beq         $v1, $v0, L_8006A8F8
    if (ctx->r3 == ctx->r2) {
        // 0x80069B5C: addiu       $s0, $a0, 0x28
        ctx->r16 = ADD32(ctx->r4, 0X28);
            goto L_8006A8F8;
    }
    // 0x80069B5C: addiu       $s0, $a0, 0x28
    ctx->r16 = ADD32(ctx->r4, 0X28);
    // 0x80069B60: addiu       $s7, $fp, 0x1
    ctx->r23 = ADD32(ctx->r30, 0X1);
    // 0x80069B64: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80069B68: lwc1        $f30, -0x3730($at)
    ctx->f30.u32l = MEM_W(ctx->r1, -0X3730);
    // 0x80069B6C: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
L_80069B70:
    // 0x80069B70: lbu         $v0, 0x0($s7)
    ctx->r2 = MEM_BU(ctx->r23, 0X0);
    // 0x80069B74: lw          $t0, 0x90($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X90);
    // 0x80069B78: beq         $v0, $t0, L_80069BF8
    if (ctx->r2 == ctx->r8) {
        // 0x80069B7C: nop
    
            goto L_80069BF8;
    }
    // 0x80069B7C: nop

    // 0x80069B80: sw          $v0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r2;
    // 0x80069B84: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80069B88: addu        $s2, $zero, $zero
    ctx->r18 = ADD32(0, 0);
    // 0x80069B8C: lw          $t1, 0x90($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X90);
    // 0x80069B90: lw          $t2, 0xF0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XF0);
    // 0x80069B94: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x80069B98: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80069B9C: subu        $v0, $v0, $t1
    ctx->r2 = SUB32(ctx->r2, ctx->r9);
    // 0x80069BA0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80069BA4: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x80069BA8: addiu       $s1, $v0, 0xC
    ctx->r17 = ADD32(ctx->r2, 0XC);
    // 0x80069BAC: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x80069BB0: bne         $v0, $zero, L_80069BC0
    if (ctx->r2 != 0) {
        // 0x80069BB4: addiu       $s3, $sp, 0x10
        ctx->r19 = ADD32(ctx->r29, 0X10);
            goto L_80069BC0;
    }
    // 0x80069BB4: addiu       $s3, $sp, 0x10
    ctx->r19 = ADD32(ctx->r29, 0X10);
    // 0x80069BB8: j           L_80069BF8
    // 0x80069BBC: addiu       $s0, $s1, 0x1C
    ctx->r16 = ADD32(ctx->r17, 0X1C);
        goto L_80069BF8;
    // 0x80069BBC: addiu       $s0, $s1, 0x1C
    ctx->r16 = ADD32(ctx->r17, 0X1C);
L_80069BC0:
    // 0x80069BC0: addiu       $a1, $s1, 0x1C
    ctx->r5 = ADD32(ctx->r17, 0X1C);
    // 0x80069BC4: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
L_80069BC8:
    // 0x80069BC8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80069BCC: addiu       $a0, $s1, 0x1C
    ctx->r4 = ADD32(ctx->r17, 0X1C);
    // 0x80069BD0: andi        $v1, $s2, 0x1
    ctx->r3 = ctx->r18 & 0X1;
    // 0x80069BD4: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x80069BD8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80069BDC: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x80069BE0: addu        $s0, $s3, $v0
    ctx->r16 = ADD32(ctx->r19, ctx->r2);
    // 0x80069BE4: jal         0x800191C4
    // 0x80069BE8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    mat3x4Multiply(rdram, ctx);
        goto after_0;
    // 0x80069BE8: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_0:
    // 0x80069BEC: lw          $s1, 0x8($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X8);
    // 0x80069BF0: bne         $s1, $zero, L_80069BC8
    if (ctx->r17 != 0) {
        // 0x80069BF4: addu        $a1, $s0, $zero
        ctx->r5 = ADD32(ctx->r16, 0);
            goto L_80069BC8;
    }
    // 0x80069BF4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
L_80069BF8:
    // 0x80069BF8: lbu         $v1, 0x0($fp)
    ctx->r3 = MEM_BU(ctx->r30, 0X0);
    // 0x80069BFC: bne         $v1, $zero, L_8006A488
    if (ctx->r3 != 0) {
        // 0x80069C00: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8006A488;
    }
    // 0x80069C00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80069C04: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80069C08: addiu       $a1, $fp, 0x4
    ctx->r5 = ADD32(ctx->r30, 0X4);
    // 0x80069C0C: jal         0x800193E8
    // 0x80069C10: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    transformVec3ByMat34(rdram, ctx);
        goto after_1;
    // 0x80069C10: addiu       $a2, $sp, 0x70
    ctx->r6 = ADD32(ctx->r29, 0X70);
    after_1:
    // 0x80069C14: lwc1        $f0, 0x70($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80069C18: lwc1        $f2, 0x0($s6)
    ctx->f2.u32l = MEM_W(ctx->r22, 0X0);
    // 0x80069C1C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80069C20: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    // 0x80069C24: lwc1        $f0, 0x74($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80069C28: lwc1        $f2, 0x4($s6)
    ctx->f2.u32l = MEM_W(ctx->r22, 0X4);
    // 0x80069C2C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80069C30: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
    // 0x80069C34: lwc1        $f0, 0x78($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80069C38: lwc1        $f2, 0x8($s6)
    ctx->f2.u32l = MEM_W(ctx->r22, 0X8);
    // 0x80069C3C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x80069C40: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80069C44: addiu       $a1, $fp, 0x10
    ctx->r5 = ADD32(ctx->r30, 0X10);
    // 0x80069C48: addiu       $a2, $sp, 0x80
    ctx->r6 = ADD32(ctx->r29, 0X80);
    // 0x80069C4C: jal         0x800193E8
    // 0x80069C50: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    transformVec3ByMat34(rdram, ctx);
        goto after_2;
    // 0x80069C50: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x80069C54: lwc1        $f2, 0x80($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80069C58: lwc1        $f0, 0x0($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X0);
    // 0x80069C5C: sub.s       $f20, $f2, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80069C60: lwc1        $f2, 0x84($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80069C64: swc1        $f20, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f20.u32l;
    // 0x80069C68: lwc1        $f0, 0x4($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X4);
    // 0x80069C6C: sub.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80069C70: lwc1        $f2, 0x88($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80069C74: swc1        $f18, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f18.u32l;
    // 0x80069C78: lwc1        $f0, 0x8($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X8);
    // 0x80069C7C: sub.s       $f16, $f2, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80069C80: swc1        $f16, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f16.u32l;
    // 0x80069C84: lwc1        $f10, 0x0($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80069C88: mul.s       $f0, $f10, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x80069C8C: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80069C90: mul.s       $f8, $f6, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x80069C94: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80069C98: mul.s       $f2, $f4, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x80069C9C: add.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80069CA0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80069CA4: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80069CA8: div.s       $f24, $f30, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = DIV_S(ctx->f30.fl, ctx->f0.fl);
    // 0x80069CAC: mul.s       $f14, $f10, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x80069CB0: nop

    // 0x80069CB4: mul.s       $f22, $f6, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f22.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x80069CB8: nop

    // 0x80069CBC: mul.s       $f24, $f24, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f24.fl = MUL_S(ctx->f24.fl, ctx->f4.fl);
    // 0x80069CC0: lwc1        $f2, 0x0($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X0);
    // 0x80069CC4: mul.s       $f2, $f14, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80069CC8: lwc1        $f26, 0x4($s5)
    ctx->f26.u32l = MEM_W(ctx->r21, 0X4);
    // 0x80069CCC: mul.s       $f4, $f22, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f26.fl);
    // 0x80069CD0: lwc1        $f0, 0x8($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X8);
    // 0x80069CD4: mul.s       $f0, $f24, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x80069CD8: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x80069CDC: add.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80069CE0: c.eq.s      $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f12.fl == ctx->f28.fl;
    // 0x80069CE4: nop

    // 0x80069CE8: bc1t        L_80069D94
    if (c1cs) {
        // 0x80069CEC: nop
    
            goto L_80069D94;
    }
    // 0x80069CEC: nop

    // 0x80069CF0: c.le.s      $f28, $f12
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f28.fl <= ctx->f12.fl;
    // 0x80069CF4: nop

    // 0x80069CF8: bc1f        L_80069D48
    if (!c1cs) {
        // 0x80069CFC: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_80069D48;
    }
    // 0x80069CFC: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
    // 0x80069D00: mul.s       $f0, $f14, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x80069D04: nop

    // 0x80069D08: mul.s       $f4, $f22, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f18.fl);
    // 0x80069D0C: nop

    // 0x80069D10: mul.s       $f10, $f24, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f24.fl, ctx->f16.fl);
    // 0x80069D14: lwc1        $f2, 0x70($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80069D18: mul.s       $f2, $f14, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80069D1C: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80069D20: mul.s       $f6, $f22, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f6.fl);
    // 0x80069D24: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80069D28: mul.s       $f8, $f24, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f24.fl, ctx->f8.fl);
    // 0x80069D2C: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80069D30: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x80069D34: add.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80069D38: add.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x80069D3C: div.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80069D40: j           L_80069E2C
    // 0x80069D44: div.s       $f26, $f2, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f26.fl = DIV_S(ctx->f2.fl, ctx->f12.fl);
        goto L_80069E2C;
    // 0x80069D44: div.s       $f26, $f2, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f26.fl = DIV_S(ctx->f2.fl, ctx->f12.fl);
L_80069D48:
    // 0x80069D48: mul.s       $f0, $f14, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x80069D4C: nop

    // 0x80069D50: mul.s       $f4, $f22, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f18.fl);
    // 0x80069D54: nop

    // 0x80069D58: mul.s       $f10, $f24, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f24.fl, ctx->f16.fl);
    // 0x80069D5C: lwc1        $f2, 0x70($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80069D60: mul.s       $f2, $f14, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80069D64: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80069D68: mul.s       $f6, $f22, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f6.fl);
    // 0x80069D6C: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80069D70: mul.s       $f8, $f24, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f24.fl, ctx->f8.fl);
    // 0x80069D74: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80069D78: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
    // 0x80069D7C: add.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80069D80: add.s       $f2, $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f8.fl;
    // 0x80069D84: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x80069D88: div.s       $f26, $f0, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f26.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80069D8C: j           L_80069E2C
    // 0x80069D90: div.s       $f16, $f2, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = DIV_S(ctx->f2.fl, ctx->f12.fl);
        goto L_80069E2C;
    // 0x80069D90: div.s       $f16, $f2, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = DIV_S(ctx->f2.fl, ctx->f12.fl);
L_80069D94:
    // 0x80069D94: mul.s       $f0, $f14, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x80069D98: nop

    // 0x80069D9C: mul.s       $f2, $f22, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f22.fl, ctx->f18.fl);
    // 0x80069DA0: nop

    // 0x80069DA4: mul.s       $f4, $f24, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f16.fl);
    // 0x80069DA8: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80069DAC: mul.s       $f6, $f14, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x80069DB0: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80069DB4: mul.s       $f10, $f22, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f10.fl);
    // 0x80069DB8: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80069DBC: mul.s       $f8, $f24, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f24.fl, ctx->f8.fl);
    // 0x80069DC0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80069DC4: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80069DC8: add.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80069DCC: c.le.s      $f28, $f20
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f28.fl <= ctx->f20.fl;
    // 0x80069DD0: nop

    // 0x80069DD4: bc1f        L_80069DEC
    if (!c1cs) {
        // 0x80069DD8: add.s       $f12, $f0, $f4
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
            goto L_80069DEC;
    }
    // 0x80069DD8: add.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80069DDC: c.le.s      $f28, $f12
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f28.fl <= ctx->f12.fl;
    // 0x80069DE0: nop

    // 0x80069DE4: bc1tl       L_8006A8E8
    if (c1cs) {
        // 0x80069DE8: addiu       $s7, $s7, 0x1C
        ctx->r23 = ADD32(ctx->r23, 0X1C);
            goto L_8006A8E8;
    }
    goto skip_0;
    // 0x80069DE8: addiu       $s7, $s7, 0x1C
    ctx->r23 = ADD32(ctx->r23, 0X1C);
    skip_0:
L_80069DEC:
    // 0x80069DEC: c.lt.s      $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f20.fl < ctx->f28.fl;
    // 0x80069DF0: nop

    // 0x80069DF4: bc1f        L_80069E0C
    if (!c1cs) {
        // 0x80069DF8: nop
    
            goto L_80069E0C;
    }
    // 0x80069DF8: nop

    // 0x80069DFC: c.lt.s      $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f12.fl < ctx->f28.fl;
    // 0x80069E00: nop

    // 0x80069E04: bc1tl       L_8006A8E8
    if (c1cs) {
        // 0x80069E08: addiu       $s7, $s7, 0x1C
        ctx->r23 = ADD32(ctx->r23, 0X1C);
            goto L_8006A8E8;
    }
    goto skip_1;
    // 0x80069E08: addiu       $s7, $s7, 0x1C
    ctx->r23 = ADD32(ctx->r23, 0X1C);
    skip_1:
L_80069E0C:
    // 0x80069E0C: c.eq.s      $f26, $f28
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f26.fl == ctx->f28.fl;
    // 0x80069E10: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80069E14: lwc1        $f16, -0x372C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X372C);
    // 0x80069E18: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80069E1C: lwc1        $f26, -0x3728($at)
    ctx->f26.u32l = MEM_W(ctx->r1, -0X3728);
    // 0x80069E20: bc1t        L_80069E2C
    if (c1cs) {
        // 0x80069E24: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_80069E2C;
    }
    // 0x80069E24: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80069E28: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80069E2C:
    // 0x80069E2C: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80069E30: mul.s       $f0, $f10, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x80069E34: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80069E38: mul.s       $f8, $f6, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x80069E3C: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80069E40: mul.s       $f2, $f4, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x80069E44: add.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x80069E48: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80069E4C: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x80069E50: div.s       $f24, $f30, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = DIV_S(ctx->f30.fl, ctx->f0.fl);
    // 0x80069E54: mul.s       $f14, $f10, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x80069E58: nop

    // 0x80069E5C: mul.s       $f22, $f6, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f22.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x80069E60: nop

    // 0x80069E64: mul.s       $f24, $f24, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f24.fl = MUL_S(ctx->f24.fl, ctx->f4.fl);
    // 0x80069E68: lwc1        $f4, 0x0($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X0);
    // 0x80069E6C: mul.s       $f4, $f14, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x80069E70: lwc1        $f2, 0x4($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X4);
    // 0x80069E74: mul.s       $f2, $f22, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x80069E78: lwc1        $f0, 0x8($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X8);
    // 0x80069E7C: mul.s       $f0, $f24, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x80069E80: add.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x80069E84: add.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x80069E88: c.eq.s      $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f12.fl == ctx->f28.fl;
    // 0x80069E8C: nop

    // 0x80069E90: bc1t        L_80069F9C
    if (c1cs) {
        // 0x80069E94: nop
    
            goto L_80069F9C;
    }
    // 0x80069E94: nop

    // 0x80069E98: c.le.s      $f28, $f12
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f28.fl <= ctx->f12.fl;
    // 0x80069E9C: nop

    // 0x80069EA0: bc1f        L_80069F20
    if (!c1cs) {
        // 0x80069EA4: nop
    
            goto L_80069F20;
    }
    // 0x80069EA4: nop

    // 0x80069EA8: lwc1        $f0, 0x70($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80069EAC: mul.s       $f0, $f14, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80069EB0: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80069EB4: mul.s       $f4, $f22, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f4.fl);
    // 0x80069EB8: lwc1        $f2, 0x78($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80069EBC: mul.s       $f2, $f24, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f24.fl, ctx->f2.fl);
    // 0x80069EC0: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80069EC4: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80069EC8: div.s       $f20, $f0, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f20.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80069ECC: c.lt.s      $f26, $f20
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f26.fl < ctx->f20.fl;
    // 0x80069ED0: nop

    // 0x80069ED4: bc1f        L_80069EE4
    if (!c1cs) {
        // 0x80069ED8: nop
    
            goto L_80069EE4;
    }
    // 0x80069ED8: nop

    // 0x80069EDC: mov.s       $f26, $f20
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    ctx->f26.fl = ctx->f20.fl;
    // 0x80069EE0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80069EE4:
    // 0x80069EE4: lwc1        $f0, 0x80($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80069EE8: mul.s       $f0, $f14, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80069EEC: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80069EF0: mul.s       $f4, $f22, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f4.fl);
    // 0x80069EF4: lwc1        $f2, 0x88($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80069EF8: mul.s       $f2, $f24, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f24.fl, ctx->f2.fl);
    // 0x80069EFC: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80069F00: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80069F04: div.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80069F08: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x80069F0C: nop

    // 0x80069F10: bc1tl       L_80069F90
    if (c1cs) {
        // 0x80069F14: mov.s       $f16, $f12
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.fl = ctx->f12.fl;
            goto L_80069F90;
    }
    goto skip_2;
    // 0x80069F14: mov.s       $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.fl = ctx->f12.fl;
    skip_2:
    // 0x80069F18: j           L_80069F90
    // 0x80069F1C: nop

        goto L_80069F90;
    // 0x80069F1C: nop

L_80069F20:
    // 0x80069F20: lwc1        $f0, 0x70($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80069F24: mul.s       $f0, $f14, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80069F28: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80069F2C: mul.s       $f4, $f22, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f4.fl);
    // 0x80069F30: lwc1        $f2, 0x78($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80069F34: mul.s       $f2, $f24, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f24.fl, ctx->f2.fl);
    // 0x80069F38: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80069F3C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80069F40: div.s       $f20, $f0, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f20.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80069F44: c.lt.s      $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f20.fl < ctx->f16.fl;
    // 0x80069F48: nop

    // 0x80069F4C: bc1tl       L_80069F54
    if (c1cs) {
        // 0x80069F50: mov.s       $f16, $f20
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    ctx->f16.fl = ctx->f20.fl;
            goto L_80069F54;
    }
    goto skip_3;
    // 0x80069F50: mov.s       $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    ctx->f16.fl = ctx->f20.fl;
    skip_3:
L_80069F54:
    // 0x80069F54: lwc1        $f0, 0x80($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80069F58: mul.s       $f0, $f14, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x80069F5C: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80069F60: mul.s       $f4, $f22, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f4.fl);
    // 0x80069F64: lwc1        $f2, 0x88($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80069F68: mul.s       $f2, $f24, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f24.fl, ctx->f2.fl);
    // 0x80069F6C: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80069F70: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x80069F74: div.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80069F78: c.lt.s      $f26, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f26.fl < ctx->f12.fl;
    // 0x80069F7C: nop

    // 0x80069F80: bc1f        L_80069F90
    if (!c1cs) {
        // 0x80069F84: nop
    
            goto L_80069F90;
    }
    // 0x80069F84: nop

    // 0x80069F88: mov.s       $f26, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    ctx->f26.fl = ctx->f12.fl;
    // 0x80069F8C: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
L_80069F90:
    // 0x80069F90: c.lt.s      $f16, $f26
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f16.fl < ctx->f26.fl;
    // 0x80069F94: j           L_8006A00C
    // 0x80069F98: nop

        goto L_8006A00C;
    // 0x80069F98: nop

L_80069F9C:
    // 0x80069F9C: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80069FA0: mul.s       $f6, $f14, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x80069FA4: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80069FA8: mul.s       $f10, $f22, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f10.fl);
    // 0x80069FAC: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80069FB0: mul.s       $f8, $f24, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f24.fl, ctx->f8.fl);
    // 0x80069FB4: lwc1        $f2, 0x80($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80069FB8: mul.s       $f2, $f14, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80069FBC: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80069FC0: mul.s       $f4, $f22, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f4.fl);
    // 0x80069FC4: lwc1        $f0, 0x88($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80069FC8: mul.s       $f0, $f24, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x80069FCC: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80069FD0: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x80069FD4: add.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80069FD8: c.le.s      $f28, $f20
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f28.fl <= ctx->f20.fl;
    // 0x80069FDC: nop

    // 0x80069FE0: bc1f        L_80069FF8
    if (!c1cs) {
        // 0x80069FE4: add.s       $f12, $f2, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f0.fl;
            goto L_80069FF8;
    }
    // 0x80069FE4: add.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80069FE8: c.le.s      $f28, $f12
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f28.fl <= ctx->f12.fl;
    // 0x80069FEC: nop

    // 0x80069FF0: bc1tl       L_8006A8E8
    if (c1cs) {
        // 0x80069FF4: addiu       $s7, $s7, 0x1C
        ctx->r23 = ADD32(ctx->r23, 0X1C);
            goto L_8006A8E8;
    }
    goto skip_4;
    // 0x80069FF4: addiu       $s7, $s7, 0x1C
    ctx->r23 = ADD32(ctx->r23, 0X1C);
    skip_4:
L_80069FF8:
    // 0x80069FF8: c.lt.s      $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f20.fl < ctx->f28.fl;
    // 0x80069FFC: nop

    // 0x8006A000: bc1f        L_8006A018
    if (!c1cs) {
        // 0x8006A004: nop
    
            goto L_8006A018;
    }
    // 0x8006A004: nop

    // 0x8006A008: c.lt.s      $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f12.fl < ctx->f28.fl;
L_8006A00C:
    // 0x8006A00C: nop

    // 0x8006A010: bc1tl       L_8006A8E8
    if (c1cs) {
        // 0x8006A014: addiu       $s7, $s7, 0x1C
        ctx->r23 = ADD32(ctx->r23, 0X1C);
            goto L_8006A8E8;
    }
    goto skip_5;
    // 0x8006A014: addiu       $s7, $s7, 0x1C
    ctx->r23 = ADD32(ctx->r23, 0X1C);
    skip_5:
L_8006A018:
    // 0x8006A018: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006A01C: mul.s       $f0, $f10, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x8006A020: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8006A024: mul.s       $f8, $f6, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8006A028: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8006A02C: mul.s       $f2, $f4, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8006A030: add.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x8006A034: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8006A038: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x8006A03C: div.s       $f24, $f30, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = DIV_S(ctx->f30.fl, ctx->f0.fl);
    // 0x8006A040: mul.s       $f14, $f10, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x8006A044: nop

    // 0x8006A048: mul.s       $f22, $f6, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f22.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x8006A04C: nop

    // 0x8006A050: mul.s       $f24, $f24, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f24.fl = MUL_S(ctx->f24.fl, ctx->f4.fl);
    // 0x8006A054: lwc1        $f4, 0x0($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X0);
    // 0x8006A058: mul.s       $f4, $f14, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x8006A05C: lwc1        $f2, 0x4($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X4);
    // 0x8006A060: mul.s       $f2, $f22, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x8006A064: lwc1        $f0, 0x8($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X8);
    // 0x8006A068: mul.s       $f0, $f24, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x8006A06C: add.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8006A070: add.s       $f12, $f4, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8006A074: c.eq.s      $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f12.fl == ctx->f28.fl;
    // 0x8006A078: nop

    // 0x8006A07C: bc1t        L_8006A180
    if (c1cs) {
        // 0x8006A080: nop
    
            goto L_8006A180;
    }
    // 0x8006A080: nop

    // 0x8006A084: c.le.s      $f28, $f12
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f28.fl <= ctx->f12.fl;
    // 0x8006A088: nop

    // 0x8006A08C: bc1f        L_8006A10C
    if (!c1cs) {
        // 0x8006A090: nop
    
            goto L_8006A10C;
    }
    // 0x8006A090: nop

    // 0x8006A094: lwc1        $f0, 0x70($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8006A098: mul.s       $f0, $f14, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8006A09C: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8006A0A0: mul.s       $f4, $f22, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f4.fl);
    // 0x8006A0A4: lwc1        $f2, 0x78($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8006A0A8: mul.s       $f2, $f24, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f24.fl, ctx->f2.fl);
    // 0x8006A0AC: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8006A0B0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8006A0B4: div.s       $f20, $f0, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f20.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8006A0B8: c.lt.s      $f26, $f20
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f26.fl < ctx->f20.fl;
    // 0x8006A0BC: nop

    // 0x8006A0C0: bc1f        L_8006A0D0
    if (!c1cs) {
        // 0x8006A0C4: nop
    
            goto L_8006A0D0;
    }
    // 0x8006A0C4: nop

    // 0x8006A0C8: mov.s       $f26, $f20
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    ctx->f26.fl = ctx->f20.fl;
    // 0x8006A0CC: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_8006A0D0:
    // 0x8006A0D0: lwc1        $f0, 0x80($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8006A0D4: mul.s       $f0, $f14, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8006A0D8: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8006A0DC: mul.s       $f4, $f22, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f4.fl);
    // 0x8006A0E0: lwc1        $f2, 0x88($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8006A0E4: mul.s       $f2, $f24, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f24.fl, ctx->f2.fl);
    // 0x8006A0E8: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8006A0EC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8006A0F0: div.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8006A0F4: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x8006A0F8: nop

    // 0x8006A0FC: bc1tl       L_8006A1FC
    if (c1cs) {
        // 0x8006A100: mov.s       $f16, $f12
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.fl = ctx->f12.fl;
            goto L_8006A1FC;
    }
    goto skip_6;
    // 0x8006A100: mov.s       $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.fl = ctx->f12.fl;
    skip_6:
    // 0x8006A104: j           L_8006A1FC
    // 0x8006A108: nop

        goto L_8006A1FC;
    // 0x8006A108: nop

L_8006A10C:
    // 0x8006A10C: lwc1        $f0, 0x70($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8006A110: mul.s       $f0, $f14, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8006A114: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8006A118: mul.s       $f4, $f22, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f4.fl);
    // 0x8006A11C: lwc1        $f2, 0x78($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8006A120: mul.s       $f2, $f24, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f24.fl, ctx->f2.fl);
    // 0x8006A124: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8006A128: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8006A12C: div.s       $f20, $f0, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f20.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8006A130: c.lt.s      $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f20.fl < ctx->f16.fl;
    // 0x8006A134: nop

    // 0x8006A138: bc1tl       L_8006A140
    if (c1cs) {
        // 0x8006A13C: mov.s       $f16, $f20
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    ctx->f16.fl = ctx->f20.fl;
            goto L_8006A140;
    }
    goto skip_7;
    // 0x8006A13C: mov.s       $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    ctx->f16.fl = ctx->f20.fl;
    skip_7:
L_8006A140:
    // 0x8006A140: lwc1        $f0, 0x80($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8006A144: mul.s       $f0, $f14, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8006A148: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8006A14C: mul.s       $f4, $f22, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f4.fl);
    // 0x8006A150: lwc1        $f2, 0x88($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8006A154: mul.s       $f2, $f24, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f24.fl, ctx->f2.fl);
    // 0x8006A158: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8006A15C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8006A160: div.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = DIV_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8006A164: c.lt.s      $f26, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f26.fl < ctx->f12.fl;
    // 0x8006A168: nop

    // 0x8006A16C: bc1f        L_8006A1FC
    if (!c1cs) {
        // 0x8006A170: nop
    
            goto L_8006A1FC;
    }
    // 0x8006A170: nop

    // 0x8006A174: mov.s       $f26, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    ctx->f26.fl = ctx->f12.fl;
    // 0x8006A178: j           L_8006A1FC
    // 0x8006A17C: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
        goto L_8006A1FC;
    // 0x8006A17C: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
L_8006A180:
    // 0x8006A180: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8006A184: mul.s       $f6, $f14, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f6.fl);
    // 0x8006A188: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8006A18C: mul.s       $f10, $f22, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f10.fl);
    // 0x8006A190: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8006A194: mul.s       $f8, $f24, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f24.fl, ctx->f8.fl);
    // 0x8006A198: lwc1        $f2, 0x80($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8006A19C: mul.s       $f2, $f14, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x8006A1A0: lwc1        $f4, 0x84($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8006A1A4: mul.s       $f4, $f22, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f4.fl);
    // 0x8006A1A8: lwc1        $f0, 0x88($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8006A1AC: mul.s       $f0, $f24, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x8006A1B0: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8006A1B4: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x8006A1B8: add.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8006A1BC: c.le.s      $f28, $f20
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f28.fl <= ctx->f20.fl;
    // 0x8006A1C0: nop

    // 0x8006A1C4: bc1f        L_8006A1DC
    if (!c1cs) {
        // 0x8006A1C8: add.s       $f12, $f2, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f0.fl;
            goto L_8006A1DC;
    }
    // 0x8006A1C8: add.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8006A1CC: c.le.s      $f28, $f12
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f28.fl <= ctx->f12.fl;
    // 0x8006A1D0: nop

    // 0x8006A1D4: bc1tl       L_8006A8E8
    if (c1cs) {
        // 0x8006A1D8: addiu       $s7, $s7, 0x1C
        ctx->r23 = ADD32(ctx->r23, 0X1C);
            goto L_8006A8E8;
    }
    goto skip_8;
    // 0x8006A1D8: addiu       $s7, $s7, 0x1C
    ctx->r23 = ADD32(ctx->r23, 0X1C);
    skip_8:
L_8006A1DC:
    // 0x8006A1DC: c.lt.s      $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f20.fl < ctx->f28.fl;
    // 0x8006A1E0: nop

    // 0x8006A1E4: bc1f        L_8006A1FC
    if (!c1cs) {
        // 0x8006A1E8: nop
    
            goto L_8006A1FC;
    }
    // 0x8006A1E8: nop

    // 0x8006A1EC: c.lt.s      $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f12.fl < ctx->f28.fl;
    // 0x8006A1F0: nop

    // 0x8006A1F4: bc1tl       L_8006A8E8
    if (c1cs) {
        // 0x8006A1F8: addiu       $s7, $s7, 0x1C
        ctx->r23 = ADD32(ctx->r23, 0X1C);
            goto L_8006A8E8;
    }
    goto skip_9;
    // 0x8006A1F8: addiu       $s7, $s7, 0x1C
    ctx->r23 = ADD32(ctx->r23, 0X1C);
    skip_9:
L_8006A1FC:
    // 0x8006A1FC: c.lt.s      $f26, $f16
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f26.fl < ctx->f16.fl;
    // 0x8006A200: nop

    // 0x8006A204: bc1fl       L_8006A8E8
    if (!c1cs) {
        // 0x8006A208: addiu       $s7, $s7, 0x1C
        ctx->r23 = ADD32(ctx->r23, 0X1C);
            goto L_8006A8E8;
    }
    goto skip_10;
    // 0x8006A208: addiu       $s7, $s7, 0x1C
    ctx->r23 = ADD32(ctx->r23, 0X1C);
    skip_10:
    // 0x8006A20C: c.le.s      $f26, $f30
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f26.fl <= ctx->f30.fl;
    // 0x8006A210: nop

    // 0x8006A214: bc1fl       L_8006A8E8
    if (!c1cs) {
        // 0x8006A218: addiu       $s7, $s7, 0x1C
        ctx->r23 = ADD32(ctx->r23, 0X1C);
            goto L_8006A8E8;
    }
    goto skip_11;
    // 0x8006A218: addiu       $s7, $s7, 0x1C
    ctx->r23 = ADD32(ctx->r23, 0X1C);
    skip_11:
    // 0x8006A21C: c.le.s      $f28, $f16
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f28.fl <= ctx->f16.fl;
    // 0x8006A220: nop

    // 0x8006A224: bc1fl       L_8006A8E8
    if (!c1cs) {
        // 0x8006A228: addiu       $s7, $s7, 0x1C
        ctx->r23 = ADD32(ctx->r23, 0X1C);
            goto L_8006A8E8;
    }
    goto skip_12;
    // 0x8006A228: addiu       $s7, $s7, 0x1C
    ctx->r23 = ADD32(ctx->r23, 0X1C);
    skip_12:
    // 0x8006A22C: beq         $s4, $zero, L_8006A8FC
    if (ctx->r20 == 0) {
        // 0x8006A230: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8006A8FC;
    }
    // 0x8006A230: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006A234: c.lt.s      $f26, $f28
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f26.fl < ctx->f28.fl;
    // 0x8006A238: nop

    // 0x8006A23C: bc1f        L_8006A274
    if (!c1cs) {
        // 0x8006A240: addiu       $a0, $s4, 0xC
        ctx->r4 = ADD32(ctx->r20, 0XC);
            goto L_8006A274;
    }
    // 0x8006A240: addiu       $a0, $s4, 0xC
    ctx->r4 = ADD32(ctx->r20, 0XC);
    // 0x8006A244: mov.s       $f26, $f28
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 28);
    ctx->f26.fl = ctx->f28.fl;
    // 0x8006A248: jal         0x8001CFA0
    // 0x8006A24C: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    vec3NormalizeInto(rdram, ctx);
        goto after_3;
    // 0x8006A24C: addu        $a1, $s5, $zero
    ctx->r5 = ADD32(ctx->r21, 0);
    after_3:
    // 0x8006A250: lw          $t3, 0x0($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X0);
    // 0x8006A254: lw          $t0, 0x4($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X4);
    // 0x8006A258: lw          $t1, 0x8($s6)
    ctx->r9 = MEM_W(ctx->r22, 0X8);
    // 0x8006A25C: sw          $t3, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r11;
    // 0x8006A260: sw          $t0, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r8;
    // 0x8006A264: sw          $t1, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r9;
    // 0x8006A268: swc1        $f26, 0x1C($s4)
    MEM_W(0X1C, ctx->r20) = ctx->f26.u32l;
    // 0x8006A26C: j           L_8006A358
    // 0x8006A270: swc1        $f26, 0x18($s4)
    MEM_W(0X18, ctx->r20) = ctx->f26.u32l;
        goto L_8006A358;
    // 0x8006A270: swc1        $f26, 0x18($s4)
    MEM_W(0X18, ctx->r20) = ctx->f26.u32l;
L_8006A274:
    // 0x8006A274: slti        $v0, $v1, 0x3
    ctx->r2 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x8006A278: bne         $v0, $zero, L_8006A2C0
    if (ctx->r2 != 0) {
        // 0x8006A27C: sll         $v0, $v1, 2
        ctx->r2 = S32(ctx->r3 << 2);
            goto L_8006A2C0;
    }
    // 0x8006A27C: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8006A280: addiu       $v1, $v1, -0x3
    ctx->r3 = ADD32(ctx->r3, -0X3);
    // 0x8006A284: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8006A288: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x8006A28C: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8006A290: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8006A294: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8006A298: mul.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8006A29C: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8006A2A0: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8006A2A4: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x8006A2A8: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8006A2AC: sqrt.s      $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = sqrtf(ctx->f2.fl);
    // 0x8006A2B0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006A2B4: lwc1        $f0, -0x3724($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3724);
    // 0x8006A2B8: j           L_8006A2EC
    // 0x8006A2BC: div.s       $f24, $f0, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
        goto L_8006A2EC;
    // 0x8006A2BC: div.s       $f24, $f0, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
L_8006A2C0:
    // 0x8006A2C0: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x8006A2C4: lwc1        $f2, 0x0($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8006A2C8: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8006A2CC: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8006A2D0: mul.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8006A2D4: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8006A2D8: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8006A2DC: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x8006A2E0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8006A2E4: sqrt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = sqrtf(ctx->f2.fl);
    // 0x8006A2E8: div.s       $f24, $f30, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = DIV_S(ctx->f30.fl, ctx->f0.fl);
L_8006A2EC:
    // 0x8006A2EC: sll         $v0, $v1, 2
    ctx->r2 = S32(ctx->r3 << 2);
    // 0x8006A2F0: addu        $v0, $s0, $v0
    ctx->r2 = ADD32(ctx->r16, ctx->r2);
    // 0x8006A2F4: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8006A2F8: mul.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x8006A2FC: swc1        $f0, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->f0.u32l;
    // 0x8006A300: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8006A304: mul.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x8006A308: swc1        $f0, 0x10($s4)
    MEM_W(0X10, ctx->r20) = ctx->f0.u32l;
    // 0x8006A30C: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8006A310: mul.s       $f0, $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x8006A314: swc1        $f26, 0x18($s4)
    MEM_W(0X18, ctx->r20) = ctx->f26.u32l;
    // 0x8006A318: swc1        $f0, 0x14($s4)
    MEM_W(0X14, ctx->r20) = ctx->f0.u32l;
    // 0x8006A31C: lwc1        $f2, 0x0($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X0);
    // 0x8006A320: mul.s       $f2, $f2, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f26.fl);
    // 0x8006A324: lwc1        $f0, 0x0($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X0);
    // 0x8006A328: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8006A32C: swc1        $f0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f0.u32l;
    // 0x8006A330: lwc1        $f2, 0x4($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X4);
    // 0x8006A334: mul.s       $f2, $f2, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f26.fl);
    // 0x8006A338: lwc1        $f0, 0x4($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X4);
    // 0x8006A33C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8006A340: swc1        $f0, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->f0.u32l;
    // 0x8006A344: lwc1        $f2, 0x8($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X8);
    // 0x8006A348: mul.s       $f2, $f2, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f26.fl);
    // 0x8006A34C: lwc1        $f0, 0x8($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X8);
    // 0x8006A350: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8006A354: swc1        $f0, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->f0.u32l;
L_8006A358:
    // 0x8006A358: lwc1        $f2, 0x0($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X0);
    // 0x8006A35C: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8006A360: lwc1        $f4, 0x4($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X4);
    // 0x8006A364: mul.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8006A368: lwc1        $f0, 0x8($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X8);
    // 0x8006A36C: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8006A370: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x8006A374: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8006A378: sqrt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = sqrtf(ctx->f2.fl);
    // 0x8006A37C: mul.s       $f0, $f26, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f26.fl, ctx->f0.fl);
    // 0x8006A380: swc1        $f0, 0x1C($s4)
    MEM_W(0X1C, ctx->r20) = ctx->f0.u32l;
    // 0x8006A384: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8006A388: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8006A38C: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006A390: mul.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8006A394: lwc1        $f0, 0x18($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8006A398: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8006A39C: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x8006A3A0: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8006A3A4: sqrt.s      $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = sqrtf(ctx->f2.fl);
    // 0x8006A3A8: lwc1        $f6, 0xF($s7)
    ctx->f6.u32l = MEM_W(ctx->r23, 0XF);
    // 0x8006A3AC: lwc1        $f0, 0x3($s7)
    ctx->f0.u32l = MEM_W(ctx->r23, 0X3);
    // 0x8006A3B0: sub.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8006A3B4: mul.s       $f6, $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8006A3B8: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    // 0x8006A3BC: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006A3C0: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8006A3C4: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8006A3C8: mul.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8006A3CC: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8006A3D0: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8006A3D4: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x8006A3D8: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8006A3DC: sqrt.s      $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = sqrtf(ctx->f2.fl);
    // 0x8006A3E0: lwc1        $f8, 0x13($s7)
    ctx->f8.u32l = MEM_W(ctx->r23, 0X13);
    // 0x8006A3E4: lwc1        $f0, 0x7($s7)
    ctx->f0.u32l = MEM_W(ctx->r23, 0X7);
    // 0x8006A3E8: sub.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8006A3EC: mul.s       $f8, $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8006A3F0: swc1        $f8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f8.u32l;
    // 0x8006A3F4: lwc1        $f2, 0x8($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006A3F8: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8006A3FC: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8006A400: mul.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8006A404: lwc1        $f0, 0x20($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8006A408: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8006A40C: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x8006A410: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8006A414: sqrt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = sqrtf(ctx->f2.fl);
    // 0x8006A418: mul.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8006A41C: lwc1        $f2, 0x17($s7)
    ctx->f2.u32l = MEM_W(ctx->r23, 0X17);
    // 0x8006A420: lwc1        $f0, 0xB($s7)
    ctx->f0.u32l = MEM_W(ctx->r23, 0XB);
    // 0x8006A424: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8006A428: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8006A42C: nop

    // 0x8006A430: mul.s       $f6, $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8006A434: swc1        $f2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f2.u32l;
    // 0x8006A438: swc1        $f6, 0x20($s4)
    MEM_W(0X20, ctx->r20) = ctx->f6.u32l;
L_8006A43C:
    // 0x8006A43C: sw          $zero, 0x24($s4)
    MEM_W(0X24, ctx->r20) = 0;
    // 0x8006A440: lw          $t3, 0xF0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XF0);
    // 0x8006A444: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8006A448: lw          $v1, 0x28($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X28);
    // 0x8006A44C: beq         $v1, $zero, L_8006A8FC
    if (ctx->r3 == 0) {
        // 0x8006A450: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8006A8FC;
    }
    // 0x8006A450: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006A454: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8006A458: beq         $v0, $zero, L_8006A8FC
    if (ctx->r2 == 0) {
        // 0x8006A45C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8006A8FC;
    }
    // 0x8006A45C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006A460:
    // 0x8006A460: lbu         $v0, 0x9($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X9);
    // 0x8006A464: lw          $t0, 0x90($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X90);
    // 0x8006A468: beql        $v0, $t0, L_8006A8E0
    if (ctx->r2 == ctx->r8) {
        // 0x8006A46C: sw          $v1, 0x24($s4)
        MEM_W(0X24, ctx->r20) = ctx->r3;
            goto L_8006A8E0;
    }
    goto skip_13;
    // 0x8006A46C: sw          $v1, 0x24($s4)
    MEM_W(0X24, ctx->r20) = ctx->r3;
    skip_13:
    // 0x8006A470: addiu       $v1, $v1, 0xA
    ctx->r3 = ADD32(ctx->r3, 0XA);
    // 0x8006A474: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8006A478: bne         $v0, $zero, L_8006A460
    if (ctx->r2 != 0) {
        // 0x8006A47C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8006A460;
    }
    // 0x8006A47C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006A480: j           L_8006A8FC
    // 0x8006A484: nop

        goto L_8006A8FC;
    // 0x8006A484: nop

L_8006A488:
    // 0x8006A488: bne         $v1, $v0, L_8006A8F8
    if (ctx->r3 != ctx->r2) {
        // 0x8006A48C: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_8006A8F8;
    }
    // 0x8006A48C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8006A490: addiu       $a1, $fp, 0x4
    ctx->r5 = ADD32(ctx->r30, 0X4);
    // 0x8006A494: jal         0x800193E8
    // 0x8006A498: addiu       $a2, $sp, 0x80
    ctx->r6 = ADD32(ctx->r29, 0X80);
    transformVec3ByMat34(rdram, ctx);
        goto after_4;
    // 0x8006A498: addiu       $a2, $sp, 0x80
    ctx->r6 = ADD32(ctx->r29, 0X80);
    after_4:
    // 0x8006A49C: lwc1        $f0, 0x80($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8006A4A0: lwc1        $f2, 0x0($s6)
    ctx->f2.u32l = MEM_W(ctx->r22, 0X0);
    // 0x8006A4A4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8006A4A8: lwc1        $f2, 0x84($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8006A4AC: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    // 0x8006A4B0: lwc1        $f0, 0x4($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X4);
    // 0x8006A4B4: sub.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8006A4B8: lwc1        $f0, 0x88($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8006A4BC: swc1        $f8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f8.u32l;
    // 0x8006A4C0: lwc1        $f2, 0x8($s6)
    ctx->f2.u32l = MEM_W(ctx->r22, 0X8);
    // 0x8006A4C4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8006A4C8: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    // 0x8006A4CC: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006A4D0: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8006A4D4: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8006A4D8: mul.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8006A4DC: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8006A4E0: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8006A4E4: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x8006A4E8: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8006A4EC: sqrt.s      $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = sqrtf(ctx->f2.fl);
    // 0x8006A4F0: lwc1        $f6, 0xF($s7)
    ctx->f6.u32l = MEM_W(ctx->r23, 0XF);
    // 0x8006A4F4: mul.s       $f6, $f6, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x8006A4F8: lwc1        $f2, 0x0($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8006A4FC: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8006A500: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8006A504: mul.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8006A508: lwc1        $f0, 0x18($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8006A50C: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8006A510: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x8006A514: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8006A518: lwc1        $f4, 0x4($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X4);
    // 0x8006A51C: lwc1        $f0, 0x13($s7)
    ctx->f0.u32l = MEM_W(ctx->r23, 0X13);
    // 0x8006A520: c.eq.s      $f4, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f4.fl == ctx->f28.fl;
    // 0x8006A524: mul.s       $f24, $f0, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8006A528: bc1t        L_8006A658
    if (c1cs) {
        // 0x8006A52C: add.s       $f22, $f8, $f6
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f8.fl + ctx->f6.fl;
            goto L_8006A658;
    }
    // 0x8006A52C: add.s       $f22, $f8, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8006A530: div.s       $f20, $f8, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = DIV_S(ctx->f8.fl, ctx->f4.fl);
    // 0x8006A534: div.s       $f12, $f22, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = DIV_S(ctx->f22.fl, ctx->f4.fl);
    // 0x8006A538: c.lt.s      $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f20.fl < ctx->f12.fl;
    // 0x8006A53C: nop

    // 0x8006A540: bc1f        L_8006A550
    if (!c1cs) {
        // 0x8006A544: mov.s       $f26, $f20
        CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    ctx->f26.fl = ctx->f20.fl;
            goto L_8006A550;
    }
    // 0x8006A544: mov.s       $f26, $f20
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    ctx->f26.fl = ctx->f20.fl;
    // 0x8006A548: j           L_8006A558
    // 0x8006A54C: mov.s       $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.fl = ctx->f12.fl;
        goto L_8006A558;
    // 0x8006A54C: mov.s       $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    ctx->f16.fl = ctx->f12.fl;
L_8006A550:
    // 0x8006A550: mov.s       $f26, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    ctx->f26.fl = ctx->f12.fl;
    // 0x8006A554: mov.s       $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    ctx->f16.fl = ctx->f20.fl;
L_8006A558:
    // 0x8006A558: c.lt.s      $f28, $f26
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f28.fl < ctx->f26.fl;
    // 0x8006A55C: nop

    // 0x8006A560: bc1f        L_8006A688
    if (!c1cs) {
        // 0x8006A564: nop
    
            goto L_8006A688;
    }
    // 0x8006A564: nop

    // 0x8006A568: c.lt.s      $f26, $f30
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f26.fl < ctx->f30.fl;
    // 0x8006A56C: nop

    // 0x8006A570: bc1f        L_8006A688
    if (!c1cs) {
        // 0x8006A574: nop
    
            goto L_8006A688;
    }
    // 0x8006A574: nop

    // 0x8006A578: lwc1        $f0, 0x0($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X0);
    // 0x8006A57C: mul.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x8006A580: lwc1        $f2, 0x70($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8006A584: sub.s       $f14, $f2, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8006A588: lwc1        $f0, 0x8($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X8);
    // 0x8006A58C: mul.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x8006A590: nop

    // 0x8006A594: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8006A598: lwc1        $f2, 0x78($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8006A59C: sub.s       $f22, $f2, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8006A5A0: mul.s       $f0, $f22, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x8006A5A4: add.s       $f14, $f4, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x8006A5A8: c.lt.s      $f14, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f14.fl < ctx->f24.fl;
    // 0x8006A5AC: nop

    // 0x8006A5B0: bc1f        L_8006A688
    if (!c1cs) {
        // 0x8006A5B4: nop
    
            goto L_8006A688;
    }
    // 0x8006A5B4: nop

    // 0x8006A5B8: beq         $s4, $zero, L_8006A8FC
    if (ctx->r20 == 0) {
        // 0x8006A5BC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8006A8FC;
    }
    // 0x8006A5BC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006A5C0: swc1        $f26, 0x18($s4)
    MEM_W(0X18, ctx->r20) = ctx->f26.u32l;
    // 0x8006A5C4: lwc1        $f2, 0x0($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X0);
    // 0x8006A5C8: mul.s       $f2, $f2, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f26.fl);
    // 0x8006A5CC: lwc1        $f0, 0x0($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X0);
    // 0x8006A5D0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8006A5D4: swc1        $f0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f0.u32l;
    // 0x8006A5D8: lwc1        $f2, 0x4($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X4);
    // 0x8006A5DC: mul.s       $f2, $f2, $f26
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f26.fl);
    // 0x8006A5E0: lwc1        $f0, 0x4($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X4);
    // 0x8006A5E4: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8006A5E8: swc1        $f0, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->f0.u32l;
    // 0x8006A5EC: lwc1        $f0, 0x8($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X8);
    // 0x8006A5F0: mul.s       $f0, $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f26.fl);
    // 0x8006A5F4: lwc1        $f2, 0x8($s6)
    ctx->f2.u32l = MEM_W(ctx->r22, 0X8);
    // 0x8006A5F8: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8006A5FC: swc1        $f28, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->f28.u32l;
    // 0x8006A600: swc1        $f28, 0x14($s4)
    MEM_W(0X14, ctx->r20) = ctx->f28.u32l;
    // 0x8006A604: swc1        $f2, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->f2.u32l;
    // 0x8006A608: lwc1        $f0, 0x4($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X4);
    // 0x8006A60C: c.lt.s      $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f0.fl < ctx->f28.fl;
    // 0x8006A610: nop

    // 0x8006A614: bc1f        L_8006A624
    if (!c1cs) {
        // 0x8006A618: mov.s       $f2, $f30
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    ctx->f2.fl = ctx->f30.fl;
            goto L_8006A624;
    }
    // 0x8006A618: mov.s       $f2, $f30
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    ctx->f2.fl = ctx->f30.fl;
    // 0x8006A61C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006A620: lwc1        $f2, -0x3720($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3720);
L_8006A624:
    // 0x8006A624: swc1        $f2, 0x10($s4)
    MEM_W(0X10, ctx->r20) = ctx->f2.u32l;
    // 0x8006A628: lwc1        $f2, 0x0($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X0);
    // 0x8006A62C: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8006A630: lwc1        $f4, 0x4($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X4);
    // 0x8006A634: mul.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8006A638: lwc1        $f0, 0x8($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X8);
    // 0x8006A63C: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8006A640: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x8006A644: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8006A648: sqrt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = sqrtf(ctx->f2.fl);
    // 0x8006A64C: mul.s       $f0, $f26, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f26.fl, ctx->f0.fl);
    // 0x8006A650: j           L_8006A898
    // 0x8006A654: swc1        $f0, 0x1C($s4)
    MEM_W(0X1C, ctx->r20) = ctx->f0.u32l;
        goto L_8006A898;
    // 0x8006A654: swc1        $f0, 0x1C($s4)
    MEM_W(0X1C, ctx->r20) = ctx->f0.u32l;
L_8006A658:
    // 0x8006A658: c.lt.s      $f28, $f8
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f28.fl < ctx->f8.fl;
    // 0x8006A65C: nop

    // 0x8006A660: bc1tl       L_8006A8E8
    if (c1cs) {
        // 0x8006A664: addiu       $s7, $s7, 0x1C
        ctx->r23 = ADD32(ctx->r23, 0X1C);
            goto L_8006A8E8;
    }
    goto skip_14;
    // 0x8006A664: addiu       $s7, $s7, 0x1C
    ctx->r23 = ADD32(ctx->r23, 0X1C);
    skip_14:
    // 0x8006A668: c.lt.s      $f22, $f28
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f22.fl < ctx->f28.fl;
    // 0x8006A66C: nop

    // 0x8006A670: bc1tl       L_8006A8E8
    if (c1cs) {
        // 0x8006A674: addiu       $s7, $s7, 0x1C
        ctx->r23 = ADD32(ctx->r23, 0X1C);
            goto L_8006A8E8;
    }
    goto skip_15;
    // 0x8006A674: addiu       $s7, $s7, 0x1C
    ctx->r23 = ADD32(ctx->r23, 0X1C);
    skip_15:
    // 0x8006A678: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006A67C: lwc1        $f26, -0x371C($at)
    ctx->f26.u32l = MEM_W(ctx->r1, -0X371C);
    // 0x8006A680: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006A684: lwc1        $f16, -0x3718($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3718);
L_8006A688:
    // 0x8006A688: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8006A68C: lwc1        $f6, 0x0($s5)
    ctx->f6.u32l = MEM_W(ctx->r21, 0X0);
    // 0x8006A690: mul.s       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8006A694: nop

    // 0x8006A698: mul.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8006A69C: lwc1        $f2, 0x78($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8006A6A0: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8006A6A4: lwc1        $f0, 0x8($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X8);
    // 0x8006A6A8: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8006A6AC: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8006A6B0: c.lt.s      $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f12.fl < ctx->f24.fl;
    // 0x8006A6B4: nop

    // 0x8006A6B8: bc1f        L_8006A744
    if (!c1cs) {
        // 0x8006A6BC: add.s       $f20, $f6, $f2
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f2.fl;
            goto L_8006A744;
    }
    // 0x8006A6BC: add.s       $f20, $f6, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x8006A6C0: lwc1        $f0, 0x74($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8006A6C4: c.lt.s      $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f0.fl < ctx->f28.fl;
    // 0x8006A6C8: nop

    // 0x8006A6CC: bc1f        L_8006A744
    if (!c1cs) {
        // 0x8006A6D0: nop
    
            goto L_8006A744;
    }
    // 0x8006A6D0: nop

    // 0x8006A6D4: c.le.s      $f28, $f22
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f28.fl <= ctx->f22.fl;
    // 0x8006A6D8: nop

    // 0x8006A6DC: bc1f        L_8006A744
    if (!c1cs) {
        // 0x8006A6E0: nop
    
            goto L_8006A744;
    }
    // 0x8006A6E0: nop

    // 0x8006A6E4: beq         $s4, $zero, L_8006A8E0
    if (ctx->r20 == 0) {
        // 0x8006A6E8: addiu       $a0, $s4, 0xC
        ctx->r4 = ADD32(ctx->r20, 0XC);
            goto L_8006A8E0;
    }
    // 0x8006A6E8: addiu       $a0, $s4, 0xC
    ctx->r4 = ADD32(ctx->r20, 0XC);
    // 0x8006A6EC: swc1        $f28, 0x1C($s4)
    MEM_W(0X1C, ctx->r20) = ctx->f28.u32l;
    // 0x8006A6F0: swc1        $f28, 0x18($s4)
    MEM_W(0X18, ctx->r20) = ctx->f28.u32l;
    // 0x8006A6F4: lw          $t1, 0x0($s6)
    ctx->r9 = MEM_W(ctx->r22, 0X0);
    // 0x8006A6F8: lw          $t2, 0x4($s6)
    ctx->r10 = MEM_W(ctx->r22, 0X4);
    // 0x8006A6FC: lw          $t3, 0x8($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X8);
    // 0x8006A700: sw          $t1, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r9;
    // 0x8006A704: sw          $t2, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r10;
    // 0x8006A708: sw          $t3, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r11;
    // 0x8006A70C: lwc1        $f0, 0x70($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8006A710: swc1        $f0, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->f0.u32l;
    // 0x8006A714: lwc1        $f0, 0x78($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8006A718: swc1        $f28, 0x10($s4)
    MEM_W(0X10, ctx->r20) = ctx->f28.u32l;
    // 0x8006A71C: jal         0x8001CF58
    // 0x8006A720: swc1        $f0, 0x14($s4)
    MEM_W(0X14, ctx->r20) = ctx->f0.u32l;
    normalize_vector(rdram, ctx);
        goto after_5;
    // 0x8006A720: swc1        $f0, 0x14($s4)
    MEM_W(0X14, ctx->r20) = ctx->f0.u32l;
    after_5:
    // 0x8006A724: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006A728: lwc1        $f2, -0x3714($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3714);
    // 0x8006A72C: mul.s       $f2, $f24, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f24.fl, ctx->f2.fl);
    // 0x8006A730: lwc1        $f0, 0x74($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8006A734: sub.s       $f0, $f22, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = ctx->f22.fl - ctx->f0.fl;
    // 0x8006A738: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8006A73C: j           L_8006A43C
    // 0x8006A740: swc1        $f2, 0x20($s4)
    MEM_W(0X20, ctx->r20) = ctx->f2.u32l;
        goto L_8006A43C;
    // 0x8006A740: swc1        $f2, 0x20($s4)
    MEM_W(0X20, ctx->r20) = ctx->f2.u32l;
L_8006A744:
    // 0x8006A744: c.lt.s      $f24, $f12
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f24.fl < ctx->f12.fl;
    // 0x8006A748: nop

    // 0x8006A74C: bc1f        L_8006A764
    if (!c1cs) {
        // 0x8006A750: nop
    
            goto L_8006A764;
    }
    // 0x8006A750: nop

    // 0x8006A754: c.lt.s      $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f20.fl < ctx->f28.fl;
    // 0x8006A758: nop

    // 0x8006A75C: bc1tl       L_8006A8E8
    if (c1cs) {
        // 0x8006A760: addiu       $s7, $s7, 0x1C
        ctx->r23 = ADD32(ctx->r23, 0X1C);
            goto L_8006A8E8;
    }
    goto skip_16;
    // 0x8006A760: addiu       $s7, $s7, 0x1C
    ctx->r23 = ADD32(ctx->r23, 0X1C);
    skip_16:
L_8006A764:
    // 0x8006A764: lwc1        $f2, 0x0($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X0);
    // 0x8006A768: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8006A76C: lwc1        $f0, 0x8($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X8);
    // 0x8006A770: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8006A774: add.s       $f14, $f2, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8006A778: c.eq.s      $f14, $f28
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f14.fl == ctx->f28.fl;
    // 0x8006A77C: nop

    // 0x8006A780: bc1tl       L_8006A8E8
    if (c1cs) {
        // 0x8006A784: addiu       $s7, $s7, 0x1C
        ctx->r23 = ADD32(ctx->r23, 0X1C);
            goto L_8006A8E8;
    }
    goto skip_17;
    // 0x8006A784: addiu       $s7, $s7, 0x1C
    ctx->r23 = ADD32(ctx->r23, 0X1C);
    skip_17:
    // 0x8006A788: mul.s       $f0, $f20, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8006A78C: sub.s       $f2, $f24, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = ctx->f24.fl - ctx->f12.fl;
    // 0x8006A790: div.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f14.fl);
    // 0x8006A794: add.s       $f12, $f2, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8006A798: c.lt.s      $f28, $f12
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f28.fl < ctx->f12.fl;
    // 0x8006A79C: nop

    // 0x8006A7A0: bc1fl       L_8006A8E8
    if (!c1cs) {
        // 0x8006A7A4: addiu       $s7, $s7, 0x1C
        ctx->r23 = ADD32(ctx->r23, 0X1C);
            goto L_8006A8E8;
    }
    goto skip_18;
    // 0x8006A7A4: addiu       $s7, $s7, 0x1C
    ctx->r23 = ADD32(ctx->r23, 0X1C);
    skip_18:
    // 0x8006A7A8: sqrt.s      $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = sqrtf(ctx->f14.fl);
    // 0x8006A7AC: sqrt.s      $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f22.fl = sqrtf(ctx->f12.fl);
    // 0x8006A7B0: div.s       $f0, $f20, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = DIV_S(ctx->f20.fl, ctx->f14.fl);
    // 0x8006A7B4: sub.s       $f0, $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f22.fl;
    // 0x8006A7B8: div.s       $f20, $f0, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f20.fl = DIV_S(ctx->f0.fl, ctx->f14.fl);
    // 0x8006A7BC: c.le.s      $f28, $f20
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f28.fl <= ctx->f20.fl;
    // 0x8006A7C0: nop

    // 0x8006A7C4: bc1fl       L_8006A8E8
    if (!c1cs) {
        // 0x8006A7C8: addiu       $s7, $s7, 0x1C
        ctx->r23 = ADD32(ctx->r23, 0X1C);
            goto L_8006A8E8;
    }
    goto skip_19;
    // 0x8006A7C8: addiu       $s7, $s7, 0x1C
    ctx->r23 = ADD32(ctx->r23, 0X1C);
    skip_19:
    // 0x8006A7CC: c.lt.s      $f20, $f30
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f20.fl < ctx->f30.fl;
    // 0x8006A7D0: nop

    // 0x8006A7D4: bc1fl       L_8006A8E8
    if (!c1cs) {
        // 0x8006A7D8: addiu       $s7, $s7, 0x1C
        ctx->r23 = ADD32(ctx->r23, 0X1C);
            goto L_8006A8E8;
    }
    goto skip_20;
    // 0x8006A7D8: addiu       $s7, $s7, 0x1C
    ctx->r23 = ADD32(ctx->r23, 0X1C);
    skip_20:
    // 0x8006A7DC: c.lt.s      $f26, $f20
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f26.fl < ctx->f20.fl;
    // 0x8006A7E0: nop

    // 0x8006A7E4: bc1fl       L_8006A8E8
    if (!c1cs) {
        // 0x8006A7E8: addiu       $s7, $s7, 0x1C
        ctx->r23 = ADD32(ctx->r23, 0X1C);
            goto L_8006A8E8;
    }
    goto skip_21;
    // 0x8006A7E8: addiu       $s7, $s7, 0x1C
    ctx->r23 = ADD32(ctx->r23, 0X1C);
    skip_21:
    // 0x8006A7EC: c.lt.s      $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f20.fl < ctx->f16.fl;
    // 0x8006A7F0: nop

    // 0x8006A7F4: bc1fl       L_8006A8E8
    if (!c1cs) {
        // 0x8006A7F8: addiu       $s7, $s7, 0x1C
        ctx->r23 = ADD32(ctx->r23, 0X1C);
            goto L_8006A8E8;
    }
    goto skip_22;
    // 0x8006A7F8: addiu       $s7, $s7, 0x1C
    ctx->r23 = ADD32(ctx->r23, 0X1C);
    skip_22:
    // 0x8006A7FC: beq         $s4, $zero, L_8006A8E0
    if (ctx->r20 == 0) {
        // 0x8006A800: addiu       $a0, $s4, 0xC
        ctx->r4 = ADD32(ctx->r20, 0XC);
            goto L_8006A8E0;
    }
    // 0x8006A800: addiu       $a0, $s4, 0xC
    ctx->r4 = ADD32(ctx->r20, 0XC);
    // 0x8006A804: swc1        $f20, 0x18($s4)
    MEM_W(0X18, ctx->r20) = ctx->f20.u32l;
    // 0x8006A808: lwc1        $f2, 0x0($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X0);
    // 0x8006A80C: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x8006A810: lwc1        $f0, 0x0($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X0);
    // 0x8006A814: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8006A818: swc1        $f0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f0.u32l;
    // 0x8006A81C: lwc1        $f2, 0x4($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X4);
    // 0x8006A820: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x8006A824: lwc1        $f0, 0x4($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X4);
    // 0x8006A828: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8006A82C: swc1        $f0, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->f0.u32l;
    // 0x8006A830: lwc1        $f2, 0x8($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X8);
    // 0x8006A834: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x8006A838: lwc1        $f0, 0x8($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0X8);
    // 0x8006A83C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8006A840: swc1        $f0, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->f0.u32l;
    // 0x8006A844: lwc1        $f2, 0x80($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8006A848: lwc1        $f0, 0x0($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8006A84C: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8006A850: lwc1        $f0, 0x8($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X8);
    // 0x8006A854: swc1        $f28, 0x10($s4)
    MEM_W(0X10, ctx->r20) = ctx->f28.u32l;
    // 0x8006A858: swc1        $f2, 0xC($s4)
    MEM_W(0XC, ctx->r20) = ctx->f2.u32l;
    // 0x8006A85C: lwc1        $f2, 0x88($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8006A860: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8006A864: jal         0x8001CF58
    // 0x8006A868: swc1        $f2, 0x14($s4)
    MEM_W(0X14, ctx->r20) = ctx->f2.u32l;
    normalize_vector(rdram, ctx);
        goto after_6;
    // 0x8006A868: swc1        $f2, 0x14($s4)
    MEM_W(0X14, ctx->r20) = ctx->f2.u32l;
    after_6:
    // 0x8006A86C: lwc1        $f2, 0x0($s5)
    ctx->f2.u32l = MEM_W(ctx->r21, 0X0);
    // 0x8006A870: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8006A874: lwc1        $f4, 0x4($s5)
    ctx->f4.u32l = MEM_W(ctx->r21, 0X4);
    // 0x8006A878: mul.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8006A87C: lwc1        $f0, 0x8($s5)
    ctx->f0.u32l = MEM_W(ctx->r21, 0X8);
    // 0x8006A880: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8006A884: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x8006A888: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8006A88C: sqrt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = sqrtf(ctx->f2.fl);
    // 0x8006A890: mul.s       $f0, $f20, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x8006A894: swc1        $f0, 0x1C($s4)
    MEM_W(0X1C, ctx->r20) = ctx->f0.u32l;
L_8006A898:
    // 0x8006A898: lwc1        $f2, 0x4($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006A89C: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8006A8A0: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8006A8A4: mul.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8006A8A8: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8006A8AC: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8006A8B0: add.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x8006A8B4: add.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x8006A8B8: sqrt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = sqrtf(ctx->f2.fl);
    // 0x8006A8BC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006A8C0: lwc1        $f0, -0x3710($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3710);
    // 0x8006A8C4: mul.s       $f0, $f24, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f24.fl, ctx->f0.fl);
    // 0x8006A8C8: lwc1        $f2, 0xF($s7)
    ctx->f2.u32l = MEM_W(ctx->r23, 0XF);
    // 0x8006A8CC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8006A8D0: nop

    // 0x8006A8D4: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8006A8D8: j           L_8006A43C
    // 0x8006A8DC: swc1        $f0, 0x20($s4)
    MEM_W(0X20, ctx->r20) = ctx->f0.u32l;
        goto L_8006A43C;
    // 0x8006A8DC: swc1        $f0, 0x20($s4)
    MEM_W(0X20, ctx->r20) = ctx->f0.u32l;
L_8006A8E0:
    // 0x8006A8E0: j           L_8006A8FC
    // 0x8006A8E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006A8FC;
    // 0x8006A8E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006A8E8:
    // 0x8006A8E8: lbu         $v1, 0x0($s7)
    ctx->r3 = MEM_BU(ctx->r23, 0X0);
    // 0x8006A8EC: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8006A8F0: bne         $v1, $v0, L_80069B70
    if (ctx->r3 != ctx->r2) {
        // 0x8006A8F4: addiu       $fp, $fp, 0x1C
        ctx->r30 = ADD32(ctx->r30, 0X1C);
            goto L_80069B70;
    }
    // 0x8006A8F4: addiu       $fp, $fp, 0x1C
    ctx->r30 = ADD32(ctx->r30, 0X1C);
L_8006A8F8:
    // 0x8006A8F8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8006A8FC:
    // 0x8006A8FC: lw          $ra, 0xBC($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XBC);
    // 0x8006A900: lw          $fp, 0xB8($sp)
    ctx->r30 = MEM_W(ctx->r29, 0XB8);
    // 0x8006A904: lw          $s7, 0xB4($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XB4);
    // 0x8006A908: lw          $s6, 0xB0($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XB0);
    // 0x8006A90C: lw          $s5, 0xAC($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XAC);
    // 0x8006A910: lw          $s4, 0xA8($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XA8);
    // 0x8006A914: lw          $s3, 0xA4($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XA4);
    // 0x8006A918: lw          $s2, 0xA0($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XA0);
    // 0x8006A91C: lw          $s1, 0x9C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X9C);
    // 0x8006A920: lw          $s0, 0x98($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X98);
    // 0x8006A924: ldc1        $f30, 0xE8($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0XE8);
    // 0x8006A928: ldc1        $f28, 0xE0($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0XE0);
    // 0x8006A92C: ldc1        $f26, 0xD8($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0XD8);
    // 0x8006A930: ldc1        $f24, 0xD0($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0XD0);
    // 0x8006A934: ldc1        $f22, 0xC8($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0XC8);
    // 0x8006A938: ldc1        $f20, 0xC0($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0XC0);
    // 0x8006A93C: jr          $ra
    // 0x8006A940: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    return;
    // 0x8006A940: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
;}
RECOMP_FUNC void func_8006A944(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A944: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006A948: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8006A94C: addu        $s0, $a0, $zero
    ctx->r16 = ADD32(ctx->r4, 0);
    // 0x8006A950: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x8006A954: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x8006A958: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8006A95C: addu        $s3, $a2, $zero
    ctx->r19 = ADD32(ctx->r6, 0);
    // 0x8006A960: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8006A964: addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    // 0x8006A968: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    // 0x8006A96C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8006A970: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8006A974: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8006A978: addu        $a3, $s3, $zero
    ctx->r7 = ADD32(ctx->r19, 0);
    // 0x8006A97C: jal         0x8006AE58
    // 0x8006A980: addiu       $a1, $a1, 0x48
    ctx->r5 = ADD32(ctx->r5, 0X48);
    func_8006AE58(rdram, ctx);
        goto after_0;
    // 0x8006A980: addiu       $a1, $a1, 0x48
    ctx->r5 = ADD32(ctx->r5, 0X48);
    after_0:
    // 0x8006A984: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x8006A988: beq         $s2, $zero, L_8006AB58
    if (ctx->r18 == 0) {
        // 0x8006A98C: addu        $v0, $zero, $zero
        ctx->r2 = ADD32(0, 0);
            goto L_8006AB58;
    }
    // 0x8006A98C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8006A990: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8006A994: lw          $v0, 0x58($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X58);
    // 0x8006A998: bne         $v0, $zero, L_8006AB38
    if (ctx->r2 != 0) {
        // 0x8006A99C: addu        $a0, $s0, $zero
        ctx->r4 = ADD32(ctx->r16, 0);
            goto L_8006AB38;
    }
    // 0x8006A99C: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8006A9A0: beq         $s1, $zero, L_8006AB58
    if (ctx->r17 == 0) {
        // 0x8006A9A4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8006AB58;
    }
    // 0x8006A9A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006A9A8: lwc1        $f6, 0x0($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8006A9AC: lwc1        $f0, 0x0($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8006A9B0: sub.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8006A9B4: lwc1        $f8, 0x0($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X0);
    // 0x8006A9B8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8006A9BC: nop

    // 0x8006A9C0: mul.s       $f6, $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8006A9C4: nop

    // 0x8006A9C8: mul.s       $f8, $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8006A9CC: lwc1        $f4, 0x4($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8006A9D0: lwc1        $f0, 0x4($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X4);
    // 0x8006A9D4: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8006A9D8: lwc1        $f12, 0x4($s3)
    ctx->f12.u32l = MEM_W(ctx->r19, 0X4);
    // 0x8006A9DC: mul.s       $f16, $f4, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8006A9E0: nop

    // 0x8006A9E4: mul.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8006A9E8: nop

    // 0x8006A9EC: mul.s       $f12, $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8006A9F0: lwc1        $f2, 0x8($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8006A9F4: lwc1        $f0, 0x8($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X8);
    // 0x8006A9F8: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8006A9FC: lwc1        $f0, 0x8($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X8);
    // 0x8006AA00: mul.s       $f14, $f2, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8006AA04: nop

    // 0x8006AA08: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8006AA0C: nop

    // 0x8006AA10: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8006AA14: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8006AA18: add.s       $f14, $f10, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x8006AA1C: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8006AA20: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8006AA24: add.s       $f8, $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x8006AA28: add.s       $f6, $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x8006AA2C: add.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8006AA30: lwc1        $f0, 0xC($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8006AA34: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8006AA38: div.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8006AA3C: add.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x8006AA40: sqrt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = sqrtf(ctx->f8.fl);
    // 0x8006AA44: sqrt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = sqrtf(ctx->f6.fl);
    // 0x8006AA48: div.s       $f0, $f14, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f14.fl, ctx->f4.fl);
    // 0x8006AA4C: sub.s       $f14, $f0, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8006AA50: div.s       $f4, $f14, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = DIV_S(ctx->f14.fl, ctx->f4.fl);
    // 0x8006AA54: swc1        $f4, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f4.u32l;
    // 0x8006AA58: lwc1        $f2, 0x0($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X0);
    // 0x8006AA5C: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8006AA60: lwc1        $f0, 0x0($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8006AA64: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8006AA68: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
    // 0x8006AA6C: lwc1        $f2, 0x4($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X4);
    // 0x8006AA70: mov.s       $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = ctx->f4.fl;
    // 0x8006AA74: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8006AA78: lwc1        $f0, 0x4($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X4);
    // 0x8006AA7C: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8006AA80: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
    // 0x8006AA84: lwc1        $f2, 0x8($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X8);
    // 0x8006AA88: mov.s       $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = ctx->f4.fl;
    // 0x8006AA8C: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8006AA90: lwc1        $f0, 0x8($s4)
    ctx->f0.u32l = MEM_W(ctx->r20, 0X8);
    // 0x8006AA94: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8006AA98: lwc1        $f2, 0x0($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8006AA9C: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
    // 0x8006AAA0: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8006AAA4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8006AAA8: lwc1        $f2, 0x4($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8006AAAC: swc1        $f0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f0.u32l;
    // 0x8006AAB0: lwc1        $f0, 0x4($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8006AAB4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8006AAB8: lwc1        $f2, 0x8($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8006AABC: swc1        $f0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f0.u32l;
    // 0x8006AAC0: lwc1        $f0, 0x8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8006AAC4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8006AAC8: addiu       $a0, $s1, 0xC
    ctx->r4 = ADD32(ctx->r17, 0XC);
    // 0x8006AACC: jal         0x8001CF58
    // 0x8006AAD0: swc1        $f0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f0.u32l;
    normalize_vector(rdram, ctx);
        goto after_1;
    // 0x8006AAD0: swc1        $f0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f0.u32l;
    after_1:
    // 0x8006AAD4: lwc1        $f0, 0x0($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X0);
    // 0x8006AAD8: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8006AADC: lwc1        $f4, 0x4($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X4);
    // 0x8006AAE0: mul.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8006AAE4: lwc1        $f2, 0x8($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X8);
    // 0x8006AAE8: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8006AAEC: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8006AAF0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8006AAF4: lwc1        $f2, 0x18($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X18);
    // 0x8006AAF8: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8006AAFC: nop

    // 0x8006AB00: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8006AB04: sqrt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = sqrtf(ctx->f0.fl);
    // 0x8006AB08: swc1        $f18, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f18.u32l;
    // 0x8006AB0C: lwc1        $f0, 0xC($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8006AB10: sqrt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = sqrtf(ctx->f0.fl);
    // 0x8006AB14: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006AB18: lwc1        $f2, -0x370C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X370C);
    // 0x8006AB1C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8006AB20: nop

    // 0x8006AB24: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8006AB28: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    // 0x8006AB2C: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
    // 0x8006AB30: j           L_8006AB58
    // 0x8006AB34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006AB58;
    // 0x8006AB34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006AB38:
    // 0x8006AB38: addu        $a1, $s4, $zero
    ctx->r5 = ADD32(ctx->r20, 0);
    // 0x8006AB3C: addu        $a2, $s3, $zero
    ctx->r6 = ADD32(ctx->r19, 0);
    // 0x8006AB40: jal         0x80069AF0
    // 0x8006AB44: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    func_80069AF0(rdram, ctx);
        goto after_2;
    // 0x8006AB44: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    after_2:
    // 0x8006AB48: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8006AB4C: bne         $v1, $zero, L_8006AB58
    if (ctx->r3 != 0) {
        // 0x8006AB50: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8006AB58;
    }
    // 0x8006AB50: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006AB54: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8006AB58:
    // 0x8006AB58: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8006AB5C: lw          $s4, 0x20($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X20);
    // 0x8006AB60: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8006AB64: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8006AB68: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8006AB6C: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8006AB70: jr          $ra
    // 0x8006AB74: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006AB74: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_8006AB78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006AB78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006AB7C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8006AB80: addu        $s0, $a1, $zero
    ctx->r16 = ADD32(ctx->r5, 0);
    // 0x8006AB84: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8006AB88: addu        $s1, $a2, $zero
    ctx->r17 = ADD32(ctx->r6, 0);
    // 0x8006AB8C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8006AB90: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x8006AB94: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x8006AB98: addu        $a3, $s1, $zero
    ctx->r7 = ADD32(ctx->r17, 0);
    // 0x8006AB9C: jal         0x8006AE58
    // 0x8006ABA0: addiu       $a1, $a1, 0x48
    ctx->r5 = ADD32(ctx->r5, 0X48);
    func_8006AE58(rdram, ctx);
        goto after_0;
    // 0x8006ABA0: addiu       $a1, $a1, 0x48
    ctx->r5 = ADD32(ctx->r5, 0X48);
    after_0:
    // 0x8006ABA4: bne         $v0, $zero, L_8006ABBC
    if (ctx->r2 != 0) {
        // 0x8006ABA8: nop
    
            goto L_8006ABBC;
    }
    // 0x8006ABA8: nop

    // 0x8006ABAC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006ABB0: lwc1        $f0, -0x3708($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3708);
    // 0x8006ABB4: j           L_8006AC68
    // 0x8006ABB8: nop

        goto L_8006AC68;
    // 0x8006ABB8: nop

L_8006ABBC:
    // 0x8006ABBC: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8006ABC0: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8006ABC4: sub.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x8006ABC8: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8006ABCC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8006ABD0: nop

    // 0x8006ABD4: mul.s       $f6, $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8006ABD8: nop

    // 0x8006ABDC: mul.s       $f8, $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8006ABE0: lwc1        $f4, 0x4($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8006ABE4: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8006ABE8: sub.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8006ABEC: lwc1        $f12, 0x4($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8006ABF0: mul.s       $f16, $f4, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8006ABF4: nop

    // 0x8006ABF8: mul.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8006ABFC: nop

    // 0x8006AC00: mul.s       $f12, $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8006AC04: lwc1        $f2, 0x8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8006AC08: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8006AC0C: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8006AC10: lwc1        $f0, 0x8($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8006AC14: mul.s       $f14, $f2, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8006AC18: nop

    // 0x8006AC1C: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8006AC20: nop

    // 0x8006AC24: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8006AC28: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8006AC2C: add.s       $f14, $f10, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x8006AC30: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8006AC34: add.s       $f6, $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8006AC38: add.s       $f8, $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x8006AC3C: add.s       $f6, $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x8006AC40: add.s       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8006AC44: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8006AC48: sub.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8006AC4C: div.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x8006AC50: add.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x8006AC54: sqrt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = sqrtf(ctx->f8.fl);
    // 0x8006AC58: sqrt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = sqrtf(ctx->f6.fl);
    // 0x8006AC5C: div.s       $f2, $f14, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8006AC60: sub.s       $f14, $f2, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x8006AC64: div.s       $f0, $f14, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
L_8006AC68:
    // 0x8006AC68: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x8006AC6C: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8006AC70: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8006AC74: jr          $ra
    // 0x8006AC78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8006AC78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void transformMeshPartIntoWorld(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006AC7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006AC80: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x8006AC84: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8006AC88: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x8006AC8C: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // 0x8006AC90: jal         0x800193E8
    // 0x8006AC94: addiu       $a1, $a1, 0x4C
    ctx->r5 = ADD32(ctx->r5, 0X4C);
    transformVec3ByMat34(rdram, ctx);
        goto after_0;
    // 0x8006AC94: addiu       $a1, $a1, 0x4C
    ctx->r5 = ADD32(ctx->r5, 0X4C);
    after_0:
    // 0x8006AC98: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8006AC9C: jr          $ra
    // 0x8006ACA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8006ACA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void fake_func_8006ACA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void func_8006ACB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006ACB0: lbu         $t0, 0xB($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0XB);
    // 0x8006ACB4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006ACB8: ori         $v0, $v0, 0x9C80
    ctx->r2 = ctx->r2 | 0X9C80;
    // 0x8006ACBC: beq         $t0, $zero, L_8006ACCC
    if (ctx->r8 == 0) {
        // 0x8006ACC0: sll         $t0, $t0, 4
        ctx->r8 = S32(ctx->r8 << 4);
            goto L_8006ACCC;
    }
    // 0x8006ACC0: sll         $t0, $t0, 4
    ctx->r8 = S32(ctx->r8 << 4);
    // 0x8006ACC4: jr          $ra
    // 0x8006ACC8: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
    return;
    // 0x8006ACC8: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
L_8006ACCC:
    // 0x8006ACCC: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8006ACD0: ori         $t1, $t1, 0xA490
    ctx->r9 = ctx->r9 | 0XA490;
    // 0x8006ACD4: lh          $t0, 0x0($t1)
    ctx->r8 = MEM_H(ctx->r9, 0X0);
    // 0x8006ACD8: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x8006ACDC: ori         $t2, $t2, 0xA498
    ctx->r10 = ctx->r10 | 0XA498;
    // 0x8006ACE0: bltz        $t0, L_8006AE3C
    if (SIGNED(ctx->r8) < 0) {
        // 0x8006ACE4: addu        $t2, $t2, $t0
        ctx->r10 = ADD32(ctx->r10, ctx->r8);
            goto L_8006AE3C;
    }
    // 0x8006ACE4: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x8006ACE8: lbu         $at, 0x0($t2)
    ctx->r1 = MEM_BU(ctx->r10, 0X0);
    // 0x8006ACEC: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8006ACF0: sh          $t0, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r8;
    // 0x8006ACF4: sb          $at, 0xB($a0)
    MEM_B(0XB, ctx->r4) = ctx->r1;
    // 0x8006ACF8: sll         $t0, $at, 4
    ctx->r8 = S32(ctx->r1 << 4);
    // 0x8006ACFC: addu        $v0, $v0, $t0
    ctx->r2 = ADD32(ctx->r2, ctx->r8);
L_8006AD00:
    // 0x8006AD00: mfc1        $t4, $f20
    ctx->r12 = (int32_t)ctx->f20.u32l;
    // 0x8006AD04: mfc1        $t5, $f22
    ctx->r13 = (int32_t)ctx->f22.u32l;
    // 0x8006AD08: mfc1        $t6, $f24
    ctx->r14 = (int32_t)ctx->f24.u32l;
    // 0x8006AD0C: mfc1        $t7, $f26
    ctx->r15 = (int32_t)ctx->f26.u32l;
    // 0x8006AD10: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8006AD14: lwc1        $f10, 0x28($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X28);
    // 0x8006AD18: lwc1        $f16, 0x34($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X34);
    // 0x8006AD1C: lwc1        $f18, 0x40($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X40);
    // 0x8006AD20: mul.s       $f20, $f10, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8006AD24: lwc1        $f10, 0x2C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X2C);
    // 0x8006AD28: mul.s       $f22, $f16, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8006AD2C: lwc1        $f16, 0x38($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8006AD30: mul.s       $f24, $f18, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f24.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8006AD34: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8006AD38: lwc1        $f18, 0x44($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X44);
    // 0x8006AD3C: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8006AD40: nop

    // 0x8006AD44: mul.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8006AD48: add.s       $f20, $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f6.fl;
    // 0x8006AD4C: add.s       $f22, $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f8.fl;
    // 0x8006AD50: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8006AD54: nop

    // 0x8006AD58: add.s       $f24, $f24, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f6.fl;
    // 0x8006AD5C: lwc1        $f10, 0x30($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X30);
    // 0x8006AD60: lwc1        $f16, 0x3C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X3C);
    // 0x8006AD64: lwc1        $f4, 0xC($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8006AD68: lwc1        $f18, 0x48($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X48);
    // 0x8006AD6C: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8006AD70: lwc1        $f10, 0x4C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x8006AD74: mul.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8006AD78: add.s       $f20, $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f6.fl;
    // 0x8006AD7C: add.s       $f22, $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f8.fl;
    // 0x8006AD80: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8006AD84: lwc1        $f16, 0x50($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8006AD88: add.s       $f24, $f24, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f6.fl;
    // 0x8006AD8C: lwc1        $f18, 0x54($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X54);
    // 0x8006AD90: add.s       $f20, $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f10.fl;
    // 0x8006AD94: add.s       $f22, $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f16.fl;
    // 0x8006AD98: add.s       $f24, $f24, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f18.fl;
    // 0x8006AD9C: swc1        $f20, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f20.u32l;
    // 0x8006ADA0: swc1        $f22, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f22.u32l;
    // 0x8006ADA4: swc1        $f24, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f24.u32l;
    // 0x8006ADA8: lhu         $t0, 0x8($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X8);
    // 0x8006ADAC: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8006ADB0: andi        $at, $t0, 0x400
    ctx->r1 = ctx->r8 & 0X400;
    // 0x8006ADB4: beq         $at, $zero, L_8006ADC8
    if (ctx->r1 == 0) {
        // 0x8006ADB8: addiu       $t1, $a0, 0x28
        ctx->r9 = ADD32(ctx->r4, 0X28);
            goto L_8006ADC8;
    }
    // 0x8006ADB8: addiu       $t1, $a0, 0x28
    ctx->r9 = ADD32(ctx->r4, 0X28);
    // 0x8006ADBC: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x8006ADC0: j           L_8006ADD8
    // 0x8006ADC4: andi        $at, $t0, 0x40
    ctx->r1 = ctx->r8 & 0X40;
        goto L_8006ADD8;
    // 0x8006ADC4: andi        $at, $t0, 0x40
    ctx->r1 = ctx->r8 & 0X40;
L_8006ADC8:
    // 0x8006ADC8: andi        $at, $t0, 0x800
    ctx->r1 = ctx->r8 & 0X800;
    // 0x8006ADCC: beq         $at, $zero, L_8006ADD8
    if (ctx->r1 == 0) {
        // 0x8006ADD0: andi        $at, $t0, 0x40
        ctx->r1 = ctx->r8 & 0X40;
            goto L_8006ADD8;
    }
    // 0x8006ADD0: andi        $at, $t0, 0x40
    ctx->r1 = ctx->r8 & 0X40;
    // 0x8006ADD4: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_8006ADD8:
    // 0x8006ADD8: beq         $at, $zero, L_8006ADF8
    if (ctx->r1 == 0) {
        // 0x8006ADDC: lwc1        $f4, 0x0($t1)
        ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
            goto L_8006ADF8;
    }
    // 0x8006ADDC: lwc1        $f4, 0x0($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8006ADE0: ori         $t0, $zero, 0x4
    ctx->r8 = 0 | 0X4;
    // 0x8006ADE4: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x8006ADE8: nop

    // 0x8006ADEC: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8006ADF0: mul.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8006ADF4: nop

L_8006ADF8:
    // 0x8006ADF8: lwc1        $f6, 0xC($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0XC);
    // 0x8006ADFC: mul.s       $f4, $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8006AE00: lwc1        $f8, 0x18($t1)
    ctx->f8.u32l = MEM_W(ctx->r9, 0X18);
    // 0x8006AE04: mul.s       $f6, $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8006AE08: nop

    // 0x8006AE0C: mul.s       $f8, $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8006AE10: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8006AE14: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8006AE18: mul.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8006AE1C: nop

    // 0x8006AE20: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x8006AE24: mtc1        $t4, $f20
    ctx->f20.u32l = ctx->r12;
    // 0x8006AE28: mtc1        $t5, $f22
    ctx->f22.u32l = ctx->r13;
    // 0x8006AE2C: mtc1        $t6, $f24
    ctx->f24.u32l = ctx->r14;
    // 0x8006AE30: mtc1        $t7, $f26
    ctx->f26.u32l = ctx->r15;
    // 0x8006AE34: jr          $ra
    // 0x8006AE38: nop

    return;
    // 0x8006AE38: nop

L_8006AE3C:
    // 0x8006AE3C: lui         $v0, 0x8006
    ctx->r2 = S32(0X8006 << 16);
    // 0x8006AE40: j           L_8006AD00
    // 0x8006AE44: ori         $v0, $v0, 0xAE48
    ctx->r2 = ctx->r2 | 0XAE48;
        goto L_8006AD00;
    // 0x8006AE44: ori         $v0, $v0, 0xAE48
    ctx->r2 = ctx->r2 | 0XAE48;
;}
RECOMP_FUNC void func_8006AE58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006AE58: addiu       $sp, $sp, -0x4
    ctx->r29 = ADD32(ctx->r29, -0X4);
    // 0x8006AE5C: sw          $ra, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r31;
    // 0x8006AE60: jal         0x8006ACB0
    // 0x8006AE64: nop

    func_8006ACB0(rdram, ctx);
        goto after_0;
    // 0x8006AE64: nop

    after_0:
    // 0x8006AE68: mfc1        $t0, $f20
    ctx->r8 = (int32_t)ctx->f20.u32l;
    // 0x8006AE6C: mfc1        $t1, $f22
    ctx->r9 = (int32_t)ctx->f22.u32l;
    // 0x8006AE70: mfc1        $t2, $f24
    ctx->r10 = (int32_t)ctx->f24.u32l;
    // 0x8006AE74: mfc1        $t3, $f26
    ctx->r11 = (int32_t)ctx->f26.u32l;
    // 0x8006AE78: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8006AE7C: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8006AE80: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8006AE84: sub.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8006AE88: lwc1        $f10, 0x4($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8006AE8C: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8006AE90: sub.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8006AE94: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x8006AE98: nop

    // 0x8006AE9C: sub.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8006AEA0: lwc1        $f20, 0x0($a3)
    ctx->f20.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8006AEA4: lwc1        $f22, 0x4($a3)
    ctx->f22.u32l = MEM_W(ctx->r7, 0X4);
    // 0x8006AEA8: mul.s       $f16, $f20, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x8006AEAC: lwc1        $f24, 0x8($a3)
    ctx->f24.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8006AEB0: mul.s       $f10, $f22, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f6.fl);
    // 0x8006AEB4: nop

    // 0x8006AEB8: mul.s       $f18, $f24, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f24.fl, ctx->f8.fl);
    // 0x8006AEBC: add.s       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8006AEC0: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8006AEC4: mul.s       $f18, $f4, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f4.fl);
    // 0x8006AEC8: nop

    // 0x8006AECC: mul.s       $f6, $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f6.fl);
    // 0x8006AED0: nop

    // 0x8006AED4: mul.s       $f8, $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8006AED8: add.s       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8006AEDC: add.s       $f18, $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8006AEE0: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8006AEE4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8006AEE8: nop

    // 0x8006AEEC: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8006AEF0: nop

    // 0x8006AEF4: c.lt.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl < ctx->f6.fl;
    // 0x8006AEF8: nop

    // 0x8006AEFC: bc1f        L_8006AF14
    if (!c1cs) {
        // 0x8006AF00: nop
    
            goto L_8006AF14;
    }
    // 0x8006AF00: nop

    // 0x8006AF04: c.le.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl <= ctx->f4.fl;
    // 0x8006AF08: nop

    // 0x8006AF0C: bc1f        L_8006AFA0
    if (!c1cs) {
        // 0x8006AF10: nop
    
            goto L_8006AFA0;
    }
    // 0x8006AF10: nop

L_8006AF14:
    // 0x8006AF14: mul.s       $f20, $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8006AF18: nop

    // 0x8006AF1C: mul.s       $f22, $f22, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x8006AF20: nop

    // 0x8006AF24: mul.s       $f24, $f24, $f24
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f24.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x8006AF28: add.s       $f20, $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f22.fl;
    // 0x8006AF2C: add.s       $f20, $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f24.fl;
    // 0x8006AF30: mul.s       $f22, $f16, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8006AF34: sub.s       $f18, $f4, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x8006AF38: div.s       $f24, $f22, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f24.fl = DIV_S(ctx->f22.fl, ctx->f20.fl);
    // 0x8006AF3C: nop

    // 0x8006AF40: add.s       $f18, $f18, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f24.fl;
    // 0x8006AF44: c.le.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl <= ctx->f6.fl;
    // 0x8006AF48: nop

    // 0x8006AF4C: bc1t        L_8006AFA0
    if (c1cs) {
        // 0x8006AF50: nop
    
            goto L_8006AFA0;
    }
    // 0x8006AF50: nop

    // 0x8006AF54: sqrt.s      $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f20.fl = sqrtf(ctx->f20.fl);
    // 0x8006AF58: nop

    // 0x8006AF5C: sqrt.s      $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = sqrtf(ctx->f18.fl);
    // 0x8006AF60: nop

    // 0x8006AF64: div.s       $f16, $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = DIV_S(ctx->f16.fl, ctx->f20.fl);
    // 0x8006AF68: nop

    // 0x8006AF6C: sub.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8006AF70: c.le.s      $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f16.fl <= ctx->f20.fl;
    // 0x8006AF74: nop

    // 0x8006AF78: bc1f        L_8006AFA0
    if (!c1cs) {
        // 0x8006AF7C: nop
    
            goto L_8006AFA0;
    }
    // 0x8006AF7C: nop

    // 0x8006AF80: mtc1        $t0, $f20
    ctx->f20.u32l = ctx->r8;
    // 0x8006AF84: mtc1        $t1, $f22
    ctx->f22.u32l = ctx->r9;
    // 0x8006AF88: mtc1        $t2, $f24
    ctx->f24.u32l = ctx->r10;
    // 0x8006AF8C: mtc1        $t3, $f26
    ctx->f26.u32l = ctx->r11;
    // 0x8006AF90: lw          $ra, 0x0($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X0);
    // 0x8006AF94: addiu       $sp, $sp, 0x4
    ctx->r29 = ADD32(ctx->r29, 0X4);
    // 0x8006AF98: jr          $ra
    // 0x8006AF9C: nop

    return;
    // 0x8006AF9C: nop

L_8006AFA0:
    // 0x8006AFA0: mtc1        $t0, $f20
    ctx->f20.u32l = ctx->r8;
    // 0x8006AFA4: mtc1        $t1, $f22
    ctx->f22.u32l = ctx->r9;
    // 0x8006AFA8: mtc1        $t2, $f24
    ctx->f24.u32l = ctx->r10;
    // 0x8006AFAC: mtc1        $t3, $f26
    ctx->f26.u32l = ctx->r11;
    // 0x8006AFB0: lw          $ra, 0x0($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X0);
    // 0x8006AFB4: addiu       $sp, $sp, 0x4
    ctx->r29 = ADD32(ctx->r29, 0X4);
    // 0x8006AFB8: jr          $ra
    // 0x8006AFBC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x8006AFBC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void decrypt_ns_hmt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006AFC0: addu        $t0, $a0, $zero
    ctx->r8 = ADD32(ctx->r4, 0);
    // 0x8006AFC4: addu        $t1, $a1, $zero
    ctx->r9 = ADD32(ctx->r5, 0);
    // 0x8006AFC8: addu        $t2, $a2, $zero
    ctx->r10 = ADD32(ctx->r6, 0);
L_8006AFCC:
    // 0x8006AFCC: lbu         $t3, 0x0($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X0);
    // 0x8006AFD0: andi        $t4, $t2, 0xFF
    ctx->r12 = ctx->r10 & 0XFF;
    // 0x8006AFD4: xor         $t5, $t3, $t4
    ctx->r13 = ctx->r11 ^ ctx->r12;
    // 0x8006AFD8: sb          $t5, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r13;
    // 0x8006AFDC: srl         $t4, $t2, 8
    ctx->r12 = S32(U32(ctx->r10) >> 8);
    // 0x8006AFE0: sll         $t2, $t2, 24
    ctx->r10 = S32(ctx->r10 << 24);
    // 0x8006AFE4: or          $t2, $t2, $t4
    ctx->r10 = ctx->r10 | ctx->r12;
    // 0x8006AFE8: addu        $t2, $t2, $t3
    ctx->r10 = ADD32(ctx->r10, ctx->r11);
    // 0x8006AFEC: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x8006AFF0: bne         $t1, $zero, L_8006AFCC
    if (ctx->r9 != 0) {
        // 0x8006AFF4: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_8006AFCC;
    }
    // 0x8006AFF4: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8006AFF8: jr          $ra
    // 0x8006AFFC: nop

    return;
    // 0x8006AFFC: nop

;}
RECOMP_FUNC void applyLevelScreenAndCameraSettings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006B004: lui         $a1, 0x8003
    ctx->r5 = S32(0X8003 << 16);
    // 0x8006B008: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8006B00C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8006B010: lbu         $a0, 0xB40($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0XB40);
    // 0x8006B014: addiu       $v0, $v0, 0x5D0
    ctx->r2 = ADD32(ctx->r2, 0X5D0);
    // 0x8006B018: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8006B01C: sll         $v1, $a0, 1
    ctx->r3 = S32(ctx->r4 << 1);
    // 0x8006B020: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x8006B024: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x8006B028: addu        $v1, $v1, $v0
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8006B02C: lhu         $v0, 0x4($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X4);
    // 0x8006B030: addiu       $a1, $a1, 0x7560
    ctx->r5 = ADD32(ctx->r5, 0X7560);
    // 0x8006B034: sll         $v0, $v0, 10
    ctx->r2 = S32(ctx->r2 << 10);
    // 0x8006B038: sw          $v0, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->r2;
    // 0x8006B03C: lhu         $v0, 0x6($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X6);
    // 0x8006B040: sll         $v0, $v0, 10
    ctx->r2 = S32(ctx->r2 << 10);
    // 0x8006B044: sw          $v0, 0x38($a1)
    MEM_W(0X38, ctx->r5) = ctx->r2;
    // 0x8006B048: lhu         $v1, 0x8($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X8);
    // 0x8006B04C: addiu       $a2, $a2, 0xB40
    ctx->r6 = ADD32(ctx->r6, 0XB40);
    // 0x8006B050: sw          $zero, 0x44($a1)
    MEM_W(0X44, ctx->r5) = 0;
    // 0x8006B054: lw          $v0, 0x10($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X10);
    // 0x8006B058: sll         $v1, $v1, 10
    ctx->r3 = S32(ctx->r3 << 10);
    // 0x8006B05C: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8006B060: beq         $v0, $zero, L_8006B084
    if (ctx->r2 == 0) {
        // 0x8006B064: sw          $v1, 0x34($a1)
        MEM_W(0X34, ctx->r5) = ctx->r3;
            goto L_8006B084;
    }
    // 0x8006B064: sw          $v1, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->r3;
    // 0x8006B068: addiu       $v0, $zero, 0x200
    ctx->r2 = ADD32(0, 0X200);
    // 0x8006B06C: sh          $v0, 0x12($a1)
    MEM_H(0X12, ctx->r5) = ctx->r2;
    // 0x8006B070: addiu       $v0, $zero, 0x1C0
    ctx->r2 = ADD32(0, 0X1C0);
    // 0x8006B074: sh          $v0, 0x14($a1)
    MEM_H(0X14, ctx->r5) = ctx->r2;
    // 0x8006B078: addiu       $v0, $zero, 0x40
    ctx->r2 = ADD32(0, 0X40);
    // 0x8006B07C: j           L_8006B0A0
    // 0x8006B080: sw          $v0, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->r2;
        goto L_8006B0A0;
    // 0x8006B080: sw          $v0, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->r2;
L_8006B084:
    // 0x8006B084: addiu       $v0, $zero, 0x140
    ctx->r2 = ADD32(0, 0X140);
    // 0x8006B088: sh          $v0, 0x12($a1)
    MEM_H(0X12, ctx->r5) = ctx->r2;
    // 0x8006B08C: lbu         $v1, 0x23($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X23);
    // 0x8006B090: addiu       $v0, $zero, 0xE0
    ctx->r2 = ADD32(0, 0XE0);
    // 0x8006B094: sh          $v0, 0x14($a1)
    MEM_H(0X14, ctx->r5) = ctx->r2;
    // 0x8006B098: beq         $v1, $zero, L_8006B0F4
    if (ctx->r3 == 0) {
        // 0x8006B09C: sw          $zero, 0x44($a1)
        MEM_W(0X44, ctx->r5) = 0;
            goto L_8006B0F4;
    }
    // 0x8006B09C: sw          $zero, 0x44($a1)
    MEM_W(0X44, ctx->r5) = 0;
L_8006B0A0:
    // 0x8006B0A0: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x8006B0A4: sh          $v0, 0x16($a1)
    MEM_H(0X16, ctx->r5) = ctx->r2;
    // 0x8006B0A8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006B0AC: lbu         $v0, 0xB63($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB63);
    // 0x8006B0B0: beq         $v0, $zero, L_8006B0F4
    if (ctx->r2 == 0) {
        // 0x8006B0B4: lui         $a1, 0x4
        ctx->r5 = S32(0X4 << 16);
            goto L_8006B0F4;
    }
    // 0x8006B0B4: lui         $a1, 0x4
    ctx->r5 = S32(0X4 << 16);
    // 0x8006B0B8: ori         $a1, $a1, 0xB000
    ctx->r5 = ctx->r5 | 0XB000;
    // 0x8006B0BC: lui         $v0, 0x8003
    ctx->r2 = S32(0X8003 << 16);
    // 0x8006B0C0: addiu       $v0, $v0, 0x7560
    ctx->r2 = ADD32(ctx->r2, 0X7560);
    // 0x8006B0C4: lui         $v1, 0x10
    ctx->r3 = S32(0X10 << 16);
    // 0x8006B0C8: sw          $v1, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r3;
    // 0x8006B0CC: lw          $v1, 0x30($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X30);
    // 0x8006B0D0: lui         $a0, 0x4
    ctx->r4 = S32(0X4 << 16);
    // 0x8006B0D4: sw          $a0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r4;
    // 0x8006B0D8: sw          $a0, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r4;
    // 0x8006B0DC: addiu       $a0, $zero, 0x7D0
    ctx->r4 = ADD32(0, 0X7D0);
    // 0x8006B0E0: sh          $a0, 0x3C($v0)
    MEM_H(0X3C, ctx->r2) = ctx->r4;
    // 0x8006B0E4: sh          $a0, 0x3E($v0)
    MEM_H(0X3E, ctx->r2) = ctx->r4;
    // 0x8006B0E8: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x8006B0EC: j           L_8006B174
    // 0x8006B0F0: sw          $v1, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r3;
        goto L_8006B174;
    // 0x8006B0F0: sw          $v1, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r3;
L_8006B0F4:
    // 0x8006B0F4: jal         0x8006B180
    // 0x8006B0F8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    isCraftAvailableByIdx(rdram, ctx);
        goto after_0;
    // 0x8006B0F8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_0:
    // 0x8006B0FC: bne         $v0, $zero, L_8006B124
    if (ctx->r2 != 0) {
        // 0x8006B100: lui         $v0, 0x8003
        ctx->r2 = S32(0X8003 << 16);
            goto L_8006B124;
    }
    // 0x8006B100: lui         $v0, 0x8003
    ctx->r2 = S32(0X8003 << 16);
    // 0x8006B104: lui         $a0, 0xFFFF
    ctx->r4 = S32(0XFFFF << 16);
    // 0x8006B108: lui         $v1, 0x8003
    ctx->r3 = S32(0X8003 << 16);
    // 0x8006B10C: addiu       $v1, $v1, 0x7560
    ctx->r3 = ADD32(ctx->r3, 0X7560);
    // 0x8006B110: lw          $v0, 0x38($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X38);
    // 0x8006B114: ori         $a0, $a0, 0x4C00
    ctx->r4 = ctx->r4 | 0X4C00;
    // 0x8006B118: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8006B11C: sw          $v0, 0x38($v1)
    MEM_W(0X38, ctx->r3) = ctx->r2;
    // 0x8006B120: lui         $v0, 0x8003
    ctx->r2 = S32(0X8003 << 16);
L_8006B124:
    // 0x8006B124: sw          $zero, 0x7588($v0)
    MEM_W(0X7588, ctx->r2) = 0;
    // 0x8006B128: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006B12C: lbu         $v1, 0xB40($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0XB40);
    // 0x8006B130: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x8006B134: beq         $v1, $v0, L_8006B168
    if (ctx->r3 == ctx->r2) {
        // 0x8006B138: slti        $v0, $v1, 0x7
        ctx->r2 = SIGNED(ctx->r3) < 0X7 ? 1 : 0;
            goto L_8006B168;
    }
    // 0x8006B138: slti        $v0, $v1, 0x7
    ctx->r2 = SIGNED(ctx->r3) < 0X7 ? 1 : 0;
    // 0x8006B13C: beq         $v0, $zero, L_8006B154
    if (ctx->r2 == 0) {
        // 0x8006B140: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8006B154;
    }
    // 0x8006B140: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8006B144: beq         $v1, $v0, L_8006B16C
    if (ctx->r3 == ctx->r2) {
        // 0x8006B148: lui         $v1, 0x8003
        ctx->r3 = S32(0X8003 << 16);
            goto L_8006B16C;
    }
    // 0x8006B148: lui         $v1, 0x8003
    ctx->r3 = S32(0X8003 << 16);
    // 0x8006B14C: j           L_8006B174
    // 0x8006B150: nop

        goto L_8006B174;
    // 0x8006B150: nop

L_8006B154:
    // 0x8006B154: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x8006B158: beq         $v1, $v0, L_8006B168
    if (ctx->r3 == ctx->r2) {
        // 0x8006B15C: addiu       $v0, $zero, 0xC
        ctx->r2 = ADD32(0, 0XC);
            goto L_8006B168;
    }
    // 0x8006B15C: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
    // 0x8006B160: bne         $v1, $v0, L_8006B174
    if (ctx->r3 != ctx->r2) {
        // 0x8006B164: nop
    
            goto L_8006B174;
    }
    // 0x8006B164: nop

L_8006B168:
    // 0x8006B168: lui         $v1, 0x8003
    ctx->r3 = S32(0X8003 << 16);
L_8006B16C:
    // 0x8006B16C: lui         $v0, 0x8
    ctx->r2 = S32(0X8 << 16);
    // 0x8006B170: sw          $v0, 0x7588($v1)
    MEM_W(0X7588, ctx->r3) = ctx->r2;
L_8006B174:
    // 0x8006B174: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8006B178: jr          $ra
    // 0x8006B17C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8006B17C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void isCraftAvailableByIdx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B180: sltiu       $v0, $a0, 0x8
    ctx->r2 = ctx->r4 < 0X8 ? 1 : 0;
    // 0x8006B184: beq         $v0, $zero, L_8006B3C8
    if (ctx->r2 == 0) {
        // 0x8006B188: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_8006B3C8;
    }
    // 0x8006B188: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8006B18C: addiu       $v0, $v0, -0x3700
    ctx->r2 = ADD32(ctx->r2, -0X3700);
    // 0x8006B190: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x8006B194: addu        $v1, $v1, $v0
    gpr jr_addend_8006B19C = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8006B198: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x8006B19C: jr          $v0
    // 0x8006B1A0: nop

    switch (jr_addend_8006B19C >> 2) {
        case 0: goto L_8006B1A4; break;
        case 1: goto L_8006B1F0; break;
        case 2: goto L_8006B23C; break;
        case 3: goto L_8006B340; break;
        case 4: goto L_8006B384; break;
        case 5: goto L_8006B274; break;
        case 6: goto L_8006B2B8; break;
        case 7: goto L_8006B2FC; break;
        default: switch_error(__func__, 0x8006B19C, 0x8003C900);
    }
    // 0x8006B1A0: nop

L_8006B1A4:
    // 0x8006B1A4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8006B1A8: addiu       $v0, $a0, 0xB40
    ctx->r2 = ADD32(ctx->r4, 0XB40);
    // 0x8006B1AC: lbu         $v0, 0x23($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X23);
    // 0x8006B1B0: bne         $v0, $zero, L_8006B1E8
    if (ctx->r2 != 0) {
        // 0x8006B1B4: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8006B1E8;
    }
    // 0x8006B1B4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006B1B8: lbu         $v0, 0xB39($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB39);
    // 0x8006B1BC: bne         $v0, $zero, L_8006B1E8
    if (ctx->r2 != 0) {
        // 0x8006B1C0: lui         $v1, 0x800A
        ctx->r3 = S32(0X800A << 16);
            goto L_8006B1E8;
    }
    // 0x8006B1C0: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8006B1C4: lbu         $a0, 0xB40($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0XB40);
    // 0x8006B1C8: addiu       $v1, $v1, 0x5D0
    ctx->r3 = ADD32(ctx->r3, 0X5D0);
    // 0x8006B1CC: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8006B1D0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8006B1D4: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8006B1D8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006B1DC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8006B1E0: jr          $ra
    // 0x8006B1E4: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    return;
    // 0x8006B1E4: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
L_8006B1E8:
    // 0x8006B1E8: jr          $ra
    // 0x8006B1EC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x8006B1EC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8006B1F0:
    // 0x8006B1F0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8006B1F4: addiu       $v0, $a0, 0xB40
    ctx->r2 = ADD32(ctx->r4, 0XB40);
    // 0x8006B1F8: lbu         $v0, 0x23($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X23);
    // 0x8006B1FC: bne         $v0, $zero, L_8006B234
    if (ctx->r2 != 0) {
        // 0x8006B200: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8006B234;
    }
    // 0x8006B200: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006B204: lbu         $v0, 0xB39($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB39);
    // 0x8006B208: bne         $v0, $zero, L_8006B234
    if (ctx->r2 != 0) {
        // 0x8006B20C: lui         $v1, 0x800A
        ctx->r3 = S32(0X800A << 16);
            goto L_8006B234;
    }
    // 0x8006B20C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8006B210: lbu         $a0, 0xB40($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0XB40);
    // 0x8006B214: addiu       $v1, $v1, 0x5D0
    ctx->r3 = ADD32(ctx->r3, 0X5D0);
    // 0x8006B218: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8006B21C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8006B220: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8006B224: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006B228: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8006B22C: jr          $ra
    // 0x8006B230: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
    return;
    // 0x8006B230: andi        $v0, $v0, 0x2
    ctx->r2 = ctx->r2 & 0X2;
L_8006B234:
    // 0x8006B234: jr          $ra
    // 0x8006B238: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8006B238: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006B23C:
    // 0x8006B23C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8006B240: addiu       $v0, $a0, 0xB40
    ctx->r2 = ADD32(ctx->r4, 0XB40);
    // 0x8006B244: lbu         $v0, 0x23($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X23);
    // 0x8006B248: bne         $v0, $zero, L_8006B234
    if (ctx->r2 != 0) {
        // 0x8006B24C: lui         $v1, 0x800A
        ctx->r3 = S32(0X800A << 16);
            goto L_8006B234;
    }
    // 0x8006B24C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8006B250: lbu         $a0, 0xB40($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0XB40);
    // 0x8006B254: addiu       $v1, $v1, 0x5D0
    ctx->r3 = ADD32(ctx->r3, 0X5D0);
    // 0x8006B258: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8006B25C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8006B260: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8006B264: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006B268: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8006B26C: jr          $ra
    // 0x8006B270: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
    return;
    // 0x8006B270: andi        $v0, $v0, 0x4
    ctx->r2 = ctx->r2 & 0X4;
L_8006B274:
    // 0x8006B274: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8006B278: addiu       $v0, $a0, 0xB40
    ctx->r2 = ADD32(ctx->r4, 0XB40);
    // 0x8006B27C: lbu         $v0, 0x23($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X23);
    // 0x8006B280: bne         $v0, $zero, L_8006B234
    if (ctx->r2 != 0) {
        // 0x8006B284: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8006B234;
    }
    // 0x8006B284: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006B288: lbu         $v0, 0xB39($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB39);
    // 0x8006B28C: bne         $v0, $zero, L_8006B234
    if (ctx->r2 != 0) {
        // 0x8006B290: lui         $v1, 0x800A
        ctx->r3 = S32(0X800A << 16);
            goto L_8006B234;
    }
    // 0x8006B290: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8006B294: lbu         $a0, 0xB40($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0XB40);
    // 0x8006B298: addiu       $v1, $v1, 0x5D0
    ctx->r3 = ADD32(ctx->r3, 0X5D0);
    // 0x8006B29C: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8006B2A0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8006B2A4: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8006B2A8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006B2AC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8006B2B0: jr          $ra
    // 0x8006B2B4: andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
    return;
    // 0x8006B2B4: andi        $v0, $v0, 0x20
    ctx->r2 = ctx->r2 & 0X20;
L_8006B2B8:
    // 0x8006B2B8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8006B2BC: addiu       $v0, $a0, 0xB40
    ctx->r2 = ADD32(ctx->r4, 0XB40);
    // 0x8006B2C0: lbu         $v0, 0x23($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X23);
    // 0x8006B2C4: bne         $v0, $zero, L_8006B1E8
    if (ctx->r2 != 0) {
        // 0x8006B2C8: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8006B1E8;
    }
    // 0x8006B2C8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006B2CC: lbu         $v0, 0xB39($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB39);
    // 0x8006B2D0: bne         $v0, $zero, L_8006B1E8
    if (ctx->r2 != 0) {
        // 0x8006B2D4: lui         $v1, 0x800A
        ctx->r3 = S32(0X800A << 16);
            goto L_8006B1E8;
    }
    // 0x8006B2D4: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8006B2D8: lbu         $a0, 0xB40($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0XB40);
    // 0x8006B2DC: addiu       $v1, $v1, 0x5D0
    ctx->r3 = ADD32(ctx->r3, 0X5D0);
    // 0x8006B2E0: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8006B2E4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8006B2E8: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8006B2EC: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006B2F0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8006B2F4: jr          $ra
    // 0x8006B2F8: andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
    return;
    // 0x8006B2F8: andi        $v0, $v0, 0x40
    ctx->r2 = ctx->r2 & 0X40;
L_8006B2FC:
    // 0x8006B2FC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8006B300: addiu       $v0, $a0, 0xB40
    ctx->r2 = ADD32(ctx->r4, 0XB40);
    // 0x8006B304: lbu         $v0, 0x23($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X23);
    // 0x8006B308: bne         $v0, $zero, L_8006B1E8
    if (ctx->r2 != 0) {
        // 0x8006B30C: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8006B1E8;
    }
    // 0x8006B30C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006B310: lbu         $v0, 0xB39($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB39);
    // 0x8006B314: bne         $v0, $zero, L_8006B1E8
    if (ctx->r2 != 0) {
        // 0x8006B318: lui         $v1, 0x800A
        ctx->r3 = S32(0X800A << 16);
            goto L_8006B1E8;
    }
    // 0x8006B318: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8006B31C: lbu         $a0, 0xB40($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0XB40);
    // 0x8006B320: addiu       $v1, $v1, 0x5D0
    ctx->r3 = ADD32(ctx->r3, 0X5D0);
    // 0x8006B324: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8006B328: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8006B32C: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8006B330: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006B334: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8006B338: jr          $ra
    // 0x8006B33C: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
    return;
    // 0x8006B33C: andi        $v0, $v0, 0x80
    ctx->r2 = ctx->r2 & 0X80;
L_8006B340:
    // 0x8006B340: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8006B344: addiu       $v0, $a0, 0xB40
    ctx->r2 = ADD32(ctx->r4, 0XB40);
    // 0x8006B348: lbu         $v0, 0x23($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X23);
    // 0x8006B34C: bne         $v0, $zero, L_8006B1E8
    if (ctx->r2 != 0) {
        // 0x8006B350: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8006B1E8;
    }
    // 0x8006B350: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006B354: lbu         $v0, 0xB39($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB39);
    // 0x8006B358: bne         $v0, $zero, L_8006B1E8
    if (ctx->r2 != 0) {
        // 0x8006B35C: lui         $v1, 0x800A
        ctx->r3 = S32(0X800A << 16);
            goto L_8006B1E8;
    }
    // 0x8006B35C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8006B360: lbu         $a0, 0xB40($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0XB40);
    // 0x8006B364: addiu       $v1, $v1, 0x5D0
    ctx->r3 = ADD32(ctx->r3, 0X5D0);
    // 0x8006B368: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8006B36C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8006B370: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8006B374: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006B378: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8006B37C: jr          $ra
    // 0x8006B380: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
    return;
    // 0x8006B380: andi        $v0, $v0, 0x8
    ctx->r2 = ctx->r2 & 0X8;
L_8006B384:
    // 0x8006B384: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8006B388: addiu       $v0, $a0, 0xB40
    ctx->r2 = ADD32(ctx->r4, 0XB40);
    // 0x8006B38C: lbu         $v0, 0x23($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X23);
    // 0x8006B390: bne         $v0, $zero, L_8006B1E8
    if (ctx->r2 != 0) {
        // 0x8006B394: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8006B1E8;
    }
    // 0x8006B394: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006B398: lbu         $v0, 0xB39($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0XB39);
    // 0x8006B39C: bne         $v0, $zero, L_8006B1E8
    if (ctx->r2 != 0) {
        // 0x8006B3A0: lui         $v1, 0x800A
        ctx->r3 = S32(0X800A << 16);
            goto L_8006B1E8;
    }
    // 0x8006B3A0: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8006B3A4: lbu         $a0, 0xB40($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0XB40);
    // 0x8006B3A8: addiu       $v1, $v1, 0x5D0
    ctx->r3 = ADD32(ctx->r3, 0X5D0);
    // 0x8006B3AC: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8006B3B0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8006B3B4: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8006B3B8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006B3BC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8006B3C0: jr          $ra
    // 0x8006B3C4: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
    return;
    // 0x8006B3C4: andi        $v0, $v0, 0x10
    ctx->r2 = ctx->r2 & 0X10;
L_8006B3C8:
    // 0x8006B3C8: jr          $ra
    // 0x8006B3CC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x8006B3CC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void getBootConfigField12(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B3D0: lui         $v0, 0x8003
    ctx->r2 = S32(0X8003 << 16);
    // 0x8006B3D4: lhu         $v0, 0x7572($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7572);
    // 0x8006B3D8: jr          $ra
    // 0x8006B3DC: nop

    return;
    // 0x8006B3DC: nop

;}
RECOMP_FUNC void getBootConfigField14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B3E0: lui         $v0, 0x8003
    ctx->r2 = S32(0X8003 << 16);
    // 0x8006B3E4: lhu         $v0, 0x7574($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7574);
    // 0x8006B3E8: jr          $ra
    // 0x8006B3EC: nop

    return;
    // 0x8006B3EC: nop

;}
RECOMP_FUNC void func_8006B3F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B3F0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8006B3F4: addiu       $v0, $v1, 0xB40
    ctx->r2 = ADD32(ctx->r3, 0XB40);
    // 0x8006B3F8: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x8006B3FC: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8006B400: beq         $v0, $zero, L_8006B42C
    if (ctx->r2 == 0) {
        // 0x8006B404: addiu       $v0, $zero, 0xD
        ctx->r2 = ADD32(0, 0XD);
            goto L_8006B42C;
    }
    // 0x8006B404: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // 0x8006B408: lbu         $v1, 0xB40($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0XB40);
    // 0x8006B40C: beq         $v1, $v0, L_8006B424
    if (ctx->r3 == ctx->r2) {
        // 0x8006B410: addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
            goto L_8006B424;
    }
    // 0x8006B410: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x8006B414: beq         $v1, $v0, L_8006B424
    if (ctx->r3 == ctx->r2) {
        // 0x8006B418: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_8006B424;
    }
    // 0x8006B418: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x8006B41C: bne         $v1, $v0, L_8006B430
    if (ctx->r3 != ctx->r2) {
        // 0x8006B420: lui         $v1, 0x800A
        ctx->r3 = S32(0X800A << 16);
            goto L_8006B430;
    }
    // 0x8006B420: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
L_8006B424:
    // 0x8006B424: jr          $ra
    // 0x8006B428: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x8006B428: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8006B42C:
    // 0x8006B42C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
L_8006B430:
    // 0x8006B430: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006B434: lbu         $a0, 0xB40($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0XB40);
    // 0x8006B438: addiu       $v1, $v1, 0x5D0
    ctx->r3 = ADD32(ctx->r3, 0X5D0);
    // 0x8006B43C: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8006B440: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8006B444: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8006B448: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006B44C: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    // 0x8006B450: jr          $ra
    // 0x8006B454: nop

    return;
    // 0x8006B454: nop

;}
RECOMP_FUNC void func_8006B458(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B458: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8006B45C: addiu       $v0, $v1, 0xB40
    ctx->r2 = ADD32(ctx->r3, 0XB40);
    // 0x8006B460: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    // 0x8006B464: andi        $v0, $v0, 0x1
    ctx->r2 = ctx->r2 & 0X1;
    // 0x8006B468: beq         $v0, $zero, L_8006B48C
    if (ctx->r2 == 0) {
        // 0x8006B46C: addiu       $v0, $zero, 0xD
        ctx->r2 = ADD32(0, 0XD);
            goto L_8006B48C;
    }
    // 0x8006B46C: addiu       $v0, $zero, 0xD
    ctx->r2 = ADD32(0, 0XD);
    // 0x8006B470: lbu         $v1, 0xB40($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0XB40);
    // 0x8006B474: beq         $v1, $v0, L_8006B484
    if (ctx->r3 == ctx->r2) {
        // 0x8006B478: addiu       $v0, $zero, 0x6
        ctx->r2 = ADD32(0, 0X6);
            goto L_8006B484;
    }
    // 0x8006B478: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x8006B47C: bne         $v1, $v0, L_8006B490
    if (ctx->r3 != ctx->r2) {
        // 0x8006B480: lui         $v1, 0x800A
        ctx->r3 = S32(0X800A << 16);
            goto L_8006B490;
    }
    // 0x8006B480: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
L_8006B484:
    // 0x8006B484: jr          $ra
    // 0x8006B488: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x8006B488: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8006B48C:
    // 0x8006B48C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
L_8006B490:
    // 0x8006B490: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006B494: lbu         $a0, 0xB40($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0XB40);
    // 0x8006B498: addiu       $v1, $v1, 0x5D0
    ctx->r3 = ADD32(ctx->r3, 0X5D0);
    // 0x8006B49C: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8006B4A0: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8006B4A4: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8006B4A8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006B4AC: lw          $v0, 0xC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XC);
    // 0x8006B4B0: jr          $ra
    // 0x8006B4B4: nop

    return;
    // 0x8006B4B4: nop

;}
RECOMP_FUNC void func_8006B4B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B4B8: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8006B4BC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006B4C0: lbu         $a0, 0xB40($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0XB40);
    // 0x8006B4C4: addiu       $v1, $v1, 0x5D0
    ctx->r3 = ADD32(ctx->r3, 0X5D0);
    // 0x8006B4C8: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8006B4CC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8006B4D0: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8006B4D4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006B4D8: lw          $v0, 0x14($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X14);
    // 0x8006B4DC: jr          $ra
    // 0x8006B4E0: nop

    return;
    // 0x8006B4E0: nop

;}
RECOMP_FUNC void func_8006B4E4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B4E4: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8006B4E8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006B4EC: lbu         $a0, 0xB40($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0XB40);
    // 0x8006B4F0: addiu       $v1, $v1, 0x5D0
    ctx->r3 = ADD32(ctx->r3, 0X5D0);
    // 0x8006B4F4: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8006B4F8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8006B4FC: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8006B500: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006B504: lw          $v0, 0x18($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X18);
    // 0x8006B508: jr          $ra
    // 0x8006B50C: nop

    return;
    // 0x8006B50C: nop

;}
RECOMP_FUNC void func_8006B510(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B510: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8006B514: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006B518: lbu         $a0, 0xB40($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0XB40);
    // 0x8006B51C: addiu       $v1, $v1, 0x5D0
    ctx->r3 = ADD32(ctx->r3, 0X5D0);
    // 0x8006B520: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8006B524: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8006B528: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8006B52C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006B530: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8006B534: jr          $ra
    // 0x8006B538: nop

    return;
    // 0x8006B538: nop

;}
RECOMP_FUNC void func_8006B53C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B53C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8006B540: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006B544: lbu         $a0, 0xB40($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0XB40);
    // 0x8006B548: addiu       $v1, $v1, 0x5D0
    ctx->r3 = ADD32(ctx->r3, 0X5D0);
    // 0x8006B54C: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8006B550: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8006B554: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8006B558: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006B55C: lwc1        $f0, 0x20($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8006B560: jr          $ra
    // 0x8006B564: nop

    return;
    // 0x8006B564: nop

;}
RECOMP_FUNC void func_8006B568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B568: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8006B56C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8006B570: lbu         $v1, 0xB40($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0XB40);
    // 0x8006B574: addiu       $a1, $a1, 0x5D0
    ctx->r5 = ADD32(ctx->r5, 0X5D0);
    // 0x8006B578: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8006B57C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006B580: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8006B584: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8006B588: lbu         $v0, 0x28($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X28);
    // 0x8006B58C: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x8006B590: lbu         $v1, 0xB40($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0XB40);
    // 0x8006B594: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8006B598: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006B59C: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8006B5A0: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8006B5A4: lbu         $v0, 0x29($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X29);
    // 0x8006B5A8: sb          $v0, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r2;
    // 0x8006B5AC: lbu         $v1, 0xB40($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0XB40);
    // 0x8006B5B0: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x8006B5B4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006B5B8: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8006B5BC: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8006B5C0: lbu         $v0, 0x2A($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X2A);
    // 0x8006B5C4: jr          $ra
    // 0x8006B5C8: sb          $v0, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r2;
    return;
    // 0x8006B5C8: sb          $v0, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void func_8006B5CC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B5CC: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8006B5D0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006B5D4: lbu         $a1, 0xB40($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0XB40);
    // 0x8006B5D8: addiu       $v1, $v1, 0x5D0
    ctx->r3 = ADD32(ctx->r3, 0X5D0);
    // 0x8006B5DC: sll         $v0, $a1, 1
    ctx->r2 = S32(ctx->r5 << 1);
    // 0x8006B5E0: addu        $v0, $v0, $a1
    ctx->r2 = ADD32(ctx->r2, ctx->r5);
    // 0x8006B5E4: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8006B5E8: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006B5EC: lwl         $a2, 0x24($v0)
    ctx->r6 = do_lwl(rdram, ctx->r6, ctx->r2, 0X24);
    // 0x8006B5F0: lwr         $a2, 0x27($v0)
    ctx->r6 = do_lwr(rdram, ctx->r6, ctx->r2, 0X27);
    // 0x8006B5F4: swl         $a2, 0x0($a0)
    do_swl(rdram, 0X0, ctx->r4, ctx->r6);
    // 0x8006B5F8: swr         $a2, 0x3($a0)
    do_swr(rdram, 0X3, ctx->r4, ctx->r6);
    // 0x8006B5FC: jr          $ra
    // 0x8006B600: nop

    return;
    // 0x8006B600: nop

;}
RECOMP_FUNC void func_8006B604(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B604: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8006B608: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006B60C: lbu         $a0, 0xB40($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0XB40);
    // 0x8006B610: addiu       $v1, $v1, 0x5D0
    ctx->r3 = ADD32(ctx->r3, 0X5D0);
    // 0x8006B614: sll         $v0, $a0, 1
    ctx->r2 = S32(ctx->r4 << 1);
    // 0x8006B618: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8006B61C: sll         $v0, $v0, 4
    ctx->r2 = S32(ctx->r2 << 4);
    // 0x8006B620: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006B624: lh          $v0, 0x2C($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X2C);
    // 0x8006B628: jr          $ra
    // 0x8006B62C: nop

    return;
    // 0x8006B62C: nop

;}
RECOMP_FUNC void func_8006B630(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B630: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8006B634: addiu       $v0, $v1, 0xB40
    ctx->r2 = ADD32(ctx->r3, 0XB40);
    // 0x8006B638: lbu         $v0, 0x23($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X23);
    // 0x8006B63C: beq         $v0, $zero, L_8006B64C
    if (ctx->r2 == 0) {
        // 0x8006B640: addiu       $v0, $zero, 0x3
        ctx->r2 = ADD32(0, 0X3);
            goto L_8006B64C;
    }
    // 0x8006B640: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8006B644: jr          $ra
    // 0x8006B648: addiu       $v0, $zero, 0x800
    ctx->r2 = ADD32(0, 0X800);
    return;
    // 0x8006B648: addiu       $v0, $zero, 0x800
    ctx->r2 = ADD32(0, 0X800);
L_8006B64C:
    // 0x8006B64C: lbu         $a0, 0xB40($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0XB40);
    // 0x8006B650: bne         $a0, $v0, L_8006B660
    if (ctx->r4 != ctx->r2) {
        // 0x8006B654: addiu       $v0, $zero, 0x7
        ctx->r2 = ADD32(0, 0X7);
            goto L_8006B660;
    }
    // 0x8006B654: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x8006B658: jr          $ra
    // 0x8006B65C: addiu       $v0, $zero, 0x190
    ctx->r2 = ADD32(0, 0X190);
    return;
    // 0x8006B65C: addiu       $v0, $zero, 0x190
    ctx->r2 = ADD32(0, 0X190);
L_8006B660:
    // 0x8006B660: bne         $a0, $v0, L_8006B670
    if (ctx->r4 != ctx->r2) {
        // 0x8006B664: addiu       $v0, $zero, 0x5
        ctx->r2 = ADD32(0, 0X5);
            goto L_8006B670;
    }
    // 0x8006B664: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x8006B668: jr          $ra
    // 0x8006B66C: addiu       $v0, $zero, 0x271
    ctx->r2 = ADD32(0, 0X271);
    return;
    // 0x8006B66C: addiu       $v0, $zero, 0x271
    ctx->r2 = ADD32(0, 0X271);
L_8006B670:
    // 0x8006B670: beq         $a0, $v0, L_8006B688
    if (ctx->r4 == ctx->r2) {
        // 0x8006B674: addiu       $v1, $zero, 0xE
        ctx->r3 = ADD32(0, 0XE);
            goto L_8006B688;
    }
    // 0x8006B674: addiu       $v1, $zero, 0xE
    ctx->r3 = ADD32(0, 0XE);
    // 0x8006B678: beq         $a0, $v1, L_8006B68C
    if (ctx->r4 == ctx->r3) {
        // 0x8006B67C: addiu       $v0, $zero, 0x258
        ctx->r2 = ADD32(0, 0X258);
            goto L_8006B68C;
    }
    // 0x8006B67C: addiu       $v0, $zero, 0x258
    ctx->r2 = ADD32(0, 0X258);
    // 0x8006B680: jr          $ra
    // 0x8006B684: addiu       $v0, $zero, 0x1F4
    ctx->r2 = ADD32(0, 0X1F4);
    return;
    // 0x8006B684: addiu       $v0, $zero, 0x1F4
    ctx->r2 = ADD32(0, 0X1F4);
L_8006B688:
    // 0x8006B688: addiu       $v0, $zero, 0x258
    ctx->r2 = ADD32(0, 0X258);
L_8006B68C:
    // 0x8006B68C: jr          $ra
    // 0x8006B690: nop

    return;
    // 0x8006B690: nop

;}
RECOMP_FUNC void getLevelTimeLimit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B694: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8006B698: addiu       $v0, $v1, 0xB40
    ctx->r2 = ADD32(ctx->r3, 0XB40);
    // 0x8006B69C: lbu         $v0, 0x23($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X23);
    // 0x8006B6A0: bne         $v0, $zero, L_8006B6FC
    if (ctx->r2 != 0) {
        // 0x8006B6A4: addiu       $v0, $zero, 0x7D0
        ctx->r2 = ADD32(0, 0X7D0);
            goto L_8006B6FC;
    }
    // 0x8006B6A4: addiu       $v0, $zero, 0x7D0
    ctx->r2 = ADD32(0, 0X7D0);
    // 0x8006B6A8: lbu         $v0, 0xB40($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0XB40);
    // 0x8006B6AC: addiu       $v1, $v0, -0x4
    ctx->r3 = ADD32(ctx->r2, -0X4);
    // 0x8006B6B0: sltiu       $v0, $v1, 0xE
    ctx->r2 = ctx->r3 < 0XE ? 1 : 0;
    // 0x8006B6B4: beq         $v0, $zero, L_8006B6F4
    if (ctx->r2 == 0) {
        // 0x8006B6B8: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_8006B6F4;
    }
    // 0x8006B6B8: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8006B6BC: addiu       $v0, $v0, -0x36E0
    ctx->r2 = ADD32(ctx->r2, -0X36E0);
    // 0x8006B6C0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8006B6C4: addu        $v1, $v1, $v0
    gpr jr_addend_8006B6CC = ctx->r3;
    ctx->r3 = ADD32(ctx->r3, ctx->r2);
    // 0x8006B6C8: lw          $v0, 0x0($v1)
    ctx->r2 = ADD32(ctx->r3, 0X0);
    // 0x8006B6CC: jr          $v0
    // 0x8006B6D0: nop

    switch (jr_addend_8006B6CC >> 2) {
        case 0: goto L_8006B6D4; break;
        case 1: goto L_8006B6F4; break;
        case 2: goto L_8006B6F4; break;
        case 3: goto L_8006B6DC; break;
        case 4: goto L_8006B6F4; break;
        case 5: goto L_8006B6D4; break;
        case 6: goto L_8006B6F4; break;
        case 7: goto L_8006B6F4; break;
        case 8: goto L_8006B6F4; break;
        case 9: goto L_8006B6D4; break;
        case 10: goto L_8006B6E4; break;
        case 11: goto L_8006B6F4; break;
        case 12: goto L_8006B6F4; break;
        case 13: goto L_8006B6EC; break;
        default: switch_error(__func__, 0x8006B6CC, 0x8003C920);
    }
    // 0x8006B6D0: nop

L_8006B6D4:
    // 0x8006B6D4: jr          $ra
    // 0x8006B6D8: addiu       $v0, $zero, 0x190
    ctx->r2 = ADD32(0, 0X190);
    return;
    // 0x8006B6D8: addiu       $v0, $zero, 0x190
    ctx->r2 = ADD32(0, 0X190);
L_8006B6DC:
    // 0x8006B6DC: jr          $ra
    // 0x8006B6E0: addiu       $v0, $zero, 0x1F4
    ctx->r2 = ADD32(0, 0X1F4);
    return;
    // 0x8006B6E0: addiu       $v0, $zero, 0x1F4
    ctx->r2 = ADD32(0, 0X1F4);
L_8006B6E4:
    // 0x8006B6E4: jr          $ra
    // 0x8006B6E8: addiu       $v0, $zero, 0x258
    ctx->r2 = ADD32(0, 0X258);
    return;
    // 0x8006B6E8: addiu       $v0, $zero, 0x258
    ctx->r2 = ADD32(0, 0X258);
L_8006B6EC:
    // 0x8006B6EC: jr          $ra
    // 0x8006B6F0: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
    return;
    // 0x8006B6F0: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
L_8006B6F4:
    // 0x8006B6F4: jr          $ra
    // 0x8006B6F8: addiu       $v0, $zero, 0x12C
    ctx->r2 = ADD32(0, 0X12C);
    return;
    // 0x8006B6F8: addiu       $v0, $zero, 0x12C
    ctx->r2 = ADD32(0, 0X12C);
L_8006B6FC:
    // 0x8006B6FC: jr          $ra
    // 0x8006B700: nop

    return;
    // 0x8006B700: nop

;}
RECOMP_FUNC void fake_func_8006B704(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void loadCraftShadowTextures(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B710: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8006B714: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8006B718: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8006B71C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006B720: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8006B724: addiu       $s0, $v0, -0x5AD8
    ctx->r16 = ADD32(ctx->r2, -0X5AD8);
    // 0x8006B728: sll         $v0, $s2, 1
    ctx->r2 = S32(ctx->r18 << 1);
    // 0x8006B72C: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8006B730: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8006B734: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x8006B738: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x8006B73C: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8006B740: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8006B744: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8006B748: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x8006B74C: ori         $v0, $zero, 0xFFFF
    ctx->r2 = 0 | 0XFFFF;
    // 0x8006B750: bne         $v1, $v0, L_8006B81C
    if (ctx->r3 != ctx->r2) {
        // 0x8006B754: nop
    
            goto L_8006B81C;
    }
    // 0x8006B754: nop

    // 0x8006B758: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8006B75C: jal         0x8006488C
    // 0x8006B760: addiu       $a0, $a0, -0x36A0
    ctx->r4 = ADD32(ctx->r4, -0X36A0);
    load_asset(rdram, ctx);
        goto after_0;
    // 0x8006B760: addiu       $a0, $a0, -0x36A0
    ctx->r4 = ADD32(ctx->r4, -0X36A0);
    after_0:
    // 0x8006B764: addu        $s5, $v0, $zero
    ctx->r21 = ADD32(ctx->r2, 0);
    // 0x8006B768: addiu       $s6, $zero, -0x4
    ctx->r22 = ADD32(0, -0X4);
    // 0x8006B76C: addu        $s3, $s0, $zero
    ctx->r19 = ADD32(ctx->r16, 0);
    // 0x8006B770: ori         $s4, $zero, 0xFFFF
    ctx->r20 = 0 | 0XFFFF;
L_8006B774:
    // 0x8006B774: addu        $s1, $s5, $zero
    ctx->r17 = ADD32(ctx->r21, 0);
    // 0x8006B778: blez        $s2, L_8006B7A0
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8006B77C: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_8006B7A0;
    }
    // 0x8006B77C: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8006B780:
    // 0x8006B780: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8006B784: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006B788: addu        $v0, $s1, $v0
    ctx->r2 = ADD32(ctx->r17, ctx->r2);
    // 0x8006B78C: addiu       $v0, $v0, 0x7
    ctx->r2 = ADD32(ctx->r2, 0X7);
    // 0x8006B790: and         $s1, $v0, $s6
    ctx->r17 = ctx->r2 & ctx->r22;
    // 0x8006B794: slt         $v0, $v1, $s2
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x8006B798: bne         $v0, $zero, L_8006B780
    if (ctx->r2 != 0) {
        // 0x8006B79C: nop
    
            goto L_8006B780;
    }
    // 0x8006B79C: nop

L_8006B7A0:
    // 0x8006B7A0: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    // 0x8006B7A4: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8006B7A8: jal         0x80055488
    // 0x8006B7AC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    full_header_image_offset_convert(rdram, ctx);
        goto after_1;
    // 0x8006B7AC: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_1:
    // 0x8006B7B0: addiu       $a0, $sp, 0x10
    ctx->r4 = ADD32(ctx->r29, 0X10);
    // 0x8006B7B4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8006B7B8: lhu         $v0, 0x32($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X32);
    // 0x8006B7BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8006B7C0: ori         $v0, $v0, 0x2000
    ctx->r2 = ctx->r2 | 0X2000;
    // 0x8006B7C4: sh          $v0, 0x32($s1)
    MEM_H(0X32, ctx->r17) = ctx->r2;
    // 0x8006B7C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006B7CC: sh          $v0, 0x10($sp)
    MEM_H(0X10, ctx->r29) = ctx->r2;
    // 0x8006B7D0: jal         0x80022B90
    // 0x8006B7D4: sb          $zero, 0x24($sp)
    MEM_B(0X24, ctx->r29) = 0;
    registerHmtTextureInTable(rdram, ctx);
        goto after_2;
    // 0x8006B7D4: sb          $zero, 0x24($sp)
    MEM_B(0X24, ctx->r29) = 0;
    after_2:
    // 0x8006B7D8: sll         $v1, $s2, 1
    ctx->r3 = S32(ctx->r18 << 1);
    // 0x8006B7DC: addu        $v1, $v1, $s3
    ctx->r3 = ADD32(ctx->r3, ctx->r19);
    // 0x8006B7E0: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x8006B7E4: lhu         $v0, 0x12($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X12);
    // 0x8006B7E8: beq         $v0, $s4, L_8006B774
    if (ctx->r2 == ctx->r20) {
        // 0x8006B7EC: addiu       $s2, $zero, 0x9
        ctx->r18 = ADD32(0, 0X9);
            goto L_8006B774;
    }
    // 0x8006B7EC: addiu       $s2, $zero, 0x9
    ctx->r18 = ADD32(0, 0X9);
    // 0x8006B7F0: lhu         $v0, 0x14($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X14);
    // 0x8006B7F4: beq         $v0, $s4, L_8006B774
    if (ctx->r2 == ctx->r20) {
        // 0x8006B7F8: addiu       $s2, $zero, 0xA
        ctx->r18 = ADD32(0, 0XA);
            goto L_8006B774;
    }
    // 0x8006B7F8: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
    // 0x8006B7FC: lhu         $v0, 0x16($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X16);
    // 0x8006B800: beq         $v0, $s4, L_8006B774
    if (ctx->r2 == ctx->r20) {
        // 0x8006B804: addiu       $s2, $zero, 0xB
        ctx->r18 = ADD32(0, 0XB);
            goto L_8006B774;
    }
    // 0x8006B804: addiu       $s2, $zero, 0xB
    ctx->r18 = ADD32(0, 0XB);
    // 0x8006B808: lhu         $v0, 0x18($s3)
    ctx->r2 = MEM_HU(ctx->r19, 0X18);
    // 0x8006B80C: beq         $v0, $s4, L_8006B774
    if (ctx->r2 == ctx->r20) {
        // 0x8006B810: addiu       $s2, $zero, 0xC
        ctx->r18 = ADD32(0, 0XC);
            goto L_8006B774;
    }
    // 0x8006B810: addiu       $s2, $zero, 0xC
    ctx->r18 = ADD32(0, 0XC);
    // 0x8006B814: jal         0x80001C98
    // 0x8006B818: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    rs_free(rdram, ctx);
        goto after_3;
    // 0x8006B818: addu        $a0, $s5, $zero
    ctx->r4 = ADD32(ctx->r21, 0);
    after_3:
L_8006B81C:
    // 0x8006B81C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8006B820: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x8006B824: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x8006B828: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8006B82C: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8006B830: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8006B834: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8006B838: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8006B83C: jr          $ra
    // 0x8006B840: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8006B840: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void applyCentripetalBankingToNpcCorners(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006B844: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8006B848: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8006B84C: addu        $s2, $a0, $zero
    ctx->r18 = ADD32(ctx->r4, 0);
    // 0x8006B850: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8006B854: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8006B858: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8006B85C: sdc1        $f30, 0x58($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X58, ctx->r29);
    // 0x8006B860: sdc1        $f28, 0x50($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X50, ctx->r29);
    // 0x8006B864: sdc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X48, ctx->r29);
    // 0x8006B868: sdc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X40, ctx->r29);
    // 0x8006B86C: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x8006B870: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x8006B874: lwc1        $f2, 0x1C($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X1C);
    // 0x8006B878: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8006B87C: lwc1        $f8, 0x8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8006B880: lwc1        $f6, 0xC($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0XC);
    // 0x8006B884: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x8006B888: nop

    // 0x8006B88C: bc1f        L_8006B8F8
    if (!c1cs) {
        // 0x8006B890: addiu       $s1, $a1, 0x178
        ctx->r17 = ADD32(ctx->r5, 0X178);
            goto L_8006B8F8;
    }
    // 0x8006B890: addiu       $s1, $a1, 0x178
    ctx->r17 = ADD32(ctx->r5, 0X178);
    // 0x8006B894: lwc1        $f0, 0x14($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X14);
    // 0x8006B898: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8006B89C: lwc1        $f4, 0x10($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X10);
    // 0x8006B8A0: lwc1        $f2, 0x20($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X20);
    // 0x8006B8A4: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8006B8A8: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8006B8AC: mul.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8006B8B0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8006B8B4: lwc1        $f0, 0x20($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X20);
    // 0x8006B8B8: lwc1        $f2, 0xC($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0XC);
    // 0x8006B8BC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8006B8C0: lwc1        $f4, 0x14($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X14);
    // 0x8006B8C4: lwc1        $f2, 0x18($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X18);
    // 0x8006B8C8: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8006B8CC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8006B8D0: mul.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8006B8D4: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8006B8D8: lwc1        $f0, 0x18($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X18);
    // 0x8006B8DC: lwc1        $f2, 0x10($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X10);
    // 0x8006B8E0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8006B8E4: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x8006B8E8: lwc1        $f2, 0x1C($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X1C);
    // 0x8006B8EC: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8006B8F0: j           L_8006B964
    // 0x8006B8F4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
        goto L_8006B964;
    // 0x8006B8F4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_8006B8F8:
    // 0x8006B8F8: lwc1        $f0, 0x14($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X14);
    // 0x8006B8FC: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8006B900: lwc1        $f4, 0x10($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X10);
    // 0x8006B904: lwc1        $f2, 0x20($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X20);
    // 0x8006B908: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8006B90C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8006B910: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8006B914: mul.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8006B918: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8006B91C: lwc1        $f0, 0x20($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X20);
    // 0x8006B920: lwc1        $f2, 0xC($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0XC);
    // 0x8006B924: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8006B928: lwc1        $f4, 0x14($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X14);
    // 0x8006B92C: lwc1        $f2, 0x18($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X18);
    // 0x8006B930: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8006B934: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8006B938: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8006B93C: mul.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8006B940: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8006B944: lwc1        $f0, 0x18($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X18);
    // 0x8006B948: lwc1        $f2, 0x10($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X10);
    // 0x8006B94C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8006B950: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x8006B954: lwc1        $f2, 0x1C($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X1C);
    // 0x8006B958: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8006B95C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8006B960: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
L_8006B964:
    // 0x8006B964: mul.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8006B968: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8006B96C: lwc1        $f0, 0xC($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0XC);
    // 0x8006B970: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8006B974: lwc1        $f2, 0x10($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X10);
    // 0x8006B978: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8006B97C: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
    // 0x8006B980: lwc1        $f0, 0x14($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X14);
    // 0x8006B984: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8006B988: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8006B98C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8006B990: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
    // 0x8006B994: lwc1        $f0, 0xC($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0XC);
    // 0x8006B998: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8006B99C: lwc1        $f2, 0x10($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X10);
    // 0x8006B9A0: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8006B9A4: swc1        $f0, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->f0.u32l;
    // 0x8006B9A8: lwc1        $f0, 0x14($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X14);
    // 0x8006B9AC: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8006B9B0: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8006B9B4: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8006B9B8: swc1        $f0, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f0.u32l;
    // 0x8006B9BC: lwc1        $f0, 0xC($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0XC);
    // 0x8006B9C0: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8006B9C4: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8006B9C8: lwc1        $f2, 0x10($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X10);
    // 0x8006B9CC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8006B9D0: swc1        $f0, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->f0.u32l;
    // 0x8006B9D4: lwc1        $f0, 0x14($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X14);
    // 0x8006B9D8: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8006B9DC: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8006B9E0: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8006B9E4: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8006B9E8: swc1        $f0, 0x50($s1)
    MEM_W(0X50, ctx->r17) = ctx->f0.u32l;
    // 0x8006B9EC: lwc1        $f0, 0xC($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0XC);
    // 0x8006B9F0: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8006B9F4: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8006B9F8: lwc1        $f2, 0x10($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X10);
    // 0x8006B9FC: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8006BA00: swc1        $f0, 0x60($s1)
    MEM_W(0X60, ctx->r17) = ctx->f0.u32l;
    // 0x8006BA04: lwc1        $f0, 0x14($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X14);
    // 0x8006BA08: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x8006BA0C: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8006BA10: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8006BA14: add.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f2.fl;
    // 0x8006BA18: lwc1        $f12, 0x0($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8006BA1C: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x8006BA20: swc1        $f0, 0x68($s1)
    MEM_W(0X68, ctx->r17) = ctx->f0.u32l;
    // 0x8006BA24: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8006BA28: lwc1        $f14, 0x8($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8006BA2C: add.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x8006BA30: lwc1        $f0, 0x8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8006BA34: addiu       $s0, $s0, -0x7FA8
    ctx->r16 = ADD32(ctx->r16, -0X7FA8);
    // 0x8006BA38: add.s       $f14, $f0, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x8006BA3C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8006BA40: jal         0x80067D90
    // 0x8006BA44: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    wrapAngleToCyclicRange(rdram, ctx);
        goto after_0;
    // 0x8006BA44: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    after_0:
    // 0x8006BA48: lwc1        $f2, 0x4($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8006BA4C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8006BA50: lwc1        $f12, 0x18($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X18);
    // 0x8006BA54: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
    // 0x8006BA58: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8006BA5C: lwc1        $f14, 0x20($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8006BA60: add.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x8006BA64: lwc1        $f0, 0x8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8006BA68: add.s       $f14, $f0, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x8006BA6C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8006BA70: jal         0x80067D90
    // 0x8006BA74: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    wrapAngleToCyclicRange(rdram, ctx);
        goto after_1;
    // 0x8006BA74: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_1:
    // 0x8006BA78: lwc1        $f2, 0x4($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8006BA7C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8006BA80: lwc1        $f12, 0x48($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X48);
    // 0x8006BA84: swc1        $f0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f0.u32l;
    // 0x8006BA88: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8006BA8C: lwc1        $f14, 0x50($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X50);
    // 0x8006BA90: add.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x8006BA94: lwc1        $f0, 0x8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8006BA98: add.s       $f14, $f0, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x8006BA9C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8006BAA0: jal         0x80067D90
    // 0x8006BAA4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    wrapAngleToCyclicRange(rdram, ctx);
        goto after_2;
    // 0x8006BAA4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_2:
    // 0x8006BAA8: lwc1        $f2, 0x4($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8006BAAC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8006BAB0: lwc1        $f12, 0x60($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X60);
    // 0x8006BAB4: swc1        $f0, 0x4C($s1)
    MEM_W(0X4C, ctx->r17) = ctx->f0.u32l;
    // 0x8006BAB8: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8006BABC: lwc1        $f14, 0x68($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X68);
    // 0x8006BAC0: add.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x8006BAC4: lwc1        $f0, 0x8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8006BAC8: add.s       $f14, $f0, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x8006BACC: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8006BAD0: jal         0x80067D90
    // 0x8006BAD4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    wrapAngleToCyclicRange(rdram, ctx);
        goto after_3;
    // 0x8006BAD4: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_3:
    // 0x8006BAD8: lwc1        $f30, 0x18($s1)
    ctx->f30.u32l = MEM_W(ctx->r17, 0X18);
    // 0x8006BADC: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8006BAE0: sub.s       $f30, $f30, $f16
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f30.fl = ctx->f30.fl - ctx->f16.fl;
    // 0x8006BAE4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006BAE8: lwc1        $f2, -0x3688($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3688);
    // 0x8006BAEC: mul.s       $f30, $f30, $f2
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f30.fl = MUL_S(ctx->f30.fl, ctx->f2.fl);
    // 0x8006BAF0: lwc1        $f10, 0x18($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X18);
    // 0x8006BAF4: lwc1        $f28, 0x60($s1)
    ctx->f28.u32l = MEM_W(ctx->r17, 0X60);
    // 0x8006BAF8: sub.s       $f10, $f10, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f28.fl;
    // 0x8006BAFC: mul.s       $f10, $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8006BB00: lwc1        $f8, 0x20($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8006BB04: lwc1        $f24, 0x68($s1)
    ctx->f24.u32l = MEM_W(ctx->r17, 0X68);
    // 0x8006BB08: sub.s       $f8, $f8, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = ctx->f8.fl - ctx->f24.fl;
    // 0x8006BB0C: mul.s       $f8, $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8006BB10: lwc1        $f6, 0x48($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X48);
    // 0x8006BB14: mov.s       $f20, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    ctx->f20.fl = ctx->f28.fl;
    // 0x8006BB18: sub.s       $f6, $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f20.fl;
    // 0x8006BB1C: mul.s       $f6, $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8006BB20: lwc1        $f26, 0x20($s1)
    ctx->f26.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8006BB24: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8006BB28: sub.s       $f26, $f26, $f16
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f26.fl = ctx->f26.fl - ctx->f16.fl;
    // 0x8006BB2C: mul.s       $f26, $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f26.fl = MUL_S(ctx->f26.fl, ctx->f2.fl);
    // 0x8006BB30: lwc1        $f22, 0x48($s1)
    ctx->f22.u32l = MEM_W(ctx->r17, 0X48);
    // 0x8006BB34: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8006BB38: sub.s       $f22, $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f22.fl - ctx->f16.fl;
    // 0x8006BB3C: mul.s       $f22, $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x8006BB40: lwc1        $f18, 0x50($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X50);
    // 0x8006BB44: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8006BB48: sub.s       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x8006BB4C: mul.s       $f18, $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8006BB50: lwc1        $f14, 0x60($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X60);
    // 0x8006BB54: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8006BB58: sub.s       $f14, $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f16.fl;
    // 0x8006BB5C: mul.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x8006BB60: lwc1        $f12, 0x68($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X68);
    // 0x8006BB64: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8006BB68: sub.s       $f12, $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f16.fl;
    // 0x8006BB6C: mul.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x8006BB70: lwc1        $f4, 0x50($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X50);
    // 0x8006BB74: mov.s       $f16, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    ctx->f16.fl = ctx->f24.fl;
    // 0x8006BB78: sub.s       $f4, $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x8006BB7C: mul.s       $f4, $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8006BB80: add.s       $f28, $f28, $f10
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f28.fl = ctx->f28.fl + ctx->f10.fl;
    // 0x8006BB84: lwc1        $f2, 0x4($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8006BB88: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8006BB8C: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8006BB90: add.s       $f2, $f16, $f30
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f2.fl = ctx->f16.fl + ctx->f30.fl;
    // 0x8006BB94: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8006BB98: add.s       $f26, $f16, $f26
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f26.fl = ctx->f16.fl + ctx->f26.fl;
    // 0x8006BB9C: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8006BBA0: add.s       $f22, $f16, $f22
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f22.fl = ctx->f16.fl + ctx->f22.fl;
    // 0x8006BBA4: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8006BBA8: add.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8006BBAC: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8006BBB0: add.s       $f14, $f16, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f16.fl + ctx->f14.fl;
    // 0x8006BBB4: lwc1        $f16, 0x8($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8006BBB8: add.s       $f24, $f24, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f8.fl;
    // 0x8006BBBC: swc1        $f0, 0x64($s1)
    MEM_W(0X64, ctx->r17) = ctx->f0.u32l;
    // 0x8006BBC0: swc1        $f2, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f2.u32l;
    // 0x8006BBC4: add.s       $f12, $f16, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f12.fl;
    // 0x8006BBC8: swc1        $f26, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f26.u32l;
    // 0x8006BBCC: lwc1        $f16, 0x68($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X68);
    // 0x8006BBD0: add.s       $f20, $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f6.fl;
    // 0x8006BBD4: swc1        $f22, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->f22.u32l;
    // 0x8006BBD8: swc1        $f18, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = ctx->f18.u32l;
    // 0x8006BBDC: swc1        $f28, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = ctx->f28.u32l;
    // 0x8006BBE0: swc1        $f24, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->f24.u32l;
    // 0x8006BBE4: swc1        $f20, 0x54($s1)
    MEM_W(0X54, ctx->r17) = ctx->f20.u32l;
    // 0x8006BBE8: add.s       $f4, $f16, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8006BBEC: swc1        $f14, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->f14.u32l;
    // 0x8006BBF0: swc1        $f12, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->f12.u32l;
    // 0x8006BBF4: swc1        $f4, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->f4.u32l;
    // 0x8006BBF8: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8006BBFC: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x8006BC00: add.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x8006BC04: lwc1        $f0, 0x8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8006BC08: mov.s       $f14, $f26
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 26);
    ctx->f14.fl = ctx->f26.fl;
    // 0x8006BC0C: add.s       $f14, $f0, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x8006BC10: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8006BC14: jal         0x80067D90
    // 0x8006BC18: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    wrapAngleToCyclicRange(rdram, ctx);
        goto after_4;
    // 0x8006BC18: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_4:
    // 0x8006BC1C: lwc1        $f2, 0x4($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8006BC20: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8006BC24: lwc1        $f12, 0x24($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8006BC28: swc1        $f0, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f0.u32l;
    // 0x8006BC2C: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8006BC30: lwc1        $f14, 0x2C($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X2C);
    // 0x8006BC34: add.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x8006BC38: lwc1        $f0, 0x8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8006BC3C: add.s       $f14, $f0, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x8006BC40: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8006BC44: jal         0x80067D90
    // 0x8006BC48: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    wrapAngleToCyclicRange(rdram, ctx);
        goto after_5;
    // 0x8006BC48: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_5:
    // 0x8006BC4C: lwc1        $f2, 0x4($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8006BC50: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8006BC54: lwc1        $f12, 0x30($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X30);
    // 0x8006BC58: swc1        $f0, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->f0.u32l;
    // 0x8006BC5C: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8006BC60: lwc1        $f14, 0x38($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X38);
    // 0x8006BC64: add.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x8006BC68: lwc1        $f0, 0x8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8006BC6C: add.s       $f14, $f0, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x8006BC70: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8006BC74: jal         0x80067D90
    // 0x8006BC78: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    wrapAngleToCyclicRange(rdram, ctx);
        goto after_6;
    // 0x8006BC78: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_6:
    // 0x8006BC7C: lwc1        $f2, 0x4($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8006BC80: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8006BC84: lwc1        $f12, 0x3C($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x8006BC88: swc1        $f0, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->f0.u32l;
    // 0x8006BC8C: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8006BC90: lwc1        $f14, 0x44($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X44);
    // 0x8006BC94: add.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x8006BC98: lwc1        $f0, 0x8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8006BC9C: add.s       $f14, $f0, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x8006BCA0: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8006BCA4: jal         0x80067D90
    // 0x8006BCA8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    wrapAngleToCyclicRange(rdram, ctx);
        goto after_7;
    // 0x8006BCA8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_7:
    // 0x8006BCAC: lwc1        $f2, 0x4($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8006BCB0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8006BCB4: lwc1        $f12, 0x54($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0X54);
    // 0x8006BCB8: swc1        $f0, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->f0.u32l;
    // 0x8006BCBC: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8006BCC0: lwc1        $f14, 0x5C($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X5C);
    // 0x8006BCC4: add.s       $f12, $f0, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x8006BCC8: lwc1        $f0, 0x8($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8006BCCC: add.s       $f14, $f0, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x8006BCD0: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8006BCD4: jal         0x80067D90
    // 0x8006BCD8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    wrapAngleToCyclicRange(rdram, ctx);
        goto after_8;
    // 0x8006BCD8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    after_8:
    // 0x8006BCDC: lwc1        $f2, 0x4($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8006BCE0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8006BCE4: swc1        $f0, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f0.u32l;
    // 0x8006BCE8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8006BCEC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8006BCF0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8006BCF4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8006BCF8: ldc1        $f30, 0x58($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X58);
    // 0x8006BCFC: ldc1        $f28, 0x50($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X50);
    // 0x8006BD00: ldc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X48);
    // 0x8006BD04: ldc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X40);
    // 0x8006BD08: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x8006BD0C: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x8006BD10: jr          $ra
    // 0x8006BD14: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8006BD14: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void allocateAndInitCraftNpcContext(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BD18: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8006BD1C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8006BD20: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x8006BD24: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8006BD28: mov.s       $f22, $f14
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 14);
    ctx->f22.fl = ctx->f14.fl;
    // 0x8006BD2C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8006BD30: addu        $s0, $a2, $zero
    ctx->r16 = ADD32(ctx->r6, 0);
    // 0x8006BD34: addiu       $a0, $zero, 0x1E4
    ctx->r4 = ADD32(0, 0X1E4);
    // 0x8006BD38: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8006BD3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006BD40: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8006BD44: jal         0x80001ACC
    // 0x8006BD48: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    rs_malloc(rdram, ctx);
        goto after_0;
    // 0x8006BD48: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    after_0:
    // 0x8006BD4C: andi        $s0, $s0, 0xF
    ctx->r16 = ctx->r16 & 0XF;
    // 0x8006BD50: addu        $a0, $s0, $zero
    ctx->r4 = ADD32(ctx->r16, 0);
    // 0x8006BD54: jal         0x8006B710
    // 0x8006BD58: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    loadCraftShadowTextures(rdram, ctx);
        goto after_1;
    // 0x8006BD58: addu        $s1, $v0, $zero
    ctx->r17 = ADD32(ctx->r2, 0);
    after_1:
    // 0x8006BD5C: lui         $v1, 0x296
    ctx->r3 = S32(0X296 << 16);
    // 0x8006BD60: ori         $v1, $v1, 0x1
    ctx->r3 = ctx->r3 | 0X1;
    // 0x8006BD64: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006BD68: addiu       $s2, $v0, -0x5AD8
    ctx->r18 = ADD32(ctx->r2, -0X5AD8);
    // 0x8006BD6C: sll         $s0, $s0, 1
    ctx->r16 = S32(ctx->r16 << 1);
    // 0x8006BD70: addu        $s0, $s0, $s2
    ctx->r16 = ADD32(ctx->r16, ctx->r18);
    // 0x8006BD74: addiu       $a0, $s1, 0x6C
    ctx->r4 = ADD32(ctx->r17, 0X6C);
    // 0x8006BD78: lhu         $s0, 0x0($s0)
    ctx->r16 = MEM_HU(ctx->r16, 0X0);
    // 0x8006BD7C: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x8006BD80: sw          $v0, 0x80($s1)
    MEM_W(0X80, ctx->r17) = ctx->r2;
    // 0x8006BD84: addiu       $v0, $s1, 0xC8
    ctx->r2 = ADD32(ctx->r17, 0XC8);
    // 0x8006BD88: sw          $v0, 0x8C($s1)
    MEM_W(0X8C, ctx->r17) = ctx->r2;
    // 0x8006BD8C: addiu       $v0, $s1, 0x178
    ctx->r2 = ADD32(ctx->r17, 0X178);
    // 0x8006BD90: sw          $zero, 0x2C($s1)
    MEM_W(0X2C, ctx->r17) = 0;
    // 0x8006BD94: sw          $zero, 0x28($s1)
    MEM_W(0X28, ctx->r17) = 0;
    // 0x8006BD98: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
    // 0x8006BD9C: sw          $zero, 0x20($s1)
    MEM_W(0X20, ctx->r17) = 0;
    // 0x8006BDA0: sw          $a0, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r4;
    // 0x8006BDA4: sw          $zero, 0x34($s1)
    MEM_W(0X34, ctx->r17) = 0;
    // 0x8006BDA8: sw          $zero, 0x70($s1)
    MEM_W(0X70, ctx->r17) = 0;
    // 0x8006BDAC: sw          $zero, 0x6C($s1)
    MEM_W(0X6C, ctx->r17) = 0;
    // 0x8006BDB0: sw          $zero, 0x74($s1)
    MEM_W(0X74, ctx->r17) = 0;
    // 0x8006BDB4: sw          $v1, 0x78($s1)
    MEM_W(0X78, ctx->r17) = ctx->r3;
    // 0x8006BDB8: sw          $zero, 0x88($s1)
    MEM_W(0X88, ctx->r17) = 0;
    // 0x8006BDBC: sw          $zero, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = 0;
    // 0x8006BDC0: sw          $zero, 0x84($s1)
    MEM_W(0X84, ctx->r17) = 0;
    // 0x8006BDC4: sw          $v0, 0x90($s1)
    MEM_W(0X90, ctx->r17) = ctx->r2;
    // 0x8006BDC8: jal         0x8000A85C
    // 0x8006BDCC: sw          $zero, 0x94($s1)
    MEM_W(0X94, ctx->r17) = 0;
    clearStructPair2C30(rdram, ctx);
        goto after_2;
    // 0x8006BDCC: sw          $zero, 0x94($s1)
    MEM_W(0X94, ctx->r17) = 0;
    after_2:
    // 0x8006BDD0: addiu       $a0, $s1, 0xD8
    ctx->r4 = ADD32(ctx->r17, 0XD8);
    // 0x8006BDD4: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8006BDD8: addiu       $a1, $a1, 0x9C0
    ctx->r5 = ADD32(ctx->r5, 0X9C0);
    // 0x8006BDDC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8006BDE0: addiu       $a2, $zero, 0xA0
    ctx->r6 = ADD32(0, 0XA0);
    // 0x8006BDE4: sw          $zero, 0xCC($s1)
    MEM_W(0XCC, ctx->r17) = 0;
    // 0x8006BDE8: sw          $zero, 0xC8($s1)
    MEM_W(0XC8, ctx->r17) = 0;
    // 0x8006BDEC: sw          $a0, 0xD0($s1)
    MEM_W(0XD0, ctx->r17) = ctx->r4;
    // 0x8006BDF0: jal         0x80018EF4
    // 0x8006BDF4: sw          $v0, 0xD4($s1)
    MEM_W(0XD4, ctx->r17) = ctx->r2;
    zmemcpy(rdram, ctx);
        goto after_3;
    // 0x8006BDF4: sw          $v0, 0xD4($s1)
    MEM_W(0XD4, ctx->r17) = ctx->r2;
    after_3:
    // 0x8006BDF8: andi        $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 & 0XFFFF;
    // 0x8006BDFC: sll         $v0, $s0, 16
    ctx->r2 = S32(ctx->r16 << 16);
    // 0x8006BE00: sw          $v0, 0x158($s1)
    MEM_W(0X158, ctx->r17) = ctx->r2;
    // 0x8006BE04: sw          $v0, 0x130($s1)
    MEM_W(0X130, ctx->r17) = ctx->r2;
    // 0x8006BE08: sw          $v0, 0x108($s1)
    MEM_W(0X108, ctx->r17) = ctx->r2;
    // 0x8006BE0C: sw          $v0, 0xE0($s1)
    MEM_W(0XE0, ctx->r17) = ctx->r2;
    // 0x8006BE10: lhu         $v0, 0xA($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0XA);
    // 0x8006BE14: beq         $s0, $v0, L_8006BE2C
    if (ctx->r16 == ctx->r2) {
        // 0x8006BE18: addiu       $v0, $zero, 0x800
        ctx->r2 = ADD32(0, 0X800);
            goto L_8006BE2C;
    }
    // 0x8006BE18: addiu       $v0, $zero, 0x800
    ctx->r2 = ADD32(0, 0X800);
    // 0x8006BE1C: lhu         $v0, 0x18($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X18);
    // 0x8006BE20: bne         $s0, $v0, L_8006BE64
    if (ctx->r16 != ctx->r2) {
        // 0x8006BE24: addu        $v0, $s1, $zero
        ctx->r2 = ADD32(ctx->r17, 0);
            goto L_8006BE64;
    }
    // 0x8006BE24: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
    // 0x8006BE28: addiu       $v0, $zero, 0x800
    ctx->r2 = ADD32(0, 0X800);
L_8006BE2C:
    // 0x8006BE2C: sh          $v0, 0x168($s1)
    MEM_H(0X168, ctx->r17) = ctx->r2;
    // 0x8006BE30: sh          $v0, 0x164($s1)
    MEM_H(0X164, ctx->r17) = ctx->r2;
    // 0x8006BE34: sh          $v0, 0x148($s1)
    MEM_H(0X148, ctx->r17) = ctx->r2;
    // 0x8006BE38: sh          $v0, 0x144($s1)
    MEM_H(0X144, ctx->r17) = ctx->r2;
    // 0x8006BE3C: sh          $v0, 0x118($s1)
    MEM_H(0X118, ctx->r17) = ctx->r2;
    // 0x8006BE40: sh          $v0, 0x114($s1)
    MEM_H(0X114, ctx->r17) = ctx->r2;
    // 0x8006BE44: sh          $v0, 0xF8($s1)
    MEM_H(0XF8, ctx->r17) = ctx->r2;
    // 0x8006BE48: sh          $v0, 0xF4($s1)
    MEM_H(0XF4, ctx->r17) = ctx->r2;
    // 0x8006BE4C: addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // 0x8006BE50: sh          $v0, 0x170($s1)
    MEM_H(0X170, ctx->r17) = ctx->r2;
    // 0x8006BE54: sh          $v0, 0x16C($s1)
    MEM_H(0X16C, ctx->r17) = ctx->r2;
    // 0x8006BE58: sh          $v0, 0x120($s1)
    MEM_H(0X120, ctx->r17) = ctx->r2;
    // 0x8006BE5C: sh          $v0, 0x11C($s1)
    MEM_H(0X11C, ctx->r17) = ctx->r2;
    // 0x8006BE60: addu        $v0, $s1, $zero
    ctx->r2 = ADD32(ctx->r17, 0);
L_8006BE64:
    // 0x8006BE64: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8006BE68: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006BE6C: lwc1        $f2, -0x3684($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3684);
    // 0x8006BE70: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006BE74: lwc1        $f4, -0x3680($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3680);
    // 0x8006BE78: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006BE7C: lwc1        $f6, -0x367C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X367C);
    // 0x8006BE80: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x8006BE84: swc1        $f20, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f20.u32l;
    // 0x8006BE88: swc1        $f22, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f22.u32l;
    // 0x8006BE8C: sh          $zero, 0x1C($v0)
    MEM_H(0X1C, ctx->r2) = 0;
    // 0x8006BE90: sh          $v1, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r3;
    // 0x8006BE94: swc1        $f0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8006BE98: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8006BE9C: swc1        $f2, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f2.u32l;
    // 0x8006BEA0: swc1        $f4, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f4.u32l;
    // 0x8006BEA4: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
    // 0x8006BEA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006BEAC: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8006BEB0: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8006BEB4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8006BEB8: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8006BEBC: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8006BEC0: jr          $ra
    // 0x8006BEC4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8006BEC4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void advanceNpcOnCurvedPath(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BEC8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8006BECC: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8006BED0: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x8006BED4: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8006BED8: addu        $s4, $a1, $zero
    ctx->r20 = ADD32(ctx->r5, 0);
    // 0x8006BEDC: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8006BEE0: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x8006BEE4: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8006BEE8: addu        $s1, $a3, $zero
    ctx->r17 = ADD32(ctx->r7, 0);
    // 0x8006BEEC: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8006BEF0: beq         $s2, $zero, L_8006BFE4
    if (ctx->r18 == 0) {
        // 0x8006BEF4: sw          $s0, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r16;
            goto L_8006BFE4;
    }
    // 0x8006BEF4: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8006BEF8: lwc1        $f2, 0x1C($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X1C);
    // 0x8006BEFC: lwc1        $f0, 0x14($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8006BF00: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8006BF04: lwc1        $f4, 0x20($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X20);
    // 0x8006BF08: lwc1        $f0, 0x10($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8006BF0C: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8006BF10: lwc1        $f6, 0xC($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8006BF14: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8006BF18: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8006BF1C: sub.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x8006BF20: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8006BF24: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8006BF28: lwc1        $f12, 0x0($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8006BF2C: add.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x8006BF30: add.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x8006BF34: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x8006BF38: lwc1        $f2, 0x18($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X18);
    // 0x8006BF3C: lwc1        $f0, 0x10($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8006BF40: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8006BF44: lwc1        $f4, 0x1C($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X1C);
    // 0x8006BF48: lwc1        $f0, 0xC($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8006BF4C: mul.s       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8006BF50: lwc1        $f6, 0x14($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8006BF54: lwc1        $f0, 0x4($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8006BF58: mul.s       $f6, $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8006BF5C: sub.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x8006BF60: lwc1        $f0, 0x0($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8006BF64: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8006BF68: lwc1        $f14, 0x8($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8006BF6C: add.s       $f14, $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f6.fl;
    // 0x8006BF70: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x8006BF74: addiu       $s0, $s0, -0x7FA8
    ctx->r16 = ADD32(ctx->r16, -0X7FA8);
    // 0x8006BF78: add.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f2.fl;
    // 0x8006BF7C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8006BF80: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8006BF84: jal         0x80067D90
    // 0x8006BF88: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    wrapAngleToCyclicRange(rdram, ctx);
        goto after_0;
    // 0x8006BF88: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x8006BF8C: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8006BF90: lwc1        $f2, 0x4($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8006BF94: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8006BF98: lwc1        $f2, 0x10($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8006BF9C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8006BFA0: mul.s       $f2, $f0, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8006BFA4: lw          $v0, 0x6E08($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6E08);
    // 0x8006BFA8: lwc1        $f0, 0x10($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8006BFAC: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8006BFB0: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8006BFB4: add.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x8006BFB8: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x8006BFBC: lwc1        $f0, 0x18($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8006BFC0: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8006BFC4: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8006BFC8: add.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f0.fl;
    // 0x8006BFCC: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8006BFD0: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8006BFD4: jal         0x80067D90
    // 0x8006BFD8: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    wrapAngleToCyclicRange(rdram, ctx);
        goto after_1;
    // 0x8006BFD8: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    after_1:
    // 0x8006BFDC: j           L_8006BFFC
    // 0x8006BFE0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
        goto L_8006BFFC;
    // 0x8006BFE0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
L_8006BFE4:
    // 0x8006BFE4: lwc1        $f0, 0x60($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X60);
    // 0x8006BFE8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8006BFEC: lwc1        $f0, 0x64($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X64);
    // 0x8006BFF0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8006BFF4: lwc1        $f0, 0x68($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X68);
    // 0x8006BFF8: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
L_8006BFFC:
    // 0x8006BFFC: beq         $s3, $zero, L_8006C024
    if (ctx->r19 == 0) {
        // 0x8006C000: addu        $a0, $s4, $zero
        ctx->r4 = ADD32(ctx->r20, 0);
            goto L_8006C024;
    }
    // 0x8006C000: addu        $a0, $s4, $zero
    ctx->r4 = ADD32(ctx->r20, 0);
    // 0x8006C004: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8006C008: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8006C00C: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x8006C010: jal         0x8001DC34
    // 0x8006C014: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    transformVec3ToNpcLocalWithScale(rdram, ctx);
        goto after_2;
    // 0x8006C014: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x8006C018: andi        $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 & 0XFF;
    // 0x8006C01C: beq         $v0, $zero, L_8006C380
    if (ctx->r2 == 0) {
        // 0x8006C020: nop
    
            goto L_8006C380;
    }
    // 0x8006C020: nop

L_8006C024:
    // 0x8006C024: lhu         $v0, 0x1C($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X1C);
    // 0x8006C028: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8006C02C: sh          $v0, 0x1C($s1)
    MEM_H(0X1C, ctx->r17) = ctx->r2;
    // 0x8006C030: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8006C034: bgtz        $v0, L_8006C120
    if (SIGNED(ctx->r2) > 0) {
        // 0x8006C038: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_8006C120;
    }
    // 0x8006C038: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8006C03C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006C040: lw          $v1, -0x5ADC($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X5ADC);
    // 0x8006C044: lw          $v0, -0x7764($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7764);
    // 0x8006C048: beq         $v1, $v0, L_8006C05C
    if (ctx->r3 == ctx->r2) {
        // 0x8006C04C: lui         $t0, 0x8014
        ctx->r8 = S32(0X8014 << 16);
            goto L_8006C05C;
    }
    // 0x8006C04C: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x8006C050: sw          $v0, -0x5ADC($a0)
    MEM_W(-0X5ADC, ctx->r4) = ctx->r2;
    // 0x8006C054: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006C058: sh          $zero, -0x5AE0($v0)
    MEM_H(-0X5AE0, ctx->r2) = 0;
L_8006C05C:
    // 0x8006C05C: lhu         $v1, -0x5AE0($t0)
    ctx->r3 = MEM_HU(ctx->r8, -0X5AE0);
    // 0x8006C060: sltiu       $v0, $v1, 0x3
    ctx->r2 = ctx->r3 < 0X3 ? 1 : 0;
    // 0x8006C064: beq         $v0, $zero, L_8006C110
    if (ctx->r2 == 0) {
        // 0x8006C068: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_8006C110;
    }
    // 0x8006C068: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006C06C: lw          $v0, -0x72E4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X72E4);
    // 0x8006C070: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8006C074: lwc1        $f0, 0x4C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x8006C078: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8006C07C: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8006C080: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8006C084: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8006C088: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8006C08C: lwc1        $f0, 0x50($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X50);
    // 0x8006C090: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x8006C094: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8006C098: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8006C09C: addiu       $a2, $a2, -0x7FA8
    ctx->r6 = ADD32(ctx->r6, -0X7FA8);
    // 0x8006C0A0: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8006C0A4: lwc1        $f0, 0x54($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X54);
    // 0x8006C0A8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x8006C0AC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8006C0B0: addiu       $v0, $v1, 0x1
    ctx->r2 = ADD32(ctx->r3, 0X1);
    // 0x8006C0B4: sh          $v0, -0x5AE0($t0)
    MEM_H(-0X5AE0, ctx->r8) = ctx->r2;
    // 0x8006C0B8: jal         0x80068D5C
    // 0x8006C0BC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    sampleTerrainAtNpcPosition(rdram, ctx);
        goto after_3;
    // 0x8006C0BC: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    after_3:
    // 0x8006C0C0: beq         $v0, $zero, L_8006C0DC
    if (ctx->r2 == 0) {
        // 0x8006C0C4: nop
    
            goto L_8006C0DC;
    }
    // 0x8006C0C4: nop

    // 0x8006C0C8: lh          $v0, 0x1E($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X1E);
    // 0x8006C0CC: bltzl       $v0, L_8006C0D4
    if (SIGNED(ctx->r2) < 0) {
        // 0x8006C0D0: negu        $v0, $v0
        ctx->r2 = SUB32(0, ctx->r2);
            goto L_8006C0D4;
    }
    goto skip_0;
    // 0x8006C0D0: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    skip_0:
L_8006C0D4:
    // 0x8006C0D4: j           L_8006C0F8
    // 0x8006C0D8: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
        goto L_8006C0F8;
    // 0x8006C0D8: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_8006C0DC:
    // 0x8006C0DC: lh          $v1, 0x1E($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X1E);
    // 0x8006C0E0: lhu         $v0, 0x1E($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X1E);
    // 0x8006C0E4: bgtz        $v1, L_8006C0FC
    if (SIGNED(ctx->r3) > 0) {
        // 0x8006C0E8: nop
    
            goto L_8006C0FC;
    }
    // 0x8006C0E8: nop

    // 0x8006C0EC: beql        $v1, $zero, L_8006C0F8
    if (ctx->r3 == 0) {
        // 0x8006C0F0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8006C0F8;
    }
    goto skip_1;
    // 0x8006C0F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x8006C0F4: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_8006C0F8:
    // 0x8006C0F8: sh          $v0, 0x1E($s1)
    MEM_H(0X1E, ctx->r17) = ctx->r2;
L_8006C0FC:
    // 0x8006C0FC: jal         0x80003430
    // 0x8006C100: nop

    rand_recomp(rdram, ctx);
        goto after_4;
    // 0x8006C100: nop

    after_4:
    // 0x8006C104: andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
    // 0x8006C108: j           L_8006C11C
    // 0x8006C10C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
        goto L_8006C11C;
    // 0x8006C10C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8006C110:
    // 0x8006C110: jal         0x80003430
    // 0x8006C114: nop

    rand_recomp(rdram, ctx);
        goto after_5;
    // 0x8006C114: nop

    after_5:
    // 0x8006C118: andi        $v0, $v0, 0x7
    ctx->r2 = ctx->r2 & 0X7;
L_8006C11C:
    // 0x8006C11C: sh          $v0, 0x1C($s1)
    MEM_H(0X1C, ctx->r17) = ctx->r2;
L_8006C120:
    // 0x8006C120: lh          $v1, 0x1E($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X1E);
    // 0x8006C124: lhu         $v0, 0x1E($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X1E);
    // 0x8006C128: beq         $v1, $zero, L_8006C380
    if (ctx->r3 == 0) {
        // 0x8006C12C: nop
    
            goto L_8006C380;
    }
    // 0x8006C12C: nop

    // 0x8006C130: bgez        $v1, L_8006C150
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8006C134: addiu       $v0, $v0, 0x20
        ctx->r2 = ADD32(ctx->r2, 0X20);
            goto L_8006C150;
    }
    // 0x8006C134: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x8006C138: sh          $v0, 0x1E($s1)
    MEM_H(0X1E, ctx->r17) = ctx->r2;
    // 0x8006C13C: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8006C140: bgezl       $v0, L_8006C16C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8006C144: sh          $zero, 0x1E($s1)
        MEM_H(0X1E, ctx->r17) = 0;
            goto L_8006C16C;
    }
    goto skip_2;
    // 0x8006C144: sh          $zero, 0x1E($s1)
    MEM_H(0X1E, ctx->r17) = 0;
    skip_2:
    // 0x8006C148: j           L_8006C16C
    // 0x8006C14C: nop

        goto L_8006C16C;
    // 0x8006C14C: nop

L_8006C150:
    // 0x8006C150: sh          $v0, 0x1E($s1)
    MEM_H(0X1E, ctx->r17) = ctx->r2;
    // 0x8006C154: sll         $v0, $v0, 16
    ctx->r2 = S32(ctx->r2 << 16);
    // 0x8006C158: sra         $v0, $v0, 16
    ctx->r2 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8006C15C: slti        $v0, $v0, 0x100
    ctx->r2 = SIGNED(ctx->r2) < 0X100 ? 1 : 0;
    // 0x8006C160: bne         $v0, $zero, L_8006C16C
    if (ctx->r2 != 0) {
        // 0x8006C164: addiu       $v0, $zero, 0xFF
        ctx->r2 = ADD32(0, 0XFF);
            goto L_8006C16C;
    }
    // 0x8006C164: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8006C168: sh          $v0, 0x1E($s1)
    MEM_H(0X1E, ctx->r17) = ctx->r2;
L_8006C16C:
    // 0x8006C16C: bne         $s2, $zero, L_8006C22C
    if (ctx->r18 != 0) {
        // 0x8006C170: nop
    
            goto L_8006C22C;
    }
    // 0x8006C170: nop

    // 0x8006C174: lh          $v0, 0x1E($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X1E);
    // 0x8006C178: lwc1        $f2, 0x18($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X18);
    // 0x8006C17C: bltzl       $v0, L_8006C1B0
    if (SIGNED(ctx->r2) < 0) {
        // 0x8006C180: negu        $v0, $v0
        ctx->r2 = SUB32(0, ctx->r2);
            goto L_8006C1B0;
    }
    goto skip_3;
    // 0x8006C180: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    skip_3:
    // 0x8006C184: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8006C188: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8006C18C: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8006C190: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006C194: lwc1        $f2, -0x3678($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3678);
    // 0x8006C198: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8006C19C: nop

    // 0x8006C1A0: bc1f        L_8006C1D4
    if (!c1cs) {
        // 0x8006C1A4: nop
    
            goto L_8006C1D4;
    }
    // 0x8006C1A4: nop

    // 0x8006C1A8: j           L_8006C1E4
    // 0x8006C1AC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
        goto L_8006C1E4;
    // 0x8006C1AC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_8006C1B0:
    // 0x8006C1B0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8006C1B4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8006C1B8: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8006C1BC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006C1C0: lwc1        $f2, -0x3674($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3674);
    // 0x8006C1C4: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8006C1C8: nop

    // 0x8006C1CC: bc1tl       L_8006C1E4
    if (c1cs) {
        // 0x8006C1D0: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_8006C1E4;
    }
    goto skip_4;
    // 0x8006C1D0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_4:
L_8006C1D4:
    // 0x8006C1D4: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8006C1D8: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x8006C1DC: j           L_8006C1F8
    // 0x8006C1E0: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
        goto L_8006C1F8;
    // 0x8006C1E0: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
L_8006C1E4:
    // 0x8006C1E4: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8006C1E8: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8006C1EC: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x8006C1F0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8006C1F4: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
L_8006C1F8:
    // 0x8006C1F8: addiu       $a1, $s1, 0xC8
    ctx->r5 = ADD32(ctx->r17, 0XC8);
    // 0x8006C1FC: lw          $v0, 0xC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XC);
    // 0x8006C200: lw          $a0, 0x8($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X8);
    // 0x8006C204: beq         $v0, $zero, L_8006C358
    if (ctx->r2 == 0) {
        // 0x8006C208: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_8006C358;
    }
    // 0x8006C208: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8006C20C:
    // 0x8006C20C: sb          $a2, 0x27($a0)
    MEM_B(0X27, ctx->r4) = ctx->r6;
    // 0x8006C210: lw          $v0, 0xC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XC);
    // 0x8006C214: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006C218: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8006C21C: bne         $v0, $zero, L_8006C20C
    if (ctx->r2 != 0) {
        // 0x8006C220: addiu       $a0, $a0, 0x28
        ctx->r4 = ADD32(ctx->r4, 0X28);
            goto L_8006C20C;
    }
    // 0x8006C220: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    // 0x8006C224: j           L_8006C358
    // 0x8006C228: nop

        goto L_8006C358;
    // 0x8006C228: nop

L_8006C22C:
    // 0x8006C22C: lwc1        $f0, 0x1C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8006C230: lwc1        $f2, 0x4($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8006C234: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8006C238: lwc1        $f2, 0x14($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8006C23C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006C240: lwc1        $f4, -0x3670($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3670);
    // 0x8006C244: div.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8006C248: sub.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8006C24C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8006C250: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8006C254: nop

    // 0x8006C258: bc1t        L_8006C380
    if (c1cs) {
        // 0x8006C25C: nop
    
            goto L_8006C380;
    }
    // 0x8006C25C: nop

    // 0x8006C260: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x8006C264: nop

    // 0x8006C268: bc1tl       L_8006C270
    if (c1cs) {
        // 0x8006C26C: mov.s       $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = ctx->f4.fl;
            goto L_8006C270;
    }
    goto skip_5;
    // 0x8006C26C: mov.s       $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = ctx->f4.fl;
    skip_5:
L_8006C270:
    // 0x8006C270: lwc1        $f0, 0x18($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X18);
    // 0x8006C274: lh          $v0, 0x1E($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X1E);
    // 0x8006C278: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8006C27C: bltzl       $v0, L_8006C2B0
    if (SIGNED(ctx->r2) < 0) {
        // 0x8006C280: negu        $v0, $v0
        ctx->r2 = SUB32(0, ctx->r2);
            goto L_8006C2B0;
    }
    goto skip_6;
    // 0x8006C280: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    skip_6:
    // 0x8006C284: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8006C288: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8006C28C: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8006C290: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006C294: lwc1        $f2, -0x366C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X366C);
    // 0x8006C298: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8006C29C: nop

    // 0x8006C2A0: bc1f        L_8006C2D4
    if (!c1cs) {
        // 0x8006C2A4: nop
    
            goto L_8006C2D4;
    }
    // 0x8006C2A4: nop

    // 0x8006C2A8: j           L_8006C2E4
    // 0x8006C2AC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
        goto L_8006C2E4;
    // 0x8006C2AC: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
L_8006C2B0:
    // 0x8006C2B0: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8006C2B4: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x8006C2B8: mul.s       $f0, $f2, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8006C2BC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006C2C0: lwc1        $f2, -0x3668($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3668);
    // 0x8006C2C4: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8006C2C8: nop

    // 0x8006C2CC: bc1tl       L_8006C2E4
    if (c1cs) {
        // 0x8006C2D0: sub.s       $f0, $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_8006C2E4;
    }
    goto skip_7;
    // 0x8006C2D0: sub.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f2.fl;
    skip_7:
L_8006C2D4:
    // 0x8006C2D4: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8006C2D8: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x8006C2DC: j           L_8006C2F8
    // 0x8006C2E0: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
        goto L_8006C2F8;
    // 0x8006C2E0: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
L_8006C2E4:
    // 0x8006C2E4: lui         $v0, 0x8000
    ctx->r2 = S32(0X8000 << 16);
    // 0x8006C2E8: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8006C2EC: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x8006C2F0: or          $v1, $v1, $v0
    ctx->r3 = ctx->r3 | ctx->r2;
    // 0x8006C2F4: addu        $a2, $v1, $zero
    ctx->r6 = ADD32(ctx->r3, 0);
L_8006C2F8:
    // 0x8006C2F8: addiu       $a1, $s1, 0xC8
    ctx->r5 = ADD32(ctx->r17, 0XC8);
    // 0x8006C2FC: lw          $v0, 0xC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XC);
    // 0x8006C300: lw          $a0, 0x8($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X8);
    // 0x8006C304: beq         $v0, $zero, L_8006C324
    if (ctx->r2 == 0) {
        // 0x8006C308: addu        $v1, $zero, $zero
        ctx->r3 = ADD32(0, 0);
            goto L_8006C324;
    }
    // 0x8006C308: addu        $v1, $zero, $zero
    ctx->r3 = ADD32(0, 0);
L_8006C30C:
    // 0x8006C30C: sb          $a2, 0x27($a0)
    MEM_B(0X27, ctx->r4) = ctx->r6;
    // 0x8006C310: lw          $v0, 0xC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XC);
    // 0x8006C314: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006C318: sltu        $v0, $v1, $v0
    ctx->r2 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x8006C31C: bne         $v0, $zero, L_8006C30C
    if (ctx->r2 != 0) {
        // 0x8006C320: addiu       $a0, $a0, 0x28
        ctx->r4 = ADD32(ctx->r4, 0X28);
            goto L_8006C30C;
    }
    // 0x8006C320: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
L_8006C324:
    // 0x8006C324: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8006C328: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006C32C: lwc1        $f0, -0x3664($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3664);
    // 0x8006C330: addu        $a1, $s1, $zero
    ctx->r5 = ADD32(ctx->r17, 0);
    // 0x8006C334: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8006C338: addu        $a2, $s2, $zero
    ctx->r6 = ADD32(ctx->r18, 0);
    // 0x8006C33C: jal         0x8006B844
    // 0x8006C340: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    applyCentripetalBankingToNpcCorners(rdram, ctx);
        goto after_6;
    // 0x8006C340: sw          $a3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r7;
    after_6:
    // 0x8006C344: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8006C348: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8006C34C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8006C350: jal         0x8001CAC4
    // 0x8006C354: addiu       $a0, $s1, 0x3C
    ctx->r4 = ADD32(ctx->r17, 0X3C);
    setVec3At0x24(rdram, ctx);
        goto after_7;
    // 0x8006C354: addiu       $a0, $s1, 0x3C
    ctx->r4 = ADD32(ctx->r17, 0X3C);
    after_7:
L_8006C358:
    // 0x8006C358: beq         $s3, $zero, L_8006C380
    if (ctx->r19 == 0) {
        // 0x8006C35C: nop
    
            goto L_8006C380;
    }
    // 0x8006C35C: nop

    // 0x8006C360: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x8006C364: beq         $v1, $zero, L_8006C374
    if (ctx->r3 == 0) {
        // 0x8006C368: sw          $v1, 0x20($s1)
        MEM_W(0X20, ctx->r17) = ctx->r3;
            goto L_8006C374;
    }
    // 0x8006C368: sw          $v1, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r3;
    // 0x8006C36C: addiu       $v0, $s1, 0x20
    ctx->r2 = ADD32(ctx->r17, 0X20);
    // 0x8006C370: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_8006C374:
    // 0x8006C374: addiu       $v0, $s1, 0x20
    ctx->r2 = ADD32(ctx->r17, 0X20);
    // 0x8006C378: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x8006C37C: sw          $zero, 0x24($s1)
    MEM_W(0X24, ctx->r17) = 0;
L_8006C380:
    // 0x8006C380: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8006C384: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8006C388: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8006C38C: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8006C390: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8006C394: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8006C398: jr          $ra
    // 0x8006C39C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8006C39C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void splineWalkerCraftNpcHandler(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C3A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006C3A4: sw          $s3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r19;
    // 0x8006C3A8: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x8006C3AC: sw          $s2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r18;
    // 0x8006C3B0: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8006C3B4: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8006C3B8: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x8006C3BC: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x8006C3C0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x8006C3C4: lw          $s1, 0x4($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X4);
    // 0x8006C3C8: beq         $a1, $v0, L_8006C4A4
    if (ctx->r5 == ctx->r2) {
        // 0x8006C3CC: addu        $s2, $a2, $zero
        ctx->r18 = ADD32(ctx->r6, 0);
            goto L_8006C4A4;
    }
    // 0x8006C3CC: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x8006C3D0: slti        $v0, $a1, 0x3
    ctx->r2 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
    // 0x8006C3D4: beq         $v0, $zero, L_8006C3EC
    if (ctx->r2 == 0) {
        // 0x8006C3D8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8006C3EC;
    }
    // 0x8006C3D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006C3DC: beq         $a1, $v0, L_8006C400
    if (ctx->r5 == ctx->r2) {
        // 0x8006C3E0: nop
    
            goto L_8006C400;
    }
    // 0x8006C3E0: nop

    // 0x8006C3E4: j           L_8006C4DC
    // 0x8006C3E8: nop

        goto L_8006C4DC;
    // 0x8006C3E8: nop

L_8006C3EC:
    // 0x8006C3EC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8006C3F0: beq         $a1, $v0, L_8006C4B8
    if (ctx->r5 == ctx->r2) {
        // 0x8006C3F4: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8006C4B8;
    }
    // 0x8006C3F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006C3F8: j           L_8006C4E0
    // 0x8006C3FC: nop

        goto L_8006C4E0;
    // 0x8006C3FC: nop

L_8006C400:
    // 0x8006C400: lhu         $a2, 0xC($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0XC);
    // 0x8006C404: lwc1        $f12, 0x4($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8006C408: lwc1        $f14, 0x8($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8006C40C: jal         0x8006BD18
    // 0x8006C410: nop

    allocateAndInitCraftNpcContext(rdram, ctx);
        goto after_0;
    // 0x8006C410: nop

    after_0:
    // 0x8006C414: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8006C418: bne         $s0, $zero, L_8006C434
    if (ctx->r16 != 0) {
        // 0x8006C41C: sw          $s0, 0xC($s1)
        MEM_W(0XC, ctx->r17) = ctx->r16;
            goto L_8006C434;
    }
    // 0x8006C41C: sw          $s0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r16;
L_8006C420:
    // 0x8006C420: lhu         $a0, 0x16($s3)
    ctx->r4 = MEM_HU(ctx->r19, 0X16);
    // 0x8006C424: jal         0x8003ED74
    // 0x8006C428: nop

    destroyNpcSlotByIndex(rdram, ctx);
        goto after_1;
    // 0x8006C428: nop

    after_1:
    // 0x8006C42C: j           L_8006C4E0
    // 0x8006C430: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006C4E0;
    // 0x8006C430: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006C434:
    // 0x8006C434: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8006C438: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006C43C: lwc1        $f0, -0x3660($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3660);
    // 0x8006C440: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x8006C444: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x8006C448: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    // 0x8006C44C: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x8006C450: jal         0x8006BEC8
    // 0x8006C454: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    advanceNpcOnCurvedPath(rdram, ctx);
        goto after_2;
    // 0x8006C454: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    after_2:
    // 0x8006C458: lui         $v1, 0xF1FF
    ctx->r3 = S32(0XF1FF << 16);
    // 0x8006C45C: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x8006C460: lw          $v0, 0x78($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X78);
    // 0x8006C464: lwc1        $f0, 0x60($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X60);
    // 0x8006C468: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8006C46C: lui         $v1, 0x800
    ctx->r3 = S32(0X800 << 16);
    // 0x8006C470: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8006C474: sw          $v0, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r2;
    // 0x8006C478: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
    // 0x8006C47C: lwc1        $f0, 0x64($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X64);
    // 0x8006C480: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
    // 0x8006C484: lwc1        $f0, 0x68($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X68);
    // 0x8006C488: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006C48C: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
    // 0x8006C490: lhu         $a0, -0x6A6C($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A6C);
    // 0x8006C494: jal         0x8003E684
    // 0x8006C498: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    popNpcSlotFromTail(rdram, ctx);
        goto after_3;
    // 0x8006C498: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_3:
    // 0x8006C49C: j           L_8006C4E0
    // 0x8006C4A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006C4E0;
    // 0x8006C4A0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006C4A4:
    // 0x8006C4A4: lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC);
    // 0x8006C4A8: jal         0x80001C98
    // 0x8006C4AC: nop

    rs_free(rdram, ctx);
        goto after_4;
    // 0x8006C4AC: nop

    after_4:
    // 0x8006C4B0: j           L_8006C4E0
    // 0x8006C4B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006C4E0;
    // 0x8006C4B4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006C4B8:
    // 0x8006C4B8: jal         0x80047D40
    // 0x8006C4BC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    isNpcWithinActiveReferenceRange(rdram, ctx);
        goto after_5;
    // 0x8006C4BC: addu        $a0, $s1, $zero
    ctx->r4 = ADD32(ctx->r17, 0);
    after_5:
    // 0x8006C4C0: beq         $v0, $zero, L_8006C420
    if (ctx->r2 == 0) {
        // 0x8006C4C4: nop
    
            goto L_8006C420;
    }
    // 0x8006C4C4: nop

    // 0x8006C4C8: lw          $a0, 0x8($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X8);
    // 0x8006C4CC: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x8006C4D0: lw          $a3, 0xC($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XC);
    // 0x8006C4D4: jal         0x8006BEC8
    // 0x8006C4D8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    advanceNpcOnCurvedPath(rdram, ctx);
        goto after_6;
    // 0x8006C4D8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_6:
L_8006C4DC:
    // 0x8006C4DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006C4E0:
    // 0x8006C4E0: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8006C4E4: lw          $s3, 0x1C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X1C);
    // 0x8006C4E8: lw          $s2, 0x18($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X18);
    // 0x8006C4EC: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x8006C4F0: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8006C4F4: jr          $ra
    // 0x8006C4F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006C4F8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void stubNpcHandler(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C4FC: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8006C500: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x8006C504: addu        $s3, $a0, $zero
    ctx->r19 = ADD32(ctx->r4, 0);
    // 0x8006C508: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x8006C50C: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x8006C510: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8006C514: sw          $ra, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r31;
    // 0x8006C518: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x8006C51C: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8006C520: sdc1        $f20, 0x58($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X58, ctx->r29);
    // 0x8006C524: lw          $s1, 0x4($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X4);
    // 0x8006C528: beq         $a1, $v0, L_8006C64C
    if (ctx->r5 == ctx->r2) {
        // 0x8006C52C: addu        $s2, $a2, $zero
        ctx->r18 = ADD32(ctx->r6, 0);
            goto L_8006C64C;
    }
    // 0x8006C52C: addu        $s2, $a2, $zero
    ctx->r18 = ADD32(ctx->r6, 0);
    // 0x8006C530: slti        $v0, $a1, 0x3
    ctx->r2 = SIGNED(ctx->r5) < 0X3 ? 1 : 0;
    // 0x8006C534: beq         $v0, $zero, L_8006C54C
    if (ctx->r2 == 0) {
        // 0x8006C538: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8006C54C;
    }
    // 0x8006C538: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006C53C: beq         $a1, $v0, L_8006C568
    if (ctx->r5 == ctx->r2) {
        // 0x8006C540: nop
    
            goto L_8006C568;
    }
    // 0x8006C540: nop

    // 0x8006C544: j           L_8006C6AC
    // 0x8006C548: nop

        goto L_8006C6AC;
    // 0x8006C548: nop

L_8006C54C:
    // 0x8006C54C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8006C550: beq         $a1, $v0, L_8006C660
    if (ctx->r5 == ctx->r2) {
        // 0x8006C554: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_8006C660;
    }
    // 0x8006C554: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8006C558: beq         $a1, $v0, L_8006C698
    if (ctx->r5 == ctx->r2) {
        // 0x8006C55C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8006C698;
    }
    // 0x8006C55C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006C560: j           L_8006C6B0
    // 0x8006C564: nop

        goto L_8006C6B0;
    // 0x8006C564: nop

L_8006C568:
    // 0x8006C568: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006C56C: lwc1        $f20, -0x365C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X365C);
    // 0x8006C570: swc1        $f20, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f20.u32l;
    // 0x8006C574: lhu         $a2, 0x10($s2)
    ctx->r6 = MEM_HU(ctx->r18, 0X10);
    // 0x8006C578: lwc1        $f12, 0x8($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8006C57C: lwc1        $f14, 0xC($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8006C580: jal         0x8006BD18
    // 0x8006C584: nop

    allocateAndInitCraftNpcContext(rdram, ctx);
        goto after_0;
    // 0x8006C584: nop

    after_0:
    // 0x8006C588: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8006C58C: bne         $s0, $zero, L_8006C5A8
    if (ctx->r16 != 0) {
        // 0x8006C590: sw          $s0, 0xC($s1)
        MEM_W(0XC, ctx->r17) = ctx->r16;
            goto L_8006C5A8;
    }
    // 0x8006C590: sw          $s0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r16;
L_8006C594:
    // 0x8006C594: lhu         $a0, 0x16($s3)
    ctx->r4 = MEM_HU(ctx->r19, 0X16);
    // 0x8006C598: jal         0x8003ED74
    // 0x8006C59C: nop

    destroyNpcSlotByIndex(rdram, ctx);
        goto after_1;
    // 0x8006C59C: nop

    after_1:
    // 0x8006C5A0: j           L_8006C6B0
    // 0x8006C5A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006C6B0;
    // 0x8006C5A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006C5A8:
    // 0x8006C5A8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8006C5AC: lwc1        $f0, 0x10($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8006C5B0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006C5B4: lwc1        $f2, -0x3658($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3658);
    // 0x8006C5B8: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    // 0x8006C5BC: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x8006C5C0: swc1        $f0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f0.u32l;
    // 0x8006C5C4: swc1        $f2, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f2.u32l;
    // 0x8006C5C8: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8006C5CC: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    // 0x8006C5D0: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8006C5D4: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8006C5D8: lwc1        $f0, 0x4($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X4);
    // 0x8006C5DC: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // 0x8006C5E0: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8006C5E4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8006C5E8: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x8006C5EC: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8006C5F0: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x8006C5F4: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x8006C5F8: jal         0x8006BEC8
    // 0x8006C5FC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    advanceNpcOnCurvedPath(rdram, ctx);
        goto after_2;
    // 0x8006C5FC: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    after_2:
    // 0x8006C600: lui         $v1, 0xF1FF
    ctx->r3 = S32(0XF1FF << 16);
    // 0x8006C604: ori         $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 | 0XFFFF;
    // 0x8006C608: lw          $v0, 0x78($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X78);
    // 0x8006C60C: lwc1        $f0, 0x60($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X60);
    // 0x8006C610: and         $v0, $v0, $v1
    ctx->r2 = ctx->r2 & ctx->r3;
    // 0x8006C614: lui         $v1, 0x800
    ctx->r3 = S32(0X800 << 16);
    // 0x8006C618: or          $v0, $v0, $v1
    ctx->r2 = ctx->r2 | ctx->r3;
    // 0x8006C61C: sw          $v0, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r2;
    // 0x8006C620: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
    // 0x8006C624: lwc1        $f0, 0x64($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X64);
    // 0x8006C628: swc1        $f0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f0.u32l;
    // 0x8006C62C: lwc1        $f0, 0x68($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X68);
    // 0x8006C630: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006C634: swc1        $f0, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f0.u32l;
    // 0x8006C638: lhu         $a0, -0x6A8C($v0)
    ctx->r4 = MEM_HU(ctx->r2, -0X6A8C);
    // 0x8006C63C: jal         0x8003E684
    // 0x8006C640: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    popNpcSlotFromTail(rdram, ctx);
        goto after_3;
    // 0x8006C640: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    after_3:
    // 0x8006C644: j           L_8006C6B0
    // 0x8006C648: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006C6B0;
    // 0x8006C648: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006C64C:
    // 0x8006C64C: lw          $a0, 0xC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XC);
    // 0x8006C650: jal         0x80001C98
    // 0x8006C654: nop

    rs_free(rdram, ctx);
        goto after_4;
    // 0x8006C654: nop

    after_4:
    // 0x8006C658: j           L_8006C6B0
    // 0x8006C65C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8006C6B0;
    // 0x8006C65C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006C660:
    // 0x8006C660: lwc1        $f0, 0x0($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8006C664: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8006C668: lwc1        $f2, -0x3654($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3654);
    // 0x8006C66C: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8006C670: lwc1        $f2, 0x10($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8006C674: sub.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8006C678: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8006C67C: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x8006C680: nop

    // 0x8006C684: bc1t        L_8006C594
    if (c1cs) {
        // 0x8006C688: swc1        $f2, 0x10($s1)
        MEM_W(0X10, ctx->r17) = ctx->f2.u32l;
            goto L_8006C594;
    }
    // 0x8006C688: swc1        $f2, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f2.u32l;
    // 0x8006C68C: lw          $v0, 0xC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XC);
    // 0x8006C690: j           L_8006C6AC
    // 0x8006C694: swc1        $f2, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f2.u32l;
        goto L_8006C6AC;
    // 0x8006C694: swc1        $f2, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f2.u32l;
L_8006C698:
    // 0x8006C698: lw          $a0, 0x8($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X8);
    // 0x8006C69C: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x8006C6A0: lw          $a3, 0xC($s1)
    ctx->r7 = MEM_W(ctx->r17, 0XC);
    // 0x8006C6A4: jal         0x8006BEC8
    // 0x8006C6A8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    advanceNpcOnCurvedPath(rdram, ctx);
        goto after_5;
    // 0x8006C6A8: addu        $a2, $zero, $zero
    ctx->r6 = ADD32(0, 0);
    after_5:
L_8006C6AC:
    // 0x8006C6AC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8006C6B0:
    // 0x8006C6B0: lw          $ra, 0x50($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X50);
    // 0x8006C6B4: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x8006C6B8: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x8006C6BC: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x8006C6C0: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x8006C6C4: ldc1        $f20, 0x58($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X58);
    // 0x8006C6C8: jr          $ra
    // 0x8006C6CC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8006C6CC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void clearTrackedNpcSlots(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C6D0: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    // 0x8006C6D4: addiu       $v1, $zero, 0xD
    ctx->r3 = ADD32(0, 0XD);
    // 0x8006C6D8: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8006C6DC: addiu       $v0, $v0, -0x5AD8
    ctx->r2 = ADD32(ctx->r2, -0X5AD8);
    // 0x8006C6E0: addiu       $v0, $v0, 0x1A
    ctx->r2 = ADD32(ctx->r2, 0X1A);
L_8006C6E4:
    // 0x8006C6E4: sh          $a0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r4;
    // 0x8006C6E8: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8006C6EC: bgez        $v1, L_8006C6E4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8006C6F0: addiu       $v0, $v0, -0x2
        ctx->r2 = ADD32(ctx->r2, -0X2);
            goto L_8006C6E4;
    }
    // 0x8006C6F0: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x8006C6F4: jr          $ra
    // 0x8006C6F8: nop

    return;
    // 0x8006C6F8: nop

;}
RECOMP_FUNC void spawnSplineWalkerCraft(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C6FC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006C700: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x8006C704: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x8006C708: addiu       $a0, $a0, -0x3C60
    ctx->r4 = ADD32(ctx->r4, -0X3C60);
    // 0x8006C70C: sw          $a1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r5;
    // 0x8006C710: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8006C714: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8006C718: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8006C71C: sh          $a3, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r7;
    // 0x8006C720: sw          $ra, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r31;
    // 0x8006C724: jal         0x8003FFEC
    // 0x8006C728: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    spawnNpcOfType(rdram, ctx);
        goto after_0;
    // 0x8006C728: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    after_0:
    // 0x8006C72C: lw          $ra, 0x20($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X20);
    // 0x8006C730: jr          $ra
    // 0x8006C734: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8006C734: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void spawnStubMarkerNpc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C738: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8006C73C: lui         $a0, 0x8007
    ctx->r4 = S32(0X8007 << 16);
    // 0x8006C740: addiu       $a0, $a0, -0x3B04
    ctx->r4 = ADD32(ctx->r4, -0X3B04);
    // 0x8006C744: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x8006C748: addiu       $a1, $sp, 0x10
    ctx->r5 = ADD32(ctx->r29, 0X10);
    // 0x8006C74C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8006C750: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8006C754: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x8006C758: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x8006C75C: sw          $ra, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r31;
    // 0x8006C760: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    // 0x8006C764: swc1        $f14, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f14.u32l;
    // 0x8006C768: jal         0x8003FFEC
    // 0x8006C76C: sh          $v0, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r2;
    spawnNpcOfType(rdram, ctx);
        goto after_0;
    // 0x8006C76C: sh          $v0, 0x20($sp)
    MEM_H(0X20, ctx->r29) = ctx->r2;
    after_0:
    // 0x8006C770: lw          $ra, 0x28($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X28);
    // 0x8006C774: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x8006C778: jr          $ra
    // 0x8006C77C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8006C77C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void load_naboo_starfighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C780: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8006C784: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8006C788: addu        $s4, $a0, $zero
    ctx->r20 = ADD32(ctx->r4, 0);
    // 0x8006C78C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006C790: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x8006C794: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006C798: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x8006C79C: addiu       $s0, $s0, -0x3650
    ctx->r16 = ADD32(ctx->r16, -0X3650);
    // 0x8006C7A0: lw          $a0, 0x7CFC($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X7CFC);
    // 0x8006C7A4: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    // 0x8006C7A8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8006C7AC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8006C7B0: jal         0x80004D5C
    // 0x8006C7B4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    get_asset_size_extra(rdram, ctx);
        goto after_0;
    // 0x8006C7B4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    after_0:
    // 0x8006C7B8: addu        $s3, $v0, $zero
    ctx->r19 = ADD32(ctx->r2, 0);
    // 0x8006C7BC: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8006C7C0: jal         0x80001ACC
    // 0x8006C7C4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    rs_malloc(rdram, ctx);
        goto after_1;
    // 0x8006C7C4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // 0x8006C7C8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8006C7CC: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x8006C7D0: addu        $a3, $s0, $zero
    ctx->r7 = ADD32(ctx->r16, 0);
    // 0x8006C7D4: lw          $a0, -0x76E0($s1)
    ctx->r4 = MEM_W(ctx->r17, -0X76E0);
    // 0x8006C7D8: lw          $a2, 0x7CFC($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X7CFC);
    // 0x8006C7DC: addu        $s2, $v0, $zero
    ctx->r18 = ADD32(ctx->r2, 0);
    // 0x8006C7E0: jal         0x80004AAC
    // 0x8006C7E4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    findAssetAcrossSegments(rdram, ctx);
        goto after_2;
    // 0x8006C7E4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x8006C7E8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x8006C7EC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8006C7F0: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x8006C7F4: lw          $a0, -0x76E0($s1)
    ctx->r4 = MEM_W(ctx->r17, -0X76E0);
    // 0x8006C7F8: addu        $a3, $a1, $zero
    ctx->r7 = ADD32(ctx->r5, 0);
    // 0x8006C7FC: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x8006C800: jal         0x80004E70
    // 0x8006C804: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    setupAssetDma(rdram, ctx);
        goto after_3;
    // 0x8006C804: sw          $s2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r18;
    after_3:
    // 0x8006C808: lw          $a0, -0x76E0($s1)
    ctx->r4 = MEM_W(ctx->r17, -0X76E0);
    // 0x8006C80C: jal         0x80004C70
    // 0x8006C810: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    teardownAssetDma(rdram, ctx);
        goto after_4;
    // 0x8006C810: addu        $a1, $s0, $zero
    ctx->r5 = ADD32(ctx->r16, 0);
    after_4:
    // 0x8006C814: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    // 0x8006C818: addu        $a1, $s3, $zero
    ctx->r5 = ADD32(ctx->r19, 0);
    // 0x8006C81C: jal         0x8006AFC0
    // 0x8006C820: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    decrypt_ns_hmt(rdram, ctx);
        goto after_5;
    // 0x8006C820: addu        $a2, $s4, $zero
    ctx->r6 = ADD32(ctx->r20, 0);
    after_5:
    // 0x8006C824: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    // 0x8006C828: sltu        $v0, $s3, $a1
    ctx->r2 = ctx->r19 < ctx->r5 ? 1 : 0;
    // 0x8006C82C: bne         $v0, $zero, L_8006C8C4
    if (ctx->r2 != 0) {
        // 0x8006C830: addu        $s0, $zero, $zero
        ctx->r16 = ADD32(0, 0);
            goto L_8006C8C4;
    }
    // 0x8006C830: addu        $s0, $zero, $zero
    ctx->r16 = ADD32(0, 0);
    // 0x8006C834: andi        $v0, $a1, 0x3
    ctx->r2 = ctx->r5 & 0X3;
    // 0x8006C838: bne         $v0, $zero, L_8006C8C4
    if (ctx->r2 != 0) {
        // 0x8006C83C: addu        $v0, $s2, $a1
        ctx->r2 = ADD32(ctx->r18, ctx->r5);
            goto L_8006C8C4;
    }
    // 0x8006C83C: addu        $v0, $s2, $a1
    ctx->r2 = ADD32(ctx->r18, ctx->r5);
    // 0x8006C840: lhu         $t0, 0x0($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X0);
    // 0x8006C844: andi        $a3, $t0, 0xFFFF
    ctx->r7 = ctx->r8 & 0XFFFF;
    // 0x8006C848: sltiu       $v0, $a3, 0x29
    ctx->r2 = ctx->r7 < 0X29 ? 1 : 0;
    // 0x8006C84C: beq         $v0, $zero, L_8006C8C4
    if (ctx->r2 == 0) {
        // 0x8006C850: sltu        $v0, $s0, $a3
        ctx->r2 = ctx->r16 < ctx->r7 ? 1 : 0;
            goto L_8006C8C4;
    }
    // 0x8006C850: sltu        $v0, $s0, $a3
    ctx->r2 = ctx->r16 < ctx->r7 ? 1 : 0;
    // 0x8006C854: beq         $v0, $zero, L_8006C8B8
    if (ctx->r2 == 0) {
        // 0x8006C858: addu        $a2, $s0, $zero
        ctx->r6 = ADD32(ctx->r16, 0);
            goto L_8006C8B8;
    }
    // 0x8006C858: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
L_8006C85C:
    // 0x8006C85C: sltu        $v0, $a1, $s3
    ctx->r2 = ctx->r5 < ctx->r19 ? 1 : 0;
    // 0x8006C860: beq         $v0, $zero, L_8006C8B8
    if (ctx->r2 == 0) {
        // 0x8006C864: addu        $v0, $a1, $s2
        ctx->r2 = ADD32(ctx->r5, ctx->r18);
            goto L_8006C8B8;
    }
    // 0x8006C864: addu        $v0, $a1, $s2
    ctx->r2 = ADD32(ctx->r5, ctx->r18);
    // 0x8006C868: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x8006C86C: beq         $v1, $zero, L_8006C8B8
    if (ctx->r3 == 0) {
        // 0x8006C870: addiu       $a0, $v0, 0x4
        ctx->r4 = ADD32(ctx->r2, 0X4);
            goto L_8006C8B8;
    }
    // 0x8006C870: addiu       $a0, $v0, 0x4
    ctx->r4 = ADD32(ctx->r2, 0X4);
    // 0x8006C874: andi        $v0, $v1, 0x3
    ctx->r2 = ctx->r3 & 0X3;
    // 0x8006C878: bne         $v0, $zero, L_8006C8B8
    if (ctx->r2 != 0) {
        // 0x8006C87C: sltu        $v0, $s3, $v1
        ctx->r2 = ctx->r19 < ctx->r3 ? 1 : 0;
            goto L_8006C8B8;
    }
    // 0x8006C87C: sltu        $v0, $s3, $v1
    ctx->r2 = ctx->r19 < ctx->r3 ? 1 : 0;
    // 0x8006C880: bne         $v0, $zero, L_8006C8BC
    if (ctx->r2 != 0) {
        // 0x8006C884: andi        $v0, $a2, 0xFFFF
        ctx->r2 = ctx->r6 & 0XFFFF;
            goto L_8006C8BC;
    }
    // 0x8006C884: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // 0x8006C888: lw          $v1, 0x24($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X24);
    // 0x8006C88C: beq         $v1, $zero, L_8006C8B8
    if (ctx->r3 == 0) {
        // 0x8006C890: andi        $v0, $v1, 0x3
        ctx->r2 = ctx->r3 & 0X3;
            goto L_8006C8B8;
    }
    // 0x8006C890: andi        $v0, $v1, 0x3
    ctx->r2 = ctx->r3 & 0X3;
    // 0x8006C894: bne         $v0, $zero, L_8006C8B8
    if (ctx->r2 != 0) {
        // 0x8006C898: sltu        $v0, $s3, $v1
        ctx->r2 = ctx->r19 < ctx->r3 ? 1 : 0;
            goto L_8006C8B8;
    }
    // 0x8006C898: sltu        $v0, $s3, $v1
    ctx->r2 = ctx->r19 < ctx->r3 ? 1 : 0;
    // 0x8006C89C: bne         $v0, $zero, L_8006C8BC
    if (ctx->r2 != 0) {
        // 0x8006C8A0: andi        $v0, $a2, 0xFFFF
        ctx->r2 = ctx->r6 & 0XFFFF;
            goto L_8006C8BC;
    }
    // 0x8006C8A0: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // 0x8006C8A4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8006C8A8: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
    // 0x8006C8AC: sltu        $v0, $v0, $a3
    ctx->r2 = ctx->r2 < ctx->r7 ? 1 : 0;
    // 0x8006C8B0: bne         $v0, $zero, L_8006C85C
    if (ctx->r2 != 0) {
        // 0x8006C8B4: addiu       $a1, $a1, 0x34
        ctx->r5 = ADD32(ctx->r5, 0X34);
            goto L_8006C85C;
    }
    // 0x8006C8B4: addiu       $a1, $a1, 0x34
    ctx->r5 = ADD32(ctx->r5, 0X34);
L_8006C8B8:
    // 0x8006C8B8: andi        $v0, $a2, 0xFFFF
    ctx->r2 = ctx->r6 & 0XFFFF;
L_8006C8BC:
    // 0x8006C8BC: beql        $v0, $t0, L_8006C8C4
    if (ctx->r2 == ctx->r8) {
        // 0x8006C8C0: addu        $s0, $s4, $zero
        ctx->r16 = ADD32(ctx->r20, 0);
            goto L_8006C8C4;
    }
    goto skip_0;
    // 0x8006C8C0: addu        $s0, $s4, $zero
    ctx->r16 = ADD32(ctx->r20, 0);
    skip_0:
L_8006C8C4:
    // 0x8006C8C4: jal         0x80001C98
    // 0x8006C8C8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    rs_free(rdram, ctx);
        goto after_6;
    // 0x8006C8C8: addu        $a0, $s2, $zero
    ctx->r4 = ADD32(ctx->r18, 0);
    after_6:
    // 0x8006C8CC: addu        $v0, $s0, $zero
    ctx->r2 = ADD32(ctx->r16, 0);
    // 0x8006C8D0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8006C8D4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8006C8D8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8006C8DC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006C8E0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006C8E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006C8E8: jr          $ra
    // 0x8006C8EC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8006C8EC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void getCraftRecordByIdx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C8F0: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8006C8F4: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8006C8F8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8006C8FC: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8006C900: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8006C904: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8006C908: addiu       $v1, $v1, 0x7DBC
    ctx->r3 = ADD32(ctx->r3, 0X7DBC);
    // 0x8006C90C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006C910: jr          $ra
    // 0x8006C914: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x8006C914: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
;}
RECOMP_FUNC void func_8006C918(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C918: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8006C91C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8006C920: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8006C924: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8006C928: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8006C92C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8006C930: addiu       $v1, $v1, 0x7DBC
    ctx->r3 = ADD32(ctx->r3, 0X7DBC);
    // 0x8006C934: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006C938: jr          $ra
    // 0x8006C93C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    return;
    // 0x8006C93C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
;}
RECOMP_FUNC void getPlayerVehicleId(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C940: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8006C944: addiu       $v1, $v1, 0x7DB8
    ctx->r3 = ADD32(ctx->r3, 0X7DB8);
    // 0x8006C948: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8006C94C: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8006C950: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8006C954: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8006C958: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8006C95C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006C960: lw          $v0, 0x294($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X294);
    // 0x8006C964: jr          $ra
    // 0x8006C968: nop

    return;
    // 0x8006C968: nop

;}
RECOMP_FUNC void func_8006C96C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006C96C: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x8006C970: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8006C974: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8006C978: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8006C97C: sll         $v0, $v0, 5
    ctx->r2 = S32(ctx->r2 << 5);
    // 0x8006C980: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8006C984: addiu       $v1, $v1, 0x7DBC
    ctx->r3 = ADD32(ctx->r3, 0X7DBC);
    // 0x8006C988: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8006C98C: jr          $ra
    // 0x8006C990: addiu       $v0, $v0, 0x34
    ctx->r2 = ADD32(ctx->r2, 0X34);
    return;
    // 0x8006C990: addiu       $v0, $v0, 0x34
    ctx->r2 = ADD32(ctx->r2, 0X34);
;}
