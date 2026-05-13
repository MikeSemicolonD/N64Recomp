#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void lv9_progressObjective_0x1A(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105960: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105964: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    // 0x80105968: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8010596C: jal         0x800C75EC
    // 0x80105970: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    increaseObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x80105970: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80105974: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105978: lui         $a1, 0x4198
    ctx->r5 = S32(0X4198 << 16);
    // 0x8010597C: jal         0x800C7864
    // 0x80105980: addiu       $a0, $a0, 0x5990
    ctx->r4 = ADD32(ctx->r4, 0X5990);
    addTimerHandleWrapper(rdram, ctx);
        goto after_1;
    // 0x80105980: addiu       $a0, $a0, 0x5990
    ctx->r4 = ADD32(ctx->r4, 0X5990);
    after_1:
    // 0x80105984: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80105988: jr          $ra
    // 0x8010598C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8010598C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void setObjBoolTrue_0x16(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105990: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105994: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x80105998: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8010599C: jal         0x800C7540
    // 0x801059A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_0;
    // 0x801059A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x801059A4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801059A8: jr          $ra
    // 0x801059AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801059AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv9_scheduleTimerAndDialogueC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801059B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801059B4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x801059B8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x801059BC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801059C0: jal         0x800C7864
    // 0x801059C4: addiu       $a0, $a0, 0x59E0
    ctx->r4 = ADD32(ctx->r4, 0X59E0);
    addTimerHandleWrapper(rdram, ctx);
        goto after_0;
    // 0x801059C4: addiu       $a0, $a0, 0x59E0
    ctx->r4 = ADD32(ctx->r4, 0X59E0);
    after_0:
    // 0x801059C8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x801059CC: jal         0x800C7D1C
    // 0x801059D0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x801059D0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_1:
    // 0x801059D4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801059D8: jr          $ra
    // 0x801059DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801059DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv9_progressObjective_0x1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801059E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801059E4: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x801059E8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801059EC: jal         0x800C75EC
    // 0x801059F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    increaseObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x801059F0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x801059F4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x801059F8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x801059FC: jal         0x800C7864
    // 0x80105A00: addiu       $a0, $a0, 0x5A10
    ctx->r4 = ADD32(ctx->r4, 0X5A10);
    addTimerHandleWrapper(rdram, ctx);
        goto after_1;
    // 0x80105A00: addiu       $a0, $a0, 0x5A10
    ctx->r4 = ADD32(ctx->r4, 0X5A10);
    after_1:
    // 0x80105A04: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80105A08: jr          $ra
    // 0x80105A0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80105A0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv9_progressObjective_0x1F(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105A10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105A14: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x80105A18: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80105A1C: jal         0x800C75EC
    // 0x80105A20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    increaseObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x80105A20: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80105A24: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105A28: lui         $a1, 0x41F0
    ctx->r5 = S32(0X41F0 << 16);
    // 0x80105A2C: jal         0x800C7864
    // 0x80105A30: addiu       $a0, $a0, 0x5A40
    ctx->r4 = ADD32(ctx->r4, 0X5A40);
    addTimerHandleWrapper(rdram, ctx);
        goto after_1;
    // 0x80105A30: addiu       $a0, $a0, 0x5A40
    ctx->r4 = ADD32(ctx->r4, 0X5A40);
    after_1:
    // 0x80105A34: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80105A38: jr          $ra
    // 0x80105A3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80105A3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv9_progressObjective_0x1D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105A40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105A44: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x80105A48: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80105A4C: jal         0x800C75EC
    // 0x80105A50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    increaseObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x80105A50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80105A54: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105A58: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80105A5C: jal         0x800C7864
    // 0x80105A60: addiu       $a0, $a0, 0x5A70
    ctx->r4 = ADD32(ctx->r4, 0X5A70);
    addTimerHandleWrapper(rdram, ctx);
        goto after_1;
    // 0x80105A60: addiu       $a0, $a0, 0x5A70
    ctx->r4 = ADD32(ctx->r4, 0X5A70);
    after_1:
    // 0x80105A64: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80105A68: jr          $ra
    // 0x80105A6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80105A6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv9_progressObjective_0x1E(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105A70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105A74: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x80105A78: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80105A7C: jal         0x800C75EC
    // 0x80105A80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    increaseObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x80105A80: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80105A84: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105A88: lui         $a1, 0x4218
    ctx->r5 = S32(0X4218 << 16);
    // 0x80105A8C: jal         0x800C7864
    // 0x80105A90: addiu       $a0, $a0, 0x5AA0
    ctx->r4 = ADD32(ctx->r4, 0X5AA0);
    addTimerHandleWrapper(rdram, ctx);
        goto after_1;
    // 0x80105A90: addiu       $a0, $a0, 0x5AA0
    ctx->r4 = ADD32(ctx->r4, 0X5AA0);
    after_1:
    // 0x80105A94: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80105A98: jr          $ra
    // 0x80105A9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80105A9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void setObjBoolTrue_0x17(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105AA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105AA4: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x80105AA8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80105AAC: jal         0x800C7540
    // 0x80105AB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_0;
    // 0x80105AB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80105AB4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80105AB8: jr          $ra
    // 0x80105ABC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80105ABC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice2_0x299(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105AC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105AC4: addiu       $a0, $zero, 0x299
    ctx->r4 = ADD32(0, 0X299);
    // 0x80105AC8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80105ACC: jal         0x800C7D1C
    // 0x80105AD0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80105AD0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x80105AD4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80105AD8: jr          $ra
    // 0x80105ADC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80105ADC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv9_setObjectiveBoolean_0x78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105AE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105AE4: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    // 0x80105AE8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80105AEC: jal         0x800C7540
    // 0x80105AF0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_0;
    // 0x80105AF0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80105AF4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80105AF8: jr          $ra
    // 0x80105AFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80105AFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv9_objectiveSlot1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105B00: jr          $ra
    // 0x80105B04: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80105B04: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void lv9_calculateFriendliesSaved(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105B08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105B0C: addiu       $a0, $zero, 0x25
    ctx->r4 = ADD32(0, 0X25);
    // 0x80105B10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80105B14: jal         0x800C761C
    // 0x80105B18: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    getObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x80105B18: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x80105B1C: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    // 0x80105B20: jal         0x800C761C
    // 0x80105B24: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    getObjectiveCount(rdram, ctx);
        goto after_1;
    // 0x80105B24: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_1:
    // 0x80105B28: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80105B2C: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x80105B30: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    // 0x80105B34: subu        $a0, $a0, $s0
    ctx->r4 = SUB32(ctx->r4, ctx->r16);
    // 0x80105B38: jal         0x800C77B0
    // 0x80105B3C: sw          $s0, -0x2F20($v1)
    MEM_W(-0X2F20, ctx->r3) = ctx->r16;
    setFriendliesSaved(rdram, ctx);
        goto after_2;
    // 0x80105B3C: sw          $s0, -0x2F20($v1)
    MEM_W(-0X2F20, ctx->r3) = ctx->r16;
    after_2:
    // 0x80105B40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80105B44: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80105B48: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80105B4C: jr          $ra
    // 0x80105B50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80105B50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void fake_func_80105B54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void lva_initializeObjectTracking(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105B60: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80105B64: lwc1        $f12, -0x67A0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X67A0);
    // 0x80105B68: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80105B6C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80105B70: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80105B74: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80105B78: jal         0x800C7CEC
    // 0x80105B7C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    setLevelObjectTrackingScalar(rdram, ctx);
        goto after_0;
    // 0x80105B7C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80105B80: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105B84: addiu       $a0, $a0, 0x5ED0
    ctx->r4 = ADD32(ctx->r4, 0X5ED0);
    // 0x80105B88: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80105B8C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80105B90: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    // 0x80105B94: addiu       $s0, $zero, 0x9
    ctx->r16 = ADD32(0, 0X9);
    // 0x80105B98: jal         0x800C7830
    // 0x80105B9C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_1;
    // 0x80105B9C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_1:
    // 0x80105BA0: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105BA4: addiu       $a0, $a0, 0x5EF8
    ctx->r4 = ADD32(ctx->r4, 0X5EF8);
    // 0x80105BA8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80105BAC: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80105BB0: addiu       $a3, $zero, 0x31
    ctx->r7 = ADD32(0, 0X31);
    // 0x80105BB4: addiu       $s1, $zero, 0x7
    ctx->r17 = ADD32(0, 0X7);
    // 0x80105BB8: jal         0x800C7830
    // 0x80105BBC: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_2;
    // 0x80105BBC: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_2:
    // 0x80105BC0: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105BC4: addiu       $a0, $a0, 0x5F20
    ctx->r4 = ADD32(ctx->r4, 0X5F20);
    // 0x80105BC8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80105BCC: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80105BD0: addiu       $a3, $zero, 0x35
    ctx->r7 = ADD32(0, 0X35);
    // 0x80105BD4: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x80105BD8: jal         0x800C7830
    // 0x80105BDC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_3;
    // 0x80105BDC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_3:
    // 0x80105BE0: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105BE4: addiu       $a0, $a0, 0x5F48
    ctx->r4 = ADD32(ctx->r4, 0X5F48);
    // 0x80105BE8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80105BEC: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80105BF0: addiu       $a3, $zero, 0x36
    ctx->r7 = ADD32(0, 0X36);
    // 0x80105BF4: addiu       $s2, $zero, 0xC
    ctx->r18 = ADD32(0, 0XC);
    // 0x80105BF8: jal         0x800C7830
    // 0x80105BFC: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_4;
    // 0x80105BFC: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_4:
    // 0x80105C00: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105C04: addiu       $a0, $a0, 0x5F70
    ctx->r4 = ADD32(ctx->r4, 0X5F70);
    // 0x80105C08: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80105C0C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80105C10: addiu       $a3, $zero, 0x37
    ctx->r7 = ADD32(0, 0X37);
    // 0x80105C14: jal         0x800C7830
    // 0x80105C18: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_5;
    // 0x80105C18: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_5:
    // 0x80105C1C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105C20: addiu       $a0, $a0, 0x5F98
    ctx->r4 = ADD32(ctx->r4, 0X5F98);
    // 0x80105C24: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80105C28: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80105C2C: addiu       $a3, $zero, 0x38
    ctx->r7 = ADD32(0, 0X38);
    // 0x80105C30: addiu       $v0, $zero, 0x6
    ctx->r2 = ADD32(0, 0X6);
    // 0x80105C34: jal         0x800C7830
    // 0x80105C38: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_6;
    // 0x80105C38: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_6:
    // 0x80105C3C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105C40: addiu       $a0, $a0, 0x5FC0
    ctx->r4 = ADD32(ctx->r4, 0X5FC0);
    // 0x80105C44: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80105C48: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80105C4C: addiu       $a3, $zero, 0x32
    ctx->r7 = ADD32(0, 0X32);
    // 0x80105C50: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80105C54: jal         0x800C7830
    // 0x80105C58: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_7;
    // 0x80105C58: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_7:
    // 0x80105C5C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105C60: addiu       $a0, $a0, 0x5FDC
    ctx->r4 = ADD32(ctx->r4, 0X5FDC);
    // 0x80105C64: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80105C68: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80105C6C: addiu       $a3, $zero, 0x37
    ctx->r7 = ADD32(0, 0X37);
    // 0x80105C70: addiu       $v0, $zero, 0x18
    ctx->r2 = ADD32(0, 0X18);
    // 0x80105C74: jal         0x800C7830
    // 0x80105C78: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_8;
    // 0x80105C78: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_8:
    // 0x80105C7C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105C80: addiu       $a0, $a0, 0x5FF8
    ctx->r4 = ADD32(ctx->r4, 0X5FF8);
    // 0x80105C84: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80105C88: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80105C8C: addiu       $a3, $zero, 0x33
    ctx->r7 = ADD32(0, 0X33);
    // 0x80105C90: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80105C94: jal         0x800C7830
    // 0x80105C98: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_9;
    // 0x80105C98: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_9:
    // 0x80105C9C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105CA0: addiu       $a0, $a0, 0x6050
    ctx->r4 = ADD32(ctx->r4, 0X6050);
    // 0x80105CA4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80105CA8: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80105CAC: addiu       $a3, $zero, 0x33
    ctx->r7 = ADD32(0, 0X33);
    // 0x80105CB0: jal         0x800C7830
    // 0x80105CB4: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_10;
    // 0x80105CB4: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_10:
    // 0x80105CB8: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105CBC: addiu       $a0, $a0, 0x6034
    ctx->r4 = ADD32(ctx->r4, 0X6034);
    // 0x80105CC0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80105CC4: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80105CC8: addiu       $a3, $zero, 0x33
    ctx->r7 = ADD32(0, 0X33);
    // 0x80105CCC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80105CD0: jal         0x800C7830
    // 0x80105CD4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_11;
    // 0x80105CD4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_11:
    // 0x80105CD8: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105CDC: addiu       $a0, $a0, 0x6088
    ctx->r4 = ADD32(ctx->r4, 0X6088);
    // 0x80105CE0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80105CE4: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80105CE8: addiu       $a3, $zero, 0x28
    ctx->r7 = ADD32(0, 0X28);
    // 0x80105CEC: jal         0x800C7830
    // 0x80105CF0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_12;
    // 0x80105CF0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_12:
    // 0x80105CF4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105CF8: addiu       $a0, $a0, 0x606C
    ctx->r4 = ADD32(ctx->r4, 0X606C);
    // 0x80105CFC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80105D00: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80105D04: addiu       $a3, $zero, 0x29
    ctx->r7 = ADD32(0, 0X29);
    // 0x80105D08: jal         0x800C7830
    // 0x80105D0C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_13;
    // 0x80105D0C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_13:
    // 0x80105D10: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105D14: addiu       $a0, $a0, 0x60B4
    ctx->r4 = ADD32(ctx->r4, 0X60B4);
    // 0x80105D18: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80105D1C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80105D20: addiu       $a3, $zero, 0x2D
    ctx->r7 = ADD32(0, 0X2D);
    // 0x80105D24: jal         0x800C7830
    // 0x80105D28: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_14;
    // 0x80105D28: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_14:
    // 0x80105D2C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105D30: addiu       $a0, $a0, 0x6014
    ctx->r4 = ADD32(ctx->r4, 0X6014);
    // 0x80105D34: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80105D38: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80105D3C: addiu       $a3, $zero, 0x36
    ctx->r7 = ADD32(0, 0X36);
    // 0x80105D40: jal         0x800C7830
    // 0x80105D44: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_15;
    // 0x80105D44: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    after_15:
    // 0x80105D48: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105D4C: addiu       $a0, $a0, 0x5E28
    ctx->r4 = ADD32(ctx->r4, 0X5E28);
    // 0x80105D50: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80105D54: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80105D58: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    // 0x80105D5C: jal         0x800C7830
    // 0x80105D60: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_16;
    // 0x80105D60: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_16:
    // 0x80105D64: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105D68: addiu       $a0, $a0, 0x5E44
    ctx->r4 = ADD32(ctx->r4, 0X5E44);
    // 0x80105D6C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80105D70: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80105D74: addiu       $a3, $zero, 0x65
    ctx->r7 = ADD32(0, 0X65);
    // 0x80105D78: jal         0x800C7830
    // 0x80105D7C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_17;
    // 0x80105D7C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_17:
    // 0x80105D80: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105D84: addiu       $a0, $a0, 0x5E60
    ctx->r4 = ADD32(ctx->r4, 0X5E60);
    // 0x80105D88: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80105D8C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80105D90: addiu       $a3, $zero, 0x66
    ctx->r7 = ADD32(0, 0X66);
    // 0x80105D94: jal         0x800C7830
    // 0x80105D98: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_18;
    // 0x80105D98: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_18:
    // 0x80105D9C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105DA0: addiu       $a0, $a0, 0x5E7C
    ctx->r4 = ADD32(ctx->r4, 0X5E7C);
    // 0x80105DA4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80105DA8: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80105DAC: addiu       $a3, $zero, 0x67
    ctx->r7 = ADD32(0, 0X67);
    // 0x80105DB0: jal         0x800C7830
    // 0x80105DB4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_19;
    // 0x80105DB4: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_19:
    // 0x80105DB8: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105DBC: addiu       $a0, $a0, 0x5E98
    ctx->r4 = ADD32(ctx->r4, 0X5E98);
    // 0x80105DC0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80105DC4: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80105DC8: addiu       $a3, $zero, 0x68
    ctx->r7 = ADD32(0, 0X68);
    // 0x80105DCC: jal         0x800C7830
    // 0x80105DD0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_20;
    // 0x80105DD0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_20:
    // 0x80105DD4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105DD8: addiu       $a0, $a0, 0x5EB4
    ctx->r4 = ADD32(ctx->r4, 0X5EB4);
    // 0x80105DDC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80105DE0: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80105DE4: addiu       $a3, $zero, 0x69
    ctx->r7 = ADD32(0, 0X69);
    // 0x80105DE8: jal         0x800C7830
    // 0x80105DEC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_21;
    // 0x80105DEC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_21:
    // 0x80105DF0: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80105DF4: addiu       $a0, $a0, 0x60E0
    ctx->r4 = ADD32(ctx->r4, 0X60E0);
    // 0x80105DF8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80105DFC: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80105E00: addiu       $a3, $zero, 0x74
    ctx->r7 = ADD32(0, 0X74);
    // 0x80105E04: jal         0x800C7830
    // 0x80105E08: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_22;
    // 0x80105E08: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_22:
    // 0x80105E0C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80105E10: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80105E14: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80105E18: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80105E1C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80105E20: jr          $ra
    // 0x80105E24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80105E24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void playVoice_0x11F(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105E28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105E2C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80105E30: jal         0x800C7CF8
    // 0x80105E34: addiu       $a0, $zero, 0x11F
    ctx->r4 = ADD32(0, 0X11F);
    playObjectiveVoiceLine1(rdram, ctx);
        goto after_0;
    // 0x80105E34: addiu       $a0, $zero, 0x11F
    ctx->r4 = ADD32(0, 0X11F);
    after_0:
    // 0x80105E38: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80105E3C: jr          $ra
    // 0x80105E40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80105E40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice_0x217(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105E44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105E48: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80105E4C: jal         0x800C7CF8
    // 0x80105E50: addiu       $a0, $zero, 0x217
    ctx->r4 = ADD32(0, 0X217);
    playObjectiveVoiceLine1(rdram, ctx);
        goto after_0;
    // 0x80105E50: addiu       $a0, $zero, 0x217
    ctx->r4 = ADD32(0, 0X217);
    after_0:
    // 0x80105E54: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80105E58: jr          $ra
    // 0x80105E5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80105E5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice_0xAA(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105E60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105E64: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80105E68: jal         0x800C7CF8
    // 0x80105E6C: addiu       $a0, $zero, 0xAA
    ctx->r4 = ADD32(0, 0XAA);
    playObjectiveVoiceLine1(rdram, ctx);
        goto after_0;
    // 0x80105E6C: addiu       $a0, $zero, 0xAA
    ctx->r4 = ADD32(0, 0XAA);
    after_0:
    // 0x80105E70: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80105E74: jr          $ra
    // 0x80105E78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80105E78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice_0xB6(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105E7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105E80: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80105E84: jal         0x800C7CF8
    // 0x80105E88: addiu       $a0, $zero, 0xB6
    ctx->r4 = ADD32(0, 0XB6);
    playObjectiveVoiceLine1(rdram, ctx);
        goto after_0;
    // 0x80105E88: addiu       $a0, $zero, 0xB6
    ctx->r4 = ADD32(0, 0XB6);
    after_0:
    // 0x80105E8C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80105E90: jr          $ra
    // 0x80105E94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80105E94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice_0xC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105E98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105E9C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80105EA0: jal         0x800C7CF8
    // 0x80105EA4: addiu       $a0, $zero, 0xC4
    ctx->r4 = ADD32(0, 0XC4);
    playObjectiveVoiceLine1(rdram, ctx);
        goto after_0;
    // 0x80105EA4: addiu       $a0, $zero, 0xC4
    ctx->r4 = ADD32(0, 0XC4);
    after_0:
    // 0x80105EA8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80105EAC: jr          $ra
    // 0x80105EB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80105EB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice_0xAA_v2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105EB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105EB8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80105EBC: jal         0x800C7CF8
    // 0x80105EC0: addiu       $a0, $zero, 0xAA
    ctx->r4 = ADD32(0, 0XAA);
    playObjectiveVoiceLine1(rdram, ctx);
        goto after_0;
    // 0x80105EC0: addiu       $a0, $zero, 0xAA
    ctx->r4 = ADD32(0, 0XAA);
    after_0:
    // 0x80105EC4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80105EC8: jr          $ra
    // 0x80105ECC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80105ECC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice_0x21E(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105ED0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105ED4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80105ED8: jal         0x800C7CF8
    // 0x80105EDC: addiu       $a0, $zero, 0x21E
    ctx->r4 = ADD32(0, 0X21E);
    playObjectiveVoiceLine1(rdram, ctx);
        goto after_0;
    // 0x80105EDC: addiu       $a0, $zero, 0x21E
    ctx->r4 = ADD32(0, 0X21E);
    after_0:
    // 0x80105EE0: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    // 0x80105EE4: jal         0x800C75EC
    // 0x80105EE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    increaseObjectiveCount(rdram, ctx);
        goto after_1;
    // 0x80105EE8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80105EEC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80105EF0: jr          $ra
    // 0x80105EF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80105EF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice_0x21D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105EF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105EFC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80105F00: jal         0x800C7CF8
    // 0x80105F04: addiu       $a0, $zero, 0x21D
    ctx->r4 = ADD32(0, 0X21D);
    playObjectiveVoiceLine1(rdram, ctx);
        goto after_0;
    // 0x80105F04: addiu       $a0, $zero, 0x21D
    ctx->r4 = ADD32(0, 0X21D);
    after_0:
    // 0x80105F08: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    // 0x80105F0C: jal         0x800C75EC
    // 0x80105F10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    increaseObjectiveCount(rdram, ctx);
        goto after_1;
    // 0x80105F10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80105F14: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80105F18: jr          $ra
    // 0x80105F1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80105F1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice_0xE5(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105F20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105F24: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80105F28: jal         0x800C7CF8
    // 0x80105F2C: addiu       $a0, $zero, 0xE5
    ctx->r4 = ADD32(0, 0XE5);
    playObjectiveVoiceLine1(rdram, ctx);
        goto after_0;
    // 0x80105F2C: addiu       $a0, $zero, 0xE5
    ctx->r4 = ADD32(0, 0XE5);
    after_0:
    // 0x80105F30: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    // 0x80105F34: jal         0x800C75EC
    // 0x80105F38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    increaseObjectiveCount(rdram, ctx);
        goto after_1;
    // 0x80105F38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80105F3C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80105F40: jr          $ra
    // 0x80105F44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80105F44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv9_progressWithDialogueA(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105F48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105F4C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80105F50: jal         0x800C7CF8
    // 0x80105F54: addiu       $a0, $zero, 0x21E
    ctx->r4 = ADD32(0, 0X21E);
    playObjectiveVoiceLine1(rdram, ctx);
        goto after_0;
    // 0x80105F54: addiu       $a0, $zero, 0x21E
    ctx->r4 = ADD32(0, 0X21E);
    after_0:
    // 0x80105F58: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    // 0x80105F5C: jal         0x800C75EC
    // 0x80105F60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    increaseObjectiveCount(rdram, ctx);
        goto after_1;
    // 0x80105F60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80105F64: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80105F68: jr          $ra
    // 0x80105F6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80105F6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice_0xB1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105F70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105F74: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80105F78: jal         0x800C7CF8
    // 0x80105F7C: addiu       $a0, $zero, 0xB1
    ctx->r4 = ADD32(0, 0XB1);
    playObjectiveVoiceLine1(rdram, ctx);
        goto after_0;
    // 0x80105F7C: addiu       $a0, $zero, 0xB1
    ctx->r4 = ADD32(0, 0XB1);
    after_0:
    // 0x80105F80: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    // 0x80105F84: jal         0x800C75EC
    // 0x80105F88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    increaseObjectiveCount(rdram, ctx);
        goto after_1;
    // 0x80105F88: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80105F8C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80105F90: jr          $ra
    // 0x80105F94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80105F94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lv9_progressWithDialogueB(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105F98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105F9C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80105FA0: jal         0x800C7CF8
    // 0x80105FA4: addiu       $a0, $zero, 0x21D
    ctx->r4 = ADD32(0, 0X21D);
    playObjectiveVoiceLine1(rdram, ctx);
        goto after_0;
    // 0x80105FA4: addiu       $a0, $zero, 0x21D
    ctx->r4 = ADD32(0, 0X21D);
    after_0:
    // 0x80105FA8: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    // 0x80105FAC: jal         0x800C75EC
    // 0x80105FB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    increaseObjectiveCount(rdram, ctx);
        goto after_1;
    // 0x80105FB0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80105FB4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80105FB8: jr          $ra
    // 0x80105FBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80105FBC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice_0x21C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105FC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105FC4: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80105FC8: jal         0x800C7CF8
    // 0x80105FCC: addiu       $a0, $zero, 0x21C
    ctx->r4 = ADD32(0, 0X21C);
    playObjectiveVoiceLine1(rdram, ctx);
        goto after_0;
    // 0x80105FCC: addiu       $a0, $zero, 0x21C
    ctx->r4 = ADD32(0, 0X21C);
    after_0:
    // 0x80105FD0: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80105FD4: jr          $ra
    // 0x80105FD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80105FD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice_0x259(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105FDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105FE0: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80105FE4: jal         0x800C7CF8
    // 0x80105FE8: addiu       $a0, $zero, 0x259
    ctx->r4 = ADD32(0, 0X259);
    playObjectiveVoiceLine1(rdram, ctx);
        goto after_0;
    // 0x80105FE8: addiu       $a0, $zero, 0x259
    ctx->r4 = ADD32(0, 0X259);
    after_0:
    // 0x80105FEC: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80105FF0: jr          $ra
    // 0x80105FF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80105FF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice_0xEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105FF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105FFC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80106000: jal         0x800C7CF8
    // 0x80106004: addiu       $a0, $zero, 0xEC
    ctx->r4 = ADD32(0, 0XEC);
    playObjectiveVoiceLine1(rdram, ctx);
        goto after_0;
    // 0x80106004: addiu       $a0, $zero, 0xEC
    ctx->r4 = ADD32(0, 0XEC);
    after_0:
    // 0x80106008: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8010600C: jr          $ra
    // 0x80106010: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80106010: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice2_0x0EE(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106014: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80106018: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    // 0x8010601C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80106020: jal         0x800C7D1C
    // 0x80106024: addiu       $a0, $zero, 0xEE
    ctx->r4 = ADD32(0, 0XEE);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80106024: addiu       $a0, $zero, 0xEE
    ctx->r4 = ADD32(0, 0XEE);
    after_0:
    // 0x80106028: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x8010602C: jr          $ra
    // 0x80106030: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80106030: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice_0x167(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106034: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80106038: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8010603C: jal         0x800C7CF8
    // 0x80106040: addiu       $a0, $zero, 0x167
    ctx->r4 = ADD32(0, 0X167);
    playObjectiveVoiceLine1(rdram, ctx);
        goto after_0;
    // 0x80106040: addiu       $a0, $zero, 0x167
    ctx->r4 = ADD32(0, 0X167);
    after_0:
    // 0x80106044: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80106048: jr          $ra
    // 0x8010604C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8010604C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice_0xC4_v2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106050: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80106054: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80106058: jal         0x800C7CF8
    // 0x8010605C: addiu       $a0, $zero, 0xC4
    ctx->r4 = ADD32(0, 0XC4);
    playObjectiveVoiceLine1(rdram, ctx);
        goto after_0;
    // 0x8010605C: addiu       $a0, $zero, 0xC4
    ctx->r4 = ADD32(0, 0XC4);
    after_0:
    // 0x80106060: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80106064: jr          $ra
    // 0x80106068: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80106068: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice_0xEA(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010606C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80106070: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80106074: jal         0x800C7CF8
    // 0x80106078: addiu       $a0, $zero, 0xEA
    ctx->r4 = ADD32(0, 0XEA);
    playObjectiveVoiceLine1(rdram, ctx);
        goto after_0;
    // 0x80106078: addiu       $a0, $zero, 0xEA
    ctx->r4 = ADD32(0, 0XEA);
    after_0:
    // 0x8010607C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80106080: jr          $ra
    // 0x80106084: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80106084: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playPairedDialogue_0x244_0x0EB(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106088: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010608C: addiu       $a0, $zero, 0x244
    ctx->r4 = ADD32(0, 0X244);
    // 0x80106090: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80106094: jal         0x800C7D1C
    // 0x80106098: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80106098: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x8010609C: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x801060A0: jal         0x800C7D1C
    // 0x801060A4: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x801060A4: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    after_1:
    // 0x801060A8: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801060AC: jr          $ra
    // 0x801060B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801060B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playPairedDialogue_0x246_0x0ED(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801060B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801060B8: addiu       $a0, $zero, 0x246
    ctx->r4 = ADD32(0, 0X246);
    // 0x801060BC: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801060C0: jal         0x800C7D1C
    // 0x801060C4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x801060C4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x801060C8: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x801060CC: jal         0x800C7D1C
    // 0x801060D0: addiu       $a0, $zero, 0xED
    ctx->r4 = ADD32(0, 0XED);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x801060D0: addiu       $a0, $zero, 0xED
    ctx->r4 = ADD32(0, 0XED);
    after_1:
    // 0x801060D4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801060D8: jr          $ra
    // 0x801060DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801060DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void playVoice2_0x159(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801060E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801060E4: addiu       $a0, $zero, 0x159
    ctx->r4 = ADD32(0, 0X159);
    // 0x801060E8: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x801060EC: jal         0x800C7D1C
    // 0x801060F0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x801060F0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_0:
    // 0x801060F4: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x801060F8: jr          $ra
    // 0x801060FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801060FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lva_80106100(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106100: jr          $ra
    // 0x80106104: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80106104: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void lva_calculateFriendliesSaved(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106108: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010610C: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80106110: jal         0x800C761C
    // 0x80106114: addiu       $a0, $zero, 0x73
    ctx->r4 = ADD32(0, 0X73);
    getObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x80106114: addiu       $a0, $zero, 0x73
    ctx->r4 = ADD32(0, 0X73);
    after_0:
    // 0x80106118: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8010611C: jal         0x800C77B0
    // 0x80106120: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    setFriendliesSaved(rdram, ctx);
        goto after_1;
    // 0x80106120: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    after_1:
    // 0x80106124: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80106128: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x8010612C: jr          $ra
    // 0x80106130: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80106130: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lva_checkComplexObjectives(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106134: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80106138: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x8010613C: jal         0x800C761C
    // 0x80106140: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    getObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x80106140: addiu       $a0, $zero, 0x63
    ctx->r4 = ADD32(0, 0X63);
    after_0:
    // 0x80106144: slti        $v0, $v0, 0x6
    ctx->r2 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x80106148: bne         $v0, $zero, L_80106164
    if (ctx->r2 != 0) {
        // 0x8010614C: nop
    
            goto L_80106164;
    }
    // 0x8010614C: nop

    // 0x80106150: jal         0x800C776C
    // 0x80106154: nop

    setHudEnableBit8(rdram, ctx);
        goto after_1;
    // 0x80106154: nop

    after_1:
    // 0x80106158: addiu       $a0, $zero, 0x21D
    ctx->r4 = ADD32(0, 0X21D);
    // 0x8010615C: jal         0x800C7D1C
    // 0x80106160: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_2;
    // 0x80106160: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_2:
L_80106164:
    // 0x80106164: jal         0x800C761C
    // 0x80106168: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    getObjectiveCount(rdram, ctx);
        goto after_3;
    // 0x80106168: addiu       $a0, $zero, 0x33
    ctx->r4 = ADD32(0, 0X33);
    after_3:
    // 0x8010616C: slti        $v0, $v0, 0xA
    ctx->r2 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x80106170: bne         $v0, $zero, L_8010618C
    if (ctx->r2 != 0) {
        // 0x80106174: nop
    
            goto L_8010618C;
    }
    // 0x80106174: nop

    // 0x80106178: jal         0x800C7738
    // 0x8010617C: nop

    setHudEnableBit4(rdram, ctx);
        goto after_4;
    // 0x8010617C: nop

    after_4:
    // 0x80106180: addiu       $a0, $zero, 0x55
    ctx->r4 = ADD32(0, 0X55);
    // 0x80106184: jal         0x800C7D1C
    // 0x80106188: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_5;
    // 0x80106188: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_5:
L_8010618C:
    // 0x8010618C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80106190: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80106194: jr          $ra
    // 0x80106198: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80106198: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void fake_func_8010619C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void lvb_initializeObjectTracking(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801061A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801061A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801061A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x801061AC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801061B0: sw          $zero, -0x2EFC($v0)
    MEM_W(-0X2EFC, ctx->r2) = 0;
    // 0x801061B4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801061B8: sw          $zero, -0x2EF8($v0)
    MEM_W(-0X2EF8, ctx->r2) = 0;
    // 0x801061BC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801061C0: sw          $zero, -0x2EF4($v0)
    MEM_W(-0X2EF4, ctx->r2) = 0;
    // 0x801061C4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801061C8: sw          $zero, -0x2EF0($v0)
    MEM_W(-0X2EF0, ctx->r2) = 0;
    // 0x801061CC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801061D0: sw          $zero, -0x2EEC($v0)
    MEM_W(-0X2EEC, ctx->r2) = 0;
    // 0x801061D4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801061D8: sw          $zero, -0x2EE8($v0)
    MEM_W(-0X2EE8, ctx->r2) = 0;
    // 0x801061DC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801061E0: sw          $zero, -0x2EE4($v0)
    MEM_W(-0X2EE4, ctx->r2) = 0;
    // 0x801061E4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801061E8: sw          $zero, -0x2EE0($v0)
    MEM_W(-0X2EE0, ctx->r2) = 0;
    // 0x801061EC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801061F0: sw          $zero, -0x2EDC($v0)
    MEM_W(-0X2EDC, ctx->r2) = 0;
    // 0x801061F4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801061F8: sw          $zero, -0x2ED8($v0)
    MEM_W(-0X2ED8, ctx->r2) = 0;
    // 0x801061FC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80106200: sw          $zero, -0x2ED4($v0)
    MEM_W(-0X2ED4, ctx->r2) = 0;
    // 0x80106204: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80106208: sw          $zero, -0x2ED0($v0)
    MEM_W(-0X2ED0, ctx->r2) = 0;
    // 0x8010620C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80106210: sw          $zero, -0x2ECC($v0)
    MEM_W(-0X2ECC, ctx->r2) = 0;
    // 0x80106214: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80106218: sw          $zero, -0x2F10($v0)
    MEM_W(-0X2F10, ctx->r2) = 0;
    // 0x8010621C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80106220: sw          $zero, -0x2F0C($v0)
    MEM_W(-0X2F0C, ctx->r2) = 0;
    // 0x80106224: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80106228: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x8010622C: sw          $v1, -0x2F08($v0)
    MEM_W(-0X2F08, ctx->r2) = ctx->r3;
    // 0x80106230: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80106234: sw          $v1, -0x2F04($v0)
    MEM_W(-0X2F04, ctx->r2) = ctx->r3;
    // 0x80106238: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8010623C: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80106240: jal         0x800C7660
    // 0x80106244: sw          $zero, -0x2F00($v0)
    MEM_W(-0X2F00, ctx->r2) = 0;
    setObjectiveHiddenFlag(rdram, ctx);
        goto after_0;
    // 0x80106244: sw          $zero, -0x2F00($v0)
    MEM_W(-0X2F00, ctx->r2) = 0;
    after_0:
    // 0x80106248: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8010624C: jal         0x800C7648
    // 0x80106250: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    getAndSetByteAtLevelStateTable(rdram, ctx);
        goto after_1;
    // 0x80106250: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    after_1:
    // 0x80106254: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80106258: jal         0x800C7648
    // 0x8010625C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    getAndSetByteAtLevelStateTable(rdram, ctx);
        goto after_2;
    // 0x8010625C: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_2:
    // 0x80106260: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x80106264: jal         0x800C7540
    // 0x80106268: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_3;
    // 0x80106268: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8010626C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80106270: lwc1        $f12, -0x6790($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X6790);
    // 0x80106274: jal         0x800C7CEC
    // 0x80106278: nop

    setLevelObjectTrackingScalar(rdram, ctx);
        goto after_4;
    // 0x80106278: nop

    after_4:
    // 0x8010627C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80106280: addiu       $a0, $a0, 0x6B08
    ctx->r4 = ADD32(ctx->r4, 0X6B08);
    // 0x80106284: addiu       $a1, $zero, 0x37
    ctx->r5 = ADD32(0, 0X37);
    // 0x80106288: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8010628C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80106290: jal         0x800C7830
    // 0x80106294: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_5;
    // 0x80106294: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x80106298: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x8010629C: addiu       $a0, $a0, 0x6B40
    ctx->r4 = ADD32(ctx->r4, 0X6B40);
    // 0x801062A0: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x801062A4: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x801062A8: addiu       $a3, $zero, 0xB
    ctx->r7 = ADD32(0, 0XB);
    // 0x801062AC: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x801062B0: jal         0x800C7830
    // 0x801062B4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_6;
    // 0x801062B4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_6:
    // 0x801062B8: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x801062BC: addiu       $a0, $a0, 0x6B78
    ctx->r4 = ADD32(ctx->r4, 0X6B78);
    // 0x801062C0: addiu       $a1, $zero, 0x5C
    ctx->r5 = ADD32(0, 0X5C);
    // 0x801062C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801062C8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x801062CC: jal         0x800C7830
    // 0x801062D0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_7;
    // 0x801062D0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_7:
    // 0x801062D4: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x801062D8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x801062DC: jr          $ra
    // 0x801062E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801062E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void lvb_checkComplexObjectives(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801062E4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801062E8: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x801062EC: mov.s       $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    ctx->f22.fl = ctx->f12.fl;
    // 0x801062F0: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x801062F4: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x801062F8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x801062FC: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80106300: jal         0x800C761C
    // 0x80106304: addiu       $a0, $zero, 0x56
    ctx->r4 = ADD32(0, 0X56);
    getObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x80106304: addiu       $a0, $zero, 0x56
    ctx->r4 = ADD32(0, 0X56);
    after_0:
    // 0x80106308: slti        $v0, $v0, 0x3
    ctx->r2 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8010630C: bne         $v0, $zero, L_80106330
    if (ctx->r2 != 0) {
        // 0x80106310: nop
    
            goto L_80106330;
    }
    // 0x80106310: nop

    // 0x80106314: jal         0x800C7738
    // 0x80106318: nop

    setHudEnableBit4(rdram, ctx);
        goto after_1;
    // 0x80106318: nop

    after_1:
    // 0x8010631C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80106320: jal         0x800C7D1C
    // 0x80106324: addiu       $a0, $zero, 0x16B
    ctx->r4 = ADD32(0, 0X16B);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_2;
    // 0x80106324: addiu       $a0, $zero, 0x16B
    ctx->r4 = ADD32(0, 0X16B);
    after_2:
    // 0x80106328: j           L_80106940
    // 0x8010632C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80106940;
    // 0x8010632C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80106330:
    // 0x80106330: jal         0x800C761C
    // 0x80106334: addiu       $a0, $zero, 0x57
    ctx->r4 = ADD32(0, 0X57);
    getObjectiveCount(rdram, ctx);
        goto after_3;
    // 0x80106334: addiu       $a0, $zero, 0x57
    ctx->r4 = ADD32(0, 0X57);
    after_3:
    // 0x80106338: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8010633C: bne         $v0, $s0, L_80106370
    if (ctx->r2 != ctx->r16) {
        // 0x80106340: nop
    
            goto L_80106370;
    }
    // 0x80106340: nop

    // 0x80106344: jal         0x800C7738
    // 0x80106348: nop

    setHudEnableBit4(rdram, ctx);
        goto after_4;
    // 0x80106348: nop

    after_4:
    // 0x8010634C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80106350: jal         0x800C7D1C
    // 0x80106354: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_5;
    // 0x80106354: addiu       $a0, $zero, 0x5D
    ctx->r4 = ADD32(0, 0X5D);
    after_5:
    // 0x80106358: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x8010635C: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80106360: jal         0x800C7D1C
    // 0x80106364: addiu       $a0, $zero, 0x55
    ctx->r4 = ADD32(0, 0X55);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_6;
    // 0x80106364: addiu       $a0, $zero, 0x55
    ctx->r4 = ADD32(0, 0X55);
    after_6:
    // 0x80106368: j           L_80106940
    // 0x8010636C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80106940;
    // 0x8010636C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80106370:
    // 0x80106370: jal         0x800C759C
    // 0x80106374: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    getObjectiveBoolean(rdram, ctx);
        goto after_7;
    // 0x80106374: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_7:
    // 0x80106378: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8010637C: bne         $v1, $s0, L_801063F0
    if (ctx->r3 != ctx->r16) {
        // 0x80106380: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_801063F0;
    }
    // 0x80106380: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80106384: lw          $a0, -0x2EF4($v0)
    ctx->r4 = MEM_W(ctx->r2, -0X2EF4);
    // 0x80106388: bne         $a0, $v1, L_801063F0
    if (ctx->r4 != ctx->r3) {
        // 0x8010638C: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_801063F0;
    }
    // 0x8010638C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80106390: lw          $s0, -0x2EF8($v0)
    ctx->r16 = MEM_W(ctx->r2, -0X2EF8);
    // 0x80106394: bne         $s0, $a0, L_801063F0
    if (ctx->r16 != ctx->r4) {
        // 0x80106398: nop
    
            goto L_801063F0;
    }
    // 0x80106398: nop

    // 0x8010639C: jal         0x800C776C
    // 0x801063A0: nop

    setHudEnableBit8(rdram, ctx);
        goto after_8;
    // 0x801063A0: nop

    after_8:
    // 0x801063A4: jal         0x800C7D98
    // 0x801063A8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    triggerSoundCueByType(rdram, ctx);
        goto after_9;
    // 0x801063A8: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    after_9:
    // 0x801063AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801063B0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801063B4: jal         0x800C76B0
    // 0x801063B8: sw          $s0, -0x2F0C($v0)
    MEM_W(-0X2F0C, ctx->r2) = ctx->r16;
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_10;
    // 0x801063B8: sw          $s0, -0x2F0C($v0)
    MEM_W(-0X2F0C, ctx->r2) = ctx->r16;
    after_10:
    // 0x801063BC: jal         0x800C76B0
    // 0x801063C0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_11;
    // 0x801063C0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_11:
    // 0x801063C4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x801063C8: jal         0x800C7660
    // 0x801063CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    setObjectiveHiddenFlag(rdram, ctx);
        goto after_12;
    // 0x801063CC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_12:
    // 0x801063D0: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x801063D4: jal         0x800C7884
    // 0x801063D8: addiu       $a0, $a0, -0x678C
    ctx->r4 = ADD32(ctx->r4, -0X678C);
    setHudFlagBit40AndStoreArg(rdram, ctx);
        goto after_13;
    // 0x801063D8: addiu       $a0, $a0, -0x678C
    ctx->r4 = ADD32(ctx->r4, -0X678C);
    after_13:
    // 0x801063DC: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x801063E0: jal         0x800C7D1C
    // 0x801063E4: addiu       $a0, $zero, 0x24A
    ctx->r4 = ADD32(0, 0X24A);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_14;
    // 0x801063E4: addiu       $a0, $zero, 0x24A
    ctx->r4 = ADD32(0, 0X24A);
    after_14:
    // 0x801063E8: j           L_80106940
    // 0x801063EC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80106940;
    // 0x801063EC: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_801063F0:
    // 0x801063F0: jal         0x800C759C
    // 0x801063F4: addiu       $a0, $zero, 0x7C
    ctx->r4 = ADD32(0, 0X7C);
    getObjectiveBoolean(rdram, ctx);
        goto after_15;
    // 0x801063F4: addiu       $a0, $zero, 0x7C
    ctx->r4 = ADD32(0, 0X7C);
    after_15:
    // 0x801063F8: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    // 0x801063FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80106400: bne         $a0, $v0, L_80106450
    if (ctx->r4 != ctx->r2) {
        // 0x80106404: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_80106450;
    }
    // 0x80106404: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80106408: lw          $v1, -0x2EF4($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X2EF4);
    // 0x8010640C: bne         $v1, $a0, L_80106450
    if (ctx->r3 != ctx->r4) {
        // 0x80106410: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_80106450;
    }
    // 0x80106410: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80106414: lw          $v0, -0x2EFC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2EFC);
    // 0x80106418: bne         $v0, $v1, L_80106450
    if (ctx->r2 != ctx->r3) {
        // 0x8010641C: nop
    
            goto L_80106450;
    }
    // 0x8010641C: nop

    // 0x80106420: jal         0x800C776C
    // 0x80106424: nop

    setHudEnableBit8(rdram, ctx);
        goto after_16;
    // 0x80106424: nop

    after_16:
    // 0x80106428: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x8010642C: jal         0x800C7660
    // 0x80106430: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    setObjectiveHiddenFlag(rdram, ctx);
        goto after_17;
    // 0x80106430: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_17:
    // 0x80106434: jal         0x800C76B0
    // 0x80106438: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_18;
    // 0x80106438: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_18:
    // 0x8010643C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80106440: jal         0x800C7D1C
    // 0x80106444: addiu       $a0, $zero, 0x21E
    ctx->r4 = ADD32(0, 0X21E);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_19;
    // 0x80106444: addiu       $a0, $zero, 0x21E
    ctx->r4 = ADD32(0, 0X21E);
    after_19:
    // 0x80106448: j           L_80106940
    // 0x8010644C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80106940;
    // 0x8010644C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80106450:
    // 0x80106450: jal         0x800C759C
    // 0x80106454: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    getObjectiveBoolean(rdram, ctx);
        goto after_20;
    // 0x80106454: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_20:
    // 0x80106458: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8010645C: bne         $v0, $v1, L_801064A0
    if (ctx->r2 != ctx->r3) {
        // 0x80106460: nop
    
            goto L_801064A0;
    }
    // 0x80106460: nop

    // 0x80106464: jal         0x800C759C
    // 0x80106468: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    getObjectiveBoolean(rdram, ctx);
        goto after_21;
    // 0x80106468: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    after_21:
    // 0x8010646C: bne         $v0, $zero, L_801064A0
    if (ctx->r2 != 0) {
        // 0x80106470: addiu       $a0, $zero, 0x46
        ctx->r4 = ADD32(0, 0X46);
            goto L_801064A0;
    }
    // 0x80106470: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
    // 0x80106474: jal         0x800C7540
    // 0x80106478: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_22;
    // 0x80106478: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_22:
    // 0x8010647C: addiu       $a0, $zero, 0x57
    ctx->r4 = ADD32(0, 0X57);
    // 0x80106480: jal         0x800C7540
    // 0x80106484: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_23;
    // 0x80106484: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_23:
    // 0x80106488: addiu       $a0, $zero, 0x58
    ctx->r4 = ADD32(0, 0X58);
    // 0x8010648C: jal         0x800C7540
    // 0x80106490: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_24;
    // 0x80106490: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_24:
    // 0x80106494: addiu       $a0, $zero, 0x59
    ctx->r4 = ADD32(0, 0X59);
    // 0x80106498: jal         0x800C7540
    // 0x8010649C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_25;
    // 0x8010649C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_25:
L_801064A0:
    // 0x801064A0: jal         0x800C759C
    // 0x801064A4: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    getObjectiveBoolean(rdram, ctx);
        goto after_26;
    // 0x801064A4: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    after_26:
    // 0x801064A8: bne         $v0, $zero, L_801064B8
    if (ctx->r2 != 0) {
        // 0x801064AC: addiu       $a0, $zero, 0x3E
        ctx->r4 = ADD32(0, 0X3E);
            goto L_801064B8;
    }
    // 0x801064AC: addiu       $a0, $zero, 0x3E
    ctx->r4 = ADD32(0, 0X3E);
    // 0x801064B0: jal         0x800C7540
    // 0x801064B4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    setObjectiveBoolean(rdram, ctx);
        goto after_27;
    // 0x801064B4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_27:
L_801064B8:
    // 0x801064B8: jal         0x800C759C
    // 0x801064BC: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    getObjectiveBoolean(rdram, ctx);
        goto after_28;
    // 0x801064BC: addiu       $a0, $zero, 0x7B
    ctx->r4 = ADD32(0, 0X7B);
    after_28:
    // 0x801064C0: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x801064C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801064C8: bne         $v1, $v0, L_801064EC
    if (ctx->r3 != ctx->r2) {
        // 0x801064CC: lui         $a0, 0x8011
        ctx->r4 = S32(0X8011 << 16);
            goto L_801064EC;
    }
    // 0x801064CC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x801064D0: lw          $v0, -0x2ED4($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X2ED4);
    // 0x801064D4: bne         $v0, $zero, L_801064EC
    if (ctx->r2 != 0) {
        // 0x801064D8: nop
    
            goto L_801064EC;
    }
    // 0x801064D8: nop

    // 0x801064DC: sw          $v1, -0x2ED4($a0)
    MEM_W(-0X2ED4, ctx->r4) = ctx->r3;
    // 0x801064E0: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x801064E4: jal         0x800C7648
    // 0x801064E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    getAndSetByteAtLevelStateTable(rdram, ctx);
        goto after_29;
    // 0x801064E8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_29:
L_801064EC:
    // 0x801064EC: jal         0x800C759C
    // 0x801064F0: addiu       $a0, $zero, 0x7D
    ctx->r4 = ADD32(0, 0X7D);
    getObjectiveBoolean(rdram, ctx);
        goto after_30;
    // 0x801064F0: addiu       $a0, $zero, 0x7D
    ctx->r4 = ADD32(0, 0X7D);
    after_30:
    // 0x801064F4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x801064F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801064FC: bne         $v1, $v0, L_80106528
    if (ctx->r3 != ctx->r2) {
        // 0x80106500: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_80106528;
    }
    // 0x80106500: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80106504: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80106508: lw          $v0, -0x2ED0($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X2ED0);
    // 0x8010650C: bnel        $v0, $zero, L_80106528
    if (ctx->r2 != 0) {
        // 0x80106510: lui         $a0, 0x800B
        ctx->r4 = S32(0X800B << 16);
            goto L_80106528;
    }
    goto skip_0;
    // 0x80106510: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    skip_0:
    // 0x80106514: sw          $v1, -0x2ED0($a0)
    MEM_W(-0X2ED0, ctx->r4) = ctx->r3;
    // 0x80106518: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8010651C: jal         0x800C7648
    // 0x80106520: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    getAndSetByteAtLevelStateTable(rdram, ctx);
        goto after_31;
    // 0x80106520: addu        $a1, $a0, $zero
    ctx->r5 = ADD32(ctx->r4, 0);
    after_31:
    // 0x80106524: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
L_80106528:
    // 0x80106528: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x8010652C: lwc1        $f20, -0x673C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X673C);
    // 0x80106530: jal         0x800C78A0
    // 0x80106534: addiu       $a0, $a0, -0x6770
    ctx->r4 = ADD32(ctx->r4, -0X6770);
    calculateDatItemDistanceToPlayer(rdram, ctx);
        goto after_32;
    // 0x80106534: addiu       $a0, $a0, -0x6770
    ctx->r4 = ADD32(ctx->r4, -0X6770);
    after_32:
    // 0x80106538: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x8010653C: nop

    // 0x80106540: bc1t        L_80106580
    if (c1cs) {
        // 0x80106544: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_80106580;
    }
    // 0x80106544: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80106548: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x8010654C: jal         0x800C78A0
    // 0x80106550: addiu       $a0, $a0, -0x6764
    ctx->r4 = ADD32(ctx->r4, -0X6764);
    calculateDatItemDistanceToPlayer(rdram, ctx);
        goto after_33;
    // 0x80106550: addiu       $a0, $a0, -0x6764
    ctx->r4 = ADD32(ctx->r4, -0X6764);
    after_33:
    // 0x80106554: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x80106558: nop

    // 0x8010655C: bc1t        L_80106580
    if (c1cs) {
        // 0x80106560: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_80106580;
    }
    // 0x80106560: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80106564: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80106568: jal         0x800C78A0
    // 0x8010656C: addiu       $a0, $a0, -0x6758
    ctx->r4 = ADD32(ctx->r4, -0X6758);
    calculateDatItemDistanceToPlayer(rdram, ctx);
        goto after_34;
    // 0x8010656C: addiu       $a0, $a0, -0x6758
    ctx->r4 = ADD32(ctx->r4, -0X6758);
    after_34:
    // 0x80106570: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x80106574: nop

    // 0x80106578: bc1f        L_8010659C
    if (!c1cs) {
        // 0x8010657C: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_8010659C;
    }
    // 0x8010657C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
L_80106580:
    // 0x80106580: lw          $v0, -0x2ED8($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X2ED8);
    // 0x80106584: bne         $v0, $zero, L_801065A0
    if (ctx->r2 != 0) {
        // 0x80106588: lui         $s0, 0x8011
        ctx->r16 = S32(0X8011 << 16);
            goto L_801065A0;
    }
    // 0x80106588: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x8010658C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80106590: sw          $v0, -0x2ED8($v1)
    MEM_W(-0X2ED8, ctx->r3) = ctx->r2;
    // 0x80106594: jal         0x800C76B0
    // 0x80106598: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_35;
    // 0x80106598: addu        $a0, $v0, $zero
    ctx->r4 = ADD32(ctx->r2, 0);
    after_35:
L_8010659C:
    // 0x8010659C: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
L_801065A0:
    // 0x801065A0: lw          $v1, -0x2ECC($s0)
    ctx->r3 = MEM_W(ctx->r16, -0X2ECC);
    // 0x801065A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801065A8: bne         $v1, $v0, L_801065D4
    if (ctx->r3 != ctx->r2) {
        // 0x801065AC: lui         $s1, 0x8011
        ctx->r17 = S32(0X8011 << 16);
            goto L_801065D4;
    }
    // 0x801065AC: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x801065B0: jal         0x800C76E0
    // 0x801065B4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    getObjectiveTimer(rdram, ctx);
        goto after_36;
    // 0x801065B4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_36:
    // 0x801065B8: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x801065BC: lwc1        $f2, -0x6738($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X6738);
    // 0x801065C0: c.le.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl <= ctx->f0.fl;
    // 0x801065C4: nop

    // 0x801065C8: bc1tl       L_801065D0
    if (c1cs) {
        // 0x801065CC: sw          $zero, -0x2ECC($s0)
        MEM_W(-0X2ECC, ctx->r16) = 0;
            goto L_801065D0;
    }
    goto skip_1;
    // 0x801065CC: sw          $zero, -0x2ECC($s0)
    MEM_W(-0X2ECC, ctx->r16) = 0;
    skip_1:
L_801065D0:
    // 0x801065D0: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
L_801065D4:
    // 0x801065D4: lw          $v0, -0x2ECC($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X2ECC);
    // 0x801065D8: bne         $v0, $zero, L_80106934
    if (ctx->r2 != 0) {
        // 0x801065DC: nop
    
            goto L_80106934;
    }
    // 0x801065DC: nop

    // 0x801065E0: jal         0x800C759C
    // 0x801065E4: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    getObjectiveBoolean(rdram, ctx);
        goto after_37;
    // 0x801065E4: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_37:
    // 0x801065E8: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x801065EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801065F0: bne         $s0, $v0, L_80106684
    if (ctx->r16 != ctx->r2) {
        // 0x801065F4: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_80106684;
    }
    // 0x801065F4: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x801065F8: lw          $v0, -0x2EF4($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X2EF4);
    // 0x801065FC: bne         $v0, $zero, L_80106684
    if (ctx->r2 != 0) {
        // 0x80106600: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_80106684;
    }
    // 0x80106600: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80106604: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80106608: sw          $s0, -0x2EF4($v1)
    MEM_W(-0X2EF4, ctx->r3) = ctx->r16;
    // 0x8010660C: sw          $s0, -0x2EFC($v0)
    MEM_W(-0X2EFC, ctx->r2) = ctx->r16;
    // 0x80106610: jal         0x800C7D98
    // 0x80106614: sw          $s0, -0x2ECC($s1)
    MEM_W(-0X2ECC, ctx->r17) = ctx->r16;
    triggerSoundCueByType(rdram, ctx);
        goto after_38;
    // 0x80106614: sw          $s0, -0x2ECC($s1)
    MEM_W(-0X2ECC, ctx->r17) = ctx->r16;
    after_38:
    // 0x80106618: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8010661C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80106620: jal         0x800C76B0
    // 0x80106624: sw          $s0, -0x2F0C($v0)
    MEM_W(-0X2F0C, ctx->r2) = ctx->r16;
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_39;
    // 0x80106624: sw          $s0, -0x2F0C($v0)
    MEM_W(-0X2F0C, ctx->r2) = ctx->r16;
    after_39:
    // 0x80106628: jal         0x800C76B0
    // 0x8010662C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_40;
    // 0x8010662C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_40:
    // 0x80106630: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x80106634: jal         0x800C7660
    // 0x80106638: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    setObjectiveHiddenFlag(rdram, ctx);
        goto after_41;
    // 0x80106638: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_41:
    // 0x8010663C: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80106640: jal         0x800C7884
    // 0x80106644: addiu       $a0, $a0, -0x678C
    ctx->r4 = ADD32(ctx->r4, -0X678C);
    setHudFlagBit40AndStoreArg(rdram, ctx);
        goto after_42;
    // 0x80106644: addiu       $a0, $a0, -0x678C
    ctx->r4 = ADD32(ctx->r4, -0X678C);
    after_42:
    // 0x80106648: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8010664C: jal         0x800C76FC
    // 0x80106650: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    setObjectiveTimer(rdram, ctx);
        goto after_43;
    // 0x80106650: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_43:
    // 0x80106654: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80106658: jal         0x800C7D1C
    // 0x8010665C: addiu       $a0, $zero, 0x24A
    ctx->r4 = ADD32(0, 0X24A);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_44;
    // 0x8010665C: addiu       $a0, $zero, 0x24A
    ctx->r4 = ADD32(0, 0X24A);
    after_44:
    // 0x80106660: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x80106664: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80106668: jal         0x800C7D1C
    // 0x8010666C: addiu       $a0, $zero, 0x16C
    ctx->r4 = ADD32(0, 0X16C);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_45;
    // 0x8010666C: addiu       $a0, $zero, 0x16C
    ctx->r4 = ADD32(0, 0X16C);
    after_45:
    // 0x80106670: addiu       $a0, $zero, 0x74
    ctx->r4 = ADD32(0, 0X74);
    // 0x80106674: jal         0x800C7540
    // 0x80106678: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    setObjectiveBoolean(rdram, ctx);
        goto after_46;
    // 0x80106678: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_46:
    // 0x8010667C: j           L_80106940
    // 0x80106680: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80106940;
    // 0x80106680: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80106684:
    // 0x80106684: jal         0x800C759C
    // 0x80106688: addiu       $a0, $zero, 0x7C
    ctx->r4 = ADD32(0, 0X7C);
    getObjectiveBoolean(rdram, ctx);
        goto after_47;
    // 0x80106688: addiu       $a0, $zero, 0x7C
    ctx->r4 = ADD32(0, 0X7C);
    after_47:
    // 0x8010668C: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x80106690: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80106694: bne         $v1, $v0, L_801066EC
    if (ctx->r3 != ctx->r2) {
        // 0x80106698: lui         $a2, 0x8011
        ctx->r6 = S32(0X8011 << 16);
            goto L_801066EC;
    }
    // 0x80106698: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x8010669C: lw          $v0, -0x2EF4($a2)
    ctx->r2 = MEM_W(ctx->r6, -0X2EF4);
    // 0x801066A0: bne         $v0, $zero, L_801066EC
    if (ctx->r2 != 0) {
        // 0x801066A4: addu        $a0, $zero, $zero
        ctx->r4 = ADD32(0, 0);
            goto L_801066EC;
    }
    // 0x801066A4: addu        $a0, $zero, $zero
    ctx->r4 = ADD32(0, 0);
    // 0x801066A8: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x801066AC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801066B0: sw          $v1, -0x2EF8($v0)
    MEM_W(-0X2EF8, ctx->r2) = ctx->r3;
    // 0x801066B4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801066B8: sw          $v1, -0x2EF4($a2)
    MEM_W(-0X2EF4, ctx->r6) = ctx->r3;
    // 0x801066BC: jal         0x800C7660
    // 0x801066C0: sw          $v1, -0x2ECC($v0)
    MEM_W(-0X2ECC, ctx->r2) = ctx->r3;
    setObjectiveHiddenFlag(rdram, ctx);
        goto after_48;
    // 0x801066C0: sw          $v1, -0x2ECC($v0)
    MEM_W(-0X2ECC, ctx->r2) = ctx->r3;
    after_48:
    // 0x801066C4: jal         0x800C76B0
    // 0x801066C8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_49;
    // 0x801066C8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_49:
    // 0x801066CC: lui         $a1, 0x4110
    ctx->r5 = S32(0X4110 << 16);
    // 0x801066D0: jal         0x800C76FC
    // 0x801066D4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    setObjectiveTimer(rdram, ctx);
        goto after_50;
    // 0x801066D4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_50:
    // 0x801066D8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x801066DC: jal         0x800C7D1C
    // 0x801066E0: addiu       $a0, $zero, 0x21E
    ctx->r4 = ADD32(0, 0X21E);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_51;
    // 0x801066E0: addiu       $a0, $zero, 0x21E
    ctx->r4 = ADD32(0, 0X21E);
    after_51:
    // 0x801066E4: j           L_80106940
    // 0x801066E8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80106940;
    // 0x801066E8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_801066EC:
    // 0x801066EC: jal         0x800C759C
    // 0x801066F0: addiu       $a0, $zero, 0x7D
    ctx->r4 = ADD32(0, 0X7D);
    getObjectiveBoolean(rdram, ctx);
        goto after_52;
    // 0x801066F0: addiu       $a0, $zero, 0x7D
    ctx->r4 = ADD32(0, 0X7D);
    after_52:
    // 0x801066F4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x801066F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801066FC: bnel        $v1, $v0, L_8010675C
    if (ctx->r3 != ctx->r2) {
        // 0x80106700: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_8010675C;
    }
    goto skip_2;
    // 0x80106700: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    skip_2:
    // 0x80106704: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80106708: lw          $v0, -0x2EF0($a1)
    ctx->r2 = MEM_W(ctx->r5, -0X2EF0);
    // 0x8010670C: bnel        $v0, $zero, L_8010675C
    if (ctx->r2 != 0) {
        // 0x80106710: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_8010675C;
    }
    goto skip_3;
    // 0x80106710: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    skip_3:
    // 0x80106714: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80106718: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x8010671C: sw          $v1, -0x2EF0($a1)
    MEM_W(-0X2EF0, ctx->r5) = ctx->r3;
    // 0x80106720: jal         0x800C7D98
    // 0x80106724: sw          $v1, -0x2ECC($v0)
    MEM_W(-0X2ECC, ctx->r2) = ctx->r3;
    triggerSoundCueByType(rdram, ctx);
        goto after_53;
    // 0x80106724: sw          $v1, -0x2ECC($v0)
    MEM_W(-0X2ECC, ctx->r2) = ctx->r3;
    after_53:
    // 0x80106728: lui         $a1, 0x4110
    ctx->r5 = S32(0X4110 << 16);
    // 0x8010672C: jal         0x800C76FC
    // 0x80106730: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    setObjectiveTimer(rdram, ctx);
        goto after_54;
    // 0x80106730: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_54:
    // 0x80106734: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80106738: jal         0x800C7884
    // 0x8010673C: addiu       $a0, $a0, -0x674C
    ctx->r4 = ADD32(ctx->r4, -0X674C);
    setHudFlagBit40AndStoreArg(rdram, ctx);
        goto after_55;
    // 0x8010673C: addiu       $a0, $a0, -0x674C
    ctx->r4 = ADD32(ctx->r4, -0X674C);
    after_55:
    // 0x80106740: jal         0x800C7D44
    // 0x80106744: nop

    func_800C7D44(rdram, ctx);
        goto after_56;
    // 0x80106744: nop

    after_56:
    // 0x80106748: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8010674C: jal         0x800C7D1C
    // 0x80106750: addiu       $a0, $zero, 0x21D
    ctx->r4 = ADD32(0, 0X21D);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_57;
    // 0x80106750: addiu       $a0, $zero, 0x21D
    ctx->r4 = ADD32(0, 0X21D);
    after_57:
    // 0x80106754: j           L_80106940
    // 0x80106758: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80106940;
    // 0x80106758: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_8010675C:
    // 0x8010675C: lw          $v0, -0x2EEC($v1)
    ctx->r2 = MEM_W(ctx->r3, -0X2EEC);
    // 0x80106760: bne         $v0, $zero, L_801067CC
    if (ctx->r2 != 0) {
        // 0x80106764: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_801067CC;
    }
    // 0x80106764: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80106768: lui         $a1, 0x40C0
    ctx->r5 = S32(0X40C0 << 16);
    // 0x8010676C: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80106770: lwc1        $f20, -0x6734($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X6734);
    // 0x80106774: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80106778: sw          $v0, -0x2EEC($v1)
    MEM_W(-0X2EEC, ctx->r3) = ctx->r2;
    // 0x8010677C: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80106780: jal         0x800C76FC
    // 0x80106784: sw          $v0, -0x2ECC($v1)
    MEM_W(-0X2ECC, ctx->r3) = ctx->r2;
    setObjectiveTimer(rdram, ctx);
        goto after_58;
    // 0x80106784: sw          $v0, -0x2ECC($v1)
    MEM_W(-0X2ECC, ctx->r3) = ctx->r2;
    after_58:
    // 0x80106788: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8010678C: jal         0x800C7D1C
    // 0x80106790: addiu       $a0, $zero, 0x108
    ctx->r4 = ADD32(0, 0X108);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_59;
    // 0x80106790: addiu       $a0, $zero, 0x108
    ctx->r4 = ADD32(0, 0X108);
    after_59:
    // 0x80106794: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80106798: jal         0x800C7D1C
    // 0x8010679C: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_60;
    // 0x8010679C: addiu       $a0, $zero, 0x42
    ctx->r4 = ADD32(0, 0X42);
    after_60:
    // 0x801067A0: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801067A4: jal         0x800C7D1C
    // 0x801067A8: addiu       $a0, $zero, 0x9B
    ctx->r4 = ADD32(0, 0X9B);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_61;
    // 0x801067A8: addiu       $a0, $zero, 0x9B
    ctx->r4 = ADD32(0, 0X9B);
    after_61:
    // 0x801067AC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801067B0: jal         0x800C7D1C
    // 0x801067B4: addiu       $a0, $zero, 0x25D
    ctx->r4 = ADD32(0, 0X25D);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_62;
    // 0x801067B4: addiu       $a0, $zero, 0x25D
    ctx->r4 = ADD32(0, 0X25D);
    after_62:
    // 0x801067B8: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x801067BC: jal         0x800C7D1C
    // 0x801067C0: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_63;
    // 0x801067C0: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    after_63:
    // 0x801067C4: j           L_80106940
    // 0x801067C8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80106940;
    // 0x801067C8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_801067CC:
    // 0x801067CC: jal         0x800C759C
    // 0x801067D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    getObjectiveBoolean(rdram, ctx);
        goto after_64;
    // 0x801067D0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_64:
    // 0x801067D4: bne         $v0, $zero, L_80106830
    if (ctx->r2 != 0) {
        // 0x801067D8: nop
    
            goto L_80106830;
    }
    // 0x801067D8: nop

    // 0x801067DC: jal         0x800C759C
    // 0x801067E0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    getObjectiveBoolean(rdram, ctx);
        goto after_65;
    // 0x801067E0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_65:
    // 0x801067E4: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x801067E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801067EC: bne         $v1, $v0, L_80106830
    if (ctx->r3 != ctx->r2) {
        // 0x801067F0: lui         $a1, 0x8011
        ctx->r5 = S32(0X8011 << 16);
            goto L_80106830;
    }
    // 0x801067F0: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x801067F4: lw          $v0, -0x2EE8($a1)
    ctx->r2 = MEM_W(ctx->r5, -0X2EE8);
    // 0x801067F8: bne         $v0, $zero, L_80106830
    if (ctx->r2 != 0) {
        // 0x801067FC: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80106830;
    }
    // 0x801067FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80106800: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80106804: sw          $v1, -0x2EE8($a1)
    MEM_W(-0X2EE8, ctx->r5) = ctx->r3;
    // 0x80106808: jal         0x800C76B0
    // 0x8010680C: sw          $v1, -0x2ECC($v0)
    MEM_W(-0X2ECC, ctx->r2) = ctx->r3;
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_66;
    // 0x8010680C: sw          $v1, -0x2ECC($v0)
    MEM_W(-0X2ECC, ctx->r2) = ctx->r3;
    after_66:
    // 0x80106810: lui         $a1, 0x4040
    ctx->r5 = S32(0X4040 << 16);
    // 0x80106814: jal         0x800C76FC
    // 0x80106818: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    setObjectiveTimer(rdram, ctx);
        goto after_67;
    // 0x80106818: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_67:
    // 0x8010681C: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80106820: jal         0x800C7D1C
    // 0x80106824: addiu       $a0, $zero, 0x169
    ctx->r4 = ADD32(0, 0X169);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_68;
    // 0x80106824: addiu       $a0, $zero, 0x169
    ctx->r4 = ADD32(0, 0X169);
    after_68:
    // 0x80106828: j           L_80106940
    // 0x8010682C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80106940;
    // 0x8010682C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80106830:
    // 0x80106830: jal         0x800C759C
    // 0x80106834: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    getObjectiveBoolean(rdram, ctx);
        goto after_69;
    // 0x80106834: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_69:
    // 0x80106838: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
    // 0x8010683C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80106840: bne         $v1, $v0, L_80106890
    if (ctx->r3 != ctx->r2) {
        // 0x80106844: lui         $a1, 0x8011
        ctx->r5 = S32(0X8011 << 16);
            goto L_80106890;
    }
    // 0x80106844: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80106848: lw          $v0, -0x2EE4($a1)
    ctx->r2 = MEM_W(ctx->r5, -0X2EE4);
    // 0x8010684C: bne         $v0, $zero, L_80106890
    if (ctx->r2 != 0) {
        // 0x80106850: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_80106890;
    }
    // 0x80106850: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80106854: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80106858: sw          $v1, -0x2EE4($a1)
    MEM_W(-0X2EE4, ctx->r5) = ctx->r3;
    // 0x8010685C: jal         0x800C76B0
    // 0x80106860: sw          $v1, -0x2ECC($v0)
    MEM_W(-0X2ECC, ctx->r2) = ctx->r3;
    activateObjectiveCompleteFlag(rdram, ctx);
        goto after_70;
    // 0x80106860: sw          $v1, -0x2ECC($v0)
    MEM_W(-0X2ECC, ctx->r2) = ctx->r3;
    after_70:
    // 0x80106864: lui         $a1, 0x4100
    ctx->r5 = S32(0X4100 << 16);
    // 0x80106868: jal         0x800C76FC
    // 0x8010686C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    setObjectiveTimer(rdram, ctx);
        goto after_71;
    // 0x8010686C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_71:
    // 0x80106870: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80106874: jal         0x800C7D1C
    // 0x80106878: addiu       $a0, $zero, 0x248
    ctx->r4 = ADD32(0, 0X248);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_72;
    // 0x80106878: addiu       $a0, $zero, 0x248
    ctx->r4 = ADD32(0, 0X248);
    after_72:
    // 0x8010687C: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    // 0x80106880: jal         0x800C75EC
    // 0x80106884: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    increaseObjectiveCount(rdram, ctx);
        goto after_73;
    // 0x80106884: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_73:
    // 0x80106888: j           L_80106940
    // 0x8010688C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80106940;
    // 0x8010688C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80106890:
    // 0x80106890: jal         0x800C761C
    // 0x80106894: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    getObjectiveCount(rdram, ctx);
        goto after_74;
    // 0x80106894: addiu       $a0, $zero, 0x2C
    ctx->r4 = ADD32(0, 0X2C);
    after_74:
    // 0x80106898: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8010689C: bne         $v0, $v1, L_801068E4
    if (ctx->r2 != ctx->r3) {
        // 0x801068A0: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_801068E4;
    }
    // 0x801068A0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801068A4: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x801068A8: lw          $v0, -0x2EE0($a2)
    ctx->r2 = MEM_W(ctx->r6, -0X2EE0);
    // 0x801068AC: bne         $v0, $zero, L_801068E4
    if (ctx->r2 != 0) {
        // 0x801068B0: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_801068E4;
    }
    // 0x801068B0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801068B4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x801068B8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801068BC: lui         $a1, 0x40E0
    ctx->r5 = S32(0X40E0 << 16);
    // 0x801068C0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801068C4: sw          $v1, -0x2EE0($a2)
    MEM_W(-0X2EE0, ctx->r6) = ctx->r3;
    // 0x801068C8: jal         0x800C76FC
    // 0x801068CC: sw          $v1, -0x2ECC($v0)
    MEM_W(-0X2ECC, ctx->r2) = ctx->r3;
    setObjectiveTimer(rdram, ctx);
        goto after_75;
    // 0x801068CC: sw          $v1, -0x2ECC($v0)
    MEM_W(-0X2ECC, ctx->r2) = ctx->r3;
    after_75:
    // 0x801068D0: addiu       $a0, $zero, 0x16A
    ctx->r4 = ADD32(0, 0X16A);
    // 0x801068D4: jal         0x800C7D1C
    // 0x801068D8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_76;
    // 0x801068D8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_76:
    // 0x801068DC: j           L_80106940
    // 0x801068E0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80106940;
    // 0x801068E0: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_801068E4:
    // 0x801068E4: lw          $v1, -0x2EE8($v0)
    ctx->r3 = MEM_W(ctx->r2, -0X2EE8);
    // 0x801068E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801068EC: bne         $v1, $v0, L_80106934
    if (ctx->r3 != ctx->r2) {
        // 0x801068F0: lui         $a2, 0x8011
        ctx->r6 = S32(0X8011 << 16);
            goto L_80106934;
    }
    // 0x801068F0: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x801068F4: lw          $v0, -0x2EDC($a2)
    ctx->r2 = MEM_W(ctx->r6, -0X2EDC);
    // 0x801068F8: bne         $v0, $zero, L_80106934
    if (ctx->r2 != 0) {
        // 0x801068FC: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_80106934;
    }
    // 0x801068FC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80106900: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80106904: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80106908: sw          $v1, -0x2EDC($a2)
    MEM_W(-0X2EDC, ctx->r6) = ctx->r3;
    // 0x8010690C: jal         0x800C76FC
    // 0x80106910: sw          $v1, -0x2ECC($v0)
    MEM_W(-0X2ECC, ctx->r2) = ctx->r3;
    setObjectiveTimer(rdram, ctx);
        goto after_77;
    // 0x80106910: sw          $v1, -0x2ECC($v0)
    MEM_W(-0X2ECC, ctx->r2) = ctx->r3;
    after_77:
    // 0x80106914: lui         $a1, 0x40E0
    ctx->r5 = S32(0X40E0 << 16);
    // 0x80106918: jal         0x800C7D1C
    // 0x8010691C: addiu       $a0, $zero, 0x92
    ctx->r4 = ADD32(0, 0X92);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_78;
    // 0x8010691C: addiu       $a0, $zero, 0x92
    ctx->r4 = ADD32(0, 0X92);
    after_78:
    // 0x80106920: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80106924: jal         0x800C7D1C
    // 0x80106928: addiu       $a0, $zero, 0x247
    ctx->r4 = ADD32(0, 0X247);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_79;
    // 0x80106928: addiu       $a0, $zero, 0x247
    ctx->r4 = ADD32(0, 0X247);
    after_79:
    // 0x8010692C: j           L_80106940
    // 0x80106930: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
        goto L_80106940;
    // 0x80106930: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80106934:
    // 0x80106934: jal         0x8010695C
    // 0x80106938: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    func_8010695C(rdram, ctx);
        goto after_80;
    // 0x80106938: mov.s       $f12, $f22
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    ctx->f12.fl = ctx->f22.fl;
    after_80:
    // 0x8010693C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
L_80106940:
    // 0x80106940: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80106944: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80106948: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x8010694C: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80106950: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80106954: jr          $ra
    // 0x80106958: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80106958: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_8010695C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010695C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80106960: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x80106964: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x80106968: lw          $v0, -0x2F10($s1)
    ctx->r2 = MEM_W(ctx->r17, -0X2F10);
    // 0x8010696C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80106970: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x80106974: sw          $ra, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r31;
    // 0x80106978: bne         $v0, $zero, L_801069E8
    if (ctx->r2 != 0) {
        // 0x8010697C: sw          $s0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r16;
            goto L_801069E8;
    }
    // 0x8010697C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x80106980: jal         0x800C759C
    // 0x80106984: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    getObjectiveBoolean(rdram, ctx);
        goto after_0;
    // 0x80106984: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x80106988: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x8010698C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80106990: bne         $s0, $v0, L_801069EC
    if (ctx->r16 != ctx->r2) {
        // 0x80106994: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_801069EC;
    }
    // 0x80106994: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x80106998: jal         0x800C759C
    // 0x8010699C: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    getObjectiveBoolean(rdram, ctx);
        goto after_1;
    // 0x8010699C: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    after_1:
    // 0x801069A0: beq         $v0, $zero, L_801069BC
    if (ctx->r2 == 0) {
        // 0x801069A4: lui         $a0, 0x8011
        ctx->r4 = S32(0X8011 << 16);
            goto L_801069BC;
    }
    // 0x801069A4: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x801069A8: jal         0x800C759C
    // 0x801069AC: addiu       $a0, $zero, 0x7D
    ctx->r4 = ADD32(0, 0X7D);
    getObjectiveBoolean(rdram, ctx);
        goto after_2;
    // 0x801069AC: addiu       $a0, $zero, 0x7D
    ctx->r4 = ADD32(0, 0X7D);
    after_2:
    // 0x801069B0: bne         $v0, $s0, L_801069EC
    if (ctx->r2 != ctx->r16) {
        // 0x801069B4: lui         $v1, 0x8011
        ctx->r3 = S32(0X8011 << 16);
            goto L_801069EC;
    }
    // 0x801069B4: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x801069B8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
L_801069BC:
    // 0x801069BC: lw          $v1, -0x2F04($a0)
    ctx->r3 = MEM_W(ctx->r4, -0X2F04);
    // 0x801069C0: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x801069C4: sw          $zero, -0x2F08($v0)
    MEM_W(-0X2F08, ctx->r2) = 0;
    // 0x801069C8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x801069CC: beq         $v1, $v0, L_801069E8
    if (ctx->r3 == ctx->r2) {
        // 0x801069D0: sw          $s0, -0x2F10($s1)
        MEM_W(-0X2F10, ctx->r17) = ctx->r16;
            goto L_801069E8;
    }
    // 0x801069D0: sw          $s0, -0x2F10($s1)
    MEM_W(-0X2F10, ctx->r17) = ctx->r16;
    // 0x801069D4: sw          $zero, -0x2F04($a0)
    MEM_W(-0X2F04, ctx->r4) = 0;
    // 0x801069D8: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x801069DC: addiu       $a0, $a0, -0x6730
    ctx->r4 = ADD32(ctx->r4, -0X6730);
    // 0x801069E0: jal         0x800C7D60
    // 0x801069E4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    delegateToLevelStageTick(rdram, ctx);
        goto after_3;
    // 0x801069E4: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    after_3:
L_801069E8:
    // 0x801069E8: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
L_801069EC:
    // 0x801069EC: lw          $a1, -0x2F0C($v1)
    ctx->r5 = MEM_W(ctx->r3, -0X2F0C);
    // 0x801069F0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801069F4: bne         $a1, $v0, L_80106A28
    if (ctx->r5 != ctx->r2) {
        // 0x801069F8: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_80106A28;
    }
    // 0x801069F8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801069FC: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80106A00: sw          $a0, -0x2F0C($v1)
    MEM_W(-0X2F0C, ctx->r3) = ctx->r4;
    // 0x80106A04: lw          $v1, -0x2F04($a2)
    ctx->r3 = MEM_W(ctx->r6, -0X2F04);
    // 0x80106A08: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80106A0C: beq         $v1, $a0, L_80106A28
    if (ctx->r3 == ctx->r4) {
        // 0x80106A10: sw          $a1, -0x2F08($v0)
        MEM_W(-0X2F08, ctx->r2) = ctx->r5;
            goto L_80106A28;
    }
    // 0x80106A10: sw          $a1, -0x2F08($v0)
    MEM_W(-0X2F08, ctx->r2) = ctx->r5;
    // 0x80106A14: sw          $a1, -0x2F04($a2)
    MEM_W(-0X2F04, ctx->r6) = ctx->r5;
    // 0x80106A18: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80106A1C: addiu       $a0, $a0, -0x6730
    ctx->r4 = ADD32(ctx->r4, -0X6730);
    // 0x80106A20: jal         0x800C7D60
    // 0x80106A24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    delegateToLevelStageTick(rdram, ctx);
        goto after_4;
    // 0x80106A24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
L_80106A28:
    // 0x80106A28: jal         0x800C759C
    // 0x80106A2C: addiu       $a0, $zero, 0x7C
    ctx->r4 = ADD32(0, 0X7C);
    getObjectiveBoolean(rdram, ctx);
        goto after_5;
    // 0x80106A2C: addiu       $a0, $zero, 0x7C
    ctx->r4 = ADD32(0, 0X7C);
    after_5:
    // 0x80106A30: bne         $v0, $zero, L_80106ACC
    if (ctx->r2 != 0) {
        // 0x80106A34: lui         $a2, 0x8011
        ctx->r6 = S32(0X8011 << 16);
            goto L_80106ACC;
    }
    // 0x80106A34: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80106A38: jal         0x800C759C
    // 0x80106A3C: addiu       $a0, $zero, 0x7D
    ctx->r4 = ADD32(0, 0X7D);
    getObjectiveBoolean(rdram, ctx);
        goto after_6;
    // 0x80106A3C: addiu       $a0, $zero, 0x7D
    ctx->r4 = ADD32(0, 0X7D);
    after_6:
    // 0x80106A40: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80106A44: bne         $v0, $v1, L_80106ACC
    if (ctx->r2 != ctx->r3) {
        // 0x80106A48: lui         $a2, 0x8011
        ctx->r6 = S32(0X8011 << 16);
            goto L_80106ACC;
    }
    // 0x80106A48: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80106A4C: jal         0x800C759C
    // 0x80106A50: addiu       $a0, $zero, 0x6F
    ctx->r4 = ADD32(0, 0X6F);
    getObjectiveBoolean(rdram, ctx);
        goto after_7;
    // 0x80106A50: addiu       $a0, $zero, 0x6F
    ctx->r4 = ADD32(0, 0X6F);
    after_7:
    // 0x80106A54: beq         $v0, $zero, L_80106A94
    if (ctx->r2 == 0) {
        // 0x80106A58: lui         $a0, 0x8011
        ctx->r4 = S32(0X8011 << 16);
            goto L_80106A94;
    }
    // 0x80106A58: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80106A5C: lw          $v0, -0x2F04($a0)
    ctx->r2 = MEM_W(ctx->r4, -0X2F04);
    // 0x80106A60: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80106A64: beq         $v0, $v1, L_80106A80
    if (ctx->r2 == ctx->r3) {
        // 0x80106A68: nop
    
            goto L_80106A80;
    }
    // 0x80106A68: nop

    // 0x80106A6C: sw          $v1, -0x2F04($a0)
    MEM_W(-0X2F04, ctx->r4) = ctx->r3;
    // 0x80106A70: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80106A74: addiu       $a0, $a0, -0x6730
    ctx->r4 = ADD32(ctx->r4, -0X6730);
    // 0x80106A78: jal         0x800C7D60
    // 0x80106A7C: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    delegateToLevelStageTick(rdram, ctx);
        goto after_8;
    // 0x80106A7C: addu        $a1, $v1, $zero
    ctx->r5 = ADD32(ctx->r3, 0);
    after_8:
L_80106A80:
    // 0x80106A80: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80106A84: lwc1        $f0, -0x6718($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6718);
    // 0x80106A88: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80106A8C: j           L_80106AF0
    // 0x80106A90: swc1        $f0, -0x2F00($v0)
    MEM_W(-0X2F00, ctx->r2) = ctx->f0.u32l;
        goto L_80106AF0;
    // 0x80106A90: swc1        $f0, -0x2F00($v0)
    MEM_W(-0X2F00, ctx->r2) = ctx->f0.u32l;
L_80106A94:
    // 0x80106A94: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80106A98: lw          $v1, -0x2F04($a2)
    ctx->r3 = MEM_W(ctx->r6, -0X2F04);
    // 0x80106A9C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80106AA0: bne         $v1, $v0, L_80106AF0
    if (ctx->r3 != ctx->r2) {
        // 0x80106AA4: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_80106AF0;
    }
    // 0x80106AA4: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80106AA8: lwc1        $f0, -0x2F00($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, -0X2F00);
    // 0x80106AAC: sub.s       $f0, $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x80106AB0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80106AB4: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x80106AB8: nop

    // 0x80106ABC: bc1f        L_80106AF0
    if (!c1cs) {
        // 0x80106AC0: swc1        $f0, -0x2F00($v0)
        MEM_W(-0X2F00, ctx->r2) = ctx->f0.u32l;
            goto L_80106AF0;
    }
    // 0x80106AC0: swc1        $f0, -0x2F00($v0)
    MEM_W(-0X2F00, ctx->r2) = ctx->f0.u32l;
    // 0x80106AC4: j           L_80106ADC
    // 0x80106AC8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
        goto L_80106ADC;
    // 0x80106AC8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_80106ACC:
    // 0x80106ACC: lw          $v1, -0x2F04($a2)
    ctx->r3 = MEM_W(ctx->r6, -0X2F04);
    // 0x80106AD0: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80106AD4: bne         $v1, $v0, L_80106AF0
    if (ctx->r3 != ctx->r2) {
        // 0x80106AD8: lui         $v0, 0x8011
        ctx->r2 = S32(0X8011 << 16);
            goto L_80106AF0;
    }
    // 0x80106AD8: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
L_80106ADC:
    // 0x80106ADC: lui         $a0, 0x800B
    ctx->r4 = S32(0X800B << 16);
    // 0x80106AE0: lw          $a1, -0x2F08($v0)
    ctx->r5 = MEM_W(ctx->r2, -0X2F08);
    // 0x80106AE4: addiu       $a0, $a0, -0x6730
    ctx->r4 = ADD32(ctx->r4, -0X6730);
    // 0x80106AE8: jal         0x800C7D60
    // 0x80106AEC: sw          $a1, -0x2F04($a2)
    MEM_W(-0X2F04, ctx->r6) = ctx->r5;
    delegateToLevelStageTick(rdram, ctx);
        goto after_9;
    // 0x80106AEC: sw          $a1, -0x2F04($a2)
    MEM_W(-0X2F04, ctx->r6) = ctx->r5;
    after_9:
L_80106AF0:
    // 0x80106AF0: lw          $ra, 0x18($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X18);
    // 0x80106AF4: lw          $s1, 0x14($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X14);
    // 0x80106AF8: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80106AFC: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80106B00: jr          $ra
    // 0x80106B04: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80106B04: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void playPairedDialogue_0x0AD_0x11A(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106B08: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80106B0C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80106B10: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80106B14: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80106B18: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80106B1C: jal         0x800C7D1C
    // 0x80106B20: addiu       $a0, $zero, 0xAD
    ctx->r4 = ADD32(0, 0XAD);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80106B20: addiu       $a0, $zero, 0xAD
    ctx->r4 = ADD32(0, 0XAD);
    after_0:
    // 0x80106B24: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80106B28: jal         0x800C7D1C
    // 0x80106B2C: addiu       $a0, $zero, 0x11A
    ctx->r4 = ADD32(0, 0X11A);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x80106B2C: addiu       $a0, $zero, 0x11A
    ctx->r4 = ADD32(0, 0X11A);
    after_1:
    // 0x80106B30: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80106B34: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80106B38: jr          $ra
    // 0x80106B3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80106B3C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void playPairedDialogue_0x1F8_0x11B(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106B40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80106B44: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80106B48: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80106B4C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80106B50: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80106B54: jal         0x800C7D1C
    // 0x80106B58: addiu       $a0, $zero, 0x1F8
    ctx->r4 = ADD32(0, 0X1F8);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80106B58: addiu       $a0, $zero, 0x1F8
    ctx->r4 = ADD32(0, 0X1F8);
    after_0:
    // 0x80106B5C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80106B60: jal         0x800C7D1C
    // 0x80106B64: addiu       $a0, $zero, 0x11B
    ctx->r4 = ADD32(0, 0X11B);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_1;
    // 0x80106B64: addiu       $a0, $zero, 0x11B
    ctx->r4 = ADD32(0, 0X11B);
    after_1:
    // 0x80106B68: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80106B6C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80106B70: jr          $ra
    // 0x80106B74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80106B74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void playVoice2_0x2F2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106B78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80106B7C: lui         $a1, 0x4000
    ctx->r5 = S32(0X4000 << 16);
    // 0x80106B80: sw          $ra, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r31;
    // 0x80106B84: jal         0x800C7D1C
    // 0x80106B88: addiu       $a0, $zero, 0x2F2
    ctx->r4 = ADD32(0, 0X2F2);
    playObjectiveVoiceLine2(rdram, ctx);
        goto after_0;
    // 0x80106B88: addiu       $a0, $zero, 0x2F2
    ctx->r4 = ADD32(0, 0X2F2);
    after_0:
    // 0x80106B8C: lw          $ra, 0x10($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X10);
    // 0x80106B90: jr          $ra
    // 0x80106B94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80106B94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void lvb_80106B98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106B98: jr          $ra
    // 0x80106B9C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    return;
    // 0x80106B9C: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
;}
RECOMP_FUNC void lvb_calculateFriendliesSaved(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106BA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80106BA4: addiu       $a0, $zero, 0x56
    ctx->r4 = ADD32(0, 0X56);
    // 0x80106BA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80106BAC: jal         0x800C761C
    // 0x80106BB0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    getObjectiveCount(rdram, ctx);
        goto after_0;
    // 0x80106BB0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x80106BB4: addiu       $a0, $zero, 0x58
    ctx->r4 = ADD32(0, 0X58);
    // 0x80106BB8: jal         0x800C761C
    // 0x80106BBC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    getObjectiveCount(rdram, ctx);
        goto after_1;
    // 0x80106BBC: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    after_1:
    // 0x80106BC0: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x80106BC4: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80106BC8: jal         0x800C77B0
    // 0x80106BCC: subu        $a0, $a0, $s0
    ctx->r4 = SUB32(ctx->r4, ctx->r16);
    setFriendliesSaved(rdram, ctx);
        goto after_2;
    // 0x80106BCC: subu        $a0, $a0, $s0
    ctx->r4 = SUB32(ctx->r4, ctx->r16);
    after_2:
    // 0x80106BD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80106BD4: lw          $s0, 0x10($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X10);
    // 0x80106BD8: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80106BDC: jr          $ra
    // 0x80106BE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80106BE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void fake_func_80106BE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
;}
RECOMP_FUNC void lvc_initializeObjectTracking(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106BF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80106BF4: lui         $at, 0x800B
    ctx->r1 = S32(0X800B << 16);
    // 0x80106BF8: lwc1        $f12, -0x6710($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X6710);
    // 0x80106BFC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80106C00: sw          $zero, -0x2EC0($v0)
    MEM_W(-0X2EC0, ctx->r2) = 0;
    // 0x80106C04: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80106C08: sw          $zero, -0x2EBC($v0)
    MEM_W(-0X2EBC, ctx->r2) = 0;
    // 0x80106C0C: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x80106C10: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80106C14: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x80106C18: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80106C1C: jal         0x800C7CEC
    // 0x80106C20: sw          $s0, -0x2EB8($v0)
    MEM_W(-0X2EB8, ctx->r2) = ctx->r16;
    setLevelObjectTrackingScalar(rdram, ctx);
        goto after_0;
    // 0x80106C20: sw          $s0, -0x2EB8($v0)
    MEM_W(-0X2EB8, ctx->r2) = ctx->r16;
    after_0:
    // 0x80106C24: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80106C28: addiu       $a0, $a0, 0x6F80
    ctx->r4 = ADD32(ctx->r4, 0X6F80);
    // 0x80106C2C: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80106C30: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x80106C34: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80106C38: jal         0x800C7830
    // 0x80106C3C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_1;
    // 0x80106C3C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x80106C40: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80106C44: addiu       $a0, $a0, 0x6FC4
    ctx->r4 = ADD32(ctx->r4, 0X6FC4);
    // 0x80106C48: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80106C4C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80106C50: addiu       $a3, $zero, 0xA
    ctx->r7 = ADD32(0, 0XA);
    // 0x80106C54: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80106C58: jal         0x800C7830
    // 0x80106C5C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_2;
    // 0x80106C5C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_2:
    // 0x80106C60: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80106C64: addiu       $a0, $a0, 0x6FF4
    ctx->r4 = ADD32(ctx->r4, 0X6FF4);
    // 0x80106C68: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    // 0x80106C6C: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x80106C70: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80106C74: jal         0x800C7830
    // 0x80106C78: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_3;
    // 0x80106C78: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x80106C7C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80106C80: addiu       $a0, $a0, 0x715C
    ctx->r4 = ADD32(ctx->r4, 0X715C);
    // 0x80106C84: addiu       $a1, $zero, 0x61
    ctx->r5 = ADD32(0, 0X61);
    // 0x80106C88: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x80106C8C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80106C90: jal         0x800C7830
    // 0x80106C94: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_4;
    // 0x80106C94: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x80106C98: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80106C9C: addiu       $a0, $a0, 0x7124
    ctx->r4 = ADD32(ctx->r4, 0X7124);
    // 0x80106CA0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80106CA4: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x80106CA8: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80106CAC: jal         0x800C7830
    // 0x80106CB0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_5;
    // 0x80106CB0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x80106CB4: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80106CB8: addiu       $a0, $a0, 0x70C8
    ctx->r4 = ADD32(ctx->r4, 0X70C8);
    // 0x80106CBC: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80106CC0: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80106CC4: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x80106CC8: jal         0x800C7830
    // 0x80106CCC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_6;
    // 0x80106CCC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_6:
    // 0x80106CD0: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80106CD4: addiu       $a0, $a0, 0x7070
    ctx->r4 = ADD32(ctx->r4, 0X7070);
    // 0x80106CD8: addu        $a1, $zero, $zero
    ctx->r5 = ADD32(0, 0);
    // 0x80106CDC: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
    // 0x80106CE0: addiu       $a3, $zero, 0x28
    ctx->r7 = ADD32(0, 0X28);
    // 0x80106CE4: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80106CE8: jal         0x800C7830
    // 0x80106CEC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_7;
    // 0x80106CEC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_7:
    // 0x80106CF0: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80106CF4: addiu       $a0, $a0, 0x7190
    ctx->r4 = ADD32(ctx->r4, 0X7190);
    // 0x80106CF8: addiu       $a1, $zero, 0x4D
    ctx->r5 = ADD32(0, 0X4D);
    // 0x80106CFC: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x80106D00: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80106D04: jal         0x800C7830
    // 0x80106D08: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_8;
    // 0x80106D08: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_8:
    // 0x80106D0C: lui         $a0, 0x8010
    ctx->r4 = S32(0X8010 << 16);
    // 0x80106D10: addiu       $a0, $a0, 0x71C8
    ctx->r4 = ADD32(ctx->r4, 0X71C8);
    // 0x80106D14: addiu       $a1, $zero, 0x5C
    ctx->r5 = ADD32(0, 0X5C);
    // 0x80106D18: addu        $a2, $s0, $zero
    ctx->r6 = ADD32(ctx->r16, 0);
    // 0x80106D1C: addu        $a3, $zero, $zero
    ctx->r7 = ADD32(0, 0);
    // 0x80106D20: jal         0x800C7830
    // 0x80106D24: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    addBooleanCountHandleWrapper(rdram, ctx);
        goto after_9;
    // 0x80106D24: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_9:
    // 0x80106D28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80106D2C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80106D30: addu        $v0, $zero, $zero
    ctx->r2 = ADD32(0, 0);
    // 0x80106D34: jr          $ra
    // 0x80106D38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80106D38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
